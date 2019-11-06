#pragma once

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-predefined-types.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-declarations-12.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Routine 'handleArrayAccess'                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_handleArrayAccess (const class GALGAS_omnibusType constinArgument0,
                                class GALGAS_omnibusType & ioArgument1,
                                class GALGAS_string & ioArgument2,
                                const class GALGAS_routineAttributes constinArgument3,
                                const class GALGAS_semanticContext constinArgument4,
                                const class GALGAS_mode constinArgument5,
                                class GALGAS_semanticTemporariesStruct & ioArgument6,
                                class GALGAS_staticEntityMap & ioArgument7,
                                class GALGAS_universalValuedObjectMap & ioArgument8,
                                class GALGAS_allocaList & ioArgument9,
                                class GALGAS_instructionListIR & ioArgument10,
                                const class GALGAS_expressionAST constinArgument11,
                                const class GALGAS_location constinArgument12,
                                const class GALGAS_bool constinArgument13,
                                const class GALGAS_LValueOperandAST constinArgument14,
                                class C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                           Routine 'handlePropertyAccess'                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_handlePropertyAccess (const class GALGAS_omnibusType constinArgument0,
                                   class GALGAS_omnibusType & ioArgument1,
                                   class GALGAS_string & ioArgument2,
                                   const class GALGAS_routineAttributes constinArgument3,
                                   const class GALGAS_semanticContext constinArgument4,
                                   const class GALGAS_mode constinArgument5,
                                   class GALGAS_semanticTemporariesStruct & ioArgument6,
                                   class GALGAS_staticEntityMap & ioArgument7,
                                   class GALGAS_universalValuedObjectMap & ioArgument8,
                                   class GALGAS_allocaList & ioArgument9,
                                   class GALGAS_instructionListIR & ioArgument10,
                                   const class GALGAS_lstring constinArgument11,
                                   const class GALGAS_LValueOperandAST constinArgument12,
                                   class C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Routine 'handleNextOperand'                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_handleNextOperand (const class GALGAS_omnibusType constinArgument0,
                                class GALGAS_omnibusType & ioArgument1,
                                class GALGAS_string & ioArgument2,
                                const class GALGAS_LValueOperandAST constinArgument3,
                                const class GALGAS_routineAttributes constinArgument4,
                                const class GALGAS_semanticContext constinArgument5,
                                const class GALGAS_mode constinArgument6,
                                class GALGAS_semanticTemporariesStruct & ioArgument7,
                                class GALGAS_staticEntityMap & ioArgument8,
                                class GALGAS_universalValuedObjectMap & ioArgument9,
                                class GALGAS_allocaList & ioArgument10,
                                class GALGAS_instructionListIR & ioArgument11,
                                class C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          Function 'memoryAllocSectionName'                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_string function_memoryAllocSectionName (class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          Function 'memoryFreeSectionName'                                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_string function_memoryFreeSectionName (class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Routine 'codeOptimization'                                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_codeOptimization (const class GALGAS_string constinArgument0,
                               class GALGAS_intermediateCodeStruct & ioArgument1,
                               class C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          Routine 'displayInvocationGraph'                                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_displayInvocationGraph (const class GALGAS_routineListIR constinArgument0,
                                     const class GALGAS_string constinArgument1,
                                     class C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Function 'asSeparatorLine'                                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_string function_asSeparatorLine (class C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                              Function 'asTitleComment'                                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_string function_asTitleComment (const class GALGAS_string & constinArgument0,
                                             class C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                              Routine 'codeGeneration'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_codeGeneration (const class GALGAS_string constinArgument0,
                             const class GALGAS_string constinArgument1,
                             const class GALGAS_location constinArgument2,
                             const class GALGAS_intermediateCodeStruct constinArgument3,
                             const class GALGAS_userLLVMTypeDefinitionListIR constinArgument4,
                             const class GALGAS_lstring constinArgument5,
                             const class GALGAS_omnibusType constinArgument6,
                             const class GALGAS_omnibusType constinArgument7,
                             const class GALGAS_availableInterruptMap constinArgument8,
                             const class GALGAS_staticListInitializationMap constinArgument9,
                             const class GALGAS_targetParameters constinArgument10,
                             class C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Routine 'generateCodeFiles'                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_generateCodeFiles (const class GALGAS_string constinArgument0,
                                const class GALGAS_string constinArgument1,
                                const class GALGAS_intermediateCodeStruct constinArgument2,
                                const class GALGAS_userLLVMTypeDefinitionListIR constinArgument3,
                                const class GALGAS_lstring constinArgument4,
                                const class GALGAS_omnibusType constinArgument5,
                                const class GALGAS_omnibusType constinArgument6,
                                const class GALGAS_availableInterruptMap constinArgument7,
                                const class GALGAS_staticListInitializationMap constinArgument8,
                                const class GALGAS_targetParameters constinArgument9,
                                class C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                              Routine 'generateTarget'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_generateTarget (const class GALGAS_string constinArgument0,
                             const class GALGAS_string constinArgument1,
                             const class GALGAS_lstring constinArgument2,
                             const class GALGAS_targetParameters constinArgument3,
                             class C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                            Filewrapper 'targetTemplates'                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const char * gWrapperFileContent_30_targetTemplates ;
extern const char * gWrapperFileContent_4_targetTemplates ;
extern const char * gWrapperFileContent_5_targetTemplates ;
extern const char * gWrapperFileContent_3_targetTemplates ;
extern const char * gWrapperFileContent_10_targetTemplates ;
extern const char * gWrapperFileContent_11_targetTemplates ;
extern const char * gWrapperFileContent_24_targetTemplates ;
extern const char * gWrapperFileContent_32_targetTemplates ;
extern const char * gWrapperFileContent_9_targetTemplates ;
extern const char * gWrapperFileContent_20_targetTemplates ;
extern const char * gWrapperFileContent_21_targetTemplates ;
extern const char * gWrapperFileContent_15_targetTemplates ;
extern const char * gWrapperFileContent_16_targetTemplates ;
extern const char * gWrapperFileContent_8_targetTemplates ;
extern const char * gWrapperFileContent_7_targetTemplates ;
extern const char * gWrapperFileContent_26_targetTemplates ;
extern const char * gWrapperFileContent_35_targetTemplates ;
extern const char * gWrapperFileContent_19_targetTemplates ;
extern const char * gWrapperFileContent_6_targetTemplates ;
extern const char * gWrapperFileContent_14_targetTemplates ;
extern const char * gWrapperFileContent_2_targetTemplates ;
extern const char * gWrapperFileContent_25_targetTemplates ;
extern const char * gWrapperFileContent_23_targetTemplates ;
extern const char * gWrapperFileContent_0_targetTemplates ;
extern const char * gWrapperFileContent_1_targetTemplates ;
extern const char * gWrapperFileContent_13_targetTemplates ;
extern const char * gWrapperFileContent_33_targetTemplates ;
extern const char * gWrapperFileContent_34_targetTemplates ;
extern const char * gWrapperFileContent_17_targetTemplates ;
extern const char * gWrapperFileContent_28_targetTemplates ;
extern const char * gWrapperFileContent_22_targetTemplates ;
extern const char * gWrapperFileContent_31_targetTemplates ;
extern const char * gWrapperFileContent_29_targetTemplates ;
extern const char * gWrapperFileContent_18_targetTemplates ;
extern const char * gWrapperFileContent_27_targetTemplates ;
extern const char * gWrapperFileContent_12_targetTemplates ;
extern const char * gWrapperFileContent_45_targetTemplates ;
extern const char * gWrapperFileContent_56_targetTemplates ;
extern const char * gWrapperFileContent_57_targetTemplates ;
extern const char * gWrapperFileContent_59_targetTemplates ;
extern const char * gWrapperFileContent_50_targetTemplates ;
extern const char * gWrapperFileContent_58_targetTemplates ;
extern const char * gWrapperFileContent_46_targetTemplates ;
extern const char * gWrapperFileContent_42_targetTemplates ;
extern const char * gWrapperFileContent_53_targetTemplates ;
extern const char * gWrapperFileContent_38_targetTemplates ;
extern const char * gWrapperFileContent_41_targetTemplates ;
extern const char * gWrapperFileContent_55_targetTemplates ;
extern const char * gWrapperFileContent_52_targetTemplates ;
extern const char * gWrapperFileContent_37_targetTemplates ;
extern const char * gWrapperFileContent_44_targetTemplates ;
extern const char * gWrapperFileContent_51_targetTemplates ;
extern const char * gWrapperFileContent_48_targetTemplates ;
extern const char * gWrapperFileContent_49_targetTemplates ;
extern const char * gWrapperFileContent_47_targetTemplates ;
extern const char * gWrapperFileContent_36_targetTemplates ;
extern const char * gWrapperFileContent_40_targetTemplates ;
extern const char * gWrapperFileContent_39_targetTemplates ;
extern const char * gWrapperFileContent_54_targetTemplates ;
extern const char * gWrapperFileContent_43_targetTemplates ;
extern const char * gWrapperFileContent_63_targetTemplates ;
extern const char * gWrapperFileContent_64_targetTemplates ;
extern const char * gWrapperFileContent_65_targetTemplates ;
extern const char * gWrapperFileContent_66_targetTemplates ;
extern const char * gWrapperFileContent_70_targetTemplates ;
extern const char * gWrapperFileContent_68_targetTemplates ;
extern const char * gWrapperFileContent_60_targetTemplates ;
extern const char * gWrapperFileContent_72_targetTemplates ;
extern const char * gWrapperFileContent_74_targetTemplates ;
extern const char * gWrapperFileContent_73_targetTemplates ;
extern const char * gWrapperFileContent_61_targetTemplates ;
extern const char * gWrapperFileContent_67_targetTemplates ;
extern const char * gWrapperFileContent_71_targetTemplates ;
extern const char * gWrapperFileContent_69_targetTemplates ;
extern const char * gWrapperFileContent_62_targetTemplates ;
extern const char * gWrapperFileContent_82_targetTemplates ;
extern const char * gWrapperFileContent_79_targetTemplates ;
extern const char * gWrapperFileContent_83_targetTemplates ;
extern const char * gWrapperFileContent_87_targetTemplates ;
extern const char * gWrapperFileContent_76_targetTemplates ;
extern const char * gWrapperFileContent_81_targetTemplates ;
extern const char * gWrapperFileContent_86_targetTemplates ;
extern const char * gWrapperFileContent_85_targetTemplates ;
extern const char * gWrapperFileContent_84_targetTemplates ;
extern const char * gWrapperFileContent_75_targetTemplates ;
extern const char * gWrapperFileContent_80_targetTemplates ;
extern const char * gWrapperFileContent_78_targetTemplates ;
extern const char * gWrapperFileContent_77_targetTemplates ;
extern const char * gWrapperFileContent_97_targetTemplates ;
extern const char * gWrapperFileContent_95_targetTemplates ;
extern const char * gWrapperFileContent_105_targetTemplates ;
extern const char * gWrapperFileContent_107_targetTemplates ;
extern const char * gWrapperFileContent_112_targetTemplates ;
extern const char * gWrapperFileContent_111_targetTemplates ;
extern const char * gWrapperFileContent_90_targetTemplates ;
extern const char * gWrapperFileContent_100_targetTemplates ;
extern const char * gWrapperFileContent_116_targetTemplates ;
extern const char * gWrapperFileContent_115_targetTemplates ;
extern const char * gWrapperFileContent_114_targetTemplates ;
extern const char * gWrapperFileContent_93_targetTemplates ;
extern const char * gWrapperFileContent_102_targetTemplates ;
extern const char * gWrapperFileContent_94_targetTemplates ;
extern const char * gWrapperFileContent_109_targetTemplates ;
extern const char * gWrapperFileContent_89_targetTemplates ;
extern const char * gWrapperFileContent_98_targetTemplates ;
extern const char * gWrapperFileContent_108_targetTemplates ;
extern const char * gWrapperFileContent_104_targetTemplates ;
extern const char * gWrapperFileContent_110_targetTemplates ;
extern const char * gWrapperFileContent_101_targetTemplates ;
extern const char * gWrapperFileContent_106_targetTemplates ;
extern const char * gWrapperFileContent_113_targetTemplates ;
extern const char * gWrapperFileContent_99_targetTemplates ;
extern const char * gWrapperFileContent_103_targetTemplates ;
extern const char * gWrapperFileContent_88_targetTemplates ;
extern const char * gWrapperFileContent_96_targetTemplates ;
extern const char * gWrapperFileContent_92_targetTemplates ;
extern const char * gWrapperFileContent_91_targetTemplates ;
extern const char * gWrapperFileContent_117_targetTemplates ;
extern const char * gWrapperFileContent_118_targetTemplates ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const cRegularFileWrapper gWrapperFile_0_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_1_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_2_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_3_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_4_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_5_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_6_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_7_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_8_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_9_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_10_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_11_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_12_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_13_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_14_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_15_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_16_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_17_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_18_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_19_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_20_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_21_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_22_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_23_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_24_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_25_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_26_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_27_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_28_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_29_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_30_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_31_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_32_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_33_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_34_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_35_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_36_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_37_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_38_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_39_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_40_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_41_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_42_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_43_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_44_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_45_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_46_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_47_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_48_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_49_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_50_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_51_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_52_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_53_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_54_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_55_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_56_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_57_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_58_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_59_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_60_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_61_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_62_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_63_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_64_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_65_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_66_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_67_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_68_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_69_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_70_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_71_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_72_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_73_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_74_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_75_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_76_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_77_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_78_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_79_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_80_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_81_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_82_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_83_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_84_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_85_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_86_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_87_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_88_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_89_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_90_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_91_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_92_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_93_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_94_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_95_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_96_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_97_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_98_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_99_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_100_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_101_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_102_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_103_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_104_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_105_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_106_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_107_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_108_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_109_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_110_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_111_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_112_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_113_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_114_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_115_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_116_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_117_targetTemplates ;
extern const cRegularFileWrapper gWrapperFile_118_targetTemplates ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const cDirectoryWrapper gWrapperDirectory_0_targetTemplates ;
extern const cDirectoryWrapper gWrapperDirectory_1_targetTemplates ;
extern const cDirectoryWrapper gWrapperDirectory_2_targetTemplates ;
extern const cDirectoryWrapper gWrapperDirectory_3_targetTemplates ;
extern const cDirectoryWrapper gWrapperDirectory_4_targetTemplates ;
extern const cDirectoryWrapper gWrapperDirectory_5_targetTemplates ;
extern const cDirectoryWrapper gWrapperDirectory_6_targetTemplates ;

