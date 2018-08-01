#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-declarations-10.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                    Overriding extension method '@truncateInstructionIR enterAccessibleEntities'                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_truncateInstructionIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * /* inObject */,
                                                                           GALGAS_accessibleEntities & /* ioArgument_ioAccessibleEntities */,
                                                                           GALGAS_uint & /* ioArgument_ioMaxBranchOfOnInstructions */,
                                                                           C_Compiler * /* inCompiler */
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_truncateInstructionIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_truncateInstructionIR.mSlotID,
                                                extensionMethod_truncateInstructionIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_truncateInstructionIR_enterAccessibleEntities (defineExtensionMethod_truncateInstructionIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      Overriding extension method '@truncateInstructionIR llvmInstructionCode'                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_truncateInstructionIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                       GALGAS_string & ioArgument_ioLLVMcode,
                                                                       const GALGAS_generationContext /* constinArgument_inGenerationContext */,
                                                                       GALGAS_generationAdds & /* ioArgument_ioGenerationAdds */,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_truncateInstructionIR * object = (const cPtr_truncateInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_truncateInstructionIR) ;
  GALGAS_string var_operandType_7083 = extensionGetter_llvmTypeName (object->mProperty_mOperand, inCompiler COMMA_SOURCE_FILE ("expression-truncate.galgas", 163)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ").add_operation (extensionGetter_llvmName (object->mProperty_mTarget, inCompiler COMMA_SOURCE_FILE ("expression-truncate.galgas", 164)), inCompiler COMMA_SOURCE_FILE ("expression-truncate.galgas", 164)).add_operation (GALGAS_string (" = trunc "), inCompiler COMMA_SOURCE_FILE ("expression-truncate.galgas", 164)).add_operation (var_operandType_7083, inCompiler COMMA_SOURCE_FILE ("expression-truncate.galgas", 164)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("expression-truncate.galgas", 164)).add_operation (extensionGetter_llvmName (object->mProperty_mOperand, inCompiler COMMA_SOURCE_FILE ("expression-truncate.galgas", 164)), inCompiler COMMA_SOURCE_FILE ("expression-truncate.galgas", 164)).add_operation (GALGAS_string (" to "), inCompiler COMMA_SOURCE_FILE ("expression-truncate.galgas", 164)).add_operation (extensionGetter_llvmTypeName (object->mProperty_mTarget, inCompiler COMMA_SOURCE_FILE ("expression-truncate.galgas", 165)), inCompiler COMMA_SOURCE_FILE ("expression-truncate.galgas", 165)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("expression-truncate.galgas", 165)), inCompiler  COMMA_SOURCE_FILE ("expression-truncate.galgas", 164)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_truncateInstructionIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_truncateInstructionIR.mSlotID,
                                            extensionMethod_truncateInstructionIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_truncateInstructionIR_llvmInstructionCode (defineExtensionMethod_truncateInstructionIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//           Overriding extension method '@addressofControlRegisterAST addDependenceEdgeForStaticExpression'           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_addressofControlRegisterAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * /* inObject */,
                                                                                              const GALGAS_lstring /* constinArgument_inConstantName */,
                                                                                              GALGAS_semanticTypePrecedenceGraph & /* ioArgument_ioGraph */,
                                                                                              C_Compiler * /* inCompiler */
                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_addressofControlRegisterAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_addressofControlRegisterAST.mSlotID,
                                                             extensionMethod_addressofControlRegisterAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_addressofControlRegisterAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_addressofControlRegisterAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//           Overriding extension method '@addressofControlRegisterAST noteExpressionTypesInPrecedenceGraph'           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_addressofControlRegisterAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                              GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_addressofControlRegisterAST * object = (const cPtr_addressofControlRegisterAST *) inObject ;
  macroValidSharedObject (object, cPtr_addressofControlRegisterAST) ;
  extensionMethod_noteExpressionTypesInPrecedenceGraph (object->mProperty_mControlRegisterLValue, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-addressof-control-register.galgas", 46)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_addressofControlRegisterAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_addressofControlRegisterAST.mSlotID,
                                                             extensionMethod_addressofControlRegisterAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_addressofControlRegisterAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_addressofControlRegisterAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                    Overriding extension method '@addressofControlRegisterAST analyzeExpression'                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_addressofControlRegisterAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                           const GALGAS_PLMType constinArgument_inSelfType,
                                                                           const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                           const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                           const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                                                           const GALGAS_semanticContext constinArgument_inContext,
                                                                           const GALGAS_mode constinArgument_inMode,
                                                                           GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                           GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                           GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                           GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                           GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                           GALGAS_objectIR & outArgument_outResult,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_addressofControlRegisterAST * object = (const cPtr_addressofControlRegisterAST *) inObject ;
  macroValidSharedObject (object, cPtr_addressofControlRegisterAST) ;
  GALGAS_string var_llvmRegisterAddressName_4047 ;
  GALGAS_PLMType joker_3949 ; // Joker input parameter
  GALGAS_uint joker_3973 ; // Joker input parameter
  GALGAS_sliceMap joker_3989 ; // Joker input parameter
  extensionMethod_controlRegisterLValueSemanticAnalysis (object->mProperty_mControlRegisterLValue, GALGAS_bool (false), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, joker_3949, joker_3973, joker_3989, var_llvmRegisterAddressName_4047, inCompiler COMMA_SOURCE_FILE ("expression-addressof-control-register.galgas", 67)) ;
  GALGAS_unifiedTypeMap_2D_proxy var_resultTypeProxy_4102 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), GALGAS_string ("uint").add_operation (constinArgument_inContext.getter_mTargetParameters (HERE).getter_mPointerSize (HERE).getter_string (SOURCE_FILE ("expression-addressof-control-register.galgas", 87)), inCompiler COMMA_SOURCE_FILE ("expression-addressof-control-register.galgas", 87)).getter_nowhere (SOURCE_FILE ("expression-addressof-control-register.galgas", 87)), inCompiler  COMMA_SOURCE_FILE ("expression-addressof-control-register.galgas", 85)) ;
  outArgument_outResult = GALGAS_objectIR::constructor_llvmValue (var_resultTypeProxy_4102.getter_type (inCompiler COMMA_SOURCE_FILE ("expression-addressof-control-register.galgas", 89)), var_llvmRegisterAddressName_4047  COMMA_SOURCE_FILE ("expression-addressof-control-register.galgas", 89)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_addressofControlRegisterAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_addressofControlRegisterAST.mSlotID,
                                          extensionMethod_addressofControlRegisterAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_addressofControlRegisterAST_analyzeExpression (defineExtensionMethod_addressofControlRegisterAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//             Overriding extension method '@addressofExpressionAST addDependenceEdgeForStaticExpression'              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_addressofExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * /* inObject */,
                                                                                         const GALGAS_lstring /* constinArgument_inConstantName */,
                                                                                         GALGAS_semanticTypePrecedenceGraph & /* ioArgument_ioGraph */,
                                                                                         C_Compiler * /* inCompiler */
                                                                                         COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_addressofExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_addressofExpressionAST.mSlotID,
                                                             extensionMethod_addressofExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_addressofExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_addressofExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//             Overriding extension method '@addressofExpressionAST noteExpressionTypesInPrecedenceGraph'              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_addressofExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                         GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_addressofExpressionAST * object = (const cPtr_addressofExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_addressofExpressionAST) ;
  extensionMethod_noteInstructionTypesInPrecedenceGraph (object->mProperty_mLValue, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 46)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_addressofExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_addressofExpressionAST.mSlotID,
                                                             extensionMethod_addressofExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_addressofExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_addressofExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                       Overriding extension method '@addressofExpressionAST analyzeExpression'                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_addressofExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                      const GALGAS_PLMType constinArgument_inSelfType,
                                                                      const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                      const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                      const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                                                      const GALGAS_semanticContext constinArgument_inContext,
                                                                      const GALGAS_mode constinArgument_inCurrentMode,
                                                                      GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                      GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                      GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                      GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                      GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                      GALGAS_objectIR & outArgument_outResult,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_addressofExpressionAST * object = (const cPtr_addressofExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_addressofExpressionAST) ;
  const enumGalgasBool test_0 = constinArgument_inRoutineAttributes.getter_guard (SOURCE_FILE ("expression-addressof-regular-var.galgas", 67)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mLValue.getter_mIdentifier (HERE).getter_location (SOURCE_FILE ("expression-addressof-regular-var.galgas", 68)), GALGAS_string ("addressof () cannot be used in guard"), fixItArray1  COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 68)) ;
    outArgument_outResult.drop () ; // Release error dropped variable
  }else if (kBoolFalse == test_0) {
    GALGAS_LValueRepresentation var_lvalueIR_4014 ;
    extensionMethod_analyzeLValue (object->mProperty_mLValue, constinArgument_inSelfType, GALGAS_bool (true), constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_lvalueIR_4014, inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 71)) ;
    GALGAS_unifiedTypeMap_2D_proxy var_resultTypeProxy_4044 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), GALGAS_string ("uint").add_operation (constinArgument_inContext.getter_mTargetParameters (HERE).getter_mPointerSize (HERE).getter_string (SOURCE_FILE ("expression-addressof-regular-var.galgas", 87)), inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 87)).getter_nowhere (SOURCE_FILE ("expression-addressof-regular-var.galgas", 87)), inCompiler  COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 85)) ;
    GALGAS_PLMType var_resultType_4207 = var_resultTypeProxy_4044.getter_type (inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 89)) ;
    {
    routine_getNewTempValue (var_resultType_4207, ioArgument_ioTemporaries, outArgument_outResult, inCompiler  COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 90)) ;
    }
    ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_addressofInstructionIR::constructor_new (outArgument_outResult, var_lvalueIR_4014  COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 91))  COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 91)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_addressofExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_addressofExpressionAST.mSlotID,
                                          extensionMethod_addressofExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_addressofExpressionAST_analyzeExpression (defineExtensionMethod_addressofExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      Overriding extension method '@addressofInstructionIR llvmInstructionCode'                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_addressofInstructionIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                        GALGAS_string & ioArgument_ioLLVMcode,
                                                                        const GALGAS_generationContext /* constinArgument_inGenerationContext */,
                                                                        GALGAS_generationAdds & /* ioArgument_ioGenerationAdds */,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_addressofInstructionIR * object = (const cPtr_addressofInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_addressofInstructionIR) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ").add_operation (extensionGetter_llvmName (object->mProperty_mTarget, inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 114)), inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 114)).add_operation (GALGAS_string (" = ptrtoint "), inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 114)).add_operation (extensionGetter_llvmTypeName (object->mProperty_mLValue.getter_type (HERE), inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 114)), inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 114)).add_operation (GALGAS_string ("* "), inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 114)).add_operation (object->mProperty_mLValue.getter_llvmName (HERE), inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 114)).add_operation (GALGAS_string (" to "), inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 114)).add_operation (extensionGetter_llvmTypeName (object->mProperty_mTarget, inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 115)), inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 115)).add_operation (GALGAS_string (" ; addressof\n"), inCompiler COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 115)), inCompiler  COMMA_SOURCE_FILE ("expression-addressof-regular-var.galgas", 114)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_addressofInstructionIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_addressofInstructionIR.mSlotID,
                                            extensionMethod_addressofInstructionIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_addressofInstructionIR_llvmInstructionCode (defineExtensionMethod_addressofInstructionIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                    Overriding extension method '@addressofInstructionIR enterAccessibleEntities'                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_addressofInstructionIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * /* inObject */,
                                                                            GALGAS_accessibleEntities & /* ioArgument_ioAccessibleEntities */,
                                                                            GALGAS_uint & /* ioArgument_ioMaxBranchOfOnInstructions */,
                                                                            C_Compiler * /* inCompiler */
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_addressofInstructionIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_addressofInstructionIR.mSlotID,
                                                extensionMethod_addressofInstructionIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_addressofInstructionIR_enterAccessibleEntities (defineExtensionMethod_addressofInstructionIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//               Overriding extension method '@sizeofExpressionAST addDependenceEdgeForStaticExpression'               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_sizeofExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * /* inObject */,
                                                                                      const GALGAS_lstring /* constinArgument_inConstantName */,
                                                                                      GALGAS_semanticTypePrecedenceGraph & /* ioArgument_ioGraph */,
                                                                                      C_Compiler * /* inCompiler */
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_sizeofExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_sizeofExpressionAST.mSlotID,
                                                             extensionMethod_sizeofExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_sizeofExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_sizeofExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                  Overriding extension method '@sizeofTypeAST addDependenceEdgeForStaticExpression'                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_sizeofTypeAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * /* inObject */,
                                                                                const GALGAS_lstring /* constinArgument_inConstantName */,
                                                                                GALGAS_semanticTypePrecedenceGraph & /* ioArgument_ioGraph */,
                                                                                C_Compiler * /* inCompiler */
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_sizeofTypeAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_sizeofTypeAST.mSlotID,
                                                             extensionMethod_sizeofTypeAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_sizeofTypeAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_sizeofTypeAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//               Overriding extension method '@sizeofExpressionAST noteExpressionTypesInPrecedenceGraph'               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_sizeofExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * /* inObject */,
                                                                                      GALGAS_semanticTypePrecedenceGraph & /* ioArgument_ioGraph */,
                                                                                      C_Compiler * /* inCompiler */
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_sizeofExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_sizeofExpressionAST.mSlotID,
                                                             extensionMethod_sizeofExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_sizeofExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_sizeofExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                  Overriding extension method '@sizeofTypeAST noteExpressionTypesInPrecedenceGraph'                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_sizeofTypeAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sizeofTypeAST * object = (const cPtr_sizeofTypeAST *) inObject ;
  macroValidSharedObject (object, cPtr_sizeofTypeAST) ;
  GALGAS_lstring var_typeName_3306 = function_llvmTypeNameFromPLMname (object->mProperty_mTypeName, inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 77)) ;
  {
  ioArgument_ioGraph.setter_noteNode (var_typeName_3306 COMMA_SOURCE_FILE ("expression-sizeof.galgas", 78)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_sizeofTypeAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_sizeofTypeAST.mSlotID,
                                                             extensionMethod_sizeofTypeAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_sizeofTypeAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_sizeofTypeAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                        Overriding extension method '@sizeofExpressionAST analyzeExpression'                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_sizeofExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                   const GALGAS_PLMType constinArgument_inSelfType,
                                                                   const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                   const GALGAS_lstring /* constinArgument_inCallerNameForInvocationGraph */,
                                                                   const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                                                   const GALGAS_semanticContext constinArgument_inContext,
                                                                   const GALGAS_mode /* constinArgument_inCurrentMode */,
                                                                   GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                   GALGAS_staticEntityMap & /* ioArgument_ioStaticEntityMap */,
                                                                   GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                   GALGAS_allocaList & /* ioArgument_ioAllocaList */,
                                                                   GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                   GALGAS_objectIR & outArgument_outResult,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sizeofExpressionAST * object = (const cPtr_sizeofExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_sizeofExpressionAST) ;
  const enumGalgasBool test_0 = constinArgument_inRoutineAttributes.getter_guard (SOURCE_FILE ("expression-sizeof.galgas", 101)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mLValue.getter_mIdentifier (HERE).getter_location (SOURCE_FILE ("expression-sizeof.galgas", 102)), GALGAS_string ("sizeof () cannot be used in guard"), fixItArray1  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 102)) ;
    outArgument_outResult.drop () ; // Release error dropped variable
  }else if (kBoolFalse == test_0) {
    GALGAS_PLMType var_type_4817 ;
    extensionMethod_searchValuedObjectType (ioArgument_ioUniversalMap, constinArgument_inSelfType, object->mProperty_mLValue, var_type_4817, inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 105)) ;
    GALGAS_unifiedTypeMap_2D_proxy var_resultTypeProxy_4842 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), GALGAS_string ("uint").add_operation (constinArgument_inContext.getter_mTargetParameters (HERE).getter_mPointerSize (HERE).getter_string (SOURCE_FILE ("expression-sizeof.galgas", 108)), inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 108)).getter_nowhere (SOURCE_FILE ("expression-sizeof.galgas", 108)), inCompiler  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 106)) ;
    GALGAS_PLMType var_resultType_4996 = var_resultTypeProxy_4842.getter_type (inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 110)) ;
    {
    routine_getNewTempValue (var_resultType_4996, ioArgument_ioTemporaries, outArgument_outResult, inCompiler  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 111)) ;
    }
    ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_sizeofInstructionIR::constructor_new (outArgument_outResult, var_type_4817  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 112))  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 112)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_sizeofExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_sizeofExpressionAST.mSlotID,
                                          extensionMethod_sizeofExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_sizeofExpressionAST_analyzeExpression (defineExtensionMethod_sizeofExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                           Overriding extension method '@sizeofTypeAST analyzeExpression'                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_sizeofTypeAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                             const GALGAS_PLMType /* constinArgument_inSelfType */,
                                                             const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                             const GALGAS_lstring /* constinArgument_inCallerNameForInvocationGraph */,
                                                             const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                                             const GALGAS_semanticContext constinArgument_inContext,
                                                             const GALGAS_mode /* constinArgument_inCurrentMode */,
                                                             GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                             GALGAS_staticEntityMap & /* ioArgument_ioStaticEntityMap */,
                                                             GALGAS_universalValuedObjectMap & /* ioArgument_ioUniversalMap */,
                                                             GALGAS_allocaList & /* ioArgument_ioAllocaList */,
                                                             GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                             GALGAS_objectIR & outArgument_outResult,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sizeofTypeAST * object = (const cPtr_sizeofTypeAST *) inObject ;
  macroValidSharedObject (object, cPtr_sizeofTypeAST) ;
  const enumGalgasBool test_0 = constinArgument_inRoutineAttributes.getter_guard (SOURCE_FILE ("expression-sizeof.galgas", 137)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("expression-sizeof.galgas", 138)), GALGAS_string ("sizeof () cannot be used in guard"), fixItArray1  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 138)) ;
    outArgument_outResult.drop () ; // Release error dropped variable
  }else if (kBoolFalse == test_0) {
    GALGAS_PLMType var_type_6284 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), object->mProperty_mTypeName, inCompiler  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 140)).getter_type (inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 140)) ;
    GALGAS_unifiedTypeMap_2D_proxy var_resultTypeProxy_6382 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), GALGAS_string ("uint").add_operation (constinArgument_inContext.getter_mTargetParameters (HERE).getter_mPointerSize (HERE).getter_string (SOURCE_FILE ("expression-sizeof.galgas", 143)), inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 143)).getter_nowhere (SOURCE_FILE ("expression-sizeof.galgas", 143)), inCompiler  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 141)) ;
    GALGAS_PLMType var_resultType_6536 = var_resultTypeProxy_6382.getter_type (inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 145)) ;
    {
    routine_getNewTempValue (var_resultType_6536, ioArgument_ioTemporaries, outArgument_outResult, inCompiler  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 146)) ;
    }
    ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_sizeofInstructionIR::constructor_new (outArgument_outResult, var_type_6284  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 147))  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 147)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_sizeofTypeAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_sizeofTypeAST.mSlotID,
                                          extensionMethod_sizeofTypeAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_sizeofTypeAST_analyzeExpression (defineExtensionMethod_sizeofTypeAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     Overriding extension method '@sizeofInstructionIR enterAccessibleEntities'                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_sizeofInstructionIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * /* inObject */,
                                                                         GALGAS_accessibleEntities & /* ioArgument_ioAccessibleEntities */,
                                                                         GALGAS_uint & /* ioArgument_ioMaxBranchOfOnInstructions */,
                                                                         C_Compiler * /* inCompiler */
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_sizeofInstructionIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_sizeofInstructionIR.mSlotID,
                                                extensionMethod_sizeofInstructionIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_sizeofInstructionIR_enterAccessibleEntities (defineExtensionMethod_sizeofInstructionIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                       Overriding extension method '@sizeofInstructionIR llvmInstructionCode'                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_sizeofInstructionIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                     GALGAS_string & ioArgument_ioLLVMcode,
                                                                     const GALGAS_generationContext /* constinArgument_inGenerationContext */,
                                                                     GALGAS_generationAdds & /* ioArgument_ioGenerationAdds */,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sizeofInstructionIR * object = (const cPtr_sizeofInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_sizeofInstructionIR) ;
  GALGAS_string var_typeName_7920 = extensionGetter_llvmTypeName (object->mProperty_mSourceType, inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 177)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ").add_operation (extensionGetter_llvmName (object->mProperty_mTarget, inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 178)), inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 178)).add_operation (GALGAS_string (".asPtr = getelementptr inbounds "), inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 178)).add_operation (var_typeName_7920, inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 178)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 178)).add_operation (var_typeName_7920, inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 178)).add_operation (GALGAS_string ("* null, i32 1\n"), inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 178)), inCompiler  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 178)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ").add_operation (extensionGetter_llvmName (object->mProperty_mTarget, inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 179)), inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 179)).add_operation (GALGAS_string (" = ptrtoint "), inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 179)).add_operation (var_typeName_7920, inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 179)).add_operation (GALGAS_string ("* "), inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 179)).add_operation (extensionGetter_llvmName (object->mProperty_mTarget, inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 179)), inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 179)).add_operation (GALGAS_string (".asPtr to i32\n"), inCompiler COMMA_SOURCE_FILE ("expression-sizeof.galgas", 179)), inCompiler  COMMA_SOURCE_FILE ("expression-sizeof.galgas", 179)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_sizeofInstructionIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_sizeofInstructionIR.mSlotID,
                                            extensionMethod_sizeofInstructionIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_sizeofInstructionIR_llvmInstructionCode (defineExtensionMethod_sizeofInstructionIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//               Overriding extension method '@constructorCallAST addDependenceEdgeForStaticExpression'                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_constructorCallAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * inObject,
                                                                                     const GALGAS_lstring constinArgument_inConstantName,
                                                                                     GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_constructorCallAST * object = (const cPtr_constructorCallAST *) inObject ;
  macroValidSharedObject (object, cPtr_constructorCallAST) ;
  GALGAS_lstring var_typeName_2123 = function_llvmTypeNameFromPLMname (object->mProperty_mTypeName, inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 49)) ;
  {
  ioArgument_ioGraph.setter_addEdge (constinArgument_inConstantName, var_typeName_2123 COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 50)) ;
  }
  cEnumerator_functionCallEffectiveParameterListAST enumerator_2240 (object->mProperty_mParameterList, kENUMERATION_UP) ;
  while (enumerator_2240.hasCurrentObject ()) {
    callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) enumerator_2240.current_mExpression (HERE).ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 53)) ;
    enumerator_2240.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_constructorCallAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_constructorCallAST.mSlotID,
                                                             extensionMethod_constructorCallAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_constructorCallAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_constructorCallAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//               Overriding extension method '@constructorCallAST noteExpressionTypesInPrecedenceGraph'                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_constructorCallAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                     GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_constructorCallAST * object = (const cPtr_constructorCallAST *) inObject ;
  macroValidSharedObject (object, cPtr_constructorCallAST) ;
  GALGAS_lstring var_typeName_2826 = function_llvmTypeNameFromPLMname (object->mProperty_mTypeName, inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 62)) ;
  {
  ioArgument_ioGraph.setter_noteNode (var_typeName_2826 COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 63)) ;
  }
  cEnumerator_functionCallEffectiveParameterListAST enumerator_2925 (object->mProperty_mParameterList, kENUMERATION_UP) ;
  while (enumerator_2925.hasCurrentObject ()) {
    callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) enumerator_2925.current_mExpression (HERE).ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 65)) ;
    enumerator_2925.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_constructorCallAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_constructorCallAST.mSlotID,
                                                             extensionMethod_constructorCallAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_constructorCallAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_constructorCallAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                         Overriding extension method '@constructorCallAST analyzeExpression'                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_constructorCallAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                  const GALGAS_PLMType constinArgument_inSelfType,
                                                                  const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                  const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                  const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                                                  const GALGAS_semanticContext constinArgument_inContext,
                                                                  const GALGAS_mode constinArgument_inCurrentMode,
                                                                  GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                  GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                  GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                  GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                  GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                  GALGAS_objectIR & outArgument_outResult,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_constructorCallAST * object = (const cPtr_constructorCallAST *) inObject ;
  macroValidSharedObject (object, cPtr_constructorCallAST) ;
  GALGAS_string var_constructorKey_4092 = GALGAS_string ("(") ;
  cEnumerator_functionCallEffectiveParameterListAST enumerator_4135 (object->mProperty_mParameterList, kENUMERATION_UP) ;
  while (enumerator_4135.hasCurrentObject ()) {
    var_constructorKey_4092.plusAssign_operation(GALGAS_string ("!").add_operation (enumerator_4135.current_mSelector (HERE).getter_string (SOURCE_FILE ("expression-constructor-call.galgas", 90)), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 90)), inCompiler  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 90)) ;
    enumerator_4135.gotoNextObject () ;
  }
  var_constructorKey_4092.plusAssign_operation(GALGAS_string (")"), inCompiler  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 92)) ;
  GALGAS_PLMType var_resultType_4272 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), object->mProperty_mTypeName, inCompiler  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 94)).getter_type (inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 94)) ;
  GALGAS_constructorMap var_constructorMap_4367 = var_resultType_4272.getter_constructorMap (HERE) ;
  GALGAS_constructorSignature var_constructorSignature_4489 ;
  GALGAS_constructorValue var_initValue_4504 ;
  var_constructorMap_4367.method_searchKey (GALGAS_lstring::constructor_new (var_constructorKey_4092, object->mProperty_mErrorLocation  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 96)), var_constructorSignature_4489, var_initValue_4504, inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 96)) ;
  switch (var_initValue_4504.enumValue ()) {
  case GALGAS_constructorValue::kNotBuilt:
    break ;
  case GALGAS_constructorValue::kEnum_arrayValue:
    {
      const cEnumAssociatedValues_constructorValue_arrayValue * extractPtr_7754 = (const cEnumAssociatedValues_constructorValue_arrayValue *) (var_initValue_4504.unsafePointer ()) ;
      const GALGAS_PLMType extractedValue_elementType = extractPtr_7754->mAssociatedValue0 ;
      const GALGAS_uint extractedValue_size = extractPtr_7754->mAssociatedValue1 ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, var_constructorKey_4092.objectCompare (GALGAS_string ("(!repeated)"))).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_expressionAST var_expression_4652 = object->mProperty_mParameterList.getter_mExpressionAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 101)) ;
        GALGAS_objectIR var_expressionResult_5214 ;
        callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) var_expression_4652.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, extractedValue_elementType, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_expressionResult_5214, inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 102)) ;
        GALGAS_objectIR var_result_5239 = function_checkAssignmentCompatibility (var_expressionResult_5214, extractedValue_elementType, object->mProperty_mParameterList.getter_mSelectorAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 119)).getter_location (HERE), GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 116)) ;
        const enumGalgasBool test_1 = extensionGetter_isStatic (var_result_5239, inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 122)).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_uint var_idx_5505 = ioArgument_ioStaticEntityMap.getter_mGlobalStructuredConstantList (HERE).getter_length (SOURCE_FILE ("expression-constructor-call.galgas", 123)) ;
          outArgument_outResult = GALGAS_objectIR::constructor_llvmArrayRepeatedStaticValue (var_resultType_4272, extractedValue_size, var_result_5239, var_idx_5505  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 124)) ;
          GALGAS_operandIRList var_operandIRList_5712 = GALGAS_operandIRList::constructor_emptyList (SOURCE_FILE ("expression-constructor-call.galgas", 125)) ;
          cEnumerator_range enumerator_5745 (GALGAS_range (GALGAS_uint ((uint32_t) 0U), extractedValue_size.substract_operation (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 126))), kENUMERATION_UP) ;
          while (enumerator_5745.hasCurrentObject ()) {
            var_operandIRList_5712.addAssign_operation (var_result_5239  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 127)) ;
            enumerator_5745.gotoNextObject () ;
          }
          ioArgument_ioStaticEntityMap.mProperty_mGlobalStructuredConstantList.addAssign_operation (var_resultType_4272, var_operandIRList_5712  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 129)) ;
        }else if (kBoolFalse == test_1) {
          outArgument_outResult = GALGAS_objectIR::constructor_llvmArrayRepeatedDynamicValue (var_resultType_4272, extractedValue_size, var_result_5239  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 131)) ;
        }
      }else if (kBoolFalse == test_0) {
        GALGAS_string var_individualConstructor_6043 = GALGAS_string ("(") ;
        cEnumerator_range enumerator_6075 (GALGAS_range (GALGAS_uint ((uint32_t) 0U), extractedValue_size.substract_operation (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 135))), kENUMERATION_UP) ;
        while (enumerator_6075.hasCurrentObject ()) {
          var_individualConstructor_6043.plusAssign_operation(GALGAS_string ("!"), inCompiler  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 136)) ;
          enumerator_6075.gotoNextObject () ;
        }
        var_individualConstructor_6043.plusAssign_operation(GALGAS_string (")"), inCompiler  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 138)) ;
        const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_constructorKey_4092.objectCompare (var_individualConstructor_6043)).boolEnum () ;
        if (kBoolTrue == test_2) {
          GALGAS_operandIRList var_operandIRList_6251 = GALGAS_operandIRList::constructor_emptyList (SOURCE_FILE ("expression-constructor-call.galgas", 140)) ;
          GALGAS_bool var_resultIsStatic_6283 = GALGAS_bool (true) ;
          cEnumerator_functionCallEffectiveParameterListAST enumerator_6323 (object->mProperty_mParameterList, kENUMERATION_UP) ;
          while (enumerator_6323.hasCurrentObject ()) {
            GALGAS_objectIR var_expressionResult_6900 ;
            callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) enumerator_6323.current_mExpression (HERE).ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, extractedValue_elementType, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_expressionResult_6900, inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 143)) ;
            GALGAS_objectIR var_result_6933 = function_checkAssignmentCompatibility (var_expressionResult_6900, extractedValue_elementType, enumerator_6323.current_mSelector (HERE).getter_location (HERE), GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 157)) ;
            var_operandIRList_6251.addAssign_operation (var_result_6933  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 163)) ;
            GALGAS_bool test_3 = var_resultIsStatic_6283 ;
            if (kBoolTrue == test_3.boolEnum ()) {
              test_3 = extensionGetter_isStatic (var_result_6933, inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 164)) ;
            }
            var_resultIsStatic_6283 = test_3 ;
            enumerator_6323.gotoNextObject () ;
          }
          const enumGalgasBool test_4 = var_resultIsStatic_6283.boolEnum () ;
          if (kBoolTrue == test_4) {
            GALGAS_uint var_idx_7303 = ioArgument_ioStaticEntityMap.getter_mGlobalStructuredConstantList (HERE).getter_length (SOURCE_FILE ("expression-constructor-call.galgas", 167)) ;
            outArgument_outResult = GALGAS_objectIR::constructor_llvmArrayStaticValues (var_resultType_4272, var_operandIRList_6251, var_idx_7303  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 168)) ;
            ioArgument_ioStaticEntityMap.mProperty_mGlobalStructuredConstantList.addAssign_operation (var_resultType_4272, var_operandIRList_6251  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 169)) ;
          }else if (kBoolFalse == test_4) {
            outArgument_outResult = GALGAS_objectIR::constructor_llvmArrayDynamicValues (var_resultType_4272, var_operandIRList_6251  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 171)) ;
          }
        }else if (kBoolFalse == test_2) {
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (object->mProperty_mErrorLocation, GALGAS_string ("invalid constructor"), fixItArray5  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 174)) ;
          outArgument_outResult.drop () ; // Release error dropped variable
        }
      }
    }
    break ;
  case GALGAS_constructorValue::kEnum_null:
    {
      outArgument_outResult = GALGAS_objectIR::constructor_null (var_resultType_4272  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 178)) ;
    }
    break ;
  case GALGAS_constructorValue::kEnum_simple:
    {
      const cEnumAssociatedValues_constructorValue_simple * extractPtr_8082 = (const cEnumAssociatedValues_constructorValue_simple *) (var_initValue_4504.unsafePointer ()) ;
      const GALGAS_bigint extractedValue_value = extractPtr_8082->mAssociatedValue0 ;
      const enumGalgasBool test_6 = GALGAS_bool (kIsNotEqual, object->mProperty_mParameterList.getter_length (SOURCE_FILE ("expression-constructor-call.galgas", 180)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_6) {
        TC_Array <C_FixItDescription> fixItArray7 ;
        inCompiler->emitSemanticError (object->mProperty_mErrorLocation, GALGAS_string ("$").add_operation (var_resultType_4272.getter_plmTypeDescriptionName (HERE), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 181)).add_operation (GALGAS_string (" constructor should have no parameter"), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 181)), fixItArray7  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 181)) ;
        outArgument_outResult.drop () ; // Release error dropped variable
      }else if (kBoolFalse == test_6) {
        outArgument_outResult = GALGAS_objectIR::constructor_literalInteger (var_resultType_4272, extractedValue_value  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 183)) ;
      }
    }
    break ;
  case GALGAS_constructorValue::kEnum_structure:
    {
      const cEnumAssociatedValues_constructorValue_structure * extractPtr_9797 = (const cEnumAssociatedValues_constructorValue_structure *) (var_initValue_4504.unsafePointer ()) ;
      const GALGAS_sortedOperandIRList extractedValue_sortedOperandList = extractPtr_9797->mAssociatedValue0 ;
      GALGAS_sortedOperandIRList var_sortedOperandIRList_8149 = extractedValue_sortedOperandList ;
      const enumGalgasBool test_8 = GALGAS_bool (kIsNotEqual, object->mProperty_mParameterList.getter_length (SOURCE_FILE ("expression-constructor-call.galgas", 187)).objectCompare (var_constructorSignature_4489.getter_length (SOURCE_FILE ("expression-constructor-call.galgas", 187)))).boolEnum () ;
      if (kBoolTrue == test_8) {
        GALGAS_string temp_9 ;
        const enumGalgasBool test_10 = GALGAS_bool (kIsStrictSup, var_constructorSignature_4489.getter_length (SOURCE_FILE ("expression-constructor-call.galgas", 189)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
        if (kBoolTrue == test_10) {
          temp_9 = GALGAS_string ("s") ;
        }else if (kBoolFalse == test_10) {
          temp_9 = GALGAS_string::makeEmptyString () ;
        }
        TC_Array <C_FixItDescription> fixItArray11 ;
        inCompiler->emitSemanticError (object->mProperty_mErrorLocation, GALGAS_string ("this constructor call should name ").add_operation (var_constructorSignature_4489.getter_length (SOURCE_FILE ("expression-constructor-call.galgas", 188)).getter_string (SOURCE_FILE ("expression-constructor-call.galgas", 188)), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 188)).add_operation (GALGAS_string (" parameter"), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 188)).add_operation (temp_9, inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 188)).add_operation (GALGAS_string (" instead of "), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 189)).add_operation (object->mProperty_mParameterList.getter_length (SOURCE_FILE ("expression-constructor-call.galgas", 190)).getter_string (SOURCE_FILE ("expression-constructor-call.galgas", 190)), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 190)), fixItArray11  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 188)) ;
        outArgument_outResult.drop () ; // Release error dropped variable
      }else if (kBoolFalse == test_8) {
        cEnumerator_constructorSignature enumerator_8542 (var_constructorSignature_4489, kENUMERATION_UP) ;
        cEnumerator_functionCallEffectiveParameterListAST enumerator_8575 (object->mProperty_mParameterList, kENUMERATION_UP) ;
        while (enumerator_8542.hasCurrentObject () && enumerator_8575.hasCurrentObject ()) {
          const enumGalgasBool test_12 = GALGAS_bool (kIsNotEqual, enumerator_8575.current_mSelector (HERE).getter_string (HERE).objectCompare (enumerator_8542.current_mSelector (HERE))).boolEnum () ;
          if (kBoolTrue == test_12) {
            TC_Array <C_FixItDescription> fixItArray13 ;
            inCompiler->emitSemanticError (enumerator_8575.current_mSelector (HERE).getter_location (SOURCE_FILE ("expression-constructor-call.galgas", 195)), GALGAS_string ("the selector should be '!").add_operation (enumerator_8542.current_mSelector (HERE), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 195)).add_operation (GALGAS_string (":'"), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 195)), fixItArray13  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 195)) ;
          }
          GALGAS_objectIR var_expressionResult_9305 ;
          callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) enumerator_8575.current_mExpression (HERE).ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, enumerator_8542.current_mType (HERE), constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_expressionResult_9305, inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 197)) ;
          GALGAS_objectIR var_result_9334 = function_checkAssignmentCompatibility (var_expressionResult_9305, enumerator_8542.current_mType (HERE), enumerator_8575.current_mSelector (HERE).getter_location (HERE), GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 211)) ;
          {
          extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_result_9334, inCompiler COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 217)) ;
          }
          var_sortedOperandIRList_8149.addAssign_operation (var_result_9334, enumerator_8542.current_mFieldIndex (HERE)  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 218)) ;
          enumerator_8542.gotoNextObject () ;
          enumerator_8575.gotoNextObject () ;
        }
        outArgument_outResult = GALGAS_objectIR::constructor_llvmStructureValue (var_resultType_4272, var_sortedOperandIRList_8149  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 220)) ;
      }
    }
    break ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_constructorCallAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_constructorCallAST.mSlotID,
                                          extensionMethod_constructorCallAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_constructorCallAST_analyzeExpression (defineExtensionMethod_constructorCallAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//              Overriding extension method '@typedConstantCallAST addDependenceEdgeForStaticExpression'               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_typedConstantCallAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * inObject,
                                                                                       const GALGAS_lstring constinArgument_inConstantName,
                                                                                       GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_typedConstantCallAST * object = (const cPtr_typedConstantCallAST *) inObject ;
  macroValidSharedObject (object, cPtr_typedConstantCallAST) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mProperty_mOptionalTypeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    ioArgument_ioGraph.setter_addEdge (constinArgument_inConstantName, function_llvmTypeNameFromPLMname (object->mProperty_mOptionalTypeName, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 46)) COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 46)) ;
    }
  }
  cEnumerator_primaryInExpressionAccessListAST enumerator_2274 (object->mProperty_mAccessList, kENUMERATION_UP) ;
  while (enumerator_2274.hasCurrentObject ()) {
    switch (enumerator_2274.current_mAccess (HERE).enumValue ()) {
    case GALGAS_primaryInExpressionAccessAST::kNotBuilt:
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_integerSlice:
      {
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_property:
      {
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_arrayAccess:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_arrayAccess * extractPtr_2518 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_arrayAccess *) (enumerator_2274.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_indexExpression = extractPtr_2518->mAssociatedValue0 ;
        callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) extractedValue_indexExpression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 54)) ;
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_funcCall:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_funcCall * extractPtr_3059 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_funcCall *) (enumerator_2274.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_effectiveArgumentListAST extractedValue_arguments = extractPtr_3059->mAssociatedValue1 ;
        cEnumerator_effectiveArgumentListAST enumerator_2606 (extractedValue_arguments, kENUMERATION_UP) ;
        while (enumerator_2606.hasCurrentObject ()) {
          switch (enumerator_2606.current_mEffectiveParameterKind (HERE).enumValue ()) {
          case GALGAS_effectiveArgumentPassingModeAST::kNotBuilt:
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_input:
            {
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_inputWithType:
            {
              const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType * extractPtr_2849 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType *) (enumerator_2606.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
              const GALGAS_lstring extractedValue_typeName = extractPtr_2849->mAssociatedValue1 ;
              const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, extractedValue_typeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
              if (kBoolTrue == test_1) {
                {
                ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (extractedValue_typeName, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 61)) COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 61)) ;
                }
              }
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_output:
            {
              const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output * extractPtr_2962 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output *) (enumerator_2606.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
              const GALGAS_expressionAST extractedValue_expression = extractPtr_2962->mAssociatedValue0 ;
              callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) extractedValue_expression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 63)) ;
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInput:
            {
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInputSelfVariable:
            {
            }
            break ;
          }
          enumerator_2606.gotoNextObject () ;
        }
      }
      break ;
    }
    enumerator_2274.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_typedConstantCallAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_typedConstantCallAST.mSlotID,
                                                             extensionMethod_typedConstantCallAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_typedConstantCallAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_typedConstantCallAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//              Overriding extension method '@typedConstantCallAST noteExpressionTypesInPrecedenceGraph'               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_typedConstantCallAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                       GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_typedConstantCallAST * object = (const cPtr_typedConstantCallAST *) inObject ;
  macroValidSharedObject (object, cPtr_typedConstantCallAST) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mProperty_mOptionalTypeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (object->mProperty_mOptionalTypeName, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 78)) COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 78)) ;
    }
  }
  cEnumerator_primaryInExpressionAccessListAST enumerator_3704 (object->mProperty_mAccessList, kENUMERATION_UP) ;
  while (enumerator_3704.hasCurrentObject ()) {
    switch (enumerator_3704.current_mAccess (HERE).enumValue ()) {
    case GALGAS_primaryInExpressionAccessAST::kNotBuilt:
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_integerSlice:
      {
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_property:
      {
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_arrayAccess:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_arrayAccess * extractPtr_3907 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_arrayAccess *) (enumerator_3704.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_indexExpression = extractPtr_3907->mAssociatedValue0 ;
        callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) extractedValue_indexExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 85)) ;
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_funcCall:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_funcCall * extractPtr_4432 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_funcCall *) (enumerator_3704.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_effectiveArgumentListAST extractedValue_arguments = extractPtr_4432->mAssociatedValue1 ;
        cEnumerator_effectiveArgumentListAST enumerator_3995 (extractedValue_arguments, kENUMERATION_UP) ;
        while (enumerator_3995.hasCurrentObject ()) {
          switch (enumerator_3995.current_mEffectiveParameterKind (HERE).enumValue ()) {
          case GALGAS_effectiveArgumentPassingModeAST::kNotBuilt:
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_input:
            {
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_inputWithType:
            {
              const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType * extractPtr_4238 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType *) (enumerator_3995.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
              const GALGAS_lstring extractedValue_typeName = extractPtr_4238->mAssociatedValue1 ;
              const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, extractedValue_typeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
              if (kBoolTrue == test_1) {
                {
                ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (extractedValue_typeName, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 92)) COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 92)) ;
                }
              }
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_output:
            {
              const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output * extractPtr_4335 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output *) (enumerator_3995.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
              const GALGAS_expressionAST extractedValue_expression = extractPtr_4335->mAssociatedValue0 ;
              callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) extractedValue_expression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 94)) ;
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInput:
            {
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInputSelfVariable:
            {
            }
            break ;
          }
          enumerator_3995.gotoNextObject () ;
        }
      }
      break ;
    }
    enumerator_3704.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_typedConstantCallAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_typedConstantCallAST.mSlotID,
                                                             extensionMethod_typedConstantCallAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_typedConstantCallAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_typedConstantCallAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                        Overriding extension method '@typedConstantCallAST analyzeExpression'                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_typedConstantCallAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                    const GALGAS_PLMType constinArgument_inSelfType,
                                                                    const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                    const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                    const GALGAS_PLMType constinArgument_inOptionalTargetType,
                                                                    const GALGAS_semanticContext constinArgument_inContext,
                                                                    const GALGAS_mode constinArgument_inCurrentMode,
                                                                    GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                    GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                    GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                    GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                    GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                    GALGAS_objectIR & outArgument_outResult,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_typedConstantCallAST * object = (const cPtr_typedConstantCallAST *) inObject ;
  macroValidSharedObject (object, cPtr_typedConstantCallAST) ;
  GALGAS_PLMType var_inferredResultType_5543 ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, object->mProperty_mOptionalTypeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_inferredResultType_5543 = constinArgument_inOptionalTargetType ;
  }else if (kBoolFalse == test_0) {
    var_inferredResultType_5543 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), object->mProperty_mOptionalTypeName, inCompiler  COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 126)).getter_type (inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 126)) ;
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_inferredResultType_5543.getter_kind (HERE).objectCompare (GALGAS_typeKind::constructor_void (SOURCE_FILE ("expression-typed-constant.galgas", 128)))).boolEnum () ;
  if (kBoolTrue == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (object->mProperty_mConstructorName.getter_location (SOURCE_FILE ("expression-typed-constant.galgas", 129)), GALGAS_string ("cannot infer type"), fixItArray2  COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 129)) ;
    outArgument_outResult.drop () ; // Release error dropped variable
  }else if (kBoolFalse == test_1) {
    GALGAS_classConstantMap var_classConstantMap_5884 = var_inferredResultType_5543.getter_classConstantMap (HERE) ;
    GALGAS_bigint var_value_5991 ;
    GALGAS_lstring var_classTypeName_6010 ;
    var_classConstantMap_5884.method_searchKey (object->mProperty_mConstructorName, var_value_5991, var_classTypeName_6010, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 132)) ;
    GALGAS_PLMType var_resultType_6030 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), var_classTypeName_6010, inCompiler  COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 133)).getter_type (inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 133)) ;
    outArgument_outResult = GALGAS_objectIR::constructor_literalInteger (var_resultType_6030, var_value_5991  COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 134)) ;
  }
  const enumGalgasBool test_3 = GALGAS_bool (kIsStrictSup, object->mProperty_mAccessList.getter_length (SOURCE_FILE ("expression-typed-constant.galgas", 137)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_3) {
    GALGAS_objectIR var_newTemporaryReference_6467 ;
    {
    routine_getNewTempReference (extensionGetter_type (outArgument_outResult, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 140)), ioArgument_ioTemporaries, var_newTemporaryReference_6467, inCompiler  COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 140)) ;
    }
    ioArgument_ioAllocaList.addAssign_operation (extensionGetter_llvmName (var_newTemporaryReference_6467, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 142)), extensionGetter_type (var_newTemporaryReference_6467, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 142)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 142)) ;
    {
    extensionSetter_appendStoreTemporaryReference (ioArgument_ioInstructionGenerationList, extensionGetter_type (var_newTemporaryReference_6467, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 145)), extensionGetter_llvmName (var_newTemporaryReference_6467, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 146)), outArgument_outResult, inCompiler COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 144)) ;
    }
    outArgument_outResult = var_newTemporaryReference_6467 ;
    {
    routine_procAnalyzeAccesListInExpression (constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inOptionalTargetType, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, object->mProperty_mAccessList, outArgument_outResult, inCompiler  COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 151)) ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_typedConstantCallAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_typedConstantCallAST.mSlotID,
                                          extensionMethod_typedConstantCallAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_typedConstantCallAST_analyzeExpression (defineExtensionMethod_typedConstantCallAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                 Overriding extension method '@ifExpressionAST addDependenceEdgeForStaticExpression'                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_ifExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * inObject,
                                                                                  const GALGAS_lstring constinArgument_inConstantName,
                                                                                  GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_ifExpressionAST * object = (const cPtr_ifExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_ifExpressionAST) ;
  callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) object->mProperty_mIfExpression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 67)) ;
  callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) object->mProperty_mThenExpression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 68)) ;
  callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) object->mProperty_mElseExpression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 69)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_ifExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_ifExpressionAST.mSlotID,
                                                             extensionMethod_ifExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_ifExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_ifExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                 Overriding extension method '@ifExpressionAST noteExpressionTypesInPrecedenceGraph'                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_ifExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                  GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_ifExpressionAST * object = (const cPtr_ifExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_ifExpressionAST) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mIfExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 77)) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mThenExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 78)) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mElseExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 79)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_ifExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_ifExpressionAST.mSlotID,
                                                             extensionMethod_ifExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_ifExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_ifExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                          Overriding extension method '@ifExpressionAST analyzeExpression'                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_ifExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                               const GALGAS_PLMType constinArgument_inSelfType,
                                                               const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                               const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                               const GALGAS_PLMType constinArgument_inOptionalTargetType,
                                                               const GALGAS_semanticContext constinArgument_inContext,
                                                               const GALGAS_mode constinArgument_inCurrentMode,
                                                               GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                               GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                               GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                               GALGAS_allocaList & ioArgument_ioAllocaList,
                                                               GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                               GALGAS_objectIR & outArgument_outResult,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_ifExpressionAST * object = (const cPtr_ifExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_ifExpressionAST) ;
  GALGAS_objectIR var_ifExpressionResult_5264 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mIfExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inOptionalTargetType, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_ifExpressionResult_5264, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 101)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_ifExpressionResult_5264, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 115)) ;
  }
  const enumGalgasBool test_0 = extensionGetter_type (var_ifExpressionResult_5264, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 120)).getter_kind (HERE).getter_isBoolean (SOURCE_FILE ("expression-if.galgas", 120)).operator_not (SOURCE_FILE ("expression-if.galgas", 120)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mIfExpressionEndLocation, GALGAS_string ("'if' expression should be boolean"), fixItArray1  COMMA_SOURCE_FILE ("expression-if.galgas", 121)) ;
  }
  GALGAS_objectIR var_thenExpressionTempResult_6074 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mThenExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inOptionalTargetType, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_thenExpressionTempResult_6074, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 124)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_thenExpressionTempResult_6074, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 138)) ;
  }
  GALGAS_objectIR var_thenExpressionResult_6219 = function_checkAssignmentCompatibility (var_thenExpressionTempResult_6074, constinArgument_inOptionalTargetType, object->mProperty_mThenExpressionEndLocation, GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 142)) ;
  GALGAS_objectIR var_elseExpressionTempResult_6932 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mElseExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inOptionalTargetType, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_elseExpressionTempResult_6932, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 149)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_elseExpressionTempResult_6932, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 163)) ;
  }
  GALGAS_objectIR var_elseExpressionResult_7077 = function_checkAssignmentCompatibility (var_elseExpressionTempResult_6932, extensionGetter_type (var_thenExpressionResult_6219, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 169)), object->mProperty_mElseExpressionEndLocation, GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 167)) ;
  const enumGalgasBool test_2 = extensionGetter_isStatic (var_ifExpressionResult_5264, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 174)).boolEnum () ;
  if (kBoolTrue == test_2) {
    GALGAS_bigint var_value_7443 ;
    GALGAS_PLMType joker_7424_1 ; // Joker input parameter
    var_ifExpressionResult_5264.method_literalInteger (joker_7424_1, var_value_7443, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 175)) ;
    GALGAS_objectIR temp_3 ;
    const enumGalgasBool test_4 = GALGAS_bool (kIsNotEqual, var_value_7443.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("expression-if.galgas", 176)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      temp_3 = var_thenExpressionResult_6219 ;
    }else if (kBoolFalse == test_4) {
      temp_3 = var_elseExpressionResult_7077 ;
    }
    outArgument_outResult = temp_3 ;
  }else if (kBoolFalse == test_2) {
    {
    routine_getNewTempValue (extensionGetter_type (var_elseExpressionResult_7077, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 178)), ioArgument_ioTemporaries, outArgument_outResult, inCompiler  COMMA_SOURCE_FILE ("expression-if.galgas", 178)) ;
    }
    {
    extensionSetter_appendSelectOperation (ioArgument_ioInstructionGenerationList, outArgument_outResult, var_ifExpressionResult_5264, var_thenExpressionResult_6219, var_elseExpressionResult_7077, inCompiler COMMA_SOURCE_FILE ("expression-if.galgas", 179)) ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_ifExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_ifExpressionAST.mSlotID,
                                          extensionMethod_ifExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_ifExpressionAST_analyzeExpression (defineExtensionMethod_ifExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//           Overriding extension method '@infixOperatorExpressionAST addDependenceEdgeForStaticExpression'            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_infixOperatorExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * inObject,
                                                                                             const GALGAS_lstring constinArgument_inConstantName,
                                                                                             GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_infixOperatorExpressionAST * object = (const cPtr_infixOperatorExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_infixOperatorExpressionAST) ;
  callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) object->mProperty_mLeftExpression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 47)) ;
  callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) object->mProperty_mRightExpression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 48)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_infixOperatorExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_infixOperatorExpressionAST.mSlotID,
                                                             extensionMethod_infixOperatorExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_infixOperatorExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_infixOperatorExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//           Overriding extension method '@infixOperatorExpressionAST noteExpressionTypesInPrecedenceGraph'            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_infixOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                             GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_infixOperatorExpressionAST * object = (const cPtr_infixOperatorExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_infixOperatorExpressionAST) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mLeftExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 56)) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mRightExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 57)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_infixOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_infixOperatorExpressionAST.mSlotID,
                                                             extensionMethod_infixOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_infixOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_infixOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     Overriding extension method '@infixOperatorExpressionAST analyzeExpression'                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_infixOperatorExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                          const GALGAS_PLMType constinArgument_inSelfType,
                                                                          const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                          const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                          const GALGAS_PLMType constinArgument_inOptionalTargetType,
                                                                          const GALGAS_semanticContext constinArgument_inContext,
                                                                          const GALGAS_mode constinArgument_inCurrentMode,
                                                                          GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                          GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                          GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                          GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                          GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                          GALGAS_objectIR & outArgument_outResult,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_infixOperatorExpressionAST * object = (const cPtr_infixOperatorExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_infixOperatorExpressionAST) ;
  GALGAS_objectIR var_leftOperand_4712 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mLeftExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inOptionalTargetType, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_leftOperand_4712, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 98)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_leftOperand_4712, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 112)) ;
  }
  GALGAS_objectIR var_rightOperand_5337 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mRightExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, extensionGetter_type (var_leftOperand_4712, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 121)), constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_rightOperand_5337, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 117)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_rightOperand_5337, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 131)) ;
  }
  GALGAS_infixOperatorMap var_operatorMap_5499 = function_getInfixOperatorMap (object->mProperty_mOp, constinArgument_inContext, constinArgument_inCurrentMode, object->mProperty_mOperatorLocation, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 136)) ;
  GALGAS_PLMType var_resultType_5806 ;
  GALGAS_infixOperatorDescription var_binaryOperator_5859 ;
  extensionMethod_checkBinaryOperationWith (var_operatorMap_5499, extensionGetter_type (var_leftOperand_4712, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 139)), extensionGetter_type (var_rightOperand_5337, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 140)), object->mProperty_mOperatorLocation, var_resultType_5806, var_binaryOperator_5859, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 138)) ;
  callExtensionMethod_generateInfixOperatorCode ((const cPtr_infixOperatorDescription *) var_binaryOperator_5859.ptr (), ioArgument_ioTemporaries, ioArgument_ioInstructionGenerationList, var_leftOperand_4712, object->mProperty_mOperatorLocation, var_rightOperand_5337, var_resultType_5806, outArgument_outResult, inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 146)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_infixOperatorExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_infixOperatorExpressionAST.mSlotID,
                                          extensionMethod_infixOperatorExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_infixOperatorExpressionAST_analyzeExpression (defineExtensionMethod_infixOperatorExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                           Function 'getInfixOperatorMap'                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_infixOperatorMap function_getInfixOperatorMap (const GALGAS_infixOperator & constinArgument_inOp,
                                                      const GALGAS_semanticContext & constinArgument_inContext,
                                                      const GALGAS_mode & constinArgument_inCurrentMode,
                                                      const GALGAS_location & constinArgument_inOperatorLocation,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperatorMap result_outOperatorMap ; // Returned variable
  switch (constinArgument_inOp.enumValue ()) {
  case GALGAS_infixOperator::kNotBuilt:
    break ;
  case GALGAS_infixOperator::kEnum_equal:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mEqualOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_nonEqual:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mNonEqualOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_strictInf:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mStrictInfOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_infEqual:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mInfEqualOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_strictSup:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mStrictSupOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_supEqual:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mSupEqualOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_andOp:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mAndOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_orOp:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mOrOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_xorOp:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mXorOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_booleanXorOp:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mBooleanXorOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_addOp:
    {
      const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_inCurrentMode.objectCompare (GALGAS_mode::constructor_panicMode (SOURCE_FILE ("expression-infix-operators.galgas", 188)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (constinArgument_inOperatorLocation, GALGAS_string ("operations that can generate panic are not allowed in ").add_operation (function_panicModeName (inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 189)), inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 189)).add_operation (GALGAS_string (" mode"), inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 189)), fixItArray1  COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 189)) ;
      }
      const enumGalgasBool test_2 = GALGAS_bool (gOption_plm_5F_options_noPanicGeneration.getter_value ()).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_outOperatorMap = constinArgument_inContext.getter_mAddNoOvfOperatorMap (HERE) ;
      }else if (kBoolFalse == test_2) {
        result_outOperatorMap = constinArgument_inContext.getter_mAddOperatorMap (HERE) ;
      }
    }
    break ;
  case GALGAS_infixOperator::kEnum_addOpNoOvf:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mAddNoOvfOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_subOp:
    {
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_inCurrentMode.objectCompare (GALGAS_mode::constructor_panicMode (SOURCE_FILE ("expression-infix-operators.galgas", 199)))).boolEnum () ;
      if (kBoolTrue == test_3) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (constinArgument_inOperatorLocation, GALGAS_string ("operations that can generate panic are not allowed in ").add_operation (function_panicModeName (inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 200)), inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 200)).add_operation (GALGAS_string (" mode"), inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 200)), fixItArray4  COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 200)) ;
      }
      const enumGalgasBool test_5 = GALGAS_bool (gOption_plm_5F_options_noPanicGeneration.getter_value ()).boolEnum () ;
      if (kBoolTrue == test_5) {
        result_outOperatorMap = constinArgument_inContext.getter_mSubNoOvfOperatorMap (HERE) ;
      }else if (kBoolFalse == test_5) {
        result_outOperatorMap = constinArgument_inContext.getter_mSubOperatorMap (HERE) ;
      }
    }
    break ;
  case GALGAS_infixOperator::kEnum_subOpNoOvf:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mSubNoOvfOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_mulOp:
    {
      const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, constinArgument_inCurrentMode.objectCompare (GALGAS_mode::constructor_panicMode (SOURCE_FILE ("expression-infix-operators.galgas", 210)))).boolEnum () ;
      if (kBoolTrue == test_6) {
        TC_Array <C_FixItDescription> fixItArray7 ;
        inCompiler->emitSemanticError (constinArgument_inOperatorLocation, GALGAS_string ("operations that can generate panic are not allowed in ").add_operation (function_panicModeName (inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 211)), inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 211)).add_operation (GALGAS_string (" mode"), inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 211)), fixItArray7  COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 211)) ;
      }
      const enumGalgasBool test_8 = GALGAS_bool (gOption_plm_5F_options_noPanicGeneration.getter_value ()).boolEnum () ;
      if (kBoolTrue == test_8) {
        result_outOperatorMap = constinArgument_inContext.getter_mMulNoOvfOperatorMap (HERE) ;
      }else if (kBoolFalse == test_8) {
        result_outOperatorMap = constinArgument_inContext.getter_mMulOperatorMap (HERE) ;
      }
    }
    break ;
  case GALGAS_infixOperator::kEnum_mulOpNoOvf:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mMulNoOvfOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_divOp:
    {
      const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, constinArgument_inCurrentMode.objectCompare (GALGAS_mode::constructor_panicMode (SOURCE_FILE ("expression-infix-operators.galgas", 221)))).boolEnum () ;
      if (kBoolTrue == test_9) {
        TC_Array <C_FixItDescription> fixItArray10 ;
        inCompiler->emitSemanticError (constinArgument_inOperatorLocation, GALGAS_string ("operations that can generate panic are not allowed in ").add_operation (function_panicModeName (inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 222)), inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 222)).add_operation (GALGAS_string (" mode"), inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 222)), fixItArray10  COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 222)) ;
      }
      const enumGalgasBool test_11 = GALGAS_bool (gOption_plm_5F_options_noPanicGeneration.getter_value ()).boolEnum () ;
      if (kBoolTrue == test_11) {
        result_outOperatorMap = constinArgument_inContext.getter_mDivNoOvfOperatorMap (HERE) ;
      }else if (kBoolFalse == test_11) {
        result_outOperatorMap = constinArgument_inContext.getter_mDivOperatorMap (HERE) ;
      }
    }
    break ;
  case GALGAS_infixOperator::kEnum_divOpNoOvf:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mDivNoOvfOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_modOp:
    {
      const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, constinArgument_inCurrentMode.objectCompare (GALGAS_mode::constructor_panicMode (SOURCE_FILE ("expression-infix-operators.galgas", 232)))).boolEnum () ;
      if (kBoolTrue == test_12) {
        TC_Array <C_FixItDescription> fixItArray13 ;
        inCompiler->emitSemanticError (constinArgument_inOperatorLocation, GALGAS_string ("operations that can generate panic are not allowed in ").add_operation (function_panicModeName (inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 233)), inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 233)).add_operation (GALGAS_string (" mode"), inCompiler COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 233)), fixItArray13  COMMA_SOURCE_FILE ("expression-infix-operators.galgas", 233)) ;
      }
      const enumGalgasBool test_14 = GALGAS_bool (gOption_plm_5F_options_noPanicGeneration.getter_value ()).boolEnum () ;
      if (kBoolTrue == test_14) {
        result_outOperatorMap = constinArgument_inContext.getter_mModNoOvfOperatorMap (HERE) ;
      }else if (kBoolFalse == test_14) {
        result_outOperatorMap = constinArgument_inContext.getter_mModOperatorMap (HERE) ;
      }
    }
    break ;
  case GALGAS_infixOperator::kEnum_modOpNoOvf:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mModNoOvfOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_leftShiftOp:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mLeftShiftOperatorMap (HERE) ;
    }
    break ;
  case GALGAS_infixOperator::kEnum_rightShiftOp:
    {
      result_outOperatorMap = constinArgument_inContext.getter_mRightShiftOperatorMap (HERE) ;
    }
    break ;
  }
//---
  return result_outOperatorMap ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//  Function introspection                                                                                             *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const C_galgas_type_descriptor * functionArgs_getInfixOperatorMap [5] = {
  & kTypeDescriptor_GALGAS_infixOperator,
  & kTypeDescriptor_GALGAS_semanticContext,
  & kTypeDescriptor_GALGAS_mode,
  & kTypeDescriptor_GALGAS_location,
  NULL
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_object functionWithGenericHeader_getInfixOperatorMap (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_infixOperator operand0 = GALGAS_infixOperator::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_semanticContext operand1 = GALGAS_semanticContext::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                                 inCompiler
                                                                                 COMMA_THERE) ;
  const GALGAS_mode operand2 = GALGAS_mode::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  const GALGAS_location operand3 = GALGAS_location::extractObject (inEffectiveParameterArray.objectAtIndex (3 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  return function_getInfixOperatorMap (operand0,
                                       operand1,
                                       operand2,
                                       operand3,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_galgas_function_descriptor functionDescriptor_getInfixOperatorMap ("getInfixOperatorMap",
                                                                     functionWithGenericHeader_getInfixOperatorMap,
                                                                     & kTypeDescriptor_GALGAS_infixOperatorMap,
                                                                     4,
                                                                     functionArgs_getInfixOperatorMap) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//   Overriding extension method '@booleanShortCircuitAndOperatorExpressionAST addDependenceEdgeForStaticExpression'   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_booleanShortCircuitAndOperatorExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * inObject,
                                                                                                              const GALGAS_lstring constinArgument_inConstantName,
                                                                                                              GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                              C_Compiler * inCompiler
                                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_booleanShortCircuitAndOperatorExpressionAST * object = (const cPtr_booleanShortCircuitAndOperatorExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_booleanShortCircuitAndOperatorExpressionAST) ;
  callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) object->mProperty_mLeftExpression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 19)) ;
  callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) object->mProperty_mRightExpression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 20)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_booleanShortCircuitAndOperatorExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_booleanShortCircuitAndOperatorExpressionAST.mSlotID,
                                                             extensionMethod_booleanShortCircuitAndOperatorExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_booleanShortCircuitAndOperatorExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_booleanShortCircuitAndOperatorExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//   Overriding extension method '@booleanShortCircuitAndOperatorExpressionAST noteExpressionTypesInPrecedenceGraph'   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_booleanShortCircuitAndOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                                              GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                              C_Compiler * inCompiler
                                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_booleanShortCircuitAndOperatorExpressionAST * object = (const cPtr_booleanShortCircuitAndOperatorExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_booleanShortCircuitAndOperatorExpressionAST) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mLeftExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 28)) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mRightExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 29)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_booleanShortCircuitAndOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_booleanShortCircuitAndOperatorExpressionAST.mSlotID,
                                                             extensionMethod_booleanShortCircuitAndOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_booleanShortCircuitAndOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_booleanShortCircuitAndOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//            Overriding extension method '@booleanShortCircuitAndOperatorExpressionAST analyzeExpression'             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_booleanShortCircuitAndOperatorExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                                           const GALGAS_PLMType constinArgument_inSelfType,
                                                                                           const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                                           const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                                           const GALGAS_PLMType constinArgument_inOptionalTargetType,
                                                                                           const GALGAS_semanticContext constinArgument_inContext,
                                                                                           const GALGAS_mode constinArgument_inCurrentMode,
                                                                                           GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                                           GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                                           GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                                           GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                                           GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                                           GALGAS_objectIR & outArgument_outResult,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_booleanShortCircuitAndOperatorExpressionAST * object = (const cPtr_booleanShortCircuitAndOperatorExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_booleanShortCircuitAndOperatorExpressionAST) ;
  GALGAS_instructionListIR var_leftInstructionGenerationList_3009 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 51)) ;
  GALGAS_objectIR var_leftOperand_3490 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mLeftExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inOptionalTargetType, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_leftInstructionGenerationList_3009, var_leftOperand_3490, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 52)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_leftOperand_3490, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 66)) ;
  }
  GALGAS_instructionListIR var_rightInstructionGenerationList_3677 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 71)) ;
  GALGAS_objectIR var_rightOperand_4159 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mRightExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, extensionGetter_type (var_leftOperand_3490, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 76)), constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_rightInstructionGenerationList_3677, var_rightOperand_4159, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 72)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_rightOperand_4159, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 86)) ;
  }
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, extensionGetter_type (var_leftOperand_3490, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 91)).getter_kind (HERE).objectCompare (GALGAS_typeKind::constructor_boolean (SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 91)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("left operand should be boolean"), fixItArray1  COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 92)) ;
  }
  const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, extensionGetter_type (var_rightOperand_4159, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 95)).getter_kind (HERE).objectCompare (GALGAS_typeKind::constructor_boolean (SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 95)))).boolEnum () ;
  if (kBoolTrue == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("left operand should be boolean"), fixItArray3  COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 96)) ;
  }
  GALGAS_bool test_4 = var_leftOperand_3490.getter_isLiteralInteger (SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 99)) ;
  if (kBoolTrue == test_4.boolEnum ()) {
    test_4 = var_rightOperand_4159.getter_isLiteralInteger (SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 99)) ;
  }
  const enumGalgasBool test_5 = test_4.boolEnum () ;
  if (kBoolTrue == test_5) {
    GALGAS_bigint var_leftStaticValue_4756 ;
    GALGAS_PLMType joker_4720 ; // Joker input parameter
    var_leftOperand_3490.method_literalInteger (joker_4720, var_leftStaticValue_4756, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 100)) ;
    GALGAS_bigint var_rightStaticValue_4834 ;
    GALGAS_PLMType joker_4797 ; // Joker input parameter
    var_rightOperand_4159.method_literalInteger (joker_4797, var_rightStaticValue_4834, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 101)) ;
    outArgument_outResult = GALGAS_objectIR::constructor_literalInteger (extensionGetter_type (var_leftOperand_3490, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 102)), var_leftStaticValue_4756.operator_and (var_rightStaticValue_4834 COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 102))  COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 102)) ;
  }else if (kBoolFalse == test_5) {
    {
    routine_getNewTempValue (extensionGetter_booleanType (constinArgument_inContext, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 105)), ioArgument_ioTemporaries, outArgument_outResult, inCompiler  COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 105)) ;
    }
    {
    extensionSetter_appendShortCircuitAndOperation (ioArgument_ioInstructionGenerationList, outArgument_outResult, var_leftOperand_3490, var_leftInstructionGenerationList_3009, var_rightOperand_4159, var_rightInstructionGenerationList_3677, object->mProperty_mOperatorLocation, inCompiler COMMA_SOURCE_FILE ("expression-boolean-short-circuit-and-operator.galgas", 107)) ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_booleanShortCircuitAndOperatorExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_booleanShortCircuitAndOperatorExpressionAST.mSlotID,
                                          extensionMethod_booleanShortCircuitAndOperatorExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_booleanShortCircuitAndOperatorExpressionAST_analyzeExpression (defineExtensionMethod_booleanShortCircuitAndOperatorExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//            Overriding extension method '@integerSliceExpressionAST addDependenceEdgeForStaticExpression'            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_integerSliceExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * inObject,
                                                                                            const GALGAS_lstring constinArgument_inConstantName,
                                                                                            GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_integerSliceExpressionAST * object = (const cPtr_integerSliceExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_integerSliceExpressionAST) ;
  cEnumerator_integerSliceFieldListAST enumerator_2546 (object->mProperty_mSliceValues, kENUMERATION_UP) ;
  while (enumerator_2546.hasCurrentObject ()) {
    callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) enumerator_2546.current_mExpression (HERE).ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 58)) ;
    enumerator_2546.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_integerSliceExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_integerSliceExpressionAST.mSlotID,
                                                             extensionMethod_integerSliceExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_integerSliceExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_integerSliceExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//            Overriding extension method '@integerSliceExpressionAST noteExpressionTypesInPrecedenceGraph'            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_integerSliceExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                            GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_integerSliceExpressionAST * object = (const cPtr_integerSliceExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_integerSliceExpressionAST) ;
  {
  ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (object->mProperty_mTypeName, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 69)) COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 69)) ;
  }
  cEnumerator_integerSliceFieldListAST enumerator_3254 (object->mProperty_mSliceValues, kENUMERATION_UP) ;
  while (enumerator_3254.hasCurrentObject ()) {
    callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) enumerator_3254.current_mExpression (HERE).ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 71)) ;
    const enumGalgasBool test_0 = enumerator_3254.current_mSliceWidth (HERE).getter_string (HERE).getter_isDecimalUnsignedNumber (SOURCE_FILE ("expression-integer-slice.galgas", 72)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_uint var_sliceWidth_3401 = enumerator_3254.current_mSliceWidth (HERE).getter_string (HERE).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 73)) ;
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_sliceWidth_3401.objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_1) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_3254.current_mSliceWidth (HERE).getter_location (SOURCE_FILE ("expression-integer-slice.galgas", 75)), GALGAS_string ("the bit slice width should be > 0"), fixItArray2  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 75)) ;
      }else if (kBoolFalse == test_1) {
        {
        extensionSetter_noteUINTType (ioArgument_ioGraph, var_sliceWidth_3401, enumerator_3254.current_mExpressionLocation (HERE), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 77)) ;
        }
      }
    }else if (kBoolFalse == test_0) {
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, enumerator_3254.current_mSliceWidth (HERE).getter_string (HERE).objectCompare (GALGAS_string ("b"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        GALGAS_lstring var_sliceTypeName_3690 = GALGAS_lstring::constructor_new (GALGAS_string ("bool"), enumerator_3254.current_mExpressionLocation (HERE)  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 80)) ;
        {
        ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (var_sliceTypeName_3690, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 81)) COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 81)) ;
        }
      }
    }
    enumerator_3254.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_integerSliceExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_integerSliceExpressionAST.mSlotID,
                                                             extensionMethod_integerSliceExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_integerSliceExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_integerSliceExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     Overriding extension method '@integerSliceExpressionAST analyzeExpression'                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_integerSliceExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                         const GALGAS_PLMType constinArgument_inSelfType,
                                                                         const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                         const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                         const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                                                         const GALGAS_semanticContext constinArgument_inContext,
                                                                         const GALGAS_mode constinArgument_inCurrentMode,
                                                                         GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                         GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                         GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                         GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                         GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                         GALGAS_objectIR & outArgument_outResult,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_integerSliceExpressionAST * object = (const cPtr_integerSliceExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_integerSliceExpressionAST) ;
  GALGAS_PLMType var_resultType_4894 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), object->mProperty_mTypeName, inCompiler  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 105)).getter_type (inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 105)) ;
  const enumGalgasBool test_0 = var_resultType_4894.getter_kind (HERE).getter_isInteger (SOURCE_FILE ("expression-integer-slice.galgas", 107)).operator_not (SOURCE_FILE ("expression-integer-slice.galgas", 107)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("expression-integer-slice.galgas", 108)), GALGAS_string ("this type should be an unsigned integer type"), fixItArray1  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 108)) ;
    outArgument_outResult.drop () ; // Release error dropped variable
  }else if (kBoolFalse == test_0) {
    GALGAS_bool var_unsigned_5196 ;
    GALGAS_uint var_bitCount_5219 ;
    GALGAS_bigint joker_5171_2 ; // Joker input parameter
    GALGAS_bigint joker_5171_1 ; // Joker input parameter
    var_resultType_4894.getter_kind (HERE).method_integer (joker_5171_2, joker_5171_1, var_unsigned_5196, var_bitCount_5219, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 110)) ;
    const enumGalgasBool test_2 = var_unsigned_5196.operator_not (SOURCE_FILE ("expression-integer-slice.galgas", 111)).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("expression-integer-slice.galgas", 112)), GALGAS_string ("this type should be an unsigned integer type"), fixItArray3  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 112)) ;
      outArgument_outResult.drop () ; // Release error dropped variable
    }else if (kBoolFalse == test_2) {
      GALGAS_uint var_leftShiftAmount_5437 = var_bitCount_5219 ;
      GALGAS_bigint var_accumulatedFieldStaticValues_5491 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 116)) ;
      GALGAS_operandIRList var_operandList_5529 = GALGAS_operandIRList::constructor_emptyList (SOURCE_FILE ("expression-integer-slice.galgas", 117)) ;
      cEnumerator_integerSliceFieldListAST enumerator_5606 (object->mProperty_mSliceValues, kENUMERATION_UP) ;
      while (enumerator_5606.hasCurrentObject ()) {
        GALGAS_uint var_sliceWidth_5634 ;
        GALGAS_lstring var_expressionTypeName_5670 ;
        const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, enumerator_5606.current_mSliceWidth (HERE).getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_4) {
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (enumerator_5606.current_mSliceWidth (HERE).getter_location (SOURCE_FILE ("expression-integer-slice.galgas", 122)), GALGAS_string ("anonymous selector not allowed here"), fixItArray5  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 122)) ;
          var_operandList_5529.drop () ; // Release error dropped variable
          var_sliceWidth_5634.drop () ; // Release error dropped variable
          var_expressionTypeName_5670.drop () ; // Release error dropped variable
        }else if (kBoolFalse == test_4) {
          const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, enumerator_5606.current_mSliceWidth (HERE).getter_string (HERE).objectCompare (GALGAS_string ("b"))).boolEnum () ;
          if (kBoolTrue == test_6) {
            var_sliceWidth_5634 = GALGAS_uint ((uint32_t) 1U) ;
            var_expressionTypeName_5670 = GALGAS_lstring::constructor_new (GALGAS_string ("bool"), object->mProperty_mTypeName.getter_location (HERE)  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 125)) ;
          }else if (kBoolFalse == test_6) {
            const enumGalgasBool test_7 = enumerator_5606.current_mSliceWidth (HERE).getter_string (HERE).getter_isDecimalUnsignedNumber (SOURCE_FILE ("expression-integer-slice.galgas", 126)).operator_not (SOURCE_FILE ("expression-integer-slice.galgas", 126)).boolEnum () ;
            if (kBoolTrue == test_7) {
              TC_Array <C_FixItDescription> fixItArray8 ;
              inCompiler->emitSemanticError (enumerator_5606.current_mSliceWidth (HERE).getter_location (SOURCE_FILE ("expression-integer-slice.galgas", 127)), GALGAS_string ("the selector should be an unsigned integer value"), fixItArray8  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 127)) ;
              var_operandList_5529.drop () ; // Release error dropped variable
              var_sliceWidth_5634.drop () ; // Release error dropped variable
              var_expressionTypeName_5670.drop () ; // Release error dropped variable
            }else if (kBoolFalse == test_7) {
              var_sliceWidth_5634 = enumerator_5606.current_mSliceWidth (HERE).getter_string (HERE).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 129)) ;
              var_expressionTypeName_5670 = GALGAS_lstring::constructor_new (GALGAS_string ("uint").add_operation (var_sliceWidth_5634.getter_string (SOURCE_FILE ("expression-integer-slice.galgas", 130)), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 130)), object->mProperty_mTypeName.getter_location (HERE)  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 130)) ;
              const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, var_sliceWidth_5634.objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
              if (kBoolTrue == test_9) {
                TC_Array <C_FixItDescription> fixItArray10 ;
                inCompiler->emitSemanticError (enumerator_5606.current_mSliceWidth (HERE).getter_location (SOURCE_FILE ("expression-integer-slice.galgas", 132)), GALGAS_string ("the bit slice width should be > 0"), fixItArray10  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 132)) ;
              }
            }
          }
        }
        const enumGalgasBool test_11 = GALGAS_bool (kIsSupOrEqual, var_leftShiftAmount_5437.objectCompare (var_sliceWidth_5634)).boolEnum () ;
        if (kBoolTrue == test_11) {
          var_leftShiftAmount_5437 = var_leftShiftAmount_5437.substract_operation (var_sliceWidth_5634, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 136)) ;
        }else if (kBoolFalse == test_11) {
          GALGAS_uint var_specifiedBitCount_6597 = var_bitCount_5219.add_operation (var_sliceWidth_5634, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 138)).substract_operation (var_leftShiftAmount_5437, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 138)) ;
          TC_Array <C_FixItDescription> fixItArray12 ;
          inCompiler->emitSemanticError (enumerator_5606.current_mSliceWidth (HERE).getter_location (SOURCE_FILE ("expression-integer-slice.galgas", 139)), GALGAS_string ("bit slice overflow: ").add_operation (var_specifiedBitCount_6597.getter_string (SOURCE_FILE ("expression-integer-slice.galgas", 139)), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 139)).add_operation (GALGAS_string (" bits, should be "), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 139)).add_operation (var_bitCount_5219.getter_string (SOURCE_FILE ("expression-integer-slice.galgas", 139)), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 139)), fixItArray12  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 139)) ;
          var_leftShiftAmount_5437 = GALGAS_uint ((uint32_t) 0U) ;
        }
        GALGAS_PLMType var_expressionTargetType_6852 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), var_expressionTypeName_5670, inCompiler  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 143)).getter_type (inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 143)) ;
        GALGAS_objectIR var_expressionResult_7487 ;
        callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) enumerator_5606.current_mExpression (HERE).ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, var_expressionTargetType_6852, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_expressionResult_7487, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 144)) ;
        {
        extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_expressionResult_7487, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 158)) ;
        }
        switch (extensionGetter_type (var_expressionResult_7487, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 163)).getter_kind (HERE).enumValue ()) {
        case GALGAS_typeKind::kNotBuilt:
          break ;
        case GALGAS_typeKind::kEnum_arrayType:
          {
            TC_Array <C_FixItDescription> fixItArray13 ;
            inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an unsigned integer expression is required here"), fixItArray13  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 165)) ;
          }
          break ;
        case GALGAS_typeKind::kEnum_dynamicArrayType:
          {
            TC_Array <C_FixItDescription> fixItArray14 ;
            inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an unsigned integer expression is required here"), fixItArray14  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 167)) ;
          }
          break ;
        case GALGAS_typeKind::kEnum_opaque:
          {
            TC_Array <C_FixItDescription> fixItArray15 ;
            inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an unsigned integer expression is required here"), fixItArray15  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 169)) ;
          }
          break ;
        case GALGAS_typeKind::kEnum_enumeration:
          {
            TC_Array <C_FixItDescription> fixItArray16 ;
            inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an unsigned integer expression is required here"), fixItArray16  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 171)) ;
          }
          break ;
        case GALGAS_typeKind::kEnum_structure:
          {
            TC_Array <C_FixItDescription> fixItArray17 ;
            inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an unsigned integer expression is required here"), fixItArray17  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 173)) ;
          }
          break ;
        case GALGAS_typeKind::kEnum_syncTool:
          {
            TC_Array <C_FixItDescription> fixItArray18 ;
            inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an unsigned integer expression is required here"), fixItArray18  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 175)) ;
          }
          break ;
        case GALGAS_typeKind::kEnum_boolean:
          {
            const enumGalgasBool test_19 = GALGAS_bool (kIsNotEqual, extensionGetter_type (var_expressionResult_7487, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 177)).getter_plmTypeDescriptionName (SOURCE_FILE ("expression-integer-slice.galgas", 177)).objectCompare (var_expressionTargetType_6852.getter_plmTypeDescriptionName (SOURCE_FILE ("expression-integer-slice.galgas", 177)))).boolEnum () ;
            if (kBoolTrue == test_19) {
              TC_Array <C_FixItDescription> fixItArray20 ;
              inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an $").add_operation (var_expressionTargetType_6852.getter_plmTypeDescriptionName (SOURCE_FILE ("expression-integer-slice.galgas", 179)), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 179)).add_operation (GALGAS_string (" expression is required, found an $"), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 179)).add_operation (extensionGetter_type (var_expressionResult_7487, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 180)).getter_plmTypeDescriptionName (SOURCE_FILE ("expression-integer-slice.galgas", 180)), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 179)).add_operation (GALGAS_string (" expression"), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 180)), fixItArray20  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 178)) ;
            }
            const enumGalgasBool test_21 = var_expressionResult_7487.getter_isLiteralInteger (SOURCE_FILE ("expression-integer-slice.galgas", 182)).boolEnum () ;
            if (kBoolTrue == test_21) {
              GALGAS_bigint var_value_8908 ;
              GALGAS_PLMType joker_8881_1 ; // Joker input parameter
              var_expressionResult_7487.method_literalInteger (joker_8881_1, var_value_8908, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 183)) ;
              var_accumulatedFieldStaticValues_5491 = var_accumulatedFieldStaticValues_5491.operator_or (var_value_8908.left_shift_operation (var_leftShiftAmount_5437 COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 184)) COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 184)) ;
            }else if (kBoolFalse == test_21) {
              GALGAS_objectIR var_extendedResult_9167 ;
              {
              routine_getNewTempValue (var_resultType_4894, ioArgument_ioTemporaries, var_extendedResult_9167, inCompiler  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 187)) ;
              }
              {
              extensionSetter_appendBoolToUInt (ioArgument_ioInstructionGenerationList, var_extendedResult_9167, var_expressionResult_7487, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 188)) ;
              }
              GALGAS_objectIR var_shiftedResult_9373 ;
              {
              routine_getNewTempValue (var_resultType_4894, ioArgument_ioTemporaries, var_shiftedResult_9373, inCompiler  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 190)) ;
              }
              {
              extensionSetter_appendShiftLeft (ioArgument_ioInstructionGenerationList, var_shiftedResult_9373, var_extendedResult_9167, var_leftShiftAmount_5437, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 191)) ;
              }
              var_operandList_5529.addAssign_operation (var_shiftedResult_9373  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 193)) ;
            }
          }
          break ;
        case GALGAS_typeKind::kEnum_void:
          {
            TC_Array <C_FixItDescription> fixItArray22 ;
            inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an unsigned integer expression is required here"), fixItArray22  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 196)) ;
          }
          break ;
        case GALGAS_typeKind::kEnum_literalString:
          {
            TC_Array <C_FixItDescription> fixItArray23 ;
            inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an unsigned integer expression is required here"), fixItArray23  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 198)) ;
          }
          break ;
        case GALGAS_typeKind::kEnum_pointer:
          {
            TC_Array <C_FixItDescription> fixItArray24 ;
            inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an unsigned integer expression is required here"), fixItArray24  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 200)) ;
          }
          break ;
        case GALGAS_typeKind::kEnum_function:
          {
            TC_Array <C_FixItDescription> fixItArray25 ;
            inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an unsigned integer expression is required here"), fixItArray25  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 202)) ;
          }
          break ;
        case GALGAS_typeKind::kEnum_staticInteger:
          {
            GALGAS_bigint var_value_10115 ;
            GALGAS_PLMType joker_10088_1 ; // Joker input parameter
            var_expressionResult_7487.method_literalInteger (joker_10088_1, var_value_10115, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 204)) ;
            const enumGalgasBool test_26 = GALGAS_bool (kIsStrictInf, var_value_10115.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 205)))).boolEnum () ;
            if (kBoolTrue == test_26) {
              TC_Array <C_FixItDescription> fixItArray27 ;
              inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("this integer expression should be positive"), fixItArray27  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 206)) ;
            }else if (kBoolFalse == test_26) {
              const enumGalgasBool test_28 = GALGAS_bool (kIsStrictInf, var_value_10115.objectCompare (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 207)).left_shift_operation (var_sliceWidth_5634 COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 207)))).boolEnum () ;
              if (kBoolTrue == test_28) {
                var_accumulatedFieldStaticValues_5491 = var_accumulatedFieldStaticValues_5491.operator_or (var_value_10115.left_shift_operation (var_leftShiftAmount_5437 COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 208)) COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 208)) ;
              }else if (kBoolFalse == test_28) {
                TC_Array <C_FixItDescription> fixItArray29 ;
                inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("expression too large (should be < ").add_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 210)).left_shift_operation (var_sliceWidth_5634 COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 210)).getter_string (SOURCE_FILE ("expression-integer-slice.galgas", 210)), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 210)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 210)), fixItArray29  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 210)) ;
              }
            }
          }
          break ;
        case GALGAS_typeKind::kEnum_integer:
          {
            const cEnumAssociatedValues_typeKind_integer * extractPtr_11425 = (const cEnumAssociatedValues_typeKind_integer *) (extensionGetter_type (var_expressionResult_7487, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 163)).getter_kind (HERE).unsafePointer ()) ;
            const GALGAS_bigint extractedValue_min = extractPtr_11425->mAssociatedValue0 ;
            const GALGAS_bigint extractedValue_max = extractPtr_11425->mAssociatedValue1 ;
            const GALGAS_bool extractedValue_unsigned = extractPtr_11425->mAssociatedValue2 ;
            const GALGAS_uint extractedValue_expressionBitCount = extractPtr_11425->mAssociatedValue3 ;
            const enumGalgasBool test_30 = extractedValue_unsigned.operator_not (SOURCE_FILE ("expression-integer-slice.galgas", 213)).boolEnum () ;
            if (kBoolTrue == test_30) {
              TC_Array <C_FixItDescription> fixItArray31 ;
              inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an $uint").add_operation (var_sliceWidth_5634.getter_string (SOURCE_FILE ("expression-integer-slice.galgas", 214)), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 214)).add_operation (GALGAS_string (" expression is required here"), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 214)), fixItArray31  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 214)) ;
            }else if (kBoolFalse == test_30) {
              const enumGalgasBool test_32 = GALGAS_bool (kIsNotEqual, extractedValue_expressionBitCount.objectCompare (var_sliceWidth_5634)).boolEnum () ;
              if (kBoolTrue == test_32) {
                TC_Array <C_FixItDescription> fixItArray33 ;
                inCompiler->emitSemanticError (enumerator_5606.current_mExpressionLocation (HERE), GALGAS_string ("an $uint").add_operation (var_sliceWidth_5634.getter_string (SOURCE_FILE ("expression-integer-slice.galgas", 216)), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 216)).add_operation (GALGAS_string (" expression is required here"), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 216)), fixItArray33  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 216)) ;
              }else if (kBoolFalse == test_32) {
                GALGAS_objectIR var_extendedResult_11030 ;
                {
                routine_getNewTempValue (var_resultType_4894, ioArgument_ioTemporaries, var_extendedResult_11030, inCompiler  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 219)) ;
                }
                {
                extensionSetter_appendExtend (ioArgument_ioInstructionGenerationList, var_extendedResult_11030, var_expressionResult_7487, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 220)) ;
                }
                GALGAS_objectIR var_shiftedResult_11232 ;
                {
                routine_getNewTempValue (var_resultType_4894, ioArgument_ioTemporaries, var_shiftedResult_11232, inCompiler  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 222)) ;
                }
                {
                extensionSetter_appendShiftLeft (ioArgument_ioInstructionGenerationList, var_shiftedResult_11232, var_extendedResult_11030, var_leftShiftAmount_5437, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 223)) ;
                }
                var_operandList_5529.addAssign_operation (var_shiftedResult_11232  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 225)) ;
              }
            }
          }
          break ;
        }
        enumerator_5606.gotoNextObject () ;
      }
      const enumGalgasBool test_34 = GALGAS_bool (kIsNotEqual, var_leftShiftAmount_5437.objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_34) {
        TC_Array <C_FixItDescription> fixItArray35 ;
        inCompiler->emitSemanticError (object->mProperty_mLocation, var_bitCount_5219.getter_string (SOURCE_FILE ("expression-integer-slice.galgas", 230)).add_operation (GALGAS_string (" bits required, "), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 230)).add_operation (var_bitCount_5219.substract_operation (var_leftShiftAmount_5437, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 230)).getter_string (SOURCE_FILE ("expression-integer-slice.galgas", 230)), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 230)).add_operation (GALGAS_string (" bits defined"), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 230)), fixItArray35  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 230)) ;
      }
      outArgument_outResult = GALGAS_objectIR::constructor_literalInteger (var_resultType_4894, var_accumulatedFieldStaticValues_5491  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 233)) ;
      cEnumerator_operandIRList enumerator_11797 (var_operandList_5529, kENUMERATION_UP) ;
      while (enumerator_11797.hasCurrentObject ()) {
        GALGAS_objectIR var_newResult_11868 ;
        {
        routine_getNewTempValue (var_resultType_4894, ioArgument_ioTemporaries, var_newResult_11868, inCompiler  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 235)) ;
        }
        {
        extensionSetter_appendBinaryOperation (ioArgument_ioInstructionGenerationList, var_newResult_11868, extensionGetter_type (var_newResult_11868, inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 238)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 239)), outArgument_outResult, GALGAS_llvmBinaryOperation::constructor_ior (SOURCE_FILE ("expression-integer-slice.galgas", 241)), enumerator_11797.current_mOperand (HERE), inCompiler COMMA_SOURCE_FILE ("expression-integer-slice.galgas", 236)) ;
        }
        outArgument_outResult = var_newResult_11868 ;
        enumerator_11797.gotoNextObject () ;
      }
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_integerSliceExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_integerSliceExpressionAST.mSlotID,
                                          extensionMethod_integerSliceExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_integerSliceExpressionAST_analyzeExpression (defineExtensionMethod_integerSliceExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//           Overriding extension method '@prefixOperatorExpressionAST addDependenceEdgeForStaticExpression'           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_prefixOperatorExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * inObject,
                                                                                              const GALGAS_lstring constinArgument_inConstantName,
                                                                                              GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_prefixOperatorExpressionAST * object = (const cPtr_prefixOperatorExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_prefixOperatorExpressionAST) ;
  callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) object->mProperty_mExpression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 28)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_prefixOperatorExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_prefixOperatorExpressionAST.mSlotID,
                                                             extensionMethod_prefixOperatorExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_prefixOperatorExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_prefixOperatorExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//           Overriding extension method '@prefixOperatorExpressionAST noteExpressionTypesInPrecedenceGraph'           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_prefixOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                              GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_prefixOperatorExpressionAST * object = (const cPtr_prefixOperatorExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_prefixOperatorExpressionAST) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 36)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_prefixOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_prefixOperatorExpressionAST.mSlotID,
                                                             extensionMethod_prefixOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_prefixOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_prefixOperatorExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                    Overriding extension method '@prefixOperatorExpressionAST analyzeExpression'                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_prefixOperatorExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                           const GALGAS_PLMType constinArgument_inSelfType,
                                                                           const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                           const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                           const GALGAS_PLMType constinArgument_inOptionalTargetType,
                                                                           const GALGAS_semanticContext constinArgument_inContext,
                                                                           const GALGAS_mode constinArgument_inCurrentMode,
                                                                           GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                           GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                           GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                           GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                           GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                           GALGAS_objectIR & outArgument_outResult,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_prefixOperatorExpressionAST * object = (const cPtr_prefixOperatorExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_prefixOperatorExpressionAST) ;
  GALGAS_objectIR var_expressionResult_3412 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inOptionalTargetType, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_expressionResult_3412, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 58)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_expressionResult_3412, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 72)) ;
  }
  GALGAS_prefixOperatorMap var_prefixOperatorMap_3612 ;
  GALGAS_llvmBinaryOperation var_binaryOperator_3650 ;
  GALGAS_objectIR var_leftOperand_3674 ;
  switch (object->mProperty_mOp.enumValue ()) {
  case GALGAS_prefixOperator::kNotBuilt:
    break ;
  case GALGAS_prefixOperator::kEnum_unsignedComplement:
    {
      var_prefixOperatorMap_3612 = constinArgument_inContext.getter_mUnsignedComplementOperatorMap (HERE) ;
      var_binaryOperator_3650 = GALGAS_llvmBinaryOperation::constructor_xor (SOURCE_FILE ("expression-prefix-operators.galgas", 83)) ;
      switch (extensionGetter_type (var_expressionResult_3412, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 84)).getter_kind (HERE).enumValue ()) {
      case GALGAS_typeKind::kNotBuilt:
        break ;
      case GALGAS_typeKind::kEnum_arrayType:
        {
          TC_Array <C_FixItDescription> fixItArray0 ;
          inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("internal error"), fixItArray0  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 86)) ;
          var_leftOperand_3674.drop () ; // Release error dropped variable
        }
        break ;
      case GALGAS_typeKind::kEnum_dynamicArrayType:
        {
          TC_Array <C_FixItDescription> fixItArray1 ;
          inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("internal error"), fixItArray1  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 88)) ;
          var_leftOperand_3674.drop () ; // Release error dropped variable
        }
        break ;
      case GALGAS_typeKind::kEnum_opaque:
        {
          TC_Array <C_FixItDescription> fixItArray2 ;
          inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("internal error"), fixItArray2  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 90)) ;
          var_leftOperand_3674.drop () ; // Release error dropped variable
        }
        break ;
      case GALGAS_typeKind::kEnum_boolean:
      case GALGAS_typeKind::kEnum_void:
        {
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("internal error"), fixItArray3  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 92)) ;
          var_leftOperand_3674.drop () ; // Release error dropped variable
        }
        break ;
      case GALGAS_typeKind::kEnum_literalString:
        {
          TC_Array <C_FixItDescription> fixItArray4 ;
          inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("internal error"), fixItArray4  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 94)) ;
          var_leftOperand_3674.drop () ; // Release error dropped variable
        }
        break ;
      case GALGAS_typeKind::kEnum_enumeration:
        {
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("internal error"), fixItArray5  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 96)) ;
          var_leftOperand_3674.drop () ; // Release error dropped variable
        }
        break ;
      case GALGAS_typeKind::kEnum_structure:
        {
          TC_Array <C_FixItDescription> fixItArray6 ;
          inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("internal error"), fixItArray6  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 98)) ;
          var_leftOperand_3674.drop () ; // Release error dropped variable
        }
        break ;
      case GALGAS_typeKind::kEnum_syncTool:
        {
          TC_Array <C_FixItDescription> fixItArray7 ;
          inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("internal error"), fixItArray7  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 100)) ;
          var_leftOperand_3674.drop () ; // Release error dropped variable
        }
        break ;
      case GALGAS_typeKind::kEnum_function:
        {
          TC_Array <C_FixItDescription> fixItArray8 ;
          inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("internal error"), fixItArray8  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 102)) ;
          var_leftOperand_3674.drop () ; // Release error dropped variable
        }
        break ;
      case GALGAS_typeKind::kEnum_pointer:
        {
          TC_Array <C_FixItDescription> fixItArray9 ;
          inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("internal error"), fixItArray9  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 104)) ;
          var_leftOperand_3674.drop () ; // Release error dropped variable
        }
        break ;
      case GALGAS_typeKind::kEnum_staticInteger:
        {
          const enumGalgasBool test_10 = constinArgument_inOptionalTargetType.getter_kind (HERE).getter_isInteger (SOURCE_FILE ("expression-prefix-operators.galgas", 106)).boolEnum () ;
          if (kBoolTrue == test_10) {
            GALGAS_bigint var_minTarget_4871 ;
            GALGAS_bigint var_maxTarget_4890 ;
            GALGAS_bool joker_4892_2 ; // Joker input parameter
            GALGAS_uint joker_4892_1 ; // Joker input parameter
            constinArgument_inOptionalTargetType.getter_kind (HERE).method_integer (var_minTarget_4871, var_maxTarget_4890, joker_4892_2, joker_4892_1, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 107)) ;
            const enumGalgasBool test_11 = GALGAS_bool (kIsStrictInf, var_minTarget_4871.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 108)))).boolEnum () ;
            if (kBoolTrue == test_11) {
              TC_Array <C_FixItDescription> fixItArray12 ;
              inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("the ~ operator cannot be applied to an inferred signed integer type"), fixItArray12  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 109)) ;
              var_leftOperand_3674.drop () ; // Release error dropped variable
            }else if (kBoolFalse == test_11) {
              var_leftOperand_3674 = GALGAS_objectIR::constructor_literalInteger (function_staticIntegerType (inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 111)), var_maxTarget_4890  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 111)) ;
            }
          }else if (kBoolFalse == test_10) {
            TC_Array <C_FixItDescription> fixItArray13 ;
            inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("for the ~ operator, the inferred type should be an unsigned integer"), fixItArray13  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 114)) ;
            var_leftOperand_3674.drop () ; // Release error dropped variable
          }
        }
        break ;
      case GALGAS_typeKind::kEnum_integer:
        {
          const cEnumAssociatedValues_typeKind_integer * extractPtr_5432 = (const cEnumAssociatedValues_typeKind_integer *) (extensionGetter_type (var_expressionResult_3412, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 84)).getter_kind (HERE).unsafePointer ()) ;
          const GALGAS_uint extractedValue_bitCount = extractPtr_5432->mAssociatedValue3 ;
          var_leftOperand_3674 = GALGAS_objectIR::constructor_literalInteger (function_staticIntegerType (inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 117)), GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 117)).left_shift_operation (extractedValue_bitCount COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 117)).substract_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 117)), inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 117))  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 117)) ;
        }
        break ;
      }
    }
    break ;
  case GALGAS_prefixOperator::kEnum_notOperator:
    {
      var_prefixOperatorMap_3612 = constinArgument_inContext.getter_mNotOperatorMap (HERE) ;
      var_binaryOperator_3650 = GALGAS_llvmBinaryOperation::constructor_xor (SOURCE_FILE ("expression-prefix-operators.galgas", 121)) ;
      var_leftOperand_3674 = GALGAS_objectIR::constructor_literalInteger (function_staticIntegerType (inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 122)), GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 122))  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 122)) ;
    }
    break ;
  case GALGAS_prefixOperator::kEnum_minusNoOvf:
    {
      var_prefixOperatorMap_3612 = constinArgument_inContext.getter_mUnaryMinusOperatorMap (HERE) ;
      var_binaryOperator_3650 = GALGAS_llvmBinaryOperation::constructor_subNoOVF (SOURCE_FILE ("expression-prefix-operators.galgas", 125)) ;
      var_leftOperand_3674 = GALGAS_objectIR::constructor_literalInteger (function_staticIntegerType (inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 126)), GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 126))  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 126)) ;
    }
    break ;
  case GALGAS_prefixOperator::kEnum_minus:
    {
      var_prefixOperatorMap_3612 = constinArgument_inContext.getter_mUnaryMinusOperatorMap (HERE) ;
      const enumGalgasBool test_14 = GALGAS_bool (kIsEqual, constinArgument_inCurrentMode.objectCompare (GALGAS_mode::constructor_panicMode (SOURCE_FILE ("expression-prefix-operators.galgas", 129)))).boolEnum () ;
      if (kBoolTrue == test_14) {
        TC_Array <C_FixItDescription> fixItArray15 ;
        inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("operations that can generate panic are not allowed in ").add_operation (function_panicModeName (inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 131)), inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 131)).add_operation (GALGAS_string (" mode"), inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 131)), fixItArray15  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 130)) ;
      }
      const enumGalgasBool test_16 = GALGAS_bool (gOption_plm_5F_options_noPanicGeneration.getter_value ()).boolEnum () ;
      if (kBoolTrue == test_16) {
        var_binaryOperator_3650 = GALGAS_llvmBinaryOperation::constructor_subNoOVF (SOURCE_FILE ("expression-prefix-operators.galgas", 134)) ;
        var_leftOperand_3674 = GALGAS_objectIR::constructor_literalInteger (function_staticIntegerType (inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 135)), GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 135))  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 135)) ;
      }else if (kBoolFalse == test_16) {
        var_binaryOperator_3650 = GALGAS_llvmBinaryOperation::constructor_ssubOVF (SOURCE_FILE ("expression-prefix-operators.galgas", 137)) ;
        var_leftOperand_3674 = GALGAS_objectIR::constructor_literalInteger (function_staticIntegerType (inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 138)), GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 138))  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 138)) ;
      }
    }
    break ;
  }
  var_prefixOperatorMap_3612.method_searchKey (GALGAS_lstring::constructor_new (extensionGetter_plmTypeDescriptionName (var_expressionResult_3412, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 142)), object->mProperty_mOperatorLocation  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 142)), inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 142)) ;
  GALGAS_PLMType var_resultType_6471 = extensionGetter_type (var_expressionResult_3412, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 143)) ;
  const enumGalgasBool test_17 = var_expressionResult_3412.getter_isLiteralInteger (SOURCE_FILE ("expression-prefix-operators.galgas", 145)).boolEnum () ;
  if (kBoolTrue == test_17) {
    GALGAS_bigint var_value_6614 ;
    GALGAS_PLMType joker_6587_1 ; // Joker input parameter
    var_expressionResult_3412.method_literalInteger (joker_6587_1, var_value_6614, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 146)) ;
    GALGAS_bigint var_result_6634 ;
    switch (object->mProperty_mOp.enumValue ()) {
    case GALGAS_prefixOperator::kNotBuilt:
      break ;
    case GALGAS_prefixOperator::kEnum_minusNoOvf:
      {
        var_result_6634 = var_value_6614.operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 150)) ;
      }
      break ;
    case GALGAS_prefixOperator::kEnum_unsignedComplement:
      {
        const enumGalgasBool test_18 = constinArgument_inOptionalTargetType.getter_kind (HERE).getter_isInteger (SOURCE_FILE ("expression-prefix-operators.galgas", 152)).boolEnum () ;
        if (kBoolTrue == test_18) {
          GALGAS_bigint var_minTarget_6839 ;
          GALGAS_bigint var_maxTarget_6858 ;
          GALGAS_bool joker_6860_2 ; // Joker input parameter
          GALGAS_uint joker_6860_1 ; // Joker input parameter
          constinArgument_inOptionalTargetType.getter_kind (HERE).method_integer (var_minTarget_6839, var_maxTarget_6858, joker_6860_2, joker_6860_1, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 153)) ;
          const enumGalgasBool test_19 = GALGAS_bool (kIsStrictInf, var_minTarget_6839.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 154)))).boolEnum () ;
          if (kBoolTrue == test_19) {
            TC_Array <C_FixItDescription> fixItArray20 ;
            inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("the ~ operator cannot be applied to an inferred signed integer type"), fixItArray20  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 155)) ;
            var_result_6634.drop () ; // Release error dropped variable
          }else if (kBoolFalse == test_19) {
            var_result_6634 = var_value_6614.operator_xor (var_maxTarget_6858 COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 157)) ;
          }
        }else if (kBoolFalse == test_18) {
          TC_Array <C_FixItDescription> fixItArray21 ;
          inCompiler->emitSemanticError (object->mProperty_mOperatorLocation, GALGAS_string ("for the ~ operator, the inferred type should be an unsigned integer"), fixItArray21  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 160)) ;
          var_result_6634.drop () ; // Release error dropped variable
        }
      }
      break ;
    case GALGAS_prefixOperator::kEnum_minus:
      {
        var_result_6634 = var_value_6614.operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 163)) ;
      }
      break ;
    case GALGAS_prefixOperator::kEnum_notOperator:
      {
        var_result_6634 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 165)).operator_xor (var_value_6614 COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 165)) ;
      }
      break ;
    }
    outArgument_outResult = GALGAS_objectIR::constructor_literalInteger (var_resultType_6471, var_result_6634  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 167)) ;
  }else if (kBoolFalse == test_17) {
    {
    routine_getNewTempValue (var_resultType_6471, ioArgument_ioTemporaries, outArgument_outResult, inCompiler  COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 170)) ;
    }
    {
    extensionSetter_appendBinaryOperation (ioArgument_ioInstructionGenerationList, outArgument_outResult, extensionGetter_type (outArgument_outResult, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 174)), object->mProperty_mOperatorLocation, var_leftOperand_3674, var_binaryOperator_3650, var_expressionResult_3412, inCompiler COMMA_SOURCE_FILE ("expression-prefix-operators.galgas", 172)) ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_prefixOperatorExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_prefixOperatorExpressionAST.mSlotID,
                                          extensionMethod_prefixOperatorExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_prefixOperatorExpressionAST_analyzeExpression (defineExtensionMethod_prefixOperatorExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//          Overriding extension method '@literalIntegerInExpressionAST addDependenceEdgeForStaticExpression'          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_literalIntegerInExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * /* inObject */,
                                                                                                const GALGAS_lstring constinArgument_inConstantName,
                                                                                                GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioGraph.setter_addEdge (constinArgument_inConstantName, function_llvmTypeNameFromPLMname (function_staticIntegerTypeName (inCompiler COMMA_SOURCE_FILE ("expression-literal-integer.galgas", 34)).getter_nowhere (SOURCE_FILE ("expression-literal-integer.galgas", 34)), inCompiler COMMA_SOURCE_FILE ("expression-literal-integer.galgas", 34)) COMMA_SOURCE_FILE ("expression-literal-integer.galgas", 34)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_literalIntegerInExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_literalIntegerInExpressionAST.mSlotID,
                                                             extensionMethod_literalIntegerInExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_literalIntegerInExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_literalIntegerInExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//          Overriding extension method '@literalIntegerInExpressionAST noteExpressionTypesInPrecedenceGraph'          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_literalIntegerInExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * /* inObject */,
                                                                                                GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (function_staticIntegerTypeName (inCompiler COMMA_SOURCE_FILE ("expression-literal-integer.galgas", 42)).getter_nowhere (SOURCE_FILE ("expression-literal-integer.galgas", 42)), inCompiler COMMA_SOURCE_FILE ("expression-literal-integer.galgas", 42)) COMMA_SOURCE_FILE ("expression-literal-integer.galgas", 42)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_literalIntegerInExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_literalIntegerInExpressionAST.mSlotID,
                                                             extensionMethod_literalIntegerInExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_literalIntegerInExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_literalIntegerInExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                   Overriding extension method '@literalIntegerInExpressionAST analyzeExpression'                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_literalIntegerInExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                             const GALGAS_PLMType /* constinArgument_inSelfType */,
                                                                             const GALGAS_routineAttributes /* constinArgument_inRoutineAttributes */,
                                                                             const GALGAS_lstring /* constinArgument_inCallerNameForInvocationGraph */,
                                                                             const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                                                             const GALGAS_semanticContext /* constinArgument_inContext */,
                                                                             const GALGAS_mode /* constinArgument_inCurrentMode */,
                                                                             GALGAS_semanticTemporariesStruct & /* ioArgument_ioTemporaries */,
                                                                             GALGAS_staticEntityMap & /* ioArgument_ioStaticEntityMap */,
                                                                             GALGAS_universalValuedObjectMap & /* ioArgument_ioUniversalMap */,
                                                                             GALGAS_allocaList & /* ioArgument_ioAllocaList */,
                                                                             GALGAS_instructionListIR & /* ioArgument_ioInstructionGenerationList */,
                                                                             GALGAS_objectIR & outArgument_outResult,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_literalIntegerInExpressionAST * object = (const cPtr_literalIntegerInExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_literalIntegerInExpressionAST) ;
  outArgument_outResult = GALGAS_objectIR::constructor_literalInteger (function_staticIntegerType (inCompiler COMMA_SOURCE_FILE ("expression-literal-integer.galgas", 63)), object->mProperty_mLiteralInteger.getter_bigint (HERE)  COMMA_SOURCE_FILE ("expression-literal-integer.galgas", 63)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_literalIntegerInExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_literalIntegerInExpressionAST.mSlotID,
                                          extensionMethod_literalIntegerInExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_literalIntegerInExpressionAST_analyzeExpression (defineExtensionMethod_literalIntegerInExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//          Overriding extension method '@literalStringInExpressionAST addDependenceEdgeForStaticExpression'           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_literalStringInExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * /* inObject */,
                                                                                               const GALGAS_lstring constinArgument_inConstantName,
                                                                                               GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                               C_Compiler * inCompiler
                                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioGraph.setter_addEdge (constinArgument_inConstantName, function_llvmTypeNameFromPLMname (GALGAS_lstring::constructor_new (function_staticStringTypeName (inCompiler COMMA_SOURCE_FILE ("expression-literal-string.galgas", 34)), constinArgument_inConstantName.getter_location (HERE)  COMMA_SOURCE_FILE ("expression-literal-string.galgas", 34)), inCompiler COMMA_SOURCE_FILE ("expression-literal-string.galgas", 34)) COMMA_SOURCE_FILE ("expression-literal-string.galgas", 34)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_literalStringInExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_literalStringInExpressionAST.mSlotID,
                                                             extensionMethod_literalStringInExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_literalStringInExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_literalStringInExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//          Overriding extension method '@literalStringInExpressionAST noteExpressionTypesInPrecedenceGraph'           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_literalStringInExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * /* inObject */,
                                                                                               GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                               C_Compiler * inCompiler
                                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (function_staticIntegerTypeName (inCompiler COMMA_SOURCE_FILE ("expression-literal-string.galgas", 42)).getter_nowhere (SOURCE_FILE ("expression-literal-string.galgas", 42)), inCompiler COMMA_SOURCE_FILE ("expression-literal-string.galgas", 42)) COMMA_SOURCE_FILE ("expression-literal-string.galgas", 42)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_literalStringInExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_literalStringInExpressionAST.mSlotID,
                                                             extensionMethod_literalStringInExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_literalStringInExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_literalStringInExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                    Overriding extension method '@literalStringInExpressionAST analyzeExpression'                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_literalStringInExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                            const GALGAS_PLMType /* constinArgument_inSelfType */,
                                                                            const GALGAS_routineAttributes /* constinArgument_inRoutineAttributes */,
                                                                            const GALGAS_lstring /* constinArgument_inCallerNameForInvocationGraph */,
                                                                            const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                                                            const GALGAS_semanticContext /* constinArgument_inContext */,
                                                                            const GALGAS_mode /* constinArgument_inCurrentMode */,
                                                                            GALGAS_semanticTemporariesStruct & /* ioArgument_ioTemporaryIndex */,
                                                                            GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                            GALGAS_universalValuedObjectMap & /* ioArgument_ioUniversalMap */,
                                                                            GALGAS_allocaList & /* ioArgument_ioAllocaList */,
                                                                            GALGAS_instructionListIR & /* ioArgument_ioInstructionGenerationList */,
                                                                            GALGAS_objectIR & outArgument_outResult,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_literalStringInExpressionAST * object = (const cPtr_literalStringInExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_literalStringInExpressionAST) ;
  GALGAS_uint var_staticStringIndex_3699 ;
  {
  extensionSetter_findOrAddStaticString (ioArgument_ioStaticEntityMap, object->mProperty_mLiteralString.getter_string (HERE), var_staticStringIndex_3699, inCompiler COMMA_SOURCE_FILE ("expression-literal-string.galgas", 63)) ;
  }
  outArgument_outResult = GALGAS_objectIR::constructor_literalString (object->mProperty_mLiteralString.getter_string (HERE).getter_utf_38_Length (SOURCE_FILE ("expression-literal-string.galgas", 64)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("expression-literal-string.galgas", 64)), var_staticStringIndex_3699  COMMA_SOURCE_FILE ("expression-literal-string.galgas", 64)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_literalStringInExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_literalStringInExpressionAST.mSlotID,
                                          extensionMethod_literalStringInExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_literalStringInExpressionAST_analyzeExpression (defineExtensionMethod_literalStringInExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//          Overriding extension method '@literalBooleanInExpressionAST addDependenceEdgeForStaticExpression'          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_literalBooleanInExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * /* inObject */,
                                                                                                const GALGAS_lstring constinArgument_inConstantName,
                                                                                                GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioGraph.setter_addEdge (constinArgument_inConstantName, function_llvmTypeNameFromPLMname (function_boolBaseTypeName (inCompiler COMMA_SOURCE_FILE ("expression-true-false.galgas", 41)).getter_nowhere (SOURCE_FILE ("expression-true-false.galgas", 41)), inCompiler COMMA_SOURCE_FILE ("expression-true-false.galgas", 41)) COMMA_SOURCE_FILE ("expression-true-false.galgas", 41)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_literalBooleanInExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_literalBooleanInExpressionAST.mSlotID,
                                                             extensionMethod_literalBooleanInExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_literalBooleanInExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_literalBooleanInExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//          Overriding extension method '@literalBooleanInExpressionAST noteExpressionTypesInPrecedenceGraph'          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_literalBooleanInExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * /* inObject */,
                                                                                                GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (function_boolBaseTypeName (inCompiler COMMA_SOURCE_FILE ("expression-true-false.galgas", 49)).getter_nowhere (SOURCE_FILE ("expression-true-false.galgas", 49)), inCompiler COMMA_SOURCE_FILE ("expression-true-false.galgas", 49)) COMMA_SOURCE_FILE ("expression-true-false.galgas", 49)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_literalBooleanInExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_literalBooleanInExpressionAST.mSlotID,
                                                             extensionMethod_literalBooleanInExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_literalBooleanInExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_literalBooleanInExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                   Overriding extension method '@literalBooleanInExpressionAST analyzeExpression'                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_literalBooleanInExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                             const GALGAS_PLMType /* constinArgument_inSelfType */,
                                                                             const GALGAS_routineAttributes /* constinArgument_inRoutineAttributes */,
                                                                             const GALGAS_lstring /* constinArgument_inCallerNameForInvocationGraph */,
                                                                             const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                                                             const GALGAS_semanticContext constinArgument_inContext,
                                                                             const GALGAS_mode /* constinArgument_inCurrentMode */,
                                                                             GALGAS_semanticTemporariesStruct & /* ioArgument_ioTemporaryIndex */,
                                                                             GALGAS_staticEntityMap & /* ioArgument_ioStaticEntityMap */,
                                                                             GALGAS_universalValuedObjectMap & /* ioArgument_ioUniversalMap */,
                                                                             GALGAS_allocaList & /* ioArgument_ioAllocaList */,
                                                                             GALGAS_instructionListIR & /* ioArgument_ioInstructionGenerationList */,
                                                                             GALGAS_objectIR & outArgument_outResult,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_literalBooleanInExpressionAST * object = (const cPtr_literalBooleanInExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_literalBooleanInExpressionAST) ;
  GALGAS_bigint temp_0 ;
  const enumGalgasBool test_1 = object->mProperty_mValue.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("expression-true-false.galgas", 70)) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("expression-true-false.galgas", 70)) ;
  }
  outArgument_outResult = GALGAS_objectIR::constructor_literalInteger (extensionGetter_booleanType (constinArgument_inContext, inCompiler COMMA_SOURCE_FILE ("expression-true-false.galgas", 70)), temp_0  COMMA_SOURCE_FILE ("expression-true-false.galgas", 70)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_literalBooleanInExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_literalBooleanInExpressionAST.mSlotID,
                                          extensionMethod_literalBooleanInExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_literalBooleanInExpressionAST_analyzeExpression (defineExtensionMethod_literalBooleanInExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//             Overriding extension method '@registerInExpressionAST addDependenceEdgeForStaticExpression'             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_registerInExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * inObject,
                                                                                          const GALGAS_lstring constinArgument_inConstantName,
                                                                                          GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_registerInExpressionAST * object = (const cPtr_registerInExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_registerInExpressionAST) ;
  {
  ioArgument_ioGraph.setter_addEdge (constinArgument_inConstantName, object->mProperty_mControlRegisterLValue.getter_mRegisterGroupName (HERE) COMMA_SOURCE_FILE ("expression-control-register.galgas", 43)) ;
  }
  extensionMethod_addDependenceEdgeForStaticExpression (object->mProperty_mControlRegisterLValue, constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-control-register.galgas", 44)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_registerInExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_registerInExpressionAST.mSlotID,
                                                             extensionMethod_registerInExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_registerInExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_registerInExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//             Overriding extension method '@registerInExpressionAST noteExpressionTypesInPrecedenceGraph'             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_registerInExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                          GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_registerInExpressionAST * object = (const cPtr_registerInExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_registerInExpressionAST) ;
  extensionMethod_noteExpressionTypesInPrecedenceGraph (object->mProperty_mControlRegisterLValue, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-control-register.galgas", 52)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_registerInExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_registerInExpressionAST.mSlotID,
                                                             extensionMethod_registerInExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_registerInExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_registerInExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      Overriding extension method '@registerInExpressionAST analyzeExpression'                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_registerInExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                       const GALGAS_PLMType constinArgument_inSelfType,
                                                                       const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                       const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                       const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                                                       const GALGAS_semanticContext constinArgument_inContext,
                                                                       const GALGAS_mode constinArgument_inMode,
                                                                       GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                       GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                       GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                       GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                       GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                       GALGAS_objectIR & outArgument_outResult,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_registerInExpressionAST * object = (const cPtr_registerInExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_registerInExpressionAST) ;
  GALGAS_PLMType var_registerType_4261 ;
  GALGAS_sliceMap var_sliceMap_4312 ;
  GALGAS_string var_llvmRegisterAddressName_4369 ;
  GALGAS_uint joker_4284 ; // Joker input parameter
  extensionMethod_controlRegisterLValueSemanticAnalysis (object->mProperty_mControlRegisterLValue, GALGAS_bool (false), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_registerType_4261, joker_4284, var_sliceMap_4312, var_llvmRegisterAddressName_4369, inCompiler COMMA_SOURCE_FILE ("expression-control-register.galgas", 73)) ;
  {
  routine_getNewTempValue (var_registerType_4261, ioArgument_ioTemporaries, outArgument_outResult, inCompiler  COMMA_SOURCE_FILE ("expression-control-register.galgas", 91)) ;
  }
  {
  extensionSetter_appendLoadIndirectVolatileRegister (ioArgument_ioInstructionGenerationList, outArgument_outResult, var_llvmRegisterAddressName_4369, inCompiler COMMA_SOURCE_FILE ("expression-control-register.galgas", 92)) ;
  }
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mProperty_mFieldName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_llvmBinaryOperation var_accessOperator_4733 ;
    GALGAS_bigint var_accessRightOperand_4771 ;
    GALGAS_PLMType var_resultType_4802 ;
    var_sliceMap_4312.method_searchKey (object->mProperty_mFieldName, var_accessOperator_4733, var_accessRightOperand_4771, var_resultType_4802, inCompiler COMMA_SOURCE_FILE ("expression-control-register.galgas", 95)) ;
    GALGAS_objectIR var_resultIR_4871 ;
    {
    routine_getNewTempValue (var_resultType_4802, ioArgument_ioTemporaries, var_resultIR_4871, inCompiler  COMMA_SOURCE_FILE ("expression-control-register.galgas", 101)) ;
    }
    {
    extensionSetter_appendBinaryOperation (ioArgument_ioInstructionGenerationList, var_resultIR_4871, extensionGetter_type (outArgument_outResult, inCompiler COMMA_SOURCE_FILE ("expression-control-register.galgas", 104)), object->mProperty_mFieldName.getter_location (HERE), outArgument_outResult, var_accessOperator_4733, GALGAS_objectIR::constructor_literalInteger (function_staticIntegerType (inCompiler COMMA_SOURCE_FILE ("expression-control-register.galgas", 108)), var_accessRightOperand_4771  COMMA_SOURCE_FILE ("expression-control-register.galgas", 108)), inCompiler COMMA_SOURCE_FILE ("expression-control-register.galgas", 102)) ;
    }
    outArgument_outResult = var_resultIR_4871 ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_registerInExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_registerInExpressionAST.mSlotID,
                                          extensionMethod_registerInExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_registerInExpressionAST_analyzeExpression (defineExtensionMethod_registerInExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//          Overriding extension method '@registerConstantExpressionAST addDependenceEdgeForStaticExpression'          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_registerConstantExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * /* inObject */,
                                                                                                const GALGAS_lstring /* constinArgument_inConstantName */,
                                                                                                GALGAS_semanticTypePrecedenceGraph & /* ioArgument_ioGraph */,
                                                                                                C_Compiler * /* inCompiler */
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_registerConstantExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_registerConstantExpressionAST.mSlotID,
                                                             extensionMethod_registerConstantExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_registerConstantExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_registerConstantExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//          Overriding extension method '@registerConstantExpressionAST noteExpressionTypesInPrecedenceGraph'          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_registerConstantExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                                GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_registerConstantExpressionAST * object = (const cPtr_registerConstantExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_registerConstantExpressionAST) ;
  cEnumerator_registerIntegerFieldListAST enumerator_2988 (object->mProperty_mFieldValues, kENUMERATION_UP) ;
  while (enumerator_2988.hasCurrentObject ()) {
    callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) enumerator_2988.current_mExpression (HERE).ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 65)) ;
    enumerator_2988.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_registerConstantExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_registerConstantExpressionAST.mSlotID,
                                                             extensionMethod_registerConstantExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_registerConstantExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_registerConstantExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                   Overriding extension method '@registerConstantExpressionAST analyzeExpression'                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_registerConstantExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                             const GALGAS_PLMType constinArgument_inSelfType,
                                                                             const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                             const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                             const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                                                             const GALGAS_semanticContext constinArgument_inContext,
                                                                             const GALGAS_mode constinArgument_inCurrentMode,
                                                                             GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                             GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                             GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                             GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                             GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                             GALGAS_objectIR & outArgument_outResult,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_registerConstantExpressionAST * object = (const cPtr_registerConstantExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_registerConstantExpressionAST) ;
  GALGAS_controlRegisterMap var_controlRegisterMap_4300 ;
  GALGAS_registerGroupKind joker_4271 ; // Joker input parameter
  constinArgument_inContext.getter_mControlRegisterGroupMap (HERE).method_searchKey (object->mProperty_mRegisterGroupName, joker_4271, var_controlRegisterMap_4300, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 88)) ;
  GALGAS_PLMType var_registerType_4457 ;
  GALGAS_sliceMap var_registerBitSliceMap_4511 ;
  GALGAS_controlRegisterFieldMap var_registerFieldMap_4562 ;
  GALGAS_uint var_registerBitCount_4596 ;
  GALGAS_uint var_powerOfTwoForArraySize_4635 ;
  GALGAS_uint var_elementArraySize_4668 ;
  GALGAS_bool joker_4463_2 ; // Joker input parameter
  GALGAS_bool joker_4463_1 ; // Joker input parameter
  GALGAS_bigint joker_4568_2 ; // Joker input parameter
  GALGAS_controlRegisterFieldList joker_4568_1 ; // Joker input parameter
  var_controlRegisterMap_4300.method_searchKey (object->mProperty_mRegisterName, var_registerType_4457, joker_4463_2, joker_4463_1, var_registerBitSliceMap_4511, var_registerFieldMap_4562, joker_4568_2, joker_4568_1, var_registerBitCount_4596, var_powerOfTwoForArraySize_4635, var_elementArraySize_4668, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 94)) ;
  GALGAS_bigint var_accumulatedFieldStaticValues_4783 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 106)) ;
  GALGAS_operandIRList var_operandList_4817 = GALGAS_operandIRList::constructor_emptyList (SOURCE_FILE ("expression-register-value-from-slices.galgas", 107)) ;
  cEnumerator_registerIntegerFieldListAST enumerator_4886 (object->mProperty_mFieldValues, kENUMERATION_UP) ;
  while (enumerator_4886.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_4886.current_mFieldName (HERE).getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (enumerator_4886.current_mFieldName (HERE).getter_location (SOURCE_FILE ("expression-register-value-from-slices.galgas", 110)), GALGAS_string ("anonymous selector not allowed here"), fixItArray1  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 110)) ;
      var_operandList_4817.drop () ; // Release error dropped variable
    }else if (kBoolFalse == test_0) {
      GALGAS_uint var_fieldBitIndex_5095 ;
      GALGAS_uint var_fieldBitCount_5128 ;
      var_registerFieldMap_4562.method_searchKey (enumerator_4886.current_mFieldName (HERE), var_fieldBitIndex_5095, var_fieldBitCount_5128, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 112)) ;
      GALGAS_lstring var_inferredTypeName_5163 = GALGAS_lstring::constructor_new (GALGAS_string ("uint").add_operation (var_fieldBitCount_5128.getter_string (SOURCE_FILE ("expression-register-value-from-slices.galgas", 117)), inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 117)), enumerator_4886.current_mFieldName (HERE).getter_location (HERE)  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 117)) ;
      GALGAS_PLMType var_inferredType_5306 ;
      GALGAS_uint joker_5308_1 ; // Joker input parameter
      constinArgument_inContext.getter_mTypeMap (HERE).method_searchKey (var_inferredTypeName_5163, var_inferredType_5306, joker_5308_1, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 118)) ;
      GALGAS_objectIR var_expressionResult_5857 ;
      callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) enumerator_4886.current_mExpression (HERE).ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, var_inferredType_5306, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_expressionResult_5857, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 120)) ;
      {
      extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_expressionResult_5857, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 134)) ;
      }
      const enumGalgasBool test_2 = extensionGetter_type (var_expressionResult_5857, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 139)).getter_kind (HERE).getter_isStaticInteger (SOURCE_FILE ("expression-register-value-from-slices.galgas", 139)).boolEnum () ;
      if (kBoolTrue == test_2) {
        GALGAS_bigint var_value_6150 ;
        GALGAS_PLMType joker_6123_1 ; // Joker input parameter
        var_expressionResult_5857.method_literalInteger (joker_6123_1, var_value_6150, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 140)) ;
        const enumGalgasBool test_3 = GALGAS_bool (kIsStrictInf, var_value_6150.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 141)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          TC_Array <C_FixItDescription> fixItArray4 ;
          inCompiler->emitSemanticError (enumerator_4886.current_mExpressionLocation (HERE), GALGAS_string ("this integer expression should be positive"), fixItArray4  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 142)) ;
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_5 = GALGAS_bool (kIsStrictInf, var_value_6150.objectCompare (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 143)).left_shift_operation (var_fieldBitCount_5128 COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 143)))).boolEnum () ;
          if (kBoolTrue == test_5) {
            var_accumulatedFieldStaticValues_4783 = var_accumulatedFieldStaticValues_4783.operator_or (var_value_6150.left_shift_operation (var_fieldBitIndex_5095 COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 144)) COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 144)) ;
          }else if (kBoolFalse == test_5) {
            TC_Array <C_FixItDescription> fixItArray6 ;
            inCompiler->emitSemanticError (enumerator_4886.current_mExpressionLocation (HERE), GALGAS_string ("expression too large (should be < ").add_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 146)).left_shift_operation (var_fieldBitCount_5128 COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 146)).getter_string (SOURCE_FILE ("expression-register-value-from-slices.galgas", 146)), inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 146)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 146)), fixItArray6  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 146)) ;
          }
        }
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_7 = extensionGetter_type (var_expressionResult_5857, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 148)).getter_kind (HERE).getter_isInteger (SOURCE_FILE ("expression-register-value-from-slices.galgas", 148)).boolEnum () ;
        if (kBoolTrue == test_7) {
          GALGAS_bool var_unsigned_6671 ;
          GALGAS_uint var_expressionBitCount_6710 ;
          GALGAS_bigint joker_6640_2 ; // Joker input parameter
          GALGAS_bigint joker_6640_1 ; // Joker input parameter
          extensionGetter_type (var_expressionResult_5857, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 149)).getter_kind (HERE).method_integer (joker_6640_2, joker_6640_1, var_unsigned_6671, var_expressionBitCount_6710, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 149)) ;
          const enumGalgasBool test_8 = var_unsigned_6671.operator_not (SOURCE_FILE ("expression-register-value-from-slices.galgas", 150)).boolEnum () ;
          if (kBoolTrue == test_8) {
            TC_Array <C_FixItDescription> fixItArray9 ;
            inCompiler->emitSemanticError (enumerator_4886.current_mExpressionLocation (HERE), GALGAS_string ("an unsigned integer expression is required here"), fixItArray9  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 151)) ;
          }else if (kBoolFalse == test_8) {
            const enumGalgasBool test_10 = GALGAS_bool (kIsNotEqual, var_expressionBitCount_6710.objectCompare (var_fieldBitCount_5128)).boolEnum () ;
            if (kBoolTrue == test_10) {
              TC_Array <C_FixItDescription> fixItArray11 ;
              inCompiler->emitSemanticError (enumerator_4886.current_mExpressionLocation (HERE), GALGAS_string ("type error, $uint").add_operation (var_fieldBitCount_5128.getter_string (SOURCE_FILE ("expression-register-value-from-slices.galgas", 153)), inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 153)).add_operation (GALGAS_string (" type required"), inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 153)), fixItArray11  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 153)) ;
            }else if (kBoolFalse == test_10) {
              GALGAS_objectIR var_partialResult_7079 = var_expressionResult_5857 ;
              const enumGalgasBool test_12 = GALGAS_bool (kIsStrictInf, var_expressionBitCount_6710.objectCompare (var_registerBitCount_4596)).boolEnum () ;
              if (kBoolTrue == test_12) {
                GALGAS_objectIR var_extendedResult_7233 ;
                {
                routine_getNewTempValue (var_registerType_4457, ioArgument_ioTemporaries, var_extendedResult_7233, inCompiler  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 158)) ;
                }
                {
                extensionSetter_appendExtend (ioArgument_ioInstructionGenerationList, var_extendedResult_7233, var_partialResult_7079, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 159)) ;
                }
                var_partialResult_7079 = var_extendedResult_7233 ;
              }
              GALGAS_objectIR var_shiftedResult_7487 ;
              {
              routine_getNewTempValue (var_registerType_4457, ioArgument_ioTemporaries, var_shiftedResult_7487, inCompiler  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 163)) ;
              }
              {
              extensionSetter_appendShiftLeft (ioArgument_ioInstructionGenerationList, var_shiftedResult_7487, var_partialResult_7079, var_fieldBitIndex_5095, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 164)) ;
              }
              var_operandList_4817.addAssign_operation (var_shiftedResult_7487  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 166)) ;
            }
          }
        }
      }
    }
    enumerator_4886.gotoNextObject () ;
  }
  outArgument_outResult = GALGAS_objectIR::constructor_literalInteger (var_registerType_4457, var_accumulatedFieldStaticValues_4783  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 172)) ;
  cEnumerator_operandIRList enumerator_7877 (var_operandList_4817, kENUMERATION_UP) ;
  while (enumerator_7877.hasCurrentObject ()) {
    GALGAS_objectIR var_newResult_7946 ;
    {
    routine_getNewTempValue (var_registerType_4457, ioArgument_ioTemporaries, var_newResult_7946, inCompiler  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 174)) ;
    }
    {
    extensionSetter_appendBinaryOperation (ioArgument_ioInstructionGenerationList, var_newResult_7946, extensionGetter_type (var_newResult_7946, inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 177)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 178)), outArgument_outResult, GALGAS_llvmBinaryOperation::constructor_ior (SOURCE_FILE ("expression-register-value-from-slices.galgas", 180)), enumerator_7877.current_mOperand (HERE), inCompiler COMMA_SOURCE_FILE ("expression-register-value-from-slices.galgas", 175)) ;
    }
    outArgument_outResult = var_newResult_7946 ;
    enumerator_7877.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_registerConstantExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_registerConstantExpressionAST.mSlotID,
                                          extensionMethod_registerConstantExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_registerConstantExpressionAST_analyzeExpression (defineExtensionMethod_registerConstantExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//             Overriding extension method '@primaryInExpressionAST addDependenceEdgeForStaticExpression'              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_primaryInExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * inObject,
                                                                                         const GALGAS_lstring constinArgument_inConstantName,
                                                                                         GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_primaryInExpressionAST * object = (const cPtr_primaryInExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_primaryInExpressionAST) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mProperty_mReceiverName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    ioArgument_ioGraph.setter_addEdge (constinArgument_inConstantName, object->mProperty_mReceiverName COMMA_SOURCE_FILE ("expression-primary.galgas", 91)) ;
    }
  }
  cEnumerator_primaryInExpressionAccessListAST enumerator_3720 (object->mProperty_mAccessList, kENUMERATION_UP) ;
  while (enumerator_3720.hasCurrentObject ()) {
    switch (enumerator_3720.current_mAccess (HERE).enumValue ()) {
    case GALGAS_primaryInExpressionAccessAST::kNotBuilt:
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_integerSlice:
      {
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_property:
      {
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_arrayAccess:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_arrayAccess * extractPtr_3939 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_arrayAccess *) (enumerator_3720.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_indexExpression = extractPtr_3939->mAssociatedValue0 ;
        callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) extractedValue_indexExpression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 98)) ;
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_funcCall:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_funcCall * extractPtr_4480 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_funcCall *) (enumerator_3720.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_effectiveArgumentListAST extractedValue_arguments = extractPtr_4480->mAssociatedValue1 ;
        cEnumerator_effectiveArgumentListAST enumerator_4027 (extractedValue_arguments, kENUMERATION_UP) ;
        while (enumerator_4027.hasCurrentObject ()) {
          switch (enumerator_4027.current_mEffectiveParameterKind (HERE).enumValue ()) {
          case GALGAS_effectiveArgumentPassingModeAST::kNotBuilt:
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_input:
            {
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_inputWithType:
            {
              const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType * extractPtr_4270 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType *) (enumerator_4027.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
              const GALGAS_lstring extractedValue_typeName = extractPtr_4270->mAssociatedValue1 ;
              const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, extractedValue_typeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
              if (kBoolTrue == test_1) {
                {
                ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (extractedValue_typeName, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 105)) COMMA_SOURCE_FILE ("expression-primary.galgas", 105)) ;
                }
              }
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_output:
            {
              const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output * extractPtr_4383 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output *) (enumerator_4027.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
              const GALGAS_expressionAST extractedValue_expression = extractPtr_4383->mAssociatedValue0 ;
              callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) extractedValue_expression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 107)) ;
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInput:
            {
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInputSelfVariable:
            {
            }
            break ;
          }
          enumerator_4027.gotoNextObject () ;
        }
      }
      break ;
    }
    enumerator_3720.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_primaryInExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_primaryInExpressionAST.mSlotID,
                                                             extensionMethod_primaryInExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_primaryInExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_primaryInExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//             Overriding extension method '@primaryInExpressionAST noteExpressionTypesInPrecedenceGraph'              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_primaryInExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                         GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_primaryInExpressionAST * object = (const cPtr_primaryInExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_primaryInExpressionAST) ;
  cEnumerator_primaryInExpressionAccessListAST enumerator_5009 (object->mProperty_mAccessList, kENUMERATION_UP) ;
  while (enumerator_5009.hasCurrentObject ()) {
    switch (enumerator_5009.current_mAccess (HERE).enumValue ()) {
    case GALGAS_primaryInExpressionAccessAST::kNotBuilt:
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_integerSlice:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_integerSlice * extractPtr_5218 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_integerSlice *) (enumerator_5009.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_lbigint extractedValue_low = extractPtr_5218->mAssociatedValue0 ;
        const GALGAS_lbigint extractedValue_high = extractPtr_5218->mAssociatedValue1 ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, extractedValue_high.getter_bigint (HERE).objectCompare (extractedValue_low.getter_bigint (HERE))).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          extensionSetter_noteUINTType (ioArgument_ioGraph, extractedValue_high.getter_bigint (HERE).substract_operation (extractedValue_low.getter_bigint (HERE), inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 125)).add_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 125)), inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 125)).getter_uint (inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 125)), extractedValue_low.getter_location (HERE), inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 125)) ;
          }
        }
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_property:
      {
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_arrayAccess:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_arrayAccess * extractPtr_5371 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_arrayAccess *) (enumerator_5009.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_indexExpression = extractPtr_5371->mAssociatedValue0 ;
        callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) extractedValue_indexExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 129)) ;
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_funcCall:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_funcCall * extractPtr_5896 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_funcCall *) (enumerator_5009.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_effectiveArgumentListAST extractedValue_arguments = extractPtr_5896->mAssociatedValue1 ;
        cEnumerator_effectiveArgumentListAST enumerator_5459 (extractedValue_arguments, kENUMERATION_UP) ;
        while (enumerator_5459.hasCurrentObject ()) {
          switch (enumerator_5459.current_mEffectiveParameterKind (HERE).enumValue ()) {
          case GALGAS_effectiveArgumentPassingModeAST::kNotBuilt:
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_input:
            {
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_inputWithType:
            {
              const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType * extractPtr_5702 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType *) (enumerator_5459.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
              const GALGAS_lstring extractedValue_typeName = extractPtr_5702->mAssociatedValue1 ;
              const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, extractedValue_typeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
              if (kBoolTrue == test_1) {
                {
                ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (extractedValue_typeName, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 136)) COMMA_SOURCE_FILE ("expression-primary.galgas", 136)) ;
                }
              }
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_output:
            {
              const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output * extractPtr_5799 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output *) (enumerator_5459.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
              const GALGAS_expressionAST extractedValue_expression = extractPtr_5799->mAssociatedValue0 ;
              callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) extractedValue_expression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 138)) ;
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInput:
            {
            }
            break ;
          case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInputSelfVariable:
            {
            }
            break ;
          }
          enumerator_5459.gotoNextObject () ;
        }
      }
      break ;
    }
    enumerator_5009.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_primaryInExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_primaryInExpressionAST.mSlotID,
                                                             extensionMethod_primaryInExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_primaryInExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_primaryInExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                       Overriding extension method '@primaryInExpressionAST analyzeExpression'                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_primaryInExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                      const GALGAS_PLMType constinArgument_inSelfType,
                                                                      const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                      const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                      const GALGAS_PLMType constinArgument_inOptionalTargetType,
                                                                      const GALGAS_semanticContext constinArgument_inContext,
                                                                      const GALGAS_mode constinArgument_inMode,
                                                                      GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                      GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                      GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                      GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                      GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                      GALGAS_objectIR & outArgument_outResult,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_primaryInExpressionAST * object = (const cPtr_primaryInExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_primaryInExpressionAST) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mProperty_mReceiverName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = constinArgument_inRoutineAttributes.getter_guard (SOURCE_FILE ("expression-primary.galgas", 167)).boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mProperty_mReceiverName.getter_location (SOURCE_FILE ("expression-primary.galgas", 168)), GALGAS_string ("in guard, only 'self' properties may be accessed"), fixItArray2  COMMA_SOURCE_FILE ("expression-primary.galgas", 168)) ;
      outArgument_outResult.drop () ; // Release error dropped variable
    }else if (kBoolFalse == test_1) {
      const GALGAS_primaryInExpressionAST temp_3 = object ;
      callExtensionMethod_analyzePrimaryExpressionNoSelf ((const cPtr_primaryInExpressionAST *) temp_3.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inOptionalTargetType, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, outArgument_outResult, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 170)) ;
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_inSelfType.getter_kind (HERE).objectCompare (GALGAS_typeKind::constructor_void (SOURCE_FILE ("expression-primary.galgas", 185)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      TC_Array <C_FixItDescription> fixItArray5 ;
      inCompiler->emitSemanticError (object->mProperty_mReceiverName.getter_location (SOURCE_FILE ("expression-primary.galgas", 186)), GALGAS_string ("'self' is not available in this context"), fixItArray5  COMMA_SOURCE_FILE ("expression-primary.galgas", 186)) ;
      outArgument_outResult.drop () ; // Release error dropped variable
    }else if (kBoolFalse == test_4) {
      const GALGAS_primaryInExpressionAST temp_6 = object ;
      callExtensionMethod_analyzePrimaryExpressionWithSelf ((const cPtr_primaryInExpressionAST *) temp_6.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inOptionalTargetType, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, outArgument_outResult, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 188)) ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_primaryInExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_primaryInExpressionAST.mSlotID,
                                          extensionMethod_primaryInExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_primaryInExpressionAST_analyzeExpression (defineExtensionMethod_primaryInExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Routine 'procAnalyzeAccesListInExpression'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_procAnalyzeAccesListInExpression (const GALGAS_PLMType constinArgument_inSelfType,
                                               const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                               const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                               const GALGAS_PLMType constinArgument_inOptionalTargetType,
                                               const GALGAS_semanticContext constinArgument_inContext,
                                               const GALGAS_mode constinArgument_inMode,
                                               GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                               GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                               GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                               GALGAS_allocaList & ioArgument_ioAllocaList,
                                               GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                               const GALGAS_primaryInExpressionAccessListAST constinArgument_inAccessList,
                                               GALGAS_objectIR & ioArgument_ioResult,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_primaryInExpressionAccessListAST enumerator_14223 (constinArgument_inAccessList, kENUMERATION_UP) ;
  while (enumerator_14223.hasCurrentObject ()) {
    switch (enumerator_14223.current_mAccess (HERE).enumValue ()) {
    case GALGAS_primaryInExpressionAccessAST::kNotBuilt:
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_integerSlice:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_integerSlice * extractPtr_14602 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_integerSlice *) (enumerator_14223.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_lbigint extractedValue_low = extractPtr_14602->mAssociatedValue0 ;
        const GALGAS_lbigint extractedValue_high = extractPtr_14602->mAssociatedValue1 ;
        {
        routine_handleSliceInExpression (constinArgument_inContext, ioArgument_ioResult, extractedValue_low, extractedValue_high, ioArgument_ioTemporaries, ioArgument_ioInstructionGenerationList, inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 358)) ;
        }
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_property:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_property * extractPtr_14826 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_property *) (enumerator_14223.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_lstring extractedValue_propertyName = extractPtr_14826->mAssociatedValue0 ;
        {
        routine_handlePropertyAccessInExpression (ioArgument_ioResult, extractedValue_propertyName, ioArgument_ioTemporaries, ioArgument_ioInstructionGenerationList, inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 367)) ;
        }
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_arrayAccess:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_arrayAccess * extractPtr_15453 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_arrayAccess *) (enumerator_14223.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_indexExpression = extractPtr_15453->mAssociatedValue0 ;
        const GALGAS_location extractedValue_endOfIndex = extractPtr_15453->mAssociatedValue1 ;
        {
        routine_handleArrayAccessInExpression (ioArgument_ioResult, extractedValue_indexExpression, extractedValue_endOfIndex, constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inOptionalTargetType, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 374)) ;
        }
      }
      break ;
    case GALGAS_primaryInExpressionAccessAST::kEnum_funcCall:
      {
        const cEnumAssociatedValues_primaryInExpressionAccessAST_funcCall * extractPtr_16205 = (const cEnumAssociatedValues_primaryInExpressionAccessAST_funcCall *) (enumerator_14223.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_lstring extractedValue_methodName = extractPtr_16205->mAssociatedValue0 ;
        const GALGAS_effectiveArgumentListAST extractedValue_arguments = extractPtr_16205->mAssociatedValue1 ;
        const GALGAS_location extractedValue_errorLocation = extractPtr_16205->mAssociatedValue2 ;
        const enumGalgasBool test_0 = constinArgument_inRoutineAttributes.getter_guard (SOURCE_FILE ("expression-primary.galgas", 391)).boolEnum () ;
        if (kBoolTrue == test_0) {
          TC_Array <C_FixItDescription> fixItArray1 ;
          inCompiler->emitSemanticError (extractedValue_errorLocation, GALGAS_string ("a method cannot be called in guard"), fixItArray1  COMMA_SOURCE_FILE ("expression-primary.galgas", 392)) ;
          ioArgument_ioResult.drop () ; // Release error dropped variable
        }else if (kBoolFalse == test_0) {
          {
          routine_handleFunctionCallInExpression (extractedValue_methodName, ioArgument_ioResult, constinArgument_inSelfType, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, constinArgument_inRoutineAttributes, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, extractedValue_arguments, ioArgument_ioInstructionGenerationList, inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 394)) ;
          }
        }
      }
      break ;
    }
    enumerator_14223.gotoNextObject () ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          Routine 'handleSliceInExpression'                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_handleSliceInExpression (const GALGAS_semanticContext constinArgument_inContext,
                                      GALGAS_objectIR & ioArgument_ioResult,
                                      const GALGAS_lbigint constinArgument_inLow,
                                      const GALGAS_lbigint constinArgument_inHigh,
                                      GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                      GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, constinArgument_inLow.getter_bigint (HERE).objectCompare (constinArgument_inHigh.getter_bigint (HERE))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (constinArgument_inLow.getter_location (SOURCE_FILE ("expression-primary.galgas", 505)), GALGAS_string ("low bound should be lower or equal to high bound"), fixItArray1  COMMA_SOURCE_FILE ("expression-primary.galgas", 505)) ;
    ioArgument_ioResult.drop () ; // Release error dropped variable
  }else if (kBoolFalse == test_0) {
    GALGAS_bool test_2 = extensionGetter_type (ioArgument_ioResult, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 506)).getter_kind (HERE).getter_isInteger (SOURCE_FILE ("expression-primary.galgas", 506)) ;
    if (kBoolTrue != test_2.boolEnum ()) {
      test_2 = extensionGetter_type (ioArgument_ioResult, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 506)).getter_kind (HERE).getter_isStaticInteger (SOURCE_FILE ("expression-primary.galgas", 506)) ;
    }
    const enumGalgasBool test_3 = test_2.operator_not (SOURCE_FILE ("expression-primary.galgas", 506)).boolEnum () ;
    if (kBoolTrue == test_3) {
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (constinArgument_inLow.getter_location (SOURCE_FILE ("expression-primary.galgas", 507)), GALGAS_string ("Invalid, receiver is not an integer"), fixItArray4  COMMA_SOURCE_FILE ("expression-primary.galgas", 507)) ;
      ioArgument_ioResult.drop () ; // Release error dropped variable
    }else if (kBoolFalse == test_3) {
      {
      extensionSetter_appendLogicalShiftRight (ioArgument_ioInstructionGenerationList, ioArgument_ioResult, constinArgument_inLow.getter_bigint (HERE).getter_uint (inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 510)), ioArgument_ioTemporaries, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 510)) ;
      }
      GALGAS_lstring var_resultIntegerName_20025 = GALGAS_lstring::constructor_new (GALGAS_string ("uint").add_operation (constinArgument_inHigh.getter_bigint (HERE).substract_operation (constinArgument_inLow.getter_bigint (HERE), inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 512)).add_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 512)), inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 512)).getter_string (SOURCE_FILE ("expression-primary.galgas", 512)), inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 512)), constinArgument_inLow.getter_location (HERE)  COMMA_SOURCE_FILE ("expression-primary.galgas", 512)) ;
      GALGAS_PLMType var_sliceType_20182 ;
      GALGAS_uint joker_20184_1 ; // Joker input parameter
      constinArgument_inContext.getter_mTypeMap (HERE).method_searchKey (var_resultIntegerName_20025, var_sliceType_20182, joker_20184_1, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 513)) ;
      {
      extensionSetter_appendTrunc (ioArgument_ioInstructionGenerationList, var_sliceType_20182, ioArgument_ioResult, ioArgument_ioTemporaries, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 514)) ;
      }
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Routine 'handlePropertyAccessInExpression'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_handlePropertyAccessInExpression (GALGAS_objectIR & ioArgument_ioResult,
                                               const GALGAS_lstring constinArgument_inPropertyName,
                                               GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                               GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_PLMType var_type_20633 = extensionGetter_type (ioArgument_ioResult, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 526)) ;
  GALGAS_propertyMap var_propertyMap_20682 = var_type_20633.getter_propertyMap (HERE) ;
  GALGAS_propertyAccessKind var_accessKind_20781 ;
  GALGAS_bool joker_20744 ; // Joker input parameter
  var_propertyMap_20682.method_searchKey (constinArgument_inPropertyName, joker_20744, var_accessKind_20781, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 528)) ;
  switch (var_accessKind_20781.enumValue ()) {
  case GALGAS_propertyAccessKind::kNotBuilt:
    break ;
  case GALGAS_propertyAccessKind::kEnum_nonVirtualMethod:
    {
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_inPropertyName.getter_location (SOURCE_FILE ("expression-primary.galgas", 531)), GALGAS_string ("a method cannot be used in this context"), fixItArray0  COMMA_SOURCE_FILE ("expression-primary.galgas", 531)) ;
      ioArgument_ioResult.drop () ; // Release error dropped variable
    }
    break ;
  case GALGAS_propertyAccessKind::kEnum_constantProperty:
    {
      const cEnumAssociatedValues_propertyAccessKind_constantProperty * extractPtr_20977 = (const cEnumAssociatedValues_propertyAccessKind_constantProperty *) (var_accessKind_20781.unsafePointer ()) ;
      const GALGAS_objectIR extractedValue_value = extractPtr_20977->mAssociatedValue0 ;
      ioArgument_ioResult = extractedValue_value ;
    }
    break ;
  case GALGAS_propertyAccessKind::kEnum_singleton:
    {
      const cEnumAssociatedValues_propertyAccessKind_singleton * extractPtr_21030 = (const cEnumAssociatedValues_propertyAccessKind_singleton *) (var_accessKind_20781.unsafePointer ()) ;
      const GALGAS_objectIR extractedValue_object = extractPtr_21030->mAssociatedValue0 ;
      ioArgument_ioResult = extractedValue_object ;
    }
    break ;
  case GALGAS_propertyAccessKind::kEnum_indexed:
    {
      const cEnumAssociatedValues_propertyAccessKind_indexed * extractPtr_21421 = (const cEnumAssociatedValues_propertyAccessKind_indexed *) (var_accessKind_20781.unsafePointer ()) ;
      const GALGAS_PLMType extractedValue_propertyType = extractPtr_21421->mAssociatedValue0 ;
      const GALGAS_uint extractedValue_propertyIndex = extractPtr_21421->mAssociatedValue1 ;
      GALGAS_string var_property_5F_llvmName_21150 ;
      {
      extensionSetter_newTempLLVMVar (ioArgument_ioTemporaries, var_property_5F_llvmName_21150, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 537)) ;
      }
      {
      extensionSetter_appendGetUniversalPropertyReference (ioArgument_ioInstructionGenerationList, extensionGetter_type (ioArgument_ioResult, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 539)), extensionGetter_llvmName (ioArgument_ioResult, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 540)), var_property_5F_llvmName_21150, extractedValue_propertyIndex, constinArgument_inPropertyName.getter_string (SOURCE_FILE ("expression-primary.galgas", 543)), inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 538)) ;
      }
      ioArgument_ioResult = GALGAS_objectIR::constructor_reference (extractedValue_propertyType, var_property_5F_llvmName_21150  COMMA_SOURCE_FILE ("expression-primary.galgas", 545)) ;
    }
    break ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                       Routine 'handleArrayAccessInExpression'                                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_handleArrayAccessInExpression (GALGAS_objectIR & ioArgument_ioResult,
                                            const GALGAS_expressionAST constinArgument_inIndexExpression,
                                            const GALGAS_location constinArgument_inEndOfIndex,
                                            const GALGAS_PLMType constinArgument_inSelfType,
                                            const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                            const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                            const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                            const GALGAS_semanticContext constinArgument_inContext,
                                            const GALGAS_mode constinArgument_inMode,
                                            GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                            GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                            GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                            GALGAS_allocaList & ioArgument_ioAllocaList,
                                            GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = extensionGetter_type (ioArgument_ioResult, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 568)).getter_kind (HERE).getter_isArrayType (SOURCE_FILE ("expression-primary.galgas", 568)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_PLMType var_elementType_22413 ;
    GALGAS_bigint var_arraySize_22441 ;
    extensionGetter_type (ioArgument_ioResult, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 569)).getter_kind (HERE).method_arrayType (var_elementType_22413, var_arraySize_22441, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 569)) ;
    GALGAS_objectIR var_indexIR_22965 ;
    {
    routine_handleArraySubscriptNew (constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, constinArgument_inIndexExpression, constinArgument_inEndOfIndex, var_arraySize_22441, var_elementType_22413, ioArgument_ioInstructionGenerationList, var_indexIR_22965, inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 570)) ;
    }
    GALGAS_objectIR var_result_23280 ;
    {
    extensionSetter_appendGetArrayElementReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, ioArgument_ioResult, var_indexIR_22965, var_result_23280, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 589)) ;
    }
    ioArgument_ioResult = var_result_23280 ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (constinArgument_inEndOfIndex, GALGAS_string ("the receiver is not an array and does not accept subscripting"), fixItArray1  COMMA_SOURCE_FILE ("expression-primary.galgas", 597)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                      Routine 'handleFunctionCallInExpression'                                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_handleFunctionCallInExpression (const GALGAS_lstring constinArgument_inMethodName,
                                             GALGAS_objectIR & ioArgument_ioObjectIR,
                                             const GALGAS_PLMType constinArgument_inSelfType,
                                             const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                             const GALGAS_semanticContext constinArgument_inContext,
                                             const GALGAS_mode constinArgument_inMode,
                                             const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                             GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                             GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                             GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                             GALGAS_allocaList & ioArgument_ioAllocaList,
                                             const GALGAS_effectiveArgumentListAST constinArgument_inArguments,
                                             GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_PLMType var_receiverType_24200 = extensionGetter_type (ioArgument_ioObjectIR, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 618)) ;
  GALGAS_propertyMap var_propertyMap_24251 = var_receiverType_24200.getter_propertyMap (HERE) ;
  GALGAS_lstring var_key_24288 = function_routineMangledNameFromCall (GALGAS_string::makeEmptyString (), constinArgument_inMethodName, constinArgument_inArguments, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 620)) ;
  GALGAS_propertyAccessKind var_propertyAccess_24423 ;
  GALGAS_bool joker_24382 ; // Joker input parameter
  var_propertyMap_24251.method_searchKey (var_key_24288, joker_24382, var_propertyAccess_24423, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 621)) ;
  switch (var_propertyAccess_24423.enumValue ()) {
  case GALGAS_propertyAccessKind::kNotBuilt:
    break ;
  case GALGAS_propertyAccessKind::kEnum_constantProperty:
    {
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_inMethodName.getter_location (SOURCE_FILE ("expression-primary.galgas", 624)), GALGAS_string ("a constant cannot be used as method"), fixItArray0  COMMA_SOURCE_FILE ("expression-primary.galgas", 624)) ;
      ioArgument_ioObjectIR.drop () ; // Release error dropped variable
    }
    break ;
  case GALGAS_propertyAccessKind::kEnum_nonVirtualMethod:
    {
      const cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod * extractPtr_26855 = (const cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod *) (var_propertyAccess_24423.unsafePointer ()) ;
      const GALGAS_routineDescriptor extractedValue_routineDescriptor = extractPtr_26855->mAssociatedValue0 ;
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, extractedValue_routineDescriptor.getter_returnTypeProxy (HERE).getter_type (inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 627)).getter_kind (HERE).objectCompare (GALGAS_typeKind::constructor_void (SOURCE_FILE ("expression-primary.galgas", 627)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (constinArgument_inMethodName.getter_location (SOURCE_FILE ("expression-primary.galgas", 628)), GALGAS_string ("not a function (returns no value)"), fixItArray2  COMMA_SOURCE_FILE ("expression-primary.galgas", 628)) ;
        ioArgument_ioObjectIR.drop () ; // Release error dropped variable
      }else if (kBoolFalse == test_1) {
        GALGAS_calleeKindIR var_calleeKind_24857 = function_checkMode (constinArgument_inMode, extensionGetter_executionMode (extractedValue_routineDescriptor.getter_routineKind (HERE), inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 633)), extractedValue_routineDescriptor.getter_routineKind (HERE), constinArgument_inMethodName.getter_location (HERE), inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 631)) ;
        {
        extensionSetter_referenceFromPossibleValue (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, ioArgument_ioAllocaList, ioArgument_ioObjectIR, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 638)) ;
        }
        GALGAS_procCallEffectiveParameterListIR var_effectiveParameterListIR_25320 = GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (SOURCE_FILE ("expression-primary.galgas", 640)) ;
        var_effectiveParameterListIR_25320.addAssign_operation (GALGAS_procEffectiveParameterPassingModeIR::constructor_outputInput (SOURCE_FILE ("expression-primary.galgas", 641)), ioArgument_ioObjectIR  COMMA_SOURCE_FILE ("expression-primary.galgas", 641)) ;
        {
        routine_analyzeEffectiveParameters (constinArgument_inSelfType, constinArgument_inRoutineAttributes, extractedValue_routineDescriptor.getter_signature (HERE), constinArgument_inArguments, constinArgument_inMethodName.getter_location (HERE), constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_effectiveParameterListIR_25320, inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 643)) ;
        }
        GALGAS_objectIR var_callReturnedResult_26217 ;
        {
        routine_getNewTempValue (extractedValue_routineDescriptor.getter_returnTypeProxy (HERE).getter_type (inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 660)), ioArgument_ioTemporaries, var_callReturnedResult_26217, inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 660)) ;
        }
        GALGAS_lstring var_routineMangledName_26270 = function_routineMangledNameFromCall (function_llvmTypeStringFromPLMname (extensionGetter_type (ioArgument_ioObjectIR, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 662)).getter_plmTypeDescriptionName (HERE), inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 662)), constinArgument_inMethodName, constinArgument_inArguments, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 662)) ;
        ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_standaloneRoutineCallIR::constructor_new (GALGAS_string::makeEmptyString (), var_callReturnedResult_26217, var_routineMangledName_26270, var_routineMangledName_26270, var_calleeKind_24857, var_effectiveParameterListIR_25320  COMMA_SOURCE_FILE ("expression-primary.galgas", 663))  COMMA_SOURCE_FILE ("expression-primary.galgas", 663)) ;
        {
        ioArgument_ioTemporaries.mProperty_mSubprogramInvocationGraph.setter_addEdge (constinArgument_inCallerNameForInvocationGraph, var_routineMangledName_26270 COMMA_SOURCE_FILE ("expression-primary.galgas", 672)) ;
        }
        ioArgument_ioObjectIR = var_callReturnedResult_26217 ;
      }
    }
    break ;
  case GALGAS_propertyAccessKind::kEnum_singleton:
    {
      const cEnumAssociatedValues_propertyAccessKind_singleton * extractPtr_26970 = (const cEnumAssociatedValues_propertyAccessKind_singleton *) (var_propertyAccess_24423.unsafePointer ()) ;
      const GALGAS_location extractedValue_errorLocation = extractPtr_26970->mAssociatedValue1 ;
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (extractedValue_errorLocation, GALGAS_string ("a property cannot be used as method"), fixItArray3  COMMA_SOURCE_FILE ("expression-primary.galgas", 677)) ;
      ioArgument_ioObjectIR.drop () ; // Release error dropped variable
    }
    break ;
  case GALGAS_propertyAccessKind::kEnum_indexed:
    {
      const cEnumAssociatedValues_propertyAccessKind_indexed * extractPtr_29196 = (const cEnumAssociatedValues_propertyAccessKind_indexed *) (var_propertyAccess_24423.unsafePointer ()) ;
      const GALGAS_PLMType extractedValue_propertyType = extractPtr_29196->mAssociatedValue0 ;
      const GALGAS_uint extractedValue_propertyIndex = extractPtr_29196->mAssociatedValue1 ;
      const enumGalgasBool test_4 = extractedValue_propertyType.getter_kind (HERE).getter_isFunction (SOURCE_FILE ("expression-primary.galgas", 679)).operator_not (SOURCE_FILE ("expression-primary.galgas", 679)).boolEnum () ;
      if (kBoolTrue == test_4) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (constinArgument_inMethodName.getter_location (SOURCE_FILE ("expression-primary.galgas", 680)), GALGAS_string ("an indexed property cannot be used as method"), fixItArray5  COMMA_SOURCE_FILE ("expression-primary.galgas", 680)) ;
        ioArgument_ioObjectIR.drop () ; // Release error dropped variable
      }else if (kBoolFalse == test_4) {
        GALGAS_routineDescriptor var_descriptor_27236 ;
        extractedValue_propertyType.getter_kind (HERE).method_function (var_descriptor_27236, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 682)) ;
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_descriptor_27236.getter_returnTypeProxy (HERE).objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("expression-primary.galgas", 684)))).boolEnum () ;
        if (kBoolTrue == test_6) {
          TC_Array <C_FixItDescription> fixItArray7 ;
          inCompiler->emitSemanticError (constinArgument_inMethodName.getter_location (SOURCE_FILE ("expression-primary.galgas", 685)), GALGAS_string ("not a function (returns no value)"), fixItArray7  COMMA_SOURCE_FILE ("expression-primary.galgas", 685)) ;
          ioArgument_ioObjectIR.drop () ; // Release error dropped variable
        }else if (kBoolFalse == test_6) {
          GALGAS_procCallEffectiveParameterListIR var_effectiveParameterListIR_27759 = GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (SOURCE_FILE ("expression-primary.galgas", 695)) ;
          {
          routine_analyzeEffectiveParameters (constinArgument_inSelfType, constinArgument_inRoutineAttributes, var_descriptor_27236.getter_signature (HERE), constinArgument_inArguments, constinArgument_inMethodName.getter_location (HERE), constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_effectiveParameterListIR_27759, inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 696)) ;
          }
          GALGAS_string var_property_5F_llvmName_28490 ;
          {
          extensionSetter_newTempLLVMVar (ioArgument_ioTemporaries, var_property_5F_llvmName_28490, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 713)) ;
          }
          {
          extensionSetter_appendGetUniversalPropertyReference (ioArgument_ioInstructionGenerationList, extensionGetter_type (ioArgument_ioObjectIR, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 715)), extensionGetter_llvmName (ioArgument_ioObjectIR, inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 716)), var_property_5F_llvmName_28490, extractedValue_propertyIndex, constinArgument_inMethodName.getter_string (SOURCE_FILE ("expression-primary.galgas", 719)), inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 714)) ;
          }
          GALGAS_objectIR var_callReturnedResult_28870 ;
          {
          routine_getNewTempValue (var_descriptor_27236.getter_returnTypeProxy (HERE).getter_type (inCompiler COMMA_SOURCE_FILE ("expression-primary.galgas", 722)), ioArgument_ioTemporaries, var_callReturnedResult_28870, inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 722)) ;
          }
          ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_indirectRoutineCallIR::constructor_new (GALGAS_objectIR::constructor_reference (extractedValue_propertyType, var_property_5F_llvmName_28490  COMMA_SOURCE_FILE ("expression-primary.galgas", 725)), extractedValue_propertyType, var_callReturnedResult_28870, var_effectiveParameterListIR_27759  COMMA_SOURCE_FILE ("expression-primary.galgas", 724))  COMMA_SOURCE_FILE ("expression-primary.galgas", 724)) ;
          ioArgument_ioObjectIR = var_callReturnedResult_28870 ;
        }
      }
    }
    break ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//        Overriding extension method '@standaloneFunctionInExpressionAST addDependenceEdgeForStaticExpression'        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_standaloneFunctionInExpressionAST_addDependenceEdgeForStaticExpression (const cPtr_expressionAST * inObject,
                                                                                                    const GALGAS_lstring constinArgument_inConstantName,
                                                                                                    GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_standaloneFunctionInExpressionAST * object = (const cPtr_standaloneFunctionInExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_standaloneFunctionInExpressionAST) ;
  {
  ioArgument_ioGraph.setter_addEdge (constinArgument_inConstantName, object->mProperty_mStandaloneFunctionName COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 37)) ;
  }
  cEnumerator_effectiveArgumentListAST enumerator_2075 (object->mProperty_mArguments, kENUMERATION_UP) ;
  while (enumerator_2075.hasCurrentObject ()) {
    switch (enumerator_2075.current_mEffectiveParameterKind (HERE).enumValue ()) {
    case GALGAS_effectiveArgumentPassingModeAST::kNotBuilt:
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_input:
      {
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_inputWithType:
      {
        const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType * extractPtr_2294 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType *) (enumerator_2075.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
        const GALGAS_lstring extractedValue_typeName = extractPtr_2294->mAssociatedValue1 ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, extractedValue_typeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (extractedValue_typeName, inCompiler COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 43)) COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 43)) ;
          }
        }
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_output:
      {
        const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output * extractPtr_2403 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output *) (enumerator_2075.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_expression = extractPtr_2403->mAssociatedValue0 ;
        callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) extractedValue_expression.ptr (), constinArgument_inConstantName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 45)) ;
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInput:
      {
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInputSelfVariable:
      {
      }
      break ;
    }
    enumerator_2075.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_standaloneFunctionInExpressionAST_addDependenceEdgeForStaticExpression (void) {
  enterExtensionMethod_addDependenceEdgeForStaticExpression (kTypeDescriptor_GALGAS_standaloneFunctionInExpressionAST.mSlotID,
                                                             extensionMethod_standaloneFunctionInExpressionAST_addDependenceEdgeForStaticExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_standaloneFunctionInExpressionAST_addDependenceEdgeForStaticExpression (defineExtensionMethod_standaloneFunctionInExpressionAST_addDependenceEdgeForStaticExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//        Overriding extension method '@standaloneFunctionInExpressionAST noteExpressionTypesInPrecedenceGraph'        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_standaloneFunctionInExpressionAST_noteExpressionTypesInPrecedenceGraph (const cPtr_expressionAST * inObject,
                                                                                                    GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_standaloneFunctionInExpressionAST * object = (const cPtr_standaloneFunctionInExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_standaloneFunctionInExpressionAST) ;
  cEnumerator_effectiveArgumentListAST enumerator_3005 (object->mProperty_mArguments, kENUMERATION_UP) ;
  while (enumerator_3005.hasCurrentObject ()) {
    switch (enumerator_3005.current_mEffectiveParameterKind (HERE).enumValue ()) {
    case GALGAS_effectiveArgumentPassingModeAST::kNotBuilt:
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_input:
      {
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_inputWithType:
      {
        const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType * extractPtr_3224 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType *) (enumerator_3005.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
        const GALGAS_lstring extractedValue_typeName = extractPtr_3224->mAssociatedValue1 ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, extractedValue_typeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (extractedValue_typeName, inCompiler COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 64)) COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 64)) ;
          }
        }
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_output:
      {
        const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output * extractPtr_3317 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output *) (enumerator_3005.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_expression = extractPtr_3317->mAssociatedValue0 ;
        callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) extractedValue_expression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 66)) ;
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInput:
      {
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInputSelfVariable:
      {
      }
      break ;
    }
    enumerator_3005.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_standaloneFunctionInExpressionAST_noteExpressionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteExpressionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_standaloneFunctionInExpressionAST.mSlotID,
                                                             extensionMethod_standaloneFunctionInExpressionAST_noteExpressionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_standaloneFunctionInExpressionAST_noteExpressionTypesInPrecedenceGraph (defineExtensionMethod_standaloneFunctionInExpressionAST_noteExpressionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                 Overriding extension method '@standaloneFunctionInExpressionAST analyzeExpression'                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_standaloneFunctionInExpressionAST_analyzeExpression (const cPtr_expressionAST * inObject,
                                                                                 const GALGAS_PLMType constinArgument_inSelfType,
                                                                                 const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                                 const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                                 const GALGAS_PLMType /* constinArgument_inOptionalTargetType */,
                                                                                 const GALGAS_semanticContext constinArgument_inContext,
                                                                                 const GALGAS_mode constinArgument_inCurrentMode,
                                                                                 GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                                 GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                                 GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                                 GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                                 GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                                 GALGAS_objectIR & outArgument_outFunctionCallReturnedValue,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_standaloneFunctionInExpressionAST * object = (const cPtr_standaloneFunctionInExpressionAST *) inObject ;
  macroValidSharedObject (object, cPtr_standaloneFunctionInExpressionAST) ;
  const enumGalgasBool test_0 = constinArgument_inRoutineAttributes.getter_guard (SOURCE_FILE ("expression-standalone-function-call.galgas", 92)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mStandaloneFunctionName.getter_location (HERE), GALGAS_string ("a routine cannot be called in guard"), fixItArray1  COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 93)) ;
  }
  GALGAS_lstring var_routineMangledName_4722 = function_routineMangledNameFromCall (GALGAS_string::makeEmptyString (), object->mProperty_mStandaloneFunctionName, object->mProperty_mArguments, inCompiler COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 96)) ;
  GALGAS_lstring var_signature_4845 = extensionGetter_routineSignature (object->mProperty_mArguments, object->mProperty_mStandaloneFunctionName.getter_location (HERE), inCompiler COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 98)) ;
  GALGAS_lstring var_LLVMInvocationRoutineName_5080 ;
  GALGAS_routineDescriptor var_routineDescriptor_5122 ;
  GALGAS_location joker_5128 ; // Joker input parameter
  extensionMethod_searchKey (constinArgument_inContext.getter_mRoutineMapForContext (HERE), GALGAS_string::makeEmptyString (), object->mProperty_mStandaloneFunctionName, var_signature_4845, var_LLVMInvocationRoutineName_5080, var_routineDescriptor_5122, joker_5128, inCompiler COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 100)) ;
  GALGAS_routineKind var_routineKind_5197 = var_routineDescriptor_5122.getter_routineKind (HERE) ;
  GALGAS_mode var_calleeMode_5246 = extensionGetter_executionMode (var_routineKind_5197, inCompiler COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 110)) ;
  GALGAS_routineTypedSignature var_formalSignature_5298 = var_routineDescriptor_5122.getter_signature (HERE) ;
  const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_routineDescriptor_5122.getter_returnTypeProxy (HERE).objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("expression-standalone-function-call.galgas", 113)))).boolEnum () ;
  if (kBoolTrue == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (object->mProperty_mStandaloneFunctionName.getter_location (SOURCE_FILE ("expression-standalone-function-call.galgas", 114)), GALGAS_string ("not a function (returns no value)"), fixItArray3  COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 114)) ;
    var_routineDescriptor_5122.drop () ; // Release error dropped variable
    outArgument_outFunctionCallReturnedValue.drop () ; // Release error dropped variable
  }else if (kBoolFalse == test_2) {
    GALGAS_calleeKindIR var_calleeKind_5590 = function_checkMode (constinArgument_inCurrentMode, var_calleeMode_5246, var_routineKind_5197, object->mProperty_mStandaloneFunctionName.getter_location (HERE), inCompiler COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 117)) ;
    GALGAS_procCallEffectiveParameterListIR var_effectiveParameterListIR_5840 = GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (SOURCE_FILE ("expression-standalone-function-call.galgas", 124)) ;
    {
    routine_analyzeEffectiveParameters (constinArgument_inSelfType, constinArgument_inRoutineAttributes, var_formalSignature_5298, object->mProperty_mArguments, object->mProperty_mStandaloneFunctionName.getter_location (HERE), constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_effectiveParameterListIR_5840, inCompiler  COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 125)) ;
    }
    {
    routine_getNewTempValue (var_routineDescriptor_5122.getter_returnTypeProxy (HERE).getter_type (inCompiler COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 142)), ioArgument_ioTemporaries, outArgument_outFunctionCallReturnedValue, inCompiler  COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 142)) ;
    }
    ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_standaloneRoutineCallIR::constructor_new (GALGAS_string::makeEmptyString (), outArgument_outFunctionCallReturnedValue, var_routineMangledName_4722, var_LLVMInvocationRoutineName_5080, var_calleeKind_5590, var_effectiveParameterListIR_5840  COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 144))  COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 144)) ;
    {
    ioArgument_ioTemporaries.mProperty_mSubprogramInvocationGraph.setter_addEdge (constinArgument_inCallerNameForInvocationGraph, var_routineMangledName_4722 COMMA_SOURCE_FILE ("expression-standalone-function-call.galgas", 153)) ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_standaloneFunctionInExpressionAST_analyzeExpression (void) {
  enterExtensionMethod_analyzeExpression (kTypeDescriptor_GALGAS_standaloneFunctionInExpressionAST.mSlotID,
                                          extensionMethod_standaloneFunctionInExpressionAST_analyzeExpression) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_standaloneFunctionInExpressionAST_analyzeExpression (defineExtensionMethod_standaloneFunctionInExpressionAST_analyzeExpression, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//              Overriding extension method '@checkInstructionAST noteInstructionTypesInPrecedenceGraph'               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_checkInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                       GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_checkInstructionAST * object = (const cPtr_checkInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_checkInstructionAST) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("directive-check.galgas", 41)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_checkInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_checkInstructionAST.mSlotID,
                                                              extensionMethod_checkInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_checkInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_checkInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                   Overriding extension method '@checkInstructionAST instructionSemanticAnalysis'                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_checkInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                             const GALGAS_PLMType constinArgument_inSelfType,
                                                                             const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                             const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                             const GALGAS_semanticContext constinArgument_inContext,
                                                                             const GALGAS_mode constinArgument_inCurrentMode,
                                                                             GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                             GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                             GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                             GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                             GALGAS_instructionListIR & /* ioArgument_ioInstructionGenerationList */,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_checkInstructionAST * object = (const cPtr_checkInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_checkInstructionAST) ;
  GALGAS_instructionListIR var_instructionGenerationList_3063 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("directive-check.galgas", 61)) ;
  GALGAS_objectIR var_expressionResult_3532 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, function_voidType (inCompiler COMMA_SOURCE_FILE ("directive-check.galgas", 66)), constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_instructionGenerationList_3063, var_expressionResult_3532, inCompiler COMMA_SOURCE_FILE ("directive-check.galgas", 62)) ;
  const enumGalgasBool test_0 = extensionGetter_type (var_expressionResult_3532, inCompiler COMMA_SOURCE_FILE ("directive-check.galgas", 77)).getter_kind (HERE).getter_isBoolean (SOURCE_FILE ("directive-check.galgas", 77)).operator_not (SOURCE_FILE ("directive-check.galgas", 77)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mInstructionLocation, GALGAS_string ("expression is not boolean"), fixItArray1  COMMA_SOURCE_FILE ("directive-check.galgas", 78)) ;
  }
  const enumGalgasBool test_2 = extensionGetter_isStatic (var_expressionResult_3532, inCompiler COMMA_SOURCE_FILE ("directive-check.galgas", 81)).operator_not (SOURCE_FILE ("directive-check.galgas", 81)).boolEnum () ;
  if (kBoolTrue == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (object->mProperty_mInstructionLocation, GALGAS_string ("expression is not static: use assert instruction"), fixItArray3  COMMA_SOURCE_FILE ("directive-check.galgas", 82)) ;
  }else if (kBoolFalse == test_2) {
    GALGAS_bigint var_value_3920 ;
    GALGAS_PLMType joker_3897_1 ; // Joker input parameter
    var_expressionResult_3532.method_literalInteger (joker_3897_1, var_value_3920, inCompiler COMMA_SOURCE_FILE ("directive-check.galgas", 84)) ;
    const enumGalgasBool test_4 = GALGAS_bool (kIsNotEqual, var_value_3920.objectCompare (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("directive-check.galgas", 85)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsNotEqual, object->mProperty_mCheckMessage.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_5) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (object->mProperty_mCheckMessage.getter_location (SOURCE_FILE ("directive-check.galgas", 87)), GALGAS_string ("check failure: ").add_operation (object->mProperty_mCheckMessage.getter_string (SOURCE_FILE ("directive-check.galgas", 87)), inCompiler COMMA_SOURCE_FILE ("directive-check.galgas", 87)), fixItArray6  COMMA_SOURCE_FILE ("directive-check.galgas", 87)) ;
      }else if (kBoolFalse == test_5) {
        TC_Array <C_FixItDescription> fixItArray7 ;
        inCompiler->emitSemanticError (object->mProperty_mCheckMessage.getter_location (SOURCE_FILE ("directive-check.galgas", 89)), GALGAS_string ("check failure"), fixItArray7  COMMA_SOURCE_FILE ("directive-check.galgas", 89)) ;
      }
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_checkInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_checkInstructionAST.mSlotID,
                                                    extensionMethod_checkInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_checkInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_checkInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//              Overriding extension method '@assertInstructionAST noteInstructionTypesInPrecedenceGraph'              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_assertInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                        GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_assertInstructionAST * object = (const cPtr_assertInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_assertInstructionAST) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 36)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_assertInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_assertInstructionAST.mSlotID,
                                                              extensionMethod_assertInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_assertInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_assertInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                   Overriding extension method '@assertInstructionAST instructionSemanticAnalysis'                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_assertInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                              const GALGAS_PLMType constinArgument_inSelfType,
                                                                              const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                              const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                              const GALGAS_semanticContext constinArgument_inContext,
                                                                              const GALGAS_mode constinArgument_inCurrentMode,
                                                                              GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                              GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                              GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                              GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                              GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_assertInstructionAST * object = (const cPtr_assertInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_assertInstructionAST) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_inCurrentMode.objectCompare (GALGAS_mode::constructor_panicMode (SOURCE_FILE ("instruction-assert.galgas", 55)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mInstructionLocation, GALGAS_string ("operations that can generate panic are not allowed in ").add_operation (function_panicModeName (inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 56)), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 56)).add_operation (GALGAS_string (" mode"), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 56)), fixItArray1  COMMA_SOURCE_FILE ("instruction-assert.galgas", 56)) ;
  }
  GALGAS_instructionListIR var_instructionGenerationList_3084 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-assert.galgas", 59)) ;
  GALGAS_objectIR var_expressionValue_3556 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, function_voidType (inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 64)), constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_instructionGenerationList_3084, var_expressionValue_3556, inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 60)) ;
  const enumGalgasBool test_2 = extensionGetter_type (var_expressionValue_3556, inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 75)).getter_kind (HERE).getter_isBoolean (SOURCE_FILE ("instruction-assert.galgas", 75)).operator_not (SOURCE_FILE ("instruction-assert.galgas", 75)).boolEnum () ;
  if (kBoolTrue == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (object->mProperty_mInstructionLocation, GALGAS_string ("expression is not boolean"), fixItArray3  COMMA_SOURCE_FILE ("instruction-assert.galgas", 76)) ;
  }
  const enumGalgasBool test_4 = extensionGetter_isStatic (var_expressionValue_3556, inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 79)).boolEnum () ;
  if (kBoolTrue == test_4) {
    TC_Array <C_FixItDescription> fixItArray5 ;
    inCompiler->emitSemanticError (object->mProperty_mInstructionLocation, GALGAS_string ("expression is static: use check directive"), fixItArray5  COMMA_SOURCE_FILE ("instruction-assert.galgas", 80)) ;
  }
  const enumGalgasBool test_6 = GALGAS_bool (gOption_plm_5F_options_noPanicGeneration.getter_value ()).operator_not (SOURCE_FILE ("instruction-assert.galgas", 83)).boolEnum () ;
  if (kBoolTrue == test_6) {
    ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_assertInstructionIR::constructor_new (object->mProperty_mInstructionLocation, var_instructionGenerationList_3084, var_expressionValue_3556  COMMA_SOURCE_FILE ("instruction-assert.galgas", 84))  COMMA_SOURCE_FILE ("instruction-assert.galgas", 84)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_assertInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_assertInstructionAST.mSlotID,
                                                    extensionMethod_assertInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_assertInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_assertInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                       Overriding extension method '@assertInstructionIR llvmInstructionCode'                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_assertInstructionIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                     GALGAS_string & ioArgument_ioLLVMcode,
                                                                     const GALGAS_generationContext constinArgument_inGenerationContext,
                                                                     GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_assertInstructionIR * object = (const cPtr_assertInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_assertInstructionIR) ;
  extensionMethod_instructionListLLVMCode (object->mProperty_mInstructionList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 109)) ;
  GALGAS_uint var_staticStringIndex_5195 ;
  {
  extensionSetter_findOrAddStaticString (ioArgument_ioGenerationAdds.mProperty_mStaticEntityMap, object->mProperty_mAssertInstructionLocation.getter_file (inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 111)).getter_lastPathComponent (SOURCE_FILE ("instruction-assert.galgas", 111)).getter_stringByDeletingPathExtension (SOURCE_FILE ("instruction-assert.galgas", 111)), var_staticStringIndex_5195, inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 110)) ;
  }
  GALGAS_string var_labelAssertOk_5219 = GALGAS_string ("assert.ok.").add_operation (ioArgument_ioGenerationAdds.getter_mUniqueIndex (HERE).getter_string (SOURCE_FILE ("instruction-assert.galgas", 114)), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 114)) ;
  GALGAS_string var_labelAssertEr_5286 = GALGAS_string ("assert.not.ok.").add_operation (ioArgument_ioGenerationAdds.getter_mUniqueIndex (HERE).getter_string (SOURCE_FILE ("instruction-assert.galgas", 115)), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 115)) ;
  ioArgument_ioGenerationAdds.mProperty_mUniqueIndex.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-assert.galgas", 116)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 ").add_operation (extensionGetter_llvmName (object->mProperty_mExpressionValue, inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 117)), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 117)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 117)).add_operation (var_labelAssertOk_5219, inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 117)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 117)).add_operation (var_labelAssertEr_5286, inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 117)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 117)), inCompiler  COMMA_SOURCE_FILE ("instruction-assert.galgas", 117)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_labelAssertEr_5286.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 118)), inCompiler  COMMA_SOURCE_FILE ("instruction-assert.galgas", 118)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  call void @raise.panic.").add_operation (var_staticStringIndex_5195.getter_string (SOURCE_FILE ("instruction-assert.galgas", 119)), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 119)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 119)), inCompiler  COMMA_SOURCE_FILE ("instruction-assert.galgas", 119)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(extensionGetter_llvmTypeName (constinArgument_inGenerationContext.getter_mPanicLineLLVMType (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 120)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 120)).add_operation (object->mProperty_mAssertInstructionLocation.getter_line (inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 120)).getter_string (SOURCE_FILE ("instruction-assert.galgas", 120)), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 120)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 120)), inCompiler  COMMA_SOURCE_FILE ("instruction-assert.galgas", 120)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(extensionGetter_llvmTypeName (constinArgument_inGenerationContext.getter_mPanicCodeLLVMType (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 121)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 121)).add_operation (function_panicCodeForAssertViolation (inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 121)).getter_string (SOURCE_FILE ("instruction-assert.galgas", 121)), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 121)).add_operation (GALGAS_string (")\n"), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 121)), inCompiler  COMMA_SOURCE_FILE ("instruction-assert.galgas", 121)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  unreachable\n"
    "\n"), inCompiler  COMMA_SOURCE_FILE ("instruction-assert.galgas", 122)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_labelAssertOk_5219.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 123)), inCompiler  COMMA_SOURCE_FILE ("instruction-assert.galgas", 123)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_assertInstructionIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_assertInstructionIR.mSlotID,
                                            extensionMethod_assertInstructionIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_assertInstructionIR_llvmInstructionCode (defineExtensionMethod_assertInstructionIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     Overriding extension method '@assertInstructionIR enterAccessibleEntities'                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_assertInstructionIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * inObject,
                                                                         GALGAS_accessibleEntities & ioArgument_ioAccessibleEntities,
                                                                         GALGAS_uint & ioArgument_ioMaxBranchOfOnInstructions,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_assertInstructionIR * object = (const cPtr_assertInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_assertInstructionIR) ;
  extensionMethod_enterAccessibleEntities (object->mProperty_mInstructionList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-assert.galgas", 132)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_assertInstructionIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_assertInstructionIR.mSlotID,
                                                extensionMethod_assertInstructionIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_assertInstructionIR_enterAccessibleEntities (defineExtensionMethod_assertInstructionIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//            Overriding extension method '@assignmentInstructionAST noteInstructionTypesInPrecedenceGraph'            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_assignmentInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                            GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_assignmentInstructionAST * object = (const cPtr_assignmentInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_assignmentInstructionAST) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mSourceExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-assignment.galgas", 40)) ;
  extensionMethod_noteInstructionTypesInPrecedenceGraph (object->mProperty_mTargetAST, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-assignment.galgas", 41)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_assignmentInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_assignmentInstructionAST.mSlotID,
                                                              extensionMethod_assignmentInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_assignmentInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_assignmentInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                 Overriding extension method '@assignmentInstructionAST instructionSemanticAnalysis'                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_assignmentInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                                  const GALGAS_PLMType constinArgument_inSelfType,
                                                                                  const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                                  const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                                  const GALGAS_semanticContext constinArgument_inContext,
                                                                                  const GALGAS_mode constinArgument_inCurrentMode,
                                                                                  GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                                  GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                                  GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                                  GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                                  GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_assignmentInstructionAST * object = (const cPtr_assignmentInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_assignmentInstructionAST) ;
  GALGAS_PLMType var_targetType_3166 ;
  extensionMethod_searchValuedObjectType (ioArgument_ioUniversalMap, constinArgument_inSelfType, object->mProperty_mTargetAST, var_targetType_3166, inCompiler COMMA_SOURCE_FILE ("instruction-assignment.galgas", 60)) ;
  GALGAS_objectIR var_sourceOperandPossibleReference_3683 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mSourceExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, var_targetType_3166, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_sourceOperandPossibleReference_3683, inCompiler COMMA_SOURCE_FILE ("instruction-assignment.galgas", 62)) ;
  GALGAS_LValueRepresentation var_lvalueIR_4162 ;
  extensionMethod_analyzeLValue (object->mProperty_mTargetAST, constinArgument_inSelfType, GALGAS_bool (false), constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_lvalueIR_4162, inCompiler COMMA_SOURCE_FILE ("instruction-assignment.galgas", 77)) ;
  GALGAS_PLMType var_t_4200 = extensionGetter_type (var_sourceOperandPossibleReference_3683, inCompiler COMMA_SOURCE_FILE ("instruction-assignment.galgas", 92)) ;
  const enumGalgasBool test_0 = extensionGetter_copyable (var_t_4200, inCompiler COMMA_SOURCE_FILE ("instruction-assignment.galgas", 93)).operator_not (SOURCE_FILE ("instruction-assignment.galgas", 93)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mTargetAST.getter_mIdentifier (HERE).getter_location (SOURCE_FILE ("instruction-assignment.galgas", 94)), GALGAS_string ("source expression is not copyable"), fixItArray1  COMMA_SOURCE_FILE ("instruction-assignment.galgas", 94)) ;
  }else if (kBoolFalse == test_0) {
    {
    extensionSetter_appendCopyFromReferences (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, object->mProperty_mTargetAST.getter_mIdentifier (HERE).getter_location (SOURCE_FILE ("instruction-assignment.galgas", 98)), var_sourceOperandPossibleReference_3683, var_lvalueIR_4162, inCompiler COMMA_SOURCE_FILE ("instruction-assignment.galgas", 96)) ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_assignmentInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_assignmentInstructionAST.mSlotID,
                                                    extensionMethod_assignmentInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_assignmentInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_assignmentInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//    Overriding extension method '@controlRegisterAssignmentInstructionAST noteInstructionTypesInPrecedenceGraph'     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_controlRegisterAssignmentInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                                           GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                           C_Compiler * inCompiler
                                                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_controlRegisterAssignmentInstructionAST * object = (const cPtr_controlRegisterAssignmentInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_controlRegisterAssignmentInstructionAST) ;
  extensionMethod_noteExpressionTypesInPrecedenceGraph (object->mProperty_mControlRegisterLValue, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 59)) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mSourceExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 60)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_controlRegisterAssignmentInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_controlRegisterAssignmentInstructionAST.mSlotID,
                                                              extensionMethod_controlRegisterAssignmentInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_controlRegisterAssignmentInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_controlRegisterAssignmentInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//         Overriding extension method '@controlRegisterAssignmentInstructionAST instructionSemanticAnalysis'          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_controlRegisterAssignmentInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                                                 const GALGAS_PLMType constinArgument_inSelfType,
                                                                                                 const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                                                 const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                                                 const GALGAS_semanticContext constinArgument_inContext,
                                                                                                 const GALGAS_mode constinArgument_inMode,
                                                                                                 GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                                                 GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                                                 GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                                                 GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                                                 GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                                                 C_Compiler * inCompiler
                                                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_controlRegisterAssignmentInstructionAST * object = (const cPtr_controlRegisterAssignmentInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_controlRegisterAssignmentInstructionAST) ;
  GALGAS_PLMType var_registerType_4424 ;
  GALGAS_string var_llvmRegAddressName_4516 ;
  GALGAS_uint joker_4447 ; // Joker input parameter
  GALGAS_sliceMap joker_4463 ; // Joker input parameter
  extensionMethod_controlRegisterLValueSemanticAnalysis (object->mProperty_mControlRegisterLValue, GALGAS_bool (true), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_registerType_4424, joker_4447, joker_4463, var_llvmRegAddressName_4516, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 80)) ;
  GALGAS_objectIR var_sourceIR_5026 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mSourceExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, var_registerType_4424, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_sourceIR_5026, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 98)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_sourceIR_5026, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 113)) ;
  }
  GALGAS_PLMType var_t_5220 = extensionGetter_type (var_sourceIR_5026, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 118)) ;
  const enumGalgasBool test_0 = extensionGetter_copyable (var_t_5220, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 119)).operator_not (SOURCE_FILE ("instruction-assignment-control-register.galgas", 119)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mControlRegisterLValue.getter_mRegisterGroupName (HERE).getter_location (SOURCE_FILE ("instruction-assignment-control-register.galgas", 120)), GALGAS_string ("source expression is not copyable"), fixItArray1  COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 120)) ;
  }else if (kBoolFalse == test_0) {
    switch (object->mProperty_mAssignmentKind.enumValue ()) {
    case GALGAS_controlRegisterAssignmentOperatorKind::kNotBuilt:
      break ;
    case GALGAS_controlRegisterAssignmentOperatorKind::kEnum_assignment:
      {
        {
        extensionSetter_appendStoreIndirectVolatileRegister (ioArgument_ioInstructionGenerationList, var_registerType_4424, var_llvmRegAddressName_4516, var_sourceIR_5026, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 124)) ;
        }
      }
      break ;
    case GALGAS_controlRegisterAssignmentOperatorKind::kEnum_assignmentWithOperator:
      {
        const cEnumAssociatedValues_controlRegisterAssignmentOperatorKind_assignmentWithOperator * extractPtr_6590 = (const cEnumAssociatedValues_controlRegisterAssignmentOperatorKind_assignmentWithOperator *) (object->mProperty_mAssignmentKind.unsafePointer ()) ;
        const GALGAS_infixOperator extractedValue_infixOperator = extractPtr_6590->mAssociatedValue0 ;
        const GALGAS_location extractedValue_operatorLocation = extractPtr_6590->mAssociatedValue1 ;
        GALGAS_objectIR var_registerValueIR_5693 ;
        {
        routine_getNewTempValue (var_registerType_4424, ioArgument_ioTemporaries, var_registerValueIR_5693, inCompiler  COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 127)) ;
        }
        {
        extensionSetter_appendLoadIndirectVolatileRegister (ioArgument_ioInstructionGenerationList, var_registerValueIR_5693, var_llvmRegAddressName_4516, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 128)) ;
        }
        GALGAS_infixOperatorMap var_operatorMap_5853 = function_getInfixOperatorMap (extractedValue_infixOperator, constinArgument_inContext, constinArgument_inMode, extractedValue_operatorLocation, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 130)) ;
        GALGAS_PLMType var_resultType_6140 ;
        GALGAS_infixOperatorDescription var_binaryOperator_6197 ;
        extensionMethod_checkBinaryOperationWith (var_operatorMap_5853, extensionGetter_type (var_registerValueIR_5693, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 132)), extensionGetter_type (var_sourceIR_5026, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 133)), extractedValue_operatorLocation, var_resultType_6140, var_binaryOperator_6197, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 131)) ;
        GALGAS_objectIR var_operationResult_6433 ;
        callExtensionMethod_generateInfixOperatorCode ((const cPtr_infixOperatorDescription *) var_binaryOperator_6197.ptr (), ioArgument_ioTemporaries, ioArgument_ioInstructionGenerationList, var_registerValueIR_5693, extractedValue_operatorLocation, var_sourceIR_5026, var_resultType_6140, var_operationResult_6433, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 138)) ;
        {
        extensionSetter_appendStoreIndirectVolatileRegister (ioArgument_ioInstructionGenerationList, var_registerType_4424, var_llvmRegAddressName_4516, var_operationResult_6433, inCompiler COMMA_SOURCE_FILE ("instruction-assignment-control-register.galgas", 148)) ;
        }
      }
      break ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_controlRegisterAssignmentInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_controlRegisterAssignmentInstructionAST.mSlotID,
                                                    extensionMethod_controlRegisterAssignmentInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_controlRegisterAssignmentInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_controlRegisterAssignmentInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//         Overriding extension method '@sliceAssignmentInstructionAST noteInstructionTypesInPrecedenceGraph'          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_sliceAssignmentInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                                 GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                 C_Compiler * inCompiler
                                                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sliceAssignmentInstructionAST * object = (const cPtr_sliceAssignmentInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_sliceAssignmentInstructionAST) ;
  {
  ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (object->mProperty_mTypeName, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 84)) COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 84)) ;
  }
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mSourceExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 85)) ;
  cEnumerator_sliceAssignmentListAST enumerator_3350 (object->mProperty_mSliceAssignmentList, kENUMERATION_UP) ;
  while (enumerator_3350.hasCurrentObject ()) {
    const enumGalgasBool test_0 = enumerator_3350.current_mSliceWidth (HERE).getter_string (HERE).getter_isDecimalUnsignedNumber (SOURCE_FILE ("instruction-slice-assignment.galgas", 87)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_uint var_sliceWidth_3433 = enumerator_3350.current_mSliceWidth (HERE).getter_string (HERE).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 88)) ;
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_sliceWidth_3433.objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_1) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_3350.current_mSliceWidth (HERE).getter_location (SOURCE_FILE ("instruction-slice-assignment.galgas", 90)), GALGAS_string ("the bit slice width should be > 0"), fixItArray2  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 90)) ;
      }else if (kBoolFalse == test_1) {
        {
        extensionSetter_noteUINTType (ioArgument_ioGraph, var_sliceWidth_3433, enumerator_3350.current_mSliceWidth (HERE).getter_location (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 92)) ;
        }
      }
    }else if (kBoolFalse == test_0) {
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, enumerator_3350.current_mSliceWidth (HERE).getter_string (HERE).objectCompare (GALGAS_string ("b"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        GALGAS_lstring var_sliceTypeName_3887 = GALGAS_lstring::constructor_new (GALGAS_string ("bool"), enumerator_3350.current_mSliceWidth (HERE).getter_location (HERE)  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 97)) ;
        {
        ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (var_sliceTypeName_3887, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 98)) COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 98)) ;
        }
      }
    }
    switch (enumerator_3350.current_mSliceKind (HERE).enumValue ()) {
    case GALGAS_sliceTargetAST::kNotBuilt:
      break ;
    case GALGAS_sliceTargetAST::kEnum_discarded:
      {
      }
      break ;
    case GALGAS_sliceTargetAST::kEnum_varDeclaration:
      {
      }
      break ;
    case GALGAS_sliceTargetAST::kEnum_letDeclaration:
      {
      }
      break ;
    case GALGAS_sliceTargetAST::kEnum_lValue:
      {
        const cEnumAssociatedValues_sliceTargetAST_lValue * extractPtr_4216 = (const cEnumAssociatedValues_sliceTargetAST_lValue *) (enumerator_3350.current_mSliceKind (HERE).unsafePointer ()) ;
        const GALGAS_LValueAST extractedValue_target = extractPtr_4216->mAssociatedValue0 ;
        extensionMethod_noteInstructionTypesInPrecedenceGraph (extractedValue_target, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 105)) ;
      }
      break ;
    }
    enumerator_3350.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_sliceAssignmentInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_sliceAssignmentInstructionAST.mSlotID,
                                                              extensionMethod_sliceAssignmentInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_sliceAssignmentInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_sliceAssignmentInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//              Overriding extension method '@sliceAssignmentInstructionAST instructionSemanticAnalysis'               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_sliceAssignmentInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                                       const GALGAS_PLMType constinArgument_inSelfType,
                                                                                       const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                                       const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                                       const GALGAS_semanticContext constinArgument_inContext,
                                                                                       const GALGAS_mode constinArgument_inCurrentMode,
                                                                                       GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                                       GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                                       GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                                       GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                                       GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sliceAssignmentInstructionAST * object = (const cPtr_sliceAssignmentInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_sliceAssignmentInstructionAST) ;
  GALGAS_PLMType var_resultType_5227 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), object->mProperty_mTypeName, inCompiler  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 127)).getter_type (inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 127)) ;
  GALGAS_uint var_bitCount_5362 ;
  const enumGalgasBool test_0 = var_resultType_5227.getter_kind (HERE).getter_isInteger (SOURCE_FILE ("instruction-slice-assignment.galgas", 130)).operator_not (SOURCE_FILE ("instruction-slice-assignment.galgas", 130)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("instruction-slice-assignment.galgas", 131)), GALGAS_string ("this type should be an unsigned integer type"), fixItArray1  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 131)) ;
    var_bitCount_5362.drop () ; // Release error dropped variable
  }else if (kBoolFalse == test_0) {
    GALGAS_bool var_unsigned_5546 ;
    GALGAS_bigint joker_5521_2 ; // Joker input parameter
    GALGAS_bigint joker_5521_1 ; // Joker input parameter
    var_resultType_5227.getter_kind (HERE).method_integer (joker_5521_2, joker_5521_1, var_unsigned_5546, var_bitCount_5362, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 133)) ;
    const enumGalgasBool test_2 = var_unsigned_5546.operator_not (SOURCE_FILE ("instruction-slice-assignment.galgas", 134)).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("instruction-slice-assignment.galgas", 135)), GALGAS_string ("this type should be an unsigned integer type"), fixItArray3  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 135)) ;
      var_bitCount_5362.drop () ; // Release error dropped variable
    }
  }
  GALGAS_objectIR var_sourceOperand_6185 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mSourceExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, var_resultType_5227, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_sourceOperand_6185, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 139)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_sourceOperand_6185, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 154)) ;
  }
  const enumGalgasBool test_4 = var_sourceOperand_6185.getter_isLiteralInteger (SOURCE_FILE ("instruction-slice-assignment.galgas", 156)).boolEnum () ;
  if (kBoolTrue == test_4) {
    GALGAS_bigint var_value_6494 ;
    GALGAS_PLMType joker_6467_1 ; // Joker input parameter
    var_sourceOperand_6185.method_literalInteger (joker_6467_1, var_value_6494, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 157)) ;
    const enumGalgasBool test_5 = GALGAS_bool (kIsSupOrEqual, var_value_6494.objectCompare (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 158)).left_shift_operation (var_bitCount_5362 COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 158)))).boolEnum () ;
    if (kBoolTrue == test_5) {
      TC_Array <C_FixItDescription> fixItArray6 ;
      inCompiler->emitSemanticError (object->mProperty_mSourceExpressionLocation, GALGAS_string ("static value too large"), fixItArray6  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 159)) ;
      var_sourceOperand_6185.drop () ; // Release error dropped variable
    }else if (kBoolFalse == test_5) {
      var_sourceOperand_6185 = GALGAS_objectIR::constructor_literalInteger (var_resultType_5227, var_value_6494  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 161)) ;
    }
  }
  GALGAS_uint var_rightShiftAmount_6750 = var_bitCount_5362 ;
  GALGAS_bigint var_accumulatedFieldStaticValues_6800 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 166)) ;
  cEnumerator_sliceAssignmentListAST enumerator_6861 (object->mProperty_mSliceAssignmentList, kENUMERATION_UP) ;
  while (enumerator_6861.hasCurrentObject ()) {
    GALGAS_objectIR var_sourceOperandForSlicing_6896 = var_sourceOperand_6185 ;
    GALGAS_lstring var_sliceTypeName_6963 ;
    GALGAS_uint var_sliceWidth_6984 ;
    const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, enumerator_6861.current_mSliceWidth (HERE).getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_7) {
      TC_Array <C_FixItDescription> fixItArray8 ;
      inCompiler->emitSemanticError (enumerator_6861.current_mSliceWidth (HERE).getter_location (SOURCE_FILE ("instruction-slice-assignment.galgas", 173)), GALGAS_string ("anonymous selector not allowed here"), fixItArray8  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 173)) ;
      var_sliceWidth_6984.drop () ; // Release error dropped variable
      var_sliceTypeName_6963.drop () ; // Release error dropped variable
    }else if (kBoolFalse == test_7) {
      const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, enumerator_6861.current_mSliceWidth (HERE).getter_string (HERE).objectCompare (GALGAS_string ("b"))).boolEnum () ;
      if (kBoolTrue == test_9) {
        var_sliceWidth_6984 = GALGAS_uint ((uint32_t) 1U) ;
        var_sliceTypeName_6963 = GALGAS_lstring::constructor_new (GALGAS_string ("bool"), object->mProperty_mTypeName.getter_location (HERE)  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 176)) ;
      }else if (kBoolFalse == test_9) {
        const enumGalgasBool test_10 = enumerator_6861.current_mSliceWidth (HERE).getter_string (HERE).getter_isDecimalUnsignedNumber (SOURCE_FILE ("instruction-slice-assignment.galgas", 177)).operator_not (SOURCE_FILE ("instruction-slice-assignment.galgas", 177)).boolEnum () ;
        if (kBoolTrue == test_10) {
          TC_Array <C_FixItDescription> fixItArray11 ;
          inCompiler->emitSemanticError (enumerator_6861.current_mSliceWidth (HERE).getter_location (SOURCE_FILE ("instruction-slice-assignment.galgas", 178)), GALGAS_string ("the selector should be an unsigned integer value"), fixItArray11  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 178)) ;
          var_sliceWidth_6984.drop () ; // Release error dropped variable
          var_sliceTypeName_6963.drop () ; // Release error dropped variable
        }else if (kBoolFalse == test_10) {
          var_sliceWidth_6984 = enumerator_6861.current_mSliceWidth (HERE).getter_string (HERE).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 180)) ;
          var_sliceTypeName_6963 = GALGAS_lstring::constructor_new (GALGAS_string ("uint").add_operation (var_sliceWidth_6984.getter_string (SOURCE_FILE ("instruction-slice-assignment.galgas", 181)), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 181)), object->mProperty_mTypeName.getter_location (HERE)  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 181)) ;
          const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, var_sliceWidth_6984.objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
          if (kBoolTrue == test_12) {
            TC_Array <C_FixItDescription> fixItArray13 ;
            inCompiler->emitSemanticError (enumerator_6861.current_mSliceWidth (HERE).getter_location (SOURCE_FILE ("instruction-slice-assignment.galgas", 183)), GALGAS_string ("the bit slice width should be > 0"), fixItArray13  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 183)) ;
          }
        }
      }
    }
    const enumGalgasBool test_14 = GALGAS_bool (kIsSupOrEqual, var_rightShiftAmount_6750.objectCompare (var_sliceWidth_6984)).boolEnum () ;
    if (kBoolTrue == test_14) {
      var_rightShiftAmount_6750 = var_rightShiftAmount_6750.substract_operation (var_sliceWidth_6984, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 187)) ;
    }else if (kBoolFalse == test_14) {
      GALGAS_uint var_specifiedBitCount_7796 = var_bitCount_5362.add_operation (var_sliceWidth_6984, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 189)).substract_operation (var_rightShiftAmount_6750, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 189)) ;
      TC_Array <C_FixItDescription> fixItArray15 ;
      inCompiler->emitSemanticError (enumerator_6861.current_mSliceWidth (HERE).getter_location (SOURCE_FILE ("instruction-slice-assignment.galgas", 190)), GALGAS_string ("bit slice overflow: ").add_operation (var_specifiedBitCount_7796.getter_string (SOURCE_FILE ("instruction-slice-assignment.galgas", 190)), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 190)).add_operation (GALGAS_string (" bits, should be "), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 190)).add_operation (var_bitCount_5362.getter_string (SOURCE_FILE ("instruction-slice-assignment.galgas", 190)), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 190)), fixItArray15  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 190)) ;
      var_rightShiftAmount_6750 = GALGAS_uint ((uint32_t) 0U) ;
    }
    GALGAS_PLMType var_sliceType_7996 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), var_sliceTypeName_6963, inCompiler  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 193)).getter_type (inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 193)) ;
    {
    extensionSetter_appendLogicalShiftRight (ioArgument_ioInstructionGenerationList, var_sourceOperandForSlicing_6896, var_rightShiftAmount_6750, ioArgument_ioTemporaries, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 195)) ;
    }
    {
    extensionSetter_appendTrunc (ioArgument_ioInstructionGenerationList, var_sliceType_7996, var_sourceOperandForSlicing_6896, ioArgument_ioTemporaries, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 196)) ;
    }
    switch (enumerator_6861.current_mSliceKind (HERE).enumValue ()) {
    case GALGAS_sliceTargetAST::kNotBuilt:
      break ;
    case GALGAS_sliceTargetAST::kEnum_discarded:
      {
      }
      break ;
    case GALGAS_sliceTargetAST::kEnum_varDeclaration:
      {
        const cEnumAssociatedValues_sliceTargetAST_varDeclaration * extractPtr_9243 = (const cEnumAssociatedValues_sliceTargetAST_varDeclaration *) (enumerator_6861.current_mSliceKind (HERE).unsafePointer ()) ;
        const GALGAS_lstring extractedValue_varName = extractPtr_9243->mAssociatedValue0 ;
        GALGAS_lstring var_plmLocalVariableName_8497 = GALGAS_lstring::constructor_new (extractedValue_varName.getter_string (HERE).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 202)).add_operation (ioArgument_ioTemporaries.getter_mTemporaryIndex (HERE).getter_string (SOURCE_FILE ("instruction-slice-assignment.galgas", 202)), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 202)), extractedValue_varName.getter_location (SOURCE_FILE ("instruction-slice-assignment.galgas", 202))  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 202)) ;
        ioArgument_ioTemporaries.mProperty_mTemporaryIndex.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 203)) ;
        {
        extensionSetter_insertLocalVariable (ioArgument_ioUniversalMap, extractedValue_varName, var_sliceType_7996, var_plmLocalVariableName_8497, GALGAS_valuedObjectState::constructor_hasUnreadValue (SOURCE_FILE ("instruction-slice-assignment.galgas", 204)), GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 204)) ;
        }
        ioArgument_ioAllocaList.addAssign_operation (function_llvmNameForLocalVariable (var_plmLocalVariableName_8497.getter_string (SOURCE_FILE ("instruction-slice-assignment.galgas", 206)), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 206)), var_sliceType_7996, GALGAS_bool (false)  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 206)) ;
        GALGAS_LValueRepresentation var_targetRef_8888 = GALGAS_LValueRepresentation::constructor_new (var_sliceType_7996, function_llvmNameForLocalVariable (var_plmLocalVariableName_8497.getter_string (SOURCE_FILE ("instruction-slice-assignment.galgas", 210)), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 210))  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 208)) ;
        {
        extensionSetter_appendCopyFromReferences (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, extractedValue_varName.getter_location (HERE), var_sourceOperandForSlicing_6896, var_targetRef_8888, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 213)) ;
        }
      }
      break ;
    case GALGAS_sliceTargetAST::kEnum_letDeclaration:
      {
        const cEnumAssociatedValues_sliceTargetAST_letDeclaration * extractPtr_10073 = (const cEnumAssociatedValues_sliceTargetAST_letDeclaration *) (enumerator_6861.current_mSliceKind (HERE).unsafePointer ()) ;
        const GALGAS_lstring extractedValue_letName = extractPtr_10073->mAssociatedValue0 ;
        GALGAS_lstring var_plmLocalVariableName_9342 = GALGAS_lstring::constructor_new (extractedValue_letName.getter_string (HERE).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 221)).add_operation (ioArgument_ioTemporaries.getter_mTemporaryIndex (HERE).getter_string (SOURCE_FILE ("instruction-slice-assignment.galgas", 221)), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 221)), extractedValue_letName.getter_location (SOURCE_FILE ("instruction-slice-assignment.galgas", 221))  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 221)) ;
        ioArgument_ioTemporaries.mProperty_mTemporaryIndex.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 222)) ;
        {
        extensionSetter_insertLocalConstant (ioArgument_ioUniversalMap, extractedValue_letName, GALGAS_bool (false), var_sliceType_7996, var_plmLocalVariableName_9342, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 223)) ;
        }
        ioArgument_ioAllocaList.addAssign_operation (function_llvmNameForLocalVariable (var_plmLocalVariableName_9342.getter_string (SOURCE_FILE ("instruction-slice-assignment.galgas", 225)), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 225)), var_sliceType_7996, GALGAS_bool (false)  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 225)) ;
        GALGAS_LValueRepresentation var_targetRef_9716 = GALGAS_LValueRepresentation::constructor_new (var_sliceType_7996, function_llvmNameForLocalVariable (var_plmLocalVariableName_9342.getter_string (SOURCE_FILE ("instruction-slice-assignment.galgas", 229)), inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 229))  COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 227)) ;
        {
        extensionSetter_appendCopyFromReferences (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, extractedValue_letName.getter_location (HERE), var_sourceOperandForSlicing_6896, var_targetRef_9716, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 232)) ;
        }
      }
      break ;
    case GALGAS_sliceTargetAST::kEnum_lValue:
      {
        const cEnumAssociatedValues_sliceTargetAST_lValue * extractPtr_10864 = (const cEnumAssociatedValues_sliceTargetAST_lValue *) (enumerator_6861.current_mSliceKind (HERE).unsafePointer ()) ;
        const GALGAS_LValueAST extractedValue_target = extractPtr_10864->mAssociatedValue0 ;
        GALGAS_LValueRepresentation var_lvalueIR_10614 ;
        extensionMethod_analyzeLValue (extractedValue_target, constinArgument_inSelfType, GALGAS_bool (false), constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_lvalueIR_10614, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 239)) ;
        {
        extensionSetter_appendCopyFromReferences (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, extractedValue_target.getter_mIdentifier (HERE).getter_location (SOURCE_FILE ("instruction-slice-assignment.galgas", 256)), var_sourceOperandForSlicing_6896, var_lvalueIR_10614, inCompiler COMMA_SOURCE_FILE ("instruction-slice-assignment.galgas", 254)) ;
        }
      }
      break ;
    }
    enumerator_6861.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_sliceAssignmentInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_sliceAssignmentInstructionAST.mSlotID,
                                                    extensionMethod_sliceAssignmentInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_sliceAssignmentInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_sliceAssignmentInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//             Overriding extension method '@bitbandInstructionAST noteInstructionTypesInPrecedenceGraph'              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_bitbandInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                         GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_bitbandInstructionAST * object = (const cPtr_bitbandInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_bitbandInstructionAST) ;
  extensionMethod_noteExpressionTypesInPrecedenceGraph (object->mProperty_mControlRegisterLValue, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 51)) ;
  {
  ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (GALGAS_lstring::constructor_new (GALGAS_string ("uint1"), object->mProperty_mControlRegisterLValue.getter_mRegisterGroupName (HERE).getter_location (SOURCE_FILE ("instruction-bit-banding.galgas", 52))  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 52)), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 52)) COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 52)) ;
  }
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mBitExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 53)) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mSourceExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 54)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_bitbandInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_bitbandInstructionAST.mSlotID,
                                                              extensionMethod_bitbandInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_bitbandInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_bitbandInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                  Overriding extension method '@bitbandInstructionAST instructionSemanticAnalysis'                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_bitbandInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                               const GALGAS_PLMType constinArgument_inSelfType,
                                                                               const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                               const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                               const GALGAS_semanticContext constinArgument_inContext,
                                                                               const GALGAS_mode constinArgument_inMode,
                                                                               GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                               GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                               GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                               GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                               GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_bitbandInstructionAST * object = (const cPtr_bitbandInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_bitbandInstructionAST) ;
  GALGAS_PLMType var_requiredSourceExpressionType_3870 ;
  GALGAS_uint joker_3876_1 ; // Joker input parameter
  constinArgument_inContext.getter_mTypeMap (HERE).method_searchKey (GALGAS_lstring::constructor_new (GALGAS_string ("uint1"), object->mProperty_mSourceExpressionLocation  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 76)), var_requiredSourceExpressionType_3870, joker_3876_1, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 75)) ;
  GALGAS_objectIR var_sourceExpressionOperand_4402 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mSourceExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, var_requiredSourceExpressionType_3870, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_sourceExpressionOperand_4402, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 81)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_sourceExpressionOperand_4402, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 96)) ;
  }
  GALGAS_bool test_0 = GALGAS_bool (kIsEqual, extensionGetter_type (var_sourceExpressionOperand_4402, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 101)).getter_plmTypeDescriptionName (HERE).objectCompare (function_staticIntegerTypeName (inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 101)))) ;
  if (kBoolTrue == test_0.boolEnum ()) {
    test_0 = var_sourceExpressionOperand_4402.getter_isLiteralInteger (SOURCE_FILE ("instruction-bit-banding.galgas", 101)) ;
  }
  const enumGalgasBool test_1 = test_0.boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_bigint var_value_4868 ;
    GALGAS_PLMType joker_4841_1 ; // Joker input parameter
    var_sourceExpressionOperand_4402.method_literalInteger (joker_4841_1, var_value_4868, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 102)) ;
    GALGAS_bool test_2 = GALGAS_bool (kIsStrictInf, var_value_4868.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 103)))) ;
    if (kBoolTrue != test_2.boolEnum ()) {
      test_2 = GALGAS_bool (kIsStrictSup, var_value_4868.objectCompare (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 103)))) ;
    }
    const enumGalgasBool test_3 = test_2.boolEnum () ;
    if (kBoolTrue == test_3) {
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (object->mProperty_mSourceExpressionLocation, GALGAS_string ("static value should be 0 or 1"), fixItArray4  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 104)) ;
    }else if (kBoolFalse == test_3) {
      var_sourceExpressionOperand_4402 = GALGAS_objectIR::constructor_literalInteger (var_requiredSourceExpressionType_3870, var_value_4868  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 106)) ;
    }
  }else if (kBoolFalse == test_1) {
    const enumGalgasBool test_5 = GALGAS_bool (kIsNotEqual, extensionGetter_type (var_sourceExpressionOperand_4402, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 108)).getter_plmTypeDescriptionName (HERE).objectCompare (var_requiredSourceExpressionType_3870.getter_plmTypeDescriptionName (HERE))).boolEnum () ;
    if (kBoolTrue == test_5) {
      TC_Array <C_FixItDescription> fixItArray6 ;
      inCompiler->emitSemanticError (object->mProperty_mSourceExpressionLocation, GALGAS_string ("bit expression type should be $").add_operation (var_requiredSourceExpressionType_3870.getter_plmTypeDescriptionName (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 109)), fixItArray6  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 109)) ;
    }
  }
  GALGAS_uint var_registerBitCount_5908 ;
  GALGAS_string var_llvmRegisterAddressName_5981 ;
  GALGAS_PLMType joker_5864 ; // Joker input parameter
  GALGAS_sliceMap joker_5923 ; // Joker input parameter
  extensionMethod_controlRegisterLValueSemanticAnalysis (object->mProperty_mControlRegisterLValue, GALGAS_bool (false), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, joker_5864, var_registerBitCount_5908, joker_5923, var_llvmRegisterAddressName_5981, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 112)) ;
  GALGAS_PLMType var_requiredBitExpressionType_6222 ;
  GALGAS_uint joker_6228_1 ; // Joker input parameter
  constinArgument_inContext.getter_mTypeMap (HERE).method_searchKey (GALGAS_lstring::constructor_new (GALGAS_string ("uint").add_operation (var_registerBitCount_5908.substract_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 133)).getter_uint (inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 133)), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 133)).getter_significantBitCount (SOURCE_FILE ("instruction-bit-banding.galgas", 133)).getter_string (SOURCE_FILE ("instruction-bit-banding.galgas", 133)), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 133)), object->mProperty_mBitExpressionLocation  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 133)), var_requiredBitExpressionType_6222, joker_6228_1, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 132)) ;
  GALGAS_objectIR var_bitExpressionOperand_6742 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mBitExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, var_requiredBitExpressionType_6222, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_bitExpressionOperand_6742, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 138)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_bitExpressionOperand_6742, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 153)) ;
  }
  GALGAS_bool test_7 = GALGAS_bool (kIsEqual, extensionGetter_type (var_bitExpressionOperand_6742, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 158)).getter_plmTypeDescriptionName (HERE).objectCompare (function_staticIntegerTypeName (inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 158)))) ;
  if (kBoolTrue == test_7.boolEnum ()) {
    test_7 = var_bitExpressionOperand_6742.getter_isLiteralInteger (SOURCE_FILE ("instruction-bit-banding.galgas", 158)) ;
  }
  const enumGalgasBool test_8 = test_7.boolEnum () ;
  if (kBoolTrue == test_8) {
    GALGAS_bigint var_value_7190 ;
    GALGAS_PLMType joker_7163_1 ; // Joker input parameter
    var_bitExpressionOperand_6742.method_literalInteger (joker_7163_1, var_value_7190, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 159)) ;
    GALGAS_bool test_9 = GALGAS_bool (kIsStrictInf, var_value_7190.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 160)))) ;
    if (kBoolTrue != test_9.boolEnum ()) {
      test_9 = GALGAS_bool (kIsSupOrEqual, var_value_7190.objectCompare (var_registerBitCount_5908.getter_bigint (SOURCE_FILE ("instruction-bit-banding.galgas", 160)))) ;
    }
    const enumGalgasBool test_10 = test_9.boolEnum () ;
    if (kBoolTrue == test_10) {
      TC_Array <C_FixItDescription> fixItArray11 ;
      inCompiler->emitSemanticError (object->mProperty_mBitExpressionLocation, GALGAS_string ("static value should be >= 0 and <").add_operation (var_registerBitCount_5908.getter_string (SOURCE_FILE ("instruction-bit-banding.galgas", 161)), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 161)), fixItArray11  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 161)) ;
    }else if (kBoolFalse == test_10) {
      var_bitExpressionOperand_6742 = GALGAS_objectIR::constructor_literalInteger (var_requiredBitExpressionType_6222, var_value_7190  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 163)) ;
    }
  }else if (kBoolFalse == test_8) {
    const enumGalgasBool test_12 = GALGAS_bool (kIsNotEqual, extensionGetter_type (var_bitExpressionOperand_6742, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 165)).getter_plmTypeDescriptionName (HERE).objectCompare (var_requiredBitExpressionType_6222.getter_plmTypeDescriptionName (HERE))).boolEnum () ;
    if (kBoolTrue == test_12) {
      TC_Array <C_FixItDescription> fixItArray13 ;
      inCompiler->emitSemanticError (object->mProperty_mBitExpressionLocation, GALGAS_string ("bit expression type should be $").add_operation (var_requiredBitExpressionType_6222.getter_plmTypeDescriptionName (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 166)), fixItArray13  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 166)) ;
    }
  }
  ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_bitbandInstructionIR::constructor_new (var_llvmRegisterAddressName_5981, var_bitExpressionOperand_6742, var_sourceExpressionOperand_4402, constinArgument_inContext.getter_mTargetParameters (HERE).getter_mBitbandRegisterBaseAddress (HERE).getter_bigint (HERE), constinArgument_inContext.getter_mTargetParameters (HERE).getter_mBitbandRegisterRelocationAddress (HERE).getter_bigint (HERE), constinArgument_inContext.getter_mTargetParameters (HERE).getter_mBitbandRegisterOffsetMultiplier (HERE).getter_bigint (HERE), constinArgument_inContext.getter_mTargetParameters (HERE).getter_mBitbandRegisterBitMultiplier (HERE).getter_bigint (HERE)  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 169))  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 169)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_bitbandInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_bitbandInstructionAST.mSlotID,
                                                    extensionMethod_bitbandInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_bitbandInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_bitbandInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                       Overriding extension method '@bitbandInstructionIR llvmInstructionCode'                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_bitbandInstructionIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                      GALGAS_string & ioArgument_ioLLVMcode,
                                                                      const GALGAS_generationContext /* constinArgument_inGenerationContext */,
                                                                      GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_bitbandInstructionIR * object = (const cPtr_bitbandInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_bitbandInstructionIR) ;
  GALGAS_string var_idx_9759 = ioArgument_ioGenerationAdds.getter_mUniqueIndex (HERE).getter_string (SOURCE_FILE ("instruction-bit-banding.galgas", 211)) ;
  ioArgument_ioGenerationAdds.mProperty_mUniqueIndex.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 212)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (";--- Bit band\n"), inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 213)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %byte.offset.").add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 214)).add_operation (GALGAS_string (" = sub i32 "), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 214)).add_operation (object->mProperty_mRegisterAddressLLVMname, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 214)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 214)).add_operation (object->mProperty_mBitbandRegisterBaseAddress.getter_string (SOURCE_FILE ("instruction-bit-banding.galgas", 214)), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 214)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 214)), inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 214)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %byte.offset.").add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 215)).add_operation (GALGAS_string (".mul = mul i32 %byte.offset."), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 215)).add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 215)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 215)).add_operation (object->mProperty_mBitbandRegisterOffsetMultiplier.getter_string (SOURCE_FILE ("instruction-bit-banding.galgas", 215)), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 215)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 215)), inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 215)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %bit.offset.").add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 216)).add_operation (GALGAS_string (".mul = mul i32 "), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 216)).add_operation (extensionGetter_llvmName (object->mProperty_mBitExpressionOperand, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 216)), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 216)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 216)).add_operation (object->mProperty_mBitbandRegisterBitMultiplier.getter_string (SOURCE_FILE ("instruction-bit-banding.galgas", 216)), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 216)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 216)), inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 216)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %offset.").add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 217)).add_operation (GALGAS_string (" = add i32 %byte.offset."), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 217)).add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 217)).add_operation (GALGAS_string (".mul, %bit.offset."), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 217)).add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 217)).add_operation (GALGAS_string (".mul\n"), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 217)), inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 217)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %bit.word.addr.").add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 218)).add_operation (GALGAS_string (" = add i32 %offset."), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 218)).add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 218)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 218)).add_operation (object->mProperty_mBitbandRegisterRelocationAddress.getter_string (SOURCE_FILE ("instruction-bit-banding.galgas", 218)), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 218)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 218)), inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 218)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %ptr.").add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 219)).add_operation (GALGAS_string (" = inttoptr i32 %bit.word.addr."), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 219)).add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 219)).add_operation (GALGAS_string (" to i32*\n"), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 219)), inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 219)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %value.").add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 220)).add_operation (GALGAS_string (" = zext i1 "), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 220)).add_operation (extensionGetter_llvmName (object->mProperty_mSourceExpressionOperand, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 220)), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 220)).add_operation (GALGAS_string (" to i32\n"), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 220)), inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 220)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  store i32 %value.").add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 221)).add_operation (GALGAS_string (", i32* %ptr."), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 221)).add_operation (var_idx_9759, inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 221)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 221)), inCompiler  COMMA_SOURCE_FILE ("instruction-bit-banding.galgas", 221)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_bitbandInstructionIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_bitbandInstructionIR.mSlotID,
                                            extensionMethod_bitbandInstructionIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_bitbandInstructionIR_llvmInstructionCode (defineExtensionMethod_bitbandInstructionIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     Overriding extension method '@bitbandInstructionIR enterAccessibleEntities'                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_bitbandInstructionIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * /* inObject */,
                                                                          GALGAS_accessibleEntities & /* ioArgument_ioAccessibleEntities */,
                                                                          GALGAS_uint & /* ioArgument_ioMaxBranchOfOnInstructions */,
                                                                          C_Compiler * /* inCompiler */
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_bitbandInstructionIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_bitbandInstructionIR.mSlotID,
                                                extensionMethod_bitbandInstructionIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_bitbandInstructionIR_enterAccessibleEntities (defineExtensionMethod_bitbandInstructionIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//        Overriding extension method '@varInstructionWithAssignmentAST noteInstructionTypesInPrecedenceGraph'         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_varInstructionWithAssignmentAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                                   GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                   C_Compiler * inCompiler
                                                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_varInstructionWithAssignmentAST * object = (const cPtr_varInstructionWithAssignmentAST *) inObject ;
  macroValidSharedObject (object, cPtr_varInstructionWithAssignmentAST) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mProperty_mOptionalTypeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_typeName_2791 = function_llvmTypeNameFromPLMname (object->mProperty_mOptionalTypeName, inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 68)) ;
    {
    ioArgument_ioGraph.setter_noteNode (var_typeName_2791 COMMA_SOURCE_FILE ("instruction-var.galgas", 69)) ;
    }
  }
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mSourceExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 71)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_varInstructionWithAssignmentAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_varInstructionWithAssignmentAST.mSlotID,
                                                              extensionMethod_varInstructionWithAssignmentAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_varInstructionWithAssignmentAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_varInstructionWithAssignmentAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//               Overriding extension method '@varInstructionAST noteInstructionTypesInPrecedenceGraph'                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_varInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                     GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_varInstructionAST * object = (const cPtr_varInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_varInstructionAST) ;
  GALGAS_lstring var_typeName_3202 = function_llvmTypeNameFromPLMname (object->mProperty_mTypeName, inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 77)) ;
  {
  ioArgument_ioGraph.setter_noteNode (var_typeName_3202 COMMA_SOURCE_FILE ("instruction-var.galgas", 78)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_varInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_varInstructionAST.mSlotID,
                                                              extensionMethod_varInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_varInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_varInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//             Overriding extension method '@varInstructionWithAssignmentAST instructionSemanticAnalysis'              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_varInstructionWithAssignmentAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                                         const GALGAS_PLMType constinArgument_inSelfType,
                                                                                         const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                                         const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                                         const GALGAS_semanticContext constinArgument_inContext,
                                                                                         const GALGAS_mode constinArgument_inCurrentMode,
                                                                                         GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                                         GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                                         GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                                         GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                                         GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_varInstructionWithAssignmentAST * object = (const cPtr_varInstructionWithAssignmentAST *) inObject ;
  macroValidSharedObject (object, cPtr_varInstructionWithAssignmentAST) ;
  GALGAS_PLMType temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, object->mProperty_mOptionalTypeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = function_voidType (inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 98)) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), object->mProperty_mOptionalTypeName, inCompiler  COMMA_SOURCE_FILE ("instruction-var.galgas", 99)).getter_type (inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 99)) ;
  }
  GALGAS_PLMType var_targetType_4261 = temp_0 ;
  GALGAS_objectIR var_sourcePossibleReference_4926 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mSourceExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, var_targetType_4261, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_sourcePossibleReference_4926, inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 102)) ;
  GALGAS_objectIR var_result_4943 = function_checkAssignmentCompatibility (var_sourcePossibleReference_4926, var_targetType_4261, object->mProperty_mVarName.getter_location (HERE), GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 116)) ;
  GALGAS_lstring var_plmLocalVariableName_5174 = GALGAS_lstring::constructor_new (object->mProperty_mVarName.getter_string (HERE).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 123)).add_operation (ioArgument_ioTemporaries.getter_mTemporaryIndex (HERE).getter_string (SOURCE_FILE ("instruction-var.galgas", 123)), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 123)), object->mProperty_mVarName.getter_location (SOURCE_FILE ("instruction-var.galgas", 123))  COMMA_SOURCE_FILE ("instruction-var.galgas", 123)) ;
  ioArgument_ioTemporaries.mProperty_mTemporaryIndex.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-var.galgas", 124)) ;
  {
  extensionSetter_insertLocalVariable (ioArgument_ioUniversalMap, object->mProperty_mVarName, extensionGetter_type (var_result_4943, inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 125)), var_plmLocalVariableName_5174, GALGAS_valuedObjectState::constructor_hasUnreadValue (SOURCE_FILE ("instruction-var.galgas", 125)), GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 125)) ;
  }
  ioArgument_ioAllocaList.addAssign_operation (function_llvmNameForLocalVariable (var_plmLocalVariableName_5174.getter_string (SOURCE_FILE ("instruction-var.galgas", 127)), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 127)), extensionGetter_type (var_result_4943, inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 127)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("instruction-var.galgas", 127)) ;
  {
  extensionSetter_appendCopyFromReferences (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, object->mProperty_mVarName.getter_location (SOURCE_FILE ("instruction-var.galgas", 131)), var_sourcePossibleReference_4926, GALGAS_LValueRepresentation::constructor_new (extensionGetter_type (var_result_4943, inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 133)), function_llvmNameForLocalVariable (var_plmLocalVariableName_5174.getter_string (SOURCE_FILE ("instruction-var.galgas", 133)), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 133))  COMMA_SOURCE_FILE ("instruction-var.galgas", 133)), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 129)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_varInstructionWithAssignmentAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_varInstructionWithAssignmentAST.mSlotID,
                                                    extensionMethod_varInstructionWithAssignmentAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_varInstructionWithAssignmentAST_instructionSemanticAnalysis (defineExtensionMethod_varInstructionWithAssignmentAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                    Overriding extension method '@varInstructionAST instructionSemanticAnalysis'                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_varInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                           const GALGAS_PLMType /* constinArgument_inSelfType */,
                                                                           const GALGAS_routineAttributes /* constinArgument_inRoutineAttributes */,
                                                                           const GALGAS_lstring /* constinArgument_inCallerNameForInvocationGraph */,
                                                                           const GALGAS_semanticContext constinArgument_inContext,
                                                                           const GALGAS_mode /* constinArgument_inCurrentMode */,
                                                                           GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                           GALGAS_staticEntityMap & /* ioArgument_ioStaticEntityMap */,
                                                                           GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                           GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                           GALGAS_instructionListIR & /* ioArgument_ioInstructionGenerationList */,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_varInstructionAST * object = (const cPtr_varInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_varInstructionAST) ;
  GALGAS_PLMType var_targetType_6541 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), object->mProperty_mTypeName, inCompiler  COMMA_SOURCE_FILE ("instruction-var.galgas", 151)).getter_type (inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 151)) ;
  const enumGalgasBool test_0 = extensionGetter_instanciable (var_targetType_6541, inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 153)).operator_not (SOURCE_FILE ("instruction-var.galgas", 153)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mVarName.getter_location (SOURCE_FILE ("instruction-var.galgas", 154)), GALGAS_string ("$").add_operation (var_targetType_6541.getter_plmTypeDescriptionName (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 154)).add_operation (GALGAS_string (" type is not instanciable"), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 154)), fixItArray1  COMMA_SOURCE_FILE ("instruction-var.galgas", 154)) ;
  }
  GALGAS_lstring var_plmName_6799 = GALGAS_lstring::constructor_new (object->mProperty_mVarName.getter_string (HERE).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 157)).add_operation (ioArgument_ioTemporaries.getter_mTemporaryIndex (HERE).getter_string (SOURCE_FILE ("instruction-var.galgas", 157)), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 157)), object->mProperty_mVarName.getter_location (SOURCE_FILE ("instruction-var.galgas", 157))  COMMA_SOURCE_FILE ("instruction-var.galgas", 157)) ;
  ioArgument_ioTemporaries.mProperty_mTemporaryIndex.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-var.galgas", 158)) ;
  {
  extensionSetter_insertLocalVariable (ioArgument_ioUniversalMap, object->mProperty_mVarName, var_targetType_6541, var_plmName_6799, GALGAS_valuedObjectState::constructor_noValue (SOURCE_FILE ("instruction-var.galgas", 159)), GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 159)) ;
  }
  ioArgument_ioAllocaList.addAssign_operation (function_llvmNameForLocalVariable (var_plmName_6799.getter_string (SOURCE_FILE ("instruction-var.galgas", 161)), inCompiler COMMA_SOURCE_FILE ("instruction-var.galgas", 161)), var_targetType_6541, GALGAS_bool (false)  COMMA_SOURCE_FILE ("instruction-var.galgas", 161)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_varInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_varInstructionAST.mSlotID,
                                                    extensionMethod_varInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_varInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_varInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//        Overriding extension method '@letInstructionWithAssignmentAST noteInstructionTypesInPrecedenceGraph'         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_letInstructionWithAssignmentAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                                   GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                   C_Compiler * inCompiler
                                                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_letInstructionWithAssignmentAST * object = (const cPtr_letInstructionWithAssignmentAST *) inObject ;
  macroValidSharedObject (object, cPtr_letInstructionWithAssignmentAST) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mProperty_mOptionalTypeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_typeName_2186 = function_llvmTypeNameFromPLMname (object->mProperty_mOptionalTypeName, inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 48)) ;
    {
    ioArgument_ioGraph.setter_noteNode (var_typeName_2186 COMMA_SOURCE_FILE ("instruction-let.galgas", 49)) ;
    }
  }
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mSourceExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 51)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_letInstructionWithAssignmentAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_letInstructionWithAssignmentAST.mSlotID,
                                                              extensionMethod_letInstructionWithAssignmentAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_letInstructionWithAssignmentAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_letInstructionWithAssignmentAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//             Overriding extension method '@letInstructionWithAssignmentAST instructionSemanticAnalysis'              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_letInstructionWithAssignmentAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                                         const GALGAS_PLMType constinArgument_inSelfType,
                                                                                         const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                                         const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                                         const GALGAS_semanticContext constinArgument_inContext,
                                                                                         const GALGAS_mode constinArgument_inCurrentMode,
                                                                                         GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                                         GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                                         GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                                         GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                                         GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_letInstructionWithAssignmentAST * object = (const cPtr_letInstructionWithAssignmentAST *) inObject ;
  macroValidSharedObject (object, cPtr_letInstructionWithAssignmentAST) ;
  GALGAS_PLMType temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, object->mProperty_mOptionalTypeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = function_voidType (inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 71)) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), object->mProperty_mOptionalTypeName, inCompiler  COMMA_SOURCE_FILE ("instruction-let.galgas", 72)).getter_type (inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 72)) ;
  }
  GALGAS_PLMType var_targetType_3334 = temp_0 ;
  GALGAS_objectIR var_expressionResult_3988 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mSourceExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, var_targetType_3334, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_expressionResult_3988, inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 75)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_expressionResult_3988, inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 89)) ;
  }
  GALGAS_objectIR var_result_4139 = function_checkAssignmentCompatibility (var_expressionResult_3988, var_targetType_3334, object->mProperty_mConstantName.getter_location (HERE), GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 94)) ;
  const enumGalgasBool test_2 = extensionGetter_instanciable (extensionGetter_type (var_result_4139, inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 102)), inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 102)).operator_not (SOURCE_FILE ("instruction-let.galgas", 102)).boolEnum () ;
  if (kBoolTrue == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (object->mProperty_mConstantName.getter_location (SOURCE_FILE ("instruction-let.galgas", 103)), GALGAS_string ("$").add_operation (extensionGetter_plmTypeDescriptionName (var_result_4139, inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 103)), inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 103)).add_operation (GALGAS_string (" type is not instanciable"), inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 103)), fixItArray3  COMMA_SOURCE_FILE ("instruction-let.galgas", 103)) ;
    var_result_4139.drop () ; // Release error dropped variable
  }
  GALGAS_lstring var_plmName_4529 = GALGAS_lstring::constructor_new (object->mProperty_mConstantName.getter_string (HERE).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 106)).add_operation (ioArgument_ioTemporaries.getter_mTemporaryIndex (HERE).getter_string (SOURCE_FILE ("instruction-let.galgas", 106)), inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 106)), object->mProperty_mConstantName.getter_location (SOURCE_FILE ("instruction-let.galgas", 106))  COMMA_SOURCE_FILE ("instruction-let.galgas", 106)) ;
  ioArgument_ioTemporaries.mProperty_mTemporaryIndex.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-let.galgas", 107)) ;
  const enumGalgasBool test_4 = GALGAS_bool (kIsNotEqual, extensionGetter_plmTypeDescriptionName (var_result_4139, inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 108)).objectCompare (function_staticIntegerTypeName (inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 108)))).boolEnum () ;
  if (kBoolTrue == test_4) {
    ioArgument_ioAllocaList.addAssign_operation (function_llvmNameForLocalVariable (var_plmName_4529.getter_string (SOURCE_FILE ("instruction-let.galgas", 109)), inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 109)), extensionGetter_type (var_result_4139, inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 109)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("instruction-let.galgas", 109)) ;
    {
    extensionSetter_appendStoreTemporaryReference (ioArgument_ioInstructionGenerationList, extensionGetter_type (var_result_4139, inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 111)), function_llvmNameForLocalVariable (var_plmName_4529.getter_string (SOURCE_FILE ("instruction-let.galgas", 112)), inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 112)), var_result_4139, inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 110)) ;
    }
  }
  {
  extensionSetter_insertLocalConstant (ioArgument_ioUniversalMap, object->mProperty_mConstantName, GALGAS_bool (false), extensionGetter_type (var_result_4139, inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 116)), var_plmName_4529, inCompiler COMMA_SOURCE_FILE ("instruction-let.galgas", 116)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_letInstructionWithAssignmentAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_letInstructionWithAssignmentAST.mSlotID,
                                                    extensionMethod_letInstructionWithAssignmentAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_letInstructionWithAssignmentAST_instructionSemanticAnalysis (defineExtensionMethod_letInstructionWithAssignmentAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//               Overriding extension method '@letInstructionNOP noteInstructionTypesInPrecedenceGraph'                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_letInstructionNOP_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * /* inObject */,
                                                                                     GALGAS_semanticTypePrecedenceGraph & /* ioArgument_ioGraph */,
                                                                                     C_Compiler * /* inCompiler */
                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_letInstructionNOP_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_letInstructionNOP.mSlotID,
                                                              extensionMethod_letInstructionNOP_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_letInstructionNOP_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_letInstructionNOP_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                    Overriding extension method '@letInstructionNOP instructionSemanticAnalysis'                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_letInstructionNOP_instructionSemanticAnalysis (const cPtr_instructionAST * /* inObject */,
                                                                           const GALGAS_PLMType /* constinArgument_inSelfType */,
                                                                           const GALGAS_routineAttributes /* constinArgument_inRoutineAttributes */,
                                                                           const GALGAS_lstring /* constinArgument_inCallerNameForInvocationGraph */,
                                                                           const GALGAS_semanticContext /* constinArgument_inContext */,
                                                                           const GALGAS_mode /* constinArgument_inCurrentMode */,
                                                                           GALGAS_semanticTemporariesStruct & /* ioArgument_ioTemporaries */,
                                                                           GALGAS_staticEntityMap & /* ioArgument_ioStaticEntityMap */,
                                                                           GALGAS_universalValuedObjectMap & /* ioArgument_ioUniversalMap */,
                                                                           GALGAS_allocaList & /* ioArgument_ioAllocaList */,
                                                                           GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  extensionSetter_appendNOP (ioArgument_ioInstructionGenerationList, inCompiler COMMA_SOURCE_FILE ("instruction-nop.galgas", 48)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_letInstructionNOP_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_letInstructionNOP.mSlotID,
                                                    extensionMethod_letInstructionNOP_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_letInstructionNOP_instructionSemanticAnalysis (defineExtensionMethod_letInstructionNOP_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//              Overriding extension method '@panicInstructionAST noteInstructionTypesInPrecedenceGraph'               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_panicInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                       GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_panicInstructionAST * object = (const cPtr_panicInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_panicInstructionAST) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mCodeExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 33)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_panicInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_panicInstructionAST.mSlotID,
                                                              extensionMethod_panicInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_panicInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_panicInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                   Overriding extension method '@panicInstructionAST instructionSemanticAnalysis'                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_panicInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                             const GALGAS_PLMType constinArgument_inSelfType,
                                                                             const GALGAS_routineAttributes /* constinArgument_inRoutineAttributes */,
                                                                             const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                             const GALGAS_semanticContext constinArgument_inContext,
                                                                             const GALGAS_mode constinArgument_inCurrentMode,
                                                                             GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                             GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                             GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                             GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                             GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_panicInstructionAST * object = (const cPtr_panicInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_panicInstructionAST) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_inCurrentMode.objectCompare (GALGAS_mode::constructor_panicMode (SOURCE_FILE ("instruction-panic.galgas", 53)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mInstructionLocation, GALGAS_string ("operations that can generate panic are not allowed in ").add_operation (function_panicModeName (inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 54)), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 54)).add_operation (GALGAS_string (" mode"), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 54)), fixItArray1  COMMA_SOURCE_FILE ("instruction-panic.galgas", 54)) ;
  }
  GALGAS_instructionListIR var_unusedInstructionListIR_3103 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-panic.galgas", 57)) ;
  GALGAS_objectIR var_result_3574 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mCodeExpression.ptr (), constinArgument_inSelfType, GALGAS_routineAttributes::constructor_none (SOURCE_FILE ("instruction-panic.galgas", 60)), constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext.getter_mPanicCodeType (HERE).getter_type (inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 62)), constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_unusedInstructionListIR_3103, var_result_3574, inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 58)) ;
  GALGAS_bool test_2 = GALGAS_bool (kIsStrictSup, var_unusedInstructionListIR_3103.getter_length (SOURCE_FILE ("instruction-panic.galgas", 74)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
  if (kBoolTrue != test_2.boolEnum ()) {
    test_2 = var_result_3574.getter_isLiteralInteger (SOURCE_FILE ("instruction-panic.galgas", 75)).operator_not (SOURCE_FILE ("instruction-panic.galgas", 75)) ;
  }
  GALGAS_bool test_3 = test_2 ;
  if (kBoolTrue != test_3.boolEnum ()) {
    test_3 = GALGAS_bool (kIsNotEqual, extensionGetter_plmTypeDescriptionName (var_result_3574, inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 76)).objectCompare (function_staticIntegerTypeName (inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 76)))) ;
  }
  const enumGalgasBool test_4 = test_3.boolEnum () ;
  if (kBoolTrue == test_4) {
    TC_Array <C_FixItDescription> fixItArray5 ;
    inCompiler->emitSemanticError (object->mProperty_mInstructionLocation, GALGAS_string ("throw expression should be a literal integer"), fixItArray5  COMMA_SOURCE_FILE ("instruction-panic.galgas", 77)) ;
  }else if (kBoolFalse == test_4) {
    GALGAS_bigint var_min_3940 ;
    GALGAS_bigint var_max_3953 ;
    GALGAS_bool joker_3955_2 ; // Joker input parameter
    GALGAS_uint joker_3955_1 ; // Joker input parameter
    constinArgument_inContext.getter_mPanicCodeType (HERE).getter_type (inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 79)).getter_kind (HERE).method_integer (var_min_3940, var_max_3953, joker_3955_2, joker_3955_1, inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 79)) ;
    GALGAS_bigint var_throwValue_4011 ;
    GALGAS_PLMType joker_3987_1 ; // Joker input parameter
    var_result_3574.method_literalInteger (joker_3987_1, var_throwValue_4011, inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 80)) ;
    GALGAS_bool test_6 = GALGAS_bool (kIsStrictInf, var_throwValue_4011.objectCompare (var_min_3940)) ;
    if (kBoolTrue != test_6.boolEnum ()) {
      test_6 = GALGAS_bool (kIsStrictSup, var_throwValue_4011.objectCompare (var_max_3953)) ;
    }
    const enumGalgasBool test_7 = test_6.boolEnum () ;
    if (kBoolTrue == test_7) {
      TC_Array <C_FixItDescription> fixItArray8 ;
      inCompiler->emitSemanticError (object->mProperty_mInstructionLocation, GALGAS_string ("panic expression cannot be represented by an `").add_operation (constinArgument_inContext.getter_mPanicCodeType (HERE).getter_key (inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 82)), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 82)), fixItArray8  COMMA_SOURCE_FILE ("instruction-panic.galgas", 82)) ;
    }else if (kBoolFalse == test_7) {
      const enumGalgasBool test_9 = GALGAS_bool (gOption_plm_5F_options_noPanicGeneration.getter_value ()).operator_not (SOURCE_FILE ("instruction-panic.galgas", 83)).boolEnum () ;
      if (kBoolTrue == test_9) {
        ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_panicInstructionIR::constructor_new (object->mProperty_mInstructionLocation, var_throwValue_4011  COMMA_SOURCE_FILE ("instruction-panic.galgas", 84))  COMMA_SOURCE_FILE ("instruction-panic.galgas", 84)) ;
      }
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_panicInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_panicInstructionAST.mSlotID,
                                                    extensionMethod_panicInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_panicInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_panicInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                        Overriding extension method '@panicInstructionIR llvmInstructionCode'                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_panicInstructionIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                    GALGAS_string & ioArgument_ioLLVMcode,
                                                                    const GALGAS_generationContext constinArgument_inGenerationContext,
                                                                    GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_panicInstructionIR * object = (const cPtr_panicInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_panicInstructionIR) ;
  GALGAS_uint var_staticStringIndex_5305 ;
  {
  extensionSetter_findOrAddStaticString (ioArgument_ioGenerationAdds.mProperty_mStaticEntityMap, object->mProperty_mThrowLocation.getter_file (inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 109)).getter_lastPathComponent (SOURCE_FILE ("instruction-panic.galgas", 109)).getter_stringByDeletingPathExtension (SOURCE_FILE ("instruction-panic.galgas", 109)), var_staticStringIndex_5305, inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 108)) ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  call void @raise.panic.").add_operation (var_staticStringIndex_5305.getter_string (SOURCE_FILE ("instruction-panic.galgas", 112)), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 112)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 112)), inCompiler  COMMA_SOURCE_FILE ("instruction-panic.galgas", 112)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(extensionGetter_llvmTypeName (constinArgument_inGenerationContext.getter_mPanicLineLLVMType (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 113)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 113)).add_operation (object->mProperty_mThrowLocation.getter_line (inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 113)).getter_string (SOURCE_FILE ("instruction-panic.galgas", 113)), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 113)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 113)), inCompiler  COMMA_SOURCE_FILE ("instruction-panic.galgas", 113)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(extensionGetter_llvmTypeName (constinArgument_inGenerationContext.getter_mPanicCodeLLVMType (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 114)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 114)).add_operation (object->mProperty_mPanicCode.getter_string (SOURCE_FILE ("instruction-panic.galgas", 114)), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 114)).add_operation (GALGAS_string (")\n"), inCompiler COMMA_SOURCE_FILE ("instruction-panic.galgas", 114)), inCompiler  COMMA_SOURCE_FILE ("instruction-panic.galgas", 114)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_panicInstructionIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_panicInstructionIR.mSlotID,
                                            extensionMethod_panicInstructionIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_panicInstructionIR_llvmInstructionCode (defineExtensionMethod_panicInstructionIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      Overriding extension method '@panicInstructionIR enterAccessibleEntities'                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_panicInstructionIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * /* inObject */,
                                                                        GALGAS_accessibleEntities & /* ioArgument_ioAccessibleEntities */,
                                                                        GALGAS_uint & /* ioArgument_ioMaxBranchOfOnInstructions */,
                                                                        C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_panicInstructionIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_panicInstructionIR.mSlotID,
                                                extensionMethod_panicInstructionIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_panicInstructionIR_enterAccessibleEntities (defineExtensionMethod_panicInstructionIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                Overriding extension method '@ifInstructionAST noteInstructionTypesInPrecedenceGraph'                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_ifInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                    GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_ifInstructionAST * object = (const cPtr_ifInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_ifInstructionAST) ;
  extensionMethod_noteInstructionListTypesInPrecedenceGraph (object->mProperty_mThenInstructionList, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 89)) ;
  extensionMethod_noteInstructionListTypesInPrecedenceGraph (object->mProperty_mElseInstructionList, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 90)) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mTestExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 91)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_ifInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_ifInstructionAST.mSlotID,
                                                              extensionMethod_ifInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_ifInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_ifInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     Overriding extension method '@ifInstructionAST instructionSemanticAnalysis'                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_ifInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                          const GALGAS_PLMType constinArgument_inSelfType,
                                                                          const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                          const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                          const GALGAS_semanticContext constinArgument_inContext,
                                                                          const GALGAS_mode constinArgument_inCurrentMode,
                                                                          GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                          GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                          GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                          GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                          GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_ifInstructionAST * object = (const cPtr_ifInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_ifInstructionAST) ;
  GALGAS_objectIR var_testResult_5148 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mTestExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, function_voidType (inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 115)), constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_testResult_5148, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 111)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_testResult_5148, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 125)) ;
  }
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, extensionGetter_type (var_testResult_5148, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 130)).getter_kind (HERE).objectCompare (GALGAS_typeKind::constructor_boolean (SOURCE_FILE ("instruction-if.galgas", 130)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mTestExpressionEndLocation, GALGAS_string ("test expression type is '").add_operation (extensionGetter_plmTypeDescriptionName (var_testResult_5148, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 131)), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 131)).add_operation (GALGAS_string ("', it should be boolean"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 131)), fixItArray1  COMMA_SOURCE_FILE ("instruction-if.galgas", 131)) ;
  }else if (kBoolFalse == test_0) {
    GALGAS_bool test_2 = object->mProperty_mStaticIfExpression ;
    if (kBoolTrue == test_2.boolEnum ()) {
      test_2 = extensionGetter_isStatic (var_testResult_5148, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 132)).operator_not (SOURCE_FILE ("instruction-if.galgas", 132)) ;
    }
    const enumGalgasBool test_3 = test_2.boolEnum () ;
    if (kBoolTrue == test_3) {
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (object->mProperty_mTestExpressionEndLocation, GALGAS_string ("'if' expression is not static"), fixItArray4  COMMA_SOURCE_FILE ("instruction-if.galgas", 133)) ;
    }else if (kBoolFalse == test_3) {
      GALGAS_bool test_5 = extensionGetter_isStatic (var_testResult_5148, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 134)) ;
      if (kBoolTrue == test_5.boolEnum ()) {
        test_5 = object->mProperty_mStaticIfExpression.operator_not (SOURCE_FILE ("instruction-if.galgas", 134)) ;
      }
      const enumGalgasBool test_6 = test_5.boolEnum () ;
      if (kBoolTrue == test_6) {
        TC_Array <C_FixItDescription> fixItArray7 ;
        inCompiler->emitSemanticWarning (object->mProperty_mTestExpressionEndLocation, GALGAS_string ("'if' expression is static (insert @").add_operation (function_staticAttribute (inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 135)), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 135)).add_operation (GALGAS_string (" attribute)"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 135)), fixItArray7  COMMA_SOURCE_FILE ("instruction-if.galgas", 135)) ;
      }
    }
  }
  {
  extensionSetter_openOverrideForSelectBlock (ioArgument_ioUniversalMap, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 137)) ;
  }
  GALGAS_instructionListIR var_thenInstructionGenerationList_5908 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-if.galgas", 139)) ;
  extensionMethod_analyzeBranchInstructionList (object->mProperty_mThenInstructionList, constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, object->mProperty_mEndOfThenInstructionList, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_thenInstructionGenerationList_5908, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 140)) ;
  GALGAS_instructionListIR var_elseInstructionGenerationList_6470 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-if.galgas", 154)) ;
  extensionMethod_analyzeBranchInstructionList (object->mProperty_mElseInstructionList, constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, object->mProperty_mEndOfElseInstructionList, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_elseInstructionGenerationList_6470, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 155)) ;
  {
  extensionSetter_closeOverride (ioArgument_ioUniversalMap, object->mProperty_mEndOf_5F_if_5F_instruction, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 168)) ;
  }
  ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_ifInstructionIR::constructor_new (var_testResult_5148, object->mProperty_mTestExpressionEndLocation, var_thenInstructionGenerationList_5908, var_elseInstructionGenerationList_6470  COMMA_SOURCE_FILE ("instruction-if.galgas", 170))  COMMA_SOURCE_FILE ("instruction-if.galgas", 170)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_ifInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_ifInstructionAST.mSlotID,
                                                    extensionMethod_ifInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_ifInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_ifInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                         Overriding extension method '@ifInstructionIR llvmInstructionCode'                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_ifInstructionIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                 GALGAS_string & ioArgument_ioLLVMcode,
                                                                 const GALGAS_generationContext constinArgument_inGenerationContext,
                                                                 GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_ifInstructionIR * object = (const cPtr_ifInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_ifInstructionIR) ;
  GALGAS_string var_labelTrue_8072 = GALGAS_string ("if.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 196)).getter_string (SOURCE_FILE ("instruction-if.galgas", 196)), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 196)).add_operation (GALGAS_string (".true"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 196)) ;
  GALGAS_string var_labelFalse_8135 = GALGAS_string ("if.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 197)).getter_string (SOURCE_FILE ("instruction-if.galgas", 197)), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 197)).add_operation (GALGAS_string (".false"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 197)) ;
  GALGAS_string var_labelEnd_8197 = GALGAS_string ("if.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 198)).getter_string (SOURCE_FILE ("instruction-if.galgas", 198)), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 198)).add_operation (GALGAS_string (".end"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 198)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 ").add_operation (extensionGetter_llvmName (object->mProperty_mTestVariable, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 199)), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 199)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 199)).add_operation (var_labelTrue_8072, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 199)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 199)).add_operation (var_labelFalse_8135, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 199)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 199)), inCompiler  COMMA_SOURCE_FILE ("instruction-if.galgas", 199)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_labelTrue_8072.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 201)), inCompiler  COMMA_SOURCE_FILE ("instruction-if.galgas", 201)) ;
  extensionMethod_instructionListLLVMCode (object->mProperty_mThenInstructionGenerationList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 202)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_labelEnd_8197, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 203)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 203)), inCompiler  COMMA_SOURCE_FILE ("instruction-if.galgas", 203)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_labelFalse_8135.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 205)), inCompiler  COMMA_SOURCE_FILE ("instruction-if.galgas", 205)) ;
  extensionMethod_instructionListLLVMCode (object->mProperty_mElseInstructionGenerationList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 206)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_labelEnd_8197, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 207)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 207)), inCompiler  COMMA_SOURCE_FILE ("instruction-if.galgas", 207)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_labelEnd_8197.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 209)), inCompiler  COMMA_SOURCE_FILE ("instruction-if.galgas", 209)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_ifInstructionIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_ifInstructionIR.mSlotID,
                                            extensionMethod_ifInstructionIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_ifInstructionIR_llvmInstructionCode (defineExtensionMethod_ifInstructionIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                       Overriding extension method '@ifInstructionIR enterAccessibleEntities'                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_ifInstructionIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * inObject,
                                                                     GALGAS_accessibleEntities & ioArgument_ioAccessibleEntities,
                                                                     GALGAS_uint & ioArgument_ioMaxBranchOfOnInstructions,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_ifInstructionIR * object = (const cPtr_ifInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_ifInstructionIR) ;
  extensionMethod_enterAccessibleEntities (object->mProperty_mThenInstructionGenerationList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 218)) ;
  extensionMethod_enterAccessibleEntities (object->mProperty_mElseInstructionGenerationList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-if.galgas", 219)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_ifInstructionIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_ifInstructionIR.mSlotID,
                                                extensionMethod_ifInstructionIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_ifInstructionIR_enterAccessibleEntities (defineExtensionMethod_ifInstructionIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//               Overriding extension method '@syncInstructionAST noteInstructionTypesInPrecedenceGraph'               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_syncInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                      GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_syncInstructionAST * object = (const cPtr_syncInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_syncInstructionAST) ;
  cEnumerator_syncInstructionBranchListAST enumerator_5027 (object->mProperty_mBranchList, kENUMERATION_UP) ;
  while (enumerator_5027.hasCurrentObject ()) {
    extensionMethod_noteInstructionListTypesInPrecedenceGraph (enumerator_5027.current_mInstructionList (HERE), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 142)) ;
    enumerator_5027.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_syncInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_syncInstructionAST.mSlotID,
                                                              extensionMethod_syncInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_syncInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_syncInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                    Overriding extension method '@syncInstructionAST instructionSemanticAnalysis'                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_syncInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                            const GALGAS_PLMType constinArgument_inSelfType,
                                                                            const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                            const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                            const GALGAS_semanticContext constinArgument_inContext,
                                                                            const GALGAS_mode constinArgument_inMode,
                                                                            GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                            GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                            GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                            GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                            GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_syncInstructionAST * object = (const cPtr_syncInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_syncInstructionAST) ;
  GALGAS_guardedCommandIRList var_guardedCommandIRList_6129 = GALGAS_guardedCommandIRList::constructor_emptyList (SOURCE_FILE ("instruction-sync.galgas", 163)) ;
  cEnumerator_syncInstructionBranchListAST enumerator_6200 (object->mProperty_mBranchList, kENUMERATION_UP) ;
  while (enumerator_6200.hasCurrentObject ()) {
    switch (enumerator_6200.current_mGuardedCommand (HERE).enumValue ()) {
    case GALGAS_guardedCommandAST::kNotBuilt:
      break ;
    case GALGAS_guardedCommandAST::kEnum_boolean:
      {
        const cEnumAssociatedValues_guardedCommandAST_boolean * extractPtr_7453 = (const cEnumAssociatedValues_guardedCommandAST_boolean *) (enumerator_6200.current_mGuardedCommand (HERE).unsafePointer ()) ;
        const GALGAS_bool extractedValue_isContinue = extractPtr_7453->mAssociatedValue0 ;
        const GALGAS_expressionAST extractedValue_expression = extractPtr_7453->mAssociatedValue1 ;
        const GALGAS_location extractedValue_endOfExpression = extractPtr_7453->mAssociatedValue2 ;
        GALGAS_instructionListIR var_guardInstructionGenerationList_6344 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-sync.galgas", 167)) ;
        GALGAS_objectIR var_sourceOperand_6869 ;
        callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) extractedValue_expression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes.operator_or (GALGAS_routineAttributes::constructor_guard (SOURCE_FILE ("instruction-sync.galgas", 170)) COMMA_SOURCE_FILE ("instruction-sync.galgas", 170)), constinArgument_inCallerNameForInvocationGraph, function_voidType (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 172)), constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_guardInstructionGenerationList_6344, var_sourceOperand_6869, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 168)) ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, extensionGetter_plmTypeDescriptionName (var_sourceOperand_6869, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 182)).objectCompare (function_boolTypeDescriptionName (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 182)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          TC_Array <C_FixItDescription> fixItArray1 ;
          inCompiler->emitSemanticError (extractedValue_endOfExpression, GALGAS_string ("guarded expression should be boolean"), fixItArray1  COMMA_SOURCE_FILE ("instruction-sync.galgas", 183)) ;
        }else if (kBoolFalse == test_0) {
          const enumGalgasBool test_2 = extensionGetter_isStatic (var_sourceOperand_6869, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 184)).boolEnum () ;
          if (kBoolTrue == test_2) {
            TC_Array <C_FixItDescription> fixItArray3 ;
            inCompiler->emitSemanticWarning (extractedValue_endOfExpression, GALGAS_string ("guarded expression is static"), fixItArray3  COMMA_SOURCE_FILE ("instruction-sync.galgas", 185)) ;
          }
        }
        {
        extensionSetter_appendLoadWhenReference (var_guardInstructionGenerationList_6344, ioArgument_ioTemporaries, var_sourceOperand_6869, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 187)) ;
        }
        var_guardedCommandIRList_6129.addAssign_operation (GALGAS_guardedCommandIR::constructor_booleanGuard (extractedValue_isContinue, var_guardInstructionGenerationList_6344, var_sourceOperand_6869  COMMA_SOURCE_FILE ("instruction-sync.galgas", 191))  COMMA_SOURCE_FILE ("instruction-sync.galgas", 191)) ;
      }
      break ;
    case GALGAS_guardedCommandAST::kEnum_boolAndSync:
      {
        const cEnumAssociatedValues_guardedCommandAST_boolAndSync * extractPtr_13192 = (const cEnumAssociatedValues_guardedCommandAST_boolAndSync *) (enumerator_6200.current_mGuardedCommand (HERE).unsafePointer ()) ;
        const GALGAS_bool extractedValue_isContinue = extractPtr_13192->mAssociatedValue0 ;
        const GALGAS_expressionAST extractedValue_exp = extractPtr_13192->mAssociatedValue1 ;
        const GALGAS_bool extractedValue_warnsOnStaticExpression = extractPtr_13192->mAssociatedValue2 ;
        const GALGAS_location extractedValue_endOfExp = extractPtr_13192->mAssociatedValue3 ;
        const GALGAS_lbool extractedValue_usesSelf = extractPtr_13192->mAssociatedValue4 ;
        const GALGAS_lstringlist extractedValue_nameList = extractPtr_13192->mAssociatedValue5 ;
        const GALGAS_effectiveArgumentListAST extractedValue_parameterList = extractPtr_13192->mAssociatedValue6 ;
        GALGAS_instructionListIR var_boolExpInstructionGenerationList_7616 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-sync.galgas", 197)) ;
        GALGAS_objectIR var_boolExpressionResult_8162 ;
        callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) extractedValue_exp.ptr (), constinArgument_inSelfType, GALGAS_routineAttributes::constructor_guard (SOURCE_FILE ("instruction-sync.galgas", 201)), constinArgument_inCallerNameForInvocationGraph, function_voidType (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 203)), constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_boolExpInstructionGenerationList_7616, var_boolExpressionResult_8162, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 199)) ;
        const enumGalgasBool test_4 = GALGAS_bool (kIsNotEqual, extensionGetter_plmTypeDescriptionName (var_boolExpressionResult_8162, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 213)).objectCompare (function_boolTypeDescriptionName (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 213)))).boolEnum () ;
        if (kBoolTrue == test_4) {
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (extractedValue_endOfExp, GALGAS_string ("guarded expression should be boolean"), fixItArray5  COMMA_SOURCE_FILE ("instruction-sync.galgas", 214)) ;
        }else if (kBoolFalse == test_4) {
          GALGAS_bool test_6 = extractedValue_warnsOnStaticExpression ;
          if (kBoolTrue == test_6.boolEnum ()) {
            test_6 = extensionGetter_isStatic (var_boolExpressionResult_8162, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 215)) ;
          }
          const enumGalgasBool test_7 = test_6.boolEnum () ;
          if (kBoolTrue == test_7) {
            TC_Array <C_FixItDescription> fixItArray8 ;
            inCompiler->emitSemanticWarning (extractedValue_endOfExp, GALGAS_string ("guarded expression is static"), fixItArray8  COMMA_SOURCE_FILE ("instruction-sync.galgas", 216)) ;
          }
        }
        {
        extensionSetter_appendLoadWhenReference (var_boolExpInstructionGenerationList_7616, ioArgument_ioTemporaries, var_boolExpressionResult_8162, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 218)) ;
        }
        GALGAS_instructionListIR var_guardInstructionGenerationList_8686 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-sync.galgas", 223)) ;
        GALGAS_procCallEffectiveParameterListIR var_guardEffectiveParameterListIR_8761 ;
        GALGAS_lstring var_guardMangledName_8793 ;
        const enumGalgasBool test_9 = extractedValue_usesSelf.getter_bool (HERE).boolEnum () ;
        if (kBoolTrue == test_9) {
          const enumGalgasBool test_10 = constinArgument_inSelfType.getter_kind (HERE).getter_isVoid (SOURCE_FILE ("instruction-sync.galgas", 227)).boolEnum () ;
          if (kBoolTrue == test_10) {
            TC_Array <C_FixItDescription> fixItArray11 ;
            inCompiler->emitSemanticError (extractedValue_usesSelf.getter_location (SOURCE_FILE ("instruction-sync.galgas", 228)), GALGAS_string ("'self' is not available in this context"), fixItArray11  COMMA_SOURCE_FILE ("instruction-sync.galgas", 228)) ;
            var_guardEffectiveParameterListIR_8761.drop () ; // Release error dropped variable
            var_guardMangledName_8793.drop () ; // Release error dropped variable
          }else if (kBoolFalse == test_10) {
            GALGAS_lstringlist var_propertyList_9041 = extractedValue_nameList ;
            GALGAS_lstring var_guardName_9101 ;
            {
            var_propertyList_9041.setter_popLast (var_guardName_9101, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 231)) ;
            }
            GALGAS_objectIR var_currentObject_9136 = GALGAS_objectIR::constructor_reference (constinArgument_inSelfType, function_llvmNameForSelf (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 232))  COMMA_SOURCE_FILE ("instruction-sync.galgas", 232)) ;
            cEnumerator_lstringlist enumerator_9242 (var_propertyList_9041, kENUMERATION_UP) ;
            while (enumerator_9242.hasCurrentObject ()) {
              {
              routine_handlePropertyAccessInExpression (var_currentObject_9136, enumerator_9242.current_mValue (HERE), ioArgument_ioTemporaries, ioArgument_ioInstructionGenerationList, inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 234)) ;
              }
              enumerator_9242.gotoNextObject () ;
            }
            {
            routine_analyzeGuardCall (constinArgument_inSelfType, constinArgument_inRoutineAttributes, var_currentObject_9136, var_guardName_9101, extractedValue_parameterList, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_guardInstructionGenerationList_8686, var_guardEffectiveParameterListIR_8761, var_guardMangledName_8793, inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 241)) ;
            }
          }
        }else if (kBoolFalse == test_9) {
          const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, extractedValue_nameList.getter_length (SOURCE_FILE ("instruction-sync.galgas", 259)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
          if (kBoolTrue == test_12) {
            {
            routine_analyzeStandaloneGuardCall (constinArgument_inSelfType, constinArgument_inRoutineAttributes, extractedValue_nameList.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 263)), extractedValue_parameterList, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_guardInstructionGenerationList_8686, var_guardEffectiveParameterListIR_8761, var_guardMangledName_8793, inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 260)) ;
            }
          }else if (kBoolFalse == test_12) {
            GALGAS_lstringlist var_propertyList_10983 = extractedValue_nameList ;
            GALGAS_lstring var_globalReceiverName_11051 ;
            {
            var_propertyList_10983.setter_popFirst (var_globalReceiverName_11051, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 278)) ;
            }
            GALGAS_lstring var_guardName_11099 ;
            {
            var_propertyList_10983.setter_popLast (var_guardName_11099, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 279)) ;
            }
            GALGAS_objectIR var_currentObjectIR_11282 ;
            extensionMethod_searchValuedObject (ioArgument_ioUniversalMap, var_globalReceiverName_11051, constinArgument_inRoutineAttributes, ioArgument_ioTemporaries.getter_mInitializedDriverSet (HERE), var_currentObjectIR_11282, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 280)) ;
            cEnumerator_lstringlist enumerator_11335 (var_propertyList_10983, kENUMERATION_UP) ;
            while (enumerator_11335.hasCurrentObject ()) {
              {
              routine_handlePropertyAccessInExpression (var_currentObjectIR_11282, enumerator_11335.current_mValue (HERE), ioArgument_ioTemporaries, ioArgument_ioInstructionGenerationList, inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 287)) ;
              }
              enumerator_11335.gotoNextObject () ;
            }
            {
            routine_analyzeGuardCall (constinArgument_inSelfType, constinArgument_inRoutineAttributes, var_currentObjectIR_11282, var_guardName_11099, extractedValue_parameterList, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_guardInstructionGenerationList_8686, var_guardEffectiveParameterListIR_8761, var_guardMangledName_8793, inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 294)) ;
            }
          }
        }
        const enumGalgasBool test_13 = var_boolExpressionResult_8162.getter_isLiteralInteger (SOURCE_FILE ("instruction-sync.galgas", 312)).boolEnum () ;
        if (kBoolTrue == test_13) {
          GALGAS_bigint var_value_12354 ;
          GALGAS_PLMType joker_12327_1 ; // Joker input parameter
          var_boolExpressionResult_8162.method_literalInteger (joker_12327_1, var_value_12354, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 313)) ;
          const enumGalgasBool test_14 = GALGAS_bool (kIsEqual, var_value_12354.objectCompare (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 314)))).boolEnum () ;
          if (kBoolTrue == test_14) {
            var_guardedCommandIRList_6129.addAssign_operation (GALGAS_guardedCommandIR::constructor_sync (extractedValue_isContinue, var_guardMangledName_8793.getter_string (HERE), var_guardInstructionGenerationList_8686, var_guardEffectiveParameterListIR_8761  COMMA_SOURCE_FILE ("instruction-sync.galgas", 315))  COMMA_SOURCE_FILE ("instruction-sync.galgas", 315)) ;
          }else if (kBoolFalse == test_14) {
            TC_Array <C_FixItDescription> fixItArray15 ;
            inCompiler->emitSemanticError (var_guardMangledName_8793.getter_location (SOURCE_FILE ("instruction-sync.galgas", 322)), GALGAS_string ("false guard not handled yet"), fixItArray15  COMMA_SOURCE_FILE ("instruction-sync.galgas", 322)) ;
          }
        }else if (kBoolFalse == test_13) {
          var_guardedCommandIRList_6129.addAssign_operation (GALGAS_guardedCommandIR::constructor_boolAndSync (extractedValue_isContinue, var_boolExpInstructionGenerationList_7616, var_boolExpressionResult_8162, var_guardMangledName_8793.getter_string (HERE), var_guardInstructionGenerationList_8686, var_guardEffectiveParameterListIR_8761  COMMA_SOURCE_FILE ("instruction-sync.galgas", 325))  COMMA_SOURCE_FILE ("instruction-sync.galgas", 325)) ;
        }
      }
      break ;
    }
    enumerator_6200.gotoNextObject () ;
  }
  {
  extensionSetter_openOverrideForSelectBlock (ioArgument_ioUniversalMap, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 337)) ;
  }
  GALGAS_syncInstructionBranchListIR var_syncInstructionBranchListIR_13353 = GALGAS_syncInstructionBranchListIR::constructor_emptyList (SOURCE_FILE ("instruction-sync.galgas", 338)) ;
  cEnumerator_syncInstructionBranchListAST enumerator_13411 (object->mProperty_mBranchList, kENUMERATION_UP) ;
  cEnumerator_guardedCommandIRList enumerator_13455 (var_guardedCommandIRList_6129, kENUMERATION_UP) ;
  while (enumerator_13411.hasCurrentObject () && enumerator_13455.hasCurrentObject ()) {
    GALGAS_instructionListIR var_branchInstructionGenerationList_13513 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-sync.galgas", 340)) ;
    extensionMethod_analyzeBranchInstructionList (enumerator_13411.current_mInstructionList (HERE), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, enumerator_13411.current_mEndOfBranch (HERE), constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_branchInstructionGenerationList_13513, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 341)) ;
    var_syncInstructionBranchListIR_13353.addAssign_operation (enumerator_13455.current_mGuardedCommand (HERE), var_branchInstructionGenerationList_13513  COMMA_SOURCE_FILE ("instruction-sync.galgas", 354)) ;
    enumerator_13411.gotoNextObject () ;
    enumerator_13455.gotoNextObject () ;
  }
  {
  extensionSetter_closeOverride (ioArgument_ioUniversalMap, object->mProperty_mEndOf_5F_on_5F_instruction, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 356)) ;
  }
  ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_syncInstructionIR::constructor_new (object->mProperty_mInstructionLocation, var_syncInstructionBranchListIR_13353  COMMA_SOURCE_FILE ("instruction-sync.galgas", 358))  COMMA_SOURCE_FILE ("instruction-sync.galgas", 358)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_syncInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_syncInstructionAST.mSlotID,
                                                    extensionMethod_syncInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_syncInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_syncInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Routine 'analyzeGuardCall'                                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_analyzeGuardCall (const GALGAS_PLMType constinArgument_inSelfType,
                               const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                               const GALGAS_objectIR constinArgument_inReceiver,
                               const GALGAS_lstring constinArgument_inGuardName,
                               const GALGAS_effectiveArgumentListAST constinArgument_inEffectiveParameterList,
                               const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                               const GALGAS_semanticContext constinArgument_inContext,
                               const GALGAS_mode constinArgument_inRequiredMode,
                               GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                               GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                               GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                               GALGAS_allocaList & ioArgument_ioAllocaList,
                               GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                               GALGAS_procCallEffectiveParameterListIR & outArgument_outEffectiveParameterListIR,
                               GALGAS_lstring & outArgument_outGuardMangledName,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outEffectiveParameterListIR.drop () ; // Release 'out' argument
  outArgument_outGuardMangledName.drop () ; // Release 'out' argument
  GALGAS_guardMapForContext var_guardMap_15243 = extensionGetter_type (constinArgument_inReceiver, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 380)).getter_guardMap (SOURCE_FILE ("instruction-sync.galgas", 380)) ;
  GALGAS_lstring var_guardMangledName_15297 = function_routineMangledNameFromCall (GALGAS_string::makeEmptyString (), constinArgument_inGuardName, constinArgument_inEffectiveParameterList, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 381)) ;
  GALGAS_bool var_isPublic_15425 ;
  GALGAS_routineTypedSignature var_formalSignature_15469 ;
  var_guardMap_15243.method_searchKey (var_guardMangledName_15297, var_isPublic_15425, var_formalSignature_15469, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 382)) ;
  const enumGalgasBool test_0 = var_isPublic_15425.operator_not (SOURCE_FILE ("instruction-sync.galgas", 384)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (constinArgument_inGuardName.getter_location (SOURCE_FILE ("instruction-sync.galgas", 385)), GALGAS_string ("this guard is not public"), fixItArray1  COMMA_SOURCE_FILE ("instruction-sync.galgas", 385)) ;
    outArgument_outGuardMangledName.drop () ; // Release error dropped variable
    outArgument_outEffectiveParameterListIR.drop () ; // Release error dropped variable
  }else if (kBoolFalse == test_0) {
    outArgument_outGuardMangledName = function_routineMangledNameFromCall (function_llvmTypeStringFromPLMname (extensionGetter_type (constinArgument_inReceiver, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 388)).getter_plmTypeDescriptionName (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 388)), constinArgument_inGuardName, constinArgument_inEffectiveParameterList, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 387)) ;
    {
    ioArgument_ioTemporaries.mProperty_mSubprogramInvocationGraph.setter_addEdge (constinArgument_inCallerNameForInvocationGraph, outArgument_outGuardMangledName COMMA_SOURCE_FILE ("instruction-sync.galgas", 393)) ;
    }
    GALGAS_procCallEffectiveParameterListIR temp_2 = GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (SOURCE_FILE ("instruction-sync.galgas", 395)) ;
    temp_2.addAssign_operation (GALGAS_procEffectiveParameterPassingModeIR::constructor_outputInput (SOURCE_FILE ("instruction-sync.galgas", 395)), constinArgument_inReceiver  COMMA_SOURCE_FILE ("instruction-sync.galgas", 395)) ;
    outArgument_outEffectiveParameterListIR = temp_2 ;
    {
    routine_analyzeEffectiveParameters (constinArgument_inSelfType, constinArgument_inRoutineAttributes, var_formalSignature_15469, constinArgument_inEffectiveParameterList, constinArgument_inGuardName.getter_location (HERE), constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inRequiredMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, outArgument_outEffectiveParameterListIR, inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 396)) ;
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                        Routine 'analyzeStandaloneGuardCall'                                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_analyzeStandaloneGuardCall (const GALGAS_PLMType constinArgument_inSelfType,
                                         const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                         const GALGAS_lstring constinArgument_inGuardName,
                                         const GALGAS_effectiveArgumentListAST constinArgument_inEffectiveParameterList,
                                         const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                         const GALGAS_semanticContext constinArgument_inContext,
                                         const GALGAS_mode constinArgument_inRequiredMode,
                                         GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                         GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                         GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                         GALGAS_allocaList & ioArgument_ioAllocaList,
                                         GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                         GALGAS_procCallEffectiveParameterListIR & outArgument_outEffectiveParameterListIR,
                                         GALGAS_lstring & outArgument_outGuardMangledName,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outEffectiveParameterListIR.drop () ; // Release 'out' argument
  outArgument_outGuardMangledName.drop () ; // Release 'out' argument
  outArgument_outGuardMangledName = function_routineMangledNameFromCall (GALGAS_string::makeEmptyString (), constinArgument_inGuardName, constinArgument_inEffectiveParameterList, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 433)) ;
  GALGAS_bool var_isPublic_17759 ;
  GALGAS_routineTypedSignature var_formalSignature_17807 ;
  constinArgument_inContext.getter_mGuardMapForContext (HERE).method_searchKey (outArgument_outGuardMangledName, var_isPublic_17759, var_formalSignature_17807, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 438)) ;
  const enumGalgasBool test_0 = var_isPublic_17759.operator_not (SOURCE_FILE ("instruction-sync.galgas", 444)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_string var_declarationFile_17891 = constinArgument_inContext.getter_mGuardMapForContext (HERE).getter_locationForKey (outArgument_outGuardMangledName.getter_string (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 445)).getter_file (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 445)) ;
    GALGAS_string var_invocationFile_17998 = constinArgument_inGuardName.getter_location (HERE).getter_file (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 446)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_invocationFile_17998.objectCompare (var_declarationFile_17891)).boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_inGuardName.getter_location (SOURCE_FILE ("instruction-sync.galgas", 448)), GALGAS_string ("this guard is not public"), fixItArray2  COMMA_SOURCE_FILE ("instruction-sync.galgas", 448)) ;
    }
  }
  {
  ioArgument_ioTemporaries.mProperty_mSubprogramInvocationGraph.setter_addEdge (constinArgument_inCallerNameForInvocationGraph, outArgument_outGuardMangledName COMMA_SOURCE_FILE ("instruction-sync.galgas", 452)) ;
  }
  outArgument_outEffectiveParameterListIR = GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (SOURCE_FILE ("instruction-sync.galgas", 454)) ;
  {
  routine_analyzeEffectiveParameters (constinArgument_inSelfType, constinArgument_inRoutineAttributes, var_formalSignature_17807, constinArgument_inEffectiveParameterList, constinArgument_inGuardName.getter_location (HERE), constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inRequiredMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, outArgument_outEffectiveParameterListIR, inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 455)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                        Overriding extension method '@syncInstructionIR llvmInstructionCode'                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_syncInstructionIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                   GALGAS_string & ioArgument_ioLLVMcode,
                                                                   const GALGAS_generationContext constinArgument_inGenerationContext,
                                                                   GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_syncInstructionIR * object = (const cPtr_syncInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_syncInstructionIR) ;
  ioArgument_ioGenerationAdds.mProperty_mUsesGuards = GALGAS_bool (true) ;
  GALGAS_string var_startLabel_21189 = GALGAS_string ("select.").add_operation (ioArgument_ioGenerationAdds.getter_mUniqueIndex (HERE).getter_string (SOURCE_FILE ("instruction-sync.galgas", 523)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 523)) ;
  ioArgument_ioGenerationAdds.mProperty_mUniqueIndex.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 524)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_startLabel_21189, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 526)).add_operation (GALGAS_string (".start\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 526)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 526)) ;
  GALGAS_string var_startLabelName_21353 = var_startLabel_21189.add_operation (GALGAS_string (".start"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 527)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_startLabelName_21353.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 528)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 528)) ;
  GALGAS_string var_exitLabelName_21437 = var_startLabel_21189.add_operation (GALGAS_string (".exit"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 529)) ;
  GALGAS_string var_selectLabelName_21482 = var_startLabel_21189.add_operation (GALGAS_string (".select"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 530)) ;
  GALGAS_string var_errorLabelName_21528 = var_startLabel_21189.add_operation (GALGAS_string (".error"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 531)) ;
  GALGAS_string var_currentStartBranchLabel_21582 = var_startLabelName_21353 ;
  cEnumerator_syncInstructionBranchListIR enumerator_21642 (object->mProperty_mOnInstructionBranchListIR, kENUMERATION_UP) ;
  GALGAS_uint index_21605 ((uint32_t) 0) ;
  while (enumerator_21642.hasCurrentObject ()) {
    GALGAS_string var_acceptanceVarName_21677 = GALGAS_string ("%").add_operation (var_startLabel_21189, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 534)).add_operation (GALGAS_string (".accept."), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 534)).add_operation (index_21605.getter_string (SOURCE_FILE ("instruction-sync.galgas", 534)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 534)) ;
    GALGAS_bool var_isWhileGuardedCommand_21747 ;
    switch (enumerator_21642.current (HERE).getter_mGuardedCommand (HERE).enumValue ()) {
    case GALGAS_guardedCommandIR::kNotBuilt:
      break ;
    case GALGAS_guardedCommandIR::kEnum_booleanGuard:
      {
        const cEnumAssociatedValues_guardedCommandIR_booleanGuard * extractPtr_22585 = (const cEnumAssociatedValues_guardedCommandIR_booleanGuard *) (enumerator_21642.current (HERE).getter_mGuardedCommand (HERE).unsafePointer ()) ;
        const GALGAS_bool extractedValue_isExitCommand = extractPtr_22585->mAssociatedValue0 ;
        const GALGAS_instructionListIR extractedValue_instructionGenerationList = extractPtr_22585->mAssociatedValue1 ;
        const GALGAS_objectIR extractedValue_result = extractPtr_22585->mAssociatedValue2 ;
        var_isWhileGuardedCommand_21747 = extractedValue_isExitCommand ;
        extensionMethod_instructionListLLVMCode (extractedValue_instructionGenerationList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 539)) ;
        GALGAS_string var_acceptedLabelName_22047 = var_startLabel_21189.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 540)).add_operation (index_21605.getter_string (SOURCE_FILE ("instruction-sync.galgas", 540)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 540)).add_operation (GALGAS_string (".true"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 540)) ;
        GALGAS_string var_rejectedLabelName_22110 = var_startLabel_21189.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 541)).add_operation (index_21605.getter_string (SOURCE_FILE ("instruction-sync.galgas", 541)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 541)).add_operation (GALGAS_string (".false"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 541)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 ").add_operation (extensionGetter_llvmName (extractedValue_result, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 542)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 542)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 542)).add_operation (var_acceptedLabelName_22047, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 542)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 542)).add_operation (var_rejectedLabelName_22110, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 542)).add_operation (GALGAS_string ("\n"
          "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 542)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 542)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(var_acceptedLabelName_22047.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 543)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 543)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  call void @accept.guard ()\n"), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 544)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_rejectedLabelName_22110, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 545)).add_operation (GALGAS_string ("\n"
          "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 545)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 545)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(var_rejectedLabelName_22110.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 546)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 546)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ").add_operation (var_acceptanceVarName_21677, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 547)).add_operation (GALGAS_string (" = or i1 "), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 547)).add_operation (extensionGetter_llvmName (extractedValue_result, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 547)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 547)).add_operation (GALGAS_string (", 0 ; assignment\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 547)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 547)) ;
      }
      break ;
    case GALGAS_guardedCommandIR::kEnum_boolAndSync:
      {
        const cEnumAssociatedValues_guardedCommandIR_boolAndSync * extractPtr_24312 = (const cEnumAssociatedValues_guardedCommandIR_boolAndSync *) (enumerator_21642.current (HERE).getter_mGuardedCommand (HERE).unsafePointer ()) ;
        const GALGAS_bool extractedValue_isExitCommand = extractPtr_24312->mAssociatedValue0 ;
        const GALGAS_instructionListIR extractedValue_expInstructionList = extractPtr_24312->mAssociatedValue1 ;
        const GALGAS_objectIR extractedValue_expResult = extractPtr_24312->mAssociatedValue2 ;
        const GALGAS_string extractedValue_guardMangledName = extractPtr_24312->mAssociatedValue3 ;
        const GALGAS_instructionListIR extractedValue_guardInstructionList = extractPtr_24312->mAssociatedValue4 ;
        const GALGAS_procCallEffectiveParameterListIR extractedValue_effectiveParameterList = extractPtr_24312->mAssociatedValue5 ;
        var_isWhileGuardedCommand_21747 = extractedValue_isExitCommand ;
        extensionMethod_instructionListLLVMCode (extractedValue_expInstructionList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 550)) ;
        GALGAS_string var_testOkLabelName_22888 = var_startLabel_21189.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 551)).add_operation (index_21605.getter_string (SOURCE_FILE ("instruction-sync.galgas", 551)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 551)).add_operation (GALGAS_string (".boolexp.true"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 551)) ;
        GALGAS_string var_testExitLabelName_22959 = var_startLabel_21189.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 552)).add_operation (index_21605.getter_string (SOURCE_FILE ("instruction-sync.galgas", 552)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 552)).add_operation (GALGAS_string (".test.exit"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 552)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 ").add_operation (extensionGetter_llvmName (extractedValue_expResult, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 553)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 553)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 553)).add_operation (var_testOkLabelName_22888, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 553)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 553)).add_operation (var_testExitLabelName_22959, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 553)).add_operation (GALGAS_string ("\n"
          "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 553)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 553)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(var_testOkLabelName_22888.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 554)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 554)) ;
        extensionMethod_instructionListLLVMCode (extractedValue_guardInstructionList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 555)) ;
        GALGAS_string var_guardAcceptationLabelName_23314 = var_startLabel_21189.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 556)).add_operation (index_21605.getter_string (SOURCE_FILE ("instruction-sync.galgas", 556)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 556)).add_operation (GALGAS_string (".guard.acceptation"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 556)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_guardAcceptationLabelName_23314, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 557)).add_operation (GALGAS_string (" = call i1 @"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 557)).add_operation (function_llvmNameForGuardCall (extractedValue_guardMangledName, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 557)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 557)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 557)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" ("), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 558)) ;
        cEnumerator_procCallEffectiveParameterListIR enumerator_23540 (extractedValue_effectiveParameterList, kENUMERATION_UP) ;
        while (enumerator_23540.hasCurrentObject ()) {
          switch (enumerator_23540.current_mEffectiveParameterPassingMode (HERE).enumValue ()) {
          case GALGAS_procEffectiveParameterPassingModeIR::kNotBuilt:
            break ;
          case GALGAS_procEffectiveParameterPassingModeIR::kEnum_input:
            {
              ioArgument_ioLLVMcode.plusAssign_operation(extensionGetter_llvmTypeName (enumerator_23540.current_mParameter (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 562)).add_operation (GALGAS_string (" * "), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 562)).add_operation (extensionGetter_llvmName (enumerator_23540.current_mParameter (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 562)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 562)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 562)) ;
            }
            break ;
          case GALGAS_procEffectiveParameterPassingModeIR::kEnum_output:
            {
              ioArgument_ioLLVMcode.plusAssign_operation(extensionGetter_llvmTypeName (enumerator_23540.current_mParameter (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 564)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 564)).add_operation (extensionGetter_llvmName (enumerator_23540.current_mParameter (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 564)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 564)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 564)) ;
            }
            break ;
          case GALGAS_procEffectiveParameterPassingModeIR::kEnum_outputInput:
            {
              ioArgument_ioLLVMcode.plusAssign_operation(extensionGetter_llvmTypeName (enumerator_23540.current_mParameter (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 566)).add_operation (GALGAS_string (" * "), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 566)).add_operation (extensionGetter_llvmName (enumerator_23540.current_mParameter (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 566)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 566)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 566)) ;
            }
            break ;
          }
          if (enumerator_23540.hasNextObject ()) {
            ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 569)) ;
          }
          enumerator_23540.gotoNextObject () ;
        }
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (")\n"), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 571)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_testExitLabelName_22959, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 572)).add_operation (GALGAS_string ("\n"
          "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 572)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 572)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(var_testExitLabelName_22959.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 573)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 573)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ").add_operation (var_acceptanceVarName_21677, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 574)).add_operation (GALGAS_string (" = phi i1 "), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 574)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 574)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("[%").add_operation (var_guardAcceptationLabelName_23314, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 575)).add_operation (GALGAS_string (", %"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 575)).add_operation (var_testOkLabelName_22888, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 575)).add_operation (GALGAS_string ("], "), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 575)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 575)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("[false, %").add_operation (var_currentStartBranchLabel_21582, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 576)).add_operation (GALGAS_string ("]\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 576)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 576)) ;
      }
      break ;
    case GALGAS_guardedCommandIR::kEnum_sync:
      {
        const cEnumAssociatedValues_guardedCommandIR_sync * extractPtr_25173 = (const cEnumAssociatedValues_guardedCommandIR_sync *) (enumerator_21642.current (HERE).getter_mGuardedCommand (HERE).unsafePointer ()) ;
        const GALGAS_bool extractedValue_isExitCommand = extractPtr_25173->mAssociatedValue0 ;
        const GALGAS_string extractedValue_guardMangledName = extractPtr_25173->mAssociatedValue1 ;
        const GALGAS_instructionListIR extractedValue_guardInstructionList = extractPtr_25173->mAssociatedValue2 ;
        const GALGAS_procCallEffectiveParameterListIR extractedValue_effectiveParameterList = extractPtr_25173->mAssociatedValue3 ;
        var_isWhileGuardedCommand_21747 = extractedValue_isExitCommand ;
        extensionMethod_instructionListLLVMCode (extractedValue_guardInstructionList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 579)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ").add_operation (var_acceptanceVarName_21677, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 580)).add_operation (GALGAS_string (" = call i1 @"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 580)).add_operation (function_llvmNameForGuardCall (extractedValue_guardMangledName, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 580)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 580)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 580)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" ("), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 581)) ;
        cEnumerator_procCallEffectiveParameterListIR enumerator_24724 (extractedValue_effectiveParameterList, kENUMERATION_UP) ;
        while (enumerator_24724.hasCurrentObject ()) {
          switch (enumerator_24724.current_mEffectiveParameterPassingMode (HERE).enumValue ()) {
          case GALGAS_procEffectiveParameterPassingModeIR::kNotBuilt:
            break ;
          case GALGAS_procEffectiveParameterPassingModeIR::kEnum_input:
            {
              ioArgument_ioLLVMcode.plusAssign_operation(extensionGetter_llvmTypeName (enumerator_24724.current_mParameter (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 585)).add_operation (GALGAS_string (" * "), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 585)).add_operation (extensionGetter_llvmName (enumerator_24724.current_mParameter (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 585)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 585)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 585)) ;
            }
            break ;
          case GALGAS_procEffectiveParameterPassingModeIR::kEnum_output:
            {
              ioArgument_ioLLVMcode.plusAssign_operation(extensionGetter_llvmTypeName (enumerator_24724.current_mParameter (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 587)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 587)).add_operation (extensionGetter_llvmName (enumerator_24724.current_mParameter (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 587)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 587)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 587)) ;
            }
            break ;
          case GALGAS_procEffectiveParameterPassingModeIR::kEnum_outputInput:
            {
              ioArgument_ioLLVMcode.plusAssign_operation(extensionGetter_llvmTypeName (enumerator_24724.current_mParameter (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 589)).add_operation (GALGAS_string (" * "), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 589)).add_operation (extensionGetter_llvmName (enumerator_24724.current_mParameter (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 589)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 589)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 589)) ;
            }
            break ;
          }
          if (enumerator_24724.hasNextObject ()) {
            ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 592)) ;
          }
          enumerator_24724.gotoNextObject () ;
        }
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (")\n"), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 594)) ;
      }
      break ;
    }
    GALGAS_string var_acceptedLabelName_25207 = var_startLabel_21189.add_operation (GALGAS_string (".accepted."), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 596)).add_operation (index_21605.getter_string (SOURCE_FILE ("instruction-sync.galgas", 596)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 596)) ;
    GALGAS_string var_rejectedLabelName_25267 = var_startLabel_21189.add_operation (GALGAS_string (".rejected."), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 597)).add_operation (index_21605.getter_string (SOURCE_FILE ("instruction-sync.galgas", 597)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 597)) ;
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 ").add_operation (var_acceptanceVarName_21677, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 598)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 598)).add_operation (var_acceptedLabelName_25207, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 598)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 598)).add_operation (var_rejectedLabelName_25267, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 598)).add_operation (GALGAS_string ("\n"
      "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 598)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 598)) ;
    ioArgument_ioLLVMcode.plusAssign_operation(var_acceptedLabelName_25207.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 599)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 599)) ;
    extensionMethod_instructionListLLVMCode (enumerator_21642.current (HERE).getter_mInstructionGenerationList (HERE), ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 600)) ;
    GALGAS_string temp_0 ;
    const enumGalgasBool test_1 = var_isWhileGuardedCommand_21747.boolEnum () ;
    if (kBoolTrue == test_1) {
      temp_0 = var_startLabelName_21353 ;
    }else if (kBoolFalse == test_1) {
      temp_0 = var_exitLabelName_21437 ;
    }
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 601)).add_operation (GALGAS_string ("\n"
      "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 601)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 601)) ;
    ioArgument_ioLLVMcode.plusAssign_operation(var_rejectedLabelName_25267.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 602)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 602)) ;
    var_currentStartBranchLabel_21582 = var_rejectedLabelName_25267 ;
    enumerator_21642.gotoNextObject () ;
    index_21605.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 533)) ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_selectLabelName_21482, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 605)).add_operation (GALGAS_string (" = call i1 @"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 605)).add_operation (function_llvmNameForServiceCall (function_waitForGuardChangeFunctionName (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 605)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 605)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 605)).add_operation (GALGAS_string (" ()\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 605)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 605)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 %").add_operation (var_selectLabelName_21482, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 606)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 606)).add_operation (var_startLabelName_21353, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 606)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 606)).add_operation (var_errorLabelName_21528, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 606)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 606)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 606)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_errorLabelName_21528.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 607)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 607)) ;
  const enumGalgasBool test_2 = GALGAS_bool (gOption_plm_5F_options_noPanicGeneration.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_2) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_exitLabelName_21437, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 609)).add_operation (GALGAS_string ("\n"
      "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 609)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 609)) ;
  }else if (kBoolFalse == test_2) {
    GALGAS_uint var_staticStringIndex_26459 ;
    {
    extensionSetter_findOrAddStaticString (ioArgument_ioGenerationAdds.mProperty_mStaticEntityMap, object->mProperty_mSelectInstructionLocation.getter_file (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 612)).getter_lastPathComponent (SOURCE_FILE ("instruction-sync.galgas", 612)).getter_stringByDeletingPathExtension (SOURCE_FILE ("instruction-sync.galgas", 612)), var_staticStringIndex_26459, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 611)) ;
    }
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  call void @raise.panic.").add_operation (var_staticStringIndex_26459.getter_string (SOURCE_FILE ("instruction-sync.galgas", 615)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 615)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 615)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 615)) ;
    ioArgument_ioLLVMcode.plusAssign_operation(extensionGetter_llvmTypeName (constinArgument_inGenerationContext.getter_mPanicLineLLVMType (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 616)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 616)).add_operation (object->mProperty_mSelectInstructionLocation.getter_line (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 616)).getter_string (SOURCE_FILE ("instruction-sync.galgas", 616)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 616)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 616)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 616)) ;
    ioArgument_ioLLVMcode.plusAssign_operation(extensionGetter_llvmTypeName (constinArgument_inGenerationContext.getter_mPanicCodeLLVMType (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 617)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 617)).add_operation (function_panicCodeForClosedSync (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 617)).getter_string (SOURCE_FILE ("instruction-sync.galgas", 617)), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 617)).add_operation (GALGAS_string (")\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 617)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 617)) ;
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  unreachable\n"
      "\n"), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 618)) ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(var_exitLabelName_21437.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 620)), inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 620)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_syncInstructionIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_syncInstructionIR.mSlotID,
                                            extensionMethod_syncInstructionIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_syncInstructionIR_llvmInstructionCode (defineExtensionMethod_syncInstructionIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      Overriding extension method '@syncInstructionIR enterAccessibleEntities'                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_syncInstructionIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * inObject,
                                                                       GALGAS_accessibleEntities & ioArgument_ioAccessibleEntities,
                                                                       GALGAS_uint & ioArgument_ioMaxBranchOfOnInstructions,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_syncInstructionIR * object = (const cPtr_syncInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_syncInstructionIR) ;
  GALGAS_uint var_branchCount_27142 = object->mProperty_mOnInstructionBranchListIR.getter_length (SOURCE_FILE ("instruction-sync.galgas", 629)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, ioArgument_ioMaxBranchOfOnInstructions.objectCompare (var_branchCount_27142)).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_ioMaxBranchOfOnInstructions = var_branchCount_27142 ;
  }
  cEnumerator_syncInstructionBranchListIR enumerator_27327 (object->mProperty_mOnInstructionBranchListIR, kENUMERATION_UP) ;
  while (enumerator_27327.hasCurrentObject ()) {
    extensionMethod_enterAccessibleEntities (enumerator_27327.current (HERE).getter_mInstructionGenerationList (HERE), ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 634)) ;
    switch (enumerator_27327.current (HERE).getter_mGuardedCommand (HERE).enumValue ()) {
    case GALGAS_guardedCommandIR::kNotBuilt:
      break ;
    case GALGAS_guardedCommandIR::kEnum_booleanGuard:
      {
        const cEnumAssociatedValues_guardedCommandIR_booleanGuard * extractPtr_27648 = (const cEnumAssociatedValues_guardedCommandIR_booleanGuard *) (enumerator_27327.current (HERE).getter_mGuardedCommand (HERE).unsafePointer ()) ;
        const GALGAS_instructionListIR extractedValue_instructionGenerationList = extractPtr_27648->mAssociatedValue1 ;
        extensionMethod_enterAccessibleEntities (extractedValue_instructionGenerationList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 637)) ;
      }
      break ;
    case GALGAS_guardedCommandIR::kEnum_sync:
      {
        const cEnumAssociatedValues_guardedCommandIR_sync * extractPtr_27892 = (const cEnumAssociatedValues_guardedCommandIR_sync *) (enumerator_27327.current (HERE).getter_mGuardedCommand (HERE).unsafePointer ()) ;
        const GALGAS_string extractedValue_guardMangledName = extractPtr_27892->mAssociatedValue1 ;
        const GALGAS_instructionListIR extractedValue_guardInstructionGenerationList = extractPtr_27892->mAssociatedValue2 ;
        extensionMethod_enterAccessibleEntities (extractedValue_guardInstructionGenerationList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 639)) ;
        ioArgument_ioAccessibleEntities.mProperty_mGuardSet.addAssign_operation (extractedValue_guardMangledName  COMMA_SOURCE_FILE ("instruction-sync.galgas", 640)) ;
      }
      break ;
    case GALGAS_guardedCommandIR::kEnum_boolAndSync:
      {
        const cEnumAssociatedValues_guardedCommandIR_boolAndSync * extractPtr_28282 = (const cEnumAssociatedValues_guardedCommandIR_boolAndSync *) (enumerator_27327.current (HERE).getter_mGuardedCommand (HERE).unsafePointer ()) ;
        const GALGAS_instructionListIR extractedValue_instructionGenerationList = extractPtr_28282->mAssociatedValue1 ;
        const GALGAS_string extractedValue_guardMangledName = extractPtr_28282->mAssociatedValue3 ;
        const GALGAS_instructionListIR extractedValue_guardInstructionGenerationList = extractPtr_28282->mAssociatedValue4 ;
        extensionMethod_enterAccessibleEntities (extractedValue_instructionGenerationList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 642)) ;
        extensionMethod_enterAccessibleEntities (extractedValue_guardInstructionGenerationList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 643)) ;
        ioArgument_ioAccessibleEntities.mProperty_mGuardSet.addAssign_operation (extractedValue_guardMangledName  COMMA_SOURCE_FILE ("instruction-sync.galgas", 644)) ;
      }
      break ;
    }
    enumerator_27327.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_syncInstructionIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_syncInstructionIR.mSlotID,
                                                extensionMethod_syncInstructionIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_syncInstructionIR_enterAccessibleEntities (defineExtensionMethod_syncInstructionIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//              Overriding extension method '@whileInstructionAST noteInstructionTypesInPrecedenceGraph'               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_whileInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                       GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_whileInstructionAST * object = (const cPtr_whileInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_whileInstructionAST) ;
  extensionMethod_noteInstructionListTypesInPrecedenceGraph (object->mProperty_mWhileInstructionList, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 47)) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_m_5F_while_5F_Expression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 48)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_whileInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_whileInstructionAST.mSlotID,
                                                              extensionMethod_whileInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_whileInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_whileInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                   Overriding extension method '@whileInstructionAST instructionSemanticAnalysis'                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_whileInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                             const GALGAS_PLMType constinArgument_inSelfType,
                                                                             const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                             const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                             const GALGAS_semanticContext constinArgument_inContext,
                                                                             const GALGAS_mode constinArgument_inCurrentMode,
                                                                             GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                             GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                             GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                             GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                             GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_whileInstructionAST * object = (const cPtr_whileInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_whileInstructionAST) ;
  GALGAS_instructionListIR var_testInstructionGenerationList_3417 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-while.galgas", 68)) ;
  GALGAS_objectIR var_testValue_3890 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_m_5F_while_5F_Expression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, function_voidType (inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 73)), constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_testInstructionGenerationList_3417, var_testValue_3890, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 69)) ;
  {
  extensionSetter_appendLoadWhenReference (var_testInstructionGenerationList_3417, ioArgument_ioTemporaries, var_testValue_3890, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 83)) ;
  }
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, extensionGetter_type (var_testValue_3890, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 88)).getter_kind (HERE).objectCompare (GALGAS_typeKind::constructor_boolean (SOURCE_FILE ("instruction-while.galgas", 88)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mEndOf_5F_test_5F_expression, GALGAS_string ("test expression type is '").add_operation (extensionGetter_plmTypeDescriptionName (var_testValue_3890, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 89)), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 89)).add_operation (GALGAS_string ("', it should be boolean"), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 89)), fixItArray1  COMMA_SOURCE_FILE ("instruction-while.galgas", 89)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = extensionGetter_isStatic (var_testValue_3890, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 90)).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mProperty_mEndOf_5F_test_5F_expression, GALGAS_string ("test expression type should not be static"), fixItArray3  COMMA_SOURCE_FILE ("instruction-while.galgas", 91)) ;
    }
  }
  GALGAS_instructionListIR var_instructionGenerationList_4388 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-while.galgas", 94)) ;
  {
  extensionSetter_openOverrideForRepeatBlock (ioArgument_ioUniversalMap, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 95)) ;
  }
  extensionMethod_analyzeBranchInstructionList (object->mProperty_mWhileInstructionList, constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, object->mProperty_mEndOf_5F_while_5F_instruction, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_instructionGenerationList_4388, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 96)) ;
  {
  extensionSetter_closeOverride (ioArgument_ioUniversalMap, object->mProperty_mEndOf_5F_while_5F_instruction, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 109)) ;
  }
  ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_whileInstructionIR::constructor_new (object->mProperty_mEndOf_5F_test_5F_expression.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 112)), var_testInstructionGenerationList_3417, var_testValue_3890, var_instructionGenerationList_4388  COMMA_SOURCE_FILE ("instruction-while.galgas", 111))  COMMA_SOURCE_FILE ("instruction-while.galgas", 111)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_whileInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_whileInstructionAST.mSlotID,
                                                    extensionMethod_whileInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_whileInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_whileInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                        Overriding extension method '@whileInstructionIR llvmInstructionCode'                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_whileInstructionIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                    GALGAS_string & ioArgument_ioLLVMcode,
                                                                    const GALGAS_generationContext constinArgument_inGenerationContext,
                                                                    GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_whileInstructionIR * object = (const cPtr_whileInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_whileInstructionIR) ;
  GALGAS_string var_labelTest_6052 = GALGAS_string ("while.").add_operation (object->mProperty_mLabelIndex.getter_string (SOURCE_FILE ("instruction-while.galgas", 137)), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 137)).add_operation (GALGAS_string (".test"), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 137)) ;
  GALGAS_string var_labelLoop_6103 = GALGAS_string ("while.").add_operation (object->mProperty_mLabelIndex.getter_string (SOURCE_FILE ("instruction-while.galgas", 138)), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 138)).add_operation (GALGAS_string (".loop"), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 138)) ;
  GALGAS_string var_labelEnd_6153 = GALGAS_string ("while.").add_operation (object->mProperty_mLabelIndex.getter_string (SOURCE_FILE ("instruction-while.galgas", 139)), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 139)).add_operation (GALGAS_string (".end"), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 139)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_labelTest_6052, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 140)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 140)), inCompiler  COMMA_SOURCE_FILE ("instruction-while.galgas", 140)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_labelTest_6052.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 141)), inCompiler  COMMA_SOURCE_FILE ("instruction-while.galgas", 141)) ;
  extensionMethod_instructionListLLVMCode (object->mProperty_mTestInstructionGenerationList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 142)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 ").add_operation (extensionGetter_llvmName (object->mProperty_m_5F_while_5F_Expression, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 143)), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 143)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 143)).add_operation (var_labelLoop_6103, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 143)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 143)).add_operation (var_labelEnd_6153, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 143)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 143)), inCompiler  COMMA_SOURCE_FILE ("instruction-while.galgas", 143)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_labelLoop_6103.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 144)), inCompiler  COMMA_SOURCE_FILE ("instruction-while.galgas", 144)) ;
  extensionMethod_instructionListLLVMCode (object->mProperty_mInstructionGenerationList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 145)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_labelTest_6052, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 146)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 146)), inCompiler  COMMA_SOURCE_FILE ("instruction-while.galgas", 146)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_labelEnd_6153.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 147)), inCompiler  COMMA_SOURCE_FILE ("instruction-while.galgas", 147)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_whileInstructionIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_whileInstructionIR.mSlotID,
                                            extensionMethod_whileInstructionIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_whileInstructionIR_llvmInstructionCode (defineExtensionMethod_whileInstructionIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      Overriding extension method '@whileInstructionIR enterAccessibleEntities'                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_whileInstructionIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * inObject,
                                                                        GALGAS_accessibleEntities & ioArgument_ioAccessibleEntities,
                                                                        GALGAS_uint & ioArgument_ioMaxBranchOfOnInstructions,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_whileInstructionIR * object = (const cPtr_whileInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_whileInstructionIR) ;
  extensionMethod_enterAccessibleEntities (object->mProperty_mTestInstructionGenerationList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 156)) ;
  extensionMethod_enterAccessibleEntities (object->mProperty_mInstructionGenerationList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-while.galgas", 157)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_whileInstructionIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_whileInstructionIR.mSlotID,
                                                extensionMethod_whileInstructionIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_whileInstructionIR_enterAccessibleEntities (defineExtensionMethod_whileInstructionIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//               Overriding extension method '@forInstructionAST noteInstructionTypesInPrecedenceGraph'                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_forInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                     GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_forInstructionAST * object = (const cPtr_forInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_forInstructionAST) ;
  extensionMethod_noteInstructionListTypesInPrecedenceGraph (object->mProperty_mDoInstructionList, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 73)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_forInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_forInstructionAST.mSlotID,
                                                              extensionMethod_forInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_forInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_forInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                    Overriding extension method '@forInstructionAST instructionSemanticAnalysis'                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_forInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                           const GALGAS_PLMType constinArgument_inSelfType,
                                                                           const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                           const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                           const GALGAS_semanticContext constinArgument_inContext,
                                                                           const GALGAS_mode constinArgument_inCurrentMode,
                                                                           GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                           GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                           GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                           GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                           GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_forInstructionAST * object = (const cPtr_forInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_forInstructionAST) ;
  GALGAS_objectIR var_iteratedObjectPointer_4115 ;
  {
  extensionSetter_searchValuedObjectForReadAccess (ioArgument_ioUniversalMap, object->mProperty_mIteratedObject, var_iteratedObjectPointer_4115, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 93)) ;
  }
  GALGAS_PLMType var_iteratedTypeKind_4154 = extensionGetter_type (var_iteratedObjectPointer_4115, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 95)) ;
  GALGAS_PLMType var_iteratedElementType_4247 ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, var_iteratedTypeKind_4154.getter_kind (HERE).objectCompare (GALGAS_typeKind::constructor_literalString (SOURCE_FILE ("instruction-for-in-do.galgas", 98)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_iteratedElementType_4247 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), GALGAS_string ("uint8").getter_nowhere (SOURCE_FILE ("instruction-for-in-do.galgas", 99)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 99)).getter_type (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 99)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = var_iteratedTypeKind_4154.getter_kind (HERE).getter_isArrayType (SOURCE_FILE ("instruction-for-in-do.galgas", 100)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_bigint joker_4524_1 ; // Joker input parameter
      var_iteratedTypeKind_4154.getter_kind (HERE).method_arrayType (var_iteratedElementType_4247, joker_4524_1, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 101)) ;
    }else if (kBoolFalse == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mProperty_mIteratedObject.getter_location (SOURCE_FILE ("instruction-for-in-do.galgas", 103)), GALGAS_string ("this object is not enumerable"), fixItArray2  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 103)) ;
      var_iteratedElementType_4247.drop () ; // Release error dropped variable
    }
  }
  GALGAS_lstring var_plmName_4641 = GALGAS_lstring::constructor_new (object->mProperty_mVarName.getter_string (HERE).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 106)).add_operation (ioArgument_ioTemporaries.getter_mTemporaryIndex (HERE).getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 106)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 106)), object->mProperty_mVarName.getter_location (SOURCE_FILE ("instruction-for-in-do.galgas", 106))  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 106)) ;
  ioArgument_ioTemporaries.mProperty_mTemporaryIndex.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 107)) ;
  ioArgument_ioAllocaList.addAssign_operation (function_llvmNameForLocalVariable (var_plmName_4641.getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 108)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 108)), var_iteratedElementType_4247, GALGAS_bool (false)  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 108)) ;
  {
  extensionSetter_openOverrideForRepeatBlock (ioArgument_ioUniversalMap, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 110)) ;
  }
  {
  extensionSetter_insertLocalConstant (ioArgument_ioUniversalMap, object->mProperty_mVarName, GALGAS_bool (false), var_iteratedElementType_4247, var_plmName_4641, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 111)) ;
  }
  GALGAS_instructionListIR var_whileExpression_5F_GenerationList_5089 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-for-in-do.galgas", 113)) ;
  GALGAS_objectIR var_whileExpressionResult_5577 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mWhileExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, function_voidType (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 118)), constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_whileExpression_5F_GenerationList_5089, var_whileExpressionResult_5577, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 114)) ;
  const enumGalgasBool test_3 = extensionGetter_type (var_whileExpressionResult_5577, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 129)).getter_kind (HERE).getter_isBoolean (SOURCE_FILE ("instruction-for-in-do.galgas", 129)).operator_not (SOURCE_FILE ("instruction-for-in-do.galgas", 129)).boolEnum () ;
  if (kBoolTrue == test_3) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (object->mProperty_mEndOf_5F_whileExpression, GALGAS_string ("'while' expression should be boolean"), fixItArray4  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 130)) ;
  }else if (kBoolFalse == test_3) {
    GALGAS_bool test_5 = object->mProperty_mStaticWhileExpression ;
    if (kBoolTrue == test_5.boolEnum ()) {
      test_5 = extensionGetter_isStatic (var_whileExpressionResult_5577, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 131)).operator_not (SOURCE_FILE ("instruction-for-in-do.galgas", 131)) ;
    }
    const enumGalgasBool test_6 = test_5.boolEnum () ;
    if (kBoolTrue == test_6) {
      TC_Array <C_FixItDescription> fixItArray7 ;
      inCompiler->emitSemanticError (object->mProperty_mEndOf_5F_whileExpression, GALGAS_string ("'while' expression is not static"), fixItArray7  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 132)) ;
    }else if (kBoolFalse == test_6) {
      GALGAS_bool test_8 = extensionGetter_isStatic (var_whileExpressionResult_5577, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 133)) ;
      if (kBoolTrue == test_8.boolEnum ()) {
        test_8 = object->mProperty_mStaticWhileExpression.operator_not (SOURCE_FILE ("instruction-for-in-do.galgas", 133)) ;
      }
      const enumGalgasBool test_9 = test_8.boolEnum () ;
      if (kBoolTrue == test_9) {
        TC_Array <C_FixItDescription> fixItArray10 ;
        inCompiler->emitSemanticWarning (object->mProperty_mEndOf_5F_whileExpression, GALGAS_string ("'while' expression is static (insert @").add_operation (function_staticAttribute (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 134)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 134)).add_operation (GALGAS_string (" attribute)"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 134)), fixItArray10  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 134)) ;
      }
    }
  }
  GALGAS_instructionListIR var_doInstructionList_5F_GenerationList_6163 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-for-in-do.galgas", 137)) ;
  extensionMethod_analyzeBranchInstructionList (object->mProperty_mDoInstructionList, constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, object->mProperty_mEndOf_5F_for_5F_instruction, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_doInstructionList_5F_GenerationList_6163, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 138)) ;
  {
  extensionSetter_closeOverride (ioArgument_ioUniversalMap, object->mProperty_mEndOf_5F_for_5F_instruction, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 151)) ;
  }
  const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, var_iteratedTypeKind_4154.getter_kind (HERE).objectCompare (GALGAS_typeKind::constructor_literalString (SOURCE_FILE ("instruction-for-in-do.galgas", 153)))).boolEnum () ;
  if (kBoolTrue == test_11) {
    ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_forInstructionOnStringIR::constructor_new (var_plmName_4641.getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 155)), object->mProperty_mIteratedObject.getter_location (HERE), var_iteratedObjectPointer_4115, var_whileExpression_5F_GenerationList_5089, var_whileExpressionResult_5577, var_doInstructionList_5F_GenerationList_6163  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 154))  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 154)) ;
  }else if (kBoolFalse == test_11) {
    const enumGalgasBool test_12 = var_iteratedTypeKind_4154.getter_kind (HERE).getter_isArrayType (SOURCE_FILE ("instruction-for-in-do.galgas", 162)).boolEnum () ;
    if (kBoolTrue == test_12) {
      GALGAS_PLMType var_elementType_7137 ;
      GALGAS_bigint var_size_7152 ;
      var_iteratedTypeKind_4154.getter_kind (HERE).method_arrayType (var_elementType_7137, var_size_7152, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 163)) ;
      GALGAS_stringset var_invokedFunctionSet_7187 = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("instruction-for-in-do.galgas", 164)) ;
      const enumGalgasBool test_13 = ioArgument_ioTemporaries.getter_mStaticArrayMapForTemporaries (HERE).getter_hasKey (object->mProperty_mIteratedObject.getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 166)) COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 166)).boolEnum () ;
      if (kBoolTrue == test_13) {
        ioArgument_ioTemporaries.getter_mStaticArrayMapForTemporaries (HERE).method_searchKey (object->mProperty_mIteratedObject, var_invokedFunctionSet_7187, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 167)) ;
      }
      ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_forInstructionOnArrayIR::constructor_new (var_plmName_4641.getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 170)), object->mProperty_mIteratedObject, var_iteratedObjectPointer_4115, var_whileExpression_5F_GenerationList_5089, var_whileExpressionResult_5577, var_doInstructionList_5F_GenerationList_6163, var_elementType_7137, var_size_7152.getter_uint (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 177)), var_invokedFunctionSet_7187  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 169))  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 169)) ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_forInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_forInstructionAST.mSlotID,
                                                    extensionMethod_forInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_forInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_forInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     Overriding extension method '@forInstructionOnArrayIR llvmInstructionCode'                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_forInstructionOnArrayIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                         GALGAS_string & ioArgument_ioLLVMcode,
                                                                         const GALGAS_generationContext constinArgument_inGenerationContext,
                                                                         GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_forInstructionOnArrayIR * object = (const cPtr_forInstructionOnArrayIR *) inObject ;
  macroValidSharedObject (object, cPtr_forInstructionOnArrayIR) ;
  GALGAS_string var_elementTypeLLVMName_9867 = extensionGetter_llvmTypeName (object->mProperty_mElementType, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 236)) ;
  GALGAS_string var_listTypeLLVMName_9920 = GALGAS_string ("[").add_operation (object->mProperty_mArraySize.getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 237)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 237)).add_operation (GALGAS_string (" x "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 237)).add_operation (var_elementTypeLLVMName_9867, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 237)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 237)) ;
  GALGAS_string var_locationIndex_9995 = object->mProperty_mIteratedObjectName.getter_location (HERE).getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 238)).getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 238)) ;
  GALGAS_string var_startLabel_10071 = GALGAS_string ("for.label.start.").add_operation (var_locationIndex_9995, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 240)) ;
  GALGAS_string var_testLabel_10124 = GALGAS_string ("for.label.test.").add_operation (var_locationIndex_9995, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 241)) ;
  GALGAS_string var_whileLabel_10177 = GALGAS_string ("for.label.while.").add_operation (var_locationIndex_9995, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 242)) ;
  GALGAS_string var_nextLabel_10230 = GALGAS_string ("for.label.next.").add_operation (var_locationIndex_9995, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 243)) ;
  GALGAS_string var_loopVar_10280 = GALGAS_string ("for.loop.").add_operation (var_locationIndex_9995, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 244)) ;
  GALGAS_string var_loopLabel_10326 = GALGAS_string ("for.label.loop.").add_operation (var_locationIndex_9995, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 245)) ;
  GALGAS_string var_endLabel_10377 = GALGAS_string ("for.label.end.").add_operation (var_locationIndex_9995, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 246)) ;
  GALGAS_string var_indexVar_10430 = GALGAS_string ("for.index.").add_operation (var_locationIndex_9995, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 248)) ;
  GALGAS_string var_ptrVar_10475 = GALGAS_string ("for.ptr.").add_operation (var_locationIndex_9995, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 249)) ;
  GALGAS_string var_currentValue_10524 = GALGAS_string ("for.currentValue.").add_operation (var_locationIndex_9995, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 250)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_startLabel_10071, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 253)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 253)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 253)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_startLabel_10071.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 256)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 256)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_ptrVar_10475, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 258)).add_operation (GALGAS_string (".start = getelementptr inbounds "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 258)).add_operation (var_listTypeLLVMName_9920, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 258)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 258)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", ").add_operation (var_listTypeLLVMName_9920, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 259)).add_operation (GALGAS_string ("* "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 259)).add_operation (extensionGetter_llvmName (object->mProperty_mIteratedObject, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 259)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 259)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 259)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", i32 0, i32 0\n"), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 260)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_testLabel_10124, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 262)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 262)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 262)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_testLabel_10124.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 265)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 265)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_ptrVar_10475, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 267)).add_operation (GALGAS_string (" = phi "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 267)).add_operation (var_elementTypeLLVMName_9867, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 267)).add_operation (GALGAS_string ("* [%"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 267)).add_operation (var_ptrVar_10475, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 267)).add_operation (GALGAS_string (".start, %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 267)).add_operation (var_startLabel_10071, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 267)).add_operation (GALGAS_string ("], [%"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 267)).add_operation (var_ptrVar_10475, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 268)).add_operation (GALGAS_string (".next, %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 268)).add_operation (var_nextLabel_10230, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 268)).add_operation (GALGAS_string ("]\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 268)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 267)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_indexVar_10430, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 270)).add_operation (GALGAS_string (" = phi i32 ["), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 270)).add_operation (object->mProperty_mArraySize.getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 270)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 270)).add_operation (GALGAS_string (", %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 270)).add_operation (var_startLabel_10071, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 270)).add_operation (GALGAS_string ("], [%"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 270)).add_operation (var_indexVar_10430, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 271)).add_operation (GALGAS_string (".next, %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 271)).add_operation (var_nextLabel_10230, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 271)).add_operation (GALGAS_string ("]\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 271)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 270)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_loopVar_10280, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 272)).add_operation (GALGAS_string (" = icmp ugt i32 %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 272)).add_operation (var_indexVar_10430, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 272)).add_operation (GALGAS_string (", 0\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 272)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 272)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 %").add_operation (var_loopVar_10280, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 274)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 274)).add_operation (var_whileLabel_10177, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 274)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 274)).add_operation (var_endLabel_10377, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 274)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 274)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 274)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_whileLabel_10177.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 277)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 277)) ;
  extensionMethod_instructionListLLVMCode (object->mProperty_mWhileInstructionList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 279)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 ").add_operation (extensionGetter_llvmName (object->mProperty_mWhileExpressionResult, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 280)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 280)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 280)).add_operation (var_loopLabel_10326, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 280)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 280)).add_operation (var_endLabel_10377, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 280)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 280)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 280)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_loopLabel_10326.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 283)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 283)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_currentValue_10524, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 285)).add_operation (GALGAS_string (" = load "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 285)).add_operation (var_elementTypeLLVMName_9867, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 285)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 285)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 285)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_elementTypeLLVMName_9867.add_operation (GALGAS_string ("* %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 286)).add_operation (var_ptrVar_10475, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 286)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 286)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 286)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  store ").add_operation (var_elementTypeLLVMName_9867, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 287)).add_operation (GALGAS_string (" %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 287)).add_operation (var_currentValue_10524, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 287)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 287)).add_operation (var_elementTypeLLVMName_9867, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 287)).add_operation (GALGAS_string ("* "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 287)).add_operation (function_llvmNameForLocalVariable (object->mProperty_mEnumeratedValueName, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 288)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 288)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 288)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 287)) ;
  extensionMethod_instructionListLLVMCode (object->mProperty_mDoInstructionList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 290)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_nextLabel_10230, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 291)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 291)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 291)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_nextLabel_10230.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 293)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 293)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_ptrVar_10475, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 295)).add_operation (GALGAS_string (".next = getelementptr inbounds "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 295)).add_operation (var_elementTypeLLVMName_9867, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 295)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 295)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 295)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_elementTypeLLVMName_9867.add_operation (GALGAS_string (" * %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 296)).add_operation (var_ptrVar_10475, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 296)).add_operation (GALGAS_string (", i32 1\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 296)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 296)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_indexVar_10430, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 298)).add_operation (GALGAS_string (".next = add i32 %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 298)).add_operation (var_indexVar_10430, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 298)).add_operation (GALGAS_string (", -1\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 298)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 298)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_testLabel_10124, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 299)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 299)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 299)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_endLabel_10377.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 302)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 302)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_forInstructionOnArrayIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_forInstructionOnArrayIR.mSlotID,
                                            extensionMethod_forInstructionOnArrayIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_forInstructionOnArrayIR_llvmInstructionCode (defineExtensionMethod_forInstructionOnArrayIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                   Overriding extension method '@forInstructionOnArrayIR enterAccessibleEntities'                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_forInstructionOnArrayIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * inObject,
                                                                             GALGAS_accessibleEntities & ioArgument_ioAccessibleEntities,
                                                                             GALGAS_uint & ioArgument_ioMaxBranchOfOnInstructions,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_forInstructionOnArrayIR * object = (const cPtr_forInstructionOnArrayIR *) inObject ;
  macroValidSharedObject (object, cPtr_forInstructionOnArrayIR) ;
  extensionMethod_enterAccessibleEntities (object->mProperty_mWhileInstructionList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 311)) ;
  extensionMethod_enterAccessibleEntities (object->mProperty_mDoInstructionList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 312)) ;
  ioArgument_ioAccessibleEntities.mProperty_mRoutineSet.plusAssign_operation(object->mProperty_mInvokedFunctionSet, inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 313)) ;
  ioArgument_ioAccessibleEntities.mProperty_mGlobalVariableSet.addAssign_operation (object->mProperty_mIteratedObjectName.getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 314))  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 314)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_forInstructionOnArrayIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_forInstructionOnArrayIR.mSlotID,
                                                extensionMethod_forInstructionOnArrayIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_forInstructionOnArrayIR_enterAccessibleEntities (defineExtensionMethod_forInstructionOnArrayIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     Overriding extension method '@forInstructionOnStringIR llvmInstructionCode'                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_forInstructionOnStringIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                          GALGAS_string & ioArgument_ioLLVMcode,
                                                                          const GALGAS_generationContext constinArgument_inGenerationContext,
                                                                          GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_forInstructionOnStringIR * object = (const cPtr_forInstructionOnStringIR *) inObject ;
  macroValidSharedObject (object, cPtr_forInstructionOnStringIR) ;
  GALGAS_string var_startLabel_14320 = GALGAS_string ("for.label.start.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 337)).getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 337)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 337)) ;
  GALGAS_string var_testLabel_14385 = GALGAS_string ("for.label.test.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 338)).getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 338)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 338)) ;
  GALGAS_string var_loopLabel_14449 = GALGAS_string ("for.label.loop.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 339)).getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 339)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 339)) ;
  GALGAS_string var_whileLabel_14514 = GALGAS_string ("for.label.while.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 340)).getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 340)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 340)) ;
  GALGAS_string var_nextLabel_14579 = GALGAS_string ("for.label.next.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 341)).getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 341)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 341)) ;
  GALGAS_string var_endLabel_14642 = GALGAS_string ("for.label.end.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 342)).getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 342)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 342)) ;
  GALGAS_string var_ptrVar_14703 = GALGAS_string ("for.ptr.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 343)).getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 343)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 343)) ;
  GALGAS_string var_currentVar_14764 = GALGAS_string ("for.current.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 344)).getter_string (SOURCE_FILE ("instruction-for-in-do.galgas", 344)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 344)) ;
  GALGAS_string var_stringLLVMTypeName_14834 = extensionGetter_llvmTypeName (function_literalStringType (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 345)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 345)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_startLabel_14320, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 347)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 347)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 347)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_startLabel_14320.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 349)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 349)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_ptrVar_14703, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 350)).add_operation (GALGAS_string (".start = load "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 350)).add_operation (var_stringLLVMTypeName_14834, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 350)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 350)).add_operation (var_stringLLVMTypeName_14834, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 350)).add_operation (GALGAS_string ("* "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 350)).add_operation (extensionGetter_llvmName (object->mProperty_mIteratedObject, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 350)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 350)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 350)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 350)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_testLabel_14385, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 351)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 351)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 351)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_testLabel_14385.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 354)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 354)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_ptrVar_14703, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 355)).add_operation (GALGAS_string (" = phi "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 355)).add_operation (var_stringLLVMTypeName_14834, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 355)).add_operation (GALGAS_string (" [%"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 355)).add_operation (var_ptrVar_14703, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 355)).add_operation (GALGAS_string (".start, %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 355)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 355)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_startLabel_14320.add_operation (GALGAS_string ("], [%"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 356)).add_operation (var_ptrVar_14703, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 356)).add_operation (GALGAS_string (".next, %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 356)).add_operation (var_nextLabel_14579, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 356)).add_operation (GALGAS_string ("]\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 356)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 356)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_currentVar_14764, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 357)).add_operation (GALGAS_string (" = load i8, "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 357)).add_operation (var_stringLLVMTypeName_14834, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 357)).add_operation (GALGAS_string (" %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 357)).add_operation (var_ptrVar_14703, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 357)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 357)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 357)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_currentVar_14764, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 358)).add_operation (GALGAS_string (".nul = icmp eq i8 %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 358)).add_operation (var_currentVar_14764, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 358)).add_operation (GALGAS_string (", 0\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 358)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 358)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 %").add_operation (var_currentVar_14764, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 359)).add_operation (GALGAS_string (".nul, label %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 359)).add_operation (var_endLabel_14642, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 359)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 359)).add_operation (var_whileLabel_14514, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 359)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 359)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 359)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_whileLabel_14514.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 362)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 362)) ;
  extensionMethod_instructionListLLVMCode (object->mProperty_mWhileInstructionList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 364)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 ").add_operation (extensionGetter_llvmName (object->mProperty_mWhileExpressionResult, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 365)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 365)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 365)).add_operation (var_loopLabel_14449, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 365)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 365)).add_operation (var_endLabel_14642, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 365)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 365)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 365)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_loopLabel_14449.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 368)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 368)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  store i8 %").add_operation (var_currentVar_14764, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 370)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 370)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 370)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("i8 * ").add_operation (function_llvmNameForLocalVariable (object->mProperty_mVarName, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 371)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 371)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 371)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 371)) ;
  extensionMethod_instructionListLLVMCode (object->mProperty_mDoInstructionList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 373)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_nextLabel_14579, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 374)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 374)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 374)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_nextLabel_14579.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 376)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 376)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_ptrVar_14703, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 377)).add_operation (GALGAS_string (".next = getelementptr inbounds i8, "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 377)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 377)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("i8 * %").add_operation (var_ptrVar_14703, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 378)).add_operation (GALGAS_string (", i32 1\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 378)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 378)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_testLabel_14385, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 379)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 379)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 379)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_endLabel_14642.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 382)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 382)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_forInstructionOnStringIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_forInstructionOnStringIR.mSlotID,
                                            extensionMethod_forInstructionOnStringIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_forInstructionOnStringIR_llvmInstructionCode (defineExtensionMethod_forInstructionOnStringIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                   Overriding extension method '@forInstructionOnStringIR enterAccessibleEntities'                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_forInstructionOnStringIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * inObject,
                                                                              GALGAS_accessibleEntities & ioArgument_ioAccessibleEntities,
                                                                              GALGAS_uint & ioArgument_ioMaxBranchOfOnInstructions,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_forInstructionOnStringIR * object = (const cPtr_forInstructionOnStringIR *) inObject ;
  macroValidSharedObject (object, cPtr_forInstructionOnStringIR) ;
  extensionMethod_enterAccessibleEntities (object->mProperty_mWhileInstructionList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 391)) ;
  extensionMethod_enterAccessibleEntities (object->mProperty_mDoInstructionList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 392)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_forInstructionOnStringIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_forInstructionOnStringIR.mSlotID,
                                                extensionMethod_forInstructionOnStringIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_forInstructionOnStringIR_enterAccessibleEntities (defineExtensionMethod_forInstructionOnStringIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//        Overriding extension method '@forLowerUpperBoundInstructionAST noteInstructionTypesInPrecedenceGraph'        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_forLowerUpperBoundInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                                    GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_forLowerUpperBoundInstructionAST * object = (const cPtr_forLowerUpperBoundInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_forLowerUpperBoundInstructionAST) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mProperty_mTypeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_typeName_2868 = function_llvmTypeNameFromPLMname (object->mProperty_mTypeName, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 67)) ;
    {
    ioArgument_ioGraph.setter_noteNode (var_typeName_2868 COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 68)) ;
    }
  }
  extensionMethod_noteInstructionListTypesInPrecedenceGraph (object->mProperty_mDoInstructionList, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 70)) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mLowerBoundExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 71)) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mUpperBoundExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 72)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_forLowerUpperBoundInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_forLowerUpperBoundInstructionAST.mSlotID,
                                                              extensionMethod_forLowerUpperBoundInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_forLowerUpperBoundInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_forLowerUpperBoundInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//             Overriding extension method '@forLowerUpperBoundInstructionAST instructionSemanticAnalysis'             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_forLowerUpperBoundInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                                          const GALGAS_PLMType constinArgument_inSelfType,
                                                                                          const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                                          const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                                          const GALGAS_semanticContext constinArgument_inContext,
                                                                                          const GALGAS_mode constinArgument_inCurrentMode,
                                                                                          GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                                          GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                                          GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                                          GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                                          GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_forLowerUpperBoundInstructionAST * object = (const cPtr_forLowerUpperBoundInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_forLowerUpperBoundInstructionAST) ;
  GALGAS_PLMType var_type_4177 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.getter_mTypeMap (HERE), object->mProperty_mTypeName, inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 92)).getter_type (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 92)) ;
  switch (var_type_4177.getter_kind (HERE).enumValue ()) {
  case GALGAS_typeKind::kNotBuilt:
    break ;
  case GALGAS_typeKind::kEnum_boolean:
  case GALGAS_typeKind::kEnum_void:
    {
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 95)), GALGAS_string ("an integer type is required here"), fixItArray0  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 95)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_arrayType:
    {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 97)), GALGAS_string ("an integer type is required here"), fixItArray1  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 97)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_dynamicArrayType:
    {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 99)), GALGAS_string ("an integer type is required here"), fixItArray2  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 99)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_enumeration:
    {
    }
    break ;
  case GALGAS_typeKind::kEnum_literalString:
    {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 102)), GALGAS_string ("an integer type is required here"), fixItArray3  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 102)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_opaque:
    {
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 104)), GALGAS_string ("an integer type is required here"), fixItArray4  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 104)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_staticInteger:
    {
      TC_Array <C_FixItDescription> fixItArray5 ;
      inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 106)), GALGAS_string ("an integer type is required here"), fixItArray5  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 106)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_structure:
    {
      TC_Array <C_FixItDescription> fixItArray6 ;
      inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 108)), GALGAS_string ("an integer type is required here"), fixItArray6  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 108)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_syncTool:
    {
      TC_Array <C_FixItDescription> fixItArray7 ;
      inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 110)), GALGAS_string ("an integer type is required here"), fixItArray7  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 110)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_pointer:
    {
      TC_Array <C_FixItDescription> fixItArray8 ;
      inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 112)), GALGAS_string ("an integer type is required here"), fixItArray8  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 112)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_function:
    {
      TC_Array <C_FixItDescription> fixItArray9 ;
      inCompiler->emitSemanticError (object->mProperty_mTypeName.getter_location (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 114)), GALGAS_string ("an integer type is required here"), fixItArray9  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 114)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_integer:
    {
      const cEnumAssociatedValues_typeKind_integer * extractPtr_8300 = (const cEnumAssociatedValues_typeKind_integer *) (var_type_4177.getter_kind (HERE).unsafePointer ()) ;
      const GALGAS_bigint extractedValue_min = extractPtr_8300->mAssociatedValue0 ;
      const GALGAS_bigint extractedValue_max = extractPtr_8300->mAssociatedValue1 ;
      const GALGAS_bool extractedValue_unsigned = extractPtr_8300->mAssociatedValue2 ;
      const GALGAS_uint extractedValue_bitCount = extractPtr_8300->mAssociatedValue3 ;
      GALGAS_objectIR var_lowerBoundExpressionResult_5724 ;
      callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mLowerBoundExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, var_type_4177, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_lowerBoundExpressionResult_5724, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 117)) ;
      {
      extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_lowerBoundExpressionResult_5724, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 131)) ;
      }
      GALGAS_objectIR var_upperBoundExpressionResult_6359 ;
      callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mUpperBoundExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, var_type_4177, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_upperBoundExpressionResult_6359, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 135)) ;
      {
      extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_upperBoundExpressionResult_6359, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 149)) ;
      }
      GALGAS_objectIR var_lowerBound_6538 = function_checkAssignmentCompatibility (var_lowerBoundExpressionResult_5724, var_type_4177, object->mProperty_mEndOf_5F_lowerBoundExpression_5F_instruction, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 154)) ;
      GALGAS_objectIR var_upperBound_6762 = function_checkAssignmentCompatibility (var_upperBoundExpressionResult_6359, var_type_4177, object->mProperty_mEndOf_5F_upperBoundExpression_5F_instruction, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 160)) ;
      {
      extensionSetter_openOverrideForRepeatBlock (ioArgument_ioUniversalMap, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 167)) ;
      }
      GALGAS_lstring var_enumeratedVarName_7087 = GALGAS_lstring::constructor_new (object->mProperty_mVarName.getter_string (HERE).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 169)).add_operation (ioArgument_ioTemporaries.getter_mTemporaryIndex (HERE).getter_string (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 169)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 169)), object->mProperty_mVarName.getter_location (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 169))  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 169)) ;
      ioArgument_ioTemporaries.mProperty_mTemporaryIndex.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 170)) ;
      ioArgument_ioAllocaList.addAssign_operation (function_llvmNameForLocalVariable (var_enumeratedVarName_7087.getter_string (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 171)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 171)), var_type_4177, GALGAS_bool (false)  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 171)) ;
      const enumGalgasBool test_10 = GALGAS_bool (kIsNotEqual, object->mProperty_mVarName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_10) {
        {
        extensionSetter_insertLocalConstant (ioArgument_ioUniversalMap, object->mProperty_mVarName, GALGAS_bool (false), var_type_4177, var_enumeratedVarName_7087, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 173)) ;
        }
      }
      GALGAS_instructionListIR var_instructionGenerationList_7495 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 176)) ;
      extensionMethod_analyzeBranchInstructionList (object->mProperty_mDoInstructionList, constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, object->mProperty_mEndOf_5F_do_5F_instruction, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_instructionGenerationList_7495, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 177)) ;
      {
      extensionSetter_closeOverride (ioArgument_ioUniversalMap, object->mProperty_mEndOf_5F_do_5F_instruction, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 190)) ;
      }
      ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_forLowerUpperBoundInstructionIR::constructor_new (var_enumeratedVarName_7087.getter_string (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 193)), var_type_4177, extractedValue_unsigned, object->mProperty_mEndOf_5F_do_5F_instruction, var_lowerBound_6538, var_upperBound_6762, var_instructionGenerationList_7495  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 192))  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 192)) ;
    }
    break ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_forLowerUpperBoundInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_forLowerUpperBoundInstructionAST.mSlotID,
                                                    extensionMethod_forLowerUpperBoundInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_forLowerUpperBoundInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_forLowerUpperBoundInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                 Overriding extension method '@forLowerUpperBoundInstructionIR llvmInstructionCode'                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_forLowerUpperBoundInstructionIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                                 GALGAS_string & ioArgument_ioLLVMcode,
                                                                                 const GALGAS_generationContext constinArgument_inGenerationContext,
                                                                                 GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_forLowerUpperBoundInstructionIR * object = (const cPtr_forLowerUpperBoundInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_forLowerUpperBoundInstructionIR) ;
  GALGAS_string var_llvmType_9364 = extensionGetter_llvmTypeName (object->mProperty_mType, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 228)) ;
  GALGAS_string var_llvmVarName_9405 = function_llvmNameForLocalVariable (object->mProperty_mVarName, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 229)) ;
  GALGAS_string var_testLabel_9460 = GALGAS_string ("for.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 230)).getter_string (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 230)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 230)).add_operation (GALGAS_string (".test"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 230)) ;
  GALGAS_string var_loopLabel_9523 = GALGAS_string ("for.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 231)).getter_string (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 231)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 231)).add_operation (GALGAS_string (".loop"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 231)) ;
  GALGAS_string var_endLabel_9585 = GALGAS_string ("for.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 232)).getter_string (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 232)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 232)).add_operation (GALGAS_string (".end"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 232)) ;
  GALGAS_string var_testResult_9649 = GALGAS_string ("%for.").add_operation (object->mProperty_mLocation.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 233)).getter_string (SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 233)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 233)).add_operation (GALGAS_string (".test.result"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 233)) ;
  GALGAS_string var_loadedVarName_9724 = GALGAS_string::makeEmptyString ().add_operation (function_llvmNameForLocalVariable (object->mProperty_mVarName.add_operation (GALGAS_string (".loaded"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 234)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 234)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 234)) ;
  GALGAS_string var_currentVarName_9801 = GALGAS_string::makeEmptyString ().add_operation (function_llvmNameForLocalVariable (object->mProperty_mVarName.add_operation (GALGAS_string (".current"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 235)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 235)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 235)) ;
  GALGAS_string var_nextVarName_9876 = GALGAS_string::makeEmptyString ().add_operation (function_llvmNameForLocalVariable (object->mProperty_mVarName.add_operation (GALGAS_string (".next"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 236)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 236)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 236)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  store ").add_operation (var_llvmType_9364, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 238)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 238)).add_operation (extensionGetter_llvmName (object->mProperty_mLowerExpressionResult, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 238)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 238)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 238)).add_operation (var_llvmType_9364, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 238)).add_operation (GALGAS_string (" * "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 238)).add_operation (var_llvmVarName_9405, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 238)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 238)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 238)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_testLabel_9460, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 239)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 239)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 239)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_testLabel_9460.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 241)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 241)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ").add_operation (var_loadedVarName_9724, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 242)).add_operation (GALGAS_string (" = load "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 242)).add_operation (var_llvmType_9364, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 242)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 242)).add_operation (var_llvmType_9364, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 242)).add_operation (GALGAS_string (" * "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 242)).add_operation (var_llvmVarName_9405, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 242)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 242)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 242)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ").add_operation (var_testResult_9649, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 243)).add_operation (GALGAS_string (" = icmp "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 243)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 243)) ;
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = object->mProperty_mUnsigned.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string ("ult") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string ("slt") ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(temp_0, inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 244)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" ").add_operation (var_llvmType_9364, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 245)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 245)).add_operation (var_loadedVarName_9724, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 245)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 245)).add_operation (extensionGetter_llvmName (object->mProperty_mUpperExpressionResult, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 245)), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 245)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 245)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 245)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 ").add_operation (var_testResult_9649, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 246)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 246)).add_operation (var_loopLabel_9523, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 246)).add_operation (GALGAS_string (", label %"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 246)).add_operation (var_endLabel_9585, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 246)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 246)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 246)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_loopLabel_9523.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 248)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 248)) ;
  extensionMethod_instructionListLLVMCode (object->mProperty_mInstructionList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 249)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ").add_operation (var_currentVarName_9801, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 250)).add_operation (GALGAS_string (" = load "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 250)).add_operation (var_llvmType_9364, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 250)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 250)).add_operation (var_llvmType_9364, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 250)).add_operation (GALGAS_string (" * "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 250)).add_operation (var_llvmVarName_9405, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 250)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 250)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 250)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ").add_operation (var_nextVarName_9876, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 251)).add_operation (GALGAS_string (" = add "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 251)).add_operation (var_llvmType_9364, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 251)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 251)).add_operation (var_currentVarName_9801, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 251)).add_operation (GALGAS_string (", 1\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 251)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 251)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  store ").add_operation (var_llvmType_9364, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 252)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 252)).add_operation (var_nextVarName_9876, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 252)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 252)).add_operation (var_llvmType_9364, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 252)).add_operation (GALGAS_string (" * "), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 252)).add_operation (var_llvmVarName_9405, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 252)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 252)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 252)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_testLabel_9460, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 253)).add_operation (GALGAS_string ("\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 253)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 253)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(var_endLabel_9585.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 255)), inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 255)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_forLowerUpperBoundInstructionIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_forLowerUpperBoundInstructionIR.mSlotID,
                                            extensionMethod_forLowerUpperBoundInstructionIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_forLowerUpperBoundInstructionIR_llvmInstructionCode (defineExtensionMethod_forLowerUpperBoundInstructionIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//               Overriding extension method '@forLowerUpperBoundInstructionIR enterAccessibleEntities'                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_forLowerUpperBoundInstructionIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * inObject,
                                                                                     GALGAS_accessibleEntities & ioArgument_ioAccessibleEntities,
                                                                                     GALGAS_uint & ioArgument_ioMaxBranchOfOnInstructions,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_forLowerUpperBoundInstructionIR * object = (const cPtr_forLowerUpperBoundInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_forLowerUpperBoundInstructionIR) ;
  extensionMethod_enterAccessibleEntities (object->mProperty_mInstructionList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 264)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_forLowerUpperBoundInstructionIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_forLowerUpperBoundInstructionIR.mSlotID,
                                                extensionMethod_forLowerUpperBoundInstructionIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_forLowerUpperBoundInstructionIR_enterAccessibleEntities (defineExtensionMethod_forLowerUpperBoundInstructionIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//          Overriding extension method '@procedureCallInstructionAST noteInstructionTypesInPrecedenceGraph'           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_procedureCallInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                               GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                               C_Compiler * inCompiler
                                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_procedureCallInstructionAST * object = (const cPtr_procedureCallInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_procedureCallInstructionAST) ;
  cEnumerator_accessInAssignmentListAST enumerator_3212 (object->mProperty_mAccessList, kENUMERATION_UP) ;
  while (enumerator_3212.hasCurrentObject ()) {
    switch (enumerator_3212.current_mAccess (HERE).enumValue ()) {
    case GALGAS_accessInAssignmentAST::kNotBuilt:
      break ;
    case GALGAS_accessInAssignmentAST::kEnum_property:
      {
      }
      break ;
    case GALGAS_accessInAssignmentAST::kEnum_arrayAccess:
      {
        const cEnumAssociatedValues_accessInAssignmentAST_arrayAccess * extractPtr_3386 = (const cEnumAssociatedValues_accessInAssignmentAST_arrayAccess *) (enumerator_3212.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_indexExpression = extractPtr_3386->mAssociatedValue0 ;
        callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) extractedValue_indexExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 75)) ;
      }
      break ;
    }
    enumerator_3212.gotoNextObject () ;
  }
  cEnumerator_effectiveArgumentListAST enumerator_3423 (object->mProperty_mArguments, kENUMERATION_UP) ;
  while (enumerator_3423.hasCurrentObject ()) {
    switch (enumerator_3423.current_mEffectiveParameterKind (HERE).enumValue ()) {
    case GALGAS_effectiveArgumentPassingModeAST::kNotBuilt:
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_input:
      {
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_inputWithType:
      {
        const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType * extractPtr_3642 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType *) (enumerator_3423.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
        const GALGAS_lstring extractedValue_typeName = extractPtr_3642->mAssociatedValue1 ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, extractedValue_typeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (extractedValue_typeName, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 83)) COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 83)) ;
          }
        }
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_output:
      {
        const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output * extractPtr_3735 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output *) (enumerator_3423.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_expression = extractPtr_3735->mAssociatedValue0 ;
        callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) extractedValue_expression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 85)) ;
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInput:
      {
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInputSelfVariable:
      {
      }
      break ;
    }
    enumerator_3423.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_procedureCallInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_procedureCallInstructionAST.mSlotID,
                                                              extensionMethod_procedureCallInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_procedureCallInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_procedureCallInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//     Overriding extension method '@standAloneProcedureCallInstructionAST noteInstructionTypesInPrecedenceGraph'      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_standAloneProcedureCallInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                                         GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                                         C_Compiler * inCompiler
                                                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_standAloneProcedureCallInstructionAST * object = (const cPtr_standAloneProcedureCallInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_standAloneProcedureCallInstructionAST) ;
  cEnumerator_effectiveArgumentListAST enumerator_4100 (object->mProperty_mArguments, kENUMERATION_UP) ;
  while (enumerator_4100.hasCurrentObject ()) {
    switch (enumerator_4100.current_mEffectiveParameterKind (HERE).enumValue ()) {
    case GALGAS_effectiveArgumentPassingModeAST::kNotBuilt:
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_input:
      {
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_inputWithType:
      {
        const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType * extractPtr_4319 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_inputWithType *) (enumerator_4100.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
        const GALGAS_lstring extractedValue_typeName = extractPtr_4319->mAssociatedValue1 ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, extractedValue_typeName.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          ioArgument_ioGraph.setter_noteNode (function_llvmTypeNameFromPLMname (extractedValue_typeName, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 102)) COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 102)) ;
          }
        }
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_output:
      {
        const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output * extractPtr_4412 = (const cEnumAssociatedValues_effectiveArgumentPassingModeAST_output *) (enumerator_4100.current_mEffectiveParameterKind (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_expression = extractPtr_4412->mAssociatedValue0 ;
        callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) extractedValue_expression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 104)) ;
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInput:
      {
      }
      break ;
    case GALGAS_effectiveArgumentPassingModeAST::kEnum_outputInputSelfVariable:
      {
      }
      break ;
    }
    enumerator_4100.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_standAloneProcedureCallInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_standAloneProcedureCallInstructionAST.mSlotID,
                                                              extensionMethod_standAloneProcedureCallInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_standAloneProcedureCallInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_standAloneProcedureCallInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//          Overriding extension method '@standAloneProcedureCallInstructionAST instructionSemanticAnalysis'           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_standAloneProcedureCallInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                                               const GALGAS_PLMType constinArgument_inSelfType,
                                                                                               const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                                               const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                                               const GALGAS_semanticContext constinArgument_inContext,
                                                                                               const GALGAS_mode constinArgument_inCurrentMode,
                                                                                               GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                                               GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                                               GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                                               GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                                               GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                                               C_Compiler * inCompiler
                                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_standAloneProcedureCallInstructionAST * object = (const cPtr_standAloneProcedureCallInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_standAloneProcedureCallInstructionAST) ;
  GALGAS_lstring var_calledRoutineSignature_6328 = extensionGetter_routineSignature (object->mProperty_mArguments, object->mProperty_mSandAloneRoutineName.getter_location (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 151)) ;
  GALGAS_lstring var_LLVMInvocationRoutineName_6571 ;
  GALGAS_routineDescriptor var_routineDescriptor_6617 ;
  GALGAS_location var_keyLocation_6655 ;
  extensionMethod_searchKey (constinArgument_inContext.getter_mRoutineMapForContext (HERE), GALGAS_string::makeEmptyString (), object->mProperty_mSandAloneRoutineName, var_calledRoutineSignature_6328, var_LLVMInvocationRoutineName_6571, var_routineDescriptor_6617, var_keyLocation_6655, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 153)) ;
  GALGAS_lstring var_routineMangledName_6723 = function_routineMangledNameFromCall (GALGAS_string::makeEmptyString (), object->mProperty_mSandAloneRoutineName, object->mProperty_mArguments, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 162)) ;
  {
  ioArgument_ioTemporaries.mProperty_mSubprogramInvocationGraph.setter_addEdge (constinArgument_inCallerNameForInvocationGraph, var_routineMangledName_6723 COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 168)) ;
  }
  GALGAS_calleeKindIR var_routineKindIR_6984 = function_checkMode (constinArgument_inCurrentMode, extensionGetter_executionMode (var_routineDescriptor_6617.getter_routineKind (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 172)), var_routineDescriptor_6617.getter_routineKind (HERE), object->mProperty_mSandAloneRoutineName.getter_location (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 170)) ;
  GALGAS_procCallEffectiveParameterListIR var_effectiveParameterListIR_7271 = GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (SOURCE_FILE ("instruction-procedure-call.galgas", 177)) ;
  {
  routine_analyzeEffectiveParameters (constinArgument_inSelfType, constinArgument_inRoutineAttributes, var_routineDescriptor_6617.getter_signature (HERE), object->mProperty_mArguments, object->mProperty_mSandAloneRoutineName.getter_location (HERE), constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_effectiveParameterListIR_7271, inCompiler  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 178)) ;
  }
  ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_standaloneRoutineCallIR::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_objectIR::constructor_void (SOURCE_FILE ("instruction-procedure-call.galgas", 198)), var_routineMangledName_6723, var_LLVMInvocationRoutineName_6571, var_routineKindIR_6984, var_effectiveParameterListIR_7271  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 196))  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 196)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_standAloneProcedureCallInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_standAloneProcedureCallInstructionAST.mSlotID,
                                                    extensionMethod_standAloneProcedureCallInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_standAloneProcedureCallInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_standAloneProcedureCallInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//               Overriding extension method '@procedureCallInstructionAST instructionSemanticAnalysis'                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_procedureCallInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                                     const GALGAS_PLMType constinArgument_inSelfType,
                                                                                     const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                                     const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                                     const GALGAS_semanticContext constinArgument_inContext,
                                                                                     const GALGAS_mode constinArgument_inCurrentMode,
                                                                                     GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                                     GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                                     GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                                     GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                                     GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_procedureCallInstructionAST * object = (const cPtr_procedureCallInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_procedureCallInstructionAST) ;
  GALGAS_PLMType var_currentType_8957 ;
  GALGAS_string var_currentLLVMAddressVar_8989 ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, object->mProperty_mIdentifier.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_inSelfType.getter_kind (HERE).objectCompare (GALGAS_typeKind::constructor_void (SOURCE_FILE ("instruction-procedure-call.galgas", 225)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (object->mProperty_mIdentifier.getter_location (SOURCE_FILE ("instruction-procedure-call.galgas", 226)), GALGAS_string ("self is not available in this context"), fixItArray2  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 226)) ;
      var_currentType_8957.drop () ; // Release error dropped variable
      var_currentLLVMAddressVar_8989.drop () ; // Release error dropped variable
    }else if (kBoolFalse == test_1) {
      var_currentType_8957 = constinArgument_inSelfType ;
      var_currentLLVMAddressVar_8989 = function_llvmNameForSelf (inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 229)) ;
    }
  }else if (kBoolFalse == test_0) {
    GALGAS_valuedObject var_entity_9359 ;
    extensionMethod_searchEntity (ioArgument_ioUniversalMap, object->mProperty_mIdentifier, var_entity_9359, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 232)) ;
    switch (var_entity_9359.enumValue ()) {
    case GALGAS_valuedObject::kNotBuilt:
      break ;
    case GALGAS_valuedObject::kEnum_task:
      {
        const cEnumAssociatedValues_valuedObject_task * extractPtr_9506 = (const cEnumAssociatedValues_valuedObject_task *) (var_entity_9359.unsafePointer ()) ;
        const GALGAS_PLMType extractedValue_type = extractPtr_9506->mAssociatedValue0 ;
        var_currentType_8957 = extractedValue_type ;
        var_currentLLVMAddressVar_8989 = function_llvmNameForGlobalVariable (object->mProperty_mIdentifier.getter_string (SOURCE_FILE ("instruction-procedure-call.galgas", 236)), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 236)) ;
      }
      break ;
    case GALGAS_valuedObject::kEnum_driver:
      {
        const cEnumAssociatedValues_valuedObject_driver * extractPtr_9796 = (const cEnumAssociatedValues_valuedObject_driver *) (var_entity_9359.unsafePointer ()) ;
        const GALGAS_PLMType extractedValue_type = extractPtr_9796->mAssociatedValue0 ;
        const GALGAS_bool extractedValue_instancied = extractPtr_9796->mAssociatedValue1 ;
        const enumGalgasBool test_3 = extractedValue_instancied.boolEnum () ;
        if (kBoolTrue == test_3) {
          var_currentType_8957 = extractedValue_type ;
          var_currentLLVMAddressVar_8989 = function_llvmNameForGlobalVariable (object->mProperty_mIdentifier.getter_string (SOURCE_FILE ("instruction-procedure-call.galgas", 240)), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 240)) ;
        }else if (kBoolFalse == test_3) {
          TC_Array <C_FixItDescription> fixItArray4 ;
          inCompiler->emitSemanticError (object->mProperty_mIdentifier.getter_location (SOURCE_FILE ("instruction-procedure-call.galgas", 242)), GALGAS_string ("the driver should be instancied"), fixItArray4  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 242)) ;
          var_currentType_8957.drop () ; // Release error dropped variable
          var_currentLLVMAddressVar_8989.drop () ; // Release error dropped variable
        }
      }
      break ;
    case GALGAS_valuedObject::kEnum_registerGroup:
      {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (object->mProperty_mIdentifier.getter_location (SOURCE_FILE ("instruction-procedure-call.galgas", 245)), GALGAS_string ("a control register constant cannot be used in this context"), fixItArray5  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 245)) ;
        var_currentType_8957.drop () ; // Release error dropped variable
        var_currentLLVMAddressVar_8989.drop () ; // Release error dropped variable
      }
      break ;
    case GALGAS_valuedObject::kEnum_globalConstant:
      {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (object->mProperty_mIdentifier.getter_location (SOURCE_FILE ("instruction-procedure-call.galgas", 249)), GALGAS_string ("a global constant cannot be used in this context"), fixItArray6  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 249)) ;
        var_currentType_8957.drop () ; // Release error dropped variable
        var_currentLLVMAddressVar_8989.drop () ; // Release error dropped variable
      }
      break ;
    case GALGAS_valuedObject::kEnum_localConstant:
      {
        const cEnumAssociatedValues_valuedObject_localConstant * extractPtr_10277 = (const cEnumAssociatedValues_valuedObject_localConstant *) (var_entity_9359.unsafePointer ()) ;
        const GALGAS_PLMType extractedValue_type = extractPtr_10277->mAssociatedValue0 ;
        const GALGAS_lstring extractedValue_plmName = extractPtr_10277->mAssociatedValue1 ;
        var_currentType_8957 = extractedValue_type ;
        var_currentLLVMAddressVar_8989 = function_llvmNameForLocalVariable (extractedValue_plmName.getter_string (SOURCE_FILE ("instruction-procedure-call.galgas", 254)), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 254)) ;
      }
      break ;
    case GALGAS_valuedObject::kEnum_localVariable:
      {
        const cEnumAssociatedValues_valuedObject_localVariable * extractPtr_10426 = (const cEnumAssociatedValues_valuedObject_localVariable *) (var_entity_9359.unsafePointer ()) ;
        const GALGAS_PLMType extractedValue_type = extractPtr_10426->mAssociatedValue0 ;
        const GALGAS_lstring extractedValue_plmName = extractPtr_10426->mAssociatedValue1 ;
        var_currentType_8957 = extractedValue_type ;
        var_currentLLVMAddressVar_8989 = function_llvmNameForLocalVariable (extractedValue_plmName.getter_string (SOURCE_FILE ("instruction-procedure-call.galgas", 257)), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 257)) ;
      }
      break ;
    case GALGAS_valuedObject::kEnum_globalSyncInstance:
      {
        const cEnumAssociatedValues_valuedObject_globalSyncInstance * extractPtr_10585 = (const cEnumAssociatedValues_valuedObject_globalSyncInstance *) (var_entity_9359.unsafePointer ()) ;
        const GALGAS_PLMType extractedValue_type = extractPtr_10585->mAssociatedValue0 ;
        const GALGAS_lstring extractedValue_plmName = extractPtr_10585->mAssociatedValue1 ;
        var_currentType_8957 = extractedValue_type ;
        var_currentLLVMAddressVar_8989 = function_llvmNameForGlobalSyncInstance (extractedValue_plmName.getter_string (SOURCE_FILE ("instruction-procedure-call.galgas", 260)), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 260)) ;
      }
      break ;
    }
  }
  GALGAS_propertyMap var_currentObjectPropertyMap_10676 = var_currentType_8957.getter_propertyMap (HERE) ;
  GALGAS_accessInAssignmentListAST var_accessList_10791 = object->mProperty_mAccessList ;
  GALGAS_accessInAssignmentAST var_lastAccess_10845 ;
  {
  var_accessList_10791.setter_popLast (var_lastAccess_10845, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 267)) ;
  }
  cEnumerator_accessInAssignmentListAST enumerator_10900 (var_accessList_10791, kENUMERATION_UP) ;
  while (enumerator_10900.hasCurrentObject ()) {
    switch (enumerator_10900.current_mAccess (HERE).enumValue ()) {
    case GALGAS_accessInAssignmentAST::kNotBuilt:
      break ;
    case GALGAS_accessInAssignmentAST::kEnum_property:
      {
        const cEnumAssociatedValues_accessInAssignmentAST_property * extractPtr_12277 = (const cEnumAssociatedValues_accessInAssignmentAST_property *) (enumerator_10900.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_lstring extractedValue_propertyName = extractPtr_12277->mAssociatedValue0 ;
        GALGAS_bool var_isPublic_11173 ;
        GALGAS_propertyAccessKind var_propertyAccess_11221 ;
        var_currentObjectPropertyMap_10676.method_searchKey (extractedValue_propertyName, var_isPublic_11173, var_propertyAccess_11221, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 274)) ;
        switch (var_propertyAccess_11221.enumValue ()) {
        case GALGAS_propertyAccessKind::kNotBuilt:
          break ;
        case GALGAS_propertyAccessKind::kEnum_nonVirtualMethod:
          {
            TC_Array <C_FixItDescription> fixItArray7 ;
            inCompiler->emitSemanticError (extractedValue_propertyName.getter_location (SOURCE_FILE ("instruction-procedure-call.galgas", 281)), GALGAS_string ("a method cannot be used in this context"), fixItArray7  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 281)) ;
            var_currentType_8957.drop () ; // Release error dropped variable
            var_currentLLVMAddressVar_8989.drop () ; // Release error dropped variable
          }
          break ;
        case GALGAS_propertyAccessKind::kEnum_constantProperty:
          {
            TC_Array <C_FixItDescription> fixItArray8 ;
            inCompiler->emitSemanticError (extractedValue_propertyName.getter_location (SOURCE_FILE ("instruction-procedure-call.galgas", 283)), GALGAS_string ("a context property cannot be used in this context"), fixItArray8  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 283)) ;
            var_currentType_8957.drop () ; // Release error dropped variable
            var_currentLLVMAddressVar_8989.drop () ; // Release error dropped variable
          }
          break ;
        case GALGAS_propertyAccessKind::kEnum_singleton:
          {
            const cEnumAssociatedValues_propertyAccessKind_singleton * extractPtr_11764 = (const cEnumAssociatedValues_propertyAccessKind_singleton *) (var_propertyAccess_11221.unsafePointer ()) ;
            const GALGAS_objectIR extractedValue_object = extractPtr_11764->mAssociatedValue0 ;
            var_currentType_8957 = extensionGetter_type (extractedValue_object, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 287)) ;
            var_currentLLVMAddressVar_8989 = extensionGetter_llvmName (extractedValue_object, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 288)) ;
            var_currentObjectPropertyMap_10676 = extensionGetter_type (extractedValue_object, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 289)).getter_propertyMap (HERE) ;
          }
          break ;
        case GALGAS_propertyAccessKind::kEnum_indexed:
          {
            const cEnumAssociatedValues_propertyAccessKind_indexed * extractPtr_12260 = (const cEnumAssociatedValues_propertyAccessKind_indexed *) (var_propertyAccess_11221.unsafePointer ()) ;
            const GALGAS_PLMType extractedValue_propertyType = extractPtr_12260->mAssociatedValue0 ;
            const GALGAS_uint extractedValue_propertyIndex = extractPtr_12260->mAssociatedValue1 ;
            GALGAS_string var_llvmPropertyName_11898 ;
            {
            extensionSetter_newTempLLVMVar (ioArgument_ioTemporaries, var_llvmPropertyName_11898, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 291)) ;
            }
            {
            extensionSetter_appendGetUniversalPropertyReference (ioArgument_ioInstructionGenerationList, var_currentType_8957, var_currentLLVMAddressVar_8989, var_llvmPropertyName_11898, extractedValue_propertyIndex, extractedValue_propertyName.getter_string (SOURCE_FILE ("instruction-procedure-call.galgas", 297)), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 292)) ;
            }
            var_currentType_8957 = extractedValue_propertyType ;
            var_currentLLVMAddressVar_8989 = var_llvmPropertyName_11898 ;
            var_currentObjectPropertyMap_10676 = var_currentType_8957.getter_propertyMap (HERE) ;
          }
          break ;
        }
      }
      break ;
    case GALGAS_accessInAssignmentAST::kEnum_arrayAccess:
      {
        const cEnumAssociatedValues_accessInAssignmentAST_arrayAccess * extractPtr_12441 = (const cEnumAssociatedValues_accessInAssignmentAST_arrayAccess *) (enumerator_10900.current_mAccess (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_indexExpression = extractPtr_12441->mAssociatedValue0 ;
        const GALGAS_location extractedValue_endOfIndex = extractPtr_12441->mAssociatedValue1 ;
        TC_Array <C_FixItDescription> fixItArray9 ;
        inCompiler->emitSemanticError (extractedValue_endOfIndex, GALGAS_string ("not handled yet"), fixItArray9  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 304)) ;
        var_currentType_8957.drop () ; // Release error dropped variable
        var_currentLLVMAddressVar_8989.drop () ; // Release error dropped variable
      }
      break ;
    }
    enumerator_10900.gotoNextObject () ;
  }
  switch (var_lastAccess_10845.enumValue ()) {
  case GALGAS_accessInAssignmentAST::kNotBuilt:
    break ;
  case GALGAS_accessInAssignmentAST::kEnum_arrayAccess:
    {
      const cEnumAssociatedValues_accessInAssignmentAST_arrayAccess * extractPtr_12697 = (const cEnumAssociatedValues_accessInAssignmentAST_arrayAccess *) (var_lastAccess_10845.unsafePointer ()) ;
      const GALGAS_location extractedValue_endOfIndex = extractPtr_12697->mAssociatedValue1 ;
      TC_Array <C_FixItDescription> fixItArray10 ;
      inCompiler->emitSemanticError (extractedValue_endOfIndex, GALGAS_string ("a property is required here"), fixItArray10  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 312)) ;
    }
    break ;
  case GALGAS_accessInAssignmentAST::kEnum_property:
    {
      const cEnumAssociatedValues_accessInAssignmentAST_property * extractPtr_18001 = (const cEnumAssociatedValues_accessInAssignmentAST_property *) (var_lastAccess_10845.unsafePointer ()) ;
      const GALGAS_lstring extractedValue_methodName = extractPtr_18001->mAssociatedValue0 ;
      GALGAS_propertyMap var_propertyMap_12757 = var_currentObjectPropertyMap_10676 ;
      GALGAS_lstring var_key_12803 = function_routineMangledNameFromCall (GALGAS_string::makeEmptyString (), extractedValue_methodName, object->mProperty_mArguments, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 315)) ;
      GALGAS_propertyAccessKind var_propertyAccess_12937 ;
      GALGAS_bool joker_12896 ; // Joker input parameter
      var_propertyMap_12757.method_searchKey (var_key_12803, joker_12896, var_propertyAccess_12937, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 316)) ;
      switch (var_propertyAccess_12937.enumValue ()) {
      case GALGAS_propertyAccessKind::kNotBuilt:
        break ;
      case GALGAS_propertyAccessKind::kEnum_constantProperty:
        {
          TC_Array <C_FixItDescription> fixItArray11 ;
          inCompiler->emitSemanticError (extractedValue_methodName.getter_location (SOURCE_FILE ("instruction-procedure-call.galgas", 319)), GALGAS_string ("a constant cannot be used as method"), fixItArray11  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 319)) ;
        }
        break ;
      case GALGAS_propertyAccessKind::kEnum_nonVirtualMethod:
        {
          const cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod * extractPtr_15745 = (const cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod *) (var_propertyAccess_12937.unsafePointer ()) ;
          const GALGAS_routineDescriptor extractedValue_routineDescriptor = extractPtr_15745->mAssociatedValue0 ;
          GALGAS_procCallEffectiveParameterListIR temp_12 = GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (SOURCE_FILE ("instruction-procedure-call.galgas", 324)) ;
          temp_12.addAssign_operation (GALGAS_procEffectiveParameterPassingModeIR::constructor_outputInput (SOURCE_FILE ("instruction-procedure-call.galgas", 323)), GALGAS_objectIR::constructor_reference (var_currentType_8957, var_currentLLVMAddressVar_8989  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 324))  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 324)) ;
          GALGAS_procCallEffectiveParameterListIR var_effectiveParameterListIR_13232 = temp_12 ;
          GALGAS_routineKind var_routineKind_13419 = extractedValue_routineDescriptor.getter_routineKind (HERE) ;
          GALGAS_mode var_calleeMode_13472 = extensionGetter_executionMode (var_routineKind_13419, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 329)) ;
          GALGAS_routineTypedSignature var_formalSignature_13528 = extractedValue_routineDescriptor.getter_signature (HERE) ;
          GALGAS_bool test_13 = GALGAS_bool (kIsEqual, object->mProperty_mIdentifier.getter_string (HERE).objectCompare (GALGAS_string::makeEmptyString ())) ;
          if (kBoolTrue == test_13.boolEnum ()) {
            test_13 = extractedValue_routineDescriptor.getter_canMutateProperties (HERE) ;
          }
          GALGAS_bool test_14 = test_13 ;
          if (kBoolTrue == test_14.boolEnum ()) {
            test_14 = constinArgument_inRoutineAttributes.getter_mutating (SOURCE_FILE ("instruction-procedure-call.galgas", 333)).operator_not (SOURCE_FILE ("instruction-procedure-call.galgas", 333)) ;
          }
          const enumGalgasBool test_15 = test_14.boolEnum () ;
          if (kBoolTrue == test_15) {
            TC_Array <C_FixItDescription> fixItArray16 ;
            inCompiler->emitSemanticError (extractedValue_methodName.getter_location (SOURCE_FILE ("instruction-procedure-call.galgas", 334)), GALGAS_string ("cannot mutate properties, current method is not declared with @").add_operation (function_mutatingAttribute (inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 335)), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 335)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 335)), fixItArray16  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 334)) ;
          }
          const enumGalgasBool test_17 = GALGAS_bool (kIsNotEqual, extractedValue_routineDescriptor.getter_returnTypeProxy (HERE).objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("instruction-procedure-call.galgas", 338)))).boolEnum () ;
          if (kBoolTrue == test_17) {
            TC_Array <C_FixItDescription> fixItArray18 ;
            inCompiler->emitSemanticError (extractedValue_methodName.getter_location (SOURCE_FILE ("instruction-procedure-call.galgas", 339)), GALGAS_string ("not a procedure (returns a value)"), fixItArray18  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 339)) ;
          }else if (kBoolFalse == test_17) {
            GALGAS_calleeKindIR var_calleeKind_14230 = function_checkMode (constinArgument_inCurrentMode, var_calleeMode_13472, var_routineKind_13419, extractedValue_methodName.getter_location (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 342)) ;
            {
            routine_analyzeEffectiveParameters (constinArgument_inSelfType, constinArgument_inRoutineAttributes, var_formalSignature_13528, object->mProperty_mArguments, extractedValue_methodName.getter_location (HERE), constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_effectiveParameterListIR_13232, inCompiler  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 349)) ;
            }
            GALGAS_lstring var_routineMangledName_15159 = function_routineMangledNameFromCall (function_llvmTypeStringFromPLMname (var_currentType_8957.getter_plmTypeDescriptionName (HERE), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 366)), extractedValue_methodName, object->mProperty_mArguments, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 366)) ;
            ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_standaloneRoutineCallIR::constructor_new (object->mProperty_mIdentifier.getter_string (SOURCE_FILE ("instruction-procedure-call.galgas", 369)), GALGAS_objectIR::constructor_void (SOURCE_FILE ("instruction-procedure-call.galgas", 370)), var_routineMangledName_15159, var_routineMangledName_15159, var_calleeKind_14230, var_effectiveParameterListIR_13232  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 368))  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 368)) ;
            {
            ioArgument_ioTemporaries.mProperty_mSubprogramInvocationGraph.setter_addEdge (constinArgument_inCallerNameForInvocationGraph, var_routineMangledName_15159 COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 377)) ;
            }
          }
        }
        break ;
      case GALGAS_propertyAccessKind::kEnum_singleton:
        {
          const cEnumAssociatedValues_propertyAccessKind_singleton * extractPtr_15851 = (const cEnumAssociatedValues_propertyAccessKind_singleton *) (var_propertyAccess_12937.unsafePointer ()) ;
          const GALGAS_location extractedValue_errorLocation = extractPtr_15851->mAssociatedValue1 ;
          TC_Array <C_FixItDescription> fixItArray19 ;
          inCompiler->emitSemanticError (extractedValue_errorLocation, GALGAS_string ("a property cannot be used as method"), fixItArray19  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 380)) ;
        }
        break ;
      case GALGAS_propertyAccessKind::kEnum_indexed:
        {
          const cEnumAssociatedValues_propertyAccessKind_indexed * extractPtr_17993 = (const cEnumAssociatedValues_propertyAccessKind_indexed *) (var_propertyAccess_12937.unsafePointer ()) ;
          const GALGAS_PLMType extractedValue_propertyType = extractPtr_17993->mAssociatedValue0 ;
          const GALGAS_uint extractedValue_propertyIndex = extractPtr_17993->mAssociatedValue1 ;
          const enumGalgasBool test_20 = extractedValue_propertyType.getter_kind (HERE).getter_isFunction (SOURCE_FILE ("instruction-procedure-call.galgas", 382)).operator_not (SOURCE_FILE ("instruction-procedure-call.galgas", 382)).boolEnum () ;
          if (kBoolTrue == test_20) {
            TC_Array <C_FixItDescription> fixItArray21 ;
            inCompiler->emitSemanticError (extractedValue_methodName.getter_location (SOURCE_FILE ("instruction-procedure-call.galgas", 383)), GALGAS_string ("an indexed property cannot be used as method"), fixItArray21  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 383)) ;
          }else if (kBoolFalse == test_20) {
            GALGAS_routineDescriptor var_descriptor_16112 ;
            extractedValue_propertyType.getter_kind (HERE).method_function (var_descriptor_16112, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 385)) ;
            const enumGalgasBool test_22 = GALGAS_bool (kIsNotEqual, var_descriptor_16112.getter_returnTypeProxy (HERE).objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("instruction-procedure-call.galgas", 387)))).boolEnum () ;
            if (kBoolTrue == test_22) {
              TC_Array <C_FixItDescription> fixItArray23 ;
              inCompiler->emitSemanticError (extractedValue_methodName.getter_location (SOURCE_FILE ("instruction-procedure-call.galgas", 388)), GALGAS_string ("a function returns a value and cannot be called as a procedure"), fixItArray23  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 388)) ;
            }else if (kBoolFalse == test_22) {
              GALGAS_procCallEffectiveParameterListIR var_effectiveParameterListIR_16663 = GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (SOURCE_FILE ("instruction-procedure-call.galgas", 398)) ;
              {
              routine_analyzeEffectiveParameters (constinArgument_inSelfType, constinArgument_inRoutineAttributes, var_descriptor_16112.getter_signature (HERE), object->mProperty_mArguments, extractedValue_methodName.getter_location (HERE), constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_effectiveParameterListIR_16663, inCompiler  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 399)) ;
              }
              GALGAS_string var_property_5F_llvmName_17434 ;
              {
              extensionSetter_newTempLLVMVar (ioArgument_ioTemporaries, var_property_5F_llvmName_17434, inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 416)) ;
              }
              {
              extensionSetter_appendGetUniversalPropertyReference (ioArgument_ioInstructionGenerationList, var_currentType_8957, var_currentLLVMAddressVar_8989, var_property_5F_llvmName_17434, extractedValue_propertyIndex, extractedValue_methodName.getter_string (SOURCE_FILE ("instruction-procedure-call.galgas", 422)), inCompiler COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 417)) ;
              }
              ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_indirectRoutineCallIR::constructor_new (GALGAS_objectIR::constructor_reference (extractedValue_propertyType, var_property_5F_llvmName_17434  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 426)), extractedValue_propertyType, GALGAS_objectIR::constructor_void (SOURCE_FILE ("instruction-procedure-call.galgas", 428)), var_effectiveParameterListIR_16663  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 425))  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 425)) ;
            }
          }
        }
        break ;
      }
    }
    break ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_procedureCallInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_procedureCallInstructionAST.mSlotID,
                                                    extensionMethod_procedureCallInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_procedureCallInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_procedureCallInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//              Overriding extension method '@switchInstructionAST noteInstructionTypesInPrecedenceGraph'              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_switchInstructionAST_noteInstructionTypesInPrecedenceGraph (const cPtr_instructionAST * inObject,
                                                                                        GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_switchInstructionAST * object = (const cPtr_switchInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_switchInstructionAST) ;
  callExtensionMethod_noteExpressionTypesInPrecedenceGraph ((const cPtr_expressionAST *) object->mProperty_mSwitchExpression.ptr (), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 68)) ;
  cEnumerator_switchCaseListAST enumerator_2891 (object->mProperty_mSwitchCaseList, kENUMERATION_UP) ;
  while (enumerator_2891.hasCurrentObject ()) {
    extensionMethod_noteInstructionListTypesInPrecedenceGraph (enumerator_2891.current_mCaseInstructionList (HERE), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 70)) ;
    enumerator_2891.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_switchInstructionAST_noteInstructionTypesInPrecedenceGraph (void) {
  enterExtensionMethod_noteInstructionTypesInPrecedenceGraph (kTypeDescriptor_GALGAS_switchInstructionAST.mSlotID,
                                                              extensionMethod_switchInstructionAST_noteInstructionTypesInPrecedenceGraph) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_switchInstructionAST_noteInstructionTypesInPrecedenceGraph (defineExtensionMethod_switchInstructionAST_noteInstructionTypesInPrecedenceGraph, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                   Overriding extension method '@switchInstructionAST instructionSemanticAnalysis'                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_switchInstructionAST_instructionSemanticAnalysis (const cPtr_instructionAST * inObject,
                                                                              const GALGAS_PLMType constinArgument_inSelfType,
                                                                              const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                                                              const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                                                              const GALGAS_semanticContext constinArgument_inContext,
                                                                              const GALGAS_mode constinArgument_inCurrentMode,
                                                                              GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                              GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                                                              GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                                                              GALGAS_allocaList & ioArgument_ioAllocaList,
                                                                              GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_switchInstructionAST * object = (const cPtr_switchInstructionAST *) inObject ;
  macroValidSharedObject (object, cPtr_switchInstructionAST) ;
  GALGAS_instructionListIR var_switchExpressionGenerationList_4009 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-switch.galgas", 91)) ;
  GALGAS_objectIR var_switchValueIR_4472 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mProperty_mSwitchExpression.ptr (), constinArgument_inSelfType, GALGAS_routineAttributes::constructor_none (SOURCE_FILE ("instruction-switch.galgas", 94)), constinArgument_inCallerNameForInvocationGraph, function_voidType (inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 96)), constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_switchExpressionGenerationList_4009, var_switchValueIR_4472, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 92)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_switchValueIR_4472, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 106)) ;
  }
  GALGAS_classConstantMap var_enumConstantMap_4626 = extensionGetter_type (var_switchValueIR_4472, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 111)).getter_classConstantMap (HERE) ;
  const enumGalgasBool test_0 = extensionGetter_type (var_switchValueIR_4472, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 112)).getter_kind (HERE).getter_isEnumeration (SOURCE_FILE ("instruction-switch.galgas", 112)).operator_not (SOURCE_FILE ("instruction-switch.galgas", 112)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (object->mProperty_mEndOf_5F_test_5F_expression, GALGAS_string ("test expression type is '").add_operation (extensionGetter_plmTypeDescriptionName (var_switchValueIR_4472, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 116)), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 116)).add_operation (GALGAS_string ("', it should be boolean"), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 116)), fixItArray1  COMMA_SOURCE_FILE ("instruction-switch.galgas", 115)) ;
  }
  const enumGalgasBool test_2 = extensionGetter_isStatic (var_switchValueIR_4472, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 119)).boolEnum () ;
  if (kBoolTrue == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (object->mProperty_mEndOf_5F_test_5F_expression, GALGAS_string ("test expression type should not be static"), fixItArray3  COMMA_SOURCE_FILE ("instruction-switch.galgas", 120)) ;
  }
  {
  extensionSetter_openOverrideForSelectBlock (ioArgument_ioUniversalMap, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 123)) ;
  }
  GALGAS_stringset var_usedEnumerationValues_5203 = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("instruction-switch.galgas", 124)) ;
  GALGAS_switchCaseListIR var_switchCaseListIR_5245 = GALGAS_switchCaseListIR::constructor_emptyList (SOURCE_FILE ("instruction-switch.galgas", 125)) ;
  cEnumerator_switchCaseListAST enumerator_5309 (object->mProperty_mSwitchCaseList, kENUMERATION_UP) ;
  while (enumerator_5309.hasCurrentObject ()) {
    GALGAS_uintlist var_caseIdentifierIndexList_5350 = GALGAS_uintlist::constructor_emptyList (SOURCE_FILE ("instruction-switch.galgas", 127)) ;
    cEnumerator_lstringlist enumerator_5392 (enumerator_5309.current_mCaseIdentifiers (HERE), kENUMERATION_UP) ;
    while (enumerator_5392.hasCurrentObject ()) {
      GALGAS_bigint var_constantIdx_5462 ;
      GALGAS_lstring joker_5464 ; // Joker input parameter
      var_enumConstantMap_4626.method_searchKey (enumerator_5392.current_mValue (HERE), var_constantIdx_5462, joker_5464, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 129)) ;
      var_caseIdentifierIndexList_5350.addAssign_operation (var_constantIdx_5462.getter_uint (inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 130))  COMMA_SOURCE_FILE ("instruction-switch.galgas", 130)) ;
      const enumGalgasBool test_4 = var_usedEnumerationValues_5203.getter_hasKey (enumerator_5392.current_mValue (HERE).getter_string (SOURCE_FILE ("instruction-switch.galgas", 131)) COMMA_SOURCE_FILE ("instruction-switch.galgas", 131)).boolEnum () ;
      if (kBoolTrue == test_4) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        fixItArray5.appendObject (C_FixItDescription (kFixItRemove, "")) ;
        inCompiler->emitSemanticError (enumerator_5392.current_mValue (HERE).getter_location (SOURCE_FILE ("instruction-switch.galgas", 132)), GALGAS_string ("duplicated enumeration constant"), fixItArray5  COMMA_SOURCE_FILE ("instruction-switch.galgas", 132)) ;
      }
      var_usedEnumerationValues_5203.addAssign_operation (enumerator_5392.current_mValue (HERE).getter_string (SOURCE_FILE ("instruction-switch.galgas", 134))  COMMA_SOURCE_FILE ("instruction-switch.galgas", 134)) ;
      enumerator_5392.gotoNextObject () ;
    }
    GALGAS_instructionListIR var_instructionGenerationList_5748 = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("instruction-switch.galgas", 136)) ;
    extensionMethod_analyzeBranchInstructionList (enumerator_5309.current_mCaseInstructionList (HERE), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, object->mProperty_mEndOf_5F_switch_5F_instruction, constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, var_instructionGenerationList_5748, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 137)) ;
    var_switchCaseListIR_5245.addAssign_operation (var_caseIdentifierIndexList_5350, var_instructionGenerationList_5748  COMMA_SOURCE_FILE ("instruction-switch.galgas", 150)) ;
    enumerator_5309.gotoNextObject () ;
  }
  {
  extensionSetter_closeOverride (ioArgument_ioUniversalMap, object->mProperty_mEndOf_5F_switch_5F_instruction, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 152)) ;
  }
  cEnumerator_classConstantMap enumerator_6488 (var_enumConstantMap_4626, kENUMERATION_UP) ;
  while (enumerator_6488.hasCurrentObject ()) {
    const enumGalgasBool test_6 = var_usedEnumerationValues_5203.getter_hasKey (enumerator_6488.current_lkey (HERE).getter_string (SOURCE_FILE ("instruction-switch.galgas", 155)) COMMA_SOURCE_FILE ("instruction-switch.galgas", 155)).operator_not (SOURCE_FILE ("instruction-switch.galgas", 155)).boolEnum () ;
    if (kBoolTrue == test_6) {
      TC_Array <C_FixItDescription> fixItArray7 ;
      inCompiler->emitSemanticError (object->mProperty_mEndOf_5F_test_5F_expression, GALGAS_string ("missing '").add_operation (enumerator_6488.current_lkey (HERE).getter_string (SOURCE_FILE ("instruction-switch.galgas", 156)), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 156)).add_operation (GALGAS_string ("' enumeration constant"), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 156)), fixItArray7  COMMA_SOURCE_FILE ("instruction-switch.galgas", 156)) ;
    }
    enumerator_6488.gotoNextObject () ;
  }
  ioArgument_ioInstructionGenerationList.addAssign_operation (GALGAS_switchInstructionIR::constructor_new (object->mProperty_mEndOf_5F_test_5F_expression.getter_locationIndex (inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 161)), var_switchExpressionGenerationList_4009, var_switchValueIR_4472, var_switchCaseListIR_5245  COMMA_SOURCE_FILE ("instruction-switch.galgas", 160))  COMMA_SOURCE_FILE ("instruction-switch.galgas", 160)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_switchInstructionAST_instructionSemanticAnalysis (void) {
  enterExtensionMethod_instructionSemanticAnalysis (kTypeDescriptor_GALGAS_switchInstructionAST.mSlotID,
                                                    extensionMethod_switchInstructionAST_instructionSemanticAnalysis) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_switchInstructionAST_instructionSemanticAnalysis (defineExtensionMethod_switchInstructionAST_instructionSemanticAnalysis, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                       Overriding extension method '@switchInstructionIR llvmInstructionCode'                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_switchInstructionIR_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                                                     GALGAS_string & ioArgument_ioLLVMcode,
                                                                     const GALGAS_generationContext constinArgument_inGenerationContext,
                                                                     GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_switchInstructionIR * object = (const cPtr_switchInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_switchInstructionIR) ;
  extensionMethod_instructionListLLVMCode (object->mProperty_mSwitchExpressionGenerationList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 194)) ;
  GALGAS_string var_labelOtherwise_8157 = GALGAS_string ("switch.").add_operation (object->mProperty_mLabelIndex.getter_string (SOURCE_FILE ("instruction-switch.galgas", 196)), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 196)).add_operation (GALGAS_string (".otherwise"), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 196)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  switch ").add_operation (extensionGetter_llvmTypeName (object->mProperty_mSwitchExpression, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 197)), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 197)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 197)).add_operation (extensionGetter_llvmName (object->mProperty_mSwitchExpression, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 197)), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 197)), inCompiler  COMMA_SOURCE_FILE ("instruction-switch.galgas", 197)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", label %").add_operation (var_labelOtherwise_8157, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 198)).add_operation (GALGAS_string (" [\n"), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 198)), inCompiler  COMMA_SOURCE_FILE ("instruction-switch.galgas", 198)) ;
  cEnumerator_switchCaseListIR enumerator_8407 (object->mProperty_mCaseGenerationList, kENUMERATION_UP) ;
  GALGAS_uint index_8358 ((uint32_t) 0) ;
  while (enumerator_8407.hasCurrentObject ()) {
    cEnumerator_uintlist enumerator_8470 (enumerator_8407.current_mCaseIdentifierIndexes (HERE), kENUMERATION_UP) ;
    while (enumerator_8470.hasCurrentObject ()) {
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("    ").add_operation (extensionGetter_llvmTypeName (object->mProperty_mSwitchExpression, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 201)), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 201)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 201)).add_operation (enumerator_8470.current_mValue (HERE).getter_string (SOURCE_FILE ("instruction-switch.galgas", 201)), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 201)), inCompiler  COMMA_SOURCE_FILE ("instruction-switch.galgas", 201)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", label %switch.").add_operation (object->mProperty_mLabelIndex.getter_string (SOURCE_FILE ("instruction-switch.galgas", 202)), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 202)).add_operation (GALGAS_string (".branch."), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 202)).add_operation (index_8358.getter_string (SOURCE_FILE ("instruction-switch.galgas", 202)), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 202)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 202)), inCompiler  COMMA_SOURCE_FILE ("instruction-switch.galgas", 202)) ;
      enumerator_8470.gotoNextObject () ;
    }
    enumerator_8407.gotoNextObject () ;
    index_8358.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-switch.galgas", 199)) ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ]\n"
    "\n"), inCompiler  COMMA_SOURCE_FILE ("instruction-switch.galgas", 205)) ;
  cEnumerator_switchCaseListIR enumerator_8753 (object->mProperty_mCaseGenerationList, kENUMERATION_UP) ;
  GALGAS_uint index_8710 ((uint32_t) 0) ;
  while (enumerator_8753.hasCurrentObject ()) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("switch.").add_operation (object->mProperty_mLabelIndex.getter_string (SOURCE_FILE ("instruction-switch.galgas", 208)), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 208)).add_operation (GALGAS_string (".branch."), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 208)).add_operation (index_8710.getter_string (SOURCE_FILE ("instruction-switch.galgas", 208)), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 208)).add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 208)), inCompiler  COMMA_SOURCE_FILE ("instruction-switch.galgas", 208)) ;
    extensionMethod_instructionListLLVMCode (enumerator_8753.current_mCaseInstructionList (HERE), ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 209)) ;
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br label %").add_operation (var_labelOtherwise_8157, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 210)).add_operation (GALGAS_string ("\n"
      "\n"), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 210)), inCompiler  COMMA_SOURCE_FILE ("instruction-switch.galgas", 210)) ;
    enumerator_8753.gotoNextObject () ;
    index_8710.increment_operation (inCompiler  COMMA_SOURCE_FILE ("instruction-switch.galgas", 207)) ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(var_labelOtherwise_8157.add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 213)), inCompiler  COMMA_SOURCE_FILE ("instruction-switch.galgas", 213)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_switchInstructionIR_llvmInstructionCode (void) {
  enterExtensionMethod_llvmInstructionCode (kTypeDescriptor_GALGAS_switchInstructionIR.mSlotID,
                                            extensionMethod_switchInstructionIR_llvmInstructionCode) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_switchInstructionIR_llvmInstructionCode (defineExtensionMethod_switchInstructionIR_llvmInstructionCode, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     Overriding extension method '@switchInstructionIR enterAccessibleEntities'                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_switchInstructionIR_enterAccessibleEntities (const cPtr_abstractInstructionIR * inObject,
                                                                         GALGAS_accessibleEntities & ioArgument_ioAccessibleEntities,
                                                                         GALGAS_uint & ioArgument_ioMaxBranchOfOnInstructions,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_switchInstructionIR * object = (const cPtr_switchInstructionIR *) inObject ;
  macroValidSharedObject (object, cPtr_switchInstructionIR) ;
  extensionMethod_enterAccessibleEntities (object->mProperty_mSwitchExpressionGenerationList, ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 222)) ;
  cEnumerator_switchCaseListIR enumerator_9500 (object->mProperty_mCaseGenerationList, kENUMERATION_UP) ;
  while (enumerator_9500.hasCurrentObject ()) {
    extensionMethod_enterAccessibleEntities (enumerator_9500.current_mCaseInstructionList (HERE), ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("instruction-switch.galgas", 224)) ;
    enumerator_9500.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_switchInstructionIR_enterAccessibleEntities (void) {
  enterExtensionMethod_enterAccessibleEntities (kTypeDescriptor_GALGAS_switchInstructionIR.mSlotID,
                                                extensionMethod_switchInstructionIR_enterAccessibleEntities) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_switchInstructionIR_enterAccessibleEntities (defineExtensionMethod_switchInstructionIR_enterAccessibleEntities, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          Routine 'handleArraySubscriptNew'                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_handleArraySubscriptNew (const GALGAS_PLMType constinArgument_inSelfType,
                                      const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                      const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                      const GALGAS_semanticContext constinArgument_inContext,
                                      const GALGAS_mode constinArgument_inCurrentMode,
                                      GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                      GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                      GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                      GALGAS_allocaList & ioArgument_ioAllocaList,
                                      const GALGAS_expressionAST constinArgument_inIndexExpression,
                                      const GALGAS_location constinArgument_inErrorLocation,
                                      const GALGAS_bigint constinArgument_inArraySize,
                                      const GALGAS_PLMType constinArgument_inElementType,
                                      GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                      GALGAS_objectIR & outArgument_outIndexIR,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outIndexIR.drop () ; // Release 'out' argument
  GALGAS_objectIR var_indexResult_1326 ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) constinArgument_inIndexExpression.ptr (), constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, function_voidType (inCompiler COMMA_SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 25)), constinArgument_inContext, constinArgument_inCurrentMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, ioArgument_ioInstructionGenerationList, var_indexResult_1326, inCompiler COMMA_SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 21)) ;
  {
  extensionSetter_appendLoadWhenReference (ioArgument_ioInstructionGenerationList, ioArgument_ioTemporaries, var_indexResult_1326, inCompiler COMMA_SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 35)) ;
  }
  const enumGalgasBool test_0 = var_indexResult_1326.getter_isLiteralInteger (SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 39)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_bigint var_indexValue_1558 ;
    GALGAS_PLMType joker_1526_1 ; // Joker input parameter
    var_indexResult_1326.method_literalInteger (joker_1526_1, var_indexValue_1558, inCompiler COMMA_SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 40)) ;
    GALGAS_bool test_1 = GALGAS_bool (kIsStrictInf, var_indexValue_1558.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 41)))) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      test_1 = GALGAS_bool (kIsSupOrEqual, var_indexValue_1558.objectCompare (constinArgument_inArraySize)) ;
    }
    const enumGalgasBool test_2 = test_1.boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (constinArgument_inErrorLocation, GALGAS_string ("static index should be positive and < ").add_operation (constinArgument_inArraySize.getter_string (SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 42)), inCompiler COMMA_SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 42)), fixItArray3  COMMA_SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 42)) ;
      outArgument_outIndexIR.drop () ; // Release error dropped variable
    }else if (kBoolFalse == test_2) {
      outArgument_outIndexIR = GALGAS_objectIR::constructor_literalInteger (constinArgument_inElementType, var_indexValue_1558  COMMA_SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 44)) ;
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_4 = extensionGetter_type (var_indexResult_1326, inCompiler COMMA_SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 46)).getter_kind (HERE).getter_isInteger (SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 46)).boolEnum () ;
    if (kBoolTrue == test_4) {
      const enumGalgasBool test_5 = GALGAS_bool (gOption_plm_5F_options_noPanicGeneration.getter_value ()).operator_not (SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 47)).boolEnum () ;
      if (kBoolTrue == test_5) {
        GALGAS_bool var_generatePanicInstruction_2092 ;
        {
        extensionSetter_testArrayIndex (ioArgument_ioInstructionGenerationList, var_indexResult_1326, constinArgument_inErrorLocation, constinArgument_inArraySize, var_generatePanicInstruction_2092, inCompiler COMMA_SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 48)) ;
        }
        GALGAS_bool test_6 = var_generatePanicInstruction_2092 ;
        if (kBoolTrue == test_6.boolEnum ()) {
          test_6 = constinArgument_inRoutineAttributes.getter_panicAllowed (SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 54)).operator_not (SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 54)) ;
        }
        const enumGalgasBool test_7 = test_6.boolEnum () ;
        if (kBoolTrue == test_7) {
          TC_Array <C_FixItDescription> fixItArray8 ;
          inCompiler->emitSemanticError (constinArgument_inErrorLocation, GALGAS_string ("index computation can generate panic"), fixItArray8  COMMA_SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 55)) ;
        }
      }
      outArgument_outIndexIR = var_indexResult_1326 ;
    }else if (kBoolFalse == test_4) {
      TC_Array <C_FixItDescription> fixItArray9 ;
      inCompiler->emitSemanticError (constinArgument_inErrorLocation, GALGAS_string ("index expression is not an integer"), fixItArray9  COMMA_SOURCE_FILE ("subscript-in-assignment-and-expression.galgas", 60)) ;
      outArgument_outIndexIR.drop () ; // Release error dropped variable
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          Routine 'analyzeVariableInLValue'                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_analyzeVariableInLValue (const GALGAS_PLMType constinArgument_inSelfType,
                                      const GALGAS_bool constinArgument_inIsReadAccess,
                                      const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                      const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                      const GALGAS_semanticContext constinArgument_inContext,
                                      const GALGAS_mode constinArgument_inMode,
                                      GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                      GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                      GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                      GALGAS_allocaList & ioArgument_ioAllocaList,
                                      GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                      const GALGAS_lstring constinArgument_inVariableName,
                                      const GALGAS_string constinArgument_inLLVMName,
                                      const GALGAS_PLMType constinArgument_inVariableType,
                                      const GALGAS_accessInAssignmentListAST constinArgument_inAccessList,
                                      GALGAS_LValueRepresentation & outArgument_outInternalRepresentation,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outInternalRepresentation.drop () ; // Release 'out' argument
  GALGAS_PLMType var_currentType_7798 = constinArgument_inVariableType ;
  GALGAS_string var_currentLLVMName_7837 = constinArgument_inLLVMName ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_inAccessList.getter_length (SOURCE_FILE ("lvalue.galgas", 193)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = constinArgument_inIsReadAccess.boolEnum () ;
    if (kBoolTrue == test_1) {
      {
      GALGAS_objectIR joker_7988 ; // Joker input parameter
      extensionSetter_searchValuedObjectForReadAccess (ioArgument_ioUniversalMap, constinArgument_inVariableName, joker_7988, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 195)) ;
      }
    }else if (kBoolFalse == test_1) {
      {
      GALGAS_objectIR joker_8074 ; // Joker input parameter
      extensionSetter_searchValuedObjectForWriteAccess (ioArgument_ioUniversalMap, constinArgument_inVariableName, joker_8074, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 197)) ;
      }
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = constinArgument_inIsReadAccess.boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      GALGAS_objectIR joker_8192 ; // Joker input parameter
      extensionSetter_searchValuedObjectForReadAccess (ioArgument_ioUniversalMap, constinArgument_inVariableName, joker_8192, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 201)) ;
      }
    }else if (kBoolFalse == test_2) {
      {
      GALGAS_objectIR joker_8282 ; // Joker input parameter
      extensionSetter_searchValuedObjectForReadWriteAccess (ioArgument_ioUniversalMap, constinArgument_inVariableName, joker_8282, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 203)) ;
      }
    }
    cEnumerator_accessInAssignmentListAST enumerator_8325 (constinArgument_inAccessList, kENUMERATION_UP) ;
    while (enumerator_8325.hasCurrentObject ()) {
      switch (enumerator_8325.current_mAccess (HERE).enumValue ()) {
      case GALGAS_accessInAssignmentAST::kNotBuilt:
        break ;
      case GALGAS_accessInAssignmentAST::kEnum_property:
        {
          const cEnumAssociatedValues_accessInAssignmentAST_property * extractPtr_9406 = (const cEnumAssociatedValues_accessInAssignmentAST_property *) (enumerator_8325.current_mAccess (HERE).unsafePointer ()) ;
          const GALGAS_lstring extractedValue_propertyName = extractPtr_9406->mAssociatedValue0 ;
          GALGAS_propertyMap var_propertyMap_8431 = var_currentType_7798.getter_propertyMap (HERE) ;
          GALGAS_propertyAccessKind var_propertyAccess_8545 ;
          GALGAS_bool joker_8504 ; // Joker input parameter
          var_propertyMap_8431.method_searchKey (extractedValue_propertyName, joker_8504, var_propertyAccess_8545, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 209)) ;
          switch (var_propertyAccess_8545.enumValue ()) {
          case GALGAS_propertyAccessKind::kNotBuilt:
            break ;
          case GALGAS_propertyAccessKind::kEnum_nonVirtualMethod:
            {
              TC_Array <C_FixItDescription> fixItArray3 ;
              inCompiler->emitSemanticError (extractedValue_propertyName.getter_location (SOURCE_FILE ("lvalue.galgas", 212)), GALGAS_string ("a method cannot be written"), fixItArray3  COMMA_SOURCE_FILE ("lvalue.galgas", 212)) ;
              var_currentType_7798.drop () ; // Release error dropped variable
              var_currentLLVMName_7837.drop () ; // Release error dropped variable
            }
            break ;
          case GALGAS_propertyAccessKind::kEnum_singleton:
            {
              const cEnumAssociatedValues_propertyAccessKind_singleton * extractPtr_8835 = (const cEnumAssociatedValues_propertyAccessKind_singleton *) (var_propertyAccess_8545.unsafePointer ()) ;
              const GALGAS_objectIR extractedValue_object = extractPtr_8835->mAssociatedValue0 ;
              var_currentType_7798 = extensionGetter_type (extractedValue_object, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 214)) ;
              var_currentLLVMName_7837 = extensionGetter_llvmName (extractedValue_object, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 215)) ;
            }
            break ;
          case GALGAS_propertyAccessKind::kEnum_constantProperty:
            {
              TC_Array <C_FixItDescription> fixItArray4 ;
              inCompiler->emitSemanticError (extractedValue_propertyName.getter_location (SOURCE_FILE ("lvalue.galgas", 217)), GALGAS_string ("a constant property cannot be written"), fixItArray4  COMMA_SOURCE_FILE ("lvalue.galgas", 217)) ;
              var_currentType_7798.drop () ; // Release error dropped variable
              var_currentLLVMName_7837.drop () ; // Release error dropped variable
            }
            break ;
          case GALGAS_propertyAccessKind::kEnum_indexed:
            {
              const cEnumAssociatedValues_propertyAccessKind_indexed * extractPtr_9394 = (const cEnumAssociatedValues_propertyAccessKind_indexed *) (var_propertyAccess_8545.unsafePointer ()) ;
              const GALGAS_PLMType extractedValue_propertyType = extractPtr_9394->mAssociatedValue0 ;
              const GALGAS_uint extractedValue_index = extractPtr_9394->mAssociatedValue1 ;
              GALGAS_string var_newLLVMvariable_9095 ;
              {
              extensionSetter_newTempLLVMVar (ioArgument_ioTemporaries, var_newLLVMvariable_9095, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 219)) ;
              }
              {
              extensionSetter_appendGetUniversalPropertyReference (ioArgument_ioInstructionGenerationList, var_currentType_7798, var_currentLLVMName_7837, var_newLLVMvariable_9095, extractedValue_index, extractedValue_propertyName.getter_string (SOURCE_FILE ("lvalue.galgas", 225)), inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 220)) ;
              }
              var_currentType_7798 = extractedValue_propertyType ;
              var_currentLLVMName_7837 = var_newLLVMvariable_9095 ;
            }
            break ;
          }
        }
        break ;
      case GALGAS_accessInAssignmentAST::kEnum_arrayAccess:
        {
          const cEnumAssociatedValues_accessInAssignmentAST_arrayAccess * extractPtr_10727 = (const cEnumAssociatedValues_accessInAssignmentAST_arrayAccess *) (enumerator_8325.current_mAccess (HERE).unsafePointer ()) ;
          const GALGAS_expressionAST extractedValue_indexExpression = extractPtr_10727->mAssociatedValue0 ;
          const GALGAS_location extractedValue_endOfIndex = extractPtr_10727->mAssociatedValue1 ;
          const enumGalgasBool test_5 = var_currentType_7798.getter_kind (HERE).getter_isArrayType (SOURCE_FILE ("lvalue.galgas", 231)).boolEnum () ;
          if (kBoolTrue == test_5) {
            GALGAS_PLMType var_elementType_9599 ;
            GALGAS_bigint var_arraySize_9627 ;
            var_currentType_7798.getter_kind (HERE).method_arrayType (var_elementType_9599, var_arraySize_9627, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 232)) ;
            GALGAS_objectIR var_indexIR_10242 ;
            {
            routine_handleArraySubscriptNew (constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, extractedValue_indexExpression, extractedValue_endOfIndex, var_arraySize_9627, var_elementType_9599, ioArgument_ioInstructionGenerationList, var_indexIR_10242, inCompiler  COMMA_SOURCE_FILE ("lvalue.galgas", 233)) ;
            }
            GALGAS_string var_newLLVMvariable_10315 ;
            {
            extensionSetter_newTempLLVMVar (ioArgument_ioTemporaries, var_newLLVMvariable_10315, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 250)) ;
            }
            {
            extensionSetter_appendGetUniversalArrayElementReference (ioArgument_ioInstructionGenerationList, var_currentType_7798, var_currentLLVMName_7837, var_elementType_9599, var_newLLVMvariable_10315, var_indexIR_10242, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 251)) ;
            }
            var_currentType_7798 = var_elementType_9599 ;
            var_currentLLVMName_7837 = var_newLLVMvariable_10315 ;
          }else if (kBoolFalse == test_5) {
            TC_Array <C_FixItDescription> fixItArray6 ;
            inCompiler->emitSemanticError (extractedValue_endOfIndex, GALGAS_string ("cannot subscript, not an array"), fixItArray6  COMMA_SOURCE_FILE ("lvalue.galgas", 261)) ;
            var_currentType_7798.drop () ; // Release error dropped variable
            var_currentLLVMName_7837.drop () ; // Release error dropped variable
          }
        }
        break ;
      }
      enumerator_8325.gotoNextObject () ;
    }
  }
  outArgument_outInternalRepresentation = GALGAS_LValueRepresentation::constructor_new (var_currentType_7798, var_currentLLVMName_7837  COMMA_SOURCE_FILE ("lvalue.galgas", 266)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                        Routine 'analyzeSelfAssignmentTarget'                                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_analyzeSelfAssignmentTarget (const GALGAS_PLMType constinArgument_inSelfType,
                                          const GALGAS_routineAttributes constinArgument_inRoutineAttributes,
                                          const GALGAS_lstring constinArgument_inCallerNameForInvocationGraph,
                                          const GALGAS_semanticContext constinArgument_inContext,
                                          const GALGAS_mode constinArgument_inMode,
                                          GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                          GALGAS_staticEntityMap & ioArgument_ioStaticEntityMap,
                                          GALGAS_universalValuedObjectMap & ioArgument_ioUniversalMap,
                                          GALGAS_allocaList & ioArgument_ioAllocaList,
                                          GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                          const GALGAS_location constinArgument_inSelfLocation,
                                          const GALGAS_accessInAssignmentListAST constinArgument_inAccessList,
                                          GALGAS_LValueRepresentation & outArgument_outInternalRepresentation,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outInternalRepresentation.drop () ; // Release 'out' argument
  GALGAS_bool test_0 = constinArgument_inSelfType.getter_kind (HERE).getter_isStructure (SOURCE_FILE ("lvalue.galgas", 286)) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    test_0 = constinArgument_inSelfType.getter_kind (HERE).getter_isSyncTool (SOURCE_FILE ("lvalue.galgas", 286)) ;
  }
  const enumGalgasBool test_1 = test_0.operator_not (SOURCE_FILE ("lvalue.galgas", 286)).boolEnum () ;
  if (kBoolTrue == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_inSelfLocation, GALGAS_string ("'self' is not available in this context"), fixItArray2  COMMA_SOURCE_FILE ("lvalue.galgas", 287)) ;
    outArgument_outInternalRepresentation.drop () ; // Release error dropped variable
  }else if (kBoolFalse == test_1) {
    GALGAS_PLMType var_currentType_11831 = constinArgument_inSelfType ;
    GALGAS_string var_currentLLVMName_11868 = function_llvmNameForSelf (inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 290)) ;
    cEnumerator_accessInAssignmentListAST enumerator_11922 (constinArgument_inAccessList, kENUMERATION_UP) ;
    while (enumerator_11922.hasCurrentObject ()) {
      switch (enumerator_11922.current_mAccess (HERE).enumValue ()) {
      case GALGAS_accessInAssignmentAST::kNotBuilt:
        break ;
      case GALGAS_accessInAssignmentAST::kEnum_property:
        {
          const cEnumAssociatedValues_accessInAssignmentAST_property * extractPtr_13003 = (const cEnumAssociatedValues_accessInAssignmentAST_property *) (enumerator_11922.current_mAccess (HERE).unsafePointer ()) ;
          const GALGAS_lstring extractedValue_propertyName = extractPtr_13003->mAssociatedValue0 ;
          GALGAS_propertyMap var_propertyMap_12028 = var_currentType_11831.getter_propertyMap (HERE) ;
          GALGAS_propertyAccessKind var_propertyAccess_12142 ;
          GALGAS_bool joker_12101 ; // Joker input parameter
          var_propertyMap_12028.method_searchKey (extractedValue_propertyName, joker_12101, var_propertyAccess_12142, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 295)) ;
          switch (var_propertyAccess_12142.enumValue ()) {
          case GALGAS_propertyAccessKind::kNotBuilt:
            break ;
          case GALGAS_propertyAccessKind::kEnum_nonVirtualMethod:
            {
              TC_Array <C_FixItDescription> fixItArray3 ;
              inCompiler->emitSemanticError (extractedValue_propertyName.getter_location (SOURCE_FILE ("lvalue.galgas", 298)), GALGAS_string ("a method cannot be written"), fixItArray3  COMMA_SOURCE_FILE ("lvalue.galgas", 298)) ;
              var_currentType_11831.drop () ; // Release error dropped variable
              var_currentLLVMName_11868.drop () ; // Release error dropped variable
            }
            break ;
          case GALGAS_propertyAccessKind::kEnum_constantProperty:
            {
              TC_Array <C_FixItDescription> fixItArray4 ;
              inCompiler->emitSemanticError (extractedValue_propertyName.getter_location (SOURCE_FILE ("lvalue.galgas", 300)), GALGAS_string ("a constant property cannot be written"), fixItArray4  COMMA_SOURCE_FILE ("lvalue.galgas", 300)) ;
              var_currentType_11831.drop () ; // Release error dropped variable
              var_currentLLVMName_11868.drop () ; // Release error dropped variable
            }
            break ;
          case GALGAS_propertyAccessKind::kEnum_singleton:
            {
              const cEnumAssociatedValues_propertyAccessKind_singleton * extractPtr_12570 = (const cEnumAssociatedValues_propertyAccessKind_singleton *) (var_propertyAccess_12142.unsafePointer ()) ;
              const GALGAS_objectIR extractedValue_object = extractPtr_12570->mAssociatedValue0 ;
              var_currentType_11831 = extensionGetter_type (extractedValue_object, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 302)) ;
              var_currentLLVMName_11868 = extensionGetter_llvmName (extractedValue_object, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 303)) ;
            }
            break ;
          case GALGAS_propertyAccessKind::kEnum_indexed:
            {
              const cEnumAssociatedValues_propertyAccessKind_indexed * extractPtr_12991 = (const cEnumAssociatedValues_propertyAccessKind_indexed *) (var_propertyAccess_12142.unsafePointer ()) ;
              const GALGAS_PLMType extractedValue_propertyType = extractPtr_12991->mAssociatedValue0 ;
              const GALGAS_uint extractedValue_index = extractPtr_12991->mAssociatedValue1 ;
              GALGAS_string var_newLLVMvariable_12692 ;
              {
              extensionSetter_newTempLLVMVar (ioArgument_ioTemporaries, var_newLLVMvariable_12692, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 305)) ;
              }
              {
              extensionSetter_appendGetUniversalPropertyReference (ioArgument_ioInstructionGenerationList, var_currentType_11831, var_currentLLVMName_11868, var_newLLVMvariable_12692, extractedValue_index, extractedValue_propertyName.getter_string (SOURCE_FILE ("lvalue.galgas", 311)), inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 306)) ;
              }
              var_currentType_11831 = extractedValue_propertyType ;
              var_currentLLVMName_11868 = var_newLLVMvariable_12692 ;
            }
            break ;
          }
        }
        break ;
      case GALGAS_accessInAssignmentAST::kEnum_arrayAccess:
        {
          const cEnumAssociatedValues_accessInAssignmentAST_arrayAccess * extractPtr_14324 = (const cEnumAssociatedValues_accessInAssignmentAST_arrayAccess *) (enumerator_11922.current_mAccess (HERE).unsafePointer ()) ;
          const GALGAS_expressionAST extractedValue_indexExpression = extractPtr_14324->mAssociatedValue0 ;
          const GALGAS_location extractedValue_endOfIndex = extractPtr_14324->mAssociatedValue1 ;
          const enumGalgasBool test_5 = var_currentType_11831.getter_kind (HERE).getter_isArrayType (SOURCE_FILE ("lvalue.galgas", 317)).boolEnum () ;
          if (kBoolTrue == test_5) {
            GALGAS_PLMType var_elementType_13196 ;
            GALGAS_bigint var_arraySize_13224 ;
            var_currentType_11831.getter_kind (HERE).method_arrayType (var_elementType_13196, var_arraySize_13224, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 318)) ;
            GALGAS_objectIR var_indexIR_13839 ;
            {
            routine_handleArraySubscriptNew (constinArgument_inSelfType, constinArgument_inRoutineAttributes, constinArgument_inCallerNameForInvocationGraph, constinArgument_inContext, constinArgument_inMode, ioArgument_ioTemporaries, ioArgument_ioStaticEntityMap, ioArgument_ioUniversalMap, ioArgument_ioAllocaList, extractedValue_indexExpression, extractedValue_endOfIndex, var_arraySize_13224, var_elementType_13196, ioArgument_ioInstructionGenerationList, var_indexIR_13839, inCompiler  COMMA_SOURCE_FILE ("lvalue.galgas", 319)) ;
            }
            GALGAS_string var_newLLVMvariable_13912 ;
            {
            extensionSetter_newTempLLVMVar (ioArgument_ioTemporaries, var_newLLVMvariable_13912, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 336)) ;
            }
            {
            extensionSetter_appendGetUniversalArrayElementReference (ioArgument_ioInstructionGenerationList, var_currentType_11831, var_currentLLVMName_11868, var_elementType_13196, var_newLLVMvariable_13912, var_indexIR_13839, inCompiler COMMA_SOURCE_FILE ("lvalue.galgas", 337)) ;
            }
            var_currentType_11831 = var_elementType_13196 ;
            var_currentLLVMName_11868 = var_newLLVMvariable_13912 ;
          }else if (kBoolFalse == test_5) {
            TC_Array <C_FixItDescription> fixItArray6 ;
            inCompiler->emitSemanticError (extractedValue_endOfIndex, GALGAS_string ("cannot subscript, not an array"), fixItArray6  COMMA_SOURCE_FILE ("lvalue.galgas", 347)) ;
            var_currentType_11831.drop () ; // Release error dropped variable
            var_currentLLVMName_11868.drop () ; // Release error dropped variable
          }
        }
        break ;
      }
      enumerator_11922.gotoNextObject () ;
    }
    outArgument_outInternalRepresentation = GALGAS_LValueRepresentation::constructor_new (var_currentType_11831, var_currentLLVMName_11868  COMMA_SOURCE_FILE ("lvalue.galgas", 351)) ;
  }
}


