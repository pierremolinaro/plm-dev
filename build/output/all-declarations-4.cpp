#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-4.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Routine 'recursiveImportFileSystemTargetFiles'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_recursiveImportFileSystemTargetFiles (GALGAS_ast & ioArgument_ioAST,
                                                   const GALGAS_string constinArgument_inTargetDirectory,
                                                   GALGAS_lstringlist inArgument_inImportedClauseList,
                                                   GALGAS_stringset & ioArgument_ioImportedFileAbsolutePathSet,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_lstringlist enumerator_7270 (inArgument_inImportedClauseList, kEnumeration_up) ;
  while (enumerator_7270.hasCurrentObject ()) {
    GALGAS_string var_absolutePath = constinArgument_inTargetDirectory.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("program.galgas", 194)).add_operation (enumerator_7270.current_mValue (HERE).mAttribute_string, inCompiler COMMA_SOURCE_FILE ("program.galgas", 194)) ;
    const enumGalgasBool test_0 = var_absolutePath.reader_fileExists (SOURCE_FILE ("program.galgas", 195)).boolEnum () ;
    if (kBoolTrue == test_0) {
      const enumGalgasBool test_1 = ioArgument_ioImportedFileAbsolutePathSet.reader_hasKey (var_absolutePath COMMA_SOURCE_FILE ("program.galgas", 196)).operator_not (SOURCE_FILE ("program.galgas", 196)).boolEnum () ;
      if (kBoolTrue == test_1) {
        ioArgument_ioImportedFileAbsolutePathSet.addAssign_operation (var_absolutePath  COMMA_SOURCE_FILE ("program.galgas", 197)) ;
        const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_absolutePath.reader_pathExtension (SOURCE_FILE ("program.galgas", 198)).objectCompare (GALGAS_string ("plm"))).boolEnum () ;
        if (kBoolTrue == test_2) {
          GALGAS_lstringlist var_importedFileList ;
          var_importedFileList.drop () ;
          GALGAS_location joker_7730 ; // Joker input parameter
          cGrammar_plm_5F_grammar::_performSourceFileParsing_ (inCompiler, GALGAS_lstring::constructor_new (var_absolutePath, enumerator_7270.current_mValue (HERE).mAttribute_location  COMMA_SOURCE_FILE ("program.galgas", 199)), ioArgument_ioAST, var_importedFileList, joker_7730  COMMA_SOURCE_FILE ("program.galgas", 199)) ;
          {
          routine_recursiveImportFileSystemTargetFiles (ioArgument_ioAST, constinArgument_inTargetDirectory, var_importedFileList, ioArgument_ioImportedFileAbsolutePathSet, inCompiler  COMMA_SOURCE_FILE ("program.galgas", 203)) ;
          }
        }else if (kBoolFalse == test_2) {
          const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, var_absolutePath.reader_pathExtension (SOURCE_FILE ("program.galgas", 209)).objectCompare (GALGAS_string ("plm-target"))).boolEnum () ;
          if (kBoolTrue == test_3) {
            GALGAS_lstringlist var_importedFileList ;
            var_importedFileList.drop () ;
            GALGAS_location joker_8223 ; // Joker input parameter
            cGrammar_plm_5F_target_5F_grammar::_performSourceFileParsing_ (inCompiler, GALGAS_lstring::constructor_new (var_absolutePath, enumerator_7270.current_mValue (HERE).mAttribute_location  COMMA_SOURCE_FILE ("program.galgas", 210)), ioArgument_ioAST, var_importedFileList, joker_8223  COMMA_SOURCE_FILE ("program.galgas", 210)) ;
            {
            routine_recursiveImportFileSystemTargetFiles (ioArgument_ioAST, constinArgument_inTargetDirectory, var_importedFileList, ioArgument_ioImportedFileAbsolutePathSet, inCompiler  COMMA_SOURCE_FILE ("program.galgas", 214)) ;
            }
          }else if (kBoolFalse == test_3) {
            GALGAS_location location_4 (enumerator_7270.current_mValue (HERE).reader_location (HERE)) ; // Implicit use of 'location' reader
            inCompiler->emitSemanticError (location_4, GALGAS_string ("invalid extension (should be .plm or .plm-target)")  COMMA_SOURCE_FILE ("program.galgas", 221)) ;
          }
        }
      }
    }else if (kBoolFalse == test_0) {
      GALGAS_location location_5 (enumerator_7270.current_mValue (HERE).reader_location (HERE)) ; // Implicit use of 'location' reader
      inCompiler->emitSemanticError (location_5, GALGAS_string ("file does not exist in file system target definition")  COMMA_SOURCE_FILE ("program.galgas", 225)) ;
    }
    enumerator_7270.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Routine 'recursiveImportEmbeddedTargetFiles'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_recursiveImportEmbeddedTargetFiles (GALGAS_ast & ioArgument_ioAST,
                                                 GALGAS_lstringlist inArgument_inImportedClauseList,
                                                 GALGAS_stringset & ioArgument_ioImportedFileAbsolutePathSet,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_lstringlist enumerator_9024 (inArgument_inImportedClauseList, kEnumeration_up) ;
  while (enumerator_9024.hasCurrentObject ()) {
    GALGAS_filewrapper var_fw = GALGAS_filewrapper (gWrapperDirectory_0_targetTemplates) ;
    const enumGalgasBool test_0 = var_fw.reader_fileExistsAtPath (enumerator_9024.current_mValue (HERE).mAttribute_string, inCompiler COMMA_SOURCE_FILE ("program.galgas", 239)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_string var_embeddedPath = GALGAS_string (":").add_operation (enumerator_9024.current_mValue (HERE).reader_string (SOURCE_FILE ("program.galgas", 240)), inCompiler COMMA_SOURCE_FILE ("program.galgas", 240)) ;
      const enumGalgasBool test_1 = ioArgument_ioImportedFileAbsolutePathSet.reader_hasKey (var_embeddedPath COMMA_SOURCE_FILE ("program.galgas", 241)).operator_not (SOURCE_FILE ("program.galgas", 241)).boolEnum () ;
      if (kBoolTrue == test_1) {
        ioArgument_ioImportedFileAbsolutePathSet.addAssign_operation (var_embeddedPath  COMMA_SOURCE_FILE ("program.galgas", 242)) ;
        const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, enumerator_9024.current_mValue (HERE).mAttribute_string.reader_pathExtension (SOURCE_FILE ("program.galgas", 243)).objectCompare (GALGAS_string ("plm"))).boolEnum () ;
        if (kBoolTrue == test_2) {
          GALGAS_lstringlist var_importedFileList ;
          var_importedFileList.drop () ;
          GALGAS_location joker_9513 ; // Joker input parameter
          cGrammar_plm_5F_grammar::_performSourceStringParsing_ (inCompiler, var_fw.reader_textFileContentsAtPath (enumerator_9024.current_mValue (HERE).mAttribute_string, inCompiler COMMA_SOURCE_FILE ("program.galgas", 244)), ioArgument_ioAST, var_importedFileList, joker_9513  COMMA_SOURCE_FILE ("program.galgas", 244)) ;
          {
          routine_recursiveImportEmbeddedTargetFiles (ioArgument_ioAST, var_importedFileList, ioArgument_ioImportedFileAbsolutePathSet, inCompiler  COMMA_SOURCE_FILE ("program.galgas", 248)) ;
          }
        }else if (kBoolFalse == test_2) {
          const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, enumerator_9024.current_mValue (HERE).mAttribute_string.reader_pathExtension (SOURCE_FILE ("program.galgas", 253)).objectCompare (GALGAS_string ("plm-target"))).boolEnum () ;
          if (kBoolTrue == test_3) {
            GALGAS_lstringlist var_importedFileList ;
            var_importedFileList.drop () ;
            GALGAS_location joker_9946 ; // Joker input parameter
            cGrammar_plm_5F_target_5F_grammar::_performSourceStringParsing_ (inCompiler, var_fw.reader_textFileContentsAtPath (enumerator_9024.current_mValue (HERE).mAttribute_string, inCompiler COMMA_SOURCE_FILE ("program.galgas", 254)), ioArgument_ioAST, var_importedFileList, joker_9946  COMMA_SOURCE_FILE ("program.galgas", 254)) ;
            {
            routine_recursiveImportEmbeddedTargetFiles (ioArgument_ioAST, var_importedFileList, ioArgument_ioImportedFileAbsolutePathSet, inCompiler  COMMA_SOURCE_FILE ("program.galgas", 258)) ;
            }
          }else if (kBoolFalse == test_3) {
            GALGAS_location location_4 (enumerator_9024.current_mValue (HERE).reader_location (HERE)) ; // Implicit use of 'location' reader
            inCompiler->emitSemanticError (location_4, GALGAS_string ("invalid extension (should be .plm or .plm-target)")  COMMA_SOURCE_FILE ("program.galgas", 264)) ;
          }
        }
      }
    }else if (kBoolFalse == test_0) {
      GALGAS_location location_5 (enumerator_9024.current_mValue (HERE).reader_location (HERE)) ; // Implicit use of 'location' reader
      inCompiler->emitSemanticError (location_5, GALGAS_string ("cannot find this file in embedded files")  COMMA_SOURCE_FILE ("program.galgas", 268)) ;
    }
    enumerator_9024.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'recursiveImportFiles'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_recursiveImportFiles (GALGAS_ast & ioArgument_ioAST,
                                   GALGAS_string inArgument_inCurrentDirectory,
                                   GALGAS_lstringlist inArgument_inImportedClauseList,
                                   GALGAS_stringset & ioArgument_ioImportedFileAbsolutePathSet,
                                   C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_lstringlist enumerator_10718 (inArgument_inImportedClauseList, kEnumeration_up) ;
  while (enumerator_10718.hasCurrentObject ()) {
    GALGAS_string var_absolutePath = enumerator_10718.current_mValue (HERE).mAttribute_string.reader_absolutePathFromPath (inArgument_inCurrentDirectory COMMA_SOURCE_FILE ("program.galgas", 282)) ;
    const enumGalgasBool test_0 = var_absolutePath.reader_fileExists (SOURCE_FILE ("program.galgas", 283)).boolEnum () ;
    if (kBoolTrue == test_0) {
      const enumGalgasBool test_1 = ioArgument_ioImportedFileAbsolutePathSet.reader_hasKey (var_absolutePath COMMA_SOURCE_FILE ("program.galgas", 284)).operator_not (SOURCE_FILE ("program.galgas", 284)).boolEnum () ;
      if (kBoolTrue == test_1) {
        ioArgument_ioImportedFileAbsolutePathSet.addAssign_operation (var_absolutePath  COMMA_SOURCE_FILE ("program.galgas", 285)) ;
        const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_absolutePath.reader_pathExtension (SOURCE_FILE ("program.galgas", 286)).objectCompare (GALGAS_string ("plm"))).boolEnum () ;
        if (kBoolTrue == test_2) {
          GALGAS_lstringlist var_importedFileList ;
          var_importedFileList.drop () ;
          GALGAS_location joker_11221 ; // Joker input parameter
          cGrammar_plm_5F_grammar::_performSourceFileParsing_ (inCompiler, GALGAS_lstring::constructor_new (var_absolutePath, enumerator_10718.current_mValue (HERE).mAttribute_location  COMMA_SOURCE_FILE ("program.galgas", 287)), ioArgument_ioAST, var_importedFileList, joker_11221  COMMA_SOURCE_FILE ("program.galgas", 287)) ;
          {
          routine_recursiveImportFiles (ioArgument_ioAST, inArgument_inCurrentDirectory, var_importedFileList, ioArgument_ioImportedFileAbsolutePathSet, inCompiler  COMMA_SOURCE_FILE ("program.galgas", 291)) ;
          }
        }else if (kBoolFalse == test_2) {
          const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, var_absolutePath.reader_pathExtension (SOURCE_FILE ("program.galgas", 297)).objectCompare (GALGAS_string ("plm-target"))).boolEnum () ;
          if (kBoolTrue == test_3) {
            GALGAS_lstringlist var_importedFileList ;
            var_importedFileList.drop () ;
            GALGAS_location joker_11700 ; // Joker input parameter
            cGrammar_plm_5F_target_5F_grammar::_performSourceFileParsing_ (inCompiler, GALGAS_lstring::constructor_new (var_absolutePath, enumerator_10718.current_mValue (HERE).mAttribute_location  COMMA_SOURCE_FILE ("program.galgas", 298)), ioArgument_ioAST, var_importedFileList, joker_11700  COMMA_SOURCE_FILE ("program.galgas", 298)) ;
            {
            routine_recursiveImportFiles (ioArgument_ioAST, inArgument_inCurrentDirectory, var_importedFileList, ioArgument_ioImportedFileAbsolutePathSet, inCompiler  COMMA_SOURCE_FILE ("program.galgas", 302)) ;
            }
          }else if (kBoolFalse == test_3) {
            GALGAS_location location_4 (enumerator_10718.current_mValue (HERE).reader_location (HERE)) ; // Implicit use of 'location' reader
            inCompiler->emitSemanticError (location_4, GALGAS_string ("invalid extension (should be .plm or .plm-target)")  COMMA_SOURCE_FILE ("program.galgas", 309)) ;
          }
        }
      }
    }else if (kBoolFalse == test_0) {
      GALGAS_filewrapper var_fw = GALGAS_filewrapper (gWrapperDirectory_0_targetTemplates) ;
      const enumGalgasBool test_5 = var_fw.reader_fileExistsAtPath (enumerator_10718.current_mValue (HERE).mAttribute_string, inCompiler COMMA_SOURCE_FILE ("program.galgas", 314)).boolEnum () ;
      if (kBoolTrue == test_5) {
        GALGAS_string var_embeddedPath = GALGAS_string (":").add_operation (enumerator_10718.current_mValue (HERE).reader_string (SOURCE_FILE ("program.galgas", 315)), inCompiler COMMA_SOURCE_FILE ("program.galgas", 315)) ;
        const enumGalgasBool test_6 = ioArgument_ioImportedFileAbsolutePathSet.reader_hasKey (var_embeddedPath COMMA_SOURCE_FILE ("program.galgas", 316)).operator_not (SOURCE_FILE ("program.galgas", 316)).boolEnum () ;
        if (kBoolTrue == test_6) {
          ioArgument_ioImportedFileAbsolutePathSet.addAssign_operation (var_embeddedPath  COMMA_SOURCE_FILE ("program.galgas", 317)) ;
          const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, enumerator_10718.current_mValue (HERE).mAttribute_string.reader_pathExtension (SOURCE_FILE ("program.galgas", 318)).objectCompare (GALGAS_string ("plm"))).boolEnum () ;
          if (kBoolTrue == test_7) {
            GALGAS_lstringlist var_importedFileList ;
            var_importedFileList.drop () ;
            GALGAS_location joker_12555 ; // Joker input parameter
            cGrammar_plm_5F_grammar::_performSourceStringParsing_ (inCompiler, var_fw.reader_textFileContentsAtPath (enumerator_10718.current_mValue (HERE).mAttribute_string, inCompiler COMMA_SOURCE_FILE ("program.galgas", 319)), ioArgument_ioAST, var_importedFileList, joker_12555  COMMA_SOURCE_FILE ("program.galgas", 319)) ;
            {
            routine_recursiveImportFiles (ioArgument_ioAST, inArgument_inCurrentDirectory, var_importedFileList, ioArgument_ioImportedFileAbsolutePathSet, inCompiler  COMMA_SOURCE_FILE ("program.galgas", 323)) ;
            }
          }else if (kBoolFalse == test_7) {
            const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, enumerator_10718.current_mValue (HERE).mAttribute_string.reader_pathExtension (SOURCE_FILE ("program.galgas", 329)).objectCompare (GALGAS_string ("plm-target"))).boolEnum () ;
            if (kBoolTrue == test_8) {
              GALGAS_lstringlist var_importedFileList ;
              var_importedFileList.drop () ;
              GALGAS_location joker_13045 ; // Joker input parameter
              cGrammar_plm_5F_target_5F_grammar::_performSourceStringParsing_ (inCompiler, var_fw.reader_textFileContentsAtPath (enumerator_10718.current_mValue (HERE).mAttribute_string, inCompiler COMMA_SOURCE_FILE ("program.galgas", 330)), ioArgument_ioAST, var_importedFileList, joker_13045  COMMA_SOURCE_FILE ("program.galgas", 330)) ;
              {
              routine_recursiveImportFiles (ioArgument_ioAST, inArgument_inCurrentDirectory, var_importedFileList, ioArgument_ioImportedFileAbsolutePathSet, inCompiler  COMMA_SOURCE_FILE ("program.galgas", 334)) ;
              }
            }else if (kBoolFalse == test_8) {
              GALGAS_location location_9 (enumerator_10718.current_mValue (HERE).reader_location (HERE)) ; // Implicit use of 'location' reader
              inCompiler->emitSemanticError (location_9, GALGAS_string ("invalid extension (should be .plm or .plm-target)")  COMMA_SOURCE_FILE ("program.galgas", 341)) ;
            }
          }
        }
      }else if (kBoolFalse == test_5) {
        GALGAS_location location_10 (enumerator_10718.current_mValue (HERE).reader_location (HERE)) ; // Implicit use of 'location' reader
        inCompiler->emitSemanticError (location_10, GALGAS_string ("cannot find this file in file system and in embedded files")  COMMA_SOURCE_FILE ("program.galgas", 345)) ;
      }
    }
    enumerator_10718.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Filewrapper 'embeddedSampleCode'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//--- File 'teensy-3-1-sequential-systick/01-blinkled.plm'

const char * gWrapperFileContent_0_embeddedSampleCode = "target \"teensy-3-1-sequential-systick\"\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc setup `user () {\n"
  "  PORTC_PCR5 = PORTC_PCR5::mux (1)\n"
  "  GPIOC_PDDR |= (1 << 5)\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "var gDelai $uint32 = 0 {\n"
  "  @rw proc loop ()\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc loop `user () {\n"
  "  gDelai &++\n"
  "  if gDelai == 1_000_000 then\n"
  "    GPIOC_PSOR = 1 << 5 // Allumer la led\n"
  "  elsif gDelai == 2_000_000 then\n"
  "    gDelai = 0\n"
  "    GPIOC_PCOR = 1 << 5 // \xC3""\x89""teindre la led\n"
  "  end  \n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_0_embeddedSampleCode (
  "01-blinkled.plm",
  "plm",
  true, // Text file
  591, // Text length
  gWrapperFileContent_0_embeddedSampleCode
) ;

//--- File 'teensy-3-1-sequential-systick/02-blinkled-systick.plm'

const char * gWrapperFileContent_1_embeddedSampleCode = "target \"teensy-3-1-sequential-systick\"\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc setup `user () {\n"
  "  PORTC_PCR5 = PORTC_PCR5::mux (1)\n"
  "  GPIOC_PDDR |= (1 << 5)\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "var gUpTimeMS $uint32 = 0 {\n"
  "  @rw proc systickHandler ()\n"
  "  proc wait (\?ms: inDuration $uint32)\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc systickHandler `isr () {\n"
  "  gUpTimeMS ++\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc wait `user (\?ms: inDuration $uint32) {\n"
  "  let deadline = gUpTimeMS + inDuration\n"
  "  while@boucle deadline > gUpTimeMS do\n"
  "  end@boucle\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc loop `user () {\n"
  "  wait (!ms:500)\n"
  "  GPIOC_PSOR = 1 << 5 // Allumer la led\n"
  "  wait (!ms:500)\n"
  "  GPIOC_PCOR = 1 << 5  // \xC3""\x89""teindre la led\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_1_embeddedSampleCode (
  "02-blinkled-systick.plm",
  "plm",
  true, // Text file
  867, // Text length
  gWrapperFileContent_1_embeddedSampleCode
) ;

//--- File 'teensy-3-1-sequential-systick/03-blinkled-systick-enum.plm'

const char * gWrapperFileContent_2_embeddedSampleCode = "target \"teensy-3-1-sequential-systick\"\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "enum $ledState @unsigned8 {\n"
  "  case on\n"
  "  case off\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc setup `user () {\n"
  "  PORTC_PCR5 = PORTC_PCR5::mux (1)\n"
  "  GPIOC_PDDR |= (1 << 5)\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "var gUpTimeMS $uint32 = 0 {\n"
  "  @rw proc systickHandler ()\n"
  "  proc wait (\?ms: inDuration $uint32)\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc systickHandler `isr () {\n"
  "  gUpTimeMS ++\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc wait `user (\?ms: inDuration $uint32) {\n"
  "  let deadline = gUpTimeMS + inDuration\n"
  "  while@boucle deadline > gUpTimeMS do\n"
  "  end@boucle\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "var led = $ledState.on {\n"
  "  @rw proc loop ()\n"
  "}\n"
  "\n"
  "let ROUGE = $ledState.off\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc loop `user () {\n"
  "  wait (!ms:250)\n"
  "  if led == .off then\n"
  "    GPIOC_PSOR = 1 << 5 // Allumer la led\n"
  "    led = .on\n"
  "  else\n"
  "    GPIOC_PCOR = 1 << 5  // \xC3""\x89""teindre la led\n"
  "    led = .off\n"
  "  end\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_2_embeddedSampleCode (
  "03-blinkled-systick-enum.plm",
  "plm",
  true, // Text file
  1149, // Text length
  gWrapperFileContent_2_embeddedSampleCode
) ;

//--- File 'teensy-3-1-sequential-systick/04-blinkled-systick-struct.plm'

const char * gWrapperFileContent_3_embeddedSampleCode = "target \"teensy-3-1-sequential-systick\"\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "struct $point {\n"
  "  var x $int32 = 1\n"
  "  var y $int32 = 2\n"
  "}\n"
  "\n"
  "struct $point3 {\n"
  "  var p $point = $point ()\n"
  "  var z $int32 = 3\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "var zzz $point3 = $point3 () {\n"
  "  @rw proc loop ()\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "var zz $int32 = 0 {\n"
  "  @rw proc loop ()\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc setup `user () {\n"
  "  PORTC_PCR5 = PORTC_PCR5::mux (1)\n"
  "  GPIOC_PDDR |= (1 << 5)\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "var gUpTimeMS $uint32 = 0 {\n"
  "  @rw proc systickHandler ()\n"
  "  proc wait (\?ms: inDuration $uint32)\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc systickHandler `isr () {\n"
  "  gUpTimeMS ++\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc wait `user (\?ms: inDuration $uint32) {\n"
  "  let deadline = gUpTimeMS + inDuration\n"
  "  while@boucle deadline > gUpTimeMS do\n"
  "  end@boucle\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n"
  "\n"
  "proc loop `user () {\n"
  "  wait (!ms:250)\n"
  "  zz = zzz.p.x\n"
  "  zzz.p.x = zz\n"
  "  zzz = $point3 ()\n"
  "  GPIOC_PSOR = 1 << 5 // Allumer la led\n"
  "  wait (!ms:250)\n"
  "  GPIOC_PCOR = 1 << 5  // \xC3""\x89""teindre la led\n"
  "}\n"
  "\n"
  "//------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_3_embeddedSampleCode (
  "04-blinkled-systick-struct.plm",
  "plm",
  true, // Text file
  1293, // Text length
  gWrapperFileContent_3_embeddedSampleCode
) ;

//--- All files of 'teensy-3-1-sequential-systick' directory

static const cRegularFileWrapper * gWrapperAllFiles_embeddedSampleCode_1 [5] = {
  & gWrapperFile_0_embeddedSampleCode,
  & gWrapperFile_1_embeddedSampleCode,
  & gWrapperFile_2_embeddedSampleCode,
  & gWrapperFile_3_embeddedSampleCode,
  NULL
} ;

//--- All sub-directories of 'teensy-3-1-sequential-systick' directory

static const cDirectoryWrapper * gWrapperAllDirectories_embeddedSampleCode_1 [1] = {
  NULL
} ;

//--- Directory 'teensy-3-1-sequential-systick'

const cDirectoryWrapper gWrapperDirectory_1_embeddedSampleCode (
  "teensy-3-1-sequential-systick",
  4,
  gWrapperAllFiles_embeddedSampleCode_1,
  0,
  gWrapperAllDirectories_embeddedSampleCode_1
) ;

//--- All files of '' directory

static const cRegularFileWrapper * gWrapperAllFiles_embeddedSampleCode_0 [1] = {
  NULL
} ;

//--- All sub-directories of '' directory

static const cDirectoryWrapper * gWrapperAllDirectories_embeddedSampleCode_0 [2] = {
  & gWrapperDirectory_1_embeddedSampleCode,
  NULL
} ;

//--- Directory ''

const cDirectoryWrapper gWrapperDirectory_0_embeddedSampleCode (
  "",
  0,
  gWrapperAllFiles_embeddedSampleCode_0,
  1,
  gWrapperAllDirectories_embeddedSampleCode_0
) ;


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Filewrapper 'embeddedTargets'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//--- File '/make.py'

const char * gWrapperFileContent_0_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import subprocess, sys, os, copy\n"
  "import urllib, shutil\n"
  "import subprocess, re\n"
  "from time import time\n"
  "import platform\n"
  "import json\n"
  "import threading, operator\n"
  "\n"
  "if sys.version_info >= (2, 6) :\n"
  "  import multiprocessing\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   processorCount                                                                                                     *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def processorCount () :\n"
  "  if sys.version_info >= (2, 6) :\n"
  "    coreCount = multiprocessing.cpu_count ()\n"
  "  else:\n"
  "    coreCount = 1\n"
  "  return coreCount\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   FOR PRINTING IN COLOR                                                                                              *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BLACK () :\n"
  "  return '\\033[90m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def RED () :\n"
  "  return '\\033[91m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def GREEN () :\n"
  "  return '\\033[92m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def YELLOW () :\n"
  "  return '\\033[93m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BLUE () :\n"
  "  return '\\033[94m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def MAGENTA () :\n"
  "  return '\\033[95m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def CYAN () :\n"
  "  return '\\033[96m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def WHITE () :\n"
  "  return '\\033[97m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def ENDC () :\n"
  "  return '\\033[0m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BOLD () :\n"
  "  return '\\033[1m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def UNDERLINE () :\n"
  "  return '\\033[4m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BLINK () :\n"
  "  return '\\033[5m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BOLD_BLUE () :\n"
  "  return BOLD () + BLUE ()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BOLD_GREEN () :\n"
  "  return BOLD () + GREEN ()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BOLD_RED () :\n"
  "  return BOLD () + RED ()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   runHiddenCommand                                                                                                   *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def runHiddenCommand (cmd) :\n"
  "  result = \"\"\n"
  "  childProcess = subprocess.Popen (cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)\n"
  "  while True:\n"
  "    line = childProcess.stdout.readline ()\n"
  "    if line != \"\":\n"
  "      result += line\n"
  "    else:\n"
  "      childProcess.wait ()\n"
  "      if childProcess.returncode != 0 :\n"
  "        sys.exit (childProcess.returncode)\n"
  "      return result\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   runSingleCommand                                                                                                   *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def runSingleCommand (cmd) :\n"
  "  cmdAsString = \"\"\n"
  "  for s in cmd:\n"
  "    if (s == \"\") or (s.find (\" \") >= 0):\n"
  "      cmdAsString += '\"' + s + '\" '\n"
  "    else:\n"
  "      cmdAsString += s + ' '\n"
  "  print cmdAsString\n"
  "  childProcess = subprocess.Popen (cmd)\n"
  "  childProcess.wait ()\n"
  "  if childProcess.returncode != 0 :\n"
  "    sys.exit (childProcess.returncode)\n"
  "  sys.stdout.flush()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   runCommand                                                                                                         *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def runCommand (cmd, title, showCommand) :\n"
  "  if title != \"\":\n"
  "    print BOLD_BLUE () + title + ENDC ()\n"
  "  if (title == \"\") or showCommand :\n"
  "    cmdAsString = \"\"\n"
  "    for s in cmd:\n"
  "      if (s == \"\") or (s.find (\" \") >= 0):\n"
  "        cmdAsString += '\"' + s + '\" '\n"
  "      else:\n"
  "        cmdAsString += s + ' '\n"
  "    print cmdAsString\n"
  "  childProcess = subprocess.Popen (cmd)\n"
  "  childProcess.wait ()\n"
  "  if childProcess.returncode != 0 :\n"
  "    sys.exit (childProcess.returncode)\n"
  "  sys.stdout.flush()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   runInThread                                                                                                        *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def runInThread (job, displayLock, terminationSemaphore):\n"
  "  childProcess = subprocess.Popen (job.mCommand, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)\n"
  "  while True:\n"
  "    line = childProcess.stdout.readline ()\n"
  "    if line != \"\":\n"
  "      displayLock.acquire ()\n"
  "      sys.stdout.write (line) # Print without newline\n"
  "      displayLock.release ()\n"
  "    else:\n"
  "      childProcess.wait ()\n"
  "      job.mReturnCode = childProcess.returncode\n"
  "      terminationSemaphore.release ()\n"
  "      break\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   modificationDateForFile                                                                                            *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def modificationDateForFile (dateCacheDictionary, file):\n"
  "  absFilePath = os.path.abspath (file)\n"
  "  if dateCacheDictionary.has_key (absFilePath) :\n"
  "    return dateCacheDictionary [absFilePath]\n"
  "  elif not os.path.exists (absFilePath):\n"
  "    date = sys.float_info.max # Very far in future\n"
  "    dateCacheDictionary [absFilePath] = date\n"
  "    return date\n"
  "  else:\n"
  "    date = os.path.getmtime (absFilePath)\n"
  "    dateCacheDictionary [absFilePath] = date\n"
  "    return date\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   class PostCommand                                                                                                  *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "class PostCommand:\n"
  "  mCommand = []\n"
  "  mTitle = \"\"\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def __init__ (self, title = \"\"):\n"
  "    self.mCommand = []\n"
  "    self.mTitle = title\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   class Job                                                                                                          *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "class Job:\n"
  "  mTarget = \"\"\n"
  "  mCommand = []\n"
  "  mTitle = \"\"\n"
  "  mRequiredFiles = []\n"
  "  mPostCommands = []\n"
  "  mReturnCode = None\n"
  "  mPriority = 0\n"
  "  mState = 0 # 0: waiting for execution\n"
  "  \n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def __init__ (self, target, requiredFiles, command, postCommands, priority, title):\n"
  "    self.mTarget = copy.deepcopy (target)\n"
  "    self.mCommand = copy.deepcopy (command)\n"
  "    self.mRequiredFiles = copy.deepcopy (requiredFiles)\n"
  "    self.mTitle = copy.deepcopy (title)\n"
  "    self.mPostCommands = copy.deepcopy (postCommands)\n"
  "    self.mPriority = priority\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def run (self, displayLock, terminationSemaphore, showCommand):\n"
  "    displayLock.acquire ()\n"
  "    if self.mTitle != \"\":\n"
  "      print BOLD_BLUE () + self.mTitle + ENDC ()\n"
  "    if (self.mTitle == \"\") or showCommand :\n"
  "      cmdAsString = \"\"\n"
  "      for s in self.mCommand:\n"
  "        if (s == \"\") or (s.find (\" \") >= 0):\n"
  "          cmdAsString += '\"' + s + '\" '\n"
  "        else:\n"
  "          cmdAsString += s + ' '\n"
  "      print cmdAsString\n"
  "    displayLock.release ()\n"
  "    thread = threading.Thread (target=runInThread, args=(self, displayLock, terminationSemaphore))\n"
  "    thread.start()\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def runPostCommand (self, displayLock, terminationSemaphore, showCommand):\n"
  "    postCommand = self.mPostCommands [0]\n"
  "    self.mCommand = postCommand.mCommand\n"
  "    displayLock.acquire ()\n"
  "    print BOLD_BLUE () + postCommand.mTitle + ENDC ()\n"
  "    if showCommand:\n"
  "      cmdAsString = \"\"\n"
  "      for s in self.mCommand:\n"
  "        if (s == \"\") or (s.find (\" \") >= 0):\n"
  "          cmdAsString += '\"' + s + '\" '\n"
  "        else:\n"
  "          cmdAsString += s + ' '\n"
  "      print cmdAsString\n"
  "    displayLock.release ()\n"
  "    thread = threading.Thread (target=runInThread, args=(self, displayLock, terminationSemaphore))\n"
  "    thread.start()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   class Rule                                                                                                         *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "class Rule:\n"
  "  mTarget = \"\"\n"
  "  mDependences = []\n"
  "  mCommand = []\n"
  "  mSecondaryMostRecentModificationDate = 0.0 # Far in the past\n"
  "  mTitle = \"\"\n"
  "  mPostCommands = []\n"
  "  mPriority = 0\n"
  "  \n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def __init__ (self, target, title = \"\"):\n"
  "    self.mTarget = copy.deepcopy (target)\n"
  "    self.mDependences = []\n"
  "    self.mCommand = []\n"
  "    self.mSecondaryMostRecentModificationDate = 0.0\n"
  "    self.mPostCommands = []\n"
  "    self.mPriority = 0\n"
  "    if title == \"\":\n"
  "      self.mTitle = \"Building \" + target\n"
  "    else:\n"
  "      self.mTitle = copy.deepcopy (title)\n"
  "  \n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def enterSecondaryDependanceFile (self, secondaryDependanceFile):\n"
  "    if secondaryDependanceFile != \"\":\n"
  "      filePath = os.path.abspath (secondaryDependanceFile)\n"
  "      if os.path.exists (filePath):\n"
  "        f = open (filePath, \"r\")\n"
  "        s = f.read ().replace (\"\\\\ \", \"\\x01\") # Read and replace escaped spaces by \\0x01\n"
  "        f.close ()\n"
  "        s = s.replace (\"\\\\\\n\", \"\")\n"
  "        liste = s.split (\"\\n\\n\")\n"
  "        dateCacheDictionary = {}\n"
  "        for s in liste:\n"
  "          components = s.split (':')\n"
  "          target = components [0].replace (\"\\x01\", \" \")\n"
  "          #print \"------- Optional dependency rules for target '\" + target + \"'\"\n"
  "          #print \"Secondary target '\" + target + \"'\"\n"
  "          for src in components [1].split ():\n"
  "            secondarySource = src.replace (\"\\x01\", \" \")\n"
  "            #print \"  '\" + secondarySource + \"'\"\n"
  "            modifDate = modificationDateForFile (dateCacheDictionary, secondarySource)\n"
  "            if self.mSecondaryMostRecentModificationDate < modifDate :\n"
  "              self.mSecondaryMostRecentModificationDate = modifDate\n"
  "              #print BOLD_BLUE () + str (modifDate) + ENDC ()\n"
  "    \n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   class Make                                                                                                         *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "class Make:\n"
  "  mRuleList = []\n"
  "  mJobList = []\n"
  "  mErrorCount = 0\n"
  "  mModificationDateDictionary = {}\n"
  "  mGoals = {}\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def addRule (self, rule):\n"
  "    self.mRuleList.append (copy.deepcopy (rule))\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def printRules (self):\n"
  "    print BOLD_BLUE () + \"--- Print the \" + str (len (self.mRuleList)) + \" rule\" + (\"s\" if len (self.mRuleList) > 1 else \"\") + \" ---\" + ENDC ()\n"
  "    for rule in self.mRuleList:\n"
  "      print BOLD_GREEN () + \"Target: '\" + rule.mTarget + \"'\" + ENDC ()\n"
  "      for dep in rule.mDependences:\n"
  "        print \"  Dependence: '\" + dep + \"'\"\n"
  "      s = \"  Command: \"\n"
  "      for cmd in rule.mCommand:\n"
  "        s += \" \\\"\" + cmd + \"\\\"\"\n"
  "      print s\n"
  "      print \"  Title: '\" + rule.mTitle + \"'\"\n"
  "      index = 0\n"
  "      for (command, title) in rule.mPostCommands:\n"
  "        index = index + 1\n"
  "        s = \"  Post command \" + str (index) + \": \"\n"
  "        for cmd in command:\n"
  "          s += \" \\\"\" + cmd + \"\\\"\"\n"
  "        print s\n"
  "        print \"  Its title: '\" + title + \"'\"\n"
  "        \n"
  "    print BOLD_BLUE () + \"--- End of print rule ---\" + ENDC ()\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def writeRuleDependancesInDotFile (self, dotFileName):\n"
  "    s = \"digraph G {\\n\"\n"
  "    s += \"  node [fontname=courier]\\n\"\n"
  "    arrowSet = set ()\n"
  "    for rule in self.mRuleList:\n"
  "      s += '  \"' + rule.mTarget + '\" [shape=rectangle]\\n'\n"
  "      for dep in rule.mDependences:\n"
  "        arrowSet.add ('  \"' + rule.mTarget + '\" -> \"' + dep + '\"\\n')\n"
  "    for arrow in arrowSet:\n"
  "      s += arrow\n"
  "    s += \"}\\n\"\n"
  "    f = open (dotFileName, \"w\")\n"
  "    f.write (s)\n"
  "    f.close ()\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def checkRules (self):\n"
  "    if self.mErrorCount == 0:\n"
  "      ruleList = copy.deepcopy (self.mRuleList)\n"
  "      index = 0\n"
  "      looping = True\n"
  "    #--- loop on rules\n"
  "      while looping:\n"
  "        looping = False\n"
  "        while index < len (ruleList):\n"
  "          aRule = ruleList [index]\n"
  "          index = index + 1\n"
  "        #--- Check dependance files have rule for building, or does exist\n"
  "          depIdx = 0\n"
  "          while depIdx < len (aRule.mDependences):\n"
  "            dep = aRule.mDependences [depIdx]\n"
  "            depIdx = depIdx + 1\n"
  "            hasBuildRule = False\n"
  "            for r in ruleList:\n"
  "              if dep == r.mTarget:\n"
  "                hasBuildRule = True\n"
  "                break\n"
  "            if not hasBuildRule:\n"
  "              looping = True\n"
  "              if not os.path.exists (os.path.abspath (dep)):\n"
  "                self.mErrorCount = self.mErrorCount + 1\n"
  "                print BOLD_RED () + \"Check rules error: '\" + dep + \"' does not exist, and there is no rule for building it.\" + ENDC ()\n"
  "              depIdx = depIdx - 1\n"
  "              aRule.mDependences.pop (depIdx)\n"
  "        #--- Rule with no dependances\n"
  "          if len (aRule.mDependences) == 0 :\n"
  "            looping = True\n"
  "            index = index - 1\n"
  "            ruleList.pop (index)\n"
  "            idx = 0\n"
  "            while idx < len (ruleList):\n"
  "              r = ruleList [idx]\n"
  "              idx = idx + 1\n"
  "              while r.mDependences.count (aRule.mTarget) > 0 :\n"
  "                r.mDependences.remove (aRule.mTarget)\n"
  "    #--- Error if rules remain\n"
  "      if len (ruleList) > 0:\n"
  "        self.mErrorCount = self.mErrorCount + 1\n"
  "        print BOLD_RED () + \"Check rules error; circulary dependances between:\" + ENDC ()\n"
  "        for aRule in ruleList: \n"
  "          print BOLD_RED () + \"  - '\" + aRule.mTarget + \"', depends from:\" + ENDC ()\n"
  "          for dep in aRule.mDependences:\n"
  "            print BOLD_RED () + \"      '\" + dep + \"'\" + ENDC ()\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def existsJobForTarget (self, target):\n"
  "    for job in self.mJobList:\n"
  "      if job.mTarget == target:\n"
  "        return True\n"
  "    return False\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def makeJob (self, target): # Return a bool indicating wheither the target should be built\n"
  "  #--- If there are errors, return immediatly\n"
  "    if self.mErrorCount != 0:\n"
  "      return False\n"
  "  #--- Target already in job list \?\n"
  "    if self.existsJobForTarget (target):\n"
  "      return True # yes, return target will be built\n"
  "  #--- Find a rule for making the target\n"
  "    absTarget = os.path.abspath (target)\n"
  "    rule = None\n"
  "    matchCount = 0\n"
  "    for r in self.mRuleList:\n"
  "      if target == r.mTarget:\n"
  "        matchCount = matchCount + 1\n"
  "        rule = r\n"
  "    if matchCount == 0:\n"
  "      absTarget = os.path.abspath (target)\n"
  "      if not os.path.exists (absTarget):\n"
  "        print BOLD_RED () + \"No rule for making '\" + target + \"'\" + ENDC ()\n"
  "        self.mErrorCount = self.mErrorCount + 1\n"
  "      return False # Error or target exists, and no rule for building it\n"
  "    elif matchCount > 1:\n"
  "      print BOLD_RED () + str (matchCount) + \" rules for making '\" + target + \"'\" + ENDC ()\n"
  "      self.mErrorCount = self.mErrorCount + 1\n"
  "      return False # Error\n"
  "  #--- Target file does not exist, and 'rule' variable indicates how build it\n"
  "    appendToJobList = not os.path.exists (absTarget)\n"
  "  #--- Build primary dependences\n"
  "    jobDependenceFiles = []\n"
  "    for dependence in rule.mDependences:\n"
  "      willBeBuilt = self.makeJob (dependence)\n"
  "      if willBeBuilt:\n"
  "        jobDependenceFiles.append (dependence)\n"
  "        appendToJobList = True\n"
  "  #--- Check primary file modification dates\n"
  "    if not appendToJobList:\n"
  "      targetDateModification = os.path.getmtime (absTarget)\n"
  "      for source in rule.mDependences:\n"
  "        sourceDateModification = os.path.getmtime (source)\n"
  "        if targetDateModification < sourceDateModification:\n"
  "          appendToJobList = True\n"
  "          break\n"
  "  #--- Check for secondary dependancy files\n"
  "    if not appendToJobList:\n"
  "      targetDateModification = os.path.getmtime (absTarget)\n"
  "      if targetDateModification < rule.mSecondaryMostRecentModificationDate:\n"
  "        appendToJobList = True\n"
  "  #--- Append to job list\n"
  "    if appendToJobList:\n"
  "      self.mJobList.append (Job (target, jobDependenceFiles, rule.mCommand, rule.mPostCommands, rule.mPriority, rule.mTitle))\n"
  "  #--- Return\n"
  "    return appendToJobList\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "  #Job state\n"
  "  # 0: waiting\n"
  "  # 1:running\n"
  "  # 2: waiting for executing post command\n"
  "  # 3:executing for executing post command\n"
  "  # 4: completed\n"
  "\n"
  "  def runJobs (self, maxConcurrentJobs, showCommand):\n"
  "    if self.mErrorCount == 0:\n"
  "      if len (self.mJobList) == 0:\n"
  "        print BOLD_BLUE () + \"Nothing to make.\" + ENDC ()\n"
  "      else:\n"
  "      #--- Sort jobs following their priorities\n"
  "        self.mJobList = sorted (self.mJobList, key=operator.attrgetter(\"mPriority\"), reverse=True)\n"
  "      #--- Run\n"
  "        if maxConcurrentJobs <= 0:\n"
  "          maxConcurrentJobs = processorCount () - maxConcurrentJobs\n"
  "        jobCount = 0 ;\n"
  "        terminationSemaphore = threading.Semaphore (0)\n"
  "        displayLock = threading.Lock ()\n"
  "        loop = True\n"
  "        returnCode = 0\n"
  "        while loop:\n"
  "        #--- Launch jobs in parallel\n"
  "          for job in self.mJobList:\n"
  "            if (returnCode == 0) and (jobCount < maxConcurrentJobs):\n"
  "              if (job.mState == 0) and (len (job.mRequiredFiles) == 0):\n"
  "                #--- Create target directory if does not exist\n"
  "                absTargetDirectory = os.path.dirname (os.path.abspath (job.mTarget))\n"
  "                if not os.path.exists (absTargetDirectory):\n"
  "                  displayLock.acquire ()\n"
  "                  runHiddenCommand ([\"mkdir\", \"-p\", absTargetDirectory])\n"
  "                  # runCommand ([\"mkdir\", \"-p\", absTargetDirectory], \"Making \" + absTargetDirectory + \" directory\", showCommand)\n"
  "                  displayLock.release ()\n"
  "                #--- Run job\n"
  "                job.run (displayLock, terminationSemaphore, showCommand)\n"
  "                jobCount = jobCount + 1\n"
  "                job.mState = 1 # Means is running\n"
  "              elif job.mState == 2: # Waiting for executing post command\n"
  "                job.mReturnCode = None # Means post command not terminated\n"
  "                job.runPostCommand (displayLock, terminationSemaphore, showCommand)\n"
  "                jobCount = jobCount + 1\n"
  "                job.mState = 3 # Means post command is running\n"
  "        #--- Wait for a job termination\n"
  "          #print \"wait \" + str (jobCount) + \" \" + str (len (self.mJobList))\n"
  "          terminationSemaphore.acquire ()\n"
  "        #--- Checks for terminated jobs\n"
  "          index = 0\n"
  "          while index < len (self.mJobList):\n"
  "            job = self.mJobList [index]\n"
  "            index = index + 1\n"
  "            if (job.mState == 1) and (job.mReturnCode == 0) : # Terminated without error\n"
  "              jobCount = jobCount - 1\n"
  "              if len (job.mPostCommands) > 0:\n"
  "                job.mState = 2 # Ready to execute next post command\n"
  "              else:\n"
  "                job.mState = 4 # Completed\n"
  "                index = index - 1 # For removing job from list\n"
  "            elif (job.mState == 1) and (job.mReturnCode > 0) : # terminated with error : exit\n"
  "              jobCount = jobCount - 1\n"
  "              job.mState = 4 # Means Terminated\n"
  "              index = index - 1 # For removing job from list\n"
  "            elif (job.mState == 3) and (job.mReturnCode == 0): # post command is terminated without error\n"
  "              jobCount = jobCount - 1\n"
  "              job.mPostCommands.pop (0) # Remove completed post command\n"
  "              if len (job.mPostCommands) > 0:\n"
  "                job.mState = 2 # Ready to execute next post command\n"
  "              else:\n"
  "                job.mState = 4 # Completed\n"
  "                index = index - 1 # For removing job from list\n"
  "            elif (job.mState == 3) and (job.mReturnCode > 0): # post command is terminated with error\n"
  "              jobCount = jobCount - 1\n"
  "              job.mState = 4 # Completed\n"
  "              index = index - 1 # For removing job from list\n"
  "            elif job.mState == 4: # Completed: delete job\n"
  "              index = index - 1\n"
  "              self.mJobList.pop (index) # Remove terminated job\n"
  "              #displayLock.acquire ()\n"
  "              #print \"Completed '\" + job.mTitle + \"'\"\n"
  "              #--- Remove dependences from this job\n"
  "              idx = 0\n"
  "              while idx < len (self.mJobList):\n"
  "                aJob = self.mJobList [idx]\n"
  "                idx = idx + 1\n"
  "                while aJob.mRequiredFiles.count (job.mTarget) > 0 :\n"
  "                  aJob.mRequiredFiles.remove (job.mTarget)\n"
  "                  #print \"  Removed from '\" + aJob.mTitle + \"': \" + str (len (aJob.mRequiredFiles))\n"
  "              #displayLock.release ()\n"
  "              #--- Signal error \?\n"
  "              if (job.mReturnCode > 0) and (returnCode == 0):\n"
  "                self.mErrorCount = self.mErrorCount + 1\n"
  "                print BOLD_RED () + \"Return code: \" + str (job.mReturnCode) + ENDC ()\n"
  "                if (returnCode == 0) and (jobCount > 0) :\n"
  "                  print \"Wait for job termination...\"\n"
  "                returnCode = job.mReturnCode\n"
  "          loop = (len (self.mJobList) > 0) if (returnCode == 0) else (jobCount > 0)\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def searchFileInDirectories (self, file, directoryList): # returns \"\" if not found, register error\n"
  "    matchCount = 0\n"
  "    result = \"\"\n"
  "    for sourceDir in directoryList:\n"
  "      sourcePath = sourceDir + \"/\" + file\n"
  "      if os.path.exists (os.path.abspath (sourcePath)):\n"
  "        matchCount = matchCount + 1\n"
  "        result = sourcePath\n"
  "    if matchCount == 0:\n"
  "      print BOLD_RED () + \"Cannot find '\" + file + \"'\" + ENDC ()\n"
  "      self.mErrorCount = self.mErrorCount + 1\n"
  "    elif matchCount > 1:\n"
  "      print BOLD_RED () + str (matchCount) + \" source files for making '\" + file + \"'\" + ENDC ()\n"
  "      self.mErrorCount = self.mErrorCount + 1\n"
  "      result = \"\"\n"
  "    return result\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def addGoal (self, goal, targetList, message):\n"
  "    self.mGoals [goal] = (targetList, message)\n"
  "    #print '%s' % ', '.join(map(str, self.mGoals))\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def printGoals (self):\n"
  "    print BOLD_BLUE () + \"--- Print the \" + str (len (self.mGoals)) + \" goal\" + (\"s\" if len (self.mGoals) > 1 else \"\") + \" ---\" + ENDC ()\n"
  "    for goalKey in self.mGoals.keys ():\n"
  "      print BOLD_GREEN () + \"Goal: '\" + goalKey + \"'\" + ENDC ()\n"
  "      (targetList, message) = self.mGoals [goalKey]\n"
  "      for target in targetList:\n"
  "        print \"  Target: '\" + target + \"'\"\n"
  "      print \"  Message: '\" + message + \"'\"\n"
  "        \n"
  "    print BOLD_BLUE () + \"--- End of print goals ---\" + ENDC ()\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def runGoal (self, goal, maxConcurrentJobs, showCommand):\n"
  "    if self.mGoals.has_key (goal) :\n"
  "      (targetList, message) = self.mGoals [goal]\n"
  "      for target in targetList:\n"
  "        self.makeJob (target)\n"
  "      self.runJobs (maxConcurrentJobs, showCommand)\n"
  "    else:\n"
  "      errorMessage = \"The '\" + goal + \"' goal is not defined; defined goals:\"\n"
  "      for key in self.mGoals:\n"
  "        (targetList, message) = self.mGoals [key]\n"
  "        errorMessage += \"\\n  '\" + key + \"': \" + message\n"
  "      print BOLD_RED () + errorMessage + ENDC ()\n"
  "      self.mErrorCount = self.mErrorCount + 1\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def enterError (self, message):\n"
  "    print BOLD_RED () + message + ENDC ()\n"
  "    self.mErrorCount = self.mErrorCount + 1\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def printErrorCountAndExitOnError (self):\n"
  "    if self.mErrorCount == 1:\n"
  "      print BOLD_RED () + \"1 error.\" + ENDC ()\n"
  "      sys.exit (1)\n"
  "    elif self.mErrorCount > 1:\n"
  "      print BOLD_RED () + str (self.mErrorCount) + \" errors.\" + ENDC ()\n"
  "      sys.exit (1)\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def printErrorCount (self):\n"
  "    if self.mErrorCount == 1:\n"
  "      print BOLD_RED () + \"1 error.\" + ENDC ()\n"
  "    elif self.mErrorCount > 1:\n"
  "      print BOLD_RED () + str (self.mErrorCount) + \" errors.\" + ENDC ()\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def errorCount (self):\n"
  "    return self.mErrorCount\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_0_embeddedTargets (
  "make.py",
  "py",
  true, // Text file
  27516, // Text length
  gWrapperFileContent_0_embeddedTargets
) ;

//--- File '/plm.py'

const char * gWrapperFileContent_1_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import sys, os, subprocess, urllib\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "import make\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   Run process and wait for termination                                                                               *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def runProcess (command) :\n"
  "  childProcess = subprocess.Popen (command)\n"
  "#--- Wait for subprocess termination\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.wait ()\n"
  "  if childProcess.returncode != 0 :\n"
  "    print make.BOLD_RED () + \"Error \" + str (childProcess.returncode) + make.ENDC ()\n"
  "    sys.exit (childProcess.returncode)\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   Run process, get output and wait for termination                                                                   *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def runProcessAndGetOutput (command) :\n"
  "  result = \"\"\n"
  "  childProcess = subprocess.Popen (command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)\n"
  "  while True:\n"
  "    out = childProcess.stdout.read(1)\n"
  "    if out == '' and childProcess.poll() != None:\n"
  "      break\n"
  "    if out != '':\n"
  "      result += out\n"
  "#--- Wait for subprocess termination\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.wait ()\n"
  "  if childProcess.returncode != 0 :\n"
  "    print make.BOLD_RED () + \"Error \" + str (childProcess.returncode) + make.ENDC ()\n"
  "    sys.exit (childProcess.returncode)\n"
  "  return result\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   ARCHIVE DOWNLOAD                                                                                                   *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "downloadProgression = 0.0\n"
  "\n"
  "def downloadReportHook (a, b, fileSize) :\n"
  "  global downloadProgression\n"
  "  newProgression = min (100.0, float(a * b) / fileSize * 100.0)\n"
  "  if newProgression > downloadProgression :\n"
  "    downloadProgression = downloadProgression + 1.0\n"
  "    sys.stdout.write(\".\")\n"
  "    sys.stdout.flush()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def downloadArchive (archiveURL, archivePath):\n"
  "  global downloadProgression\n"
  "  downloadProgression = 0.0\n"
  "  make.runHiddenCommand ([\"rm\", \"-f\", archivePath + \".downloading\"])\n"
  "  make.runHiddenCommand ([\"rm\", \"-f\", archivePath + \".tar.bz2\"])\n"
  "  make.runHiddenCommand ([\"mkdir\", \"-p\", os.path.dirname (archivePath)])\n"
  "  #print \"URL: \"+ archiveURL\n"
  "  #print \"Downloading... \" + archivePath + \".downloading\"\n"
  "  try:\n"
  "    urllib.urlretrieve (archiveURL,  archivePath + \".downloading\", downloadReportHook)\n"
  "    print \"\"\n"
  "    fileSize = os.path.getsize (archivePath + \".downloading\")\n"
  "    ok = fileSize > 1000000\n"
  "    if ok:\n"
  "      make.runHiddenCommand ([\"mv\", archivePath + \".downloading\", archivePath + \".tar.bz2\"])\n"
  "    else:\n"
  "      print make.BOLD_RED () + \"Error: cannot download file\" + make.ENDC ()\n"
  "      sys.exit (1)\n"
  "  except:\n"
  "    print make.BOLD_RED () + \"Error: no network connection\" + make.ENDC ()\n"
  "    sys.exit (1)\n"
  "    \n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def runMakefile (toolDirectory, archiveBaseURL, LLVMsourceList, \\\n"
  "                 objectDir, LLCcompiler, llvmOptimizerCompiler, \\\n"
  "                 asAssembler, \\\n"
  "                 productDir, linker, objcopy, \\\n"
  "                 dumpObjectCode, displayObjectSize, runExecutableOnTarget, \\\n"
  "                 currentFile) :\n"
  "  #--- Get max parallel jobs as first argument\n"
  "  goal = \"all\"\n"
  "  if len (sys.argv) > 1 :\n"
  "    goal = sys.argv [1]\n"
  "  #--- Get max parallel jobs as first argument\n"
  "  maxParallelJobs = 0 # 0 means use host processor count\n"
  "  if len (sys.argv) > 2 :\n"
  "    maxParallelJobs = int (sys.argv [2])\n"
  "  #--- Get script absolute path\n"
  "  scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))\n"
  "  #--- Download compiler tool if needed\n"
  "  if not os.path.exists (toolDirectory):\n"
  "    print make.BOLD_GREEN () + \"Downloading compiler tool chain\" + make.ENDC ()\n"
  "    archiveName = os.path.basename (toolDirectory)\n"
  "    archiveURL = archiveBaseURL + archiveName + \".tar.bz2\"\n"
  "    downloadArchive (archiveURL, toolDirectory)\n"
  "    installDir = os.path.normpath (toolDirectory + \"/..\")\n"
  "    os.chdir (installDir)\n"
  "    make.runHiddenCommand ([\"bunzip2\", \"-k\", archiveName + \".tar.bz2\"])\n"
  "    make.runHiddenCommand ([\"rm\", archiveName + \".tar.bz2\"])\n"
  "    make.runHiddenCommand ([\"tar\", \"xf\", archiveName + \".tar\"])\n"
  "    make.runHiddenCommand ([\"rm\", archiveName + \".tar\"])\n"
  "  #---\n"
  "  os.chdir (scriptDir)\n"
  "  print \"Product directory: \" + scriptDir\n"
  "  #--- Build python makefile\n"
  "  makefile = make.Make ()\n"
  "  #--- Add C files compile rule\n"
  "  objectList = []\n"
  "  for source in LLVMsourceList:\n"
  "  #--- Optimize LLVM source\n"
  "    optimizedSource = objectDir + \"/\" + source + \"-opt.ll\"\n"
  "    rule = make.Rule (optimizedSource, \"Optimizing \" + source)\n"
  "    rule.mDependences.append (\"sources/\" + source)\n"
  "    rule.mDependences.append (currentFile)\n"
  "    rule.mCommand += llvmOptimizerCompiler\n"
  "    rule.mCommand += [\"sources/\" + source]\n"
  "    rule.mCommand += [\"-o\", optimizedSource]\n"
  "    makefile.addRule (rule)\n"
  "  #--- Compile LLVM source\n"
  "    asSource = objectDir + \"/\" + source + \".s\"\n"
  "    rule = make.Rule (asSource, \"Compiling \" + optimizedSource)\n"
  "    rule.mDependences.append (optimizedSource)\n"
  "    rule.mCommand += LLCcompiler\n"
  "    rule.mCommand += [optimizedSource]\n"
  "    rule.mCommand += [\"-o\", asSource]\n"
  "    makefile.addRule (rule)\n"
  "  #--- Assembling\n"
  "    asObject = objectDir + \"/\" + source + \".s.o\"\n"
  "    rule = make.Rule (asObject, \"Assembling \" + asSource)\n"
  "    rule.mDependences.append (asSource)\n"
  "    rule.mCommand += asAssembler\n"
  "    rule.mCommand += [asSource]\n"
  "    rule.mCommand += [\"-o\", asObject]\n"
  "    makefile.addRule (rule)\n"
  "    objectList.append (asObject)\n"
  "  #--- Add linker rule\n"
  "  productELF = productDir + \"/product.elf\"\n"
  "  rule = make.Rule (productELF, \"Linking \" + productELF)\n"
  "  rule.mDependences += objectList\n"
  "  rule.mCommand += linker\n"
  "  rule.mCommand += objectList\n"
  "  rule.mCommand += [\"-o\", productELF]\n"
  "  rule.mCommand += [\"-Tsources/linker.ld\"]\n"
  "  rule.mCommand += [\"-Map=\" + productELF + \".map\"]\n"
  "  makefile.addRule (rule)\n"
  "  #--- Add objcopy rule\n"
  "  productHEX = productDir + \"/product.ihex\"\n"
  "  rule = make.Rule (productHEX, \"Hexing \" + productHEX)\n"
  "  rule.mDependences += [productELF]\n"
  "  rule.mCommand += objcopy\n"
  "  rule.mCommand += [\"-O\", \"ihex\"]\n"
  "  rule.mCommand += [productELF]\n"
  "  rule.mCommand += [productHEX]\n"
  "  makefile.addRule (rule)\n"
  "  #--- Add goals\n"
  "  makefile.addGoal (\"run\", [productHEX], \"Building all and run\")\n"
  "  makefile.addGoal (\"all\", [productHEX], \"Building all\")\n"
  "  makefile.addGoal (\"display-object-size\", [productHEX], \"Display Object Size\")\n"
  "  makefile.addGoal (\"object-dump\", [productHEX], \"Dump Object Code\")\n"
  "  #--- Build\n"
  "  #makefile.printRules ()\n"
  "  makefile.runGoal (goal, maxParallelJobs, maxParallelJobs == 1)\n"
  "  #--- Build Ok \?\n"
  "  makefile.printErrorCountAndExitOnError ()\n"
  "  #--- Run or all \? Display size\n"
  "  if (goal == \"run\") or (goal == \"all\") :\n"
  "    s = runProcessAndGetOutput (displayObjectSize + objectList)\n"
  "    secondLine = s.split('\\n')[1]\n"
  "    numbers = [int(s) for s in secondLine.split() if s.isdigit()]\n"
  "    print \"Code:   \" + str (numbers [0]) + \" bytes\"\n"
  "    print \"Data:   \" + str (numbers [1]) + \" bytes\"\n"
  "    print \"Global: \" + str (numbers [2]) + \" bytes\"\n"
  "  #--- Run \?\n"
  "  if goal == \"run\":\n"
  "    print make.BOLD_BLUE () + \"Loading Teensy...\" + make.ENDC ()\n"
  "    runProcess (runExecutableOnTarget + [productHEX])\n"
  "    print make.BOLD_GREEN () + \"Success\" + make.ENDC ()\n"
  "  elif goal == \"display-object-size\":\n"
  "    print make.BOLD_BLUE () + \"Display Object Sizes\" + make.ENDC ()\n"
  "    runProcess (displayObjectSize + objectList)\n"
  "    print make.BOLD_GREEN () + \"Success\" + make.ENDC ()\n"
  "  elif goal == \"object-dump\":\n"
  "    print make.BOLD_BLUE () + \"Dump Object Code\" + make.ENDC ()\n"
  "    runProcess (dumpObjectCode + [productELF])\n"
  "    print make.BOLD_GREEN () + \"Success\" + make.ENDC ()\n"
  "\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_1_embeddedTargets (
  "plm.py",
  "py",
  true, // Text file
  8757, // Text length
  gWrapperFileContent_1_embeddedTargets
) ;

//--- File '/teensy-3-1-interrupt.plm-target'

const char * gWrapperFileContent_2_embeddedTargets = "newUnsignedRepresentation @unsigned8  : \"uint8_t\"   8\n"
  "newUnsignedRepresentation @unsigned16 : \"uint16_t\" 16\n"
  "newUnsignedRepresentation @unsigned32 : \"uint32_t\" 32\n"
  "newUnsignedRepresentation @unsigned64 : \"uint64_t\" 64\n"
  "\n"
  "newSignedRepresentation @signed8  : \"int8_t\"   8\n"
  "newSignedRepresentation @signed16 : \"int16_t\" 16\n"
  "newSignedRepresentation @signed32 : \"int32_t\" 32\n"
  "newSignedRepresentation @signed64 : \"int64_t\" 64\n"
  "\n"
  "newUnsignedRepresentation @size : \"uint32_t\" 32\n"
  "\n"
  "booleanType $bool : @unsigned8\n"
  "\n"
  "newIntegerType $uint8  : @unsigned8\n"
  "newIntegerType $uint16 : @unsigned16\n"
  "newIntegerType $uint32 : @unsigned32\n"
  "newIntegerType $uint64 : @unsigned64\n"
  "newIntegerType $int8  : @signed8\n"
  "newIntegerType $int16 : @signed16\n"
  "newIntegerType $int32 : @signed32\n"
  "newIntegerType $int64 : @signed64\n"
  "\n"
  "exception : $int32 $uint32\n"
  "\n"
  "mode `isr\n"
  "mode `user\n"
  "\n"
  "import \"files/mk20dx256.plm\"\n"
  "import \"files/lcd.plm\"\n"
  "import \"files/leds.plm\"\n"
  "import \"files/default-isr.plm\"\n"
  "\n"
  "required proc setup `user ()\n"
  "required proc loop `user ()\n"
  "\n"
  "boot 10 {\n"
  "//---------1- Inhiber le chien de garde\n"
  "  WDOG_UNLOCK = WDOG_UNLOCK_SEQ1\n"
  "  WDOG_UNLOCK = WDOG_UNLOCK_SEQ2\n"
  "  WDOG_STCTRLH = 0x0010\n"
  "//--- Enable clocks to always-used peripherals\n"
  "  SIM_SCGC3 = SIM_SCGC3_ADC1 | SIM_SCGC3_FTM2\n"
  "  SIM_SCGC5 = 0x00043F82    // clocks active to all GPIO\n"
  "  SIM_SCGC6 = SIM_SCGC6_RTC | SIM_SCGC6_FTM0 | SIM_SCGC6_FTM1 | SIM_SCGC6_ADC0 | SIM_SCGC6_FTFL\n"
  "//--- If the RTC oscillator isn't enabled, get it started early\n"
  "  if not RTC_CR.OSCE.bool then\n"
  "    RTC_SR = 0\n"
  "    RTC_CR = RTC_CR::SC16P | RTC_CR::SC4P | RTC_CR::OSCE\n"
  "  end\n"
  "//--- Release I/O pins hold, if we woke up from VLLS mode\n"
  "  if PMC_REGSC.ACKISO != 0 then\n"
  "    PMC_REGSC |= PMC_REGSC::ACKISO\n"
  "  end\n"
  "// TODO: do this while the PLL is waiting to lock....\n"
  "  VTOR = 0  // use vector table in flash\n"
  "//  // default all interrupts to medium priority level\n"
  "////  for (int32_t i=0; i < NVIC_NUM_INTERRUPTS; i++) NVIC_SET_PRIORITY(i, 128);\n"
  "//---------2- Initialisation de la PLL\n"
  "// start in FEI mode\n"
  "//--- Enable capacitors for crystal\n"
  "  OSC_CR = OSC_CR::SC8P | OSC_CR::SC2P\n"
  "//--- Enable osc, 8-32 MHz range, low power mode\n"
  "  MCG_C2 = MCG_C2::RANGE0(2) | MCG_C2::EREFS\n"
  "//--- Switch to crystal as clock source, FLL input = 16 MHz / 512\n"
  "  MCG_C1 = MCG_C1::CLKS(2) | MCG_C1::FRDIV(4)\n"
  "//--- Wait for crystal oscillator to begin\n"
  "  while MCG_S.OSCINIT0 == 0 do\n"
  "  end\n"
  "//--- Wait for FLL to use oscillator\n"
  "  while MCG_S.IREFST != 0 do\n"
  "  end\n"
  "//--- Wait for MCGOUT to use oscillator\n"
  "  while MCG_S.CLKST != MCG_S::CLKST(2) do\n"
  "  end\n"
  "//--- Now we're in FBE mode\n"
  "//    Config PLL input for 16 MHz Crystal / 4 = 4 MHz\n"
  "  MCG_C5 = MCG_C5::PRDIV0(3)\n"
  "//--- Config PLL for 96 MHz output\n"
  "  MCG_C6 = MCG_C6::PLLS | MCG_C6::VDIV0(0)\n"
  "//--- Wait for PLL to start using xtal as its input\n"
  "  while MCG_S.PLLST == 0 do\n"
  "  end\n"
  "//--- Wait for PLL to lock\n"
  "  while MCG_S.LOCK0 == 0 do\n"
  "  end\n"
  "//--- Now we're in PBE mode\n"
  "//    Config divisors: 96 MHz core, 48 MHz bus, 24 MHz flash\n"
  "  SIM_CLKDIV1 = SIM_CLKDIV1::OUTDIV1(0) | SIM_CLKDIV1::OUTDIV2(1) | SIM_CLKDIV1::OUTDIV4(3)\n"
  "//--- Switch to PLL as clock source, FLL input = 16 MHz / 512\n"
  "  MCG_C1 = MCG_C1::CLKS(0) | MCG_C1::FRDIV(4)\n"
  "//--- Wait for PLL clock to be used\n"
  "  while MCG_S.CLKST != MCG_S::CLKST(3) do\n"
  "  end\n"
  "}\n"
  "\n" ;

const cRegularFileWrapper gWrapperFile_2_embeddedTargets (
  "teensy-3-1-interrupt.plm-target",
  "plm-target",
  true, // Text file
  3208, // Text length
  gWrapperFileContent_2_embeddedTargets
) ;

//--- File '/teensy-3-1-sequential-systick.plm-target'

const char * gWrapperFileContent_3_embeddedTargets = "\n"
  "signedIntegerType 1 -> 128\n"
  "unsignedIntegerType 1 -> 128\n"
  "\n"
  "pointerSize 32\n"
  "\n"
  "exception : $int32 $uint32\n"
  "\n"
  "mode `isr\n"
  "mode `user\n"
  "\n"
  "import \"files/mk20dx256.plm\"\n"
  "import \"files/boot-teensy-3-1.plm\"\n"
  "\n"
  "required proc systickHandler `isr ()\n"
  "required proc setup `user ()\n"
  "required proc loop `user ()\n"
  "\n"
  "proc systickHandler `isr @weak () {\n"
  "}\n"
  "\n"
  "init 0 { // Configure Systick interrupt every ms\n"
  "  SYST_RVR = 96000 - 1 // Interrupt every 96000 core clocks, i.e. every ms\n"
  "  SYST_CVR = 0\n"
  "  SYST_CSR = SYST_CSR::CLKSOURCE | SYST_CSR::TICKINT | SYST_CSR::ENABLE\n"
  "}\n" ;

const cRegularFileWrapper gWrapperFile_3_embeddedTargets (
  "teensy-3-1-sequential-systick.plm-target",
  "plm-target",
  true, // Text file
  536, // Text length
  gWrapperFileContent_3_embeddedTargets
) ;

//--- File 'files/boot-teensy-3-1.plm'

const char * gWrapperFileContent_4_embeddedTargets = "//-----------------------------------------------------------------------------*\n"
  "\n"
  "boot 0 {\n"
  "//---------1- Inhiber le chien de garde\n"
  "  WDOG_UNLOCK = WDOG_UNLOCK_SEQ1\n"
  "  WDOG_UNLOCK = WDOG_UNLOCK_SEQ2\n"
  "  WDOG_STCTRLH = 0x0010\n"
  "//--- Enable clocks to always-used peripherals\n"
  "  SIM_SCGC3 = SIM_SCGC3_ADC1 | SIM_SCGC3_FTM2\n"
  "  SIM_SCGC5 = 0x00043F82    // clocks active to all GPIO\n"
  "  SIM_SCGC6 = SIM_SCGC6_RTC | SIM_SCGC6_FTM0 | SIM_SCGC6_FTM1 | SIM_SCGC6_ADC0 | SIM_SCGC6_FTFL\n"
  "//--- If the RTC oscillator isn't enabled, get it started early\n"
  "  if not RTC_CR.OSCE.bool then\n"
  "    RTC_SR = 0\n"
  "    RTC_CR = RTC_CR::SC16P | RTC_CR::SC4P | RTC_CR::OSCE\n"
  "  end\n"
  "//--- Release I/O pins hold, if we woke up from VLLS mode\n"
  "  if PMC_REGSC.ACKISO != 0 then\n"
  "    PMC_REGSC |= PMC_REGSC::ACKISO\n"
  "  end\n"
  "// TODO: do this while the PLL is waiting to lock....\n"
  "  VTOR = 0  // use vector table in flash\n"
  "//  // default all interrupts to medium priority level\n"
  "////  for (int32_t i=0; i < NVIC_NUM_INTERRUPTS; i++) NVIC_SET_PRIORITY(i, 128);\n"
  "//---------2- Initialisation de la PLL\n"
  "// start in FEI mode\n"
  "//--- Enable capacitors for crystal\n"
  "  OSC_CR = OSC_CR::SC8P | OSC_CR::SC2P\n"
  "//--- Enable osc, 8-32 MHz range, low power mode\n"
  "  MCG_C2 = MCG_C2::RANGE0(2) | MCG_C2::EREFS\n"
  "//--- Switch to crystal as clock source, FLL input = 16 MHz / 512\n"
  "  MCG_C1 = MCG_C1::CLKS(2) | MCG_C1::FRDIV(4)\n"
  "//--- Wait for crystal oscillator to begin\n"
  "  while MCG_S.OSCINIT0 == 0 do\n"
  "  end\n"
  "//--- Wait for FLL to use oscillator\n"
  "  while MCG_S.IREFST != 0 do\n"
  "  end\n"
  "//--- Wait for MCGOUT to use oscillator\n"
  "  while MCG_S.CLKST != MCG_S::CLKST(2) do\n"
  "  end\n"
  "//--- Now we're in FBE mode\n"
  "//    Config PLL input for 16 MHz Crystal / 4 = 4 MHz\n"
  "  MCG_C5 = MCG_C5::PRDIV0(3)\n"
  "//--- Config PLL for 96 MHz output\n"
  "  MCG_C6 = MCG_C6::PLLS | MCG_C6::VDIV0(0)\n"
  "//--- Wait for PLL to start using xtal as its input\n"
  "  while MCG_S.PLLST == 0 do\n"
  "  end\n"
  "//--- Wait for PLL to lock\n"
  "  while MCG_S.LOCK0 == 0 do\n"
  "  end\n"
  "//--- Now we're in PBE mode\n"
  "//    Config divisors: 96 MHz core, 48 MHz bus, 24 MHz flash\n"
  "  SIM_CLKDIV1 = SIM_CLKDIV1::OUTDIV1(0) | SIM_CLKDIV1::OUTDIV2(1) | SIM_CLKDIV1::OUTDIV4(3)\n"
  "//--- Switch to PLL as clock source, FLL input = 16 MHz / 512\n"
  "  MCG_C1 = MCG_C1::CLKS(0) | MCG_C1::FRDIV(4)\n"
  "//--- Wait for PLL clock to be used\n"
  "  while MCG_S.CLKST != MCG_S::CLKST(3) do\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n" ;

const cRegularFileWrapper gWrapperFile_4_embeddedTargets (
  "boot-teensy-3-1.plm",
  "plm",
  true, // Text file
  2377, // Text length
  gWrapperFileContent_4_embeddedTargets
) ;

//--- File 'files/default-isr.plm'

const char * gWrapperFileContent_5_embeddedTargets = "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc NMIHandler `isr ()\n"
  "\n"
  "proc NMIHandler `isr @weak () {\n"
  "  throw 2\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc HardFaultHandler `isr ()\n"
  "\n"
  "proc HardFaultHandler `isr @weak () {\n"
  "  throw 3\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc MemManageHandler `isr ()\n"
  "\n"
  "proc MemManageHandler `isr @weak () {\n"
  "  throw 4\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc BusFaultHandler `isr ()\n"
  "\n"
  "proc BusFaultHandler `isr @weak () {\n"
  "  throw 5\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc UsageFaultHandler `isr ()\n"
  "\n"
  "proc UsageFaultHandler `isr @weak () {\n"
  "  throw 6\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc svcHandler `isr ()\n"
  "\n"
  "proc svcHandler `isr @weak () {\n"
  "  throw 11\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DebugMonitorHandler `isr ()\n"
  "\n"
  "proc DebugMonitorHandler `isr @weak () {\n"
  "  throw 12\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc PendSVHandler `isr ()\n"
  "\n"
  "proc PendSVHandler `isr @weak () {\n"
  "  throw 14\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "init 0 { // Configure Systick interrupt every ms\n"
  "  SYST_RVR = 96000 - 1 // Interrupt every 96000 core clocks, i.e. every ms\n"
  "  SYST_CVR = 0\n"
  "  SYST_CSR = SYST_CSR::CLKSOURCE | SYST_CSR::TICKINT | SYST_CSR::ENABLE\n"
  "}\n"
  "\n"
  "var gCompteur $uint32 = 0 {\n"
  "  @rw proc systickHandler ()\n"
  "  proc waitMS (\?inDuration $uint32)\n"
  "  proc busyWaitingDuringMS (\?inDuration $uint32)\n"
  "}\n"
  "\n"
  "required proc systickHandler `isr ()\n"
  "\n"
  "proc systickHandler `isr @weak () {\n"
  "  gCompteur &++\n"
  "  userSystickHandler ()\n"
  "}\n"
  "\n"
  "proc userSystickHandler `isr @weak () {\n"
  "}\n"
  "\n"
  "proc waitMS `user `init (\?inDuration $uint32) {\n"
  "  let deadline = gCompteur + inDuration\n"
  "  while gCompteur < deadline do\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel0TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel0TranfertCompleteHandler `isr @weak () {\n"
  "  throw 16\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel1TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel1TranfertCompleteHandler `isr @weak () {\n"
  "  throw 17\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel2TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel2TranfertCompleteHandler `isr @weak () {\n"
  "  throw 18\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel3TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel3TranfertCompleteHandler `isr @weak () {\n"
  "  throw 19\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel4TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel4TranfertCompleteHandler `isr @weak () {\n"
  "  throw 20\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel5TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel5TranfertCompleteHandler `isr @weak () {\n"
  "  throw 21\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel6TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel6TranfertCompleteHandler `isr @weak () {\n"
  "  throw 22\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel7TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel7TranfertCompleteHandler `isr @weak () {\n"
  "  throw 23\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel8TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel8TranfertCompleteHandler `isr @weak () {\n"
  "  throw 24\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel9TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel9TranfertCompleteHandler `isr @weak () {\n"
  "  throw 25\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel10TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel10TranfertCompleteHandler `isr @weak () {\n"
  "  throw 26\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel11TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel11TranfertCompleteHandler `isr @weak () {\n"
  "  throw 27\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel12TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel12TranfertCompleteHandler `isr @weak () {\n"
  "  throw 28\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel13TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel13TranfertCompleteHandler `isr @weak () {\n"
  "  throw 29\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel14TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel14TranfertCompleteHandler `isr @weak () {\n"
  "  throw 30\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAChannel15TranfertCompleteHandler `isr ()\n"
  "\n"
  "proc DMAChannel15TranfertCompleteHandler `isr @weak () {\n"
  "  throw 31\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DMAErrorHandler `isr ()\n"
  "\n"
  "proc DMAErrorHandler `isr @weak () {\n"
  "  throw 32\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc flashMemoryCommandCompleteHandler `isr ()\n"
  "\n"
  "proc flashMemoryCommandCompleteHandler `isr @weak () {\n"
  "  throw 34\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc flashMemoryReadCollisionHandler `isr ()\n"
  "\n"
  "proc flashMemoryReadCollisionHandler `isr @weak () {\n"
  "  throw 35\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc modeControllerHandler `isr ()\n"
  "\n"
  "proc modeControllerHandler `isr @weak () {\n"
  "  throw 36\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc LLWUHandler `isr ()\n"
  "\n"
  "proc LLWUHandler `isr @weak () {\n"
  "  throw 37\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc WDOGEWMHandler `isr ()\n"
  "\n"
  "proc WDOGEWMHandler `isr @weak () {\n"
  "  throw 38\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc I2C0Handler `isr ()\n"
  "\n"
  "proc I2C0Handler `isr @weak () {\n"
  "  throw 40\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc I2C1Handler `isr ()\n"
  "\n"
  "proc I2C1Handler `isr @weak () {\n"
  "  throw 41\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc SPI0Handler `isr ()\n"
  "\n"
  "proc SPI0Handler `isr @weak () {\n"
  "  throw 42\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc SPI1Handler `isr ()\n"
  "\n"
  "proc SPI1Handler `isr @weak () {\n"
  "  throw 43\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc CAN0MessageBufferHandler `isr ()\n"
  "\n"
  "proc CAN0MessageBufferHandler `isr @weak () {\n"
  "  throw 45\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc CAN0BusOffHandler `isr ()\n"
  "\n"
  "proc CAN0BusOffHandler `isr @weak () {\n"
  "  throw 46\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc CAN0ErrorHandler `isr ()\n"
  "\n"
  "proc CAN0ErrorHandler `isr @weak () {\n"
  "  throw 47\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc CAN0TransmitWarningHandler `isr ()\n"
  "\n"
  "proc CAN0TransmitWarningHandler `isr @weak () {\n"
  "  throw 48\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc CAN0ReceiveWarningHandler `isr ()\n"
  "\n"
  "proc CAN0ReceiveWarningHandler `isr @weak () {\n"
  "  throw 49\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc CAN0WakeUpHandler `isr ()\n"
  "\n"
  "proc CAN0WakeUpHandler `isr @weak () {\n"
  "  throw 50\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc I2S0TransmitHandler `isr ()\n"
  "\n"
  "proc I2S0TransmitHandler `isr @weak () {\n"
  "  throw 51\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc I2S0ReceiveHandler `isr ()\n"
  "\n"
  "proc I2S0ReceiveHandler `isr @weak () {\n"
  "  throw 52\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc UART0LONHandler `isr ()\n"
  "\n"
  "proc UART0LONHandler `isr @weak () {\n"
  "  throw 60\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc UART0StatusHandler `isr ()\n"
  "\n"
  "proc UART0StatusHandler `isr @weak () {\n"
  "  throw 61\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc UART0ErrorHandler `isr ()\n"
  "\n"
  "proc UART0ErrorHandler `isr @weak () {\n"
  "  throw 62\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc UART1StatusHandler `isr ()\n"
  "\n"
  "proc UART1StatusHandler `isr @weak () {\n"
  "  throw 63\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc UART1ErrorHandler `isr ()\n"
  "\n"
  "proc UART1ErrorHandler `isr @weak () {\n"
  "  throw 64\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc UART2StatusHandler `isr ()\n"
  "\n"
  "proc UART2StatusHandler `isr @weak () {\n"
  "  throw 64\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc UART2ErrorHandler `isr ()\n"
  "\n"
  "proc UART2ErrorHandler `isr @weak () {\n"
  "  throw 65\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc ADC0Handler `isr ()\n"
  "\n"
  "proc ADC0Handler `isr @weak () {\n"
  "  throw 73\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc ADC1Handler `isr ()\n"
  "\n"
  "proc ADC1Handler `isr @weak () {\n"
  "  throw 74\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc CMP0Handler `isr ()\n"
  "\n"
  "proc CMP0Handler `isr @weak () {\n"
  "  throw 75\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc CMP1Handler `isr ()\n"
  "\n"
  "proc CMP1Handler `isr @weak () {\n"
  "  throw 76\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc CMP2Handler `isr ()\n"
  "\n"
  "proc CMP2Handler `isr @weak () {\n"
  "  throw 77\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc FMT0Handler `isr ()\n"
  "\n"
  "proc FMT0Handler `isr @weak () {\n"
  "  throw 78\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc FMT1Handler `isr ()\n"
  "\n"
  "proc FMT1Handler `isr @weak () {\n"
  "  throw 79\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc FMT2Handler `isr ()\n"
  "\n"
  "proc FMT2Handler `isr @weak () {\n"
  "  throw 80\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc CMTHandler `isr ()\n"
  "\n"
  "proc CMTHandler `isr @weak () {\n"
  "  throw 81\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc RTCAlarmHandler `isr ()\n"
  "\n"
  "proc RTCAlarmHandler `isr @weak () {\n"
  "  throw 82\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc RTCSecondHandler `isr ()\n"
  "\n"
  "proc RTCSecondHandler `isr @weak () {\n"
  "  throw 83\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc PITChannel0Handler `isr ()\n"
  "\n"
  "proc PITChannel0Handler `isr @weak () {\n"
  "  throw 84\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc PITChannel1Handler `isr ()\n"
  "\n"
  "proc PITChannel1Handler `isr @weak () {\n"
  "  throw 85\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc PITChannel2Handler `isr ()\n"
  "\n"
  "proc PITChannel2Handler `isr @weak () {\n"
  "  throw 86\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc PITChannel3Handler `isr ()\n"
  "\n"
  "proc PITChannel3Handler `isr @weak () {\n"
  "  throw 87\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc PDBHandler `isr ()\n"
  "\n"
  "proc PDBHandler `isr @weak () {\n"
  "  throw 88\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc USBOTGHandler `isr ()\n"
  "\n"
  "proc USBOTGHandler `isr @weak () {\n"
  "  throw 89\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc USBChargerDetectHandler `isr ()\n"
  "\n"
  "proc USBChargerDetectHandler `isr @weak () {\n"
  "  throw 90\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc DAC0Handler `isr ()\n"
  "\n"
  "proc DAC0Handler `isr @weak () {\n"
  "  throw 97\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc TSIHandler `isr ()\n"
  "\n"
  "proc TSIHandler `isr @weak () {\n"
  "  throw 99\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc MCGHandler `isr ()\n"
  "\n"
  "proc MCGHandler `isr @weak () {\n"
  "  throw 100\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc lowPowerTimerHandler `isr ()\n"
  "\n"
  "proc lowPowerTimerHandler `isr @weak () {\n"
  "  throw 101\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc pinDetectPortAHandler `isr ()\n"
  "\n"
  "proc pinDetectPortAHandler `isr @weak () {\n"
  "  throw 103\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc pinDetectPortBHandler `isr ()\n"
  "\n"
  "proc pinDetectPortBHandler `isr @weak () {\n"
  "  throw 104\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc pinDetectPortCHandler `isr ()\n"
  "\n"
  "proc pinDetectPortCHandler `isr @weak () {\n"
  "  throw 105\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc pinDetectPortDHandler `isr ()\n"
  "\n"
  "proc pinDetectPortDHandler `isr @weak () {\n"
  "  throw 106\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc pinDetectPortEHandler `isr ()\n"
  "\n"
  "proc pinDetectPortEHandler `isr @weak () {\n"
  "  throw 107\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "required proc softwareInterruptHandler `isr ()\n"
  "\n"
  "proc softwareInterruptHandler `isr @weak () {\n"
  "  throw 110\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_5_embeddedTargets (
  "default-isr.plm",
  "plm",
  true, // Text file
  14836, // Text length
  gWrapperFileContent_5_embeddedTargets
) ;

//--- File 'files/lcd.plm'

const char * gWrapperFileContent_6_embeddedTargets = "\n"
  "// http://esd.cs.ucr.edu/labs/interface/interface.html\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "//   PORT CONFIGURATION                                                        *\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "//   D4 : PTB0\n"
  "//   D5 : PTC0\n"
  "//   D6 : PTD1\n"
  "//   D7 : PTB2\n"
  "//   RS : PTB3\n"
  "//   E  : PTB1\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc configurePorts `init () {\n"
  "//--- D4 (PTB0) is a GPIO (input by default)\n"
  "  PORTB_PCR0 = (1 << 8) ;\n"
  "  GPIOB_PDDR |= (1 << 0) ; // Program D4 as output (PTB0)\n"
  "//--- D5 (PTC0) is a GPIO (input by default)\n"
  "  PORTC_PCR0 = (1 << 8) ;\n"
  "  GPIOC_PDDR |= (1 << 0) ; // Program D5 as output (PTC0)\n"
  "//--- D6 (PTD1) is a GPIO (input by default)\n"
  "  PORTD_PCR1 = (1 << 8) ;\n"
  "  GPIOD_PDDR |= (1 << 1) ; // Program D6 as output (PTD1)\n"
  "//--- D7 (PTB2) is a GPIO (input by default)\n"
  "  PORTB_PCR2 = (1 << 8) ;\n"
  "  GPIOB_PDDR |= (1 << 2) ; // Program D7 as output (PTB2)\n"
  "//--- RS (PTB3) is an output\n"
  "  PORTB_PCR3 = (1 << 8) ;\n"
  "  GPIOB_PDDR |= (1 << 3) ;\n"
  "//--- E (PTB1) is an output\n"
  "  PORTB_PCR1 = (1 << 8) ;\n"
  "  GPIOB_PDDR |= (1 << 1) ;\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc driveHighE `init `exception `user () {\n"
  "  GPIOB_PSOR = 1 << 1 ; // E is PTB1\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "\n"
  "proc driveLowE `init `exception `user () {\n"
  "  GPIOB_PCOR = 1 << 1 ; // E is PTB1\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "\n"
  "proc driveHighRS `init `exception `user () {\n"
  "  GPIOB_PSOR = 1 << 3 ; // RS is PTB3\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "\n"
  "proc driveLowRS `init `exception `user () {\n"
  "  GPIOB_PCOR = 1 << 3 ; // RS is PTB3\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc setD4 `init `exception `user (\?inValue $bool) { // PTB0\n"
  "  if inValue then\n"
  "    GPIOB_PSOR = 1 << 0 ;\n"
  "  else\n"
  "    GPIOB_PCOR = 1 << 0 ;\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc setD5 `init `exception `user (\?inValue $bool) { // PTC0\n"
  "  if inValue then\n"
  "    GPIOC_PSOR = 1 << 0 ;\n"
  "  else\n"
  "    GPIOC_PCOR = 1 << 0 ;\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc setD6 `init `exception `user (\?inValue $bool) { // PTD1\n"
  "  if inValue then\n"
  "    GPIOD_PSOR = 1 << 1 ;\n"
  "  else\n"
  "    GPIOD_PCOR = 1 << 1 ;\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc setD7 `init `exception `user (\?inValue $bool) { // PTB2\n"
  "  if inValue then\n"
  "    GPIOB_PSOR = 1 << 2 ;\n"
  "  else\n"
  "    GPIOB_PCOR = 1 << 2 ;\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "//   UTILITY ROUTINES                                                          *\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc busyWaitingDuringMS `init (\?inDuration $uint32) {\n"
  "  let deadline = gCompteur + inDuration\n"
  "  while gCompteur < deadline do\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc programLcd4BitDataBusOutput `init (\?inValue $uint8) {\n"
  "  setD4 (!(inValue & 0x01) != 0)\n"
  "  setD5 (!(inValue & 0x02) != 0)\n"
  "  setD6 (!(inValue & 0x04) != 0)\n"
  "  setD7 (!(inValue & 0x08) != 0)\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc write4BitCommand `init (\?inValue $uint8) {\n"
  "  busyWaitingDuringMS (!1) ;\n"
  "  driveLowRS () ;\n"
  "  programLcd4BitDataBusOutput (!inValue) ;\n"
  "  driveHighE () ;\n"
  "  busyWaitingDuringMS (!1) ;\n"
  "  driveLowE () ;\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc write8bitCommand `init (\?inCommand $uint8) {\n"
  "  busyWaitingDuringMS (!1) ;\n"
  "  driveLowRS () ;\n"
  "  programLcd4BitDataBusOutput (!inCommand >> 4) ;\n"
  "  driveHighE () ;\n"
  "  busyWaitingDuringMS (!1) ;\n"
  "  driveLowE () ;\n"
  "  busyWaitingDuringMS (!1) ;\n"
  "  programLcd4BitDataBusOutput (!inCommand) ;\n"
  "  driveHighE () ;\n"
  "  busyWaitingDuringMS (!1) ;\n"
  "  driveLowE () ;\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "//   LCD INIT                                                                  *\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "init 10 {\n"
  "  configurePorts () ;\n"
  "//--- \xC3""\x89""tape 1 : attendre 15 ms\n"
  "  busyWaitingDuringMS (!15) ;\n"
  "//--- \xC3""\x89""tape 2 : \xC3""\xA9""crire la commande 0x30\n"
  "  write4BitCommand (!0x3) ;\n"
  "//--- \xC3""\x89""tape 3 : attendre 4,1 ms (en fait 5 ms)\n"
  "  busyWaitingDuringMS (!5) ;\n"
  "//--- \xC3""\x89""tape 4 : \xC3""\xA9""crire la commande 0x30 une 2e fois\n"
  "  write4BitCommand (!0x3) ;\n"
  "//--- \xC3""\x89""tape 5 : attendre 100 \xC2""\xB5""s\n"
  "  busyWaitingDuringMS (!1) ;\n"
  "//--- \xC3""\x89""tape 6 : \xC3""\xA9""crire la commande 0x30 une 3e fois\n"
  "  write4BitCommand (!0x3) ;\n"
  "//--- \xC3""\x89""tape 7 : \xC3""\xA9""crire la commande 0x20 pour passer en 4 bits\n"
  "  write4BitCommand (!0x2) ;\n"
  "//--- \xC3""\x89""tape 8 : \xC3""\xA9""crire la commande 'Set Interface Length' : 0 0 1 DL N F * *\n"
  "//    DL : Data interface length : 0 (4 bits)\n"
  "//    N : Number of Display lines : 1 (2 lignes)\n"
  "//    F : Character Font : 0 (5x7)\n"
  "  write8bitCommand (!0x28) ;\n"
  "//--- \xC3""\x89""tape 9 : \xC3""\xA9""crire la commande 'Display Off'\n"
  "  write8bitCommand (!0x08) ;\n"
  "//--- \xC3""\x89""tape 10 : \xC3""\xA9""crire la commande 'Clear Display'\n"
  "  write8bitCommand (!0x01) ;\n"
  "//--- \xC3""\x89""tape 11 : \xC3""\xA9""crire la commande 'Set Cursor Move Direction' : 0 0 0 0 0 1 ID S\n"
  "//    ID : Increment Cursor after Each Byte Written to Display : 1 (oui)\n"
  "//    S : Shift Display When Byte Written : 0 (non)\n"
  "  write8bitCommand (!0x06) ;\n"
  "//--- \xC3""\x89""tape 12 : \xC3""\xA9""crire la commande 'Move Cursor / Shift Display' : 0 0 0 1 SC RL * *\n"
  "//    SC : Display Shift On : 1 (oui)\n"
  "//    RL : Direction of Shift : 1 (vers la droite)\n"
  "  write8bitCommand (!0x1C) ;\n"
  "//--- \xC3""\x89""tape 13 : \xC3""\xA9""crire la commande 'Return Cursor and LCD to Home Position'\n"
  "  write8bitCommand (!0x02) ;\n"
  "//--- \xC3""\x89""tape 14 : \xC3""\xA9""crire la commande 'Enable Display / Cursor' : 0 0 0 0 1 D C B\n"
  "//    D : Turn Display On : 1 (oui)\n"
  "//    C : Turn Cursor On : 0 (non)\n"
  "//    B : Cursor Blink On : 0 (non)\n"
  "  write8bitCommand (!0x0C) ;\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "//   PRINT ROUTINES IN USER MODE                                               *\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc programLcd4BitDataBusOutput_inUserMode `user @noWarningIfUnused (\?inValue $uint8) {\n"
  "  setD4 (!(inValue & 0x01) != 0)\n"
  "  setD5 (!(inValue & 0x02) != 0)\n"
  "  setD6 (!(inValue & 0x04) != 0)\n"
  "  setD7 (!(inValue & 0x08) != 0)\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc write8bitCommand_inUserMode `user @noWarningIfUnused (\?inCommand $uint8) {\n"
  "  waitMS (!1) ;\n"
  "  driveLowRS () ;\n"
  "  programLcd4BitDataBusOutput_inUserMode (!inCommand >> 4) ;\n"
  "  driveHighE () ;\n"
  "  waitMS (!1) ;\n"
  "  driveLowE () ;\n"
  "  waitMS (!1) ;\n"
  "  programLcd4BitDataBusOutput_inUserMode (!inCommand) ;\n"
  "  driveHighE () ;\n"
  "  waitMS (!1) ;\n"
  "  driveLowE () ;\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc writeData_inUserMode `user @noWarningIfUnused (\?inData $uint8) {\n"
  "  waitMS (!1) ;\n"
  "  driveHighRS () ;\n"
  "  programLcd4BitDataBusOutput_inUserMode (!inData >> 4) ;\n"
  "  driveHighE () ;\n"
  "  waitMS (!1) ;\n"
  "  driveLowE () ;\n"
  "  waitMS (!1) ;\n"
  "  programLcd4BitDataBusOutput_inUserMode (!inData) ;\n"
  "  driveHighE () ;\n"
  "  waitMS (!1) ;\n"
  "  driveLowE () ;\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "// Line 0 : 00 -> 19\n"
  "// Line 1 : 64 -> 83\n"
  "// Line 2 : 20 -> 39\n"
  "// Line 3 : 84 -> 103\n"
  "\n"
  "proc goto `user @noWarningIfUnused (\?line:inLine $uint32 \?column:inColumn $uint8) {\n"
  "  if inColumn < 20 then\n"
  "    if inLine == 0 then\n"
  "      write8bitCommand_inUserMode (!0x80 + 0 + inColumn) ;\n"
  "    elsif inLine == 1 then\n"
  "      write8bitCommand_inUserMode (!0x80 + 64 + inColumn) ;\n"
  "    elsif inLine == 2 then\n"
  "      write8bitCommand_inUserMode (!0x80 + 20 + inColumn) ;\n"
  "    elsif inLine == 3 then\n"
  "      write8bitCommand_inUserMode (!0x80 + 84 + inColumn) ;\n"
  "    end\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "//void printString (const char * inString) {\n"
  "//  if (NULL != inString) {\n"
  "//    while ('\\0' != *inString) {\n"
  "//      writeData (*inString) ;\n"
  "//      inString ++ ;\n"
  "//    }\n"
  "//  }\n"
  "//}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "//void printChar (const char inChar) {\n"
  "//  writeData (inChar) ;\n"
  "//}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc clearScreen `user @noWarningIfUnused () {\n"
  "  write8bitCommand_inUserMode (!0x01)\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc printSpaces `user @noWarningIfUnused (\?inCount $uint32) {\n"
  "  var count = inCount\n"
  "  while (count > 0) do\n"
  "    writeData_inUserMode (!0x20)\n"
  "    count -- ;\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc printUnsigned `user @noWarningIfUnused (\?inValue $uint32) {\n"
  "  var divisor $uint32 = 1_000_000_000\n"
  "  var value = inValue\n"
  "  var isPrinting = false\n"
  "  while divisor > 0 do\n"
  "    if isPrinting or (value >= divisor) then\n"
  "      writeData_inUserMode (!0x30 + ((value / divisor) \\ $uint8))\n"
  "      value = value % divisor\n"
  "      isPrinting = true\n"
  "    end\n"
  "    divisor = divisor / 10\n"
  "  end\n"
  "  if not isPrinting then\n"
  "    writeData_inUserMode (!0x30)\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc printSigned `user @noWarningIfUnused (\?inValue : Int32) {\n"
  "  if inValue >= 0 then\n"
  "    printUnsigned (!inValue &\\ $uint32)\n"
  "  else\n"
  "    writeData_inUserMode (!0x2D) // Signe -\n"
  "    printUnsigned (!(- inValue) &\\ $uint32)\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "//void printSigned (const int32_t inValue) {\n"
  "//  if (inValue < 0) {\n"
  "//    printChar ('-') ;\n"
  "//    printUnsigned (($uint32_t) -inValue) ;\n"
  "//  }else{\n"
  "//    printUnsigned (($uint32_t) inValue) ;\n"
  "//  }\n"
  "//}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "//void printHex1 (const $uint32_t inValue) {\n"
  "//  const $uint32_t v = inValue & 0xF ;\n"
  "//  if (v < 10) {\n"
  "//    printChar ('0' + v) ;\n"
  "//  }else{\n"
  "//    printChar ('A' + v - 10) ;\n"
  "//  }  \n"
  "//}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "//void printHex2 (const $uint32_t inValue) {\n"
  "//  printHex1 (inValue >> 4) ;\n"
  "//  printHex1 (inValue) ;\n"
  "//}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "//void printHex4 (const $uint32_t inValue) {\n"
  "//  printHex2 (inValue >> 8) ;\n"
  "//  printHex2 (inValue) ;\n"
  "//}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "\n"
  "//void printHex8 (const $uint32_t inValue) {\n"
  "//  printHex4 (inValue >> 16) ;\n"
  "//  printHex4 (inValue) ;\n"
  "//}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "//void printHex16 (const $uint64_t inValue) {\n"
  "//  printHex8 (($uint32_t) (inValue >> 32)) ;\n"
  "//  printHex8 (($uint32_t) inValue) ;\n"
  "//}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "//   EXCEPTION                                                                 *\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc programLcd4BitDataBusOutput_inExceptionMode `exception @noWarningIfUnused (\?inValue $uint8) {\n"
  "  setD4 (!(inValue & 0x01) != 0)\n"
  "  setD5 (!(inValue & 0x02) != 0)\n"
  "  setD6 (!(inValue & 0x04) != 0)\n"
  "  setD7 (!(inValue & 0x08) != 0)\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc waitOneMillisecondInExceptionMode `exception @noWarningIfUnused () {\n"
  "  while not SYST_CSR.COUNTFLAG.bool do\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc waitMSInExceptionMode `exception @noWarningIfUnused (\?duration: inDuration $uint32) {\n"
  "  var duration = inDuration\n"
  "  while duration > 0 do\n"
  "    waitOneMillisecondInExceptionMode ()\n"
  "    duration &--\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc writeDataInExceptionMode `exception @noWarningIfUnused (\?inData $uint8) {\n"
  "  waitOneMillisecondInExceptionMode () ;\n"
  "  driveHighRS () ;\n"
  "  programLcd4BitDataBusOutput_inExceptionMode (!inData >> 4) ;\n"
  "  driveHighE () ;\n"
  "  waitOneMillisecondInExceptionMode () ;\n"
  "  driveLowE () ;\n"
  "  waitOneMillisecondInExceptionMode () ;\n"
  "  programLcd4BitDataBusOutput_inExceptionMode (!inData) ;\n"
  "  driveHighE () ;\n"
  "  waitOneMillisecondInExceptionMode () ;\n"
  "  driveLowE () ;\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc printUnsignedInExceptionMode `exception @noWarningIfUnused (\?inValue $uint32) {\n"
  "  var divisor $uint32 = 1_000_000_000\n"
  "  var value = inValue\n"
  "  var isPrinting = false\n"
  "  while divisor > 0 do\n"
  "    if isPrinting or (value >= divisor) then\n"
  "      writeDataInExceptionMode (!0x30 &+ ((value &/ divisor) &\\ $uint8))\n"
  "      value = value &% divisor\n"
  "      isPrinting = true\n"
  "    end\n"
  "    divisor = divisor &/ 10\n"
  "  end\n"
  "  if not isPrinting then\n"
  "    writeDataInExceptionMode (!0x30)\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc printSignedInExceptionMode `exception @noWarningIfUnused (\?inValue : Int32) {\n"
  "  if inValue >= 0 then\n"
  "    printUnsignedInExceptionMode (!inValue &\\ $uint32)\n"
  "  else\n"
  "    writeDataInExceptionMode (!0x2D) // Signe -\n"
  "    printUnsignedInExceptionMode (!(&- inValue) &\\ $uint32)\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc write8bitCommand_inExceptionMode `exception @noWarningIfUnused (\?inCommand $uint8) {\n"
  "  waitOneMillisecondInExceptionMode () ;\n"
  "  driveLowRS () ;\n"
  "  programLcd4BitDataBusOutput_inExceptionMode (!inCommand >> 4) ;\n"
  "  driveHighE () ;\n"
  "  waitOneMillisecondInExceptionMode () ;\n"
  "  driveLowE () ;\n"
  "  waitOneMillisecondInExceptionMode () ;\n"
  "  programLcd4BitDataBusOutput_inExceptionMode (!inCommand) ;\n"
  "  driveHighE () ;\n"
  "  waitOneMillisecondInExceptionMode () ;\n"
  "  driveLowE () ;\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc gotoInExceptionMode `exception @noWarningIfUnused (\?line:inLine $uint32 \?column:inColumn $uint8) {\n"
  "  if inColumn < 20 then\n"
  "    if inLine == 0 then\n"
  "      write8bitCommand_inExceptionMode (!0x80 &+ 0 &+ inColumn) ;\n"
  "    elsif inLine == 1 then\n"
  "      write8bitCommand_inExceptionMode (!0x80 &+ 64 &+ inColumn) ;\n"
  "    elsif inLine == 2 then\n"
  "      write8bitCommand_inExceptionMode (!0x80 &+ 20 &+ inColumn) ;\n"
  "    elsif inLine == 3 then\n"
  "      write8bitCommand_inExceptionMode (!0x80 &+ 84 &+ inColumn) ;\n"
  "    end\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc clearScreenInExceptionMode `exception @noWarningIfUnused () {\n"
  "  write8bitCommand_inExceptionMode (!0x01)\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "exception setup 0 {\n"
  "  clearScreenInExceptionMode ()\n"
  "  waitMSInExceptionMode (!duration:4)\n"
  "  gotoInExceptionMode (!line:0 !column:0)\n"
  "  printSignedInExceptionMode (!CODE)\n"
  "  gotoInExceptionMode (!line:1 !column:0)\n"
  "  printUnsignedInExceptionMode (!LINE)\n"
  "}\n"
  "\n"
  "exception loop 0 {\n"
  "  waitMSInExceptionMode (!duration:50)\n"
  "  ledOn (!LED_L0 | LED_L1 | LED_L2 | LED_L3 | LED_L4 | LED_TEENSY)\n"
  "  waitMSInExceptionMode (!duration:50)\n"
  "  ledOff (!LED_L0 | LED_L1 | LED_L2 | LED_L3 | LED_L4 | LED_TEENSY)\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n" ;

const cRegularFileWrapper gWrapperFile_6_embeddedTargets (
  "lcd.plm",
  "plm",
  true, // Text file
  15511, // Text length
  gWrapperFileContent_6_embeddedTargets
) ;

//--- File 'files/leds.plm'

const char * gWrapperFileContent_7_embeddedTargets = "//-----------------------------------------------------------------------------*\n"
  "//   Led L0 : PTA12\n"
  "//   Led L1 : PTA13\n"
  "//   Led L2 : PTD7\n"
  "//   Led L3 : PTD4\n"
  "//   Led L4 : PTD2\n"
  "//   Led sur carte Teensy : PTC5\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "init 100 {\n"
  "//--- Led L0 : PTA12\n"
  "  PORTA_PCR12 = (1 << 8)\n"
  "  GPIOA_PDDR |= (1 << 12)\n"
  "//--- Led L1 : PTA13\n"
  "  PORTA_PCR13 = (1 << 8)\n"
  "  GPIOA_PDDR |= (1 << 13)\n"
  "//--- Led L2 : PTD13\n"
  "  PORTD_PCR7 = (1 << 8)\n"
  "  GPIOD_PDDR |= (1 << 7)\n"
  "//--- Led L3 : PTD4\n"
  "  PORTD_PCR4 = (1 << 8)\n"
  "  GPIOD_PDDR |= (1 << 4)\n"
  "//--- Led L4 : PTD2\n"
  "  PORTD_PCR2 = (1 << 8)\n"
  "  GPIOD_PDDR |= (1 << 2)\n"
  "//--- Led Teensy\n"
  "  PORTC_PCR5 = (1 << 8)\n"
  "  GPIOC_PDDR |= (1 << 5)\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "let LED_L0 $uint32 = (1 << 0)\n"
  "let LED_L1 $uint32 = (1 << 1)\n"
  "let LED_L2 $uint32 = (1 << 2)\n"
  "let LED_L3 $uint32 = (1 << 3)\n"
  "let LED_L4 $uint32 = (1 << 4)\n"
  "let LED_TEENSY $uint32 = (1 << 5)\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc ledOn `user `exception `isr (\?inLeds $uint32) {\n"
  "//--- Led L0\n"
  "  if ((inLeds & LED_L0) != 0) then\n"
  "    GPIOA_PSOR = 1 << 12 ;\n"
  "  end\n"
  "//--- Led L1\n"
  "  if ((inLeds & LED_L1) != 0) then\n"
  "    GPIOA_PSOR = 1 << 13 ;\n"
  "  end\n"
  "//--- Led L2\n"
  "  if ((inLeds & LED_L2) != 0) then\n"
  "    GPIOD_PSOR = 1 << 7 ;\n"
  "  end\n"
  "//--- Led L3\n"
  "  if ((inLeds & LED_L3) != 0) then\n"
  "    GPIOD_PSOR = 1 << 4 ;\n"
  "  end\n"
  "//--- Led L4\n"
  "  if ((inLeds & LED_L4) != 0) then\n"
  "    GPIOD_PSOR = 1 << 2 ;\n"
  "  end\n"
  "//--- Led Teensy\n"
  "  if ((inLeds & LED_TEENSY) != 0) then\n"
  "    GPIOC_PSOR = 1 << 5 ;\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n"
  "\n"
  "proc ledOff `user `exception `isr (\?inLeds $uint32) {\n"
  "//--- Led L0\n"
  "  if ((inLeds & LED_L0) != 0) then\n"
  "    GPIOA_PCOR = 1 << 12 ;\n"
  "  end\n"
  "//--- Led L1\n"
  "  if ((inLeds & LED_L1) != 0) then\n"
  "    GPIOA_PCOR = 1 << 13 ;\n"
  "  end\n"
  "//--- Led L2\n"
  "  if ((inLeds & LED_L2) != 0) then\n"
  "    GPIOD_PCOR = 1 << 7 ;\n"
  "  end\n"
  "//--- Led L3\n"
  "  if ((inLeds & LED_L3) != 0) then\n"
  "    GPIOD_PCOR = 1 << 4 ;\n"
  "  end\n"
  "//--- Led L4\n"
  "  if ((inLeds & LED_L4) != 0) then\n"
  "    GPIOD_PCOR = 1 << 2 ;\n"
  "  end\n"
  "//--- Led Teensy\n"
  "  if ((inLeds & LED_TEENSY) != 0) then\n"
  "    GPIOC_PCOR = 1 << 5 ;\n"
  "  end\n"
  "}\n"
  "\n"
  "//-----------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_7_embeddedTargets (
  "leds.plm",
  "plm",
  true, // Text file
  2330, // Text length
  gWrapperFileContent_7_embeddedTargets
) ;

//--- File 'files/mk20dx256.plm'

const char * gWrapperFileContent_8_embeddedTargets = "// Teensyduino Core Library\n"
  "// http://www.pjrc.com/teensy/\n"
  "// Copyright (c) 2013 PJRC.COM, LLC.\n"
  "//\n"
  "// Permission is hereby granted, free of charge, to any person obtaining\n"
  "// a copy of this software and associated documentation files (the\n"
  "// \"Software\"), to deal in the Software without restriction, including\n"
  "// without limitation the rights to use, copy, modify, merge, publish,\n"
  "// distribute, sublicense, and/or sell copies of the Software, and to\n"
  "// permit persons to whom the Software is furnished to do so, subject to\n"
  "// the following conditions:\n"
  "//\n"
  "// 1. The above copyright notice and this permission notice shall be \n"
  "// included in all copies or substantial portions of the Software.\n"
  "//\n"
  "// 2. If the Software is incorporated into a build system thallows \n"
  "// selection among a list of target devices, then similar target\n"
  "// devices manufactured by PJRC.COM must be included in the list of\n"
  "// target devices and selectable in the same manner.\n"
  "//\n"
  "// THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND,\n"
  "// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF\n"
  "// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND\n"
  "// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS\n"
  "// BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN\n"
  "// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN\n"
  "// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n"
  "// SOFTWARE.\n"
  "\n"
  "let f_cpu $uint32 = 96_000_000\n"
  "\n"
  "let f_bus $uint32 = 48_000_000\n"
  "let f_mem  $uint32= 24_000_000\n"
  "\n"
  "// chapter 11: Port control and interrupts (PORT)\n"
  " // Pin Control Register n\n"
  "register\n"
  "  PORTA_PCR0   at 0x40049000\n"
  "  PORTA_PCR1   at 0x40049004\n"
  "  PORTA_PCR2   at 0x40049008\n"
  "  PORTA_PCR3   at 0x4004900C\n"
  "  PORTA_PCR4   at 0x40049010\n"
  "  PORTA_PCR5   at 0x40049014\n"
  "  PORTA_PCR6   at 0x40049018\n"
  "  PORTA_PCR7   at 0x4004901C\n"
  "  PORTA_PCR8   at 0x40049020\n"
  "  PORTA_PCR9   at 0x40049024\n"
  "  PORTA_PCR10  at 0x40049028\n"
  "  PORTA_PCR11  at 0x4004902C\n"
  "  PORTA_PCR12  at 0x40049030\n"
  "  PORTA_PCR13  at 0x40049034\n"
  "  PORTA_PCR14  at 0x40049038\n"
  "  PORTA_PCR15  at 0x4004903C\n"
  "  PORTA_PCR16  at 0x40049040\n"
  "  PORTA_PCR17  at 0x40049044\n"
  "  PORTA_PCR18  at 0x40049048\n"
  "  PORTA_PCR19  at 0x4004904C\n"
  "  PORTA_PCR20  at 0x40049050\n"
  "  PORTA_PCR21  at 0x40049054\n"
  "  PORTA_PCR22  at 0x40049058\n"
  "  PORTA_PCR23  at 0x4004905C\n"
  "  PORTA_PCR24  at 0x40049060\n"
  "  PORTA_PCR25  at 0x40049064\n"
  "  PORTA_PCR26  at 0x40049068\n"
  "  PORTA_PCR27  at 0x4004906C\n"
  "  PORTA_PCR28  at 0x40049070\n"
  "  PORTA_PCR29  at 0x40049074\n"
  "  PORTA_PCR30  at 0x40049078\n"
  "  PORTA_PCR31  at 0x4004907C\n"
  "  PORTB_PCR0   at 0x4004A000\n"
  "  PORTB_PCR1   at 0x4004A004\n"
  "  PORTB_PCR2   at 0x4004A008\n"
  "  PORTB_PCR3   at 0x4004A00C\n"
  "  PORTB_PCR4   at 0x4004A010\n"
  "  PORTB_PCR5   at 0x4004A014\n"
  "  PORTB_PCR6   at 0x4004A018\n"
  "  PORTB_PCR7   at 0x4004A01C\n"
  "  PORTB_PCR8   at 0x4004A020\n"
  "  PORTB_PCR9   at 0x4004A024\n"
  "  PORTB_PCR10  at 0x4004A028\n"
  "  PORTB_PCR11  at 0x4004A02C\n"
  "  PORTB_PCR12  at 0x4004A030\n"
  "  PORTB_PCR13  at 0x4004A034\n"
  "  PORTB_PCR14  at 0x4004A038\n"
  "  PORTB_PCR15  at 0x4004A03C\n"
  "  PORTB_PCR16  at 0x4004A040\n"
  "  PORTB_PCR17  at 0x4004A044\n"
  "  PORTB_PCR18  at 0x4004A048\n"
  "  PORTB_PCR19  at 0x4004A04C\n"
  "  PORTB_PCR20  at 0x4004A050\n"
  "  PORTB_PCR21  at 0x4004A054\n"
  "  PORTB_PCR22  at 0x4004A058\n"
  "  PORTB_PCR23  at 0x4004A05C\n"
  "  PORTB_PCR24  at 0x4004A060\n"
  "  PORTB_PCR25  at 0x4004A064\n"
  "  PORTB_PCR26  at 0x4004A068\n"
  "  PORTB_PCR27  at 0x4004A06C\n"
  "  PORTB_PCR28  at 0x4004A070\n"
  "  PORTB_PCR29  at 0x4004A074\n"
  "  PORTB_PCR30  at 0x4004A078\n"
  "  PORTB_PCR31  at 0x4004A07C\n"
  "  PORTC_PCR0   at 0x4004B000\n"
  "  PORTC_PCR1   at 0x4004B004\n"
  "  PORTC_PCR2   at 0x4004B008\n"
  "  PORTC_PCR3   at 0x4004B00C\n"
  "  PORTC_PCR4   at 0x4004B010\n"
  "  PORTC_PCR5   at 0x4004B014\n"
  "  PORTC_PCR6   at 0x4004B018\n"
  "  PORTC_PCR7   at 0x4004B01C\n"
  "  PORTC_PCR8   at 0x4004B020\n"
  "  PORTC_PCR9   at 0x4004B024\n"
  "  PORTC_PCR10  at 0x4004B028\n"
  "  PORTC_PCR11  at 0x4004B02C\n"
  "  PORTC_PCR12  at 0x4004B030\n"
  "  PORTC_PCR13  at 0x4004B034\n"
  "  PORTC_PCR14  at 0x4004B038\n"
  "  PORTC_PCR15  at 0x4004B03C\n"
  "  PORTC_PCR16  at 0x4004B040\n"
  "  PORTC_PCR17  at 0x4004B044\n"
  "  PORTC_PCR18  at 0x4004B048\n"
  "  PORTC_PCR19  at 0x4004B04C\n"
  "  PORTC_PCR20  at 0x4004B050\n"
  "  PORTC_PCR21  at 0x4004B054\n"
  "  PORTC_PCR22  at 0x4004B058\n"
  "  PORTC_PCR23  at 0x4004B05C\n"
  "  PORTC_PCR24  at 0x4004B060\n"
  "  PORTC_PCR25  at 0x4004B064\n"
  "  PORTC_PCR26  at 0x4004B068\n"
  "  PORTC_PCR27  at 0x4004B06C\n"
  "  PORTC_PCR28  at 0x4004B070\n"
  "  PORTC_PCR29  at 0x4004B074\n"
  "  PORTC_PCR30  at 0x4004B078\n"
  "  PORTC_PCR31  at 0x4004B07C\n"
  "  PORTD_PCR0   at 0x4004C000\n"
  "  PORTD_PCR1   at 0x4004C004\n"
  "  PORTD_PCR2   at 0x4004C008\n"
  "  PORTD_PCR3   at 0x4004C00C\n"
  "  PORTD_PCR4   at 0x4004C010\n"
  "  PORTD_PCR5   at 0x4004C014\n"
  "  PORTD_PCR6   at 0x4004C018\n"
  "  PORTD_PCR7   at 0x4004C01C\n"
  "  PORTD_PCR8   at 0x4004C020\n"
  "  PORTD_PCR9   at 0x4004C024\n"
  "  PORTD_PCR10  at 0x4004C028\n"
  "  PORTD_PCR11  at 0x4004C02C\n"
  "  PORTD_PCR12  at 0x4004C030\n"
  "  PORTD_PCR13  at 0x4004C034\n"
  "  PORTD_PCR14  at 0x4004C038\n"
  "  PORTD_PCR15  at 0x4004C03C\n"
  "  PORTD_PCR16  at 0x4004C040\n"
  "  PORTD_PCR17  at 0x4004C044\n"
  "  PORTD_PCR18  at 0x4004C048\n"
  "  PORTD_PCR19  at 0x4004C04C\n"
  "  PORTD_PCR20  at 0x4004C050\n"
  "  PORTD_PCR21  at 0x4004C054\n"
  "  PORTD_PCR22  at 0x4004C058\n"
  "  PORTD_PCR23  at 0x4004C05C\n"
  "  PORTD_PCR24  at 0x4004C060\n"
  "  PORTD_PCR25  at 0x4004C064\n"
  "  PORTD_PCR26  at 0x4004C068\n"
  "  PORTD_PCR27  at 0x4004C06C\n"
  "  PORTD_PCR28  at 0x4004C070\n"
  "  PORTD_PCR29  at 0x4004C074\n"
  "  PORTD_PCR30  at 0x4004C078\n"
  "  PORTD_PCR31  at 0x4004C07C\n"
  "  PORTE_PCR0   at 0x4004D000\n"
  "  PORTE_PCR1   at 0x4004D004\n"
  "  PORTE_PCR2   at 0x4004D008\n"
  "  PORTE_PCR3   at 0x4004D00C\n"
  "  PORTE_PCR4   at 0x4004D010\n"
  "  PORTE_PCR5   at 0x4004D014\n"
  "  PORTE_PCR6   at 0x4004D018\n"
  "  PORTE_PCR7   at 0x4004D01C\n"
  "  PORTE_PCR8   at 0x4004D020\n"
  "  PORTE_PCR9   at 0x4004D024\n"
  "  PORTE_PCR10  at 0x4004D028\n"
  "  PORTE_PCR11  at 0x4004D02C\n"
  "  PORTE_PCR12  at 0x4004D030\n"
  "  PORTE_PCR13  at 0x4004D034\n"
  "  PORTE_PCR14  at 0x4004D038\n"
  "  PORTE_PCR15  at 0x4004D03C\n"
  "  PORTE_PCR16  at 0x4004D040\n"
  "  PORTE_PCR17  at 0x4004D044\n"
  "  PORTE_PCR18  at 0x4004D048\n"
  "  PORTE_PCR19  at 0x4004D04C\n"
  "  PORTE_PCR20  at 0x4004D050\n"
  "  PORTE_PCR21  at 0x4004D054\n"
  "  PORTE_PCR22  at 0x4004D058\n"
  "  PORTE_PCR23  at 0x4004D05C\n"
  "  PORTE_PCR24  at 0x4004D060\n"
  "  PORTE_PCR25  at 0x4004D064\n"
  "  PORTE_PCR26  at 0x4004D068\n"
  "  PORTE_PCR27  at 0x4004D06C\n"
  "  PORTE_PCR28  at 0x4004D070\n"
  "  PORTE_PCR29  at 0x4004D074\n"
  "  PORTE_PCR30  at 0x4004D078\n"
  "  PORTE_PCR31  at 0x4004D07C\n"
  "$uint32 {\n"
  "  7, isf, 4, irqc[4], lk, 4, mux[3], 1, dse, ode, pfe, 1, sre, pe, ps\n"
  "}\n"
  "\n"
  "let PORT_PCR_ISF  $uint32  = 0x01000000  // Interrupt Status Flag\n"
  "//register $uint32 PORT_PCR_IRQC(n)   (((n) & 15) << 16) // Interrupt Configuration\n"
  "let PORT_PCR_IRQC_MASK  $uint32 = 0x000F0000\n"
  "let PORT_PCR_LK   $uint32 = 0x00008000  // Lock Register\n"
  "//register $uint32 PORT_PCR_MUX(n)    (((n) & 7) << 8) // Pin Mux Control\n"
  "let PORT_PCR_MUX_MASK $uint32 = 0x00000700\n"
  "let PORT_PCR_DSE      $uint32 = 0x00000040  // Drive Strength Enable\n"
  "let PORT_PCR_ODE      $uint32 = 0x00000020  // Open Drain Enable\n"
  "let PORT_PCR_PFE      $uint32 = 0x00000010  // Passive Filter Enable\n"
  "let PORT_PCR_SRE      $uint32 = 0x00000004  // Slew Rate Enable\n"
  "let PORT_PCR_PE       $uint32 = 0x00000002  // Pull Enable\n"
  "let PORT_PCR_PS       $uint32 = 0x00000001  // Pull Select\n"
  "\n"
  "register PORTA_GPCLR  at 0x40049080 $uint32 // Global Pin Control Low Register\n"
  "register PORTA_GPCHR  at 0x40049084 $uint32 // Global Pin Control High Register\n"
  "register PORTA_ISFR   at 0x400490A0 $uint32 // Interrupt Status Flag Register\n"
  "\n"
  "register PORTB_GPCLR  at 0x4004A080 $uint32 // Global Pin Control Low Register\n"
  "register PORTB_GPCHR  at 0x4004A084 $uint32 // Global Pin Control High Register\n"
  "register PORTB_ISFR   at 0x4004A0A0 $uint32 // Interrupt Status Flag Register\n"
  "\n"
  "register PORTC_GPCLR  at 0x4004B080 $uint32 // Global Pin Control Low Register\n"
  "register PORTC_GPCHR  at 0x4004B084 $uint32 // Global Pin Control High Register\n"
  "register PORTC_ISFR   at 0x4004B0A0 $uint32 // Interrupt Status Flag Register\n"
  "\n"
  "register PORTD_GPCLR  at 0x4004C080 $uint32 // Global Pin Control Low Register\n"
  "register PORTD_GPCHR  at 0x4004C084 $uint32 // Global Pin Control High Register\n"
  "register PORTD_ISFR   at 0x4004C0A0 $uint32 // Interrupt Status Flag Register\n"
  "\n"
  "register PORTE_GPCLR  at 0x4004D080 $uint32 // Global Pin Control Low Register\n"
  "register PORTE_GPCHR  at 0x4004D084 $uint32 // Global Pin Control High Register\n"
  "register PORTE_ISFR   at 0x4004D0A0 $uint32 // Interrupt Status Flag Register\n"
  "\n"
  "// Chapter 12: System Integration Module (SIM)\n"
  "register SIM_SOPT1    at 0x40047000 $uint32 // System Options Register 1\n"
  "register SIM_SOPT1CFG at 0x40047004 $uint32 // SOPT1 Configuration Register\n"
  "register SIM_SOPT2    at 0x40048004 $uint32 // System Options Register 2\n"
  "register SIM_SOPT2_USBSRC at 0x00040000  $uint32 // 0=USB_CLKIN, 1=FFL/PLL \n"
  "register SIM_SOPT2_PLLFLLSEL at 0x00010000  $uint32 // 0=FLL, 1=PLL\n"
  "register SIM_SOPT2_TRACECLKSEL at 0x00001000  $uint32 // 0=MCGOUTCLK, 1=CPU\n"
  "register SIM_SOPT2_PTD7PAD at 0x00000800  $uint32 // 0=normal, 1=double drive PTD7\n"
  "//register $uint32 SIM_SOPT2_CLKOUTSEL(n)   (((n) & 7) << 5) // Selects the clock to output on the CLKOUT pin.\n"
  "let SIM_SOPT2_RTCCLKOUTSEL $uint32 = 0x00000010  // RTC clock out select\n"
  "register SIM_SOPT4   at 0x4004800C $uint32 // System Options Register 4\n"
  "register SIM_SOPT5   at 0x40048010 $uint32 // System Options Register 5\n"
  "register SIM_SOPT7   at 0x40048018 $uint32 // System Options Register 7\n"
  "register SIM_SDID @ro at 0x40048024 $uint32 // System Device Identification Register\n"
  "register SIM_SCGC2  at 0x4004802C $uint32 // System Clock Gating Control Register 2\n"
  "let SIM_SCGC2_DAC0  $uint32 =  0x00001000 // DAC0 Clock Gate Control\n"
  "register SIM_SCGC3  at 0x40048030 $uint32 // System Clock Gating Control Register 3\n"
  "let SIM_SCGC3_ADC1 $uint32 =  0x08000000 // ADC1 Clock Gate Control\n"
  "let SIM_SCGC3_FTM2 $uint32 =  0x01000000 // FTM2 Clock Gate Control\n"
  "register SIM_SCGC4 at 0x40048034 $uint32 // System Clock Gating Control Register 4\n"
  "let SIM_SCGC4_VREF  $uint32 =  0x00100000  // VREF Clock Gate Control\n"
  "let SIM_SCGC4_CMP   $uint32 = 0x00080000  // Comparator Clock Gate Control\n"
  "let SIM_SCGC4_USBOTG  $uint32 = 0x00040000  // USB Clock Gate Control\n"
  "let SIM_SCGC4_UART2  $uint32 =  0x00001000  // UART2 Clock Gate Control\n"
  "let SIM_SCGC4_UART1  $uint32 =  0x00000800  // UART1 Clock Gate Control\n"
  "let SIM_SCGC4_UART0  $uint32 =  0x00000400  // UART0 Clock Gate Control\n"
  "let SIM_SCGC4_I2C1  $uint32 =  0x00000080  // I2C1 Clock Gate Control\n"
  "let SIM_SCGC4_I2C0  $uint32 =  0x00000040  // I2C0 Clock Gate Control\n"
  "let SIM_SCGC4_CMT  $uint32 =  0x00000004  // CMT Clock Gate Control\n"
  "let SIM_SCGC4_EWM  $uint32 =  0x00000002  // EWM Clock Gate Control\n"
  "register SIM_SCGC5 at 0x40048038 $uint32 // System Clock Gating Control Register 5\n"
  "let SIM_SCGC5_PORTE  $uint32 =  0x00002000  // Port E Clock Gate Control\n"
  "let SIM_SCGC5_PORTD  $uint32 =  0x00001000  // Port D Clock Gate Control\n"
  "let SIM_SCGC5_PORTC  $uint32 =  0x00000800  // Port C Clock Gate Control\n"
  "let SIM_SCGC5_PORTB  $uint32 =  0x00000400  // Port B Clock Gate Control\n"
  "let SIM_SCGC5_PORTA  $uint32 =  0x00000200  // Port A Clock Gate Control\n"
  "let SIM_SCGC5_TSI  $uint32 =  0x00000020  // Touch Sense Input TSI Clock Gate Control\n"
  "let SIM_SCGC5_LPTIMER  $uint32 =  0x00000001  // Low Power Timer Access Control\n"
  "register SIM_SCGC6 at 0x4004803C $uint32 // System Clock Gating Control Register 6\n"
  "let SIM_SCGC6_RTC   $uint32 = 0x20000000  // RTC Access\n"
  "let SIM_SCGC6_ADC0  $uint32 =   0x08000000  // ADC0 Clock Gate Control\n"
  "let SIM_SCGC6_FTM1  $uint32 =   0x02000000  // FTM1 Clock Gate Control\n"
  "let SIM_SCGC6_FTM0  $uint32 =   0x01000000  // FTM0 Clock Gate Control\n"
  "let SIM_SCGC6_PIT  $uint32 =  0x00800000  // PIT Clock Gate Control\n"
  "let SIM_SCGC6_PDB  $uint32 =  0x00400000  // PDB Clock Gate Control\n"
  "let SIM_SCGC6_USBDCD  $uint32=  0x00200000  // USB DCD Clock Gate Control\n"
  "let SIM_SCGC6_CRC  $uint32 =  0x00040000  // CRC Clock Gate Control\n"
  "let SIM_SCGC6_I2S  $uint32 =  0x00008000  // I2S Clock Gate Control\n"
  "let SIM_SCGC6_SPI1  $uint32=   0x00002000  // SPI1 Clock Gate Control\n"
  "let SIM_SCGC6_SPI0  $uint32=   0x00001000  // SPI0 Clock Gate Control\n"
  "let SIM_SCGC6_FLEXCAN0  $uint32 =  0x00000010  // FlexCAN0 Clock Gate Control\n"
  "let SIM_SCGC6_DMAMUX $uint32 =  0x00000002  // DMA Mux Clock Gate Control\n"
  "let SIM_SCGC6_FTFL  $uint32 =  0x00000001  // Flash Memory Clock Gate Control\n"
  "\n"
  "register SIM_SCGC7 at 0x40048040 $uint32 // System Clock Gating Control Register 7\n"
  "let SIM_SCGC7_DMA  $uint32 =  0x00000002  // DMA Clock Gate Control\n"
  "\n"
  "register SIM_CLKDIV1 at 0x4004_8044 $uint32 {// System Clock Divider Register 1\n"
  "  OUTDIV1[4], // Divide value for the core/system clock\n"
  "  OUTDIV2[4], // Divide value for the peripheral clock\n"
  "  4,\n"
  "  OUTDIV4[4], // Divide value for the flash clock\n"
  "  16\n"
  "}\n"
  "\n"
  "register SIM_CLKDIV2 at 0x40048048 $uint32 // System Clock Divider Register 2\n"
  "//register $uint32 SIM_CLKDIV2_USBDIV(n)   (((n) & 0x07) << 1)\n"
  "let SIM_CLKDIV2_USBFRAC  $uint32 =  0x01\n"
  "register SIM_FCFG1 @ro at 0x4004804C $uint32 // Flash Configuration Register 1\n"
  "register SIM_FCFG2 @ro at 0x40048050 $uint32 // Flash Configuration Register 2\n"
  "register SIM_UIDH  @ro at 0x40048054 $uint32 // Unique Identification Register High\n"
  "register SIM_UIDMH @ro at 0x40048058 $uint32 // Unique Identification Register Mid-High\n"
  "register SIM_UIDML @ro at 0x4004805C $uint32 // Unique Identification Register Mid Low\n"
  "register SIM_UIDL  @ro at 0x40048060 $uint32 // Unique Identification Register Low\n"
  "\n"
  "// Chapter 13: Reset Control Module (RCM)\n"
  "register RCM_SRS0 at 0x4007F000 $uint8 // System Reset Status Register 0\n"
  "register RCM_SRS1 at 0x4007F001 $uint8 // System Reset Status Register 1\n"
  "register RCM_RPFC at 0x4007F004 $uint8 // Reset Pin Filter Control Register\n"
  "register RCM_RPFW at 0x4007F005 $uint8 // Reset Pin Filter Width Register\n"
  "register RCM_MR   at 0x4007F007 $uint8 // Mode Register\n"
  "\n"
  "// Chapter 14: System Mode Controller\n"
  "register SMC_PMPROT  at 0x4007E000 $uint8 // Power Mode Protection Register\n"
  "let SMC_PMPROT_AVLP  $uint8 = 0x20   // Allow very low power modes\n"
  "let SMC_PMPROT_ALLS $uint8  = 0x08   // Allow low leakage stop mode\n"
  "let SMC_PMPROT_AVLLS $uint8 = 0x02   // Allow very low leakage stop mode\n"
  "\n"
  "register SMC_PMCTRL  at 0x4007E001 $uint8 // Power Mode Control Register\n"
  "let SMC_PMCTRL_LPWUI $uint8  = 0x80   // Low Power Wake Up on Interrupt\n"
  "//register $uint8 SMC_PMCTRL_RUNM(n)  ($uint8_t)(((n) & 0x03) << 5) // Run Mode Control\n"
  "let SMC_PMCTRL_STOPA $uint8  = 0x08   // Stop Aborted\n"
  "//register $uint8 SMC_PMCTRL_STOPM(n)  ($uint8_t)((n) & 0x07)  // Stop Mode Control\n"
  "\n"
  "register SMC_VLLSCTRL at 0x4007E002 $uint8 // VLLS Control Register\n"
  "let SMC_VLLSCTRL_PORPO $uint8 = 0x20   // POR Power Option\n"
  "//let $uint8 SMC_VLLSCTRL_VLLSM(n)  ($uint8_t)((n) & 0x07)  // VLLS Mode Control\n"
  "\n"
  "register SMC_PMST at 0x4007E003 $uint8 // Power Mode Status Register\n"
  "let SMC_PMSTAT_RUN  $uint8 = 0x01   // Current power mode is RUN\n"
  "let SMC_PMSTAT_STOP $uint8 = 0x02   // Current power mode is STOP\n"
  "let SMC_PMSTAT_VLPR $uint8 = 0x04   // Current power mode is VLPR\n"
  "let SMC_PMSTAT_VLPW $uint8 = 0x08   // Current power mode is VLPW\n"
  "let SMC_PMSTAT_VLPS $uint8 = 0x10   // Current power mode is VLPS\n"
  "let SMC_PMSTAT_LLS  $uint8 = 0x20   // Current power mode is LLS\n"
  "let SMC_PMSTAT_VLLS $uint8 = 0x40   // Current power mode is VLLS\n"
  "\n"
  "// Chapter 15: Power Management Controller\n"
  "register PMC_LVDSC1 at 0x4007D000 $uint8 // Low Voltage Detect Status And Control 1 register\n"
  "let PMC_LVDSC1_LVDF $uint8 = 0x80   // Low-Voltage Detect Flag\n"
  "let PMC_LVDSC1_LVDACK $uint8 = 0x40   // Low-Voltage Detect Acknowledge\n"
  "let PMC_LVDSC1_LVDIE $uint8 = 0x20   // Low-Voltage Detect Interrupt Enable\n"
  "let PMC_LVDSC1_LVDRE $uint8 = 0x10   // Low-Voltage Detect Reset Enable\n"
  "//let $uint8 PMC_LVDSC1_LVDV(n)  ($uint8_t)((n) & 0x03)  // Low-Voltage Detect Voltage Select\n"
  "register PMC_LVDSC2 at 0x4007D001 $uint8 // Low Voltage Detect Status And Control 2 register\n"
  "let PMC_LVDSC2_LVWF $uint8  = 0x80   // Low-Voltage Warning Flag\n"
  "let PMC_LVDSC2_LVWACK $uint8 = 0x40   // Low-Voltage Warning Acknowledge\n"
  "let PMC_LVDSC2_LVWIE $uint8 = 0x20   // Low-Voltage Warning Interrupt Enable\n"
  "//let $uint8 PMC_LVDSC2_LVWV(n)  ($uint8_t)((n) & 0x03)  // Low-Voltage Warning Voltage Select\n"
  "\n"
  "register PMC_REGSC at 0x4007D002 $uint8 { // Regulator Status And Control register\n"
  "  3, BGEN, ACKISO, REGONS, BGBE, 1\n"
  "}\n"
  "\n"
  "// Chapter 16: Low-Leakage Wakeup Unit (LLWU)\n"
  "register LLWU_PE1  at 0x4007C000 $uint8 // LLWU Pin Enable 1 register\n"
  "register LLWU_PE2  at 0x4007C001 $uint8 // LLWU Pin Enable 2 register\n"
  "register LLWU_PE3  at 0x4007C002 $uint8 // LLWU Pin Enable 3 register\n"
  "register LLWU_PE4  at 0x4007C003 $uint8 // LLWU Pin Enable 4 register\n"
  "register LLWU_ME   at 0x4007C004 $uint8 // LLWU Module Enable register\n"
  "register LLWU_F1   at 0x4007C005 $uint8 // LLWU Flag 1 register\n"
  "register LLWU_F2   at 0x4007C006 $uint8 // LLWU Flag 2 register\n"
  "register LLWU_F3   at 0x4007C007 $uint8 // LLWU Flag 3 register\n"
  "register LLWU_FILT1 at 0x4007C008 $uint8 // LLWU Pin Filter 1 register\n"
  "register LLWU_FILT2 at 0x4007C009 $uint8 // LLWU Pin Filter 2 register\n"
  "register LLWU_RST  at 0x4007C00A $uint8 // LLWU Reset Enable register\n"
  "\n"
  "// Chapter 17: Miscellaneous Control Module (MCM)\n"
  "register MCM_PLASC at 0xE0080008 $uint16 // Crossbar Switch (AXBS) Slave Configuration\n"
  "\n"
  "register MCM_PLAMC at 0xE008000A $uint16 // Crossbar Switch (AXBS) Master Configuration\n"
  "\n"
  "register MCM_PLACR at 0xE008000C $uint32 // Crossbar Switch (AXBS) Control Register (MK20DX128)\n"
  "let MCM_PLACR_ARG   $uint32 = 0x00000200  // Arbitration select, 0=fixed, 1=round-robin\n"
  "\n"
  "register MCM_CR at 0xE008000C $uint32 // RAM arbitration control register (MK20DX256)\n"
  "let MCM_CR_SRAMLWP  $uint32 =  0x4000_0000  // SRAM_L write protect\n"
  "//let $uint32 MCM_CR_SRAMLAP(n)   (((n) & 0x03) << 28) // SRAM_L priority, 0=RR, 1=favor DMA, 2=CPU, 3=DMA\n"
  "let MCM_CR_SRAMUWP  $uint32 =  0x0400_0000  // SRAM_U write protect\n"
  "//let $uint32 MCM_CR_SRAMUAP(n)   (((n) & 0x03) << 24) // SRAM_U priority, 0=RR, 1=favor DMA, 2=CPU, 3=DMA\n"
  "\n"
  "// Crossbar Switch (AXBS) - only programmable on MK20DX256\n"
  "register AXBS_PRS0   at 0x40004000 $uint32 // Priority Registers Slave 0\n"
  "register AXBS_CRS0   at 0x40004010 $uint32 // Control Register 0\n"
  "register AXBS_PRS1   at 0x40004100 $uint32 // Priority Registers Slave 1\n"
  "register AXBS_CRS1   at 0x40004110 $uint32 // Control Register 1\n"
  "register AXBS_PRS2   at 0x40004200 $uint32 // Priority Registers Slave 2\n"
  "register AXBS_CRS2   at 0x40004210 $uint32 // Control Register 2\n"
  "register AXBS_PRS3   at 0x40004300 $uint32 // Priority Registers Slave 3\n"
  "register AXBS_CRS3   at 0x40004310 $uint32 // Control Register 3\n"
  "register AXBS_PRS4   at 0x40004400 $uint32 // Priority Registers Slave 4\n"
  "register AXBS_CRS4   at 0x40004410 $uint32 // Control Register 4\n"
  "register AXBS_PRS5   at 0x40004500 $uint32 // Priority Registers Slave 5\n"
  "register AXBS_CRS5   at 0x40004510 $uint32 // Control Register 5\n"
  "register AXBS_PRS6   at 0x40004600 $uint32 // Priority Registers Slave 6\n"
  "register AXBS_CRS6   at 0x40004610 $uint32 // Control Register 6\n"
  "register AXBS_PRS7   at 0x40004700 $uint32 // Priority Registers Slave 7\n"
  "register AXBS_CRS7   at 0x40004710 $uint32 // Control Register 7\n"
  "register AXBS_MGPCR0 at 0x40004800 $uint32 // Master 0 General Purpose Control Register\n"
  "register AXBS_MGPCR1 at 0x40004900 $uint32 // Master 1 General Purpose Control Register\n"
  "register AXBS_MGPCR2 at 0x40004A00 $uint32 // Master 2 General Purpose Control Register\n"
  "register AXBS_MGPCR3 at 0x40004B00 $uint32 // Master 3 General Purpose Control Register\n"
  "register AXBS_MGPCR4 at 0x40004C00 $uint32 // Master 4 General Purpose Control Register\n"
  "register AXBS_MGPCR5 at 0x40004D00 $uint32 // Master 5 General Purpose Control Register\n"
  "register AXBS_MGPCR6 at 0x40004E00 $uint32 // Master 6 General Purpose Control Register\n"
  "register AXBS_MGPCR7 at 0x40004F00 $uint32 // Master 7 General Purpose Control Register\n"
  "let AXBS_CRS_READONLY  $uint32=  0x80000000\n"
  "let AXBS_CRS_HALTLOWPRIORITY  $uint32 = 0x40000000\n"
  "let AXBS_CRS_ARB_FIXED  $uint32 = 0x00000000\n"
  "let AXBS_CRS_ARB_ROUNDROBIN  $uint32 = 0x00010000\n"
  "let AXBS_CRS_PARK_FIXED  $uint32 =  0x00000000\n"
  "let AXBS_CRS_PARK_PREVIOUS  $uint32 =  0x00000010\n"
  "let AXBS_CRS_PARK_NONE  $uint32 =  0x00000020\n"
  "//let $uint32 AXBS_CRS_PARK(n)   (((n) & 7) << 0)\n"
  "\n"
  "\n"
  "\n"
  "// Chapter 20: Direct Memory Access Multiplexer (DMAMUX)\n"
  "register DMAMUX0_CHCFG0  at 0x40021000 $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG1  at 0x40021001 $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG2  at 0x40021002 $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG3  at 0x40021003 $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG4  at 0x40021004 $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG5  at 0x40021005 $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG6  at 0x40021006 $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG7  at 0x40021007 $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG8  at 0x40021008 $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG9  at 0x40021009 $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG10 at 0x4002100A $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG11 at 0x4002100B $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG12 at 0x4002100C $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG13 at 0x4002100D $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG14 at 0x4002100E $uint8 // Channel Configuration register\n"
  "register DMAMUX0_CHCFG15 at 0x4002100F $uint8 // Channel Configuration register\n"
  "let DMAMUX_DISABLE $uint8 =  0\n"
  "let DMAMUX_TRIG  $uint8 = 64\n"
  "let DMAMUX_ENABLE $uint8 =  128\n"
  "let DMAMUX_SOURCE_UART0_RX $uint8 = 2\n"
  "let DMAMUX_SOURCE_UART0_TX $uint8 = 3\n"
  "let DMAMUX_SOURCE_UART1_RX $uint8 = 4\n"
  "let DMAMUX_SOURCE_UART1_TX $uint8 = 5\n"
  "let DMAMUX_SOURCE_UART2_RX $uint8 = 6\n"
  "let DMAMUX_SOURCE_UART2_TX $uint8 = 7\n"
  "let DMAMUX_SOURCE_I2S0_RX  $uint8 =14\n"
  "let DMAMUX_SOURCE_I2S0_TX  $uint8 =15\n"
  "let DMAMUX_SOURCE_SPI0_RX  $uint8 =16\n"
  "let DMAMUX_SOURCE_SPI0_TX  $uint8 =17\n"
  "let DMAMUX_SOURCE_I2C0  $uint8 =22\n"
  "let DMAMUX_SOURCE_I2C1  $uint8 =23\n"
  "let DMAMUX_SOURCE_FTM0_CH0 $uint8 = 24\n"
  "let DMAMUX_SOURCE_FTM0_CH1 $uint8 = 25\n"
  "let DMAMUX_SOURCE_FTM0_CH2 $uint8 = 26\n"
  "let DMAMUX_SOURCE_FTM0_CH3 $uint8 = 27\n"
  "let DMAMUX_SOURCE_FTM0_CH4 $uint8 = 28\n"
  "let DMAMUX_SOURCE_FTM0_CH5 $uint8 = 29\n"
  "let DMAMUX_SOURCE_FTM0_CH6 $uint8 = 30\n"
  "let DMAMUX_SOURCE_FTM0_CH7 $uint8 = 31\n"
  "let DMAMUX_SOURCE_FTM1_CH0 $uint8 = 32\n"
  "let DMAMUX_SOURCE_FTM1_CH1 $uint8 = 33\n"
  "let DMAMUX_SOURCE_FTM2_CH0 $uint8 = 34\n"
  "let DMAMUX_SOURCE_FTM2_CH1 $uint8 = 35\n"
  "let DMAMUX_SOURCE_ADC0 $uint8 = 40\n"
  "let DMAMUX_SOURCE_ADC1 $uint8 = 41\n"
  "let DMAMUX_SOURCE_CMP0 $uint8 = 42\n"
  "let DMAMUX_SOURCE_CMP1 $uint8 = 43\n"
  "let DMAMUX_SOURCE_CMP2 $uint8 = 44\n"
  "let DMAMUX_SOURCE_DAC0 $uint8 = 45\n"
  "let DMAMUX_SOURCE_CMT  $uint8 = 47\n"
  "let DMAMUX_SOURCE_PDB  $uint8 = 48\n"
  "let DMAMUX_SOURCE_PORTA $uint8 = 49\n"
  "let DMAMUX_SOURCE_PORTB $uint8 = 50\n"
  "let DMAMUX_SOURCE_PORTC $uint8 = 51\n"
  "let DMAMUX_SOURCE_PORTD $uint8 = 52\n"
  "let DMAMUX_SOURCE_PORTE $uint8 = 53\n"
  "let DMAMUX_SOURCE_ALWAYS0 $uint8 = 54\n"
  "let DMAMUX_SOURCE_ALWAYS1 $uint8 = 55\n"
  "let DMAMUX_SOURCE_ALWAYS2 $uint8 = 56\n"
  "let DMAMUX_SOURCE_ALWAYS3 $uint8 = 57\n"
  "let DMAMUX_SOURCE_ALWAYS4 $uint8 = 58\n"
  "let DMAMUX_SOURCE_ALWAYS5 $uint8 = 59\n"
  "let DMAMUX_SOURCE_ALWAYS6 $uint8 = 60\n"
  "let DMAMUX_SOURCE_ALWAYS7 $uint8 = 61\n"
  "let DMAMUX_SOURCE_ALWAYS8 $uint8 = 62\n"
  "let DMAMUX_SOURCE_ALWAYS9 $uint8 = 63\n"
  "\n"
  "// Chapter 21: Direct Memory Access Controller (eDMA)\n"
  "register DMA_CR at 0x40008000 $uint32 // Control Register\n"
  "let DMA_CR_CX   $uint32  = 0x2_0000 // Cancel Transfer\n"
  "let DMA_CR_ECX   $uint32 = 0x1_0000 // Error Cancel Transfer\n"
  "let DMA_CR_EMLM   $uint32= 0x80 // Enable Minor Loop Mapping\n"
  "let DMA_CR_CLM   $uint32 = 0x40 // Continuous Link Mode\n"
  "let DMA_CR_HALT  $uint32 = 0x20 // Halt DMA Operations\n"
  "let DMA_CR_HOE   $uint32 = 0x10 // Halt On Error\n"
  "let DMA_CR_ERCA  $uint32 = 0x04 // Enable Round Robin Channel Arbitration\n"
  "let DMA_CR_EDBG   $uint32= 0x02 // Enable Debug\n"
  "register DMA_ES  at 0x40008004 $uint32 // Error Status Register\n"
  "register DMA_ERQ at 0x4000800C $uint32 // Enable Request Register\n"
  "let DMA_ERQ_ERQ0   $uint32 = 1 // Enable DMA Request 0\n"
  "let DMA_ERQ_ERQ1   $uint32 = 2 // Enable DMA Request 1\n"
  "let DMA_ERQ_ERQ2   $uint32 = 4 // Enable DMA Request 2\n"
  "let DMA_ERQ_ERQ3   $uint32 = 8 // Enable DMA Request 3\n"
  "register DMA_EEI at 0x40008014 $uint8 // Enable Error Interrupt Register\n"
  "let DMA_EEI_EEI0   $uint32 = 1 // Enable Error Interrupt 0\n"
  "let DMA_EEI_EEI1   $uint32 = 2 // Enable Error Interrupt 1\n"
  "let DMA_EEI_EEI2   $uint32 = 4 // Enable Error Interrupt 2\n"
  "let DMA_EEI_EEI3   $uint32 = 8 // Enable Error Interrupt 3\n"
  "//register $uint8 DMA_CEEI  *(volatile $uint8_t  *)0x40008018 // Clear Enable Error Interrupt Register\n"
  "//register $uint32 DMA_CEEI_CEEI(n)  (($uint8_t)(n & 3)<<0) // Clear Enable Error Interrupt\n"
  "//register $uint32 DMA_CEEI_CAEE   (($uint8_t)1<<6)  // Clear All Enable Error Interrupts\n"
  "//register $uint32 DMA_CEEI_NOP   (($uint8_t)1<<7)  // NOP\n"
  "//register $uint32 DMA_SEEI  *(volatile $uint8_t  *)0x40008019 // Set Enable Error Interrupt Register\n"
  "//register $uint32 DMA_SEEI_SEEI(n)  (($uint8_t)(n & 3)<<0) // Set Enable Error Interrupt\n"
  "//register $uint32 DMA_SEEI_SAEE   (($uint8_t)1<<6)  // Set All Enable Error Interrupts\n"
  "//register $uint32 DMA_SEEI_NOP   (($uint8_t)1<<7)  // NOP\n"
  "//register $uint32 DMA_CERQ  *(volatile $uint8_t  *)0x4000801A // Clear Enable Request Register\n"
  "//register $uint32 DMA_CERQ_CERQ(n)  (($uint8_t)(n & 3)<<0) // Clear Enable Request\n"
  "//register $uint32 DMA_CERQ_CAER   (($uint8_t)1<<6)  // Clear All Enable Requests\n"
  "//register $uint32 DMA_CERQ_NOP   (($uint8_t)1<<7)  // NOP\n"
  "//register $uint32 DMA_SERQ  *(volatile $uint8_t  *)0x4000801B // Set Enable Request Register\n"
  "//register $uint32 DMA_SERQ_SERQ(n)  (($uint8_t)(n & 3)<<0) // Set Enable Request\n"
  "//register $uint32 DMA_SERQ_SAER   (($uint8_t)1<<6)  // Set All Enable Requests\n"
  "//register $uint32 DMA_SERQ_NOP   (($uint8_t)1<<7)  // NOP\n"
  "//register $uint32 DMA_CDNE  *(volatile $uint8_t  *)0x4000801C // Clear DONE Status Bit Register\n"
  "//register $uint32 DMA_CDNE_CDNE(n)  (($uint8_t)(n & 3)<<0) // Clear Done Bit\n"
  "//register $uint32 DMA_CDNE_CADN   (($uint8_t)1<<6)  // Clear All Done Bits\n"
  "//register $uint32 DMA_CDNE_NOP   (($uint8_t)1<<7)  // NOP\n"
  "//register $uint32 DMA_SSRT  *(volatile $uint8_t  *)0x4000801D // Set START Bit Register\n"
  "//register $uint32 DMA_SSRT_SSRT(n)  (($uint8_t)(n & 3)<<0) // Set Start Bit\n"
  "//register $uint32 DMA_SSRT_SAST   (($uint8_t)1<<6)  // Set All Start Bits\n"
  "//register $uint32 DMA_SSRT_NOP   (($uint8_t)1<<7)  // NOP\n"
  "//register $uint32 DMA_CERR  *(volatile $uint8_t  *)0x4000801E // Clear Error Register\n"
  "//register $uint32 DMA_CERR_CERR(n)  (($uint8_t)(n & 3)<<0) // Clear Error Indicator\n"
  "//register $uint32 DMA_CERR_CAEI   (($uint8_t)1<<6)  // Clear All Error Indicators\n"
  "//register $uint32 DMA_CERR_NOP   (($uint8_t)1<<7)  // NOP\n"
  "//register $uint32 DMA_CINT  *(volatile $uint8_t  *)0x4000801F // Clear Interrupt Request Register\n"
  "//register $uint32 DMA_CINT_CINT(n)  (($uint8_t)(n & 3)<<0) // Clear Interrupt Request\n"
  "//register $uint32 DMA_CINT_CAIR   (($uint8_t)1<<6)  // Clear All Interrupt Requests\n"
  "//register $uint32 DMA_CINT_NOP   (($uint8_t)1<<7)  // NOP\n"
  "//register $uint32 DMA_INT    0x40008024 // Interrupt Request Register\n"
  "//register $uint32 DMA_INT_INT0   ( 1<<0) // Interrupt Request 0\n"
  "//register $uint32 DMA_INT_INT1   ( 1<<1) // Interrupt Request 1\n"
  "//register $uint32 DMA_INT_INT2   ( 1<<2) // Interrupt Request 2\n"
  "//register $uint32 DMA_INT_INT3   ( 1<<3) // Interrupt Request 3\n"
  "//register $uint32 DMA_ERR    0x4000802C // Error Register\n"
  "//register $uint32 DMA_ERR_ERR0   ( 1<<0) // Error in Channel 0\n"
  "//register $uint32 DMA_ERR_ERR1   ( 1<<1) // Error in Channel 1\n"
  "//register $uint32 DMA_ERR_ERR2   ( 1<<2) // Error in Channel 2\n"
  "//register $uint32 DMA_ERR_ERR3   ( 1<<3) // Error in Channel 3\n"
  "//register $uint32 DMA_HRS    0x40008034 // Hardware Request Status Register\n"
  "//register $uint32 DMA_HRS_HRS0   ( 1<<0) // Hardware Request Status Channel 0\n"
  "//register $uint32 DMA_HRS_HRS1   ( 1<<1) // Hardware Request Status Channel 1\n"
  "//register $uint32 DMA_HRS_HRS2   ( 1<<2) // Hardware Request Status Channel 2\n"
  "//register $uint32 DMA_HRS_HRS3   ( 1<<3) // Hardware Request Status Channel 3\n"
  "//register $uint32 DMA_DCHPRI3  *(volatile $uint8_t  *)0x40008100 // Channel n Priority Register\n"
  "//register $uint32 DMA_DCHPRI2  *(volatile $uint8_t  *)0x40008101 // Channel n Priority Register\n"
  "//register $uint32 DMA_DCHPRI1  *(volatile $uint8_t  *)0x40008102 // Channel n Priority Register\n"
  "//register $uint32 DMA_DCHPRI0  *(volatile $uint8_t  *)0x40008103 // Channel n Priority Register\n"
  "//register $uint32 DMA_DCHPRI_CHPRI(n)  (($uint8_t)(n & 3)<<0) // Channel Arbitration Priority\n"
  "//register $uint32 DMA_DCHPRI_DPA   (($uint8_t)1<<6)  // Disable PreEmpt Ability\n"
  "//register $uint32 DMA_DCHPRI_ECP   (($uint8_t)1<<7)  // Enable PreEmption\n"
  "//\n"
  "//\n"
  "//register DMA_TCD_ATTR_SMOD(n)  (((n) & 0x1F) << 11)\n"
  "//register DMA_TCD_ATTR_SSIZE(n)  (((n) & 0x7) << 8)\n"
  "//register DMA_TCD_ATTR_DMOD(n)  (((n) & 0x1F) << 3)\n"
  "//register DMA_TCD_ATTR_DSIZE(n)  (((n) & 0x7) << 0)\n"
  "//register DMA_TCD_ATTR_SIZE_8BIT  0\n"
  "//register DMA_TCD_ATTR_SIZE_16BIT  1\n"
  "//register DMA_TCD_ATTR_SIZE_32BIT  2\n"
  "//register DMA_TCD_ATTR_SIZE_16BYTE 4\n"
  "//register DMA_TCD_ATTR_SIZE_32BYTE 5\n"
  "//register DMA_TCD_CSR_BWC(n)  (((n) & 0x3) << 14)\n"
  "//register DMA_TCD_CSR_MAJORLINKCH(n) (((n) & 0x3) << 8)\n"
  "//register DMA_TCD_CSR_DONE  0x0080\n"
  "//register DMA_TCD_CSR_ACTIVE  0x0040\n"
  "//register DMA_TCD_CSR_MAJORELINK  0x0020\n"
  "//register DMA_TCD_CSR_ESG   0x0010\n"
  "//register DMA_TCD_CSR_DREQ  0x0008\n"
  "//register DMA_TCD_CSR_INTHALF  0x0004\n"
  "//register DMA_TCD_CSR_INTMAJOR  0x0002\n"
  "//register DMA_TCD_CSR_START  0x0001\n"
  "//register DMA_TCD_CITER_MASK      (($uint16_t)0x7FFF)    // Loop count mask\n"
  "//register DMA_TCD_CITER_ELINK      (($uint16_t)1<<15)    // Enable channel linking on minor-loop complete\n"
  "//register DMA_TCD_BITER_MASK      (($uint16_t)0x7FFF)    // Loop count mask\n"
  "//register DMA_TCD_BITER_ELINK      (($uint16_t)1<<15)    // Enable channel linking on minor-loop complete\n"
  "//register DMA_TCD_NBYTES_SMLOE      ( 1<<31)      // Source Minor Loop Offset Enable\n"
  "//register DMA_TCD_NBYTES_DMLOE      ( 1<<30)      // Destination Minor Loop Offset Enable\n"
  "//register DMA_TCD_NBYTES_MLOFFNO_NBYTES(n)    ( (n))      // NBytes transfer count when minor loop disabled\n"
  "//register DMA_TCD_NBYTES_MLOFFYES_NBYTES(n)   ( (n & 0x1F))     // NBytes transfer count when minor loop enabled\n"
  "//register DMA_TCD_NBYTES_MLOFFYES_MLOFF(n)    ( (n & 0xFFFFF)<<10)   // Offset \n"
  "//\n"
  "//register DMA_TCD0_SADDR  *(volatile const void * volatile *)0x40009000 // TCD Source Address\n"
  "//register DMA_TCD0_SOFF  *(volatile int16_t *)0x40009004  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD0_ATTR  *(volatile $uint16_t *)0x40009006 // TCD Transfer Attributes\n"
  "//register DMA_TCD0_NBYTES_MLNO  0x40009008 // TCD Minor Byte Count (Minor Loop Disabled)\n"
  "//register DMA_TCD0_NBYTES_MLOFFNO  0x40009008 // TCD Signed Minor Loop Offset (Minor Loop Enabled and Offset Disabled)\n"
  "//register DMA_TCD0_NBYTES_MLOFFYES  0x40009008 // TCD Signed Minor Loop Offset (Minor Loop and Offset Enabled)\n"
  "//register DMA_TCD0_SLAST  *(volatile int32_t *)0x4000900C  // TCD Last Source Address Adjustment\n"
  "//register DMA_TCD0_DADDR  *(volatile void * volatile *)0x40009010 // TCD Destination Address\n"
  "//register DMA_TCD0_DOFF  *(volatile int16_t *)0x40009014  // TCD Signed Destination Address Offset\n"
  "//register DMA_TCD0_CITER_ELINKYES *(volatile $uint16_t *)0x40009016 // TCD Current Minor Loop Link, Major Loop Count, Channel Linking Enabled\n"
  "//register DMA_TCD0_CITER_ELINKNO *(volatile $uint16_t *)0x40009016 // \?\?\n"
  "//register DMA_TCD0_DLASTSGA *(volatile int32_t *)0x40009018  // TCD Last Destination Address Adjustment/Scatter Gather Address\n"
  "//register DMA_TCD0_CSR  *(volatile $uint16_t *)0x4000901C // TCD Control and Status\n"
  "//register DMA_TCD0_BITER_ELINKYES *(volatile $uint16_t *)0x4000901E // TCD Beginning Minor Loop Link, Major Loop Count, Channel Linking Enabled\n"
  "//register DMA_TCD0_BITER_ELINKNO *(volatile $uint16_t *)0x4000901E // TCD Beginning Minor Loop Link, Major Loop Count, Channel Linking Disabled\n"
  "//\n"
  "//register DMA_TCD1_SADDR  *(volatile const void * volatile *)0x40009020 // TCD Source Address\n"
  "//register DMA_TCD1_SOFF  *(volatile int16_t *)0x40009024  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD1_ATTR  *(volatile $uint16_t *)0x40009026 // TCD Transfer Attributes\n"
  "//register DMA_TCD1_NBYTES_MLNO  0x40009028 // TCD Minor Byte Count, Minor Loop Disabled\n"
  "//register DMA_TCD1_NBYTES_MLOFFNO  0x40009028 // TCD Signed Minor Loop Offset, Minor Loop Enabled and Offset Disabled\n"
  "//register DMA_TCD1_NBYTES_MLOFFYES  0x40009028 // TCD Signed Minor Loop Offset, Minor Loop and Offset Enabled\n"
  "//register DMA_TCD1_SLAST  *(volatile int32_t *)0x4000902C  // TCD Last Source Address Adjustment\n"
  "//register DMA_TCD1_DADDR  *(volatile void * volatile *)0x40009030 // TCD Destination Address\n"
  "//register DMA_TCD1_DOFF  *(volatile int16_t *)0x40009034  // TCD Signed Destination Address Offset\n"
  "//register DMA_TCD1_CITER_ELINKYES *(volatile $uint16_t *)0x40009036 // TCD Current Minor Loop Link, Major Loop Count, Channel Linking Enabled\n"
  "//register DMA_TCD1_CITER_ELINKNO *(volatile $uint16_t *)0x40009036 // \?\?\n"
  "//register DMA_TCD1_DLASTSGA *(volatile int32_t *)0x40009038  // TCD Last Destination Address Adjustment/Scatter Gather Address\n"
  "//register DMA_TCD1_CSR  *(volatile $uint16_t *)0x4000903C // TCD Control and Status\n"
  "//register DMA_TCD1_BITER_ELINKYES *(volatile $uint16_t *)0x4000903E // TCD Beginning Minor Loop Link, Major Loop Count Channel Linking Enabled\n"
  "//register DMA_TCD1_BITER_ELINKNO *(volatile $uint16_t *)0x4000903E // TCD Beginning Minor Loop Link, Major Loop Count, Channel Linking Disabled\n"
  "//\n"
  "//register DMA_TCD2_SADDR  *(volatile const void * volatile *)0x40009040 // TCD Source Address\n"
  "//register DMA_TCD2_SOFF  *(volatile int16_t *)0x40009044  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD2_ATTR  *(volatile $uint16_t *)0x40009046 // TCD Transfer Attributes\n"
  "//register DMA_TCD2_NBYTES_MLNO  0x40009048 // TCD Minor Byte Count, Minor Loop Disabled\n"
  "//register DMA_TCD2_NBYTES_MLOFFNO  0x40009048 // TCD Signed Minor Loop Offset, Minor Loop Enabled and Offset Disabled\n"
  "//register DMA_TCD2_NBYTES_MLOFFYES  0x40009048 // TCD Signed Minor Loop Offset, Minor Loop and Offset Enabled\n"
  "//register DMA_TCD2_SLAST  *(volatile int32_t *)0x4000904C  // TCD Last Source Address Adjustment\n"
  "//register DMA_TCD2_DADDR  *(volatile void * volatile *)0x40009050 // TCD Destination Address\n"
  "//register DMA_TCD2_DOFF  *(volatile int16_t *)0x40009054  // TCD Signed Destination Address Offset\n"
  "//register DMA_TCD2_CITER_ELINKYES *(volatile $uint16_t *)0x40009056 // TCD Current Minor Loop Link, Major Loop Count, Channel Linking Enabled\n"
  "//register DMA_TCD2_CITER_ELINKNO *(volatile $uint16_t *)0x40009056 // \?\?\n"
  "//register DMA_TCD2_DLASTSGA *(volatile int32_t *)0x40009058  // TCD Last Destination Address Adjustment/Scatter Gather Address\n"
  "//register DMA_TCD2_CSR  *(volatile $uint16_t *)0x4000905C // TCD Control and Status\n"
  "//register DMA_TCD2_BITER_ELINKYES *(volatile $uint16_t *)0x4000905E // TCD Beginning Minor Loop Link, Major Loop Count, Channel Linking Enabled\n"
  "//register DMA_TCD2_BITER_ELINKNO *(volatile $uint16_t *)0x4000905E // TCD Beginning Minor Loop Link, Major Loop Count, Channel Linking Disabled\n"
  "//\n"
  "//register DMA_TCD3_SADDR  *(volatile const void * volatile *)0x40009060 // TCD Source Address\n"
  "//register DMA_TCD3_SOFF  *(volatile int16_t *)0x40009064  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD3_ATTR  *(volatile $uint16_t *)0x40009066 // TCD Transfer Attributes\n"
  "//register DMA_TCD3_NBYTES_MLNO  0x40009068 // TCD Minor Byte Count, Minor Loop Disabled\n"
  "//register DMA_TCD3_NBYTES_MLOFFNO  0x40009068 // TCD Signed Minor Loop Offset, Minor Loop Enabled and Offset Disabled\n"
  "//register DMA_TCD3_NBYTES_MLOFFYES  0x40009068 // TCD Signed Minor Loop Offset, Minor Loop and Offset Enabled\n"
  "//register DMA_TCD3_SLAST  *(volatile int32_t *)0x4000906C  // TCD Last Source Address Adjustment\n"
  "//register DMA_TCD3_DADDR  *(volatile void * volatile *)0x40009070 // TCD Destination Address\n"
  "//register DMA_TCD3_DOFF  *(volatile int16_t *)0x40009074  // TCD Signed Destination Address Offset\n"
  "//register DMA_TCD3_CITER_ELINKYES *(volatile $uint16_t *)0x40009076 // TCD Current Minor Loop Link, Major Loop Count, Channel Linking Enabled\n"
  "//register DMA_TCD3_CITER_ELINKNO *(volatile $uint16_t *)0x40009076 // \?\?\n"
  "//register DMA_TCD3_DLASTSGA *(volatile int32_t *)0x40009078  // TCD Last Destination Address Adjustment/Scatter Gather Address\n"
  "//register DMA_TCD3_CSR  *(volatile $uint16_t *)0x4000907C // TCD Control and Status\n"
  "//register DMA_TCD3_BITER_ELINKYES *(volatile $uint16_t *)0x4000907E // TCD Beginning Minor Loop Link, Major Loop Count ,Channel Linking Enabled\n"
  "//register DMA_TCD3_BITER_ELINKNO *(volatile $uint16_t *)0x4000907E // TCD Beginning Minor Loop Link, Major Loop Count ,Channel Linking Disabled\n"
  "//\n"
  "//register DMA_TCD4_SADDR  *(volatile const void * volatile *)0x40009080 // TCD Source Addr\n"
  "//register DMA_TCD4_SOFF  *(volatile int16_t *)0x40009084  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD4_ATTR  *(volatile $uint16_t *)0x40009086 // TCD Transfer Attributes\n"
  "//register DMA_TCD4_NBYTES_MLNO  0x40009088 // TCD Minor Byte Count\n"
  "//register DMA_TCD4_NBYTES_MLOFFNO  0x40009088 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD4_NBYTES_MLOFFYES  0x40009088 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD4_SLAST  *(volatile int32_t *)0x4000908C  // TCD Last Source Addr Adj.\n"
  "//register DMA_TCD4_DADDR  *(volatile void * volatile *)0x40009090 // TCD Destination Address\n"
  "//register DMA_TCD4_DOFF  *(volatile int16_t *)0x40009094  // TCD Signed Dest Address Offset\n"
  "//register DMA_TCD4_CITER_ELINKYES *(volatile $uint16_t *)0x40009096 // TCD Current Minor Loop Link\n"
  "//register DMA_TCD4_CITER_ELINKNO *(volatile $uint16_t *)0x40009096 // \?\?\n"
  "//register DMA_TCD4_DLASTSGA *(volatile int32_t *)0x40009098  // TCD Last Destination Addr Adj\n"
  "//register DMA_TCD4_CSR  *(volatile $uint16_t *)0x4000909C // TCD Control and Status\n"
  "//register DMA_TCD4_BITER_ELINKYES *(volatile $uint16_t *)0x4000909E // TCD Beginning Minor Loop Link\n"
  "//register DMA_TCD4_BITER_ELINKNO *(volatile $uint16_t *)0x4000909E // TCD Beginning Minor Loop Link\n"
  "//\n"
  "//register DMA_TCD5_SADDR  *(volatile const void * volatile *)0x400090A0 // TCD Source Addr\n"
  "//register DMA_TCD5_SOFF  *(volatile int16_t *)0x400090A4  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD5_ATTR  *(volatile $uint16_t *)0x400090A6 // TCD Transfer Attributes\n"
  "//register DMA_TCD5_NBYTES_MLNO  0x400090A8 // TCD Minor Byte Count\n"
  "//register DMA_TCD5_NBYTES_MLOFFNO  0x400090A8 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD5_NBYTES_MLOFFYES  0x400090A8 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD5_SLAST  *(volatile int32_t *)0x400090AC  // TCD Last Source Addr Adj.\n"
  "//register DMA_TCD5_DADDR  *(volatile void * volatile *)0x400090B0 // TCD Destination Address\n"
  "//register DMA_TCD5_DOFF  *(volatile int16_t *)0x400090B4  // TCD Signed Dest Address Offset\n"
  "//register DMA_TCD5_CITER_ELINKYES *(volatile $uint16_t *)0x400090B6 // TCD Current Minor Loop Link\n"
  "//register DMA_TCD5_CITER_ELINKNO *(volatile $uint16_t *)0x400090B6 // \?\?\n"
  "//register DMA_TCD5_DLASTSGA *(volatile int32_t *)0x400090B8  // TCD Last Destination Addr Adj\n"
  "//register DMA_TCD5_CSR  *(volatile $uint16_t *)0x400090BC // TCD Control and Status\n"
  "//register DMA_TCD5_BITER_ELINKYES *(volatile $uint16_t *)0x400090BE // TCD Beginning Minor Loop Link\n"
  "//register DMA_TCD5_BITER_ELINKNO *(volatile $uint16_t *)0x400090BE // TCD Beginning Minor Loop Link\n"
  "//\n"
  "//register DMA_TCD6_SADDR  *(volatile const void * volatile *)0x400090C0 // TCD Source Addr\n"
  "//register DMA_TCD6_SOFF  *(volatile int16_t *)0x400090C4  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD6_ATTR  *(volatile $uint16_t *)0x400090C6 // TCD Transfer Attributes\n"
  "//register DMA_TCD6_NBYTES_MLNO  0x400090C8 // TCD Minor Byte Count\n"
  "//register DMA_TCD6_NBYTES_MLOFFNO  0x400090C8 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD6_NBYTES_MLOFFYES  0x400090C8 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD6_SLAST  *(volatile int32_t *)0x400090CC  // TCD Last Source Addr Adj.\n"
  "//register DMA_TCD6_DADDR  *(volatile void * volatile *)0x400090D0 // TCD Destination Address\n"
  "//register DMA_TCD6_DOFF  *(volatile int16_t *)0x400090D4  // TCD Signed Dest Address Offset\n"
  "//register DMA_TCD6_CITER_ELINKYES *(volatile $uint16_t *)0x400090D6 // TCD Current Minor Loop Link\n"
  "//register DMA_TCD6_CITER_ELINKNO *(volatile $uint16_t *)0x400090D6 // \?\?\n"
  "//register DMA_TCD6_DLASTSGA *(volatile int32_t *)0x400090D8  // TCD Last Destination Addr Adj\n"
  "//register DMA_TCD6_CSR  *(volatile $uint16_t *)0x400090DC // TCD Control and Status\n"
  "//register DMA_TCD6_BITER_ELINKYES *(volatile $uint16_t *)0x400090DE // TCD Beginning Minor Loop Link\n"
  "//register DMA_TCD6_BITER_ELINKNO *(volatile $uint16_t *)0x400090DE // TCD Beginning Minor Loop Link\n"
  "//\n"
  "//register DMA_TCD7_SADDR  *(volatile const void * volatile *)0x400090E0 // TCD Source Addr\n"
  "//register DMA_TCD7_SOFF  *(volatile int16_t *)0x400090E4  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD7_ATTR  *(volatile $uint16_t *)0x400090E6 // TCD Transfer Attributes\n"
  "//register DMA_TCD7_NBYTES_MLNO  0x400090E8 // TCD Minor Byte Count\n"
  "//register DMA_TCD7_NBYTES_MLOFFNO  0x400090E8 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD7_NBYTES_MLOFFYES  0x400090E8 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD7_SLAST  *(volatile int32_t *)0x400090EC  // TCD Last Source Addr Adj.\n"
  "//register DMA_TCD7_DADDR  *(volatile void * volatile *)0x400090F0 // TCD Destination Address\n"
  "//register DMA_TCD7_DOFF  *(volatile int16_t *)0x400090F4  // TCD Signed Dest Address Offset\n"
  "//register DMA_TCD7_CITER_ELINKYES *(volatile $uint16_t *)0x400090F6 // TCD Current Minor Loop Link\n"
  "//register DMA_TCD7_CITER_ELINKNO *(volatile $uint16_t *)0x400090F6 // \?\?\n"
  "//register DMA_TCD7_DLASTSGA *(volatile int32_t *)0x400090F8  // TCD Last Destination Addr Adj\n"
  "//register DMA_TCD7_CSR  *(volatile $uint16_t *)0x400090FC // TCD Control and Status\n"
  "//register DMA_TCD7_BITER_ELINKYES *(volatile $uint16_t *)0x400090FE // TCD Beginning Minor Loop Link\n"
  "//register DMA_TCD7_BITER_ELINKNO *(volatile $uint16_t *)0x400090FE // TCD Beginning Minor Loop Link\n"
  "//\n"
  "//register DMA_TCD8_SADDR  *(volatile const void * volatile *)0x40009100 // TCD Source Addr\n"
  "//register DMA_TCD8_SOFF  *(volatile int16_t *)0x40009104  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD8_ATTR  *(volatile $uint16_t *)0x40009106 // TCD Transfer Attributes\n"
  "//register DMA_TCD8_NBYTES_MLNO  0x40009108 // TCD Minor Byte Count\n"
  "//register DMA_TCD8_NBYTES_MLOFFNO  0x40009108 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD8_NBYTES_MLOFFYES  0x40009108 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD8_SLAST  *(volatile int32_t *)0x4000910C  // TCD Last Source Addr Adj.\n"
  "//register DMA_TCD8_DADDR  *(volatile void * volatile *)0x40009110 // TCD Destination Address\n"
  "//register DMA_TCD8_DOFF  *(volatile int16_t *)0x40009114  // TCD Signed Dest Address Offset\n"
  "//register DMA_TCD8_CITER_ELINKYES *(volatile $uint16_t *)0x40009116 // TCD Current Minor Loop Link\n"
  "//register DMA_TCD8_CITER_ELINKNO *(volatile $uint16_t *)0x40009116 // \?\?\n"
  "//register DMA_TCD8_DLASTSGA *(volatile int32_t *)0x40009118  // TCD Last Destination Addr Adj\n"
  "//register DMA_TCD8_CSR  *(volatile $uint16_t *)0x4000911C // TCD Control and Status\n"
  "//register DMA_TCD8_BITER_ELINKYES *(volatile $uint16_t *)0x4000911E // TCD Beginning Minor Loop Link\n"
  "//register DMA_TCD8_BITER_ELINKNO *(volatile $uint16_t *)0x4000911E // TCD Beginning Minor Loop Link\n"
  "//\n"
  "//register DMA_TCD9_SADDR  *(volatile const void * volatile *)0x40009120 // TCD Source Addr\n"
  "//register DMA_TCD9_SOFF  *(volatile int16_t *)0x40009124  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD9_ATTR  *(volatile $uint16_t *)0x40009126 // TCD Transfer Attributes\n"
  "//register DMA_TCD9_NBYTES_MLNO  0x40009128 // TCD Minor Byte Count\n"
  "//register DMA_TCD9_NBYTES_MLOFFNO  0x40009128 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD9_NBYTES_MLOFFYES  0x40009128 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD9_SLAST  *(volatile int32_t *)0x4000912C  // TCD Last Source Addr Adj.\n"
  "//register DMA_TCD9_DADDR  *(volatile void * volatile *)0x40009130 // TCD Destination Address\n"
  "//register DMA_TCD9_DOFF  *(volatile int16_t *)0x40009134  // TCD Signed Dest Address Offset\n"
  "//register DMA_TCD9_CITER_ELINKYES *(volatile $uint16_t *)0x40009136 // TCD Current Minor Loop Link\n"
  "//register DMA_TCD9_CITER_ELINKNO *(volatile $uint16_t *)0x40009136 // \?\?\n"
  "//register DMA_TCD9_DLASTSGA *(volatile int32_t *)0x40009138  // TCD Last Destination Addr Adj\n"
  "//register DMA_TCD9_CSR  *(volatile $uint16_t *)0x4000913C // TCD Control and Status\n"
  "//register DMA_TCD9_BITER_ELINKYES *(volatile $uint16_t *)0x4000913E // TCD Beginning Minor Loop Link\n"
  "//register DMA_TCD9_BITER_ELINKNO *(volatile $uint16_t *)0x4000913E // TCD Beginning Minor Loop Link\n"
  "//\n"
  "//register DMA_TCD10_SADDR  *(volatile const void * volatile *)0x40009140 // TCD Source Addr\n"
  "//register DMA_TCD10_SOFF  *(volatile int16_t *)0x40009144  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD10_ATTR  *(volatile $uint16_t *)0x40009146 // TCD Transfer Attributes\n"
  "//register DMA_TCD10_NBYTES_MLNO  0x40009148 // TCD Minor Byte Count\n"
  "//register DMA_TCD10_NBYTES_MLOFFNO  0x40009148 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD10_NBYTES_MLOFFYES  0x40009148 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD10_SLAST  *(volatile int32_t *)0x4000914C  // TCD Last Source Addr Adj.\n"
  "//register DMA_TCD10_DADDR  *(volatile void * volatile *)0x40009150 // TCD Destination Address\n"
  "//register DMA_TCD10_DOFF  *(volatile int16_t *)0x40009154  // TCD Signed Dest Address Offset\n"
  "//register DMA_TCD10_CITER_ELINKYES *(volatile $uint16_t *)0x40009156 // TCD Current Minor Loop Link\n"
  "//register DMA_TCD10_CITER_ELINKNO *(volatile $uint16_t *)0x40009156 // \?\?\n"
  "//register DMA_TCD10_DLASTSGA *(volatile int32_t *)0x40009158  // TCD Last Destination Addr Adj\n"
  "//register DMA_TCD10_CSR  *(volatile $uint16_t *)0x4000915C // TCD Control and Status\n"
  "//register DMA_TCD10_BITER_ELINKYES *(volatile $uint16_t *)0x4000915E // TCD Beginning Minor Loop Link\n"
  "//register DMA_TCD10_BITER_ELINKNO *(volatile $uint16_t *)0x4000915E // TCD Beginning Minor Loop Link\n"
  "//\n"
  "//register DMA_TCD11_SADDR  *(volatile const void * volatile *)0x40009160 // TCD Source Addr\n"
  "//register DMA_TCD11_SOFF  *(volatile int16_t *)0x40009164  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD11_ATTR  *(volatile $uint16_t *)0x40009166 // TCD Transfer Attributes\n"
  "//register DMA_TCD11_NBYTES_MLNO  0x40009168 // TCD Minor Byte Count\n"
  "//register DMA_TCD11_NBYTES_MLOFFNO  0x40009168 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD11_NBYTES_MLOFFYES  0x40009168 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD11_SLAST  *(volatile int32_t *)0x4000916C  // TCD Last Source Addr Adj.\n"
  "//register DMA_TCD11_DADDR  *(volatile void * volatile *)0x40009170 // TCD Destination Address\n"
  "//register DMA_TCD11_DOFF  *(volatile int16_t *)0x40009174  // TCD Signed Dest Address Offset\n"
  "//register DMA_TCD11_CITER_ELINKYES *(volatile $uint16_t *)0x40009176 // TCD Current Minor Loop Link\n"
  "//register DMA_TCD11_CITER_ELINKNO *(volatile $uint16_t *)0x40009176 // \?\?\n"
  "//register DMA_TCD11_DLASTSGA *(volatile int32_t *)0x40009178  // TCD Last Destination Addr Adj\n"
  "//register DMA_TCD11_CSR  *(volatile $uint16_t *)0x4000917C // TCD Control and Status\n"
  "//register DMA_TCD11_BITER_ELINKYES *(volatile $uint16_t *)0x4000917E // TCD Beginning Minor Loop Link\n"
  "//register DMA_TCD11_BITER_ELINKNO *(volatile $uint16_t *)0x4000917E // TCD Beginning Minor Loop Link\n"
  "//\n"
  "//register DMA_TCD12_SADDR  *(volatile const void * volatile *)0x40009180 // TCD Source Addr\n"
  "//register DMA_TCD12_SOFF  *(volatile int16_t *)0x40009184  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD12_ATTR  *(volatile $uint16_t *)0x40009186 // TCD Transfer Attributes\n"
  "//register DMA_TCD12_NBYTES_MLNO  0x40009188 // TCD Minor Byte Count\n"
  "//register DMA_TCD12_NBYTES_MLOFFNO  0x40009188 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD12_NBYTES_MLOFFYES  0x40009188 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD12_SLAST  *(volatile int32_t *)0x4000918C  // TCD Last Source Addr Adj.\n"
  "//register DMA_TCD12_DADDR  *(volatile void * volatile *)0x40009190 // TCD Destination Address\n"
  "//register DMA_TCD12_DOFF  *(volatile int16_t *)0x40009194  // TCD Signed Dest Address Offset\n"
  "//register DMA_TCD12_CITER_ELINKYES *(volatile $uint16_t *)0x40009196 // TCD Current Minor Loop Link\n"
  "//register DMA_TCD12_CITER_ELINKNO *(volatile $uint16_t *)0x40009196 // \?\?\n"
  "//register DMA_TCD12_DLASTSGA *(volatile int32_t *)0x40009198  // TCD Last Destination Addr Adj\n"
  "//register DMA_TCD12_CSR  *(volatile $uint16_t *)0x4000919C // TCD Control and Status\n"
  "//register DMA_TCD12_BITER_ELINKYES *(volatile $uint16_t *)0x4000919E // TCD Beginning Minor Loop Link\n"
  "//register DMA_TCD12_BITER_ELINKNO *(volatile $uint16_t *)0x4000919E // TCD Beginning Minor Loop Link\n"
  "//\n"
  "//register DMA_TCD13_SADDR  *(volatile const void * volatile *)0x400091A0 // TCD Source Addr\n"
  "//register DMA_TCD13_SOFF  *(volatile int16_t *)0x400091A4  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD13_ATTR  *(volatile $uint16_t *)0x400091A6 // TCD Transfer Attributes\n"
  "//register DMA_TCD13_NBYTES_MLNO  0x400091A8 // TCD Minor Byte Count\n"
  "//register DMA_TCD13_NBYTES_MLOFFNO  0x400091A8 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD13_NBYTES_MLOFFYES  0x400091A8 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD13_SLAST  *(volatile int32_t *)0x400091AC  // TCD Last Source Addr Adj.\n"
  "//register DMA_TCD13_DADDR  *(volatile void * volatile *)0x400091B0 // TCD Destination Address\n"
  "//register DMA_TCD13_DOFF  *(volatile int16_t *)0x400091B4  // TCD Signed Dest Address Offset\n"
  "//register DMA_TCD13_CITER_ELINKYES *(volatile $uint16_t *)0x400091B6 // TCD Current Minor Loop Link\n"
  "//register DMA_TCD13_CITER_ELINKNO *(volatile $uint16_t *)0x400091B6 // \?\?\n"
  "//register DMA_TCD13_DLASTSGA *(volatile int32_t *)0x400091B8  // TCD Last Destination Addr Adj\n"
  "//register DMA_TCD13_CSR  *(volatile $uint16_t *)0x400091BC // TCD Control and Status\n"
  "//register DMA_TCD13_BITER_ELINKYES *(volatile $uint16_t *)0x400091BE // TCD Beginning Minor Loop Link\n"
  "//register DMA_TCD13_BITER_ELINKNO *(volatile $uint16_t *)0x400091BE // TCD Beginning Minor Loop Link\n"
  "//\n"
  "//register DMA_TCD14_SADDR  *(volatile const void * volatile *)0x400091C0 // TCD Source Addr\n"
  "//register DMA_TCD14_SOFF  *(volatile int16_t *)0x400091C4  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD14_ATTR  *(volatile $uint16_t *)0x400091C6 // TCD Transfer Attributes\n"
  "//register DMA_TCD14_NBYTES_MLNO  0x400091C8 // TCD Minor Byte Count\n"
  "//register DMA_TCD14_NBYTES_MLOFFNO  0x400091C8 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD14_NBYTES_MLOFFYES  0x400091C8 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD14_SLAST  *(volatile int32_t *)0x400091CC  // TCD Last Source Addr Adj.\n"
  "//register DMA_TCD14_DADDR  *(volatile void * volatile *)0x400091D0 // TCD Destination Address\n"
  "//register DMA_TCD14_DOFF  *(volatile int16_t *)0x400091D4  // TCD Signed Dest Address Offset\n"
  "//register DMA_TCD14_CITER_ELINKYES *(volatile $uint16_t *)0x400091D6 // TCD Current Minor Loop Link\n"
  "//register DMA_TCD14_CITER_ELINKNO *(volatile $uint16_t *)0x400091D6 // \?\?\n"
  "//register DMA_TCD14_DLASTSGA *(volatile int32_t *)0x400091D8  // TCD Last Destination Addr Adj\n"
  "//register DMA_TCD14_CSR  *(volatile $uint16_t *)0x400091DC // TCD Control and Status\n"
  "//register DMA_TCD14_BITER_ELINKYES *(volatile $uint16_t *)0x400091DE // TCD Beginning Minor Loop Link\n"
  "//register DMA_TCD14_BITER_ELINKNO *(volatile $uint16_t *)0x400091DE // TCD Beginning Minor Loop Link\n"
  "//\n"
  "//register DMA_TCD15_SADDR  *(volatile const void * volatile *)0x400091E0 // TCD Source Addr\n"
  "//register DMA_TCD15_SOFF  *(volatile int16_t *)0x400091E4  // TCD Signed Source Address Offset\n"
  "//register DMA_TCD15_ATTR  *(volatile $uint16_t *)0x400091E6 // TCD Transfer Attributes\n"
  "//register DMA_TCD15_NBYTES_MLNO  0x400091E8 // TCD Minor Byte Count\n"
  "//register DMA_TCD15_NBYTES_MLOFFNO  0x400091E8 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD15_NBYTES_MLOFFYES  0x400091E8 // TCD Signed Minor Loop Offset\n"
  "//register DMA_TCD15_SLAST  *(volatile int32_t *)0x400091EC  // TCD Last Source Addr Adj.\n"
  "//register DMA_TCD15_DADDR  *(volatile void * volatile *)0x400091F0 // TCD Destination Address\n"
  "//register DMA_TCD15_DOFF  *(volatile int16_t *)0x400091F4  // TCD Signed Dest Address Offset\n"
  "//register DMA_TCD15_CITER_ELINKYES *(volatile $uint16_t *)0x400091F6 // TCD Current Minor Loop Link\n"
  "//register DMA_TCD15_CITER_ELINKNO *(volatile $uint16_t *)0x400091F6 // \?\?\n"
  "//register DMA_TCD15_DLASTSGA *(volatile int32_t *)0x400091F8  // TCD Last Destination Addr Adj\n"
  "//register DMA_TCD15_CSR  *(volatile $uint16_t *)0x400091FC // TCD Control and Status\n"
  "//register DMA_TCD15_BITER_ELINKYES *(volatile $uint16_t *)0x400091FE // TCD Beginning Minor Loop Link\n"
  "//register DMA_TCD15_BITER_ELINKNO *(volatile $uint16_t *)0x400091FE // TCD Beginning Minor Loop Link\n"
  "//\n"
  "//\n"
  "//// Chapter 22: External Watchdog Monitor (EWM)\n"
  "//register EWM_CTRL  *(volatile $uint8_t  *)0x40061000 // Control Register\n"
  "//register EWM_SERV  *(volatile $uint8_t  *)0x40061001 // Service Register\n"
  "//register EWM_CMPL  *(volatile $uint8_t  *)0x40061002 // Compare Low Register\n"
  "//register EWM_CMPH  *(volatile $uint8_t  *)0x40061003 // Compare High Register\n"
  "//\n"
  "//// Chapter 23: Watchdog Timer (WDOG)\n"
  "register WDOG_STCTRLH at 0x40052000 $uint16 // Watchdog Status and Control Register High\n"
  "let WDOG_STCTRLH_DISTESTWDOG $uint16 = 0x4000  // Allows the WDOG's functional test mode to be disabled permanently.\n"
  "//register WDOG_STCTRLH_BYTESEL(n)  ($uint16_t)(((n) & 3) << 12) // selects the byte to be tested when the watchdog is in the byte test mode.\n"
  "let WDOG_STCTRLH_TESTSEL  $uint16 = 0x0800\n"
  "let WDOG_STCTRLH_TESTWDOG $uint16 = 0x0400\n"
  "let WDOG_STCTRLH_WAITEN $uint16 = 0x0080\n"
  "let WDOG_STCTRLH_STOPEN $uint16 = 0x0040\n"
  "let WDOG_STCTRLH_DBGEN  $uint16 = 0x0020\n"
  "let WDOG_STCTRLH_ALLOWUPDATE $uint16 = 0x0010\n"
  "let WDOG_STCTRLH_WINEN $uint16 = 0x0008\n"
  "let WDOG_STCTRLH_IRQRSTEN $uint16 = 0x0004\n"
  "let WDOG_STCTRLH_CLKSRC $uint16 = 0x0002\n"
  "let WDOG_STCTRLH_WDOGEN $uint16 = 0x0001\n"
  "register WDOG_STCTRLL  at 0x40052002 $uint16 // Watchdog Status and Control Register Low\n"
  "register WDOG_TOVALH   at 0x40052004 $uint16 // Watchdog Time-out Value Register High\n"
  "register WDOG_TOVALL   at 0x40052006 $uint16 // Watchdog Time-out Value Register Low\n"
  "register WDOG_WINH     at 0x40052008 $uint16 // Watchdog Window Register High\n"
  "register WDOG_WINL     at 0x4005200A $uint16 // Watchdog Window Register Low\n"
  "register WDOG_REFRESH  at 0x4005200C $uint16 // Watchdog Refresh register\n"
  "register WDOG_UNLOCK   at 0x4005200E $uint16 // Watchdog Unlock register\n"
  "let WDOG_UNLOCK_SEQ1 $uint16   = 0xC520\n"
  "let WDOG_UNLOCK_SEQ2 $uint16   = 0xD928\n"
  "register WDOG_TMROUTH  at 0x40052010 $uint16 // Watchdog Timer Output Register High\n"
  "register WDOG_TMROUTL  at 0x40052012 $uint16 // Watchdog Timer Output Register Low\n"
  "register WDOG_RSTCNT   at 0x40052014 $uint16 // Watchdog Reset Count register\n"
  "register WDOG_PRESC    at 0x40052016 $uint16 // Watchdog Prescaler register\n"
  "\n"
  "// Chapter 24: Multipurpose Clock Generator (MCG)\n"
  "register MCG_C1 at 0x40064000 $uint8 { // MCG Control 1 Register\n"
  "  CLKS [2], // Clock Source Select, Selects the clock source for MCGOUTCLK\n"
  "  FRDIV [3], // FLL External Reference Divider, Selects the amount to divide down the external reference clock for the FLL\n"
  "  IREFS, // Internal Reference Select, Selects the reference clock source for the FLL\n"
  "  IRCLKEN, // Internal Reference Clock Enable, Enables the internal reference clock for use as MCGIRCLK\n"
  "  IREFSTEN // Internal Reference Stop Enable, Controls whether or not the internal reference clock remains enabled when the MCG enters Stop mode\n"
  "}\n"
  "\n"
  "register MCG_C2 at 0x4006_4001 $uint8 { // MCG Control 2 Register\n"
  "  LOCRE0, // Loss of Clock Reset Enable, Determines whether an interrupt \n"
  "          // or a reset request is made following a loss of OSC0\n"
  "  1,\n"
  "  RANGE0[2], // Frequency Range Select, Selects the frequency range\n"
  "             // for the crystal oscillator\n"
  "  HGO0, // High Gain Oscillator Select, Controls the crystal oscillator mode of operation  \n"
  "  EREFS, // External Reference Select, selects the source for the external reference clock\n"
  "  LP, // Low Power Select, Controls whether the FLL or PLL is disabled in BLPI and BLPE modes.\n"
  "  IRCS // Internal Reference Clock Select, Selects between the fast or slow internal reference clock source.\n"
  "}\n"
  "\n"
  "register MCG_C3 at 0x4006_4002 $uint8 // MCG Control 3 Register\n"
  "//register MCG_C3_SCTRIM(n)  ($uint8_t)(n)   // Slow Internal Reference Clock Trim Setting\n"
  "register MCG_C4 at 0x40064003 $uint8 // MCG Control 4 Register\n"
  "let MCG_C4_SCFTRIM $uint8 = 0x01   // Slow Internal Reference Clock Fine Trim\n"
  "//register MCG_C4_FCTRIM(n)  ($uint8_t)(((n) & 0x0F) << 1) // Fast Internal Reference Clock Trim Setting\n"
  "//register MCG_C4_DRST_DRS(n)  ($uint8_t)(((n) & 0x03) << 5) // DCO Range Select\n"
  "let MCG_C4_DMX32 $uint8 = 0x80   // DCO Maximum Frequency with 32.768 kHz Reference, controls whether the DCO frequency range is narrowed\n"
  "\n"
  "\n"
  "register MCG_C5 at 0x4006_4004 $uint8 { // MCG Control 5 Register\n"
  " 1,\n"
  " PLLCLKEN0, // PLL Clock Enable\n"
  " PLLSTEN0,  // PLL Stop Enable\n"
  " PRDIV0 [5] // PLL External Reference Divider\n"
  "}\n"
  "\n"
  "register MCG_C6 at 0x4006_4005 $uint8 { // MCG Control 6 Register\n"
  " LOLIE0, // Loss of Lock Interrrupt Enable\n"
  " PLLS, // PLL Select, Controls whether the PLL or FLL output is selected as the MCG source when CLKS[1:0]=00\n"
  " CME0,   // Clock Monitor Enable\n"
  " VDIV0[5] // VCO 0 Divider\n"
  "}\n"
  "\n"
  "register MCG_S @ro at 0x40064006 $uint8 { // MCG Status Register\n"
  " LOLS0, // Loss of Lock Status\n"
  " LOCK0, // Lock Status, 0=PLL Unlocked, 1=PLL Locked\n"
  " PLLST, // PLL Select Status\n"
  " IREFST, // Internal Reference Status\n"
  " CLKST [2], // Clock Mode Status, 0=FLL is selected, 1= Internal ref, 2=External ref, 3=PLL\n"
  " OSCINIT0, // OSC Initialization, resets to 0, is set to 1 after the initialization cycles of the crystal oscillator\n"
  " IRCST   // Internal Reference Clock Status\n"
  "}\n"
  "\n"
  "register MCG_SC at 0x40064008 $uint8 // MCG Status and Control Register\n"
  "let MCG_SC_LOCS0 $uint8 = 0x01   // OSC0 Loss of Clock Status\n"
  "//register MCG_SC_FCRDIV(n)  ($uint8_t)(((n) & 0x07) << 1) // Fast Clock Internal Reference Divider\n"
  "let MCG_SC_FLTPRSRV $uint8 = 0x10   // FLL Filter Preserve Enable\n"
  "let MCG_SC_ATMF $uint8 = 0x20   // Automatic Trim Machine Fail Flag\n"
  "let MCG_SC_ATMS $uint8 = 0x40   // Automatic Trim Machine Select\n"
  "let MCG_SC_ATME $uint8 = 0x80   // Automatic Trim Machine Enable\n"
  "\n"
  "register MCG_ATCVH at 0x4006400A $uint8 // MCG Auto Trim Compare Value High Register\n"
  "register MCG_ATCVL at 0x4006400B $uint8 // MCG Auto Trim Compare Value Low Register\n"
  "register MCG_C7    at 0x4006400C $uint8 // MCG Control 7 Register\n"
  "register MCG_C8    at 0x4006400D $uint8 // MCG Control 8 Register\n"
  "//\n"
  "//// Chapter 25: Oscillator (OSC)\n"
  "register OSC_CR at 0x40065000 $uint8 {// OSC Control Register\n"
  "  ERCLKEN, // External Reference Enable, Enables external reference clock (OSCERCLK)\n"
  "  1,\n"
  "  EREFSTEN, // External Reference Stop Enable, Controls whether or not \n"
  "            // the external reference clock (OSCERCLK) remains enabled when\n"
  "            // MCU enters Stop mode.\n"
  "  1,\n"
  "  SC2P, // Oscillator 2 pF Capacitor Load Configure\n"
  "  SC4P, // Oscillator 4 pF Capacitor Load Configure\n"
  "  SC8P, // Oscillator 8 pF Capacitor Load Configure\n"
  "  SC16P // Oscillator 16 pF Capacitor Load Configure\n"
  "}\n"
  "let OSC_SC16P  $uint8 = 0x01   \n"
  "\n"
  "//// Chapter 27: Flash Memory Controller (FMC)\n"
  "register FMC_PFAPR     at 0x4001F000 $uint32 // Flash Access Protection\n"
  "register FMC_PFB0CR    at 0x4001F004 $uint32 // Flash Control\n"
  "register FMC_TAGVDW0S0 at 0x4001F100 $uint32 // Cache Tag Storage\n"
  "register FMC_TAGVDW0S1 at 0x4001F104 $uint32 // Cache Tag Storage\n"
  "register FMC_TAGVDW1S0 at 0x4001F108 $uint32 // Cache Tag Storage\n"
  "register FMC_TAGVDW1S1 at 0x4001F10C $uint32 // Cache Tag Storage\n"
  "register FMC_TAGVDW2S0 at 0x4001F110 $uint32 // Cache Tag Storage\n"
  "register FMC_TAGVDW2S1 at 0x4001F114 $uint32 // Cache Tag Storage\n"
  "register FMC_TAGVDW3S0 at 0x4001F118 $uint32 // Cache Tag Storage\n"
  "register FMC_TAGVDW3S1 at 0x4001F11C $uint32 // Cache Tag Storage\n"
  "register FMC_DATAW0S0  at 0x4001F200 $uint32 // Cache Data Storage\n"
  "register FMC_DATAW0S1  at 0x4001F204 $uint32 // Cache Data Storage\n"
  "register FMC_DATAW1S0  at 0x4001F208 $uint32 // Cache Data Storage\n"
  "register FMC_DATAW1S1  at 0x4001F20C $uint32 // Cache Data Storage\n"
  "register FMC_DATAW2S0  at 0x4001F210 $uint32 // Cache Data Storage\n"
  "register FMC_DATAW2S1  at 0x4001F214 $uint32 // Cache Data Storage\n"
  "register FMC_DATAW3S0  at 0x4001F218 $uint32 // Cache Data Storage\n"
  "register FMC_DATAW3S1  at 0x4001F21C $uint32 // Cache Data Storage\n"
  "//\n"
  "//// Chapter 28: Flash Memory Module (FTFL)\n"
  "//register FTFL_FST *(volatile $uint8_t  *)0x40020000      // Flash Status Register\n"
  "//register FTFL_FSTAT_CCIF   ($uint8_t)0x80   // Command Complete Interrupt Flag\n"
  "//register FTFL_FSTAT_RDCOLERR  ($uint8_t)0x40   // Flash Read Collision Error Flag\n"
  "//register FTFL_FSTAT_ACCERR  ($uint8_t)0x20   // Flash Access Error Flag\n"
  "//register FTFL_FSTAT_FPVIOL  ($uint8_t)0x10   // Flash Protection Violation Flag\n"
  "//register FTFL_FSTAT_MGSTAT0  ($uint8_t)0x01   // Memory Controller Command Completion Status Flag\n"
  "//register FTFL_FCNFG  *(volatile $uint8_t  *)0x40020001      // Flash Configuration Register\n"
  "//register FTFL_FCNFG_CCIE   ($uint8_t)0x80   // Command Complete Interrupt Enable\n"
  "//register FTFL_FCNFG_RDCOLLIE  ($uint8_t)0x40   // Read Collision Error Interrupt Enable\n"
  "//register FTFL_FCNFG_ERSAREQ  ($uint8_t)0x20   // Erase All Request\n"
  "//register FTFL_FCNFG_ERSSUSP  ($uint8_t)0x10   // Erase Suspend\n"
  "//register FTFL_FCNFG_PFLSH  ($uint8_t)0x04   // Flash memory configuration\n"
  "//register FTFL_FCNFG_RAMRDY  ($uint8_t)0x02   // RAM Ready\n"
  "//register FTFL_FCNFG_EEERDY  ($uint8_t)0x01   // EEPROM Ready\n"
  "//register FTFL_FSEC  *(const    $uint8_t  *)0x40020002      // Flash Security Register\n"
  "//register FTFL_FOPT  *(const    $uint8_t  *)0x40020003      // Flash Option Register\n"
  "//register FTFL_FCCOB3  *(volatile $uint8_t  *)0x40020004      // Flash Common Command Object Registers\n"
  "//register FTFL_FCCOB2  *(volatile $uint8_t  *)0x40020005\n"
  "//register FTFL_FCCOB1  *(volatile $uint8_t  *)0x40020006\n"
  "//register FTFL_FCCOB0  *(volatile $uint8_t  *)0x40020007\n"
  "//register FTFL_FCCOB7  *(volatile $uint8_t  *)0x40020008\n"
  "//register FTFL_FCCOB6  *(volatile $uint8_t  *)0x40020009\n"
  "//register FTFL_FCCOB5  *(volatile $uint8_t  *)0x4002000A\n"
  "//register FTFL_FCCOB4  *(volatile $uint8_t  *)0x4002000B\n"
  "//register FTFL_FCCOBB  *(volatile $uint8_t  *)0x4002000C\n"
  "//register FTFL_FCCOBA  *(volatile $uint8_t  *)0x4002000D\n"
  "//register FTFL_FCCOB9  *(volatile $uint8_t  *)0x4002000E\n"
  "//register FTFL_FCCOB8  *(volatile $uint8_t  *)0x4002000F\n"
  "//register FTFL_FPROT3  *(volatile $uint8_t  *)0x40020010      // Program Flash Protection Registers\n"
  "//register FTFL_FPROT2  *(volatile $uint8_t  *)0x40020011      // Program Flash Protection Registers\n"
  "//register FTFL_FPROT1  *(volatile $uint8_t  *)0x40020012      // Program Flash Protection Registers\n"
  "//register FTFL_FPROT0  *(volatile $uint8_t  *)0x40020013      // Program Flash Protection Registers\n"
  "//register FTFL_FEPROT  *(volatile $uint8_t  *)0x40020016      // EEPROM Protection Register\n"
  "//register FTFL_FDPROT  *(volatile $uint8_t  *)0x40020017      // Data Flash Protection Register\n"
  "\n"
  "// Chapter 30: Cyclic Redundancy Check (CRC)\n"
  "register CRC_CRC   at 0x40032000 $uint32 // CRC Data register\n"
  "register CRC_GPOLY at 0x40032004 $uint32 // CRC Polynomial register\n"
  "register CRC_CTRL  at 0x40032008 $uint32 // CRC Control register\n"
  "\n"
  "// Chapter 31: Analog-to-Digital Converter (ADC)\n"
  "register ADC0_SC1A   at 0x4003B000 $uint32 // ADC status and control registers 1\n"
  "register ADC0_SC1B   at 0x4003B004 $uint32 // ADC status and control registers 1\n"
  "let ADC_SC1_COCO  $uint32 = 0x80   // Conversion complete flag\n"
  "let ADC_SC1_AIEN  $uint32 = 0x40   // Interrupt enable\n"
  "let ADC_SC1_DIFF  $uint32 = 0x20   // Differential mode enable\n"
  "//register ADC_SC1_ADCH(n)    ((n) & 0x1F)  // Input channel select\n"
  "register ADC0_CFG1   at 0x4003B008 $uint32 // ADC configuration register 1\n"
  "let ADC_CFG1_ADLPC  $uint32 = 0x80   // Low-power configuration\n"
  "//register ADC_CFG1_ADIV(n)   (((n) & 3) << 5) // Clock divide select, 0=direct, 1=div2, 2=div4, 3=div8\n"
  "let ADC_CFG1_ADLSMP  $uint32 = 0x10   // Sample time configuration, 0=Short, 1=Long\n"
  "//register ADC_CFG1_MODE(n)   (((n) & 3) << 2) // Conversion mode, 0=8 bit, 1=12 bit, 2=10 bit, 3=16 bit\n"
  "//register ADC_CFG1_ADICLK(n)   (((n) & 3) << 0) // Input clock, 0=bus, 1=bus/2, 2=OSCERCLK, 3=async\n"
  "register ADC0_CFG2  at 0x4003B00C $uint32 // Configuration register 2\n"
  "let ADC_CFG2_MUXSEL  $uint32 = 0x10   // 0=a channels, 1=b channels\n"
  "let ADC_CFG2_ADACKEN  $uint32 = 0x08   // async clock enable\n"
  "let ADC_CFG2_ADHSC   $uint32 = 0x04   // High speed configuration\n"
  "//register ADC_CFG2_ADLSTS(n)   (((n) & 3) << 0) // Sample time, 0=24 cycles, 1=12 cycles, 2=6 cycles, 3=2 cycles\n"
  "register ADC0_RA    at 0x4003B010 $uint32 // ADC data result register\n"
  "register ADC0_RB    at 0x4003B014 $uint32 // ADC data result register\n"
  "register ADC0_CV1   at 0x4003B018 $uint32 // Compare value registers\n"
  "register ADC0_CV2   at 0x4003B01C $uint32 // Compare value registers\n"
  "register ADC0_SC2   at 0x4003B020 $uint32 // Status and control register 2\n"
  "let ADC_SC2_ADACT  $uint32 = 0x80   // Conversion active\n"
  "let ADC_SC2_ADTRG  $uint32 = 0x40   // Conversion trigger select, 0=software, 1=hardware\n"
  "let ADC_SC2_ACFE   $uint32 = 0x20   // Compare function enable\n"
  "let ADC_SC2_ACFGT  $uint32 = 0x10   // Compare function greater than enable\n"
  "let ADC_SC2_ACREN  $uint32 = 0x08   // Compare function range enable\n"
  "let ADC_SC2_DMAEN  $uint32= 0x04   // DMA enable\n"
  "//register ADC_SC2_REFSEL(n)   (((n) & 3) << 0) // Voltage reference, 0=vcc/external, 1=1.2 volts\n"
  "register ADC0_SC3   at 0x4003B024 $uint32 // Status and control register 3\n"
  "let ADC_SC3_CAL  $uint32 = 0x80   // Calibration, 1=begin, stays set while cal in progress\n"
  "let ADC_SC3_CALF  $uint32= 0x40   // Calibration failed flag\n"
  "let ADC_SC3_ADCO  $uint32= 0x08   // Continuous conversion enable\n"
  "let ADC_SC3_AVGE  $uint32= 0x04   // Hardware average enable\n"
  "//register ADC_SC3_AVGS(n)    (((n) & 3) << 0) // avg select, 0=4 samples, 1=8 samples, 2=16 samples, 3=32 samples\n"
  "register ADC0_OFS   at 0x4003B028 $uint32 // ADC offset correction register\n"
  "register ADC0_PG    at 0x4003B02C $uint32 // ADC plus-side gain register\n"
  "register ADC0_MG    at 0x4003B030 $uint32 // ADC minus-side gain register\n"
  "register ADC0_CLPD  at 0x4003B034 $uint32 // ADC plus-side general calibration value register\n"
  "register ADC0_CLPS  at 0x4003B038 $uint32 // ADC plus-side general calibration value register\n"
  "register ADC0_CLP4  at 0x4003B03C $uint32 // ADC plus-side general calibration value register\n"
  "register ADC0_CLP3  at 0x4003B040 $uint32 // ADC plus-side general calibration value register\n"
  "register ADC0_CLP2  at 0x4003B044 $uint32 // ADC plus-side general calibration value register\n"
  "register ADC0_CLP1  at 0x4003B048 $uint32 // ADC plus-side general calibration value register\n"
  "register ADC0_CLP0  at 0x4003B04C $uint32 // ADC plus-side general calibration value register\n"
  "register ADC0_PGA   at 0x4003B050 $uint32 // ADC Programmable Gain Amplifier\n"
  "let ADC0_PGA_PGAEN  $uint32 = 0x00800000  // Enable\n"
  "let ADC0_PGA_PGALPB  $uint32 = 0x00100000  // Low-Power Mode Control, 0=low power, 1=normal\n"
  "//register ADC0_PGA_PGAG(n)   (((n) & 15) << 16) // Gain, 0=1X, 1=2X, 2=4X, 3=8X, 4=16X, 5=32X, 6=64X\n"
  "register ADC0_CLMD   at 0x4003B054 $uint32 // ADC minus-side general calibration value register\n"
  "register ADC0_CLMS   at 0x4003B058 $uint32 // ADC minus-side general calibration value register\n"
  "register ADC0_CLM4   at 0x4003B05C $uint32 // ADC minus-side general calibration value register\n"
  "register ADC0_CLM3   at 0x4003B060 $uint32 // ADC minus-side general calibration value register\n"
  "register ADC0_CLM2   at 0x4003B064 $uint32 // ADC minus-side general calibration value register\n"
  "register ADC0_CLM1   at 0x4003B068 $uint32 // ADC minus-side general calibration value register\n"
  "register ADC0_CLM0   at 0x4003B06C $uint32 // ADC minus-side general calibration value register\n"
  "\n"
  "register ADC1_SC1A   at 0x400BB000 $uint32 // ADC status and control registers 1\n"
  "register ADC1_SC1B   at 0x400BB004 $uint32 // ADC status and control registers 1\n"
  "register ADC1_CFG1   at 0x400BB008 $uint32 // ADC configuration register 1\n"
  "register ADC1_CFG2   at 0x400BB00C $uint32 // Configuration register 2\n"
  "register ADC1_RA     at 0x400BB010 $uint32 // ADC data result register\n"
  "register ADC1_RB     at 0x400BB014 $uint32 // ADC data result register\n"
  "register ADC1_CV1    at 0x400BB018 $uint32 // Compare value registers\n"
  "register ADC1_CV2    at 0x400BB01C $uint32 // Compare value registers\n"
  "register ADC1_SC2    at 0x400BB020 $uint32 // Status and control register 2\n"
  "register ADC1_SC3    at 0x400BB024 $uint32 // Status and control register 3\n"
  "register ADC1_OFS    at 0x400BB028 $uint32 // ADC offset correction register\n"
  "register ADC1_PG     at 0x400BB02C $uint32 // ADC plus-side gain register\n"
  "register ADC1_MG     at 0x400BB030 $uint32 // ADC minus-side gain register\n"
  "register ADC1_CLPD   at 0x400BB034 $uint32 // ADC plus-side general calibration value register\n"
  "register ADC1_CLPS   at 0x400BB038 $uint32 // ADC plus-side general calibration value register\n"
  "register ADC1_CLP4   at 0x400BB03C $uint32 // ADC plus-side general calibration value register\n"
  "register ADC1_CLP3   at 0x400BB040 $uint32 // ADC plus-side general calibration value register\n"
  "register ADC1_CLP2   at 0x400BB044 $uint32 // ADC plus-side general calibration value register\n"
  "register ADC1_CLP1   at 0x400BB048 $uint32 // ADC plus-side general calibration value register\n"
  "register ADC1_CLP0   at 0x400BB04C $uint32 // ADC plus-side general calibration value register\n"
  "register ADC1_PGA    at 0x400BB050 $uint32 // ADC Programmable Gain Amplifier\n"
  "register ADC1_CLMD   at 0x400BB054 $uint32 // ADC minus-side general calibration value register\n"
  "register ADC1_CLMS   at 0x400BB058 $uint32 // ADC minus-side general calibration value register\n"
  "register ADC1_CLM4   at 0x400BB05C $uint32 // ADC minus-side general calibration value register\n"
  "register ADC1_CLM3   at 0x400BB060 $uint32 // ADC minus-side general calibration value register\n"
  "register ADC1_CLM2   at 0x400BB064 $uint32 // ADC minus-side general calibration value register\n"
  "register ADC1_CLM1   at 0x400BB068 $uint32 // ADC minus-side general calibration value register\n"
  "register ADC1_CLM0   at 0x400BB06C $uint32 // ADC minus-side general calibration value register\n"
  "\n"
  "register DAC0_DAT0L at 0x400CC000 $uint8 // DAC Data Low Register \n"
  "register DAC0_DATH  at 0x400CC001 $uint8 // DAC Data High Register \n"
  "register DAC0_DAT1L at 0x400CC002 $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT2L at 0x400CC004 $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT3L at 0x400CC006 $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT4L at 0x400CC008 $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT5L at 0x400CC00A $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT6L at 0x400CC00C $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT7L at 0x400CC00E $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT8L at 0x400CC010 $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT9L at 0x400CC012 $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT10L at 0x400CC014 $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT11L at 0x400CC016 $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT12L at 0x400CC018 $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT13L at 0x400CC01A $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT14L at 0x400CC01C $uint8 // DAC Data Low Register \n"
  "register DAC0_DAT15L at 0x400CC01E $uint8 // DAC Data Low Register \n"
  "register DAC0_SR     at 0x400CC020 $uint8 // DAC Status Register \n"
  "register DAC0_C0     at 0x400CC021 $uint8 // DAC Control Register \n"
  "let DAC_C0_DACEN  $uint8 = 0x80    // DAC Enable\n"
  "let DAC_C0_DACRFS $uint8 = 0x40    // DAC Reference Select\n"
  "let DAC_C0_DACTRGSEL $uint8 = 0x20    // DAC Trigger Select\n"
  "let DAC_C0_DACSWTRG  $uint8 = 0x10    // DAC Software Trigger\n"
  "let DAC_C0_LPEN  $uint8 = 0x08    // DAC Low Power Control\n"
  "let DAC_C0_DACBWIEN  $uint8 = 0x04    // DAC Buffer Watermark Interrupt Enable\n"
  "let DAC_C0_DACBTIEN $uint8 = 0x02    // DAC Buffer Read Pointer Top Flag Interrupt Enable\n"
  "let DAC_C0_DACBBIEN $uint8 = 0x01    // DAC Buffer Read Pointer Bottom Flag Interrupt Enable\n"
  "\n"
  "register DAC0_C1  at 0x400CC022 $uint8 // DAC Control Register 1 \n"
  "let DAC_C1_DMAEN $uint8 = 0x80    // DMA Enable Select\n"
  "//register DAC_C1_DACBFWM(n)  (((n) & 3) << 3)  // DAC Buffer Watermark Select\n"
  "//register DAC_C1_DACBFMD(n)  (((n) & 3) << 0)  // DAC Buffer Work Mode Select\n"
  "let DAC_C1_DACBFEN $uint8 = 0x00    // DAC Buffer Enable\n"
  "//\n"
  "register DAC0_C2  at 0x400CC023 $uint8 // DAC Control Register 2 \n"
  "//register DAC_C2_DACBFRP(n)  (((n) & 15) << 4)  // DAC Buffer Read Pointer\n"
  "//register DAC_C2_DACBFUP(n)  (((n) & 15) << 0)  // DAC Buffer Upper Limit\n"
  "//\n"
  "//\n"
  "////register MCG_C2_RANGE0(n)  ($uint8_t)(((n) & 0x03) << 4) // Frequency Range Select, Selects the frequency range for the crystal oscillator\n"
  "////register MCG_C2_LOCRE0   ($uint8_t)0x80   // Loss of Clock Reset Enable, Determines whether an interrupt or a reset request is made following a lo"
  "ss of OSC0 \n"
  "//\n"
  "//// Chapter 32: Comparator (CMP)\n"
  "register CMP0_CR0   at 0x40073000 $uint8 // CMP Control Register 0\n"
  "register CMP0_CR1   at 0x40073001 $uint8 // CMP Control Register 1\n"
  "register CMP0_FPR   at 0x40073002 $uint8 // CMP Filter Period Register\n"
  "register CMP0_SCR   at 0x40073003 $uint8 // CMP Status and Control Register\n"
  "register CMP0_DACCR at 0x40073004 $uint8 // DAC Control Register\n"
  "register CMP0_MUXCR at 0x40073005 $uint8 // MUX Control Register\n"
  "register CMP1_CR0   at 0x40073008 $uint8 // CMP Control Register 0\n"
  "register CMP1_CR1   at 0x40073009 $uint8 // CMP Control Register 1\n"
  "register CMP1_FPR   at 0x4007300A $uint8 // CMP Filter Period Register\n"
  "register CMP1_SCR   at 0x4007300B $uint8 // CMP Status and Control Register\n"
  "register CMP1_DACCR at 0x4007300C $uint8 // DAC Control Register\n"
  "register CMP1_MUXCR at 0x4007300D $uint8 // MUX Control Register\n"
  "//\n"
  "//// Chapter 33: Voltage Reference (VREFV1)\n"
  "register VREF_TRM  at 0x40074000 $uint8 // VREF Trim Register\n"
  "register VREF_SC   at 0x40074001 $uint8 // VREF Status and Control Register\n"
  "\n"
  "// Chapter 34: Programmable Delay Block (PDB)\n"
  "//register PDB0_SC    0x40036000 // Status and Control Register\n"
  "//register PDB_SC_LDMOD(n)   (((n) & 3) << 18) // Load Mode Select\n"
  "//register PDB_SC_PDBEIE   0x00020000  // Sequence Error Interrupt Enable\n"
  "//register PDB_SC_SWTRIG   0x00010000  // Software Trigger\n"
  "//register PDB_SC_DMAEN   0x00008000  // DMA Enable\n"
  "//register PDB_SC_PRESCALER(n)  (((n) & 7) << 12) // Prescaler Divider Select\n"
  "//register PDB_SC_TRGSEL(n)  (((n) & 15) << 8) // Trigger Input Source Select\n"
  "//register PDB_SC_PDBEN   0x00000080  // PDB Enable\n"
  "//register PDB_SC_PDBIF   0x00000040  // PDB Interrupt Flag\n"
  "//register PDB_SC_PDBIE   0x00000020  // PDB Interrupt Enable.\n"
  "//register PDB_SC_MULT(n)   (((n) & 3) << 2) // Multiplication Factor\n"
  "//register PDB_SC_CONT   0x00000002  // Continuous Mode Enable\n"
  "//register PDB_SC_LDOK   0x00000001  // Load OK\n"
  "//register PDB0_MOD   0x40036004 // Modulus Register\n"
  "//register PDB0_CNT   0x40036008 // Counter Register\n"
  "//register PDB0_IDLY   0x4003600C // Interrupt Delay Register\n"
  "//register PDB0_CH0C1   0x40036010 // Channel n Control Register 1\n"
  "//register PDB0_CH0S   0x40036014 // Channel n Status Register\n"
  "//register PDB0_CH0DLY0   0x40036018 // Channel n Delay 0 Register\n"
  "//register PDB0_CH0DLY1   0x4003601C // Channel n Delay 1 Register\n"
  "//register PDB0_POEN   0x40036190 // Pulse-Out n Enable Register\n"
  "//register PDB0_PO0DLY   0x40036194 // Pulse-Out n Delay Register\n"
  "//register PDB0_PO1DLY   0x40036198 // Pulse-Out n Delay Register\n"
  "//\n"
  "//// Chapter 35: FlexTimer Module (FTM)\n"
  "//register FTM0_SC    0x40038000 // Status And Control\n"
  "//register FTM_SC_TOF   0x80    // Timer Overflow Flag\n"
  "//register FTM_SC_TOIE   0x40    // Timer Overflow Interrupt Enable\n"
  "//register FTM_SC_CPWMS   0x20    // Center-Aligned PWM Select\n"
  "//register FTM_SC_CLKS(n)   (((n) & 3) << 3)  // Clock Source Selection\n"
  "//register FTM_SC_PS(n)   (((n) & 7) << 0)  // Prescale Factor Selection\n"
  "//register FTM0_CNT   0x40038004 // Counter\n"
  "//register FTM0_MOD   0x40038008 // Modulo\n"
  "//register FTM0_C0SC   0x4003800C // Channel 0 Status And Control\n"
  "//register FTM0_C0V   0x40038010 // Channel 0 Value\n"
  "//register FTM0_C1SC   0x40038014 // Channel 1 Status And Control\n"
  "//register FTM0_C1V   0x40038018 // Channel 1 Value\n"
  "//register FTM0_C2SC   0x4003801C // Channel 2 Status And Control\n"
  "//register FTM0_C2V   0x40038020 // Channel 2 Value\n"
  "//register FTM0_C3SC   0x40038024 // Channel 3 Status And Control\n"
  "//register FTM0_C3V   0x40038028 // Channel 3 Value\n"
  "//register FTM0_C4SC   0x4003802C // Channel 4 Status And Control\n"
  "//register FTM0_C4V   0x40038030 // Channel 4 Value\n"
  "//register FTM0_C5SC   0x40038034 // Channel 5 Status And Control\n"
  "//register FTM0_C5V   0x40038038 // Channel 5 Value\n"
  "//register FTM0_C6SC   0x4003803C // Channel 6 Status And Control\n"
  "//register FTM0_C6V   0x40038040 // Channel 6 Value\n"
  "//register FTM0_C7SC   0x40038044 // Channel 7 Status And Control\n"
  "//register FTM0_C7V   0x40038048 // Channel 7 Value\n"
  "//register FTM0_CNTIN   0x4003804C // Counter Initial Value\n"
  "//register FTM0_STATUS   0x40038050 // Capture And Compare Status\n"
  "//register FTM0_MODE   0x40038054 // Features Mode Selection\n"
  "//register FTM_MODE_FAULTIE  0x80    // Fault Interrupt Enable\n"
  "//register FTM_MODE_FAULTM(n)  (((n) & 3) << 5)  // Fault Control Mode\n"
  "//register FTM_MODE_CAPTEST  0x10    // Capture Test Mode Enable\n"
  "//register FTM_MODE_PWMSYNC  0x08    // PWM Synchronization Mode\n"
  "//register FTM_MODE_WPDIS   0x04    // Write Protection Disable\n"
  "//register FTM_MODE_INIT   0x02    // Initialize The Channels Output\n"
  "//register FTM_MODE_FTMEN   0x01    // FTM Enable\n"
  "//register FTM0_SYNC   0x40038058 // Synchronization\n"
  "//register FTM_SYNC_SWSYNC   0x80    // \n"
  "//register FTM_SYNC_TRIG2   0x40    // \n"
  "//register FTM_SYNC_TRIG1   0x20    // \n"
  "//register FTM_SYNC_TRIG0   0x10    // \n"
  "//register FTM_SYNC_SYNCHOM  0x08    // \n"
  "//register FTM_SYNC_REINIT   0x04    // \n"
  "//register FTM_SYNC_CNTMAX   0x02    // \n"
  "//register FTM_SYNC_CNTMIN   0x01    // \n"
  "//register FTM0_OUTINIT   0x4003805C // Initial State For Channels Output\n"
  "//register FTM0_OUTMASK   0x40038060 // Output Mask\n"
  "//register FTM0_COMBINE   0x40038064 // Function For Linked Channels\n"
  "//register FTM0_DEADTIME   0x40038068 // Deadtime Insertion Control\n"
  "//register FTM0_EXTTRIG   0x4003806C // FTM External Trigger\n"
  "//register FTM0_POL   0x40038070 // Channels Polarity\n"
  "//register FTM0_FMS   0x40038074 // Fault Mode Status\n"
  "//register FTM0_FILTER   0x40038078 // Input Capture Filter Control\n"
  "//register FTM0_FLTCTRL   0x4003807C // Fault Control\n"
  "//register FTM0_QDCTRL   0x40038080 // Quadrature Decoder Control And Status\n"
  "//register FTM0_CONF   0x40038084 // Configuration\n"
  "//register FTM0_FLTPOL   0x40038088 // FTM Fault Input Polarity\n"
  "//register FTM0_SYNCONF   0x4003808C // Synchronization Configuration\n"
  "//register FTM0_INVCTRL   0x40038090 // FTM Inverting Control\n"
  "//register FTM0_SWOCTRL   0x40038094 // FTM Software Output Control\n"
  "//register FTM0_PWMLOAD   0x40038098 // FTM PWM Load\n"
  "//register FTM1_SC    0x40039000 // Status And Control\n"
  "//register FTM1_CNT   0x40039004 // Counter\n"
  "//register FTM1_MOD   0x40039008 // Modulo\n"
  "//register FTM1_C0SC   0x4003900C // Channel 0 Status And Control\n"
  "//register FTM1_C0V   0x40039010 // Channel 0 Value\n"
  "//register FTM1_C1SC   0x40039014 // Channel 1 Status And Control\n"
  "//register FTM1_C1V   0x40039018 // Channel 1 Value\n"
  "//register FTM1_CNTIN   0x4003904C // Counter Initial Value\n"
  "//register FTM1_STATUS   0x40039050 // Capture And Compare Status\n"
  "//register FTM1_MODE   0x40039054 // Features Mode Selection\n"
  "//register FTM1_SYNC   0x40039058 // Synchronization\n"
  "//register FTM1_OUTINIT   0x4003905C // Initial State For Channels Output\n"
  "//register FTM1_OUTMASK   0x40039060 // Output Mask\n"
  "//register FTM1_COMBINE   0x40039064 // Function For Linked Channels\n"
  "//register FTM1_DEADTIME   0x40039068 // Deadtime Insertion Control\n"
  "//register FTM1_EXTTRIG   0x4003906C // FTM External Trigger\n"
  "//register FTM1_POL   0x40039070 // Channels Polarity\n"
  "//register FTM1_FMS   0x40039074 // Fault Mode Status\n"
  "//register FTM1_FILTER   0x40039078 // Input Capture Filter Control\n"
  "//register FTM1_FLTCTRL   0x4003907C // Fault Control\n"
  "//register FTM1_QDCTRL   0x40039080 // Quadrature Decoder Control And Status\n"
  "//register FTM1_CONF   0x40039084 // Configuration\n"
  "//register FTM1_FLTPOL   0x40039088 // FTM Fault Input Polarity\n"
  "//register FTM1_SYNCONF   0x4003908C // Synchronization Configuration\n"
  "//register FTM1_INVCTRL   0x40039090 // FTM Inverting Control\n"
  "//register FTM1_SWOCTRL   0x40039094 // FTM Software Output Control\n"
  "//register FTM1_PWMLOAD   0x40039098 // FTM PWM Load\n"
  "//register FTM2_SC    0x400B8000 // Status And Control\n"
  "//register FTM2_CNT   0x400B8004 // Counter\n"
  "//register FTM2_MOD   0x400B8008 // Modulo\n"
  "//register FTM2_C0SC   0x400B800C // Channel 0 Status And Control\n"
  "//register FTM2_C0V   0x400B8010 // Channel 0 Value\n"
  "//register FTM2_C1SC   0x400B8014 // Channel 1 Status And Control\n"
  "//register FTM2_C1V   0x400B8018 // Channel 1 Value\n"
  "//register FTM2_CNTIN   0x400B804C // Counter Initial Value\n"
  "//register FTM2_STATUS   0x400B8050 // Capture And Compare Status\n"
  "//register FTM2_MODE   0x400B8054 // Features Mode Selection\n"
  "//register FTM2_SYNC   0x400B8058 // Synchronization\n"
  "//register FTM2_OUTINIT   0x400B805C // Initial State For Channels Output\n"
  "//register FTM2_OUTMASK   0x400B8060 // Output Mask\n"
  "//register FTM2_COMBINE   0x400B8064 // Function For Linked Channels\n"
  "//register FTM2_DEADTIME   0x400B8068 // Deadtime Insertion Control\n"
  "//register FTM2_EXTTRIG   0x400B806C // FTM External Trigger\n"
  "//register FTM2_POL   0x400B8070 // Channels Polarity\n"
  "//register FTM2_FMS   0x400B8074 // Fault Mode Status\n"
  "//register FTM2_FILTER   0x400B8078 // Input Capture Filter Control\n"
  "//register FTM2_FLTCTRL   0x400B807C // Fault Control\n"
  "//register FTM2_QDCTRL   0x400B8080 // Quadrature Decoder Control And Status\n"
  "//register FTM2_CONF   0x400B8084 // Configuration\n"
  "//register FTM2_FLTPOL   0x400B8088 // FTM Fault Input Polarity\n"
  "//register FTM2_SYNCONF   0x400B808C // Synchronization Configuration\n"
  "//register FTM2_INVCTRL   0x400B8090 // FTM Inverting Control\n"
  "//register FTM2_SWOCTRL   0x400B8094 // FTM Software Output Control\n"
  "//register FTM2_PWMLOAD   0x400B8098 // FTM PWM Load\n"
  "//\n"
  "//// Chapter 36: Periodic Interrupt Timer (PIT)\n"
  "//register PIT_MCR    0x40037000 // PIT Module Control Register\n"
  "//register PIT_LDVAL0   0x40037100 // Timer Load Value Register\n"
  "//register PIT_CVAL0   0x40037104 // Current Timer Value Register\n"
  "//register PIT_TCTRL0   0x40037108 // Timer Control Register\n"
  "//register PIT_TFLG0   0x4003710C // Timer Flag Register\n"
  "//register PIT_LDVAL1   0x40037110 // Timer Load Value Register\n"
  "//register PIT_CVAL1   0x40037114 // Current Timer Value Register\n"
  "//register PIT_TCTRL1   0x40037118 // Timer Control Register\n"
  "//register PIT_TFLG1   0x4003711C // Timer Flag Register\n"
  "//register PIT_LDVAL2   0x40037120 // Timer Load Value Register\n"
  "//register PIT_CVAL2   0x40037124 // Current Timer Value Register\n"
  "//register PIT_TCTRL2   0x40037128 // Timer Control Register\n"
  "//register PIT_TFLG2   0x4003712C // Timer Flag Register\n"
  "//register PIT_LDVAL3   0x40037130 // Timer Load Value Register\n"
  "//register PIT_CVAL3   0x40037134 // Current Timer Value Register\n"
  "//register PIT_TCTRL3   0x40037138 // Timer Control Register\n"
  "//register PIT_TFLG3   0x4003713C // Timer Flag Register\n"
  "//\n"
  "//// Chapter 37: Low-Power Timer (LPTMR)\n"
  "//register LPTMR0_CSR   0x40040000 // Low Power Timer Control Status Register\n"
  "//register LPTMR0_PSR   0x40040004 // Low Power Timer Prescale Register\n"
  "//register LPTMR0_CMR   0x40040008 // Low Power Timer Compare Register\n"
  "//register LPTMR0_CNR   0x4004000C // Low Power Timer Counter Register\n"
  "//\n"
  "//// Chapter 38: Carrier Modulator Transmitter (CMT)\n"
  "//register CMT_CGH1  *(volatile $uint8_t  *)0x40062000 // CMT Carrier Generator High Data Register 1\n"
  "//register CMT_CGL1  *(volatile $uint8_t  *)0x40062001 // CMT Carrier Generator Low Data Register 1\n"
  "//register CMT_CGH2  *(volatile $uint8_t  *)0x40062002 // CMT Carrier Generator High Data Register 2\n"
  "//register CMT_CGL2  *(volatile $uint8_t  *)0x40062003 // CMT Carrier Generator Low Data Register 2\n"
  "//register CMT_OC   *(volatile $uint8_t  *)0x40062004 // CMT Output Control Register\n"
  "//register CMT_MSC   *(volatile $uint8_t  *)0x40062005 // CMT Modulator Status and Control Register\n"
  "//register CMT_CMD1  *(volatile $uint8_t  *)0x40062006 // CMT Modulator Data Register Mark High\n"
  "//register CMT_CMD2  *(volatile $uint8_t  *)0x40062007 // CMT Modulator Data Register Mark Low\n"
  "//register CMT_CMD3  *(volatile $uint8_t  *)0x40062008 // CMT Modulator Data Register Space High\n"
  "//register CMT_CMD4  *(volatile $uint8_t  *)0x40062009 // CMT Modulator Data Register Space Low\n"
  "//register CMT_PPS   *(volatile $uint8_t  *)0x4006200A // CMT Primary Prescaler Register\n"
  "//register CMT_DMA   *(volatile $uint8_t  *)0x4006200B // CMT Direct Memory Access Register\n"
  "//\n"
  "//// Chapter 39: Real Time Clock (RTC)\n"
  "register RTC_TSR at  0x4003D000 $uint32 // RTC Time Seconds Register\n"
  "register RTC_TPR at  0x4003D004 $uint32 // RTC Time Prescaler Register\n"
  "register RTC_TAR at  0x4003D008 $uint32 // RTC Time Alarm Register\n"
  "register RTC_TCR at  0x4003D00C $uint32 // RTC Time Compensation Register\n"
  "//register RTC_TCR_CIC(n)   (((n) & 255) << 24)  // Compensation Interval Counter\n"
  "//register RTC_TCR_TCV(n)   (((n) & 255) << 16)  // Time Compensation Value\n"
  "//register RTC_TCR_CIR(n)   (((n) & 255) << 8)  // Compensation Interval Register\n"
  "//register RTC_TCR_TCR(n)   (((n) & 255) << 0)  // Time Compensation Register\n"
  "register RTC_CR at  0x4003D010 $uint32 {// RTC Control Register\n"
  "  18, SC2P, SC4P, SC8P, SC16P,CKLO, OSCE, 4, UM, SUP, WPE, SWR\n"
  "}\n"
  " \n"
  "register RTC_SR at  0x4003D014 $uint32 // RTC Status Register\n"
  "let RTC_SR_TCE $uint32 = 0x00000010  \n"
  "let RTC_SR_TAF $uint32 = 0x00000004  // \n"
  "let RTC_SR_TOF $uint32 = 0x00000002  // \n"
  "let RTC_SR_TIF $uint32 = 0x00000001  // \n"
  "\n"
  "register RTC_LR  at 0x4003D018 $uint32 // RTC Lock Register\n"
  "register RTC_IER at 0x4003D01C $uint32 // RTC Interrupt Enable Register\n"
  "register RTC_WAR at 0x4003D800 $uint32 // RTC Write Access Register\n"
  "register RTC_RAR at 0x4003D804 $uint32 // RTC Read Access Register\n"
  "\n"
  "//// Chapter 40: Universal Serial Bus OTG Controller (USBOTG)\n"
  "//register USB0_PERID  *(const    $uint8_t  *)0x40072000 // Peripheral ID register\n"
  "//register USB0_IDCOMP  *(const    $uint8_t  *)0x40072004 // Peripheral ID Complement register\n"
  "//register USB0_REV  *(const    $uint8_t  *)0x40072008 // Peripheral Revision register\n"
  "//register USB0_ADDINFO  *(volatile $uint8_t  *)0x4007200C // Peripheral Additional Info register\n"
  "//register USB0_OTGIST *(volatile $uint8_t  *)0x40072010 // OTG Interrupt Status register\n"
  "//register USB_OTGISTAT_IDCHG  ($uint8_t)0x80   //\n"
  "//register USB_OTGISTAT_ONEMSEC  ($uint8_t)0x40   //\n"
  "//register USB_OTGISTAT_LINE_STATE_CHG ($uint8_t)0x20   //\n"
  "//register USB_OTGISTAT_SESSVLDCHG  ($uint8_t)0x08   //\n"
  "//register USB_OTGISTAT_B_SESS_CHG  ($uint8_t)0x04   //\n"
  "//register USB_OTGISTAT_AVBUSCHG  ($uint8_t)0x01   //\n"
  "//register USB0_OTGICR  *(volatile $uint8_t  *)0x40072014 // OTG Interrupt Control Register\n"
  "//register USB_OTGICR_IDEN   ($uint8_t)0x80   // \n"
  "//register USB_OTGICR_ONEMSECEN  ($uint8_t)0x40   // \n"
  "//register USB_OTGICR_LINESTATEEN  ($uint8_t)0x20   // \n"
  "//register USB_OTGICR_SESSVLDEN  ($uint8_t)0x08   // \n"
  "//register USB_OTGICR_BSESSEN  ($uint8_t)0x04   // \n"
  "//register USB_OTGICR_AVBUSEN  ($uint8_t)0x01   // \n"
  "//register USB0_OTGST *(volatile $uint8_t  *)0x40072018 // OTG Status register\n"
  "//register USB_OTGSTAT_ID   ($uint8_t)0x80   // \n"
  "//register USB_OTGSTAT_ONEMSECEN  ($uint8_t)0x40   // \n"
  "//register USB_OTGSTAT_LINESTATESTABLE ($uint8_t)0x20   // \n"
  "//register USB_OTGSTAT_SESS_VLD  ($uint8_t)0x08   // \n"
  "//register USB_OTGSTAT_BSESSEND  ($uint8_t)0x04   // \n"
  "//register USB_OTGSTAT_AVBUSVLD  ($uint8_t)0x01   // \n"
  "//register USB0_OTGCTL  *(volatile $uint8_t  *)0x4007201C // OTG Control Register\n"
  "//register USB_OTGCTL_DPHIGH  ($uint8_t)0x80   // \n"
  "//register USB_OTGCTL_DPLOW  ($uint8_t)0x20   // \n"
  "//register USB_OTGCTL_DMLOW  ($uint8_t)0x10   // \n"
  "//register USB_OTGCTL_OTGEN  ($uint8_t)0x04   // \n"
  "//register USB0_IST *(volatile $uint8_t  *)0x40072080 // Interrupt Status Register\n"
  "//register USB_ISTAT_STALL   ($uint8_t)0x80   // \n"
  "//register USB_ISTAT_ATTACH  ($uint8_t)0x40   // \n"
  "//register USB_ISTAT_RESUME  ($uint8_t)0x20   // \n"
  "//register USB_ISTAT_SLEEP   ($uint8_t)0x10   // \n"
  "//register USB_ISTAT_TOKDNE  ($uint8_t)0x08   // \n"
  "//register USB_ISTAT_SOFTOK  ($uint8_t)0x04   // \n"
  "//register USB_ISTAT_ERROR   ($uint8_t)0x02   // \n"
  "//register USB_ISTAT_USBRST  ($uint8_t)0x01   // \n"
  "//register USB0_INTEN  *(volatile $uint8_t  *)0x40072084 // Interrupt Enable Register\n"
  "//register USB_INTEN_STALLEN  ($uint8_t)0x80   // \n"
  "//register USB_INTEN_ATTACHEN  ($uint8_t)0x40   // \n"
  "//register USB_INTEN_RESUMEEN  ($uint8_t)0x20   // \n"
  "//register USB_INTEN_SLEEPEN  ($uint8_t)0x10   // \n"
  "//register USB_INTEN_TOKDNEEN  ($uint8_t)0x08   // \n"
  "//register USB_INTEN_SOFTOKEN  ($uint8_t)0x04   // \n"
  "//register USB_INTEN_ERROREN  ($uint8_t)0x02   // \n"
  "//register USB_INTEN_USBRSTEN  ($uint8_t)0x01   // \n"
  "//register USB0_ERRST *(volatile $uint8_t  *)0x40072088 // Error Interrupt Status Register\n"
  "//register USB_ERRSTAT_BTSERR  ($uint8_t)0x80   // \n"
  "//register USB_ERRSTAT_DMAERR  ($uint8_t)0x20   // \n"
  "//register USB_ERRSTAT_BTOERR  ($uint8_t)0x10   // \n"
  "//register USB_ERRSTAT_DFN8  ($uint8_t)0x08   // \n"
  "//register USB_ERRSTAT_CRC16  ($uint8_t)0x04   // \n"
  "//register USB_ERRSTAT_CRC5EOF  ($uint8_t)0x02   // \n"
  "//register USB_ERRSTAT_PIDERR  ($uint8_t)0x01   // \n"
  "//register USB0_ERREN  *(volatile $uint8_t  *)0x4007208C // Error Interrupt Enable Register\n"
  "//register USB_ERREN_BTSERREN  ($uint8_t)0x80   // \n"
  "//register USB_ERREN_DMAERREN  ($uint8_t)0x20   // \n"
  "//register USB_ERREN_BTOERREN  ($uint8_t)0x10   // \n"
  "//register USB_ERREN_DFN8EN  ($uint8_t)0x08   // \n"
  "//register USB_ERREN_CRC16EN  ($uint8_t)0x04   // \n"
  "//register USB_ERREN_CRC5EOFEN  ($uint8_t)0x02   // \n"
  "//register USB_ERREN_PIDERREN  ($uint8_t)0x01   // \n"
  "//register USB0_ST *(volatile $uint8_t  *)0x40072090 // Status Register\n"
  "//register USB_STAT_TX   ($uint8_t)0x08   // \n"
  "//register USB_STAT_ODD   ($uint8_t)0x04   // \n"
  "//register USB_STAT_ENDP(n)  ($uint8_t)((n) >> 4)  // \n"
  "//register USB0_CTL  *(volatile $uint8_t  *)0x40072094 // Control Register\n"
  "//register USB_CTL_JSTATE   ($uint8_t)0x80   // \n"
  "//register USB_CTL_SE0   ($uint8_t)0x40   // \n"
  "//register USB_CTL_TXSUSPENDTOKENBUSY ($uint8_t)0x20   // \n"
  "//register USB_CTL_RESET   ($uint8_t)0x10   // \n"
  "//register USB_CTL_HOSTMODEEN  ($uint8_t)0x08   // \n"
  "//register USB_CTL_RESUME   ($uint8_t)0x04   // \n"
  "//register USB_CTL_ODDRST   ($uint8_t)0x02   // \n"
  "//register USB_CTL_USBENSOFEN  ($uint8_t)0x01   // \n"
  "//register USB0_ADDR  *(volatile $uint8_t  *)0x40072098 // Address Register\n"
  "//register USB0_BDTPAGE1  *(volatile $uint8_t  *)0x4007209C // BDT Page Register 1\n"
  "//register USB0_FRMNUML  *(volatile $uint8_t  *)0x400720A0 // Frame Number Register Low\n"
  "//register USB0_FRMNUMH  *(volatile $uint8_t  *)0x400720A4 // Frame Number Register High\n"
  "//register USB0_TOKEN  *(volatile $uint8_t  *)0x400720A8 // Token Register\n"
  "//register USB0_SOFTHLD  *(volatile $uint8_t  *)0x400720AC // SOF Threshold Register\n"
  "//register USB0_BDTPAGE2  *(volatile $uint8_t  *)0x400720B0 // BDT Page Register 2\n"
  "//register USB0_BDTPAGE3  *(volatile $uint8_t  *)0x400720B4 // BDT Page Register 3\n"
  "//register USB0_ENDPT0  *(volatile $uint8_t  *)0x400720C0 // Endpoint Control Register\n"
  "//register USB_ENDPT_HOSTWOHUB  ($uint8_t)0x80   // host only, enable low speed\n"
  "//register USB_ENDPT_RETRYDIS  ($uint8_t)0x40   // host only, set to disable NAK retry\n"
  "//register USB_ENDPT_EPCTLDIS  ($uint8_t)0x10   // 0=control, 1=bulk, interrupt, isync\n"
  "//register USB_ENDPT_EPRXEN  ($uint8_t)0x08   // enables the endpoint for RX transfers.\n"
  "//register USB_ENDPT_EPTXEN  ($uint8_t)0x04   // enables the endpoint for TX transfers.\n"
  "//register USB_ENDPT_EPSTALL  ($uint8_t)0x02   // set to stall endpoint\n"
  "//register USB_ENDPT_EPHSHK  ($uint8_t)0x01   // enable handshaking during a transaction, generally set unless Isochronous\n"
  "//register USB0_ENDPT1  *(volatile $uint8_t  *)0x400720C4 // Endpoint Control Register\n"
  "//register USB0_ENDPT2  *(volatile $uint8_t  *)0x400720C8 // Endpoint Control Register\n"
  "//register USB0_ENDPT3  *(volatile $uint8_t  *)0x400720CC // Endpoint Control Register\n"
  "//register USB0_ENDPT4  *(volatile $uint8_t  *)0x400720D0 // Endpoint Control Register\n"
  "//register USB0_ENDPT5  *(volatile $uint8_t  *)0x400720D4 // Endpoint Control Register\n"
  "//register USB0_ENDPT6  *(volatile $uint8_t  *)0x400720D8 // Endpoint Control Register\n"
  "//register USB0_ENDPT7  *(volatile $uint8_t  *)0x400720DC // Endpoint Control Register\n"
  "//register USB0_ENDPT8  *(volatile $uint8_t  *)0x400720E0 // Endpoint Control Register\n"
  "//register USB0_ENDPT9  *(volatile $uint8_t  *)0x400720E4 // Endpoint Control Register\n"
  "//register USB0_ENDPT10  *(volatile $uint8_t  *)0x400720E8 // Endpoint Control Register\n"
  "//register USB0_ENDPT11  *(volatile $uint8_t  *)0x400720EC // Endpoint Control Register\n"
  "//register USB0_ENDPT12  *(volatile $uint8_t  *)0x400720F0 // Endpoint Control Register\n"
  "//register USB0_ENDPT13  *(volatile $uint8_t  *)0x400720F4 // Endpoint Control Register\n"
  "//register USB0_ENDPT14  *(volatile $uint8_t  *)0x400720F8 // Endpoint Control Register\n"
  "//register USB0_ENDPT15  *(volatile $uint8_t  *)0x400720FC // Endpoint Control Register\n"
  "//register USB0_USBCTRL  *(volatile $uint8_t  *)0x40072100 // USB Control Register\n"
  "//register USB_USBCTRL_SUSP  ($uint8_t)0x80   // Places the USB transceiver into the suspend state.\n"
  "//register USB_USBCTRL_PDE   ($uint8_t)0x40   // Enables the weak pulldowns on the USB transceiver.\n"
  "//register USB0_OBSERVE  *(volatile $uint8_t  *)0x40072104 // USB OTG Observe Register\n"
  "//register USB_OBSERVE_DPPU  ($uint8_t)0x80   // \n"
  "//register USB_OBSERVE_DPPD  ($uint8_t)0x40   // \n"
  "//register USB_OBSERVE_DMPD  ($uint8_t)0x10   // \n"
  "//register USB0_CONTROL  *(volatile $uint8_t  *)0x40072108 // USB OTG Control Register\n"
  "//register USB_CONTROL_DPPULLUPNONOTG ($uint8_t)0x10   //  Provides control of the DP PULLUP in the USB OTG module, if USB is configured in non-OTG de"
  "vice mode.\n"
  "//register USB0_USBTRC0  *(volatile $uint8_t  *)0x4007210C // USB Transceiver Control Register 0\n"
  "//register USB_USBTRC_USBRESET  ($uint8_t)0x80   //\n"
  "//register USB_USBTRC_USBRESMEN  ($uint8_t)0x20   //\n"
  "//register USB_USBTRC_SYNC_DET  ($uint8_t)0x02   //\n"
  "//register USB_USBTRC_USB_RESUME_INT ($uint8_t)0x01   //\n"
  "//register USB0_USBFRMADJUST *(volatile $uint8_t  *)0x40072114 // Frame Adjust Register\n"
  "//\n"
  "//// Chapter 41: USB Device Charger Detection Module (USBDCD)\n"
  "//register USBDCD_CONTROL   0x40035000 // Control register\n"
  "//register USBDCD_CLOCK   0x40035004 // Clock register\n"
  "//register USBDCD_STATUS   0x40035008 // Status register\n"
  "//register USBDCD_TIMER0   0x40035010 // TIMER0 register\n"
  "//register USBDCD_TIMER1   0x40035014 // TIMER1 register\n"
  "//register USBDCD_TIMER2   0x40035018 // TIMER2 register\n"
  "//\n"
  "//// Chapter 43: SPI (DSPI)\n"
  "//register SPI0_MCR   0x4002C000 // DSPI Module Configuration Register\n"
  "//register SPI_MCR_MSTR    0x80000000  // Master/Slave Mode Select\n"
  "//register SPI_MCR_CONT_SCKE   0x40000000  // \n"
  "//register SPI_MCR_DCONF(n)  (((n) & 3) << 28)  // \n"
  "//register SPI_MCR_FRZ    0x08000000  // \n"
  "//register SPI_MCR_MTFE    0x04000000  // \n"
  "//register SPI_MCR_ROOE    0x01000000  // \n"
  "//register SPI_MCR_PCSIS(n)  (((n) & 0x1F) << 16)  //\n"
  "//register SPI_MCR_DOZE    0x00008000  // \n"
  "//register SPI_MCR_MDIS    0x00004000  // \n"
  "//register SPI_MCR_DIS_TXF    0x00002000  // \n"
  "//register SPI_MCR_DIS_RXF    0x00001000  // \n"
  "//register SPI_MCR_CLR_TXF    0x00000800  // \n"
  "//register SPI_MCR_CLR_RXF    0x00000400  // \n"
  "//register SPI_MCR_SMPL_PT(n)  (((n) & 3) << 8)  //\n"
  "//register SPI_MCR_HALT    0x00000001  // \n"
  "//register SPI0_TCR   0x4002C008 // DSPI Transfer Count Register\n"
  "//register SPI0_CTAR0   0x4002C00C // DSPI Clock and Transfer Attributes Register, In Master Mode\n"
  "//register SPI_CTAR_DBR    0x80000000  // Double Baud Rate\n"
  "//register SPI_CTAR_FMSZ(n)  (((n) & 15) << 27)  // Frame Size (+1)\n"
  "//register SPI_CTAR_CPOL    0x04000000  // Clock Polarity\n"
  "//register SPI_CTAR_CPHA    0x02000000  // Clock Phase\n"
  "//register SPI_CTAR_LSBFE    0x01000000  // LSB First\n"
  "//register SPI_CTAR_PCSSCK(n)  (((n) & 3) << 22)  // PCS to SCK Delay Prescaler\n"
  "//register SPI_CTAR_PASC(n)  (((n) & 3) << 20)  // After SCK Delay Prescaler\n"
  "//register SPI_CTAR_PDT(n)   (((n) & 3) << 18)  // Delay after Transfer Prescaler\n"
  "//register SPI_CTAR_PBR(n)   (((n) & 3) << 16)  // Baud Rate Prescaler\n"
  "//register SPI_CTAR_CSSCK(n)  (((n) & 15) << 12)  // PCS to SCK Delay Scaler\n"
  "//register SPI_CTAR_ASC(n)   (((n) & 15) << 8)  // After SCK Delay Scaler\n"
  "//register SPI_CTAR_DT(n)   (((n) & 15) << 4)  // Delay After Transfer Scaler\n"
  "//register SPI_CTAR_BR(n)   (((n) & 15) << 0)  // Baud Rate Scaler\n"
  "//register SPI0_CTAR0_SLAVE  0x4002C00C // DSPI Clock and Transfer Attributes Register, In Slave Mode\n"
  "//register SPI0_CTAR1   0x4002C010 // DSPI Clock and Transfer Attributes Register, In Master Mode\n"
  "//register SPI0_SR    0x4002C02C // DSPI Status Register\n"
  "//register SPI_SR_TCF    0x80000000  // Transfer Complete Flag\n"
  "//register SPI_SR_TXRXS    0x40000000  // TX and RX Status\n"
  "//register SPI_SR_EOQF    0x10000000  // End of Queue Flag\n"
  "//register SPI_SR_TFUF    0x08000000  // Transmit FIFO Underflow Flag\n"
  "//register SPI_SR_TFFF    0x02000000  // Transmit FIFO Fill Flag\n"
  "//register SPI_SR_RFOF    0x00080000  // Receive FIFO Overflow Flag\n"
  "//register SPI_SR_RFDF    0x00020000  // Receive FIFO Drain Flag\n"
  "//register SPI0_RSER   0x4002C030 // DSPI DMA/Interrupt Request Select and Enable Register\n"
  "//register SPI_RSER_TCF_RE    0x80000000  // Transmission Complete Request Enable\n"
  "//register SPI_RSER_EOQF_RE   0x10000000  // DSPI Finished Request Request Enable\n"
  "//register SPI_RSER_TFUF_RE   0x08000000  // Transmit FIFO Underflow Request Enable\n"
  "//register SPI_RSER_TFFF_RE   0x02000000  // Transmit FIFO Fill Request Enable\n"
  "//register SPI_RSER_TFFF_DIRS   0x01000000  // Transmit FIFO FIll Dma or Interrupt Request Select\n"
  "//register SPI_RSER_RFOF_RE   0x00080000  // Receive FIFO Overflow Request Enable\n"
  "//register SPI_RSER_RFDF_RE   0x00020000  // Receive FIFO Drain Request Enable\n"
  "//register SPI_RSER_RFDF_DIRS   0x00010000  // Receive FIFO Drain DMA or Interrupt Request Select\n"
  "//register SPI0_PUSHR   0x4002C034 // DSPI PUSH TX FIFO Register In Master Mode\n"
  "//register SPI_PUSHR_CONT    0x80000000  // \n"
  "//register SPI_PUSHR_CTAS(n)  (((n) & 7) << 28)  // \n"
  "//register SPI_PUSHR_EOQ    0x08000000  // \n"
  "//register SPI_PUSHR_CTCNT    0x04000000  // \n"
  "//register SPI_PUSHR_PCS(n)  (((n) & 31) << 16)  //\n"
  "//register SPI0_PUSHR_SLAVE  0x4002C034 // DSPI PUSH TX FIFO Register In Slave Mode\n"
  "//register SPI0_POPR   0x4002C038 // DSPI POP RX FIFO Register\n"
  "//register SPI0_TXFR0   0x4002C03C // DSPI Transmit FIFO Registers\n"
  "//register SPI0_TXFR1   0x4002C040 // DSPI Transmit FIFO Registers\n"
  "//register SPI0_TXFR2   0x4002C044 // DSPI Transmit FIFO Registers\n"
  "//register SPI0_TXFR3   0x4002C048 // DSPI Transmit FIFO Registers\n"
  "//register SPI0_RXFR0   0x4002C07C // DSPI Receive FIFO Registers\n"
  "//register SPI0_RXFR1   0x4002C080 // DSPI Receive FIFO Registers\n"
  "//register SPI0_RXFR2   0x4002C084 // DSPI Receive FIFO Registers\n"
  "//register SPI0_RXFR3   0x4002C088 // DSPI Receive FIFO Registers\n"
  "//typedef struct {\n"
  "// volatile $uint32_t MCR; // 0\n"
  "// volatile $uint32_t unused1;// 4\n"
  "// volatile $uint32_t TCR; // 8\n"
  "// volatile $uint32_t CTAR0; // c\n"
  "// volatile $uint32_t CTAR1; // 10\n"
  "// volatile $uint32_t CTAR2; // 14\n"
  "// volatile $uint32_t CTAR3; // 18\n"
  "// volatile $uint32_t CTAR4; // 1c\n"
  "// volatile $uint32_t CTAR5; // 20\n"
  "// volatile $uint32_t CTAR6; // 24\n"
  "// volatile $uint32_t CTAR7; // 28\n"
  "// volatile $uint32_t SR; // 2c\n"
  "// volatile $uint32_t RSER; // 30\n"
  "// volatile $uint32_t PUSHR; // 34\n"
  "// volatile $uint32_t POPR; // 38\n"
  "// volatile $uint32_t TXFR[16]; // 3c\n"
  "// volatile $uint32_t RXFR[16]; // 7c\n"
  "//} SPI_t;\n"
  "//register SPI0  (*(SPI_t *)0x4002C000)\n"
  "//\n"
  "//// Chapter 44: Inter-Integrated Circuit (I2C)\n"
  "//register I2C0_A1   *(volatile $uint8_t  *)0x40066000 // I2C Address Register 1\n"
  "//register I2C0_F   *(volatile $uint8_t  *)0x40066001 // I2C Frequency Divider register\n"
  "//register I2C0_C1   *(volatile $uint8_t  *)0x40066002 // I2C Control Register 1\n"
  "//register I2C_C1_IICEN   ($uint8_t)0x80   // I2C Enable\n"
  "//register I2C_C1_IICIE   ($uint8_t)0x40   // I2C Interrupt Enable\n"
  "//register I2C_C1_MST   ($uint8_t)0x20   // Master Mode Select\n"
  "//register I2C_C1_TX   ($uint8_t)0x10   // Transmit Mode Select\n"
  "//register I2C_C1_TXAK   ($uint8_t)0x08   // Transmit Acknowledge Enable\n"
  "//register I2C_C1_RSTA   ($uint8_t)0x04   // RepeSTART\n"
  "//register I2C_C1_WUEN   ($uint8_t)0x02   // Wakeup Enable\n"
  "//register I2C_C1_DMAEN   ($uint8_t)0x01   // DMA Enable\n"
  "//register I2C0_S   *(volatile $uint8_t  *)0x40066003 // I2C Status register\n"
  "//register I2C_S_TCF   ($uint8_t)0x80   // Transfer Complete Flag\n"
  "//register I2C_S_IAAS   ($uint8_t)0x40   // Addressed As A Slave\n"
  "//register I2C_S_BUSY   ($uint8_t)0x20   // Bus Busy\n"
  "//register I2C_S_ARBL   ($uint8_t)0x10   // Arbitration Lost\n"
  "//register I2C_S_RAM   ($uint8_t)0x08   // Range Address Match\n"
  "//register I2C_S_SRW   ($uint8_t)0x04   // Slave Read/Write\n"
  "//register I2C_S_IICIF   ($uint8_t)0x02   // Interrupt Flag\n"
  "//register I2C_S_RXAK   ($uint8_t)0x01   // Receive Acknowledge\n"
  "//register I2C0_D   *(volatile $uint8_t  *)0x40066004 // I2C Data I/O register\n"
  "//register I2C0_C2   *(volatile $uint8_t  *)0x40066005 // I2C Control Register 2\n"
  "//register I2C_C2_GCAEN   ($uint8_t)0x80   // General Call Address Enable\n"
  "//register I2C_C2_ADEXT   ($uint8_t)0x40   // Address Extension\n"
  "//register I2C_C2_HDRS   ($uint8_t)0x20   // High Drive Select\n"
  "//register I2C_C2_SBRC   ($uint8_t)0x10   // Slave Baud Rate Control\n"
  "//register I2C_C2_RMEN   ($uint8_t)0x08   // Range Address Matching Enable\n"
  "//register I2C_C2_AD(n)   ((n) & 7)   // Slave Address, upper 3 bits\n"
  "//register I2C0_FLT  *(volatile $uint8_t  *)0x40066006 // I2C Programmable Input Glitch Filter register\n"
  "//register I2C0_RA   *(volatile $uint8_t  *)0x40066007 // I2C Range Address register\n"
  "//register I2C0_SMB  *(volatile $uint8_t  *)0x40066008 // I2C SMBus Control and Status register\n"
  "//register I2C0_A2   *(volatile $uint8_t  *)0x40066009 // I2C Address Register 2\n"
  "//register I2C0_SLTH  *(volatile $uint8_t  *)0x4006600A // I2C SCL Low Timeout Register High\n"
  "//register I2C0_SLTL  *(volatile $uint8_t  *)0x4006600B // I2C SCL Low Timeout Register Low\n"
  "//\n"
  "//register I2C1_A1   *(volatile $uint8_t  *)0x40067000 // I2C Address Register 1\n"
  "//register I2C1_F   *(volatile $uint8_t  *)0x40067001 // I2C Frequency Divider register\n"
  "//register I2C1_C1   *(volatile $uint8_t  *)0x40067002 // I2C Control Register 1\n"
  "//register I2C1_S   *(volatile $uint8_t  *)0x40067003 // I2C Status register\n"
  "//register I2C1_D   *(volatile $uint8_t  *)0x40067004 // I2C Data I/O register\n"
  "//register I2C1_C2   *(volatile $uint8_t  *)0x40067005 // I2C Control Register 2\n"
  "//register I2C1_FLT  *(volatile $uint8_t  *)0x40067006 // I2C Programmable Input Glitch Filter register\n"
  "//register I2C1_RA   *(volatile $uint8_t  *)0x40067007 // I2C Range Address register\n"
  "//register I2C1_SMB  *(volatile $uint8_t  *)0x40067008 // I2C SMBus Control and Status register\n"
  "//register I2C1_A2   *(volatile $uint8_t  *)0x40067009 // I2C Address Register 2\n"
  "//register I2C1_SLTH  *(volatile $uint8_t  *)0x4006700A // I2C SCL Low Timeout Register High\n"
  "//register I2C1_SLTL  *(volatile $uint8_t  *)0x4006700B // I2C SCL Low Timeout Register Low\n"
  "//\n"
  "//// Chapter 45: Universal Asynchronous Receiver/Transmitter (UART)\n"
  "//register UART0_BDH  *(volatile $uint8_t  *)0x4006A000 // UART Baud Rate Registers: High\n"
  "//register UART0_BDL  *(volatile $uint8_t  *)0x4006A001 // UART Baud Rate Registers: Low\n"
  "//register UART0_C1  *(volatile $uint8_t  *)0x4006A002 // UART Control Register 1\n"
  "//register UART_C1_LOOPS   ($uint8_t)0x80   // When LOOPS is set, the RxD pin is disconnected from the UART and the transmitter output is internally c"
  "onnected to the receiver input\n"
  "//register UART_C1_UARTSWAI  ($uint8_t)0x40   // UART Stops in Wait Mode\n"
  "//register UART_C1_RSRC   ($uint8_t)0x20   // When LOOPS is set, the RSRC field determines the source for the receiver shift register input\n"
  "//register UART_C1_M   ($uint8_t)0x10   // 9-bit or 8-bit Mode Select\n"
  "//register UART_C1_WAKE   ($uint8_t)0x08   // Determines which condition wakes the UART\n"
  "//register UART_C1_ILT   ($uint8_t)0x04   // Idle Line Type Select\n"
  "//register UART_C1_PE   ($uint8_t)0x02   // Parity Enable\n"
  "//register UART_C1_PT   ($uint8_t)0x01   // Parity Type, 0=even, 1=odd\n"
  "//register UART0_C2  *(volatile $uint8_t  *)0x4006A003 // UART Control Register 2\n"
  "//register UART_C2_TIE   ($uint8_t)0x80   // Transmitter Interrupt or DMA Transfer Enable.\n"
  "//register UART_C2_TCIE   ($uint8_t)0x40   // Transmission Complete Interrupt Enable\n"
  "//register UART_C2_RIE   ($uint8_t)0x20   // Receiver Full Interrupt or DMA Transfer Enable\n"
  "//register UART_C2_ILIE   ($uint8_t)0x10   // Idle Line Interrupt Enable\n"
  "//register UART_C2_TE   ($uint8_t)0x08   // Transmitter Enable\n"
  "//register UART_C2_RE   ($uint8_t)0x04   // Receiver Enable\n"
  "//register UART_C2_RWU   ($uint8_t)0x02   // Receiver Wakeup Control\n"
  "//register UART_C2_SBK   ($uint8_t)0x01   // Send Break\n"
  "//register UART0_S1  *(volatile $uint8_t  *)0x4006A004 // UART Status Register 1\n"
  "//register UART_S1_TDRE   ($uint8_t)0x80   // Transmit Data Register Empty Flag\n"
  "//register UART_S1_TC   ($uint8_t)0x40   // Transmit Complete Flag\n"
  "//register UART_S1_RDRF   ($uint8_t)0x20   // Receive Data Register Full Flag\n"
  "//register UART_S1_IDLE   ($uint8_t)0x10   // Idle Line Flag\n"
  "//register UART_S1_OR   ($uint8_t)0x08   // Receiver Overrun Flag\n"
  "//register UART_S1_NF   ($uint8_t)0x04   // Noise Flag\n"
  "//register UART_S1_FE   ($uint8_t)0x02   // Framing Error Flag\n"
  "//register UART_S1_PF   ($uint8_t)0x01   // Parity Error Flag\n"
  "//register UART0_S2  *(volatile $uint8_t  *)0x4006A005 // UART Status Register 2\n"
  "//register UART0_C3  *(volatile $uint8_t  *)0x4006A006 // UART Control Register 3\n"
  "//register UART0_D   *(volatile $uint8_t  *)0x4006A007 // UART Data Register\n"
  "//register UART0_MA1  *(volatile $uint8_t  *)0x4006A008 // UART Match Address Registers 1\n"
  "//register UART0_MA2  *(volatile $uint8_t  *)0x4006A009 // UART Match Address Registers 2\n"
  "//register UART0_C4  *(volatile $uint8_t  *)0x4006A00A // UART Control Register 4\n"
  "//register UART0_C5  *(volatile $uint8_t  *)0x4006A00B // UART Control Register 5\n"
  "//register UART0_ED  *(volatile $uint8_t  *)0x4006A00C // UART Extended Data Register\n"
  "//register UART0_MODEM  *(volatile $uint8_t  *)0x4006A00D // UART Modem Register\n"
  "//register UART0_IR  *(volatile $uint8_t  *)0x4006A00E // UART Infrared Register\n"
  "//register UART0_PFIFO  *(volatile $uint8_t  *)0x4006A010 // UART FIFO Parameters\n"
  "//register UART_PFIFO_TXFE   ($uint8_t)0x80\n"
  "//register UART_PFIFO_RXFE   ($uint8_t)0x08\n"
  "//register UART0_CFIFO  *(volatile $uint8_t  *)0x4006A011 // UART FIFO Control Register\n"
  "//register UART_CFIFO_TXFLUSH  ($uint8_t)0x80   // \n"
  "//register UART_CFIFO_RXFLUSH  ($uint8_t)0x40   // \n"
  "//register UART_CFIFO_RXOFE  ($uint8_t)0x04   // \n"
  "//register UART_CFIFO_TXOFE  ($uint8_t)0x02   // \n"
  "//register UART_CFIFO_RXUFE  ($uint8_t)0x01   // \n"
  "//register UART0_SFIFO  *(volatile $uint8_t  *)0x4006A012 // UART FIFO Status Register\n"
  "//register UART_SFIFO_TXEMPT  ($uint8_t)0x80\n"
  "//register UART_SFIFO_RXEMPT  ($uint8_t)0x40\n"
  "//register UART_SFIFO_RXOF   ($uint8_t)0x04\n"
  "//register UART_SFIFO_TXOF   ($uint8_t)0x02\n"
  "//register UART_SFIFO_RXUF   ($uint8_t)0x01\n"
  "//register UART0_TWFIFO  *(volatile $uint8_t  *)0x4006A013 // UART FIFO Transmit Watermark\n"
  "//register UART0_TCFIFO  *(volatile $uint8_t  *)0x4006A014 // UART FIFO Transmit Count\n"
  "//register UART0_RWFIFO  *(volatile $uint8_t  *)0x4006A015 // UART FIFO Receive Watermark\n"
  "//register UART0_RCFIFO  *(volatile $uint8_t  *)0x4006A016 // UART FIFO Receive Count\n"
  "//register UART0_C7816  *(volatile $uint8_t  *)0x4006A018 // UART 7816 Control Register\n"
  "//register UART0_IE7816  *(volatile $uint8_t  *)0x4006A019 // UART 7816 Interrupt Enable Register\n"
  "//register UART0_IS7816  *(volatile $uint8_t  *)0x4006A01A // UART 7816 Interrupt Status Register\n"
  "//register UART0_WP7816T0  *(volatile $uint8_t  *)0x4006A01B // UART 7816 Wait Parameter Register\n"
  "//register UART0_WP7816T1  *(volatile $uint8_t  *)0x4006A01B // UART 7816 Wait Parameter Register\n"
  "//register UART0_WN7816  *(volatile $uint8_t  *)0x4006A01C // UART 7816 Wait N Register\n"
  "//register UART0_WF7816  *(volatile $uint8_t  *)0x4006A01D // UART 7816 Wait FD Register\n"
  "//register UART0_ET7816  *(volatile $uint8_t  *)0x4006A01E // UART 7816 Error Threshold Register\n"
  "//register UART0_TL7816  *(volatile $uint8_t  *)0x4006A01F // UART 7816 Transmit Length Register\n"
  "//register UART0_C6  *(volatile $uint8_t  *)0x4006A021 // UART CEA709.1-B Control Register 6\n"
  "//register UART0_PCTH  *(volatile $uint8_t  *)0x4006A022 // UART CEA709.1-B Packet Cycle Time Counter High\n"
  "//register UART0_PCTL  *(volatile $uint8_t  *)0x4006A023 // UART CEA709.1-B Packet Cycle Time Counter Low\n"
  "//register UART0_B1T  *(volatile $uint8_t  *)0x4006A024 // UART CEA709.1-B Beta1 Timer\n"
  "//register UART0_SDTH  *(volatile $uint8_t  *)0x4006A025 // UART CEA709.1-B Secondary Delay Timer High\n"
  "//register UART0_SDTL  *(volatile $uint8_t  *)0x4006A026 // UART CEA709.1-B Secondary Delay Timer Low\n"
  "//register UART0_PRE  *(volatile $uint8_t  *)0x4006A027 // UART CEA709.1-B Preamble\n"
  "//register UART0_TPL  *(volatile $uint8_t  *)0x4006A028 // UART CEA709.1-B Transmit Packet Length\n"
  "//register UART0_IE  *(volatile $uint8_t  *)0x4006A029 // UART CEA709.1-B Interrupt Enable Register\n"
  "//register UART0_WB  *(volatile $uint8_t  *)0x4006A02A // UART CEA709.1-B WBASE\n"
  "//register UART0_S3  *(volatile $uint8_t  *)0x4006A02B // UART CEA709.1-B Status Register\n"
  "//register UART0_S4  *(volatile $uint8_t  *)0x4006A02C // UART CEA709.1-B Status Register\n"
  "//register UART0_RPL  *(volatile $uint8_t  *)0x4006A02D // UART CEA709.1-B Received Packet Length\n"
  "//register UART0_RPREL  *(volatile $uint8_t  *)0x4006A02E // UART CEA709.1-B Received Preamble Length\n"
  "//register UART0_CPW  *(volatile $uint8_t  *)0x4006A02F // UART CEA709.1-B Collision Pulse Width\n"
  "//register UART0_RIDT  *(volatile $uint8_t  *)0x4006A030 // UART CEA709.1-B Receive Indeterminate Time\n"
  "//register UART0_TIDT  *(volatile $uint8_t  *)0x4006A031 // UART CEA709.1-B Transmit Indeterminate Time\n"
  "//register UART1_BDH  *(volatile $uint8_t  *)0x4006B000 // UART Baud Rate Registers: High\n"
  "//register UART1_BDL  *(volatile $uint8_t  *)0x4006B001 // UART Baud Rate Registers: Low\n"
  "//register UART1_C1  *(volatile $uint8_t  *)0x4006B002 // UART Control Register 1\n"
  "//register UART1_C2  *(volatile $uint8_t  *)0x4006B003 // UART Control Register 2\n"
  "//register UART1_S1  *(volatile $uint8_t  *)0x4006B004 // UART Status Register 1\n"
  "//register UART1_S2  *(volatile $uint8_t  *)0x4006B005 // UART Status Register 2\n"
  "//register UART1_C3  *(volatile $uint8_t  *)0x4006B006 // UART Control Register 3\n"
  "//register UART1_D   *(volatile $uint8_t  *)0x4006B007 // UART Data Register\n"
  "//register UART1_MA1  *(volatile $uint8_t  *)0x4006B008 // UART Match Address Registers 1\n"
  "//register UART1_MA2  *(volatile $uint8_t  *)0x4006B009 // UART Match Address Registers 2\n"
  "//register UART1_C4  *(volatile $uint8_t  *)0x4006B00A // UART Control Register 4\n"
  "//register UART1_C5  *(volatile $uint8_t  *)0x4006B00B // UART Control Register 5\n"
  "//register UART1_ED  *(volatile $uint8_t  *)0x4006B00C // UART Extended Data Register\n"
  "//register UART1_MODEM  *(volatile $uint8_t  *)0x4006B00D // UART Modem Register\n"
  "//register UART1_IR  *(volatile $uint8_t  *)0x4006B00E // UART Infrared Register\n"
  "//register UART1_PFIFO  *(volatile $uint8_t  *)0x4006B010 // UART FIFO Parameters\n"
  "//register UART1_CFIFO  *(volatile $uint8_t  *)0x4006B011 // UART FIFO Control Register\n"
  "//register UART1_SFIFO  *(volatile $uint8_t  *)0x4006B012 // UART FIFO Status Register\n"
  "//register UART1_TWFIFO  *(volatile $uint8_t  *)0x4006B013 // UART FIFO Transmit Watermark\n"
  "//register UART1_TCFIFO  *(volatile $uint8_t  *)0x4006B014 // UART FIFO Transmit Count\n"
  "//register UART1_RWFIFO  *(volatile $uint8_t  *)0x4006B015 // UART FIFO Receive Watermark\n"
  "//register UART1_RCFIFO  *(volatile $uint8_t  *)0x4006B016 // UART FIFO Receive Count\n"
  "//register UART1_C7816  *(volatile $uint8_t  *)0x4006B018 // UART 7816 Control Register\n"
  "//register UART1_IE7816  *(volatile $uint8_t  *)0x4006B019 // UART 7816 Interrupt Enable Register\n"
  "//register UART1_IS7816  *(volatile $uint8_t  *)0x4006B01A // UART 7816 Interrupt Status Register\n"
  "//register UART1_WP7816T0  *(volatile $uint8_t  *)0x4006B01B // UART 7816 Wait Parameter Register\n"
  "//register UART1_WP7816T1  *(volatile $uint8_t  *)0x4006B01B // UART 7816 Wait Parameter Register\n"
  "//register UART1_WN7816  *(volatile $uint8_t  *)0x4006B01C // UART 7816 Wait N Register\n"
  "//register UART1_WF7816  *(volatile $uint8_t  *)0x4006B01D // UART 7816 Wait FD Register\n"
  "//register UART1_ET7816  *(volatile $uint8_t  *)0x4006B01E // UART 7816 Error Threshold Register\n"
  "//register UART1_TL7816  *(volatile $uint8_t  *)0x4006B01F // UART 7816 Transmit Length Register\n"
  "//register UART1_C6  *(volatile $uint8_t  *)0x4006B021 // UART CEA709.1-B Control Register 6\n"
  "//register UART1_PCTH  *(volatile $uint8_t  *)0x4006B022 // UART CEA709.1-B Packet Cycle Time Counter High\n"
  "//register UART1_PCTL  *(volatile $uint8_t  *)0x4006B023 // UART CEA709.1-B Packet Cycle Time Counter Low\n"
  "//register UART1_B1T  *(volatile $uint8_t  *)0x4006B024 // UART CEA709.1-B Beta1 Timer\n"
  "//register UART1_SDTH  *(volatile $uint8_t  *)0x4006B025 // UART CEA709.1-B Secondary Delay Timer High\n"
  "//register UART1_SDTL  *(volatile $uint8_t  *)0x4006B026 // UART CEA709.1-B Secondary Delay Timer Low\n"
  "//register UART1_PRE  *(volatile $uint8_t  *)0x4006B027 // UART CEA709.1-B Preamble\n"
  "//register UART1_TPL  *(volatile $uint8_t  *)0x4006B028 // UART CEA709.1-B Transmit Packet Length\n"
  "//register UART1_IE  *(volatile $uint8_t  *)0x4006B029 // UART CEA709.1-B Interrupt Enable Register\n"
  "//register UART1_WB  *(volatile $uint8_t  *)0x4006B02A // UART CEA709.1-B WBASE\n"
  "//register UART1_S3  *(volatile $uint8_t  *)0x4006B02B // UART CEA709.1-B Status Register\n"
  "//register UART1_S4  *(volatile $uint8_t  *)0x4006B02C // UART CEA709.1-B Status Register\n"
  "//register UART1_RPL  *(volatile $uint8_t  *)0x4006B02D // UART CEA709.1-B Received Packet Length\n"
  "//register UART1_RPREL  *(volatile $uint8_t  *)0x4006B02E // UART CEA709.1-B Received Preamble Length\n"
  "//register UART1_CPW  *(volatile $uint8_t  *)0x4006B02F // UART CEA709.1-B Collision Pulse Width\n"
  "//register UART1_RIDT  *(volatile $uint8_t  *)0x4006B030 // UART CEA709.1-B Receive Indeterminate Time\n"
  "//register UART1_TIDT  *(volatile $uint8_t  *)0x4006B031 // UART CEA709.1-B Transmit Indeterminate Time\n"
  "//register UART2_BDH  *(volatile $uint8_t  *)0x4006C000 // UART Baud Rate Registers: High\n"
  "//register UART2_BDL  *(volatile $uint8_t  *)0x4006C001 // UART Baud Rate Registers: Low\n"
  "//register UART2_C1  *(volatile $uint8_t  *)0x4006C002 // UART Control Register 1\n"
  "//register UART2_C2  *(volatile $uint8_t  *)0x4006C003 // UART Control Register 2\n"
  "//register UART2_S1  *(volatile $uint8_t  *)0x4006C004 // UART Status Register 1\n"
  "//register UART2_S2  *(volatile $uint8_t  *)0x4006C005 // UART Status Register 2\n"
  "//register UART2_C3  *(volatile $uint8_t  *)0x4006C006 // UART Control Register 3\n"
  "//register UART2_D   *(volatile $uint8_t  *)0x4006C007 // UART Data Register\n"
  "//register UART2_MA1  *(volatile $uint8_t  *)0x4006C008 // UART Match Address Registers 1\n"
  "//register UART2_MA2  *(volatile $uint8_t  *)0x4006C009 // UART Match Address Registers 2\n"
  "//register UART2_C4  *(volatile $uint8_t  *)0x4006C00A // UART Control Register 4\n"
  "//register UART2_C5  *(volatile $uint8_t  *)0x4006C00B // UART Control Register 5\n"
  "//register UART2_ED  *(volatile $uint8_t  *)0x4006C00C // UART Extended Data Register\n"
  "//register UART2_MODEM  *(volatile $uint8_t  *)0x4006C00D // UART Modem Register\n"
  "//register UART2_IR  *(volatile $uint8_t  *)0x4006C00E // UART Infrared Register\n"
  "//register UART2_PFIFO  *(volatile $uint8_t  *)0x4006C010 // UART FIFO Parameters\n"
  "//register UART2_CFIFO  *(volatile $uint8_t  *)0x4006C011 // UART FIFO Control Register\n"
  "//register UART2_SFIFO  *(volatile $uint8_t  *)0x4006C012 // UART FIFO Status Register\n"
  "//register UART2_TWFIFO  *(volatile $uint8_t  *)0x4006C013 // UART FIFO Transmit Watermark\n"
  "//register UART2_TCFIFO  *(volatile $uint8_t  *)0x4006C014 // UART FIFO Transmit Count\n"
  "//register UART2_RWFIFO  *(volatile $uint8_t  *)0x4006C015 // UART FIFO Receive Watermark\n"
  "//register UART2_RCFIFO  *(volatile $uint8_t  *)0x4006C016 // UART FIFO Receive Count\n"
  "//register UART2_C7816  *(volatile $uint8_t  *)0x4006C018 // UART 7816 Control Register\n"
  "//register UART2_IE7816  *(volatile $uint8_t  *)0x4006C019 // UART 7816 Interrupt Enable Register\n"
  "//register UART2_IS7816  *(volatile $uint8_t  *)0x4006C01A // UART 7816 Interrupt Status Register\n"
  "//register UART2_WP7816T0  *(volatile $uint8_t  *)0x4006C01B // UART 7816 Wait Parameter Register\n"
  "//register UART2_WP7816T1  *(volatile $uint8_t  *)0x4006C01B // UART 7816 Wait Parameter Register\n"
  "//register UART2_WN7816  *(volatile $uint8_t  *)0x4006C01C // UART 7816 Wait N Register\n"
  "//register UART2_WF7816  *(volatile $uint8_t  *)0x4006C01D // UART 7816 Wait FD Register\n"
  "//register UART2_ET7816  *(volatile $uint8_t  *)0x4006C01E // UART 7816 Error Threshold Register\n"
  "//register UART2_TL7816  *(volatile $uint8_t  *)0x4006C01F // UART 7816 Transmit Length Register\n"
  "//register UART2_C6  *(volatile $uint8_t  *)0x4006C021 // UART CEA709.1-B Control Register 6\n"
  "//register UART2_PCTH  *(volatile $uint8_t  *)0x4006C022 // UART CEA709.1-B Packet Cycle Time Counter High\n"
  "//register UART2_PCTL  *(volatile $uint8_t  *)0x4006C023 // UART CEA709.1-B Packet Cycle Time Counter Low\n"
  "//register UART2_B1T  *(volatile $uint8_t  *)0x4006C024 // UART CEA709.1-B Beta1 Timer\n"
  "//register UART2_SDTH  *(volatile $uint8_t  *)0x4006C025 // UART CEA709.1-B Secondary Delay Timer High\n"
  "//register UART2_SDTL  *(volatile $uint8_t  *)0x4006C026 // UART CEA709.1-B Secondary Delay Timer Low\n"
  "//register UART2_PRE  *(volatile $uint8_t  *)0x4006C027 // UART CEA709.1-B Preamble\n"
  "//register UART2_TPL  *(volatile $uint8_t  *)0x4006C028 // UART CEA709.1-B Transmit Packet Length\n"
  "//register UART2_IE  *(volatile $uint8_t  *)0x4006C029 // UART CEA709.1-B Interrupt Enable Register\n"
  "//register UART2_WB  *(volatile $uint8_t  *)0x4006C02A // UART CEA709.1-B WBASE\n"
  "//register UART2_S3  *(volatile $uint8_t  *)0x4006C02B // UART CEA709.1-B Status Register\n"
  "//register UART2_S4  *(volatile $uint8_t  *)0x4006C02C // UART CEA709.1-B Status Register\n"
  "//register UART2_RPL  *(volatile $uint8_t  *)0x4006C02D // UART CEA709.1-B Received Packet Length\n"
  "//register UART2_RPREL  *(volatile $uint8_t  *)0x4006C02E // UART CEA709.1-B Received Preamble Length\n"
  "//register UART2_CPW  *(volatile $uint8_t  *)0x4006C02F // UART CEA709.1-B Collision Pulse Width\n"
  "//register UART2_RIDT  *(volatile $uint8_t  *)0x4006C030 // UART CEA709.1-B Receive Indeterminate Time\n"
  "//register UART2_TIDT  *(volatile $uint8_t  *)0x4006C031 // UART CEA709.1-B Transmit Indeterminate Time\n"
  "//\n"
  "//// Chapter 46: Synchronous Audio Interface (SAI)\n"
  "//register I2S0_TCSR   0x4002F000 // SAI Transmit Control Register\n"
  "//register I2S_TCSR_TE    0x80000000 // Transmitter Enable\n"
  "//register I2S_TCSR_STOPE    0x40000000 // Transmitter Enable in Stop mode\n"
  "//register I2S_TCSR_DBGE    0x20000000 // Transmitter Enable in Debug mode\n"
  "//register I2S_TCSR_BCE    0x10000000 // Bit Clock Enable\n"
  "//register I2S_TCSR_FR    0x02000000 // FIFO Reset\n"
  "//register I2S_TCSR_SR    0x01000000 // Software Reset\n"
  "//register I2S_TCSR_WSF    0x00100000 // Word Start Flag\n"
  "//register I2S_TCSR_SEF    0x00080000 // Sync Error Flag\n"
  "//register I2S_TCSR_FEF    0x00040000 // FIFO Error Flag (underrun)\n"
  "//register I2S_TCSR_FWF    0x00020000 // FIFO Warning Flag (empty)\n"
  "//register I2S_TCSR_FRF    0x00010000 // FIFO Request Flag (Data Ready)\n"
  "//register I2S_TCSR_WSIE    0x00001000 // Word Start Interrupt Enable\n"
  "//register I2S_TCSR_SEIE    0x00000800 // Sync Error Interrupt Enable\n"
  "//register I2S_TCSR_FEIE    0x00000400 // FIFO Error Interrupt Enable\n"
  "//register I2S_TCSR_FWIE    0x00000200 // FIFO Warning Interrupt Enable\n"
  "//register I2S_TCSR_FRIE    0x00000100 // FIFO Request Interrupt Enable\n"
  "//register I2S_TCSR_FWDE    0x00000002 // FIFO Warning DMA Enable\n"
  "//register I2S_TCSR_FRDE    0x00000001 // FIFO Request DMA Enable\n"
  "//register I2S0_TCR1   0x4002F004 // SAI Transmit Configuration 1 Register\n"
  "//register I2S_TCR1_TFW(n)   ( n & 0x03)       // Transmit FIFO watermark\n"
  "//register I2S0_TCR2   0x4002F008 // SAI Transmit Configuration 2 Register\n"
  "//register I2S_TCR2_DIV(n)   ( n & 0xff)       // Bit clock divide by (DIV+1)*2\n"
  "//register I2S_TCR2_BCD   ( 1<<24)       // Bit clock direction\n"
  "//register I2S_TCR2_BCP   ( 1<<25)       // Bit clock polarity\n"
  "//register I2S_TCR2_MSEL(n)  ( (n & 3)<<26)       // MCLK select, 0=bus clock, 1=I2S0_MCLK\n"
  "//register I2S_TCR2_BCI   ( 1<<28)       // Bit clock input\n"
  "//register I2S_TCR2_BCS   ( 1<<29)       // Bit clock swap\n"
  "//register I2S_TCR2_SYNC(n)  ( (n & 3)<<30)       // 0=async 1=sync with receiver\n"
  "//register I2S0_TCR3   0x4002F00C // SAI Transmit Configuration 3 Register\n"
  "//register I2S_TCR3_WDFL(n)  ( n & 0x0f)       // word flag configuration\n"
  "//register I2S_TCR3_TCE   ( 0x10000)       // transmit channel enable\n"
  "//register I2S0_TCR4   0x4002F010 // SAI Transmit Configuration 4 Register\n"
  "//register I2S_TCR4_FSD   ( 1)        // Frame Sync Direction\n"
  "//register I2S_TCR4_FSP   ( 2)        // Frame Sync Polarity\n"
  "//register I2S_TCR4_FSE   ( 8)        // Frame Sync Early\n"
  "//register I2S_TCR4_MF   ( 0x10)       // MSB First\n"
  "//register I2S_TCR4_SYWD(n)  ( (n & 0x1f)<<8)     // Sync Width\n"
  "//register I2S_TCR4_FRSZ(n)  ( (n & 0x0f)<<16)    // Frame Size\n"
  "//register I2S0_TCR5   0x4002F014 // SAI Transmit Configuration 5 Register\n"
  "//register I2S_TCR5_FBT(n)   ( (n & 0x1f)<<8)     // First Bit Shifted\n"
  "//register I2S_TCR5_W0W(n)   ( (n & 0x1f)<<16)    // Word 0 Width\n"
  "//register I2S_TCR5_WNW(n)   ( (n & 0x1f)<<24)    // Word N Width\n"
  "//register I2S0_TDR0   0x4002F020 // SAI Transmit Data Register\n"
  "//register I2S0_TDR1   0x4002F024 // SAI Transmit Data Register\n"
  "//register I2S0_TFR0   0x4002F040 // SAI Transmit FIFO Register\n"
  "//register I2S0_TFR1   0x4002F044 // SAI Transmit FIFO Register\n"
  "//register I2S_TFR_RFP(n)   ( n & 7)       // read FIFO pointer\n"
  "//register I2S_TFR_WFP(n)   ( (n & 7)<<16)       // write FIFO pointer\n"
  "//register I2S0_TMR   0x4002F060 // SAI Transmit Mask Register\n"
  "//register I2S_TMR_TWM(n)   ( n & 0xFFFFFFFF)\n"
  "//register I2S0_RCSR   0x4002F080 // SAI Receive Control Register\n"
  "//register I2S_RCSR_RE    0x80000000 // Receiver Enable\n"
  "//register I2S_RCSR_STOPE    0x40000000 // Receiver Enable in Stop mode\n"
  "//register I2S_RCSR_DBGE    0x20000000 // Receiver Enable in Debug mode\n"
  "//register I2S_RCSR_BCE    0x10000000 // Bit Clock Enable\n"
  "//register I2S_RCSR_FR    0x02000000 // FIFO Reset\n"
  "//register I2S_RCSR_SR    0x01000000 // Software Reset\n"
  "//register I2S_RCSR_WSF    0x00100000 // Word Start Flag\n"
  "//register I2S_RCSR_SEF    0x00080000 // Sync Error Flag\n"
  "//register I2S_RCSR_FEF    0x00040000 // FIFO Error Flag (underrun)\n"
  "//register I2S_RCSR_FWF    0x00020000 // FIFO Warning Flag (empty)\n"
  "//register I2S_RCSR_FRF    0x00010000 // FIFO Request Flag (Data Ready)\n"
  "//register I2S_RCSR_WSIE    0x00001000 // Word Start Interrupt Enable\n"
  "//register I2S_RCSR_SEIE    0x00000800 // Sync Error Interrupt Enable\n"
  "//register I2S_RCSR_FEIE    0x00000400 // FIFO Error Interrupt Enable\n"
  "//register I2S_RCSR_FWIE    0x00000200 // FIFO Warning Interrupt Enable\n"
  "//register I2S_RCSR_FRIE    0x00000100 // FIFO Request Interrupt Enable\n"
  "//register I2S_RCSR_FWDE    0x00000002 // FIFO Warning DMA Enable\n"
  "//register I2S_RCSR_FRDE    0x00000001 // FIFO Request DMA Enable\n"
  "//register I2S0_RCR1   0x4002F084 // SAI Receive Configuration 1 Register\n"
  "//register I2S_RCR1_RFW(n)   ( n & 0x03)       // Receive FIFO watermark\n"
  "//register I2S0_RCR2   0x4002F088 // SAI Receive Configuration 2 Register\n"
  "//register I2S_RCR2_DIV(n)   ( n & 0xff)       // Bit clock divide by (DIV+1)*2\n"
  "//register I2S_RCR2_BCD   ( 1<<24)       // Bit clock direction\n"
  "//register I2S_RCR2_BCP   ( 1<<25)       // Bit clock polarity\n"
  "//register I2S_RCR2_MSEL(n)  ( (n & 3)<<26)       // MCLK select, 0=bus clock, 1=I2S0_MCLK\n"
  "//register I2S_RCR2_BCI   ( 1<<28)       // Bit clock input\n"
  "//register I2S_RCR2_BCS   ( 1<<29)       // Bit clock swap\n"
  "//register I2S_RCR2_SYNC(n)  ( (n & 3)<<30)       // 0=async 1=sync with receiver\n"
  "//register I2S0_RCR3   0x4002F08C // SAI Receive Configuration 3 Register\n"
  "//register I2S_RCR3_WDFL(n)  ( n & 0x0f)       // word flag configuration\n"
  "//register I2S_RCR3_RCE   ( 0x10000)       // receive channel enable\n"
  "//register I2S0_RCR4   0x4002F090 // SAI Receive Configuration 4 Register\n"
  "//register I2S_RCR4_FSD   ( 1)        // Frame Sync Direction\n"
  "//register I2S_RCR4_FSP   ( 2)        // Frame Sync Polarity\n"
  "//register I2S_RCR4_FSE   ( 8)        // Frame Sync Early\n"
  "//register I2S_RCR4_MF   ( 0x10)       // MSB First\n"
  "//register I2S_RCR4_SYWD(n)  ( (n & 0x1f)<<8)     // Sync Width\n"
  "//register I2S_RCR4_FRSZ(n)  ( (n & 0x0f)<<16)    // Frame Size\n"
  "//register I2S0_RCR5   0x4002F094 // SAI Receive Configuration 5 Register\n"
  "//register I2S_RCR5_FBT(n)   ( (n & 0x1f)<<8)     // First Bit Shifted\n"
  "//register I2S_RCR5_W0W(n)   ( (n & 0x1f)<<16)    // Word 0 Width\n"
  "//register I2S_RCR5_WNW(n)   ( (n & 0x1f)<<24)    // Word N Width\n"
  "//register I2S0_RDR0   0x4002F0A0 // SAI Receive Data Register\n"
  "//register I2S0_RDR1   0x4002F0A4 // SAI Receive Data Register\n"
  "//register I2S0_RFR0   0x4002F0C0 // SAI Receive FIFO Register\n"
  "//register I2S0_RFR1   0x4002F0C4 // SAI Receive FIFO Register\n"
  "//register I2S_RFR_RFP(n)   ( n & 7)       // read FIFO pointer\n"
  "//register I2S_RFR_WFP(n)   ( (n & 7)<<16)       // write FIFO pointer\n"
  "//register I2S0_RMR   0x4002F0E0 // SAI Receive Mask Register\n"
  "//register I2S_RMR_RWM(n)   ( n & 0xFFFFFFFF)\n"
  "//register I2S0_MCR   0x4002F100 // SAI MCLK Control Register\n"
  "//register I2S_MCR_DUF   ( 1<<31)       // Divider Update Flag\n"
  "//register I2S_MCR_MOE   ( 1<<30)       // MCLK Output Enable\n"
  "//register I2S_MCR_MICS(n)   ( (n & 3)<<24)       // MCLK Input Clock Select\n"
  "//register I2S0_MDR   0x4002F104 // SAI MCLK Divide Register\n"
  "//register I2S_MDR_FRACT(n)  ( (n & 0xff)<<12)    // MCLK Fraction\n"
  "//register I2S_MDR_DIVIDE(n)  ( (n & 0xfff))       // MCLK Divide\n"
  "\n"
  "// Chapter 47: General-Purpose Input/Output (GPIO)\n"
  "register GPIOA_PDOR   at 0x400FF000 $uint32 // Port Data Output Register\n"
  "register GPIOA_PSOR   at 0x400FF004 $uint32 // Port Set Output Register\n"
  "register GPIOA_PCOR   at 0x400FF008 $uint32 // Port Clear Output Register\n"
  "register GPIOA_PTOR   at 0x400FF00C $uint32 // Port Toggle Output Register\n"
  "register GPIOA_PDIR   at 0x400FF010 $uint32 // Port Data Input Register\n"
  "register GPIOA_PDDR   at 0x400FF014 $uint32 // Port Data Direction Register\n"
  "register GPIOB_PDOR   at 0x400FF040 $uint32 // Port Data Output Register\n"
  "register GPIOB_PSOR   at 0x400FF044 $uint32 // Port Set Output Register\n"
  "register GPIOB_PCOR   at 0x400FF048 $uint32 // Port Clear Output Register\n"
  "register GPIOB_PTOR   at 0x400FF04C $uint32 // Port Toggle Output Register\n"
  "register GPIOB_PDIR   at 0x400FF050 $uint32 // Port Data Input Register\n"
  "register GPIOB_PDDR   at 0x400FF054 $uint32 // Port Data Direction Register\n"
  "register GPIOC_PDOR   at 0x400FF080 $uint32 // Port Data Output Register\n"
  "register GPIOC_PSOR   at 0x400FF084 $uint32 // Port Set Output Register\n"
  "register GPIOC_PCOR   at 0x400FF088 $uint32 // Port Clear Output Register\n"
  "register GPIOC_PTOR   at 0x400FF08C $uint32 // Port Toggle Output Register\n"
  "register GPIOC_PDIR   at 0x400FF090 $uint32 // Port Data Input Register\n"
  "register GPIOC_PDDR   at 0x400FF094 $uint32 // Port Data Direction Register\n"
  "register GPIOD_PDOR   at 0x400FF0C0 $uint32 // Port Data Output Register\n"
  "register GPIOD_PSOR   at 0x400FF0C4 $uint32 // Port Set Output Register\n"
  "register GPIOD_PCOR   at 0x400FF0C8 $uint32 // Port Clear Output Register\n"
  "register GPIOD_PTOR   at 0x400FF0CC $uint32 // Port Toggle Output Register\n"
  "register GPIOD_PDIR   at 0x400FF0D0 $uint32 // Port Data Input Register\n"
  "register GPIOD_PDDR   at 0x400FF0D4 $uint32 // Port Data Direction Register\n"
  "register GPIOE_PDOR   at 0x400FF100 $uint32 // Port Data Output Register\n"
  "register GPIOE_PSOR   at 0x400FF104 $uint32 // Port Set Output Register\n"
  "register GPIOE_PCOR   at 0x400FF108 $uint32 // Port Clear Output Register\n"
  "register GPIOE_PTOR   at 0x400FF10C $uint32 // Port Toggle Output Register\n"
  "register GPIOE_PDIR   at 0x400FF110 $uint32 // Port Data Input Register\n"
  "register GPIOE_PDDR   at 0x400FF114 $uint32 // Port Data Direction Register\n"
  "//\n"
  "//// Chapter 48: Touch sense input (TSI)\n"
  "//register TSI0_GENCS   0x40045000 // General Control and Status Register\n"
  "//register TSI_GENCS_LPCLKS   0x10000000  // \n"
  "//register TSI_GENCS_LPSCNITV(n)  (((n) & 15) << 24)  // \n"
  "//register TSI_GENCS_NSCN(n)  (((n) & 31) << 19)  // \n"
  "//register TSI_GENCS_PS(n)   (((n) & 7) << 16)  // \n"
  "//register TSI_GENCS_EOSF    0x00008000  // \n"
  "//register TSI_GENCS_OUTRGF   0x00004000  // \n"
  "//register TSI_GENCS_EXTERF   0x00002000  // \n"
  "//register TSI_GENCS_OVRF    0x00001000  // \n"
  "//register TSI_GENCS_SCNIP    0x00000200  // \n"
  "//register TSI_GENCS_SWTS    0x00000100  // \n"
  "//register TSI_GENCS_TSIEN    0x00000080  // \n"
  "//register TSI_GENCS_TSIIE    0x00000040  // \n"
  "//register TSI_GENCS_ERIE    0x00000020  // \n"
  "//register TSI_GENCS_ESOR    0x00000010  // \n"
  "//register TSI_GENCS_STM    0x00000002  // \n"
  "//register TSI_GENCS_STPE    0x00000001  // \n"
  "//register TSI0_SCANC   0x40045004 // SCAN Control Register\n"
  "//register TSI_SCANC_REFCHRG(n)  (((n) & 15) << 24)  // \n"
  "//register TSI_SCANC_EXTCHRG(n)  (((n) & 7) << 16)  // \n"
  "//register TSI_SCANC_SMOD(n)  (((n) & 255) << 8)  // \n"
  "//register TSI_SCANC_AMCLKS(n)  (((n) & 3) << 3)  // \n"
  "//register TSI_SCANC_AMPSC(n)  (((n) & 7) << 0)  // \n"
  "//register TSI0_PEN   0x40045008 // Pin Enable Register\n"
  "//register TSI0_WUCNTR   0x4004500C // Wake-Up Channel Counter Register\n"
  "//register TSI0_CNTR1   0x40045100 // Counter Register\n"
  "//register TSI0_CNTR3   0x40045104 // Counter Register\n"
  "//register TSI0_CNTR5   0x40045108 // Counter Register\n"
  "//register TSI0_CNTR7   0x4004510C // Counter Register\n"
  "//register TSI0_CNTR9   0x40045110 // Counter Register\n"
  "//register TSI0_CNTR11   0x40045114 // Counter Register\n"
  "//register TSI0_CNTR13   0x40045118 // Counter Register\n"
  "//register TSI0_CNTR15   0x4004511C // Counter Register\n"
  "//register TSI0_THRESHOLD   0x40045120 // Low Power Channel Threshold Register\n"
  "//\n"
  "//// Nested Vectored Interrupt Controller, Table 3-4 & ARMv7 ref, appendix B3.4 (page 750)\n"
  "//register NVIC_ENABLE_IRQ(n) (*((volatile $uint32_t *)0xE000E100 + (n >> 5)) = (1 << (n & 31)))\n"
  "//register NVIC_DISABLE_IRQ(n) (*((volatile $uint32_t *)0xE000E180 + (n >> 5)) = (1 << (n & 31)))\n"
  "//register NVIC_SET_PENDING(n) (*((volatile $uint32_t *)0xE000E200 + (n >> 5)) = (1 << (n & 31)))\n"
  "//register NVIC_CLEAR_PENDING(n) (*((volatile $uint32_t *)0xE000E280 + (n >> 5)) = (1 << (n & 31)))\n"
  "//\n"
  "//register NVIC_ISER0   0xE000E100\n"
  "//register NVIC_ISER1   0xE000E104\n"
  "//register NVIC_ICER0   0xE000E180\n"
  "//register NVIC_ICER1   0xE000E184\n"
  "//\n"
  "//// 0 = highest priority\n"
  "//// Cortex-M4: 0,16,32,48,64,80,96,112,128,144,160,176,192,208,224,240\n"
  "//// Cortex-M0: 0,64,128,192\n"
  "//register NVIC_SET_PRIORITY(irqnum, priority)  (*((volatile $uint8_t *)0xE000E400 + (irqnum)) = ($uint8_t)(priority))\n"
  "//register NVIC_GET_PRIORITY(irqnum) (*(($uint8_t *)0xE000E400 + (irqnum)))\n"
  "//\n"
  "//register IRQ_DMA_CH0  0\n"
  "//register IRQ_DMA_CH1  1\n"
  "//register IRQ_DMA_CH2  2\n"
  "//register IRQ_DMA_CH3  3\n"
  "//register IRQ_DMA_CH4  4\n"
  "//register IRQ_DMA_CH5  5\n"
  "//register IRQ_DMA_CH6  6\n"
  "//register IRQ_DMA_CH7  7\n"
  "//register IRQ_DMA_CH8  8\n"
  "//register IRQ_DMA_CH9  9\n"
  "//register IRQ_DMA_CH10  10\n"
  "//register IRQ_DMA_CH11  11\n"
  "//register IRQ_DMA_CH12  12\n"
  "//register IRQ_DMA_CH13  13\n"
  "//register IRQ_DMA_CH14  14\n"
  "//register IRQ_DMA_CH15  15\n"
  "//register IRQ_DMA_ERROR  16\n"
  "//register IRQ_FTFL_COMPLETE 18\n"
  "//register IRQ_FTFL_COLLISION 19\n"
  "//register IRQ_LOW_VOLTAGE  20\n"
  "//register IRQ_LLWU  21\n"
  "//register IRQ_WDOG  22\n"
  "//register IRQ_I2C0  24\n"
  "//register IRQ_I2C1  25\n"
  "//register IRQ_SPI0  26\n"
  "//register IRQ_SPI1  27\n"
  "//register IRQ_CAN_MESSAGE  29\n"
  "//register IRQ_CAN_BUS_OFF  30\n"
  "//register IRQ_CAN_ERROR  31\n"
  "//register IRQ_CAN_TX_WARN  32\n"
  "//register IRQ_CAN_RX_WARN  33\n"
  "//register IRQ_CAN_WAKEUP  34\n"
  "//register IRQ_I2S0_TX  35\n"
  "//register IRQ_I2S0_RX  36\n"
  "//register IRQ_UART0_LON  44\n"
  "//register IRQ_UART0_STATUS 45\n"
  "//register IRQ_UART0_ERROR  46\n"
  "//register IRQ_UART1_STATUS 47\n"
  "//register IRQ_UART1_ERROR  48\n"
  "//register IRQ_UART2_STATUS 49\n"
  "//register IRQ_UART2_ERROR  50\n"
  "//register IRQ_ADC0  57\n"
  "//register IRQ_ADC1  58\n"
  "//register IRQ_CMP0  59\n"
  "//register IRQ_CMP1  60\n"
  "//register IRQ_CMP2  61\n"
  "//register IRQ_FTM0  62\n"
  "//register IRQ_FTM1  63\n"
  "//register IRQ_FTM2  64\n"
  "//register IRQ_CMT   65\n"
  "//register IRQ_RTC_ALARM  66\n"
  "//register IRQ_RTC_SECOND  67\n"
  "//register IRQ_PIT_CH0  68\n"
  "//register IRQ_PIT_CH1  69\n"
  "//register IRQ_PIT_CH2  70\n"
  "//register IRQ_PIT_CH3  71\n"
  "//register IRQ_PDB   72\n"
  "//register IRQ_USBOTG  73\n"
  "//register IRQ_USBDCD  74\n"
  "//register IRQ_DAC0  81\n"
  "//register IRQ_TSI   83\n"
  "//register IRQ_MCG   84\n"
  "//register IRQ_LPTMR  85\n"
  "//register IRQ_PORTA  87\n"
  "//register IRQ_PORTB  88\n"
  "//register IRQ_PORTC  89\n"
  "//register IRQ_PORTD  90\n"
  "//register IRQ_PORTE  91\n"
  "//register IRQ_SOFTWARE  94\n"
  "//register NVIC_NUM_INTERRUPTS 95\n"
  "//\n"
  "\n"
  "//System Control Space (SCS), ARMv7 ref manual, B3.2, page 708\n"
  "//register SCB_CPUID  *(const    $uint32_t *)0xE000ED00 // CPUID Base Register\n"
  "\n"
  "register ICSR at 0xE000_ED04 $uint32 { // Interrupt Control and State\n"
  "  NMIPENDSET, 2, PENDSVSET, PENDSVCLR, PENDSTSET, PENDSTCLR, 1, ISRPREEMPT,\n"
  "  ISRPENDING, 1, VECTPENDING[9], RETTOBASE, 2, VECTACTIVE[9]\n"
  "}\n"
  "\n"
  "register VTOR at 0xE000ED08 $uint32 // Vector Table Offset\n"
  "\n"
  "register AIRCR at 0xE000ED0C $uint32 { // Application Interrupt and Reset Control\n"
  "  VECTKEY[16], ENDIANNESS, 4, PRIGROUP[3],\n"
  "  5, SYSRESETREQ, VECTCLRACTIVE, VECTRESET \n"
  "}\n"
  "\n"
  "//register SCB_SCR    0xE000ED10 // System Control Register\n"
  "//register SCB_CCR    0xE000ED14 // Configuration and Control\n"
  "//register SCB_SHPR1   0xE000ED18 // System Handler Priority Register 1\n"
  "//register SCB_SHPR2   0xE000ED1C // System Handler Priority Register 2\n"
  "//register SCB_SHPR3   0xE000ED20 // System Handler Priority Register 3\n"
  "//register SCB_SHCSR   0xE000ED24 // System Handler Control and State\n"
  "//register SCB_CFSR   0xE000ED28 // Configurable Fault Status Register\n"
  "//register SCB_HFSR   0xE000ED2C // HardFault Status\n"
  "//register SCB_DFSR   0xE000ED30 // Debug Fault Status\n"
  "//register SCB_MMFAR   0xE000ED34 // MemManage Fault Address\n"
  "\n"
  "register SYST_CSR at 0xE000_E010 $uint32 { // SysTick Control and Status\n"
  "  15, \n"
  "  COUNTFLAG,\n"
  "  13,\n"
  "  CLKSOURCE,\n"
  "  TICKINT,\n"
  "  ENABLE\n"
  "}\n"
  "\n"
  "register SYST_RVR   at 0xE000_E014 $uint32 // SysTick Reload Value Register\n"
  "\n"
  "register SYST_CVR   at 0xE000_E018 $uint32 // SysTick Current Value Register\n"
  "\n"
  "register SYST_CALIB  @ro at 0xE000_E01C $uint32 // SysTick Calibration Value\n"
  "\n"
  "\n"
  "//register ARM_DEMCR   0xE000EDFC // Debug Exception and Monitor Control\n"
  "//register ARM_DEMCR_TRCENA  (1 << 24)  // Enable debugging & monitoring blocks\n"
  "//register ARM_DWT_CTRL   0xE0001000 // DWT control register\n"
  "//register ARM_DWT_CTRL_CYCCNTENA  (1 << 0)  // Enable cycle count\n"
  "//register ARM_DWT_CYCCNT   0xE0001004 // Cycle count register\n" ;

const cRegularFileWrapper gWrapperFile_8_embeddedTargets (
  "mk20dx256.plm",
  "plm",
  true, // Text file
  135562, // Text length
  gWrapperFileContent_8_embeddedTargets
) ;

//--- All files of 'files' directory

static const cRegularFileWrapper * gWrapperAllFiles_embeddedTargets_1 [6] = {
  & gWrapperFile_4_embeddedTargets,
  & gWrapperFile_5_embeddedTargets,
  & gWrapperFile_6_embeddedTargets,
  & gWrapperFile_7_embeddedTargets,
  & gWrapperFile_8_embeddedTargets,
  NULL
} ;

//--- All sub-directories of 'files' directory

static const cDirectoryWrapper * gWrapperAllDirectories_embeddedTargets_1 [1] = {
  NULL
} ;

//--- Directory 'files'

const cDirectoryWrapper gWrapperDirectory_1_embeddedTargets (
  "files",
  5,
  gWrapperAllFiles_embeddedTargets_1,
  0,
  gWrapperAllDirectories_embeddedTargets_1
) ;

//--- File 'teensy-3-1-interrupt/build-verbose.py'

const char * gWrapperFileContent_9_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import subprocess\n"
  "import sys\n"
  "import os\n"
  "import atexit\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "def cleanup():\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.kill ()\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "#--- Register a function for killing subprocess\n"
  "atexit.register (cleanup)\n"
  "#--- Get script absolute path\n"
  "scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))\n"
  "os.chdir (scriptDir)\n"
  "#---\n"
  "childProcess = subprocess.Popen ([\"python\", \"build.py\", \"all\", \"1\"])\n"
  "#--- Wait for subprocess termination\n"
  "if childProcess.poll () == None :\n"
  "  childProcess.wait ()\n"
  "if childProcess.returncode != 0 :\n"
  "  sys.exit (childProcess.returncode)\n"
  "\n"
  "#------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_9_embeddedTargets (
  "build-verbose.py",
  "py",
  true, // Text file
  1002, // Text length
  gWrapperFileContent_9_embeddedTargets
) ;

//--- File 'teensy-3-1-interrupt/build.py'

const char * gWrapperFileContent_10_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import subprocess, sys, os, copy\n"
  "import urllib, shutil\n"
  "import subprocess, re\n"
  "from time import time\n"
  "import platform\n"
  "import json\n"
  "import threading, operator\n"
  "\n"
  "if sys.version_info >= (2, 6) :\n"
  "  import multiprocessing\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   processorCount                                                                                                     *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def processorCount () :\n"
  "  if sys.version_info >= (2, 6) :\n"
  "    coreCount = multiprocessing.cpu_count ()\n"
  "  else:\n"
  "    coreCount = 1\n"
  "  return coreCount\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   FOR PRINTING IN COLOR                                                                                              *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BLACK () :\n"
  "  return '\\033[90m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def RED () :\n"
  "  return '\\033[91m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def GREEN () :\n"
  "  return '\\033[92m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def YELLOW () :\n"
  "  return '\\033[93m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BLUE () :\n"
  "  return '\\033[94m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def MAGENTA () :\n"
  "  return '\\033[95m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def CYAN () :\n"
  "  return '\\033[96m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def WHITE () :\n"
  "  return '\\033[97m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def ENDC () :\n"
  "  return '\\033[0m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BOLD () :\n"
  "  return '\\033[1m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def UNDERLINE () :\n"
  "  return '\\033[4m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BLINK () :\n"
  "  return '\\033[5m'\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BOLD_BLUE () :\n"
  "  return BOLD () + BLUE ()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BOLD_GREEN () :\n"
  "  return BOLD () + GREEN ()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def BOLD_RED () :\n"
  "  return BOLD () + RED ()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   runHiddenCommand                                                                                                   *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def runHiddenCommand (cmd) :\n"
  "  result = \"\"\n"
  "  childProcess = subprocess.Popen (cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)\n"
  "  while True:\n"
  "    line = childProcess.stdout.readline ()\n"
  "    if line != \"\":\n"
  "      result += line\n"
  "    else:\n"
  "      childProcess.wait ()\n"
  "      if childProcess.returncode != 0 :\n"
  "        sys.exit (childProcess.returncode)\n"
  "      return result\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   runSingleCommand                                                                                                   *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def runSingleCommand (cmd) :\n"
  "  cmdAsString = \"\"\n"
  "  for s in cmd:\n"
  "    if (s == \"\") or (s.find (\" \") >= 0):\n"
  "      cmdAsString += '\"' + s + '\" '\n"
  "    else:\n"
  "      cmdAsString += s + ' '\n"
  "  print cmdAsString\n"
  "  childProcess = subprocess.Popen (cmd)\n"
  "  childProcess.wait ()\n"
  "  if childProcess.returncode != 0 :\n"
  "    sys.exit (childProcess.returncode)\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   runCommand                                                                                                         *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def runCommand (cmd, title, showCommand) :\n"
  "  if title != \"\":\n"
  "    print BOLD_BLUE () + title + ENDC ()\n"
  "  if (title == \"\") or showCommand :\n"
  "    cmdAsString = \"\"\n"
  "    for s in cmd:\n"
  "      if (s == \"\") or (s.find (\" \") >= 0):\n"
  "        cmdAsString += '\"' + s + '\" '\n"
  "      else:\n"
  "        cmdAsString += s + ' '\n"
  "    print cmdAsString\n"
  "  childProcess = subprocess.Popen (cmd)\n"
  "  childProcess.wait ()\n"
  "  if childProcess.returncode != 0 :\n"
  "    sys.exit (childProcess.returncode)\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   runInThread                                                                                                        *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def runInThread (job, displayLock, terminationSemaphore):\n"
  "  childProcess = subprocess.Popen (job.mCommand, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)\n"
  "  while True:\n"
  "    line = childProcess.stdout.readline ()\n"
  "    if line != \"\":\n"
  "      displayLock.acquire ()\n"
  "      sys.stdout.write (line) # Print without newline\n"
  "      displayLock.release ()\n"
  "    else:\n"
  "      childProcess.wait ()\n"
  "      job.mReturnCode = childProcess.returncode\n"
  "      terminationSemaphore.release ()\n"
  "      break\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   modificationDateForFile                                                                                            *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def modificationDateForFile (dateCacheDictionary, file):\n"
  "  absFilePath = os.path.abspath (file)\n"
  "  if dateCacheDictionary.has_key (absFilePath) :\n"
  "    return dateCacheDictionary [absFilePath]\n"
  "  elif not os.path.exists (absFilePath):\n"
  "    date = sys.float_info.max # Very far in future\n"
  "    dateCacheDictionary [absFilePath] = date\n"
  "    return date\n"
  "  else:\n"
  "    date = os.path.getmtime (absFilePath)\n"
  "    dateCacheDictionary [absFilePath] = date\n"
  "    return date\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   class PostCommand                                                                                                  *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "class PostCommand:\n"
  "  mCommand = []\n"
  "  mTitle = \"\"\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def __init__ (self, title = \"\"):\n"
  "    self.mCommand = []\n"
  "    self.mTitle = title\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   class Job                                                                                                          *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "class Job:\n"
  "  mTarget = \"\"\n"
  "  mCommand = []\n"
  "  mTitle = \"\"\n"
  "  mRequiredFiles = []\n"
  "  mPostCommands = []\n"
  "  mReturnCode = None\n"
  "  mPriority = 0\n"
  "  mState = 0 # 0: waiting for execution\n"
  "  \n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def __init__ (self, target, requiredFiles, command, postCommands, priority, title):\n"
  "    self.mTarget = copy.deepcopy (target)\n"
  "    self.mCommand = copy.deepcopy (command)\n"
  "    self.mRequiredFiles = copy.deepcopy (requiredFiles)\n"
  "    self.mTitle = copy.deepcopy (title)\n"
  "    self.mPostCommands = copy.deepcopy (postCommands)\n"
  "    self.mPriority = priority\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def run (self, displayLock, terminationSemaphore, showCommand):\n"
  "    displayLock.acquire ()\n"
  "    if self.mTitle != \"\":\n"
  "      print BOLD_BLUE () + self.mTitle + ENDC ()\n"
  "    if (self.mTitle == \"\") or showCommand :\n"
  "      cmdAsString = \"\"\n"
  "      for s in self.mCommand:\n"
  "        if (s == \"\") or (s.find (\" \") >= 0):\n"
  "          cmdAsString += '\"' + s + '\" '\n"
  "        else:\n"
  "          cmdAsString += s + ' '\n"
  "      print cmdAsString\n"
  "    displayLock.release ()\n"
  "    thread = threading.Thread (target=runInThread, args=(self, displayLock, terminationSemaphore))\n"
  "    thread.start()\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def runPostCommand (self, displayLock, terminationSemaphore, showCommand):\n"
  "    postCommand = self.mPostCommands [0]\n"
  "    self.mCommand = postCommand.mCommand\n"
  "    displayLock.acquire ()\n"
  "    print BOLD_BLUE () + postCommand.mTitle + ENDC ()\n"
  "    if showCommand:\n"
  "      cmdAsString = \"\"\n"
  "      for s in self.mCommand:\n"
  "        if (s == \"\") or (s.find (\" \") >= 0):\n"
  "          cmdAsString += '\"' + s + '\" '\n"
  "        else:\n"
  "          cmdAsString += s + ' '\n"
  "      print cmdAsString\n"
  "    displayLock.release ()\n"
  "    thread = threading.Thread (target=runInThread, args=(self, displayLock, terminationSemaphore))\n"
  "    thread.start()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   class Rule                                                                                                         *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "class Rule:\n"
  "  mTarget = \"\"\n"
  "  mDependences = []\n"
  "  mCommand = []\n"
  "  mSecondaryMostRecentModificationDate = 0.0 # Far in the past\n"
  "  mTitle = \"\"\n"
  "  mPostCommands = []\n"
  "  mPriority = 0\n"
  "  \n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def __init__ (self, target, title = \"\"):\n"
  "    self.mTarget = copy.deepcopy (target)\n"
  "    self.mDependences = []\n"
  "    self.mCommand = []\n"
  "    self.mSecondaryMostRecentModificationDate = 0.0\n"
  "    self.mPostCommands = []\n"
  "    self.mPriority = 0\n"
  "    if title == \"\":\n"
  "      self.mTitle = \"Building \" + target\n"
  "    else:\n"
  "      self.mTitle = copy.deepcopy (title)\n"
  "  \n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def enterSecondaryDependanceFile (self, secondaryDependanceFile):\n"
  "    if secondaryDependanceFile != \"\":\n"
  "      filePath = os.path.abspath (secondaryDependanceFile)\n"
  "      if os.path.exists (filePath):\n"
  "        f = open (filePath, \"r\")\n"
  "        s = f.read ().replace (\"\\\\ \", \"\\x01\") # Read and replace escaped spaces by \\0x01\n"
  "        f.close ()\n"
  "        s = s.replace (\"\\\\\\n\", \"\")\n"
  "        liste = s.split (\"\\n\\n\")\n"
  "        dateCacheDictionary = {}\n"
  "        for s in liste:\n"
  "          components = s.split (':')\n"
  "          target = components [0].replace (\"\\x01\", \" \")\n"
  "          #print \"------- Optional dependency rules for target '\" + target + \"'\"\n"
  "          #print \"Secondary target '\" + target + \"'\"\n"
  "          for src in components [1].split ():\n"
  "            secondarySource = src.replace (\"\\x01\", \" \")\n"
  "            #print \"  '\" + secondarySource + \"'\"\n"
  "            modifDate = modificationDateForFile (dateCacheDictionary, secondarySource)\n"
  "            if self.mSecondaryMostRecentModificationDate < modifDate :\n"
  "              self.mSecondaryMostRecentModificationDate = modifDate\n"
  "              #print BOLD_BLUE () + str (modifDate) + ENDC ()\n"
  "    \n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   class Make                                                                                                         *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "class Make:\n"
  "  mRuleList = []\n"
  "  mJobList = []\n"
  "  mErrorCount = 0\n"
  "  mModificationDateDictionary = {}\n"
  "  mGoals = {}\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def addRule (self, rule):\n"
  "    self.mRuleList.append (copy.deepcopy (rule))\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def printRules (self):\n"
  "    print BOLD_BLUE () + \"--- Print the \" + str (len (self.mRuleList)) + \" rule\" + (\"s\" if len (self.mRuleList) > 1 else \"\") + \" ---\" + ENDC ()\n"
  "    for rule in self.mRuleList:\n"
  "      print BOLD_GREEN () + \"Target: '\" + rule.mTarget + \"'\" + ENDC ()\n"
  "      for dep in rule.mDependences:\n"
  "        print \"  Dependence: '\" + dep + \"'\"\n"
  "      s = \"  Command: \"\n"
  "      for cmd in rule.mCommand:\n"
  "        s += \" \\\"\" + cmd + \"\\\"\"\n"
  "      print s\n"
  "      print \"  Title: '\" + rule.mTitle + \"'\"\n"
  "      index = 0\n"
  "      for (command, title) in rule.mPostCommands:\n"
  "        index = index + 1\n"
  "        s = \"  Post command \" + str (index) + \": \"\n"
  "        for cmd in command:\n"
  "          s += \" \\\"\" + cmd + \"\\\"\"\n"
  "        print s\n"
  "        print \"  Its title: '\" + title + \"'\"\n"
  "        \n"
  "    print BOLD_BLUE () + \"--- End of print rule ---\" + ENDC ()\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def writeRuleDependancesInDotFile (self, dotFileName):\n"
  "    s = \"digraph G {\\n\"\n"
  "    s += \"  node [fontname=courier]\\n\"\n"
  "    arrowSet = set ()\n"
  "    for rule in self.mRuleList:\n"
  "      s += '  \"' + rule.mTarget + '\" [shape=rectangle]\\n'\n"
  "      for dep in rule.mDependences:\n"
  "        arrowSet.add ('  \"' + rule.mTarget + '\" -> \"' + dep + '\"\\n')\n"
  "    for arrow in arrowSet:\n"
  "      s += arrow\n"
  "    s += \"}\\n\"\n"
  "    f = open (dotFileName, \"w\")\n"
  "    f.write (s)\n"
  "    f.close ()\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def checkRules (self):\n"
  "    if self.mErrorCount == 0:\n"
  "      ruleList = copy.deepcopy (self.mRuleList)\n"
  "      index = 0\n"
  "      looping = True\n"
  "    #--- loop on rules\n"
  "      while looping:\n"
  "        looping = False\n"
  "        while index < len (ruleList):\n"
  "          aRule = ruleList [index]\n"
  "          index = index + 1\n"
  "        #--- Check dependance files have rule for building, or does exist\n"
  "          depIdx = 0\n"
  "          while depIdx < len (aRule.mDependences):\n"
  "            dep = aRule.mDependences [depIdx]\n"
  "            depIdx = depIdx + 1\n"
  "            hasBuildRule = False\n"
  "            for r in ruleList:\n"
  "              if dep == r.mTarget:\n"
  "                hasBuildRule = True\n"
  "                break\n"
  "            if not hasBuildRule:\n"
  "              looping = True\n"
  "              if not os.path.exists (os.path.abspath (dep)):\n"
  "                self.mErrorCount = self.mErrorCount + 1\n"
  "                print BOLD_RED () + \"Check rules error: '\" + dep + \"' does not exist, and there is no rule for building it.\" + ENDC ()\n"
  "              depIdx = depIdx - 1\n"
  "              aRule.mDependences.pop (depIdx)\n"
  "        #--- Rule with no dependances\n"
  "          if len (aRule.mDependences) == 0 :\n"
  "            looping = True\n"
  "            index = index - 1\n"
  "            ruleList.pop (index)\n"
  "            idx = 0\n"
  "            while idx < len (ruleList):\n"
  "              r = ruleList [idx]\n"
  "              idx = idx + 1\n"
  "              while r.mDependences.count (aRule.mTarget) > 0 :\n"
  "                r.mDependences.remove (aRule.mTarget)\n"
  "    #--- Error if rules remain\n"
  "      if len (ruleList) > 0:\n"
  "        self.mErrorCount = self.mErrorCount + 1\n"
  "        print BOLD_RED () + \"Check rules error; circulary dependances between:\" + ENDC ()\n"
  "        for aRule in ruleList: \n"
  "          print BOLD_RED () + \"  - '\" + aRule.mTarget + \"', depends from:\" + ENDC ()\n"
  "          for dep in aRule.mDependences:\n"
  "            print BOLD_RED () + \"      '\" + dep + \"'\" + ENDC ()\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def existsJobForTarget (self, target):\n"
  "    for job in self.mJobList:\n"
  "      if job.mTarget == target:\n"
  "        return True\n"
  "    return False\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def makeJob (self, target): # Return a bool indicating wheither the target should be built\n"
  "  #--- If there are errors, return immediatly\n"
  "    if self.mErrorCount != 0:\n"
  "      return False\n"
  "  #--- Target already in job list \?\n"
  "    if self.existsJobForTarget (target):\n"
  "      return True # yes, return target will be built\n"
  "  #--- Find a rule for making the target\n"
  "    absTarget = os.path.abspath (target)\n"
  "    rule = None\n"
  "    matchCount = 0\n"
  "    for r in self.mRuleList:\n"
  "      if target == r.mTarget:\n"
  "        matchCount = matchCount + 1\n"
  "        rule = r\n"
  "    if matchCount == 0:\n"
  "      absTarget = os.path.abspath (target)\n"
  "      if not os.path.exists (absTarget):\n"
  "        print BOLD_RED () + \"No rule for making '\" + target + \"'\" + ENDC ()\n"
  "        self.mErrorCount = self.mErrorCount + 1\n"
  "      return False # Error or target exists, and no rule for building it\n"
  "    elif matchCount > 1:\n"
  "      print BOLD_RED () + str (matchCount) + \" rules for making '\" + target + \"'\" + ENDC ()\n"
  "      self.mErrorCount = self.mErrorCount + 1\n"
  "      return False # Error\n"
  "  #--- Target file does not exist, and 'rule' variable indicates how build it\n"
  "    appendToJobList = not os.path.exists (absTarget)\n"
  "  #--- Build primary dependences\n"
  "    jobDependenceFiles = []\n"
  "    for dependence in rule.mDependences:\n"
  "      willBeBuilt = self.makeJob (dependence)\n"
  "      if willBeBuilt:\n"
  "        jobDependenceFiles.append (dependence)\n"
  "        appendToJobList = True\n"
  "  #--- Check primary file modification dates\n"
  "    if not appendToJobList:\n"
  "      targetDateModification = os.path.getmtime (absTarget)\n"
  "      for source in rule.mDependences:\n"
  "        sourceDateModification = os.path.getmtime (source)\n"
  "        if targetDateModification < sourceDateModification:\n"
  "          appendToJobList = True\n"
  "          break\n"
  "  #--- Check for secondary dependancy files\n"
  "    if not appendToJobList:\n"
  "      targetDateModification = os.path.getmtime (absTarget)\n"
  "      if targetDateModification < rule.mSecondaryMostRecentModificationDate:\n"
  "        appendToJobList = True\n"
  "  #--- Append to job list\n"
  "    if appendToJobList:\n"
  "      self.mJobList.append (Job (target, jobDependenceFiles, rule.mCommand, rule.mPostCommands, rule.mPriority, rule.mTitle))\n"
  "  #--- Return\n"
  "    return appendToJobList\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "  #Job state\n"
  "  # 0: waiting\n"
  "  # 1:running\n"
  "  # 2: waiting for executing post command\n"
  "  # 3:executing for executing post command\n"
  "  # 4: completed\n"
  "\n"
  "  def runJobs (self, maxConcurrentJobs, showCommand):\n"
  "    if self.mErrorCount == 0:\n"
  "      if len (self.mJobList) == 0:\n"
  "        print BOLD_BLUE () + \"Nothing to make.\" + ENDC ()\n"
  "      else:\n"
  "      #--- Sort jobs following their priorities\n"
  "        self.mJobList = sorted (self.mJobList, key=operator.attrgetter(\"mPriority\"), reverse=True)\n"
  "      #--- Run\n"
  "        if maxConcurrentJobs <= 0:\n"
  "          maxConcurrentJobs = processorCount () - maxConcurrentJobs\n"
  "        jobCount = 0 ;\n"
  "        terminationSemaphore = threading.Semaphore (0)\n"
  "        displayLock = threading.Lock ()\n"
  "        loop = True\n"
  "        returnCode = 0\n"
  "        while loop:\n"
  "        #--- Launch jobs in parallel\n"
  "          for job in self.mJobList:\n"
  "            if (returnCode == 0) and (jobCount < maxConcurrentJobs):\n"
  "              if (job.mState == 0) and (len (job.mRequiredFiles) == 0):\n"
  "                #--- Create target directory if does not exist\n"
  "                absTargetDirectory = os.path.dirname (os.path.abspath (job.mTarget))\n"
  "                if not os.path.exists (absTargetDirectory):\n"
  "                  displayLock.acquire ()\n"
  "                  runCommand ([\"mkdir\", \"-p\", absTargetDirectory], \"Making \" + absTargetDirectory + \" directory\", showCommand)\n"
  "                  displayLock.release ()\n"
  "                #--- Run job\n"
  "                job.run (displayLock, terminationSemaphore, showCommand)\n"
  "                jobCount = jobCount + 1\n"
  "                job.mState = 1 # Means is running\n"
  "              elif job.mState == 2: # Waiting for executing post command\n"
  "                job.mReturnCode = None # Means post command not terminated\n"
  "                job.runPostCommand (displayLock, terminationSemaphore, showCommand)\n"
  "                jobCount = jobCount + 1\n"
  "                job.mState = 3 # Means post command is running\n"
  "        #--- Wait for a job termination\n"
  "          #print \"wait \" + str (jobCount) + \" \" + str (len (self.mJobList))\n"
  "          terminationSemaphore.acquire ()\n"
  "        #--- Checks for terminated jobs\n"
  "          index = 0\n"
  "          while index < len (self.mJobList):\n"
  "            job = self.mJobList [index]\n"
  "            index = index + 1\n"
  "            if (job.mState == 1) and (job.mReturnCode == 0) : # Terminated without error\n"
  "              jobCount = jobCount - 1\n"
  "              if len (job.mPostCommands) > 0:\n"
  "                job.mState = 2 # Ready to execute next post command\n"
  "              else:\n"
  "                job.mState = 4 # Completed\n"
  "                index = index - 1 # For removing job from list\n"
  "            elif (job.mState == 1) and (job.mReturnCode > 0) : # terminated with error : exit\n"
  "              jobCount = jobCount - 1\n"
  "              job.mState = 4 # Means Terminated\n"
  "              index = index - 1 # For removing job from list\n"
  "            elif (job.mState == 3) and (job.mReturnCode == 0): # post command is terminated without error\n"
  "              jobCount = jobCount - 1\n"
  "              job.mPostCommands.pop (0) # Remove completed post command\n"
  "              if len (job.mPostCommands) > 0:\n"
  "                job.mState = 2 # Ready to execute next post command\n"
  "              else:\n"
  "                job.mState = 4 # Completed\n"
  "                index = index - 1 # For removing job from list\n"
  "            elif (job.mState == 3) and (job.mReturnCode > 0): # post command is terminated with error\n"
  "              jobCount = jobCount - 1\n"
  "              job.mState = 4 # Completed\n"
  "              index = index - 1 # For removing job from list\n"
  "            elif job.mState == 4: # Completed: delete job\n"
  "              index = index - 1\n"
  "              self.mJobList.pop (index) # Remove terminated job\n"
  "              #displayLock.acquire ()\n"
  "              #print \"Completed '\" + job.mTitle + \"'\"\n"
  "              #--- Remove dependences from this job\n"
  "              idx = 0\n"
  "              while idx < len (self.mJobList):\n"
  "                aJob = self.mJobList [idx]\n"
  "                idx = idx + 1\n"
  "                while aJob.mRequiredFiles.count (job.mTarget) > 0 :\n"
  "                  aJob.mRequiredFiles.remove (job.mTarget)\n"
  "                  #print \"  Removed from '\" + aJob.mTitle + \"': \" + str (len (aJob.mRequiredFiles))\n"
  "              #displayLock.release ()\n"
  "              #--- Signal error \?\n"
  "              if (job.mReturnCode > 0) and (returnCode == 0):\n"
  "                self.mErrorCount = self.mErrorCount + 1\n"
  "                print BOLD_RED () + \"Return code: \" + str (job.mReturnCode) + ENDC ()\n"
  "                if (returnCode == 0) and (jobCount > 0) :\n"
  "                  print \"Wait for job termination...\"\n"
  "                returnCode = job.mReturnCode\n"
  "          loop = (len (self.mJobList) > 0) if (returnCode == 0) else (jobCount > 0)\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def searchFileInDirectories (self, file, directoryList): # returns \"\" if not found, register error\n"
  "    matchCount = 0\n"
  "    result = \"\"\n"
  "    for sourceDir in directoryList:\n"
  "      sourcePath = sourceDir + \"/\" + file\n"
  "      if os.path.exists (os.path.abspath (sourcePath)):\n"
  "        matchCount = matchCount + 1\n"
  "        result = sourcePath\n"
  "    if matchCount == 0:\n"
  "      print BOLD_RED () + \"Cannot find '\" + file + \"'\" + ENDC ()\n"
  "      self.mErrorCount = self.mErrorCount + 1\n"
  "    elif matchCount > 1:\n"
  "      print BOLD_RED () + str (matchCount) + \" source files for making '\" + file + \"'\" + ENDC ()\n"
  "      self.mErrorCount = self.mErrorCount + 1\n"
  "      result = \"\"\n"
  "    return result\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def addGoal (self, goal, targetList, message):\n"
  "    self.mGoals [goal] = (targetList, message)\n"
  "    #print '%s' % ', '.join(map(str, self.mGoals))\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def printGoals (self):\n"
  "    print BOLD_BLUE () + \"--- Print the \" + str (len (self.mGoals)) + \" goal\" + (\"s\" if len (self.mGoals) > 1 else \"\") + \" ---\" + ENDC ()\n"
  "    for goalKey in self.mGoals.keys ():\n"
  "      print BOLD_GREEN () + \"Goal: '\" + goalKey + \"'\" + ENDC ()\n"
  "      (targetList, message) = self.mGoals [goalKey]\n"
  "      for target in targetList:\n"
  "        print \"  Target: '\" + target + \"'\"\n"
  "      print \"  Message: '\" + message + \"'\"\n"
  "        \n"
  "    print BOLD_BLUE () + \"--- End of print goals ---\" + ENDC ()\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def runGoal (self, goal, maxConcurrentJobs, showCommand):\n"
  "    if self.mGoals.has_key (goal) :\n"
  "      (targetList, message) = self.mGoals [goal]\n"
  "      for target in targetList:\n"
  "        self.makeJob (target)\n"
  "      self.runJobs (maxConcurrentJobs, showCommand)\n"
  "    else:\n"
  "      errorMessage = \"The '\" + goal + \"' goal is not defined; defined goals:\"\n"
  "      for key in self.mGoals:\n"
  "        (targetList, message) = self.mGoals [key]\n"
  "        errorMessage += \"\\n  '\" + key + \"': \" + message\n"
  "      print BOLD_RED () + errorMessage + ENDC ()\n"
  "      self.mErrorCount = self.mErrorCount + 1\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def enterError (self, message):\n"
  "    print BOLD_RED () + message + ENDC ()\n"
  "    self.mErrorCount = self.mErrorCount + 1\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def printErrorCountAndExitOnError (self):\n"
  "    if self.mErrorCount == 1:\n"
  "      print BOLD_RED () + \"1 error.\" + ENDC ()\n"
  "      sys.exit (1)\n"
  "    elif self.mErrorCount > 1:\n"
  "      print BOLD_RED () + str (self.mErrorCount) + \" errors.\" + ENDC ()\n"
  "      sys.exit (1)\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def printErrorCount (self):\n"
  "    if self.mErrorCount == 1:\n"
  "      print BOLD_RED () + \"1 error.\" + ENDC ()\n"
  "    elif self.mErrorCount > 1:\n"
  "      print BOLD_RED () + str (self.mErrorCount) + \" errors.\" + ENDC ()\n"
  "\n"
  "  #--------------------------------------------------------------------------*\n"
  "\n"
  "  def errorCount (self):\n"
  "    return self.mErrorCount\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Source files                                                                                                       *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def sourceList ():\n"
  "  return [\"plm.c\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Product directory                                                                                                  *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def productDir ():\n"
  "  return \"product\"\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#                         Object files directories                                                                     *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def objectDir ():\n"
  "  return \"objects\"\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#                         Object files directories                                                                     *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def asDir ():\n"
  "  return \"as\"\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Tool dir                                                                                                           *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def toolDir ():\n"
  "  (SYSTEM_NAME, MODE_NAME, RELEASE, VERSION, MACHINE) = os.uname ()\n"
  "  if SYSTEM_NAME == \"Darwin\":\n"
  "    MACHINE = \"i386\"\n"
  "  return os.path.expanduser (\"~/plm-tools/plm-\" + SYSTEM_NAME + \"-\" + MACHINE + \"-binutils-2.25-gcc-5.2.0-newlib-2.2.0.20150623-libusb-1.0.19\")\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Compiler invocation                                                                                                *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def compiler ():\n"
  "  return [toolDir () + \"/bin/arm-eabi-gcc\", \"-mthumb\", \"-mcpu=cortex-m4\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Display object size invocation                                                                                     *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def displayObjectSize ():\n"
  "  return [toolDir () + \"/bin/arm-eabi-size\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Object Dump invocation                                                                                             *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def dumpObjectCode ():\n"
  "  return [toolDir () + \"/bin/arm-eabi-objdump\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#    C Compiler options                                                                                                *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def cCompilerOptions ():\n"
  "  result = []\n"
  "  result.append (\"-Wall\")\n"
  "  result.append (\"-Werror\")\n"
  "  result.append (\"-Wreturn-type\")\n"
  "  result.append (\"-Wformat\")\n"
  "  result.append (\"-Wsign-compare\")\n"
  "  result.append (\"-Wpointer-arith\")\n"
  "  result.append (\"-Wparentheses\")\n"
  "  result.append (\"-Wcast-align\")\n"
  "  result.append (\"-Wcast-qual\")\n"
  "  result.append (\"-Wwrite-strings\")\n"
  "  result.append (\"-Wswitch\")\n"
  "  result.append (\"-Wuninitialized\")\n"
  "  result.append (\"-fno-builtin\")\n"
  "  result.append (\"-Wno-aggressive-loop-optimizations\")\n"
  "  result.append (\"-ffunction-sections\")\n"
  "  result.append (\"-fdata-sections\")\n"
  "  result.append (\"-std=c99\")\n"
  "  result.append (\"-Wstrict-prototypes\")\n"
  "  result.append (\"-Wbad-function-cast\")\n"
  "  result.append (\"-Wmissing-declarations\")\n"
  "  result.append (\"-Wimplicit-function-declaration\")\n"
  "  result.append (\"-Wno-int-to-pointer-cast\")\n"
  "  result.append (\"-Wno-pointer-to-int-cast\")\n"
  "  result.append (\"-Wmissing-prototypes\")\n"
  "  result.append (\"-Os\")\n"
  "  result.append (\"-fomit-frame-pointer\")\n"
  "  result.append (\"-foptimize-register-move\") \n"
  "  result.append (\"-I../build\")\n"
  "  return result\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Linker invocation                                                                                                  *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def linker ():\n"
  "  return [toolDir () + \"/bin/arm-eabi-gcc\", \"-mthumb\", \"-mcpu=cortex-m4\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Linker options                                                                                                     *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def linkerOptions ():\n"
  "  result = []\n"
  "  result.append (\"-nostartfiles\")\n"
  "  result.append (\"-Wl,--fatal-warnings\")\n"
  "  result.append (\"-Wl,--warn-common\")\n"
  "  result.append (\"-Wl,--no-undefined\")\n"
  "  result.append (\"-Wl,--cref\")\n"
  "  result.append (\"-lc\")\n"
  "  result.append (\"-lgcc\")\n"
  "  result.append (\"-Wl,-static\")\n"
  "  result.append (\"-Wl,-s\")\n"
  "  result.append (\"-Wl,--gc-sections\")\n"
  "  return result\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   objcopy invocation                                                                                                 *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def objcopy ():\n"
  "  return [toolDir () + \"/bin/arm-eabi-objcopy\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Teensy loader                                                                                                      *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def teensyLoader ():\n"
  "  return toolDir () + \"/bin/teensy-loader-cli\"\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#   ARCHIVE DOWNLOAD                                                                                                   *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def downloadReportHook (a,b,fileSize): \n"
  "  if fileSize < (1 << 10):\n"
  "    sizeString = str (fileSize)\n"
  "  else:\n"
  "    if fileSize < (1 << 20):\n"
  "      sizeString = str (fileSize >> 10) + \"Ki\"\n"
  "    else:\n"
  "      sizeString = str (fileSize >> 20) + \"Mi\"\n"
  "  # \",\" at the end of the line is important!\n"
  "  print \"% 3.1f%% of %sB\\r\" % (min(100.0, float(a * b) / fileSize * 100.0), sizeString),\n"
  "  sys.stdout.flush()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def downloadArchive (archiveURL, archivePath):\n"
  "  runSingleCommand ([\"rm\", \"-f\", archivePath + \".downloading\"])\n"
  "  runSingleCommand ([\"rm\", \"-f\", archivePath + \".tar.bz2\"])\n"
  "  runSingleCommand ([\"mkdir\", \"-p\", os.path.dirname (archivePath)])\n"
  "  print \"URL: \"+ archiveURL\n"
  "  print \"Downloading... \" + archivePath + \".downloading\"\n"
  "  urllib.urlretrieve (archiveURL,  archivePath + \".downloading\", downloadReportHook)\n"
  "  print \"\"\n"
  "  fileSize = os.path.getsize (archivePath + \".downloading\")\n"
  "  ok = fileSize > 1000000\n"
  "  if ok:\n"
  "    runSingleCommand ([\"mv\", archivePath + \".downloading\", archivePath + \".tar.bz2\"])\n"
  "  else:\n"
  "    print BOLD_RED () + \"Error: cannot download file\" + ENDC ()\n"
  "    sys.exit (1)\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   MAIN                                                                                                               *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "#--- Get max parallel jobs as first argument\n"
  "goal = \"all\"\n"
  "if len (sys.argv) > 1 :\n"
  "  goal = sys.argv [1]\n"
  "#--- Get max parallel jobs as first argument\n"
  "maxParallelJobs = 0 # 0 means use host processor count\n"
  "if len (sys.argv) > 2 :\n"
  "  maxParallelJobs = int (sys.argv [2])\n"
  "#--- Get script absolute path\n"
  "scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))\n"
  "#--- Download compiler tool if needed\n"
  "toolDirectory = toolDir ()\n"
  "if not os.path.exists (toolDirectory):\n"
  "  print BOLD_GREEN () + \"Downloading compiler tool chain\" + ENDC ()\n"
  "  archiveName = os.path.basename (toolDirectory)\n"
  "  archiveURL = \"http://crossgcc.rts-software.org/downloads/plm-tools/\" + archiveName + \".tar.bz2\"\n"
  "  downloadArchive (archiveURL, toolDirectory)\n"
  "  installDir = os.path.normpath (toolDirectory + \"/..\")\n"
  "  os.chdir (installDir)\n"
  "  runSingleCommand ([\"bunzip2\", \"-k\", archiveName + \".tar.bz2\"])\n"
  "  runSingleCommand ([\"rm\", archiveName + \".tar.bz2\"])\n"
  "  runSingleCommand ([\"tar\", \"xf\", archiveName + \".tar\"])\n"
  "  runSingleCommand ([\"rm\", archiveName + \".tar\"])\n"
  "#---\n"
  "os.chdir (scriptDir)\n"
  "#--- Build python makefile\n"
  "makefile = Make ()\n"
  "#--- Add C files compile rule\n"
  "objectList = []\n"
  "asObjectList = []\n"
  "for source in sourceList ():\n"
  "#--- Compile\n"
  "  object = objectDir () + \"/\" + source + \".o\"\n"
  "  rule = Rule (object, \"Compiling \" + source)\n"
  "  rule.mDependences.append (\"sources/\" + source)\n"
  "  rule.mCommand += compiler ()\n"
  "  rule.mCommand += cCompilerOptions ()\n"
  "  rule.mCommand += [\"-c\", \"sources/\" + source]\n"
  "  rule.mCommand += [\"-o\", object]\n"
  "  rule.enterSecondaryDependanceFile (object + \".dep\")\n"
  "  makefile.addRule (rule)\n"
  "  objectList.append (object)\n"
  "#--- Assembling\n"
  "  asObject = asDir () + \"/\" + source + \".s\"\n"
  "  rule = Rule (asObject, \"Assembling \" + source)\n"
  "  rule.mDependences.append (\"sources/\" + source)\n"
  "  rule.mCommand += compiler ()\n"
  "  rule.mCommand += cCompilerOptions ()\n"
  "  rule.mCommand += [\"-S\", \"sources/\" + source]\n"
  "  rule.mCommand += [\"-o\", asObject]\n"
  "  rule.enterSecondaryDependanceFile (asObject + \".dep\")\n"
  "  makefile.addRule (rule)\n"
  "  asObjectList.append (asObject)\n"
  "#--- Add linker rule\n"
  "productELF = productDir () + \"/product.elf\"\n"
  "rule = Rule (productELF, \"Linking \" + productELF)\n"
  "rule.mDependences += objectList\n"
  "rule.mCommand += linker ()\n"
  "rule.mCommand += linkerOptions ()\n"
  "rule.mCommand += objectList\n"
  "rule.mCommand += [\"-o\", productELF]\n"
  "rule.mCommand += [\"-Tsources/linker.ld\"]\n"
  "rule.mCommand += [\"-Wl,-Map=\" + productELF + \".map\"]\n"
  "makefile.addRule (rule)\n"
  "#--- Add objcopy rule\n"
  "productHEX = productDir () + \"/product.ihex\"\n"
  "rule = Rule (productHEX, \"Hexing \" + productHEX)\n"
  "rule.mDependences += [productELF]\n"
  "rule.mCommand += objcopy ()\n"
  "rule.mCommand += [\"-O\", \"ihex\"]\n"
  "rule.mCommand += [productELF]\n"
  "rule.mCommand += [productHEX]\n"
  "makefile.addRule (rule)\n"
  "#--- Add goals\n"
  "makefile.addGoal (\"run\", [productHEX], \"Building all and run\")\n"
  "makefile.addGoal (\"all\", [productHEX], \"Building all\")\n"
  "makefile.addGoal (\"as\", asObjectList, \"Assembling C files\")\n"
  "makefile.addGoal (\"display-object-size\", [productHEX], \"Display Object Size\")\n"
  "makefile.addGoal (\"object-dump\", [productHEX], \"Dump Object Code\")\n"
  "#--- Build\n"
  "#makefile.printRules ()\n"
  "makefile.runGoal (goal, maxParallelJobs, maxParallelJobs == 1)\n"
  "#--- Build Ok \?\n"
  "makefile.printErrorCountAndExitOnError ()\n"
  "#--- Run \?\n"
  "if goal == \"run\":\n"
  "  print BOLD_BLUE () + \"Loading Teensy...\" + ENDC ()\n"
  "  childProcess = subprocess.Popen ([teensyLoader (), \"-w\", \"-v\", \"-mmcu=mk20dx128\", productHEX])\n"
  "#--- Wait for subprocess termination\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.wait ()\n"
  "  if childProcess.returncode != 0 :\n"
  "    print BOLD_RED () + \"Error \" + str (childProcess.returncode) + ENDC ()\n"
  "    sys.exit (childProcess.returncode)\n"
  "  else:\n"
  "    print BOLD_GREEN () + \"Success\" + ENDC ()\n"
  "elif goal == \"display-object-size\":\n"
  "  print BOLD_BLUE () + \"Display Object Sizes\" + ENDC ()\n"
  "  childProcess = subprocess.Popen (displayObjectSize () + objectList + [\"-t\"])\n"
  "#--- Wait for subprocess termination\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.wait ()\n"
  "  if childProcess.returncode != 0 :\n"
  "    print BOLD_RED () + \"Error \" + str (childProcess.returncode) + ENDC ()\n"
  "    sys.exit (childProcess.returncode)\n"
  "  else:\n"
  "    print BOLD_GREEN () + \"Success\" + ENDC ()\n"
  "elif goal == \"object-dump\":\n"
  "  print BOLD_BLUE () + \"Dump Object Code\" + ENDC ()\n"
  "  childProcess = subprocess.Popen (dumpObjectCode () + [productELF, \"-Sdh\", \"-Mforce-thumb\"])\n"
  "#--- Wait for subprocess termination\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.wait ()\n"
  "  if childProcess.returncode != 0 :\n"
  "    print BOLD_RED () + \"Error \" + str (childProcess.returncode) + ENDC ()\n"
  "    sys.exit (childProcess.returncode)\n"
  "  else:\n"
  "    print BOLD_GREEN () + \"Success\" + ENDC ()\n" ;

const cRegularFileWrapper gWrapperFile_10_embeddedTargets (
  "build.py",
  "py",
  true, // Text file
  44330, // Text length
  gWrapperFileContent_10_embeddedTargets
) ;

//--- File 'teensy-3-1-interrupt/clean.py'

const char * gWrapperFileContent_11_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import subprocess\n"
  "import sys\n"
  "import os\n"
  "import atexit\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def cleanup():\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.kill ()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "#--- Register a function for killing subprocess\n"
  "atexit.register (cleanup)\n"
  "#--- Get script absolute path\n"
  "scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))\n"
  "#--- Directories to clean\n"
  "dir1 = scriptDir + \"/objects\"\n"
  "dir2 = scriptDir + \"/product\"\n"
  "dir3 = scriptDir + \"/as\"\n"
  "#---\n"
  "childProcess = subprocess.Popen ([\"rm\", \"-fr\", dir1, dir2, dir3], cwd=scriptDir)\n"
  "#--- Wait for subprocess termination\n"
  "if childProcess.poll () == None :\n"
  "  childProcess.wait ()\n"
  "if childProcess.returncode != 0 :\n"
  "  sys.exit (childProcess.returncode)\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_11_embeddedTargets (
  "clean.py",
  "py",
  true, // Text file
  1264, // Text length
  gWrapperFileContent_11_embeddedTargets
) ;

//--- File 'teensy-3-1-interrupt/display-obj-dump.py'

const char * gWrapperFileContent_12_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import subprocess\n"
  "import sys\n"
  "import os\n"
  "import atexit\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "def cleanup():\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.kill ()\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "#--- Register a function for killing subprocess\n"
  "atexit.register (cleanup)\n"
  "#--- Get script absolute path\n"
  "scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))\n"
  "os.chdir (scriptDir)\n"
  "#---\n"
  "childProcess = subprocess.Popen ([\"python\", \"build.py\", \"object-dump\"])\n"
  "#--- Wait for subprocess termination\n"
  "if childProcess.poll () == None :\n"
  "  childProcess.wait ()\n"
  "if childProcess.returncode != 0 :\n"
  "  sys.exit (childProcess.returncode)\n"
  "\n"
  "#------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_12_embeddedTargets (
  "display-obj-dump.py",
  "py",
  true, // Text file
  1005, // Text length
  gWrapperFileContent_12_embeddedTargets
) ;

//--- File 'teensy-3-1-interrupt/display-obj-size.py'

const char * gWrapperFileContent_13_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import subprocess\n"
  "import sys\n"
  "import os\n"
  "import atexit\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "def cleanup():\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.kill ()\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "#--- Register a function for killing subprocess\n"
  "atexit.register (cleanup)\n"
  "#--- Get script absolute path\n"
  "scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))\n"
  "os.chdir (scriptDir)\n"
  "#---\n"
  "childProcess = subprocess.Popen ([\"python\", \"build.py\", \"display-object-size\"])\n"
  "#--- Wait for subprocess termination\n"
  "if childProcess.poll () == None :\n"
  "  childProcess.wait ()\n"
  "if childProcess.returncode != 0 :\n"
  "  sys.exit (childProcess.returncode)\n"
  "\n"
  "#------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_13_embeddedTargets (
  "display-obj-size.py",
  "py",
  true, // Text file
  1013, // Text length
  gWrapperFileContent_13_embeddedTargets
) ;

//--- File 'teensy-3-1-interrupt/run.py'

const char * gWrapperFileContent_14_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import subprocess\n"
  "import sys\n"
  "import os\n"
  "import atexit\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "def cleanup():\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.kill ()\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "#--- Register a function for killing subprocess\n"
  "atexit.register (cleanup)\n"
  "#--- Get script absolute path\n"
  "scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))\n"
  "os.chdir (scriptDir)\n"
  "#---\n"
  "childProcess = subprocess.Popen ([\"python\", \"build.py\", \"run\"])\n"
  "#--- Wait for subprocess termination\n"
  "if childProcess.poll () == None :\n"
  "  childProcess.wait ()\n"
  "if childProcess.returncode != 0 :\n"
  "  sys.exit (childProcess.returncode)\n"
  "\n"
  "#------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_14_embeddedTargets (
  "run.py",
  "py",
  true, // Text file
  997, // Text length
  gWrapperFileContent_14_embeddedTargets
) ;

//--- File 'sources/linker.ld'

const char * gWrapperFileContent_15_embeddedTargets = "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                                   Memory                                   */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "MEMORY {\n"
  "  flash (rx) : ORIGIN = 0, LENGTH = 256k \n"
  "  sram_u (rwx) : ORIGIN = 0x20000000, LENGTH = 32k \n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "__sram_u_end = 0x20000000 + 32k ;\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                                ISR Vectors                                 */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "SECTIONS {\n"
  "  .vectors : {\n"
  "    __vectors_start = . ;\n"
  "    KEEP (*(.isr_vector)) ;\n"
  "    __vectors_end = . ;\n"
  "  } > flash\n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                                    Code                                    */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "SECTIONS {\n"
  "  .text : {\n"
  "    FILL(0xff)\n"
  "    __code_start = . ;\n"
  "  /*--- Tableau des routines d'initialisation */\n"
  "    . = ALIGN (4) ;\n"
  "    __init_routine_array_start = . ;\n"
  "    KEEP (*(init_routine_array)) ;\n"
  "    . = ALIGN (4) ;\n"
  "    __init_routine_array_end = . ;\n"
  "  /*--- Initialisation des objets globaux C++ */\n"
  "    . = ALIGN (4) ;\n"
  "    __constructor_array_start = . ;\n"
  "    KEEP (*(.init_array)) ;\n"
  "    . = ALIGN (4) ;\n"
  "    __constructor_array_end = . ;\n"
  "  /*--- Real Interrupt Service Routine Array */\n"
  "    . = ALIGN (4) ;\n"
  "    __real_time_isr_array_start = . ;\n"
  "    KEEP (*(real_time_isr_array)) ;\n"
  "    . = ALIGN (4) ;\n"
  "    __real_time_isr_array_end = . ;\n"
  "  /*--- Code */\n"
  "    *(.text.*) ;\n"
  "    *(.text) ;\n"
  "    *(text) ;\n"
  "    *(.gnu.linkonce.t.*) ;\n"
  "  /*---- ROM data ----*/\n"
  "    . = ALIGN(4);\n"
  "    *(.rodata);\n"
  "    . = ALIGN(4);\n"
  "    *(.rodata*);\n"
  "    . = ALIGN(4);\n"
  "    *(.gnu.linkonce.r.*);\n"
  "    . = ALIGN(4);\n"
  "    *(.glue_7t);\n"
  "    . = ALIGN(4);\n"
  "    *(.glue_7);\n"
  "    . = ALIGN(4);\n"
  "  } > flash\n"
  "\n"
  "  .ARM.exidx : {\n"
  "    *(.ARM.exidx* .gnu.linkonce.armexidx.*);\n"
  "    __code_end = . ;\n"
  "  } > flash\n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                          Data (initialized data)                           */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "SECTIONS {\n"
  "  .data : {\n"
  "    FILL (0xFF)\n"
  "    . = ALIGN (4) ;\n"
  "    __data_start = . ;\n"
  "    * (.data.*init*) ;\n"
  "    * (.data*) ;\n"
  "    . = ALIGN (4) ;\n"
  "    __data_end = . ;\n"
  "  } > sram_u AT > flash\n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "__data_load_start = LOADADDR (.data) ;\n"
  "__data_load_end   = LOADADDR (.data) + SIZEOF (.data) ;\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                          BSS (uninitialized data)                          */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "SECTIONS {\n"
  "  .bss : {\n"
  "    . = ALIGN(4);\n"
  "    __bss_start = . ;\n"
  "    * (.bss.*) ;\n"
  "    * (.bss) ;\n"
  "    * (COMMON) ;\n"
  "    . = ALIGN(4);\n"
  "    __bss_end = . ;\n"
  "  } > sram_u\n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                                System stack                                */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "SECTIONS {\n"
  "  .system_stack :{\n"
  "    . = ALIGN (4) ;\n"
  "    __system_stack_start = . ;\n"
  "    . += 1k ;\n"
  "    . = ALIGN (4) ;\n"
  "    __system_stack_end = . ;\n"
  "  } > sram_u\n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                                    Heap                                    */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "SECTIONS {\n"
  "  .heap : {\n"
  "    . = ALIGN (4) ;\n"
  "    __heap_start = . ;\n"
  "  } > sram_u\n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "__heap_end = __sram_u_end ;\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n" ;

const cRegularFileWrapper gWrapperFile_15_embeddedTargets (
  "linker.ld",
  "ld",
  true, // Text file
  5218, // Text length
  gWrapperFileContent_15_embeddedTargets
) ;

//--- File 'sources/target-exception.c'

const char * gWrapperFileContent_16_embeddedTargets = "//---------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "static void raise_exception (const type_int32 inCode,\n"
  "                             const char * inSourceFile,\n"
  "                             const type_uint32 inSourceLine) {\n"
  " //--- Mask interrupt: write 1 into FAULTMASK register\n"
  "  const uint32_t maskValue = 1 ;\n"
  "  __asm__ (\"msr FAULTMASK, %[reg]\" : : [reg]\"r\"(maskValue));\n"
  "  raise_exception_internal (inCode, inSourceFile, inSourceLine) ;\n"
  "}\n"
  "\n"
  "//---------------------------------------------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_16_embeddedTargets (
  "target-exception.c",
  "c",
  true, // Text file
  634, // Text length
  gWrapperFileContent_16_embeddedTargets
) ;

//--- File 'sources/target.c'

const char * gWrapperFileContent_17_embeddedTargets = "//---------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "static void ResetISR (void) {\n"
  "//---------1- Boot routines\n"
  "  boot () ;\n"
  "  // now we're in PEE mode\n"
  "  // configure USB for 48 MHz clock\n"
  "//  SIM_CLKDIV2 = SIM_CLKDIV2_USBDIV(1); // USB = 96 MHz PLL / 2\n"
  "  // USB uses PLL clock, trace is CPU clock, CLKOUT=OSCERCLK0\n"
  "//  SIM_SOPT2 = SIM_SOPT2_USBSRC | SIM_SOPT2_PLLFLLSEL | SIM_SOPT2_TRACECLKSEL | SIM_SOPT2_CLKOUTSEL(6);\n"
  "\n"
  "//---------2- Initialisation de la section .bss\n"
  "  extern unsigned __bss_start ;\n"
  "  extern unsigned __bss_end ;\n"
  "  unsigned * p = & __bss_start ;\n"
  "  while (p != & __bss_end) {\n"
  "    * p = 0 ;\n"
  "    p ++ ;\n"
  "  }\n"
  "//---------3- Copy de la section .data\n"
  "  extern unsigned __data_start ;\n"
  "  extern unsigned __data_end ;\n"
  "  extern unsigned __data_load_start ;\n"
  "  unsigned * pSrc = & __data_load_start ;\n"
  "  unsigned * pDest = & __data_start ;\n"
  "  while (pDest != & __data_end) {\n"
  "    * pDest = * pSrc ;\n"
  "    pDest ++ ;\n"
  "    pSrc ++ ;\n"
  "  }\n"
  "//---------4- Init Routines\n"
  "  init () ;\n"
  "//---------5- User routines\n"
  "  proc_setup () ;\n"
  "  while (1) {\n"
  "    proc_loop () ;\n"
  "  }\n"
  "}\n"
  "\n"
  "//---------------------------------------------------------------------------------------------------------------------*\n"
  "//   Vector table                                                                                                      *\n"
  "//---------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "typedef struct {\n"
  "  unsigned * mStackPointer ;\n"
  "//--- ARM Core System Handler Vectors\n"
  "  void (* mCoreSystemHandlerVector [15]) (void) ;\n"
  "//--- Non-Core Vectors\n"
  "  void (* mNonCoreHandlerVector [240]) (void) ;\n"
  "//--- Flash magic values\n"
  "  int mFlash [4] ;\n"
  "} vectorStructSeq ;\n"
  "\n"
  "//---------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "extern unsigned __system_stack_end ;\n"
  "\n"
  "//---------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "const vectorStructSeq vector __attribute__ ((section (\".isr_vector\"))) = {\n"
  "  & __system_stack_end, // 0\n"
  "//--- ARM Core System Handler Vectors\n"
  "  { ResetISR, // 1\n"
  "    proc_NMIHandler, // 2\n"
  "    proc_HardFaultHandler, // 3\n"
  "    proc_MemManageHandler, // 4\n"
  "    proc_BusFaultHandler, // 5\n"
  "    proc_UsageFaultHandler, // 6\n"
  "    NULL, // 7 (reserved)\n"
  "    NULL, // 8 (reserved)\n"
  "    NULL, // 9 (reserved)\n"
  "    NULL, // 10 (reserved)\n"
  "    proc_svcHandler, // 11\n"
  "    proc_DebugMonitorHandler, // 12\n"
  "    NULL, // 13 (reserved)\n"
  "    proc_PendSVHandler, // 14\n"
  "    proc_systickHandler // 15\n"
  "  },\n"
  "//--- Non-Core Vectors\n"
  "  { proc_DMAChannel0TranfertCompleteHandler, // 16\n"
  "    proc_DMAChannel1TranfertCompleteHandler, // 17\n"
  "    proc_DMAChannel2TranfertCompleteHandler, // 18\n"
  "    proc_DMAChannel3TranfertCompleteHandler, // 19\n"
  "    proc_DMAChannel4TranfertCompleteHandler, // 20\n"
  "    proc_DMAChannel5TranfertCompleteHandler, // 21\n"
  "    proc_DMAChannel6TranfertCompleteHandler, // 22\n"
  "    proc_DMAChannel7TranfertCompleteHandler, // 23\n"
  "    proc_DMAChannel8TranfertCompleteHandler, // 24\n"
  "    proc_DMAChannel9TranfertCompleteHandler, // 25\n"
  "    proc_DMAChannel10TranfertCompleteHandler, // 26\n"
  "    proc_DMAChannel11TranfertCompleteHandler, // 27\n"
  "    proc_DMAChannel12TranfertCompleteHandler, // 28\n"
  "    proc_DMAChannel13TranfertCompleteHandler, // 29\n"
  "    proc_DMAChannel14TranfertCompleteHandler, // 30\n"
  "    proc_DMAChannel15TranfertCompleteHandler, // 31\n"
  "    proc_DMAErrorHandler, // 32\n"
  "    NULL, // 33\n"
  "    proc_flashMemoryCommandCompleteHandler, // 34\n"
  "    proc_flashMemoryReadCollisionHandler, // 35\n"
  "    proc_modeControllerHandler, // 36\n"
  "    proc_LLWUHandler, // 37\n"
  "    proc_WDOGEWMHandler, // 38\n"
  "    NULL, // 39\n"
  "    proc_I2C0Handler, // 40\n"
  "    proc_I2C1Handler, // 41\n"
  "    proc_SPI0Handler, // 42\n"
  "    proc_SPI1Handler, // 43\n"
  "    NULL, // 44\n"
  "    proc_CAN0MessageBufferHandler, // 45\n"
  "    proc_CAN0BusOffHandler, // 46\n"
  "    proc_CAN0ErrorHandler, // 47\n"
  "    proc_CAN0TransmitWarningHandler, // 48\n"
  "    proc_CAN0ReceiveWarningHandler, // 49\n"
  "    proc_CAN0WakeUpHandler, // 50\n"
  "    proc_I2S0TransmitHandler, // 51\n"
  "    proc_I2S0ReceiveHandler, // 52\n"
  "    NULL, // 53\n"
  "    NULL, // 54\n"
  "    NULL, // 55\n"
  "    NULL, // 56\n"
  "    NULL, // 57\n"
  "    NULL, // 58\n"
  "    NULL, // 59\n"
  "    proc_UART0LONHandler, // 60\n"
  "    proc_UART0StatusHandler, // 61\n"
  "    proc_UART0ErrorHandler, // 62\n"
  "    proc_UART1StatusHandler, // 63\n"
  "    proc_UART1ErrorHandler, // 64\n"
  "    proc_UART2StatusHandler, // 65\n"
  "    proc_UART2ErrorHandler, // 66\n"
  "    NULL, // 67\n"
  "    NULL, // 68\n"
  "    NULL, // 69\n"
  "    NULL, // 70\n"
  "    NULL, // 71\n"
  "    NULL, // 72\n"
  "    proc_ADC0Handler, // 73\n"
  "    proc_ADC1Handler, // 74\n"
  "    proc_CMP0Handler, // 75\n"
  "    proc_CMP1Handler, // 76\n"
  "    proc_CMP2Handler, // 77\n"
  "    proc_FMT0Handler, // 78\n"
  "    proc_FMT1Handler, // 79\n"
  "    proc_FMT2Handler, // 80\n"
  "    proc_CMTHandler, // 81\n"
  "    proc_RTCAlarmHandler, // 82\n"
  "    proc_RTCSecondHandler, // 83\n"
  "    proc_PITChannel0Handler, // 84\n"
  "    proc_PITChannel1Handler, // 85\n"
  "    proc_PITChannel2Handler, // 86\n"
  "    proc_PITChannel3Handler, // 87\n"
  "    proc_PDBHandler, // 88\n"
  "    proc_USBOTGHandler, // 89\n"
  "    proc_USBChargerDetectHandler, // 90\n"
  "    NULL, // 91\n"
  "    NULL, // 92\n"
  "    NULL, // 93\n"
  "    NULL, // 94\n"
  "    NULL, // 95\n"
  "    NULL, // 96\n"
  "    proc_DAC0Handler, // 97\n"
  "    NULL, // 98\n"
  "    proc_TSIHandler, // 99\n"
  "    proc_MCGHandler, // 100\n"
  "    proc_lowPowerTimerHandler, // 101\n"
  "    NULL, // 102\n"
  "    proc_pinDetectPortAHandler, // 103\n"
  "    proc_pinDetectPortBHandler, // 104\n"
  "    proc_pinDetectPortCHandler, // 105\n"
  "    proc_pinDetectPortDHandler, // 106\n"
  "    proc_pinDetectPortEHandler, // 107\n"
  "    NULL, // 108\n"
  "    NULL, // 109\n"
  "    proc_softwareInterruptHandler, // 110\n"
  "    NULL, // 111\n"
  "    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, // 112 \xC3""\xA0"" 127\n"
  "    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, // 128 \xC3""\xA0"" 143\n"
  "    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, // 143 \xC3""\xA0"" 159\n"
  "    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, // 160 \xC3""\xA0"" 175\n"
  "    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, // 176 \xC3""\xA0"" 191\n"
  "    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, // 192 \xC3""\xA0"" 207\n"
  "    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, // 208 \xC3""\xA0"" 223\n"
  "    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, // 224 \xC3""\xA0"" 239\n"
  "    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL  // 240 \xC3""\xA0"" 255\n"
  "  },\n"
  "//--- Flash magic values\n"
  "  {-1, -1, -1, -2}\n"
  "} ;\n"
  "\n"
  "//---------------------------------------------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_17_embeddedTargets (
  "target.c",
  "c",
  true, // Text file
  6877, // Text length
  gWrapperFileContent_17_embeddedTargets
) ;

//--- All files of 'sources' directory

static const cRegularFileWrapper * gWrapperAllFiles_embeddedTargets_3 [4] = {
  & gWrapperFile_15_embeddedTargets,
  & gWrapperFile_16_embeddedTargets,
  & gWrapperFile_17_embeddedTargets,
  NULL
} ;

//--- All sub-directories of 'sources' directory

static const cDirectoryWrapper * gWrapperAllDirectories_embeddedTargets_3 [1] = {
  NULL
} ;

//--- Directory 'sources'

const cDirectoryWrapper gWrapperDirectory_3_embeddedTargets (
  "sources",
  3,
  gWrapperAllFiles_embeddedTargets_3,
  0,
  gWrapperAllDirectories_embeddedTargets_3
) ;

//--- All files of 'teensy-3-1-interrupt' directory

static const cRegularFileWrapper * gWrapperAllFiles_embeddedTargets_2 [7] = {
  & gWrapperFile_9_embeddedTargets,
  & gWrapperFile_10_embeddedTargets,
  & gWrapperFile_11_embeddedTargets,
  & gWrapperFile_12_embeddedTargets,
  & gWrapperFile_13_embeddedTargets,
  & gWrapperFile_14_embeddedTargets,
  NULL
} ;

//--- All sub-directories of 'teensy-3-1-interrupt' directory

static const cDirectoryWrapper * gWrapperAllDirectories_embeddedTargets_2 [2] = {
  & gWrapperDirectory_3_embeddedTargets,
  NULL
} ;

//--- Directory 'teensy-3-1-interrupt'

const cDirectoryWrapper gWrapperDirectory_2_embeddedTargets (
  "teensy-3-1-interrupt",
  6,
  gWrapperAllFiles_embeddedTargets_2,
  1,
  gWrapperAllDirectories_embeddedTargets_2
) ;

//--- File 'teensy-3-1-sequential-systick/build-verbose.py'

const char * gWrapperFileContent_18_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import subprocess\n"
  "import sys\n"
  "import os\n"
  "import atexit\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "def cleanup():\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.kill ()\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "#--- Register a function for killing subprocess\n"
  "atexit.register (cleanup)\n"
  "#--- Get script absolute path\n"
  "scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))\n"
  "os.chdir (scriptDir)\n"
  "#---\n"
  "childProcess = subprocess.Popen ([\"python\", \"build.py\", \"all\", \"1\"])\n"
  "#--- Wait for subprocess termination\n"
  "if childProcess.poll () == None :\n"
  "  childProcess.wait ()\n"
  "if childProcess.returncode != 0 :\n"
  "  sys.exit (childProcess.returncode)\n"
  "\n"
  "#------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_18_embeddedTargets (
  "build-verbose.py",
  "py",
  true, // Text file
  1002, // Text length
  gWrapperFileContent_18_embeddedTargets
) ;

//--- File 'teensy-3-1-sequential-systick/build.py'

const char * gWrapperFileContent_19_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "import sys, os\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "sys.path.append (os.path.dirname (os.path.abspath (sys.argv [0])) + \"/sources\")\n"
  "import plm\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#                         Object files directories                                                                     *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def archiveBaseURL ():\n"
  "  return \"http://crossgcc.rts-software.org/downloads/plm-tools/\"\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Tool dir                                                                                                           *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def toolDir ():\n"
  "  (SYSTEM_NAME, MODE_NAME, RELEASE, VERSION, MACHINE) = os.uname ()\n"
  "  if SYSTEM_NAME == \"Darwin\":\n"
  "    MACHINE = \"i386\"\n"
  "  return os.path.expanduser (\"~/plm-tools/plm-\" + SYSTEM_NAME + \"-\" + MACHINE + \"-llvm-3.7.0-binutils-2.25-libusb-1.0.19\")\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   LLVM optimizer invocation                                                                                          *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def llvmOptimizerCompiler ():\n"
  "  return [toolDir () + \"/bin/opt\", \"-<<OPT_OPTIMIZATION_OPTION>>\", \"-disable-simplify-libcalls\", \"-S\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   LLC Compiler invocation                                                                                            *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def LLCcompiler ():\n"
  "  return [toolDir () + \"/bin/llc\", \"-<<LLC_OPTIMIZATION_OPTION>>\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   AS assembler invocation                                                                                            *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def asAssembler ():\n"
  "  return [toolDir () + \"/bin/arm-eabi-as\", \"-mthumb\", \"-mcpu=cortex-m4\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Display object size invocation                                                                                     *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def displayObjectSize ():\n"
  "  return [toolDir () + \"/bin/arm-eabi-size\", \"-t\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Object Dump invocation                                                                                             *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def dumpObjectCode ():\n"
  "  return [toolDir () + \"/bin/arm-eabi-objdump\", \"-Sdh\", \"-Mforce-thumb\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Linker invocation                                                                                                  *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def linker ():\n"
  "  result = [toolDir () + \"/bin/arm-eabi-ld\"]\n"
  "  result.append (\"-nostartfiles\")\n"
  "  result.append (\"--fatal-warnings\")\n"
  "  result.append (\"--warn-common\")\n"
  "  result.append (\"--no-undefined\")\n"
  "  result.append (\"--cref\")\n"
  "  result.append (\"-static\")\n"
  "  result.append (\"-s\")\n"
  "  result.append (\"--gc-sections\")\n"
  "  return result\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   objcopy invocation                                                                                                 *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def objcopy ():\n"
  "  return [toolDir () + \"/bin/arm-eabi-objcopy\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   LLVM Source files                                                                                                  *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def LLVMsourceList ():\n"
  "  return [\"source-plm.ll\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Product directory                                                                                                  *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def productDir ():\n"
  "  return \"product\"\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#                         Object files directories                                                                     *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def objectDir ():\n"
  "  return \"objects\"\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   Run executable                                                                                                      *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def runExecutableOnTarget ():\n"
  "  return [toolDir () + \"/bin/teensy-loader-cli\", \"-w\", \"-v\", \"-mmcu=mk20dx128\"]\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "#                                                                                                                      *\n"
  "#   MAIN                                                                                                               *\n"
  "#                                                                                                                      *\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "currentFile = os.path.abspath (sys.argv [0])\n"
  "plm.runMakefile (toolDir (), archiveBaseURL (), LLVMsourceList (), objectDir (), \\\n"
  "                 LLCcompiler (), llvmOptimizerCompiler (), \\\n"
  "                 asAssembler (), productDir (), \\\n"
  "                 linker (), \\\n"
  "                 objcopy (), dumpObjectCode (), displayObjectSize (), runExecutableOnTarget (), \\\n"
  "                 currentFile)\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_19_embeddedTargets (
  "build.py",
  "py",
  true, // Text file
  10876, // Text length
  gWrapperFileContent_19_embeddedTargets
) ;

//--- File 'teensy-3-1-sequential-systick/clean.py'

const char * gWrapperFileContent_20_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import subprocess\n"
  "import sys\n"
  "import os\n"
  "import atexit\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "def cleanup():\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.kill ()\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n"
  "\n"
  "#--- Register a function for killing subprocess\n"
  "atexit.register (cleanup)\n"
  "#--- Get script absolute path\n"
  "scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))\n"
  "#--- Directories to clean\n"
  "dir1 = scriptDir + \"/objects\"\n"
  "dir2 = scriptDir + \"/product\"\n"
  "dir3 = scriptDir + \"/as\"\n"
  "#---\n"
  "childProcess = subprocess.Popen ([\"rm\", \"-fr\", dir1, dir2, dir3], cwd=scriptDir)\n"
  "#--- Wait for subprocess termination\n"
  "if childProcess.poll () == None :\n"
  "  childProcess.wait ()\n"
  "if childProcess.returncode != 0 :\n"
  "  sys.exit (childProcess.returncode)\n"
  "\n"
  "#----------------------------------------------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_20_embeddedTargets (
  "clean.py",
  "py",
  true, // Text file
  1264, // Text length
  gWrapperFileContent_20_embeddedTargets
) ;

//--- File 'teensy-3-1-sequential-systick/linker.ld'

const char * gWrapperFileContent_21_embeddedTargets = "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                                   Memory                                   */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "MEMORY {\n"
  "  flash (rx) : ORIGIN = 0, LENGTH = 256k \n"
  "  sram_u (rwx) : ORIGIN = 0x20000000, LENGTH = 32k \n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "__sram_u_end = 0x20000000 + 32k ;\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                                ISR Vectors                                 */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "SECTIONS {\n"
  "  .vectors : {\n"
  "    __vectors_start = . ;\n"
  "    KEEP (*(.isr_vector)) ;\n"
  "    __vectors_end = . ;\n"
  "  } > flash\n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                                    Code                                    */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "SECTIONS {\n"
  "  .text : {\n"
  "    FILL(0xff)\n"
  "    __code_start = . ;\n"
  "  /*--- Tableau des routines d'initialisation */\n"
  "    . = ALIGN (4) ;\n"
  "    __init_routine_array_start = . ;\n"
  "    KEEP (*(init_routine_array)) ;\n"
  "    . = ALIGN (4) ;\n"
  "    __init_routine_array_end = . ;\n"
  "  /*--- Initialisation des objets globaux C++ */\n"
  "    . = ALIGN (4) ;\n"
  "    __constructor_array_start = . ;\n"
  "    KEEP (*(.init_array)) ;\n"
  "    . = ALIGN (4) ;\n"
  "    __constructor_array_end = . ;\n"
  "  /*--- Real Interrupt Service Routine Array */\n"
  "    . = ALIGN (4) ;\n"
  "    __real_time_isr_array_start = . ;\n"
  "    KEEP (*(real_time_isr_array)) ;\n"
  "    . = ALIGN (4) ;\n"
  "    __real_time_isr_array_end = . ;\n"
  "  /*--- Code */\n"
  "    *(.text.*) ;\n"
  "    *(.text) ;\n"
  "    *(text) ;\n"
  "    *(.gnu.linkonce.t.*) ;\n"
  "  /*---- ROM data ----*/\n"
  "    . = ALIGN(4);\n"
  "    *(.rodata);\n"
  "    . = ALIGN(4);\n"
  "    *(.rodata*);\n"
  "    . = ALIGN(4);\n"
  "    *(.gnu.linkonce.r.*);\n"
  "    . = ALIGN(4);\n"
  "    *(.glue_7t);\n"
  "    . = ALIGN(4);\n"
  "    *(.glue_7);\n"
  "    . = ALIGN(4);\n"
  "  } > flash\n"
  "\n"
  "  .ARM.exidx : {\n"
  "    *(.ARM.exidx* .gnu.linkonce.armexidx.*);\n"
  "    __code_end = . ;\n"
  "  } > flash\n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                          Data (initialized data)                           */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "SECTIONS {\n"
  "  .data : {\n"
  "    FILL (0xFF)\n"
  "    . = ALIGN (4) ;\n"
  "    __data_start = . ;\n"
  "    * (.data.*init*) ;\n"
  "    * (.data*) ;\n"
  "    . = ALIGN (4) ;\n"
  "    __data_end = . ;\n"
  "  } > sram_u AT > flash\n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "__data_load_start = LOADADDR (.data) ;\n"
  "__data_load_end   = LOADADDR (.data) + SIZEOF (.data) ;\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                          BSS (uninitialized data)                          */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "SECTIONS {\n"
  "  .bss : {\n"
  "    . = ALIGN(4);\n"
  "    __bss_start = . ;\n"
  "    * (.bss.*) ;\n"
  "    * (.bss) ;\n"
  "    * (COMMON) ;\n"
  "    . = ALIGN(4);\n"
  "    __bss_end = . ;\n"
  "  } > sram_u\n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                                System stack                                */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "SECTIONS {\n"
  "  .system_stack :{\n"
  "    . = ALIGN (4) ;\n"
  "    __system_stack_start = . ;\n"
  "    . += 1k ;\n"
  "    . = ALIGN (4) ;\n"
  "    __system_stack_end = . ;\n"
  "  } > sram_u\n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "/*                                                                            */\n"
  "/*                                    Heap                                    */\n"
  "/*                                                                            */\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "SECTIONS {\n"
  "  .heap : {\n"
  "    . = ALIGN (4) ;\n"
  "    __heap_start = . ;\n"
  "  } > sram_u\n"
  "}\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n"
  "\n"
  "__heap_end = __sram_u_end ;\n"
  "\n"
  "/*----------------------------------------------------------------------------*/\n" ;

const cRegularFileWrapper gWrapperFile_21_embeddedTargets (
  "linker.ld",
  "ld",
  true, // Text file
  5218, // Text length
  gWrapperFileContent_21_embeddedTargets
) ;

//--- File 'teensy-3-1-sequential-systick/objdump.py'

const char * gWrapperFileContent_22_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import subprocess\n"
  "import sys\n"
  "import os\n"
  "import atexit\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "def cleanup():\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.kill ()\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "#--- Register a function for killing subprocess\n"
  "atexit.register (cleanup)\n"
  "#--- Get script absolute path\n"
  "scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))\n"
  "os.chdir (scriptDir)\n"
  "#---\n"
  "childProcess = subprocess.Popen ([\"python\", \"build.py\", \"object-dump\"])\n"
  "#--- Wait for subprocess termination\n"
  "if childProcess.poll () == None :\n"
  "  childProcess.wait ()\n"
  "if childProcess.returncode != 0 :\n"
  "  sys.exit (childProcess.returncode)\n"
  "\n"
  "#------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_22_embeddedTargets (
  "objdump.py",
  "py",
  true, // Text file
  1005, // Text length
  gWrapperFileContent_22_embeddedTargets
) ;

//--- File 'teensy-3-1-sequential-systick/objsize.py'

const char * gWrapperFileContent_23_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import subprocess\n"
  "import sys\n"
  "import os\n"
  "import atexit\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "def cleanup():\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.kill ()\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "#--- Register a function for killing subprocess\n"
  "atexit.register (cleanup)\n"
  "#--- Get script absolute path\n"
  "scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))\n"
  "os.chdir (scriptDir)\n"
  "#---\n"
  "childProcess = subprocess.Popen ([\"python\", \"build.py\", \"display-object-size\"])\n"
  "#--- Wait for subprocess termination\n"
  "if childProcess.poll () == None :\n"
  "  childProcess.wait ()\n"
  "if childProcess.returncode != 0 :\n"
  "  sys.exit (childProcess.returncode)\n"
  "\n"
  "#------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_23_embeddedTargets (
  "objsize.py",
  "py",
  true, // Text file
  1013, // Text length
  gWrapperFileContent_23_embeddedTargets
) ;

//--- File 'teensy-3-1-sequential-systick/run.py'

const char * gWrapperFileContent_24_embeddedTargets = "#! /usr/bin/env python\n"
  "# -*- coding: UTF-8 -*-\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "# https://docs.python.org/2/library/subprocess.html#module-subprocess\n"
  "\n"
  "import subprocess\n"
  "import sys\n"
  "import os\n"
  "import atexit\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "def cleanup():\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.kill ()\n"
  "\n"
  "#------------------------------------------------------------------------------*\n"
  "\n"
  "#--- Register a function for killing subprocess\n"
  "atexit.register (cleanup)\n"
  "#--- Get script absolute path\n"
  "scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))\n"
  "os.chdir (scriptDir)\n"
  "#---\n"
  "childProcess = subprocess.Popen ([\"python\", \"build.py\", \"run\"])\n"
  "#--- Wait for subprocess termination\n"
  "try:\n"
  "  if childProcess.poll () == None :\n"
  "    childProcess.wait ()\n"
  "  if childProcess.returncode != 0 :\n"
  "    sys.exit (childProcess.returncode)\n"
  "except :\n"
  "    sys.exit (1)\n"
  "\n"
  "#------------------------------------------------------------------------------*\n" ;

const cRegularFileWrapper gWrapperFile_24_embeddedTargets (
  "run.py",
  "py",
  true, // Text file
  1036, // Text length
  gWrapperFileContent_24_embeddedTargets
) ;

//--- All files of 'teensy-3-1-sequential-systick' directory

static const cRegularFileWrapper * gWrapperAllFiles_embeddedTargets_4 [8] = {
  & gWrapperFile_18_embeddedTargets,
  & gWrapperFile_19_embeddedTargets,
  & gWrapperFile_20_embeddedTargets,
  & gWrapperFile_21_embeddedTargets,
  & gWrapperFile_22_embeddedTargets,
  & gWrapperFile_23_embeddedTargets,
  & gWrapperFile_24_embeddedTargets,
  NULL
} ;

//--- All sub-directories of 'teensy-3-1-sequential-systick' directory

static const cDirectoryWrapper * gWrapperAllDirectories_embeddedTargets_4 [1] = {
  NULL
} ;

//--- Directory 'teensy-3-1-sequential-systick'

const cDirectoryWrapper gWrapperDirectory_4_embeddedTargets (
  "teensy-3-1-sequential-systick",
  7,
  gWrapperAllFiles_embeddedTargets_4,
  0,
  gWrapperAllDirectories_embeddedTargets_4
) ;

//--- All files of '' directory

static const cRegularFileWrapper * gWrapperAllFiles_embeddedTargets_0 [5] = {
  & gWrapperFile_0_embeddedTargets,
  & gWrapperFile_1_embeddedTargets,
  & gWrapperFile_2_embeddedTargets,
  & gWrapperFile_3_embeddedTargets,
  NULL
} ;

//--- All sub-directories of '' directory

static const cDirectoryWrapper * gWrapperAllDirectories_embeddedTargets_0 [4] = {
  & gWrapperDirectory_1_embeddedTargets,
  & gWrapperDirectory_2_embeddedTargets,
  & gWrapperDirectory_4_embeddedTargets,
  NULL
} ;

//--- Directory ''

const cDirectoryWrapper gWrapperDirectory_0_embeddedTargets (
  "",
  4,
  gWrapperAllFiles_embeddedTargets_0,
  3,
  gWrapperAllDirectories_embeddedTargets_0
) ;


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_abstractDeclaration::objectCompare (const GALGAS_abstractDeclaration & inOperand) const {
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

GALGAS_abstractDeclaration::GALGAS_abstractDeclaration (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractDeclaration::GALGAS_abstractDeclaration (const cPtr_abstractDeclaration * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_abstractDeclaration) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @abstractDeclaration class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_abstractDeclaration::cPtr_abstractDeclaration (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @abstractDeclaration type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_abstractDeclaration ("abstractDeclaration",
                                            NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_abstractDeclaration::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_abstractDeclaration ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_abstractDeclaration::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_abstractDeclaration (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractDeclaration GALGAS_abstractDeclaration::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_abstractDeclaration result ;
  const GALGAS_abstractDeclaration * p = (const GALGAS_abstractDeclaration *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_abstractDeclaration *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("abstractDeclaration", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_booleanDeclaration::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_booleanDeclaration * p = (const cPtr_booleanDeclaration *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_booleanDeclaration) ;
  if (kOperandEqual == result) {
    result = mAttribute_mBooleanTypeName.objectCompare (p->mAttribute_mBooleanTypeName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mAttributeList.objectCompare (p->mAttribute_mAttributeList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_booleanDeclaration::objectCompare (const GALGAS_booleanDeclaration & inOperand) const {
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

GALGAS_booleanDeclaration::GALGAS_booleanDeclaration (void) :
GALGAS_abstractDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_booleanDeclaration GALGAS_booleanDeclaration::constructor_default (LOCATION_ARGS) {
  return GALGAS_booleanDeclaration::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                     GALGAS_lstringlist::constructor_emptyList (HERE)
                                                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_booleanDeclaration::GALGAS_booleanDeclaration (const cPtr_booleanDeclaration * inSourcePtr) :
GALGAS_abstractDeclaration (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_booleanDeclaration) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_booleanDeclaration GALGAS_booleanDeclaration::constructor_new (const GALGAS_lstring & inAttribute_mBooleanTypeName,
                                                                      const GALGAS_lstringlist & inAttribute_mAttributeList
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_booleanDeclaration result ;
  if (inAttribute_mBooleanTypeName.isValid () && inAttribute_mAttributeList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_booleanDeclaration (inAttribute_mBooleanTypeName, inAttribute_mAttributeList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_booleanDeclaration::reader_mBooleanTypeName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_booleanDeclaration * p = (const cPtr_booleanDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_booleanDeclaration) ;
    result = p->mAttribute_mBooleanTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_booleanDeclaration::reader_mBooleanTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mBooleanTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_booleanDeclaration::reader_mAttributeList (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  if (NULL != mObjectPtr) {
    const cPtr_booleanDeclaration * p = (const cPtr_booleanDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_booleanDeclaration) ;
    result = p->mAttribute_mAttributeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cPtr_booleanDeclaration::reader_mAttributeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @booleanDeclaration class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_booleanDeclaration::cPtr_booleanDeclaration (const GALGAS_lstring & in_mBooleanTypeName,
                                                  const GALGAS_lstringlist & in_mAttributeList
                                                  COMMA_LOCATION_ARGS) :
cPtr_abstractDeclaration (THERE),
mAttribute_mBooleanTypeName (in_mBooleanTypeName),
mAttribute_mAttributeList (in_mAttributeList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_booleanDeclaration::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_booleanDeclaration ;
}

void cPtr_booleanDeclaration::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@booleanDeclaration:" ;
  mAttribute_mBooleanTypeName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mAttributeList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_booleanDeclaration::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_booleanDeclaration (mAttribute_mBooleanTypeName, mAttribute_mAttributeList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @booleanDeclaration type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_booleanDeclaration ("booleanDeclaration",
                                           & kTypeDescriptor_GALGAS_abstractDeclaration) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_booleanDeclaration::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_booleanDeclaration ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_booleanDeclaration::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_booleanDeclaration (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_booleanDeclaration GALGAS_booleanDeclaration::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_booleanDeclaration result ;
  const GALGAS_booleanDeclaration * p = (const GALGAS_booleanDeclaration *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_booleanDeclaration *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("booleanDeclaration", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_enumerationDeclaration::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_enumerationDeclaration * p = (const cPtr_enumerationDeclaration *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_enumerationDeclaration) ;
  if (kOperandEqual == result) {
    result = mAttribute_mEnumerationName.objectCompare (p->mAttribute_mEnumerationName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mAttributeList.objectCompare (p->mAttribute_mAttributeList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mCaseNameList.objectCompare (p->mAttribute_mCaseNameList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_enumerationDeclaration::objectCompare (const GALGAS_enumerationDeclaration & inOperand) const {
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

GALGAS_enumerationDeclaration::GALGAS_enumerationDeclaration (void) :
GALGAS_abstractDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumerationDeclaration GALGAS_enumerationDeclaration::constructor_default (LOCATION_ARGS) {
  return GALGAS_enumerationDeclaration::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                         GALGAS_lstringlist::constructor_emptyList (HERE),
                                                         GALGAS_lstringlist::constructor_emptyList (HERE)
                                                         COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumerationDeclaration::GALGAS_enumerationDeclaration (const cPtr_enumerationDeclaration * inSourcePtr) :
GALGAS_abstractDeclaration (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_enumerationDeclaration) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumerationDeclaration GALGAS_enumerationDeclaration::constructor_new (const GALGAS_lstring & inAttribute_mEnumerationName,
                                                                              const GALGAS_lstringlist & inAttribute_mAttributeList,
                                                                              const GALGAS_lstringlist & inAttribute_mCaseNameList
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_enumerationDeclaration result ;
  if (inAttribute_mEnumerationName.isValid () && inAttribute_mAttributeList.isValid () && inAttribute_mCaseNameList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_enumerationDeclaration (inAttribute_mEnumerationName, inAttribute_mAttributeList, inAttribute_mCaseNameList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_enumerationDeclaration::reader_mEnumerationName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_enumerationDeclaration * p = (const cPtr_enumerationDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumerationDeclaration) ;
    result = p->mAttribute_mEnumerationName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_enumerationDeclaration::reader_mEnumerationName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEnumerationName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_enumerationDeclaration::reader_mAttributeList (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  if (NULL != mObjectPtr) {
    const cPtr_enumerationDeclaration * p = (const cPtr_enumerationDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumerationDeclaration) ;
    result = p->mAttribute_mAttributeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cPtr_enumerationDeclaration::reader_mAttributeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_enumerationDeclaration::reader_mCaseNameList (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  if (NULL != mObjectPtr) {
    const cPtr_enumerationDeclaration * p = (const cPtr_enumerationDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumerationDeclaration) ;
    result = p->mAttribute_mCaseNameList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cPtr_enumerationDeclaration::reader_mCaseNameList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mCaseNameList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @enumerationDeclaration class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_enumerationDeclaration::cPtr_enumerationDeclaration (const GALGAS_lstring & in_mEnumerationName,
                                                          const GALGAS_lstringlist & in_mAttributeList,
                                                          const GALGAS_lstringlist & in_mCaseNameList
                                                          COMMA_LOCATION_ARGS) :
cPtr_abstractDeclaration (THERE),
mAttribute_mEnumerationName (in_mEnumerationName),
mAttribute_mAttributeList (in_mAttributeList),
mAttribute_mCaseNameList (in_mCaseNameList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_enumerationDeclaration::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumerationDeclaration ;
}

void cPtr_enumerationDeclaration::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@enumerationDeclaration:" ;
  mAttribute_mEnumerationName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mAttributeList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mCaseNameList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_enumerationDeclaration::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_enumerationDeclaration (mAttribute_mEnumerationName, mAttribute_mAttributeList, mAttribute_mCaseNameList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @enumerationDeclaration type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_enumerationDeclaration ("enumerationDeclaration",
                                               & kTypeDescriptor_GALGAS_abstractDeclaration) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_enumerationDeclaration::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumerationDeclaration ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_enumerationDeclaration::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_enumerationDeclaration (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumerationDeclaration GALGAS_enumerationDeclaration::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_enumerationDeclaration result ;
  const GALGAS_enumerationDeclaration * p = (const GALGAS_enumerationDeclaration *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_enumerationDeclaration *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("enumerationDeclaration", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_globalConstantDeclaration::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_globalConstantDeclaration * p = (const cPtr_globalConstantDeclaration *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_globalConstantDeclaration) ;
  if (kOperandEqual == result) {
    result = mAttribute_mTypeName.objectCompare (p->mAttribute_mTypeName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mConstantName.objectCompare (p->mAttribute_mConstantName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mSourceExpression.objectCompare (p->mAttribute_mSourceExpression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_globalConstantDeclaration::objectCompare (const GALGAS_globalConstantDeclaration & inOperand) const {
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

GALGAS_globalConstantDeclaration::GALGAS_globalConstantDeclaration (void) :
GALGAS_abstractDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantDeclaration::GALGAS_globalConstantDeclaration (const cPtr_globalConstantDeclaration * inSourcePtr) :
GALGAS_abstractDeclaration (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_globalConstantDeclaration) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantDeclaration GALGAS_globalConstantDeclaration::constructor_new (const GALGAS_lstring & inAttribute_mTypeName,
                                                                                    const GALGAS_lstring & inAttribute_mConstantName,
                                                                                    const GALGAS_expressionAST & inAttribute_mSourceExpression
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_globalConstantDeclaration result ;
  if (inAttribute_mTypeName.isValid () && inAttribute_mConstantName.isValid () && inAttribute_mSourceExpression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_globalConstantDeclaration (inAttribute_mTypeName, inAttribute_mConstantName, inAttribute_mSourceExpression COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_globalConstantDeclaration::reader_mTypeName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_globalConstantDeclaration * p = (const cPtr_globalConstantDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_globalConstantDeclaration) ;
    result = p->mAttribute_mTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_globalConstantDeclaration::reader_mTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_globalConstantDeclaration::reader_mConstantName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_globalConstantDeclaration * p = (const cPtr_globalConstantDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_globalConstantDeclaration) ;
    result = p->mAttribute_mConstantName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_globalConstantDeclaration::reader_mConstantName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mConstantName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_globalConstantDeclaration::reader_mSourceExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_globalConstantDeclaration * p = (const cPtr_globalConstantDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_globalConstantDeclaration) ;
    result = p->mAttribute_mSourceExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_globalConstantDeclaration::reader_mSourceExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSourceExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @globalConstantDeclaration class                                  *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_globalConstantDeclaration::cPtr_globalConstantDeclaration (const GALGAS_lstring & in_mTypeName,
                                                                const GALGAS_lstring & in_mConstantName,
                                                                const GALGAS_expressionAST & in_mSourceExpression
                                                                COMMA_LOCATION_ARGS) :
cPtr_abstractDeclaration (THERE),
mAttribute_mTypeName (in_mTypeName),
mAttribute_mConstantName (in_mConstantName),
mAttribute_mSourceExpression (in_mSourceExpression) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_globalConstantDeclaration::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalConstantDeclaration ;
}

void cPtr_globalConstantDeclaration::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "[@globalConstantDeclaration:" ;
  mAttribute_mTypeName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mConstantName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mSourceExpression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_globalConstantDeclaration::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_globalConstantDeclaration (mAttribute_mTypeName, mAttribute_mConstantName, mAttribute_mSourceExpression COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @globalConstantDeclaration type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_globalConstantDeclaration ("globalConstantDeclaration",
                                                  & kTypeDescriptor_GALGAS_abstractDeclaration) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_globalConstantDeclaration::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalConstantDeclaration ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_globalConstantDeclaration::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_globalConstantDeclaration (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantDeclaration GALGAS_globalConstantDeclaration::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_globalConstantDeclaration result ;
  const GALGAS_globalConstantDeclaration * p = (const GALGAS_globalConstantDeclaration *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_globalConstantDeclaration *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("globalConstantDeclaration", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_integerDeclaration::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_integerDeclaration * p = (const cPtr_integerDeclaration *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_integerDeclaration) ;
  if (kOperandEqual == result) {
    result = mAttribute_mIsSigned.objectCompare (p->mAttribute_mIsSigned) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mSize.objectCompare (p->mAttribute_mSize) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_integerDeclaration::objectCompare (const GALGAS_integerDeclaration & inOperand) const {
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

GALGAS_integerDeclaration::GALGAS_integerDeclaration (void) :
GALGAS_abstractDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_integerDeclaration GALGAS_integerDeclaration::constructor_default (LOCATION_ARGS) {
  return GALGAS_integerDeclaration::constructor_new (GALGAS_bool::constructor_default (HERE),
                                                     GALGAS_uint::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_integerDeclaration::GALGAS_integerDeclaration (const cPtr_integerDeclaration * inSourcePtr) :
GALGAS_abstractDeclaration (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_integerDeclaration) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_integerDeclaration GALGAS_integerDeclaration::constructor_new (const GALGAS_bool & inAttribute_mIsSigned,
                                                                      const GALGAS_uint & inAttribute_mSize
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_integerDeclaration result ;
  if (inAttribute_mIsSigned.isValid () && inAttribute_mSize.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_integerDeclaration (inAttribute_mIsSigned, inAttribute_mSize COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_integerDeclaration::reader_mIsSigned (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_integerDeclaration * p = (const cPtr_integerDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_integerDeclaration) ;
    result = p->mAttribute_mIsSigned ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_integerDeclaration::reader_mIsSigned (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIsSigned ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_integerDeclaration::reader_mSize (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_integerDeclaration * p = (const cPtr_integerDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_integerDeclaration) ;
    result = p->mAttribute_mSize ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_integerDeclaration::reader_mSize (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSize ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @integerDeclaration class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_integerDeclaration::cPtr_integerDeclaration (const GALGAS_bool & in_mIsSigned,
                                                  const GALGAS_uint & in_mSize
                                                  COMMA_LOCATION_ARGS) :
cPtr_abstractDeclaration (THERE),
mAttribute_mIsSigned (in_mIsSigned),
mAttribute_mSize (in_mSize) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_integerDeclaration::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_integerDeclaration ;
}

void cPtr_integerDeclaration::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@integerDeclaration:" ;
  mAttribute_mIsSigned.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mSize.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_integerDeclaration::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_integerDeclaration (mAttribute_mIsSigned, mAttribute_mSize COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @integerDeclaration type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_integerDeclaration ("integerDeclaration",
                                           & kTypeDescriptor_GALGAS_abstractDeclaration) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_integerDeclaration::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_integerDeclaration ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_integerDeclaration::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_integerDeclaration (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_integerDeclaration GALGAS_integerDeclaration::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_integerDeclaration result ;
  const GALGAS_integerDeclaration * p = (const GALGAS_integerDeclaration *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_integerDeclaration *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("integerDeclaration", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_literalStringDeclaration::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_literalStringDeclaration * p = (const cPtr_literalStringDeclaration *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_literalStringDeclaration) ;
  if (kOperandEqual == result) {
    result = mAttribute_mLiteralStringTypeName.objectCompare (p->mAttribute_mLiteralStringTypeName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_literalStringDeclaration::objectCompare (const GALGAS_literalStringDeclaration & inOperand) const {
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

GALGAS_literalStringDeclaration::GALGAS_literalStringDeclaration (void) :
GALGAS_abstractDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalStringDeclaration GALGAS_literalStringDeclaration::constructor_default (LOCATION_ARGS) {
  return GALGAS_literalStringDeclaration::constructor_new (GALGAS_lstring::constructor_default (HERE)
                                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalStringDeclaration::GALGAS_literalStringDeclaration (const cPtr_literalStringDeclaration * inSourcePtr) :
GALGAS_abstractDeclaration (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_literalStringDeclaration) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalStringDeclaration GALGAS_literalStringDeclaration::constructor_new (const GALGAS_lstring & inAttribute_mLiteralStringTypeName
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_literalStringDeclaration result ;
  if (inAttribute_mLiteralStringTypeName.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_literalStringDeclaration (inAttribute_mLiteralStringTypeName COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_literalStringDeclaration::reader_mLiteralStringTypeName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_literalStringDeclaration * p = (const cPtr_literalStringDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_literalStringDeclaration) ;
    result = p->mAttribute_mLiteralStringTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_literalStringDeclaration::reader_mLiteralStringTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLiteralStringTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @literalStringDeclaration class                                  *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_literalStringDeclaration::cPtr_literalStringDeclaration (const GALGAS_lstring & in_mLiteralStringTypeName
                                                              COMMA_LOCATION_ARGS) :
cPtr_abstractDeclaration (THERE),
mAttribute_mLiteralStringTypeName (in_mLiteralStringTypeName) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_literalStringDeclaration::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_literalStringDeclaration ;
}

void cPtr_literalStringDeclaration::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@literalStringDeclaration:" ;
  mAttribute_mLiteralStringTypeName.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_literalStringDeclaration::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_literalStringDeclaration (mAttribute_mLiteralStringTypeName COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @literalStringDeclaration type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_literalStringDeclaration ("literalStringDeclaration",
                                                 & kTypeDescriptor_GALGAS_abstractDeclaration) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_literalStringDeclaration::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_literalStringDeclaration ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_literalStringDeclaration::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_literalStringDeclaration (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalStringDeclaration GALGAS_literalStringDeclaration::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_literalStringDeclaration result ;
  const GALGAS_literalStringDeclaration * p = (const GALGAS_literalStringDeclaration *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_literalStringDeclaration *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("literalStringDeclaration", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_modeDeclaration::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_modeDeclaration * p = (const cPtr_modeDeclaration *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_modeDeclaration) ;
  if (kOperandEqual == result) {
    result = mAttribute_mModeName.objectCompare (p->mAttribute_mModeName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_modeDeclaration::objectCompare (const GALGAS_modeDeclaration & inOperand) const {
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

GALGAS_modeDeclaration::GALGAS_modeDeclaration (void) :
GALGAS_abstractDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_modeDeclaration GALGAS_modeDeclaration::constructor_default (LOCATION_ARGS) {
  return GALGAS_modeDeclaration::constructor_new (GALGAS_lstring::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_modeDeclaration::GALGAS_modeDeclaration (const cPtr_modeDeclaration * inSourcePtr) :
GALGAS_abstractDeclaration (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_modeDeclaration) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_modeDeclaration GALGAS_modeDeclaration::constructor_new (const GALGAS_lstring & inAttribute_mModeName
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_modeDeclaration result ;
  if (inAttribute_mModeName.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_modeDeclaration (inAttribute_mModeName COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_modeDeclaration::reader_mModeName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_modeDeclaration * p = (const cPtr_modeDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_modeDeclaration) ;
    result = p->mAttribute_mModeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_modeDeclaration::reader_mModeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mModeName ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @modeDeclaration class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_modeDeclaration::cPtr_modeDeclaration (const GALGAS_lstring & in_mModeName
                                            COMMA_LOCATION_ARGS) :
cPtr_abstractDeclaration (THERE),
mAttribute_mModeName (in_mModeName) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_modeDeclaration::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_modeDeclaration ;
}

void cPtr_modeDeclaration::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@modeDeclaration:" ;
  mAttribute_mModeName.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_modeDeclaration::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_modeDeclaration (mAttribute_mModeName COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @modeDeclaration type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_modeDeclaration ("modeDeclaration",
                                        & kTypeDescriptor_GALGAS_abstractDeclaration) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_modeDeclaration::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_modeDeclaration ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_modeDeclaration::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_modeDeclaration (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_modeDeclaration GALGAS_modeDeclaration::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_modeDeclaration result ;
  const GALGAS_modeDeclaration * p = (const GALGAS_modeDeclaration *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_modeDeclaration *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("modeDeclaration", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_pointerSizeDeclaration::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_pointerSizeDeclaration * p = (const cPtr_pointerSizeDeclaration *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_pointerSizeDeclaration) ;
  if (kOperandEqual == result) {
    result = mAttribute_mSize.objectCompare (p->mAttribute_mSize) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_pointerSizeDeclaration::objectCompare (const GALGAS_pointerSizeDeclaration & inOperand) const {
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

GALGAS_pointerSizeDeclaration::GALGAS_pointerSizeDeclaration (void) :
GALGAS_abstractDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_pointerSizeDeclaration GALGAS_pointerSizeDeclaration::constructor_default (LOCATION_ARGS) {
  return GALGAS_pointerSizeDeclaration::constructor_new (GALGAS_lbigint::constructor_default (HERE)
                                                         COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_pointerSizeDeclaration::GALGAS_pointerSizeDeclaration (const cPtr_pointerSizeDeclaration * inSourcePtr) :
GALGAS_abstractDeclaration (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_pointerSizeDeclaration) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_pointerSizeDeclaration GALGAS_pointerSizeDeclaration::constructor_new (const GALGAS_lbigint & inAttribute_mSize
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_pointerSizeDeclaration result ;
  if (inAttribute_mSize.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_pointerSizeDeclaration (inAttribute_mSize COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint GALGAS_pointerSizeDeclaration::reader_mSize (UNUSED_LOCATION_ARGS) const {
  GALGAS_lbigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_pointerSizeDeclaration * p = (const cPtr_pointerSizeDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_pointerSizeDeclaration) ;
    result = p->mAttribute_mSize ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint cPtr_pointerSizeDeclaration::reader_mSize (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSize ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @pointerSizeDeclaration class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_pointerSizeDeclaration::cPtr_pointerSizeDeclaration (const GALGAS_lbigint & in_mSize
                                                          COMMA_LOCATION_ARGS) :
cPtr_abstractDeclaration (THERE),
mAttribute_mSize (in_mSize) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_pointerSizeDeclaration::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_pointerSizeDeclaration ;
}

void cPtr_pointerSizeDeclaration::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@pointerSizeDeclaration:" ;
  mAttribute_mSize.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_pointerSizeDeclaration::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_pointerSizeDeclaration (mAttribute_mSize COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @pointerSizeDeclaration type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_pointerSizeDeclaration ("pointerSizeDeclaration",
                                               & kTypeDescriptor_GALGAS_abstractDeclaration) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_pointerSizeDeclaration::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_pointerSizeDeclaration ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_pointerSizeDeclaration::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_pointerSizeDeclaration (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_pointerSizeDeclaration GALGAS_pointerSizeDeclaration::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_pointerSizeDeclaration result ;
  const GALGAS_pointerSizeDeclaration * p = (const GALGAS_pointerSizeDeclaration *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_pointerSizeDeclaration *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("pointerSizeDeclaration", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_registerDeclaration::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_registerDeclaration * p = (const cPtr_registerDeclaration *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_registerDeclaration) ;
  if (kOperandEqual == result) {
    result = mAttribute_mRegisterDeclarationList.objectCompare (p->mAttribute_mRegisterDeclarationList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mRegisterTypeName.objectCompare (p->mAttribute_mRegisterTypeName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mRegisterBitSliceList.objectCompare (p->mAttribute_mRegisterBitSliceList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_registerDeclaration::objectCompare (const GALGAS_registerDeclaration & inOperand) const {
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

GALGAS_registerDeclaration::GALGAS_registerDeclaration (void) :
GALGAS_abstractDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerDeclaration GALGAS_registerDeclaration::constructor_default (LOCATION_ARGS) {
  return GALGAS_registerDeclaration::constructor_new (GALGAS_registerDeclarationList::constructor_emptyList (HERE),
                                                      GALGAS_lstring::constructor_default (HERE),
                                                      GALGAS_registerBitSliceList::constructor_emptyList (HERE)
                                                      COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerDeclaration::GALGAS_registerDeclaration (const cPtr_registerDeclaration * inSourcePtr) :
GALGAS_abstractDeclaration (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_registerDeclaration) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerDeclaration GALGAS_registerDeclaration::constructor_new (const GALGAS_registerDeclarationList & inAttribute_mRegisterDeclarationList,
                                                                        const GALGAS_lstring & inAttribute_mRegisterTypeName,
                                                                        const GALGAS_registerBitSliceList & inAttribute_mRegisterBitSliceList
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_registerDeclaration result ;
  if (inAttribute_mRegisterDeclarationList.isValid () && inAttribute_mRegisterTypeName.isValid () && inAttribute_mRegisterBitSliceList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_registerDeclaration (inAttribute_mRegisterDeclarationList, inAttribute_mRegisterTypeName, inAttribute_mRegisterBitSliceList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerDeclarationList GALGAS_registerDeclaration::reader_mRegisterDeclarationList (UNUSED_LOCATION_ARGS) const {
  GALGAS_registerDeclarationList result ;
  if (NULL != mObjectPtr) {
    const cPtr_registerDeclaration * p = (const cPtr_registerDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_registerDeclaration) ;
    result = p->mAttribute_mRegisterDeclarationList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerDeclarationList cPtr_registerDeclaration::reader_mRegisterDeclarationList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterDeclarationList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_registerDeclaration::reader_mRegisterTypeName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_registerDeclaration * p = (const cPtr_registerDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_registerDeclaration) ;
    result = p->mAttribute_mRegisterTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_registerDeclaration::reader_mRegisterTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerBitSliceList GALGAS_registerDeclaration::reader_mRegisterBitSliceList (UNUSED_LOCATION_ARGS) const {
  GALGAS_registerBitSliceList result ;
  if (NULL != mObjectPtr) {
    const cPtr_registerDeclaration * p = (const cPtr_registerDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_registerDeclaration) ;
    result = p->mAttribute_mRegisterBitSliceList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerBitSliceList cPtr_registerDeclaration::reader_mRegisterBitSliceList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterBitSliceList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @registerDeclaration class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_registerDeclaration::cPtr_registerDeclaration (const GALGAS_registerDeclarationList & in_mRegisterDeclarationList,
                                                    const GALGAS_lstring & in_mRegisterTypeName,
                                                    const GALGAS_registerBitSliceList & in_mRegisterBitSliceList
                                                    COMMA_LOCATION_ARGS) :
cPtr_abstractDeclaration (THERE),
mAttribute_mRegisterDeclarationList (in_mRegisterDeclarationList),
mAttribute_mRegisterTypeName (in_mRegisterTypeName),
mAttribute_mRegisterBitSliceList (in_mRegisterBitSliceList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_registerDeclaration::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_registerDeclaration ;
}

void cPtr_registerDeclaration::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@registerDeclaration:" ;
  mAttribute_mRegisterDeclarationList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mRegisterTypeName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mRegisterBitSliceList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_registerDeclaration::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_registerDeclaration (mAttribute_mRegisterDeclarationList, mAttribute_mRegisterTypeName, mAttribute_mRegisterBitSliceList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @registerDeclaration type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_registerDeclaration ("registerDeclaration",
                                            & kTypeDescriptor_GALGAS_abstractDeclaration) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_registerDeclaration::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_registerDeclaration ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_registerDeclaration::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_registerDeclaration (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerDeclaration GALGAS_registerDeclaration::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_registerDeclaration result ;
  const GALGAS_registerDeclaration * p = (const GALGAS_registerDeclaration *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_registerDeclaration *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("registerDeclaration", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_structureDeclaration::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_structureDeclaration * p = (const cPtr_structureDeclaration *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_structureDeclaration) ;
  if (kOperandEqual == result) {
    result = mAttribute_mStructureName.objectCompare (p->mAttribute_mStructureName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mAttributeList.objectCompare (p->mAttribute_mAttributeList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mStructureFieldListAST.objectCompare (p->mAttribute_mStructureFieldListAST) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_structureDeclaration::objectCompare (const GALGAS_structureDeclaration & inOperand) const {
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

GALGAS_structureDeclaration::GALGAS_structureDeclaration (void) :
GALGAS_abstractDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureDeclaration GALGAS_structureDeclaration::constructor_default (LOCATION_ARGS) {
  return GALGAS_structureDeclaration::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                       GALGAS_lstringlist::constructor_emptyList (HERE),
                                                       GALGAS_structureFieldListAST::constructor_emptyList (HERE)
                                                       COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureDeclaration::GALGAS_structureDeclaration (const cPtr_structureDeclaration * inSourcePtr) :
GALGAS_abstractDeclaration (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_structureDeclaration) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureDeclaration GALGAS_structureDeclaration::constructor_new (const GALGAS_lstring & inAttribute_mStructureName,
                                                                          const GALGAS_lstringlist & inAttribute_mAttributeList,
                                                                          const GALGAS_structureFieldListAST & inAttribute_mStructureFieldListAST
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_structureDeclaration result ;
  if (inAttribute_mStructureName.isValid () && inAttribute_mAttributeList.isValid () && inAttribute_mStructureFieldListAST.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_structureDeclaration (inAttribute_mStructureName, inAttribute_mAttributeList, inAttribute_mStructureFieldListAST COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_structureDeclaration::reader_mStructureName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_structureDeclaration * p = (const cPtr_structureDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structureDeclaration) ;
    result = p->mAttribute_mStructureName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_structureDeclaration::reader_mStructureName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mStructureName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_structureDeclaration::reader_mAttributeList (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  if (NULL != mObjectPtr) {
    const cPtr_structureDeclaration * p = (const cPtr_structureDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structureDeclaration) ;
    result = p->mAttribute_mAttributeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cPtr_structureDeclaration::reader_mAttributeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureFieldListAST GALGAS_structureDeclaration::reader_mStructureFieldListAST (UNUSED_LOCATION_ARGS) const {
  GALGAS_structureFieldListAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_structureDeclaration * p = (const cPtr_structureDeclaration *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structureDeclaration) ;
    result = p->mAttribute_mStructureFieldListAST ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureFieldListAST cPtr_structureDeclaration::reader_mStructureFieldListAST (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mStructureFieldListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @structureDeclaration class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_structureDeclaration::cPtr_structureDeclaration (const GALGAS_lstring & in_mStructureName,
                                                      const GALGAS_lstringlist & in_mAttributeList,
                                                      const GALGAS_structureFieldListAST & in_mStructureFieldListAST
                                                      COMMA_LOCATION_ARGS) :
cPtr_abstractDeclaration (THERE),
mAttribute_mStructureName (in_mStructureName),
mAttribute_mAttributeList (in_mAttributeList),
mAttribute_mStructureFieldListAST (in_mStructureFieldListAST) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_structureDeclaration::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_structureDeclaration ;
}

void cPtr_structureDeclaration::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@structureDeclaration:" ;
  mAttribute_mStructureName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mAttributeList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mStructureFieldListAST.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_structureDeclaration::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_structureDeclaration (mAttribute_mStructureName, mAttribute_mAttributeList, mAttribute_mStructureFieldListAST COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @structureDeclaration type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_structureDeclaration ("structureDeclaration",
                                             & kTypeDescriptor_GALGAS_abstractDeclaration) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_structureDeclaration::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_structureDeclaration ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_structureDeclaration::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_structureDeclaration (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureDeclaration GALGAS_structureDeclaration::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_structureDeclaration result ;
  const GALGAS_structureDeclaration * p = (const GALGAS_structureDeclaration *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_structureDeclaration *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("structureDeclaration", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_abstractExpressionIR::objectCompare (const GALGAS_abstractExpressionIR & inOperand) const {
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

GALGAS_abstractExpressionIR::GALGAS_abstractExpressionIR (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractExpressionIR::GALGAS_abstractExpressionIR (const cPtr_abstractExpressionIR * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_abstractExpressionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @abstractExpressionIR class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_abstractExpressionIR::cPtr_abstractExpressionIR (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @abstractExpressionIR type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_abstractExpressionIR ("abstractExpressionIR",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_abstractExpressionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_abstractExpressionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_abstractExpressionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_abstractExpressionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractExpressionIR GALGAS_abstractExpressionIR::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_abstractExpressionIR result ;
  const GALGAS_abstractExpressionIR * p = (const GALGAS_abstractExpressionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_abstractExpressionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("abstractExpressionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

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
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_allocaConstantIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_allocaConstantIR * p = (const cPtr_allocaConstantIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_allocaConstantIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mLocalVariableName.objectCompare (p->mAttribute_mLocalVariableName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mVariableType.objectCompare (p->mAttribute_mVariableType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_allocaConstantIR::objectCompare (const GALGAS_allocaConstantIR & inOperand) const {
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

GALGAS_allocaConstantIR::GALGAS_allocaConstantIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaConstantIR GALGAS_allocaConstantIR::constructor_default (LOCATION_ARGS) {
  return GALGAS_allocaConstantIR::constructor_new (GALGAS_string::constructor_default (HERE),
                                                   GALGAS_unifiedTypeMap_2D_proxy::constructor_null (HERE)
                                                   COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaConstantIR::GALGAS_allocaConstantIR (const cPtr_allocaConstantIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_allocaConstantIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaConstantIR GALGAS_allocaConstantIR::constructor_new (const GALGAS_string & inAttribute_mLocalVariableName,
                                                                  const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mVariableType
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_allocaConstantIR result ;
  if (inAttribute_mLocalVariableName.isValid () && inAttribute_mVariableType.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_allocaConstantIR (inAttribute_mLocalVariableName, inAttribute_mVariableType COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_allocaConstantIR::reader_mLocalVariableName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_allocaConstantIR * p = (const cPtr_allocaConstantIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_allocaConstantIR) ;
    result = p->mAttribute_mLocalVariableName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_allocaConstantIR::reader_mLocalVariableName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLocalVariableName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_allocaConstantIR::reader_mVariableType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_allocaConstantIR * p = (const cPtr_allocaConstantIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_allocaConstantIR) ;
    result = p->mAttribute_mVariableType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_allocaConstantIR::reader_mVariableType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mVariableType ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @allocaConstantIR class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_allocaConstantIR::cPtr_allocaConstantIR (const GALGAS_string & in_mLocalVariableName,
                                              const GALGAS_unifiedTypeMap_2D_proxy & in_mVariableType
                                              COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mLocalVariableName (in_mLocalVariableName),
mAttribute_mVariableType (in_mVariableType) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_allocaConstantIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_allocaConstantIR ;
}

void cPtr_allocaConstantIR::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@allocaConstantIR:" ;
  mAttribute_mLocalVariableName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mVariableType.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_allocaConstantIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_allocaConstantIR (mAttribute_mLocalVariableName, mAttribute_mVariableType COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @allocaConstantIR type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_allocaConstantIR ("allocaConstantIR",
                                         & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_allocaConstantIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_allocaConstantIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_allocaConstantIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_allocaConstantIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaConstantIR GALGAS_allocaConstantIR::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_allocaConstantIR result ;
  const GALGAS_allocaConstantIR * p = (const GALGAS_allocaConstantIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_allocaConstantIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("allocaConstantIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_assertInstructionIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_assertInstructionIR * p = (const cPtr_assertInstructionIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_assertInstructionIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mAssertInstructionLocation.objectCompare (p->mAttribute_mAssertInstructionLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mInstructionList.objectCompare (p->mAttribute_mInstructionList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mExpressionValue.objectCompare (p->mAttribute_mExpressionValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_assertInstructionIR::objectCompare (const GALGAS_assertInstructionIR & inOperand) const {
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

GALGAS_assertInstructionIR::GALGAS_assertInstructionIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_assertInstructionIR::GALGAS_assertInstructionIR (const cPtr_assertInstructionIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_assertInstructionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_assertInstructionIR GALGAS_assertInstructionIR::constructor_new (const GALGAS_location & inAttribute_mAssertInstructionLocation,
                                                                        const GALGAS_instructionListIR & inAttribute_mInstructionList,
                                                                        const GALGAS_operandIR & inAttribute_mExpressionValue
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_assertInstructionIR result ;
  if (inAttribute_mAssertInstructionLocation.isValid () && inAttribute_mInstructionList.isValid () && inAttribute_mExpressionValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_assertInstructionIR (inAttribute_mAssertInstructionLocation, inAttribute_mInstructionList, inAttribute_mExpressionValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_assertInstructionIR::reader_mAssertInstructionLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_assertInstructionIR * p = (const cPtr_assertInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_assertInstructionIR) ;
    result = p->mAttribute_mAssertInstructionLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_assertInstructionIR::reader_mAssertInstructionLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAssertInstructionLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_assertInstructionIR::reader_mInstructionList (UNUSED_LOCATION_ARGS) const {
  GALGAS_instructionListIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_assertInstructionIR * p = (const cPtr_assertInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_assertInstructionIR) ;
    result = p->mAttribute_mInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cPtr_assertInstructionIR::reader_mInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_assertInstructionIR::reader_mExpressionValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_assertInstructionIR * p = (const cPtr_assertInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_assertInstructionIR) ;
    result = p->mAttribute_mExpressionValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_assertInstructionIR::reader_mExpressionValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mExpressionValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @assertInstructionIR class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_assertInstructionIR::cPtr_assertInstructionIR (const GALGAS_location & in_mAssertInstructionLocation,
                                                    const GALGAS_instructionListIR & in_mInstructionList,
                                                    const GALGAS_operandIR & in_mExpressionValue
                                                    COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mAssertInstructionLocation (in_mAssertInstructionLocation),
mAttribute_mInstructionList (in_mInstructionList),
mAttribute_mExpressionValue (in_mExpressionValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_assertInstructionIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_assertInstructionIR ;
}

void cPtr_assertInstructionIR::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@assertInstructionIR:" ;
  mAttribute_mAssertInstructionLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mInstructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mExpressionValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_assertInstructionIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_assertInstructionIR (mAttribute_mAssertInstructionLocation, mAttribute_mInstructionList, mAttribute_mExpressionValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @assertInstructionIR type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_assertInstructionIR ("assertInstructionIR",
                                            & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_assertInstructionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_assertInstructionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_assertInstructionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_assertInstructionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_assertInstructionIR GALGAS_assertInstructionIR::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_assertInstructionIR result ;
  const GALGAS_assertInstructionIR * p = (const GALGAS_assertInstructionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_assertInstructionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("assertInstructionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_binaryOperationIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_binaryOperationIR * p = (const cPtr_binaryOperationIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_binaryOperationIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mTargetOperand.objectCompare (p->mAttribute_mTargetOperand) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mTargetVarType.objectCompare (p->mAttribute_mTargetVarType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mLeftOperand.objectCompare (p->mAttribute_mLeftOperand) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mOperation.objectCompare (p->mAttribute_mOperation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mRightOperand.objectCompare (p->mAttribute_mRightOperand) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mLocation.objectCompare (p->mAttribute_mLocation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_binaryOperationIR::objectCompare (const GALGAS_binaryOperationIR & inOperand) const {
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

GALGAS_binaryOperationIR::GALGAS_binaryOperationIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryOperationIR::GALGAS_binaryOperationIR (const cPtr_binaryOperationIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_binaryOperationIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryOperationIR GALGAS_binaryOperationIR::constructor_new (const GALGAS_operandIR & inAttribute_mTargetOperand,
                                                                    const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mTargetVarType,
                                                                    const GALGAS_operandIR & inAttribute_mLeftOperand,
                                                                    const GALGAS_llvmBinaryOperation & inAttribute_mOperation,
                                                                    const GALGAS_operandIR & inAttribute_mRightOperand,
                                                                    const GALGAS_location & inAttribute_mLocation
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_binaryOperationIR result ;
  if (inAttribute_mTargetOperand.isValid () && inAttribute_mTargetVarType.isValid () && inAttribute_mLeftOperand.isValid () && inAttribute_mOperation.isValid () && inAttribute_mRightOperand.isValid () && inAttribute_mLocation.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_binaryOperationIR (inAttribute_mTargetOperand, inAttribute_mTargetVarType, inAttribute_mLeftOperand, inAttribute_mOperation, inAttribute_mRightOperand, inAttribute_mLocation COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_binaryOperationIR::reader_mTargetOperand (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_binaryOperationIR * p = (const cPtr_binaryOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_binaryOperationIR) ;
    result = p->mAttribute_mTargetOperand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_binaryOperationIR::reader_mTargetOperand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_binaryOperationIR::reader_mTargetVarType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_binaryOperationIR * p = (const cPtr_binaryOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_binaryOperationIR) ;
    result = p->mAttribute_mTargetVarType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_binaryOperationIR::reader_mTargetVarType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetVarType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_binaryOperationIR::reader_mLeftOperand (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_binaryOperationIR * p = (const cPtr_binaryOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_binaryOperationIR) ;
    result = p->mAttribute_mLeftOperand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_binaryOperationIR::reader_mLeftOperand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLeftOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_llvmBinaryOperation GALGAS_binaryOperationIR::reader_mOperation (UNUSED_LOCATION_ARGS) const {
  GALGAS_llvmBinaryOperation result ;
  if (NULL != mObjectPtr) {
    const cPtr_binaryOperationIR * p = (const cPtr_binaryOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_binaryOperationIR) ;
    result = p->mAttribute_mOperation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_llvmBinaryOperation cPtr_binaryOperationIR::reader_mOperation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_binaryOperationIR::reader_mRightOperand (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_binaryOperationIR * p = (const cPtr_binaryOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_binaryOperationIR) ;
    result = p->mAttribute_mRightOperand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_binaryOperationIR::reader_mRightOperand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRightOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_binaryOperationIR::reader_mLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_binaryOperationIR * p = (const cPtr_binaryOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_binaryOperationIR) ;
    result = p->mAttribute_mLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_binaryOperationIR::reader_mLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @binaryOperationIR class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_binaryOperationIR::cPtr_binaryOperationIR (const GALGAS_operandIR & in_mTargetOperand,
                                                const GALGAS_unifiedTypeMap_2D_proxy & in_mTargetVarType,
                                                const GALGAS_operandIR & in_mLeftOperand,
                                                const GALGAS_llvmBinaryOperation & in_mOperation,
                                                const GALGAS_operandIR & in_mRightOperand,
                                                const GALGAS_location & in_mLocation
                                                COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mTargetOperand (in_mTargetOperand),
mAttribute_mTargetVarType (in_mTargetVarType),
mAttribute_mLeftOperand (in_mLeftOperand),
mAttribute_mOperation (in_mOperation),
mAttribute_mRightOperand (in_mRightOperand),
mAttribute_mLocation (in_mLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_binaryOperationIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_binaryOperationIR ;
}

void cPtr_binaryOperationIR::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@binaryOperationIR:" ;
  mAttribute_mTargetOperand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mTargetVarType.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mLeftOperand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mOperation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mRightOperand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mLocation.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_binaryOperationIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_binaryOperationIR (mAttribute_mTargetOperand, mAttribute_mTargetVarType, mAttribute_mLeftOperand, mAttribute_mOperation, mAttribute_mRightOperand, mAttribute_mLocation COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @binaryOperationIR type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_binaryOperationIR ("binaryOperationIR",
                                          & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_binaryOperationIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_binaryOperationIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_binaryOperationIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_binaryOperationIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryOperationIR GALGAS_binaryOperationIR::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_binaryOperationIR result ;
  const GALGAS_binaryOperationIR * p = (const GALGAS_binaryOperationIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_binaryOperationIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("binaryOperationIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_commentIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_commentIR * p = (const cPtr_commentIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_commentIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mComment.objectCompare (p->mAttribute_mComment) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_commentIR::objectCompare (const GALGAS_commentIR & inOperand) const {
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

GALGAS_commentIR::GALGAS_commentIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_commentIR GALGAS_commentIR::constructor_default (LOCATION_ARGS) {
  return GALGAS_commentIR::constructor_new (GALGAS_string::constructor_default (HERE)
                                            COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_commentIR::GALGAS_commentIR (const cPtr_commentIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_commentIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_commentIR GALGAS_commentIR::constructor_new (const GALGAS_string & inAttribute_mComment
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_commentIR result ;
  if (inAttribute_mComment.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_commentIR (inAttribute_mComment COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_commentIR::reader_mComment (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_commentIR * p = (const cPtr_commentIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_commentIR) ;
    result = p->mAttribute_mComment ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_commentIR::reader_mComment (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mComment ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                         Pointer class for @commentIR class                                          *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_commentIR::cPtr_commentIR (const GALGAS_string & in_mComment
                                COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mComment (in_mComment) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_commentIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_commentIR ;
}

void cPtr_commentIR::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "[@commentIR:" ;
  mAttribute_mComment.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_commentIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_commentIR (mAttribute_mComment COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @commentIR type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_commentIR ("commentIR",
                                  & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_commentIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_commentIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_commentIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_commentIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_commentIR GALGAS_commentIR::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_commentIR result ;
  const GALGAS_commentIR * p = (const GALGAS_commentIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_commentIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("commentIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_conversionInstructionIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_conversionInstructionIR * p = (const cPtr_conversionInstructionIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_conversionInstructionIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mTargetType.objectCompare (p->mAttribute_mTargetType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mConvertedExpressionType.objectCompare (p->mAttribute_mConvertedExpressionType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mTemporaryResultVariable.objectCompare (p->mAttribute_mTemporaryResultVariable) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mOperand.objectCompare (p->mAttribute_mOperand) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mSilently.objectCompare (p->mAttribute_mSilently) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mLocation.objectCompare (p->mAttribute_mLocation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_conversionInstructionIR::objectCompare (const GALGAS_conversionInstructionIR & inOperand) const {
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

GALGAS_conversionInstructionIR::GALGAS_conversionInstructionIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_conversionInstructionIR::GALGAS_conversionInstructionIR (const cPtr_conversionInstructionIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_conversionInstructionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_conversionInstructionIR GALGAS_conversionInstructionIR::constructor_new (const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mTargetType,
                                                                                const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mConvertedExpressionType,
                                                                                const GALGAS_variableKindIR & inAttribute_mTemporaryResultVariable,
                                                                                const GALGAS_variableKindIR & inAttribute_mOperand,
                                                                                const GALGAS_bool & inAttribute_mSilently,
                                                                                const GALGAS_location & inAttribute_mLocation
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_conversionInstructionIR result ;
  if (inAttribute_mTargetType.isValid () && inAttribute_mConvertedExpressionType.isValid () && inAttribute_mTemporaryResultVariable.isValid () && inAttribute_mOperand.isValid () && inAttribute_mSilently.isValid () && inAttribute_mLocation.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_conversionInstructionIR (inAttribute_mTargetType, inAttribute_mConvertedExpressionType, inAttribute_mTemporaryResultVariable, inAttribute_mOperand, inAttribute_mSilently, inAttribute_mLocation COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_conversionInstructionIR::reader_mTargetType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_conversionInstructionIR * p = (const cPtr_conversionInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_conversionInstructionIR) ;
    result = p->mAttribute_mTargetType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_conversionInstructionIR::reader_mTargetType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_conversionInstructionIR::reader_mConvertedExpressionType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_conversionInstructionIR * p = (const cPtr_conversionInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_conversionInstructionIR) ;
    result = p->mAttribute_mConvertedExpressionType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_conversionInstructionIR::reader_mConvertedExpressionType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mConvertedExpressionType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_variableKindIR GALGAS_conversionInstructionIR::reader_mTemporaryResultVariable (UNUSED_LOCATION_ARGS) const {
  GALGAS_variableKindIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_conversionInstructionIR * p = (const cPtr_conversionInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_conversionInstructionIR) ;
    result = p->mAttribute_mTemporaryResultVariable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_variableKindIR cPtr_conversionInstructionIR::reader_mTemporaryResultVariable (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTemporaryResultVariable ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_variableKindIR GALGAS_conversionInstructionIR::reader_mOperand (UNUSED_LOCATION_ARGS) const {
  GALGAS_variableKindIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_conversionInstructionIR * p = (const cPtr_conversionInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_conversionInstructionIR) ;
    result = p->mAttribute_mOperand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_variableKindIR cPtr_conversionInstructionIR::reader_mOperand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_conversionInstructionIR::reader_mSilently (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_conversionInstructionIR * p = (const cPtr_conversionInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_conversionInstructionIR) ;
    result = p->mAttribute_mSilently ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_conversionInstructionIR::reader_mSilently (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSilently ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_conversionInstructionIR::reader_mLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_conversionInstructionIR * p = (const cPtr_conversionInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_conversionInstructionIR) ;
    result = p->mAttribute_mLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_conversionInstructionIR::reader_mLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @conversionInstructionIR class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_conversionInstructionIR::cPtr_conversionInstructionIR (const GALGAS_unifiedTypeMap_2D_proxy & in_mTargetType,
                                                            const GALGAS_unifiedTypeMap_2D_proxy & in_mConvertedExpressionType,
                                                            const GALGAS_variableKindIR & in_mTemporaryResultVariable,
                                                            const GALGAS_variableKindIR & in_mOperand,
                                                            const GALGAS_bool & in_mSilently,
                                                            const GALGAS_location & in_mLocation
                                                            COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mTargetType (in_mTargetType),
mAttribute_mConvertedExpressionType (in_mConvertedExpressionType),
mAttribute_mTemporaryResultVariable (in_mTemporaryResultVariable),
mAttribute_mOperand (in_mOperand),
mAttribute_mSilently (in_mSilently),
mAttribute_mLocation (in_mLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_conversionInstructionIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_conversionInstructionIR ;
}

void cPtr_conversionInstructionIR::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@conversionInstructionIR:" ;
  mAttribute_mTargetType.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mConvertedExpressionType.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mTemporaryResultVariable.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mOperand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mSilently.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mLocation.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_conversionInstructionIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_conversionInstructionIR (mAttribute_mTargetType, mAttribute_mConvertedExpressionType, mAttribute_mTemporaryResultVariable, mAttribute_mOperand, mAttribute_mSilently, mAttribute_mLocation COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @conversionInstructionIR type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_conversionInstructionIR ("conversionInstructionIR",
                                                & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_conversionInstructionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_conversionInstructionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_conversionInstructionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_conversionInstructionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_conversionInstructionIR GALGAS_conversionInstructionIR::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_conversionInstructionIR result ;
  const GALGAS_conversionInstructionIR * p = (const GALGAS_conversionInstructionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_conversionInstructionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("conversionInstructionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_fieldAccessIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_fieldAccessIR * p = (const cPtr_fieldAccessIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_fieldAccessIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mTargetType.objectCompare (p->mAttribute_mTargetType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mResult.objectCompare (p->mAttribute_mResult) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mSource.objectCompare (p->mAttribute_mSource) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mField.objectCompare (p->mAttribute_mField) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_fieldAccessIR::objectCompare (const GALGAS_fieldAccessIR & inOperand) const {
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

GALGAS_fieldAccessIR::GALGAS_fieldAccessIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_fieldAccessIR::GALGAS_fieldAccessIR (const cPtr_fieldAccessIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_fieldAccessIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_fieldAccessIR GALGAS_fieldAccessIR::constructor_new (const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mTargetType,
                                                            const GALGAS_variableKindIR & inAttribute_mResult,
                                                            const GALGAS_variableKindIR & inAttribute_mSource,
                                                            const GALGAS_lstring & inAttribute_mField
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_fieldAccessIR result ;
  if (inAttribute_mTargetType.isValid () && inAttribute_mResult.isValid () && inAttribute_mSource.isValid () && inAttribute_mField.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_fieldAccessIR (inAttribute_mTargetType, inAttribute_mResult, inAttribute_mSource, inAttribute_mField COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_fieldAccessIR::reader_mTargetType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_fieldAccessIR * p = (const cPtr_fieldAccessIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_fieldAccessIR) ;
    result = p->mAttribute_mTargetType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_fieldAccessIR::reader_mTargetType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_variableKindIR GALGAS_fieldAccessIR::reader_mResult (UNUSED_LOCATION_ARGS) const {
  GALGAS_variableKindIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_fieldAccessIR * p = (const cPtr_fieldAccessIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_fieldAccessIR) ;
    result = p->mAttribute_mResult ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_variableKindIR cPtr_fieldAccessIR::reader_mResult (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mResult ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_variableKindIR GALGAS_fieldAccessIR::reader_mSource (UNUSED_LOCATION_ARGS) const {
  GALGAS_variableKindIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_fieldAccessIR * p = (const cPtr_fieldAccessIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_fieldAccessIR) ;
    result = p->mAttribute_mSource ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_variableKindIR cPtr_fieldAccessIR::reader_mSource (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSource ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_fieldAccessIR::reader_mField (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_fieldAccessIR * p = (const cPtr_fieldAccessIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_fieldAccessIR) ;
    result = p->mAttribute_mField ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_fieldAccessIR::reader_mField (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mField ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @fieldAccessIR class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_fieldAccessIR::cPtr_fieldAccessIR (const GALGAS_unifiedTypeMap_2D_proxy & in_mTargetType,
                                        const GALGAS_variableKindIR & in_mResult,
                                        const GALGAS_variableKindIR & in_mSource,
                                        const GALGAS_lstring & in_mField
                                        COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mTargetType (in_mTargetType),
mAttribute_mResult (in_mResult),
mAttribute_mSource (in_mSource),
mAttribute_mField (in_mField) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_fieldAccessIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_fieldAccessIR ;
}

void cPtr_fieldAccessIR::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "[@fieldAccessIR:" ;
  mAttribute_mTargetType.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mResult.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mSource.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mField.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_fieldAccessIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_fieldAccessIR (mAttribute_mTargetType, mAttribute_mResult, mAttribute_mSource, mAttribute_mField COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @fieldAccessIR type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_fieldAccessIR ("fieldAccessIR",
                                      & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_fieldAccessIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_fieldAccessIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_fieldAccessIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_fieldAccessIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_fieldAccessIR GALGAS_fieldAccessIR::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_fieldAccessIR result ;
  const GALGAS_fieldAccessIR * p = (const GALGAS_fieldAccessIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_fieldAccessIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("fieldAccessIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_ifInstructionIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_ifInstructionIR * p = (const cPtr_ifInstructionIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_ifInstructionIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mTestVariable.objectCompare (p->mAttribute_mTestVariable) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mLocation.objectCompare (p->mAttribute_mLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mThenInstructionGenerationList.objectCompare (p->mAttribute_mThenInstructionGenerationList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mElseInstructionGenerationList.objectCompare (p->mAttribute_mElseInstructionGenerationList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_ifInstructionIR::objectCompare (const GALGAS_ifInstructionIR & inOperand) const {
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

GALGAS_ifInstructionIR::GALGAS_ifInstructionIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ifInstructionIR::GALGAS_ifInstructionIR (const cPtr_ifInstructionIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_ifInstructionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ifInstructionIR GALGAS_ifInstructionIR::constructor_new (const GALGAS_operandIR & inAttribute_mTestVariable,
                                                                const GALGAS_location & inAttribute_mLocation,
                                                                const GALGAS_instructionListIR & inAttribute_mThenInstructionGenerationList,
                                                                const GALGAS_instructionListIR & inAttribute_mElseInstructionGenerationList
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_ifInstructionIR result ;
  if (inAttribute_mTestVariable.isValid () && inAttribute_mLocation.isValid () && inAttribute_mThenInstructionGenerationList.isValid () && inAttribute_mElseInstructionGenerationList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_ifInstructionIR (inAttribute_mTestVariable, inAttribute_mLocation, inAttribute_mThenInstructionGenerationList, inAttribute_mElseInstructionGenerationList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_ifInstructionIR::reader_mTestVariable (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifInstructionIR * p = (const cPtr_ifInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifInstructionIR) ;
    result = p->mAttribute_mTestVariable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_ifInstructionIR::reader_mTestVariable (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTestVariable ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_ifInstructionIR::reader_mLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifInstructionIR * p = (const cPtr_ifInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifInstructionIR) ;
    result = p->mAttribute_mLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_ifInstructionIR::reader_mLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_ifInstructionIR::reader_mThenInstructionGenerationList (UNUSED_LOCATION_ARGS) const {
  GALGAS_instructionListIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifInstructionIR * p = (const cPtr_ifInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifInstructionIR) ;
    result = p->mAttribute_mThenInstructionGenerationList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cPtr_ifInstructionIR::reader_mThenInstructionGenerationList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mThenInstructionGenerationList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_ifInstructionIR::reader_mElseInstructionGenerationList (UNUSED_LOCATION_ARGS) const {
  GALGAS_instructionListIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_ifInstructionIR * p = (const cPtr_ifInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ifInstructionIR) ;
    result = p->mAttribute_mElseInstructionGenerationList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cPtr_ifInstructionIR::reader_mElseInstructionGenerationList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mElseInstructionGenerationList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @ifInstructionIR class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_ifInstructionIR::cPtr_ifInstructionIR (const GALGAS_operandIR & in_mTestVariable,
                                            const GALGAS_location & in_mLocation,
                                            const GALGAS_instructionListIR & in_mThenInstructionGenerationList,
                                            const GALGAS_instructionListIR & in_mElseInstructionGenerationList
                                            COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mTestVariable (in_mTestVariable),
mAttribute_mLocation (in_mLocation),
mAttribute_mThenInstructionGenerationList (in_mThenInstructionGenerationList),
mAttribute_mElseInstructionGenerationList (in_mElseInstructionGenerationList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_ifInstructionIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ifInstructionIR ;
}

void cPtr_ifInstructionIR::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@ifInstructionIR:" ;
  mAttribute_mTestVariable.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mThenInstructionGenerationList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mElseInstructionGenerationList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_ifInstructionIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_ifInstructionIR (mAttribute_mTestVariable, mAttribute_mLocation, mAttribute_mThenInstructionGenerationList, mAttribute_mElseInstructionGenerationList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @ifInstructionIR type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ifInstructionIR ("ifInstructionIR",
                                        & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_ifInstructionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ifInstructionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_ifInstructionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ifInstructionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ifInstructionIR GALGAS_ifInstructionIR::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_ifInstructionIR result ;
  const GALGAS_ifInstructionIR * p = (const GALGAS_ifInstructionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ifInstructionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ifInstructionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_loadGlobalVariableIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_loadGlobalVariableIR * p = (const cPtr_loadGlobalVariableIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_loadGlobalVariableIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mTargetValue.objectCompare (p->mAttribute_mTargetValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mVariableName.objectCompare (p->mAttribute_mVariableName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mVariableType.objectCompare (p->mAttribute_mVariableType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mIsVolatile.objectCompare (p->mAttribute_mIsVolatile) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_loadGlobalVariableIR::objectCompare (const GALGAS_loadGlobalVariableIR & inOperand) const {
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

GALGAS_loadGlobalVariableIR::GALGAS_loadGlobalVariableIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadGlobalVariableIR::GALGAS_loadGlobalVariableIR (const cPtr_loadGlobalVariableIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_loadGlobalVariableIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadGlobalVariableIR GALGAS_loadGlobalVariableIR::constructor_new (const GALGAS_operandIR & inAttribute_mTargetValue,
                                                                          const GALGAS_string & inAttribute_mVariableName,
                                                                          const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mVariableType,
                                                                          const GALGAS_bool & inAttribute_mIsVolatile
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_loadGlobalVariableIR result ;
  if (inAttribute_mTargetValue.isValid () && inAttribute_mVariableName.isValid () && inAttribute_mVariableType.isValid () && inAttribute_mIsVolatile.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_loadGlobalVariableIR (inAttribute_mTargetValue, inAttribute_mVariableName, inAttribute_mVariableType, inAttribute_mIsVolatile COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_loadGlobalVariableIR::reader_mTargetValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadGlobalVariableIR * p = (const cPtr_loadGlobalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadGlobalVariableIR) ;
    result = p->mAttribute_mTargetValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_loadGlobalVariableIR::reader_mTargetValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_loadGlobalVariableIR::reader_mVariableName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadGlobalVariableIR * p = (const cPtr_loadGlobalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadGlobalVariableIR) ;
    result = p->mAttribute_mVariableName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_loadGlobalVariableIR::reader_mVariableName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mVariableName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_loadGlobalVariableIR::reader_mVariableType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadGlobalVariableIR * p = (const cPtr_loadGlobalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadGlobalVariableIR) ;
    result = p->mAttribute_mVariableType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_loadGlobalVariableIR::reader_mVariableType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mVariableType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_loadGlobalVariableIR::reader_mIsVolatile (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadGlobalVariableIR * p = (const cPtr_loadGlobalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadGlobalVariableIR) ;
    result = p->mAttribute_mIsVolatile ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_loadGlobalVariableIR::reader_mIsVolatile (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIsVolatile ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @loadGlobalVariableIR class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_loadGlobalVariableIR::cPtr_loadGlobalVariableIR (const GALGAS_operandIR & in_mTargetValue,
                                                      const GALGAS_string & in_mVariableName,
                                                      const GALGAS_unifiedTypeMap_2D_proxy & in_mVariableType,
                                                      const GALGAS_bool & in_mIsVolatile
                                                      COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mTargetValue (in_mTargetValue),
mAttribute_mVariableName (in_mVariableName),
mAttribute_mVariableType (in_mVariableType),
mAttribute_mIsVolatile (in_mIsVolatile) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_loadGlobalVariableIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_loadGlobalVariableIR ;
}

void cPtr_loadGlobalVariableIR::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@loadGlobalVariableIR:" ;
  mAttribute_mTargetValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mVariableName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mVariableType.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mIsVolatile.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_loadGlobalVariableIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_loadGlobalVariableIR (mAttribute_mTargetValue, mAttribute_mVariableName, mAttribute_mVariableType, mAttribute_mIsVolatile COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @loadGlobalVariableIR type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_loadGlobalVariableIR ("loadGlobalVariableIR",
                                             & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_loadGlobalVariableIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_loadGlobalVariableIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_loadGlobalVariableIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_loadGlobalVariableIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadGlobalVariableIR GALGAS_loadGlobalVariableIR::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_loadGlobalVariableIR result ;
  const GALGAS_loadGlobalVariableIR * p = (const GALGAS_loadGlobalVariableIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_loadGlobalVariableIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("loadGlobalVariableIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_loadLocalVariableIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_loadLocalVariableIR * p = (const cPtr_loadLocalVariableIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_loadLocalVariableIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mTargetValue.objectCompare (p->mAttribute_mTargetValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mVariableName.objectCompare (p->mAttribute_mVariableName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mVariableType.objectCompare (p->mAttribute_mVariableType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_loadLocalVariableIR::objectCompare (const GALGAS_loadLocalVariableIR & inOperand) const {
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

GALGAS_loadLocalVariableIR::GALGAS_loadLocalVariableIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadLocalVariableIR::GALGAS_loadLocalVariableIR (const cPtr_loadLocalVariableIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_loadLocalVariableIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadLocalVariableIR GALGAS_loadLocalVariableIR::constructor_new (const GALGAS_operandIR & inAttribute_mTargetValue,
                                                                        const GALGAS_string & inAttribute_mVariableName,
                                                                        const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mVariableType
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_loadLocalVariableIR result ;
  if (inAttribute_mTargetValue.isValid () && inAttribute_mVariableName.isValid () && inAttribute_mVariableType.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_loadLocalVariableIR (inAttribute_mTargetValue, inAttribute_mVariableName, inAttribute_mVariableType COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_loadLocalVariableIR::reader_mTargetValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadLocalVariableIR * p = (const cPtr_loadLocalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadLocalVariableIR) ;
    result = p->mAttribute_mTargetValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_loadLocalVariableIR::reader_mTargetValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_loadLocalVariableIR::reader_mVariableName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadLocalVariableIR * p = (const cPtr_loadLocalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadLocalVariableIR) ;
    result = p->mAttribute_mVariableName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_loadLocalVariableIR::reader_mVariableName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mVariableName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_loadLocalVariableIR::reader_mVariableType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadLocalVariableIR * p = (const cPtr_loadLocalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadLocalVariableIR) ;
    result = p->mAttribute_mVariableType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_loadLocalVariableIR::reader_mVariableType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mVariableType ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @loadLocalVariableIR class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_loadLocalVariableIR::cPtr_loadLocalVariableIR (const GALGAS_operandIR & in_mTargetValue,
                                                    const GALGAS_string & in_mVariableName,
                                                    const GALGAS_unifiedTypeMap_2D_proxy & in_mVariableType
                                                    COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mTargetValue (in_mTargetValue),
mAttribute_mVariableName (in_mVariableName),
mAttribute_mVariableType (in_mVariableType) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_loadLocalVariableIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_loadLocalVariableIR ;
}

void cPtr_loadLocalVariableIR::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@loadLocalVariableIR:" ;
  mAttribute_mTargetValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mVariableName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mVariableType.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_loadLocalVariableIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_loadLocalVariableIR (mAttribute_mTargetValue, mAttribute_mVariableName, mAttribute_mVariableType COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @loadLocalVariableIR type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_loadLocalVariableIR ("loadLocalVariableIR",
                                            & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_loadLocalVariableIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_loadLocalVariableIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_loadLocalVariableIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_loadLocalVariableIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadLocalVariableIR GALGAS_loadLocalVariableIR::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_loadLocalVariableIR result ;
  const GALGAS_loadLocalVariableIR * p = (const GALGAS_loadLocalVariableIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_loadLocalVariableIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("loadLocalVariableIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_loadRegisterIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_loadRegisterIR * p = (const cPtr_loadRegisterIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_loadRegisterIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mTargetValue.objectCompare (p->mAttribute_mTargetValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mRegisterName.objectCompare (p->mAttribute_mRegisterName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mRegisterType.objectCompare (p->mAttribute_mRegisterType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mRegisterAddress.objectCompare (p->mAttribute_mRegisterAddress) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_loadRegisterIR::objectCompare (const GALGAS_loadRegisterIR & inOperand) const {
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

GALGAS_loadRegisterIR::GALGAS_loadRegisterIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadRegisterIR::GALGAS_loadRegisterIR (const cPtr_loadRegisterIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_loadRegisterIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadRegisterIR GALGAS_loadRegisterIR::constructor_new (const GALGAS_operandIR & inAttribute_mTargetValue,
                                                              const GALGAS_string & inAttribute_mRegisterName,
                                                              const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mRegisterType,
                                                              const GALGAS_bigint & inAttribute_mRegisterAddress
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_loadRegisterIR result ;
  if (inAttribute_mTargetValue.isValid () && inAttribute_mRegisterName.isValid () && inAttribute_mRegisterType.isValid () && inAttribute_mRegisterAddress.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_loadRegisterIR (inAttribute_mTargetValue, inAttribute_mRegisterName, inAttribute_mRegisterType, inAttribute_mRegisterAddress COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_loadRegisterIR::reader_mTargetValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadRegisterIR * p = (const cPtr_loadRegisterIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadRegisterIR) ;
    result = p->mAttribute_mTargetValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_loadRegisterIR::reader_mTargetValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_loadRegisterIR::reader_mRegisterName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadRegisterIR * p = (const cPtr_loadRegisterIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadRegisterIR) ;
    result = p->mAttribute_mRegisterName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_loadRegisterIR::reader_mRegisterName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_loadRegisterIR::reader_mRegisterType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadRegisterIR * p = (const cPtr_loadRegisterIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadRegisterIR) ;
    result = p->mAttribute_mRegisterType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_loadRegisterIR::reader_mRegisterType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_loadRegisterIR::reader_mRegisterAddress (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadRegisterIR * p = (const cPtr_loadRegisterIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadRegisterIR) ;
    result = p->mAttribute_mRegisterAddress ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_loadRegisterIR::reader_mRegisterAddress (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterAddress ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @loadRegisterIR class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_loadRegisterIR::cPtr_loadRegisterIR (const GALGAS_operandIR & in_mTargetValue,
                                          const GALGAS_string & in_mRegisterName,
                                          const GALGAS_unifiedTypeMap_2D_proxy & in_mRegisterType,
                                          const GALGAS_bigint & in_mRegisterAddress
                                          COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mTargetValue (in_mTargetValue),
mAttribute_mRegisterName (in_mRegisterName),
mAttribute_mRegisterType (in_mRegisterType),
mAttribute_mRegisterAddress (in_mRegisterAddress) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_loadRegisterIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_loadRegisterIR ;
}

void cPtr_loadRegisterIR::description (C_String & ioString,
                                       const int32_t inIndentation) const {
  ioString << "[@loadRegisterIR:" ;
  mAttribute_mTargetValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mRegisterName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mRegisterType.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mRegisterAddress.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_loadRegisterIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_loadRegisterIR (mAttribute_mTargetValue, mAttribute_mRegisterName, mAttribute_mRegisterType, mAttribute_mRegisterAddress COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @loadRegisterIR type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_loadRegisterIR ("loadRegisterIR",
                                       & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_loadRegisterIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_loadRegisterIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_loadRegisterIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_loadRegisterIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadRegisterIR GALGAS_loadRegisterIR::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_loadRegisterIR result ;
  const GALGAS_loadRegisterIR * p = (const GALGAS_loadRegisterIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_loadRegisterIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("loadRegisterIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_prefixOperatorExpressionIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_prefixOperatorExpressionIR * p = (const cPtr_prefixOperatorExpressionIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_prefixOperatorExpressionIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mTargetType.objectCompare (p->mAttribute_mTargetType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mResult.objectCompare (p->mAttribute_mResult) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mOperand.objectCompare (p->mAttribute_mOperand) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mOperator.objectCompare (p->mAttribute_mOperator) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mOperatorLocation.objectCompare (p->mAttribute_mOperatorLocation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_prefixOperatorExpressionIR::objectCompare (const GALGAS_prefixOperatorExpressionIR & inOperand) const {
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

GALGAS_prefixOperatorExpressionIR::GALGAS_prefixOperatorExpressionIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorExpressionIR::GALGAS_prefixOperatorExpressionIR (const cPtr_prefixOperatorExpressionIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_prefixOperatorExpressionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorExpressionIR GALGAS_prefixOperatorExpressionIR::constructor_new (const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mTargetType,
                                                                                      const GALGAS_operandIR & inAttribute_mResult,
                                                                                      const GALGAS_operandIR & inAttribute_mOperand,
                                                                                      const GALGAS_prefixOperatorIR & inAttribute_mOperator,
                                                                                      const GALGAS_location & inAttribute_mOperatorLocation
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_prefixOperatorExpressionIR result ;
  if (inAttribute_mTargetType.isValid () && inAttribute_mResult.isValid () && inAttribute_mOperand.isValid () && inAttribute_mOperator.isValid () && inAttribute_mOperatorLocation.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_prefixOperatorExpressionIR (inAttribute_mTargetType, inAttribute_mResult, inAttribute_mOperand, inAttribute_mOperator, inAttribute_mOperatorLocation COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_prefixOperatorExpressionIR::reader_mTargetType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_prefixOperatorExpressionIR * p = (const cPtr_prefixOperatorExpressionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_prefixOperatorExpressionIR) ;
    result = p->mAttribute_mTargetType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_prefixOperatorExpressionIR::reader_mTargetType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_prefixOperatorExpressionIR::reader_mResult (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_prefixOperatorExpressionIR * p = (const cPtr_prefixOperatorExpressionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_prefixOperatorExpressionIR) ;
    result = p->mAttribute_mResult ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_prefixOperatorExpressionIR::reader_mResult (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mResult ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_prefixOperatorExpressionIR::reader_mOperand (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_prefixOperatorExpressionIR * p = (const cPtr_prefixOperatorExpressionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_prefixOperatorExpressionIR) ;
    result = p->mAttribute_mOperand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_prefixOperatorExpressionIR::reader_mOperand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorIR GALGAS_prefixOperatorExpressionIR::reader_mOperator (UNUSED_LOCATION_ARGS) const {
  GALGAS_prefixOperatorIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_prefixOperatorExpressionIR * p = (const cPtr_prefixOperatorExpressionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_prefixOperatorExpressionIR) ;
    result = p->mAttribute_mOperator ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorIR cPtr_prefixOperatorExpressionIR::reader_mOperator (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperator ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_prefixOperatorExpressionIR::reader_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_prefixOperatorExpressionIR * p = (const cPtr_prefixOperatorExpressionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_prefixOperatorExpressionIR) ;
    result = p->mAttribute_mOperatorLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_prefixOperatorExpressionIR::reader_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperatorLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @prefixOperatorExpressionIR class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_prefixOperatorExpressionIR::cPtr_prefixOperatorExpressionIR (const GALGAS_unifiedTypeMap_2D_proxy & in_mTargetType,
                                                                  const GALGAS_operandIR & in_mResult,
                                                                  const GALGAS_operandIR & in_mOperand,
                                                                  const GALGAS_prefixOperatorIR & in_mOperator,
                                                                  const GALGAS_location & in_mOperatorLocation
                                                                  COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mTargetType (in_mTargetType),
mAttribute_mResult (in_mResult),
mAttribute_mOperand (in_mOperand),
mAttribute_mOperator (in_mOperator),
mAttribute_mOperatorLocation (in_mOperatorLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_prefixOperatorExpressionIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefixOperatorExpressionIR ;
}

void cPtr_prefixOperatorExpressionIR::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@prefixOperatorExpressionIR:" ;
  mAttribute_mTargetType.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mResult.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mOperand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mOperator.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mOperatorLocation.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_prefixOperatorExpressionIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_prefixOperatorExpressionIR (mAttribute_mTargetType, mAttribute_mResult, mAttribute_mOperand, mAttribute_mOperator, mAttribute_mOperatorLocation COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @prefixOperatorExpressionIR type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_prefixOperatorExpressionIR ("prefixOperatorExpressionIR",
                                                   & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_prefixOperatorExpressionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefixOperatorExpressionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_prefixOperatorExpressionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_prefixOperatorExpressionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorExpressionIR GALGAS_prefixOperatorExpressionIR::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_prefixOperatorExpressionIR result ;
  const GALGAS_prefixOperatorExpressionIR * p = (const GALGAS_prefixOperatorExpressionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_prefixOperatorExpressionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("prefixOperatorExpressionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_procCallInstructionIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_procCallInstructionIR * p = (const cPtr_procCallInstructionIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_procCallInstructionIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mProcName.objectCompare (p->mAttribute_mProcName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mParameters.objectCompare (p->mAttribute_mParameters) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_procCallInstructionIR::objectCompare (const GALGAS_procCallInstructionIR & inOperand) const {
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

GALGAS_procCallInstructionIR::GALGAS_procCallInstructionIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallInstructionIR GALGAS_procCallInstructionIR::constructor_default (LOCATION_ARGS) {
  return GALGAS_procCallInstructionIR::constructor_new (GALGAS_string::constructor_default (HERE),
                                                        GALGAS_procCallEffectiveParameterListIR::constructor_emptyList (HERE)
                                                        COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallInstructionIR::GALGAS_procCallInstructionIR (const cPtr_procCallInstructionIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_procCallInstructionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallInstructionIR GALGAS_procCallInstructionIR::constructor_new (const GALGAS_string & inAttribute_mProcName,
                                                                            const GALGAS_procCallEffectiveParameterListIR & inAttribute_mParameters
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_procCallInstructionIR result ;
  if (inAttribute_mProcName.isValid () && inAttribute_mParameters.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_procCallInstructionIR (inAttribute_mProcName, inAttribute_mParameters COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_procCallInstructionIR::reader_mProcName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_procCallInstructionIR * p = (const cPtr_procCallInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_procCallInstructionIR) ;
    result = p->mAttribute_mProcName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_procCallInstructionIR::reader_mProcName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mProcName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR GALGAS_procCallInstructionIR::reader_mParameters (UNUSED_LOCATION_ARGS) const {
  GALGAS_procCallEffectiveParameterListIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_procCallInstructionIR * p = (const cPtr_procCallInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_procCallInstructionIR) ;
    result = p->mAttribute_mParameters ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR cPtr_procCallInstructionIR::reader_mParameters (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mParameters ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @procCallInstructionIR class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_procCallInstructionIR::cPtr_procCallInstructionIR (const GALGAS_string & in_mProcName,
                                                        const GALGAS_procCallEffectiveParameterListIR & in_mParameters
                                                        COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mProcName (in_mProcName),
mAttribute_mParameters (in_mParameters) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_procCallInstructionIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procCallInstructionIR ;
}

void cPtr_procCallInstructionIR::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@procCallInstructionIR:" ;
  mAttribute_mProcName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mParameters.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_procCallInstructionIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_procCallInstructionIR (mAttribute_mProcName, mAttribute_mParameters COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @procCallInstructionIR type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procCallInstructionIR ("procCallInstructionIR",
                                              & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procCallInstructionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procCallInstructionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procCallInstructionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procCallInstructionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallInstructionIR GALGAS_procCallInstructionIR::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_procCallInstructionIR result ;
  const GALGAS_procCallInstructionIR * p = (const GALGAS_procCallInstructionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procCallInstructionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procCallInstructionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_registerIntegerConstantInExpressionIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_registerIntegerConstantInExpressionIR * p = (const cPtr_registerIntegerConstantInExpressionIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_registerIntegerConstantInExpressionIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mInstructionLocation.objectCompare (p->mAttribute_mInstructionLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mExpressionValue.objectCompare (p->mAttribute_mExpressionValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mMaxBound.objectCompare (p->mAttribute_mMaxBound) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mBitShift.objectCompare (p->mAttribute_mBitShift) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mResultVariable.objectCompare (p->mAttribute_mResultVariable) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mTargetType.objectCompare (p->mAttribute_mTargetType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mNoCheck.objectCompare (p->mAttribute_mNoCheck) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_registerIntegerConstantInExpressionIR::objectCompare (const GALGAS_registerIntegerConstantInExpressionIR & inOperand) const {
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

GALGAS_registerIntegerConstantInExpressionIR::GALGAS_registerIntegerConstantInExpressionIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerConstantInExpressionIR::GALGAS_registerIntegerConstantInExpressionIR (const cPtr_registerIntegerConstantInExpressionIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_registerIntegerConstantInExpressionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerConstantInExpressionIR GALGAS_registerIntegerConstantInExpressionIR::constructor_new (const GALGAS_location & inAttribute_mInstructionLocation,
                                                                                                            const GALGAS_operandIR & inAttribute_mExpressionValue,
                                                                                                            const GALGAS_uint_36__34_ & inAttribute_mMaxBound,
                                                                                                            const GALGAS_uint & inAttribute_mBitShift,
                                                                                                            const GALGAS_operandIR & inAttribute_mResultVariable,
                                                                                                            const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mTargetType,
                                                                                                            const GALGAS_bool & inAttribute_mNoCheck
                                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_registerIntegerConstantInExpressionIR result ;
  if (inAttribute_mInstructionLocation.isValid () && inAttribute_mExpressionValue.isValid () && inAttribute_mMaxBound.isValid () && inAttribute_mBitShift.isValid () && inAttribute_mResultVariable.isValid () && inAttribute_mTargetType.isValid () && inAttribute_mNoCheck.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_registerIntegerConstantInExpressionIR (inAttribute_mInstructionLocation, inAttribute_mExpressionValue, inAttribute_mMaxBound, inAttribute_mBitShift, inAttribute_mResultVariable, inAttribute_mTargetType, inAttribute_mNoCheck COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_registerIntegerConstantInExpressionIR::reader_mInstructionLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_registerIntegerConstantInExpressionIR * p = (const cPtr_registerIntegerConstantInExpressionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_registerIntegerConstantInExpressionIR) ;
    result = p->mAttribute_mInstructionLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_registerIntegerConstantInExpressionIR::reader_mInstructionLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInstructionLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_registerIntegerConstantInExpressionIR::reader_mExpressionValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_registerIntegerConstantInExpressionIR * p = (const cPtr_registerIntegerConstantInExpressionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_registerIntegerConstantInExpressionIR) ;
    result = p->mAttribute_mExpressionValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_registerIntegerConstantInExpressionIR::reader_mExpressionValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mExpressionValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_registerIntegerConstantInExpressionIR::reader_mMaxBound (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_registerIntegerConstantInExpressionIR * p = (const cPtr_registerIntegerConstantInExpressionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_registerIntegerConstantInExpressionIR) ;
    result = p->mAttribute_mMaxBound ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ cPtr_registerIntegerConstantInExpressionIR::reader_mMaxBound (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mMaxBound ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_registerIntegerConstantInExpressionIR::reader_mBitShift (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_registerIntegerConstantInExpressionIR * p = (const cPtr_registerIntegerConstantInExpressionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_registerIntegerConstantInExpressionIR) ;
    result = p->mAttribute_mBitShift ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_registerIntegerConstantInExpressionIR::reader_mBitShift (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mBitShift ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_registerIntegerConstantInExpressionIR::reader_mResultVariable (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_registerIntegerConstantInExpressionIR * p = (const cPtr_registerIntegerConstantInExpressionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_registerIntegerConstantInExpressionIR) ;
    result = p->mAttribute_mResultVariable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_registerIntegerConstantInExpressionIR::reader_mResultVariable (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mResultVariable ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_registerIntegerConstantInExpressionIR::reader_mTargetType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_registerIntegerConstantInExpressionIR * p = (const cPtr_registerIntegerConstantInExpressionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_registerIntegerConstantInExpressionIR) ;
    result = p->mAttribute_mTargetType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_registerIntegerConstantInExpressionIR::reader_mTargetType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_registerIntegerConstantInExpressionIR::reader_mNoCheck (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_registerIntegerConstantInExpressionIR * p = (const cPtr_registerIntegerConstantInExpressionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_registerIntegerConstantInExpressionIR) ;
    result = p->mAttribute_mNoCheck ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_registerIntegerConstantInExpressionIR::reader_mNoCheck (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mNoCheck ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                           Pointer class for @registerIntegerConstantInExpressionIR class                            *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_registerIntegerConstantInExpressionIR::cPtr_registerIntegerConstantInExpressionIR (const GALGAS_location & in_mInstructionLocation,
                                                                                        const GALGAS_operandIR & in_mExpressionValue,
                                                                                        const GALGAS_uint_36__34_ & in_mMaxBound,
                                                                                        const GALGAS_uint & in_mBitShift,
                                                                                        const GALGAS_operandIR & in_mResultVariable,
                                                                                        const GALGAS_unifiedTypeMap_2D_proxy & in_mTargetType,
                                                                                        const GALGAS_bool & in_mNoCheck
                                                                                        COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mInstructionLocation (in_mInstructionLocation),
mAttribute_mExpressionValue (in_mExpressionValue),
mAttribute_mMaxBound (in_mMaxBound),
mAttribute_mBitShift (in_mBitShift),
mAttribute_mResultVariable (in_mResultVariable),
mAttribute_mTargetType (in_mTargetType),
mAttribute_mNoCheck (in_mNoCheck) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_registerIntegerConstantInExpressionIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_registerIntegerConstantInExpressionIR ;
}

void cPtr_registerIntegerConstantInExpressionIR::description (C_String & ioString,
                                                              const int32_t inIndentation) const {
  ioString << "[@registerIntegerConstantInExpressionIR:" ;
  mAttribute_mInstructionLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mExpressionValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mMaxBound.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mBitShift.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mResultVariable.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mTargetType.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mNoCheck.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_registerIntegerConstantInExpressionIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_registerIntegerConstantInExpressionIR (mAttribute_mInstructionLocation, mAttribute_mExpressionValue, mAttribute_mMaxBound, mAttribute_mBitShift, mAttribute_mResultVariable, mAttribute_mTargetType, mAttribute_mNoCheck COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     @registerIntegerConstantInExpressionIR type                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_registerIntegerConstantInExpressionIR ("registerIntegerConstantInExpressionIR",
                                                              & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_registerIntegerConstantInExpressionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_registerIntegerConstantInExpressionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_registerIntegerConstantInExpressionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_registerIntegerConstantInExpressionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerIntegerConstantInExpressionIR GALGAS_registerIntegerConstantInExpressionIR::extractObject (const GALGAS_object & inObject,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_registerIntegerConstantInExpressionIR result ;
  const GALGAS_registerIntegerConstantInExpressionIR * p = (const GALGAS_registerIntegerConstantInExpressionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_registerIntegerConstantInExpressionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("registerIntegerConstantInExpressionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_shortCircuitAndOperationIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mTargetOperand.objectCompare (p->mAttribute_mTargetOperand) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mLeftOperand.objectCompare (p->mAttribute_mLeftOperand) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mLeftInstructionList.objectCompare (p->mAttribute_mLeftInstructionList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mRightOperand.objectCompare (p->mAttribute_mRightOperand) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mRightInstructionList.objectCompare (p->mAttribute_mRightInstructionList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mLocation.objectCompare (p->mAttribute_mLocation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_shortCircuitAndOperationIR::objectCompare (const GALGAS_shortCircuitAndOperationIR & inOperand) const {
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

GALGAS_shortCircuitAndOperationIR::GALGAS_shortCircuitAndOperationIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_shortCircuitAndOperationIR::GALGAS_shortCircuitAndOperationIR (const cPtr_shortCircuitAndOperationIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_shortCircuitAndOperationIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_shortCircuitAndOperationIR GALGAS_shortCircuitAndOperationIR::constructor_new (const GALGAS_operandIR & inAttribute_mTargetOperand,
                                                                                      const GALGAS_operandIR & inAttribute_mLeftOperand,
                                                                                      const GALGAS_instructionListIR & inAttribute_mLeftInstructionList,
                                                                                      const GALGAS_operandIR & inAttribute_mRightOperand,
                                                                                      const GALGAS_instructionListIR & inAttribute_mRightInstructionList,
                                                                                      const GALGAS_location & inAttribute_mLocation
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_shortCircuitAndOperationIR result ;
  if (inAttribute_mTargetOperand.isValid () && inAttribute_mLeftOperand.isValid () && inAttribute_mLeftInstructionList.isValid () && inAttribute_mRightOperand.isValid () && inAttribute_mRightInstructionList.isValid () && inAttribute_mLocation.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_shortCircuitAndOperationIR (inAttribute_mTargetOperand, inAttribute_mLeftOperand, inAttribute_mLeftInstructionList, inAttribute_mRightOperand, inAttribute_mRightInstructionList, inAttribute_mLocation COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_shortCircuitAndOperationIR::reader_mTargetOperand (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
    result = p->mAttribute_mTargetOperand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_shortCircuitAndOperationIR::reader_mTargetOperand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_shortCircuitAndOperationIR::reader_mLeftOperand (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
    result = p->mAttribute_mLeftOperand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_shortCircuitAndOperationIR::reader_mLeftOperand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLeftOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_shortCircuitAndOperationIR::reader_mLeftInstructionList (UNUSED_LOCATION_ARGS) const {
  GALGAS_instructionListIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
    result = p->mAttribute_mLeftInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cPtr_shortCircuitAndOperationIR::reader_mLeftInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLeftInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_shortCircuitAndOperationIR::reader_mRightOperand (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
    result = p->mAttribute_mRightOperand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_shortCircuitAndOperationIR::reader_mRightOperand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRightOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_shortCircuitAndOperationIR::reader_mRightInstructionList (UNUSED_LOCATION_ARGS) const {
  GALGAS_instructionListIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
    result = p->mAttribute_mRightInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cPtr_shortCircuitAndOperationIR::reader_mRightInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRightInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_shortCircuitAndOperationIR::reader_mLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
    result = p->mAttribute_mLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_shortCircuitAndOperationIR::reader_mLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @shortCircuitAndOperationIR class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_shortCircuitAndOperationIR::cPtr_shortCircuitAndOperationIR (const GALGAS_operandIR & in_mTargetOperand,
                                                                  const GALGAS_operandIR & in_mLeftOperand,
                                                                  const GALGAS_instructionListIR & in_mLeftInstructionList,
                                                                  const GALGAS_operandIR & in_mRightOperand,
                                                                  const GALGAS_instructionListIR & in_mRightInstructionList,
                                                                  const GALGAS_location & in_mLocation
                                                                  COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mTargetOperand (in_mTargetOperand),
mAttribute_mLeftOperand (in_mLeftOperand),
mAttribute_mLeftInstructionList (in_mLeftInstructionList),
mAttribute_mRightOperand (in_mRightOperand),
mAttribute_mRightInstructionList (in_mRightInstructionList),
mAttribute_mLocation (in_mLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_shortCircuitAndOperationIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_shortCircuitAndOperationIR ;
}

void cPtr_shortCircuitAndOperationIR::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@shortCircuitAndOperationIR:" ;
  mAttribute_mTargetOperand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mLeftOperand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mLeftInstructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mRightOperand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mRightInstructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mLocation.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_shortCircuitAndOperationIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_shortCircuitAndOperationIR (mAttribute_mTargetOperand, mAttribute_mLeftOperand, mAttribute_mLeftInstructionList, mAttribute_mRightOperand, mAttribute_mRightInstructionList, mAttribute_mLocation COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @shortCircuitAndOperationIR type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_shortCircuitAndOperationIR ("shortCircuitAndOperationIR",
                                                   & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_shortCircuitAndOperationIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_shortCircuitAndOperationIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_shortCircuitAndOperationIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_shortCircuitAndOperationIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_shortCircuitAndOperationIR GALGAS_shortCircuitAndOperationIR::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_shortCircuitAndOperationIR result ;
  const GALGAS_shortCircuitAndOperationIR * p = (const GALGAS_shortCircuitAndOperationIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_shortCircuitAndOperationIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("shortCircuitAndOperationIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_storeGlobalVariableIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_storeGlobalVariableIR * p = (const cPtr_storeGlobalVariableIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_storeGlobalVariableIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mGlobalVarName.objectCompare (p->mAttribute_mGlobalVarName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mTargetVarType.objectCompare (p->mAttribute_mTargetVarType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mSourceValue.objectCompare (p->mAttribute_mSourceValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mIsVolatile.objectCompare (p->mAttribute_mIsVolatile) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_storeGlobalVariableIR::objectCompare (const GALGAS_storeGlobalVariableIR & inOperand) const {
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

GALGAS_storeGlobalVariableIR::GALGAS_storeGlobalVariableIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_storeGlobalVariableIR::GALGAS_storeGlobalVariableIR (const cPtr_storeGlobalVariableIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_storeGlobalVariableIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_storeGlobalVariableIR GALGAS_storeGlobalVariableIR::constructor_new (const GALGAS_string & inAttribute_mGlobalVarName,
                                                                            const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mTargetVarType,
                                                                            const GALGAS_operandIR & inAttribute_mSourceValue,
                                                                            const GALGAS_bool & inAttribute_mIsVolatile
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_storeGlobalVariableIR result ;
  if (inAttribute_mGlobalVarName.isValid () && inAttribute_mTargetVarType.isValid () && inAttribute_mSourceValue.isValid () && inAttribute_mIsVolatile.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_storeGlobalVariableIR (inAttribute_mGlobalVarName, inAttribute_mTargetVarType, inAttribute_mSourceValue, inAttribute_mIsVolatile COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_storeGlobalVariableIR::reader_mGlobalVarName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_storeGlobalVariableIR * p = (const cPtr_storeGlobalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_storeGlobalVariableIR) ;
    result = p->mAttribute_mGlobalVarName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_storeGlobalVariableIR::reader_mGlobalVarName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGlobalVarName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_storeGlobalVariableIR::reader_mTargetVarType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_storeGlobalVariableIR * p = (const cPtr_storeGlobalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_storeGlobalVariableIR) ;
    result = p->mAttribute_mTargetVarType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_storeGlobalVariableIR::reader_mTargetVarType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetVarType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_storeGlobalVariableIR::reader_mSourceValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_storeGlobalVariableIR * p = (const cPtr_storeGlobalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_storeGlobalVariableIR) ;
    result = p->mAttribute_mSourceValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_storeGlobalVariableIR::reader_mSourceValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSourceValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_storeGlobalVariableIR::reader_mIsVolatile (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_storeGlobalVariableIR * p = (const cPtr_storeGlobalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_storeGlobalVariableIR) ;
    result = p->mAttribute_mIsVolatile ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_storeGlobalVariableIR::reader_mIsVolatile (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIsVolatile ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @storeGlobalVariableIR class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_storeGlobalVariableIR::cPtr_storeGlobalVariableIR (const GALGAS_string & in_mGlobalVarName,
                                                        const GALGAS_unifiedTypeMap_2D_proxy & in_mTargetVarType,
                                                        const GALGAS_operandIR & in_mSourceValue,
                                                        const GALGAS_bool & in_mIsVolatile
                                                        COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mGlobalVarName (in_mGlobalVarName),
mAttribute_mTargetVarType (in_mTargetVarType),
mAttribute_mSourceValue (in_mSourceValue),
mAttribute_mIsVolatile (in_mIsVolatile) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_storeGlobalVariableIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_storeGlobalVariableIR ;
}

void cPtr_storeGlobalVariableIR::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@storeGlobalVariableIR:" ;
  mAttribute_mGlobalVarName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mTargetVarType.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mSourceValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mIsVolatile.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_storeGlobalVariableIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_storeGlobalVariableIR (mAttribute_mGlobalVarName, mAttribute_mTargetVarType, mAttribute_mSourceValue, mAttribute_mIsVolatile COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @storeGlobalVariableIR type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_storeGlobalVariableIR ("storeGlobalVariableIR",
                                              & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_storeGlobalVariableIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_storeGlobalVariableIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_storeGlobalVariableIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_storeGlobalVariableIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_storeGlobalVariableIR GALGAS_storeGlobalVariableIR::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_storeGlobalVariableIR result ;
  const GALGAS_storeGlobalVariableIR * p = (const GALGAS_storeGlobalVariableIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_storeGlobalVariableIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("storeGlobalVariableIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_storeLocalVariableIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_storeLocalVariableIR * p = (const cPtr_storeLocalVariableIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_storeLocalVariableIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mLocalVarName.objectCompare (p->mAttribute_mLocalVarName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mTargetVarType.objectCompare (p->mAttribute_mTargetVarType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mSourceValue.objectCompare (p->mAttribute_mSourceValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_storeLocalVariableIR::objectCompare (const GALGAS_storeLocalVariableIR & inOperand) const {
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

GALGAS_storeLocalVariableIR::GALGAS_storeLocalVariableIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_storeLocalVariableIR::GALGAS_storeLocalVariableIR (const cPtr_storeLocalVariableIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_storeLocalVariableIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_storeLocalVariableIR GALGAS_storeLocalVariableIR::constructor_new (const GALGAS_string & inAttribute_mLocalVarName,
                                                                          const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mTargetVarType,
                                                                          const GALGAS_operandIR & inAttribute_mSourceValue
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_storeLocalVariableIR result ;
  if (inAttribute_mLocalVarName.isValid () && inAttribute_mTargetVarType.isValid () && inAttribute_mSourceValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_storeLocalVariableIR (inAttribute_mLocalVarName, inAttribute_mTargetVarType, inAttribute_mSourceValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_storeLocalVariableIR::reader_mLocalVarName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_storeLocalVariableIR * p = (const cPtr_storeLocalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_storeLocalVariableIR) ;
    result = p->mAttribute_mLocalVarName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_storeLocalVariableIR::reader_mLocalVarName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLocalVarName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_storeLocalVariableIR::reader_mTargetVarType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_storeLocalVariableIR * p = (const cPtr_storeLocalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_storeLocalVariableIR) ;
    result = p->mAttribute_mTargetVarType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_storeLocalVariableIR::reader_mTargetVarType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetVarType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_storeLocalVariableIR::reader_mSourceValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_storeLocalVariableIR * p = (const cPtr_storeLocalVariableIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_storeLocalVariableIR) ;
    result = p->mAttribute_mSourceValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_storeLocalVariableIR::reader_mSourceValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSourceValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @storeLocalVariableIR class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_storeLocalVariableIR::cPtr_storeLocalVariableIR (const GALGAS_string & in_mLocalVarName,
                                                      const GALGAS_unifiedTypeMap_2D_proxy & in_mTargetVarType,
                                                      const GALGAS_operandIR & in_mSourceValue
                                                      COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mLocalVarName (in_mLocalVarName),
mAttribute_mTargetVarType (in_mTargetVarType),
mAttribute_mSourceValue (in_mSourceValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_storeLocalVariableIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_storeLocalVariableIR ;
}

void cPtr_storeLocalVariableIR::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@storeLocalVariableIR:" ;
  mAttribute_mLocalVarName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mTargetVarType.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mSourceValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_storeLocalVariableIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_storeLocalVariableIR (mAttribute_mLocalVarName, mAttribute_mTargetVarType, mAttribute_mSourceValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @storeLocalVariableIR type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_storeLocalVariableIR ("storeLocalVariableIR",
                                             & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_storeLocalVariableIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_storeLocalVariableIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_storeLocalVariableIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_storeLocalVariableIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_storeLocalVariableIR GALGAS_storeLocalVariableIR::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_storeLocalVariableIR result ;
  const GALGAS_storeLocalVariableIR * p = (const GALGAS_storeLocalVariableIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_storeLocalVariableIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("storeLocalVariableIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_storeVolatileIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_storeVolatileIR * p = (const cPtr_storeVolatileIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_storeVolatileIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mRegisterName.objectCompare (p->mAttribute_mRegisterName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mTargetVarType.objectCompare (p->mAttribute_mTargetVarType) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mAddress.objectCompare (p->mAttribute_mAddress) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mSourceValue.objectCompare (p->mAttribute_mSourceValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_storeVolatileIR::objectCompare (const GALGAS_storeVolatileIR & inOperand) const {
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

GALGAS_storeVolatileIR::GALGAS_storeVolatileIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_storeVolatileIR::GALGAS_storeVolatileIR (const cPtr_storeVolatileIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_storeVolatileIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_storeVolatileIR GALGAS_storeVolatileIR::constructor_new (const GALGAS_string & inAttribute_mRegisterName,
                                                                const GALGAS_unifiedTypeMap_2D_proxy & inAttribute_mTargetVarType,
                                                                const GALGAS_bigint & inAttribute_mAddress,
                                                                const GALGAS_operandIR & inAttribute_mSourceValue
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_storeVolatileIR result ;
  if (inAttribute_mRegisterName.isValid () && inAttribute_mTargetVarType.isValid () && inAttribute_mAddress.isValid () && inAttribute_mSourceValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_storeVolatileIR (inAttribute_mRegisterName, inAttribute_mTargetVarType, inAttribute_mAddress, inAttribute_mSourceValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_storeVolatileIR::reader_mRegisterName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_storeVolatileIR * p = (const cPtr_storeVolatileIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_storeVolatileIR) ;
    result = p->mAttribute_mRegisterName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_storeVolatileIR::reader_mRegisterName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_storeVolatileIR::reader_mTargetVarType (UNUSED_LOCATION_ARGS) const {
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != mObjectPtr) {
    const cPtr_storeVolatileIR * p = (const cPtr_storeVolatileIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_storeVolatileIR) ;
    result = p->mAttribute_mTargetVarType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cPtr_storeVolatileIR::reader_mTargetVarType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTargetVarType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_storeVolatileIR::reader_mAddress (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_storeVolatileIR * p = (const cPtr_storeVolatileIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_storeVolatileIR) ;
    result = p->mAttribute_mAddress ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_storeVolatileIR::reader_mAddress (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAddress ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_storeVolatileIR::reader_mSourceValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_storeVolatileIR * p = (const cPtr_storeVolatileIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_storeVolatileIR) ;
    result = p->mAttribute_mSourceValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_storeVolatileIR::reader_mSourceValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSourceValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @storeVolatileIR class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_storeVolatileIR::cPtr_storeVolatileIR (const GALGAS_string & in_mRegisterName,
                                            const GALGAS_unifiedTypeMap_2D_proxy & in_mTargetVarType,
                                            const GALGAS_bigint & in_mAddress,
                                            const GALGAS_operandIR & in_mSourceValue
                                            COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mRegisterName (in_mRegisterName),
mAttribute_mTargetVarType (in_mTargetVarType),
mAttribute_mAddress (in_mAddress),
mAttribute_mSourceValue (in_mSourceValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_storeVolatileIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_storeVolatileIR ;
}

void cPtr_storeVolatileIR::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@storeVolatileIR:" ;
  mAttribute_mRegisterName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mTargetVarType.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mAddress.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mSourceValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_storeVolatileIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_storeVolatileIR (mAttribute_mRegisterName, mAttribute_mTargetVarType, mAttribute_mAddress, mAttribute_mSourceValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @storeVolatileIR type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_storeVolatileIR ("storeVolatileIR",
                                        & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_storeVolatileIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_storeVolatileIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_storeVolatileIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_storeVolatileIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_storeVolatileIR GALGAS_storeVolatileIR::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_storeVolatileIR result ;
  const GALGAS_storeVolatileIR * p = (const GALGAS_storeVolatileIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_storeVolatileIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("storeVolatileIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_throwInstructionIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_throwInstructionIR * p = (const cPtr_throwInstructionIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_throwInstructionIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mThrowInstructionLocation.objectCompare (p->mAttribute_mThrowInstructionLocation) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mCode.objectCompare (p->mAttribute_mCode) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_throwInstructionIR::objectCompare (const GALGAS_throwInstructionIR & inOperand) const {
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

GALGAS_throwInstructionIR::GALGAS_throwInstructionIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_throwInstructionIR::GALGAS_throwInstructionIR (const cPtr_throwInstructionIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_throwInstructionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_throwInstructionIR GALGAS_throwInstructionIR::constructor_new (const GALGAS_location & inAttribute_mThrowInstructionLocation,
                                                                      const GALGAS_operandIR & inAttribute_mCode
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_throwInstructionIR result ;
  if (inAttribute_mThrowInstructionLocation.isValid () && inAttribute_mCode.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_throwInstructionIR (inAttribute_mThrowInstructionLocation, inAttribute_mCode COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_throwInstructionIR::reader_mThrowInstructionLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_throwInstructionIR * p = (const cPtr_throwInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_throwInstructionIR) ;
    result = p->mAttribute_mThrowInstructionLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_throwInstructionIR::reader_mThrowInstructionLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mThrowInstructionLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_throwInstructionIR::reader_mCode (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_throwInstructionIR * p = (const cPtr_throwInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_throwInstructionIR) ;
    result = p->mAttribute_mCode ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_throwInstructionIR::reader_mCode (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mCode ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @throwInstructionIR class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_throwInstructionIR::cPtr_throwInstructionIR (const GALGAS_location & in_mThrowInstructionLocation,
                                                  const GALGAS_operandIR & in_mCode
                                                  COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mThrowInstructionLocation (in_mThrowInstructionLocation),
mAttribute_mCode (in_mCode) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_throwInstructionIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_throwInstructionIR ;
}

void cPtr_throwInstructionIR::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@throwInstructionIR:" ;
  mAttribute_mThrowInstructionLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mCode.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_throwInstructionIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_throwInstructionIR (mAttribute_mThrowInstructionLocation, mAttribute_mCode COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @throwInstructionIR type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_throwInstructionIR ("throwInstructionIR",
                                           & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_throwInstructionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_throwInstructionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_throwInstructionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_throwInstructionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_throwInstructionIR GALGAS_throwInstructionIR::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_throwInstructionIR result ;
  const GALGAS_throwInstructionIR * p = (const GALGAS_throwInstructionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_throwInstructionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("throwInstructionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_whileInstructionIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_whileInstructionIR * p = (const cPtr_whileInstructionIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_whileInstructionIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mLabelIndex.objectCompare (p->mAttribute_mLabelIndex) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mTestInstructionGenerationList.objectCompare (p->mAttribute_mTestInstructionGenerationList) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mTestExpression.objectCompare (p->mAttribute_mTestExpression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mInstructionGenerationList.objectCompare (p->mAttribute_mInstructionGenerationList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_whileInstructionIR::objectCompare (const GALGAS_whileInstructionIR & inOperand) const {
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

GALGAS_whileInstructionIR::GALGAS_whileInstructionIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_whileInstructionIR::GALGAS_whileInstructionIR (const cPtr_whileInstructionIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_whileInstructionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_whileInstructionIR GALGAS_whileInstructionIR::constructor_new (const GALGAS_uint & inAttribute_mLabelIndex,
                                                                      const GALGAS_instructionListIR & inAttribute_mTestInstructionGenerationList,
                                                                      const GALGAS_operandIR & inAttribute_mTestExpression,
                                                                      const GALGAS_instructionListIR & inAttribute_mInstructionGenerationList
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_whileInstructionIR result ;
  if (inAttribute_mLabelIndex.isValid () && inAttribute_mTestInstructionGenerationList.isValid () && inAttribute_mTestExpression.isValid () && inAttribute_mInstructionGenerationList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_whileInstructionIR (inAttribute_mLabelIndex, inAttribute_mTestInstructionGenerationList, inAttribute_mTestExpression, inAttribute_mInstructionGenerationList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_whileInstructionIR::reader_mLabelIndex (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_whileInstructionIR * p = (const cPtr_whileInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_whileInstructionIR) ;
    result = p->mAttribute_mLabelIndex ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_whileInstructionIR::reader_mLabelIndex (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLabelIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_whileInstructionIR::reader_mTestInstructionGenerationList (UNUSED_LOCATION_ARGS) const {
  GALGAS_instructionListIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_whileInstructionIR * p = (const cPtr_whileInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_whileInstructionIR) ;
    result = p->mAttribute_mTestInstructionGenerationList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cPtr_whileInstructionIR::reader_mTestInstructionGenerationList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTestInstructionGenerationList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_whileInstructionIR::reader_mTestExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_operandIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_whileInstructionIR * p = (const cPtr_whileInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_whileInstructionIR) ;
    result = p->mAttribute_mTestExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR cPtr_whileInstructionIR::reader_mTestExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTestExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_whileInstructionIR::reader_mInstructionGenerationList (UNUSED_LOCATION_ARGS) const {
  GALGAS_instructionListIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_whileInstructionIR * p = (const cPtr_whileInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_whileInstructionIR) ;
    result = p->mAttribute_mInstructionGenerationList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cPtr_whileInstructionIR::reader_mInstructionGenerationList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInstructionGenerationList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @whileInstructionIR class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_whileInstructionIR::cPtr_whileInstructionIR (const GALGAS_uint & in_mLabelIndex,
                                                  const GALGAS_instructionListIR & in_mTestInstructionGenerationList,
                                                  const GALGAS_operandIR & in_mTestExpression,
                                                  const GALGAS_instructionListIR & in_mInstructionGenerationList
                                                  COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mAttribute_mLabelIndex (in_mLabelIndex),
mAttribute_mTestInstructionGenerationList (in_mTestInstructionGenerationList),
mAttribute_mTestExpression (in_mTestExpression),
mAttribute_mInstructionGenerationList (in_mInstructionGenerationList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_whileInstructionIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_whileInstructionIR ;
}

void cPtr_whileInstructionIR::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@whileInstructionIR:" ;
  mAttribute_mLabelIndex.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mTestInstructionGenerationList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mTestExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mInstructionGenerationList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_whileInstructionIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_whileInstructionIR (mAttribute_mLabelIndex, mAttribute_mTestInstructionGenerationList, mAttribute_mTestExpression, mAttribute_mInstructionGenerationList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @whileInstructionIR type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_whileInstructionIR ("whileInstructionIR",
                                           & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_whileInstructionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_whileInstructionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_whileInstructionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_whileInstructionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_whileInstructionIR GALGAS_whileInstructionIR::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_whileInstructionIR result ;
  const GALGAS_whileInstructionIR * p = (const GALGAS_whileInstructionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_whileInstructionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("whileInstructionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_abstractTypeIR::objectCompare (const GALGAS_abstractTypeIR & inOperand) const {
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

GALGAS_abstractTypeIR::GALGAS_abstractTypeIR (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractTypeIR::GALGAS_abstractTypeIR (const cPtr_abstractTypeIR * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_abstractTypeIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @abstractTypeIR class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_abstractTypeIR::cPtr_abstractTypeIR (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @abstractTypeIR type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_abstractTypeIR ("abstractTypeIR",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_abstractTypeIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_abstractTypeIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_abstractTypeIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_abstractTypeIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractTypeIR GALGAS_abstractTypeIR::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_abstractTypeIR result ;
  const GALGAS_abstractTypeIR * p = (const GALGAS_abstractTypeIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_abstractTypeIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("abstractTypeIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_enumerationIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_enumerationIR * p = (const cPtr_enumerationIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_enumerationIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mEnumerationName.objectCompare (p->mAttribute_mEnumerationName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mActualTypeName.objectCompare (p->mAttribute_mActualTypeName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_enumerationIR::objectCompare (const GALGAS_enumerationIR & inOperand) const {
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

GALGAS_enumerationIR::GALGAS_enumerationIR (void) :
GALGAS_abstractTypeIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumerationIR GALGAS_enumerationIR::constructor_default (LOCATION_ARGS) {
  return GALGAS_enumerationIR::constructor_new (GALGAS_string::constructor_default (HERE),
                                                GALGAS_string::constructor_default (HERE)
                                                COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumerationIR::GALGAS_enumerationIR (const cPtr_enumerationIR * inSourcePtr) :
GALGAS_abstractTypeIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_enumerationIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumerationIR GALGAS_enumerationIR::constructor_new (const GALGAS_string & inAttribute_mEnumerationName,
                                                            const GALGAS_string & inAttribute_mActualTypeName
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_enumerationIR result ;
  if (inAttribute_mEnumerationName.isValid () && inAttribute_mActualTypeName.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_enumerationIR (inAttribute_mEnumerationName, inAttribute_mActualTypeName COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_enumerationIR::reader_mEnumerationName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_enumerationIR * p = (const cPtr_enumerationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumerationIR) ;
    result = p->mAttribute_mEnumerationName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_enumerationIR::reader_mEnumerationName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEnumerationName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_enumerationIR::reader_mActualTypeName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_enumerationIR * p = (const cPtr_enumerationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_enumerationIR) ;
    result = p->mAttribute_mActualTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_enumerationIR::reader_mActualTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mActualTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @enumerationIR class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_enumerationIR::cPtr_enumerationIR (const GALGAS_string & in_mEnumerationName,
                                        const GALGAS_string & in_mActualTypeName
                                        COMMA_LOCATION_ARGS) :
cPtr_abstractTypeIR (THERE),
mAttribute_mEnumerationName (in_mEnumerationName),
mAttribute_mActualTypeName (in_mActualTypeName) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_enumerationIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumerationIR ;
}

void cPtr_enumerationIR::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "[@enumerationIR:" ;
  mAttribute_mEnumerationName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mActualTypeName.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_enumerationIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_enumerationIR (mAttribute_mEnumerationName, mAttribute_mActualTypeName COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @enumerationIR type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_enumerationIR ("enumerationIR",
                                      & kTypeDescriptor_GALGAS_abstractTypeIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_enumerationIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumerationIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_enumerationIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_enumerationIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumerationIR GALGAS_enumerationIR::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_enumerationIR result ;
  const GALGAS_enumerationIR * p = (const GALGAS_enumerationIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_enumerationIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("enumerationIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_integerIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_integerIR * p = (const cPtr_integerIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_integerIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mIntegerTypeName.objectCompare (p->mAttribute_mIntegerTypeName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mActualTypeName.objectCompare (p->mAttribute_mActualTypeName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_integerIR::objectCompare (const GALGAS_integerIR & inOperand) const {
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

GALGAS_integerIR::GALGAS_integerIR (void) :
GALGAS_abstractTypeIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_integerIR GALGAS_integerIR::constructor_default (LOCATION_ARGS) {
  return GALGAS_integerIR::constructor_new (GALGAS_string::constructor_default (HERE),
                                            GALGAS_string::constructor_default (HERE)
                                            COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_integerIR::GALGAS_integerIR (const cPtr_integerIR * inSourcePtr) :
GALGAS_abstractTypeIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_integerIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_integerIR GALGAS_integerIR::constructor_new (const GALGAS_string & inAttribute_mIntegerTypeName,
                                                    const GALGAS_string & inAttribute_mActualTypeName
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_integerIR result ;
  if (inAttribute_mIntegerTypeName.isValid () && inAttribute_mActualTypeName.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_integerIR (inAttribute_mIntegerTypeName, inAttribute_mActualTypeName COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_integerIR::reader_mIntegerTypeName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_integerIR * p = (const cPtr_integerIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_integerIR) ;
    result = p->mAttribute_mIntegerTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_integerIR::reader_mIntegerTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIntegerTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_integerIR::reader_mActualTypeName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_integerIR * p = (const cPtr_integerIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_integerIR) ;
    result = p->mAttribute_mActualTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_integerIR::reader_mActualTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mActualTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                         Pointer class for @integerIR class                                          *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_integerIR::cPtr_integerIR (const GALGAS_string & in_mIntegerTypeName,
                                const GALGAS_string & in_mActualTypeName
                                COMMA_LOCATION_ARGS) :
cPtr_abstractTypeIR (THERE),
mAttribute_mIntegerTypeName (in_mIntegerTypeName),
mAttribute_mActualTypeName (in_mActualTypeName) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_integerIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_integerIR ;
}

void cPtr_integerIR::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "[@integerIR:" ;
  mAttribute_mIntegerTypeName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mActualTypeName.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_integerIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_integerIR (mAttribute_mIntegerTypeName, mAttribute_mActualTypeName COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @integerIR type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_integerIR ("integerIR",
                                  & kTypeDescriptor_GALGAS_abstractTypeIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_integerIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_integerIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_integerIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_integerIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_integerIR GALGAS_integerIR::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_integerIR result ;
  const GALGAS_integerIR * p = (const GALGAS_integerIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_integerIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("integerIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_literalStringTypeIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_literalStringTypeIR * p = (const cPtr_literalStringTypeIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_literalStringTypeIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mLiteralStringTypeName.objectCompare (p->mAttribute_mLiteralStringTypeName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_literalStringTypeIR::objectCompare (const GALGAS_literalStringTypeIR & inOperand) const {
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

GALGAS_literalStringTypeIR::GALGAS_literalStringTypeIR (void) :
GALGAS_abstractTypeIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalStringTypeIR GALGAS_literalStringTypeIR::constructor_default (LOCATION_ARGS) {
  return GALGAS_literalStringTypeIR::constructor_new (GALGAS_string::constructor_default (HERE)
                                                      COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalStringTypeIR::GALGAS_literalStringTypeIR (const cPtr_literalStringTypeIR * inSourcePtr) :
GALGAS_abstractTypeIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_literalStringTypeIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalStringTypeIR GALGAS_literalStringTypeIR::constructor_new (const GALGAS_string & inAttribute_mLiteralStringTypeName
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_literalStringTypeIR result ;
  if (inAttribute_mLiteralStringTypeName.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_literalStringTypeIR (inAttribute_mLiteralStringTypeName COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_literalStringTypeIR::reader_mLiteralStringTypeName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_literalStringTypeIR * p = (const cPtr_literalStringTypeIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_literalStringTypeIR) ;
    result = p->mAttribute_mLiteralStringTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_literalStringTypeIR::reader_mLiteralStringTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLiteralStringTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @literalStringTypeIR class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_literalStringTypeIR::cPtr_literalStringTypeIR (const GALGAS_string & in_mLiteralStringTypeName
                                                    COMMA_LOCATION_ARGS) :
cPtr_abstractTypeIR (THERE),
mAttribute_mLiteralStringTypeName (in_mLiteralStringTypeName) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_literalStringTypeIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_literalStringTypeIR ;
}

void cPtr_literalStringTypeIR::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@literalStringTypeIR:" ;
  mAttribute_mLiteralStringTypeName.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_literalStringTypeIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_literalStringTypeIR (mAttribute_mLiteralStringTypeName COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @literalStringTypeIR type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_literalStringTypeIR ("literalStringTypeIR",
                                            & kTypeDescriptor_GALGAS_abstractTypeIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_literalStringTypeIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_literalStringTypeIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_literalStringTypeIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_literalStringTypeIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalStringTypeIR GALGAS_literalStringTypeIR::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_literalStringTypeIR result ;
  const GALGAS_literalStringTypeIR * p = (const GALGAS_literalStringTypeIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_literalStringTypeIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("literalStringTypeIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_structureIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_structureIR * p = (const cPtr_structureIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_structureIR) ;
  if (kOperandEqual == result) {
    result = mAttribute_mStructureName.objectCompare (p->mAttribute_mStructureName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mStructureFieldListForGeneration.objectCompare (p->mAttribute_mStructureFieldListForGeneration) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_structureIR::objectCompare (const GALGAS_structureIR & inOperand) const {
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

GALGAS_structureIR::GALGAS_structureIR (void) :
GALGAS_abstractTypeIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureIR GALGAS_structureIR::constructor_default (LOCATION_ARGS) {
  return GALGAS_structureIR::constructor_new (GALGAS_string::constructor_default (HERE),
                                              GALGAS_structureFieldListForGeneration::constructor_emptyList (HERE)
                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureIR::GALGAS_structureIR (const cPtr_structureIR * inSourcePtr) :
GALGAS_abstractTypeIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_structureIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureIR GALGAS_structureIR::constructor_new (const GALGAS_string & inAttribute_mStructureName,
                                                        const GALGAS_structureFieldListForGeneration & inAttribute_mStructureFieldListForGeneration
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_structureIR result ;
  if (inAttribute_mStructureName.isValid () && inAttribute_mStructureFieldListForGeneration.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_structureIR (inAttribute_mStructureName, inAttribute_mStructureFieldListForGeneration COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_structureIR::reader_mStructureName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_structureIR * p = (const cPtr_structureIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structureIR) ;
    result = p->mAttribute_mStructureName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_structureIR::reader_mStructureName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mStructureName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureFieldListForGeneration GALGAS_structureIR::reader_mStructureFieldListForGeneration (UNUSED_LOCATION_ARGS) const {
  GALGAS_structureFieldListForGeneration result ;
  if (NULL != mObjectPtr) {
    const cPtr_structureIR * p = (const cPtr_structureIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_structureIR) ;
    result = p->mAttribute_mStructureFieldListForGeneration ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureFieldListForGeneration cPtr_structureIR::reader_mStructureFieldListForGeneration (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mStructureFieldListForGeneration ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @structureIR class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_structureIR::cPtr_structureIR (const GALGAS_string & in_mStructureName,
                                    const GALGAS_structureFieldListForGeneration & in_mStructureFieldListForGeneration
                                    COMMA_LOCATION_ARGS) :
cPtr_abstractTypeIR (THERE),
mAttribute_mStructureName (in_mStructureName),
mAttribute_mStructureFieldListForGeneration (in_mStructureFieldListForGeneration) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_structureIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_structureIR ;
}

void cPtr_structureIR::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "[@structureIR:" ;
  mAttribute_mStructureName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mStructureFieldListForGeneration.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_structureIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_structureIR (mAttribute_mStructureName, mAttribute_mStructureFieldListForGeneration COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @structureIR type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_structureIR ("structureIR",
                                    & kTypeDescriptor_GALGAS_abstractTypeIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_structureIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_structureIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_structureIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_structureIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureIR GALGAS_structureIR::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_structureIR result ;
  const GALGAS_structureIR * p = (const GALGAS_structureIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_structureIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("structureIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_expressionAST::objectCompare (const GALGAS_expressionAST & inOperand) const {
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

GALGAS_expressionAST::GALGAS_expressionAST (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST::GALGAS_expressionAST (const cPtr_expressionAST * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_expressionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @expressionAST class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_expressionAST::cPtr_expressionAST (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @expressionAST type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_expressionAST ("expressionAST",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_expressionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_expressionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_expressionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_expressionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_expressionAST::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_expressionAST result ;
  const GALGAS_expressionAST * p = (const GALGAS_expressionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_expressionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("expressionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
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

GALGAS_expressionAST GALGAS_booleanShortCircuitAndOperatorExpressionAST::reader_mLeftExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_booleanShortCircuitAndOperatorExpressionAST * p = (const cPtr_booleanShortCircuitAndOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_booleanShortCircuitAndOperatorExpressionAST) ;
    result = p->mAttribute_mLeftExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_booleanShortCircuitAndOperatorExpressionAST::reader_mLeftExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLeftExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_booleanShortCircuitAndOperatorExpressionAST::reader_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_booleanShortCircuitAndOperatorExpressionAST * p = (const cPtr_booleanShortCircuitAndOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_booleanShortCircuitAndOperatorExpressionAST) ;
    result = p->mAttribute_mOperatorLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_booleanShortCircuitAndOperatorExpressionAST::reader_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperatorLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_booleanShortCircuitAndOperatorExpressionAST::reader_mRightExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_booleanShortCircuitAndOperatorExpressionAST * p = (const cPtr_booleanShortCircuitAndOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_booleanShortCircuitAndOperatorExpressionAST) ;
    result = p->mAttribute_mRightExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_booleanShortCircuitAndOperatorExpressionAST::reader_mRightExpression (UNUSED_LOCATION_ARGS) const {
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
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_conversionExpressionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_conversionExpressionAST * p = (const cPtr_conversionExpressionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_conversionExpressionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mExpression.objectCompare (p->mAttribute_mExpression) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mTypeName.objectCompare (p->mAttribute_mTypeName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mSilently.objectCompare (p->mAttribute_mSilently) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mEndOfExpression.objectCompare (p->mAttribute_mEndOfExpression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_conversionExpressionAST::objectCompare (const GALGAS_conversionExpressionAST & inOperand) const {
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

GALGAS_conversionExpressionAST::GALGAS_conversionExpressionAST (void) :
GALGAS_expressionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_conversionExpressionAST::GALGAS_conversionExpressionAST (const cPtr_conversionExpressionAST * inSourcePtr) :
GALGAS_expressionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_conversionExpressionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_conversionExpressionAST GALGAS_conversionExpressionAST::constructor_new (const GALGAS_expressionAST & inAttribute_mExpression,
                                                                                const GALGAS_lstring & inAttribute_mTypeName,
                                                                                const GALGAS_bool & inAttribute_mSilently,
                                                                                const GALGAS_location & inAttribute_mEndOfExpression
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_conversionExpressionAST result ;
  if (inAttribute_mExpression.isValid () && inAttribute_mTypeName.isValid () && inAttribute_mSilently.isValid () && inAttribute_mEndOfExpression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_conversionExpressionAST (inAttribute_mExpression, inAttribute_mTypeName, inAttribute_mSilently, inAttribute_mEndOfExpression COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_conversionExpressionAST::reader_mExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_conversionExpressionAST * p = (const cPtr_conversionExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_conversionExpressionAST) ;
    result = p->mAttribute_mExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_conversionExpressionAST::reader_mExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_conversionExpressionAST::reader_mTypeName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_conversionExpressionAST * p = (const cPtr_conversionExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_conversionExpressionAST) ;
    result = p->mAttribute_mTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_conversionExpressionAST::reader_mTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_conversionExpressionAST::reader_mSilently (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_conversionExpressionAST * p = (const cPtr_conversionExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_conversionExpressionAST) ;
    result = p->mAttribute_mSilently ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_conversionExpressionAST::reader_mSilently (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSilently ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_conversionExpressionAST::reader_mEndOfExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_conversionExpressionAST * p = (const cPtr_conversionExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_conversionExpressionAST) ;
    result = p->mAttribute_mEndOfExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_conversionExpressionAST::reader_mEndOfExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                  Pointer class for @conversionExpressionAST class                                   *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_conversionExpressionAST::cPtr_conversionExpressionAST (const GALGAS_expressionAST & in_mExpression,
                                                            const GALGAS_lstring & in_mTypeName,
                                                            const GALGAS_bool & in_mSilently,
                                                            const GALGAS_location & in_mEndOfExpression
                                                            COMMA_LOCATION_ARGS) :
cPtr_expressionAST (THERE),
mAttribute_mExpression (in_mExpression),
mAttribute_mTypeName (in_mTypeName),
mAttribute_mSilently (in_mSilently),
mAttribute_mEndOfExpression (in_mEndOfExpression) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_conversionExpressionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_conversionExpressionAST ;
}

void cPtr_conversionExpressionAST::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@conversionExpressionAST:" ;
  mAttribute_mExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mTypeName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mSilently.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mEndOfExpression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_conversionExpressionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_conversionExpressionAST (mAttribute_mExpression, mAttribute_mTypeName, mAttribute_mSilently, mAttribute_mEndOfExpression COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @conversionExpressionAST type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_conversionExpressionAST ("conversionExpressionAST",
                                                & kTypeDescriptor_GALGAS_expressionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_conversionExpressionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_conversionExpressionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_conversionExpressionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_conversionExpressionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_conversionExpressionAST GALGAS_conversionExpressionAST::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_conversionExpressionAST result ;
  const GALGAS_conversionExpressionAST * p = (const GALGAS_conversionExpressionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_conversionExpressionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("conversionExpressionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
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

GALGAS_expressionAST GALGAS_infixOperatorExpressionAST::reader_mLeftExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_infixOperatorExpressionAST * p = (const cPtr_infixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_infixOperatorExpressionAST) ;
    result = p->mAttribute_mLeftExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_infixOperatorExpressionAST::reader_mLeftExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLeftExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_infixOperatorExpressionAST::reader_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_infixOperatorExpressionAST * p = (const cPtr_infixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_infixOperatorExpressionAST) ;
    result = p->mAttribute_mOperatorLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_infixOperatorExpressionAST::reader_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperatorLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator GALGAS_infixOperatorExpressionAST::reader_mOp (UNUSED_LOCATION_ARGS) const {
  GALGAS_infixOperator result ;
  if (NULL != mObjectPtr) {
    const cPtr_infixOperatorExpressionAST * p = (const cPtr_infixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_infixOperatorExpressionAST) ;
    result = p->mAttribute_mOp ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperator cPtr_infixOperatorExpressionAST::reader_mOp (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOp ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_infixOperatorExpressionAST::reader_mRightExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_infixOperatorExpressionAST * p = (const cPtr_infixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_infixOperatorExpressionAST) ;
    result = p->mAttribute_mRightExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_infixOperatorExpressionAST::reader_mRightExpression (UNUSED_LOCATION_ARGS) const {
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
  return GALGAS_literalBooleanInExpressionAST::constructor_new (GALGAS_bigint::constructor_zero (HERE)
                                                                COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalBooleanInExpressionAST::GALGAS_literalBooleanInExpressionAST (const cPtr_literalBooleanInExpressionAST * inSourcePtr) :
GALGAS_expressionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_literalBooleanInExpressionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalBooleanInExpressionAST GALGAS_literalBooleanInExpressionAST::constructor_new (const GALGAS_bigint & inAttribute_mValue
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_literalBooleanInExpressionAST result ;
  if (inAttribute_mValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_literalBooleanInExpressionAST (inAttribute_mValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_literalBooleanInExpressionAST::reader_mValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_literalBooleanInExpressionAST * p = (const cPtr_literalBooleanInExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_literalBooleanInExpressionAST) ;
    result = p->mAttribute_mValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_literalBooleanInExpressionAST::reader_mValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                               Pointer class for @literalBooleanInExpressionAST class                                *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_literalBooleanInExpressionAST::cPtr_literalBooleanInExpressionAST (const GALGAS_bigint & in_mValue
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
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_literalIntegerInExpressionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_literalIntegerInExpressionAST * p = (const cPtr_literalIntegerInExpressionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_literalIntegerInExpressionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mLiteralInteger.objectCompare (p->mAttribute_mLiteralInteger) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_literalIntegerInExpressionAST::objectCompare (const GALGAS_literalIntegerInExpressionAST & inOperand) const {
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

GALGAS_literalIntegerInExpressionAST::GALGAS_literalIntegerInExpressionAST (void) :
GALGAS_expressionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalIntegerInExpressionAST GALGAS_literalIntegerInExpressionAST::constructor_default (LOCATION_ARGS) {
  return GALGAS_literalIntegerInExpressionAST::constructor_new (GALGAS_lbigint::constructor_default (HERE)
                                                                COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalIntegerInExpressionAST::GALGAS_literalIntegerInExpressionAST (const cPtr_literalIntegerInExpressionAST * inSourcePtr) :
GALGAS_expressionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_literalIntegerInExpressionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalIntegerInExpressionAST GALGAS_literalIntegerInExpressionAST::constructor_new (const GALGAS_lbigint & inAttribute_mLiteralInteger
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_literalIntegerInExpressionAST result ;
  if (inAttribute_mLiteralInteger.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_literalIntegerInExpressionAST (inAttribute_mLiteralInteger COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint GALGAS_literalIntegerInExpressionAST::reader_mLiteralInteger (UNUSED_LOCATION_ARGS) const {
  GALGAS_lbigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_literalIntegerInExpressionAST * p = (const cPtr_literalIntegerInExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_literalIntegerInExpressionAST) ;
    result = p->mAttribute_mLiteralInteger ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint cPtr_literalIntegerInExpressionAST::reader_mLiteralInteger (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mLiteralInteger ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                               Pointer class for @literalIntegerInExpressionAST class                                *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_literalIntegerInExpressionAST::cPtr_literalIntegerInExpressionAST (const GALGAS_lbigint & in_mLiteralInteger
                                                                        COMMA_LOCATION_ARGS) :
cPtr_expressionAST (THERE),
mAttribute_mLiteralInteger (in_mLiteralInteger) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_literalIntegerInExpressionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_literalIntegerInExpressionAST ;
}

void cPtr_literalIntegerInExpressionAST::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "[@literalIntegerInExpressionAST:" ;
  mAttribute_mLiteralInteger.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_literalIntegerInExpressionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_literalIntegerInExpressionAST (mAttribute_mLiteralInteger COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @literalIntegerInExpressionAST type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_literalIntegerInExpressionAST ("literalIntegerInExpressionAST",
                                                      & kTypeDescriptor_GALGAS_expressionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_literalIntegerInExpressionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_literalIntegerInExpressionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_literalIntegerInExpressionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_literalIntegerInExpressionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_literalIntegerInExpressionAST GALGAS_literalIntegerInExpressionAST::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_literalIntegerInExpressionAST result ;
  const GALGAS_literalIntegerInExpressionAST * p = (const GALGAS_literalIntegerInExpressionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_literalIntegerInExpressionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("literalIntegerInExpressionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
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

GALGAS_location GALGAS_prefixOperatorExpressionAST::reader_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_prefixOperatorExpressionAST * p = (const cPtr_prefixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_prefixOperatorExpressionAST) ;
    result = p->mAttribute_mOperatorLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_prefixOperatorExpressionAST::reader_mOperatorLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperatorLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperator GALGAS_prefixOperatorExpressionAST::reader_mOp (UNUSED_LOCATION_ARGS) const {
  GALGAS_prefixOperator result ;
  if (NULL != mObjectPtr) {
    const cPtr_prefixOperatorExpressionAST * p = (const cPtr_prefixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_prefixOperatorExpressionAST) ;
    result = p->mAttribute_mOp ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperator cPtr_prefixOperatorExpressionAST::reader_mOp (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOp ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_prefixOperatorExpressionAST::reader_mExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_expressionAST result ;
  if (NULL != mObjectPtr) {
    const cPtr_prefixOperatorExpressionAST * p = (const cPtr_prefixOperatorExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_prefixOperatorExpressionAST) ;
    result = p->mAttribute_mExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cPtr_prefixOperatorExpressionAST::reader_mExpression (UNUSED_LOCATION_ARGS) const {
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

typeComparisonResult cPtr_registerConstantInExpressionAST::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_registerConstantInExpressionAST * p = (const cPtr_registerConstantInExpressionAST *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_registerConstantInExpressionAST) ;
  if (kOperandEqual == result) {
    result = mAttribute_mRegisterName.objectCompare (p->mAttribute_mRegisterName) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_mFieldName.objectCompare (p->mAttribute_mFieldName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_registerConstantInExpressionAST::objectCompare (const GALGAS_registerConstantInExpressionAST & inOperand) const {
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

GALGAS_registerConstantInExpressionAST::GALGAS_registerConstantInExpressionAST (void) :
GALGAS_expressionAST () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerConstantInExpressionAST GALGAS_registerConstantInExpressionAST::constructor_default (LOCATION_ARGS) {
  return GALGAS_registerConstantInExpressionAST::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                                  GALGAS_lstring::constructor_default (HERE)
                                                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerConstantInExpressionAST::GALGAS_registerConstantInExpressionAST (const cPtr_registerConstantInExpressionAST * inSourcePtr) :
GALGAS_expressionAST (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_registerConstantInExpressionAST) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerConstantInExpressionAST GALGAS_registerConstantInExpressionAST::constructor_new (const GALGAS_lstring & inAttribute_mRegisterName,
                                                                                                const GALGAS_lstring & inAttribute_mFieldName
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_registerConstantInExpressionAST result ;
  if (inAttribute_mRegisterName.isValid () && inAttribute_mFieldName.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_registerConstantInExpressionAST (inAttribute_mRegisterName, inAttribute_mFieldName COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_registerConstantInExpressionAST::reader_mRegisterName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_registerConstantInExpressionAST * p = (const cPtr_registerConstantInExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_registerConstantInExpressionAST) ;
    result = p->mAttribute_mRegisterName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_registerConstantInExpressionAST::reader_mRegisterName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_registerConstantInExpressionAST::reader_mFieldName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_registerConstantInExpressionAST * p = (const cPtr_registerConstantInExpressionAST *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_registerConstantInExpressionAST) ;
    result = p->mAttribute_mFieldName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_registerConstantInExpressionAST::reader_mFieldName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mFieldName ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                              Pointer class for @registerConstantInExpressionAST class                               *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_registerConstantInExpressionAST::cPtr_registerConstantInExpressionAST (const GALGAS_lstring & in_mRegisterName,
                                                                            const GALGAS_lstring & in_mFieldName
                                                                            COMMA_LOCATION_ARGS) :
cPtr_expressionAST (THERE),
mAttribute_mRegisterName (in_mRegisterName),
mAttribute_mFieldName (in_mFieldName) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_registerConstantInExpressionAST::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_registerConstantInExpressionAST ;
}

void cPtr_registerConstantInExpressionAST::description (C_String & ioString,
                                                        const int32_t inIndentation) const {
  ioString << "[@registerConstantInExpressionAST:" ;
  mAttribute_mRegisterName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_mFieldName.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_registerConstantInExpressionAST::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_registerConstantInExpressionAST (mAttribute_mRegisterName, mAttribute_mFieldName COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @registerConstantInExpressionAST type                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_registerConstantInExpressionAST ("registerConstantInExpressionAST",
                                                        & kTypeDescriptor_GALGAS_expressionAST) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_registerConstantInExpressionAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_registerConstantInExpressionAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_registerConstantInExpressionAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_registerConstantInExpressionAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_registerConstantInExpressionAST GALGAS_registerConstantInExpressionAST::extractObject (const GALGAS_object & inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_registerConstantInExpressionAST result ;
  const GALGAS_registerConstantInExpressionAST * p = (const GALGAS_registerConstantInExpressionAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_registerConstantInExpressionAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("registerConstantInExpressionAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

