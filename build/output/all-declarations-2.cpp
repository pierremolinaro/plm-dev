#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-2.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@initListIR generateLLVMinitCode'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_generateLLVMinitCode (const GALGAS_initListIR inObject,
                                           GALGAS_string & ioArgument_ioLLVMcode,
                                           const GALGAS_routineMapIR constinArgument_inProcedureMapIR,
                                           const GALGAS_generationContext constinArgument_inGenerationContext,
                                           GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_ioLLVMcode.plusAssign_operation(function_llvmTitleComment (GALGAS_string ("Init"), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 206)), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 206)) ;
  const GALGAS_initListIR temp_0 = inObject ;
  cEnumerator_initListIR enumerator_8082 (temp_0, kEnumeration_up) ;
  while (enumerator_8082.hasCurrentObject ()) {
    GALGAS_bool var_generate_8104 ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, enumerator_8082.current (HERE).mAttribute_mInitRequiredByProcList.getter_length (SOURCE_FILE ("declaration-init.galgas", 209)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_generate_8104 = GALGAS_bool (true) ;
    }else if (kBoolFalse == test_1) {
      var_generate_8104 = GALGAS_bool (false) ;
      cEnumerator_lstringlist enumerator_8277 (enumerator_8082.current (HERE).mAttribute_mInitRequiredByProcList, kEnumeration_up) ;
      bool bool_2 = var_generate_8104.operator_not (SOURCE_FILE ("declaration-init.galgas", 213)).isValidAndTrue () ;
      if (enumerator_8277.hasCurrentObject () && bool_2) {
        while (enumerator_8277.hasCurrentObject () && bool_2) {
          var_generate_8104 = constinArgument_inProcedureMapIR.getter_hasKey (enumerator_8277.current_mValue (HERE).mAttribute_string COMMA_SOURCE_FILE ("declaration-init.galgas", 214)) ;
          enumerator_8277.gotoNextObject () ;
          if (enumerator_8277.hasCurrentObject ()) {
            bool_2 = var_generate_8104.operator_not (SOURCE_FILE ("declaration-init.galgas", 213)).isValidAndTrue () ;
          }
        }
      }
    }
    const enumGalgasBool test_3 = var_generate_8104.boolEnum () ;
    if (kBoolTrue == test_3) {
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("define internal void @init.").add_operation (enumerator_8082.current (HERE).mAttribute_mPriority.getter_string (SOURCE_FILE ("declaration-init.galgas", 218)), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 218)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 218)), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 218)) ;
      const enumGalgasBool test_4 = GALGAS_bool (kIsNotEqual, enumerator_8082.current (HERE).mAttribute_mSelfType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-init.galgas", 219)))).boolEnum () ;
      if (kBoolTrue == test_4) {
        ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8082.current (HERE).mAttribute_mSelfType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 220)).add_operation (GALGAS_string (" * %self"), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 220)), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 220)) ;
      }
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (")").add_operation (function_llvmAttributeFunction (inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 222)), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 222)).add_operation (GALGAS_string ("{\n"), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 222)), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 222)) ;
      cEnumerator_allocaList enumerator_8702 (enumerator_8082.current (HERE).mAttribute_mAllocaList, kEnumeration_up) ;
      while (enumerator_8702.hasCurrentObject ()) {
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (function_llvmNameForLocalVariable (enumerator_8702.current_mVarName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 224)), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 224)).add_operation (GALGAS_string (" = alloca "), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 224)).add_operation (enumerator_8702.current_mType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 224)), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 224)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 224)), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 224)) ;
        enumerator_8702.gotoNextObject () ;
      }
      extensionMethod_instructionListLLVMCode (enumerator_8082.current (HERE).mAttribute_mInstructionListIR, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 226)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ret void\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 227)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("}\n"
        "\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 228)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(function_llvmSeparatorLine (inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 229)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 229)), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 229)) ;
    }
    enumerator_8082.gotoNextObject () ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("define internal void @init ()").add_operation (function_llvmAttributeFunction (inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 232)), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 232)).add_operation (GALGAS_string ("{\n"), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 232)), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 232)) ;
  const GALGAS_initListIR temp_5 = inObject ;
  cEnumerator_initListIR enumerator_9162 (temp_5, kEnumeration_up) ;
  while (enumerator_9162.hasCurrentObject ()) {
    GALGAS_bool var_generate_9184 ;
    const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, enumerator_9162.current (HERE).mAttribute_mInitRequiredByProcList.getter_length (SOURCE_FILE ("declaration-init.galgas", 235)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_6) {
      var_generate_9184 = GALGAS_bool (true) ;
    }else if (kBoolFalse == test_6) {
      var_generate_9184 = GALGAS_bool (false) ;
      cEnumerator_lstringlist enumerator_9357 (enumerator_9162.current (HERE).mAttribute_mInitRequiredByProcList, kEnumeration_up) ;
      bool bool_7 = var_generate_9184.operator_not (SOURCE_FILE ("declaration-init.galgas", 239)).isValidAndTrue () ;
      if (enumerator_9357.hasCurrentObject () && bool_7) {
        while (enumerator_9357.hasCurrentObject () && bool_7) {
          var_generate_9184 = constinArgument_inProcedureMapIR.getter_hasKey (enumerator_9357.current_mValue (HERE).mAttribute_string COMMA_SOURCE_FILE ("declaration-init.galgas", 240)) ;
          enumerator_9357.gotoNextObject () ;
          if (enumerator_9357.hasCurrentObject ()) {
            bool_7 = var_generate_9184.operator_not (SOURCE_FILE ("declaration-init.galgas", 239)).isValidAndTrue () ;
          }
        }
      }
    }
    const enumGalgasBool test_8 = var_generate_9184.boolEnum () ;
    if (kBoolTrue == test_8) {
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  call void @init.").add_operation (enumerator_9162.current (HERE).mAttribute_mPriority.getter_string (SOURCE_FILE ("declaration-init.galgas", 244)), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 244)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 244)), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 244)) ;
      const enumGalgasBool test_9 = GALGAS_bool (kIsNotEqual, enumerator_9162.current (HERE).mAttribute_mSelfType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-init.galgas", 245)))).boolEnum () ;
      if (kBoolTrue == test_9) {
        ioArgument_ioLLVMcode.plusAssign_operation(enumerator_9162.current (HERE).mAttribute_mSelfType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 246)).add_operation (GALGAS_string (" * @"), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 246)).add_operation (function_llvmNameForGlobalVariable (enumerator_9162.current (HERE).mAttribute_mGlobalVariable, inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 246)), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 246)), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 246)) ;
      }
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (")\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 248)) ;
    }
    enumerator_9162.gotoNextObject () ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ret void\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 251)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("}\n"
    "\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 252)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Class for element of '@procFormalArgumentList' list                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_procFormalArgumentList : public cCollectionElement {
  public : GALGAS_procFormalArgumentList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_procFormalArgumentList (const GALGAS_procFormalArgumentPassingMode & in_mFormalArgumentPassingMode,
                                                      const GALGAS_lstring & in_mSelector,
                                                      const GALGAS_lstring & in_mFormalArgumentTypeName,
                                                      const GALGAS_lstring & in_mFormalArgumentName
                                                      COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_procFormalArgumentList::cCollectionElement_procFormalArgumentList (const GALGAS_procFormalArgumentPassingMode & in_mFormalArgumentPassingMode,
                                                                                      const GALGAS_lstring & in_mSelector,
                                                                                      const GALGAS_lstring & in_mFormalArgumentTypeName,
                                                                                      const GALGAS_lstring & in_mFormalArgumentName
                                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mFormalArgumentPassingMode, in_mSelector, in_mFormalArgumentTypeName, in_mFormalArgumentName) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_procFormalArgumentList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_procFormalArgumentList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_procFormalArgumentList (mObject.mAttribute_mFormalArgumentPassingMode, mObject.mAttribute_mSelector, mObject.mAttribute_mFormalArgumentTypeName, mObject.mAttribute_mFormalArgumentName COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_procFormalArgumentList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFormalArgumentPassingMode" ":" ;
  mObject.mAttribute_mFormalArgumentPassingMode.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSelector" ":" ;
  mObject.mAttribute_mSelector.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFormalArgumentTypeName" ":" ;
  mObject.mAttribute_mFormalArgumentTypeName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFormalArgumentName" ":" ;
  mObject.mAttribute_mFormalArgumentName.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_procFormalArgumentList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_procFormalArgumentList * operand = (cCollectionElement_procFormalArgumentList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_procFormalArgumentList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList::GALGAS_procFormalArgumentList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList::GALGAS_procFormalArgumentList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_procFormalArgumentList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_procFormalArgumentList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_procFormalArgumentList::constructor_listWithValue (const GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                                        const GALGAS_lstring & inOperand1,
                                                                                        const GALGAS_lstring & inOperand2,
                                                                                        const GALGAS_lstring & inOperand3
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_procFormalArgumentList result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_procFormalArgumentList::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                               const GALGAS_procFormalArgumentPassingMode & in_mFormalArgumentPassingMode,
                                                               const GALGAS_lstring & in_mSelector,
                                                               const GALGAS_lstring & in_mFormalArgumentTypeName,
                                                               const GALGAS_lstring & in_mFormalArgumentName
                                                               COMMA_LOCATION_ARGS) {
  cCollectionElement_procFormalArgumentList * p = NULL ;
  macroMyNew (p, cCollectionElement_procFormalArgumentList (in_mFormalArgumentPassingMode,
                                                            in_mSelector,
                                                            in_mFormalArgumentTypeName,
                                                            in_mFormalArgumentName COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentList::addAssign_operation (const GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                         const GALGAS_lstring & inOperand1,
                                                         const GALGAS_lstring & inOperand2,
                                                         const GALGAS_lstring & inOperand3
                                                         COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_procFormalArgumentList (inOperand0, inOperand1, inOperand2, inOperand3 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentList::setter_insertAtIndex (const GALGAS_procFormalArgumentPassingMode inOperand0,
                                                          const GALGAS_lstring inOperand1,
                                                          const GALGAS_lstring inOperand2,
                                                          const GALGAS_lstring inOperand3,
                                                          const GALGAS_uint inInsertionIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_procFormalArgumentList (inOperand0, inOperand1, inOperand2, inOperand3 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentList::setter_removeAtIndex (GALGAS_procFormalArgumentPassingMode & outOperand0,
                                                          GALGAS_lstring & outOperand1,
                                                          GALGAS_lstring & outOperand2,
                                                          GALGAS_lstring & outOperand3,
                                                          const GALGAS_uint inRemoveIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_procFormalArgumentList * p = (cCollectionElement_procFormalArgumentList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
      outOperand0 = p->mObject.mAttribute_mFormalArgumentPassingMode ;
      outOperand1 = p->mObject.mAttribute_mSelector ;
      outOperand2 = p->mObject.mAttribute_mFormalArgumentTypeName ;
      outOperand3 = p->mObject.mAttribute_mFormalArgumentName ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentList::setter_popFirst (GALGAS_procFormalArgumentPassingMode & outOperand0,
                                                     GALGAS_lstring & outOperand1,
                                                     GALGAS_lstring & outOperand2,
                                                     GALGAS_lstring & outOperand3,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentList * p = (cCollectionElement_procFormalArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
    outOperand0 = p->mObject.mAttribute_mFormalArgumentPassingMode ;
    outOperand1 = p->mObject.mAttribute_mSelector ;
    outOperand2 = p->mObject.mAttribute_mFormalArgumentTypeName ;
    outOperand3 = p->mObject.mAttribute_mFormalArgumentName ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentList::setter_popLast (GALGAS_procFormalArgumentPassingMode & outOperand0,
                                                    GALGAS_lstring & outOperand1,
                                                    GALGAS_lstring & outOperand2,
                                                    GALGAS_lstring & outOperand3,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentList * p = (cCollectionElement_procFormalArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
    outOperand0 = p->mObject.mAttribute_mFormalArgumentPassingMode ;
    outOperand1 = p->mObject.mAttribute_mSelector ;
    outOperand2 = p->mObject.mAttribute_mFormalArgumentTypeName ;
    outOperand3 = p->mObject.mAttribute_mFormalArgumentName ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentList::method_first (GALGAS_procFormalArgumentPassingMode & outOperand0,
                                                  GALGAS_lstring & outOperand1,
                                                  GALGAS_lstring & outOperand2,
                                                  GALGAS_lstring & outOperand3,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentList * p = (cCollectionElement_procFormalArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
    outOperand0 = p->mObject.mAttribute_mFormalArgumentPassingMode ;
    outOperand1 = p->mObject.mAttribute_mSelector ;
    outOperand2 = p->mObject.mAttribute_mFormalArgumentTypeName ;
    outOperand3 = p->mObject.mAttribute_mFormalArgumentName ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentList::method_last (GALGAS_procFormalArgumentPassingMode & outOperand0,
                                                 GALGAS_lstring & outOperand1,
                                                 GALGAS_lstring & outOperand2,
                                                 GALGAS_lstring & outOperand3,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentList * p = (cCollectionElement_procFormalArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
    outOperand0 = p->mObject.mAttribute_mFormalArgumentPassingMode ;
    outOperand1 = p->mObject.mAttribute_mSelector ;
    outOperand2 = p->mObject.mAttribute_mFormalArgumentTypeName ;
    outOperand3 = p->mObject.mAttribute_mFormalArgumentName ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_procFormalArgumentList::add_operation (const GALGAS_procFormalArgumentList & inOperand,
                                                                            C_Compiler * /* inCompiler */
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_procFormalArgumentList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_procFormalArgumentList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_procFormalArgumentList result = GALGAS_procFormalArgumentList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_procFormalArgumentList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_procFormalArgumentList result = GALGAS_procFormalArgumentList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_procFormalArgumentList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_procFormalArgumentList result = GALGAS_procFormalArgumentList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentList::plusAssign_operation (const GALGAS_procFormalArgumentList inOperand,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentPassingMode GALGAS_procFormalArgumentList::getter_mFormalArgumentPassingModeAtIndex (const GALGAS_uint & inIndex,
                                                                                                              C_Compiler * inCompiler
                                                                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentList * p = (cCollectionElement_procFormalArgumentList *) attributes.ptr () ;
  GALGAS_procFormalArgumentPassingMode result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
    result = p->mObject.mAttribute_mFormalArgumentPassingMode ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_procFormalArgumentList::getter_mSelectorAtIndex (const GALGAS_uint & inIndex,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentList * p = (cCollectionElement_procFormalArgumentList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
    result = p->mObject.mAttribute_mSelector ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_procFormalArgumentList::getter_mFormalArgumentTypeNameAtIndex (const GALGAS_uint & inIndex,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentList * p = (cCollectionElement_procFormalArgumentList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
    result = p->mObject.mAttribute_mFormalArgumentTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_procFormalArgumentList::getter_mFormalArgumentNameAtIndex (const GALGAS_uint & inIndex,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentList * p = (cCollectionElement_procFormalArgumentList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
    result = p->mObject.mAttribute_mFormalArgumentName ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_procFormalArgumentList::cEnumerator_procFormalArgumentList (const GALGAS_procFormalArgumentList & inEnumeratedObject,
                                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList_2D_element cEnumerator_procFormalArgumentList::current (LOCATION_ARGS) const {
  const cCollectionElement_procFormalArgumentList * p = (const cCollectionElement_procFormalArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentPassingMode cEnumerator_procFormalArgumentList::current_mFormalArgumentPassingMode (LOCATION_ARGS) const {
  const cCollectionElement_procFormalArgumentList * p = (const cCollectionElement_procFormalArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
  return p->mObject.mAttribute_mFormalArgumentPassingMode ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_procFormalArgumentList::current_mSelector (LOCATION_ARGS) const {
  const cCollectionElement_procFormalArgumentList * p = (const cCollectionElement_procFormalArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
  return p->mObject.mAttribute_mSelector ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_procFormalArgumentList::current_mFormalArgumentTypeName (LOCATION_ARGS) const {
  const cCollectionElement_procFormalArgumentList * p = (const cCollectionElement_procFormalArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
  return p->mObject.mAttribute_mFormalArgumentTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_procFormalArgumentList::current_mFormalArgumentName (LOCATION_ARGS) const {
  const cCollectionElement_procFormalArgumentList * p = (const cCollectionElement_procFormalArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procFormalArgumentList) ;
  return p->mObject.mAttribute_mFormalArgumentName ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @procFormalArgumentList type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procFormalArgumentList ("procFormalArgumentList",
                                               NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procFormalArgumentList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procFormalArgumentList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procFormalArgumentList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_procFormalArgumentList::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_procFormalArgumentList result ;
  const GALGAS_procFormalArgumentList * p = (const GALGAS_procFormalArgumentList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procFormalArgumentList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procFormalArgumentList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentPassingMode::GALGAS_procFormalArgumentPassingMode (void) :
mEnum (kNotBuilt) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentPassingMode GALGAS_procFormalArgumentPassingMode::constructor_input (UNUSED_LOCATION_ARGS) {
  GALGAS_procFormalArgumentPassingMode result ;
  result.mEnum = kEnum_input ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentPassingMode GALGAS_procFormalArgumentPassingMode::constructor_output (UNUSED_LOCATION_ARGS) {
  GALGAS_procFormalArgumentPassingMode result ;
  result.mEnum = kEnum_output ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentPassingMode GALGAS_procFormalArgumentPassingMode::constructor_inputOutput (UNUSED_LOCATION_ARGS) {
  GALGAS_procFormalArgumentPassingMode result ;
  result.mEnum = kEnum_inputOutput ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * gEnumNameArrayFor_procFormalArgumentPassingMode [4] = {
  "(not built)",
  "input",
  "output",
  "inputOutput"
} ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_procFormalArgumentPassingMode::getter_isInput (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_input == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_procFormalArgumentPassingMode::getter_isOutput (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_output == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_procFormalArgumentPassingMode::getter_isInputOutput (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_inputOutput == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentPassingMode::description (C_String & ioString,
                                                        const int32_t /* inIndentation */) const {
  ioString << "<enum @procFormalArgumentPassingMode: " << gEnumNameArrayFor_procFormalArgumentPassingMode [mEnum] ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_procFormalArgumentPassingMode::objectCompare (const GALGAS_procFormalArgumentPassingMode & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @procFormalArgumentPassingMode type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procFormalArgumentPassingMode ("procFormalArgumentPassingMode",
                                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procFormalArgumentPassingMode::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procFormalArgumentPassingMode ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procFormalArgumentPassingMode::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procFormalArgumentPassingMode (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentPassingMode GALGAS_procFormalArgumentPassingMode::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_procFormalArgumentPassingMode result ;
  const GALGAS_procFormalArgumentPassingMode * p = (const GALGAS_procFormalArgumentPassingMode *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procFormalArgumentPassingMode *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procFormalArgumentPassingMode", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Extension Getter '@procFormalArgumentPassingMode formalPassingModeString'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_formalPassingModeString (const GALGAS_procFormalArgumentPassingMode & inObject,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outResult ; // Returned variable
  const GALGAS_procFormalArgumentPassingMode temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
    break ;
  case GALGAS_procFormalArgumentPassingMode::kEnum_input:
    {
      result_outResult = GALGAS_string ("\?") ;
    }
    break ;
  case GALGAS_procFormalArgumentPassingMode::kEnum_output:
    {
      result_outResult = GALGAS_string ("!") ;
    }
    break ;
  case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
    {
      result_outResult = GALGAS_string ("\?!") ;
    }
    break ;
  }
//---
  return result_outResult ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//               Extension Getter '@procFormalArgumentPassingMode requiredActualPassingModeForSelector'                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_requiredActualPassingModeForSelector (const GALGAS_procFormalArgumentPassingMode & inObject,
                                                                    const GALGAS_string & constinArgument_inSelector,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outResult ; // Returned variable
  const GALGAS_procFormalArgumentPassingMode temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
    break ;
  case GALGAS_procFormalArgumentPassingMode::kEnum_input:
    {
      result_outResult = GALGAS_string ("!") ;
    }
    break ;
  case GALGAS_procFormalArgumentPassingMode::kEnum_output:
    {
      result_outResult = GALGAS_string ("\?") ;
    }
    break ;
  case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
    {
      result_outResult = GALGAS_string ("!\?") ;
    }
    break ;
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, constinArgument_inSelector.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_1) {
    result_outResult.plusAssign_operation(constinArgument_inSelector.add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 52)), inCompiler  COMMA_SOURCE_FILE ("declaration-func.galgas", 52)) ;
  }
//---
  return result_outResult ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Extension method '@functionDeclarationListAST noteTypesInPrecedenceGraph'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_noteTypesInPrecedenceGraph (const GALGAS_functionDeclarationListAST inObject,
                                                 GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_functionDeclarationListAST temp_0 = inObject ;
  cEnumerator_functionDeclarationListAST enumerator_6204 (temp_0, kEnumeration_up) ;
  while (enumerator_6204.hasCurrentObject ()) {
    cEnumerator_procFormalArgumentList enumerator_6277 (enumerator_6204.current_mFunctionFormalArgumentList (HERE), kEnumeration_up) ;
    while (enumerator_6277.hasCurrentObject ()) {
      GALGAS_lstring var_typeName_6299 = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (enumerator_6277.current_mFormalArgumentTypeName (HERE).getter_string (SOURCE_FILE ("declaration-func.galgas", 203)), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 203)), enumerator_6277.current_mFormalArgumentTypeName (HERE).mAttribute_location  COMMA_SOURCE_FILE ("declaration-func.galgas", 203)) ;
      {
      ioArgument_ioGraph.setter_noteNode (var_typeName_6299 COMMA_SOURCE_FILE ("declaration-func.galgas", 204)) ;
      }
      enumerator_6277.gotoNextObject () ;
    }
    extensionMethod_noteInstructionListTypesInPrecedenceGraph (enumerator_6204.current_mFunctionInstructionList (HERE), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 206)) ;
    enumerator_6204.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension method '@functionDeclarationListAST enterFunctionInContext'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterFunctionInContext (const GALGAS_functionDeclarationListAST inObject,
                                             const GALGAS_string constinArgument_inSelfTypeName,
                                             GALGAS_semanticContext & ioArgument_ioContext,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_functionDeclarationListAST temp_0 = inObject ;
  cEnumerator_functionDeclarationListAST enumerator_7047 (temp_0, kEnumeration_up) ;
  while (enumerator_7047.hasCurrentObject ()) {
    GALGAS_lstring temp_1 ;
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_inSelfTypeName.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_2) {
      temp_1 = enumerator_7047.current (HERE).mAttribute_mFunctionName ;
    }else if (kBoolFalse == test_2) {
      temp_1 = GALGAS_lstring::constructor_new (constinArgument_inSelfTypeName.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 223)).add_operation (enumerator_7047.current (HERE).mAttribute_mFunctionName.getter_string (SOURCE_FILE ("declaration-func.galgas", 223)), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 223)), enumerator_7047.current (HERE).mAttribute_mFunctionName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-func.galgas", 223)) ;
    }
    GALGAS_lstring var_routineMangledName_7094 = temp_1 ;
    var_routineMangledName_7094.mAttribute_string.plusAssign_operation(GALGAS_string ("("), inCompiler  COMMA_SOURCE_FILE ("declaration-func.galgas", 225)) ;
    GALGAS_procedureSignature var_signature_7346 = GALGAS_procedureSignature::constructor_emptyList (SOURCE_FILE ("declaration-func.galgas", 226)) ;
    cEnumerator_procFormalArgumentList enumerator_7462 (enumerator_7047.current (HERE).mAttribute_mFunctionFormalArgumentList, kEnumeration_up) ;
    while (enumerator_7462.hasCurrentObject ()) {
      GALGAS_unifiedTypeMap_2D_proxy var_typeProxy_7485 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_7462.current_mFormalArgumentTypeName (HERE), inCompiler  COMMA_SOURCE_FILE ("declaration-func.galgas", 228)) ;
      var_signature_7346.addAssign_operation (enumerator_7462.current_mFormalArgumentPassingMode (HERE), enumerator_7462.current_mSelector (HERE).mAttribute_string, var_typeProxy_7485  COMMA_SOURCE_FILE ("declaration-func.galgas", 229)) ;
      var_routineMangledName_7094.mAttribute_string.plusAssign_operation(extensionGetter_formalPassingModeString (enumerator_7462.current_mFormalArgumentPassingMode (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 230)).add_operation (enumerator_7462.current_mSelector (HERE).getter_string (SOURCE_FILE ("declaration-func.galgas", 230)), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 230)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 230)), inCompiler  COMMA_SOURCE_FILE ("declaration-func.galgas", 230)) ;
      enumerator_7462.gotoNextObject () ;
    }
    var_routineMangledName_7094.mAttribute_string.plusAssign_operation(GALGAS_string (")"), inCompiler  COMMA_SOURCE_FILE ("declaration-func.galgas", 232)) ;
    GALGAS_unifiedTypeMap_2D_proxy temp_3 ;
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, enumerator_7047.current (HERE).mAttribute_mFunctionReturnTypeName.mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_4) {
      temp_3 = GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-func.galgas", 235)) ;
    }else if (kBoolFalse == test_4) {
      temp_3 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_7047.current (HERE).mAttribute_mFunctionReturnTypeName, inCompiler  COMMA_SOURCE_FILE ("declaration-func.galgas", 237)) ;
    }
    GALGAS_unifiedTypeMap_2D_proxy var_returnType_7826 = temp_3 ;
    GALGAS_bool var_weakProcedure_8067 = GALGAS_bool (false) ;
    GALGAS_bool var_globalProcedure_8099 = GALGAS_bool (false) ;
    GALGAS_bool var_canMutateProperties_8135 = GALGAS_bool (false) ;
    GALGAS_bool var_canAccessProperties_8171 = GALGAS_bool (false) ;
    cEnumerator_lstringlist enumerator_8235 (enumerator_7047.current (HERE).mAttribute_mFunctionAttributeList, kEnumeration_up) ;
    bool bool_5 = var_weakProcedure_8067.operator_not (SOURCE_FILE ("declaration-func.galgas", 244)).isValidAndTrue () ;
    if (enumerator_8235.hasCurrentObject () && bool_5) {
      while (enumerator_8235.hasCurrentObject () && bool_5) {
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, enumerator_8235.current_mValue (HERE).mAttribute_string.objectCompare (function_weakAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 245)))).boolEnum () ;
        if (kBoolTrue == test_6) {
          var_weakProcedure_8067 = GALGAS_bool (true) ;
        }
        const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, enumerator_8235.current_mValue (HERE).mAttribute_string.objectCompare (function_globalAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 248)))).boolEnum () ;
        if (kBoolTrue == test_7) {
          var_globalProcedure_8099 = GALGAS_bool (true) ;
        }
        const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, enumerator_8235.current_mValue (HERE).mAttribute_string.objectCompare (function_mutatingAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 251)))).boolEnum () ;
        if (kBoolTrue == test_8) {
          var_canMutateProperties_8135 = GALGAS_bool (true) ;
        }
        enumerator_8235.gotoNextObject () ;
        if (enumerator_8235.hasCurrentObject ()) {
          bool_5 = var_weakProcedure_8067.operator_not (SOURCE_FILE ("declaration-func.galgas", 244)).isValidAndTrue () ;
        }
      }
    }
    var_canAccessProperties_8171 = GALGAS_bool (kIsNotEqual, enumerator_7047.current (HERE).mAttribute_mMode.objectCompare (GALGAS_mode::constructor_userMode (SOURCE_FILE ("declaration-func.galgas", 261)))) ;
    const enumGalgasBool test_9 = ioArgument_ioContext.mAttribute_mRoutineMapForContext.getter_hasKey (var_routineMangledName_7094.mAttribute_string COMMA_SOURCE_FILE ("declaration-func.galgas", 266)).boolEnum () ;
    if (kBoolTrue == test_9) {
      GALGAS_bool var_weak_9165 = ioArgument_ioContext.mAttribute_mRoutineMapForContext.getter_mWeakForKey (var_routineMangledName_7094.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 267)) ;
      GALGAS_bool test_10 = var_weakProcedure_8067 ;
      if (kBoolTrue == test_10.boolEnum ()) {
        test_10 = var_weak_9165.operator_not (SOURCE_FILE ("declaration-func.galgas", 268)) ;
      }
      const enumGalgasBool test_11 = test_10.boolEnum () ;
      if (kBoolTrue == test_11) {
      }else if (kBoolFalse == test_11) {
        GALGAS_bool test_12 = var_weakProcedure_8067 ;
        if (kBoolTrue == test_12.boolEnum ()) {
          test_12 = var_weak_9165 ;
        }
        const enumGalgasBool test_13 = test_12.boolEnum () ;
        if (kBoolTrue == test_13) {
          TC_Array <C_FixItDescription> fixItArray14 ;
          inCompiler->emitSemanticError (enumerator_7047.current (HERE).mAttribute_mFunctionName.getter_location (SOURCE_FILE ("declaration-func.galgas", 271)), GALGAS_string ("this weak procedure overrides a weak procedure"), fixItArray14  COMMA_SOURCE_FILE ("declaration-func.galgas", 271)) ;
        }else if (kBoolFalse == test_13) {
          GALGAS_bool test_15 = var_weakProcedure_8067.operator_not (SOURCE_FILE ("declaration-func.galgas", 272)) ;
          if (kBoolTrue == test_15.boolEnum ()) {
            test_15 = var_weak_9165 ;
          }
          const enumGalgasBool test_16 = test_15.boolEnum () ;
          if (kBoolTrue == test_16) {
            {
            GALGAS_lstring joker_9574_11 ; // Joker input parameter
            GALGAS_bool joker_9574_10 ; // Joker input parameter
            GALGAS_bool joker_9574_9 ; // Joker input parameter
            GALGAS_mode joker_9574_8 ; // Joker input parameter
            GALGAS_procedureSignature joker_9574_7 ; // Joker input parameter
            GALGAS_routineKind joker_9574_6 ; // Joker input parameter
            GALGAS_bool joker_9574_5 ; // Joker input parameter
            GALGAS_unifiedTypeMap_2D_proxy joker_9574_4 ; // Joker input parameter
            GALGAS_bool joker_9574_3 ; // Joker input parameter
            GALGAS_bool joker_9574_2 ; // Joker input parameter
            GALGAS_bool joker_9574_1 ; // Joker input parameter
            ioArgument_ioContext.mAttribute_mRoutineMapForContext.setter_removeKey (var_routineMangledName_7094, joker_9574_11, joker_9574_10, joker_9574_9, joker_9574_8, joker_9574_7, joker_9574_6, joker_9574_5, joker_9574_4, joker_9574_3, joker_9574_2, joker_9574_1, inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 273)) ;
            }
            {
            ioArgument_ioContext.mAttribute_mRoutineMapForContext.setter_insertKey (var_routineMangledName_7094, var_routineMangledName_7094, enumerator_7047.current (HERE).mAttribute_mPublicFunction, var_globalProcedure_8099, enumerator_7047.current (HERE).mAttribute_mMode, var_signature_7346, GALGAS_routineKind::constructor_function (SOURCE_FILE ("declaration-func.galgas", 281)), var_weakProcedure_8067, var_returnType_7826, GALGAS_bool (false), var_canMutateProperties_8135, var_canAccessProperties_8171, inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 274)) ;
            }
          }else if (kBoolFalse == test_16) {
            {
            ioArgument_ioContext.mAttribute_mRoutineMapForContext.setter_insertKey (var_routineMangledName_7094, var_routineMangledName_7094, enumerator_7047.current (HERE).mAttribute_mPublicFunction, var_globalProcedure_8099, enumerator_7047.current (HERE).mAttribute_mMode, var_signature_7346, GALGAS_routineKind::constructor_function (SOURCE_FILE ("declaration-func.galgas", 296)), var_weakProcedure_8067, var_returnType_7826, GALGAS_bool (false), var_canMutateProperties_8135, var_canAccessProperties_8171, inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 289)) ;
            }
          }
        }
      }
    }else if (kBoolFalse == test_9) {
      {
      ioArgument_ioContext.mAttribute_mRoutineMapForContext.setter_insertKey (var_routineMangledName_7094, var_routineMangledName_7094, enumerator_7047.current (HERE).mAttribute_mPublicFunction, var_globalProcedure_8099, enumerator_7047.current (HERE).mAttribute_mMode, var_signature_7346, GALGAS_routineKind::constructor_function (SOURCE_FILE ("declaration-func.galgas", 312)), var_weakProcedure_8067, var_returnType_7826, GALGAS_bool (false), var_canMutateProperties_8135, var_canAccessProperties_8171, inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 305)) ;
      }
    }
    enumerator_7047.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Extension method '@functionDeclarationListAST procedureSemanticAnalysis'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_procedureSemanticAnalysis (const GALGAS_functionDeclarationListAST inObject,
                                                GALGAS_unifiedTypeMap_2D_proxy inArgument_inReceiverType,
                                                const GALGAS_semanticContext constinArgument_inSemanticContext,
                                                GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                GALGAS_intermediateCodeStruct & ioArgument_ioIntermediateCodeStruct,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_functionDeclarationListAST temp_0 = inObject ;
  cEnumerator_functionDeclarationListAST enumerator_11668 (temp_0, kEnumeration_up) ;
  while (enumerator_11668.hasCurrentObject ()) {
    GALGAS_bool var_warnIfUnused_11692 = GALGAS_bool (true) ;
    GALGAS_bool var_globalProcedure_11723 = GALGAS_bool (false) ;
    GALGAS_bool var_weakProcedure_11753 = GALGAS_bool (false) ;
    cEnumerator_lstringlist enumerator_11817 (enumerator_11668.current (HERE).mAttribute_mFunctionAttributeList, kEnumeration_up) ;
    while (enumerator_11817.hasCurrentObject ()) {
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, enumerator_11817.current_mValue (HERE).mAttribute_string.objectCompare (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 338)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        const enumGalgasBool test_2 = var_warnIfUnused_11692.operator_not (SOURCE_FILE ("declaration-func.galgas", 339)).boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (enumerator_11817.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-func.galgas", 340)), GALGAS_string ("duplicated @").add_operation (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 340)), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 340)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 340)), fixItArray3  COMMA_SOURCE_FILE ("declaration-func.galgas", 340)) ;
        }
        var_warnIfUnused_11692 = GALGAS_bool (false) ;
      }else if (kBoolFalse == test_1) {
        const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, enumerator_11817.current_mValue (HERE).mAttribute_string.objectCompare (function_globalAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 343)))).boolEnum () ;
        if (kBoolTrue == test_4) {
          const enumGalgasBool test_5 = var_globalProcedure_11723.boolEnum () ;
          if (kBoolTrue == test_5) {
            TC_Array <C_FixItDescription> fixItArray6 ;
            inCompiler->emitSemanticError (enumerator_11817.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-func.galgas", 345)), GALGAS_string ("duplicated @").add_operation (function_globalAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 345)), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 345)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 345)), fixItArray6  COMMA_SOURCE_FILE ("declaration-func.galgas", 345)) ;
          }
          var_globalProcedure_11723 = GALGAS_bool (true) ;
        }else if (kBoolFalse == test_4) {
          const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, enumerator_11817.current_mValue (HERE).mAttribute_string.objectCompare (function_weakAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 348)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            const enumGalgasBool test_8 = var_weakProcedure_11753.boolEnum () ;
            if (kBoolTrue == test_8) {
              TC_Array <C_FixItDescription> fixItArray9 ;
              inCompiler->emitSemanticError (enumerator_11817.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-func.galgas", 350)), GALGAS_string ("duplicated @").add_operation (function_weakAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 350)), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 350)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 350)), fixItArray9  COMMA_SOURCE_FILE ("declaration-func.galgas", 350)) ;
            }
            var_weakProcedure_11753 = GALGAS_bool (true) ;
          }else if (kBoolFalse == test_7) {
            TC_Array <C_FixItDescription> fixItArray10 ;
            inCompiler->emitSemanticError (enumerator_11817.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-func.galgas", 354)), GALGAS_string ("unknown attribute; available attributes are @").add_operation (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 355)), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 354)).add_operation (GALGAS_string (", @"), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 355)).add_operation (function_weakAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 355)), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 355)).add_operation (GALGAS_string (", @"), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 355)).add_operation (function_globalAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 355)), inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 355)), fixItArray10  COMMA_SOURCE_FILE ("declaration-func.galgas", 354)) ;
          }
        }
      }
      enumerator_11817.gotoNextObject () ;
    }
    {
    routine_routineSemanticAnalysis (inArgument_inReceiverType, GALGAS_routineKind::constructor_function (SOURCE_FILE ("declaration-func.galgas", 360)), enumerator_11668.current (HERE).mAttribute_mMode, enumerator_11668.current (HERE).mAttribute_mFunctionName, enumerator_11668.current (HERE).mAttribute_mFunctionFormalArgumentList, enumerator_11668.current (HERE).mAttribute_mFunctionReturnTypeName, enumerator_11668.current (HERE).mAttribute_mFunctionInstructionList, enumerator_11668.current (HERE).mAttribute_mEndOfFunctionDeclaration, GALGAS_bool (true), GALGAS_bool (true), var_warnIfUnused_11692, var_globalProcedure_11723, var_weakProcedure_11753, constinArgument_inSemanticContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler  COMMA_SOURCE_FILE ("declaration-func.galgas", 358)) ;
    }
    enumerator_11668.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                  Extension method '@externProcedureDeclarationListAST noteTypesInPrecedenceGraph'                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_noteTypesInPrecedenceGraph (const GALGAS_externProcedureDeclarationListAST inObject,
                                                 GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_externProcedureDeclarationListAST temp_0 = inObject ;
  cEnumerator_externProcedureDeclarationListAST enumerator_2220 (temp_0, kEnumeration_up) ;
  while (enumerator_2220.hasCurrentObject ()) {
    cEnumerator_procFormalArgumentList enumerator_2289 (enumerator_2220.current_mProcFormalArgumentList (HERE), kEnumeration_up) ;
    while (enumerator_2289.hasCurrentObject ()) {
      GALGAS_lstring var_typeName_2311 = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (enumerator_2289.current_mFormalArgumentTypeName (HERE).getter_string (SOURCE_FILE ("declaration-extern-proc.galgas", 52)), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 52)), enumerator_2289.current_mFormalArgumentTypeName (HERE).mAttribute_location  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 52)) ;
      {
      ioArgument_ioGraph.setter_noteNode (var_typeName_2311 COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 53)) ;
      }
      enumerator_2289.gotoNextObject () ;
    }
    enumerator_2220.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   Extension method '@externProcedureDeclarationListAST enterExternProcInContext'                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterExternProcInContext (const GALGAS_externProcedureDeclarationListAST inObject,
                                               GALGAS_semanticContext & ioArgument_ioContext,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_externProcedureDeclarationListAST temp_0 = inObject ;
  cEnumerator_externProcedureDeclarationListAST enumerator_2947 (temp_0, kEnumeration_up) ;
  while (enumerator_2947.hasCurrentObject ()) {
    extensionMethod_enterExternProcInContext (enumerator_2947.current (HERE), ioArgument_ioContext, inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 66)) ;
    enumerator_2947.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                Extension method '@externProcedureDeclarationListAST externProcedureSemanticAnalysis'                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_externProcedureSemanticAnalysis (const GALGAS_externProcedureDeclarationListAST inObject,
                                                      const GALGAS_semanticContext constinArgument_inContext,
                                                      GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                      GALGAS_intermediateCodeStruct & ioArgument_ioIntermediateCodeStruct,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_externProcedureDeclarationListAST temp_0 = inObject ;
  cEnumerator_externProcedureDeclarationListAST enumerator_5179 (temp_0, kEnumeration_up) ;
  while (enumerator_5179.hasCurrentObject ()) {
    extensionMethod_externProcedureSemanticAnalysis (enumerator_5179.current (HERE), constinArgument_inContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 122)) ;
    enumerator_5179.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*

cMapElement_externProcedureMapIR::cMapElement_externProcedureMapIR (const GALGAS_lstring & inKey,
                                                                    const GALGAS_procFormalArgumentListForGeneration & in_mFormalArgumentListForGeneration,
                                                                    const GALGAS_unifiedTypeMap_2D_proxy & in_mReturnType
                                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_mFormalArgumentListForGeneration (in_mFormalArgumentListForGeneration),
mAttribute_mReturnType (in_mReturnType) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_externProcedureMapIR::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mFormalArgumentListForGeneration.isValid () && mAttribute_mReturnType.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_externProcedureMapIR::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_externProcedureMapIR (mAttribute_lkey, mAttribute_mFormalArgumentListForGeneration, mAttribute_mReturnType COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_externProcedureMapIR::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFormalArgumentListForGeneration" ":" ;
  mAttribute_mFormalArgumentListForGeneration.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mReturnType" ":" ;
  mAttribute_mReturnType.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_externProcedureMapIR::compare (const cCollectionElement * inOperand) const {
  cMapElement_externProcedureMapIR * operand = (cMapElement_externProcedureMapIR *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_mFormalArgumentListForGeneration.objectCompare (operand->mAttribute_mFormalArgumentListForGeneration) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mReturnType.objectCompare (operand->mAttribute_mReturnType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureMapIR::GALGAS_externProcedureMapIR (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureMapIR::GALGAS_externProcedureMapIR (const GALGAS_externProcedureMapIR & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureMapIR & GALGAS_externProcedureMapIR::operator = (const GALGAS_externProcedureMapIR & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureMapIR GALGAS_externProcedureMapIR::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_externProcedureMapIR result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureMapIR GALGAS_externProcedureMapIR::constructor_mapWithMapToOverride (const GALGAS_externProcedureMapIR & inMapToOverride
                                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_externProcedureMapIR result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureMapIR GALGAS_externProcedureMapIR::getter_overriddenMap (C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_externProcedureMapIR result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureMapIR::addAssign_operation (const GALGAS_lstring & inKey,
                                                       const GALGAS_procFormalArgumentListForGeneration & inArgument0,
                                                       const GALGAS_unifiedTypeMap_2D_proxy & inArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cMapElement_externProcedureMapIR * p = NULL ;
  macroMyNew (p, cMapElement_externProcedureMapIR (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@externProcedureMapIR insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureMapIR::setter_insertKey (GALGAS_lstring inKey,
                                                    GALGAS_procFormalArgumentListForGeneration inArgument0,
                                                    GALGAS_unifiedTypeMap_2D_proxy inArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_externProcedureMapIR * p = NULL ;
  macroMyNew (p, cMapElement_externProcedureMapIR (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "extern procedure %K is already declared" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration GALGAS_externProcedureMapIR::getter_mFormalArgumentListForGenerationForKey (const GALGAS_string & inKey,
                                                                                                                       C_Compiler * inCompiler
                                                                                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_externProcedureMapIR * p = (const cMapElement_externProcedureMapIR *) attributes ;
  GALGAS_procFormalArgumentListForGeneration result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_externProcedureMapIR) ;
    result = p->mAttribute_mFormalArgumentListForGeneration ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_externProcedureMapIR::getter_mReturnTypeForKey (const GALGAS_string & inKey,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_externProcedureMapIR * p = (const cMapElement_externProcedureMapIR *) attributes ;
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_externProcedureMapIR) ;
    result = p->mAttribute_mReturnType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureMapIR::setter_setMFormalArgumentListForGenerationForKey (GALGAS_procFormalArgumentListForGeneration inAttributeValue,
                                                                                    GALGAS_string inKey,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_externProcedureMapIR * p = (cMapElement_externProcedureMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_externProcedureMapIR) ;
    p->mAttribute_mFormalArgumentListForGeneration = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureMapIR::setter_setMReturnTypeForKey (GALGAS_unifiedTypeMap_2D_proxy inAttributeValue,
                                                               GALGAS_string inKey,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_externProcedureMapIR * p = (cMapElement_externProcedureMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_externProcedureMapIR) ;
    p->mAttribute_mReturnType = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_externProcedureMapIR * GALGAS_externProcedureMapIR::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                   const GALGAS_string & inKey
                                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_externProcedureMapIR * result = (cMapElement_externProcedureMapIR *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_externProcedureMapIR) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_externProcedureMapIR::cEnumerator_externProcedureMapIR (const GALGAS_externProcedureMapIR & inEnumeratedObject,
                                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureMapIR_2D_element cEnumerator_externProcedureMapIR::current (LOCATION_ARGS) const {
  const cMapElement_externProcedureMapIR * p = (const cMapElement_externProcedureMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_externProcedureMapIR) ;
  return GALGAS_externProcedureMapIR_2D_element (p->mAttribute_lkey, p->mAttribute_mFormalArgumentListForGeneration, p->mAttribute_mReturnType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_externProcedureMapIR::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration cEnumerator_externProcedureMapIR::current_mFormalArgumentListForGeneration (LOCATION_ARGS) const {
  const cMapElement_externProcedureMapIR * p = (const cMapElement_externProcedureMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_externProcedureMapIR) ;
  return p->mAttribute_mFormalArgumentListForGeneration ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cEnumerator_externProcedureMapIR::current_mReturnType (LOCATION_ARGS) const {
  const cMapElement_externProcedureMapIR * p = (const cMapElement_externProcedureMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_externProcedureMapIR) ;
  return p->mAttribute_mReturnType ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @externProcedureMapIR type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_externProcedureMapIR ("externProcedureMapIR",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_externProcedureMapIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_externProcedureMapIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_externProcedureMapIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_externProcedureMapIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureMapIR GALGAS_externProcedureMapIR::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_externProcedureMapIR result ;
  const GALGAS_externProcedureMapIR * p = (const GALGAS_externProcedureMapIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_externProcedureMapIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("externProcedureMapIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Class for element of '@procFormalArgumentListForGeneration' list                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_procFormalArgumentListForGeneration : public cCollectionElement {
  public : GALGAS_procFormalArgumentListForGeneration_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_procFormalArgumentListForGeneration (const GALGAS_procFormalArgumentPassingMode & in_mFormalArgumentKind,
                                                                   const GALGAS_unifiedTypeMap_2D_proxy & in_mFormalArgumentType,
                                                                   const GALGAS_string & in_mFormalArgumentName
                                                                   COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_procFormalArgumentListForGeneration::cCollectionElement_procFormalArgumentListForGeneration (const GALGAS_procFormalArgumentPassingMode & in_mFormalArgumentKind,
                                                                                                                const GALGAS_unifiedTypeMap_2D_proxy & in_mFormalArgumentType,
                                                                                                                const GALGAS_string & in_mFormalArgumentName
                                                                                                                COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mFormalArgumentKind, in_mFormalArgumentType, in_mFormalArgumentName) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_procFormalArgumentListForGeneration::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_procFormalArgumentListForGeneration::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_procFormalArgumentListForGeneration (mObject.mAttribute_mFormalArgumentKind, mObject.mAttribute_mFormalArgumentType, mObject.mAttribute_mFormalArgumentName COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_procFormalArgumentListForGeneration::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFormalArgumentKind" ":" ;
  mObject.mAttribute_mFormalArgumentKind.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFormalArgumentType" ":" ;
  mObject.mAttribute_mFormalArgumentType.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFormalArgumentName" ":" ;
  mObject.mAttribute_mFormalArgumentName.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_procFormalArgumentListForGeneration::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_procFormalArgumentListForGeneration * operand = (cCollectionElement_procFormalArgumentListForGeneration *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_procFormalArgumentListForGeneration) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration::GALGAS_procFormalArgumentListForGeneration (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration::GALGAS_procFormalArgumentListForGeneration (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration GALGAS_procFormalArgumentListForGeneration::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_procFormalArgumentListForGeneration result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration GALGAS_procFormalArgumentListForGeneration::constructor_listWithValue (const GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                                                                  const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                                                                  const GALGAS_string & inOperand2
                                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_procFormalArgumentListForGeneration result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_procFormalArgumentListForGeneration::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentListForGeneration::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                            const GALGAS_procFormalArgumentPassingMode & in_mFormalArgumentKind,
                                                                            const GALGAS_unifiedTypeMap_2D_proxy & in_mFormalArgumentType,
                                                                            const GALGAS_string & in_mFormalArgumentName
                                                                            COMMA_LOCATION_ARGS) {
  cCollectionElement_procFormalArgumentListForGeneration * p = NULL ;
  macroMyNew (p, cCollectionElement_procFormalArgumentListForGeneration (in_mFormalArgumentKind,
                                                                         in_mFormalArgumentType,
                                                                         in_mFormalArgumentName COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentListForGeneration::addAssign_operation (const GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                      const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                      const GALGAS_string & inOperand2
                                                                      COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_procFormalArgumentListForGeneration (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentListForGeneration::setter_insertAtIndex (const GALGAS_procFormalArgumentPassingMode inOperand0,
                                                                       const GALGAS_unifiedTypeMap_2D_proxy inOperand1,
                                                                       const GALGAS_string inOperand2,
                                                                       const GALGAS_uint inInsertionIndex,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_procFormalArgumentListForGeneration (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentListForGeneration::setter_removeAtIndex (GALGAS_procFormalArgumentPassingMode & outOperand0,
                                                                       GALGAS_unifiedTypeMap_2D_proxy & outOperand1,
                                                                       GALGAS_string & outOperand2,
                                                                       const GALGAS_uint inRemoveIndex,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_procFormalArgumentListForGeneration * p = (cCollectionElement_procFormalArgumentListForGeneration *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_procFormalArgumentListForGeneration) ;
      outOperand0 = p->mObject.mAttribute_mFormalArgumentKind ;
      outOperand1 = p->mObject.mAttribute_mFormalArgumentType ;
      outOperand2 = p->mObject.mAttribute_mFormalArgumentName ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentListForGeneration::setter_popFirst (GALGAS_procFormalArgumentPassingMode & outOperand0,
                                                                  GALGAS_unifiedTypeMap_2D_proxy & outOperand1,
                                                                  GALGAS_string & outOperand2,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentListForGeneration * p = (cCollectionElement_procFormalArgumentListForGeneration *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentListForGeneration) ;
    outOperand0 = p->mObject.mAttribute_mFormalArgumentKind ;
    outOperand1 = p->mObject.mAttribute_mFormalArgumentType ;
    outOperand2 = p->mObject.mAttribute_mFormalArgumentName ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentListForGeneration::setter_popLast (GALGAS_procFormalArgumentPassingMode & outOperand0,
                                                                 GALGAS_unifiedTypeMap_2D_proxy & outOperand1,
                                                                 GALGAS_string & outOperand2,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentListForGeneration * p = (cCollectionElement_procFormalArgumentListForGeneration *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentListForGeneration) ;
    outOperand0 = p->mObject.mAttribute_mFormalArgumentKind ;
    outOperand1 = p->mObject.mAttribute_mFormalArgumentType ;
    outOperand2 = p->mObject.mAttribute_mFormalArgumentName ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentListForGeneration::method_first (GALGAS_procFormalArgumentPassingMode & outOperand0,
                                                               GALGAS_unifiedTypeMap_2D_proxy & outOperand1,
                                                               GALGAS_string & outOperand2,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentListForGeneration * p = (cCollectionElement_procFormalArgumentListForGeneration *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentListForGeneration) ;
    outOperand0 = p->mObject.mAttribute_mFormalArgumentKind ;
    outOperand1 = p->mObject.mAttribute_mFormalArgumentType ;
    outOperand2 = p->mObject.mAttribute_mFormalArgumentName ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentListForGeneration::method_last (GALGAS_procFormalArgumentPassingMode & outOperand0,
                                                              GALGAS_unifiedTypeMap_2D_proxy & outOperand1,
                                                              GALGAS_string & outOperand2,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentListForGeneration * p = (cCollectionElement_procFormalArgumentListForGeneration *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentListForGeneration) ;
    outOperand0 = p->mObject.mAttribute_mFormalArgumentKind ;
    outOperand1 = p->mObject.mAttribute_mFormalArgumentType ;
    outOperand2 = p->mObject.mAttribute_mFormalArgumentName ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration GALGAS_procFormalArgumentListForGeneration::add_operation (const GALGAS_procFormalArgumentListForGeneration & inOperand,
                                                                                                      C_Compiler * /* inCompiler */
                                                                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_procFormalArgumentListForGeneration result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration GALGAS_procFormalArgumentListForGeneration::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                                C_Compiler * inCompiler
                                                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_procFormalArgumentListForGeneration result = GALGAS_procFormalArgumentListForGeneration::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration GALGAS_procFormalArgumentListForGeneration::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                                C_Compiler * inCompiler
                                                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_procFormalArgumentListForGeneration result = GALGAS_procFormalArgumentListForGeneration::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration GALGAS_procFormalArgumentListForGeneration::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                                              C_Compiler * inCompiler
                                                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_procFormalArgumentListForGeneration result = GALGAS_procFormalArgumentListForGeneration::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentListForGeneration::plusAssign_operation (const GALGAS_procFormalArgumentListForGeneration inOperand,
                                                                       C_Compiler * /* inCompiler */
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentPassingMode GALGAS_procFormalArgumentListForGeneration::getter_mFormalArgumentKindAtIndex (const GALGAS_uint & inIndex,
                                                                                                                    C_Compiler * inCompiler
                                                                                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentListForGeneration * p = (cCollectionElement_procFormalArgumentListForGeneration *) attributes.ptr () ;
  GALGAS_procFormalArgumentPassingMode result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentListForGeneration) ;
    result = p->mObject.mAttribute_mFormalArgumentKind ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_procFormalArgumentListForGeneration::getter_mFormalArgumentTypeAtIndex (const GALGAS_uint & inIndex,
                                                                                                              C_Compiler * inCompiler
                                                                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentListForGeneration * p = (cCollectionElement_procFormalArgumentListForGeneration *) attributes.ptr () ;
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentListForGeneration) ;
    result = p->mObject.mAttribute_mFormalArgumentType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_procFormalArgumentListForGeneration::getter_mFormalArgumentNameAtIndex (const GALGAS_uint & inIndex,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_procFormalArgumentListForGeneration * p = (cCollectionElement_procFormalArgumentListForGeneration *) attributes.ptr () ;
  GALGAS_string result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_procFormalArgumentListForGeneration) ;
    result = p->mObject.mAttribute_mFormalArgumentName ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_procFormalArgumentListForGeneration::cEnumerator_procFormalArgumentListForGeneration (const GALGAS_procFormalArgumentListForGeneration & inEnumeratedObject,
                                                                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration_2D_element cEnumerator_procFormalArgumentListForGeneration::current (LOCATION_ARGS) const {
  const cCollectionElement_procFormalArgumentListForGeneration * p = (const cCollectionElement_procFormalArgumentListForGeneration *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procFormalArgumentListForGeneration) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentPassingMode cEnumerator_procFormalArgumentListForGeneration::current_mFormalArgumentKind (LOCATION_ARGS) const {
  const cCollectionElement_procFormalArgumentListForGeneration * p = (const cCollectionElement_procFormalArgumentListForGeneration *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procFormalArgumentListForGeneration) ;
  return p->mObject.mAttribute_mFormalArgumentKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cEnumerator_procFormalArgumentListForGeneration::current_mFormalArgumentType (LOCATION_ARGS) const {
  const cCollectionElement_procFormalArgumentListForGeneration * p = (const cCollectionElement_procFormalArgumentListForGeneration *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procFormalArgumentListForGeneration) ;
  return p->mObject.mAttribute_mFormalArgumentType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_procFormalArgumentListForGeneration::current_mFormalArgumentName (LOCATION_ARGS) const {
  const cCollectionElement_procFormalArgumentListForGeneration * p = (const cCollectionElement_procFormalArgumentListForGeneration *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procFormalArgumentListForGeneration) ;
  return p->mObject.mAttribute_mFormalArgumentName ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @procFormalArgumentListForGeneration type                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procFormalArgumentListForGeneration ("procFormalArgumentListForGeneration",
                                                            NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procFormalArgumentListForGeneration::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procFormalArgumentListForGeneration ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procFormalArgumentListForGeneration::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procFormalArgumentListForGeneration (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration GALGAS_procFormalArgumentListForGeneration::extractObject (const GALGAS_object & inObject,
                                                                                                      C_Compiler * inCompiler
                                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_procFormalArgumentListForGeneration result ;
  const GALGAS_procFormalArgumentListForGeneration * p = (const GALGAS_procFormalArgumentListForGeneration *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procFormalArgumentListForGeneration *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procFormalArgumentListForGeneration", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Extension method '@externProcedureMapIR llvmPrototypeGeneration'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_llvmPrototypeGeneration (const GALGAS_externProcedureMapIR inObject,
                                              GALGAS_string & ioArgument_ioLLVMcode,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_externProcedureMapIR temp_0 = inObject ;
  cEnumerator_externProcedureMapIR enumerator_8023 (temp_0, kEnumeration_up) ;
  while (enumerator_8023.hasCurrentObject ()) {
    extensionMethod_llvmPrototypeGeneration (enumerator_8023.current (HERE), ioArgument_ioLLVMcode, inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 201)) ;
    enumerator_8023.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension method '@isrDeclarationListAST enterInContext'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterInContext (const GALGAS_isrDeclarationListAST inObject,
                                     GALGAS_semanticContext & ioArgument_ioSemanticContext,
                                     C_Compiler * /* inCompiler */
                                     COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_isrDeclarationListAST temp_0 = inObject ;
  cEnumerator_isrDeclarationListAST enumerator_2217 (temp_0, kEnumeration_up) ;
  while (enumerator_2217.hasCurrentObject ()) {
    ioArgument_ioSemanticContext.mAttribute_mDefinedInterruptSet.addAssign_operation (enumerator_2217.current (HERE).mAttribute_mISRName.mAttribute_string  COMMA_SOURCE_FILE ("declaration-isr.galgas", 53)) ;
    enumerator_2217.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension method '@isrDeclarationListAST isrSemanticAnalysis'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_isrSemanticAnalysis (const GALGAS_isrDeclarationListAST inObject,
                                          const GALGAS_semanticContext constinArgument_inSemanticContext,
                                          GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                          GALGAS_intermediateCodeStruct & ioArgument_ioIntermediateCodeStruct,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_isrDeclarationListAST temp_0 = inObject ;
  cEnumerator_isrDeclarationListAST enumerator_2905 (temp_0, kEnumeration_up) ;
  while (enumerator_2905.hasCurrentObject ()) {
    GALGAS_bool var_xtrAttribute_2955 = GALGAS_bool (false) ;
    cEnumerator_lstringlist enumerator_3008 (enumerator_2905.current (HERE).mAttribute_mISRAttributeList, kEnumeration_up) ;
    while (enumerator_3008.hasCurrentObject ()) {
      const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, enumerator_3008.current_mValue (HERE).mAttribute_string.objectCompare (GALGAS_string ("xtr"))).boolEnum () ;
      if (kBoolTrue == test_1) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        fixItArray2.addObject (C_FixItDescription (kFixItRemove, "")) ;
        inCompiler->emitSemanticError (enumerator_3008.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-isr.galgas", 71)), GALGAS_string ("only @xtr attribute is allowed here"), fixItArray2  COMMA_SOURCE_FILE ("declaration-isr.galgas", 71)) ;
      }else if (kBoolFalse == test_1) {
        const enumGalgasBool test_3 = var_xtrAttribute_2955.boolEnum () ;
        if (kBoolTrue == test_3) {
          TC_Array <C_FixItDescription> fixItArray4 ;
          fixItArray4.addObject (C_FixItDescription (kFixItRemove, "")) ;
          inCompiler->emitSemanticError (enumerator_3008.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-isr.galgas", 73)), GALGAS_string ("duplicate @xtr attribute"), fixItArray4  COMMA_SOURCE_FILE ("declaration-isr.galgas", 73)) ;
        }else if (kBoolFalse == test_3) {
          var_xtrAttribute_2955 = GALGAS_bool (true) ;
        }
      }
      enumerator_3008.gotoNextObject () ;
    }
    GALGAS_mode temp_5 ;
    const enumGalgasBool test_6 = var_xtrAttribute_2955.boolEnum () ;
    if (kBoolTrue == test_6) {
      temp_5 = GALGAS_mode::constructor_serviceMode (SOURCE_FILE ("declaration-isr.galgas", 79)) ;
    }else if (kBoolFalse == test_6) {
      temp_5 = GALGAS_mode::constructor_sectionMode (SOURCE_FILE ("declaration-isr.galgas", 79)) ;
    }
    GALGAS_mode var_mode_3321 = temp_5 ;
    GALGAS_lstring var_routineNameForInvocationGraph_3441 = function_interruptNameForInvocationGraph (enumerator_2905.current (HERE).mAttribute_mISRName, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 81)) ;
    const enumGalgasBool test_7 = ioArgument_ioTemporaries.mAttribute_mSubprogramInvocationGraph.getter_isNodeDefined (var_routineNameForInvocationGraph_3441.mAttribute_string COMMA_SOURCE_FILE ("declaration-isr.galgas", 82)).operator_not (SOURCE_FILE ("declaration-isr.galgas", 82)).boolEnum () ;
    if (kBoolTrue == test_7) {
      {
      ioArgument_ioTemporaries.mAttribute_mSubprogramInvocationGraph.setter_addNode (var_routineNameForInvocationGraph_3441, var_routineNameForInvocationGraph_3441, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 83)) ;
      }
    }
    GALGAS_variableMap var_variableMap_4011 ;
    {
    routine_initialVariableMap (constinArgument_inSemanticContext, var_mode_3321, GALGAS_bool (false), GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("declaration-isr.galgas", 95)), var_variableMap_4011, inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 89)) ;
    }
    GALGAS_unifiedTypeMap_2D_proxy temp_8 ;
    const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, enumerator_2905.current (HERE).mAttribute_mSelfTypeName.mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_9) {
      temp_8 = GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-isr.galgas", 100)) ;
    }else if (kBoolFalse == test_9) {
      temp_8 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inSemanticContext.mAttribute_mTypeMap, enumerator_2905.current (HERE).mAttribute_mSelfTypeName, inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 102)) ;
    }
    GALGAS_unifiedTypeMap_2D_proxy var_selfType_4051 = temp_8 ;
    GALGAS_allocaList var_allocaList_4288 = GALGAS_allocaList::constructor_emptyList (SOURCE_FILE ("declaration-isr.galgas", 105)) ;
    GALGAS_instructionListIR var_instructionGenerationList_4342 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("declaration-isr.galgas", 106)) ;
    extensionMethod_analyzeRoutineInstructionList (enumerator_2905.current (HERE).mAttribute_mISRInstructionList, var_selfType_4051, GALGAS_bool (true), GALGAS_bool (true), var_routineNameForInvocationGraph_3441, constinArgument_inSemanticContext, var_mode_3321, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct.mAttribute_mStaticStringMap, var_variableMap_4011, var_allocaList_4288, var_instructionGenerationList_4342, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 107)) ;
    var_variableMap_4011.method_checkAutomatonStates (enumerator_2905.current (HERE).mAttribute_mEndOfISRDeclaration, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 122)) ;
    GALGAS_interruptionPanicCode joker_5081 ; // Joker input parameter
    constinArgument_inSemanticContext.mAttribute_mAvailableInterruptMap.method_searchKey (enumerator_2905.current (HERE).mAttribute_mISRName, joker_5081, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 125)) ;
    {
    ioArgument_ioIntermediateCodeStruct.mAttribute_mInterruptMapIR.setter_insertKey (enumerator_2905.current (HERE).mAttribute_mISRName, var_selfType_4051, enumerator_2905.current (HERE).mAttribute_mGlobalVariableName, var_allocaList_4288, var_instructionGenerationList_4342, var_xtrAttribute_2955, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 126)) ;
    }
    enumerator_2905.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*

cMapElement_interruptMapIR::cMapElement_interruptMapIR (const GALGAS_lstring & inKey,
                                                        const GALGAS_unifiedTypeMap_2D_proxy & in_mSelfType,
                                                        const GALGAS_string & in_mGlobalVariableName,
                                                        const GALGAS_allocaList & in_mAllocaList,
                                                        const GALGAS_instructionListIR & in_mInstructionGenerationList,
                                                        const GALGAS_bool & in_mXTR
                                                        COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_mSelfType (in_mSelfType),
mAttribute_mGlobalVariableName (in_mGlobalVariableName),
mAttribute_mAllocaList (in_mAllocaList),
mAttribute_mInstructionGenerationList (in_mInstructionGenerationList),
mAttribute_mXTR (in_mXTR) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_interruptMapIR::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mSelfType.isValid () && mAttribute_mGlobalVariableName.isValid () && mAttribute_mAllocaList.isValid () && mAttribute_mInstructionGenerationList.isValid () && mAttribute_mXTR.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_interruptMapIR::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_interruptMapIR (mAttribute_lkey, mAttribute_mSelfType, mAttribute_mGlobalVariableName, mAttribute_mAllocaList, mAttribute_mInstructionGenerationList, mAttribute_mXTR COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_interruptMapIR::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSelfType" ":" ;
  mAttribute_mSelfType.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGlobalVariableName" ":" ;
  mAttribute_mGlobalVariableName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAllocaList" ":" ;
  mAttribute_mAllocaList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mInstructionGenerationList" ":" ;
  mAttribute_mInstructionGenerationList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mXTR" ":" ;
  mAttribute_mXTR.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_interruptMapIR::compare (const cCollectionElement * inOperand) const {
  cMapElement_interruptMapIR * operand = (cMapElement_interruptMapIR *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_mSelfType.objectCompare (operand->mAttribute_mSelfType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mGlobalVariableName.objectCompare (operand->mAttribute_mGlobalVariableName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mAllocaList.objectCompare (operand->mAttribute_mAllocaList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mInstructionGenerationList.objectCompare (operand->mAttribute_mInstructionGenerationList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mXTR.objectCompare (operand->mAttribute_mXTR) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR::GALGAS_interruptMapIR (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR::GALGAS_interruptMapIR (const GALGAS_interruptMapIR & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR & GALGAS_interruptMapIR::operator = (const GALGAS_interruptMapIR & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR GALGAS_interruptMapIR::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_interruptMapIR result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR GALGAS_interruptMapIR::constructor_mapWithMapToOverride (const GALGAS_interruptMapIR & inMapToOverride
                                                                               COMMA_LOCATION_ARGS) {
  GALGAS_interruptMapIR result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR GALGAS_interruptMapIR::getter_overriddenMap (C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_interruptMapIR result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptMapIR::addAssign_operation (const GALGAS_lstring & inKey,
                                                 const GALGAS_unifiedTypeMap_2D_proxy & inArgument0,
                                                 const GALGAS_string & inArgument1,
                                                 const GALGAS_allocaList & inArgument2,
                                                 const GALGAS_instructionListIR & inArgument3,
                                                 const GALGAS_bool & inArgument4,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_interruptMapIR * p = NULL ;
  macroMyNew (p, cMapElement_interruptMapIR (inKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@interruptMapIR insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptMapIR::setter_insertKey (GALGAS_lstring inKey,
                                              GALGAS_unifiedTypeMap_2D_proxy inArgument0,
                                              GALGAS_string inArgument1,
                                              GALGAS_allocaList inArgument2,
                                              GALGAS_instructionListIR inArgument3,
                                              GALGAS_bool inArgument4,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cMapElement_interruptMapIR * p = NULL ;
  macroMyNew (p, cMapElement_interruptMapIR (inKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "interrupt '%K' is already defined" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_interruptMapIR_searchKey = "** internal error **" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptMapIR::method_searchKey (GALGAS_lstring inKey,
                                              GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                              GALGAS_string & outArgument1,
                                              GALGAS_allocaList & outArgument2,
                                              GALGAS_instructionListIR & outArgument3,
                                              GALGAS_bool & outArgument4,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  const cMapElement_interruptMapIR * p = (const cMapElement_interruptMapIR *) performSearch (inKey,
                                                                                               inCompiler,
                                                                                               kSearchErrorMessage_interruptMapIR_searchKey
                                                                                               COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
    outArgument2.drop () ;
    outArgument3.drop () ;
    outArgument4.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_interruptMapIR) ;
    outArgument0 = p->mAttribute_mSelfType ;
    outArgument1 = p->mAttribute_mGlobalVariableName ;
    outArgument2 = p->mAttribute_mAllocaList ;
    outArgument3 = p->mAttribute_mInstructionGenerationList ;
    outArgument4 = p->mAttribute_mXTR ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptMapIR::setter_removeKey (GALGAS_lstring inKey,
                                              GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                              GALGAS_string & outArgument1,
                                              GALGAS_allocaList & outArgument2,
                                              GALGAS_instructionListIR & outArgument3,
                                              GALGAS_bool & outArgument4,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "** internal error **" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_interruptMapIR * p = (cMapElement_interruptMapIR *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_interruptMapIR) ;
    outArgument0 = p->mAttribute_mSelfType ;
    outArgument1 = p->mAttribute_mGlobalVariableName ;
    outArgument2 = p->mAttribute_mAllocaList ;
    outArgument3 = p->mAttribute_mInstructionGenerationList ;
    outArgument4 = p->mAttribute_mXTR ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_interruptMapIR::getter_mSelfTypeForKey (const GALGAS_string & inKey,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_interruptMapIR * p = (const cMapElement_interruptMapIR *) attributes ;
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_interruptMapIR) ;
    result = p->mAttribute_mSelfType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_interruptMapIR::getter_mGlobalVariableNameForKey (const GALGAS_string & inKey,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_interruptMapIR * p = (const cMapElement_interruptMapIR *) attributes ;
  GALGAS_string result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_interruptMapIR) ;
    result = p->mAttribute_mGlobalVariableName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList GALGAS_interruptMapIR::getter_mAllocaListForKey (const GALGAS_string & inKey,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_interruptMapIR * p = (const cMapElement_interruptMapIR *) attributes ;
  GALGAS_allocaList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_interruptMapIR) ;
    result = p->mAttribute_mAllocaList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_interruptMapIR::getter_mInstructionGenerationListForKey (const GALGAS_string & inKey,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_interruptMapIR * p = (const cMapElement_interruptMapIR *) attributes ;
  GALGAS_instructionListIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_interruptMapIR) ;
    result = p->mAttribute_mInstructionGenerationList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_interruptMapIR::getter_mXTRForKey (const GALGAS_string & inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_interruptMapIR * p = (const cMapElement_interruptMapIR *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_interruptMapIR) ;
    result = p->mAttribute_mXTR ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptMapIR::setter_setMSelfTypeForKey (GALGAS_unifiedTypeMap_2D_proxy inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_interruptMapIR * p = (cMapElement_interruptMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_interruptMapIR) ;
    p->mAttribute_mSelfType = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptMapIR::setter_setMGlobalVariableNameForKey (GALGAS_string inAttributeValue,
                                                                 GALGAS_string inKey,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_interruptMapIR * p = (cMapElement_interruptMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_interruptMapIR) ;
    p->mAttribute_mGlobalVariableName = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptMapIR::setter_setMAllocaListForKey (GALGAS_allocaList inAttributeValue,
                                                         GALGAS_string inKey,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_interruptMapIR * p = (cMapElement_interruptMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_interruptMapIR) ;
    p->mAttribute_mAllocaList = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptMapIR::setter_setMInstructionGenerationListForKey (GALGAS_instructionListIR inAttributeValue,
                                                                        GALGAS_string inKey,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_interruptMapIR * p = (cMapElement_interruptMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_interruptMapIR) ;
    p->mAttribute_mInstructionGenerationList = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptMapIR::setter_setMXTRForKey (GALGAS_bool inAttributeValue,
                                                  GALGAS_string inKey,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_interruptMapIR * p = (cMapElement_interruptMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_interruptMapIR) ;
    p->mAttribute_mXTR = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_interruptMapIR * GALGAS_interruptMapIR::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) {
  cMapElement_interruptMapIR * result = (cMapElement_interruptMapIR *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_interruptMapIR) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_interruptMapIR::cEnumerator_interruptMapIR (const GALGAS_interruptMapIR & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR_2D_element cEnumerator_interruptMapIR::current (LOCATION_ARGS) const {
  const cMapElement_interruptMapIR * p = (const cMapElement_interruptMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_interruptMapIR) ;
  return GALGAS_interruptMapIR_2D_element (p->mAttribute_lkey, p->mAttribute_mSelfType, p->mAttribute_mGlobalVariableName, p->mAttribute_mAllocaList, p->mAttribute_mInstructionGenerationList, p->mAttribute_mXTR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_interruptMapIR::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cEnumerator_interruptMapIR::current_mSelfType (LOCATION_ARGS) const {
  const cMapElement_interruptMapIR * p = (const cMapElement_interruptMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_interruptMapIR) ;
  return p->mAttribute_mSelfType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_interruptMapIR::current_mGlobalVariableName (LOCATION_ARGS) const {
  const cMapElement_interruptMapIR * p = (const cMapElement_interruptMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_interruptMapIR) ;
  return p->mAttribute_mGlobalVariableName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList cEnumerator_interruptMapIR::current_mAllocaList (LOCATION_ARGS) const {
  const cMapElement_interruptMapIR * p = (const cMapElement_interruptMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_interruptMapIR) ;
  return p->mAttribute_mAllocaList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cEnumerator_interruptMapIR::current_mInstructionGenerationList (LOCATION_ARGS) const {
  const cMapElement_interruptMapIR * p = (const cMapElement_interruptMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_interruptMapIR) ;
  return p->mAttribute_mInstructionGenerationList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_interruptMapIR::current_mXTR (LOCATION_ARGS) const {
  const cMapElement_interruptMapIR * p = (const cMapElement_interruptMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_interruptMapIR) ;
  return p->mAttribute_mXTR ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @interruptMapIR type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_interruptMapIR ("interruptMapIR",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_interruptMapIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_interruptMapIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_interruptMapIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_interruptMapIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR GALGAS_interruptMapIR::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_interruptMapIR result ;
  const GALGAS_interruptMapIR * p = (const GALGAS_interruptMapIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_interruptMapIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("interruptMapIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension method '@interruptMapIR interruptCodeGeneration'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_interruptCodeGeneration (const GALGAS_interruptMapIR inObject,
                                              GALGAS_string & ioArgument_ioLLVMcode,
                                              GALGAS_string & ioArgument_ioAScode,
                                              const GALGAS_string constinArgument_inUndefinedInterruptString,
                                              const GALGAS_string constinArgument_inXTRInterruptHandlerString,
                                              const GALGAS_generationContext constinArgument_inGenerationContext,
                                              GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringset var_definedInterrupts_6391 = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("declaration-isr.galgas", 158)) ;
  const GALGAS_interruptMapIR temp_0 = inObject ;
  cEnumerator_interruptMapIR enumerator_6420 (temp_0, kEnumeration_up) ;
  while (enumerator_6420.hasCurrentObject ()) {
    var_definedInterrupts_6391.addAssign_operation (enumerator_6420.current (HERE).mAttribute_lkey.mAttribute_string  COMMA_SOURCE_FILE ("declaration-isr.galgas", 160)) ;
    GALGAS_string temp_1 ;
    const enumGalgasBool test_2 = enumerator_6420.current (HERE).mAttribute_mXTR.boolEnum () ;
    if (kBoolTrue == test_2) {
      temp_1 = function_llvmNameForInterrupt (enumerator_6420.current (HERE).mAttribute_lkey, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 162)).mAttribute_string ;
    }else if (kBoolFalse == test_2) {
      temp_1 = function_llvmNameForISR (enumerator_6420.current (HERE).mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 164)) ;
    }
    GALGAS_string var_interruptImplementationName_6507 = temp_1 ;
    ioArgument_ioLLVMcode.plusAssign_operation(function_llvmTitleComment (var_interruptImplementationName_6507, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 166)), inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 166)) ;
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("define void @").add_operation (var_interruptImplementationName_6507, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 167)).add_operation (GALGAS_string (" ()"), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 167)).add_operation (function_llvmAttributeFunction (inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 167)), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 167)).add_operation (GALGAS_string (" {\n"), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 167)), inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 167)) ;
    cEnumerator_allocaList enumerator_6884 (enumerator_6420.current (HERE).mAttribute_mAllocaList, kEnumeration_up) ;
    while (enumerator_6884.hasCurrentObject ()) {
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (function_llvmNameForLocalVariable (enumerator_6884.current_mVarName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 170)), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 170)).add_operation (GALGAS_string (" = alloca "), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 170)).add_operation (enumerator_6884.current_mType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 170)), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 170)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 170)), inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 170)) ;
      enumerator_6884.gotoNextObject () ;
    }
    const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, enumerator_6420.current (HERE).mAttribute_mSelfType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-isr.galgas", 173)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      GALGAS_string var_varName_7082 = function_llvmNameForGlobalVariable (enumerator_6420.current (HERE).mAttribute_mGlobalVariableName, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 174)) ;
      GALGAS_string var_typeName_7162 = enumerator_6420.current (HERE).mAttribute_mSelfType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 175)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %self = getelementptr inbounds ").add_operation (var_typeName_7162, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 176)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 176)).add_operation (var_typeName_7162, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 176)).add_operation (GALGAS_string (" * @"), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 176)).add_operation (var_varName_7082, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 176)), inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 176)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", i32 0 ; Perform %self = @").add_operation (var_varName_7082, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 177)).add_operation (GALGAS_string (" \n"), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 177)), inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 177)) ;
    }
    extensionMethod_instructionListLLVMCode (enumerator_6420.current (HERE).mAttribute_mInstructionGenerationList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 180)) ;
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ret void\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 182)) ;
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("}\n"
      "\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 183)) ;
    const enumGalgasBool test_4 = enumerator_6420.current (HERE).mAttribute_mXTR.boolEnum () ;
    if (kBoolTrue == test_4) {
      GALGAS_string var_interruptHandlerName_7697 = function_llvmNameForInterrupt (enumerator_6420.current (HERE).mAttribute_lkey, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 186)).mAttribute_string ;
      GALGAS_string var_isrName_7762 = function_llvmNameForISR (enumerator_6420.current (HERE).mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 187)) ;
      GALGAS_string var_s_31__7816 = constinArgument_inXTRInterruptHandlerString.getter_stringByReplacingStringByString (GALGAS_string ("!ISR!"), var_isrName_7762, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 188)) ;
      GALGAS_string var_s_32__7910 = var_s_31__7816.getter_stringByReplacingStringByString (GALGAS_string ("!HANDLER!"), var_interruptHandlerName_7697, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 189)) ;
      ioArgument_ioAScode.plusAssign_operation(var_s_32__7910, inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 190)) ;
    }
    enumerator_6420.gotoNextObject () ;
  }
  cEnumerator_availableInterruptMap enumerator_8139 (constinArgument_inGenerationContext.mAttribute_mAvailableInterruptMap, kEnumeration_up) ;
  while (enumerator_8139.hasCurrentObject ()) {
    const enumGalgasBool test_5 = var_definedInterrupts_6391.getter_hasKey (enumerator_8139.current_lkey (HERE).mAttribute_string COMMA_SOURCE_FILE ("declaration-isr.galgas", 195)).operator_not (SOURCE_FILE ("declaration-isr.galgas", 195)).boolEnum () ;
    if (kBoolTrue == test_5) {
      switch (enumerator_8139.current_mInterruptionPanicCode (HERE).enumValue ()) {
      case GALGAS_interruptionPanicCode::kNotBuilt:
        break ;
      case GALGAS_interruptionPanicCode::kEnum_noPanicCode:
        {
          GALGAS_string var_s_8260 = constinArgument_inUndefinedInterruptString.getter_stringByReplacingStringByString (GALGAS_string ("!ISR!"), function_llvmNameForISR (enumerator_8139.current_lkey (HERE).mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 198)), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 198)) ;
          ioArgument_ioAScode.plusAssign_operation(var_s_8260, inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 199)) ;
        }
        break ;
      case GALGAS_interruptionPanicCode::kEnum_panicCode:
        {
          const cEnumAssociatedValues_interruptionPanicCode_panicCode * extractPtr_9079 = (const cEnumAssociatedValues_interruptionPanicCode_panicCode *) (enumerator_8139.current_mInterruptionPanicCode (HERE).unsafePointer ()) ;
          const GALGAS_lbigint extractedValue_value = extractPtr_9079->mAssociatedValue0 ;
          const enumGalgasBool test_6 = GALGAS_bool (gOption_plm_5F_options_noPanicGeneration.getter_value ()).boolEnum () ;
          if (kBoolTrue == test_6) {
            GALGAS_string var_s_8502 = constinArgument_inUndefinedInterruptString.getter_stringByReplacingStringByString (GALGAS_string ("!ISR!"), function_llvmNameForISR (enumerator_8139.current_lkey (HERE).mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 202)), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 202)) ;
            ioArgument_ioAScode.plusAssign_operation(var_s_8502, inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 203)) ;
          }else if (kBoolFalse == test_6) {
            GALGAS_string var_name_8661 = function_llvmNameForISR (enumerator_8139.current_lkey (HERE).mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 205)) ;
            ioArgument_ioLLVMcode.plusAssign_operation(function_llvmTitleComment (GALGAS_string ("Panic code for ").add_operation (var_name_8661, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 206)), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 206)), inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 206)) ;
            ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("define void @").add_operation (var_name_8661, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 207)).add_operation (GALGAS_string (" ()"), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 207)).add_operation (function_llvmAttributeFunction (inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 207)), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 207)).add_operation (GALGAS_string (" noreturn {\n"), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 207)), inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 207)) ;
            ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  call void @panic.isr (").add_operation (constinArgument_inGenerationContext.mAttribute_mPanicCodeLLVMType, inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 208)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 208)).add_operation (extractedValue_value.mAttribute_bigint.getter_string (SOURCE_FILE ("declaration-isr.galgas", 208)), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 208)).add_operation (GALGAS_string (") noreturn \n"), inCompiler COMMA_SOURCE_FILE ("declaration-isr.galgas", 208)), inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 208)) ;
            ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  unreachable\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 209)) ;
            ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("}\n"
              "\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 210)) ;
          }
        }
        break ;
      }
    }
    enumerator_8139.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   Extension method '@sectionDeclarationListAST noteSectionTypesInPrecedenceGraph'                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_noteSectionTypesInPrecedenceGraph (const GALGAS_sectionDeclarationListAST inObject,
                                                        GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_sectionDeclarationListAST temp_0 = inObject ;
  cEnumerator_sectionDeclarationListAST enumerator_2555 (temp_0, kEnumeration_up) ;
  while (enumerator_2555.hasCurrentObject ()) {
    cEnumerator_procFormalArgumentList enumerator_2627 (enumerator_2555.current_mSectionFormalArgumentList (HERE), kEnumeration_up) ;
    while (enumerator_2627.hasCurrentObject ()) {
      GALGAS_lstring var_typeName_2649 = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (enumerator_2627.current_mFormalArgumentTypeName (HERE).getter_string (SOURCE_FILE ("declaration-section.galgas", 71)), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 71)), enumerator_2627.current_mFormalArgumentTypeName (HERE).mAttribute_location  COMMA_SOURCE_FILE ("declaration-section.galgas", 71)) ;
      {
      ioArgument_ioGraph.setter_noteNode (var_typeName_2649 COMMA_SOURCE_FILE ("declaration-section.galgas", 72)) ;
      }
      enumerator_2627.gotoNextObject () ;
    }
    extensionMethod_noteInstructionListTypesInPrecedenceGraph (enumerator_2555.current_mSectionInstructionList (HERE), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 74)) ;
    enumerator_2555.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension method '@sectionDeclarationListAST enterInContext'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterInContext (const GALGAS_sectionDeclarationListAST inObject,
                                     const GALGAS_string constinArgument_inReceiverTypeName,
                                     GALGAS_semanticContext & ioArgument_ioContext,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_sectionDeclarationListAST temp_0 = inObject ;
  cEnumerator_sectionDeclarationListAST enumerator_3388 (temp_0, kEnumeration_up) ;
  while (enumerator_3388.hasCurrentObject ()) {
    GALGAS_lstring temp_1 ;
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_inReceiverTypeName.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_2) {
      temp_1 = enumerator_3388.current (HERE).mAttribute_mSectionName ;
    }else if (kBoolFalse == test_2) {
      temp_1 = GALGAS_lstring::constructor_new (constinArgument_inReceiverTypeName.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 91)).add_operation (enumerator_3388.current (HERE).mAttribute_mSectionName.getter_string (SOURCE_FILE ("declaration-section.galgas", 91)), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 91)), enumerator_3388.current (HERE).mAttribute_mSectionName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-section.galgas", 91)) ;
    }
    GALGAS_lstring var_routineMangledName_3435 = temp_1 ;
    GALGAS_procedureSignature var_signature_3649 = GALGAS_procedureSignature::constructor_emptyList (SOURCE_FILE ("declaration-section.galgas", 93)) ;
    var_routineMangledName_3435.mAttribute_string.plusAssign_operation(GALGAS_string ("("), inCompiler  COMMA_SOURCE_FILE ("declaration-section.galgas", 94)) ;
    cEnumerator_procFormalArgumentList enumerator_3799 (enumerator_3388.current (HERE).mAttribute_mSectionFormalArgumentList, kEnumeration_up) ;
    while (enumerator_3799.hasCurrentObject ()) {
      GALGAS_unifiedTypeMap_2D_proxy var_typeProxy_3822 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_3799.current_mFormalArgumentTypeName (HERE), inCompiler  COMMA_SOURCE_FILE ("declaration-section.galgas", 96)) ;
      var_signature_3649.addAssign_operation (enumerator_3799.current_mFormalArgumentPassingMode (HERE), enumerator_3799.current_mSelector (HERE).mAttribute_string, var_typeProxy_3822  COMMA_SOURCE_FILE ("declaration-section.galgas", 97)) ;
      var_routineMangledName_3435.mAttribute_string.plusAssign_operation(extensionGetter_formalPassingModeString (enumerator_3799.current_mFormalArgumentPassingMode (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 98)).add_operation (enumerator_3799.current_mSelector (HERE).getter_string (SOURCE_FILE ("declaration-section.galgas", 98)), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 98)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 98)), inCompiler  COMMA_SOURCE_FILE ("declaration-section.galgas", 98)) ;
      enumerator_3799.gotoNextObject () ;
    }
    var_routineMangledName_3435.mAttribute_string.plusAssign_operation(GALGAS_string (")"), inCompiler  COMMA_SOURCE_FILE ("declaration-section.galgas", 100)) ;
    GALGAS_unifiedTypeMap_2D_proxy temp_3 ;
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, enumerator_3388.current (HERE).mAttribute_mReturnTypeName.mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_4) {
      temp_3 = GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-section.galgas", 102)) ;
    }else if (kBoolFalse == test_4) {
      temp_3 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_3388.current (HERE).mAttribute_mReturnTypeName, inCompiler  COMMA_SOURCE_FILE ("declaration-section.galgas", 104)) ;
    }
    GALGAS_unifiedTypeMap_2D_proxy var_returnType_4144 = temp_3 ;
    GALGAS_bool var_mutating_4361 = GALGAS_bool (false) ;
    cEnumerator_lstringlist enumerator_4422 (enumerator_3388.current (HERE).mAttribute_mSectionAttributeList, kEnumeration_up) ;
    while (enumerator_4422.hasCurrentObject ()) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, enumerator_4422.current_mValue (HERE).mAttribute_string.objectCompare (function_mutatingAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 109)))).boolEnum () ;
      if (kBoolTrue == test_5) {
        var_mutating_4361 = GALGAS_bool (true) ;
      }
      enumerator_4422.gotoNextObject () ;
    }
    {
    ioArgument_ioContext.mAttribute_mRoutineMapForContext.setter_insertKey (var_routineMangledName_3435, var_routineMangledName_3435, enumerator_3388.current (HERE).mAttribute_mPublic, GALGAS_bool (false), GALGAS_mode::constructor_userMode (SOURCE_FILE ("declaration-section.galgas", 119)), var_signature_3649, GALGAS_routineKind::constructor_section (SOURCE_FILE ("declaration-section.galgas", 121)), GALGAS_bool (false), var_returnType_4144, GALGAS_bool (false), var_mutating_4361, GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 114)) ;
    }
    enumerator_3388.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension method '@sectionDeclarationListAST sectionSemanticAnalysis'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_sectionSemanticAnalysis (const GALGAS_sectionDeclarationListAST inObject,
                                              GALGAS_unifiedTypeMap_2D_proxy inArgument_inReceiverType,
                                              const GALGAS_semanticContext constinArgument_inSemanticContext,
                                              GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                              GALGAS_intermediateCodeStruct & ioArgument_ioIntermediateCodeStruct,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_sectionDeclarationListAST temp_0 = inObject ;
  cEnumerator_sectionDeclarationListAST enumerator_5610 (temp_0, kEnumeration_up) ;
  while (enumerator_5610.hasCurrentObject ()) {
    GALGAS_bool var_mutating_5630 = GALGAS_bool (false) ;
    GALGAS_bool var_noUnusedWarning_5662 = GALGAS_bool (false) ;
    cEnumerator_lstringlist enumerator_5723 (enumerator_5610.current (HERE).mAttribute_mSectionAttributeList, kEnumeration_up) ;
    while (enumerator_5723.hasCurrentObject ()) {
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, enumerator_5723.current_mValue (HERE).mAttribute_string.objectCompare (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 145)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        const enumGalgasBool test_2 = var_noUnusedWarning_5662.boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          fixItArray3.addObject (C_FixItDescription (kFixItRemove, "")) ;
          inCompiler->emitSemanticError (enumerator_5723.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-section.galgas", 147)), GALGAS_string ("duplicated @").add_operation (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 147)), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 147)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 147)), fixItArray3  COMMA_SOURCE_FILE ("declaration-section.galgas", 147)) ;
        }
        var_noUnusedWarning_5662 = GALGAS_bool (true) ;
      }else if (kBoolFalse == test_1) {
        const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, enumerator_5723.current_mValue (HERE).mAttribute_string.objectCompare (function_mutatingAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 150)))).boolEnum () ;
        if (kBoolTrue == test_4) {
          const enumGalgasBool test_5 = var_mutating_5630.boolEnum () ;
          if (kBoolTrue == test_5) {
            TC_Array <C_FixItDescription> fixItArray6 ;
            fixItArray6.addObject (C_FixItDescription (kFixItRemove, "")) ;
            inCompiler->emitSemanticError (enumerator_5723.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-section.galgas", 152)), GALGAS_string ("duplicated @").add_operation (function_mutatingAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 152)), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 152)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 152)), fixItArray6  COMMA_SOURCE_FILE ("declaration-section.galgas", 152)) ;
          }
          var_mutating_5630 = GALGAS_bool (true) ;
        }else if (kBoolFalse == test_4) {
          TC_Array <C_FixItDescription> fixItArray7 ;
          fixItArray7.addObject (C_FixItDescription (kFixItRemove, "")) ;
          inCompiler->emitSemanticError (enumerator_5723.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-section.galgas", 156)), GALGAS_string ("unknown attribute; available attributes are @").add_operation (function_mutatingAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 157)), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 157)).add_operation (GALGAS_string (", @"), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 157)).add_operation (function_mutatingAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 157)), inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 157)), fixItArray7  COMMA_SOURCE_FILE ("declaration-section.galgas", 156)) ;
        }
      }
      enumerator_5723.gotoNextObject () ;
    }
    {
    routine_routineSemanticAnalysis (inArgument_inReceiverType, GALGAS_routineKind::constructor_section (SOURCE_FILE ("declaration-section.galgas", 163)), GALGAS_mode::constructor_sectionMode (SOURCE_FILE ("declaration-section.galgas", 164)), enumerator_5610.current (HERE).mAttribute_mSectionName, enumerator_5610.current (HERE).mAttribute_mSectionFormalArgumentList, enumerator_5610.current (HERE).mAttribute_mReturnTypeName, enumerator_5610.current (HERE).mAttribute_mSectionInstructionList, enumerator_5610.current (HERE).mAttribute_mEndOfSectionLocation, GALGAS_bool (true), var_mutating_5630, var_noUnusedWarning_5662.operator_not (SOURCE_FILE ("declaration-section.galgas", 172)), GALGAS_bool (true), GALGAS_bool (false), constinArgument_inSemanticContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler  COMMA_SOURCE_FILE ("declaration-section.galgas", 161)) ;
    }
    enumerator_5610.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*

cMapElement_routineMapIR::cMapElement_routineMapIR (const GALGAS_lstring & inKey,
                                                    const GALGAS_unifiedTypeMap_2D_proxy & in_mReceiverType,
                                                    const GALGAS_lstring & in_mRoutineNameForGeneration,
                                                    const GALGAS_procFormalArgumentListForGeneration & in_mFormalArgumentListForGeneration,
                                                    const GALGAS_allocaList & in_mAllocaList,
                                                    const GALGAS_instructionListIR & in_mInstructionGenerationList,
                                                    const GALGAS_bool & in_mIsRequired,
                                                    const GALGAS_bool & in_mWarnIfUnused,
                                                    const GALGAS_bool & in_mWeak,
                                                    const GALGAS_bool & in_mGlobal,
                                                    const GALGAS_routineKind & in_mKind,
                                                    const GALGAS_unifiedTypeMap_2D_proxy & in_mReturnType,
                                                    const GALGAS_bool & in_mAppendFileAndLineArgumentForPanicLocation
                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_mReceiverType (in_mReceiverType),
mAttribute_mRoutineNameForGeneration (in_mRoutineNameForGeneration),
mAttribute_mFormalArgumentListForGeneration (in_mFormalArgumentListForGeneration),
mAttribute_mAllocaList (in_mAllocaList),
mAttribute_mInstructionGenerationList (in_mInstructionGenerationList),
mAttribute_mIsRequired (in_mIsRequired),
mAttribute_mWarnIfUnused (in_mWarnIfUnused),
mAttribute_mWeak (in_mWeak),
mAttribute_mGlobal (in_mGlobal),
mAttribute_mKind (in_mKind),
mAttribute_mReturnType (in_mReturnType),
mAttribute_mAppendFileAndLineArgumentForPanicLocation (in_mAppendFileAndLineArgumentForPanicLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_routineMapIR::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mReceiverType.isValid () && mAttribute_mRoutineNameForGeneration.isValid () && mAttribute_mFormalArgumentListForGeneration.isValid () && mAttribute_mAllocaList.isValid () && mAttribute_mInstructionGenerationList.isValid () && mAttribute_mIsRequired.isValid () && mAttribute_mWarnIfUnused.isValid () && mAttribute_mWeak.isValid () && mAttribute_mGlobal.isValid () && mAttribute_mKind.isValid () && mAttribute_mReturnType.isValid () && mAttribute_mAppendFileAndLineArgumentForPanicLocation.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_routineMapIR::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_routineMapIR (mAttribute_lkey, mAttribute_mReceiverType, mAttribute_mRoutineNameForGeneration, mAttribute_mFormalArgumentListForGeneration, mAttribute_mAllocaList, mAttribute_mInstructionGenerationList, mAttribute_mIsRequired, mAttribute_mWarnIfUnused, mAttribute_mWeak, mAttribute_mGlobal, mAttribute_mKind, mAttribute_mReturnType, mAttribute_mAppendFileAndLineArgumentForPanicLocation COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_routineMapIR::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mReceiverType" ":" ;
  mAttribute_mReceiverType.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mRoutineNameForGeneration" ":" ;
  mAttribute_mRoutineNameForGeneration.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFormalArgumentListForGeneration" ":" ;
  mAttribute_mFormalArgumentListForGeneration.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAllocaList" ":" ;
  mAttribute_mAllocaList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mInstructionGenerationList" ":" ;
  mAttribute_mInstructionGenerationList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mIsRequired" ":" ;
  mAttribute_mIsRequired.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mWarnIfUnused" ":" ;
  mAttribute_mWarnIfUnused.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mWeak" ":" ;
  mAttribute_mWeak.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGlobal" ":" ;
  mAttribute_mGlobal.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mKind" ":" ;
  mAttribute_mKind.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mReturnType" ":" ;
  mAttribute_mReturnType.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAppendFileAndLineArgumentForPanicLocation" ":" ;
  mAttribute_mAppendFileAndLineArgumentForPanicLocation.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_routineMapIR::compare (const cCollectionElement * inOperand) const {
  cMapElement_routineMapIR * operand = (cMapElement_routineMapIR *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_mReceiverType.objectCompare (operand->mAttribute_mReceiverType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mRoutineNameForGeneration.objectCompare (operand->mAttribute_mRoutineNameForGeneration) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mFormalArgumentListForGeneration.objectCompare (operand->mAttribute_mFormalArgumentListForGeneration) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mAllocaList.objectCompare (operand->mAttribute_mAllocaList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mInstructionGenerationList.objectCompare (operand->mAttribute_mInstructionGenerationList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mIsRequired.objectCompare (operand->mAttribute_mIsRequired) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mWarnIfUnused.objectCompare (operand->mAttribute_mWarnIfUnused) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mWeak.objectCompare (operand->mAttribute_mWeak) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mGlobal.objectCompare (operand->mAttribute_mGlobal) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mKind.objectCompare (operand->mAttribute_mKind) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mReturnType.objectCompare (operand->mAttribute_mReturnType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mAppendFileAndLineArgumentForPanicLocation.objectCompare (operand->mAttribute_mAppendFileAndLineArgumentForPanicLocation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapIR::GALGAS_routineMapIR (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapIR::GALGAS_routineMapIR (const GALGAS_routineMapIR & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapIR & GALGAS_routineMapIR::operator = (const GALGAS_routineMapIR & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapIR GALGAS_routineMapIR::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_routineMapIR result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapIR GALGAS_routineMapIR::constructor_mapWithMapToOverride (const GALGAS_routineMapIR & inMapToOverride
                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_routineMapIR result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapIR GALGAS_routineMapIR::getter_overriddenMap (C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_routineMapIR result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::addAssign_operation (const GALGAS_lstring & inKey,
                                               const GALGAS_unifiedTypeMap_2D_proxy & inArgument0,
                                               const GALGAS_lstring & inArgument1,
                                               const GALGAS_procFormalArgumentListForGeneration & inArgument2,
                                               const GALGAS_allocaList & inArgument3,
                                               const GALGAS_instructionListIR & inArgument4,
                                               const GALGAS_bool & inArgument5,
                                               const GALGAS_bool & inArgument6,
                                               const GALGAS_bool & inArgument7,
                                               const GALGAS_bool & inArgument8,
                                               const GALGAS_routineKind & inArgument9,
                                               const GALGAS_unifiedTypeMap_2D_proxy & inArgument10,
                                               const GALGAS_bool & inArgument11,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cMapElement_routineMapIR * p = NULL ;
  macroMyNew (p, cMapElement_routineMapIR (inKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4, inArgument5, inArgument6, inArgument7, inArgument8, inArgument9, inArgument10, inArgument11 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@routineMapIR insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_insertKey (GALGAS_lstring inKey,
                                            GALGAS_unifiedTypeMap_2D_proxy inArgument0,
                                            GALGAS_lstring inArgument1,
                                            GALGAS_procFormalArgumentListForGeneration inArgument2,
                                            GALGAS_allocaList inArgument3,
                                            GALGAS_instructionListIR inArgument4,
                                            GALGAS_bool inArgument5,
                                            GALGAS_bool inArgument6,
                                            GALGAS_bool inArgument7,
                                            GALGAS_bool inArgument8,
                                            GALGAS_routineKind inArgument9,
                                            GALGAS_unifiedTypeMap_2D_proxy inArgument10,
                                            GALGAS_bool inArgument11,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  cMapElement_routineMapIR * p = NULL ;
  macroMyNew (p, cMapElement_routineMapIR (inKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4, inArgument5, inArgument6, inArgument7, inArgument8, inArgument9, inArgument10, inArgument11 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "routine '%K' is already defined" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_routineMapIR_searchKey = "** internal error **" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::method_searchKey (GALGAS_lstring inKey,
                                            GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                            GALGAS_lstring & outArgument1,
                                            GALGAS_procFormalArgumentListForGeneration & outArgument2,
                                            GALGAS_allocaList & outArgument3,
                                            GALGAS_instructionListIR & outArgument4,
                                            GALGAS_bool & outArgument5,
                                            GALGAS_bool & outArgument6,
                                            GALGAS_bool & outArgument7,
                                            GALGAS_bool & outArgument8,
                                            GALGAS_routineKind & outArgument9,
                                            GALGAS_unifiedTypeMap_2D_proxy & outArgument10,
                                            GALGAS_bool & outArgument11,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) performSearch (inKey,
                                                                                           inCompiler,
                                                                                           kSearchErrorMessage_routineMapIR_searchKey
                                                                                           COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
    outArgument2.drop () ;
    outArgument3.drop () ;
    outArgument4.drop () ;
    outArgument5.drop () ;
    outArgument6.drop () ;
    outArgument7.drop () ;
    outArgument8.drop () ;
    outArgument9.drop () ;
    outArgument10.drop () ;
    outArgument11.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    outArgument0 = p->mAttribute_mReceiverType ;
    outArgument1 = p->mAttribute_mRoutineNameForGeneration ;
    outArgument2 = p->mAttribute_mFormalArgumentListForGeneration ;
    outArgument3 = p->mAttribute_mAllocaList ;
    outArgument4 = p->mAttribute_mInstructionGenerationList ;
    outArgument5 = p->mAttribute_mIsRequired ;
    outArgument6 = p->mAttribute_mWarnIfUnused ;
    outArgument7 = p->mAttribute_mWeak ;
    outArgument8 = p->mAttribute_mGlobal ;
    outArgument9 = p->mAttribute_mKind ;
    outArgument10 = p->mAttribute_mReturnType ;
    outArgument11 = p->mAttribute_mAppendFileAndLineArgumentForPanicLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_removeKey (GALGAS_lstring inKey,
                                            GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                            GALGAS_lstring & outArgument1,
                                            GALGAS_procFormalArgumentListForGeneration & outArgument2,
                                            GALGAS_allocaList & outArgument3,
                                            GALGAS_instructionListIR & outArgument4,
                                            GALGAS_bool & outArgument5,
                                            GALGAS_bool & outArgument6,
                                            GALGAS_bool & outArgument7,
                                            GALGAS_bool & outArgument8,
                                            GALGAS_routineKind & outArgument9,
                                            GALGAS_unifiedTypeMap_2D_proxy & outArgument10,
                                            GALGAS_bool & outArgument11,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "** internal error **" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    outArgument0 = p->mAttribute_mReceiverType ;
    outArgument1 = p->mAttribute_mRoutineNameForGeneration ;
    outArgument2 = p->mAttribute_mFormalArgumentListForGeneration ;
    outArgument3 = p->mAttribute_mAllocaList ;
    outArgument4 = p->mAttribute_mInstructionGenerationList ;
    outArgument5 = p->mAttribute_mIsRequired ;
    outArgument6 = p->mAttribute_mWarnIfUnused ;
    outArgument7 = p->mAttribute_mWeak ;
    outArgument8 = p->mAttribute_mGlobal ;
    outArgument9 = p->mAttribute_mKind ;
    outArgument10 = p->mAttribute_mReturnType ;
    outArgument11 = p->mAttribute_mAppendFileAndLineArgumentForPanicLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_routineMapIR::getter_mReceiverTypeForKey (const GALGAS_string & inKey,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) attributes ;
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    result = p->mAttribute_mReceiverType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_routineMapIR::getter_mRoutineNameForGenerationForKey (const GALGAS_string & inKey,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) attributes ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    result = p->mAttribute_mRoutineNameForGeneration ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration GALGAS_routineMapIR::getter_mFormalArgumentListForGenerationForKey (const GALGAS_string & inKey,
                                                                                                               C_Compiler * inCompiler
                                                                                                               COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) attributes ;
  GALGAS_procFormalArgumentListForGeneration result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    result = p->mAttribute_mFormalArgumentListForGeneration ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList GALGAS_routineMapIR::getter_mAllocaListForKey (const GALGAS_string & inKey,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) attributes ;
  GALGAS_allocaList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    result = p->mAttribute_mAllocaList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_routineMapIR::getter_mInstructionGenerationListForKey (const GALGAS_string & inKey,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) attributes ;
  GALGAS_instructionListIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    result = p->mAttribute_mInstructionGenerationList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_routineMapIR::getter_mIsRequiredForKey (const GALGAS_string & inKey,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    result = p->mAttribute_mIsRequired ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_routineMapIR::getter_mWarnIfUnusedForKey (const GALGAS_string & inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    result = p->mAttribute_mWarnIfUnused ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_routineMapIR::getter_mWeakForKey (const GALGAS_string & inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    result = p->mAttribute_mWeak ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_routineMapIR::getter_mGlobalForKey (const GALGAS_string & inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    result = p->mAttribute_mGlobal ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineKind GALGAS_routineMapIR::getter_mKindForKey (const GALGAS_string & inKey,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) attributes ;
  GALGAS_routineKind result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    result = p->mAttribute_mKind ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_routineMapIR::getter_mReturnTypeForKey (const GALGAS_string & inKey,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) attributes ;
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    result = p->mAttribute_mReturnType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_routineMapIR::getter_mAppendFileAndLineArgumentForPanicLocationForKey (const GALGAS_string & inKey,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    result = p->mAttribute_mAppendFileAndLineArgumentForPanicLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_setMReceiverTypeForKey (GALGAS_unifiedTypeMap_2D_proxy inAttributeValue,
                                                         GALGAS_string inKey,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    p->mAttribute_mReceiverType = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_setMRoutineNameForGenerationForKey (GALGAS_lstring inAttributeValue,
                                                                     GALGAS_string inKey,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    p->mAttribute_mRoutineNameForGeneration = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_setMFormalArgumentListForGenerationForKey (GALGAS_procFormalArgumentListForGeneration inAttributeValue,
                                                                            GALGAS_string inKey,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    p->mAttribute_mFormalArgumentListForGeneration = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_setMAllocaListForKey (GALGAS_allocaList inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    p->mAttribute_mAllocaList = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_setMInstructionGenerationListForKey (GALGAS_instructionListIR inAttributeValue,
                                                                      GALGAS_string inKey,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    p->mAttribute_mInstructionGenerationList = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_setMIsRequiredForKey (GALGAS_bool inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    p->mAttribute_mIsRequired = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_setMWarnIfUnusedForKey (GALGAS_bool inAttributeValue,
                                                         GALGAS_string inKey,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    p->mAttribute_mWarnIfUnused = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_setMWeakForKey (GALGAS_bool inAttributeValue,
                                                 GALGAS_string inKey,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    p->mAttribute_mWeak = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_setMGlobalForKey (GALGAS_bool inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    p->mAttribute_mGlobal = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_setMKindForKey (GALGAS_routineKind inAttributeValue,
                                                 GALGAS_string inKey,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    p->mAttribute_mKind = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_setMReturnTypeForKey (GALGAS_unifiedTypeMap_2D_proxy inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    p->mAttribute_mReturnType = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapIR::setter_setMAppendFileAndLineArgumentForPanicLocationForKey (GALGAS_bool inAttributeValue,
                                                                                      GALGAS_string inKey,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_routineMapIR * p = (cMapElement_routineMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_routineMapIR) ;
    p->mAttribute_mAppendFileAndLineArgumentForPanicLocation = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_routineMapIR * GALGAS_routineMapIR::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                   const GALGAS_string & inKey
                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_routineMapIR * result = (cMapElement_routineMapIR *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_routineMapIR) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_routineMapIR::cEnumerator_routineMapIR (const GALGAS_routineMapIR & inEnumeratedObject,
                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapIR_2D_element cEnumerator_routineMapIR::current (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return GALGAS_routineMapIR_2D_element (p->mAttribute_lkey, p->mAttribute_mReceiverType, p->mAttribute_mRoutineNameForGeneration, p->mAttribute_mFormalArgumentListForGeneration, p->mAttribute_mAllocaList, p->mAttribute_mInstructionGenerationList, p->mAttribute_mIsRequired, p->mAttribute_mWarnIfUnused, p->mAttribute_mWeak, p->mAttribute_mGlobal, p->mAttribute_mKind, p->mAttribute_mReturnType, p->mAttribute_mAppendFileAndLineArgumentForPanicLocation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_routineMapIR::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cEnumerator_routineMapIR::current_mReceiverType (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return p->mAttribute_mReceiverType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_routineMapIR::current_mRoutineNameForGeneration (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return p->mAttribute_mRoutineNameForGeneration ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration cEnumerator_routineMapIR::current_mFormalArgumentListForGeneration (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return p->mAttribute_mFormalArgumentListForGeneration ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList cEnumerator_routineMapIR::current_mAllocaList (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return p->mAttribute_mAllocaList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cEnumerator_routineMapIR::current_mInstructionGenerationList (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return p->mAttribute_mInstructionGenerationList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_routineMapIR::current_mIsRequired (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return p->mAttribute_mIsRequired ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_routineMapIR::current_mWarnIfUnused (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return p->mAttribute_mWarnIfUnused ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_routineMapIR::current_mWeak (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return p->mAttribute_mWeak ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_routineMapIR::current_mGlobal (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return p->mAttribute_mGlobal ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineKind cEnumerator_routineMapIR::current_mKind (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return p->mAttribute_mKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cEnumerator_routineMapIR::current_mReturnType (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return p->mAttribute_mReturnType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_routineMapIR::current_mAppendFileAndLineArgumentForPanicLocation (LOCATION_ARGS) const {
  const cMapElement_routineMapIR * p = (const cMapElement_routineMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_routineMapIR) ;
  return p->mAttribute_mAppendFileAndLineArgumentForPanicLocation ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @routineMapIR type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_routineMapIR ("routineMapIR",
                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_routineMapIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_routineMapIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_routineMapIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_routineMapIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapIR GALGAS_routineMapIR::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_routineMapIR result ;
  const GALGAS_routineMapIR * p = (const GALGAS_routineMapIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_routineMapIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("routineMapIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension method '@safeDeclarationListAST noteTypesInPrecedenceGraph'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_noteTypesInPrecedenceGraph (const GALGAS_safeDeclarationListAST inObject,
                                                 GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_safeDeclarationListAST temp_0 = inObject ;
  cEnumerator_safeDeclarationListAST enumerator_2500 (temp_0, kEnumeration_up) ;
  while (enumerator_2500.hasCurrentObject ()) {
    cEnumerator_procFormalArgumentList enumerator_2569 (enumerator_2500.current_mSafeFormalArgumentList (HERE), kEnumeration_up) ;
    while (enumerator_2569.hasCurrentObject ()) {
      GALGAS_lstring var_typeName_2591 = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (enumerator_2569.current_mFormalArgumentTypeName (HERE).getter_string (SOURCE_FILE ("declaration-safe.galgas", 71)), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 71)), enumerator_2569.current_mFormalArgumentTypeName (HERE).mAttribute_location  COMMA_SOURCE_FILE ("declaration-safe.galgas", 71)) ;
      {
      ioArgument_ioGraph.setter_noteNode (var_typeName_2591 COMMA_SOURCE_FILE ("declaration-safe.galgas", 72)) ;
      }
      enumerator_2569.gotoNextObject () ;
    }
    extensionMethod_noteInstructionListTypesInPrecedenceGraph (enumerator_2500.current_mSafeInstructionList (HERE), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 74)) ;
    enumerator_2500.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension method '@safeDeclarationListAST enterInContext'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterInContext (const GALGAS_safeDeclarationListAST inObject,
                                     const GALGAS_string constinArgument_inReceiverTypeName,
                                     GALGAS_semanticContext & ioArgument_ioContext,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_safeDeclarationListAST temp_0 = inObject ;
  cEnumerator_safeDeclarationListAST enumerator_3321 (temp_0, kEnumeration_up) ;
  while (enumerator_3321.hasCurrentObject ()) {
    GALGAS_lstring temp_1 ;
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_inReceiverTypeName.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_2) {
      temp_1 = enumerator_3321.current (HERE).mAttribute_mSafeName ;
    }else if (kBoolFalse == test_2) {
      temp_1 = GALGAS_lstring::constructor_new (constinArgument_inReceiverTypeName.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 91)).add_operation (enumerator_3321.current (HERE).mAttribute_mSafeName.getter_string (SOURCE_FILE ("declaration-safe.galgas", 91)), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 91)), enumerator_3321.current (HERE).mAttribute_mSafeName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-safe.galgas", 91)) ;
    }
    GALGAS_lstring var_routineMangledName_3368 = temp_1 ;
    GALGAS_procedureSignature var_signature_3564 = GALGAS_procedureSignature::constructor_emptyList (SOURCE_FILE ("declaration-safe.galgas", 93)) ;
    var_routineMangledName_3368.mAttribute_string.plusAssign_operation(GALGAS_string ("("), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 94)) ;
    cEnumerator_procFormalArgumentList enumerator_3708 (enumerator_3321.current (HERE).mAttribute_mSafeFormalArgumentList, kEnumeration_up) ;
    while (enumerator_3708.hasCurrentObject ()) {
      GALGAS_unifiedTypeMap_2D_proxy var_typeProxy_3731 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_3708.current_mFormalArgumentTypeName (HERE), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 96)) ;
      var_signature_3564.addAssign_operation (enumerator_3708.current_mFormalArgumentPassingMode (HERE), enumerator_3708.current_mSelector (HERE).mAttribute_string, var_typeProxy_3731  COMMA_SOURCE_FILE ("declaration-safe.galgas", 97)) ;
      var_routineMangledName_3368.mAttribute_string.plusAssign_operation(extensionGetter_formalPassingModeString (enumerator_3708.current_mFormalArgumentPassingMode (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 98)).add_operation (enumerator_3708.current_mSelector (HERE).getter_string (SOURCE_FILE ("declaration-safe.galgas", 98)), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 98)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 98)), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 98)) ;
      enumerator_3708.gotoNextObject () ;
    }
    var_routineMangledName_3368.mAttribute_string.plusAssign_operation(GALGAS_string (")"), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 100)) ;
    GALGAS_unifiedTypeMap_2D_proxy temp_3 ;
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, enumerator_3321.current (HERE).mAttribute_mReturnTypeName.mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_4) {
      temp_3 = GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-safe.galgas", 102)) ;
    }else if (kBoolFalse == test_4) {
      temp_3 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_3321.current (HERE).mAttribute_mReturnTypeName, inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 104)) ;
    }
    GALGAS_unifiedTypeMap_2D_proxy var_returnType_4053 = temp_3 ;
    GALGAS_bool var_mutating_4264 = GALGAS_bool (false) ;
    cEnumerator_lstringlist enumerator_4319 (enumerator_3321.current (HERE).mAttribute_mSafeAttributeList, kEnumeration_up) ;
    while (enumerator_4319.hasCurrentObject ()) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, enumerator_4319.current_mValue (HERE).mAttribute_string.objectCompare (function_mutatingAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 109)))).boolEnum () ;
      if (kBoolTrue == test_5) {
        var_mutating_4264 = GALGAS_bool (true) ;
      }
      enumerator_4319.gotoNextObject () ;
    }
    {
    ioArgument_ioContext.mAttribute_mRoutineMapForContext.setter_insertKey (var_routineMangledName_3368, var_routineMangledName_3368, enumerator_3321.current (HERE).mAttribute_mPublic, GALGAS_bool (false), GALGAS_mode::constructor_userMode (SOURCE_FILE ("declaration-safe.galgas", 119)), var_signature_3564, GALGAS_routineKind::constructor_safe (SOURCE_FILE ("declaration-safe.galgas", 121)), GALGAS_bool (false), var_returnType_4053, GALGAS_bool (false), var_mutating_4264, GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 114)) ;
    }
    enumerator_3321.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Extension method '@safeDeclarationListAST sectionSemanticAnalysis'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_sectionSemanticAnalysis (const GALGAS_safeDeclarationListAST inObject,
                                              GALGAS_unifiedTypeMap_2D_proxy inArgument_inReceiverType,
                                              const GALGAS_semanticContext constinArgument_inSemanticContext,
                                              GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                              GALGAS_intermediateCodeStruct & ioArgument_ioIntermediateCodeStruct,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_safeDeclarationListAST temp_0 = inObject ;
  cEnumerator_safeDeclarationListAST enumerator_5495 (temp_0, kEnumeration_up) ;
  while (enumerator_5495.hasCurrentObject ()) {
    GALGAS_bool var_mutating_5515 = GALGAS_bool (false) ;
    GALGAS_bool var_noUnusedWarning_5547 = GALGAS_bool (false) ;
    cEnumerator_lstringlist enumerator_5602 (enumerator_5495.current (HERE).mAttribute_mSafeAttributeList, kEnumeration_up) ;
    while (enumerator_5602.hasCurrentObject ()) {
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, enumerator_5602.current_mValue (HERE).mAttribute_string.objectCompare (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 145)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        const enumGalgasBool test_2 = var_noUnusedWarning_5547.boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          fixItArray3.addObject (C_FixItDescription (kFixItRemove, "")) ;
          inCompiler->emitSemanticError (enumerator_5602.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-safe.galgas", 147)), GALGAS_string ("duplicated @").add_operation (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 147)), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 147)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 147)), fixItArray3  COMMA_SOURCE_FILE ("declaration-safe.galgas", 147)) ;
        }
        var_noUnusedWarning_5547 = GALGAS_bool (true) ;
      }else if (kBoolFalse == test_1) {
        const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, enumerator_5602.current_mValue (HERE).mAttribute_string.objectCompare (function_mutatingAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 150)))).boolEnum () ;
        if (kBoolTrue == test_4) {
          const enumGalgasBool test_5 = var_mutating_5515.boolEnum () ;
          if (kBoolTrue == test_5) {
            TC_Array <C_FixItDescription> fixItArray6 ;
            fixItArray6.addObject (C_FixItDescription (kFixItRemove, "")) ;
            inCompiler->emitSemanticError (enumerator_5602.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-safe.galgas", 152)), GALGAS_string ("duplicated @").add_operation (function_mutatingAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 152)), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 152)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 152)), fixItArray6  COMMA_SOURCE_FILE ("declaration-safe.galgas", 152)) ;
          }
          var_mutating_5515 = GALGAS_bool (true) ;
        }else if (kBoolFalse == test_4) {
          TC_Array <C_FixItDescription> fixItArray7 ;
          fixItArray7.addObject (C_FixItDescription (kFixItRemove, "")) ;
          inCompiler->emitSemanticError (enumerator_5602.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-safe.galgas", 156)), GALGAS_string ("unknown attribute; available attributes are @").add_operation (function_mutatingAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 157)), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 157)).add_operation (GALGAS_string (", @"), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 157)).add_operation (function_mutatingAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 157)), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 157)), fixItArray7  COMMA_SOURCE_FILE ("declaration-safe.galgas", 156)) ;
        }
      }
      enumerator_5602.gotoNextObject () ;
    }
    {
    routine_routineSemanticAnalysis (inArgument_inReceiverType, GALGAS_routineKind::constructor_safe (SOURCE_FILE ("declaration-safe.galgas", 163)), GALGAS_mode::constructor_safeMode (SOURCE_FILE ("declaration-safe.galgas", 164)), enumerator_5495.current (HERE).mAttribute_mSafeName, enumerator_5495.current (HERE).mAttribute_mSafeFormalArgumentList, enumerator_5495.current (HERE).mAttribute_mReturnTypeName, enumerator_5495.current (HERE).mAttribute_mSafeInstructionList, enumerator_5495.current (HERE).mAttribute_mEndOfSafeLocation, GALGAS_bool (true), var_mutating_5515, var_noUnusedWarning_5547.operator_not (SOURCE_FILE ("declaration-safe.galgas", 172)), GALGAS_bool (true), GALGAS_bool (false), constinArgument_inSemanticContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 161)) ;
    }
    enumerator_5495.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@routineMapIR safeCodeGeneration'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_safeCodeGeneration (const GALGAS_routineMapIR inObject,
                                         GALGAS_string & ioArgument_ioLLVMcode,
                                         GALGAS__32_stringlist & ioArgument_ioSafeList,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_routineMapIR temp_0 = inObject ;
  cEnumerator_routineMapIR enumerator_7343 (temp_0, kEnumeration_up) ;
  while (enumerator_7343.hasCurrentObject ()) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, enumerator_7343.current (HERE).mAttribute_mKind.objectCompare (GALGAS_routineKind::constructor_safe (SOURCE_FILE ("declaration-safe.galgas", 192)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_string var_safeCallName_7401 = function_llvmNameForSafeCall (enumerator_7343.current (HERE).mAttribute_mRoutineNameForGeneration.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 193)) ;
      GALGAS_string var_safeImplementationName_7497 = function_llvmNameForSafeImplementation (enumerator_7343.current (HERE).mAttribute_mRoutineNameForGeneration.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 194)) ;
      ioArgument_ioSafeList.addAssign_operation (var_safeCallName_7401, var_safeImplementationName_7497  COMMA_SOURCE_FILE ("declaration-safe.galgas", 195)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(function_llvmTitleComment (var_safeCallName_7401, inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 196)), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 196)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("declare"), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 197)) ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, enumerator_7343.current (HERE).mAttribute_mReturnType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-safe.galgas", 198)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" void"), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 199)) ;
      }else if (kBoolFalse == test_2) {
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" ").add_operation (enumerator_7343.current (HERE).mAttribute_mReturnType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 201)), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 201)), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 201)) ;
      }
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" @").add_operation (var_safeCallName_7401, inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 203)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 203)), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 203)) ;
      GALGAS_bool var_first_7925 = GALGAS_bool (true) ;
      const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, enumerator_7343.current (HERE).mAttribute_mReceiverType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-safe.galgas", 205)))).boolEnum () ;
      if (kBoolTrue == test_3) {
        ioArgument_ioLLVMcode.plusAssign_operation(enumerator_7343.current (HERE).mAttribute_mReceiverType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 206)).add_operation (GALGAS_string (" * %receiver"), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 206)), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 206)) ;
        var_first_7925 = GALGAS_bool (false) ;
      }
      cEnumerator_procFormalArgumentListForGeneration enumerator_8133 (enumerator_7343.current (HERE).mAttribute_mFormalArgumentListForGeneration, kEnumeration_up) ;
      while (enumerator_8133.hasCurrentObject ()) {
        const enumGalgasBool test_4 = var_first_7925.boolEnum () ;
        if (kBoolTrue == test_4) {
          var_first_7925 = GALGAS_bool (false) ;
        }else if (kBoolFalse == test_4) {
          ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 213)) ;
        }
        switch (enumerator_8133.current_mFormalArgumentKind (HERE).enumValue ()) {
        case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
          break ;
        case GALGAS_procFormalArgumentPassingMode::kEnum_input:
          {
            ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8133.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 217)).add_operation (GALGAS_string (" %in."), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 217)).add_operation (enumerator_8133.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 217)), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 217)) ;
          }
          break ;
        case GALGAS_procFormalArgumentPassingMode::kEnum_output:
          {
            ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8133.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 219)).add_operation (GALGAS_string (" * %"), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 219)).add_operation (function_llvmNameForLocalVariable (enumerator_8133.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 219)), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 219)), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 219)) ;
          }
          break ;
        case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
          {
            ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8133.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 221)).add_operation (GALGAS_string (" * %"), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 221)).add_operation (function_llvmNameForLocalVariable (enumerator_8133.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 221)), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 221)), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 221)) ;
          }
          break ;
        }
        enumerator_8133.gotoNextObject () ;
      }
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (")").add_operation (function_llvmAttributeFunction (inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 224)), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 224)).add_operation (GALGAS_string ("\n"
        "\n"), inCompiler COMMA_SOURCE_FILE ("declaration-safe.galgas", 224)), inCompiler  COMMA_SOURCE_FILE ("declaration-safe.galgas", 224)) ;
    }
    enumerator_7343.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   Extension method '@serviceDeclarationListAST noteServiceTypesInPrecedenceGraph'                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_noteServiceTypesInPrecedenceGraph (const GALGAS_serviceDeclarationListAST inObject,
                                                        GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_serviceDeclarationListAST temp_0 = inObject ;
  cEnumerator_serviceDeclarationListAST enumerator_2555 (temp_0, kEnumeration_up) ;
  while (enumerator_2555.hasCurrentObject ()) {
    cEnumerator_procFormalArgumentList enumerator_2627 (enumerator_2555.current_mServiceFormalArgumentList (HERE), kEnumeration_up) ;
    while (enumerator_2627.hasCurrentObject ()) {
      GALGAS_lstring var_typeName_2649 = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (enumerator_2627.current_mFormalArgumentTypeName (HERE).getter_string (SOURCE_FILE ("declaration-service.galgas", 71)), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 71)), enumerator_2627.current_mFormalArgumentTypeName (HERE).mAttribute_location  COMMA_SOURCE_FILE ("declaration-service.galgas", 71)) ;
      {
      ioArgument_ioGraph.setter_noteNode (var_typeName_2649 COMMA_SOURCE_FILE ("declaration-service.galgas", 72)) ;
      }
      enumerator_2627.gotoNextObject () ;
    }
    extensionMethod_noteInstructionListTypesInPrecedenceGraph (enumerator_2555.current_mServiceInstructionList (HERE), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 74)) ;
    enumerator_2555.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension method '@serviceDeclarationListAST enterInContext'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterInContext (const GALGAS_serviceDeclarationListAST inObject,
                                     const GALGAS_string constinArgument_inReceiverTypeName,
                                     GALGAS_semanticContext & ioArgument_ioContext,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_serviceDeclarationListAST temp_0 = inObject ;
  cEnumerator_serviceDeclarationListAST enumerator_3388 (temp_0, kEnumeration_up) ;
  while (enumerator_3388.hasCurrentObject ()) {
    GALGAS_lstring temp_1 ;
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_inReceiverTypeName.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_2) {
      temp_1 = enumerator_3388.current (HERE).mAttribute_mServiceName ;
    }else if (kBoolFalse == test_2) {
      temp_1 = GALGAS_lstring::constructor_new (constinArgument_inReceiverTypeName.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 91)).add_operation (enumerator_3388.current (HERE).mAttribute_mServiceName.getter_string (SOURCE_FILE ("declaration-service.galgas", 91)), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 91)), enumerator_3388.current (HERE).mAttribute_mServiceName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-service.galgas", 91)) ;
    }
    GALGAS_lstring var_routineMangledName_3435 = temp_1 ;
    GALGAS_procedureSignature var_signature_3649 = GALGAS_procedureSignature::constructor_emptyList (SOURCE_FILE ("declaration-service.galgas", 93)) ;
    var_routineMangledName_3435.mAttribute_string.plusAssign_operation(GALGAS_string ("("), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 94)) ;
    cEnumerator_procFormalArgumentList enumerator_3799 (enumerator_3388.current (HERE).mAttribute_mServiceFormalArgumentList, kEnumeration_up) ;
    while (enumerator_3799.hasCurrentObject ()) {
      GALGAS_unifiedTypeMap_2D_proxy var_typeProxy_3822 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_3799.current_mFormalArgumentTypeName (HERE), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 96)) ;
      var_signature_3649.addAssign_operation (enumerator_3799.current_mFormalArgumentPassingMode (HERE), enumerator_3799.current_mSelector (HERE).mAttribute_string, var_typeProxy_3822  COMMA_SOURCE_FILE ("declaration-service.galgas", 97)) ;
      var_routineMangledName_3435.mAttribute_string.plusAssign_operation(extensionGetter_formalPassingModeString (enumerator_3799.current_mFormalArgumentPassingMode (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 98)).add_operation (enumerator_3799.current_mSelector (HERE).getter_string (SOURCE_FILE ("declaration-service.galgas", 98)), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 98)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 98)), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 98)) ;
      enumerator_3799.gotoNextObject () ;
    }
    var_routineMangledName_3435.mAttribute_string.plusAssign_operation(GALGAS_string (")"), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 100)) ;
    GALGAS_unifiedTypeMap_2D_proxy temp_3 ;
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, enumerator_3388.current (HERE).mAttribute_mReturnTypeName.mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_4) {
      temp_3 = GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-service.galgas", 105)) ;
    }else if (kBoolFalse == test_4) {
      temp_3 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_3388.current (HERE).mAttribute_mReturnTypeName, inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 107)) ;
    }
    GALGAS_unifiedTypeMap_2D_proxy var_returnType_4305 = temp_3 ;
    {
    ioArgument_ioContext.mAttribute_mRoutineMapForContext.setter_insertKey (var_routineMangledName_3435, var_routineMangledName_3435, enumerator_3388.current (HERE).mAttribute_mPublic, GALGAS_bool (false), GALGAS_mode::constructor_serviceMode (SOURCE_FILE ("declaration-service.galgas", 114)), var_signature_3649, GALGAS_routineKind::constructor_service (SOURCE_FILE ("declaration-service.galgas", 116)), GALGAS_bool (false), var_returnType_4305, GALGAS_bool (false), GALGAS_bool (true), GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 109)) ;
    }
    enumerator_3388.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension method '@serviceDeclarationListAST serviceSemanticAnalysis'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_serviceSemanticAnalysis (const GALGAS_serviceDeclarationListAST inObject,
                                              GALGAS_unifiedTypeMap_2D_proxy inArgument_inReceiverType,
                                              const GALGAS_semanticContext constinArgument_inSemanticContext,
                                              GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                              GALGAS_intermediateCodeStruct & ioArgument_ioIntermediateCodeStruct,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_serviceDeclarationListAST temp_0 = inObject ;
  cEnumerator_serviceDeclarationListAST enumerator_5548 (temp_0, kEnumeration_up) ;
  while (enumerator_5548.hasCurrentObject ()) {
    GALGAS_bool var_warnIfUnused_5572 = GALGAS_bool (true) ;
    cEnumerator_lstringlist enumerator_5632 (enumerator_5548.current (HERE).mAttribute_mServiceAttributeList, kEnumeration_up) ;
    while (enumerator_5632.hasCurrentObject ()) {
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, enumerator_5632.current_mValue (HERE).mAttribute_string.objectCompare (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 139)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        const enumGalgasBool test_2 = var_warnIfUnused_5572.operator_not (SOURCE_FILE ("declaration-service.galgas", 140)).boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          fixItArray3.addObject (C_FixItDescription (kFixItRemove, "")) ;
          inCompiler->emitSemanticError (enumerator_5632.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-service.galgas", 141)), GALGAS_string ("duplicate @").add_operation (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 141)), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 141)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 141)), fixItArray3  COMMA_SOURCE_FILE ("declaration-service.galgas", 141)) ;
        }
        var_warnIfUnused_5572 = GALGAS_bool (false) ;
      }else if (kBoolFalse == test_1) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        fixItArray4.addObject (C_FixItDescription (kFixItRemove, "")) ;
        inCompiler->emitSemanticError (enumerator_5632.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-service.galgas", 145)), GALGAS_string ("unknown attribute; available attribute is @").add_operation (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 145)), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 145)), fixItArray4  COMMA_SOURCE_FILE ("declaration-service.galgas", 145)) ;
      }
      enumerator_5632.gotoNextObject () ;
    }
    {
    routine_routineSemanticAnalysis (inArgument_inReceiverType, GALGAS_routineKind::constructor_service (SOURCE_FILE ("declaration-service.galgas", 150)), GALGAS_mode::constructor_serviceMode (SOURCE_FILE ("declaration-service.galgas", 151)), enumerator_5548.current (HERE).mAttribute_mServiceName, enumerator_5548.current (HERE).mAttribute_mServiceFormalArgumentList, enumerator_5548.current (HERE).mAttribute_mReturnTypeName, enumerator_5548.current (HERE).mAttribute_mServiceInstructionList, enumerator_5548.current (HERE).mAttribute_mEndOfServiceLocation, GALGAS_bool (true), GALGAS_bool (true), var_warnIfUnused_5572, GALGAS_bool (true), GALGAS_bool (false), constinArgument_inSemanticContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 148)) ;
    }
    enumerator_5548.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension method '@routineMapIR serviceCodeGeneration'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_serviceCodeGeneration (const GALGAS_routineMapIR inObject,
                                            GALGAS_string & ioArgument_ioLLVMcode,
                                            GALGAS__32_stringlist & ioArgument_ioServiceList,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_routineMapIR temp_0 = inObject ;
  cEnumerator_routineMapIR enumerator_7138 (temp_0, kEnumeration_up) ;
  while (enumerator_7138.hasCurrentObject ()) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, enumerator_7138.current (HERE).mAttribute_mKind.objectCompare (GALGAS_routineKind::constructor_service (SOURCE_FILE ("declaration-service.galgas", 179)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_string var_serviceImplementationName_7215 = function_llvmNameForServiceImplementation (enumerator_7138.current (HERE).mAttribute_mRoutineNameForGeneration.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 180)) ;
      GALGAS_string var_serviceCallName_7320 = function_llvmNameForServiceCall (enumerator_7138.current (HERE).mAttribute_mRoutineNameForGeneration.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 181)) ;
      ioArgument_ioServiceList.addAssign_operation (var_serviceCallName_7320, var_serviceImplementationName_7215  COMMA_SOURCE_FILE ("declaration-service.galgas", 182)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(function_llvmTitleComment (var_serviceImplementationName_7215, inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 183)), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 183)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("declare"), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 184)) ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, enumerator_7138.current (HERE).mAttribute_mReturnType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-service.galgas", 185)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" void"), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 186)) ;
      }else if (kBoolFalse == test_2) {
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" ").add_operation (enumerator_7138.current (HERE).mAttribute_mReturnType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 188)), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 188)), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 188)) ;
      }
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" @").add_operation (function_llvmNameForServiceCall (enumerator_7138.current (HERE).mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 190)), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 190)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 190)), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 190)) ;
      GALGAS_string var_typeName_7808 = enumerator_7138.current (HERE).mAttribute_lkey.mAttribute_string.getter_stringByDeletingPathExtension (SOURCE_FILE ("declaration-service.galgas", 191)) ;
      GALGAS_bool var_first_7878 = GALGAS_bool (kIsEqual, var_typeName_7808.objectCompare (GALGAS_string::makeEmptyString ())) ;
      const enumGalgasBool test_3 = var_first_7878.operator_not (SOURCE_FILE ("declaration-service.galgas", 193)).boolEnum () ;
      if (kBoolTrue == test_3) {
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("%").add_operation (var_typeName_7808.getter_assemblerRepresentation (SOURCE_FILE ("declaration-service.galgas", 194)), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 194)).add_operation (GALGAS_string (" * %self"), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 194)), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 194)) ;
      }
      cEnumerator_procFormalArgumentListForGeneration enumerator_8064 (enumerator_7138.current (HERE).mAttribute_mFormalArgumentListForGeneration, kEnumeration_up) ;
      while (enumerator_8064.hasCurrentObject ()) {
        const enumGalgasBool test_4 = var_first_7878.boolEnum () ;
        if (kBoolTrue == test_4) {
          var_first_7878 = GALGAS_bool (false) ;
        }else if (kBoolFalse == test_4) {
          ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 197)) ;
        }
        switch (enumerator_8064.current_mFormalArgumentKind (HERE).enumValue ()) {
        case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
          break ;
        case GALGAS_procFormalArgumentPassingMode::kEnum_input:
          {
            ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8064.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 200)).add_operation (GALGAS_string (" %in."), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 200)).add_operation (enumerator_8064.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 200)), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 200)) ;
          }
          break ;
        case GALGAS_procFormalArgumentPassingMode::kEnum_output:
          {
            ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8064.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 202)).add_operation (GALGAS_string (" * %"), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 202)).add_operation (function_llvmNameForLocalVariable (enumerator_8064.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 202)), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 202)), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 202)) ;
          }
          break ;
        case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
          {
            ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8064.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 204)).add_operation (GALGAS_string (" * %"), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 204)).add_operation (function_llvmNameForLocalVariable (enumerator_8064.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 204)), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 204)), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 204)) ;
          }
          break ;
        }
        enumerator_8064.gotoNextObject () ;
      }
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (")").add_operation (function_llvmAttributeFunction (inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 207)), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 207)).add_operation (GALGAS_string ("\n"
        "\n"), inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 207)), inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 207)) ;
    }
    enumerator_7138.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                 Extension method '@primitiveDeclarationListAST notePrimitiveTypesInPrecedenceGraph'                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_notePrimitiveTypesInPrecedenceGraph (const GALGAS_primitiveDeclarationListAST inObject,
                                                          GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_primitiveDeclarationListAST temp_0 = inObject ;
  cEnumerator_primitiveDeclarationListAST enumerator_2596 (temp_0, kEnumeration_up) ;
  while (enumerator_2596.hasCurrentObject ()) {
    cEnumerator_procFormalArgumentList enumerator_2670 (enumerator_2596.current_mPrimitiveFormalArgumentList (HERE), kEnumeration_up) ;
    while (enumerator_2670.hasCurrentObject ()) {
      GALGAS_lstring var_typeName_2692 = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (enumerator_2670.current_mFormalArgumentTypeName (HERE).getter_string (SOURCE_FILE ("declaration-primitive.galgas", 71)), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 71)), enumerator_2670.current_mFormalArgumentTypeName (HERE).mAttribute_location  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 71)) ;
      {
      ioArgument_ioGraph.setter_noteNode (var_typeName_2692 COMMA_SOURCE_FILE ("declaration-primitive.galgas", 72)) ;
      }
      enumerator_2670.gotoNextObject () ;
    }
    extensionMethod_noteInstructionListTypesInPrecedenceGraph (enumerator_2596.current_mPrimitiveInstructionList (HERE), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 74)) ;
    enumerator_2596.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Extension method '@primitiveDeclarationListAST enterInContext'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterInContext (const GALGAS_primitiveDeclarationListAST inObject,
                                     const GALGAS_string constinArgument_inReceiverTypeName,
                                     GALGAS_semanticContext & ioArgument_ioContext,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_primitiveDeclarationListAST temp_0 = inObject ;
  cEnumerator_primitiveDeclarationListAST enumerator_3437 (temp_0, kEnumeration_up) ;
  while (enumerator_3437.hasCurrentObject ()) {
    GALGAS_lstring temp_1 ;
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_inReceiverTypeName.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_2) {
      temp_1 = enumerator_3437.current (HERE).mAttribute_mPrimitiveName ;
    }else if (kBoolFalse == test_2) {
      temp_1 = GALGAS_lstring::constructor_new (constinArgument_inReceiverTypeName.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 91)).add_operation (enumerator_3437.current (HERE).mAttribute_mPrimitiveName.getter_string (SOURCE_FILE ("declaration-primitive.galgas", 91)), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 91)), enumerator_3437.current (HERE).mAttribute_mPrimitiveName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 91)) ;
    }
    GALGAS_lstring var_routineMangledName_3484 = temp_1 ;
    GALGAS_procedureSignature var_signature_3710 = GALGAS_procedureSignature::constructor_emptyList (SOURCE_FILE ("declaration-primitive.galgas", 93)) ;
    var_routineMangledName_3484.mAttribute_string.plusAssign_operation(GALGAS_string ("("), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 94)) ;
    cEnumerator_procFormalArgumentList enumerator_3864 (enumerator_3437.current (HERE).mAttribute_mPrimitiveFormalArgumentList, kEnumeration_up) ;
    while (enumerator_3864.hasCurrentObject ()) {
      GALGAS_unifiedTypeMap_2D_proxy var_typeProxy_3887 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_3864.current_mFormalArgumentTypeName (HERE), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 96)) ;
      var_signature_3710.addAssign_operation (enumerator_3864.current_mFormalArgumentPassingMode (HERE), enumerator_3864.current_mSelector (HERE).mAttribute_string, var_typeProxy_3887  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 97)) ;
      var_routineMangledName_3484.mAttribute_string.plusAssign_operation(extensionGetter_formalPassingModeString (enumerator_3864.current_mFormalArgumentPassingMode (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 98)).add_operation (enumerator_3864.current_mSelector (HERE).getter_string (SOURCE_FILE ("declaration-primitive.galgas", 98)), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 98)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 98)), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 98)) ;
      enumerator_3864.gotoNextObject () ;
    }
    var_routineMangledName_3484.mAttribute_string.plusAssign_operation(GALGAS_string (")"), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 100)) ;
    GALGAS_unifiedTypeMap_2D_proxy temp_3 ;
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, enumerator_3437.current (HERE).mAttribute_mReturnTypeName.mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_4) {
      temp_3 = GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-primitive.galgas", 105)) ;
    }else if (kBoolFalse == test_4) {
      temp_3 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_3437.current (HERE).mAttribute_mReturnTypeName, inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 107)) ;
    }
    GALGAS_unifiedTypeMap_2D_proxy var_returnType_4335 = temp_3 ;
    {
    ioArgument_ioContext.mAttribute_mRoutineMapForContext.setter_insertKey (var_routineMangledName_3484, var_routineMangledName_3484, enumerator_3437.current (HERE).mAttribute_mPublic, GALGAS_bool (false), GALGAS_mode::constructor_primitiveMode (SOURCE_FILE ("declaration-primitive.galgas", 114)), var_signature_3710, GALGAS_routineKind::constructor_primitive (SOURCE_FILE ("declaration-primitive.galgas", 116)), GALGAS_bool (false), var_returnType_4335, GALGAS_bool (false), GALGAS_bool (true), GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 109)) ;
    }
    enumerator_3437.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Extension method '@primitiveDeclarationListAST primitiveSemanticAnalysis'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_primitiveSemanticAnalysis (const GALGAS_primitiveDeclarationListAST inObject,
                                                GALGAS_unifiedTypeMap_2D_proxy inArgument_inReceiverType,
                                                const GALGAS_semanticContext constinArgument_inSemanticContext,
                                                GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                GALGAS_intermediateCodeStruct & ioArgument_ioIntermediateCodeStruct,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_primitiveDeclarationListAST temp_0 = inObject ;
  cEnumerator_primitiveDeclarationListAST enumerator_5594 (temp_0, kEnumeration_up) ;
  while (enumerator_5594.hasCurrentObject ()) {
    GALGAS_bool var_warnIfUnused_5618 = GALGAS_bool (true) ;
    cEnumerator_lstringlist enumerator_5686 (enumerator_5594.current (HERE).mAttribute_mPrimitiveNameAttributeList, kEnumeration_up) ;
    while (enumerator_5686.hasCurrentObject ()) {
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, enumerator_5686.current_mValue (HERE).mAttribute_string.objectCompare (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 139)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        const enumGalgasBool test_2 = var_warnIfUnused_5618.operator_not (SOURCE_FILE ("declaration-primitive.galgas", 140)).boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          fixItArray3.addObject (C_FixItDescription (kFixItRemove, "")) ;
          inCompiler->emitSemanticError (enumerator_5686.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-primitive.galgas", 141)), GALGAS_string ("duplicate @").add_operation (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 141)), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 141)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 141)), fixItArray3  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 141)) ;
        }
        var_warnIfUnused_5618 = GALGAS_bool (false) ;
      }else if (kBoolFalse == test_1) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        fixItArray4.addObject (C_FixItDescription (kFixItRemove, "")) ;
        inCompiler->emitSemanticError (enumerator_5686.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-primitive.galgas", 145)), GALGAS_string ("unknown attribute; available attribute is @").add_operation (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 145)), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 145)), fixItArray4  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 145)) ;
      }
      enumerator_5686.gotoNextObject () ;
    }
    {
    routine_routineSemanticAnalysis (inArgument_inReceiverType, GALGAS_routineKind::constructor_primitive (SOURCE_FILE ("declaration-primitive.galgas", 150)), GALGAS_mode::constructor_primitiveMode (SOURCE_FILE ("declaration-primitive.galgas", 151)), enumerator_5594.current (HERE).mAttribute_mPrimitiveName, enumerator_5594.current (HERE).mAttribute_mPrimitiveFormalArgumentList, enumerator_5594.current (HERE).mAttribute_mReturnTypeName, enumerator_5594.current (HERE).mAttribute_mPrimitiveInstructionList, enumerator_5594.current (HERE).mAttribute_mEndOfPrimitiveDeclaration, GALGAS_bool (true), GALGAS_bool (true), var_warnIfUnused_5618, GALGAS_bool (true), GALGAS_bool (false), constinArgument_inSemanticContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 148)) ;
    }
    enumerator_5594.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension method '@routineMapIR primitiveCodeGeneration'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_primitiveCodeGeneration (const GALGAS_routineMapIR inObject,
                                              GALGAS_string & ioArgument_ioLLVMcode,
                                              GALGAS__32_stringlist & ioArgument_ioServiceList,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_routineMapIR temp_0 = inObject ;
  cEnumerator_routineMapIR enumerator_7223 (temp_0, kEnumeration_up) ;
  while (enumerator_7223.hasCurrentObject ()) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, enumerator_7223.current (HERE).mAttribute_mKind.objectCompare (GALGAS_routineKind::constructor_primitive (SOURCE_FILE ("declaration-primitive.galgas", 179)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_string var_primitiveImplementationName_7306 = function_llvmNameForPrimitiveImplementation (enumerator_7223.current (HERE).mAttribute_mRoutineNameForGeneration.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 180)) ;
      GALGAS_string var_primitiveCallName_7417 = function_llvmNameForPrimitiveCall (enumerator_7223.current (HERE).mAttribute_mRoutineNameForGeneration.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 181)) ;
      ioArgument_ioServiceList.addAssign_operation (var_primitiveCallName_7417, var_primitiveImplementationName_7306  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 182)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(function_llvmTitleComment (var_primitiveImplementationName_7306, inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 183)), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 183)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("declare"), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 184)) ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, enumerator_7223.current (HERE).mAttribute_mReturnType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-primitive.galgas", 185)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" void"), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 186)) ;
      }else if (kBoolFalse == test_2) {
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" ").add_operation (enumerator_7223.current (HERE).mAttribute_mReturnType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 188)), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 188)), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 188)) ;
      }
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" @").add_operation (var_primitiveCallName_7417, inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 190)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 190)), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 190)) ;
      GALGAS_string var_typeName_7891 = enumerator_7223.current (HERE).mAttribute_lkey.mAttribute_string.getter_stringByDeletingPathExtension (SOURCE_FILE ("declaration-primitive.galgas", 191)) ;
      GALGAS_bool var_first_7963 = GALGAS_bool (kIsEqual, var_typeName_7891.objectCompare (GALGAS_string::makeEmptyString ())) ;
      const enumGalgasBool test_3 = var_first_7963.operator_not (SOURCE_FILE ("declaration-primitive.galgas", 193)).boolEnum () ;
      if (kBoolTrue == test_3) {
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("%").add_operation (var_typeName_7891.getter_assemblerRepresentation (SOURCE_FILE ("declaration-primitive.galgas", 194)), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 194)).add_operation (GALGAS_string (" * %self"), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 194)), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 194)) ;
      }
      cEnumerator_procFormalArgumentListForGeneration enumerator_8151 (enumerator_7223.current (HERE).mAttribute_mFormalArgumentListForGeneration, kEnumeration_up) ;
      while (enumerator_8151.hasCurrentObject ()) {
        const enumGalgasBool test_4 = var_first_7963.boolEnum () ;
        if (kBoolTrue == test_4) {
          var_first_7963 = GALGAS_bool (false) ;
        }else if (kBoolFalse == test_4) {
          ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 197)) ;
        }
        switch (enumerator_8151.current_mFormalArgumentKind (HERE).enumValue ()) {
        case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
          break ;
        case GALGAS_procFormalArgumentPassingMode::kEnum_input:
          {
            ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8151.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 200)).add_operation (GALGAS_string (" %in."), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 200)).add_operation (enumerator_8151.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 200)), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 200)) ;
          }
          break ;
        case GALGAS_procFormalArgumentPassingMode::kEnum_output:
          {
            ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8151.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 202)).add_operation (GALGAS_string (" * %"), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 202)).add_operation (function_llvmNameForLocalVariable (enumerator_8151.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 202)), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 202)), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 202)) ;
          }
          break ;
        case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
          {
            ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8151.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 204)).add_operation (GALGAS_string (" * %"), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 204)).add_operation (function_llvmNameForLocalVariable (enumerator_8151.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 204)), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 204)), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 204)) ;
          }
          break ;
        }
        enumerator_8151.gotoNextObject () ;
      }
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (")").add_operation (function_llvmAttributeFunction (inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 207)), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 207)).add_operation (GALGAS_string ("\n"
        "\n"), inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 207)), inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 207)) ;
    }
    enumerator_7223.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Extension method '@guardDeclarationListAST noteTypesInPrecedenceGraph'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_noteTypesInPrecedenceGraph (const GALGAS_guardDeclarationListAST inObject,
                                                 GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_guardDeclarationListAST temp_0 = inObject ;
  cEnumerator_guardDeclarationListAST enumerator_2737 (temp_0, kEnumeration_up) ;
  while (enumerator_2737.hasCurrentObject ()) {
    cEnumerator_procFormalArgumentList enumerator_2807 (enumerator_2737.current_mGuardFormalArgumentList (HERE), kEnumeration_up) ;
    while (enumerator_2807.hasCurrentObject ()) {
      GALGAS_lstring var_typeName_2829 = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (enumerator_2807.current_mFormalArgumentTypeName (HERE).getter_string (SOURCE_FILE ("declaration-guard.galgas", 83)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 83)), enumerator_2807.current_mFormalArgumentTypeName (HERE).mAttribute_location  COMMA_SOURCE_FILE ("declaration-guard.galgas", 83)) ;
      {
      ioArgument_ioGraph.setter_noteNode (var_typeName_2829 COMMA_SOURCE_FILE ("declaration-guard.galgas", 84)) ;
      }
      enumerator_2807.gotoNextObject () ;
    }
    extensionMethod_noteInstructionListTypesInPrecedenceGraph (enumerator_2737.current_mGuardInstructionList (HERE), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 86)) ;
    enumerator_2737.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension method '@guardDeclarationListAST enterInContext'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterInContext (const GALGAS_guardDeclarationListAST inObject,
                                     const GALGAS_string constinArgument_inReceiverTypeName,
                                     GALGAS_semanticContext & ioArgument_ioContext,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_guardDeclarationListAST temp_0 = inObject ;
  cEnumerator_guardDeclarationListAST enumerator_3562 (temp_0, kEnumeration_up) ;
  while (enumerator_3562.hasCurrentObject ()) {
    GALGAS_lstring temp_1 ;
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_inReceiverTypeName.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_2) {
      temp_1 = enumerator_3562.current (HERE).mAttribute_mGuardName ;
    }else if (kBoolFalse == test_2) {
      temp_1 = GALGAS_lstring::constructor_new (constinArgument_inReceiverTypeName.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 103)).add_operation (enumerator_3562.current (HERE).mAttribute_mGuardName.getter_string (SOURCE_FILE ("declaration-guard.galgas", 103)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 103)), enumerator_3562.current (HERE).mAttribute_mGuardName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-guard.galgas", 103)) ;
    }
    GALGAS_lstring var_guardMangledName_3607 = temp_1 ;
    var_guardMangledName_3607.mAttribute_string.plusAssign_operation(GALGAS_string ("("), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 105)) ;
    GALGAS_procedureSignature var_signature_3844 = GALGAS_procedureSignature::constructor_emptyList (SOURCE_FILE ("declaration-guard.galgas", 106)) ;
    cEnumerator_procFormalArgumentList enumerator_3953 (enumerator_3562.current (HERE).mAttribute_mGuardFormalArgumentList, kEnumeration_up) ;
    while (enumerator_3953.hasCurrentObject ()) {
      GALGAS_unifiedTypeMap_2D_proxy var_typeProxy_3976 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_3953.current_mFormalArgumentTypeName (HERE), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 108)) ;
      var_signature_3844.addAssign_operation (enumerator_3953.current_mFormalArgumentPassingMode (HERE), enumerator_3953.current_mSelector (HERE).mAttribute_string, var_typeProxy_3976  COMMA_SOURCE_FILE ("declaration-guard.galgas", 109)) ;
      var_guardMangledName_3607.mAttribute_string.plusAssign_operation(extensionGetter_formalPassingModeString (enumerator_3953.current_mFormalArgumentPassingMode (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 110)).add_operation (enumerator_3953.current_mSelector (HERE).getter_string (SOURCE_FILE ("declaration-guard.galgas", 110)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 110)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 110)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 110)) ;
      enumerator_3953.gotoNextObject () ;
    }
    var_guardMangledName_3607.mAttribute_string.plusAssign_operation(GALGAS_string (")"), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 112)) ;
    {
    ioArgument_ioContext.mAttribute_mGuardMapForContext.setter_insertKey (var_guardMangledName_3607, enumerator_3562.current (HERE).mAttribute_mIsPublic, var_signature_3844, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 114)) ;
    }
    enumerator_3562.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Extension method '@guardDeclarationListAST guardSemanticAnalysis'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_guardSemanticAnalysis (const GALGAS_guardDeclarationListAST inObject,
                                            GALGAS_unifiedTypeMap_2D_proxy inArgument_inReceiverType,
                                            const GALGAS_semanticContext constinArgument_inSemanticContext,
                                            GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                            GALGAS_intermediateCodeStruct & ioArgument_ioIntermediateCodeStruct,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_guardDeclarationListAST temp_0 = inObject ;
  cEnumerator_guardDeclarationListAST enumerator_5093 (temp_0, kEnumeration_up) ;
  while (enumerator_5093.hasCurrentObject ()) {
    GALGAS_bool var_warnIfUnused_5117 = GALGAS_bool (true) ;
    cEnumerator_lstringlist enumerator_5173 (enumerator_5093.current (HERE).mAttribute_mGuardAttributeList, kEnumeration_up) ;
    while (enumerator_5173.hasCurrentObject ()) {
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, enumerator_5173.current_mValue (HERE).mAttribute_string.objectCompare (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 135)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        const enumGalgasBool test_2 = var_warnIfUnused_5117.operator_not (SOURCE_FILE ("declaration-guard.galgas", 136)).boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (enumerator_5173.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-guard.galgas", 137)), GALGAS_string ("duplicate @").add_operation (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 137)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 137)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 137)), fixItArray3  COMMA_SOURCE_FILE ("declaration-guard.galgas", 137)) ;
        }
        var_warnIfUnused_5117 = GALGAS_bool (false) ;
      }else if (kBoolFalse == test_1) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (enumerator_5173.current_mValue (HERE).getter_location (SOURCE_FILE ("declaration-guard.galgas", 141)), GALGAS_string ("unknown attribute; available attribute is @").add_operation (function_noUnusedWarningAttribute (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 141)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 141)), fixItArray4  COMMA_SOURCE_FILE ("declaration-guard.galgas", 141)) ;
      }
      enumerator_5173.gotoNextObject () ;
    }
    {
    routine_guardSemanticAnalysis (inArgument_inReceiverType, enumerator_5093.current (HERE).mAttribute_mGuardName, enumerator_5093.current (HERE).mAttribute_mGuardFormalArgumentList, enumerator_5093.current (HERE).mAttribute_mGuardKind, enumerator_5093.current (HERE).mAttribute_mGuardInstructionList, enumerator_5093.current (HERE).mAttribute_mEndOfGuardDeclaration, var_warnIfUnused_5117, constinArgument_inSemanticContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 144)) ;
    }
    enumerator_5093.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Class for element of '@procCallEffectiveParameterListIR' list                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_procCallEffectiveParameterListIR : public cCollectionElement {
  public : GALGAS_procCallEffectiveParameterListIR_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_procCallEffectiveParameterListIR (const GALGAS_procEffectiveParameterPassingModeIR & in_mEffectiveParameterPassingMode,
                                                                const GALGAS_objectIR & in_mParameter
                                                                COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_procCallEffectiveParameterListIR::cCollectionElement_procCallEffectiveParameterListIR (const GALGAS_procEffectiveParameterPassingModeIR & in_mEffectiveParameterPassingMode,
                                                                                                          const GALGAS_objectIR & in_mParameter
                                                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mEffectiveParameterPassingMode, in_mParameter) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_procCallEffectiveParameterListIR::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_procCallEffectiveParameterListIR::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_procCallEffectiveParameterListIR (mObject.mAttribute_mEffectiveParameterPassingMode, mObject.mAttribute_mParameter COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_procCallEffectiveParameterListIR::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEffectiveParameterPassingMode" ":" ;
  mObject.mAttribute_mEffectiveParameterPassingMode.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mParameter" ":" ;
  mObject.mAttribute_mParameter.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_procCallEffectiveParameterListIR::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_procCallEffectiveParameterListIR * operand = (cCollectionElement_procCallEffectiveParameterListIR *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_procCallEffectiveParameterListIR) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR::GALGAS_procCallEffectiveParameterListIR (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR::GALGAS_procCallEffectiveParameterListIR (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_procCallEffectiveParameterListIR result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR GALGAS_procCallEffectiveParameterListIR::constructor_listWithValue (const GALGAS_procEffectiveParameterPassingModeIR & inOperand0,
                                                                                                            const GALGAS_objectIR & inOperand1
                                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_procCallEffectiveParameterListIR result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_procCallEffectiveParameterListIR::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                         const GALGAS_procEffectiveParameterPassingModeIR & in_mEffectiveParameterPassingMode,
                                                                         const GALGAS_objectIR & in_mParameter
                                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_procCallEffectiveParameterListIR * p = NULL ;
  macroMyNew (p, cCollectionElement_procCallEffectiveParameterListIR (in_mEffectiveParameterPassingMode,
                                                                      in_mParameter COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR::addAssign_operation (const GALGAS_procEffectiveParameterPassingModeIR & inOperand0,
                                                                   const GALGAS_objectIR & inOperand1
                                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_procCallEffectiveParameterListIR (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR::setter_insertAtIndex (const GALGAS_procEffectiveParameterPassingModeIR inOperand0,
                                                                    const GALGAS_objectIR inOperand1,
                                                                    const GALGAS_uint inInsertionIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_procCallEffectiveParameterListIR (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR::setter_removeAtIndex (GALGAS_procEffectiveParameterPassingModeIR & outOperand0,
                                                                    GALGAS_objectIR & outOperand1,
                                                                    const GALGAS_uint inRemoveIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_procCallEffectiveParameterListIR * p = (cCollectionElement_procCallEffectiveParameterListIR *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_procCallEffectiveParameterListIR) ;
      outOperand0 = p->mObject.mAttribute_mEffectiveParameterPassingMode ;
      outOperand1 = p->mObject.mAttribute_mParameter ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR::setter_popFirst (GALGAS_procEffectiveParameterPassingModeIR & outOperand0,
                                                               GALGAS_objectIR & outOperand1,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procCallEffectiveParameterListIR * p = (cCollectionElement_procCallEffectiveParameterListIR *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procCallEffectiveParameterListIR) ;
    outOperand0 = p->mObject.mAttribute_mEffectiveParameterPassingMode ;
    outOperand1 = p->mObject.mAttribute_mParameter ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR::setter_popLast (GALGAS_procEffectiveParameterPassingModeIR & outOperand0,
                                                              GALGAS_objectIR & outOperand1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procCallEffectiveParameterListIR * p = (cCollectionElement_procCallEffectiveParameterListIR *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procCallEffectiveParameterListIR) ;
    outOperand0 = p->mObject.mAttribute_mEffectiveParameterPassingMode ;
    outOperand1 = p->mObject.mAttribute_mParameter ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR::method_first (GALGAS_procEffectiveParameterPassingModeIR & outOperand0,
                                                            GALGAS_objectIR & outOperand1,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procCallEffectiveParameterListIR * p = (cCollectionElement_procCallEffectiveParameterListIR *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procCallEffectiveParameterListIR) ;
    outOperand0 = p->mObject.mAttribute_mEffectiveParameterPassingMode ;
    outOperand1 = p->mObject.mAttribute_mParameter ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR::method_last (GALGAS_procEffectiveParameterPassingModeIR & outOperand0,
                                                           GALGAS_objectIR & outOperand1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procCallEffectiveParameterListIR * p = (cCollectionElement_procCallEffectiveParameterListIR *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procCallEffectiveParameterListIR) ;
    outOperand0 = p->mObject.mAttribute_mEffectiveParameterPassingMode ;
    outOperand1 = p->mObject.mAttribute_mParameter ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR GALGAS_procCallEffectiveParameterListIR::add_operation (const GALGAS_procCallEffectiveParameterListIR & inOperand,
                                                                                                C_Compiler * /* inCompiler */
                                                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_procCallEffectiveParameterListIR result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR GALGAS_procCallEffectiveParameterListIR::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_procCallEffectiveParameterListIR result = GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR GALGAS_procCallEffectiveParameterListIR::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_procCallEffectiveParameterListIR result = GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR GALGAS_procCallEffectiveParameterListIR::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                                        C_Compiler * inCompiler
                                                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_procCallEffectiveParameterListIR result = GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR::plusAssign_operation (const GALGAS_procCallEffectiveParameterListIR inOperand,
                                                                    C_Compiler * /* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterPassingModeIR GALGAS_procCallEffectiveParameterListIR::getter_mEffectiveParameterPassingModeAtIndex (const GALGAS_uint & inIndex,
                                                                                                                                  C_Compiler * inCompiler
                                                                                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_procCallEffectiveParameterListIR * p = (cCollectionElement_procCallEffectiveParameterListIR *) attributes.ptr () ;
  GALGAS_procEffectiveParameterPassingModeIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_procCallEffectiveParameterListIR) ;
    result = p->mObject.mAttribute_mEffectiveParameterPassingMode ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_procCallEffectiveParameterListIR::getter_mParameterAtIndex (const GALGAS_uint & inIndex,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_procCallEffectiveParameterListIR * p = (cCollectionElement_procCallEffectiveParameterListIR *) attributes.ptr () ;
  GALGAS_objectIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_procCallEffectiveParameterListIR) ;
    result = p->mObject.mAttribute_mParameter ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_procCallEffectiveParameterListIR::cEnumerator_procCallEffectiveParameterListIR (const GALGAS_procCallEffectiveParameterListIR & inEnumeratedObject,
                                                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR_2D_element cEnumerator_procCallEffectiveParameterListIR::current (LOCATION_ARGS) const {
  const cCollectionElement_procCallEffectiveParameterListIR * p = (const cCollectionElement_procCallEffectiveParameterListIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procCallEffectiveParameterListIR) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterPassingModeIR cEnumerator_procCallEffectiveParameterListIR::current_mEffectiveParameterPassingMode (LOCATION_ARGS) const {
  const cCollectionElement_procCallEffectiveParameterListIR * p = (const cCollectionElement_procCallEffectiveParameterListIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procCallEffectiveParameterListIR) ;
  return p->mObject.mAttribute_mEffectiveParameterPassingMode ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cEnumerator_procCallEffectiveParameterListIR::current_mParameter (LOCATION_ARGS) const {
  const cCollectionElement_procCallEffectiveParameterListIR * p = (const cCollectionElement_procCallEffectiveParameterListIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procCallEffectiveParameterListIR) ;
  return p->mObject.mAttribute_mParameter ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @procCallEffectiveParameterListIR type                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procCallEffectiveParameterListIR ("procCallEffectiveParameterListIR",
                                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procCallEffectiveParameterListIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procCallEffectiveParameterListIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procCallEffectiveParameterListIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procCallEffectiveParameterListIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR GALGAS_procCallEffectiveParameterListIR::extractObject (const GALGAS_object & inObject,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_procCallEffectiveParameterListIR result ;
  const GALGAS_procCallEffectiveParameterListIR * p = (const GALGAS_procCallEffectiveParameterListIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procCallEffectiveParameterListIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procCallEffectiveParameterListIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_guardMapIR::cMapElement_guardMapIR (const GALGAS_lstring & inKey,
                                                const GALGAS_procFormalArgumentListForGeneration & in_mFormalArgumentListForGeneration,
                                                const GALGAS_guardKindGenerationIR & in_mGuardKindGenerationIR,
                                                const GALGAS_allocaList & in_mAllocaList,
                                                const GALGAS_instructionListIR & in_mInstructionGenerationList,
                                                const GALGAS_bool & in_mWarnIfUnused
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_mFormalArgumentListForGeneration (in_mFormalArgumentListForGeneration),
mAttribute_mGuardKindGenerationIR (in_mGuardKindGenerationIR),
mAttribute_mAllocaList (in_mAllocaList),
mAttribute_mInstructionGenerationList (in_mInstructionGenerationList),
mAttribute_mWarnIfUnused (in_mWarnIfUnused) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_guardMapIR::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mFormalArgumentListForGeneration.isValid () && mAttribute_mGuardKindGenerationIR.isValid () && mAttribute_mAllocaList.isValid () && mAttribute_mInstructionGenerationList.isValid () && mAttribute_mWarnIfUnused.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_guardMapIR::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_guardMapIR (mAttribute_lkey, mAttribute_mFormalArgumentListForGeneration, mAttribute_mGuardKindGenerationIR, mAttribute_mAllocaList, mAttribute_mInstructionGenerationList, mAttribute_mWarnIfUnused COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_guardMapIR::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFormalArgumentListForGeneration" ":" ;
  mAttribute_mFormalArgumentListForGeneration.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGuardKindGenerationIR" ":" ;
  mAttribute_mGuardKindGenerationIR.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAllocaList" ":" ;
  mAttribute_mAllocaList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mInstructionGenerationList" ":" ;
  mAttribute_mInstructionGenerationList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mWarnIfUnused" ":" ;
  mAttribute_mWarnIfUnused.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_guardMapIR::compare (const cCollectionElement * inOperand) const {
  cMapElement_guardMapIR * operand = (cMapElement_guardMapIR *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_mFormalArgumentListForGeneration.objectCompare (operand->mAttribute_mFormalArgumentListForGeneration) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mGuardKindGenerationIR.objectCompare (operand->mAttribute_mGuardKindGenerationIR) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mAllocaList.objectCompare (operand->mAttribute_mAllocaList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mInstructionGenerationList.objectCompare (operand->mAttribute_mInstructionGenerationList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mWarnIfUnused.objectCompare (operand->mAttribute_mWarnIfUnused) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapIR::GALGAS_guardMapIR (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapIR::GALGAS_guardMapIR (const GALGAS_guardMapIR & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapIR & GALGAS_guardMapIR::operator = (const GALGAS_guardMapIR & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapIR GALGAS_guardMapIR::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_guardMapIR result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapIR GALGAS_guardMapIR::constructor_mapWithMapToOverride (const GALGAS_guardMapIR & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_guardMapIR result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapIR GALGAS_guardMapIR::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_guardMapIR result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardMapIR::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_procFormalArgumentListForGeneration & inArgument0,
                                             const GALGAS_guardKindGenerationIR & inArgument1,
                                             const GALGAS_allocaList & inArgument2,
                                             const GALGAS_instructionListIR & inArgument3,
                                             const GALGAS_bool & inArgument4,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_guardMapIR * p = NULL ;
  macroMyNew (p, cMapElement_guardMapIR (inKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@guardMapIR insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardMapIR::setter_insertKey (GALGAS_lstring inKey,
                                          GALGAS_procFormalArgumentListForGeneration inArgument0,
                                          GALGAS_guardKindGenerationIR inArgument1,
                                          GALGAS_allocaList inArgument2,
                                          GALGAS_instructionListIR inArgument3,
                                          GALGAS_bool inArgument4,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_guardMapIR * p = NULL ;
  macroMyNew (p, cMapElement_guardMapIR (inKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "guard '%K' is already defined" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_guardMapIR_searchKey = "** internal error **" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardMapIR::method_searchKey (GALGAS_lstring inKey,
                                          GALGAS_procFormalArgumentListForGeneration & outArgument0,
                                          GALGAS_guardKindGenerationIR & outArgument1,
                                          GALGAS_allocaList & outArgument2,
                                          GALGAS_instructionListIR & outArgument3,
                                          GALGAS_bool & outArgument4,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_guardMapIR * p = (const cMapElement_guardMapIR *) performSearch (inKey,
                                                                                       inCompiler,
                                                                                       kSearchErrorMessage_guardMapIR_searchKey
                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
    outArgument2.drop () ;
    outArgument3.drop () ;
    outArgument4.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_guardMapIR) ;
    outArgument0 = p->mAttribute_mFormalArgumentListForGeneration ;
    outArgument1 = p->mAttribute_mGuardKindGenerationIR ;
    outArgument2 = p->mAttribute_mAllocaList ;
    outArgument3 = p->mAttribute_mInstructionGenerationList ;
    outArgument4 = p->mAttribute_mWarnIfUnused ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardMapIR::setter_removeKey (GALGAS_lstring inKey,
                                          GALGAS_procFormalArgumentListForGeneration & outArgument0,
                                          GALGAS_guardKindGenerationIR & outArgument1,
                                          GALGAS_allocaList & outArgument2,
                                          GALGAS_instructionListIR & outArgument3,
                                          GALGAS_bool & outArgument4,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "** internal error **" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_guardMapIR * p = (cMapElement_guardMapIR *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_guardMapIR) ;
    outArgument0 = p->mAttribute_mFormalArgumentListForGeneration ;
    outArgument1 = p->mAttribute_mGuardKindGenerationIR ;
    outArgument2 = p->mAttribute_mAllocaList ;
    outArgument3 = p->mAttribute_mInstructionGenerationList ;
    outArgument4 = p->mAttribute_mWarnIfUnused ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration GALGAS_guardMapIR::getter_mFormalArgumentListForGenerationForKey (const GALGAS_string & inKey,
                                                                                                             C_Compiler * inCompiler
                                                                                                             COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_guardMapIR * p = (const cMapElement_guardMapIR *) attributes ;
  GALGAS_procFormalArgumentListForGeneration result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_guardMapIR) ;
    result = p->mAttribute_mFormalArgumentListForGeneration ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardKindGenerationIR GALGAS_guardMapIR::getter_mGuardKindGenerationIRForKey (const GALGAS_string & inKey,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_guardMapIR * p = (const cMapElement_guardMapIR *) attributes ;
  GALGAS_guardKindGenerationIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_guardMapIR) ;
    result = p->mAttribute_mGuardKindGenerationIR ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList GALGAS_guardMapIR::getter_mAllocaListForKey (const GALGAS_string & inKey,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_guardMapIR * p = (const cMapElement_guardMapIR *) attributes ;
  GALGAS_allocaList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_guardMapIR) ;
    result = p->mAttribute_mAllocaList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_guardMapIR::getter_mInstructionGenerationListForKey (const GALGAS_string & inKey,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_guardMapIR * p = (const cMapElement_guardMapIR *) attributes ;
  GALGAS_instructionListIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_guardMapIR) ;
    result = p->mAttribute_mInstructionGenerationList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_guardMapIR::getter_mWarnIfUnusedForKey (const GALGAS_string & inKey,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_guardMapIR * p = (const cMapElement_guardMapIR *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_guardMapIR) ;
    result = p->mAttribute_mWarnIfUnused ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardMapIR::setter_setMFormalArgumentListForGenerationForKey (GALGAS_procFormalArgumentListForGeneration inAttributeValue,
                                                                          GALGAS_string inKey,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_guardMapIR * p = (cMapElement_guardMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_guardMapIR) ;
    p->mAttribute_mFormalArgumentListForGeneration = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardMapIR::setter_setMGuardKindGenerationIRForKey (GALGAS_guardKindGenerationIR inAttributeValue,
                                                                GALGAS_string inKey,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_guardMapIR * p = (cMapElement_guardMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_guardMapIR) ;
    p->mAttribute_mGuardKindGenerationIR = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardMapIR::setter_setMAllocaListForKey (GALGAS_allocaList inAttributeValue,
                                                     GALGAS_string inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_guardMapIR * p = (cMapElement_guardMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_guardMapIR) ;
    p->mAttribute_mAllocaList = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardMapIR::setter_setMInstructionGenerationListForKey (GALGAS_instructionListIR inAttributeValue,
                                                                    GALGAS_string inKey,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_guardMapIR * p = (cMapElement_guardMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_guardMapIR) ;
    p->mAttribute_mInstructionGenerationList = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardMapIR::setter_setMWarnIfUnusedForKey (GALGAS_bool inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_guardMapIR * p = (cMapElement_guardMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_guardMapIR) ;
    p->mAttribute_mWarnIfUnused = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_guardMapIR * GALGAS_guardMapIR::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_guardMapIR * result = (cMapElement_guardMapIR *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_guardMapIR) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_guardMapIR::cEnumerator_guardMapIR (const GALGAS_guardMapIR & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapIR_2D_element cEnumerator_guardMapIR::current (LOCATION_ARGS) const {
  const cMapElement_guardMapIR * p = (const cMapElement_guardMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_guardMapIR) ;
  return GALGAS_guardMapIR_2D_element (p->mAttribute_lkey, p->mAttribute_mFormalArgumentListForGeneration, p->mAttribute_mGuardKindGenerationIR, p->mAttribute_mAllocaList, p->mAttribute_mInstructionGenerationList, p->mAttribute_mWarnIfUnused) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_guardMapIR::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration cEnumerator_guardMapIR::current_mFormalArgumentListForGeneration (LOCATION_ARGS) const {
  const cMapElement_guardMapIR * p = (const cMapElement_guardMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_guardMapIR) ;
  return p->mAttribute_mFormalArgumentListForGeneration ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardKindGenerationIR cEnumerator_guardMapIR::current_mGuardKindGenerationIR (LOCATION_ARGS) const {
  const cMapElement_guardMapIR * p = (const cMapElement_guardMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_guardMapIR) ;
  return p->mAttribute_mGuardKindGenerationIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList cEnumerator_guardMapIR::current_mAllocaList (LOCATION_ARGS) const {
  const cMapElement_guardMapIR * p = (const cMapElement_guardMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_guardMapIR) ;
  return p->mAttribute_mAllocaList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cEnumerator_guardMapIR::current_mInstructionGenerationList (LOCATION_ARGS) const {
  const cMapElement_guardMapIR * p = (const cMapElement_guardMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_guardMapIR) ;
  return p->mAttribute_mInstructionGenerationList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_guardMapIR::current_mWarnIfUnused (LOCATION_ARGS) const {
  const cMapElement_guardMapIR * p = (const cMapElement_guardMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_guardMapIR) ;
  return p->mAttribute_mWarnIfUnused ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @guardMapIR type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_guardMapIR ("guardMapIR",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_guardMapIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_guardMapIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_guardMapIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_guardMapIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapIR GALGAS_guardMapIR::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_guardMapIR result ;
  const GALGAS_guardMapIR * p = (const GALGAS_guardMapIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_guardMapIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("guardMapIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@guardMapIR guardCodeGeneration'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_guardCodeGeneration (const GALGAS_guardMapIR inObject,
                                          GALGAS_string & ioArgument_ioLLVMcode,
                                          GALGAS__32_stringlist & ioArgument_ioServiceList,
                                          const GALGAS_generationContext constinArgument_inGenerationContext,
                                          GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_guardMapIR temp_0 = inObject ;
  cEnumerator_guardMapIR enumerator_15178 (temp_0, kEnumeration_up) ;
  while (enumerator_15178.hasCurrentObject ()) {
    switch (enumerator_15178.current (HERE).mAttribute_mGuardKindGenerationIR.enumValue ()) {
    case GALGAS_guardKindGenerationIR::kNotBuilt:
      break ;
    case GALGAS_guardKindGenerationIR::kEnum_convenienceGuard:
      {
      }
      break ;
    case GALGAS_guardKindGenerationIR::kEnum_baseGuard:
      {
        GALGAS_string var_guardImplementationName_15314 = function_llvmNameForGuardImplementation (enumerator_15178.current (HERE).mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 400)) ;
        GALGAS_string var_guardCallName_15392 = function_llvmNameForGuardCall (enumerator_15178.current (HERE).mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 401)) ;
        ioArgument_ioServiceList.addAssign_operation (var_guardCallName_15392, var_guardImplementationName_15314  COMMA_SOURCE_FILE ("declaration-guard.galgas", 402)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(function_llvmTitleComment (var_guardImplementationName_15314, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 403)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 403)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("declare i1 @").add_operation (var_guardCallName_15392, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 404)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 404)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 404)) ;
        GALGAS_string var_typeName_15640 = enumerator_15178.current (HERE).mAttribute_lkey.mAttribute_string.getter_stringByDeletingPathExtension (SOURCE_FILE ("declaration-guard.galgas", 405)) ;
        GALGAS_bool var_first_15708 = GALGAS_bool (kIsEqual, var_typeName_15640.objectCompare (GALGAS_string::makeEmptyString ())) ;
        const enumGalgasBool test_1 = var_first_15708.operator_not (SOURCE_FILE ("declaration-guard.galgas", 407)).boolEnum () ;
        if (kBoolTrue == test_1) {
          ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("%").add_operation (var_typeName_15640.getter_assemblerRepresentation (SOURCE_FILE ("declaration-guard.galgas", 408)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 408)).add_operation (GALGAS_string (" * %self"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 408)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 408)) ;
        }
        cEnumerator_procFormalArgumentListForGeneration enumerator_15892 (enumerator_15178.current (HERE).mAttribute_mFormalArgumentListForGeneration, kEnumeration_up) ;
        while (enumerator_15892.hasCurrentObject ()) {
          const enumGalgasBool test_2 = var_first_15708.boolEnum () ;
          if (kBoolTrue == test_2) {
            var_first_15708 = GALGAS_bool (false) ;
          }else if (kBoolFalse == test_2) {
            ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 411)) ;
          }
          switch (enumerator_15892.current_mFormalArgumentKind (HERE).enumValue ()) {
          case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
            break ;
          case GALGAS_procFormalArgumentPassingMode::kEnum_input:
            {
              ioArgument_ioLLVMcode.plusAssign_operation(enumerator_15892.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 414)).add_operation (GALGAS_string (" %in."), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 414)).add_operation (enumerator_15892.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 414)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 414)) ;
            }
            break ;
          case GALGAS_procFormalArgumentPassingMode::kEnum_output:
            {
              ioArgument_ioLLVMcode.plusAssign_operation(enumerator_15892.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 416)).add_operation (GALGAS_string (" * %"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 416)).add_operation (function_llvmNameForLocalVariable (enumerator_15892.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 416)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 416)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 416)) ;
            }
            break ;
          case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
            {
              ioArgument_ioLLVMcode.plusAssign_operation(enumerator_15892.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 418)).add_operation (GALGAS_string (" * %"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 418)).add_operation (function_llvmNameForLocalVariable (enumerator_15892.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 418)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 418)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 418)) ;
            }
            break ;
          }
          enumerator_15892.gotoNextObject () ;
        }
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (")").add_operation (function_llvmAttributeFunction (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 421)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 421)).add_operation (GALGAS_string ("\n"
          "\n"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 421)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 421)) ;
      }
      break ;
    }
    extensionMethod_llvmCodeGeneration (enumerator_15178.current (HERE), ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 423)) ;
    enumerator_15178.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   Abstract extension method '@expressionAST noteExpressionTypesInPrecedenceGraph'                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_expressionAST_noteExpressionTypesInPrecedenceGraph> gExtensionMethodTable_expressionAST_noteExpressionTypesInPrecedenceGraph ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (const int32_t inClassIndex,
                                                                extensionMethodSignature_expressionAST_noteExpressionTypesInPrecedenceGraph inMethod) {
  gExtensionMethodTable_expressionAST_noteExpressionTypesInPrecedenceGraph.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_expressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  gExtensionMethodTable_expressionAST_noteExpressionTypesInPrecedenceGraph.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_expressionAST_noteExpressionTypesInPrecedenceGraph (NULL,
                                                                               freeExtensionMethod_expressionAST_noteExpressionTypesInPrecedenceGraph) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                               GALGAS_semanticTypePrecedenceGraph & io_ioGraph,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_expressionAST) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_expressionAST_noteExpressionTypesInPrecedenceGraph f = NULL ;
    if (classIndex < gExtensionMethodTable_expressionAST_noteExpressionTypesInPrecedenceGraph.count ()) {
      f = gExtensionMethodTable_expressionAST_noteExpressionTypesInPrecedenceGraph (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_expressionAST_noteExpressionTypesInPrecedenceGraph.count ()) {
          f = gExtensionMethodTable_expressionAST_noteExpressionTypesInPrecedenceGraph (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_expressionAST_noteExpressionTypesInPrecedenceGraph.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_ioGraph, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Abstract extension method '@expressionAST analyzeExpression'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_expressionAST_analyzeExpression> gExtensionMethodTable_expressionAST_analyzeExpression ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_analyzeExpression (const int32_t inClassIndex,
                                             extensionMethodSignature_expressionAST_analyzeExpression inMethod) {
  gExtensionMethodTable_expressionAST_analyzeExpression.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_expressionAST_analyzeExpression (void) {
  gExtensionMethodTable_expressionAST_analyzeExpression.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_expressionAST_analyzeExpression (NULL,
                                                            freeExtensionMethod_expressionAST_analyzeExpression) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_analyzeExpression (const cPtr_expressionAST * inObject,
                                            const GALGAS_unifiedTypeMap_2D_proxy constin_inSelfType,
                                            const GALGAS_bool constin_inDirectAccessToPropertiesAllowed,
                                            const GALGAS_bool constin_inGuard,
                                            const GALGAS_lstring constin_inCallerNameForInvocationGraph,
                                            const GALGAS_unifiedTypeMap_2D_proxy constin_inTargetType,
                                            const GALGAS_semanticContext constin_inContext,
                                            const GALGAS_mode constin_inCurrentMode,
                                            GALGAS_semanticTemporariesStruct & io_ioTemporaries,
                                            GALGAS_staticStringMap & io_ioGlobalLiteralStringMap,
                                            GALGAS_variableMap & io_ioVariableMap,
                                            GALGAS_allocaList & io_ioAllocaList,
                                            GALGAS_instructionListIR & io_ioInstructionGenerationList,
                                            GALGAS_objectIR & out_outResult,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
//--- Drop output arguments
  out_outResult.drop () ;
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_expressionAST) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_expressionAST_analyzeExpression f = NULL ;
    if (classIndex < gExtensionMethodTable_expressionAST_analyzeExpression.count ()) {
      f = gExtensionMethodTable_expressionAST_analyzeExpression (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_expressionAST_analyzeExpression.count ()) {
          f = gExtensionMethodTable_expressionAST_analyzeExpression (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_expressionAST_analyzeExpression.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_inSelfType, constin_inDirectAccessToPropertiesAllowed, constin_inGuard, constin_inCallerNameForInvocationGraph, constin_inTargetType, constin_inContext, constin_inCurrentMode, io_ioTemporaries, io_ioGlobalLiteralStringMap, io_ioVariableMap, io_ioAllocaList, io_ioInstructionGenerationList, out_outResult, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension method '@expressionAST analyzeStaticExpression'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_expressionAST_analyzeStaticExpression> gExtensionMethodTable_expressionAST_analyzeStaticExpression ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_analyzeStaticExpression (const int32_t inClassIndex,
                                                   extensionMethodSignature_expressionAST_analyzeStaticExpression inMethod) {
  gExtensionMethodTable_expressionAST_analyzeStaticExpression.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_analyzeStaticExpression (const cPtr_expressionAST * inObject,
                                                  const GALGAS_location constin_inErrorLocation,
                                                  const GALGAS_semanticContext constin_inContext,
                                                  GALGAS_staticStringMap & io_ioGlobalLiteralStringMap,
                                                  GALGAS_objectIR & out_outResult,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  out_outResult.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_expressionAST) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_expressionAST_analyzeStaticExpression f = NULL ;
    if (classIndex < gExtensionMethodTable_expressionAST_analyzeStaticExpression.count ()) {
      f = gExtensionMethodTable_expressionAST_analyzeStaticExpression (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_expressionAST_analyzeStaticExpression.count ()) {
           f = gExtensionMethodTable_expressionAST_analyzeStaticExpression (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_expressionAST_analyzeStaticExpression.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_inErrorLocation, constin_inContext, io_ioGlobalLiteralStringMap, out_outResult, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_expressionAST_analyzeStaticExpression (const cPtr_expressionAST * inObject,
                                                                   const GALGAS_location constinArgument_inErrorLocation,
                                                                   const GALGAS_semanticContext constinArgument_inContext,
                                                                   GALGAS_staticStringMap & ioArgument_ioGlobalLiteralStringMap,
                                                                   GALGAS_objectIR & outArgument_outResult,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_expressionAST * object = inObject ;
  macroValidSharedObject (object, cPtr_expressionAST) ;
  GALGAS_instructionListIR var_instructionGenerationList_14239 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("expression-operator-priority.galgas", 455)) ;
  GALGAS_allocaList var_allocaList_14269 = GALGAS_allocaList::constructor_emptyList (SOURCE_FILE ("expression-operator-priority.galgas", 456)) ;
  GALGAS_semanticTemporariesStruct joker_14524 = GALGAS_semanticTemporariesStruct::constructor_default (SOURCE_FILE ("expression-operator-priority.galgas", 465)) ;
  GALGAS_variableMap joker_14591 = GALGAS_variableMap::constructor_emptyMap (SOURCE_FILE ("expression-operator-priority.galgas", 467)) ;
  const GALGAS_expressionAST temp_0 = object ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) temp_0.ptr (), GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("expression-operator-priority.galgas", 458)), GALGAS_bool (false), GALGAS_bool (false), GALGAS_string ("compiler").getter_nowhere (SOURCE_FILE ("expression-operator-priority.galgas", 461)), GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("expression-operator-priority.galgas", 462)), constinArgument_inContext, GALGAS_mode::constructor_bootMode (SOURCE_FILE ("expression-operator-priority.galgas", 464)), joker_14524, ioArgument_ioGlobalLiteralStringMap, joker_14591, var_allocaList_14269, var_instructionGenerationList_14239, outArgument_outResult, inCompiler COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 457)) ;
  GALGAS_bool test_1 = GALGAS_bool (kIsStrictSup, var_allocaList_14269.getter_length (SOURCE_FILE ("expression-operator-priority.galgas", 472)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
  if (kBoolTrue != test_1.boolEnum ()) {
    test_1 = GALGAS_bool (kIsStrictSup, var_instructionGenerationList_14239.getter_length (SOURCE_FILE ("expression-operator-priority.galgas", 472)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
  }
  GALGAS_bool test_2 = test_1 ;
  if (kBoolTrue != test_2.boolEnum ()) {
    test_2 = extensionGetter_isStatic (outArgument_outResult, inCompiler COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 472)).operator_not (SOURCE_FILE ("expression-operator-priority.galgas", 472)) ;
  }
  const enumGalgasBool test_3 = test_2.boolEnum () ;
  if (kBoolTrue == test_3) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_inErrorLocation, GALGAS_string ("this expression should be a static expression"), fixItArray4  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 473)) ;
    outArgument_outResult.drop () ; // Release error dropped variable
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_expressionAST_analyzeStaticExpression (void) {
  enterExtensionMethod_analyzeStaticExpression (kTypeDescriptor_GALGAS_expressionAST.mSlotID,
                                                extensionMethod_expressionAST_analyzeStaticExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_expressionAST_analyzeStaticExpression (void) {
  gExtensionMethodTable_expressionAST_analyzeStaticExpression.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_expressionAST_analyzeStaticExpression (defineExtensionMethod_expressionAST_analyzeStaticExpression,
                                                                  freeExtensionMethod_expressionAST_analyzeStaticExpression) ;

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_abstractInstructionIR::objectCompare (const GALGAS_abstractInstructionIR & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractInstructionIR::GALGAS_abstractInstructionIR (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractInstructionIR::GALGAS_abstractInstructionIR (const cPtr_abstractInstructionIR * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_abstractInstructionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @abstractInstructionIR class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_abstractInstructionIR::cPtr_abstractInstructionIR (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @abstractInstructionIR type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_abstractInstructionIR ("abstractInstructionIR",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_abstractInstructionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_abstractInstructionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_abstractInstructionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_abstractInstructionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractInstructionIR GALGAS_abstractInstructionIR::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_abstractInstructionIR result ;
  const GALGAS_abstractInstructionIR * p = (const GALGAS_abstractInstructionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_abstractInstructionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("abstractInstructionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Class for element of '@functionCallEffectiveParameterList' list                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_functionCallEffectiveParameterList : public cCollectionElement {
  public : GALGAS_functionCallEffectiveParameterList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_functionCallEffectiveParameterList (const GALGAS_lstring & in_mSelector,
                                                                  const GALGAS_expressionAST & in_mExpression
                                                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_functionCallEffectiveParameterList::cCollectionElement_functionCallEffectiveParameterList (const GALGAS_lstring & in_mSelector,
                                                                                                              const GALGAS_expressionAST & in_mExpression
                                                                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mSelector, in_mExpression) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_functionCallEffectiveParameterList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_functionCallEffectiveParameterList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_functionCallEffectiveParameterList (mObject.mAttribute_mSelector, mObject.mAttribute_mExpression COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_functionCallEffectiveParameterList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSelector" ":" ;
  mObject.mAttribute_mSelector.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mExpression" ":" ;
  mObject.mAttribute_mExpression.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_functionCallEffectiveParameterList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_functionCallEffectiveParameterList * operand = (cCollectionElement_functionCallEffectiveParameterList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_functionCallEffectiveParameterList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList::GALGAS_functionCallEffectiveParameterList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList::GALGAS_functionCallEffectiveParameterList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList GALGAS_functionCallEffectiveParameterList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_functionCallEffectiveParameterList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList GALGAS_functionCallEffectiveParameterList::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                                                                const GALGAS_expressionAST & inOperand1
                                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_functionCallEffectiveParameterList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_functionCallEffectiveParameterList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionCallEffectiveParameterList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                           const GALGAS_lstring & in_mSelector,
                                                                           const GALGAS_expressionAST & in_mExpression
                                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement_functionCallEffectiveParameterList * p = NULL ;
  macroMyNew (p, cCollectionElement_functionCallEffectiveParameterList (in_mSelector,
                                                                        in_mExpression COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionCallEffectiveParameterList::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                                     const GALGAS_expressionAST & inOperand1
                                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_functionCallEffectiveParameterList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionCallEffectiveParameterList::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                                      const GALGAS_expressionAST inOperand1,
                                                                      const GALGAS_uint inInsertionIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_functionCallEffectiveParameterList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionCallEffectiveParameterList::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                                      GALGAS_expressionAST & outOperand1,
                                                                      const GALGAS_uint inRemoveIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_functionCallEffectiveParameterList * p = (cCollectionElement_functionCallEffectiveParameterList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_functionCallEffectiveParameterList) ;
      outOperand0 = p->mObject.mAttribute_mSelector ;
      outOperand1 = p->mObject.mAttribute_mExpression ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionCallEffectiveParameterList::setter_popFirst (GALGAS_lstring & outOperand0,
                                                                 GALGAS_expressionAST & outOperand1,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_functionCallEffectiveParameterList * p = (cCollectionElement_functionCallEffectiveParameterList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_functionCallEffectiveParameterList) ;
    outOperand0 = p->mObject.mAttribute_mSelector ;
    outOperand1 = p->mObject.mAttribute_mExpression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionCallEffectiveParameterList::setter_popLast (GALGAS_lstring & outOperand0,
                                                                GALGAS_expressionAST & outOperand1,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_functionCallEffectiveParameterList * p = (cCollectionElement_functionCallEffectiveParameterList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_functionCallEffectiveParameterList) ;
    outOperand0 = p->mObject.mAttribute_mSelector ;
    outOperand1 = p->mObject.mAttribute_mExpression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionCallEffectiveParameterList::method_first (GALGAS_lstring & outOperand0,
                                                              GALGAS_expressionAST & outOperand1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_functionCallEffectiveParameterList * p = (cCollectionElement_functionCallEffectiveParameterList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_functionCallEffectiveParameterList) ;
    outOperand0 = p->mObject.mAttribute_mSelector ;
    outOperand1 = p->mObject.mAttribute_mExpression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionCallEffectiveParameterList::method_last (GALGAS_lstring & outOperand0,
                                                             GALGAS_expressionAST & outOperand1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_functionCallEffectiveParameterList * p = (cCollectionElement_functionCallEffectiveParameterList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_functionCallEffectiveParameterList) ;
    outOperand0 = p->mObject.mAttribute_mSelector ;
    outOperand1 = p->mObject.mAttribute_mExpression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList GALGAS_functionCallEffectiveParameterList::add_operation (const GALGAS_functionCallEffectiveParameterList & inOperand,
                                                                                                    C_Compiler * /* inCompiler */
                                                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_functionCallEffectiveParameterList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList GALGAS_functionCallEffectiveParameterList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                              C_Compiler * inCompiler
                                                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_functionCallEffectiveParameterList result = GALGAS_functionCallEffectiveParameterList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList GALGAS_functionCallEffectiveParameterList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                              C_Compiler * inCompiler
                                                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_functionCallEffectiveParameterList result = GALGAS_functionCallEffectiveParameterList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList GALGAS_functionCallEffectiveParameterList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_functionCallEffectiveParameterList result = GALGAS_functionCallEffectiveParameterList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionCallEffectiveParameterList::plusAssign_operation (const GALGAS_functionCallEffectiveParameterList inOperand,
                                                                      C_Compiler * /* inCompiler */
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_functionCallEffectiveParameterList::getter_mSelectorAtIndex (const GALGAS_uint & inIndex,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_functionCallEffectiveParameterList * p = (cCollectionElement_functionCallEffectiveParameterList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_functionCallEffectiveParameterList) ;
    result = p->mObject.mAttribute_mSelector ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_functionCallEffectiveParameterList::getter_mExpressionAtIndex (const GALGAS_uint & inIndex,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_functionCallEffectiveParameterList * p = (cCollectionElement_functionCallEffectiveParameterList *) attributes.ptr () ;
  GALGAS_expressionAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_functionCallEffectiveParameterList) ;
    result = p->mObject.mAttribute_mExpression ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_functionCallEffectiveParameterList::cEnumerator_functionCallEffectiveParameterList (const GALGAS_functionCallEffectiveParameterList & inEnumeratedObject,
                                                                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList_2D_element cEnumerator_functionCallEffectiveParameterList::current (LOCATION_ARGS) const {
  const cCollectionElement_functionCallEffectiveParameterList * p = (const cCollectionElement_functionCallEffectiveParameterList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionCallEffectiveParameterList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_functionCallEffectiveParameterList::current_mSelector (LOCATION_ARGS) const {
  const cCollectionElement_functionCallEffectiveParameterList * p = (const cCollectionElement_functionCallEffectiveParameterList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionCallEffectiveParameterList) ;
  return p->mObject.mAttribute_mSelector ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cEnumerator_functionCallEffectiveParameterList::current_mExpression (LOCATION_ARGS) const {
  const cCollectionElement_functionCallEffectiveParameterList * p = (const cCollectionElement_functionCallEffectiveParameterList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionCallEffectiveParameterList) ;
  return p->mObject.mAttribute_mExpression ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @functionCallEffectiveParameterList type                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_functionCallEffectiveParameterList ("functionCallEffectiveParameterList",
                                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_functionCallEffectiveParameterList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_functionCallEffectiveParameterList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_functionCallEffectiveParameterList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_functionCallEffectiveParameterList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList GALGAS_functionCallEffectiveParameterList::extractObject (const GALGAS_object & inObject,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_functionCallEffectiveParameterList result ;
  const GALGAS_functionCallEffectiveParameterList * p = (const GALGAS_functionCallEffectiveParameterList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_functionCallEffectiveParameterList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("functionCallEffectiveParameterList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_ifExpressionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_ifExpressionAST * p = (const cPtr_ifExpressionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_ifExpressionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mIfExpression.objectCompare (p->mAttribute_mIfExpression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mIfExpressionEndLocation.objectCompare (p->mAttribute_mIfExpressionEndLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mThenExpression.objectCompare (p->mAttribute_mThenExpression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mThenExpressionEndLocation.objectCompare (p->mAttribute_mThenExpressionEndLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mElseExpression.objectCompare (p->mAttribute_mElseExpression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mElseExpressionEndLocation.objectCompare (p->mAttribute_mElseExpressionEndLocation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_ifExpressionAST::objectCompare (const GALGAS_ifExpressionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ifExpressionAST::GALGAS_ifExpressionAST (void) :
GALGAS_expressionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ifExpressionAST::GALGAS_ifExpressionAST (const cPtr_ifExpressionAST * inSourcePtr) :
GALGAS_expressionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_ifExpressionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ifExpressionAST GALGAS_ifExpressionAST::constructor_new (const GALGAS_expressionAST & inAttribute_mIfExpression,
                                                                const GALGAS_location & inAttribute_mIfExpressionEndLocation,
                                                                const GALGAS_expressionAST & inAttribute_mThenExpression,
                                                                const GALGAS_location & inAttribute_mThenExpressionEndLocation,
                                                                const GALGAS_expressionAST & inAttribute_mElseExpression,
                                                                const GALGAS_location & inAttribute_mElseExpressionEndLocation
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_ifExpressionAST result ;
  if (inAttribute_mIfExpression.isValid () && inAttribute_mIfExpressionEndLocation.isValid () && inAttribute_mThenExpression.isValid () && inAttribute_mThenExpressionEndLocation.isValid () && inAttribute_mElseExpression.isValid () && inAttribute_mElseExpressionEndLocation.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_ifExpressionAST (inAttribute_mIfExpression, inAttribute_mIfExpressionEndLocation, inAttribute_mThenExpression, inAttribute_mThenExpressionEndLocation, inAttribute_mElseExpression, inAttribute_mElseExpressionEndLocation COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_ifExpressionAST::getter_mIfExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifExpressionAST * p = (const cPtr_ifExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifExpressionAST) ;
    result = p->mAttribute_mIfExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_ifExpressionAST::getter_mIfExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIfExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_ifExpressionAST::getter_mIfExpressionEndLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifExpressionAST * p = (const cPtr_ifExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifExpressionAST) ;
    result = p->mAttribute_mIfExpressionEndLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_ifExpressionAST::getter_mIfExpressionEndLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIfExpressionEndLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_ifExpressionAST::getter_mThenExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifExpressionAST * p = (const cPtr_ifExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifExpressionAST) ;
    result = p->mAttribute_mThenExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_ifExpressionAST::getter_mThenExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mThenExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_ifExpressionAST::getter_mThenExpressionEndLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifExpressionAST * p = (const cPtr_ifExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifExpressionAST) ;
    result = p->mAttribute_mThenExpressionEndLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_ifExpressionAST::getter_mThenExpressionEndLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mThenExpressionEndLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_ifExpressionAST::getter_mElseExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifExpressionAST * p = (const cPtr_ifExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifExpressionAST) ;
    result = p->mAttribute_mElseExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_ifExpressionAST::getter_mElseExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mElseExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_ifExpressionAST::getter_mElseExpressionEndLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifExpressionAST * p = (const cPtr_ifExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifExpressionAST) ;
    result = p->mAttribute_mElseExpressionEndLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_ifExpressionAST::getter_mElseExpressionEndLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mElseExpressionEndLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @ifExpressionAST class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_ifExpressionAST::cPtr_ifExpressionAST (const GALGAS_expressionAST & in_mIfExpression,
                                            const GALGAS_location & in_mIfExpressionEndLocation,
                                            const GALGAS_expressionAST & in_mThenExpression,
                                            const GALGAS_location & in_mThenExpressionEndLocation,
                                            const GALGAS_expressionAST & in_mElseExpression,
                                            const GALGAS_location & in_mElseExpressionEndLocation
                                            COMMA_LOCATION_ARGS) :
cPtr_expressionAST (THERE),
mAttribute_mIfExpression (in_mIfExpression),
mAttribute_mIfExpressionEndLocation (in_mIfExpressionEndLocation),
mAttribute_mThenExpression (in_mThenExpression),
mAttribute_mThenExpressionEndLocation (in_mThenExpressionEndLocation),
mAttribute_mElseExpression (in_mElseExpression),
mAttribute_mElseExpressionEndLocation (in_mElseExpressionEndLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_ifExpressionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ifExpressionAST ;
}

void cPtr_ifExpressionAST::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@ifExpressionAST:" ;
  mAttribute_mIfExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mIfExpressionEndLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mThenExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mThenExpressionEndLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mElseExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mElseExpressionEndLocation.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_ifExpressionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_ifExpressionAST (mAttribute_mIfExpression, mAttribute_mIfExpressionEndLocation, mAttribute_mThenExpression, mAttribute_mThenExpressionEndLocation, mAttribute_mElseExpression, mAttribute_mElseExpressionEndLocation COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @ifExpressionAST type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ifExpressionAST ("ifExpressionAST",
                                        & kTypeDescriptor_GALGAS_expressionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_ifExpressionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ifExpressionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_ifExpressionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ifExpressionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ifExpressionAST GALGAS_ifExpressionAST::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_ifExpressionAST result ;
  const GALGAS_ifExpressionAST * p = (const GALGAS_ifExpressionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ifExpressionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ifExpressionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator::GALGAS_infixOperator (void) :
mEnum (kNotBuilt) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_equal (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_equal ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_nonEqual (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_nonEqual ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_strictInf (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_strictInf ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_strictSup (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_strictSup ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_infEqual (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_infEqual ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_supEqual (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_supEqual ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_andOp (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_andOp ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_orOp (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_orOp ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_xorOp (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_xorOp ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_booleanXorOp (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_booleanXorOp ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_addOp (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_addOp ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_addOpNoOvf (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_addOpNoOvf ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_subOp (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_subOp ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_subOpNoOvf (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_subOpNoOvf ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_mulOp (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_mulOp ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_mulOpNoOvf (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_mulOpNoOvf ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_divOp (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_divOp ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_divOpNoOvf (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_divOpNoOvf ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_modOp (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_modOp ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_modOpNoOvf (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_modOpNoOvf ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_leftShiftOp (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_leftShiftOp ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::constructor_rightShiftOp (UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  result.mEnum = kEnum_rightShiftOp ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * gEnumNameArrayFor_infixOperator [23] = {
  "(not built)",
  "equal",
  "nonEqual",
  "strictInf",
  "strictSup",
  "infEqual",
  "supEqual",
  "andOp",
  "orOp",
  "xorOp",
  "booleanXorOp",
  "addOp",
  "addOpNoOvf",
  "subOp",
  "subOpNoOvf",
  "mulOp",
  "mulOpNoOvf",
  "divOp",
  "divOpNoOvf",
  "modOp",
  "modOpNoOvf",
  "leftShiftOp",
  "rightShiftOp"
} ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isEqual (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_equal == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isNonEqual (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_nonEqual == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isStrictInf (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_strictInf == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isStrictSup (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_strictSup == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isInfEqual (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_infEqual == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isSupEqual (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_supEqual == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isAndOp (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_andOp == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isOrOp (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_orOp == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isXorOp (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_xorOp == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isBooleanXorOp (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_booleanXorOp == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isAddOp (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_addOp == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isAddOpNoOvf (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_addOpNoOvf == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isSubOp (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_subOp == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isSubOpNoOvf (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_subOpNoOvf == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isMulOp (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_mulOp == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isMulOpNoOvf (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_mulOpNoOvf == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isDivOp (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_divOp == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isDivOpNoOvf (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_divOpNoOvf == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isModOp (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_modOp == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isModOpNoOvf (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_modOpNoOvf == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isLeftShiftOp (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_leftShiftOp == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_infixOperator::getter_isRightShiftOp (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_rightShiftOp == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_infixOperator::description (C_String & ioString,
                                        const int32_t /* inIndentation */) const {
  ioString << "<enum @infixOperator: " << gEnumNameArrayFor_infixOperator [mEnum] ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_infixOperator::objectCompare (const GALGAS_infixOperator & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @infixOperator type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_infixOperator ("infixOperator",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_infixOperator::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_infixOperator ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_infixOperator::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_infixOperator (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperator::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_infixOperator result ;
  const GALGAS_infixOperator * p = (const GALGAS_infixOperator *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_infixOperator *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("infixOperator", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_infixOperatorExpressionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_infixOperatorExpressionAST * p = (const cPtr_infixOperatorExpressionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_infixOperatorExpressionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mLeftExpression.objectCompare (p->mAttribute_mLeftExpression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mOperatorLocation.objectCompare (p->mAttribute_mOperatorLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mOp.objectCompare (p->mAttribute_mOp) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mRightExpression.objectCompare (p->mAttribute_mRightExpression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_infixOperatorExpressionAST::objectCompare (const GALGAS_infixOperatorExpressionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorExpressionAST::GALGAS_infixOperatorExpressionAST (void) :
GALGAS_expressionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorExpressionAST::GALGAS_infixOperatorExpressionAST (const cPtr_infixOperatorExpressionAST * inSourcePtr) :
GALGAS_expressionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_infixOperatorExpressionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorExpressionAST GALGAS_infixOperatorExpressionAST::constructor_new (const GALGAS_expressionAST & inAttribute_mLeftExpression,
                                                                                      const GALGAS_location & inAttribute_mOperatorLocation,
                                                                                      const GALGAS_infixOperator & inAttribute_mOp,
                                                                                      const GALGAS_expressionAST & inAttribute_mRightExpression
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_infixOperatorExpressionAST result ;
  if (inAttribute_mLeftExpression.isValid () && inAttribute_mOperatorLocation.isValid () && inAttribute_mOp.isValid () && inAttribute_mRightExpression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_infixOperatorExpressionAST (inAttribute_mLeftExpression, inAttribute_mOperatorLocation, inAttribute_mOp, inAttribute_mRightExpression COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_infixOperatorExpressionAST::getter_mLeftExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_infixOperatorExpressionAST * p = (const cPtr_infixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_infixOperatorExpressionAST) ;
    result = p->mAttribute_mLeftExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_infixOperatorExpressionAST::getter_mLeftExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLeftExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_infixOperatorExpressionAST::getter_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_infixOperatorExpressionAST * p = (const cPtr_infixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_infixOperatorExpressionAST) ;
    result = p->mAttribute_mOperatorLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_infixOperatorExpressionAST::getter_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperatorLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperatorExpressionAST::getter_mOp (UNUSED_LOCATION_ARGS) const {
  GALGAS_infixOperator result ;
  if (NULL != mObjectPtr) {
    const cPtr_infixOperatorExpressionAST * p = (const cPtr_infixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_infixOperatorExpressionAST) ;
    result = p->mAttribute_mOp ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator cPtr_infixOperatorExpressionAST::getter_mOp (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOp ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_infixOperatorExpressionAST::getter_mRightExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_infixOperatorExpressionAST * p = (const cPtr_infixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_infixOperatorExpressionAST) ;
    result = p->mAttribute_mRightExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_infixOperatorExpressionAST::getter_mRightExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRightExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @infixOperatorExpressionAST class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_infixOperatorExpressionAST::cPtr_infixOperatorExpressionAST (const GALGAS_expressionAST & in_mLeftExpression,
                                                                  const GALGAS_location & in_mOperatorLocation,
                                                                  const GALGAS_infixOperator & in_mOp,
                                                                  const GALGAS_expressionAST & in_mRightExpression
                                                                  COMMA_LOCATION_ARGS) :
cPtr_expressionAST (THERE),
mAttribute_mLeftExpression (in_mLeftExpression),
mAttribute_mOperatorLocation (in_mOperatorLocation),
mAttribute_mOp (in_mOp),
mAttribute_mRightExpression (in_mRightExpression) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_infixOperatorExpressionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_infixOperatorExpressionAST ;
}

void cPtr_infixOperatorExpressionAST::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@infixOperatorExpressionAST:" ;
  mAttribute_mLeftExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mOperatorLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mOp.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mRightExpression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_infixOperatorExpressionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_infixOperatorExpressionAST (mAttribute_mLeftExpression, mAttribute_mOperatorLocation, mAttribute_mOp, mAttribute_mRightExpression COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @infixOperatorExpressionAST type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_infixOperatorExpressionAST ("infixOperatorExpressionAST",
                                                   & kTypeDescriptor_GALGAS_expressionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_infixOperatorExpressionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_infixOperatorExpressionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_infixOperatorExpressionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_infixOperatorExpressionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorExpressionAST GALGAS_infixOperatorExpressionAST::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_infixOperatorExpressionAST result ;
  const GALGAS_infixOperatorExpressionAST * p = (const GALGAS_infixOperatorExpressionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_infixOperatorExpressionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("infixOperatorExpressionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_booleanShortCircuitAndOperatorExpressionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_booleanShortCircuitAndOperatorExpressionAST * p = (const cPtr_booleanShortCircuitAndOperatorExpressionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_booleanShortCircuitAndOperatorExpressionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mLeftExpression.objectCompare (p->mAttribute_mLeftExpression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mOperatorLocation.objectCompare (p->mAttribute_mOperatorLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mRightExpression.objectCompare (p->mAttribute_mRightExpression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_booleanShortCircuitAndOperatorExpressionAST::objectCompare (const GALGAS_booleanShortCircuitAndOperatorExpressionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_booleanShortCircuitAndOperatorExpressionAST::GALGAS_booleanShortCircuitAndOperatorExpressionAST (void) :
GALGAS_expressionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_booleanShortCircuitAndOperatorExpressionAST::GALGAS_booleanShortCircuitAndOperatorExpressionAST (const cPtr_booleanShortCircuitAndOperatorExpressionAST * inSourcePtr) :
GALGAS_expressionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_booleanShortCircuitAndOperatorExpressionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_booleanShortCircuitAndOperatorExpressionAST GALGAS_booleanShortCircuitAndOperatorExpressionAST::constructor_new (const GALGAS_expressionAST & inAttribute_mLeftExpression,
                                                                                                                        const GALGAS_location & inAttribute_mOperatorLocation,
                                                                                                                        const GALGAS_expressionAST & inAttribute_mRightExpression
                                                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_booleanShortCircuitAndOperatorExpressionAST result ;
  if (inAttribute_mLeftExpression.isValid () && inAttribute_mOperatorLocation.isValid () && inAttribute_mRightExpression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_booleanShortCircuitAndOperatorExpressionAST (inAttribute_mLeftExpression, inAttribute_mOperatorLocation, inAttribute_mRightExpression COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_booleanShortCircuitAndOperatorExpressionAST::getter_mLeftExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_booleanShortCircuitAndOperatorExpressionAST * p = (const cPtr_booleanShortCircuitAndOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_booleanShortCircuitAndOperatorExpressionAST) ;
    result = p->mAttribute_mLeftExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_booleanShortCircuitAndOperatorExpressionAST::getter_mLeftExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLeftExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_booleanShortCircuitAndOperatorExpressionAST::getter_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_booleanShortCircuitAndOperatorExpressionAST * p = (const cPtr_booleanShortCircuitAndOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_booleanShortCircuitAndOperatorExpressionAST) ;
    result = p->mAttribute_mOperatorLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_booleanShortCircuitAndOperatorExpressionAST::getter_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperatorLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_booleanShortCircuitAndOperatorExpressionAST::getter_mRightExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_booleanShortCircuitAndOperatorExpressionAST * p = (const cPtr_booleanShortCircuitAndOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_booleanShortCircuitAndOperatorExpressionAST) ;
    result = p->mAttribute_mRightExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_booleanShortCircuitAndOperatorExpressionAST::getter_mRightExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRightExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                        Pointer class for @booleanShortCircuitAndOperatorExpressionAST class                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_booleanShortCircuitAndOperatorExpressionAST::cPtr_booleanShortCircuitAndOperatorExpressionAST (const GALGAS_expressionAST & in_mLeftExpression,
                                                                                                    const GALGAS_location & in_mOperatorLocation,
                                                                                                    const GALGAS_expressionAST & in_mRightExpression
                                                                                                    COMMA_LOCATION_ARGS) :
cPtr_expressionAST (THERE),
mAttribute_mLeftExpression (in_mLeftExpression),
mAttribute_mOperatorLocation (in_mOperatorLocation),
mAttribute_mRightExpression (in_mRightExpression) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_booleanShortCircuitAndOperatorExpressionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_booleanShortCircuitAndOperatorExpressionAST ;
}

void cPtr_booleanShortCircuitAndOperatorExpressionAST::description (C_String & ioString,
                                                                    const int32_t inIndentation) const {
  ioString << "[@booleanShortCircuitAndOperatorExpressionAST:" ;
  mAttribute_mLeftExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mOperatorLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mRightExpression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_booleanShortCircuitAndOperatorExpressionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_booleanShortCircuitAndOperatorExpressionAST (mAttribute_mLeftExpression, mAttribute_mOperatorLocation, mAttribute_mRightExpression COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  @booleanShortCircuitAndOperatorExpressionAST type                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_booleanShortCircuitAndOperatorExpressionAST ("booleanShortCircuitAndOperatorExpressionAST",
                                                                    & kTypeDescriptor_GALGAS_expressionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_booleanShortCircuitAndOperatorExpressionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_booleanShortCircuitAndOperatorExpressionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_booleanShortCircuitAndOperatorExpressionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_booleanShortCircuitAndOperatorExpressionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_booleanShortCircuitAndOperatorExpressionAST GALGAS_booleanShortCircuitAndOperatorExpressionAST::extractObject (const GALGAS_object & inObject,
                                                                                                                      C_Compiler * inCompiler
                                                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_booleanShortCircuitAndOperatorExpressionAST result ;
  const GALGAS_booleanShortCircuitAndOperatorExpressionAST * p = (const GALGAS_booleanShortCircuitAndOperatorExpressionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_booleanShortCircuitAndOperatorExpressionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("booleanShortCircuitAndOperatorExpressionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_infixOperatorMap::cMapElement_infixOperatorMap (const GALGAS_lstring & inKey,
                                                            const GALGAS_unifiedTypeMap_2D_proxy & in_mResultType,
                                                            const GALGAS_infixOperatorDescription & in_mOperation
                                                            COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_mResultType (in_mResultType),
mAttribute_mOperation (in_mOperation) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_infixOperatorMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mResultType.isValid () && mAttribute_mOperation.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_infixOperatorMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_infixOperatorMap (mAttribute_lkey, mAttribute_mResultType, mAttribute_mOperation COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_infixOperatorMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mResultType" ":" ;
  mAttribute_mResultType.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mOperation" ":" ;
  mAttribute_mOperation.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_infixOperatorMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_infixOperatorMap * operand = (cMapElement_infixOperatorMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_mResultType.objectCompare (operand->mAttribute_mResultType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mOperation.objectCompare (operand->mAttribute_mOperation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap::GALGAS_infixOperatorMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap::GALGAS_infixOperatorMap (const GALGAS_infixOperatorMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap & GALGAS_infixOperatorMap::operator = (const GALGAS_infixOperatorMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap GALGAS_infixOperatorMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_infixOperatorMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap GALGAS_infixOperatorMap::constructor_mapWithMapToOverride (const GALGAS_infixOperatorMap & inMapToOverride
                                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_infixOperatorMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap GALGAS_infixOperatorMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  GALGAS_infixOperatorMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_infixOperatorMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                   const GALGAS_unifiedTypeMap_2D_proxy & inArgument0,
                                                   const GALGAS_infixOperatorDescription & inArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cMapElement_infixOperatorMap * p = NULL ;
  macroMyNew (p, cMapElement_infixOperatorMap (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@infixOperatorMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_infixOperatorMap::setter_insertKey (GALGAS_lstring inKey,
                                                GALGAS_unifiedTypeMap_2D_proxy inArgument0,
                                                GALGAS_infixOperatorDescription inArgument1,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cMapElement_infixOperatorMap * p = NULL ;
  macroMyNew (p, cMapElement_infixOperatorMap (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "** internal error **" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_infixOperatorMap_searchKey = "** internal error **" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_infixOperatorMap::method_searchKey (GALGAS_lstring inKey,
                                                GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                                GALGAS_infixOperatorDescription & outArgument1,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  const cMapElement_infixOperatorMap * p = (const cMapElement_infixOperatorMap *) performSearch (inKey,
                                                                                                   inCompiler,
                                                                                                   kSearchErrorMessage_infixOperatorMap_searchKey
                                                                                                   COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_infixOperatorMap) ;
    outArgument0 = p->mAttribute_mResultType ;
    outArgument1 = p->mAttribute_mOperation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_infixOperatorMap::getter_mResultTypeForKey (const GALGAS_string & inKey,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_infixOperatorMap * p = (const cMapElement_infixOperatorMap *) attributes ;
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_infixOperatorMap) ;
    result = p->mAttribute_mResultType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorDescription GALGAS_infixOperatorMap::getter_mOperationForKey (const GALGAS_string & inKey,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_infixOperatorMap * p = (const cMapElement_infixOperatorMap *) attributes ;
  GALGAS_infixOperatorDescription result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_infixOperatorMap) ;
    result = p->mAttribute_mOperation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_infixOperatorMap::setter_setMResultTypeForKey (GALGAS_unifiedTypeMap_2D_proxy inAttributeValue,
                                                           GALGAS_string inKey,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_infixOperatorMap * p = (cMapElement_infixOperatorMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_infixOperatorMap) ;
    p->mAttribute_mResultType = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_infixOperatorMap::setter_setMOperationForKey (GALGAS_infixOperatorDescription inAttributeValue,
                                                          GALGAS_string inKey,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_infixOperatorMap * p = (cMapElement_infixOperatorMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_infixOperatorMap) ;
    p->mAttribute_mOperation = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_infixOperatorMap * GALGAS_infixOperatorMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) {
  cMapElement_infixOperatorMap * result = (cMapElement_infixOperatorMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_infixOperatorMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_infixOperatorMap::cEnumerator_infixOperatorMap (const GALGAS_infixOperatorMap & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap_2D_element cEnumerator_infixOperatorMap::current (LOCATION_ARGS) const {
  const cMapElement_infixOperatorMap * p = (const cMapElement_infixOperatorMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_infixOperatorMap) ;
  return GALGAS_infixOperatorMap_2D_element (p->mAttribute_lkey, p->mAttribute_mResultType, p->mAttribute_mOperation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_infixOperatorMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cEnumerator_infixOperatorMap::current_mResultType (LOCATION_ARGS) const {
  const cMapElement_infixOperatorMap * p = (const cMapElement_infixOperatorMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_infixOperatorMap) ;
  return p->mAttribute_mResultType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorDescription cEnumerator_infixOperatorMap::current_mOperation (LOCATION_ARGS) const {
  const cMapElement_infixOperatorMap * p = (const cMapElement_infixOperatorMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_infixOperatorMap) ;
  return p->mAttribute_mOperation ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @infixOperatorMap type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_infixOperatorMap ("infixOperatorMap",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_infixOperatorMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_infixOperatorMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_infixOperatorMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_infixOperatorMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap GALGAS_infixOperatorMap::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_infixOperatorMap result ;
  const GALGAS_infixOperatorMap * p = (const GALGAS_infixOperatorMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_infixOperatorMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("infixOperatorMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperator::GALGAS_prefixOperator (void) :
mEnum (kNotBuilt) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperator GALGAS_prefixOperator::constructor_notOperator (UNUSED_LOCATION_ARGS) {
  GALGAS_prefixOperator result ;
  result.mEnum = kEnum_notOperator ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperator GALGAS_prefixOperator::constructor_minus (UNUSED_LOCATION_ARGS) {
  GALGAS_prefixOperator result ;
  result.mEnum = kEnum_minus ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperator GALGAS_prefixOperator::constructor_unsignedComplement (UNUSED_LOCATION_ARGS) {
  GALGAS_prefixOperator result ;
  result.mEnum = kEnum_unsignedComplement ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperator GALGAS_prefixOperator::constructor_minusNoOvf (UNUSED_LOCATION_ARGS) {
  GALGAS_prefixOperator result ;
  result.mEnum = kEnum_minusNoOvf ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * gEnumNameArrayFor_prefixOperator [5] = {
  "(not built)",
  "notOperator",
  "minus",
  "unsignedComplement",
  "minusNoOvf"
} ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_prefixOperator::getter_isNotOperator (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_notOperator == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_prefixOperator::getter_isMinus (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_minus == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_prefixOperator::getter_isUnsignedComplement (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_unsignedComplement == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_prefixOperator::getter_isMinusNoOvf (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_minusNoOvf == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefixOperator::description (C_String & ioString,
                                         const int32_t /* inIndentation */) const {
  ioString << "<enum @prefixOperator: " << gEnumNameArrayFor_prefixOperator [mEnum] ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_prefixOperator::objectCompare (const GALGAS_prefixOperator & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @prefixOperator type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_prefixOperator ("prefixOperator",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_prefixOperator::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefixOperator ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_prefixOperator::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_prefixOperator (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperator GALGAS_prefixOperator::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_prefixOperator result ;
  const GALGAS_prefixOperator * p = (const GALGAS_prefixOperator *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_prefixOperator *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("prefixOperator", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_prefixOperatorExpressionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_prefixOperatorExpressionAST * p = (const cPtr_prefixOperatorExpressionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_prefixOperatorExpressionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mOperatorLocation.objectCompare (p->mAttribute_mOperatorLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mOp.objectCompare (p->mAttribute_mOp) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mExpression.objectCompare (p->mAttribute_mExpression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_prefixOperatorExpressionAST::objectCompare (const GALGAS_prefixOperatorExpressionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorExpressionAST::GALGAS_prefixOperatorExpressionAST (void) :
GALGAS_expressionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorExpressionAST::GALGAS_prefixOperatorExpressionAST (const cPtr_prefixOperatorExpressionAST * inSourcePtr) :
GALGAS_expressionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_prefixOperatorExpressionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorExpressionAST GALGAS_prefixOperatorExpressionAST::constructor_new (const GALGAS_location & inAttribute_mOperatorLocation,
                                                                                        const GALGAS_prefixOperator & inAttribute_mOp,
                                                                                        const GALGAS_expressionAST & inAttribute_mExpression
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_prefixOperatorExpressionAST result ;
  if (inAttribute_mOperatorLocation.isValid () && inAttribute_mOp.isValid () && inAttribute_mExpression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_prefixOperatorExpressionAST (inAttribute_mOperatorLocation, inAttribute_mOp, inAttribute_mExpression COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_prefixOperatorExpressionAST::getter_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_prefixOperatorExpressionAST * p = (const cPtr_prefixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_prefixOperatorExpressionAST) ;
    result = p->mAttribute_mOperatorLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_prefixOperatorExpressionAST::getter_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperatorLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperator GALGAS_prefixOperatorExpressionAST::getter_mOp (UNUSED_LOCATION_ARGS) const {
  GALGAS_prefixOperator result ;
  if (NULL != mObjectPtr) {
    const cPtr_prefixOperatorExpressionAST * p = (const cPtr_prefixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_prefixOperatorExpressionAST) ;
    result = p->mAttribute_mOp ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperator cPtr_prefixOperatorExpressionAST::getter_mOp (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOp ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_prefixOperatorExpressionAST::getter_mExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_prefixOperatorExpressionAST * p = (const cPtr_prefixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_prefixOperatorExpressionAST) ;
    result = p->mAttribute_mExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_prefixOperatorExpressionAST::getter_mExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                Pointer class for @prefixOperatorExpressionAST class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_prefixOperatorExpressionAST::cPtr_prefixOperatorExpressionAST (const GALGAS_location & in_mOperatorLocation,
                                                                    const GALGAS_prefixOperator & in_mOp,
                                                                    const GALGAS_expressionAST & in_mExpression
                                                                    COMMA_LOCATION_ARGS) :
cPtr_expressionAST (THERE),
mAttribute_mOperatorLocation (in_mOperatorLocation),
mAttribute_mOp (in_mOp),
mAttribute_mExpression (in_mExpression) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_prefixOperatorExpressionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefixOperatorExpressionAST ;
}

void cPtr_prefixOperatorExpressionAST::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@prefixOperatorExpressionAST:" ;
  mAttribute_mOperatorLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mOp.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mExpression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_prefixOperatorExpressionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_prefixOperatorExpressionAST (mAttribute_mOperatorLocation, mAttribute_mOp, mAttribute_mExpression COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @prefixOperatorExpressionAST type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_prefixOperatorExpressionAST ("prefixOperatorExpressionAST",
                                                    & kTypeDescriptor_GALGAS_expressionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_prefixOperatorExpressionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefixOperatorExpressionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_prefixOperatorExpressionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_prefixOperatorExpressionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorExpressionAST GALGAS_prefixOperatorExpressionAST::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_prefixOperatorExpressionAST result ;
  const GALGAS_prefixOperatorExpressionAST * p = (const GALGAS_prefixOperatorExpressionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_prefixOperatorExpressionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("prefixOperatorExpressionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_literalBooleanInExpressionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_literalBooleanInExpressionAST * p = (const cPtr_literalBooleanInExpressionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_literalBooleanInExpressionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mValue.objectCompare (p->mAttribute_mValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_literalBooleanInExpressionAST::objectCompare (const GALGAS_literalBooleanInExpressionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalBooleanInExpressionAST::GALGAS_literalBooleanInExpressionAST (void) :
GALGAS_expressionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalBooleanInExpressionAST GALGAS_literalBooleanInExpressionAST::constructor_default (LOCATION_ARGS) {
  return GALGAS_literalBooleanInExpressionAST::constructor_new (GALGAS_bool::constructor_default (HERE)
                                                                COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalBooleanInExpressionAST::GALGAS_literalBooleanInExpressionAST (const cPtr_literalBooleanInExpressionAST * inSourcePtr) :
GALGAS_expressionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_literalBooleanInExpressionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalBooleanInExpressionAST GALGAS_literalBooleanInExpressionAST::constructor_new (const GALGAS_bool & inAttribute_mValue
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_literalBooleanInExpressionAST result ;
  if (inAttribute_mValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_literalBooleanInExpressionAST (inAttribute_mValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_literalBooleanInExpressionAST::getter_mValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_literalBooleanInExpressionAST * p = (const cPtr_literalBooleanInExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_literalBooleanInExpressionAST) ;
    result = p->mAttribute_mValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_literalBooleanInExpressionAST::getter_mValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                               Pointer class for @literalBooleanInExpressionAST class                                *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_literalBooleanInExpressionAST::cPtr_literalBooleanInExpressionAST (const GALGAS_bool & in_mValue
                                                                        COMMA_LOCATION_ARGS) :
cPtr_expressionAST (THERE),
mAttribute_mValue (in_mValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_literalBooleanInExpressionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_literalBooleanInExpressionAST ;
}

void cPtr_literalBooleanInExpressionAST::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "[@literalBooleanInExpressionAST:" ;
  mAttribute_mValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_literalBooleanInExpressionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_literalBooleanInExpressionAST (mAttribute_mValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @literalBooleanInExpressionAST type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_literalBooleanInExpressionAST ("literalBooleanInExpressionAST",
                                                      & kTypeDescriptor_GALGAS_expressionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_literalBooleanInExpressionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_literalBooleanInExpressionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_literalBooleanInExpressionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_literalBooleanInExpressionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalBooleanInExpressionAST GALGAS_literalBooleanInExpressionAST::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_literalBooleanInExpressionAST result ;
  const GALGAS_literalBooleanInExpressionAST * p = (const GALGAS_literalBooleanInExpressionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_literalBooleanInExpressionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("literalBooleanInExpressionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Class for element of '@registerIntegerFieldListAST' list                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_registerIntegerFieldListAST : public cCollectionElement {
  public : GALGAS_registerIntegerFieldListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_registerIntegerFieldListAST (const GALGAS_lstring & in_mFieldName,
                                                           const GALGAS_expressionAST & in_mExpression,
                                                           const GALGAS_location & in_mExpressionLocation
                                                           COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_registerIntegerFieldListAST::cCollectionElement_registerIntegerFieldListAST (const GALGAS_lstring & in_mFieldName,
                                                                                                const GALGAS_expressionAST & in_mExpression,
                                                                                                const GALGAS_location & in_mExpressionLocation
                                                                                                COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mFieldName, in_mExpression, in_mExpressionLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_registerIntegerFieldListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_registerIntegerFieldListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_registerIntegerFieldListAST (mObject.mAttribute_mFieldName, mObject.mAttribute_mExpression, mObject.mAttribute_mExpressionLocation COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_registerIntegerFieldListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFieldName" ":" ;
  mObject.mAttribute_mFieldName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mExpression" ":" ;
  mObject.mAttribute_mExpression.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mExpressionLocation" ":" ;
  mObject.mAttribute_mExpressionLocation.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_registerIntegerFieldListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_registerIntegerFieldListAST * operand = (cCollectionElement_registerIntegerFieldListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_registerIntegerFieldListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerFieldListAST::GALGAS_registerIntegerFieldListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerFieldListAST::GALGAS_registerIntegerFieldListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerFieldListAST GALGAS_registerIntegerFieldListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_registerIntegerFieldListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerFieldListAST GALGAS_registerIntegerFieldListAST::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                                                  const GALGAS_expressionAST & inOperand1,
                                                                                                  const GALGAS_location & inOperand2
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_registerIntegerFieldListAST result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_registerIntegerFieldListAST::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_registerIntegerFieldListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                    const GALGAS_lstring & in_mFieldName,
                                                                    const GALGAS_expressionAST & in_mExpression,
                                                                    const GALGAS_location & in_mExpressionLocation
                                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_registerIntegerFieldListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_registerIntegerFieldListAST (in_mFieldName,
                                                                 in_mExpression,
                                                                 in_mExpressionLocation COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_registerIntegerFieldListAST::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                              const GALGAS_expressionAST & inOperand1,
                                                              const GALGAS_location & inOperand2
                                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_registerIntegerFieldListAST (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_registerIntegerFieldListAST::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                               const GALGAS_expressionAST inOperand1,
                                                               const GALGAS_location inOperand2,
                                                               const GALGAS_uint inInsertionIndex,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_registerIntegerFieldListAST (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_registerIntegerFieldListAST::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                               GALGAS_expressionAST & outOperand1,
                                                               GALGAS_location & outOperand2,
                                                               const GALGAS_uint inRemoveIndex,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_registerIntegerFieldListAST * p = (cCollectionElement_registerIntegerFieldListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_registerIntegerFieldListAST) ;
      outOperand0 = p->mObject.mAttribute_mFieldName ;
      outOperand1 = p->mObject.mAttribute_mExpression ;
      outOperand2 = p->mObject.mAttribute_mExpressionLocation ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_registerIntegerFieldListAST::setter_popFirst (GALGAS_lstring & outOperand0,
                                                          GALGAS_expressionAST & outOperand1,
                                                          GALGAS_location & outOperand2,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_registerIntegerFieldListAST * p = (cCollectionElement_registerIntegerFieldListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_registerIntegerFieldListAST) ;
    outOperand0 = p->mObject.mAttribute_mFieldName ;
    outOperand1 = p->mObject.mAttribute_mExpression ;
    outOperand2 = p->mObject.mAttribute_mExpressionLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_registerIntegerFieldListAST::setter_popLast (GALGAS_lstring & outOperand0,
                                                         GALGAS_expressionAST & outOperand1,
                                                         GALGAS_location & outOperand2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_registerIntegerFieldListAST * p = (cCollectionElement_registerIntegerFieldListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_registerIntegerFieldListAST) ;
    outOperand0 = p->mObject.mAttribute_mFieldName ;
    outOperand1 = p->mObject.mAttribute_mExpression ;
    outOperand2 = p->mObject.mAttribute_mExpressionLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_registerIntegerFieldListAST::method_first (GALGAS_lstring & outOperand0,
                                                       GALGAS_expressionAST & outOperand1,
                                                       GALGAS_location & outOperand2,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_registerIntegerFieldListAST * p = (cCollectionElement_registerIntegerFieldListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_registerIntegerFieldListAST) ;
    outOperand0 = p->mObject.mAttribute_mFieldName ;
    outOperand1 = p->mObject.mAttribute_mExpression ;
    outOperand2 = p->mObject.mAttribute_mExpressionLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_registerIntegerFieldListAST::method_last (GALGAS_lstring & outOperand0,
                                                      GALGAS_expressionAST & outOperand1,
                                                      GALGAS_location & outOperand2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_registerIntegerFieldListAST * p = (cCollectionElement_registerIntegerFieldListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_registerIntegerFieldListAST) ;
    outOperand0 = p->mObject.mAttribute_mFieldName ;
    outOperand1 = p->mObject.mAttribute_mExpression ;
    outOperand2 = p->mObject.mAttribute_mExpressionLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerFieldListAST GALGAS_registerIntegerFieldListAST::add_operation (const GALGAS_registerIntegerFieldListAST & inOperand,
                                                                                      C_Compiler * /* inCompiler */
                                                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_registerIntegerFieldListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerFieldListAST GALGAS_registerIntegerFieldListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_registerIntegerFieldListAST result = GALGAS_registerIntegerFieldListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerFieldListAST GALGAS_registerIntegerFieldListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_registerIntegerFieldListAST result = GALGAS_registerIntegerFieldListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerFieldListAST GALGAS_registerIntegerFieldListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_registerIntegerFieldListAST result = GALGAS_registerIntegerFieldListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_registerIntegerFieldListAST::plusAssign_operation (const GALGAS_registerIntegerFieldListAST inOperand,
                                                               C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_registerIntegerFieldListAST::getter_mFieldNameAtIndex (const GALGAS_uint & inIndex,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_registerIntegerFieldListAST * p = (cCollectionElement_registerIntegerFieldListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_registerIntegerFieldListAST) ;
    result = p->mObject.mAttribute_mFieldName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_registerIntegerFieldListAST::getter_mExpressionAtIndex (const GALGAS_uint & inIndex,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_registerIntegerFieldListAST * p = (cCollectionElement_registerIntegerFieldListAST *) attributes.ptr () ;
  GALGAS_expressionAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_registerIntegerFieldListAST) ;
    result = p->mObject.mAttribute_mExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_registerIntegerFieldListAST::getter_mExpressionLocationAtIndex (const GALGAS_uint & inIndex,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_registerIntegerFieldListAST * p = (cCollectionElement_registerIntegerFieldListAST *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_registerIntegerFieldListAST) ;
    result = p->mObject.mAttribute_mExpressionLocation ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_registerIntegerFieldListAST::cEnumerator_registerIntegerFieldListAST (const GALGAS_registerIntegerFieldListAST & inEnumeratedObject,
                                                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerFieldListAST_2D_element cEnumerator_registerIntegerFieldListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_registerIntegerFieldListAST * p = (const cCollectionElement_registerIntegerFieldListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_registerIntegerFieldListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_registerIntegerFieldListAST::current_mFieldName (LOCATION_ARGS) const {
  const cCollectionElement_registerIntegerFieldListAST * p = (const cCollectionElement_registerIntegerFieldListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_registerIntegerFieldListAST) ;
  return p->mObject.mAttribute_mFieldName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cEnumerator_registerIntegerFieldListAST::current_mExpression (LOCATION_ARGS) const {
  const cCollectionElement_registerIntegerFieldListAST * p = (const cCollectionElement_registerIntegerFieldListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_registerIntegerFieldListAST) ;
  return p->mObject.mAttribute_mExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_registerIntegerFieldListAST::current_mExpressionLocation (LOCATION_ARGS) const {
  const cCollectionElement_registerIntegerFieldListAST * p = (const cCollectionElement_registerIntegerFieldListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_registerIntegerFieldListAST) ;
  return p->mObject.mAttribute_mExpressionLocation ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @registerIntegerFieldListAST type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_registerIntegerFieldListAST ("registerIntegerFieldListAST",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_registerIntegerFieldListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_registerIntegerFieldListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_registerIntegerFieldListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_registerIntegerFieldListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerFieldListAST GALGAS_registerIntegerFieldListAST::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_registerIntegerFieldListAST result ;
  const GALGAS_registerIntegerFieldListAST * p = (const GALGAS_registerIntegerFieldListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_registerIntegerFieldListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("registerIntegerFieldListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Class for element of '@effectiveParameterListAST' list                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_effectiveParameterListAST : public cCollectionElement {
  public : GALGAS_effectiveParameterListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_effectiveParameterListAST (const GALGAS_effectiveParameterPassingModeAST & in_mEffectiveParameterKind,
                                                         const GALGAS_lstring & in_mSelector
                                                         COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_effectiveParameterListAST::cCollectionElement_effectiveParameterListAST (const GALGAS_effectiveParameterPassingModeAST & in_mEffectiveParameterKind,
                                                                                            const GALGAS_lstring & in_mSelector
                                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mEffectiveParameterKind, in_mSelector) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_effectiveParameterListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_effectiveParameterListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_effectiveParameterListAST (mObject.mAttribute_mEffectiveParameterKind, mObject.mAttribute_mSelector COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_effectiveParameterListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEffectiveParameterKind" ":" ;
  mObject.mAttribute_mEffectiveParameterKind.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSelector" ":" ;
  mObject.mAttribute_mSelector.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_effectiveParameterListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_effectiveParameterListAST * operand = (cCollectionElement_effectiveParameterListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_effectiveParameterListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST::GALGAS_effectiveParameterListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST::GALGAS_effectiveParameterListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST GALGAS_effectiveParameterListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_effectiveParameterListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST GALGAS_effectiveParameterListAST::constructor_listWithValue (const GALGAS_effectiveParameterPassingModeAST & inOperand0,
                                                                                              const GALGAS_lstring & inOperand1
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_effectiveParameterListAST result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_effectiveParameterListAST::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_effectiveParameterListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                  const GALGAS_effectiveParameterPassingModeAST & in_mEffectiveParameterKind,
                                                                  const GALGAS_lstring & in_mSelector
                                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_effectiveParameterListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_effectiveParameterListAST (in_mEffectiveParameterKind,
                                                               in_mSelector COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_effectiveParameterListAST::addAssign_operation (const GALGAS_effectiveParameterPassingModeAST & inOperand0,
                                                            const GALGAS_lstring & inOperand1
                                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_effectiveParameterListAST (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_effectiveParameterListAST::setter_insertAtIndex (const GALGAS_effectiveParameterPassingModeAST inOperand0,
                                                             const GALGAS_lstring inOperand1,
                                                             const GALGAS_uint inInsertionIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_effectiveParameterListAST (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_effectiveParameterListAST::setter_removeAtIndex (GALGAS_effectiveParameterPassingModeAST & outOperand0,
                                                             GALGAS_lstring & outOperand1,
                                                             const GALGAS_uint inRemoveIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_effectiveParameterListAST * p = (cCollectionElement_effectiveParameterListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_effectiveParameterListAST) ;
      outOperand0 = p->mObject.mAttribute_mEffectiveParameterKind ;
      outOperand1 = p->mObject.mAttribute_mSelector ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_effectiveParameterListAST::setter_popFirst (GALGAS_effectiveParameterPassingModeAST & outOperand0,
                                                        GALGAS_lstring & outOperand1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_effectiveParameterListAST * p = (cCollectionElement_effectiveParameterListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_effectiveParameterListAST) ;
    outOperand0 = p->mObject.mAttribute_mEffectiveParameterKind ;
    outOperand1 = p->mObject.mAttribute_mSelector ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_effectiveParameterListAST::setter_popLast (GALGAS_effectiveParameterPassingModeAST & outOperand0,
                                                       GALGAS_lstring & outOperand1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_effectiveParameterListAST * p = (cCollectionElement_effectiveParameterListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_effectiveParameterListAST) ;
    outOperand0 = p->mObject.mAttribute_mEffectiveParameterKind ;
    outOperand1 = p->mObject.mAttribute_mSelector ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_effectiveParameterListAST::method_first (GALGAS_effectiveParameterPassingModeAST & outOperand0,
                                                     GALGAS_lstring & outOperand1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_effectiveParameterListAST * p = (cCollectionElement_effectiveParameterListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_effectiveParameterListAST) ;
    outOperand0 = p->mObject.mAttribute_mEffectiveParameterKind ;
    outOperand1 = p->mObject.mAttribute_mSelector ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_effectiveParameterListAST::method_last (GALGAS_effectiveParameterPassingModeAST & outOperand0,
                                                    GALGAS_lstring & outOperand1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_effectiveParameterListAST * p = (cCollectionElement_effectiveParameterListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_effectiveParameterListAST) ;
    outOperand0 = p->mObject.mAttribute_mEffectiveParameterKind ;
    outOperand1 = p->mObject.mAttribute_mSelector ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST GALGAS_effectiveParameterListAST::add_operation (const GALGAS_effectiveParameterListAST & inOperand,
                                                                                  C_Compiler * /* inCompiler */
                                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_effectiveParameterListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST GALGAS_effectiveParameterListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_effectiveParameterListAST result = GALGAS_effectiveParameterListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST GALGAS_effectiveParameterListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_effectiveParameterListAST result = GALGAS_effectiveParameterListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST GALGAS_effectiveParameterListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_effectiveParameterListAST result = GALGAS_effectiveParameterListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_effectiveParameterListAST::plusAssign_operation (const GALGAS_effectiveParameterListAST inOperand,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterPassingModeAST GALGAS_effectiveParameterListAST::getter_mEffectiveParameterKindAtIndex (const GALGAS_uint & inIndex,
                                                                                                                 C_Compiler * inCompiler
                                                                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_effectiveParameterListAST * p = (cCollectionElement_effectiveParameterListAST *) attributes.ptr () ;
  GALGAS_effectiveParameterPassingModeAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_effectiveParameterListAST) ;
    result = p->mObject.mAttribute_mEffectiveParameterKind ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_effectiveParameterListAST::getter_mSelectorAtIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_effectiveParameterListAST * p = (cCollectionElement_effectiveParameterListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_effectiveParameterListAST) ;
    result = p->mObject.mAttribute_mSelector ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_effectiveParameterListAST::cEnumerator_effectiveParameterListAST (const GALGAS_effectiveParameterListAST & inEnumeratedObject,
                                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST_2D_element cEnumerator_effectiveParameterListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_effectiveParameterListAST * p = (const cCollectionElement_effectiveParameterListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_effectiveParameterListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterPassingModeAST cEnumerator_effectiveParameterListAST::current_mEffectiveParameterKind (LOCATION_ARGS) const {
  const cCollectionElement_effectiveParameterListAST * p = (const cCollectionElement_effectiveParameterListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_effectiveParameterListAST) ;
  return p->mObject.mAttribute_mEffectiveParameterKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_effectiveParameterListAST::current_mSelector (LOCATION_ARGS) const {
  const cCollectionElement_effectiveParameterListAST * p = (const cCollectionElement_effectiveParameterListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_effectiveParameterListAST) ;
  return p->mObject.mAttribute_mSelector ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @effectiveParameterListAST type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_effectiveParameterListAST ("effectiveParameterListAST",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_effectiveParameterListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_effectiveParameterListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_effectiveParameterListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_effectiveParameterListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST GALGAS_effectiveParameterListAST::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_effectiveParameterListAST result ;
  const GALGAS_effectiveParameterListAST * p = (const GALGAS_effectiveParameterListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_effectiveParameterListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("effectiveParameterListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_primaryInExpressionSelfAccessAST_selfAccess::cEnumAssociatedValues_primaryInExpressionSelfAccessAST_selfAccess (const GALGAS_location & inAssociatedValue0
                                                                                                                                      COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_primaryInExpressionSelfAccessAST_selfAccess::description (C_String & ioString,
                                                                                     const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_primaryInExpressionSelfAccessAST_selfAccess::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_primaryInExpressionSelfAccessAST_selfAccess * ptr = dynamic_cast<const cEnumAssociatedValues_primaryInExpressionSelfAccessAST_selfAccess *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionSelfAccessAST::GALGAS_primaryInExpressionSelfAccessAST (void) :
mAssociatedValues (),
mEnum (kNotBuilt) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionSelfAccessAST GALGAS_primaryInExpressionSelfAccessAST::constructor_noSelfAccess (UNUSED_LOCATION_ARGS) {
  GALGAS_primaryInExpressionSelfAccessAST result ;
  result.mEnum = kEnum_noSelfAccess ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionSelfAccessAST GALGAS_primaryInExpressionSelfAccessAST::constructor_selfAccess (const GALGAS_location & inAssociatedValue0
                                                                                                         COMMA_LOCATION_ARGS) {
  GALGAS_primaryInExpressionSelfAccessAST result ;
  if (inAssociatedValue0.isValid ()) {
    result.mEnum = kEnum_selfAccess ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_primaryInExpressionSelfAccessAST_selfAccess (inAssociatedValue0 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionSelfAccessAST::method_selfAccess (GALGAS_location & outAssociatedValue0,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_selfAccess) {
    outAssociatedValue0.drop () ;
    C_String s ;
    s << "method @primaryInExpressionSelfAccessAST selfAccess invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_primaryInExpressionSelfAccessAST_selfAccess * ptr = (const cEnumAssociatedValues_primaryInExpressionSelfAccessAST_selfAccess *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * gEnumNameArrayFor_primaryInExpressionSelfAccessAST [3] = {
  "(not built)",
  "noSelfAccess",
  "selfAccess"
} ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_primaryInExpressionSelfAccessAST::getter_isNoSelfAccess (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_noSelfAccess == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_primaryInExpressionSelfAccessAST::getter_isSelfAccess (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_selfAccess == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionSelfAccessAST::description (C_String & ioString,
                                                           const int32_t inIndentation) const {
  ioString << "<enum @primaryInExpressionSelfAccessAST: " << gEnumNameArrayFor_primaryInExpressionSelfAccessAST [mEnum] ;
  mAssociatedValues.description (ioString, inIndentation) ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_primaryInExpressionSelfAccessAST::objectCompare (const GALGAS_primaryInExpressionSelfAccessAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mAssociatedValues.objectCompare (inOperand.mAssociatedValues) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @primaryInExpressionSelfAccessAST type                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_primaryInExpressionSelfAccessAST ("primaryInExpressionSelfAccessAST",
                                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_primaryInExpressionSelfAccessAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_primaryInExpressionSelfAccessAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_primaryInExpressionSelfAccessAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_primaryInExpressionSelfAccessAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionSelfAccessAST GALGAS_primaryInExpressionSelfAccessAST::extractObject (const GALGAS_object & inObject,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_primaryInExpressionSelfAccessAST result ;
  const GALGAS_primaryInExpressionSelfAccessAST * p = (const GALGAS_primaryInExpressionSelfAccessAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_primaryInExpressionSelfAccessAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("primaryInExpressionSelfAccessAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Class for element of '@primaryInExpressionAccessListAST' list                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_primaryInExpressionAccessListAST : public cCollectionElement {
  public : GALGAS_primaryInExpressionAccessListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_primaryInExpressionAccessListAST (const GALGAS_primaryInExpressionAccessAST & in_mAccess
                                                                COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_primaryInExpressionAccessListAST::cCollectionElement_primaryInExpressionAccessListAST (const GALGAS_primaryInExpressionAccessAST & in_mAccess
                                                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mAccess) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_primaryInExpressionAccessListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_primaryInExpressionAccessListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_primaryInExpressionAccessListAST (mObject.mAttribute_mAccess COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_primaryInExpressionAccessListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAccess" ":" ;
  mObject.mAttribute_mAccess.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_primaryInExpressionAccessListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_primaryInExpressionAccessListAST * operand = (cCollectionElement_primaryInExpressionAccessListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_primaryInExpressionAccessListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST::GALGAS_primaryInExpressionAccessListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST::GALGAS_primaryInExpressionAccessListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST GALGAS_primaryInExpressionAccessListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_primaryInExpressionAccessListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST GALGAS_primaryInExpressionAccessListAST::constructor_listWithValue (const GALGAS_primaryInExpressionAccessAST & inOperand0
                                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_primaryInExpressionAccessListAST result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_primaryInExpressionAccessListAST::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionAccessListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                         const GALGAS_primaryInExpressionAccessAST & in_mAccess
                                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_primaryInExpressionAccessListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_primaryInExpressionAccessListAST (in_mAccess COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionAccessListAST::addAssign_operation (const GALGAS_primaryInExpressionAccessAST & inOperand0
                                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_primaryInExpressionAccessListAST (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionAccessListAST::setter_insertAtIndex (const GALGAS_primaryInExpressionAccessAST inOperand0,
                                                                    const GALGAS_uint inInsertionIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_primaryInExpressionAccessListAST (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionAccessListAST::setter_removeAtIndex (GALGAS_primaryInExpressionAccessAST & outOperand0,
                                                                    const GALGAS_uint inRemoveIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_primaryInExpressionAccessListAST * p = (cCollectionElement_primaryInExpressionAccessListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_primaryInExpressionAccessListAST) ;
      outOperand0 = p->mObject.mAttribute_mAccess ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionAccessListAST::setter_popFirst (GALGAS_primaryInExpressionAccessAST & outOperand0,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_primaryInExpressionAccessListAST * p = (cCollectionElement_primaryInExpressionAccessListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_primaryInExpressionAccessListAST) ;
    outOperand0 = p->mObject.mAttribute_mAccess ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionAccessListAST::setter_popLast (GALGAS_primaryInExpressionAccessAST & outOperand0,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_primaryInExpressionAccessListAST * p = (cCollectionElement_primaryInExpressionAccessListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_primaryInExpressionAccessListAST) ;
    outOperand0 = p->mObject.mAttribute_mAccess ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionAccessListAST::method_first (GALGAS_primaryInExpressionAccessAST & outOperand0,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_primaryInExpressionAccessListAST * p = (cCollectionElement_primaryInExpressionAccessListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_primaryInExpressionAccessListAST) ;
    outOperand0 = p->mObject.mAttribute_mAccess ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionAccessListAST::method_last (GALGAS_primaryInExpressionAccessAST & outOperand0,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_primaryInExpressionAccessListAST * p = (cCollectionElement_primaryInExpressionAccessListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_primaryInExpressionAccessListAST) ;
    outOperand0 = p->mObject.mAttribute_mAccess ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST GALGAS_primaryInExpressionAccessListAST::add_operation (const GALGAS_primaryInExpressionAccessListAST & inOperand,
                                                                                                C_Compiler * /* inCompiler */
                                                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_primaryInExpressionAccessListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST GALGAS_primaryInExpressionAccessListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_primaryInExpressionAccessListAST result = GALGAS_primaryInExpressionAccessListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST GALGAS_primaryInExpressionAccessListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_primaryInExpressionAccessListAST result = GALGAS_primaryInExpressionAccessListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST GALGAS_primaryInExpressionAccessListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                                        C_Compiler * inCompiler
                                                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_primaryInExpressionAccessListAST result = GALGAS_primaryInExpressionAccessListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionAccessListAST::plusAssign_operation (const GALGAS_primaryInExpressionAccessListAST inOperand,
                                                                    C_Compiler * /* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessAST GALGAS_primaryInExpressionAccessListAST::getter_mAccessAtIndex (const GALGAS_uint & inIndex,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_primaryInExpressionAccessListAST * p = (cCollectionElement_primaryInExpressionAccessListAST *) attributes.ptr () ;
  GALGAS_primaryInExpressionAccessAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_primaryInExpressionAccessListAST) ;
    result = p->mObject.mAttribute_mAccess ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_primaryInExpressionAccessListAST::cEnumerator_primaryInExpressionAccessListAST (const GALGAS_primaryInExpressionAccessListAST & inEnumeratedObject,
                                                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST_2D_element cEnumerator_primaryInExpressionAccessListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_primaryInExpressionAccessListAST * p = (const cCollectionElement_primaryInExpressionAccessListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_primaryInExpressionAccessListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessAST cEnumerator_primaryInExpressionAccessListAST::current_mAccess (LOCATION_ARGS) const {
  const cCollectionElement_primaryInExpressionAccessListAST * p = (const cCollectionElement_primaryInExpressionAccessListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_primaryInExpressionAccessListAST) ;
  return p->mObject.mAttribute_mAccess ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @primaryInExpressionAccessListAST type                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_primaryInExpressionAccessListAST ("primaryInExpressionAccessListAST",
                                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_primaryInExpressionAccessListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_primaryInExpressionAccessListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_primaryInExpressionAccessListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_primaryInExpressionAccessListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST GALGAS_primaryInExpressionAccessListAST::extractObject (const GALGAS_object & inObject,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_primaryInExpressionAccessListAST result ;
  const GALGAS_primaryInExpressionAccessListAST * p = (const GALGAS_primaryInExpressionAccessListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_primaryInExpressionAccessListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("primaryInExpressionAccessListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_instructionAST::objectCompare (const GALGAS_instructionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionAST::GALGAS_instructionAST (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionAST::GALGAS_instructionAST (const cPtr_instructionAST * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_instructionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @instructionAST class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_instructionAST::cPtr_instructionAST (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @instructionAST type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_instructionAST ("instructionAST",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_instructionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_instructionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_instructionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_instructionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionAST GALGAS_instructionAST::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_instructionAST result ;
  const GALGAS_instructionAST * p = (const GALGAS_instructionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_instructionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("instructionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                  Abstract extension method '@instructionAST noteInstructionTypesInPrecedenceGraph'                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_instructionAST_noteInstructionTypesInPrecedenceGraph> gExtensionMethodTable_instructionAST_noteInstructionTypesInPrecedenceGraph ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (const int32_t inClassIndex,
                                                                 extensionMethodSignature_instructionAST_noteInstructionTypesInPrecedenceGraph inMethod) {
  gExtensionMethodTable_instructionAST_noteInstructionTypesInPrecedenceGraph.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_instructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  gExtensionMethodTable_instructionAST_noteInstructionTypesInPrecedenceGraph.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_instructionAST_noteInstructionTypesInPrecedenceGraph (NULL,
                                                                                 freeExtensionMethod_instructionAST_noteInstructionTypesInPrecedenceGraph) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                GALGAS_semanticTypePrecedenceGraph & io_ioGraph,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_instructionAST) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_instructionAST_noteInstructionTypesInPrecedenceGraph f = NULL ;
    if (classIndex < gExtensionMethodTable_instructionAST_noteInstructionTypesInPrecedenceGraph.count ()) {
      f = gExtensionMethodTable_instructionAST_noteInstructionTypesInPrecedenceGraph (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_instructionAST_noteInstructionTypesInPrecedenceGraph.count ()) {
          f = gExtensionMethodTable_instructionAST_noteInstructionTypesInPrecedenceGraph (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_instructionAST_noteInstructionTypesInPrecedenceGraph.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_ioGraph, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                  Extension method '@instructionListAST noteInstructionListTypesInPrecedenceGraph'                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_noteInstructionListTypesInPrecedenceGraph (const GALGAS_instructionListAST inObject,
                                                                GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_instructionListAST temp_0 = inObject ;
  cEnumerator_instructionListAST enumerator_2171 (temp_0, kEnumeration_up) ;
  while (enumerator_2171.hasCurrentObject ()) {
    callExtensionMethod_noteInstructionTypesInPrecedenceGraph ((const cPtr_instructionAST *) enumerator_2171.current_mInstruction (HERE).ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instructionList.galgas", 49)) ;
    enumerator_2171.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Abstract extension method '@instructionAST analyze'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_instructionAST_analyze> gExtensionMethodTable_instructionAST_analyze ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_analyze (const int32_t inClassIndex,
                                   extensionMethodSignature_instructionAST_analyze inMethod) {
  gExtensionMethodTable_instructionAST_analyze.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_instructionAST_analyze (void) {
  gExtensionMethodTable_instructionAST_analyze.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_instructionAST_analyze (NULL,
                                                   freeExtensionMethod_instructionAST_analyze) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_analyze (const cPtr_instructionAST * inObject,
                                  const GALGAS_unifiedTypeMap_2D_proxy constin_inSelfType,
                                  const GALGAS_bool constin_inRoutineCanMutateProperties,
                                  const GALGAS_bool constin_inDirectAccessToPropertiesAllowed,
                                  const GALGAS_lstring constin_inCallerNameForInvocationGraph,
                                  const GALGAS_semanticContext constin_inContext,
                                  const GALGAS_mode constin_inCurrentMode,
                                  GALGAS_semanticTemporariesStruct & io_ioTemporaries,
                                  GALGAS_staticStringMap & io_ioGlobalLiteralStringMap,
                                  GALGAS_variableMap & io_ioVariableMap,
                                  GALGAS_allocaList & io_ioAllocaList,
                                  GALGAS_instructionListIR & io_ioInstructionGenerationList,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_instructionAST) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_instructionAST_analyze f = NULL ;
    if (classIndex < gExtensionMethodTable_instructionAST_analyze.count ()) {
      f = gExtensionMethodTable_instructionAST_analyze (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_instructionAST_analyze.count ()) {
          f = gExtensionMethodTable_instructionAST_analyze (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_instructionAST_analyze.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_inSelfType, constin_inRoutineCanMutateProperties, constin_inDirectAccessToPropertiesAllowed, constin_inCallerNameForInvocationGraph, constin_inContext, constin_inCurrentMode, io_ioTemporaries, io_ioGlobalLiteralStringMap, io_ioVariableMap, io_ioAllocaList, io_ioInstructionGenerationList, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Extension method '@instructionListAST analyzeBranchInstructionList'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_analyzeBranchInstructionList (const GALGAS_instructionListAST inObject,
                                                   const GALGAS_unifiedTypeMap_2D_proxy constinArgument_inSelfType,
                                                   const GALGAS_bool constinArgument_inRoutineCanMutateProperties,
                                                   const GALGAS_bool constinArgument_inDirectAccessToPropertiesAllowed,
                                                   const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                   GALGAS_location inArgument_inEndOfInstructionList,
                                                   const GALGAS_semanticContext constinArgument_inContext,
                                                   const GALGAS_mode constinArgument_inCurrentMode,
                                                   GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                   GALGAS_staticStringMap & ioArgument_ioGlobalLiteralStringMap,
                                                   GALGAS_variableMap & ioArgument_ioVariableMap,
                                                   GALGAS_allocaList & ioArgument_ioAllocaList,
                                                   GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioVariableMap.setter_openBranch (inCompiler COMMA_SOURCE_FILE ("instructionList.galgas", 87)) ;
  }
  const GALGAS_instructionListAST temp_0 = inObject ;
  cEnumerator_instructionListAST enumerator_4164 (temp_0, kEnumeration_up) ;
  while (enumerator_4164.hasCurrentObject ()) {
    {
    extensionSetter_appendSourceLineComment (ioArgument_ioInstructionGenerationList, enumerator_4164.current_mInstructionLocation (HERE), inCompiler COMMA_SOURCE_FILE ("instructionList.galgas", 89)) ;
    }
    callExtensionMethod_analyze ((const cPtr_instructionAST *) enumerator_4164.current_mInstruction (HERE).ptr (), constinArgument_inSelfType, constinArgument_inRoutineCanMutateProperties, constinArgument_inDirectAccessToPropertiesAllowed, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioGlobalLiteralStringMap, ioArgument_ioVariableMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, inCompiler COMMA_SOURCE_FILE ("instructionList.galgas", 90)) ;
    enumerator_4164.gotoNextObject () ;
  }
  {
  ioArgument_ioVariableMap.setter_closeBranch (inArgument_inEndOfInstructionList, inCompiler COMMA_SOURCE_FILE ("instructionList.galgas", 106)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension method '@instructionListAST analyzeRoutineInstructionList'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_analyzeRoutineInstructionList (const GALGAS_instructionListAST inObject,
                                                    const GALGAS_unifiedTypeMap_2D_proxy constinArgument_inSelfType,
                                                    const GALGAS_bool constinArgument_inDirectAccessToPropertiesAllowed,
                                                    const GALGAS_bool constinArgument_inRoutineCanMutateProperties,
                                                    const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                    const GALGAS_semanticContext constinArgument_inContext,
                                                    const GALGAS_mode constinArgument_inCurrentMode,
                                                    GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                    GALGAS_staticStringMap & ioArgument_ioGlobalLiteralStringMap,
                                                    GALGAS_variableMap & ioArgument_ioVariableMap,
                                                    GALGAS_allocaList & ioArgument_ioAllocaList,
                                                    GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_instructionListAST temp_0 = inObject ;
  cEnumerator_instructionListAST enumerator_5672 (temp_0, kEnumeration_up) ;
  while (enumerator_5672.hasCurrentObject ()) {
    {
    extensionSetter_appendSourceLineComment (ioArgument_ioInstructionGenerationList, enumerator_5672.current_mInstructionLocation (HERE), inCompiler COMMA_SOURCE_FILE ("instructionList.galgas", 125)) ;
    }
    callExtensionMethod_analyze ((const cPtr_instructionAST *) enumerator_5672.current_mInstruction (HERE).ptr (), constinArgument_inSelfType, constinArgument_inRoutineCanMutateProperties, constinArgument_inDirectAccessToPropertiesAllowed, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioGlobalLiteralStringMap, ioArgument_ioVariableMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, inCompiler COMMA_SOURCE_FILE ("instructionList.galgas", 126)) ;
    enumerator_5672.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension method '@instructionListIR instructionListLLVMCode'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_instructionListLLVMCode (const GALGAS_instructionListIR inObject,
                                              GALGAS_string & ioArgument_ioLLVMcode,
                                              const GALGAS_generationContext constinArgument_inGenerationContext,
                                              GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_instructionListIR temp_0 = inObject ;
  cEnumerator_instructionListIR enumerator_6807 (temp_0, kEnumeration_up) ;
  while (enumerator_6807.hasCurrentObject ()) {
    callExtensionMethod_llvmInstructionCode ((const cPtr_abstractInstructionIR *) enumerator_6807.current_mInstructionGeneration (HERE).ptr (), ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instructionList.galgas", 152)) ;
    enumerator_6807.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_checkInstructionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_checkInstructionAST * p = (const cPtr_checkInstructionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_checkInstructionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mCheckInstructionLocation.objectCompare (p->mAttribute_mCheckInstructionLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mExpression.objectCompare (p->mAttribute_mExpression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_checkInstructionAST::objectCompare (const GALGAS_checkInstructionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_checkInstructionAST::GALGAS_checkInstructionAST (void) :
GALGAS_instructionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_checkInstructionAST::GALGAS_checkInstructionAST (const cPtr_checkInstructionAST * inSourcePtr) :
GALGAS_instructionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_checkInstructionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_checkInstructionAST GALGAS_checkInstructionAST::constructor_new (const GALGAS_location & inAttribute_mCheckInstructionLocation,
                                                                        const GALGAS_expressionAST & inAttribute_mExpression
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_checkInstructionAST result ;
  if (inAttribute_mCheckInstructionLocation.isValid () && inAttribute_mExpression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_checkInstructionAST (inAttribute_mCheckInstructionLocation, inAttribute_mExpression COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_checkInstructionAST::getter_mCheckInstructionLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_checkInstructionAST * p = (const cPtr_checkInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_checkInstructionAST) ;
    result = p->mAttribute_mCheckInstructionLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_checkInstructionAST::getter_mCheckInstructionLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mCheckInstructionLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_checkInstructionAST::getter_mExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_checkInstructionAST * p = (const cPtr_checkInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_checkInstructionAST) ;
    result = p->mAttribute_mExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_checkInstructionAST::getter_mExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @checkInstructionAST class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_checkInstructionAST::cPtr_checkInstructionAST (const GALGAS_location & in_mCheckInstructionLocation,
                                                    const GALGAS_expressionAST & in_mExpression
                                                    COMMA_LOCATION_ARGS) :
cPtr_instructionAST (THERE),
mAttribute_mCheckInstructionLocation (in_mCheckInstructionLocation),
mAttribute_mExpression (in_mExpression) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_checkInstructionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_checkInstructionAST ;
}

void cPtr_checkInstructionAST::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@checkInstructionAST:" ;
  mAttribute_mCheckInstructionLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mExpression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_checkInstructionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_checkInstructionAST (mAttribute_mCheckInstructionLocation, mAttribute_mExpression COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @checkInstructionAST type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_checkInstructionAST ("checkInstructionAST",
                                            & kTypeDescriptor_GALGAS_instructionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_checkInstructionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_checkInstructionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_checkInstructionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_checkInstructionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_checkInstructionAST GALGAS_checkInstructionAST::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_checkInstructionAST result ;
  const GALGAS_checkInstructionAST * p = (const GALGAS_checkInstructionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_checkInstructionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("checkInstructionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind::GALGAS_operatorAssignmentKind (void) :
mEnum (kNotBuilt) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_bitWiseOrAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_bitWiseOrAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_bitWiseAndAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_bitWiseAndAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_bitWiseXorAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_bitWiseXorAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_addAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_addAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_addModuloAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_addModuloAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_subAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_subAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_subModuloAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_subModuloAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_mulAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_mulAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_mulModuloAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_mulModuloAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_divAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_divAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_divZeroAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_divZeroAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_modAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_modAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::constructor_modZeroAssign (UNUSED_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  result.mEnum = kEnum_modZeroAssign ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * gEnumNameArrayFor_operatorAssignmentKind [14] = {
  "(not built)",
  "bitWiseOrAssign",
  "bitWiseAndAssign",
  "bitWiseXorAssign",
  "addAssign",
  "addModuloAssign",
  "subAssign",
  "subModuloAssign",
  "mulAssign",
  "mulModuloAssign",
  "divAssign",
  "divZeroAssign",
  "modAssign",
  "modZeroAssign"
} ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isBitWiseOrAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_bitWiseOrAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isBitWiseAndAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_bitWiseAndAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isBitWiseXorAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_bitWiseXorAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isAddAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_addAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isAddModuloAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_addModuloAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isSubAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_subAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isSubModuloAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_subModuloAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isMulAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_mulAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isMulModuloAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_mulModuloAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isDivAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_divAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isDivZeroAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_divZeroAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isModAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_modAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_operatorAssignmentKind::getter_isModZeroAssign (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_modZeroAssign == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_operatorAssignmentKind::description (C_String & ioString,
                                                 const int32_t /* inIndentation */) const {
  ioString << "<enum @operatorAssignmentKind: " << gEnumNameArrayFor_operatorAssignmentKind [mEnum] ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_operatorAssignmentKind::objectCompare (const GALGAS_operatorAssignmentKind & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @operatorAssignmentKind type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_operatorAssignmentKind ("operatorAssignmentKind",
                                               NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_operatorAssignmentKind::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_operatorAssignmentKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_operatorAssignmentKind::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_operatorAssignmentKind (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operatorAssignmentKind GALGAS_operatorAssignmentKind::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_operatorAssignmentKind result ;
  const GALGAS_operatorAssignmentKind * p = (const GALGAS_operatorAssignmentKind *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_operatorAssignmentKind *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("operatorAssignmentKind", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_assertInstructionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_assertInstructionAST * p = (const cPtr_assertInstructionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_assertInstructionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mAssertInstructionLocation.objectCompare (p->mAttribute_mAssertInstructionLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mExpression.objectCompare (p->mAttribute_mExpression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_assertInstructionAST::objectCompare (const GALGAS_assertInstructionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_assertInstructionAST::GALGAS_assertInstructionAST (void) :
GALGAS_instructionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_assertInstructionAST::GALGAS_assertInstructionAST (const cPtr_assertInstructionAST * inSourcePtr) :
GALGAS_instructionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_assertInstructionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_assertInstructionAST GALGAS_assertInstructionAST::constructor_new (const GALGAS_location & inAttribute_mAssertInstructionLocation,
                                                                          const GALGAS_expressionAST & inAttribute_mExpression
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_assertInstructionAST result ;
  if (inAttribute_mAssertInstructionLocation.isValid () && inAttribute_mExpression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_assertInstructionAST (inAttribute_mAssertInstructionLocation, inAttribute_mExpression COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_assertInstructionAST::getter_mAssertInstructionLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_assertInstructionAST * p = (const cPtr_assertInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_assertInstructionAST) ;
    result = p->mAttribute_mAssertInstructionLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_assertInstructionAST::getter_mAssertInstructionLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAssertInstructionLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_assertInstructionAST::getter_mExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_assertInstructionAST * p = (const cPtr_assertInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_assertInstructionAST) ;
    result = p->mAttribute_mExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_assertInstructionAST::getter_mExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @assertInstructionAST class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_assertInstructionAST::cPtr_assertInstructionAST (const GALGAS_location & in_mAssertInstructionLocation,
                                                      const GALGAS_expressionAST & in_mExpression
                                                      COMMA_LOCATION_ARGS) :
cPtr_instructionAST (THERE),
mAttribute_mAssertInstructionLocation (in_mAssertInstructionLocation),
mAttribute_mExpression (in_mExpression) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_assertInstructionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_assertInstructionAST ;
}

void cPtr_assertInstructionAST::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@assertInstructionAST:" ;
  mAttribute_mAssertInstructionLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mExpression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_assertInstructionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_assertInstructionAST (mAttribute_mAssertInstructionLocation, mAttribute_mExpression COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @assertInstructionAST type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_assertInstructionAST ("assertInstructionAST",
                                             & kTypeDescriptor_GALGAS_instructionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_assertInstructionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_assertInstructionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_assertInstructionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_assertInstructionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_assertInstructionAST GALGAS_assertInstructionAST::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_assertInstructionAST result ;
  const GALGAS_assertInstructionAST * p = (const GALGAS_assertInstructionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_assertInstructionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("assertInstructionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_panicInstructionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_panicInstructionAST * p = (const cPtr_panicInstructionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_panicInstructionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mThrowLocation.objectCompare (p->mAttribute_mThrowLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mCodeExpression.objectCompare (p->mAttribute_mCodeExpression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_panicInstructionAST::objectCompare (const GALGAS_panicInstructionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicInstructionAST::GALGAS_panicInstructionAST (void) :
GALGAS_instructionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicInstructionAST::GALGAS_panicInstructionAST (const cPtr_panicInstructionAST * inSourcePtr) :
GALGAS_instructionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_panicInstructionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicInstructionAST GALGAS_panicInstructionAST::constructor_new (const GALGAS_location & inAttribute_mThrowLocation,
                                                                        const GALGAS_expressionAST & inAttribute_mCodeExpression
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_panicInstructionAST result ;
  if (inAttribute_mThrowLocation.isValid () && inAttribute_mCodeExpression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_panicInstructionAST (inAttribute_mThrowLocation, inAttribute_mCodeExpression COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_panicInstructionAST::getter_mThrowLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_panicInstructionAST * p = (const cPtr_panicInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_panicInstructionAST) ;
    result = p->mAttribute_mThrowLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_panicInstructionAST::getter_mThrowLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mThrowLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_panicInstructionAST::getter_mCodeExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_panicInstructionAST * p = (const cPtr_panicInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_panicInstructionAST) ;
    result = p->mAttribute_mCodeExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_panicInstructionAST::getter_mCodeExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mCodeExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @panicInstructionAST class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_panicInstructionAST::cPtr_panicInstructionAST (const GALGAS_location & in_mThrowLocation,
                                                    const GALGAS_expressionAST & in_mCodeExpression
                                                    COMMA_LOCATION_ARGS) :
cPtr_instructionAST (THERE),
mAttribute_mThrowLocation (in_mThrowLocation),
mAttribute_mCodeExpression (in_mCodeExpression) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_panicInstructionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_panicInstructionAST ;
}

void cPtr_panicInstructionAST::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@panicInstructionAST:" ;
  mAttribute_mThrowLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mCodeExpression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_panicInstructionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_panicInstructionAST (mAttribute_mThrowLocation, mAttribute_mCodeExpression COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @panicInstructionAST type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_panicInstructionAST ("panicInstructionAST",
                                            & kTypeDescriptor_GALGAS_instructionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_panicInstructionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_panicInstructionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_panicInstructionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_panicInstructionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicInstructionAST GALGAS_panicInstructionAST::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_panicInstructionAST result ;
  const GALGAS_panicInstructionAST * p = (const GALGAS_panicInstructionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_panicInstructionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("panicInstructionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_panicInstructionIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_panicInstructionIR * p = (const cPtr_panicInstructionIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_panicInstructionIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mThrowLocation.objectCompare (p->mAttribute_mThrowLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mPanicCode.objectCompare (p->mAttribute_mPanicCode) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_panicInstructionIR::objectCompare (const GALGAS_panicInstructionIR & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicInstructionIR::GALGAS_panicInstructionIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicInstructionIR GALGAS_panicInstructionIR::constructor_default (LOCATION_ARGS) {
  return GALGAS_panicInstructionIR::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                     GALGAS_bigint::constructor_zero (HERE)
                                                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicInstructionIR::GALGAS_panicInstructionIR (const cPtr_panicInstructionIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_panicInstructionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicInstructionIR GALGAS_panicInstructionIR::constructor_new (const GALGAS_location & inAttribute_mThrowLocation,
                                                                      const GALGAS_bigint & inAttribute_mPanicCode
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_panicInstructionIR result ;
  if (inAttribute_mThrowLocation.isValid () && inAttribute_mPanicCode.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_panicInstructionIR (inAttribute_mThrowLocation, inAttribute_mPanicCode COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_panicInstructionIR::getter_mThrowLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_panicInstructionIR * p = (const cPtr_panicInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_panicInstructionIR) ;
    result = p->mAttribute_mThrowLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_panicInstructionIR::getter_mThrowLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mThrowLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_panicInstructionIR::getter_mPanicCode (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_panicInstructionIR * p = (const cPtr_panicInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_panicInstructionIR) ;
    result = p->mAttribute_mPanicCode ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_panicInstructionIR::getter_mPanicCode (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPanicCode ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @panicInstructionIR class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_panicInstructionIR::cPtr_panicInstructionIR (const GALGAS_location & in_mThrowLocation,
                                                  const GALGAS_bigint & in_mPanicCode
                                                  COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mThrowLocation (in_mThrowLocation),
mAttribute_mPanicCode (in_mPanicCode) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_panicInstructionIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_panicInstructionIR ;
}

void cPtr_panicInstructionIR::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@panicInstructionIR:" ;
  mAttribute_mThrowLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mPanicCode.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_panicInstructionIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_panicInstructionIR (mAttribute_mThrowLocation, mAttribute_mPanicCode COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @panicInstructionIR type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_panicInstructionIR ("panicInstructionIR",
                                           & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_panicInstructionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_panicInstructionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_panicInstructionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_panicInstructionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicInstructionIR GALGAS_panicInstructionIR::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_panicInstructionIR result ;
  const GALGAS_panicInstructionIR * p = (const GALGAS_panicInstructionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_panicInstructionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("panicInstructionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_ifInstructionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_ifInstructionAST * p = (const cPtr_ifInstructionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_ifInstructionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mTestExpression.objectCompare (p->mAttribute_mTestExpression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mTestExpressionEndLocation.objectCompare (p->mAttribute_mTestExpressionEndLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mThenInstructionList.objectCompare (p->mAttribute_mThenInstructionList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mEndOfThenInstructionList.objectCompare (p->mAttribute_mEndOfThenInstructionList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mElseInstructionList.objectCompare (p->mAttribute_mElseInstructionList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mEndOfElseInstructionList.objectCompare (p->mAttribute_mEndOfElseInstructionList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mEndOf_5F_if_5F_instruction.objectCompare (p->mAttribute_mEndOf_5F_if_5F_instruction) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_ifInstructionAST::objectCompare (const GALGAS_ifInstructionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ifInstructionAST::GALGAS_ifInstructionAST (void) :
GALGAS_instructionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ifInstructionAST::GALGAS_ifInstructionAST (const cPtr_ifInstructionAST * inSourcePtr) :
GALGAS_instructionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_ifInstructionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ifInstructionAST GALGAS_ifInstructionAST::constructor_new (const GALGAS_expressionAST & inAttribute_mTestExpression,
                                                                  const GALGAS_location & inAttribute_mTestExpressionEndLocation,
                                                                  const GALGAS_instructionListAST & inAttribute_mThenInstructionList,
                                                                  const GALGAS_location & inAttribute_mEndOfThenInstructionList,
                                                                  const GALGAS_instructionListAST & inAttribute_mElseInstructionList,
                                                                  const GALGAS_location & inAttribute_mEndOfElseInstructionList,
                                                                  const GALGAS_location & inAttribute_mEndOf_5F_if_5F_instruction
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_ifInstructionAST result ;
  if (inAttribute_mTestExpression.isValid () && inAttribute_mTestExpressionEndLocation.isValid () && inAttribute_mThenInstructionList.isValid () && inAttribute_mEndOfThenInstructionList.isValid () && inAttribute_mElseInstructionList.isValid () && inAttribute_mEndOfElseInstructionList.isValid () && inAttribute_mEndOf_5F_if_5F_instruction.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_ifInstructionAST (inAttribute_mTestExpression, inAttribute_mTestExpressionEndLocation, inAttribute_mThenInstructionList, inAttribute_mEndOfThenInstructionList, inAttribute_mElseInstructionList, inAttribute_mEndOfElseInstructionList, inAttribute_mEndOf_5F_if_5F_instruction COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_ifInstructionAST::getter_mTestExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifInstructionAST * p = (const cPtr_ifInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifInstructionAST) ;
    result = p->mAttribute_mTestExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_ifInstructionAST::getter_mTestExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTestExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_ifInstructionAST::getter_mTestExpressionEndLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifInstructionAST * p = (const cPtr_ifInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifInstructionAST) ;
    result = p->mAttribute_mTestExpressionEndLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_ifInstructionAST::getter_mTestExpressionEndLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTestExpressionEndLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_ifInstructionAST::getter_mThenInstructionList (UNUSED_LOCATION_ARGS) const {
  GALGAS_instructionListAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifInstructionAST * p = (const cPtr_ifInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifInstructionAST) ;
    result = p->mAttribute_mThenInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cPtr_ifInstructionAST::getter_mThenInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mThenInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_ifInstructionAST::getter_mEndOfThenInstructionList (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifInstructionAST * p = (const cPtr_ifInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifInstructionAST) ;
    result = p->mAttribute_mEndOfThenInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_ifInstructionAST::getter_mEndOfThenInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfThenInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_ifInstructionAST::getter_mElseInstructionList (UNUSED_LOCATION_ARGS) const {
  GALGAS_instructionListAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifInstructionAST * p = (const cPtr_ifInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifInstructionAST) ;
    result = p->mAttribute_mElseInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cPtr_ifInstructionAST::getter_mElseInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mElseInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_ifInstructionAST::getter_mEndOfElseInstructionList (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifInstructionAST * p = (const cPtr_ifInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifInstructionAST) ;
    result = p->mAttribute_mEndOfElseInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_ifInstructionAST::getter_mEndOfElseInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfElseInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_ifInstructionAST::getter_mEndOf_5F_if_5F_instruction (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifInstructionAST * p = (const cPtr_ifInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifInstructionAST) ;
    result = p->mAttribute_mEndOf_5F_if_5F_instruction ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_ifInstructionAST::getter_mEndOf_5F_if_5F_instruction (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOf_5F_if_5F_instruction ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @ifInstructionAST class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_ifInstructionAST::cPtr_ifInstructionAST (const GALGAS_expressionAST & in_mTestExpression,
                                              const GALGAS_location & in_mTestExpressionEndLocation,
                                              const GALGAS_instructionListAST & in_mThenInstructionList,
                                              const GALGAS_location & in_mEndOfThenInstructionList,
                                              const GALGAS_instructionListAST & in_mElseInstructionList,
                                              const GALGAS_location & in_mEndOfElseInstructionList,
                                              const GALGAS_location & in_mEndOf_5F_if_5F_instruction
                                              COMMA_LOCATION_ARGS) :
cPtr_instructionAST (THERE),
mAttribute_mTestExpression (in_mTestExpression),
mAttribute_mTestExpressionEndLocation (in_mTestExpressionEndLocation),
mAttribute_mThenInstructionList (in_mThenInstructionList),
mAttribute_mEndOfThenInstructionList (in_mEndOfThenInstructionList),
mAttribute_mElseInstructionList (in_mElseInstructionList),
mAttribute_mEndOfElseInstructionList (in_mEndOfElseInstructionList),
mAttribute_mEndOf_5F_if_5F_instruction (in_mEndOf_5F_if_5F_instruction) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_ifInstructionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ifInstructionAST ;
}

void cPtr_ifInstructionAST::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@ifInstructionAST:" ;
  mAttribute_mTestExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mTestExpressionEndLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mThenInstructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mEndOfThenInstructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mElseInstructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mEndOfElseInstructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mEndOf_5F_if_5F_instruction.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_ifInstructionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_ifInstructionAST (mAttribute_mTestExpression, mAttribute_mTestExpressionEndLocation, mAttribute_mThenInstructionList, mAttribute_mEndOfThenInstructionList, mAttribute_mElseInstructionList, mAttribute_mEndOfElseInstructionList, mAttribute_mEndOf_5F_if_5F_instruction COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @ifInstructionAST type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ifInstructionAST ("ifInstructionAST",
                                         & kTypeDescriptor_GALGAS_instructionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_ifInstructionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ifInstructionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_ifInstructionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ifInstructionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ifInstructionAST GALGAS_ifInstructionAST::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_ifInstructionAST result ;
  const GALGAS_ifInstructionAST * p = (const GALGAS_ifInstructionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ifInstructionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ifInstructionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_syncInstructionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_syncInstructionAST * p = (const cPtr_syncInstructionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_syncInstructionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mStartOf_5F_on_5F_instruction.objectCompare (p->mAttribute_mStartOf_5F_on_5F_instruction) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mBranchList.objectCompare (p->mAttribute_mBranchList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mEndOf_5F_on_5F_instruction.objectCompare (p->mAttribute_mEndOf_5F_on_5F_instruction) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_syncInstructionAST::objectCompare (const GALGAS_syncInstructionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionAST::GALGAS_syncInstructionAST (void) :
GALGAS_instructionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionAST GALGAS_syncInstructionAST::constructor_default (LOCATION_ARGS) {
  return GALGAS_syncInstructionAST::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                     GALGAS_syncInstructionBranchList::constructor_emptyList (HERE),
                                                     GALGAS_location::constructor_nowhere (HERE)
                                                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionAST::GALGAS_syncInstructionAST (const cPtr_syncInstructionAST * inSourcePtr) :
GALGAS_instructionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_syncInstructionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionAST GALGAS_syncInstructionAST::constructor_new (const GALGAS_location & inAttribute_mStartOf_5F_on_5F_instruction,
                                                                      const GALGAS_syncInstructionBranchList & inAttribute_mBranchList,
                                                                      const GALGAS_location & inAttribute_mEndOf_5F_on_5F_instruction
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_syncInstructionAST result ;
  if (inAttribute_mStartOf_5F_on_5F_instruction.isValid () && inAttribute_mBranchList.isValid () && inAttribute_mEndOf_5F_on_5F_instruction.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_syncInstructionAST (inAttribute_mStartOf_5F_on_5F_instruction, inAttribute_mBranchList, inAttribute_mEndOf_5F_on_5F_instruction COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_syncInstructionAST::getter_mStartOf_5F_on_5F_instruction (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_syncInstructionAST * p = (const cPtr_syncInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_syncInstructionAST) ;
    result = p->mAttribute_mStartOf_5F_on_5F_instruction ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_syncInstructionAST::getter_mStartOf_5F_on_5F_instruction (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mStartOf_5F_on_5F_instruction ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchList GALGAS_syncInstructionAST::getter_mBranchList (UNUSED_LOCATION_ARGS) const {
  GALGAS_syncInstructionBranchList result ;
  if (NULL != mObjectPtr) {
    const cPtr_syncInstructionAST * p = (const cPtr_syncInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_syncInstructionAST) ;
    result = p->mAttribute_mBranchList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchList cPtr_syncInstructionAST::getter_mBranchList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mBranchList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_syncInstructionAST::getter_mEndOf_5F_on_5F_instruction (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_syncInstructionAST * p = (const cPtr_syncInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_syncInstructionAST) ;
    result = p->mAttribute_mEndOf_5F_on_5F_instruction ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_syncInstructionAST::getter_mEndOf_5F_on_5F_instruction (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOf_5F_on_5F_instruction ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @syncInstructionAST class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_syncInstructionAST::cPtr_syncInstructionAST (const GALGAS_location & in_mStartOf_5F_on_5F_instruction,
                                                  const GALGAS_syncInstructionBranchList & in_mBranchList,
                                                  const GALGAS_location & in_mEndOf_5F_on_5F_instruction
                                                  COMMA_LOCATION_ARGS) :
cPtr_instructionAST (THERE),
mAttribute_mStartOf_5F_on_5F_instruction (in_mStartOf_5F_on_5F_instruction),
mAttribute_mBranchList (in_mBranchList),
mAttribute_mEndOf_5F_on_5F_instruction (in_mEndOf_5F_on_5F_instruction) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_syncInstructionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_syncInstructionAST ;
}

void cPtr_syncInstructionAST::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@syncInstructionAST:" ;
  mAttribute_mStartOf_5F_on_5F_instruction.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mBranchList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mEndOf_5F_on_5F_instruction.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_syncInstructionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_syncInstructionAST (mAttribute_mStartOf_5F_on_5F_instruction, mAttribute_mBranchList, mAttribute_mEndOf_5F_on_5F_instruction COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @syncInstructionAST type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_syncInstructionAST ("syncInstructionAST",
                                           & kTypeDescriptor_GALGAS_instructionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_syncInstructionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_syncInstructionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_syncInstructionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_syncInstructionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionAST GALGAS_syncInstructionAST::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_syncInstructionAST result ;
  const GALGAS_syncInstructionAST * p = (const GALGAS_syncInstructionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_syncInstructionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("syncInstructionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Class for element of '@syncInstructionBranchListIR' list                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_syncInstructionBranchListIR : public cCollectionElement {
  public : GALGAS_syncInstructionBranchListIR_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_syncInstructionBranchListIR (const GALGAS_guardedCommandIR & in_mGuardedCommand,
                                                           const GALGAS_instructionListIR & in_mInstructionGenerationList
                                                           COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_syncInstructionBranchListIR::cCollectionElement_syncInstructionBranchListIR (const GALGAS_guardedCommandIR & in_mGuardedCommand,
                                                                                                const GALGAS_instructionListIR & in_mInstructionGenerationList
                                                                                                COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mGuardedCommand, in_mInstructionGenerationList) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_syncInstructionBranchListIR::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_syncInstructionBranchListIR::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_syncInstructionBranchListIR (mObject.mAttribute_mGuardedCommand, mObject.mAttribute_mInstructionGenerationList COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_syncInstructionBranchListIR::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGuardedCommand" ":" ;
  mObject.mAttribute_mGuardedCommand.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mInstructionGenerationList" ":" ;
  mObject.mAttribute_mInstructionGenerationList.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_syncInstructionBranchListIR::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_syncInstructionBranchListIR * operand = (cCollectionElement_syncInstructionBranchListIR *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_syncInstructionBranchListIR) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR::GALGAS_syncInstructionBranchListIR (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR::GALGAS_syncInstructionBranchListIR (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR GALGAS_syncInstructionBranchListIR::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_syncInstructionBranchListIR result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR GALGAS_syncInstructionBranchListIR::constructor_listWithValue (const GALGAS_guardedCommandIR & inOperand0,
                                                                                                  const GALGAS_instructionListIR & inOperand1
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_syncInstructionBranchListIR result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_syncInstructionBranchListIR::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                    const GALGAS_guardedCommandIR & in_mGuardedCommand,
                                                                    const GALGAS_instructionListIR & in_mInstructionGenerationList
                                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_syncInstructionBranchListIR * p = NULL ;
  macroMyNew (p, cCollectionElement_syncInstructionBranchListIR (in_mGuardedCommand,
                                                                 in_mInstructionGenerationList COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR::addAssign_operation (const GALGAS_guardedCommandIR & inOperand0,
                                                              const GALGAS_instructionListIR & inOperand1
                                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_syncInstructionBranchListIR (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR::setter_insertAtIndex (const GALGAS_guardedCommandIR inOperand0,
                                                               const GALGAS_instructionListIR inOperand1,
                                                               const GALGAS_uint inInsertionIndex,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_syncInstructionBranchListIR (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR::setter_removeAtIndex (GALGAS_guardedCommandIR & outOperand0,
                                                               GALGAS_instructionListIR & outOperand1,
                                                               const GALGAS_uint inRemoveIndex,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_syncInstructionBranchListIR * p = (cCollectionElement_syncInstructionBranchListIR *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_syncInstructionBranchListIR) ;
      outOperand0 = p->mObject.mAttribute_mGuardedCommand ;
      outOperand1 = p->mObject.mAttribute_mInstructionGenerationList ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR::setter_popFirst (GALGAS_guardedCommandIR & outOperand0,
                                                          GALGAS_instructionListIR & outOperand1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_syncInstructionBranchListIR * p = (cCollectionElement_syncInstructionBranchListIR *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_syncInstructionBranchListIR) ;
    outOperand0 = p->mObject.mAttribute_mGuardedCommand ;
    outOperand1 = p->mObject.mAttribute_mInstructionGenerationList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR::setter_popLast (GALGAS_guardedCommandIR & outOperand0,
                                                         GALGAS_instructionListIR & outOperand1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_syncInstructionBranchListIR * p = (cCollectionElement_syncInstructionBranchListIR *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_syncInstructionBranchListIR) ;
    outOperand0 = p->mObject.mAttribute_mGuardedCommand ;
    outOperand1 = p->mObject.mAttribute_mInstructionGenerationList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR::method_first (GALGAS_guardedCommandIR & outOperand0,
                                                       GALGAS_instructionListIR & outOperand1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_syncInstructionBranchListIR * p = (cCollectionElement_syncInstructionBranchListIR *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_syncInstructionBranchListIR) ;
    outOperand0 = p->mObject.mAttribute_mGuardedCommand ;
    outOperand1 = p->mObject.mAttribute_mInstructionGenerationList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR::method_last (GALGAS_guardedCommandIR & outOperand0,
                                                      GALGAS_instructionListIR & outOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_syncInstructionBranchListIR * p = (cCollectionElement_syncInstructionBranchListIR *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_syncInstructionBranchListIR) ;
    outOperand0 = p->mObject.mAttribute_mGuardedCommand ;
    outOperand1 = p->mObject.mAttribute_mInstructionGenerationList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR GALGAS_syncInstructionBranchListIR::add_operation (const GALGAS_syncInstructionBranchListIR & inOperand,
                                                                                      C_Compiler * /* inCompiler */
                                                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_syncInstructionBranchListIR result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR GALGAS_syncInstructionBranchListIR::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_syncInstructionBranchListIR result = GALGAS_syncInstructionBranchListIR::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR GALGAS_syncInstructionBranchListIR::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_syncInstructionBranchListIR result = GALGAS_syncInstructionBranchListIR::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR GALGAS_syncInstructionBranchListIR::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_syncInstructionBranchListIR result = GALGAS_syncInstructionBranchListIR::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR::plusAssign_operation (const GALGAS_syncInstructionBranchListIR inOperand,
                                                               C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardedCommandIR GALGAS_syncInstructionBranchListIR::getter_mGuardedCommandAtIndex (const GALGAS_uint & inIndex,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_syncInstructionBranchListIR * p = (cCollectionElement_syncInstructionBranchListIR *) attributes.ptr () ;
  GALGAS_guardedCommandIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_syncInstructionBranchListIR) ;
    result = p->mObject.mAttribute_mGuardedCommand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_syncInstructionBranchListIR::getter_mInstructionGenerationListAtIndex (const GALGAS_uint & inIndex,
                                                                                                       C_Compiler * inCompiler
                                                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_syncInstructionBranchListIR * p = (cCollectionElement_syncInstructionBranchListIR *) attributes.ptr () ;
  GALGAS_instructionListIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_syncInstructionBranchListIR) ;
    result = p->mObject.mAttribute_mInstructionGenerationList ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_syncInstructionBranchListIR::cEnumerator_syncInstructionBranchListIR (const GALGAS_syncInstructionBranchListIR & inEnumeratedObject,
                                                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR_2D_element cEnumerator_syncInstructionBranchListIR::current (LOCATION_ARGS) const {
  const cCollectionElement_syncInstructionBranchListIR * p = (const cCollectionElement_syncInstructionBranchListIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_syncInstructionBranchListIR) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardedCommandIR cEnumerator_syncInstructionBranchListIR::current_mGuardedCommand (LOCATION_ARGS) const {
  const cCollectionElement_syncInstructionBranchListIR * p = (const cCollectionElement_syncInstructionBranchListIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_syncInstructionBranchListIR) ;
  return p->mObject.mAttribute_mGuardedCommand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cEnumerator_syncInstructionBranchListIR::current_mInstructionGenerationList (LOCATION_ARGS) const {
  const cCollectionElement_syncInstructionBranchListIR * p = (const cCollectionElement_syncInstructionBranchListIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_syncInstructionBranchListIR) ;
  return p->mObject.mAttribute_mInstructionGenerationList ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @syncInstructionBranchListIR type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_syncInstructionBranchListIR ("syncInstructionBranchListIR",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_syncInstructionBranchListIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_syncInstructionBranchListIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_syncInstructionBranchListIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_syncInstructionBranchListIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR GALGAS_syncInstructionBranchListIR::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_syncInstructionBranchListIR result ;
  const GALGAS_syncInstructionBranchListIR * p = (const GALGAS_syncInstructionBranchListIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_syncInstructionBranchListIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("syncInstructionBranchListIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_syncInstructionIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_syncInstructionIR * p = (const cPtr_syncInstructionIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_syncInstructionIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mSelectInstructionLocation.objectCompare (p->mAttribute_mSelectInstructionLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mOnInstructionBranchListIR.objectCompare (p->mAttribute_mOnInstructionBranchListIR) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_syncInstructionIR::objectCompare (const GALGAS_syncInstructionIR & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionIR::GALGAS_syncInstructionIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionIR GALGAS_syncInstructionIR::constructor_default (LOCATION_ARGS) {
  return GALGAS_syncInstructionIR::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                    GALGAS_syncInstructionBranchListIR::constructor_emptyList (HERE)
                                                    COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionIR::GALGAS_syncInstructionIR (const cPtr_syncInstructionIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_syncInstructionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionIR GALGAS_syncInstructionIR::constructor_new (const GALGAS_location & inAttribute_mSelectInstructionLocation,
                                                                    const GALGAS_syncInstructionBranchListIR & inAttribute_mOnInstructionBranchListIR
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_syncInstructionIR result ;
  if (inAttribute_mSelectInstructionLocation.isValid () && inAttribute_mOnInstructionBranchListIR.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_syncInstructionIR (inAttribute_mSelectInstructionLocation, inAttribute_mOnInstructionBranchListIR COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_syncInstructionIR::getter_mSelectInstructionLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_syncInstructionIR * p = (const cPtr_syncInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_syncInstructionIR) ;
    result = p->mAttribute_mSelectInstructionLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_syncInstructionIR::getter_mSelectInstructionLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSelectInstructionLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR GALGAS_syncInstructionIR::getter_mOnInstructionBranchListIR (UNUSED_LOCATION_ARGS) const {
  GALGAS_syncInstructionBranchListIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_syncInstructionIR * p = (const cPtr_syncInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_syncInstructionIR) ;
    result = p->mAttribute_mOnInstructionBranchListIR ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR cPtr_syncInstructionIR::getter_mOnInstructionBranchListIR (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOnInstructionBranchListIR ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @syncInstructionIR class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_syncInstructionIR::cPtr_syncInstructionIR (const GALGAS_location & in_mSelectInstructionLocation,
                                                const GALGAS_syncInstructionBranchListIR & in_mOnInstructionBranchListIR
                                                COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mSelectInstructionLocation (in_mSelectInstructionLocation),
mAttribute_mOnInstructionBranchListIR (in_mOnInstructionBranchListIR) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_syncInstructionIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_syncInstructionIR ;
}

void cPtr_syncInstructionIR::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@syncInstructionIR:" ;
  mAttribute_mSelectInstructionLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mOnInstructionBranchListIR.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_syncInstructionIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_syncInstructionIR (mAttribute_mSelectInstructionLocation, mAttribute_mOnInstructionBranchListIR COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @syncInstructionIR type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_syncInstructionIR ("syncInstructionIR",
                                          & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_syncInstructionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_syncInstructionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_syncInstructionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_syncInstructionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionIR GALGAS_syncInstructionIR::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_syncInstructionIR result ;
  const GALGAS_syncInstructionIR * p = (const GALGAS_syncInstructionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_syncInstructionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("syncInstructionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_whileInstructionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_whileInstructionAST * p = (const cPtr_whileInstructionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_whileInstructionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mTestExpression.objectCompare (p->mAttribute_mTestExpression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mEndOf_5F_test_5F_expression.objectCompare (p->mAttribute_mEndOf_5F_test_5F_expression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mWhileInstructionList.objectCompare (p->mAttribute_mWhileInstructionList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mEndOf_5F_while_5F_instruction.objectCompare (p->mAttribute_mEndOf_5F_while_5F_instruction) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_whileInstructionAST::objectCompare (const GALGAS_whileInstructionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_whileInstructionAST::GALGAS_whileInstructionAST (void) :
GALGAS_instructionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_whileInstructionAST::GALGAS_whileInstructionAST (const cPtr_whileInstructionAST * inSourcePtr) :
GALGAS_instructionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_whileInstructionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_whileInstructionAST GALGAS_whileInstructionAST::constructor_new (const GALGAS_expressionAST & inAttribute_mTestExpression,
                                                                        const GALGAS_location & inAttribute_mEndOf_5F_test_5F_expression,
                                                                        const GALGAS_instructionListAST & inAttribute_mWhileInstructionList,
                                                                        const GALGAS_location & inAttribute_mEndOf_5F_while_5F_instruction
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_whileInstructionAST result ;
  if (inAttribute_mTestExpression.isValid () && inAttribute_mEndOf_5F_test_5F_expression.isValid () && inAttribute_mWhileInstructionList.isValid () && inAttribute_mEndOf_5F_while_5F_instruction.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_whileInstructionAST (inAttribute_mTestExpression, inAttribute_mEndOf_5F_test_5F_expression, inAttribute_mWhileInstructionList, inAttribute_mEndOf_5F_while_5F_instruction COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_whileInstructionAST::getter_mTestExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_whileInstructionAST * p = (const cPtr_whileInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_whileInstructionAST) ;
    result = p->mAttribute_mTestExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_whileInstructionAST::getter_mTestExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTestExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_whileInstructionAST::getter_mEndOf_5F_test_5F_expression (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_whileInstructionAST * p = (const cPtr_whileInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_whileInstructionAST) ;
    result = p->mAttribute_mEndOf_5F_test_5F_expression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_whileInstructionAST::getter_mEndOf_5F_test_5F_expression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOf_5F_test_5F_expression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_whileInstructionAST::getter_mWhileInstructionList (UNUSED_LOCATION_ARGS) const {
  GALGAS_instructionListAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_whileInstructionAST * p = (const cPtr_whileInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_whileInstructionAST) ;
    result = p->mAttribute_mWhileInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cPtr_whileInstructionAST::getter_mWhileInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mWhileInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_whileInstructionAST::getter_mEndOf_5F_while_5F_instruction (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_whileInstructionAST * p = (const cPtr_whileInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_whileInstructionAST) ;
    result = p->mAttribute_mEndOf_5F_while_5F_instruction ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_whileInstructionAST::getter_mEndOf_5F_while_5F_instruction (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOf_5F_while_5F_instruction ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @whileInstructionAST class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_whileInstructionAST::cPtr_whileInstructionAST (const GALGAS_expressionAST & in_mTestExpression,
                                                    const GALGAS_location & in_mEndOf_5F_test_5F_expression,
                                                    const GALGAS_instructionListAST & in_mWhileInstructionList,
                                                    const GALGAS_location & in_mEndOf_5F_while_5F_instruction
                                                    COMMA_LOCATION_ARGS) :
cPtr_instructionAST (THERE),
mAttribute_mTestExpression (in_mTestExpression),
mAttribute_mEndOf_5F_test_5F_expression (in_mEndOf_5F_test_5F_expression),
mAttribute_mWhileInstructionList (in_mWhileInstructionList),
mAttribute_mEndOf_5F_while_5F_instruction (in_mEndOf_5F_while_5F_instruction) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_whileInstructionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_whileInstructionAST ;
}

void cPtr_whileInstructionAST::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@whileInstructionAST:" ;
  mAttribute_mTestExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mEndOf_5F_test_5F_expression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mWhileInstructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mEndOf_5F_while_5F_instruction.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_whileInstructionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_whileInstructionAST (mAttribute_mTestExpression, mAttribute_mEndOf_5F_test_5F_expression, mAttribute_mWhileInstructionList, mAttribute_mEndOf_5F_while_5F_instruction COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @whileInstructionAST type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_whileInstructionAST ("whileInstructionAST",
                                            & kTypeDescriptor_GALGAS_instructionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_whileInstructionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_whileInstructionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_whileInstructionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_whileInstructionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_whileInstructionAST GALGAS_whileInstructionAST::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_whileInstructionAST result ;
  const GALGAS_whileInstructionAST * p = (const GALGAS_whileInstructionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_whileInstructionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("whileInstructionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Class for element of '@procEffectiveParameterList' list                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_procEffectiveParameterList : public cCollectionElement {
  public : GALGAS_procEffectiveParameterList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_procEffectiveParameterList (const GALGAS_effectiveParameterPassingModeAST & in_mEffectiveParameterPassingMode,
                                                          const GALGAS_lstring & in_mSelector,
                                                          const GALGAS_unifiedTypeMap_2D_proxy & in_mParameterType
                                                          COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_procEffectiveParameterList::cCollectionElement_procEffectiveParameterList (const GALGAS_effectiveParameterPassingModeAST & in_mEffectiveParameterPassingMode,
                                                                                              const GALGAS_lstring & in_mSelector,
                                                                                              const GALGAS_unifiedTypeMap_2D_proxy & in_mParameterType
                                                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mEffectiveParameterPassingMode, in_mSelector, in_mParameterType) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_procEffectiveParameterList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_procEffectiveParameterList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_procEffectiveParameterList (mObject.mAttribute_mEffectiveParameterPassingMode, mObject.mAttribute_mSelector, mObject.mAttribute_mParameterType COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_procEffectiveParameterList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEffectiveParameterPassingMode" ":" ;
  mObject.mAttribute_mEffectiveParameterPassingMode.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSelector" ":" ;
  mObject.mAttribute_mSelector.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mParameterType" ":" ;
  mObject.mAttribute_mParameterType.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_procEffectiveParameterList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_procEffectiveParameterList * operand = (cCollectionElement_procEffectiveParameterList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_procEffectiveParameterList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList::GALGAS_procEffectiveParameterList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList::GALGAS_procEffectiveParameterList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList GALGAS_procEffectiveParameterList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_procEffectiveParameterList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList GALGAS_procEffectiveParameterList::constructor_listWithValue (const GALGAS_effectiveParameterPassingModeAST & inOperand0,
                                                                                                const GALGAS_lstring & inOperand1,
                                                                                                const GALGAS_unifiedTypeMap_2D_proxy & inOperand2
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_procEffectiveParameterList result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_procEffectiveParameterList::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procEffectiveParameterList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                   const GALGAS_effectiveParameterPassingModeAST & in_mEffectiveParameterPassingMode,
                                                                   const GALGAS_lstring & in_mSelector,
                                                                   const GALGAS_unifiedTypeMap_2D_proxy & in_mParameterType
                                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_procEffectiveParameterList * p = NULL ;
  macroMyNew (p, cCollectionElement_procEffectiveParameterList (in_mEffectiveParameterPassingMode,
                                                                in_mSelector,
                                                                in_mParameterType COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procEffectiveParameterList::addAssign_operation (const GALGAS_effectiveParameterPassingModeAST & inOperand0,
                                                             const GALGAS_lstring & inOperand1,
                                                             const GALGAS_unifiedTypeMap_2D_proxy & inOperand2
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_procEffectiveParameterList (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procEffectiveParameterList::setter_insertAtIndex (const GALGAS_effectiveParameterPassingModeAST inOperand0,
                                                              const GALGAS_lstring inOperand1,
                                                              const GALGAS_unifiedTypeMap_2D_proxy inOperand2,
                                                              const GALGAS_uint inInsertionIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_procEffectiveParameterList (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procEffectiveParameterList::setter_removeAtIndex (GALGAS_effectiveParameterPassingModeAST & outOperand0,
                                                              GALGAS_lstring & outOperand1,
                                                              GALGAS_unifiedTypeMap_2D_proxy & outOperand2,
                                                              const GALGAS_uint inRemoveIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_procEffectiveParameterList * p = (cCollectionElement_procEffectiveParameterList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_procEffectiveParameterList) ;
      outOperand0 = p->mObject.mAttribute_mEffectiveParameterPassingMode ;
      outOperand1 = p->mObject.mAttribute_mSelector ;
      outOperand2 = p->mObject.mAttribute_mParameterType ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procEffectiveParameterList::setter_popFirst (GALGAS_effectiveParameterPassingModeAST & outOperand0,
                                                         GALGAS_lstring & outOperand1,
                                                         GALGAS_unifiedTypeMap_2D_proxy & outOperand2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procEffectiveParameterList * p = (cCollectionElement_procEffectiveParameterList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procEffectiveParameterList) ;
    outOperand0 = p->mObject.mAttribute_mEffectiveParameterPassingMode ;
    outOperand1 = p->mObject.mAttribute_mSelector ;
    outOperand2 = p->mObject.mAttribute_mParameterType ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procEffectiveParameterList::setter_popLast (GALGAS_effectiveParameterPassingModeAST & outOperand0,
                                                        GALGAS_lstring & outOperand1,
                                                        GALGAS_unifiedTypeMap_2D_proxy & outOperand2,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procEffectiveParameterList * p = (cCollectionElement_procEffectiveParameterList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procEffectiveParameterList) ;
    outOperand0 = p->mObject.mAttribute_mEffectiveParameterPassingMode ;
    outOperand1 = p->mObject.mAttribute_mSelector ;
    outOperand2 = p->mObject.mAttribute_mParameterType ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procEffectiveParameterList::method_first (GALGAS_effectiveParameterPassingModeAST & outOperand0,
                                                      GALGAS_lstring & outOperand1,
                                                      GALGAS_unifiedTypeMap_2D_proxy & outOperand2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procEffectiveParameterList * p = (cCollectionElement_procEffectiveParameterList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procEffectiveParameterList) ;
    outOperand0 = p->mObject.mAttribute_mEffectiveParameterPassingMode ;
    outOperand1 = p->mObject.mAttribute_mSelector ;
    outOperand2 = p->mObject.mAttribute_mParameterType ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procEffectiveParameterList::method_last (GALGAS_effectiveParameterPassingModeAST & outOperand0,
                                                     GALGAS_lstring & outOperand1,
                                                     GALGAS_unifiedTypeMap_2D_proxy & outOperand2,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_procEffectiveParameterList * p = (cCollectionElement_procEffectiveParameterList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_procEffectiveParameterList) ;
    outOperand0 = p->mObject.mAttribute_mEffectiveParameterPassingMode ;
    outOperand1 = p->mObject.mAttribute_mSelector ;
    outOperand2 = p->mObject.mAttribute_mParameterType ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList GALGAS_procEffectiveParameterList::add_operation (const GALGAS_procEffectiveParameterList & inOperand,
                                                                                    C_Compiler * /* inCompiler */
                                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_procEffectiveParameterList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList GALGAS_procEffectiveParameterList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_procEffectiveParameterList result = GALGAS_procEffectiveParameterList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList GALGAS_procEffectiveParameterList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_procEffectiveParameterList result = GALGAS_procEffectiveParameterList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList GALGAS_procEffectiveParameterList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_procEffectiveParameterList result = GALGAS_procEffectiveParameterList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procEffectiveParameterList::plusAssign_operation (const GALGAS_procEffectiveParameterList inOperand,
                                                              C_Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterPassingModeAST GALGAS_procEffectiveParameterList::getter_mEffectiveParameterPassingModeAtIndex (const GALGAS_uint & inIndex,
                                                                                                                         C_Compiler * inCompiler
                                                                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_procEffectiveParameterList * p = (cCollectionElement_procEffectiveParameterList *) attributes.ptr () ;
  GALGAS_effectiveParameterPassingModeAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_procEffectiveParameterList) ;
    result = p->mObject.mAttribute_mEffectiveParameterPassingMode ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_procEffectiveParameterList::getter_mSelectorAtIndex (const GALGAS_uint & inIndex,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_procEffectiveParameterList * p = (cCollectionElement_procEffectiveParameterList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_procEffectiveParameterList) ;
    result = p->mObject.mAttribute_mSelector ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_procEffectiveParameterList::getter_mParameterTypeAtIndex (const GALGAS_uint & inIndex,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_procEffectiveParameterList * p = (cCollectionElement_procEffectiveParameterList *) attributes.ptr () ;
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_procEffectiveParameterList) ;
    result = p->mObject.mAttribute_mParameterType ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_procEffectiveParameterList::cEnumerator_procEffectiveParameterList (const GALGAS_procEffectiveParameterList & inEnumeratedObject,
                                                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList_2D_element cEnumerator_procEffectiveParameterList::current (LOCATION_ARGS) const {
  const cCollectionElement_procEffectiveParameterList * p = (const cCollectionElement_procEffectiveParameterList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procEffectiveParameterList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterPassingModeAST cEnumerator_procEffectiveParameterList::current_mEffectiveParameterPassingMode (LOCATION_ARGS) const {
  const cCollectionElement_procEffectiveParameterList * p = (const cCollectionElement_procEffectiveParameterList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procEffectiveParameterList) ;
  return p->mObject.mAttribute_mEffectiveParameterPassingMode ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_procEffectiveParameterList::current_mSelector (LOCATION_ARGS) const {
  const cCollectionElement_procEffectiveParameterList * p = (const cCollectionElement_procEffectiveParameterList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procEffectiveParameterList) ;
  return p->mObject.mAttribute_mSelector ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cEnumerator_procEffectiveParameterList::current_mParameterType (LOCATION_ARGS) const {
  const cCollectionElement_procEffectiveParameterList * p = (const cCollectionElement_procEffectiveParameterList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_procEffectiveParameterList) ;
  return p->mObject.mAttribute_mParameterType ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @procEffectiveParameterList type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procEffectiveParameterList ("procEffectiveParameterList",
                                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procEffectiveParameterList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procEffectiveParameterList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procEffectiveParameterList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procEffectiveParameterList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList GALGAS_procEffectiveParameterList::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_procEffectiveParameterList result ;
  const GALGAS_procEffectiveParameterList * p = (const GALGAS_procEffectiveParameterList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procEffectiveParameterList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procEffectiveParameterList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterPassingModeIR::GALGAS_procEffectiveParameterPassingModeIR (void) :
mEnum (kNotBuilt) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterPassingModeIR GALGAS_procEffectiveParameterPassingModeIR::constructor_input (UNUSED_LOCATION_ARGS) {
  GALGAS_procEffectiveParameterPassingModeIR result ;
  result.mEnum = kEnum_input ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterPassingModeIR GALGAS_procEffectiveParameterPassingModeIR::constructor_output (UNUSED_LOCATION_ARGS) {
  GALGAS_procEffectiveParameterPassingModeIR result ;
  result.mEnum = kEnum_output ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterPassingModeIR GALGAS_procEffectiveParameterPassingModeIR::constructor_outputInput (UNUSED_LOCATION_ARGS) {
  GALGAS_procEffectiveParameterPassingModeIR result ;
  result.mEnum = kEnum_outputInput ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * gEnumNameArrayFor_procEffectiveParameterPassingModeIR [4] = {
  "(not built)",
  "input",
  "output",
  "outputInput"
} ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_procEffectiveParameterPassingModeIR::getter_isInput (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_input == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_procEffectiveParameterPassingModeIR::getter_isOutput (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_output == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_procEffectiveParameterPassingModeIR::getter_isOutputInput (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_outputInput == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procEffectiveParameterPassingModeIR::description (C_String & ioString,
                                                              const int32_t /* inIndentation */) const {
  ioString << "<enum @procEffectiveParameterPassingModeIR: " << gEnumNameArrayFor_procEffectiveParameterPassingModeIR [mEnum] ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_procEffectiveParameterPassingModeIR::objectCompare (const GALGAS_procEffectiveParameterPassingModeIR & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @procEffectiveParameterPassingModeIR type                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procEffectiveParameterPassingModeIR ("procEffectiveParameterPassingModeIR",
                                                            NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procEffectiveParameterPassingModeIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procEffectiveParameterPassingModeIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procEffectiveParameterPassingModeIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procEffectiveParameterPassingModeIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterPassingModeIR GALGAS_procEffectiveParameterPassingModeIR::extractObject (const GALGAS_object & inObject,
                                                                                                      C_Compiler * inCompiler
                                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_procEffectiveParameterPassingModeIR result ;
  const GALGAS_procEffectiveParameterPassingModeIR * p = (const GALGAS_procEffectiveParameterPassingModeIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procEffectiveParameterPassingModeIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procEffectiveParameterPassingModeIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_calleeKindIR::GALGAS_calleeKindIR (void) :
mEnum (kNotBuilt) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_calleeKindIR GALGAS_calleeKindIR::constructor_function (UNUSED_LOCATION_ARGS) {
  GALGAS_calleeKindIR result ;
  result.mEnum = kEnum_function ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_calleeKindIR GALGAS_calleeKindIR::constructor_primitiveFromProcessorUserMode (UNUSED_LOCATION_ARGS) {
  GALGAS_calleeKindIR result ;
  result.mEnum = kEnum_primitiveFromProcessorUserMode ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_calleeKindIR GALGAS_calleeKindIR::constructor_safeFromProcessorUserMode (UNUSED_LOCATION_ARGS) {
  GALGAS_calleeKindIR result ;
  result.mEnum = kEnum_safeFromProcessorUserMode ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_calleeKindIR GALGAS_calleeKindIR::constructor_sectionFromProcessorUserMode (UNUSED_LOCATION_ARGS) {
  GALGAS_calleeKindIR result ;
  result.mEnum = kEnum_sectionFromProcessorUserMode ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_calleeKindIR GALGAS_calleeKindIR::constructor_serviceFromProcessorUserMode (UNUSED_LOCATION_ARGS) {
  GALGAS_calleeKindIR result ;
  result.mEnum = kEnum_serviceFromProcessorUserMode ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_calleeKindIR GALGAS_calleeKindIR::constructor_primitiveFromProcessorPrivilegedMode (UNUSED_LOCATION_ARGS) {
  GALGAS_calleeKindIR result ;
  result.mEnum = kEnum_primitiveFromProcessorPrivilegedMode ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_calleeKindIR GALGAS_calleeKindIR::constructor_sectionFromProcessorPrivilegedMode (UNUSED_LOCATION_ARGS) {
  GALGAS_calleeKindIR result ;
  result.mEnum = kEnum_sectionFromProcessorPrivilegedMode ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_calleeKindIR GALGAS_calleeKindIR::constructor_safeFromProcessorPrivilegedMode (UNUSED_LOCATION_ARGS) {
  GALGAS_calleeKindIR result ;
  result.mEnum = kEnum_safeFromProcessorPrivilegedMode ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_calleeKindIR GALGAS_calleeKindIR::constructor_serviceFromProcessorPrivilegedMode (UNUSED_LOCATION_ARGS) {
  GALGAS_calleeKindIR result ;
  result.mEnum = kEnum_serviceFromProcessorPrivilegedMode ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * gEnumNameArrayFor_calleeKindIR [10] = {
  "(not built)",
  "function",
  "primitiveFromProcessorUserMode",
  "safeFromProcessorUserMode",
  "sectionFromProcessorUserMode",
  "serviceFromProcessorUserMode",
  "primitiveFromProcessorPrivilegedMode",
  "sectionFromProcessorPrivilegedMode",
  "safeFromProcessorPrivilegedMode",
  "serviceFromProcessorPrivilegedMode"
} ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_calleeKindIR::getter_isFunction (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_function == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_calleeKindIR::getter_isPrimitiveFromProcessorUserMode (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_primitiveFromProcessorUserMode == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_calleeKindIR::getter_isSafeFromProcessorUserMode (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_safeFromProcessorUserMode == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_calleeKindIR::getter_isSectionFromProcessorUserMode (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_sectionFromProcessorUserMode == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_calleeKindIR::getter_isServiceFromProcessorUserMode (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_serviceFromProcessorUserMode == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_calleeKindIR::getter_isPrimitiveFromProcessorPrivilegedMode (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_primitiveFromProcessorPrivilegedMode == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_calleeKindIR::getter_isSectionFromProcessorPrivilegedMode (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_sectionFromProcessorPrivilegedMode == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_calleeKindIR::getter_isSafeFromProcessorPrivilegedMode (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_safeFromProcessorPrivilegedMode == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_calleeKindIR::getter_isServiceFromProcessorPrivilegedMode (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_serviceFromProcessorPrivilegedMode == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_calleeKindIR::description (C_String & ioString,
                                       const int32_t /* inIndentation */) const {
  ioString << "<enum @calleeKindIR: " << gEnumNameArrayFor_calleeKindIR [mEnum] ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_calleeKindIR::objectCompare (const GALGAS_calleeKindIR & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @calleeKindIR type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_calleeKindIR ("calleeKindIR",
                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_calleeKindIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_calleeKindIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_calleeKindIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_calleeKindIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_calleeKindIR GALGAS_calleeKindIR::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_calleeKindIR result ;
  const GALGAS_calleeKindIR * p = (const GALGAS_calleeKindIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_calleeKindIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("calleeKindIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Class for element of '@switchCaseList' list                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_switchCaseList : public cCollectionElement {
  public : GALGAS_switchCaseList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_switchCaseList (const GALGAS_lstringlist & in_mCaseIdentifiers,
                                              const GALGAS_instructionListAST & in_mCaseInstructionList
                                              COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_switchCaseList::cCollectionElement_switchCaseList (const GALGAS_lstringlist & in_mCaseIdentifiers,
                                                                      const GALGAS_instructionListAST & in_mCaseInstructionList
                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mCaseIdentifiers, in_mCaseInstructionList) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_switchCaseList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_switchCaseList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_switchCaseList (mObject.mAttribute_mCaseIdentifiers, mObject.mAttribute_mCaseInstructionList COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_switchCaseList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mCaseIdentifiers" ":" ;
  mObject.mAttribute_mCaseIdentifiers.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mCaseInstructionList" ":" ;
  mObject.mAttribute_mCaseInstructionList.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_switchCaseList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_switchCaseList * operand = (cCollectionElement_switchCaseList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_switchCaseList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseList::GALGAS_switchCaseList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseList::GALGAS_switchCaseList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseList GALGAS_switchCaseList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_switchCaseList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseList GALGAS_switchCaseList::constructor_listWithValue (const GALGAS_lstringlist & inOperand0,
                                                                        const GALGAS_instructionListAST & inOperand1
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_switchCaseList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_switchCaseList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                       const GALGAS_lstringlist & in_mCaseIdentifiers,
                                                       const GALGAS_instructionListAST & in_mCaseInstructionList
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement_switchCaseList * p = NULL ;
  macroMyNew (p, cCollectionElement_switchCaseList (in_mCaseIdentifiers,
                                                    in_mCaseInstructionList COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseList::addAssign_operation (const GALGAS_lstringlist & inOperand0,
                                                 const GALGAS_instructionListAST & inOperand1
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_switchCaseList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseList::setter_insertAtIndex (const GALGAS_lstringlist inOperand0,
                                                  const GALGAS_instructionListAST inOperand1,
                                                  const GALGAS_uint inInsertionIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_switchCaseList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseList::setter_removeAtIndex (GALGAS_lstringlist & outOperand0,
                                                  GALGAS_instructionListAST & outOperand1,
                                                  const GALGAS_uint inRemoveIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_switchCaseList * p = (cCollectionElement_switchCaseList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_switchCaseList) ;
      outOperand0 = p->mObject.mAttribute_mCaseIdentifiers ;
      outOperand1 = p->mObject.mAttribute_mCaseInstructionList ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseList::setter_popFirst (GALGAS_lstringlist & outOperand0,
                                             GALGAS_instructionListAST & outOperand1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_switchCaseList * p = (cCollectionElement_switchCaseList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_switchCaseList) ;
    outOperand0 = p->mObject.mAttribute_mCaseIdentifiers ;
    outOperand1 = p->mObject.mAttribute_mCaseInstructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseList::setter_popLast (GALGAS_lstringlist & outOperand0,
                                            GALGAS_instructionListAST & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_switchCaseList * p = (cCollectionElement_switchCaseList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_switchCaseList) ;
    outOperand0 = p->mObject.mAttribute_mCaseIdentifiers ;
    outOperand1 = p->mObject.mAttribute_mCaseInstructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseList::method_first (GALGAS_lstringlist & outOperand0,
                                          GALGAS_instructionListAST & outOperand1,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_switchCaseList * p = (cCollectionElement_switchCaseList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_switchCaseList) ;
    outOperand0 = p->mObject.mAttribute_mCaseIdentifiers ;
    outOperand1 = p->mObject.mAttribute_mCaseInstructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseList::method_last (GALGAS_lstringlist & outOperand0,
                                         GALGAS_instructionListAST & outOperand1,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_switchCaseList * p = (cCollectionElement_switchCaseList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_switchCaseList) ;
    outOperand0 = p->mObject.mAttribute_mCaseIdentifiers ;
    outOperand1 = p->mObject.mAttribute_mCaseInstructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseList GALGAS_switchCaseList::add_operation (const GALGAS_switchCaseList & inOperand,
                                                            C_Compiler * /* inCompiler */
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_switchCaseList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseList GALGAS_switchCaseList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_switchCaseList result = GALGAS_switchCaseList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseList GALGAS_switchCaseList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_switchCaseList result = GALGAS_switchCaseList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseList GALGAS_switchCaseList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_switchCaseList result = GALGAS_switchCaseList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseList::plusAssign_operation (const GALGAS_switchCaseList inOperand,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_switchCaseList::getter_mCaseIdentifiersAtIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_switchCaseList * p = (cCollectionElement_switchCaseList *) attributes.ptr () ;
  GALGAS_lstringlist result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_switchCaseList) ;
    result = p->mObject.mAttribute_mCaseIdentifiers ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_switchCaseList::getter_mCaseInstructionListAtIndex (const GALGAS_uint & inIndex,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_switchCaseList * p = (cCollectionElement_switchCaseList *) attributes.ptr () ;
  GALGAS_instructionListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_switchCaseList) ;
    result = p->mObject.mAttribute_mCaseInstructionList ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_switchCaseList::cEnumerator_switchCaseList (const GALGAS_switchCaseList & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseList_2D_element cEnumerator_switchCaseList::current (LOCATION_ARGS) const {
  const cCollectionElement_switchCaseList * p = (const cCollectionElement_switchCaseList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_switchCaseList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cEnumerator_switchCaseList::current_mCaseIdentifiers (LOCATION_ARGS) const {
  const cCollectionElement_switchCaseList * p = (const cCollectionElement_switchCaseList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_switchCaseList) ;
  return p->mObject.mAttribute_mCaseIdentifiers ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cEnumerator_switchCaseList::current_mCaseInstructionList (LOCATION_ARGS) const {
  const cCollectionElement_switchCaseList * p = (const cCollectionElement_switchCaseList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_switchCaseList) ;
  return p->mObject.mAttribute_mCaseInstructionList ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @switchCaseList type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_switchCaseList ("switchCaseList",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_switchCaseList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_switchCaseList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_switchCaseList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_switchCaseList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseList GALGAS_switchCaseList::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_switchCaseList result ;
  const GALGAS_switchCaseList * p = (const GALGAS_switchCaseList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_switchCaseList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("switchCaseList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_switchInstructionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_switchInstructionAST * p = (const cPtr_switchInstructionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_switchInstructionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mSwitchExpression.objectCompare (p->mAttribute_mSwitchExpression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mEndOf_5F_test_5F_expression.objectCompare (p->mAttribute_mEndOf_5F_test_5F_expression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mSwitchCaseList.objectCompare (p->mAttribute_mSwitchCaseList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mEndOf_5F_while_5F_instruction.objectCompare (p->mAttribute_mEndOf_5F_while_5F_instruction) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_switchInstructionAST::objectCompare (const GALGAS_switchInstructionAST & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchInstructionAST::GALGAS_switchInstructionAST (void) :
GALGAS_instructionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchInstructionAST::GALGAS_switchInstructionAST (const cPtr_switchInstructionAST * inSourcePtr) :
GALGAS_instructionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_switchInstructionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchInstructionAST GALGAS_switchInstructionAST::constructor_new (const GALGAS_expressionAST & inAttribute_mSwitchExpression,
                                                                          const GALGAS_location & inAttribute_mEndOf_5F_test_5F_expression,
                                                                          const GALGAS_switchCaseList & inAttribute_mSwitchCaseList,
                                                                          const GALGAS_location & inAttribute_mEndOf_5F_while_5F_instruction
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_switchInstructionAST result ;
  if (inAttribute_mSwitchExpression.isValid () && inAttribute_mEndOf_5F_test_5F_expression.isValid () && inAttribute_mSwitchCaseList.isValid () && inAttribute_mEndOf_5F_while_5F_instruction.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_switchInstructionAST (inAttribute_mSwitchExpression, inAttribute_mEndOf_5F_test_5F_expression, inAttribute_mSwitchCaseList, inAttribute_mEndOf_5F_while_5F_instruction COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_switchInstructionAST::getter_mSwitchExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_switchInstructionAST * p = (const cPtr_switchInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_switchInstructionAST) ;
    result = p->mAttribute_mSwitchExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_switchInstructionAST::getter_mSwitchExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSwitchExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_switchInstructionAST::getter_mEndOf_5F_test_5F_expression (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_switchInstructionAST * p = (const cPtr_switchInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_switchInstructionAST) ;
    result = p->mAttribute_mEndOf_5F_test_5F_expression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_switchInstructionAST::getter_mEndOf_5F_test_5F_expression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOf_5F_test_5F_expression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseList GALGAS_switchInstructionAST::getter_mSwitchCaseList (UNUSED_LOCATION_ARGS) const {
  GALGAS_switchCaseList result ;
  if (NULL != mObjectPtr) {
    const cPtr_switchInstructionAST * p = (const cPtr_switchInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_switchInstructionAST) ;
    result = p->mAttribute_mSwitchCaseList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseList cPtr_switchInstructionAST::getter_mSwitchCaseList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSwitchCaseList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_switchInstructionAST::getter_mEndOf_5F_while_5F_instruction (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_switchInstructionAST * p = (const cPtr_switchInstructionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_switchInstructionAST) ;
    result = p->mAttribute_mEndOf_5F_while_5F_instruction ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_switchInstructionAST::getter_mEndOf_5F_while_5F_instruction (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOf_5F_while_5F_instruction ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @switchInstructionAST class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_switchInstructionAST::cPtr_switchInstructionAST (const GALGAS_expressionAST & in_mSwitchExpression,
                                                      const GALGAS_location & in_mEndOf_5F_test_5F_expression,
                                                      const GALGAS_switchCaseList & in_mSwitchCaseList,
                                                      const GALGAS_location & in_mEndOf_5F_while_5F_instruction
                                                      COMMA_LOCATION_ARGS) :
cPtr_instructionAST (THERE),
mAttribute_mSwitchExpression (in_mSwitchExpression),
mAttribute_mEndOf_5F_test_5F_expression (in_mEndOf_5F_test_5F_expression),
mAttribute_mSwitchCaseList (in_mSwitchCaseList),
mAttribute_mEndOf_5F_while_5F_instruction (in_mEndOf_5F_while_5F_instruction) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_switchInstructionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_switchInstructionAST ;
}

void cPtr_switchInstructionAST::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@switchInstructionAST:" ;
  mAttribute_mSwitchExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mEndOf_5F_test_5F_expression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mSwitchCaseList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mEndOf_5F_while_5F_instruction.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_switchInstructionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_switchInstructionAST (mAttribute_mSwitchExpression, mAttribute_mEndOf_5F_test_5F_expression, mAttribute_mSwitchCaseList, mAttribute_mEndOf_5F_while_5F_instruction COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @switchInstructionAST type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_switchInstructionAST ("switchInstructionAST",
                                             & kTypeDescriptor_GALGAS_instructionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_switchInstructionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_switchInstructionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_switchInstructionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_switchInstructionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchInstructionAST GALGAS_switchInstructionAST::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_switchInstructionAST result ;
  const GALGAS_switchInstructionAST * p = (const GALGAS_switchInstructionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_switchInstructionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("switchInstructionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

