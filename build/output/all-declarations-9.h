#ifndef all_2D_declarations_2D__39__ENTITIES_DEFINED
#define all_2D_declarations_2D__39__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "all-predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-8.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Routine 'handleArrayAccessInExpression'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_handleArrayAccessInExpression (class GALGAS_internalRepresentation & ioArgument0,
                                            const class GALGAS_expressionAST constinArgument1,
                                            const class GALGAS_location constinArgument2,
                                            const class GALGAS_PLMType constinArgument3,
                                            const class GALGAS_bool constinArgument4,
                                            const class GALGAS_lstring constinArgument5,
                                            const class GALGAS_PLMType constinArgument6,
                                            const class GALGAS_semanticContext constinArgument7,
                                            const class GALGAS_mode constinArgument8,
                                            class GALGAS_semanticTemporariesStruct & ioArgument9,
                                            class GALGAS_staticStringMap & ioArgument10,
                                            class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument11,
                                            class GALGAS_allocaList & ioArgument12,
                                            class GALGAS_instructionListIR & ioArgument13,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Routine 'handleFunctionCallInExpressionNew'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_handleFunctionCallInExpressionNew (class GALGAS_internalRepresentation & ioArgument0,
                                                const class GALGAS_PLMType constinArgument1,
                                                const class GALGAS_bool constinArgument2,
                                                const class GALGAS_lstring constinArgument3,
                                                const class GALGAS_semanticContext constinArgument4,
                                                const class GALGAS_mode constinArgument5,
                                                class GALGAS_semanticTemporariesStruct & ioArgument6,
                                                class GALGAS_staticStringMap & ioArgument7,
                                                class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument8,
                                                class GALGAS_allocaList & ioArgument9,
                                                const class GALGAS_effectiveArgumentListAST constinArgument10,
                                                const class GALGAS_location constinArgument11,
                                                class GALGAS_instructionListIR & ioArgument12,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Routine 'handlePropertyAccessInExpression'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_handlePropertyAccessInExpression (class GALGAS_internalRepresentation & ioArgument0,
                                               const class GALGAS_lstring constinArgument1,
                                               const class GALGAS_lstring constinArgument2,
                                               const class GALGAS_PLMType constinArgument3,
                                               const class GALGAS_semanticContext constinArgument4,
                                               const class GALGAS_mode constinArgument5,
                                               class GALGAS_semanticTemporariesStruct & ioArgument6,
                                               class GALGAS_staticStringMap & ioArgument7,
                                               class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument8,
                                               class GALGAS_allocaList & ioArgument9,
                                               class GALGAS_instructionListIR & ioArgument10,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Routine 'handleSubscriptArrayInAssignmentAndExpressionNew'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_handleSubscriptArrayInAssignmentAndExpressionNew (const class GALGAS_PLMType constinArgument0,
                                                               const class GALGAS_bool constinArgument1,
                                                               const class GALGAS_lstring constinArgument2,
                                                               const class GALGAS_semanticContext constinArgument3,
                                                               const class GALGAS_mode constinArgument4,
                                                               class GALGAS_semanticTemporariesStruct & ioArgument5,
                                                               class GALGAS_staticStringMap & ioArgument6,
                                                               class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument7,
                                                               class GALGAS_allocaList & ioArgument8,
                                                               const class GALGAS_expressionAST constinArgument9,
                                                               const class GALGAS_location constinArgument10,
                                                               class GALGAS_instructionListIR & ioArgument11,
                                                               class GALGAS_objectIR & ioArgument12,
                                                               class C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Routine 'handleSubscriptRegisterArrayInAssignmentAndExpressionNew'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_handleSubscriptRegisterArrayInAssignmentAndExpressionNew (const class GALGAS_PLMType constinArgument0,
                                                                       const class GALGAS_bool constinArgument1,
                                                                       const class GALGAS_lstring constinArgument2,
                                                                       const class GALGAS_semanticContext constinArgument3,
                                                                       const class GALGAS_mode constinArgument4,
                                                                       class GALGAS_semanticTemporariesStruct & ioArgument5,
                                                                       class GALGAS_staticStringMap & ioArgument6,
                                                                       class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument7,
                                                                       class GALGAS_allocaList & ioArgument8,
                                                                       const class GALGAS_expressionAST constinArgument9,
                                                                       const class GALGAS_location constinArgument10,
                                                                       class GALGAS_instructionListIR & ioArgument11,
                                                                       class GALGAS_objectIR & ioArgument12,
                                                                       class GALGAS_sliceMap & outArgument13,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Routine 'handleMethodCallInExpressionNew'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_handleMethodCallInExpressionNew (const class GALGAS_lstring constinArgument0,
                                              const class GALGAS_objectIR constinArgument1,
                                              const class GALGAS_PLMType constinArgument2,
                                              const class GALGAS_lstring constinArgument3,
                                              const class GALGAS_semanticContext constinArgument4,
                                              const class GALGAS_mode constinArgument5,
                                              class GALGAS_semanticTemporariesStruct & ioArgument6,
                                              class GALGAS_staticStringMap & ioArgument7,
                                              class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument8,
                                              class GALGAS_allocaList & ioArgument9,
                                              const class GALGAS_effectiveArgumentListAST constinArgument10,
                                              class GALGAS_instructionListIR & ioArgument11,
                                              class GALGAS_objectIR & outArgument12,
                                              class C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Routine 'handleStandAloneFunctionCallInExpression'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_handleStandAloneFunctionCallInExpression (class GALGAS_internalRepresentation & ioArgument0,
                                                       const class GALGAS_lstring constinArgument1,
                                                       const class GALGAS_PLMType constinArgument2,
                                                       const class GALGAS_bool constinArgument3,
                                                       const class GALGAS_lstring constinArgument4,
                                                       const class GALGAS_semanticContext constinArgument5,
                                                       const class GALGAS_mode constinArgument6,
                                                       class GALGAS_semanticTemporariesStruct & ioArgument7,
                                                       class GALGAS_staticStringMap & ioArgument8,
                                                       class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument9,
                                                       class GALGAS_allocaList & ioArgument10,
                                                       const class GALGAS_effectiveArgumentListAST constinArgument11,
                                                       const class GALGAS_location constinArgument12,
                                                       class GALGAS_instructionListIR & ioArgument13,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Function 'routineMangledNameFromCall'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring function_routineMangledNameFromCall (const class GALGAS_string & constinArgument0,
                                                          const class GALGAS_lstring & constinArgument1,
                                                          const class GALGAS_effectiveArgumentListAST & constinArgument2,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Routine 'analyzeEffectiveParametersNew'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_analyzeEffectiveParametersNew (const class GALGAS_PLMType constinArgument0,
                                            const class GALGAS_routineTypedSignature constinArgument1,
                                            const class GALGAS_effectiveArgumentListAST constinArgument2,
                                            const class GALGAS_location constinArgument3,
                                            const class GALGAS_lstring constinArgument4,
                                            const class GALGAS_semanticContext constinArgument5,
                                            const class GALGAS_mode constinArgument6,
                                            class GALGAS_semanticTemporariesStruct & ioArgument7,
                                            class GALGAS_staticStringMap & ioArgument8,
                                            class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument9,
                                            class GALGAS_allocaList & ioArgument10,
                                            class GALGAS_instructionListIR & ioArgument11,
                                            class GALGAS_procCallEffectiveParameterListIR & ioArgument12,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Routine 'handleFunctionCallInExpression'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_handleFunctionCallInExpression (const class GALGAS_PLMType constinArgument0,
                                             const class GALGAS_string constinArgument1,
                                             const class GALGAS_bool constinArgument2,
                                             const class GALGAS_bool constinArgument3,
                                             const class GALGAS_bool constinArgument4,
                                             const class GALGAS_lstring constinArgument5,
                                             const class GALGAS_semanticContext constinArgument6,
                                             const class GALGAS_mode constinArgument7,
                                             class GALGAS_semanticTemporariesStruct & ioArgument8,
                                             class GALGAS_staticStringMap & ioArgument9,
                                             class GALGAS_unifiedSymbolMapEx & ioArgument10,
                                             class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument11,
                                             class GALGAS_allocaList & ioArgument12,
                                             const class GALGAS_effectiveArgumentListAST constinArgument13,
                                             const class GALGAS_location constinArgument14,
                                             class GALGAS_instructionListIR & ioArgument15,
                                             class GALGAS_objectIR & ioArgument16,
                                             class GALGAS_PLMType & outArgument17,
                                             class C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'analyzeEffectiveParameters'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_analyzeEffectiveParameters (const class GALGAS_PLMType constinArgument0,
                                         const class GALGAS_bool constinArgument1,
                                         const class GALGAS_bool constinArgument2,
                                         const class GALGAS_routineTypedSignature constinArgument3,
                                         const class GALGAS_effectiveArgumentListAST constinArgument4,
                                         const class GALGAS_location constinArgument5,
                                         const class GALGAS_lstring constinArgument6,
                                         const class GALGAS_semanticContext constinArgument7,
                                         const class GALGAS_mode constinArgument8,
                                         class GALGAS_semanticTemporariesStruct & ioArgument9,
                                         class GALGAS_staticStringMap & ioArgument10,
                                         class GALGAS_unifiedSymbolMapEx & ioArgument11,
                                         class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument12,
                                         class GALGAS_allocaList & ioArgument13,
                                         class GALGAS_instructionListIR & ioArgument14,
                                         class GALGAS_procCallEffectiveParameterListIR & ioArgument15,
                                         class C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'analyzeGuardCall'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_analyzeGuardCall (const class GALGAS_PLMType constinArgument0,
                               const class GALGAS_lstring constinArgument1,
                               const class GALGAS_lstring constinArgument2,
                               const class GALGAS_effectiveArgumentListAST constinArgument3,
                               const class GALGAS_lstring constinArgument4,
                               const class GALGAS_semanticContext constinArgument5,
                               const class GALGAS_mode constinArgument6,
                               class GALGAS_semanticTemporariesStruct & ioArgument7,
                               class GALGAS_staticStringMap & ioArgument8,
                               class GALGAS_unifiedSymbolMapEx & ioArgument9,
                               class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument10,
                               class GALGAS_allocaList & ioArgument11,
                               class GALGAS_instructionListIR & ioArgument12,
                               class GALGAS_procCallEffectiveParameterListIR & outArgument13,
                               class GALGAS_lstring & outArgument14,
                               class C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Function 'waitForGuardChangeFunctionName'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_waitForGuardChangeFunctionName (class C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Routine 'handleSubscriptArrayInAssignmentAndExpression'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_handleSubscriptArrayInAssignmentAndExpression (const class GALGAS_PLMType constinArgument0,
                                                            const class GALGAS_bool constinArgument1,
                                                            const class GALGAS_bool constinArgument2,
                                                            const class GALGAS_lstring constinArgument3,
                                                            const class GALGAS_semanticContext constinArgument4,
                                                            const class GALGAS_mode constinArgument5,
                                                            class GALGAS_semanticTemporariesStruct & ioArgument6,
                                                            class GALGAS_staticStringMap & ioArgument7,
                                                            class GALGAS_unifiedSymbolMapEx & ioArgument8,
                                                            class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument9,
                                                            class GALGAS_allocaList & ioArgument10,
                                                            const class GALGAS_expressionAST constinArgument11,
                                                            const class GALGAS_location constinArgument12,
                                                            class GALGAS_instructionListIR & ioArgument13,
                                                            class GALGAS_objectIR & ioArgument14,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Routine 'handleSubscriptRegisterArrayInAssignmentAndExpression'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_handleSubscriptRegisterArrayInAssignmentAndExpression (const class GALGAS_PLMType constinArgument0,
                                                                    const class GALGAS_bool constinArgument1,
                                                                    const class GALGAS_bool constinArgument2,
                                                                    const class GALGAS_lstring constinArgument3,
                                                                    const class GALGAS_semanticContext constinArgument4,
                                                                    const class GALGAS_mode constinArgument5,
                                                                    class GALGAS_semanticTemporariesStruct & ioArgument6,
                                                                    class GALGAS_staticStringMap & ioArgument7,
                                                                    class GALGAS_unifiedSymbolMapEx & ioArgument8,
                                                                    class GALGAS_universalPropertyAndRoutineMapForContext & ioArgument9,
                                                                    class GALGAS_allocaList & ioArgument10,
                                                                    const class GALGAS_expressionAST constinArgument11,
                                                                    const class GALGAS_location constinArgument12,
                                                                    class GALGAS_instructionListIR & ioArgument13,
                                                                    class GALGAS_objectIR & ioArgument14,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'buildOrderedDeclarationList'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_buildOrderedDeclarationList (const class GALGAS_ast constinArgument0,
                                          const class GALGAS_string constinArgument1,
                                          const class GALGAS_location constinArgument2,
                                          class GALGAS_declarationListAST & outArgument3,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'buildSemanticContext'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_buildSemanticContext (const class GALGAS_declarationListAST constinArgument0,
                                   const class GALGAS_lstring constinArgument1,
                                   const class GALGAS_ast constinArgument2,
                                   class GALGAS_staticStringMap & ioArgument3,
                                   class GALGAS_staticlistValues_5F_listMap & ioArgument4,
                                   class GALGAS_semanticContext & outArgument5,
                                   class C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Function 'llvmNameForStaticListType'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_llvmNameForStaticListType (const class GALGAS_string & constinArgument0,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'plmNameForStaticListType'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring function_plmNameForStaticListType (const class GALGAS_lstring & constinArgument0,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'buildTypeMapHTMLFile'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_buildTypeMapHTMLFile (class GALGAS_unifiedTypeMap inArgument0,
                                   const class GALGAS_lstring constinArgument1,
                                   class C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Filewrapper 'typeDumpGenerationTemplate'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*

extern const cDirectoryWrapper gWrapperDirectory_0_typeDumpGenerationTemplate ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Filewrapper template 'typeDumpGenerationTemplate dump'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string filewrapperTemplate_typeDumpGenerationTemplate_dump (class C_Compiler * inCompiler,
                                                                   const class GALGAS_string & in_PROJECT_5F_NAME,
                                                                   const class GALGAS_unifiedTypeMap & in_GLOBAL_5F_TYPE_5F_MAP,
                                                                   const class GALGAS_stringset & in_FIRST_5F_LETTER_5F_SET,
                                                                   const class GALGAS_string & in_TABLE_5F_OF_5F_TYPES_5F_STRING
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'linkForHTMLTypeMap'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_linkForHTMLTypeMap (const class GALGAS_string & constinArgument0,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'semanticAnalysis'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_semanticAnalysis (const class GALGAS_string constinArgument0,
                               const class GALGAS_ast constinArgument1,
                               const class GALGAS_semanticContext constinArgument2,
                               const class GALGAS_location constinArgument3,
                               const class GALGAS_staticStringMap constinArgument4,
                               class GALGAS_intermediateCodeStruct & outArgument5,
                               class C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

#endif
