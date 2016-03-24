//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "lexique-plm_lexique-cocoa.h"
#import "PMDebug.h"

//---------------------------------------------------------------------------------------------------------------------*

@implementation OC_Lexique_plm_lexique

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Template Replacements                                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Template Delimiters                                                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*

- (instancetype) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mLexicalAttribute_bigInteger = [[NSMutableString alloc] init] ;
    mLexicalAttribute_tokenString = [[NSMutableString alloc] init] ;
  }
  return self ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) FINALIZE_OR_DEALLOC {
  noteObjectDeallocation (self) ;
  macroSuperFinalize ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                 I N D E X I N G    D I R E C T O R Y                                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) indexingDirectory {
  return @"" ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                 I N D E X I N G    T I T L E S                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (NSArray *) indexingTitles { // Array of NSString

  return [NSArray array] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//            Terminal Symbols as end of script in template mark                                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//             Key words table 'keyWordList'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const C_cocoa_lexique_table_entry ktable_for_plm_5F_lexique_keyWordList [52] = {
  {"at", plm_lexique_1_at},
  {"do", plm_lexique_1_do},
  {"if", plm_lexique_1_if},
  {"in", plm_lexique_1_in},
  {"on", plm_lexique_1_on},
  {"or", plm_lexique_1_or},
  {"and", plm_lexique_1_and},
  {"end", plm_lexique_1_end},
  {"for", plm_lexique_1_for},
  {"let", plm_lexique_1_let},
  {"not", plm_lexique_1_not},
  {"var", plm_lexique_1_var},
  {"xor", plm_lexique_1_xor},
  {"boot", plm_lexique_1_boot},
  {"case", plm_lexique_1_case},
  {"else", plm_lexique_1_else},
  {"enum", plm_lexique_1_enum},
  {"func", plm_lexique_1_func},
  {"init", plm_lexique_1_init},
  {"self", plm_lexique_1_self},
  {"task", plm_lexique_1_task},
  {"then", plm_lexique_1_then},
  {"true", plm_lexique_1_true},
  {"when", plm_lexique_1_when},
  {"check", plm_lexique_1_check},
  {"elsif", plm_lexique_1_elsif},
  {"false", plm_lexique_1_false},
  {"guard", plm_lexique_1_guard},
  {"panic", plm_lexique_1_panic},
  {"while", plm_lexique_1_while},
  {"assert", plm_lexique_1_assert},
  {"extend", plm_lexique_1_extend},
  {"extern", plm_lexique_1_extern},
  {"import", plm_lexique_1_import},
  {"select", plm_lexique_1_select},
  {"struct", plm_lexique_1_struct},
  {"target", plm_lexique_1_target},
  {"boolset", plm_lexique_1_boolset},
  {"convert", plm_lexique_1_convert},
  {"newType", plm_lexique_1_newType},
  {"section", plm_lexique_1_section},
  {"service", plm_lexique_1_service},
  {"priority", plm_lexique_1_priority},
  {"register", plm_lexique_1_register},
  {"required", plm_lexique_1_required},
  {"truncate", plm_lexique_1_truncate},
  {"extension", plm_lexique_1_extension},
  {"primitive", plm_lexique_1_primitive},
  {"stackSize", plm_lexique_1_stackSize},
  {"opaqueType", plm_lexique_1_opaqueType},
  {"requiredBy", plm_lexique_1_requiredBy},
  {"pointerSize", plm_lexique_1_pointerSize}
} ;

static NSInteger search_into_plm_5F_lexique_keyWordList (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_plm_5F_lexique_keyWordList, 52) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//               P A R S E    L E X I C A L    T O K E N                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (void) parseLexicalTokenForLexicalColoring {
  mLoop = YES ;
  BOOL scanningOk = YES ;
  mTokenCode = 0 ;
  while ((mTokenCode == 0) && (mCurrentChar != '\0')) {
    mTokenStartLocation = mCurrentLocation ;
    [mLexicalAttribute_bigInteger setString:@""] ;
    [mLexicalAttribute_tokenString setString:@""] ;
    mTokenStartLocation = mCurrentLocation ;
    if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
      do {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
        if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputChar:95] || [self testForInputFromChar:48 toChar:57])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      if (mTokenCode == 0) {
        mTokenCode = search_into_plm_5F_lexique_keyWordList (mLexicalAttribute_tokenString) ;
      }
      if (mTokenCode == 0) {
        mTokenCode = plm_lexique_1_identifier ;
      }
    }else if (scanningOk && ([self testForInputChar:64])) {
      if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputFromChar:48 toChar:57])) {
        do {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
          if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputFromChar:48 toChar:57] || [self testForInputChar:46])) {
          }else{
            mLoop = NO ;
          }
        }while (mLoop && scanningOk) ;
        mLoop = YES ;
      }else{
        scanningOk = NO ;
      }
      mTokenCode = plm_lexique_1_attribute ;
    }else if (scanningOk && ([self testForInputChar:36])) {
      if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputFromChar:48 toChar:57])) {
        do {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
          if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputFromChar:48 toChar:57] || [self testForInputChar:95])) {
          }else{
            mLoop = NO ;
          }
        }while (mLoop && scanningOk) ;
        mLoop = YES ;
      }else{
        scanningOk = NO ;
      }
      mTokenCode = plm_lexique_1_typeName ;
    }else if (scanningOk && ([self testForInputChar:96])) {
      if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputFromChar:48 toChar:57])) {
        do {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
          if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputFromChar:48 toChar:57])) {
          }else{
            mLoop = NO ;
          }
        }while (mLoop && scanningOk) ;
        mLoop = YES ;
      }else{
        scanningOk = NO ;
      }
      mTokenCode = plm_lexique_1_modeName ;
    }else if (scanningOk && ([self testForInputString:@"0b" advance:YES])) {
      do {
        if (scanningOk && ([self testForInputChar:95])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      if (scanningOk && ([self testForInputFromChar:48 toChar:49])) {
        scanner_cocoa_routine_enterBinaryDigitIntoBigInt (& scanningOk, mPreviousChar, mLexicalAttribute_bigInteger) ;
        do {
          if (scanningOk && ([self testForInputFromChar:48 toChar:49])) {
            scanner_cocoa_routine_enterBinaryDigitIntoBigInt (& scanningOk, mPreviousChar, mLexicalAttribute_bigInteger) ;
          }else if (scanningOk && ([self testForInputChar:95])) {
          }else{
            mLoop = NO ;
          }
        }while (mLoop && scanningOk) ;
        mLoop = YES ;
        mTokenCode = plm_lexique_1_integer ;
      }else{
        scanningOk = NO ;
      }
    }else if (scanningOk && ([self testForInputString:@"0x" advance:YES])) {
      do {
        if (scanningOk && ([self testForInputChar:95])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
        scanner_cocoa_routine_enterHexDigitIntoBigInt (& scanningOk, mPreviousChar, mLexicalAttribute_bigInteger) ;
        do {
          if (scanningOk && ([self testForInputFromChar:48 toChar:57] || [self testForInputFromChar:97 toChar:102] || [self testForInputFromChar:65 toChar:70])) {
            scanner_cocoa_routine_enterHexDigitIntoBigInt (& scanningOk, mPreviousChar, mLexicalAttribute_bigInteger) ;
          }else if (scanningOk && ([self testForInputChar:95])) {
          }else{
            mLoop = NO ;
          }
        }while (mLoop && scanningOk) ;
        mLoop = YES ;
        mTokenCode = plm_lexique_1_integer ;
      }else{
        scanningOk = NO ;
      }
    }else if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
      scanner_cocoa_routine_enterDecimalDigitIntoBigInt (& scanningOk, mPreviousChar, mLexicalAttribute_bigInteger) ;
      do {
        if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
          scanner_cocoa_routine_enterDecimalDigitIntoBigInt (& scanningOk, mPreviousChar, mLexicalAttribute_bigInteger) ;
        }else if (scanningOk && ([self testForInputChar:95])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      mTokenCode = plm_lexique_1_integer ;
    }else if (scanningOk && ([self testForInputChar:34])) {
      do {
        if (scanningOk && ([self testForInputChar:32] || [self testForInputChar:33] || [self testForInputFromChar:35 toChar:65533])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      if (scanningOk && ([self testForInputChar:34])) {
        mTokenCode = plm_lexique_1_literal_5F_string ;
      }else{
        scanningOk = NO ;
      }
    }else if (scanningOk && ([self testForInputString:@"//" advance:YES])) {
      do {
        if (scanningOk && ([self testForInputFromChar:1 toChar:9] || [self testForInputChar:11] || [self testForInputChar:12] || [self testForInputFromChar:14 toChar:65533])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      mTokenCode = plm_lexique_1_comment ;
    }else if (scanningOk && [self testForInputString:@"-%=" advance:YES]) {
      mTokenCode = plm_lexique_1__2D__25__3D_ ;
    }else if (scanningOk && [self testForInputString:@"+%=" advance:YES]) {
      mTokenCode = plm_lexique_1__2B__25__3D_ ;
    }else if (scanningOk && [self testForInputString:@"*%=" advance:YES]) {
      mTokenCode = plm_lexique_1__2A__25__3D_ ;
    }else if (scanningOk && [self testForInputString:@"!/=" advance:YES]) {
      mTokenCode = plm_lexique_1__21__2F__3D_ ;
    }else if (scanningOk && [self testForInputString:@"!%=" advance:YES]) {
      mTokenCode = plm_lexique_1__21__25__3D_ ;
    }else if (scanningOk && [self testForInputString:@"|=" advance:YES]) {
      mTokenCode = plm_lexique_1__7C__3D_ ;
    }else if (scanningOk && [self testForInputString:@"^=" advance:YES]) {
      mTokenCode = plm_lexique_1__5E__3D_ ;
    }else if (scanningOk && [self testForInputString:@">>" advance:YES]) {
      mTokenCode = plm_lexique_1__3E__3E_ ;
    }else if (scanningOk && [self testForInputString:@">=" advance:YES]) {
      mTokenCode = plm_lexique_1__3E__3D_ ;
    }else if (scanningOk && [self testForInputString:@"==" advance:YES]) {
      mTokenCode = plm_lexique_1__3D__3D_ ;
    }else if (scanningOk && [self testForInputString:@"<=" advance:YES]) {
      mTokenCode = plm_lexique_1__3C__3D_ ;
    }else if (scanningOk && [self testForInputString:@"<<" advance:YES]) {
      mTokenCode = plm_lexique_1__3C__3C_ ;
    }else if (scanningOk && [self testForInputString:@"::" advance:YES]) {
      mTokenCode = plm_lexique_1__3A__3A_ ;
    }else if (scanningOk && [self testForInputString:@"/=" advance:YES]) {
      mTokenCode = plm_lexique_1__2F__3D_ ;
    }else if (scanningOk && [self testForInputString:@"->" advance:YES]) {
      mTokenCode = plm_lexique_1__2D__3E_ ;
    }else if (scanningOk && [self testForInputString:@"-=" advance:YES]) {
      mTokenCode = plm_lexique_1__2D__3D_ ;
    }else if (scanningOk && [self testForInputString:@"-%" advance:YES]) {
      mTokenCode = plm_lexique_1__2D__25_ ;
    }else if (scanningOk && [self testForInputString:@"+=" advance:YES]) {
      mTokenCode = plm_lexique_1__2B__3D_ ;
    }else if (scanningOk && [self testForInputString:@"+%" advance:YES]) {
      mTokenCode = plm_lexique_1__2B__25_ ;
    }else if (scanningOk && [self testForInputString:@"*=" advance:YES]) {
      mTokenCode = plm_lexique_1__2A__3D_ ;
    }else if (scanningOk && [self testForInputString:@"*%" advance:YES]) {
      mTokenCode = plm_lexique_1__2A__25_ ;
    }else if (scanningOk && [self testForInputString:@"&=" advance:YES]) {
      mTokenCode = plm_lexique_1__26__3D_ ;
    }else if (scanningOk && [self testForInputString:@"%=" advance:YES]) {
      mTokenCode = plm_lexique_1__25__3D_ ;
    }else if (scanningOk && [self testForInputString:@"!=" advance:YES]) {
      mTokenCode = plm_lexique_1__21__3D_ ;
    }else if (scanningOk && [self testForInputString:@"!/" advance:YES]) {
      mTokenCode = plm_lexique_1__21__2F_ ;
    }else if (scanningOk && [self testForInputString:@"!%" advance:YES]) {
      mTokenCode = plm_lexique_1__21__25_ ;
    }else if (scanningOk && [self testForInputString:@"~" advance:YES]) {
      mTokenCode = plm_lexique_1__7E_ ;
    }else if (scanningOk && [self testForInputString:@"}" advance:YES]) {
      mTokenCode = plm_lexique_1__7D_ ;
    }else if (scanningOk && [self testForInputString:@"|" advance:YES]) {
      mTokenCode = plm_lexique_1__7C_ ;
    }else if (scanningOk && [self testForInputString:@"{" advance:YES]) {
      mTokenCode = plm_lexique_1__7B_ ;
    }else if (scanningOk && [self testForInputString:@"^" advance:YES]) {
      mTokenCode = plm_lexique_1__5E_ ;
    }else if (scanningOk && [self testForInputString:@"]" advance:YES]) {
      mTokenCode = plm_lexique_1__5D_ ;
    }else if (scanningOk && [self testForInputString:@"[" advance:YES]) {
      mTokenCode = plm_lexique_1__5B_ ;
    }else if (scanningOk && [self testForInputString:@">" advance:YES]) {
      mTokenCode = plm_lexique_1__3E_ ;
    }else if (scanningOk && [self testForInputString:@"=" advance:YES]) {
      mTokenCode = plm_lexique_1__3D_ ;
    }else if (scanningOk && [self testForInputString:@"<" advance:YES]) {
      mTokenCode = plm_lexique_1__3C_ ;
    }else if (scanningOk && [self testForInputString:@";" advance:YES]) {
      mTokenCode = plm_lexique_1__3B_ ;
    }else if (scanningOk && [self testForInputString:@":" advance:YES]) {
      mTokenCode = plm_lexique_1__3A_ ;
    }else if (scanningOk && [self testForInputString:@"/" advance:YES]) {
      mTokenCode = plm_lexique_1__2F_ ;
    }else if (scanningOk && [self testForInputString:@"." advance:YES]) {
      mTokenCode = plm_lexique_1__2E_ ;
    }else if (scanningOk && [self testForInputString:@"-" advance:YES]) {
      mTokenCode = plm_lexique_1__2D_ ;
    }else if (scanningOk && [self testForInputString:@"," advance:YES]) {
      mTokenCode = plm_lexique_1__2C_ ;
    }else if (scanningOk && [self testForInputString:@"+" advance:YES]) {
      mTokenCode = plm_lexique_1__2B_ ;
    }else if (scanningOk && [self testForInputString:@"*" advance:YES]) {
      mTokenCode = plm_lexique_1__2A_ ;
    }else if (scanningOk && [self testForInputString:@")" advance:YES]) {
      mTokenCode = plm_lexique_1__29_ ;
    }else if (scanningOk && [self testForInputString:@"(" advance:YES]) {
      mTokenCode = plm_lexique_1__28_ ;
    }else if (scanningOk && [self testForInputString:@"&" advance:YES]) {
      mTokenCode = plm_lexique_1__26_ ;
    }else if (scanningOk && [self testForInputString:@"%" advance:YES]) {
      mTokenCode = plm_lexique_1__25_ ;
    }else if (scanningOk && ([self testForInputChar:63])) {
      scanningPointStructForCocoa locationForTag_onlyInterrogationMark ;
      [self saveScanningPoint: & locationForTag_onlyInterrogationMark] ;
      if (scanningOk && ([self testForInputChar:33])) {
        scanningPointStructForCocoa locationForTag_onlyExclamationInterrogationMark ;
        [self saveScanningPoint: & locationForTag_onlyExclamationInterrogationMark] ;
        if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
          do {
            scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
            if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputFromChar:48 toChar:57] || [self testForInputChar:95])) {
            }else{
              mLoop = NO ;
            }
          }while (mLoop && scanningOk) ;
          mLoop = YES ;
          if (scanningOk && ([self testForInputChar:58])) {
            mTokenCode = plm_lexique_1__3F__21_ ;
          }else{
            scanner_cocoa_routine_resetString (& scanningOk, mLexicalAttribute_tokenString) ;
            [self restoreScanningPoint: & locationForTag_onlyExclamationInterrogationMark] ;
            mTokenCode = plm_lexique_1__3F__21_ ;
          }
        }else{
          mTokenCode = plm_lexique_1__3F__21_ ;
        }
      }else if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
        do {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
          if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputFromChar:48 toChar:57] || [self testForInputChar:95])) {
          }else{
            mLoop = NO ;
          }
        }while (mLoop && scanningOk) ;
        mLoop = YES ;
        if (scanningOk && ([self testForInputChar:58])) {
          mTokenCode = plm_lexique_1__3F_ ;
        }else{
          scanner_cocoa_routine_resetString (& scanningOk, mLexicalAttribute_tokenString) ;
          [self restoreScanningPoint: & locationForTag_onlyInterrogationMark] ;
          mTokenCode = plm_lexique_1__3F_ ;
        }
      }else{
        mTokenCode = plm_lexique_1__3F_ ;
      }
    }else if (scanningOk && ([self testForInputChar:33])) {
      scanningPointStructForCocoa locationForTag_onlyExclamationMark ;
      [self saveScanningPoint: & locationForTag_onlyExclamationMark] ;
      if (scanningOk && ([self testForInputChar:63])) {
        scanningPointStructForCocoa locationForTag_onlyInterrogationExclamationMark ;
        [self saveScanningPoint: & locationForTag_onlyInterrogationExclamationMark] ;
        if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
          do {
            scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
            if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputFromChar:48 toChar:57] || [self testForInputChar:95])) {
            }else{
              mLoop = NO ;
            }
          }while (mLoop && scanningOk) ;
          mLoop = YES ;
          if (scanningOk && ([self testForInputChar:58])) {
            mTokenCode = plm_lexique_1__21__3F_ ;
          }else{
            scanner_cocoa_routine_resetString (& scanningOk, mLexicalAttribute_tokenString) ;
            [self restoreScanningPoint: & locationForTag_onlyInterrogationExclamationMark] ;
            mTokenCode = plm_lexique_1__21__3F_ ;
          }
        }else{
          mTokenCode = plm_lexique_1__21__3F_ ;
        }
      }else if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
        do {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_tokenString, mPreviousChar) ;
          if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputFromChar:48 toChar:57] || [self testForInputChar:95])) {
          }else{
            mLoop = NO ;
          }
        }while (mLoop && scanningOk) ;
        mLoop = YES ;
        if (scanningOk && ([self testForInputChar:58])) {
          mTokenCode = plm_lexique_1__21_ ;
        }else{
          scanner_cocoa_routine_resetString (& scanningOk, mLexicalAttribute_tokenString) ;
          [self restoreScanningPoint: & locationForTag_onlyExclamationMark] ;
          mTokenCode = plm_lexique_1__21_ ;
        }
      }else{
        mTokenCode = plm_lexique_1__21_ ;
      }
    }else if (scanningOk && ([self testForInputFromChar:1 toChar:32])) {
    }else if ([self testForInputChar:'\0']) { // End of source text ? 
      mTokenCode = plm_lexique_1_ ; // Empty string code
    }else{ // Unknown input character
      scanningOk = NO ;
      [self advance] ;
    }
  //--- Error ?
    if (! scanningOk) {
      mTokenCode = -1 ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                   T E R M I N A L    C O U N T                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (NSUInteger) terminalVocabularyCount {
  return 111 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     S T Y L E   C O U N T                                                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (NSUInteger) styleCount {
  return 10 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                I S    T E M P L A T E    L E X I Q U E                                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) isTemplateLexique {
  return NO ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal {
  static const NSUInteger kTerminalSymbolStyles [112] = {0,
    0 /* plm_lexique_1_identifier */,
    2 /* plm_lexique_1_attribute */,
    3 /* plm_lexique_1_typeName */,
    4 /* plm_lexique_1_modeName */,
    5 /* plm_lexique_1_integer */,
    6 /* plm_lexique_1_literal_5F_string */,
    7 /* plm_lexique_1_comment */,
    9 /* plm_lexique_1__3F_ */,
    9 /* plm_lexique_1__3F__21_ */,
    9 /* plm_lexique_1__21_ */,
    9 /* plm_lexique_1__21__3F_ */,
    1 /* plm_lexique_1_and */,
    1 /* plm_lexique_1_assert */,
    1 /* plm_lexique_1_at */,
    1 /* plm_lexique_1_boolset */,
    1 /* plm_lexique_1_boot */,
    1 /* plm_lexique_1_case */,
    1 /* plm_lexique_1_check */,
    1 /* plm_lexique_1_convert */,
    1 /* plm_lexique_1_do */,
    1 /* plm_lexique_1_else */,
    1 /* plm_lexique_1_elsif */,
    1 /* plm_lexique_1_end */,
    1 /* plm_lexique_1_enum */,
    1 /* plm_lexique_1_extend */,
    1 /* plm_lexique_1_extension */,
    1 /* plm_lexique_1_extern */,
    1 /* plm_lexique_1_false */,
    1 /* plm_lexique_1_for */,
    1 /* plm_lexique_1_func */,
    1 /* plm_lexique_1_guard */,
    1 /* plm_lexique_1_if */,
    1 /* plm_lexique_1_import */,
    1 /* plm_lexique_1_in */,
    1 /* plm_lexique_1_init */,
    1 /* plm_lexique_1_let */,
    1 /* plm_lexique_1_newType */,
    1 /* plm_lexique_1_not */,
    1 /* plm_lexique_1_opaqueType */,
    1 /* plm_lexique_1_on */,
    1 /* plm_lexique_1_or */,
    1 /* plm_lexique_1_panic */,
    1 /* plm_lexique_1_pointerSize */,
    1 /* plm_lexique_1_primitive */,
    1 /* plm_lexique_1_priority */,
    1 /* plm_lexique_1_register */,
    1 /* plm_lexique_1_required */,
    1 /* plm_lexique_1_requiredBy */,
    1 /* plm_lexique_1_section */,
    1 /* plm_lexique_1_select */,
    1 /* plm_lexique_1_self */,
    1 /* plm_lexique_1_service */,
    1 /* plm_lexique_1_struct */,
    1 /* plm_lexique_1_stackSize */,
    1 /* plm_lexique_1_target */,
    1 /* plm_lexique_1_task */,
    1 /* plm_lexique_1_then */,
    1 /* plm_lexique_1_true */,
    1 /* plm_lexique_1_truncate */,
    1 /* plm_lexique_1_var */,
    1 /* plm_lexique_1_when */,
    1 /* plm_lexique_1_while */,
    1 /* plm_lexique_1_xor */,
    8 /* plm_lexique_1__3A_ */,
    8 /* plm_lexique_1__2E_ */,
    8 /* plm_lexique_1__2C_ */,
    8 /* plm_lexique_1__3B_ */,
    8 /* plm_lexique_1__7B_ */,
    8 /* plm_lexique_1__7D_ */,
    8 /* plm_lexique_1__3D_ */,
    8 /* plm_lexique_1__28_ */,
    8 /* plm_lexique_1__29_ */,
    8 /* plm_lexique_1__3D__3D_ */,
    8 /* plm_lexique_1__21__3D_ */,
    8 /* plm_lexique_1__3C_ */,
    8 /* plm_lexique_1__3C__3D_ */,
    8 /* plm_lexique_1__3E_ */,
    8 /* plm_lexique_1__3E__3D_ */,
    8 /* plm_lexique_1__5B_ */,
    8 /* plm_lexique_1__5D_ */,
    8 /* plm_lexique_1__3C__3C_ */,
    8 /* plm_lexique_1__3E__3E_ */,
    8 /* plm_lexique_1__7E_ */,
    8 /* plm_lexique_1__2D__3E_ */,
    8 /* plm_lexique_1__3A__3A_ */,
    8 /* plm_lexique_1__7C_ */,
    8 /* plm_lexique_1__7C__3D_ */,
    8 /* plm_lexique_1__26_ */,
    8 /* plm_lexique_1__26__3D_ */,
    8 /* plm_lexique_1__5E_ */,
    8 /* plm_lexique_1__5E__3D_ */,
    8 /* plm_lexique_1__2B_ */,
    8 /* plm_lexique_1__2B__25_ */,
    8 /* plm_lexique_1__2B__3D_ */,
    8 /* plm_lexique_1__2B__25__3D_ */,
    8 /* plm_lexique_1__2D_ */,
    8 /* plm_lexique_1__2D__25_ */,
    8 /* plm_lexique_1__2D__3D_ */,
    8 /* plm_lexique_1__2D__25__3D_ */,
    8 /* plm_lexique_1__2A_ */,
    8 /* plm_lexique_1__2A__25_ */,
    8 /* plm_lexique_1__2A__3D_ */,
    8 /* plm_lexique_1__2A__25__3D_ */,
    8 /* plm_lexique_1__2F_ */,
    8 /* plm_lexique_1__21__2F_ */,
    8 /* plm_lexique_1__2F__3D_ */,
    8 /* plm_lexique_1__21__2F__3D_ */,
    8 /* plm_lexique_1__25_ */,
    8 /* plm_lexique_1__21__25_ */,
    8 /* plm_lexique_1__25__3D_ */,
    8 /* plm_lexique_1__21__25__3D_ */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    A T O M I C    S E L E C T I O N   F O R    T E R M I N A L                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex {
  static const BOOL kTerminalAtomicSelection [112] = {NO,
    YES /* plm_lexique_1_identifier */,
    YES /* plm_lexique_1_attribute */,
    YES /* plm_lexique_1_typeName */,
    YES /* plm_lexique_1_modeName */,
    YES /* plm_lexique_1_integer */,
    NO /* plm_lexique_1_literal_5F_string */,
    NO /* plm_lexique_1_comment */,
    YES /* plm_lexique_1__3F_ */,
    YES /* plm_lexique_1__3F__21_ */,
    YES /* plm_lexique_1__21_ */,
    YES /* plm_lexique_1__21__3F_ */,
    YES /* plm_lexique_1_and */,
    YES /* plm_lexique_1_assert */,
    YES /* plm_lexique_1_at */,
    YES /* plm_lexique_1_boolset */,
    YES /* plm_lexique_1_boot */,
    YES /* plm_lexique_1_case */,
    YES /* plm_lexique_1_check */,
    YES /* plm_lexique_1_convert */,
    YES /* plm_lexique_1_do */,
    YES /* plm_lexique_1_else */,
    YES /* plm_lexique_1_elsif */,
    YES /* plm_lexique_1_end */,
    YES /* plm_lexique_1_enum */,
    YES /* plm_lexique_1_extend */,
    YES /* plm_lexique_1_extension */,
    YES /* plm_lexique_1_extern */,
    YES /* plm_lexique_1_false */,
    YES /* plm_lexique_1_for */,
    YES /* plm_lexique_1_func */,
    YES /* plm_lexique_1_guard */,
    YES /* plm_lexique_1_if */,
    YES /* plm_lexique_1_import */,
    YES /* plm_lexique_1_in */,
    YES /* plm_lexique_1_init */,
    YES /* plm_lexique_1_let */,
    YES /* plm_lexique_1_newType */,
    YES /* plm_lexique_1_not */,
    YES /* plm_lexique_1_opaqueType */,
    YES /* plm_lexique_1_on */,
    YES /* plm_lexique_1_or */,
    YES /* plm_lexique_1_panic */,
    YES /* plm_lexique_1_pointerSize */,
    YES /* plm_lexique_1_primitive */,
    YES /* plm_lexique_1_priority */,
    YES /* plm_lexique_1_register */,
    YES /* plm_lexique_1_required */,
    YES /* plm_lexique_1_requiredBy */,
    YES /* plm_lexique_1_section */,
    YES /* plm_lexique_1_select */,
    YES /* plm_lexique_1_self */,
    YES /* plm_lexique_1_service */,
    YES /* plm_lexique_1_struct */,
    YES /* plm_lexique_1_stackSize */,
    YES /* plm_lexique_1_target */,
    YES /* plm_lexique_1_task */,
    YES /* plm_lexique_1_then */,
    YES /* plm_lexique_1_true */,
    YES /* plm_lexique_1_truncate */,
    YES /* plm_lexique_1_var */,
    YES /* plm_lexique_1_when */,
    YES /* plm_lexique_1_while */,
    YES /* plm_lexique_1_xor */,
    YES /* plm_lexique_1__3A_ */,
    YES /* plm_lexique_1__2E_ */,
    YES /* plm_lexique_1__2C_ */,
    YES /* plm_lexique_1__3B_ */,
    YES /* plm_lexique_1__7B_ */,
    YES /* plm_lexique_1__7D_ */,
    YES /* plm_lexique_1__3D_ */,
    YES /* plm_lexique_1__28_ */,
    YES /* plm_lexique_1__29_ */,
    YES /* plm_lexique_1__3D__3D_ */,
    YES /* plm_lexique_1__21__3D_ */,
    YES /* plm_lexique_1__3C_ */,
    YES /* plm_lexique_1__3C__3D_ */,
    YES /* plm_lexique_1__3E_ */,
    YES /* plm_lexique_1__3E__3D_ */,
    YES /* plm_lexique_1__5B_ */,
    YES /* plm_lexique_1__5D_ */,
    YES /* plm_lexique_1__3C__3C_ */,
    YES /* plm_lexique_1__3E__3E_ */,
    YES /* plm_lexique_1__7E_ */,
    YES /* plm_lexique_1__2D__3E_ */,
    YES /* plm_lexique_1__3A__3A_ */,
    YES /* plm_lexique_1__7C_ */,
    YES /* plm_lexique_1__7C__3D_ */,
    YES /* plm_lexique_1__26_ */,
    YES /* plm_lexique_1__26__3D_ */,
    YES /* plm_lexique_1__5E_ */,
    YES /* plm_lexique_1__5E__3D_ */,
    YES /* plm_lexique_1__2B_ */,
    YES /* plm_lexique_1__2B__25_ */,
    YES /* plm_lexique_1__2B__3D_ */,
    YES /* plm_lexique_1__2B__25__3D_ */,
    YES /* plm_lexique_1__2D_ */,
    YES /* plm_lexique_1__2D__25_ */,
    YES /* plm_lexique_1__2D__3D_ */,
    YES /* plm_lexique_1__2D__25__3D_ */,
    YES /* plm_lexique_1__2A_ */,
    YES /* plm_lexique_1__2A__25_ */,
    YES /* plm_lexique_1__2A__3D_ */,
    YES /* plm_lexique_1__2A__25__3D_ */,
    YES /* plm_lexique_1__2F_ */,
    YES /* plm_lexique_1__21__2F_ */,
    YES /* plm_lexique_1__2F__3D_ */,
    YES /* plm_lexique_1__21__2F__3D_ */,
    YES /* plm_lexique_1__25_ */,
    YES /* plm_lexique_1__21__25_ */,
    YES /* plm_lexique_1__25__3D_ */,
    YES /* plm_lexique_1__21__25__3D_ */
  } ;
  return kTerminalAtomicSelection [inTokenIndex] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//             S T Y L E   N A M E    F O R    I N D E X                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) styleNameForStyleIndex: (NSInteger) inIndex {
  NSString * result = nil ;
  if ((inIndex >= 0) && (inIndex < 10)) {
    NSString * kStyleArray [10] = {
      @"Default Style",
      @"Keywords",
      @"Attributes",
      @"Types",
      @"Modes",
      @"Integer Constants",
      @"Literal Strings",
      @"Comments",
      @"Delimiters",
      @"Selectors"
    } ;
    result = kStyleArray [inIndex] ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//         S T Y L E   I D E N T I F I E R    F O R    I N D E X                                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) styleIdentifierForStyleIndex: (NSInteger) inIndex {
  NSString * result = nil ;
  if ((inIndex >= 0) && (inIndex < 10)) {
    NSString * kStyleArray [10] = {
      @"plm_lexique",
      @"plm_lexique-keywordsStyle",
      @"plm_lexique-attributeStyle",
      @"plm_lexique-typeStyle",
      @"plm_lexique-modeStyle",
      @"plm_lexique-integerStyle",
      @"plm_lexique-stringStyle",
      @"plm_lexique-commentStyle",
      @"plm_lexique-delimitersStyle",
      @"plm_lexique-selectorStyle"
    } ;
    result = kStyleArray [inIndex] ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//         L E X I Q U E   I D E N T I F I E R                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) lexiqueIdentifier {
  return @"plm_lexique" ;
}

//---------------------------------------------------------------------------------------------------------------------*

@end

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


