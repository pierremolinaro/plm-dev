#ifndef all_2D_declarations_2D__39__ENTITIES_DEFINED
#define all_2D_declarations_2D__39__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "all-predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-8.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension method '@infixOperatorMap checkBinaryOperationWith'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_checkBinaryOperationWith (const class GALGAS_infixOperatorMap inObject,
                                               const class GALGAS_unifiedTypeMap_2D_proxy constin_inLeftType,
                                               const class GALGAS_unifiedTypeMap_2D_proxy constin_inRightType,
                                               const class GALGAS_location constin_inOperatorLocation,
                                               class GALGAS_unifiedTypeMap_2D_proxy & out_outResultType,
                                               class GALGAS_infixOperatorDescription & out_outOperation,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   Abstract extension method '@infixOperatorDescription generateInfixOperatorCode'                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_infixOperatorDescription_generateInfixOperatorCode) (const class cPtr_infixOperatorDescription * inObject,
                                                                                             class GALGAS_semanticTemporariesStruct & ioArgument0,
                                                                                             class GALGAS_instructionListIR & ioArgument1,
                                                                                             const class GALGAS_objectIR constinArgument2,
                                                                                             const class GALGAS_location constinArgument3,
                                                                                             const class GALGAS_objectIR constinArgument4,
                                                                                             const class GALGAS_unifiedTypeMap_2D_proxy constinArgument5,
                                                                                             class GALGAS_objectIR & outArgument6,
                                                                                             class C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_generateInfixOperatorCode (const int32_t inClassIndex,
                                                     extensionMethodSignature_infixOperatorDescription_generateInfixOperatorCode inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_generateInfixOperatorCode (const class cPtr_infixOperatorDescription * inObject,
                                                    GALGAS_semanticTemporariesStruct & io_ioTemporaries,
                                                    GALGAS_instructionListIR & io_ioInstructionGenerationList,
                                                    const GALGAS_objectIR constin_inLeftOperand,
                                                    const GALGAS_location constin_inOperatorLocation,
                                                    const GALGAS_objectIR constin_inRightOperand,
                                                    const GALGAS_unifiedTypeMap_2D_proxy constin_inResultType,
                                                    GALGAS_objectIR & out_outResultValue,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Extension getter '@infixOperatorDescription performStaticOperation'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bigint (*enterExtensionGetter_infixOperatorDescription_performStaticOperation) (const class cPtr_infixOperatorDescription * inObject,
                                                                                                     const class GALGAS_bigint & constinArgument0,
                                                                                                     const class GALGAS_bigint & constinArgument1,
                                                                                                     C_Compiler * inCompiler
                                                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_performStaticOperation (const int32_t inClassIndex,
                                                  enterExtensionGetter_infixOperatorDescription_performStaticOperation inGetter) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bigint callExtensionGetter_performStaticOperation (const cPtr_infixOperatorDescription * inObject,
                                                                const GALGAS_bigint & constin_inLeft,
                                                                const GALGAS_bigint & constin_inRight,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    Extension method '@assignmentTargetAST noteInstructionTypesInPrecedenceGraph'                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_noteInstructionTypesInPrecedenceGraph (const class GALGAS_assignmentTargetAST inObject,
                                                            class GALGAS_semanticTypePrecedenceGraph & io_ioGraph,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Extension method '@assignmentTargetAST analyzeAssignmentTarget'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_analyzeAssignmentTarget (const class GALGAS_assignmentTargetAST inObject,
                                              const class GALGAS_unifiedTypeMap_2D_proxy constin_inSelfType,
                                              const class GALGAS_targetAccessKind constin_inSelfAccessKind,
                                              const class GALGAS_bool constin_inRoutineCanMutateProperties,
                                              const class GALGAS_bool constin_inDirectAccessToPropertiesAllowed,
                                              const class GALGAS_lstring constin_inCallerNameForInvocationGraph,
                                              const class GALGAS_semanticContext constin_inContext,
                                              const class GALGAS_stringset constin_inModeSet,
                                              const class GALGAS_bool constin_inAllowPanic,
                                              class GALGAS_semanticTemporariesStruct & io_ioTemporaries,
                                              class GALGAS_staticStringMap & io_ioGlobalLiteralStringMap,
                                              class GALGAS_variableMap & io_ioVariableMap,
                                              class GALGAS_allocaList & io_ioAllocaList,
                                              class GALGAS_instructionListIR & io_ioInstructionGenerationList,
                                              class GALGAS_objectIR & out_outCurrentObject,
                                              class GALGAS_string & out_outGlobalVariableReceiverName,
                                              class C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension getter '@objectIR isGlobalVariable' (as function)                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool extensionGetter_isGlobalVariable (const class GALGAS_objectIR & inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Extension method '@binaryOperationIR enterCodeForOverflowOperation'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_binaryOperationIR_enterCodeForOverflowOperation) (const class cPtr_binaryOperationIR * inObject,
                                                                                          const class GALGAS_string constinArgument0,
                                                                                          const class GALGAS_bigint constinArgument1,
                                                                                          class GALGAS_string & ioArgument2,
                                                                                          const class GALGAS_generationContext constinArgument3,
                                                                                          class GALGAS_generationAdds & ioArgument4,
                                                                                          class C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_enterCodeForOverflowOperation (const int32_t inClassIndex,
                                                         extensionMethodSignature_binaryOperationIR_enterCodeForOverflowOperation inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_enterCodeForOverflowOperation (const class cPtr_binaryOperationIR * inObject,
                                                        const GALGAS_string constin_inOperation,
                                                        const GALGAS_bigint constin_inPanicCode,
                                                        GALGAS_string & io_ioLLVMcode,
                                                        const GALGAS_generationContext constin_inGenerationContext,
                                                        GALGAS_generationAdds & io_ioGenerationAdds,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   Extension method '@binaryOperationIR enterCodeForDivisionWithZeroDivisorPanic'                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*extensionMethodSignature_binaryOperationIR_enterCodeForDivisionWithZeroDivisorPanic) (const class cPtr_binaryOperationIR * inObject,
                                                                                                     const class GALGAS_string constinArgument0,
                                                                                                     const class GALGAS_bigint constinArgument1,
                                                                                                     class GALGAS_string & ioArgument2,
                                                                                                     const class GALGAS_generationContext constinArgument3,
                                                                                                     class GALGAS_generationAdds & ioArgument4,
                                                                                                     class C_Compiler * inCompiler
                                                                                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_enterCodeForDivisionWithZeroDivisorPanic (const int32_t inClassIndex,
                                                                    extensionMethodSignature_binaryOperationIR_enterCodeForDivisionWithZeroDivisorPanic inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_enterCodeForDivisionWithZeroDivisorPanic (const class cPtr_binaryOperationIR * inObject,
                                                                   const GALGAS_string constin_inOperation,
                                                                   const GALGAS_bigint constin_inPanicCode,
                                                                   GALGAS_string & io_ioLLVMcode,
                                                                   const GALGAS_generationContext constin_inGenerationContext,
                                                                   GALGAS_generationAdds & io_ioGenerationAdds,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

#endif
