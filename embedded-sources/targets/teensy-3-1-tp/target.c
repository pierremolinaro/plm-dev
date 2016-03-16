//---------------------------------------------------------------------------------------------------------------------*

#define TASK_COUNT (!TASKCOUNT!)

//---------------------------------------------------------------------------------------------------------------------*

typedef unsigned task_list ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   T A S K    R O U T I N E    T Y P E                                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (* routineTaskType) (void) ;

//---------------------------------------------------------------------------------------------------------------------*

/*static unsigned countTrainingZeros (const unsigned inValue) {
  unsigned result = 0 ;
  unsigned w = inValue ;
  while ((w & 1) == 0) {
    result ++ ;
    w >>= 1 ;
  }
  return result ;
}*/

static unsigned countTrainingZeros (const unsigned inValue) {
  unsigned reversedValue ;
  __asm__ ("rbit %0, %1" : "=r" (reversedValue) : "r" (inValue)) ;
  unsigned result ;
  __asm__ ("clz %0, %1" : "=r" (result) : "r" (reversedValue)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                C O R T E X    M 4    S T A C K E D    R E G I S T E R S                                             *
//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   |                            |                                                                    *
//         PSP+32 -> |----------------------------| \                                                                  *
//                   | xPSR                       |  |                                                                 *
//         PSP+28 -> |----------------------------|  |                                                                 *
//                   | PC (after SVC instruction) |  |                                                                 *
//         PSP+24 -> |----------------------------|  |                                                                 *
//                   | LR                         |  |                                                                 *
//         PSP+20 -> |----------------------------|  |                                                                 *
//                   | R12                        |  |  Saved by interrupt response                                    *
//         PSP+16 -> |----------------------------|  |                                                                 *
//                   | R3                         |  |                                                                 *
//         PSP+12 -> |----------------------------|  |                                                                 *
//                   | R2                         |  |                                                                 *
//         PSP+8  -> |----------------------------|  |                                                                 *
//                   | R1                         |  |                                                                 *
//         PSP+4  -> |----------------------------|  |                                                                 *
//                   | R0                         |  |                                                                 *
//         PSP    -> |----------------------------| /                                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef struct {
  unsigned mR0 ;
  unsigned mR1 ;
  unsigned mR2 ;
  unsigned mR3 ;
  unsigned mR12 ;
  unsigned mLR ;
  unsigned mPC ;
  unsigned mXPSR ;
} stacked_registers ;

//----------------------------------------------------------------------------------------------------------------------
//
//                                            *---------------------*
//                                            | LR return code      | +36 [ 9]
//                                            *---------------------*
//                                            | R13 (PSP)           | +32 [ 8]
//                                            *---------------------*
//                                            | R11                 | +28 [ 7]
//                                            *---------------------*
//                                            | R10                 | +24 [ 6]
//                                            *---------------------*
//                                            | R9                  | +20 [ 5]
//                                            *---------------------*
//                                            | R8                  | +16 [ 4]
//                                            *---------------------*
//                                            | R7                  | +12 [ 3]
//                                            *---------------------*
//                                            | R6                  | + 8 [ 2]
//                                            *---------------------*
//                                            | R5                  | + 4 [ 1]
//  *--------------------------------*        *---------------------*
//  | gRunningTaskContextSaveAddress +------> | R4                  | + 0 [ 0]
//  *--------------------------------*        *---------------------*
//
//----------------------------------------------------------------------------------------------------------------------

typedef struct {
  unsigned mR4 ;
  unsigned mR5 ;
  unsigned mR6 ;
  unsigned mR7 ;
  unsigned mR8 ;
  unsigned mR9 ;
  unsigned mR10 ;
  unsigned mR11 ;
  stacked_registers * mSP_USR ;
  unsigned mLR_RETURN_CODE ;
} task_context ;

//---------------------------------------------------------------------------------------------------------------------*

static void kernel_set_return_code (task_context * inTaskContext,
                                    const unsigned inReturnCode) {
  stacked_registers * ptr = inTaskContext->mSP_USR ;
  ptr->mR0 = inReturnCode ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void kernel_set_task_context (task_context * inTaskContext,
                                     const unsigned inStackPointerInitialValue,
                                     routineTaskType inTaskRoutine) {
//--- Initialize LR
  inTaskContext->mLR_RETURN_CODE = 0xFFFFFFFD ;
//--- Initialize SP
  stacked_registers * ptr = (stacked_registers *) (inStackPointerInitialValue - sizeof (stacked_registers)) ; // 8 stacked registers
  inTaskContext->mSP_USR = ptr ;
//--- Initialize PC
  ptr->mPC = (unsigned) inTaskRoutine ;
//--- Initialize CPSR
  ptr->mXPSR = 1 << 24 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   T A S K    C O N T R O L    B L O C K                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

typedef struct task_control_block {
//--- Context buffer
  task_context mTaskContext ;
//--- This field is used for deadline waiting
  unsigned mDate ;
//---
  task_list * mWaitingList ;
//--- Stack buffer parameters
  unsigned * mStackBufferAddress ;
  unsigned mStackBufferSize ; // In bytes
} task_control_block ;

//---------------------------------------------------------------------------------------------------------------------*

static task_control_block gTaskDescriptorArray [TASK_COUNT] ;

//---------------------------------------------------------------------------------------------------------------------*
//   S C H E D U L E R                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

task_context * gRunningTaskContextSaveAddress ; // Shared with assembly code (arm_context.s)
static unsigned gRunningTaskIndex ; // Not significant if gRunningTaskContextSaveAddress == NULL
static task_list gReadyTaskList ;

//---------------------------------------------------------------------------------------------------------------------*

static unsigned kernel_runningTaskIndex (void) {
  return gRunningTaskIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void kernel_makeTaskReady (const unsigned inTaskIndex) {
  gReadyTaskList |= 1 << inTaskIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void kernel_makeNoTaskRunning (void) {
  gRunningTaskContextSaveAddress = (task_context *) 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

void kernel_selectTaskToRun (void) ;

void kernel_selectTaskToRun (void) {
  if (((task_context *) 0) != gRunningTaskContextSaveAddress) {
    gReadyTaskList |= 1 << gRunningTaskIndex ;
    gRunningTaskContextSaveAddress = (task_context *) 0 ;
  }
  if (gReadyTaskList != 0) {
    gRunningTaskIndex = countTrainingZeros (gReadyTaskList) ;
    gReadyTaskList &= ~ (1 << gRunningTaskIndex) ;
    gRunningTaskContextSaveAddress = & (gTaskDescriptorArray [gRunningTaskIndex].mTaskContext) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//   kernel_create_task                                                                                                *
//---------------------------------------------------------------------------------------------------------------------*

void kernel_create_task (const unsigned inTaskIndex,
                         unsigned * inStackBufferAddress,
                         unsigned inStackBufferSize,
                         routineTaskType inTaskRoutine) ;

void kernel_create_task (const unsigned inTaskIndex,
                         unsigned * inStackBufferAddress,
                         unsigned inStackBufferSize,
                         routineTaskType inTaskRoutine) {
  task_control_block * taskDescriptorPtr = & gTaskDescriptorArray [inTaskIndex] ;
  taskDescriptorPtr->mWaitingList = (task_list *) 0 ;
//--- Store stack parameters
  taskDescriptorPtr->mStackBufferAddress = inStackBufferAddress ;
  taskDescriptorPtr->mStackBufferSize = inStackBufferSize ;
//--- Stack Pointer initial value
  const unsigned spInitialValue = ((unsigned) taskDescriptorPtr->mStackBufferAddress) + taskDescriptorPtr->mStackBufferSize ;
//--- Initialize Context
  kernel_set_task_context (& (taskDescriptorPtr->mTaskContext),
                           spInitialValue,
                           inTaskRoutine) ;
//--- Make task ready
  kernel_makeTaskReady (inTaskIndex) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   L I S T    M A N A G E M E N T                                                                                    *
//---------------------------------------------------------------------------------------------------------------------*

static task_list gDeadlineWaitingTaskList ;

//---------------------------------------------------------------------------------------------------------------------*
//  B L O C K I N G    R U N N I N G    T A S K                                                                        *
//---------------------------------------------------------------------------------------------------------------------*

void blockInList (task_list * ioWaitingList) asm ("proc..blockInList") ;

void blockInList (task_list * ioWaitingList) {
  const unsigned currentTaskIndex = kernel_runningTaskIndex () ;
  *ioWaitingList |= 1 << currentTaskIndex ;
  task_control_block * taskDescriptorPtr = & gTaskDescriptorArray [currentTaskIndex] ;
  taskDescriptorPtr->mWaitingList = ioWaitingList ;
  kernel_makeNoTaskRunning () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void blockOnDeadline (const unsigned inDeadlineMS) asm ("proc..blockOnDeadline") ;

void blockOnDeadline (const unsigned inDeadlineMS) {
  const unsigned currentTaskIndex = kernel_runningTaskIndex () ;
  task_control_block * taskDescriptorPtr = & gTaskDescriptorArray [currentTaskIndex] ;
  gDeadlineWaitingTaskList |= 1 << currentTaskIndex ;
  taskDescriptorPtr->mDate = inDeadlineMS ;
  kernel_makeNoTaskRunning () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void blockInListAndOnDeadline (task_list * ioWaitingList, const unsigned inDeadlineMS)
asm ("proc..blockInListAndOnDeadline") ;

void blockInListAndOnDeadline (task_list * ioWaitingList, const unsigned inDeadlineMS) {
  const unsigned currentTaskIndex = kernel_runningTaskIndex () ;
  task_control_block * taskDescriptorPtr = & gTaskDescriptorArray [currentTaskIndex] ;
  *ioWaitingList |= 1 << currentTaskIndex ;
  taskDescriptorPtr->mWaitingList = ioWaitingList ;
  gDeadlineWaitingTaskList |= 1 << currentTaskIndex ;
  taskDescriptorPtr->mDate = inDeadlineMS ;
  kernel_makeNoTaskRunning () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//  M A K E    T A S K    R E A D Y                                                                                    *
//---------------------------------------------------------------------------------------------------------------------*

void makeTaskReady (task_list * ioWaitingList, unsigned char * outFound)
asm ("proc..makeTaskReady") ;

void makeTaskReady (task_list * ioWaitingList, unsigned char * outFound) {
  * outFound = (* ioWaitingList) != 0 ;
  if (* outFound) {
    const unsigned taskIndex = countTrainingZeros (* ioWaitingList) ;
    task_control_block * taskDescriptorPtr = & gTaskDescriptorArray [taskIndex] ;
    kernel_set_return_code (& taskDescriptorPtr->mTaskContext, 1) ;
    gDeadlineWaitingTaskList &= ~ (1 << taskIndex) ;
    *(taskDescriptorPtr->mWaitingList) &= ~ (1 << taskIndex) ;
    taskDescriptorPtr->mWaitingList = (task_list *) 0 ;
    kernel_makeTaskReady (taskIndex) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void makeTasksReadyFromCurrentDate (const unsigned inCurrentDate)
asm ("proc..makeTasksReadyFromCurrentDate") ;

void makeTasksReadyFromCurrentDate (const unsigned inCurrentDate) {
  unsigned w = gDeadlineWaitingTaskList ;
  while (w > 0) {
    const unsigned taskIndex = countTrainingZeros (w) ;
    w &= ~ (1 << taskIndex) ;
    task_control_block * taskDescriptorPtr = & gTaskDescriptorArray [taskIndex] ;
    if (inCurrentDate >= taskDescriptorPtr->mDate) {
      gDeadlineWaitingTaskList &= ~ (1 << taskIndex) ;
      if (taskDescriptorPtr->mWaitingList != (task_list *) 0) {
        *(taskDescriptorPtr->mWaitingList) &= ~ (1 << taskIndex) ;
        taskDescriptorPtr->mWaitingList = (task_list *) 0 ;
      }
      kernel_set_return_code (& taskDescriptorPtr->mTaskContext, 0) ;
      kernel_makeTaskReady (taskIndex) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

