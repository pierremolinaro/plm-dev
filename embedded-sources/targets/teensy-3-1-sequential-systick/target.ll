target datalayout = "e-m:e-p:32:32-i64:64-v128:64:128-a:0:32-n32-S64"
target triple = "thumbv7em-none--eabi"

;----------------------------------------------------------------------------------------------------------------------*
;    ISR Vector                                                                                                        *
;----------------------------------------------------------------------------------------------------------------------*

%vectorStructSeq = type {
  i32*,            ; unsigned * mStackPointer
  [15  x void()*], ; void (* mCoreSystemHandlerVector [15]) (void) ;
  [240 x void()*], ; void (* mNonCoreHandlerVector [240]) (void) ;
  [4   x i32]      ; int mFlash [4] ;
} 

;----------------------------------------------------------------------------------------------------------------------*

@__system_stack_end = external global i32

;----------------------------------------------------------------------------------------------------------------------*

@startup = constant %vectorStructSeq {
  i32* @__system_stack_end,
;--- ARM Core System Handler Vectors
  [15  x void()*] [
    void()* @ResetISR, ; 1
    void()* null, ; 2
    void()* null, ; 3
    void()* null, ; 4
    void()* null, ; 5
    void()* null, ; 6
    void()* null, ; 7
    void()* null, ; 8
    void()* null, ; 9
    void()* null, ; 10
    void()* null, ; 11
    void()* null, ; 12
    void()* null, ; 13
    void()* null, ; 14
    void()* null  ; 15
  ],
;--- Non-Core Vectors
  [240 x void()*] zeroinitializer,
;--- Flash magic values
  [4   x i32] [i32 -1, i32 -1, i32 -1, i32 -2]
}, section ".isr_vector"

;----------------------------------------------------------------------------------------------------------------------*
;   Clear BSS                                                                                                          *
;----------------------------------------------------------------------------------------------------------------------*
;void clearBSS (void) {
;  extern unsigned __bss_start ;
;  extern unsigned __bss_end ;
;  unsigned * p = & __bss_start ;
;  while (p != & __bss_end) {
;    * p = 0 ;
;    p ++ ;
;  }
;}
;----------------------------------------------------------------------------------------------------------------------*

@__bss_start = external global [0 x i32]
@__bss_end = external global [0 x i32]

;----------------------------------------------------------------------------------------------------------------------*

define internal void @clearBSS () nounwind {
entry:
  %startPtr = getelementptr  [0 x i32], [0 x i32]* @__bss_start, i32 0, i32 0
  %endPtr = getelementptr  [0 x i32], [0 x i32]* @__bss_end, i32 0, i32 0
  br label %bssLoopTest
 
bssLoopTest:
  %p = phi i32* [%startPtr, %entry], [%p.next, %bssLoop]
  %completed = icmp eq i32* %p, %endPtr
  br i1 %completed, label %clearCompleted, label %bssLoop
 
bssLoop:
  store i32 0, i32* %p, align 4
  %p.next = getelementptr inbounds i32, i32* %p, i32 1
  br label %bssLoopTest
 
clearCompleted:
  ret void
}

;----------------------------------------------------------------------------------------------------------------------*
;   Copy .data section                                                                                                 *
;----------------------------------------------------------------------------------------------------------------------*
;void copyData (void) {
;  extern unsigned __data_start ;
;  extern unsigned __data_end ;
;  extern unsigned __data_load_start ;
;  unsigned * pSrc = & __data_load_start ;
;  unsigned * pDest = & __data_start ;
;  while (pDest != & __data_end) {
;    * pDest = * pSrc ;
;    pDest ++ ;
;    pSrc ++ ;
;  }
;}
;----------------------------------------------------------------------------------------------------------------------*

@__data_start = external global [0 x i32]
@__data_end = external global [0 x i32]
@__data_load_start = external global [0 x i32]

;----------------------------------------------------------------------------------------------------------------------*

define internal void @copyData () nounwind {
entry:
  %data_start = getelementptr  [0 x i32], [0 x i32]* @__data_start, i32 0, i32 0
  %data_end = getelementptr  [0 x i32], [0 x i32]* @__data_end, i32 0, i32 0
  %data_load_start = getelementptr  [0 x i32], [0 x i32]* @__data_load_start, i32 0, i32 0
  br label %copyLoop.test
 
copyLoop.test:
  %pDest = phi i32* [%data_start, %entry], [%pDestInct, %copyLoop]
  %pSource = phi i32* [%data_load_start, %entry], [%pSourceInc, %copyLoop]
  %equal = icmp eq i32* %pDest, %data_end
  br i1 %equal, label %copyCompleted, label %copyLoop
 
copyLoop:
  %value = load i32, i32* %pSource
  store i32 %value, i32* %pDest, align 4
  %pDestInct = getelementptr inbounds i32, i32* %pDest, i32 1
  %pSourceInc = getelementptr inbounds i32, i32* %pSource, i32 1
  br label %copyLoop.test

copyCompleted:
  ret void
}

;----------------------------------------------------------------------------------------------------------------------*
;   ResetISR                                                                                                           *
;----------------------------------------------------------------------------------------------------------------------*

define internal void @ResetISR () nounwind noreturn naked {
  call void @boot ()
  call void @clearBSS ()
  call void @copyData ()
  call void @proc_setup ()
  br label %loop
loop:
  call void @proc_loop ()
  br label %loop
}
