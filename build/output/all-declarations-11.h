#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-10.h"

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'assignmentOperatorFuncName'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_assignmentOperatorFuncName (const class GALGAS_omnibusType & constinArgument0,
                                                         const class GALGAS_omnibusType & constinArgument1,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'assignValueToFixedSizeArrayElements_functionName'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_assignValueToFixedSizeArrayElements_5F_functionName (const class GALGAS_omnibusType & constinArgument0,
                                                                                  class C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'addIntegerInfixOperator'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_addIntegerInfixOperator (const class GALGAS_omnibusInfixOperator constinArgument0,
                                      const class GALGAS_omnibusType constinArgument1,
                                      const class GALGAS_string constinArgument2,
                                      class GALGAS_infixOperatorMap & ioArgument3,
                                      const class GALGAS_omnibusType constinArgument4,
                                      class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'copyableAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_copyableAttribute (class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'minValueForInteger'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_minValueForInteger (const class GALGAS_bool & constinArgument0,
                                                 const class GALGAS_uint & constinArgument1,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'maxValueForInteger'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_maxValueForInteger (const class GALGAS_bool & constinArgument0,
                                                 const class GALGAS_uint & constinArgument1,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'instantiableAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_instantiableAttribute (class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'registerGroupNameFromOmnibusName'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring function_registerGroupNameFromOmnibusName (const class GALGAS_lstring & constinArgument0,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Filewrapper 'controlRegisterDumpGenerationTemplate'
//
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------

extern const cDirectoryWrapper gWrapperDirectory_0_controlRegisterDumpGenerationTemplate ;

//----------------------------------------------------------------------------------------------------------------------
//
//Filewrapper template 'controlRegisterDumpGenerationTemplate dumpByName'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string filewrapperTemplate_controlRegisterDumpGenerationTemplate_dumpByName (class C_Compiler * inCompiler,
                                                                                    const class GALGAS_string & in_PROJECT_5F_NAME,
                                                                                    const class GALGAS_uint & in_CONTROL_5F_REGISTER_5F_COUNT,
                                                                                    const class GALGAS_controlRegisterByName & in_CONTROL_5F_REGISTER_5F_SORTED_5F_BY_5F_NAME
                                                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Filewrapper template 'controlRegisterDumpGenerationTemplate dumpByAddress'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string filewrapperTemplate_controlRegisterDumpGenerationTemplate_dumpByAddress (class C_Compiler * inCompiler,
                                                                                       const class GALGAS_string & in_PROJECT_5F_NAME,
                                                                                       const class GALGAS_uint & in_CONTROL_5F_REGISTER_5F_COUNT,
                                                                                       const class GALGAS_controlRegisterByAddress & in_CONTROL_5F_REGISTER_5F_SORTED_5F_BY_5F_ADDRESS
                                                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'buildControlRegisterMaps'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_buildControlRegisterMaps (const class GALGAS_controlRegisterMap constinArgument0,
                                       const class GALGAS_bigint constinArgument1,
                                       const class GALGAS_string constinArgument2,
                                       class GALGAS_controlRegisterByAddress & ioArgument3,
                                       class GALGAS_controlRegisterByName & ioArgument4,
                                       class GALGAS_uint & ioArgument5,
                                       class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'arrayIndexListFor'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_uintlist function_arrayIndexListFor (const class GALGAS_uint & constinArgument0,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'fieldIndexColumns'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_fieldIndexColumns (const class GALGAS_uint & constinArgument0,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Filewrapper 'constantDumpGenerationTemplate'
//
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------

extern const cDirectoryWrapper gWrapperDirectory_0_constantDumpGenerationTemplate ;

//----------------------------------------------------------------------------------------------------------------------
//
//Filewrapper template 'constantDumpGenerationTemplate dump'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string filewrapperTemplate_constantDumpGenerationTemplate_dump (class C_Compiler * inCompiler,
                                                                       const class GALGAS_string & in_PROJECT_5F_NAME,
                                                                       const class GALGAS_globalConstantMap & in_GLOBAL_5F_CONSTANT_5F_MAP,
                                                                       const class GALGAS_stringset & in_FIRST_5F_LETTER_5F_SET,
                                                                       const class GALGAS_string & in_TABLE_5F_OF_5F_TYPES_5F_STRING
                                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'linkForGlobalConstant'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_linkForGlobalConstant (const class GALGAS_string & constinArgument0,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'retainRequiredDrivers'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_retainRequiredDrivers (class GALGAS_ast & ioArgument0,
                                    class C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'omnibusNameForStaticListType'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring function_omnibusNameForStaticListType (const class GALGAS_lstring & constinArgument0,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'llvmNameForStaticListType'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring function_llvmNameForStaticListType (const class GALGAS_lstring & constinArgument0,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'omnibusNameForStaticListElementType'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring function_omnibusNameForStaticListElementType (const class GALGAS_lstring & constinArgument0,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'checkModeAndReturnsRoutineLLVMName'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_checkModeAndReturnsRoutineLLVMName (const class GALGAS_routineLLVMNameDict & constinArgument0,
                                                                 const class GALGAS_mode & constinArgument1,
                                                                 const class GALGAS_lstring & constinArgument2,
                                                                 class C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'noUnusedWarningAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_noUnusedWarningAttribute (class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'systemUserMangledNameFromAST'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring function_systemUserMangledNameFromAST (const class GALGAS_string & constinArgument0,
                                                            const class GALGAS_routineKind & constinArgument1,
                                                            const class GALGAS_lstring & constinArgument2,
                                                            const class GALGAS_routineFormalArgumentListAST & constinArgument3,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'systemImplementationMangledNameFromAST'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring function_systemImplementationMangledNameFromAST (const class GALGAS_string & constinArgument0,
                                                                      const class GALGAS_routineKind & constinArgument1,
                                                                      const class GALGAS_lstring & constinArgument2,
                                                                      const class GALGAS_routineFormalArgumentListAST & constinArgument3,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'llvmFunctionPrototype'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_llvmFunctionPrototype (const class GALGAS_string & constinArgument0,
                                                    const class GALGAS_string & constinArgument1,
                                                    const class GALGAS_omnibusType & constinArgument2,
                                                    const class GALGAS_routineFormalArgumentListIR & constinArgument3,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'generateSectionDispatcher'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_generateSectionDispatcher (const class GALGAS_string constinArgument0,
                                        const class GALGAS_string constinArgument1,
                                        const class GALGAS_targetParameters constinArgument2,
                                        class GALGAS_string & ioArgument3,
                                        const class GALGAS_sectionIRlist constinArgument4,
                                        class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'getTargetTextFile'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_getTargetTextFile (const class GALGAS_string & constinArgument0,
                                                const class GALGAS_string & constinArgument1,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'generatePrimitiveAndServiceDispatcher'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_generatePrimitiveAndServiceDispatcher (const class GALGAS_string constinArgument0,
                                                    const class GALGAS_string constinArgument1,
                                                    class GALGAS_string & ioArgument2,
                                                    const class GALGAS_primitiveAndServiceIRlist constinArgument3,
                                                    const class GALGAS_targetParameters constinArgument4,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'routineTypedSignature2'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_routineTypedSignature_32_ (class GALGAS_unifiedTypeMap inArgument0,
                                        const class GALGAS_routineFormalArgumentListAST constinArgument1,
                                        class GALGAS_routineTypedSignature & outArgument2,
                                        class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'guardImplementationLLVMName'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring function_guardImplementationLLVMName (const class GALGAS_string & constinArgument0,
                                                           const class GALGAS_lstring & constinArgument1,
                                                           const class GALGAS_routineFormalArgumentListAST & constinArgument2,
                                                           class C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'guardUserLLVMName'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring function_guardUserLLVMName (const class GALGAS_string & constinArgument0,
                                                 const class GALGAS_lstring & constinArgument1,
                                                 const class GALGAS_routineFormalArgumentListAST & constinArgument2,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

