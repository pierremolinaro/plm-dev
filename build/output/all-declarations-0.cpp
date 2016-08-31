#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-0.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     L E X I Q U E                                                                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "strings/unicode_character_cpp.h"
#include "galgas2/scanner_actions.h"
#include "galgas2/cLexiqueIntrospection.h"

//---------------------------------------------------------------------------------------------------------------------*

cTokenFor_plm_5F_lexique::cTokenFor_plm_5F_lexique (void) :
mLexicalAttribute_bigInteger (),
mLexicalAttribute_tokenString () {
}

//---------------------------------------------------------------------------------------------------------------------*

C_Lexique_plm_5F_lexique::C_Lexique_plm_5F_lexique (C_Compiler * inCallerCompiler,
                                                    const C_String & inDependencyFileExtension,
                                                    const C_String & inDependencyFilePath,
                                                    const C_String & inSourceFileName
                                                    COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inDependencyFileExtension, inDependencyFilePath, inSourceFileName COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

C_Lexique_plm_5F_lexique::C_Lexique_plm_5F_lexique (C_Compiler * inCallerCompiler,
                                                    const C_String & inSourceString,
                                                    const C_String & inStringForError
                                                    COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                 I N D E X I N G    D I R E C T O R Y                                                                *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_plm_5F_lexique::indexingDirectory (void) const {
  return "" ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                        Lexical error message list                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

static const char * gLexicalMessage_plm_5F_lexique_attributeError = "in an attribute name, a letter, a digit or a dot should follow the '@' character" ;

static const char * gLexicalMessage_plm_5F_lexique_binaryDigitError = "0b should be followed by a binary digit" ;

static const char * gLexicalMessage_plm_5F_lexique_hexDigitError = "0x should be followed by a hexadecimal digit" ;

static const char * gLexicalMessage_plm_5F_lexique_incorrectStringEnd = "string does not end with '\"'" ;

static const char * gLexicalMessage_plm_5F_lexique_internalError = "internal error" ;

static const char * gLexicalMessage_plm_5F_lexique_modeError = "in a mode name, a letter or a digit should follow the '`' character" ;

static const char * gLexicalMessage_plm_5F_lexique_typeError = "in a type name, a letter or a digit should follow the '$' character" ;

//---------------------------------------------------------------------------------------------------------------------*
//          Syntax error messages, for every terminal symbol                                                           *
//---------------------------------------------------------------------------------------------------------------------*

//--- Syntax error message for terminal '$identifier$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_identifier = "an identifier" ;

//--- Syntax error message for terminal '$@attribute$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__40_attribute = "an attribute @..." ;

//--- Syntax error message for terminal '$$type$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__24_type = "a type $..." ;

//--- Syntax error message for terminal '$`mode$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__60_mode = "a mode `..." ;

//--- Syntax error message for terminal '$integer$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_integer = "a literal integer" ;

//--- Syntax error message for terminal '$"string"$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__22_string_22_ = "a literal character string \"...\"" ;

//--- Syntax error message for terminal '$comment$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_comment = "a comment" ;

//--- Syntax error message for terminal '$?$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__3F_ = "the '\?' or '\?selector:' delimitor" ;

//--- Syntax error message for terminal '$?!$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__3F__21_ = "the '\?!' or '\?!selector:' delimitor" ;

//--- Syntax error message for terminal '$!$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__21_ = "the '!' or '!selector:' delimitor" ;

//--- Syntax error message for terminal '$!?$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__21__3F_ = "the '!\?' or '!\?selector:' delimitor" ;

//--- Syntax error message for terminal '$and$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_and = "the 'and' keyword" ;

//--- Syntax error message for terminal '$assert$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_assert = "the 'assert' keyword" ;

//--- Syntax error message for terminal '$at$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_at = "the 'at' keyword" ;

//--- Syntax error message for terminal '$boot$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_boot = "the 'boot' keyword" ;

//--- Syntax error message for terminal '$case$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_case = "the 'case' keyword" ;

//--- Syntax error message for terminal '$check$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_check = "the 'check' keyword" ;

//--- Syntax error message for terminal '$configuration$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_configuration = "the 'configuration' keyword" ;

//--- Syntax error message for terminal '$convert$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_convert = "the 'convert' keyword" ;

//--- Syntax error message for terminal '$do$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_do = "the 'do' keyword" ;

//--- Syntax error message for terminal '$else$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_else = "the 'else' keyword" ;

//--- Syntax error message for terminal '$enum$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_enum = "the 'enum' keyword" ;

//--- Syntax error message for terminal '$extend$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_extend = "the 'extend' keyword" ;

//--- Syntax error message for terminal '$extension$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_extension = "the 'extension' keyword" ;

//--- Syntax error message for terminal '$extern$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_extern = "the 'extern' keyword" ;

//--- Syntax error message for terminal '$false$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_false = "the 'false' keyword" ;

//--- Syntax error message for terminal '$for$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_for = "the 'for' keyword" ;

//--- Syntax error message for terminal '$func$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_func = "the 'func' keyword" ;

//--- Syntax error message for terminal '$guard$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_guard = "the 'guard' keyword" ;

//--- Syntax error message for terminal '$if$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_if = "the 'if' keyword" ;

//--- Syntax error message for terminal '$import$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_import = "the 'import' keyword" ;

//--- Syntax error message for terminal '$in$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_in = "the 'in' keyword" ;

//--- Syntax error message for terminal '$init$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_init = "the 'init' keyword" ;

//--- Syntax error message for terminal '$isr$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_isr = "the 'isr' keyword" ;

//--- Syntax error message for terminal '$let$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_let = "the 'let' keyword" ;

//--- Syntax error message for terminal '$module$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_module = "the 'module' keyword" ;

//--- Syntax error message for terminal '$not$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_not = "the 'not' keyword" ;

//--- Syntax error message for terminal '$or$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_or = "the 'or' keyword" ;

//--- Syntax error message for terminal '$panic$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_panic = "the 'panic' keyword" ;

//--- Syntax error message for terminal '$primitive$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_primitive = "the 'primitive' keyword" ;

//--- Syntax error message for terminal '$priority$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_priority = "the 'priority' keyword" ;

//--- Syntax error message for terminal '$public$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_public = "the 'public' keyword" ;

//--- Syntax error message for terminal '$register$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_register = "the 'register' keyword" ;

//--- Syntax error message for terminal '$required$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_required = "the 'required' keyword" ;

//--- Syntax error message for terminal '$section$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_section = "the 'section' keyword" ;

//--- Syntax error message for terminal '$self$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_self = "the 'self' keyword" ;

//--- Syntax error message for terminal '$service$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_service = "the 'service' keyword" ;

//--- Syntax error message for terminal '$struct$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_struct = "the 'struct' keyword" ;

//--- Syntax error message for terminal '$stackSize$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_stackSize = "the 'stackSize' keyword" ;

//--- Syntax error message for terminal '$sync$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_sync = "the 'sync' keyword" ;

//--- Syntax error message for terminal '$target$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_target = "the 'target' keyword" ;

//--- Syntax error message for terminal '$task$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_task = "the 'task' keyword" ;

//--- Syntax error message for terminal '$true$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_true = "the 'true' keyword" ;

//--- Syntax error message for terminal '$truncate$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_truncate = "the 'truncate' keyword" ;

//--- Syntax error message for terminal '$type$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_type = "the 'type' keyword" ;

//--- Syntax error message for terminal '$until$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_until = "the 'until' keyword" ;

//--- Syntax error message for terminal '$var$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_var = "the 'var' keyword" ;

//--- Syntax error message for terminal '$when$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_when = "the 'when' keyword" ;

//--- Syntax error message for terminal '$while$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_while = "the 'while' keyword" ;

//--- Syntax error message for terminal '$xor$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique_xor = "the 'xor' keyword" ;

//--- Syntax error message for terminal '$:$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__3A_ = "the ':' delimitor" ;

//--- Syntax error message for terminal '$.$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2E_ = "the '.' delimitor" ;

//--- Syntax error message for terminal '$,$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2C_ = "the ',' delimitor" ;

//--- Syntax error message for terminal '$;$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__3B_ = "the ';' delimitor" ;

//--- Syntax error message for terminal '${$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__7B_ = "the '{' delimitor" ;

//--- Syntax error message for terminal '$}$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__7D_ = "the '}' delimitor" ;

//--- Syntax error message for terminal '$=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__3D_ = "the '=' delimitor" ;

//--- Syntax error message for terminal '$($' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__28_ = "the '(' delimitor" ;

//--- Syntax error message for terminal '$)$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__29_ = "the ')' delimitor" ;

//--- Syntax error message for terminal '$==$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__3D__3D_ = "the '==' delimitor" ;

//--- Syntax error message for terminal '$!=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__21__3D_ = "the '!=' delimitor" ;

//--- Syntax error message for terminal '$<$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__3C_ = "the '<' delimitor" ;

//--- Syntax error message for terminal '$<=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__3C__3D_ = "the '<=' delimitor" ;

//--- Syntax error message for terminal '$>$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__3E_ = "the '>' delimitor" ;

//--- Syntax error message for terminal '$>=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__3E__3D_ = "the '>=' delimitor" ;

//--- Syntax error message for terminal '$[$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__5B_ = "the '[' delimitor" ;

//--- Syntax error message for terminal '$]$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__5D_ = "the ']' delimitor" ;

//--- Syntax error message for terminal '$<<$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__3C__3C_ = "the '<<' delimitor" ;

//--- Syntax error message for terminal '$>>$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__3E__3E_ = "the '>>' delimitor" ;

//--- Syntax error message for terminal '$~$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__7E_ = "the '~' delimitor" ;

//--- Syntax error message for terminal '$->$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2D__3E_ = "the '->' delimitor" ;

//--- Syntax error message for terminal '$..<$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2E__2E__3C_ = "the '..<' delimitor" ;

//--- Syntax error message for terminal '$|$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__7C_ = "the '|' delimitor" ;

//--- Syntax error message for terminal '$|=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__7C__3D_ = "the '|=' delimitor" ;

//--- Syntax error message for terminal '$&$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__26_ = "the '&' delimitor" ;

//--- Syntax error message for terminal '$&=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__26__3D_ = "the '&=' delimitor" ;

//--- Syntax error message for terminal '$^$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__5E_ = "the '^' delimitor" ;

//--- Syntax error message for terminal '$^=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__5E__3D_ = "the '^=' delimitor" ;

//--- Syntax error message for terminal '$+$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2B_ = "the '+' delimitor" ;

//--- Syntax error message for terminal '$+%$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2B__25_ = "the '+%' delimitor" ;

//--- Syntax error message for terminal '$+=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2B__3D_ = "the '+=' delimitor" ;

//--- Syntax error message for terminal '$+%=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2B__25__3D_ = "the '+%=' delimitor" ;

//--- Syntax error message for terminal '$-$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2D_ = "the '-' delimitor" ;

//--- Syntax error message for terminal '$-%$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2D__25_ = "the '-%' delimitor" ;

//--- Syntax error message for terminal '$-=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2D__3D_ = "the '-=' delimitor" ;

//--- Syntax error message for terminal '$-%=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2D__25__3D_ = "the '-%=' delimitor" ;

//--- Syntax error message for terminal '$*$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2A_ = "the '*' delimitor" ;

//--- Syntax error message for terminal '$*%$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2A__25_ = "the '*%' delimitor" ;

//--- Syntax error message for terminal '$*=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2A__3D_ = "the '*=' delimitor" ;

//--- Syntax error message for terminal '$*%=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2A__25__3D_ = "the '*%=' delimitor" ;

//--- Syntax error message for terminal '$/$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2F_ = "the '/' delimitor" ;

//--- Syntax error message for terminal '$!/$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__21__2F_ = "the '!/' delimitor" ;

//--- Syntax error message for terminal '$/=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__2F__3D_ = "the '/=' delimitor" ;

//--- Syntax error message for terminal '$!/=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__21__2F__3D_ = "the '!/=' delimitor" ;

//--- Syntax error message for terminal '$%$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__25_ = "the '%' delimitor" ;

//--- Syntax error message for terminal '$!%$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__21__25_ = "the '!%' delimitor" ;

//--- Syntax error message for terminal '$%=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__25__3D_ = "the '%=' delimitor" ;

//--- Syntax error message for terminal '$!%=$' :
static const char * gSyntaxErrorMessage_plm_5F_lexique__21__25__3D_ = "the '!%=' delimitor" ;

//---------------------------------------------------------------------------------------------------------------------*
//                getMessageForTerminal                                                                                *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_plm_5F_lexique::getMessageForTerminal (const int16_t inTerminalIndex) const {
  static const char * syntaxErrorMessageArray [109] = {kEndOfSourceLexicalErrorMessage,
    gSyntaxErrorMessage_plm_5F_lexique_identifier,
    gSyntaxErrorMessage_plm_5F_lexique__40_attribute,
    gSyntaxErrorMessage_plm_5F_lexique__24_type,
    gSyntaxErrorMessage_plm_5F_lexique__60_mode,
    gSyntaxErrorMessage_plm_5F_lexique_integer,
    gSyntaxErrorMessage_plm_5F_lexique__22_string_22_,
    gSyntaxErrorMessage_plm_5F_lexique_comment,
    gSyntaxErrorMessage_plm_5F_lexique__3F_,
    gSyntaxErrorMessage_plm_5F_lexique__3F__21_,
    gSyntaxErrorMessage_plm_5F_lexique__21_,
    gSyntaxErrorMessage_plm_5F_lexique__21__3F_,
    gSyntaxErrorMessage_plm_5F_lexique_and,
    gSyntaxErrorMessage_plm_5F_lexique_assert,
    gSyntaxErrorMessage_plm_5F_lexique_at,
    gSyntaxErrorMessage_plm_5F_lexique_boot,
    gSyntaxErrorMessage_plm_5F_lexique_case,
    gSyntaxErrorMessage_plm_5F_lexique_check,
    gSyntaxErrorMessage_plm_5F_lexique_configuration,
    gSyntaxErrorMessage_plm_5F_lexique_convert,
    gSyntaxErrorMessage_plm_5F_lexique_do,
    gSyntaxErrorMessage_plm_5F_lexique_else,
    gSyntaxErrorMessage_plm_5F_lexique_enum,
    gSyntaxErrorMessage_plm_5F_lexique_extend,
    gSyntaxErrorMessage_plm_5F_lexique_extension,
    gSyntaxErrorMessage_plm_5F_lexique_extern,
    gSyntaxErrorMessage_plm_5F_lexique_false,
    gSyntaxErrorMessage_plm_5F_lexique_for,
    gSyntaxErrorMessage_plm_5F_lexique_func,
    gSyntaxErrorMessage_plm_5F_lexique_guard,
    gSyntaxErrorMessage_plm_5F_lexique_if,
    gSyntaxErrorMessage_plm_5F_lexique_import,
    gSyntaxErrorMessage_plm_5F_lexique_in,
    gSyntaxErrorMessage_plm_5F_lexique_init,
    gSyntaxErrorMessage_plm_5F_lexique_isr,
    gSyntaxErrorMessage_plm_5F_lexique_let,
    gSyntaxErrorMessage_plm_5F_lexique_module,
    gSyntaxErrorMessage_plm_5F_lexique_not,
    gSyntaxErrorMessage_plm_5F_lexique_or,
    gSyntaxErrorMessage_plm_5F_lexique_panic,
    gSyntaxErrorMessage_plm_5F_lexique_primitive,
    gSyntaxErrorMessage_plm_5F_lexique_priority,
    gSyntaxErrorMessage_plm_5F_lexique_public,
    gSyntaxErrorMessage_plm_5F_lexique_register,
    gSyntaxErrorMessage_plm_5F_lexique_required,
    gSyntaxErrorMessage_plm_5F_lexique_section,
    gSyntaxErrorMessage_plm_5F_lexique_self,
    gSyntaxErrorMessage_plm_5F_lexique_service,
    gSyntaxErrorMessage_plm_5F_lexique_struct,
    gSyntaxErrorMessage_plm_5F_lexique_stackSize,
    gSyntaxErrorMessage_plm_5F_lexique_sync,
    gSyntaxErrorMessage_plm_5F_lexique_target,
    gSyntaxErrorMessage_plm_5F_lexique_task,
    gSyntaxErrorMessage_plm_5F_lexique_true,
    gSyntaxErrorMessage_plm_5F_lexique_truncate,
    gSyntaxErrorMessage_plm_5F_lexique_type,
    gSyntaxErrorMessage_plm_5F_lexique_until,
    gSyntaxErrorMessage_plm_5F_lexique_var,
    gSyntaxErrorMessage_plm_5F_lexique_when,
    gSyntaxErrorMessage_plm_5F_lexique_while,
    gSyntaxErrorMessage_plm_5F_lexique_xor,
    gSyntaxErrorMessage_plm_5F_lexique__3A_,
    gSyntaxErrorMessage_plm_5F_lexique__2E_,
    gSyntaxErrorMessage_plm_5F_lexique__2C_,
    gSyntaxErrorMessage_plm_5F_lexique__3B_,
    gSyntaxErrorMessage_plm_5F_lexique__7B_,
    gSyntaxErrorMessage_plm_5F_lexique__7D_,
    gSyntaxErrorMessage_plm_5F_lexique__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__28_,
    gSyntaxErrorMessage_plm_5F_lexique__29_,
    gSyntaxErrorMessage_plm_5F_lexique__3D__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__21__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__3C_,
    gSyntaxErrorMessage_plm_5F_lexique__3C__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__3E_,
    gSyntaxErrorMessage_plm_5F_lexique__3E__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__5B_,
    gSyntaxErrorMessage_plm_5F_lexique__5D_,
    gSyntaxErrorMessage_plm_5F_lexique__3C__3C_,
    gSyntaxErrorMessage_plm_5F_lexique__3E__3E_,
    gSyntaxErrorMessage_plm_5F_lexique__7E_,
    gSyntaxErrorMessage_plm_5F_lexique__2D__3E_,
    gSyntaxErrorMessage_plm_5F_lexique__2E__2E__3C_,
    gSyntaxErrorMessage_plm_5F_lexique__7C_,
    gSyntaxErrorMessage_plm_5F_lexique__7C__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__26_,
    gSyntaxErrorMessage_plm_5F_lexique__26__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__5E_,
    gSyntaxErrorMessage_plm_5F_lexique__5E__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__2B_,
    gSyntaxErrorMessage_plm_5F_lexique__2B__25_,
    gSyntaxErrorMessage_plm_5F_lexique__2B__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__2B__25__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__2D_,
    gSyntaxErrorMessage_plm_5F_lexique__2D__25_,
    gSyntaxErrorMessage_plm_5F_lexique__2D__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__2D__25__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__2A_,
    gSyntaxErrorMessage_plm_5F_lexique__2A__25_,
    gSyntaxErrorMessage_plm_5F_lexique__2A__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__2A__25__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__2F_,
    gSyntaxErrorMessage_plm_5F_lexique__21__2F_,
    gSyntaxErrorMessage_plm_5F_lexique__2F__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__21__2F__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__25_,
    gSyntaxErrorMessage_plm_5F_lexique__21__25_,
    gSyntaxErrorMessage_plm_5F_lexique__25__3D_,
    gSyntaxErrorMessage_plm_5F_lexique__21__25__3D_} ;
  return syntaxErrorMessageArray [inTerminalIndex] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                      U N I C O D E    S T R I N G S                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

//--- Unicode string for '$_21__25_$'
static const utf32 kUnicodeString_plm_5F_lexique__21__25_ [] = {
  TO_UNICODE ('!'),
  TO_UNICODE ('%'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_21__25__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__21__25__3D_ [] = {
  TO_UNICODE ('!'),
  TO_UNICODE ('%'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_21__2F_$'
static const utf32 kUnicodeString_plm_5F_lexique__21__2F_ [] = {
  TO_UNICODE ('!'),
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_21__2F__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__21__2F__3D_ [] = {
  TO_UNICODE ('!'),
  TO_UNICODE ('/'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_21__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__21__3D_ [] = {
  TO_UNICODE ('!'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_25_$'
static const utf32 kUnicodeString_plm_5F_lexique__25_ [] = {
  TO_UNICODE ('%'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_25__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__25__3D_ [] = {
  TO_UNICODE ('%'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_$'
static const utf32 kUnicodeString_plm_5F_lexique__26_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__26__3D_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_28_$'
static const utf32 kUnicodeString_plm_5F_lexique__28_ [] = {
  TO_UNICODE ('('),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_29_$'
static const utf32 kUnicodeString_plm_5F_lexique__29_ [] = {
  TO_UNICODE (')'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2A_$'
static const utf32 kUnicodeString_plm_5F_lexique__2A_ [] = {
  TO_UNICODE ('*'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2A__25_$'
static const utf32 kUnicodeString_plm_5F_lexique__2A__25_ [] = {
  TO_UNICODE ('*'),
  TO_UNICODE ('%'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2A__25__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__2A__25__3D_ [] = {
  TO_UNICODE ('*'),
  TO_UNICODE ('%'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2A__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__2A__3D_ [] = {
  TO_UNICODE ('*'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B_$'
static const utf32 kUnicodeString_plm_5F_lexique__2B_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B__25_$'
static const utf32 kUnicodeString_plm_5F_lexique__2B__25_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE ('%'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B__25__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__2B__25__3D_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE ('%'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__2B__3D_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2C_$'
static const utf32 kUnicodeString_plm_5F_lexique__2C_ [] = {
  TO_UNICODE (','),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D_$'
static const utf32 kUnicodeString_plm_5F_lexique__2D_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__25_$'
static const utf32 kUnicodeString_plm_5F_lexique__2D__25_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('%'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__25__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__2D__25__3D_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('%'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__2D__3D_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__3E_$'
static const utf32 kUnicodeString_plm_5F_lexique__2D__3E_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2E_$'
static const utf32 kUnicodeString_plm_5F_lexique__2E_ [] = {
  TO_UNICODE ('.'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2E__2E__3C_$'
static const utf32 kUnicodeString_plm_5F_lexique__2E__2E__3C_ [] = {
  TO_UNICODE ('.'),
  TO_UNICODE ('.'),
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F_$'
static const utf32 kUnicodeString_plm_5F_lexique__2F_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F__2F_$'
static const utf32 kUnicodeString_plm_5F_lexique__2F__2F_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__2F__3D_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_b$'
static const utf32 kUnicodeString_plm_5F_lexique__30_b [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('b'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_x$'
static const utf32 kUnicodeString_plm_5F_lexique__30_x [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('x'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A_$'
static const utf32 kUnicodeString_plm_5F_lexique__3A_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3B_$'
static const utf32 kUnicodeString_plm_5F_lexique__3B_ [] = {
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C_$'
static const utf32 kUnicodeString_plm_5F_lexique__3C_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3C_$'
static const utf32 kUnicodeString_plm_5F_lexique__3C__3C_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__3C__3D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__3D__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E_$'
static const utf32 kUnicodeString_plm_5F_lexique__3E_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__3E__3D_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E__3E_$'
static const utf32 kUnicodeString_plm_5F_lexique__3E__3E_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5B_$'
static const utf32 kUnicodeString_plm_5F_lexique__5B_ [] = {
  TO_UNICODE ('['),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5D_$'
static const utf32 kUnicodeString_plm_5F_lexique__5D_ [] = {
  TO_UNICODE (']'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5E_$'
static const utf32 kUnicodeString_plm_5F_lexique__5E_ [] = {
  TO_UNICODE ('^'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5E__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__5E__3D_ [] = {
  TO_UNICODE ('^'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$and$'
static const utf32 kUnicodeString_plm_5F_lexique_and [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$assert$'
static const utf32 kUnicodeString_plm_5F_lexique_assert [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('s'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$at$'
static const utf32 kUnicodeString_plm_5F_lexique_at [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$boot$'
static const utf32 kUnicodeString_plm_5F_lexique_boot [] = {
  TO_UNICODE ('b'),
  TO_UNICODE ('o'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$case$'
static const utf32 kUnicodeString_plm_5F_lexique_case [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('a'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$check$'
static const utf32 kUnicodeString_plm_5F_lexique_check [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('h'),
  TO_UNICODE ('e'),
  TO_UNICODE ('c'),
  TO_UNICODE ('k'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$configuration$'
static const utf32 kUnicodeString_plm_5F_lexique_configuration [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE ('f'),
  TO_UNICODE ('i'),
  TO_UNICODE ('g'),
  TO_UNICODE ('u'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$convert$'
static const utf32 kUnicodeString_plm_5F_lexique_convert [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE ('v'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$do$'
static const utf32 kUnicodeString_plm_5F_lexique_do [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('o'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$else$'
static const utf32 kUnicodeString_plm_5F_lexique_else [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$enum$'
static const utf32 kUnicodeString_plm_5F_lexique_enum [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('u'),
  TO_UNICODE ('m'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$extend$'
static const utf32 kUnicodeString_plm_5F_lexique_extend [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$extension$'
static const utf32 kUnicodeString_plm_5F_lexique_extension [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$extern$'
static const utf32 kUnicodeString_plm_5F_lexique_extern [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$false$'
static const utf32 kUnicodeString_plm_5F_lexique_false [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$for$'
static const utf32 kUnicodeString_plm_5F_lexique_for [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$func$'
static const utf32 kUnicodeString_plm_5F_lexique_func [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('u'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$guard$'
static const utf32 kUnicodeString_plm_5F_lexique_guard [] = {
  TO_UNICODE ('g'),
  TO_UNICODE ('u'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$if$'
static const utf32 kUnicodeString_plm_5F_lexique_if [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$import$'
static const utf32 kUnicodeString_plm_5F_lexique_import [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$in$'
static const utf32 kUnicodeString_plm_5F_lexique_in [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$init$'
static const utf32 kUnicodeString_plm_5F_lexique_init [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$isr$'
static const utf32 kUnicodeString_plm_5F_lexique_isr [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$let$'
static const utf32 kUnicodeString_plm_5F_lexique_let [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$module$'
static const utf32 kUnicodeString_plm_5F_lexique_module [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('o'),
  TO_UNICODE ('d'),
  TO_UNICODE ('u'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$not$'
static const utf32 kUnicodeString_plm_5F_lexique_not [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$or$'
static const utf32 kUnicodeString_plm_5F_lexique_or [] = {
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$panic$'
static const utf32 kUnicodeString_plm_5F_lexique_panic [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('a'),
  TO_UNICODE ('n'),
  TO_UNICODE ('i'),
  TO_UNICODE ('c'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$primitive$'
static const utf32 kUnicodeString_plm_5F_lexique_primitive [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('v'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$priority$'
static const utf32 kUnicodeString_plm_5F_lexique_priority [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$public$'
static const utf32 kUnicodeString_plm_5F_lexique_public [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('u'),
  TO_UNICODE ('b'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('c'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$register$'
static const utf32 kUnicodeString_plm_5F_lexique_register [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('g'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$required$'
static const utf32 kUnicodeString_plm_5F_lexique_required [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('q'),
  TO_UNICODE ('u'),
  TO_UNICODE ('i'),
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$section$'
static const utf32 kUnicodeString_plm_5F_lexique_section [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('c'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$self$'
static const utf32 kUnicodeString_plm_5F_lexique_self [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$service$'
static const utf32 kUnicodeString_plm_5F_lexique_service [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('v'),
  TO_UNICODE ('i'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$stackSize$'
static const utf32 kUnicodeString_plm_5F_lexique_stackSize [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('k'),
  TO_UNICODE ('S'),
  TO_UNICODE ('i'),
  TO_UNICODE ('z'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$struct$'
static const utf32 kUnicodeString_plm_5F_lexique_struct [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('u'),
  TO_UNICODE ('c'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$sync$'
static const utf32 kUnicodeString_plm_5F_lexique_sync [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('y'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$target$'
static const utf32 kUnicodeString_plm_5F_lexique_target [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE ('g'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$task$'
static const utf32 kUnicodeString_plm_5F_lexique_task [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('s'),
  TO_UNICODE ('k'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$true$'
static const utf32 kUnicodeString_plm_5F_lexique_true [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$truncate$'
static const utf32 kUnicodeString_plm_5F_lexique_truncate [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('u'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$type$'
static const utf32 kUnicodeString_plm_5F_lexique_type [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$until$'
static const utf32 kUnicodeString_plm_5F_lexique_until [] = {
  TO_UNICODE ('u'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('l'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$var$'
static const utf32 kUnicodeString_plm_5F_lexique_var [] = {
  TO_UNICODE ('v'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$when$'
static const utf32 kUnicodeString_plm_5F_lexique_when [] = {
  TO_UNICODE ('w'),
  TO_UNICODE ('h'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$while$'
static const utf32 kUnicodeString_plm_5F_lexique_while [] = {
  TO_UNICODE ('w'),
  TO_UNICODE ('h'),
  TO_UNICODE ('i'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$xor$'
static const utf32 kUnicodeString_plm_5F_lexique_xor [] = {
  TO_UNICODE ('x'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7B_$'
static const utf32 kUnicodeString_plm_5F_lexique__7B_ [] = {
  TO_UNICODE ('{'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7C_$'
static const utf32 kUnicodeString_plm_5F_lexique__7C_ [] = {
  TO_UNICODE ('|'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7C__3D_$'
static const utf32 kUnicodeString_plm_5F_lexique__7C__3D_ [] = {
  TO_UNICODE ('|'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7D_$'
static const utf32 kUnicodeString_plm_5F_lexique__7D_ [] = {
  TO_UNICODE ('}'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7E_$'
static const utf32 kUnicodeString_plm_5F_lexique__7E_ [] = {
  TO_UNICODE ('~'),
  TO_UNICODE (0)
} ;

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'delimitorsList'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_plm_5F_lexique_delimitorsList = 48 ;

static const C_unicode_lexique_table_entry ktable_for_plm_5F_lexique_delimitorsList [ktable_size_plm_5F_lexique_delimitorsList] = {
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__25_, 1, C_Lexique_plm_5F_lexique::kToken__25_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__26_, 1, C_Lexique_plm_5F_lexique::kToken__26_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__28_, 1, C_Lexique_plm_5F_lexique::kToken__28_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__29_, 1, C_Lexique_plm_5F_lexique::kToken__29_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2A_, 1, C_Lexique_plm_5F_lexique::kToken__2A_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2B_, 1, C_Lexique_plm_5F_lexique::kToken__2B_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2C_, 1, C_Lexique_plm_5F_lexique::kToken__2C_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2D_, 1, C_Lexique_plm_5F_lexique::kToken__2D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2E_, 1, C_Lexique_plm_5F_lexique::kToken__2E_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2F_, 1, C_Lexique_plm_5F_lexique::kToken__2F_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__3A_, 1, C_Lexique_plm_5F_lexique::kToken__3A_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__3B_, 1, C_Lexique_plm_5F_lexique::kToken__3B_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__3C_, 1, C_Lexique_plm_5F_lexique::kToken__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__3D_, 1, C_Lexique_plm_5F_lexique::kToken__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__3E_, 1, C_Lexique_plm_5F_lexique::kToken__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__5B_, 1, C_Lexique_plm_5F_lexique::kToken__5B_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__5D_, 1, C_Lexique_plm_5F_lexique::kToken__5D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__5E_, 1, C_Lexique_plm_5F_lexique::kToken__5E_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__7B_, 1, C_Lexique_plm_5F_lexique::kToken__7B_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__7C_, 1, C_Lexique_plm_5F_lexique::kToken__7C_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__7D_, 1, C_Lexique_plm_5F_lexique::kToken__7D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__7E_, 1, C_Lexique_plm_5F_lexique::kToken__7E_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__21__25_, 2, C_Lexique_plm_5F_lexique::kToken__21__25_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__21__2F_, 2, C_Lexique_plm_5F_lexique::kToken__21__2F_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__21__3D_, 2, C_Lexique_plm_5F_lexique::kToken__21__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__25__3D_, 2, C_Lexique_plm_5F_lexique::kToken__25__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__26__3D_, 2, C_Lexique_plm_5F_lexique::kToken__26__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2A__25_, 2, C_Lexique_plm_5F_lexique::kToken__2A__25_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2A__3D_, 2, C_Lexique_plm_5F_lexique::kToken__2A__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2B__25_, 2, C_Lexique_plm_5F_lexique::kToken__2B__25_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2B__3D_, 2, C_Lexique_plm_5F_lexique::kToken__2B__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2D__25_, 2, C_Lexique_plm_5F_lexique::kToken__2D__25_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2D__3D_, 2, C_Lexique_plm_5F_lexique::kToken__2D__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2D__3E_, 2, C_Lexique_plm_5F_lexique::kToken__2D__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2F__3D_, 2, C_Lexique_plm_5F_lexique::kToken__2F__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__3C__3C_, 2, C_Lexique_plm_5F_lexique::kToken__3C__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__3C__3D_, 2, C_Lexique_plm_5F_lexique::kToken__3C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__3D__3D_, 2, C_Lexique_plm_5F_lexique::kToken__3D__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__3E__3D_, 2, C_Lexique_plm_5F_lexique::kToken__3E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__3E__3E_, 2, C_Lexique_plm_5F_lexique::kToken__3E__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__5E__3D_, 2, C_Lexique_plm_5F_lexique::kToken__5E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__7C__3D_, 2, C_Lexique_plm_5F_lexique::kToken__7C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__21__25__3D_, 3, C_Lexique_plm_5F_lexique::kToken__21__25__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__21__2F__3D_, 3, C_Lexique_plm_5F_lexique::kToken__21__2F__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2A__25__3D_, 3, C_Lexique_plm_5F_lexique::kToken__2A__25__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2B__25__3D_, 3, C_Lexique_plm_5F_lexique::kToken__2B__25__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2D__25__3D_, 3, C_Lexique_plm_5F_lexique::kToken__2D__25__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique__2E__2E__3C_, 3, C_Lexique_plm_5F_lexique::kToken__2E__2E__3C_)
} ;

int16_t C_Lexique_plm_5F_lexique::search_into_delimitorsList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_plm_5F_lexique_delimitorsList, ktable_size_plm_5F_lexique_delimitorsList) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'keyWordList'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_plm_5F_lexique_keyWordList = 49 ;

static const C_unicode_lexique_table_entry ktable_for_plm_5F_lexique_keyWordList [ktable_size_plm_5F_lexique_keyWordList] = {
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_at, 2, C_Lexique_plm_5F_lexique::kToken_at),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_do, 2, C_Lexique_plm_5F_lexique::kToken_do),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_if, 2, C_Lexique_plm_5F_lexique::kToken_if),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_in, 2, C_Lexique_plm_5F_lexique::kToken_in),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_or, 2, C_Lexique_plm_5F_lexique::kToken_or),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_and, 3, C_Lexique_plm_5F_lexique::kToken_and),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_for, 3, C_Lexique_plm_5F_lexique::kToken_for),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_isr, 3, C_Lexique_plm_5F_lexique::kToken_isr),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_let, 3, C_Lexique_plm_5F_lexique::kToken_let),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_not, 3, C_Lexique_plm_5F_lexique::kToken_not),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_var, 3, C_Lexique_plm_5F_lexique::kToken_var),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_xor, 3, C_Lexique_plm_5F_lexique::kToken_xor),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_boot, 4, C_Lexique_plm_5F_lexique::kToken_boot),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_case, 4, C_Lexique_plm_5F_lexique::kToken_case),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_else, 4, C_Lexique_plm_5F_lexique::kToken_else),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_enum, 4, C_Lexique_plm_5F_lexique::kToken_enum),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_func, 4, C_Lexique_plm_5F_lexique::kToken_func),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_init, 4, C_Lexique_plm_5F_lexique::kToken_init),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_self, 4, C_Lexique_plm_5F_lexique::kToken_self),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_sync, 4, C_Lexique_plm_5F_lexique::kToken_sync),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_task, 4, C_Lexique_plm_5F_lexique::kToken_task),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_true, 4, C_Lexique_plm_5F_lexique::kToken_true),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_type, 4, C_Lexique_plm_5F_lexique::kToken_type),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_when, 4, C_Lexique_plm_5F_lexique::kToken_when),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_check, 5, C_Lexique_plm_5F_lexique::kToken_check),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_false, 5, C_Lexique_plm_5F_lexique::kToken_false),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_guard, 5, C_Lexique_plm_5F_lexique::kToken_guard),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_panic, 5, C_Lexique_plm_5F_lexique::kToken_panic),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_until, 5, C_Lexique_plm_5F_lexique::kToken_until),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_while, 5, C_Lexique_plm_5F_lexique::kToken_while),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_assert, 6, C_Lexique_plm_5F_lexique::kToken_assert),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_extend, 6, C_Lexique_plm_5F_lexique::kToken_extend),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_extern, 6, C_Lexique_plm_5F_lexique::kToken_extern),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_import, 6, C_Lexique_plm_5F_lexique::kToken_import),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_module, 6, C_Lexique_plm_5F_lexique::kToken_module),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_public, 6, C_Lexique_plm_5F_lexique::kToken_public),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_struct, 6, C_Lexique_plm_5F_lexique::kToken_struct),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_target, 6, C_Lexique_plm_5F_lexique::kToken_target),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_convert, 7, C_Lexique_plm_5F_lexique::kToken_convert),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_section, 7, C_Lexique_plm_5F_lexique::kToken_section),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_service, 7, C_Lexique_plm_5F_lexique::kToken_service),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_priority, 8, C_Lexique_plm_5F_lexique::kToken_priority),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_register, 8, C_Lexique_plm_5F_lexique::kToken_register),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_required, 8, C_Lexique_plm_5F_lexique::kToken_required),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_truncate, 8, C_Lexique_plm_5F_lexique::kToken_truncate),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_extension, 9, C_Lexique_plm_5F_lexique::kToken_extension),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_primitive, 9, C_Lexique_plm_5F_lexique::kToken_primitive),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_stackSize, 9, C_Lexique_plm_5F_lexique::kToken_stackSize),
  C_unicode_lexique_table_entry (kUnicodeString_plm_5F_lexique_configuration, 13, C_Lexique_plm_5F_lexique::kToken_configuration)
} ;

int16_t C_Lexique_plm_5F_lexique::search_into_keyWordList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_plm_5F_lexique_keyWordList, ktable_size_plm_5F_lexique_keyWordList) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                          getCurrentTokenString                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_plm_5F_lexique::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_plm_5F_lexique * ptr = (const cTokenFor_plm_5F_lexique *) inTokenPtr ;
  C_String s ;
  if (ptr == NULL) {
    s.appendCString("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString("$$") ;
      break ;
    case kToken_identifier:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("identifier") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken__40_attribute:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("@attribute") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken__24_type:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("$type") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken__60_mode:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("`mode") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_integer:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("integer") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_bigInteger.decimalString ()) ;
      break ;
    case kToken__22_string_22_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("\"string\"") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_comment:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("comment") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("\?") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken__3F__21_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("\?!") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken__21_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("!") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken__21__3F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("!\?") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_and:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("and") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_assert:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("assert") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_at:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("at") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_boot:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("boot") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_case:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("case") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_check:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("check") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_configuration:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("configuration") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_convert:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("convert") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_do:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("do") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_else:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("else") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_enum:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("enum") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_extend:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("extend") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_extension:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("extension") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_extern:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("extern") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_false:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("false") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_for:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("for") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_func:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("func") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_guard:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("guard") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_if:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("if") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_import:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("import") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_in:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("in") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_init:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("init") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_isr:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("isr") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_let:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("let") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_module:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("module") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_not:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("not") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_or:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("or") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_panic:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("panic") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_primitive:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("primitive") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_priority:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("priority") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_public:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("public") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_register:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("register") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_required:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("required") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_section:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("section") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_self:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("self") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_service:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("service") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_struct:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("struct") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_stackSize:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("stackSize") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_sync:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("sync") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_target:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("target") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_task:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("task") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_true:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("true") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_truncate:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("truncate") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_type:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("type") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_until:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("until") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_var:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("var") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_when:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("when") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_while:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("while") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_xor:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("xor") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (":") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (".") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (",") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (";") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("{") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("}") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__28_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("(") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__29_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (")") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3D__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("==") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__21__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("!=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("[") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("]") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__3C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<<") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">>") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("~") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("->") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2E__2E__3C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("..<") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("|") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7C__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("|=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__26_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("&") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__26__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("&=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("^") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5E__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("^=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("+") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2B__25_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("+%") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2B__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("+=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2B__25__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("+%=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D__25_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-%") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D__25__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-%=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("*") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2A__25_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("*%") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2A__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("*=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2A__25__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("*%=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("/") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__21__2F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("!/") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2F__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("/=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__21__2F__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("!/=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__25_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("%") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__21__25_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("!%") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__25__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("%=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__21__25__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("!%=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    default:
      break ;
    }
  }
  return s ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                           Template Delimiters                                                                       *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                           Template Replacements                                                                     *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//            Terminal Symbols as end of script in template mark                                                       *
//---------------------------------------------------------------------------------------------------------------------*



//---------------------------------------------------------------------------------------------------------------------*
//               P A R S E    L E X I C A L    T O K E N                                                               *
//---------------------------------------------------------------------------------------------------------------------*

bool C_Lexique_plm_5F_lexique::parseLexicalToken (void) {
  cTokenFor_plm_5F_lexique token ;
  mLoop = true ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    token.mLexicalAttribute_bigInteger.setToZero () ;
    token.mLexicalAttribute_tokenString.setLengthToZero () ;
    mTokenStartLocation = mCurrentLocation ;
    try{
      if (testForCharWithFunction (isUnicodeLetter)) {
        do {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
          if (testForCharWithFunction (isUnicodeLetter) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (token.mTokenCode == -1) {
          token.mTokenCode = search_into_keyWordList (token.mLexicalAttribute_tokenString) ;
        }
        if (token.mTokenCode == -1) {
          token.mTokenCode = kToken_identifier ;
        }
        enterToken (token) ;
      }else if (testForInputUTF32Char (TO_UNICODE ('@'))) {
        if (testForCharWithFunction (isUnicodeLetter) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          do {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            if (testForCharWithFunction (isUnicodeLetter) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32Char (TO_UNICODE ('.'))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
        }else{
          lexicalError (gLexicalMessage_plm_5F_lexique_attributeError COMMA_LINE_AND_SOURCE_FILE) ;
        }
        token.mTokenCode = kToken__40_attribute ;
        enterToken (token) ;
      }else if (testForInputUTF32Char (TO_UNICODE ('$'))) {
        if (testForCharWithFunction (isUnicodeLetter)) {
          do {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            if (testForCharWithFunction (isUnicodeLetter) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32Char (TO_UNICODE ('_'))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
        }else{
          lexicalError (gLexicalMessage_plm_5F_lexique_typeError COMMA_LINE_AND_SOURCE_FILE) ;
        }
        token.mTokenCode = kToken__24_type ;
        enterToken (token) ;
      }else if (testForInputUTF32Char (TO_UNICODE ('`'))) {
        if (testForCharWithFunction (isUnicodeLetter) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          do {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            if (testForCharWithFunction (isUnicodeLetter) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
        }else{
          lexicalError (gLexicalMessage_plm_5F_lexique_modeError COMMA_LINE_AND_SOURCE_FILE) ;
        }
        token.mTokenCode = kToken__60_mode ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__30_b, 2, true)) {
        do {
          if (testForInputUTF32Char (TO_UNICODE ('_'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('1'))) {
          ::scanner_routine_enterBinaryDigitIntoBigInt (*this, previousChar (), token.mLexicalAttribute_bigInteger, gLexicalMessage_plm_5F_lexique_internalError) ;
          do {
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('1'))) {
              ::scanner_routine_enterBinaryDigitIntoBigInt (*this, previousChar (), token.mLexicalAttribute_bigInteger, gLexicalMessage_plm_5F_lexique_internalError) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          token.mTokenCode = kToken_integer ;
          enterToken (token) ;
        }else{
          lexicalError (gLexicalMessage_plm_5F_lexique_binaryDigitError COMMA_LINE_AND_SOURCE_FILE) ;
        }
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__30_x, 2, true)) {
        do {
          if (testForInputUTF32Char (TO_UNICODE ('_'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
          ::scanner_routine_enterHexDigitIntoBigInt (*this, previousChar (), token.mLexicalAttribute_bigInteger, gLexicalMessage_plm_5F_lexique_internalError) ;
          do {
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
              ::scanner_routine_enterHexDigitIntoBigInt (*this, previousChar (), token.mLexicalAttribute_bigInteger, gLexicalMessage_plm_5F_lexique_internalError) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          token.mTokenCode = kToken_integer ;
          enterToken (token) ;
        }else{
          lexicalError (gLexicalMessage_plm_5F_lexique_hexDigitError COMMA_LINE_AND_SOURCE_FILE) ;
        }
      }else if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        ::scanner_routine_enterDecimalDigitIntoBigInt (*this, previousChar (), token.mLexicalAttribute_bigInteger, gLexicalMessage_plm_5F_lexique_internalError) ;
        do {
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            ::scanner_routine_enterDecimalDigitIntoBigInt (*this, previousChar (), token.mLexicalAttribute_bigInteger, gLexicalMessage_plm_5F_lexique_internalError) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        token.mTokenCode = kToken_integer ;
        enterToken (token) ;
      }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
        do {
          if (testForInputUTF32Char (TO_UNICODE (' ')) || testForInputUTF32Char (TO_UNICODE ('!')) || testForInputUTF32CharRange (TO_UNICODE ('#'), TO_UNICODE (65533))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
          token.mTokenCode = kToken__22_string_22_ ;
          enterToken (token) ;
        }else{
          lexicalError (gLexicalMessage_plm_5F_lexique_incorrectStringEnd COMMA_LINE_AND_SOURCE_FILE) ;
        }
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2F__2F_, 2, true)) {
        do {
          if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE ('\t')) || testForInputUTF32Char (TO_UNICODE ('\v')) || testForInputUTF32Char (TO_UNICODE ('\f')) || testForInputUTF32CharRange (TO_UNICODE (14), TO_UNICODE (65533))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        enterDroppedTerminal (kToken_comment) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2E__2E__3C_, 3, true)) {
        token.mTokenCode = kToken__2E__2E__3C_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2D__25__3D_, 3, true)) {
        token.mTokenCode = kToken__2D__25__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2B__25__3D_, 3, true)) {
        token.mTokenCode = kToken__2B__25__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2A__25__3D_, 3, true)) {
        token.mTokenCode = kToken__2A__25__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__21__2F__3D_, 3, true)) {
        token.mTokenCode = kToken__21__2F__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__21__25__3D_, 3, true)) {
        token.mTokenCode = kToken__21__25__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__7C__3D_, 2, true)) {
        token.mTokenCode = kToken__7C__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__5E__3D_, 2, true)) {
        token.mTokenCode = kToken__5E__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__3E__3E_, 2, true)) {
        token.mTokenCode = kToken__3E__3E_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__3E__3D_, 2, true)) {
        token.mTokenCode = kToken__3E__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__3D__3D_, 2, true)) {
        token.mTokenCode = kToken__3D__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__3C__3D_, 2, true)) {
        token.mTokenCode = kToken__3C__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__3C__3C_, 2, true)) {
        token.mTokenCode = kToken__3C__3C_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2F__3D_, 2, true)) {
        token.mTokenCode = kToken__2F__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2D__3E_, 2, true)) {
        token.mTokenCode = kToken__2D__3E_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2D__3D_, 2, true)) {
        token.mTokenCode = kToken__2D__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2D__25_, 2, true)) {
        token.mTokenCode = kToken__2D__25_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2B__3D_, 2, true)) {
        token.mTokenCode = kToken__2B__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2B__25_, 2, true)) {
        token.mTokenCode = kToken__2B__25_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2A__3D_, 2, true)) {
        token.mTokenCode = kToken__2A__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2A__25_, 2, true)) {
        token.mTokenCode = kToken__2A__25_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__26__3D_, 2, true)) {
        token.mTokenCode = kToken__26__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__25__3D_, 2, true)) {
        token.mTokenCode = kToken__25__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__21__3D_, 2, true)) {
        token.mTokenCode = kToken__21__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__21__2F_, 2, true)) {
        token.mTokenCode = kToken__21__2F_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__21__25_, 2, true)) {
        token.mTokenCode = kToken__21__25_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__7E_, 1, true)) {
        token.mTokenCode = kToken__7E_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__7D_, 1, true)) {
        token.mTokenCode = kToken__7D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__7C_, 1, true)) {
        token.mTokenCode = kToken__7C_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__7B_, 1, true)) {
        token.mTokenCode = kToken__7B_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__5E_, 1, true)) {
        token.mTokenCode = kToken__5E_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__5D_, 1, true)) {
        token.mTokenCode = kToken__5D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__5B_, 1, true)) {
        token.mTokenCode = kToken__5B_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__3E_, 1, true)) {
        token.mTokenCode = kToken__3E_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__3D_, 1, true)) {
        token.mTokenCode = kToken__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__3C_, 1, true)) {
        token.mTokenCode = kToken__3C_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__3B_, 1, true)) {
        token.mTokenCode = kToken__3B_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__3A_, 1, true)) {
        token.mTokenCode = kToken__3A_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2F_, 1, true)) {
        token.mTokenCode = kToken__2F_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2E_, 1, true)) {
        token.mTokenCode = kToken__2E_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2D_, 1, true)) {
        token.mTokenCode = kToken__2D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2C_, 1, true)) {
        token.mTokenCode = kToken__2C_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2B_, 1, true)) {
        token.mTokenCode = kToken__2B_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__2A_, 1, true)) {
        token.mTokenCode = kToken__2A_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__29_, 1, true)) {
        token.mTokenCode = kToken__29_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__28_, 1, true)) {
        token.mTokenCode = kToken__28_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__26_, 1, true)) {
        token.mTokenCode = kToken__26_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_plm_5F_lexique__25_, 1, true)) {
        token.mTokenCode = kToken__25_ ;
        enterToken (token) ;
      }else if (testForInputUTF32Char (TO_UNICODE ('\?'))) {
        const C_LocationInSource currentLocationForTag_onlyInterrogationMark = mCurrentLocation ;
        const C_LocationInSource endLocationForTag_onlyInterrogationMark = mTokenEndLocation ;
        const utf32 currentCharForTag_onlyInterrogationMark = mCurrentChar ;
        if (testForInputUTF32Char (TO_UNICODE ('!'))) {
          const C_LocationInSource currentLocationForTag_onlyExclamationInterrogationMark = mCurrentLocation ;
          const C_LocationInSource endLocationForTag_onlyExclamationInterrogationMark = mTokenEndLocation ;
          const utf32 currentCharForTag_onlyExclamationInterrogationMark = mCurrentChar ;
          if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
            do {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
              if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32Char (TO_UNICODE ('_'))) {
              }else{
                mLoop = false ;
              }
            }while (mLoop) ;
            mLoop = true ;
            if (testForInputUTF32Char (TO_UNICODE (':'))) {
              token.mTokenCode = kToken__3F__21_ ;
              enterToken (token) ;
            }else{
              ::scanner_routine_resetString (*this, token.mLexicalAttribute_tokenString) ;
              mCurrentLocation = currentLocationForTag_onlyExclamationInterrogationMark ;
              mTokenEndLocation = endLocationForTag_onlyExclamationInterrogationMark ;
              mCurrentChar = currentCharForTag_onlyExclamationInterrogationMark ;
              token.mTokenCode = kToken__3F__21_ ;
              enterToken (token) ;
            }
          }else{
            token.mTokenCode = kToken__3F__21_ ;
            enterToken (token) ;
          }
        }else if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
          do {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32Char (TO_UNICODE ('_'))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          if (testForInputUTF32Char (TO_UNICODE (':'))) {
            token.mTokenCode = kToken__3F_ ;
            enterToken (token) ;
          }else{
            ::scanner_routine_resetString (*this, token.mLexicalAttribute_tokenString) ;
            mCurrentLocation = currentLocationForTag_onlyInterrogationMark ;
            mTokenEndLocation = endLocationForTag_onlyInterrogationMark ;
            mCurrentChar = currentCharForTag_onlyInterrogationMark ;
            token.mTokenCode = kToken__3F_ ;
            enterToken (token) ;
          }
        }else{
          token.mTokenCode = kToken__3F_ ;
          enterToken (token) ;
        }
      }else if (testForInputUTF32Char (TO_UNICODE ('!'))) {
        const C_LocationInSource currentLocationForTag_onlyExclamationMark = mCurrentLocation ;
        const C_LocationInSource endLocationForTag_onlyExclamationMark = mTokenEndLocation ;
        const utf32 currentCharForTag_onlyExclamationMark = mCurrentChar ;
        if (testForInputUTF32Char (TO_UNICODE ('\?'))) {
          const C_LocationInSource currentLocationForTag_onlyInterrogationExclamationMark = mCurrentLocation ;
          const C_LocationInSource endLocationForTag_onlyInterrogationExclamationMark = mTokenEndLocation ;
          const utf32 currentCharForTag_onlyInterrogationExclamationMark = mCurrentChar ;
          if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
            do {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
              if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32Char (TO_UNICODE ('_'))) {
              }else{
                mLoop = false ;
              }
            }while (mLoop) ;
            mLoop = true ;
            if (testForInputUTF32Char (TO_UNICODE (':'))) {
              token.mTokenCode = kToken__21__3F_ ;
              enterToken (token) ;
            }else{
              ::scanner_routine_resetString (*this, token.mLexicalAttribute_tokenString) ;
              mCurrentLocation = currentLocationForTag_onlyInterrogationExclamationMark ;
              mTokenEndLocation = endLocationForTag_onlyInterrogationExclamationMark ;
              mCurrentChar = currentCharForTag_onlyInterrogationExclamationMark ;
              token.mTokenCode = kToken__21__3F_ ;
              enterToken (token) ;
            }
          }else{
            token.mTokenCode = kToken__21__3F_ ;
            enterToken (token) ;
          }
        }else if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
          do {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32Char (TO_UNICODE ('_'))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          if (testForInputUTF32Char (TO_UNICODE (':'))) {
            token.mTokenCode = kToken__21_ ;
            enterToken (token) ;
          }else{
            ::scanner_routine_resetString (*this, token.mLexicalAttribute_tokenString) ;
            mCurrentLocation = currentLocationForTag_onlyExclamationMark ;
            mTokenEndLocation = endLocationForTag_onlyExclamationMark ;
            mCurrentChar = currentCharForTag_onlyExclamationMark ;
            token.mTokenCode = kToken__21_ ;
            enterToken (token) ;
          }
        }else{
          token.mTokenCode = kToken__21_ ;
          enterToken (token) ;
        }
      }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (' '))) {
      }else if (testForInputUTF32Char (TO_UNICODE ('\0'))) { // End of source text ? 
        token.mTokenCode = kToken_ ; // Empty string code
      }else{ // Unknown input character
        unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
      }
    }catch (const C_lexicalErrorException &) {
      token.mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }
  if (UNICODE_VALUE (mCurrentChar) == '\0') { // && (token.mTemplateStringBeforeToken.length () > 0)) {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         E N T E R    T O K E N                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

void C_Lexique_plm_5F_lexique::enterToken (cTokenFor_plm_5F_lexique & ioToken) {
  cTokenFor_plm_5F_lexique * ptr = NULL ;
  macroMyNew (ptr, cTokenFor_plm_5F_lexique ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_bigInteger = ioToken.mLexicalAttribute_bigInteger ;
  ptr->mLexicalAttribute_tokenString = ioToken.mLexicalAttribute_tokenString ;
  enterTokenFromPointer (ptr) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//               A T T R I B U T E   A C C E S S                                                                       *
//---------------------------------------------------------------------------------------------------------------------*

C_BigInt C_Lexique_plm_5F_lexique::attributeValue_bigInteger (void) const {
  cTokenFor_plm_5F_lexique * ptr = (cTokenFor_plm_5F_lexique *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_bigInteger ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_plm_5F_lexique::attributeValue_tokenString (void) const {
  cTokenFor_plm_5F_lexique * ptr = (cTokenFor_plm_5F_lexique *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_tokenString ;
}

//---------------------------------------------------------------------------------------------------------------------*
//         A S S I G N    F R O M    A T T R I B U T E                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint C_Lexique_plm_5F_lexique::synthetizedAttribute_bigInteger (void) const {
  cTokenFor_plm_5F_lexique * ptr = (cTokenFor_plm_5F_lexique *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_plm_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_bigint value (ptr->mLexicalAttribute_bigInteger) ;
  GALGAS_lbigint result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_plm_5F_lexique::synthetizedAttribute_tokenString (void) const {
  cTokenFor_plm_5F_lexique * ptr = (cTokenFor_plm_5F_lexique *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_plm_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_tokenString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         I N T R O S P E C T I O N                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist C_Lexique_plm_5F_lexique::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("identifier") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("@attribute") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("$type") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("`mode") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("integer") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("\"string\"") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("comment") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("\?") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("\?!") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("!") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("!\?") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("and") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("assert") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("at") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("boot") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("case") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("check") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("configuration") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("convert") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("do") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("else") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("enum") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("extend") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("extension") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("extern") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("false") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("for") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("func") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("guard") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("if") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("import") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("in") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("init") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("isr") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("let") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("module") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("not") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("or") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("panic") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("primitive") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("priority") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("public") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("register") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("required") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("section") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("self") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("service") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("struct") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("stackSize") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("sync") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("target") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("task") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("true") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("truncate") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("type") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("until") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("var") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("when") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("while") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("xor") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (":") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (".") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (",") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (";") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("{") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("}") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("(") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (")") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("==") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("!=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("[") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("]") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<<") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">>") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("~") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("->") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("..<") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("|") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("|=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("&") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("&=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("^") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("^=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("+") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("+%") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("+=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("+%=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-%") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-%=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("*") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("*%") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("*=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("*%=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("/") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("!/") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("/=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("!/=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("%") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("!%") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("%=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("!%=") COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void getKeywordLists_plm_5F_lexique (TC_UniqueArray <C_String> & ioList) {
  ioList.addObject ("plm_lexique:delimitorsList") ;
  ioList.addObject ("plm_lexique:keyWordList") ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void getKeywordsForIdentifier_plm_5F_lexique (const C_String & inIdentifier,
                                                     bool & ioFound,
                                                     TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "plm_lexique:delimitorsList") {
    ioFound = true ;
    ioList.addObject ("%") ;
    ioList.addObject ("&") ;
    ioList.addObject ("(") ;
    ioList.addObject (")") ;
    ioList.addObject ("*") ;
    ioList.addObject ("+") ;
    ioList.addObject (",") ;
    ioList.addObject ("-") ;
    ioList.addObject (".") ;
    ioList.addObject ("/") ;
    ioList.addObject (":") ;
    ioList.addObject (";") ;
    ioList.addObject ("<") ;
    ioList.addObject ("=") ;
    ioList.addObject (">") ;
    ioList.addObject ("[") ;
    ioList.addObject ("]") ;
    ioList.addObject ("^") ;
    ioList.addObject ("{") ;
    ioList.addObject ("|") ;
    ioList.addObject ("}") ;
    ioList.addObject ("~") ;
    ioList.addObject ("!%") ;
    ioList.addObject ("!/") ;
    ioList.addObject ("!=") ;
    ioList.addObject ("%=") ;
    ioList.addObject ("&=") ;
    ioList.addObject ("*%") ;
    ioList.addObject ("*=") ;
    ioList.addObject ("+%") ;
    ioList.addObject ("+=") ;
    ioList.addObject ("-%") ;
    ioList.addObject ("-=") ;
    ioList.addObject ("->") ;
    ioList.addObject ("/=") ;
    ioList.addObject ("<<") ;
    ioList.addObject ("<=") ;
    ioList.addObject ("==") ;
    ioList.addObject (">=") ;
    ioList.addObject (">>") ;
    ioList.addObject ("^=") ;
    ioList.addObject ("|=") ;
    ioList.addObject ("!%=") ;
    ioList.addObject ("!/=") ;
    ioList.addObject ("*%=") ;
    ioList.addObject ("+%=") ;
    ioList.addObject ("-%=") ;
    ioList.addObject ("..<") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "plm_lexique:keyWordList") {
    ioFound = true ;
    ioList.addObject ("at") ;
    ioList.addObject ("do") ;
    ioList.addObject ("if") ;
    ioList.addObject ("in") ;
    ioList.addObject ("or") ;
    ioList.addObject ("and") ;
    ioList.addObject ("for") ;
    ioList.addObject ("isr") ;
    ioList.addObject ("let") ;
    ioList.addObject ("not") ;
    ioList.addObject ("var") ;
    ioList.addObject ("xor") ;
    ioList.addObject ("boot") ;
    ioList.addObject ("case") ;
    ioList.addObject ("else") ;
    ioList.addObject ("enum") ;
    ioList.addObject ("func") ;
    ioList.addObject ("init") ;
    ioList.addObject ("self") ;
    ioList.addObject ("sync") ;
    ioList.addObject ("task") ;
    ioList.addObject ("true") ;
    ioList.addObject ("type") ;
    ioList.addObject ("when") ;
    ioList.addObject ("check") ;
    ioList.addObject ("false") ;
    ioList.addObject ("guard") ;
    ioList.addObject ("panic") ;
    ioList.addObject ("until") ;
    ioList.addObject ("while") ;
    ioList.addObject ("assert") ;
    ioList.addObject ("extend") ;
    ioList.addObject ("extern") ;
    ioList.addObject ("import") ;
    ioList.addObject ("module") ;
    ioList.addObject ("public") ;
    ioList.addObject ("struct") ;
    ioList.addObject ("target") ;
    ioList.addObject ("convert") ;
    ioList.addObject ("section") ;
    ioList.addObject ("service") ;
    ioList.addObject ("priority") ;
    ioList.addObject ("register") ;
    ioList.addObject ("required") ;
    ioList.addObject ("truncate") ;
    ioList.addObject ("extension") ;
    ioList.addObject ("primitive") ;
    ioList.addObject ("stackSize") ;
    ioList.addObject ("configuration") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static cLexiqueIntrospection lexiqueIntrospection_plm_5F_lexique
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_plm_5F_lexique, getKeywordsForIdentifier_plm_5F_lexique) ;

//---------------------------------------------------------------------------------------------------------------------*
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_Lexique_plm_5F_lexique::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [109] = {0,
    0 /* plm_lexique_1_identifier */,
    2 /* plm_lexique_1__40_attribute */,
    3 /* plm_lexique_1__24_type */,
    4 /* plm_lexique_1__60_mode */,
    5 /* plm_lexique_1_integer */,
    6 /* plm_lexique_1__22_string_22_ */,
    7 /* plm_lexique_1_comment */,
    9 /* plm_lexique_1__3F_ */,
    9 /* plm_lexique_1__3F__21_ */,
    9 /* plm_lexique_1__21_ */,
    9 /* plm_lexique_1__21__3F_ */,
    1 /* plm_lexique_1_and */,
    1 /* plm_lexique_1_assert */,
    1 /* plm_lexique_1_at */,
    1 /* plm_lexique_1_boot */,
    1 /* plm_lexique_1_case */,
    1 /* plm_lexique_1_check */,
    1 /* plm_lexique_1_configuration */,
    1 /* plm_lexique_1_convert */,
    1 /* plm_lexique_1_do */,
    1 /* plm_lexique_1_else */,
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
    1 /* plm_lexique_1_isr */,
    1 /* plm_lexique_1_let */,
    1 /* plm_lexique_1_module */,
    1 /* plm_lexique_1_not */,
    1 /* plm_lexique_1_or */,
    1 /* plm_lexique_1_panic */,
    1 /* plm_lexique_1_primitive */,
    1 /* plm_lexique_1_priority */,
    1 /* plm_lexique_1_public */,
    1 /* plm_lexique_1_register */,
    1 /* plm_lexique_1_required */,
    1 /* plm_lexique_1_section */,
    1 /* plm_lexique_1_self */,
    1 /* plm_lexique_1_service */,
    1 /* plm_lexique_1_struct */,
    1 /* plm_lexique_1_stackSize */,
    1 /* plm_lexique_1_sync */,
    1 /* plm_lexique_1_target */,
    1 /* plm_lexique_1_task */,
    1 /* plm_lexique_1_true */,
    1 /* plm_lexique_1_truncate */,
    1 /* plm_lexique_1_type */,
    1 /* plm_lexique_1_until */,
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
    8 /* plm_lexique_1__2E__2E__3C_ */,
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
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                                            *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_plm_5F_lexique::styleNameForIndex (const uint32_t inStyleIndex) const {
  C_String result ;
  if (inStyleIndex < 10) {
    static const char * kStyleArray [10] = {
      "",
      "keywordsStyle",
      "attributeStyle",
      "typeStyle",
      "modeStyle",
      "integerStyle",
      "stringStyle",
      "commentStyle",
      "delimitersStyle",
      "selectorStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}

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
//                                                                                                                     *
//                              Abstract extension getter '@abstractDeclaration location'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_abstractDeclaration_location> gExtensionGetterTable_abstractDeclaration_location ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_location (const int32_t inClassIndex,
                                    enterExtensionGetter_abstractDeclaration_location inGetter) {
  gExtensionGetterTable_abstractDeclaration_location.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_abstractDeclaration_location (void) {
  gExtensionGetterTable_abstractDeclaration_location.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_abstractDeclaration_location (NULL,
                                                         freeExtensionGetter_abstractDeclaration_location) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location callExtensionGetter_location (const cPtr_abstractDeclaration * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_location result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_abstractDeclaration) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_abstractDeclaration_location f = NULL ;
    if (classIndex < gExtensionGetterTable_abstractDeclaration_location.count ()) {
      f = gExtensionGetterTable_abstractDeclaration_location (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_abstractDeclaration_location.count ()) {
           f = gExtensionGetterTable_abstractDeclaration_location (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_abstractDeclaration_location.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Class for element of '@declarationListAST' list                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_declarationListAST : public cCollectionElement {
  public : GALGAS_declarationListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_declarationListAST (const GALGAS_abstractDeclaration & in_mDeclaration
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

cCollectionElement_declarationListAST::cCollectionElement_declarationListAST (const GALGAS_abstractDeclaration & in_mDeclaration
                                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mDeclaration) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_declarationListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_declarationListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_declarationListAST (mObject.mAttribute_mDeclaration COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_declarationListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mDeclaration" ":" ;
  mObject.mAttribute_mDeclaration.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_declarationListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_declarationListAST * operand = (cCollectionElement_declarationListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_declarationListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST::GALGAS_declarationListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST::GALGAS_declarationListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST GALGAS_declarationListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_declarationListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST GALGAS_declarationListAST::constructor_listWithValue (const GALGAS_abstractDeclaration & inOperand0
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_declarationListAST result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_declarationListAST::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                           const GALGAS_abstractDeclaration & in_mDeclaration
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement_declarationListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_declarationListAST (in_mDeclaration COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationListAST::addAssign_operation (const GALGAS_abstractDeclaration & inOperand0
                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_declarationListAST (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationListAST::setter_insertAtIndex (const GALGAS_abstractDeclaration inOperand0,
                                                      const GALGAS_uint inInsertionIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_declarationListAST (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationListAST::setter_removeAtIndex (GALGAS_abstractDeclaration & outOperand0,
                                                      const GALGAS_uint inRemoveIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_declarationListAST * p = (cCollectionElement_declarationListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_declarationListAST) ;
      outOperand0 = p->mObject.mAttribute_mDeclaration ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationListAST::setter_popFirst (GALGAS_abstractDeclaration & outOperand0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_declarationListAST * p = (cCollectionElement_declarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_declarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationListAST::setter_popLast (GALGAS_abstractDeclaration & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_declarationListAST * p = (cCollectionElement_declarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_declarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationListAST::method_first (GALGAS_abstractDeclaration & outOperand0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_declarationListAST * p = (cCollectionElement_declarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_declarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationListAST::method_last (GALGAS_abstractDeclaration & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_declarationListAST * p = (cCollectionElement_declarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_declarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST GALGAS_declarationListAST::add_operation (const GALGAS_declarationListAST & inOperand,
                                                                    C_Compiler * /* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_declarationListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST GALGAS_declarationListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_declarationListAST result = GALGAS_declarationListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST GALGAS_declarationListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_declarationListAST result = GALGAS_declarationListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST GALGAS_declarationListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_declarationListAST result = GALGAS_declarationListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationListAST::plusAssign_operation (const GALGAS_declarationListAST inOperand,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractDeclaration GALGAS_declarationListAST::getter_mDeclarationAtIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_declarationListAST * p = (cCollectionElement_declarationListAST *) attributes.ptr () ;
  GALGAS_abstractDeclaration result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_declarationListAST) ;
    result = p->mObject.mAttribute_mDeclaration ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_declarationListAST::cEnumerator_declarationListAST (const GALGAS_declarationListAST & inEnumeratedObject,
                                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST_2D_element cEnumerator_declarationListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_declarationListAST * p = (const cCollectionElement_declarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_declarationListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractDeclaration cEnumerator_declarationListAST::current_mDeclaration (LOCATION_ARGS) const {
  const cCollectionElement_declarationListAST * p = (const cCollectionElement_declarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_declarationListAST) ;
  return p->mObject.mAttribute_mDeclaration ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @declarationListAST type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_declarationListAST ("declarationListAST",
                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_declarationListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_declarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_declarationListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_declarationListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST GALGAS_declarationListAST::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_declarationListAST result ;
  const GALGAS_declarationListAST * p = (const GALGAS_declarationListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_declarationListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("declarationListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Class for element of '@globalVarDeclarationList' list                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_globalVarDeclarationList : public cCollectionElement {
  public : GALGAS_globalVarDeclarationList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_globalVarDeclarationList (const GALGAS_lstring & in_mTypeName,
                                                        const GALGAS_lstring & in_mVarName,
                                                        const GALGAS_expressionAST & in_mSourceExpression,
                                                        const GALGAS_allowedRoutineList & in_mAllowedProcList,
                                                        const GALGAS_allowedInitList & in_mAllowedInitList,
                                                        const GALGAS_allowedPanicList & in_mAllowedPanicList,
                                                        const GALGAS_allowedGuardList & in_mAllowedGuardList,
                                                        const GALGAS_allowedISRList & in_mAllowedISRList,
                                                        const GALGAS_allowedTaskList & in_mAllowedTaskList,
                                                        const GALGAS_bool & in_mAllowedAccessToAll
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

cCollectionElement_globalVarDeclarationList::cCollectionElement_globalVarDeclarationList (const GALGAS_lstring & in_mTypeName,
                                                                                          const GALGAS_lstring & in_mVarName,
                                                                                          const GALGAS_expressionAST & in_mSourceExpression,
                                                                                          const GALGAS_allowedRoutineList & in_mAllowedProcList,
                                                                                          const GALGAS_allowedInitList & in_mAllowedInitList,
                                                                                          const GALGAS_allowedPanicList & in_mAllowedPanicList,
                                                                                          const GALGAS_allowedGuardList & in_mAllowedGuardList,
                                                                                          const GALGAS_allowedISRList & in_mAllowedISRList,
                                                                                          const GALGAS_allowedTaskList & in_mAllowedTaskList,
                                                                                          const GALGAS_bool & in_mAllowedAccessToAll
                                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mTypeName, in_mVarName, in_mSourceExpression, in_mAllowedProcList, in_mAllowedInitList, in_mAllowedPanicList, in_mAllowedGuardList, in_mAllowedISRList, in_mAllowedTaskList, in_mAllowedAccessToAll) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_globalVarDeclarationList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_globalVarDeclarationList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_globalVarDeclarationList (mObject.mAttribute_mTypeName, mObject.mAttribute_mVarName, mObject.mAttribute_mSourceExpression, mObject.mAttribute_mAllowedProcList, mObject.mAttribute_mAllowedInitList, mObject.mAttribute_mAllowedPanicList, mObject.mAttribute_mAllowedGuardList, mObject.mAttribute_mAllowedISRList, mObject.mAttribute_mAllowedTaskList, mObject.mAttribute_mAllowedAccessToAll COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_globalVarDeclarationList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mTypeName" ":" ;
  mObject.mAttribute_mTypeName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mVarName" ":" ;
  mObject.mAttribute_mVarName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSourceExpression" ":" ;
  mObject.mAttribute_mSourceExpression.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAllowedProcList" ":" ;
  mObject.mAttribute_mAllowedProcList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAllowedInitList" ":" ;
  mObject.mAttribute_mAllowedInitList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAllowedPanicList" ":" ;
  mObject.mAttribute_mAllowedPanicList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAllowedGuardList" ":" ;
  mObject.mAttribute_mAllowedGuardList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAllowedISRList" ":" ;
  mObject.mAttribute_mAllowedISRList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAllowedTaskList" ":" ;
  mObject.mAttribute_mAllowedTaskList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAllowedAccessToAll" ":" ;
  mObject.mAttribute_mAllowedAccessToAll.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_globalVarDeclarationList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_globalVarDeclarationList * operand = (cCollectionElement_globalVarDeclarationList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_globalVarDeclarationList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVarDeclarationList::GALGAS_globalVarDeclarationList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVarDeclarationList::GALGAS_globalVarDeclarationList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVarDeclarationList GALGAS_globalVarDeclarationList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_globalVarDeclarationList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVarDeclarationList GALGAS_globalVarDeclarationList::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                                            const GALGAS_lstring & inOperand1,
                                                                                            const GALGAS_expressionAST & inOperand2,
                                                                                            const GALGAS_allowedRoutineList & inOperand3,
                                                                                            const GALGAS_allowedInitList & inOperand4,
                                                                                            const GALGAS_allowedPanicList & inOperand5,
                                                                                            const GALGAS_allowedGuardList & inOperand6,
                                                                                            const GALGAS_allowedISRList & inOperand7,
                                                                                            const GALGAS_allowedTaskList & inOperand8,
                                                                                            const GALGAS_bool & inOperand9
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_globalVarDeclarationList result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid () && inOperand8.isValid () && inOperand9.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_globalVarDeclarationList::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7, inOperand8, inOperand9 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVarDeclarationList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                 const GALGAS_lstring & in_mTypeName,
                                                                 const GALGAS_lstring & in_mVarName,
                                                                 const GALGAS_expressionAST & in_mSourceExpression,
                                                                 const GALGAS_allowedRoutineList & in_mAllowedProcList,
                                                                 const GALGAS_allowedInitList & in_mAllowedInitList,
                                                                 const GALGAS_allowedPanicList & in_mAllowedPanicList,
                                                                 const GALGAS_allowedGuardList & in_mAllowedGuardList,
                                                                 const GALGAS_allowedISRList & in_mAllowedISRList,
                                                                 const GALGAS_allowedTaskList & in_mAllowedTaskList,
                                                                 const GALGAS_bool & in_mAllowedAccessToAll
                                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement_globalVarDeclarationList * p = NULL ;
  macroMyNew (p, cCollectionElement_globalVarDeclarationList (in_mTypeName,
                                                              in_mVarName,
                                                              in_mSourceExpression,
                                                              in_mAllowedProcList,
                                                              in_mAllowedInitList,
                                                              in_mAllowedPanicList,
                                                              in_mAllowedGuardList,
                                                              in_mAllowedISRList,
                                                              in_mAllowedTaskList,
                                                              in_mAllowedAccessToAll COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVarDeclarationList::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                           const GALGAS_lstring & inOperand1,
                                                           const GALGAS_expressionAST & inOperand2,
                                                           const GALGAS_allowedRoutineList & inOperand3,
                                                           const GALGAS_allowedInitList & inOperand4,
                                                           const GALGAS_allowedPanicList & inOperand5,
                                                           const GALGAS_allowedGuardList & inOperand6,
                                                           const GALGAS_allowedISRList & inOperand7,
                                                           const GALGAS_allowedTaskList & inOperand8,
                                                           const GALGAS_bool & inOperand9
                                                           COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid () && inOperand8.isValid () && inOperand9.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_globalVarDeclarationList (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7, inOperand8, inOperand9 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVarDeclarationList::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                            const GALGAS_lstring inOperand1,
                                                            const GALGAS_expressionAST inOperand2,
                                                            const GALGAS_allowedRoutineList inOperand3,
                                                            const GALGAS_allowedInitList inOperand4,
                                                            const GALGAS_allowedPanicList inOperand5,
                                                            const GALGAS_allowedGuardList inOperand6,
                                                            const GALGAS_allowedISRList inOperand7,
                                                            const GALGAS_allowedTaskList inOperand8,
                                                            const GALGAS_bool inOperand9,
                                                            const GALGAS_uint inInsertionIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid () && inOperand8.isValid () && inOperand9.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_globalVarDeclarationList (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7, inOperand8, inOperand9 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVarDeclarationList::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                            GALGAS_lstring & outOperand1,
                                                            GALGAS_expressionAST & outOperand2,
                                                            GALGAS_allowedRoutineList & outOperand3,
                                                            GALGAS_allowedInitList & outOperand4,
                                                            GALGAS_allowedPanicList & outOperand5,
                                                            GALGAS_allowedGuardList & outOperand6,
                                                            GALGAS_allowedISRList & outOperand7,
                                                            GALGAS_allowedTaskList & outOperand8,
                                                            GALGAS_bool & outOperand9,
                                                            const GALGAS_uint inRemoveIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
      outOperand4.drop () ;
      outOperand5.drop () ;
      outOperand6.drop () ;
      outOperand7.drop () ;
      outOperand8.drop () ;
      outOperand9.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
      outOperand0 = p->mObject.mAttribute_mTypeName ;
      outOperand1 = p->mObject.mAttribute_mVarName ;
      outOperand2 = p->mObject.mAttribute_mSourceExpression ;
      outOperand3 = p->mObject.mAttribute_mAllowedProcList ;
      outOperand4 = p->mObject.mAttribute_mAllowedInitList ;
      outOperand5 = p->mObject.mAttribute_mAllowedPanicList ;
      outOperand6 = p->mObject.mAttribute_mAllowedGuardList ;
      outOperand7 = p->mObject.mAttribute_mAllowedISRList ;
      outOperand8 = p->mObject.mAttribute_mAllowedTaskList ;
      outOperand9 = p->mObject.mAttribute_mAllowedAccessToAll ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVarDeclarationList::setter_popFirst (GALGAS_lstring & outOperand0,
                                                       GALGAS_lstring & outOperand1,
                                                       GALGAS_expressionAST & outOperand2,
                                                       GALGAS_allowedRoutineList & outOperand3,
                                                       GALGAS_allowedInitList & outOperand4,
                                                       GALGAS_allowedPanicList & outOperand5,
                                                       GALGAS_allowedGuardList & outOperand6,
                                                       GALGAS_allowedISRList & outOperand7,
                                                       GALGAS_allowedTaskList & outOperand8,
                                                       GALGAS_bool & outOperand9,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
    outOperand7.drop () ;
    outOperand8.drop () ;
    outOperand9.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    outOperand0 = p->mObject.mAttribute_mTypeName ;
    outOperand1 = p->mObject.mAttribute_mVarName ;
    outOperand2 = p->mObject.mAttribute_mSourceExpression ;
    outOperand3 = p->mObject.mAttribute_mAllowedProcList ;
    outOperand4 = p->mObject.mAttribute_mAllowedInitList ;
    outOperand5 = p->mObject.mAttribute_mAllowedPanicList ;
    outOperand6 = p->mObject.mAttribute_mAllowedGuardList ;
    outOperand7 = p->mObject.mAttribute_mAllowedISRList ;
    outOperand8 = p->mObject.mAttribute_mAllowedTaskList ;
    outOperand9 = p->mObject.mAttribute_mAllowedAccessToAll ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVarDeclarationList::setter_popLast (GALGAS_lstring & outOperand0,
                                                      GALGAS_lstring & outOperand1,
                                                      GALGAS_expressionAST & outOperand2,
                                                      GALGAS_allowedRoutineList & outOperand3,
                                                      GALGAS_allowedInitList & outOperand4,
                                                      GALGAS_allowedPanicList & outOperand5,
                                                      GALGAS_allowedGuardList & outOperand6,
                                                      GALGAS_allowedISRList & outOperand7,
                                                      GALGAS_allowedTaskList & outOperand8,
                                                      GALGAS_bool & outOperand9,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
    outOperand7.drop () ;
    outOperand8.drop () ;
    outOperand9.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    outOperand0 = p->mObject.mAttribute_mTypeName ;
    outOperand1 = p->mObject.mAttribute_mVarName ;
    outOperand2 = p->mObject.mAttribute_mSourceExpression ;
    outOperand3 = p->mObject.mAttribute_mAllowedProcList ;
    outOperand4 = p->mObject.mAttribute_mAllowedInitList ;
    outOperand5 = p->mObject.mAttribute_mAllowedPanicList ;
    outOperand6 = p->mObject.mAttribute_mAllowedGuardList ;
    outOperand7 = p->mObject.mAttribute_mAllowedISRList ;
    outOperand8 = p->mObject.mAttribute_mAllowedTaskList ;
    outOperand9 = p->mObject.mAttribute_mAllowedAccessToAll ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVarDeclarationList::method_first (GALGAS_lstring & outOperand0,
                                                    GALGAS_lstring & outOperand1,
                                                    GALGAS_expressionAST & outOperand2,
                                                    GALGAS_allowedRoutineList & outOperand3,
                                                    GALGAS_allowedInitList & outOperand4,
                                                    GALGAS_allowedPanicList & outOperand5,
                                                    GALGAS_allowedGuardList & outOperand6,
                                                    GALGAS_allowedISRList & outOperand7,
                                                    GALGAS_allowedTaskList & outOperand8,
                                                    GALGAS_bool & outOperand9,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
    outOperand7.drop () ;
    outOperand8.drop () ;
    outOperand9.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    outOperand0 = p->mObject.mAttribute_mTypeName ;
    outOperand1 = p->mObject.mAttribute_mVarName ;
    outOperand2 = p->mObject.mAttribute_mSourceExpression ;
    outOperand3 = p->mObject.mAttribute_mAllowedProcList ;
    outOperand4 = p->mObject.mAttribute_mAllowedInitList ;
    outOperand5 = p->mObject.mAttribute_mAllowedPanicList ;
    outOperand6 = p->mObject.mAttribute_mAllowedGuardList ;
    outOperand7 = p->mObject.mAttribute_mAllowedISRList ;
    outOperand8 = p->mObject.mAttribute_mAllowedTaskList ;
    outOperand9 = p->mObject.mAttribute_mAllowedAccessToAll ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVarDeclarationList::method_last (GALGAS_lstring & outOperand0,
                                                   GALGAS_lstring & outOperand1,
                                                   GALGAS_expressionAST & outOperand2,
                                                   GALGAS_allowedRoutineList & outOperand3,
                                                   GALGAS_allowedInitList & outOperand4,
                                                   GALGAS_allowedPanicList & outOperand5,
                                                   GALGAS_allowedGuardList & outOperand6,
                                                   GALGAS_allowedISRList & outOperand7,
                                                   GALGAS_allowedTaskList & outOperand8,
                                                   GALGAS_bool & outOperand9,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
    outOperand7.drop () ;
    outOperand8.drop () ;
    outOperand9.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    outOperand0 = p->mObject.mAttribute_mTypeName ;
    outOperand1 = p->mObject.mAttribute_mVarName ;
    outOperand2 = p->mObject.mAttribute_mSourceExpression ;
    outOperand3 = p->mObject.mAttribute_mAllowedProcList ;
    outOperand4 = p->mObject.mAttribute_mAllowedInitList ;
    outOperand5 = p->mObject.mAttribute_mAllowedPanicList ;
    outOperand6 = p->mObject.mAttribute_mAllowedGuardList ;
    outOperand7 = p->mObject.mAttribute_mAllowedISRList ;
    outOperand8 = p->mObject.mAttribute_mAllowedTaskList ;
    outOperand9 = p->mObject.mAttribute_mAllowedAccessToAll ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVarDeclarationList GALGAS_globalVarDeclarationList::add_operation (const GALGAS_globalVarDeclarationList & inOperand,
                                                                                C_Compiler * /* inCompiler */
                                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_globalVarDeclarationList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVarDeclarationList GALGAS_globalVarDeclarationList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_globalVarDeclarationList result = GALGAS_globalVarDeclarationList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVarDeclarationList GALGAS_globalVarDeclarationList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_globalVarDeclarationList result = GALGAS_globalVarDeclarationList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVarDeclarationList GALGAS_globalVarDeclarationList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_globalVarDeclarationList result = GALGAS_globalVarDeclarationList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVarDeclarationList::plusAssign_operation (const GALGAS_globalVarDeclarationList inOperand,
                                                            C_Compiler * /* inCompiler */
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_globalVarDeclarationList::getter_mTypeNameAtIndex (const GALGAS_uint & inIndex,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    result = p->mObject.mAttribute_mTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_globalVarDeclarationList::getter_mVarNameAtIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    result = p->mObject.mAttribute_mVarName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_globalVarDeclarationList::getter_mSourceExpressionAtIndex (const GALGAS_uint & inIndex,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  GALGAS_expressionAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    result = p->mObject.mAttribute_mSourceExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineList GALGAS_globalVarDeclarationList::getter_mAllowedProcListAtIndex (const GALGAS_uint & inIndex,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  GALGAS_allowedRoutineList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    result = p->mObject.mAttribute_mAllowedProcList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedInitList GALGAS_globalVarDeclarationList::getter_mAllowedInitListAtIndex (const GALGAS_uint & inIndex,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  GALGAS_allowedInitList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    result = p->mObject.mAttribute_mAllowedInitList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedPanicList GALGAS_globalVarDeclarationList::getter_mAllowedPanicListAtIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  GALGAS_allowedPanicList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    result = p->mObject.mAttribute_mAllowedPanicList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardList GALGAS_globalVarDeclarationList::getter_mAllowedGuardListAtIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  GALGAS_allowedGuardList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    result = p->mObject.mAttribute_mAllowedGuardList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRList GALGAS_globalVarDeclarationList::getter_mAllowedISRListAtIndex (const GALGAS_uint & inIndex,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  GALGAS_allowedISRList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    result = p->mObject.mAttribute_mAllowedISRList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedTaskList GALGAS_globalVarDeclarationList::getter_mAllowedTaskListAtIndex (const GALGAS_uint & inIndex,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  GALGAS_allowedTaskList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    result = p->mObject.mAttribute_mAllowedTaskList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_globalVarDeclarationList::getter_mAllowedAccessToAllAtIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalVarDeclarationList * p = (cCollectionElement_globalVarDeclarationList *) attributes.ptr () ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
    result = p->mObject.mAttribute_mAllowedAccessToAll ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_globalVarDeclarationList::cEnumerator_globalVarDeclarationList (const GALGAS_globalVarDeclarationList & inEnumeratedObject,
                                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVarDeclarationList_2D_element cEnumerator_globalVarDeclarationList::current (LOCATION_ARGS) const {
  const cCollectionElement_globalVarDeclarationList * p = (const cCollectionElement_globalVarDeclarationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_globalVarDeclarationList::current_mTypeName (LOCATION_ARGS) const {
  const cCollectionElement_globalVarDeclarationList * p = (const cCollectionElement_globalVarDeclarationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
  return p->mObject.mAttribute_mTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_globalVarDeclarationList::current_mVarName (LOCATION_ARGS) const {
  const cCollectionElement_globalVarDeclarationList * p = (const cCollectionElement_globalVarDeclarationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
  return p->mObject.mAttribute_mVarName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST cEnumerator_globalVarDeclarationList::current_mSourceExpression (LOCATION_ARGS) const {
  const cCollectionElement_globalVarDeclarationList * p = (const cCollectionElement_globalVarDeclarationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
  return p->mObject.mAttribute_mSourceExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineList cEnumerator_globalVarDeclarationList::current_mAllowedProcList (LOCATION_ARGS) const {
  const cCollectionElement_globalVarDeclarationList * p = (const cCollectionElement_globalVarDeclarationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
  return p->mObject.mAttribute_mAllowedProcList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedInitList cEnumerator_globalVarDeclarationList::current_mAllowedInitList (LOCATION_ARGS) const {
  const cCollectionElement_globalVarDeclarationList * p = (const cCollectionElement_globalVarDeclarationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
  return p->mObject.mAttribute_mAllowedInitList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedPanicList cEnumerator_globalVarDeclarationList::current_mAllowedPanicList (LOCATION_ARGS) const {
  const cCollectionElement_globalVarDeclarationList * p = (const cCollectionElement_globalVarDeclarationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
  return p->mObject.mAttribute_mAllowedPanicList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardList cEnumerator_globalVarDeclarationList::current_mAllowedGuardList (LOCATION_ARGS) const {
  const cCollectionElement_globalVarDeclarationList * p = (const cCollectionElement_globalVarDeclarationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
  return p->mObject.mAttribute_mAllowedGuardList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRList cEnumerator_globalVarDeclarationList::current_mAllowedISRList (LOCATION_ARGS) const {
  const cCollectionElement_globalVarDeclarationList * p = (const cCollectionElement_globalVarDeclarationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
  return p->mObject.mAttribute_mAllowedISRList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedTaskList cEnumerator_globalVarDeclarationList::current_mAllowedTaskList (LOCATION_ARGS) const {
  const cCollectionElement_globalVarDeclarationList * p = (const cCollectionElement_globalVarDeclarationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
  return p->mObject.mAttribute_mAllowedTaskList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_globalVarDeclarationList::current_mAllowedAccessToAll (LOCATION_ARGS) const {
  const cCollectionElement_globalVarDeclarationList * p = (const cCollectionElement_globalVarDeclarationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalVarDeclarationList) ;
  return p->mObject.mAttribute_mAllowedAccessToAll ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @globalVarDeclarationList type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_globalVarDeclarationList ("globalVarDeclarationList",
                                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_globalVarDeclarationList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalVarDeclarationList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_globalVarDeclarationList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_globalVarDeclarationList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVarDeclarationList GALGAS_globalVarDeclarationList::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_globalVarDeclarationList result ;
  const GALGAS_globalVarDeclarationList * p = (const GALGAS_globalVarDeclarationList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_globalVarDeclarationList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("globalVarDeclarationList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Class for element of '@extensionDeclarationListAST' list                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_extensionDeclarationListAST : public cCollectionElement {
  public : GALGAS_extensionDeclarationListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_extensionDeclarationListAST (const GALGAS_lstring & in_mTypeName,
                                                           const GALGAS_functionDeclarationListAST & in_mProcedureDeclarationListAST,
                                                           const GALGAS_structurePropertyListAST & in_mPropertyList,
                                                           const GALGAS_serviceDeclarationListAST & in_mServiceListAST,
                                                           const GALGAS_sectionDeclarationListAST & in_mSectionListAST,
                                                           const GALGAS_primitiveDeclarationListAST & in_mPrimitiveListAST,
                                                           const GALGAS_guardDeclarationListAST & in_mGuardListAST
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

cCollectionElement_extensionDeclarationListAST::cCollectionElement_extensionDeclarationListAST (const GALGAS_lstring & in_mTypeName,
                                                                                                const GALGAS_functionDeclarationListAST & in_mProcedureDeclarationListAST,
                                                                                                const GALGAS_structurePropertyListAST & in_mPropertyList,
                                                                                                const GALGAS_serviceDeclarationListAST & in_mServiceListAST,
                                                                                                const GALGAS_sectionDeclarationListAST & in_mSectionListAST,
                                                                                                const GALGAS_primitiveDeclarationListAST & in_mPrimitiveListAST,
                                                                                                const GALGAS_guardDeclarationListAST & in_mGuardListAST
                                                                                                COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mTypeName, in_mProcedureDeclarationListAST, in_mPropertyList, in_mServiceListAST, in_mSectionListAST, in_mPrimitiveListAST, in_mGuardListAST) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_extensionDeclarationListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_extensionDeclarationListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_extensionDeclarationListAST (mObject.mAttribute_mTypeName, mObject.mAttribute_mProcedureDeclarationListAST, mObject.mAttribute_mPropertyList, mObject.mAttribute_mServiceListAST, mObject.mAttribute_mSectionListAST, mObject.mAttribute_mPrimitiveListAST, mObject.mAttribute_mGuardListAST COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_extensionDeclarationListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mTypeName" ":" ;
  mObject.mAttribute_mTypeName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mProcedureDeclarationListAST" ":" ;
  mObject.mAttribute_mProcedureDeclarationListAST.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPropertyList" ":" ;
  mObject.mAttribute_mPropertyList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mServiceListAST" ":" ;
  mObject.mAttribute_mServiceListAST.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSectionListAST" ":" ;
  mObject.mAttribute_mSectionListAST.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPrimitiveListAST" ":" ;
  mObject.mAttribute_mPrimitiveListAST.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGuardListAST" ":" ;
  mObject.mAttribute_mGuardListAST.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_extensionDeclarationListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_extensionDeclarationListAST * operand = (cCollectionElement_extensionDeclarationListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_extensionDeclarationListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST::GALGAS_extensionDeclarationListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST::GALGAS_extensionDeclarationListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST GALGAS_extensionDeclarationListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_extensionDeclarationListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST GALGAS_extensionDeclarationListAST::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                                                  const GALGAS_functionDeclarationListAST & inOperand1,
                                                                                                  const GALGAS_structurePropertyListAST & inOperand2,
                                                                                                  const GALGAS_serviceDeclarationListAST & inOperand3,
                                                                                                  const GALGAS_sectionDeclarationListAST & inOperand4,
                                                                                                  const GALGAS_primitiveDeclarationListAST & inOperand5,
                                                                                                  const GALGAS_guardDeclarationListAST & inOperand6
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_extensionDeclarationListAST result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_extensionDeclarationListAST::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extensionDeclarationListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                    const GALGAS_lstring & in_mTypeName,
                                                                    const GALGAS_functionDeclarationListAST & in_mProcedureDeclarationListAST,
                                                                    const GALGAS_structurePropertyListAST & in_mPropertyList,
                                                                    const GALGAS_serviceDeclarationListAST & in_mServiceListAST,
                                                                    const GALGAS_sectionDeclarationListAST & in_mSectionListAST,
                                                                    const GALGAS_primitiveDeclarationListAST & in_mPrimitiveListAST,
                                                                    const GALGAS_guardDeclarationListAST & in_mGuardListAST
                                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_extensionDeclarationListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_extensionDeclarationListAST (in_mTypeName,
                                                                 in_mProcedureDeclarationListAST,
                                                                 in_mPropertyList,
                                                                 in_mServiceListAST,
                                                                 in_mSectionListAST,
                                                                 in_mPrimitiveListAST,
                                                                 in_mGuardListAST COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extensionDeclarationListAST::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                              const GALGAS_functionDeclarationListAST & inOperand1,
                                                              const GALGAS_structurePropertyListAST & inOperand2,
                                                              const GALGAS_serviceDeclarationListAST & inOperand3,
                                                              const GALGAS_sectionDeclarationListAST & inOperand4,
                                                              const GALGAS_primitiveDeclarationListAST & inOperand5,
                                                              const GALGAS_guardDeclarationListAST & inOperand6
                                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_extensionDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extensionDeclarationListAST::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                               const GALGAS_functionDeclarationListAST inOperand1,
                                                               const GALGAS_structurePropertyListAST inOperand2,
                                                               const GALGAS_serviceDeclarationListAST inOperand3,
                                                               const GALGAS_sectionDeclarationListAST inOperand4,
                                                               const GALGAS_primitiveDeclarationListAST inOperand5,
                                                               const GALGAS_guardDeclarationListAST inOperand6,
                                                               const GALGAS_uint inInsertionIndex,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_extensionDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extensionDeclarationListAST::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                               GALGAS_functionDeclarationListAST & outOperand1,
                                                               GALGAS_structurePropertyListAST & outOperand2,
                                                               GALGAS_serviceDeclarationListAST & outOperand3,
                                                               GALGAS_sectionDeclarationListAST & outOperand4,
                                                               GALGAS_primitiveDeclarationListAST & outOperand5,
                                                               GALGAS_guardDeclarationListAST & outOperand6,
                                                               const GALGAS_uint inRemoveIndex,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_extensionDeclarationListAST * p = (cCollectionElement_extensionDeclarationListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
      outOperand4.drop () ;
      outOperand5.drop () ;
      outOperand6.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
      outOperand0 = p->mObject.mAttribute_mTypeName ;
      outOperand1 = p->mObject.mAttribute_mProcedureDeclarationListAST ;
      outOperand2 = p->mObject.mAttribute_mPropertyList ;
      outOperand3 = p->mObject.mAttribute_mServiceListAST ;
      outOperand4 = p->mObject.mAttribute_mSectionListAST ;
      outOperand5 = p->mObject.mAttribute_mPrimitiveListAST ;
      outOperand6 = p->mObject.mAttribute_mGuardListAST ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extensionDeclarationListAST::setter_popFirst (GALGAS_lstring & outOperand0,
                                                          GALGAS_functionDeclarationListAST & outOperand1,
                                                          GALGAS_structurePropertyListAST & outOperand2,
                                                          GALGAS_serviceDeclarationListAST & outOperand3,
                                                          GALGAS_sectionDeclarationListAST & outOperand4,
                                                          GALGAS_primitiveDeclarationListAST & outOperand5,
                                                          GALGAS_guardDeclarationListAST & outOperand6,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_extensionDeclarationListAST * p = (cCollectionElement_extensionDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mTypeName ;
    outOperand1 = p->mObject.mAttribute_mProcedureDeclarationListAST ;
    outOperand2 = p->mObject.mAttribute_mPropertyList ;
    outOperand3 = p->mObject.mAttribute_mServiceListAST ;
    outOperand4 = p->mObject.mAttribute_mSectionListAST ;
    outOperand5 = p->mObject.mAttribute_mPrimitiveListAST ;
    outOperand6 = p->mObject.mAttribute_mGuardListAST ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extensionDeclarationListAST::setter_popLast (GALGAS_lstring & outOperand0,
                                                         GALGAS_functionDeclarationListAST & outOperand1,
                                                         GALGAS_structurePropertyListAST & outOperand2,
                                                         GALGAS_serviceDeclarationListAST & outOperand3,
                                                         GALGAS_sectionDeclarationListAST & outOperand4,
                                                         GALGAS_primitiveDeclarationListAST & outOperand5,
                                                         GALGAS_guardDeclarationListAST & outOperand6,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_extensionDeclarationListAST * p = (cCollectionElement_extensionDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mTypeName ;
    outOperand1 = p->mObject.mAttribute_mProcedureDeclarationListAST ;
    outOperand2 = p->mObject.mAttribute_mPropertyList ;
    outOperand3 = p->mObject.mAttribute_mServiceListAST ;
    outOperand4 = p->mObject.mAttribute_mSectionListAST ;
    outOperand5 = p->mObject.mAttribute_mPrimitiveListAST ;
    outOperand6 = p->mObject.mAttribute_mGuardListAST ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extensionDeclarationListAST::method_first (GALGAS_lstring & outOperand0,
                                                       GALGAS_functionDeclarationListAST & outOperand1,
                                                       GALGAS_structurePropertyListAST & outOperand2,
                                                       GALGAS_serviceDeclarationListAST & outOperand3,
                                                       GALGAS_sectionDeclarationListAST & outOperand4,
                                                       GALGAS_primitiveDeclarationListAST & outOperand5,
                                                       GALGAS_guardDeclarationListAST & outOperand6,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_extensionDeclarationListAST * p = (cCollectionElement_extensionDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mTypeName ;
    outOperand1 = p->mObject.mAttribute_mProcedureDeclarationListAST ;
    outOperand2 = p->mObject.mAttribute_mPropertyList ;
    outOperand3 = p->mObject.mAttribute_mServiceListAST ;
    outOperand4 = p->mObject.mAttribute_mSectionListAST ;
    outOperand5 = p->mObject.mAttribute_mPrimitiveListAST ;
    outOperand6 = p->mObject.mAttribute_mGuardListAST ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extensionDeclarationListAST::method_last (GALGAS_lstring & outOperand0,
                                                      GALGAS_functionDeclarationListAST & outOperand1,
                                                      GALGAS_structurePropertyListAST & outOperand2,
                                                      GALGAS_serviceDeclarationListAST & outOperand3,
                                                      GALGAS_sectionDeclarationListAST & outOperand4,
                                                      GALGAS_primitiveDeclarationListAST & outOperand5,
                                                      GALGAS_guardDeclarationListAST & outOperand6,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_extensionDeclarationListAST * p = (cCollectionElement_extensionDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mTypeName ;
    outOperand1 = p->mObject.mAttribute_mProcedureDeclarationListAST ;
    outOperand2 = p->mObject.mAttribute_mPropertyList ;
    outOperand3 = p->mObject.mAttribute_mServiceListAST ;
    outOperand4 = p->mObject.mAttribute_mSectionListAST ;
    outOperand5 = p->mObject.mAttribute_mPrimitiveListAST ;
    outOperand6 = p->mObject.mAttribute_mGuardListAST ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST GALGAS_extensionDeclarationListAST::add_operation (const GALGAS_extensionDeclarationListAST & inOperand,
                                                                                      C_Compiler * /* inCompiler */
                                                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_extensionDeclarationListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST GALGAS_extensionDeclarationListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_extensionDeclarationListAST result = GALGAS_extensionDeclarationListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST GALGAS_extensionDeclarationListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_extensionDeclarationListAST result = GALGAS_extensionDeclarationListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST GALGAS_extensionDeclarationListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_extensionDeclarationListAST result = GALGAS_extensionDeclarationListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extensionDeclarationListAST::plusAssign_operation (const GALGAS_extensionDeclarationListAST inOperand,
                                                               C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_extensionDeclarationListAST::getter_mTypeNameAtIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_extensionDeclarationListAST * p = (cCollectionElement_extensionDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
    result = p->mObject.mAttribute_mTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST GALGAS_extensionDeclarationListAST::getter_mProcedureDeclarationListASTAtIndex (const GALGAS_uint & inIndex,
                                                                                                                  C_Compiler * inCompiler
                                                                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_extensionDeclarationListAST * p = (cCollectionElement_extensionDeclarationListAST *) attributes.ptr () ;
  GALGAS_functionDeclarationListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
    result = p->mObject.mAttribute_mProcedureDeclarationListAST ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structurePropertyListAST GALGAS_extensionDeclarationListAST::getter_mPropertyListAtIndex (const GALGAS_uint & inIndex,
                                                                                                 C_Compiler * inCompiler
                                                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_extensionDeclarationListAST * p = (cCollectionElement_extensionDeclarationListAST *) attributes.ptr () ;
  GALGAS_structurePropertyListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
    result = p->mObject.mAttribute_mPropertyList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST GALGAS_extensionDeclarationListAST::getter_mServiceListASTAtIndex (const GALGAS_uint & inIndex,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_extensionDeclarationListAST * p = (cCollectionElement_extensionDeclarationListAST *) attributes.ptr () ;
  GALGAS_serviceDeclarationListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
    result = p->mObject.mAttribute_mServiceListAST ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST GALGAS_extensionDeclarationListAST::getter_mSectionListASTAtIndex (const GALGAS_uint & inIndex,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_extensionDeclarationListAST * p = (cCollectionElement_extensionDeclarationListAST *) attributes.ptr () ;
  GALGAS_sectionDeclarationListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
    result = p->mObject.mAttribute_mSectionListAST ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST GALGAS_extensionDeclarationListAST::getter_mPrimitiveListASTAtIndex (const GALGAS_uint & inIndex,
                                                                                                        C_Compiler * inCompiler
                                                                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_extensionDeclarationListAST * p = (cCollectionElement_extensionDeclarationListAST *) attributes.ptr () ;
  GALGAS_primitiveDeclarationListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
    result = p->mObject.mAttribute_mPrimitiveListAST ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST GALGAS_extensionDeclarationListAST::getter_mGuardListASTAtIndex (const GALGAS_uint & inIndex,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_extensionDeclarationListAST * p = (cCollectionElement_extensionDeclarationListAST *) attributes.ptr () ;
  GALGAS_guardDeclarationListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
    result = p->mObject.mAttribute_mGuardListAST ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_extensionDeclarationListAST::cEnumerator_extensionDeclarationListAST (const GALGAS_extensionDeclarationListAST & inEnumeratedObject,
                                                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST_2D_element cEnumerator_extensionDeclarationListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_extensionDeclarationListAST * p = (const cCollectionElement_extensionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_extensionDeclarationListAST::current_mTypeName (LOCATION_ARGS) const {
  const cCollectionElement_extensionDeclarationListAST * p = (const cCollectionElement_extensionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
  return p->mObject.mAttribute_mTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST cEnumerator_extensionDeclarationListAST::current_mProcedureDeclarationListAST (LOCATION_ARGS) const {
  const cCollectionElement_extensionDeclarationListAST * p = (const cCollectionElement_extensionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
  return p->mObject.mAttribute_mProcedureDeclarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structurePropertyListAST cEnumerator_extensionDeclarationListAST::current_mPropertyList (LOCATION_ARGS) const {
  const cCollectionElement_extensionDeclarationListAST * p = (const cCollectionElement_extensionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
  return p->mObject.mAttribute_mPropertyList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST cEnumerator_extensionDeclarationListAST::current_mServiceListAST (LOCATION_ARGS) const {
  const cCollectionElement_extensionDeclarationListAST * p = (const cCollectionElement_extensionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
  return p->mObject.mAttribute_mServiceListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST cEnumerator_extensionDeclarationListAST::current_mSectionListAST (LOCATION_ARGS) const {
  const cCollectionElement_extensionDeclarationListAST * p = (const cCollectionElement_extensionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
  return p->mObject.mAttribute_mSectionListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST cEnumerator_extensionDeclarationListAST::current_mPrimitiveListAST (LOCATION_ARGS) const {
  const cCollectionElement_extensionDeclarationListAST * p = (const cCollectionElement_extensionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
  return p->mObject.mAttribute_mPrimitiveListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST cEnumerator_extensionDeclarationListAST::current_mGuardListAST (LOCATION_ARGS) const {
  const cCollectionElement_extensionDeclarationListAST * p = (const cCollectionElement_extensionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_extensionDeclarationListAST) ;
  return p->mObject.mAttribute_mGuardListAST ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @extensionDeclarationListAST type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_extensionDeclarationListAST ("extensionDeclarationListAST",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_extensionDeclarationListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_extensionDeclarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_extensionDeclarationListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_extensionDeclarationListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST GALGAS_extensionDeclarationListAST::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_extensionDeclarationListAST result ;
  const GALGAS_extensionDeclarationListAST * p = (const GALGAS_extensionDeclarationListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_extensionDeclarationListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("extensionDeclarationListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Class for element of '@controlRegisterDeclarationListAST' list                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_controlRegisterDeclarationListAST : public cCollectionElement {
  public : GALGAS_controlRegisterDeclarationListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_controlRegisterDeclarationListAST (const GALGAS_controlRegisterNameList & in_mRegisterNameList,
                                                                 const GALGAS_lstring & in_mRegisterTypeName,
                                                                 const GALGAS_controlRegisterBitSliceList & in_mRegisterBitSliceList,
                                                                 const GALGAS_location & in_mRegisterBitSliceListLocation
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

cCollectionElement_controlRegisterDeclarationListAST::cCollectionElement_controlRegisterDeclarationListAST (const GALGAS_controlRegisterNameList & in_mRegisterNameList,
                                                                                                            const GALGAS_lstring & in_mRegisterTypeName,
                                                                                                            const GALGAS_controlRegisterBitSliceList & in_mRegisterBitSliceList,
                                                                                                            const GALGAS_location & in_mRegisterBitSliceListLocation
                                                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mRegisterNameList, in_mRegisterTypeName, in_mRegisterBitSliceList, in_mRegisterBitSliceListLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_controlRegisterDeclarationListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_controlRegisterDeclarationListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_controlRegisterDeclarationListAST (mObject.mAttribute_mRegisterNameList, mObject.mAttribute_mRegisterTypeName, mObject.mAttribute_mRegisterBitSliceList, mObject.mAttribute_mRegisterBitSliceListLocation COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_controlRegisterDeclarationListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mRegisterNameList" ":" ;
  mObject.mAttribute_mRegisterNameList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mRegisterTypeName" ":" ;
  mObject.mAttribute_mRegisterTypeName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mRegisterBitSliceList" ":" ;
  mObject.mAttribute_mRegisterBitSliceList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mRegisterBitSliceListLocation" ":" ;
  mObject.mAttribute_mRegisterBitSliceListLocation.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_controlRegisterDeclarationListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_controlRegisterDeclarationListAST * operand = (cCollectionElement_controlRegisterDeclarationListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_controlRegisterDeclarationListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST::GALGAS_controlRegisterDeclarationListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST::GALGAS_controlRegisterDeclarationListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST GALGAS_controlRegisterDeclarationListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_controlRegisterDeclarationListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST GALGAS_controlRegisterDeclarationListAST::constructor_listWithValue (const GALGAS_controlRegisterNameList & inOperand0,
                                                                                                              const GALGAS_lstring & inOperand1,
                                                                                                              const GALGAS_controlRegisterBitSliceList & inOperand2,
                                                                                                              const GALGAS_location & inOperand3
                                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_controlRegisterDeclarationListAST result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_controlRegisterDeclarationListAST::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterDeclarationListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                          const GALGAS_controlRegisterNameList & in_mRegisterNameList,
                                                                          const GALGAS_lstring & in_mRegisterTypeName,
                                                                          const GALGAS_controlRegisterBitSliceList & in_mRegisterBitSliceList,
                                                                          const GALGAS_location & in_mRegisterBitSliceListLocation
                                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement_controlRegisterDeclarationListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_controlRegisterDeclarationListAST (in_mRegisterNameList,
                                                                       in_mRegisterTypeName,
                                                                       in_mRegisterBitSliceList,
                                                                       in_mRegisterBitSliceListLocation COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterDeclarationListAST::addAssign_operation (const GALGAS_controlRegisterNameList & inOperand0,
                                                                    const GALGAS_lstring & inOperand1,
                                                                    const GALGAS_controlRegisterBitSliceList & inOperand2,
                                                                    const GALGAS_location & inOperand3
                                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_controlRegisterDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterDeclarationListAST::setter_insertAtIndex (const GALGAS_controlRegisterNameList inOperand0,
                                                                     const GALGAS_lstring inOperand1,
                                                                     const GALGAS_controlRegisterBitSliceList inOperand2,
                                                                     const GALGAS_location inOperand3,
                                                                     const GALGAS_uint inInsertionIndex,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_controlRegisterDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterDeclarationListAST::setter_removeAtIndex (GALGAS_controlRegisterNameList & outOperand0,
                                                                     GALGAS_lstring & outOperand1,
                                                                     GALGAS_controlRegisterBitSliceList & outOperand2,
                                                                     GALGAS_location & outOperand3,
                                                                     const GALGAS_uint inRemoveIndex,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_controlRegisterDeclarationListAST * p = (cCollectionElement_controlRegisterDeclarationListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
      outOperand0 = p->mObject.mAttribute_mRegisterNameList ;
      outOperand1 = p->mObject.mAttribute_mRegisterTypeName ;
      outOperand2 = p->mObject.mAttribute_mRegisterBitSliceList ;
      outOperand3 = p->mObject.mAttribute_mRegisterBitSliceListLocation ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterDeclarationListAST::setter_popFirst (GALGAS_controlRegisterNameList & outOperand0,
                                                                GALGAS_lstring & outOperand1,
                                                                GALGAS_controlRegisterBitSliceList & outOperand2,
                                                                GALGAS_location & outOperand3,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_controlRegisterDeclarationListAST * p = (cCollectionElement_controlRegisterDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mRegisterNameList ;
    outOperand1 = p->mObject.mAttribute_mRegisterTypeName ;
    outOperand2 = p->mObject.mAttribute_mRegisterBitSliceList ;
    outOperand3 = p->mObject.mAttribute_mRegisterBitSliceListLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterDeclarationListAST::setter_popLast (GALGAS_controlRegisterNameList & outOperand0,
                                                               GALGAS_lstring & outOperand1,
                                                               GALGAS_controlRegisterBitSliceList & outOperand2,
                                                               GALGAS_location & outOperand3,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_controlRegisterDeclarationListAST * p = (cCollectionElement_controlRegisterDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mRegisterNameList ;
    outOperand1 = p->mObject.mAttribute_mRegisterTypeName ;
    outOperand2 = p->mObject.mAttribute_mRegisterBitSliceList ;
    outOperand3 = p->mObject.mAttribute_mRegisterBitSliceListLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterDeclarationListAST::method_first (GALGAS_controlRegisterNameList & outOperand0,
                                                             GALGAS_lstring & outOperand1,
                                                             GALGAS_controlRegisterBitSliceList & outOperand2,
                                                             GALGAS_location & outOperand3,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_controlRegisterDeclarationListAST * p = (cCollectionElement_controlRegisterDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mRegisterNameList ;
    outOperand1 = p->mObject.mAttribute_mRegisterTypeName ;
    outOperand2 = p->mObject.mAttribute_mRegisterBitSliceList ;
    outOperand3 = p->mObject.mAttribute_mRegisterBitSliceListLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterDeclarationListAST::method_last (GALGAS_controlRegisterNameList & outOperand0,
                                                            GALGAS_lstring & outOperand1,
                                                            GALGAS_controlRegisterBitSliceList & outOperand2,
                                                            GALGAS_location & outOperand3,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_controlRegisterDeclarationListAST * p = (cCollectionElement_controlRegisterDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mRegisterNameList ;
    outOperand1 = p->mObject.mAttribute_mRegisterTypeName ;
    outOperand2 = p->mObject.mAttribute_mRegisterBitSliceList ;
    outOperand3 = p->mObject.mAttribute_mRegisterBitSliceListLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST GALGAS_controlRegisterDeclarationListAST::add_operation (const GALGAS_controlRegisterDeclarationListAST & inOperand,
                                                                                                  C_Compiler * /* inCompiler */
                                                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_controlRegisterDeclarationListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST GALGAS_controlRegisterDeclarationListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_controlRegisterDeclarationListAST result = GALGAS_controlRegisterDeclarationListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST GALGAS_controlRegisterDeclarationListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_controlRegisterDeclarationListAST result = GALGAS_controlRegisterDeclarationListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST GALGAS_controlRegisterDeclarationListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_controlRegisterDeclarationListAST result = GALGAS_controlRegisterDeclarationListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterDeclarationListAST::plusAssign_operation (const GALGAS_controlRegisterDeclarationListAST inOperand,
                                                                     C_Compiler * /* inCompiler */
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterNameList GALGAS_controlRegisterDeclarationListAST::getter_mRegisterNameListAtIndex (const GALGAS_uint & inIndex,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_controlRegisterDeclarationListAST * p = (cCollectionElement_controlRegisterDeclarationListAST *) attributes.ptr () ;
  GALGAS_controlRegisterNameList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
    result = p->mObject.mAttribute_mRegisterNameList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_controlRegisterDeclarationListAST::getter_mRegisterTypeNameAtIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_controlRegisterDeclarationListAST * p = (cCollectionElement_controlRegisterDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
    result = p->mObject.mAttribute_mRegisterTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceList GALGAS_controlRegisterDeclarationListAST::getter_mRegisterBitSliceListAtIndex (const GALGAS_uint & inIndex,
                                                                                                                  C_Compiler * inCompiler
                                                                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_controlRegisterDeclarationListAST * p = (cCollectionElement_controlRegisterDeclarationListAST *) attributes.ptr () ;
  GALGAS_controlRegisterBitSliceList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
    result = p->mObject.mAttribute_mRegisterBitSliceList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_controlRegisterDeclarationListAST::getter_mRegisterBitSliceListLocationAtIndex (const GALGAS_uint & inIndex,
                                                                                                       C_Compiler * inCompiler
                                                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_controlRegisterDeclarationListAST * p = (cCollectionElement_controlRegisterDeclarationListAST *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
    result = p->mObject.mAttribute_mRegisterBitSliceListLocation ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_controlRegisterDeclarationListAST::cEnumerator_controlRegisterDeclarationListAST (const GALGAS_controlRegisterDeclarationListAST & inEnumeratedObject,
                                                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST_2D_element cEnumerator_controlRegisterDeclarationListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_controlRegisterDeclarationListAST * p = (const cCollectionElement_controlRegisterDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterNameList cEnumerator_controlRegisterDeclarationListAST::current_mRegisterNameList (LOCATION_ARGS) const {
  const cCollectionElement_controlRegisterDeclarationListAST * p = (const cCollectionElement_controlRegisterDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
  return p->mObject.mAttribute_mRegisterNameList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_controlRegisterDeclarationListAST::current_mRegisterTypeName (LOCATION_ARGS) const {
  const cCollectionElement_controlRegisterDeclarationListAST * p = (const cCollectionElement_controlRegisterDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
  return p->mObject.mAttribute_mRegisterTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceList cEnumerator_controlRegisterDeclarationListAST::current_mRegisterBitSliceList (LOCATION_ARGS) const {
  const cCollectionElement_controlRegisterDeclarationListAST * p = (const cCollectionElement_controlRegisterDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
  return p->mObject.mAttribute_mRegisterBitSliceList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_controlRegisterDeclarationListAST::current_mRegisterBitSliceListLocation (LOCATION_ARGS) const {
  const cCollectionElement_controlRegisterDeclarationListAST * p = (const cCollectionElement_controlRegisterDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_controlRegisterDeclarationListAST) ;
  return p->mObject.mAttribute_mRegisterBitSliceListLocation ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @controlRegisterDeclarationListAST type                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_controlRegisterDeclarationListAST ("controlRegisterDeclarationListAST",
                                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_controlRegisterDeclarationListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_controlRegisterDeclarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_controlRegisterDeclarationListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_controlRegisterDeclarationListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST GALGAS_controlRegisterDeclarationListAST::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_controlRegisterDeclarationListAST result ;
  const GALGAS_controlRegisterDeclarationListAST * p = (const GALGAS_controlRegisterDeclarationListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_controlRegisterDeclarationListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("controlRegisterDeclarationListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Class for element of '@functionDeclarationListAST' list                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_functionDeclarationListAST : public cCollectionElement {
  public : GALGAS_functionDeclarationListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_functionDeclarationListAST (const GALGAS_lstringlist & in_mFunctionModeList,
                                                          const GALGAS_bool & in_mPublicFunction,
                                                          const GALGAS_lstring & in_mFunctionName,
                                                          const GALGAS_lstringlist & in_mFunctionAttributeList,
                                                          const GALGAS_procFormalArgumentList & in_mFunctionFormalArgumentList,
                                                          const GALGAS_lstring & in_mFunctionReturnTypeName,
                                                          const GALGAS_instructionListAST & in_mFunctionInstructionList,
                                                          const GALGAS_location & in_mEndOfFunctionDeclaration
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

cCollectionElement_functionDeclarationListAST::cCollectionElement_functionDeclarationListAST (const GALGAS_lstringlist & in_mFunctionModeList,
                                                                                              const GALGAS_bool & in_mPublicFunction,
                                                                                              const GALGAS_lstring & in_mFunctionName,
                                                                                              const GALGAS_lstringlist & in_mFunctionAttributeList,
                                                                                              const GALGAS_procFormalArgumentList & in_mFunctionFormalArgumentList,
                                                                                              const GALGAS_lstring & in_mFunctionReturnTypeName,
                                                                                              const GALGAS_instructionListAST & in_mFunctionInstructionList,
                                                                                              const GALGAS_location & in_mEndOfFunctionDeclaration
                                                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mFunctionModeList, in_mPublicFunction, in_mFunctionName, in_mFunctionAttributeList, in_mFunctionFormalArgumentList, in_mFunctionReturnTypeName, in_mFunctionInstructionList, in_mEndOfFunctionDeclaration) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_functionDeclarationListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_functionDeclarationListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_functionDeclarationListAST (mObject.mAttribute_mFunctionModeList, mObject.mAttribute_mPublicFunction, mObject.mAttribute_mFunctionName, mObject.mAttribute_mFunctionAttributeList, mObject.mAttribute_mFunctionFormalArgumentList, mObject.mAttribute_mFunctionReturnTypeName, mObject.mAttribute_mFunctionInstructionList, mObject.mAttribute_mEndOfFunctionDeclaration COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_functionDeclarationListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFunctionModeList" ":" ;
  mObject.mAttribute_mFunctionModeList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPublicFunction" ":" ;
  mObject.mAttribute_mPublicFunction.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFunctionName" ":" ;
  mObject.mAttribute_mFunctionName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFunctionAttributeList" ":" ;
  mObject.mAttribute_mFunctionAttributeList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFunctionFormalArgumentList" ":" ;
  mObject.mAttribute_mFunctionFormalArgumentList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFunctionReturnTypeName" ":" ;
  mObject.mAttribute_mFunctionReturnTypeName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFunctionInstructionList" ":" ;
  mObject.mAttribute_mFunctionInstructionList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEndOfFunctionDeclaration" ":" ;
  mObject.mAttribute_mEndOfFunctionDeclaration.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_functionDeclarationListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_functionDeclarationListAST * operand = (cCollectionElement_functionDeclarationListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_functionDeclarationListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST::GALGAS_functionDeclarationListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST::GALGAS_functionDeclarationListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST GALGAS_functionDeclarationListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_functionDeclarationListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST GALGAS_functionDeclarationListAST::constructor_listWithValue (const GALGAS_lstringlist & inOperand0,
                                                                                                const GALGAS_bool & inOperand1,
                                                                                                const GALGAS_lstring & inOperand2,
                                                                                                const GALGAS_lstringlist & inOperand3,
                                                                                                const GALGAS_procFormalArgumentList & inOperand4,
                                                                                                const GALGAS_lstring & inOperand5,
                                                                                                const GALGAS_instructionListAST & inOperand6,
                                                                                                const GALGAS_location & inOperand7
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_functionDeclarationListAST result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_functionDeclarationListAST::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionDeclarationListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                   const GALGAS_lstringlist & in_mFunctionModeList,
                                                                   const GALGAS_bool & in_mPublicFunction,
                                                                   const GALGAS_lstring & in_mFunctionName,
                                                                   const GALGAS_lstringlist & in_mFunctionAttributeList,
                                                                   const GALGAS_procFormalArgumentList & in_mFunctionFormalArgumentList,
                                                                   const GALGAS_lstring & in_mFunctionReturnTypeName,
                                                                   const GALGAS_instructionListAST & in_mFunctionInstructionList,
                                                                   const GALGAS_location & in_mEndOfFunctionDeclaration
                                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_functionDeclarationListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_functionDeclarationListAST (in_mFunctionModeList,
                                                                in_mPublicFunction,
                                                                in_mFunctionName,
                                                                in_mFunctionAttributeList,
                                                                in_mFunctionFormalArgumentList,
                                                                in_mFunctionReturnTypeName,
                                                                in_mFunctionInstructionList,
                                                                in_mEndOfFunctionDeclaration COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionDeclarationListAST::addAssign_operation (const GALGAS_lstringlist & inOperand0,
                                                             const GALGAS_bool & inOperand1,
                                                             const GALGAS_lstring & inOperand2,
                                                             const GALGAS_lstringlist & inOperand3,
                                                             const GALGAS_procFormalArgumentList & inOperand4,
                                                             const GALGAS_lstring & inOperand5,
                                                             const GALGAS_instructionListAST & inOperand6,
                                                             const GALGAS_location & inOperand7
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_functionDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionDeclarationListAST::setter_insertAtIndex (const GALGAS_lstringlist inOperand0,
                                                              const GALGAS_bool inOperand1,
                                                              const GALGAS_lstring inOperand2,
                                                              const GALGAS_lstringlist inOperand3,
                                                              const GALGAS_procFormalArgumentList inOperand4,
                                                              const GALGAS_lstring inOperand5,
                                                              const GALGAS_instructionListAST inOperand6,
                                                              const GALGAS_location inOperand7,
                                                              const GALGAS_uint inInsertionIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_functionDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionDeclarationListAST::setter_removeAtIndex (GALGAS_lstringlist & outOperand0,
                                                              GALGAS_bool & outOperand1,
                                                              GALGAS_lstring & outOperand2,
                                                              GALGAS_lstringlist & outOperand3,
                                                              GALGAS_procFormalArgumentList & outOperand4,
                                                              GALGAS_lstring & outOperand5,
                                                              GALGAS_instructionListAST & outOperand6,
                                                              GALGAS_location & outOperand7,
                                                              const GALGAS_uint inRemoveIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
      outOperand4.drop () ;
      outOperand5.drop () ;
      outOperand6.drop () ;
      outOperand7.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
      outOperand0 = p->mObject.mAttribute_mFunctionModeList ;
      outOperand1 = p->mObject.mAttribute_mPublicFunction ;
      outOperand2 = p->mObject.mAttribute_mFunctionName ;
      outOperand3 = p->mObject.mAttribute_mFunctionAttributeList ;
      outOperand4 = p->mObject.mAttribute_mFunctionFormalArgumentList ;
      outOperand5 = p->mObject.mAttribute_mFunctionReturnTypeName ;
      outOperand6 = p->mObject.mAttribute_mFunctionInstructionList ;
      outOperand7 = p->mObject.mAttribute_mEndOfFunctionDeclaration ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionDeclarationListAST::setter_popFirst (GALGAS_lstringlist & outOperand0,
                                                         GALGAS_bool & outOperand1,
                                                         GALGAS_lstring & outOperand2,
                                                         GALGAS_lstringlist & outOperand3,
                                                         GALGAS_procFormalArgumentList & outOperand4,
                                                         GALGAS_lstring & outOperand5,
                                                         GALGAS_instructionListAST & outOperand6,
                                                         GALGAS_location & outOperand7,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
    outOperand7.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mFunctionModeList ;
    outOperand1 = p->mObject.mAttribute_mPublicFunction ;
    outOperand2 = p->mObject.mAttribute_mFunctionName ;
    outOperand3 = p->mObject.mAttribute_mFunctionAttributeList ;
    outOperand4 = p->mObject.mAttribute_mFunctionFormalArgumentList ;
    outOperand5 = p->mObject.mAttribute_mFunctionReturnTypeName ;
    outOperand6 = p->mObject.mAttribute_mFunctionInstructionList ;
    outOperand7 = p->mObject.mAttribute_mEndOfFunctionDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionDeclarationListAST::setter_popLast (GALGAS_lstringlist & outOperand0,
                                                        GALGAS_bool & outOperand1,
                                                        GALGAS_lstring & outOperand2,
                                                        GALGAS_lstringlist & outOperand3,
                                                        GALGAS_procFormalArgumentList & outOperand4,
                                                        GALGAS_lstring & outOperand5,
                                                        GALGAS_instructionListAST & outOperand6,
                                                        GALGAS_location & outOperand7,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
    outOperand7.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mFunctionModeList ;
    outOperand1 = p->mObject.mAttribute_mPublicFunction ;
    outOperand2 = p->mObject.mAttribute_mFunctionName ;
    outOperand3 = p->mObject.mAttribute_mFunctionAttributeList ;
    outOperand4 = p->mObject.mAttribute_mFunctionFormalArgumentList ;
    outOperand5 = p->mObject.mAttribute_mFunctionReturnTypeName ;
    outOperand6 = p->mObject.mAttribute_mFunctionInstructionList ;
    outOperand7 = p->mObject.mAttribute_mEndOfFunctionDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionDeclarationListAST::method_first (GALGAS_lstringlist & outOperand0,
                                                      GALGAS_bool & outOperand1,
                                                      GALGAS_lstring & outOperand2,
                                                      GALGAS_lstringlist & outOperand3,
                                                      GALGAS_procFormalArgumentList & outOperand4,
                                                      GALGAS_lstring & outOperand5,
                                                      GALGAS_instructionListAST & outOperand6,
                                                      GALGAS_location & outOperand7,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
    outOperand7.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mFunctionModeList ;
    outOperand1 = p->mObject.mAttribute_mPublicFunction ;
    outOperand2 = p->mObject.mAttribute_mFunctionName ;
    outOperand3 = p->mObject.mAttribute_mFunctionAttributeList ;
    outOperand4 = p->mObject.mAttribute_mFunctionFormalArgumentList ;
    outOperand5 = p->mObject.mAttribute_mFunctionReturnTypeName ;
    outOperand6 = p->mObject.mAttribute_mFunctionInstructionList ;
    outOperand7 = p->mObject.mAttribute_mEndOfFunctionDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionDeclarationListAST::method_last (GALGAS_lstringlist & outOperand0,
                                                     GALGAS_bool & outOperand1,
                                                     GALGAS_lstring & outOperand2,
                                                     GALGAS_lstringlist & outOperand3,
                                                     GALGAS_procFormalArgumentList & outOperand4,
                                                     GALGAS_lstring & outOperand5,
                                                     GALGAS_instructionListAST & outOperand6,
                                                     GALGAS_location & outOperand7,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
    outOperand7.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mFunctionModeList ;
    outOperand1 = p->mObject.mAttribute_mPublicFunction ;
    outOperand2 = p->mObject.mAttribute_mFunctionName ;
    outOperand3 = p->mObject.mAttribute_mFunctionAttributeList ;
    outOperand4 = p->mObject.mAttribute_mFunctionFormalArgumentList ;
    outOperand5 = p->mObject.mAttribute_mFunctionReturnTypeName ;
    outOperand6 = p->mObject.mAttribute_mFunctionInstructionList ;
    outOperand7 = p->mObject.mAttribute_mEndOfFunctionDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST GALGAS_functionDeclarationListAST::add_operation (const GALGAS_functionDeclarationListAST & inOperand,
                                                                                    C_Compiler * /* inCompiler */
                                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_functionDeclarationListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST GALGAS_functionDeclarationListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_functionDeclarationListAST result = GALGAS_functionDeclarationListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST GALGAS_functionDeclarationListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_functionDeclarationListAST result = GALGAS_functionDeclarationListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST GALGAS_functionDeclarationListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_functionDeclarationListAST result = GALGAS_functionDeclarationListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionDeclarationListAST::plusAssign_operation (const GALGAS_functionDeclarationListAST inOperand,
                                                              C_Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_functionDeclarationListAST::getter_mFunctionModeListAtIndex (const GALGAS_uint & inIndex,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstringlist result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
    result = p->mObject.mAttribute_mFunctionModeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_functionDeclarationListAST::getter_mPublicFunctionAtIndex (const GALGAS_uint & inIndex,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
    result = p->mObject.mAttribute_mPublicFunction ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_functionDeclarationListAST::getter_mFunctionNameAtIndex (const GALGAS_uint & inIndex,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
    result = p->mObject.mAttribute_mFunctionName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_functionDeclarationListAST::getter_mFunctionAttributeListAtIndex (const GALGAS_uint & inIndex,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstringlist result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
    result = p->mObject.mAttribute_mFunctionAttributeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_functionDeclarationListAST::getter_mFunctionFormalArgumentListAtIndex (const GALGAS_uint & inIndex,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
  GALGAS_procFormalArgumentList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
    result = p->mObject.mAttribute_mFunctionFormalArgumentList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_functionDeclarationListAST::getter_mFunctionReturnTypeNameAtIndex (const GALGAS_uint & inIndex,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
    result = p->mObject.mAttribute_mFunctionReturnTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_functionDeclarationListAST::getter_mFunctionInstructionListAtIndex (const GALGAS_uint & inIndex,
                                                                                                     C_Compiler * inCompiler
                                                                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
  GALGAS_instructionListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
    result = p->mObject.mAttribute_mFunctionInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_functionDeclarationListAST::getter_mEndOfFunctionDeclarationAtIndex (const GALGAS_uint & inIndex,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_functionDeclarationListAST * p = (cCollectionElement_functionDeclarationListAST *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
    result = p->mObject.mAttribute_mEndOfFunctionDeclaration ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_functionDeclarationListAST::cEnumerator_functionDeclarationListAST (const GALGAS_functionDeclarationListAST & inEnumeratedObject,
                                                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST_2D_element cEnumerator_functionDeclarationListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_functionDeclarationListAST * p = (const cCollectionElement_functionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cEnumerator_functionDeclarationListAST::current_mFunctionModeList (LOCATION_ARGS) const {
  const cCollectionElement_functionDeclarationListAST * p = (const cCollectionElement_functionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
  return p->mObject.mAttribute_mFunctionModeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_functionDeclarationListAST::current_mPublicFunction (LOCATION_ARGS) const {
  const cCollectionElement_functionDeclarationListAST * p = (const cCollectionElement_functionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
  return p->mObject.mAttribute_mPublicFunction ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_functionDeclarationListAST::current_mFunctionName (LOCATION_ARGS) const {
  const cCollectionElement_functionDeclarationListAST * p = (const cCollectionElement_functionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
  return p->mObject.mAttribute_mFunctionName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cEnumerator_functionDeclarationListAST::current_mFunctionAttributeList (LOCATION_ARGS) const {
  const cCollectionElement_functionDeclarationListAST * p = (const cCollectionElement_functionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
  return p->mObject.mAttribute_mFunctionAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList cEnumerator_functionDeclarationListAST::current_mFunctionFormalArgumentList (LOCATION_ARGS) const {
  const cCollectionElement_functionDeclarationListAST * p = (const cCollectionElement_functionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
  return p->mObject.mAttribute_mFunctionFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_functionDeclarationListAST::current_mFunctionReturnTypeName (LOCATION_ARGS) const {
  const cCollectionElement_functionDeclarationListAST * p = (const cCollectionElement_functionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
  return p->mObject.mAttribute_mFunctionReturnTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cEnumerator_functionDeclarationListAST::current_mFunctionInstructionList (LOCATION_ARGS) const {
  const cCollectionElement_functionDeclarationListAST * p = (const cCollectionElement_functionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
  return p->mObject.mAttribute_mFunctionInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_functionDeclarationListAST::current_mEndOfFunctionDeclaration (LOCATION_ARGS) const {
  const cCollectionElement_functionDeclarationListAST * p = (const cCollectionElement_functionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionDeclarationListAST) ;
  return p->mObject.mAttribute_mEndOfFunctionDeclaration ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @functionDeclarationListAST type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_functionDeclarationListAST ("functionDeclarationListAST",
                                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_functionDeclarationListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_functionDeclarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_functionDeclarationListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_functionDeclarationListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST GALGAS_functionDeclarationListAST::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_functionDeclarationListAST result ;
  const GALGAS_functionDeclarationListAST * p = (const GALGAS_functionDeclarationListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_functionDeclarationListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("functionDeclarationListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Class for element of '@requiredProcedureDeclarationListAST' list                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_requiredProcedureDeclarationListAST : public cCollectionElement {
  public : GALGAS_requiredProcedureDeclarationListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_requiredProcedureDeclarationListAST (const GALGAS_lstring & in_mRequiredProcedureName,
                                                                   const GALGAS_lstringlist & in_mProcedureModeList,
                                                                   const GALGAS_procFormalArgumentList & in_mProcFormalArgumentList,
                                                                   const GALGAS_location & in_mEndOfProcLocation
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

cCollectionElement_requiredProcedureDeclarationListAST::cCollectionElement_requiredProcedureDeclarationListAST (const GALGAS_lstring & in_mRequiredProcedureName,
                                                                                                                const GALGAS_lstringlist & in_mProcedureModeList,
                                                                                                                const GALGAS_procFormalArgumentList & in_mProcFormalArgumentList,
                                                                                                                const GALGAS_location & in_mEndOfProcLocation
                                                                                                                COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mRequiredProcedureName, in_mProcedureModeList, in_mProcFormalArgumentList, in_mEndOfProcLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_requiredProcedureDeclarationListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_requiredProcedureDeclarationListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_requiredProcedureDeclarationListAST (mObject.mAttribute_mRequiredProcedureName, mObject.mAttribute_mProcedureModeList, mObject.mAttribute_mProcFormalArgumentList, mObject.mAttribute_mEndOfProcLocation COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_requiredProcedureDeclarationListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mRequiredProcedureName" ":" ;
  mObject.mAttribute_mRequiredProcedureName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mProcedureModeList" ":" ;
  mObject.mAttribute_mProcedureModeList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mProcFormalArgumentList" ":" ;
  mObject.mAttribute_mProcFormalArgumentList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEndOfProcLocation" ":" ;
  mObject.mAttribute_mEndOfProcLocation.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_requiredProcedureDeclarationListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_requiredProcedureDeclarationListAST * operand = (cCollectionElement_requiredProcedureDeclarationListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_requiredProcedureDeclarationListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST::GALGAS_requiredProcedureDeclarationListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST::GALGAS_requiredProcedureDeclarationListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST GALGAS_requiredProcedureDeclarationListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_requiredProcedureDeclarationListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST GALGAS_requiredProcedureDeclarationListAST::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                                                                  const GALGAS_lstringlist & inOperand1,
                                                                                                                  const GALGAS_procFormalArgumentList & inOperand2,
                                                                                                                  const GALGAS_location & inOperand3
                                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_requiredProcedureDeclarationListAST result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_requiredProcedureDeclarationListAST::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_requiredProcedureDeclarationListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                            const GALGAS_lstring & in_mRequiredProcedureName,
                                                                            const GALGAS_lstringlist & in_mProcedureModeList,
                                                                            const GALGAS_procFormalArgumentList & in_mProcFormalArgumentList,
                                                                            const GALGAS_location & in_mEndOfProcLocation
                                                                            COMMA_LOCATION_ARGS) {
  cCollectionElement_requiredProcedureDeclarationListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_requiredProcedureDeclarationListAST (in_mRequiredProcedureName,
                                                                         in_mProcedureModeList,
                                                                         in_mProcFormalArgumentList,
                                                                         in_mEndOfProcLocation COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_requiredProcedureDeclarationListAST::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                                      const GALGAS_lstringlist & inOperand1,
                                                                      const GALGAS_procFormalArgumentList & inOperand2,
                                                                      const GALGAS_location & inOperand3
                                                                      COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_requiredProcedureDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_requiredProcedureDeclarationListAST::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                                       const GALGAS_lstringlist inOperand1,
                                                                       const GALGAS_procFormalArgumentList inOperand2,
                                                                       const GALGAS_location inOperand3,
                                                                       const GALGAS_uint inInsertionIndex,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_requiredProcedureDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_requiredProcedureDeclarationListAST::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                                       GALGAS_lstringlist & outOperand1,
                                                                       GALGAS_procFormalArgumentList & outOperand2,
                                                                       GALGAS_location & outOperand3,
                                                                       const GALGAS_uint inRemoveIndex,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_requiredProcedureDeclarationListAST * p = (cCollectionElement_requiredProcedureDeclarationListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
      outOperand0 = p->mObject.mAttribute_mRequiredProcedureName ;
      outOperand1 = p->mObject.mAttribute_mProcedureModeList ;
      outOperand2 = p->mObject.mAttribute_mProcFormalArgumentList ;
      outOperand3 = p->mObject.mAttribute_mEndOfProcLocation ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_requiredProcedureDeclarationListAST::setter_popFirst (GALGAS_lstring & outOperand0,
                                                                  GALGAS_lstringlist & outOperand1,
                                                                  GALGAS_procFormalArgumentList & outOperand2,
                                                                  GALGAS_location & outOperand3,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_requiredProcedureDeclarationListAST * p = (cCollectionElement_requiredProcedureDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mRequiredProcedureName ;
    outOperand1 = p->mObject.mAttribute_mProcedureModeList ;
    outOperand2 = p->mObject.mAttribute_mProcFormalArgumentList ;
    outOperand3 = p->mObject.mAttribute_mEndOfProcLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_requiredProcedureDeclarationListAST::setter_popLast (GALGAS_lstring & outOperand0,
                                                                 GALGAS_lstringlist & outOperand1,
                                                                 GALGAS_procFormalArgumentList & outOperand2,
                                                                 GALGAS_location & outOperand3,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_requiredProcedureDeclarationListAST * p = (cCollectionElement_requiredProcedureDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mRequiredProcedureName ;
    outOperand1 = p->mObject.mAttribute_mProcedureModeList ;
    outOperand2 = p->mObject.mAttribute_mProcFormalArgumentList ;
    outOperand3 = p->mObject.mAttribute_mEndOfProcLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_requiredProcedureDeclarationListAST::method_first (GALGAS_lstring & outOperand0,
                                                               GALGAS_lstringlist & outOperand1,
                                                               GALGAS_procFormalArgumentList & outOperand2,
                                                               GALGAS_location & outOperand3,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_requiredProcedureDeclarationListAST * p = (cCollectionElement_requiredProcedureDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mRequiredProcedureName ;
    outOperand1 = p->mObject.mAttribute_mProcedureModeList ;
    outOperand2 = p->mObject.mAttribute_mProcFormalArgumentList ;
    outOperand3 = p->mObject.mAttribute_mEndOfProcLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_requiredProcedureDeclarationListAST::method_last (GALGAS_lstring & outOperand0,
                                                              GALGAS_lstringlist & outOperand1,
                                                              GALGAS_procFormalArgumentList & outOperand2,
                                                              GALGAS_location & outOperand3,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_requiredProcedureDeclarationListAST * p = (cCollectionElement_requiredProcedureDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mRequiredProcedureName ;
    outOperand1 = p->mObject.mAttribute_mProcedureModeList ;
    outOperand2 = p->mObject.mAttribute_mProcFormalArgumentList ;
    outOperand3 = p->mObject.mAttribute_mEndOfProcLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST GALGAS_requiredProcedureDeclarationListAST::add_operation (const GALGAS_requiredProcedureDeclarationListAST & inOperand,
                                                                                                      C_Compiler * /* inCompiler */
                                                                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_requiredProcedureDeclarationListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST GALGAS_requiredProcedureDeclarationListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                                C_Compiler * inCompiler
                                                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_requiredProcedureDeclarationListAST result = GALGAS_requiredProcedureDeclarationListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST GALGAS_requiredProcedureDeclarationListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                                C_Compiler * inCompiler
                                                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_requiredProcedureDeclarationListAST result = GALGAS_requiredProcedureDeclarationListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST GALGAS_requiredProcedureDeclarationListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                                              C_Compiler * inCompiler
                                                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_requiredProcedureDeclarationListAST result = GALGAS_requiredProcedureDeclarationListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_requiredProcedureDeclarationListAST::plusAssign_operation (const GALGAS_requiredProcedureDeclarationListAST inOperand,
                                                                       C_Compiler * /* inCompiler */
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_requiredProcedureDeclarationListAST::getter_mRequiredProcedureNameAtIndex (const GALGAS_uint & inIndex,
                                                                                                 C_Compiler * inCompiler
                                                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_requiredProcedureDeclarationListAST * p = (cCollectionElement_requiredProcedureDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
    result = p->mObject.mAttribute_mRequiredProcedureName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_requiredProcedureDeclarationListAST::getter_mProcedureModeListAtIndex (const GALGAS_uint & inIndex,
                                                                                                 C_Compiler * inCompiler
                                                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_requiredProcedureDeclarationListAST * p = (cCollectionElement_requiredProcedureDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstringlist result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
    result = p->mObject.mAttribute_mProcedureModeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_requiredProcedureDeclarationListAST::getter_mProcFormalArgumentListAtIndex (const GALGAS_uint & inIndex,
                                                                                                                 C_Compiler * inCompiler
                                                                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_requiredProcedureDeclarationListAST * p = (cCollectionElement_requiredProcedureDeclarationListAST *) attributes.ptr () ;
  GALGAS_procFormalArgumentList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
    result = p->mObject.mAttribute_mProcFormalArgumentList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_requiredProcedureDeclarationListAST::getter_mEndOfProcLocationAtIndex (const GALGAS_uint & inIndex,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_requiredProcedureDeclarationListAST * p = (cCollectionElement_requiredProcedureDeclarationListAST *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
    result = p->mObject.mAttribute_mEndOfProcLocation ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_requiredProcedureDeclarationListAST::cEnumerator_requiredProcedureDeclarationListAST (const GALGAS_requiredProcedureDeclarationListAST & inEnumeratedObject,
                                                                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST_2D_element cEnumerator_requiredProcedureDeclarationListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_requiredProcedureDeclarationListAST * p = (const cCollectionElement_requiredProcedureDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_requiredProcedureDeclarationListAST::current_mRequiredProcedureName (LOCATION_ARGS) const {
  const cCollectionElement_requiredProcedureDeclarationListAST * p = (const cCollectionElement_requiredProcedureDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
  return p->mObject.mAttribute_mRequiredProcedureName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cEnumerator_requiredProcedureDeclarationListAST::current_mProcedureModeList (LOCATION_ARGS) const {
  const cCollectionElement_requiredProcedureDeclarationListAST * p = (const cCollectionElement_requiredProcedureDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
  return p->mObject.mAttribute_mProcedureModeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList cEnumerator_requiredProcedureDeclarationListAST::current_mProcFormalArgumentList (LOCATION_ARGS) const {
  const cCollectionElement_requiredProcedureDeclarationListAST * p = (const cCollectionElement_requiredProcedureDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
  return p->mObject.mAttribute_mProcFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_requiredProcedureDeclarationListAST::current_mEndOfProcLocation (LOCATION_ARGS) const {
  const cCollectionElement_requiredProcedureDeclarationListAST * p = (const cCollectionElement_requiredProcedureDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_requiredProcedureDeclarationListAST) ;
  return p->mObject.mAttribute_mEndOfProcLocation ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @requiredProcedureDeclarationListAST type                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_requiredProcedureDeclarationListAST ("requiredProcedureDeclarationListAST",
                                                            NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_requiredProcedureDeclarationListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_requiredProcedureDeclarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_requiredProcedureDeclarationListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_requiredProcedureDeclarationListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST GALGAS_requiredProcedureDeclarationListAST::extractObject (const GALGAS_object & inObject,
                                                                                                      C_Compiler * inCompiler
                                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_requiredProcedureDeclarationListAST result ;
  const GALGAS_requiredProcedureDeclarationListAST * p = (const GALGAS_requiredProcedureDeclarationListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_requiredProcedureDeclarationListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("requiredProcedureDeclarationListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Class for element of '@externProcedureDeclarationListAST' list                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_externProcedureDeclarationListAST : public cCollectionElement {
  public : GALGAS_externProcedureDeclarationListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_externProcedureDeclarationListAST (const GALGAS_lstring & in_mExternProcedureName,
                                                                 const GALGAS_lstringlist & in_mProcedureModeList,
                                                                 const GALGAS_procFormalArgumentList & in_mProcFormalArgumentList,
                                                                 const GALGAS_lstring & in_mReturnTypeName,
                                                                 const GALGAS_lstring & in_mRoutineNameForGeneration,
                                                                 const GALGAS_location & in_mEndOfProcLocation
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

cCollectionElement_externProcedureDeclarationListAST::cCollectionElement_externProcedureDeclarationListAST (const GALGAS_lstring & in_mExternProcedureName,
                                                                                                            const GALGAS_lstringlist & in_mProcedureModeList,
                                                                                                            const GALGAS_procFormalArgumentList & in_mProcFormalArgumentList,
                                                                                                            const GALGAS_lstring & in_mReturnTypeName,
                                                                                                            const GALGAS_lstring & in_mRoutineNameForGeneration,
                                                                                                            const GALGAS_location & in_mEndOfProcLocation
                                                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mExternProcedureName, in_mProcedureModeList, in_mProcFormalArgumentList, in_mReturnTypeName, in_mRoutineNameForGeneration, in_mEndOfProcLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_externProcedureDeclarationListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_externProcedureDeclarationListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_externProcedureDeclarationListAST (mObject.mAttribute_mExternProcedureName, mObject.mAttribute_mProcedureModeList, mObject.mAttribute_mProcFormalArgumentList, mObject.mAttribute_mReturnTypeName, mObject.mAttribute_mRoutineNameForGeneration, mObject.mAttribute_mEndOfProcLocation COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_externProcedureDeclarationListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mExternProcedureName" ":" ;
  mObject.mAttribute_mExternProcedureName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mProcedureModeList" ":" ;
  mObject.mAttribute_mProcedureModeList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mProcFormalArgumentList" ":" ;
  mObject.mAttribute_mProcFormalArgumentList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mReturnTypeName" ":" ;
  mObject.mAttribute_mReturnTypeName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mRoutineNameForGeneration" ":" ;
  mObject.mAttribute_mRoutineNameForGeneration.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEndOfProcLocation" ":" ;
  mObject.mAttribute_mEndOfProcLocation.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_externProcedureDeclarationListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_externProcedureDeclarationListAST * operand = (cCollectionElement_externProcedureDeclarationListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_externProcedureDeclarationListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureDeclarationListAST::GALGAS_externProcedureDeclarationListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureDeclarationListAST::GALGAS_externProcedureDeclarationListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureDeclarationListAST GALGAS_externProcedureDeclarationListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_externProcedureDeclarationListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureDeclarationListAST GALGAS_externProcedureDeclarationListAST::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                                                              const GALGAS_lstringlist & inOperand1,
                                                                                                              const GALGAS_procFormalArgumentList & inOperand2,
                                                                                                              const GALGAS_lstring & inOperand3,
                                                                                                              const GALGAS_lstring & inOperand4,
                                                                                                              const GALGAS_location & inOperand5
                                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_externProcedureDeclarationListAST result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_externProcedureDeclarationListAST::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureDeclarationListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                          const GALGAS_lstring & in_mExternProcedureName,
                                                                          const GALGAS_lstringlist & in_mProcedureModeList,
                                                                          const GALGAS_procFormalArgumentList & in_mProcFormalArgumentList,
                                                                          const GALGAS_lstring & in_mReturnTypeName,
                                                                          const GALGAS_lstring & in_mRoutineNameForGeneration,
                                                                          const GALGAS_location & in_mEndOfProcLocation
                                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement_externProcedureDeclarationListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_externProcedureDeclarationListAST (in_mExternProcedureName,
                                                                       in_mProcedureModeList,
                                                                       in_mProcFormalArgumentList,
                                                                       in_mReturnTypeName,
                                                                       in_mRoutineNameForGeneration,
                                                                       in_mEndOfProcLocation COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureDeclarationListAST::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                                    const GALGAS_lstringlist & inOperand1,
                                                                    const GALGAS_procFormalArgumentList & inOperand2,
                                                                    const GALGAS_lstring & inOperand3,
                                                                    const GALGAS_lstring & inOperand4,
                                                                    const GALGAS_location & inOperand5
                                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_externProcedureDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureDeclarationListAST::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                                     const GALGAS_lstringlist inOperand1,
                                                                     const GALGAS_procFormalArgumentList inOperand2,
                                                                     const GALGAS_lstring inOperand3,
                                                                     const GALGAS_lstring inOperand4,
                                                                     const GALGAS_location inOperand5,
                                                                     const GALGAS_uint inInsertionIndex,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_externProcedureDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureDeclarationListAST::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                                     GALGAS_lstringlist & outOperand1,
                                                                     GALGAS_procFormalArgumentList & outOperand2,
                                                                     GALGAS_lstring & outOperand3,
                                                                     GALGAS_lstring & outOperand4,
                                                                     GALGAS_location & outOperand5,
                                                                     const GALGAS_uint inRemoveIndex,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_externProcedureDeclarationListAST * p = (cCollectionElement_externProcedureDeclarationListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
      outOperand4.drop () ;
      outOperand5.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
      outOperand0 = p->mObject.mAttribute_mExternProcedureName ;
      outOperand1 = p->mObject.mAttribute_mProcedureModeList ;
      outOperand2 = p->mObject.mAttribute_mProcFormalArgumentList ;
      outOperand3 = p->mObject.mAttribute_mReturnTypeName ;
      outOperand4 = p->mObject.mAttribute_mRoutineNameForGeneration ;
      outOperand5 = p->mObject.mAttribute_mEndOfProcLocation ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureDeclarationListAST::setter_popFirst (GALGAS_lstring & outOperand0,
                                                                GALGAS_lstringlist & outOperand1,
                                                                GALGAS_procFormalArgumentList & outOperand2,
                                                                GALGAS_lstring & outOperand3,
                                                                GALGAS_lstring & outOperand4,
                                                                GALGAS_location & outOperand5,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_externProcedureDeclarationListAST * p = (cCollectionElement_externProcedureDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mExternProcedureName ;
    outOperand1 = p->mObject.mAttribute_mProcedureModeList ;
    outOperand2 = p->mObject.mAttribute_mProcFormalArgumentList ;
    outOperand3 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand4 = p->mObject.mAttribute_mRoutineNameForGeneration ;
    outOperand5 = p->mObject.mAttribute_mEndOfProcLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureDeclarationListAST::setter_popLast (GALGAS_lstring & outOperand0,
                                                               GALGAS_lstringlist & outOperand1,
                                                               GALGAS_procFormalArgumentList & outOperand2,
                                                               GALGAS_lstring & outOperand3,
                                                               GALGAS_lstring & outOperand4,
                                                               GALGAS_location & outOperand5,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_externProcedureDeclarationListAST * p = (cCollectionElement_externProcedureDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mExternProcedureName ;
    outOperand1 = p->mObject.mAttribute_mProcedureModeList ;
    outOperand2 = p->mObject.mAttribute_mProcFormalArgumentList ;
    outOperand3 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand4 = p->mObject.mAttribute_mRoutineNameForGeneration ;
    outOperand5 = p->mObject.mAttribute_mEndOfProcLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureDeclarationListAST::method_first (GALGAS_lstring & outOperand0,
                                                             GALGAS_lstringlist & outOperand1,
                                                             GALGAS_procFormalArgumentList & outOperand2,
                                                             GALGAS_lstring & outOperand3,
                                                             GALGAS_lstring & outOperand4,
                                                             GALGAS_location & outOperand5,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_externProcedureDeclarationListAST * p = (cCollectionElement_externProcedureDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mExternProcedureName ;
    outOperand1 = p->mObject.mAttribute_mProcedureModeList ;
    outOperand2 = p->mObject.mAttribute_mProcFormalArgumentList ;
    outOperand3 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand4 = p->mObject.mAttribute_mRoutineNameForGeneration ;
    outOperand5 = p->mObject.mAttribute_mEndOfProcLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureDeclarationListAST::method_last (GALGAS_lstring & outOperand0,
                                                            GALGAS_lstringlist & outOperand1,
                                                            GALGAS_procFormalArgumentList & outOperand2,
                                                            GALGAS_lstring & outOperand3,
                                                            GALGAS_lstring & outOperand4,
                                                            GALGAS_location & outOperand5,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_externProcedureDeclarationListAST * p = (cCollectionElement_externProcedureDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mExternProcedureName ;
    outOperand1 = p->mObject.mAttribute_mProcedureModeList ;
    outOperand2 = p->mObject.mAttribute_mProcFormalArgumentList ;
    outOperand3 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand4 = p->mObject.mAttribute_mRoutineNameForGeneration ;
    outOperand5 = p->mObject.mAttribute_mEndOfProcLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureDeclarationListAST GALGAS_externProcedureDeclarationListAST::add_operation (const GALGAS_externProcedureDeclarationListAST & inOperand,
                                                                                                  C_Compiler * /* inCompiler */
                                                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_externProcedureDeclarationListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureDeclarationListAST GALGAS_externProcedureDeclarationListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_externProcedureDeclarationListAST result = GALGAS_externProcedureDeclarationListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureDeclarationListAST GALGAS_externProcedureDeclarationListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_externProcedureDeclarationListAST result = GALGAS_externProcedureDeclarationListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureDeclarationListAST GALGAS_externProcedureDeclarationListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_externProcedureDeclarationListAST result = GALGAS_externProcedureDeclarationListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_externProcedureDeclarationListAST::plusAssign_operation (const GALGAS_externProcedureDeclarationListAST inOperand,
                                                                     C_Compiler * /* inCompiler */
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_externProcedureDeclarationListAST::getter_mExternProcedureNameAtIndex (const GALGAS_uint & inIndex,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_externProcedureDeclarationListAST * p = (cCollectionElement_externProcedureDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
    result = p->mObject.mAttribute_mExternProcedureName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_externProcedureDeclarationListAST::getter_mProcedureModeListAtIndex (const GALGAS_uint & inIndex,
                                                                                               C_Compiler * inCompiler
                                                                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_externProcedureDeclarationListAST * p = (cCollectionElement_externProcedureDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstringlist result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
    result = p->mObject.mAttribute_mProcedureModeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_externProcedureDeclarationListAST::getter_mProcFormalArgumentListAtIndex (const GALGAS_uint & inIndex,
                                                                                                               C_Compiler * inCompiler
                                                                                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_externProcedureDeclarationListAST * p = (cCollectionElement_externProcedureDeclarationListAST *) attributes.ptr () ;
  GALGAS_procFormalArgumentList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
    result = p->mObject.mAttribute_mProcFormalArgumentList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_externProcedureDeclarationListAST::getter_mReturnTypeNameAtIndex (const GALGAS_uint & inIndex,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_externProcedureDeclarationListAST * p = (cCollectionElement_externProcedureDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
    result = p->mObject.mAttribute_mReturnTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_externProcedureDeclarationListAST::getter_mRoutineNameForGenerationAtIndex (const GALGAS_uint & inIndex,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_externProcedureDeclarationListAST * p = (cCollectionElement_externProcedureDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
    result = p->mObject.mAttribute_mRoutineNameForGeneration ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_externProcedureDeclarationListAST::getter_mEndOfProcLocationAtIndex (const GALGAS_uint & inIndex,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_externProcedureDeclarationListAST * p = (cCollectionElement_externProcedureDeclarationListAST *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
    result = p->mObject.mAttribute_mEndOfProcLocation ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_externProcedureDeclarationListAST::cEnumerator_externProcedureDeclarationListAST (const GALGAS_externProcedureDeclarationListAST & inEnumeratedObject,
                                                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureDeclarationListAST_2D_element cEnumerator_externProcedureDeclarationListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_externProcedureDeclarationListAST * p = (const cCollectionElement_externProcedureDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_externProcedureDeclarationListAST::current_mExternProcedureName (LOCATION_ARGS) const {
  const cCollectionElement_externProcedureDeclarationListAST * p = (const cCollectionElement_externProcedureDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
  return p->mObject.mAttribute_mExternProcedureName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cEnumerator_externProcedureDeclarationListAST::current_mProcedureModeList (LOCATION_ARGS) const {
  const cCollectionElement_externProcedureDeclarationListAST * p = (const cCollectionElement_externProcedureDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
  return p->mObject.mAttribute_mProcedureModeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList cEnumerator_externProcedureDeclarationListAST::current_mProcFormalArgumentList (LOCATION_ARGS) const {
  const cCollectionElement_externProcedureDeclarationListAST * p = (const cCollectionElement_externProcedureDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
  return p->mObject.mAttribute_mProcFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_externProcedureDeclarationListAST::current_mReturnTypeName (LOCATION_ARGS) const {
  const cCollectionElement_externProcedureDeclarationListAST * p = (const cCollectionElement_externProcedureDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
  return p->mObject.mAttribute_mReturnTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_externProcedureDeclarationListAST::current_mRoutineNameForGeneration (LOCATION_ARGS) const {
  const cCollectionElement_externProcedureDeclarationListAST * p = (const cCollectionElement_externProcedureDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
  return p->mObject.mAttribute_mRoutineNameForGeneration ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_externProcedureDeclarationListAST::current_mEndOfProcLocation (LOCATION_ARGS) const {
  const cCollectionElement_externProcedureDeclarationListAST * p = (const cCollectionElement_externProcedureDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_externProcedureDeclarationListAST) ;
  return p->mObject.mAttribute_mEndOfProcLocation ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @externProcedureDeclarationListAST type                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_externProcedureDeclarationListAST ("externProcedureDeclarationListAST",
                                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_externProcedureDeclarationListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_externProcedureDeclarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_externProcedureDeclarationListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_externProcedureDeclarationListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_externProcedureDeclarationListAST GALGAS_externProcedureDeclarationListAST::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_externProcedureDeclarationListAST result ;
  const GALGAS_externProcedureDeclarationListAST * p = (const GALGAS_externProcedureDeclarationListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_externProcedureDeclarationListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("externProcedureDeclarationListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Class for element of '@isrDeclarationListAST' list                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_isrDeclarationListAST : public cCollectionElement {
  public : GALGAS_isrDeclarationListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_isrDeclarationListAST (const GALGAS_lstring & in_mISRName,
                                                     const GALGAS_lstring & in_mSelfTypeName,
                                                     const GALGAS_string & in_mGlobalVariableName,
                                                     const GALGAS_lstringlist & in_mISRAttributeList,
                                                     const GALGAS_instructionListAST & in_mISRInstructionList,
                                                     const GALGAS_location & in_mEndOfISRDeclaration
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

cCollectionElement_isrDeclarationListAST::cCollectionElement_isrDeclarationListAST (const GALGAS_lstring & in_mISRName,
                                                                                    const GALGAS_lstring & in_mSelfTypeName,
                                                                                    const GALGAS_string & in_mGlobalVariableName,
                                                                                    const GALGAS_lstringlist & in_mISRAttributeList,
                                                                                    const GALGAS_instructionListAST & in_mISRInstructionList,
                                                                                    const GALGAS_location & in_mEndOfISRDeclaration
                                                                                    COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mISRName, in_mSelfTypeName, in_mGlobalVariableName, in_mISRAttributeList, in_mISRInstructionList, in_mEndOfISRDeclaration) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_isrDeclarationListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_isrDeclarationListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_isrDeclarationListAST (mObject.mAttribute_mISRName, mObject.mAttribute_mSelfTypeName, mObject.mAttribute_mGlobalVariableName, mObject.mAttribute_mISRAttributeList, mObject.mAttribute_mISRInstructionList, mObject.mAttribute_mEndOfISRDeclaration COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_isrDeclarationListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mISRName" ":" ;
  mObject.mAttribute_mISRName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSelfTypeName" ":" ;
  mObject.mAttribute_mSelfTypeName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGlobalVariableName" ":" ;
  mObject.mAttribute_mGlobalVariableName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mISRAttributeList" ":" ;
  mObject.mAttribute_mISRAttributeList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mISRInstructionList" ":" ;
  mObject.mAttribute_mISRInstructionList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEndOfISRDeclaration" ":" ;
  mObject.mAttribute_mEndOfISRDeclaration.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_isrDeclarationListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_isrDeclarationListAST * operand = (cCollectionElement_isrDeclarationListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_isrDeclarationListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST::GALGAS_isrDeclarationListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST::GALGAS_isrDeclarationListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST GALGAS_isrDeclarationListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_isrDeclarationListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST GALGAS_isrDeclarationListAST::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                                      const GALGAS_lstring & inOperand1,
                                                                                      const GALGAS_string & inOperand2,
                                                                                      const GALGAS_lstringlist & inOperand3,
                                                                                      const GALGAS_instructionListAST & inOperand4,
                                                                                      const GALGAS_location & inOperand5
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_isrDeclarationListAST result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_isrDeclarationListAST::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_isrDeclarationListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                              const GALGAS_lstring & in_mISRName,
                                                              const GALGAS_lstring & in_mSelfTypeName,
                                                              const GALGAS_string & in_mGlobalVariableName,
                                                              const GALGAS_lstringlist & in_mISRAttributeList,
                                                              const GALGAS_instructionListAST & in_mISRInstructionList,
                                                              const GALGAS_location & in_mEndOfISRDeclaration
                                                              COMMA_LOCATION_ARGS) {
  cCollectionElement_isrDeclarationListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_isrDeclarationListAST (in_mISRName,
                                                           in_mSelfTypeName,
                                                           in_mGlobalVariableName,
                                                           in_mISRAttributeList,
                                                           in_mISRInstructionList,
                                                           in_mEndOfISRDeclaration COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_isrDeclarationListAST::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                        const GALGAS_lstring & inOperand1,
                                                        const GALGAS_string & inOperand2,
                                                        const GALGAS_lstringlist & inOperand3,
                                                        const GALGAS_instructionListAST & inOperand4,
                                                        const GALGAS_location & inOperand5
                                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_isrDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_isrDeclarationListAST::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                         const GALGAS_lstring inOperand1,
                                                         const GALGAS_string inOperand2,
                                                         const GALGAS_lstringlist inOperand3,
                                                         const GALGAS_instructionListAST inOperand4,
                                                         const GALGAS_location inOperand5,
                                                         const GALGAS_uint inInsertionIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_isrDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_isrDeclarationListAST::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                         GALGAS_lstring & outOperand1,
                                                         GALGAS_string & outOperand2,
                                                         GALGAS_lstringlist & outOperand3,
                                                         GALGAS_instructionListAST & outOperand4,
                                                         GALGAS_location & outOperand5,
                                                         const GALGAS_uint inRemoveIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_isrDeclarationListAST * p = (cCollectionElement_isrDeclarationListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
      outOperand4.drop () ;
      outOperand5.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
      outOperand0 = p->mObject.mAttribute_mISRName ;
      outOperand1 = p->mObject.mAttribute_mSelfTypeName ;
      outOperand2 = p->mObject.mAttribute_mGlobalVariableName ;
      outOperand3 = p->mObject.mAttribute_mISRAttributeList ;
      outOperand4 = p->mObject.mAttribute_mISRInstructionList ;
      outOperand5 = p->mObject.mAttribute_mEndOfISRDeclaration ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_isrDeclarationListAST::setter_popFirst (GALGAS_lstring & outOperand0,
                                                    GALGAS_lstring & outOperand1,
                                                    GALGAS_string & outOperand2,
                                                    GALGAS_lstringlist & outOperand3,
                                                    GALGAS_instructionListAST & outOperand4,
                                                    GALGAS_location & outOperand5,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_isrDeclarationListAST * p = (cCollectionElement_isrDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mISRName ;
    outOperand1 = p->mObject.mAttribute_mSelfTypeName ;
    outOperand2 = p->mObject.mAttribute_mGlobalVariableName ;
    outOperand3 = p->mObject.mAttribute_mISRAttributeList ;
    outOperand4 = p->mObject.mAttribute_mISRInstructionList ;
    outOperand5 = p->mObject.mAttribute_mEndOfISRDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_isrDeclarationListAST::setter_popLast (GALGAS_lstring & outOperand0,
                                                   GALGAS_lstring & outOperand1,
                                                   GALGAS_string & outOperand2,
                                                   GALGAS_lstringlist & outOperand3,
                                                   GALGAS_instructionListAST & outOperand4,
                                                   GALGAS_location & outOperand5,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_isrDeclarationListAST * p = (cCollectionElement_isrDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mISRName ;
    outOperand1 = p->mObject.mAttribute_mSelfTypeName ;
    outOperand2 = p->mObject.mAttribute_mGlobalVariableName ;
    outOperand3 = p->mObject.mAttribute_mISRAttributeList ;
    outOperand4 = p->mObject.mAttribute_mISRInstructionList ;
    outOperand5 = p->mObject.mAttribute_mEndOfISRDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_isrDeclarationListAST::method_first (GALGAS_lstring & outOperand0,
                                                 GALGAS_lstring & outOperand1,
                                                 GALGAS_string & outOperand2,
                                                 GALGAS_lstringlist & outOperand3,
                                                 GALGAS_instructionListAST & outOperand4,
                                                 GALGAS_location & outOperand5,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_isrDeclarationListAST * p = (cCollectionElement_isrDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mISRName ;
    outOperand1 = p->mObject.mAttribute_mSelfTypeName ;
    outOperand2 = p->mObject.mAttribute_mGlobalVariableName ;
    outOperand3 = p->mObject.mAttribute_mISRAttributeList ;
    outOperand4 = p->mObject.mAttribute_mISRInstructionList ;
    outOperand5 = p->mObject.mAttribute_mEndOfISRDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_isrDeclarationListAST::method_last (GALGAS_lstring & outOperand0,
                                                GALGAS_lstring & outOperand1,
                                                GALGAS_string & outOperand2,
                                                GALGAS_lstringlist & outOperand3,
                                                GALGAS_instructionListAST & outOperand4,
                                                GALGAS_location & outOperand5,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_isrDeclarationListAST * p = (cCollectionElement_isrDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mISRName ;
    outOperand1 = p->mObject.mAttribute_mSelfTypeName ;
    outOperand2 = p->mObject.mAttribute_mGlobalVariableName ;
    outOperand3 = p->mObject.mAttribute_mISRAttributeList ;
    outOperand4 = p->mObject.mAttribute_mISRInstructionList ;
    outOperand5 = p->mObject.mAttribute_mEndOfISRDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST GALGAS_isrDeclarationListAST::add_operation (const GALGAS_isrDeclarationListAST & inOperand,
                                                                          C_Compiler * /* inCompiler */
                                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_isrDeclarationListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST GALGAS_isrDeclarationListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_isrDeclarationListAST result = GALGAS_isrDeclarationListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST GALGAS_isrDeclarationListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_isrDeclarationListAST result = GALGAS_isrDeclarationListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST GALGAS_isrDeclarationListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_isrDeclarationListAST result = GALGAS_isrDeclarationListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_isrDeclarationListAST::plusAssign_operation (const GALGAS_isrDeclarationListAST inOperand,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_isrDeclarationListAST::getter_mISRNameAtIndex (const GALGAS_uint & inIndex,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_isrDeclarationListAST * p = (cCollectionElement_isrDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
    result = p->mObject.mAttribute_mISRName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_isrDeclarationListAST::getter_mSelfTypeNameAtIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_isrDeclarationListAST * p = (cCollectionElement_isrDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
    result = p->mObject.mAttribute_mSelfTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_isrDeclarationListAST::getter_mGlobalVariableNameAtIndex (const GALGAS_uint & inIndex,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_isrDeclarationListAST * p = (cCollectionElement_isrDeclarationListAST *) attributes.ptr () ;
  GALGAS_string result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
    result = p->mObject.mAttribute_mGlobalVariableName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_isrDeclarationListAST::getter_mISRAttributeListAtIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_isrDeclarationListAST * p = (cCollectionElement_isrDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstringlist result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
    result = p->mObject.mAttribute_mISRAttributeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_isrDeclarationListAST::getter_mISRInstructionListAtIndex (const GALGAS_uint & inIndex,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_isrDeclarationListAST * p = (cCollectionElement_isrDeclarationListAST *) attributes.ptr () ;
  GALGAS_instructionListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
    result = p->mObject.mAttribute_mISRInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_isrDeclarationListAST::getter_mEndOfISRDeclarationAtIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_isrDeclarationListAST * p = (cCollectionElement_isrDeclarationListAST *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
    result = p->mObject.mAttribute_mEndOfISRDeclaration ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_isrDeclarationListAST::cEnumerator_isrDeclarationListAST (const GALGAS_isrDeclarationListAST & inEnumeratedObject,
                                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST_2D_element cEnumerator_isrDeclarationListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_isrDeclarationListAST * p = (const cCollectionElement_isrDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_isrDeclarationListAST::current_mISRName (LOCATION_ARGS) const {
  const cCollectionElement_isrDeclarationListAST * p = (const cCollectionElement_isrDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
  return p->mObject.mAttribute_mISRName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_isrDeclarationListAST::current_mSelfTypeName (LOCATION_ARGS) const {
  const cCollectionElement_isrDeclarationListAST * p = (const cCollectionElement_isrDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
  return p->mObject.mAttribute_mSelfTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_isrDeclarationListAST::current_mGlobalVariableName (LOCATION_ARGS) const {
  const cCollectionElement_isrDeclarationListAST * p = (const cCollectionElement_isrDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
  return p->mObject.mAttribute_mGlobalVariableName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cEnumerator_isrDeclarationListAST::current_mISRAttributeList (LOCATION_ARGS) const {
  const cCollectionElement_isrDeclarationListAST * p = (const cCollectionElement_isrDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
  return p->mObject.mAttribute_mISRAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cEnumerator_isrDeclarationListAST::current_mISRInstructionList (LOCATION_ARGS) const {
  const cCollectionElement_isrDeclarationListAST * p = (const cCollectionElement_isrDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
  return p->mObject.mAttribute_mISRInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_isrDeclarationListAST::current_mEndOfISRDeclaration (LOCATION_ARGS) const {
  const cCollectionElement_isrDeclarationListAST * p = (const cCollectionElement_isrDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_isrDeclarationListAST) ;
  return p->mObject.mAttribute_mEndOfISRDeclaration ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @isrDeclarationListAST type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_isrDeclarationListAST ("isrDeclarationListAST",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_isrDeclarationListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_isrDeclarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_isrDeclarationListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_isrDeclarationListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST GALGAS_isrDeclarationListAST::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_isrDeclarationListAST result ;
  const GALGAS_isrDeclarationListAST * p = (const GALGAS_isrDeclarationListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_isrDeclarationListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("isrDeclarationListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Class for element of '@sectionDeclarationListAST' list                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_sectionDeclarationListAST : public cCollectionElement {
  public : GALGAS_sectionDeclarationListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_sectionDeclarationListAST (const GALGAS_lstring & in_mSectionName,
                                                         const GALGAS_bool & in_mPublic,
                                                         const GALGAS_lstringlist & in_mSectionAttributeList,
                                                         const GALGAS_procFormalArgumentList & in_mSectionFormalArgumentList,
                                                         const GALGAS_lstring & in_mReturnTypeName,
                                                         const GALGAS_instructionListAST & in_mSectionInstructionList,
                                                         const GALGAS_location & in_mEndOfSectionLocation
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

cCollectionElement_sectionDeclarationListAST::cCollectionElement_sectionDeclarationListAST (const GALGAS_lstring & in_mSectionName,
                                                                                            const GALGAS_bool & in_mPublic,
                                                                                            const GALGAS_lstringlist & in_mSectionAttributeList,
                                                                                            const GALGAS_procFormalArgumentList & in_mSectionFormalArgumentList,
                                                                                            const GALGAS_lstring & in_mReturnTypeName,
                                                                                            const GALGAS_instructionListAST & in_mSectionInstructionList,
                                                                                            const GALGAS_location & in_mEndOfSectionLocation
                                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mSectionName, in_mPublic, in_mSectionAttributeList, in_mSectionFormalArgumentList, in_mReturnTypeName, in_mSectionInstructionList, in_mEndOfSectionLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_sectionDeclarationListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_sectionDeclarationListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_sectionDeclarationListAST (mObject.mAttribute_mSectionName, mObject.mAttribute_mPublic, mObject.mAttribute_mSectionAttributeList, mObject.mAttribute_mSectionFormalArgumentList, mObject.mAttribute_mReturnTypeName, mObject.mAttribute_mSectionInstructionList, mObject.mAttribute_mEndOfSectionLocation COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_sectionDeclarationListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSectionName" ":" ;
  mObject.mAttribute_mSectionName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPublic" ":" ;
  mObject.mAttribute_mPublic.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSectionAttributeList" ":" ;
  mObject.mAttribute_mSectionAttributeList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSectionFormalArgumentList" ":" ;
  mObject.mAttribute_mSectionFormalArgumentList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mReturnTypeName" ":" ;
  mObject.mAttribute_mReturnTypeName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSectionInstructionList" ":" ;
  mObject.mAttribute_mSectionInstructionList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEndOfSectionLocation" ":" ;
  mObject.mAttribute_mEndOfSectionLocation.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_sectionDeclarationListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_sectionDeclarationListAST * operand = (cCollectionElement_sectionDeclarationListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_sectionDeclarationListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST::GALGAS_sectionDeclarationListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST::GALGAS_sectionDeclarationListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST GALGAS_sectionDeclarationListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_sectionDeclarationListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST GALGAS_sectionDeclarationListAST::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                                              const GALGAS_bool & inOperand1,
                                                                                              const GALGAS_lstringlist & inOperand2,
                                                                                              const GALGAS_procFormalArgumentList & inOperand3,
                                                                                              const GALGAS_lstring & inOperand4,
                                                                                              const GALGAS_instructionListAST & inOperand5,
                                                                                              const GALGAS_location & inOperand6
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_sectionDeclarationListAST result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_sectionDeclarationListAST::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sectionDeclarationListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                  const GALGAS_lstring & in_mSectionName,
                                                                  const GALGAS_bool & in_mPublic,
                                                                  const GALGAS_lstringlist & in_mSectionAttributeList,
                                                                  const GALGAS_procFormalArgumentList & in_mSectionFormalArgumentList,
                                                                  const GALGAS_lstring & in_mReturnTypeName,
                                                                  const GALGAS_instructionListAST & in_mSectionInstructionList,
                                                                  const GALGAS_location & in_mEndOfSectionLocation
                                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_sectionDeclarationListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_sectionDeclarationListAST (in_mSectionName,
                                                               in_mPublic,
                                                               in_mSectionAttributeList,
                                                               in_mSectionFormalArgumentList,
                                                               in_mReturnTypeName,
                                                               in_mSectionInstructionList,
                                                               in_mEndOfSectionLocation COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sectionDeclarationListAST::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_bool & inOperand1,
                                                            const GALGAS_lstringlist & inOperand2,
                                                            const GALGAS_procFormalArgumentList & inOperand3,
                                                            const GALGAS_lstring & inOperand4,
                                                            const GALGAS_instructionListAST & inOperand5,
                                                            const GALGAS_location & inOperand6
                                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_sectionDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sectionDeclarationListAST::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                             const GALGAS_bool inOperand1,
                                                             const GALGAS_lstringlist inOperand2,
                                                             const GALGAS_procFormalArgumentList inOperand3,
                                                             const GALGAS_lstring inOperand4,
                                                             const GALGAS_instructionListAST inOperand5,
                                                             const GALGAS_location inOperand6,
                                                             const GALGAS_uint inInsertionIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_sectionDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sectionDeclarationListAST::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                             GALGAS_bool & outOperand1,
                                                             GALGAS_lstringlist & outOperand2,
                                                             GALGAS_procFormalArgumentList & outOperand3,
                                                             GALGAS_lstring & outOperand4,
                                                             GALGAS_instructionListAST & outOperand5,
                                                             GALGAS_location & outOperand6,
                                                             const GALGAS_uint inRemoveIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_sectionDeclarationListAST * p = (cCollectionElement_sectionDeclarationListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
      outOperand4.drop () ;
      outOperand5.drop () ;
      outOperand6.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
      outOperand0 = p->mObject.mAttribute_mSectionName ;
      outOperand1 = p->mObject.mAttribute_mPublic ;
      outOperand2 = p->mObject.mAttribute_mSectionAttributeList ;
      outOperand3 = p->mObject.mAttribute_mSectionFormalArgumentList ;
      outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
      outOperand5 = p->mObject.mAttribute_mSectionInstructionList ;
      outOperand6 = p->mObject.mAttribute_mEndOfSectionLocation ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sectionDeclarationListAST::setter_popFirst (GALGAS_lstring & outOperand0,
                                                        GALGAS_bool & outOperand1,
                                                        GALGAS_lstringlist & outOperand2,
                                                        GALGAS_procFormalArgumentList & outOperand3,
                                                        GALGAS_lstring & outOperand4,
                                                        GALGAS_instructionListAST & outOperand5,
                                                        GALGAS_location & outOperand6,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sectionDeclarationListAST * p = (cCollectionElement_sectionDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mSectionName ;
    outOperand1 = p->mObject.mAttribute_mPublic ;
    outOperand2 = p->mObject.mAttribute_mSectionAttributeList ;
    outOperand3 = p->mObject.mAttribute_mSectionFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand5 = p->mObject.mAttribute_mSectionInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfSectionLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sectionDeclarationListAST::setter_popLast (GALGAS_lstring & outOperand0,
                                                       GALGAS_bool & outOperand1,
                                                       GALGAS_lstringlist & outOperand2,
                                                       GALGAS_procFormalArgumentList & outOperand3,
                                                       GALGAS_lstring & outOperand4,
                                                       GALGAS_instructionListAST & outOperand5,
                                                       GALGAS_location & outOperand6,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sectionDeclarationListAST * p = (cCollectionElement_sectionDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mSectionName ;
    outOperand1 = p->mObject.mAttribute_mPublic ;
    outOperand2 = p->mObject.mAttribute_mSectionAttributeList ;
    outOperand3 = p->mObject.mAttribute_mSectionFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand5 = p->mObject.mAttribute_mSectionInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfSectionLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sectionDeclarationListAST::method_first (GALGAS_lstring & outOperand0,
                                                     GALGAS_bool & outOperand1,
                                                     GALGAS_lstringlist & outOperand2,
                                                     GALGAS_procFormalArgumentList & outOperand3,
                                                     GALGAS_lstring & outOperand4,
                                                     GALGAS_instructionListAST & outOperand5,
                                                     GALGAS_location & outOperand6,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sectionDeclarationListAST * p = (cCollectionElement_sectionDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mSectionName ;
    outOperand1 = p->mObject.mAttribute_mPublic ;
    outOperand2 = p->mObject.mAttribute_mSectionAttributeList ;
    outOperand3 = p->mObject.mAttribute_mSectionFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand5 = p->mObject.mAttribute_mSectionInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfSectionLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sectionDeclarationListAST::method_last (GALGAS_lstring & outOperand0,
                                                    GALGAS_bool & outOperand1,
                                                    GALGAS_lstringlist & outOperand2,
                                                    GALGAS_procFormalArgumentList & outOperand3,
                                                    GALGAS_lstring & outOperand4,
                                                    GALGAS_instructionListAST & outOperand5,
                                                    GALGAS_location & outOperand6,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sectionDeclarationListAST * p = (cCollectionElement_sectionDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mSectionName ;
    outOperand1 = p->mObject.mAttribute_mPublic ;
    outOperand2 = p->mObject.mAttribute_mSectionAttributeList ;
    outOperand3 = p->mObject.mAttribute_mSectionFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand5 = p->mObject.mAttribute_mSectionInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfSectionLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST GALGAS_sectionDeclarationListAST::add_operation (const GALGAS_sectionDeclarationListAST & inOperand,
                                                                                  C_Compiler * /* inCompiler */
                                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sectionDeclarationListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST GALGAS_sectionDeclarationListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_sectionDeclarationListAST result = GALGAS_sectionDeclarationListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST GALGAS_sectionDeclarationListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_sectionDeclarationListAST result = GALGAS_sectionDeclarationListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST GALGAS_sectionDeclarationListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sectionDeclarationListAST result = GALGAS_sectionDeclarationListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sectionDeclarationListAST::plusAssign_operation (const GALGAS_sectionDeclarationListAST inOperand,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_sectionDeclarationListAST::getter_mSectionNameAtIndex (const GALGAS_uint & inIndex,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sectionDeclarationListAST * p = (cCollectionElement_sectionDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
    result = p->mObject.mAttribute_mSectionName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_sectionDeclarationListAST::getter_mPublicAtIndex (const GALGAS_uint & inIndex,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sectionDeclarationListAST * p = (cCollectionElement_sectionDeclarationListAST *) attributes.ptr () ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
    result = p->mObject.mAttribute_mPublic ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_sectionDeclarationListAST::getter_mSectionAttributeListAtIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sectionDeclarationListAST * p = (cCollectionElement_sectionDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstringlist result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
    result = p->mObject.mAttribute_mSectionAttributeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_sectionDeclarationListAST::getter_mSectionFormalArgumentListAtIndex (const GALGAS_uint & inIndex,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sectionDeclarationListAST * p = (cCollectionElement_sectionDeclarationListAST *) attributes.ptr () ;
  GALGAS_procFormalArgumentList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
    result = p->mObject.mAttribute_mSectionFormalArgumentList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_sectionDeclarationListAST::getter_mReturnTypeNameAtIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sectionDeclarationListAST * p = (cCollectionElement_sectionDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
    result = p->mObject.mAttribute_mReturnTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_sectionDeclarationListAST::getter_mSectionInstructionListAtIndex (const GALGAS_uint & inIndex,
                                                                                                   C_Compiler * inCompiler
                                                                                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sectionDeclarationListAST * p = (cCollectionElement_sectionDeclarationListAST *) attributes.ptr () ;
  GALGAS_instructionListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
    result = p->mObject.mAttribute_mSectionInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_sectionDeclarationListAST::getter_mEndOfSectionLocationAtIndex (const GALGAS_uint & inIndex,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sectionDeclarationListAST * p = (cCollectionElement_sectionDeclarationListAST *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
    result = p->mObject.mAttribute_mEndOfSectionLocation ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_sectionDeclarationListAST::cEnumerator_sectionDeclarationListAST (const GALGAS_sectionDeclarationListAST & inEnumeratedObject,
                                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST_2D_element cEnumerator_sectionDeclarationListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_sectionDeclarationListAST * p = (const cCollectionElement_sectionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_sectionDeclarationListAST::current_mSectionName (LOCATION_ARGS) const {
  const cCollectionElement_sectionDeclarationListAST * p = (const cCollectionElement_sectionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
  return p->mObject.mAttribute_mSectionName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_sectionDeclarationListAST::current_mPublic (LOCATION_ARGS) const {
  const cCollectionElement_sectionDeclarationListAST * p = (const cCollectionElement_sectionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
  return p->mObject.mAttribute_mPublic ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cEnumerator_sectionDeclarationListAST::current_mSectionAttributeList (LOCATION_ARGS) const {
  const cCollectionElement_sectionDeclarationListAST * p = (const cCollectionElement_sectionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
  return p->mObject.mAttribute_mSectionAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList cEnumerator_sectionDeclarationListAST::current_mSectionFormalArgumentList (LOCATION_ARGS) const {
  const cCollectionElement_sectionDeclarationListAST * p = (const cCollectionElement_sectionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
  return p->mObject.mAttribute_mSectionFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_sectionDeclarationListAST::current_mReturnTypeName (LOCATION_ARGS) const {
  const cCollectionElement_sectionDeclarationListAST * p = (const cCollectionElement_sectionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
  return p->mObject.mAttribute_mReturnTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cEnumerator_sectionDeclarationListAST::current_mSectionInstructionList (LOCATION_ARGS) const {
  const cCollectionElement_sectionDeclarationListAST * p = (const cCollectionElement_sectionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
  return p->mObject.mAttribute_mSectionInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_sectionDeclarationListAST::current_mEndOfSectionLocation (LOCATION_ARGS) const {
  const cCollectionElement_sectionDeclarationListAST * p = (const cCollectionElement_sectionDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sectionDeclarationListAST) ;
  return p->mObject.mAttribute_mEndOfSectionLocation ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @sectionDeclarationListAST type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sectionDeclarationListAST ("sectionDeclarationListAST",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sectionDeclarationListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sectionDeclarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sectionDeclarationListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sectionDeclarationListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST GALGAS_sectionDeclarationListAST::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_sectionDeclarationListAST result ;
  const GALGAS_sectionDeclarationListAST * p = (const GALGAS_sectionDeclarationListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sectionDeclarationListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sectionDeclarationListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Class for element of '@serviceDeclarationListAST' list                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_serviceDeclarationListAST : public cCollectionElement {
  public : GALGAS_serviceDeclarationListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_serviceDeclarationListAST (const GALGAS_lstring & in_mServiceName,
                                                         const GALGAS_bool & in_mPublic,
                                                         const GALGAS_lstringlist & in_mServiceAttributeList,
                                                         const GALGAS_procFormalArgumentList & in_mServiceFormalArgumentList,
                                                         const GALGAS_lstring & in_mReturnTypeName,
                                                         const GALGAS_instructionListAST & in_mServiceInstructionList,
                                                         const GALGAS_location & in_mEndOfServiceLocation
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

cCollectionElement_serviceDeclarationListAST::cCollectionElement_serviceDeclarationListAST (const GALGAS_lstring & in_mServiceName,
                                                                                            const GALGAS_bool & in_mPublic,
                                                                                            const GALGAS_lstringlist & in_mServiceAttributeList,
                                                                                            const GALGAS_procFormalArgumentList & in_mServiceFormalArgumentList,
                                                                                            const GALGAS_lstring & in_mReturnTypeName,
                                                                                            const GALGAS_instructionListAST & in_mServiceInstructionList,
                                                                                            const GALGAS_location & in_mEndOfServiceLocation
                                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mServiceName, in_mPublic, in_mServiceAttributeList, in_mServiceFormalArgumentList, in_mReturnTypeName, in_mServiceInstructionList, in_mEndOfServiceLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_serviceDeclarationListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_serviceDeclarationListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_serviceDeclarationListAST (mObject.mAttribute_mServiceName, mObject.mAttribute_mPublic, mObject.mAttribute_mServiceAttributeList, mObject.mAttribute_mServiceFormalArgumentList, mObject.mAttribute_mReturnTypeName, mObject.mAttribute_mServiceInstructionList, mObject.mAttribute_mEndOfServiceLocation COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_serviceDeclarationListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mServiceName" ":" ;
  mObject.mAttribute_mServiceName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPublic" ":" ;
  mObject.mAttribute_mPublic.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mServiceAttributeList" ":" ;
  mObject.mAttribute_mServiceAttributeList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mServiceFormalArgumentList" ":" ;
  mObject.mAttribute_mServiceFormalArgumentList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mReturnTypeName" ":" ;
  mObject.mAttribute_mReturnTypeName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mServiceInstructionList" ":" ;
  mObject.mAttribute_mServiceInstructionList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEndOfServiceLocation" ":" ;
  mObject.mAttribute_mEndOfServiceLocation.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_serviceDeclarationListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_serviceDeclarationListAST * operand = (cCollectionElement_serviceDeclarationListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_serviceDeclarationListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST::GALGAS_serviceDeclarationListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST::GALGAS_serviceDeclarationListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST GALGAS_serviceDeclarationListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_serviceDeclarationListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST GALGAS_serviceDeclarationListAST::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                                              const GALGAS_bool & inOperand1,
                                                                                              const GALGAS_lstringlist & inOperand2,
                                                                                              const GALGAS_procFormalArgumentList & inOperand3,
                                                                                              const GALGAS_lstring & inOperand4,
                                                                                              const GALGAS_instructionListAST & inOperand5,
                                                                                              const GALGAS_location & inOperand6
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_serviceDeclarationListAST result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_serviceDeclarationListAST::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_serviceDeclarationListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                  const GALGAS_lstring & in_mServiceName,
                                                                  const GALGAS_bool & in_mPublic,
                                                                  const GALGAS_lstringlist & in_mServiceAttributeList,
                                                                  const GALGAS_procFormalArgumentList & in_mServiceFormalArgumentList,
                                                                  const GALGAS_lstring & in_mReturnTypeName,
                                                                  const GALGAS_instructionListAST & in_mServiceInstructionList,
                                                                  const GALGAS_location & in_mEndOfServiceLocation
                                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_serviceDeclarationListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_serviceDeclarationListAST (in_mServiceName,
                                                               in_mPublic,
                                                               in_mServiceAttributeList,
                                                               in_mServiceFormalArgumentList,
                                                               in_mReturnTypeName,
                                                               in_mServiceInstructionList,
                                                               in_mEndOfServiceLocation COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_serviceDeclarationListAST::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_bool & inOperand1,
                                                            const GALGAS_lstringlist & inOperand2,
                                                            const GALGAS_procFormalArgumentList & inOperand3,
                                                            const GALGAS_lstring & inOperand4,
                                                            const GALGAS_instructionListAST & inOperand5,
                                                            const GALGAS_location & inOperand6
                                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_serviceDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_serviceDeclarationListAST::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                             const GALGAS_bool inOperand1,
                                                             const GALGAS_lstringlist inOperand2,
                                                             const GALGAS_procFormalArgumentList inOperand3,
                                                             const GALGAS_lstring inOperand4,
                                                             const GALGAS_instructionListAST inOperand5,
                                                             const GALGAS_location inOperand6,
                                                             const GALGAS_uint inInsertionIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_serviceDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_serviceDeclarationListAST::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                             GALGAS_bool & outOperand1,
                                                             GALGAS_lstringlist & outOperand2,
                                                             GALGAS_procFormalArgumentList & outOperand3,
                                                             GALGAS_lstring & outOperand4,
                                                             GALGAS_instructionListAST & outOperand5,
                                                             GALGAS_location & outOperand6,
                                                             const GALGAS_uint inRemoveIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_serviceDeclarationListAST * p = (cCollectionElement_serviceDeclarationListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
      outOperand4.drop () ;
      outOperand5.drop () ;
      outOperand6.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
      outOperand0 = p->mObject.mAttribute_mServiceName ;
      outOperand1 = p->mObject.mAttribute_mPublic ;
      outOperand2 = p->mObject.mAttribute_mServiceAttributeList ;
      outOperand3 = p->mObject.mAttribute_mServiceFormalArgumentList ;
      outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
      outOperand5 = p->mObject.mAttribute_mServiceInstructionList ;
      outOperand6 = p->mObject.mAttribute_mEndOfServiceLocation ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_serviceDeclarationListAST::setter_popFirst (GALGAS_lstring & outOperand0,
                                                        GALGAS_bool & outOperand1,
                                                        GALGAS_lstringlist & outOperand2,
                                                        GALGAS_procFormalArgumentList & outOperand3,
                                                        GALGAS_lstring & outOperand4,
                                                        GALGAS_instructionListAST & outOperand5,
                                                        GALGAS_location & outOperand6,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_serviceDeclarationListAST * p = (cCollectionElement_serviceDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mServiceName ;
    outOperand1 = p->mObject.mAttribute_mPublic ;
    outOperand2 = p->mObject.mAttribute_mServiceAttributeList ;
    outOperand3 = p->mObject.mAttribute_mServiceFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand5 = p->mObject.mAttribute_mServiceInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfServiceLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_serviceDeclarationListAST::setter_popLast (GALGAS_lstring & outOperand0,
                                                       GALGAS_bool & outOperand1,
                                                       GALGAS_lstringlist & outOperand2,
                                                       GALGAS_procFormalArgumentList & outOperand3,
                                                       GALGAS_lstring & outOperand4,
                                                       GALGAS_instructionListAST & outOperand5,
                                                       GALGAS_location & outOperand6,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_serviceDeclarationListAST * p = (cCollectionElement_serviceDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mServiceName ;
    outOperand1 = p->mObject.mAttribute_mPublic ;
    outOperand2 = p->mObject.mAttribute_mServiceAttributeList ;
    outOperand3 = p->mObject.mAttribute_mServiceFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand5 = p->mObject.mAttribute_mServiceInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfServiceLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_serviceDeclarationListAST::method_first (GALGAS_lstring & outOperand0,
                                                     GALGAS_bool & outOperand1,
                                                     GALGAS_lstringlist & outOperand2,
                                                     GALGAS_procFormalArgumentList & outOperand3,
                                                     GALGAS_lstring & outOperand4,
                                                     GALGAS_instructionListAST & outOperand5,
                                                     GALGAS_location & outOperand6,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_serviceDeclarationListAST * p = (cCollectionElement_serviceDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mServiceName ;
    outOperand1 = p->mObject.mAttribute_mPublic ;
    outOperand2 = p->mObject.mAttribute_mServiceAttributeList ;
    outOperand3 = p->mObject.mAttribute_mServiceFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand5 = p->mObject.mAttribute_mServiceInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfServiceLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_serviceDeclarationListAST::method_last (GALGAS_lstring & outOperand0,
                                                    GALGAS_bool & outOperand1,
                                                    GALGAS_lstringlist & outOperand2,
                                                    GALGAS_procFormalArgumentList & outOperand3,
                                                    GALGAS_lstring & outOperand4,
                                                    GALGAS_instructionListAST & outOperand5,
                                                    GALGAS_location & outOperand6,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_serviceDeclarationListAST * p = (cCollectionElement_serviceDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mServiceName ;
    outOperand1 = p->mObject.mAttribute_mPublic ;
    outOperand2 = p->mObject.mAttribute_mServiceAttributeList ;
    outOperand3 = p->mObject.mAttribute_mServiceFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand5 = p->mObject.mAttribute_mServiceInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfServiceLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST GALGAS_serviceDeclarationListAST::add_operation (const GALGAS_serviceDeclarationListAST & inOperand,
                                                                                  C_Compiler * /* inCompiler */
                                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_serviceDeclarationListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST GALGAS_serviceDeclarationListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_serviceDeclarationListAST result = GALGAS_serviceDeclarationListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST GALGAS_serviceDeclarationListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_serviceDeclarationListAST result = GALGAS_serviceDeclarationListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST GALGAS_serviceDeclarationListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_serviceDeclarationListAST result = GALGAS_serviceDeclarationListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_serviceDeclarationListAST::plusAssign_operation (const GALGAS_serviceDeclarationListAST inOperand,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_serviceDeclarationListAST::getter_mServiceNameAtIndex (const GALGAS_uint & inIndex,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_serviceDeclarationListAST * p = (cCollectionElement_serviceDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
    result = p->mObject.mAttribute_mServiceName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_serviceDeclarationListAST::getter_mPublicAtIndex (const GALGAS_uint & inIndex,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_serviceDeclarationListAST * p = (cCollectionElement_serviceDeclarationListAST *) attributes.ptr () ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
    result = p->mObject.mAttribute_mPublic ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_serviceDeclarationListAST::getter_mServiceAttributeListAtIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_serviceDeclarationListAST * p = (cCollectionElement_serviceDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstringlist result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
    result = p->mObject.mAttribute_mServiceAttributeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_serviceDeclarationListAST::getter_mServiceFormalArgumentListAtIndex (const GALGAS_uint & inIndex,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_serviceDeclarationListAST * p = (cCollectionElement_serviceDeclarationListAST *) attributes.ptr () ;
  GALGAS_procFormalArgumentList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
    result = p->mObject.mAttribute_mServiceFormalArgumentList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_serviceDeclarationListAST::getter_mReturnTypeNameAtIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_serviceDeclarationListAST * p = (cCollectionElement_serviceDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
    result = p->mObject.mAttribute_mReturnTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_serviceDeclarationListAST::getter_mServiceInstructionListAtIndex (const GALGAS_uint & inIndex,
                                                                                                   C_Compiler * inCompiler
                                                                                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_serviceDeclarationListAST * p = (cCollectionElement_serviceDeclarationListAST *) attributes.ptr () ;
  GALGAS_instructionListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
    result = p->mObject.mAttribute_mServiceInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_serviceDeclarationListAST::getter_mEndOfServiceLocationAtIndex (const GALGAS_uint & inIndex,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_serviceDeclarationListAST * p = (cCollectionElement_serviceDeclarationListAST *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
    result = p->mObject.mAttribute_mEndOfServiceLocation ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_serviceDeclarationListAST::cEnumerator_serviceDeclarationListAST (const GALGAS_serviceDeclarationListAST & inEnumeratedObject,
                                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST_2D_element cEnumerator_serviceDeclarationListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_serviceDeclarationListAST * p = (const cCollectionElement_serviceDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_serviceDeclarationListAST::current_mServiceName (LOCATION_ARGS) const {
  const cCollectionElement_serviceDeclarationListAST * p = (const cCollectionElement_serviceDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
  return p->mObject.mAttribute_mServiceName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_serviceDeclarationListAST::current_mPublic (LOCATION_ARGS) const {
  const cCollectionElement_serviceDeclarationListAST * p = (const cCollectionElement_serviceDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
  return p->mObject.mAttribute_mPublic ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cEnumerator_serviceDeclarationListAST::current_mServiceAttributeList (LOCATION_ARGS) const {
  const cCollectionElement_serviceDeclarationListAST * p = (const cCollectionElement_serviceDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
  return p->mObject.mAttribute_mServiceAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList cEnumerator_serviceDeclarationListAST::current_mServiceFormalArgumentList (LOCATION_ARGS) const {
  const cCollectionElement_serviceDeclarationListAST * p = (const cCollectionElement_serviceDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
  return p->mObject.mAttribute_mServiceFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_serviceDeclarationListAST::current_mReturnTypeName (LOCATION_ARGS) const {
  const cCollectionElement_serviceDeclarationListAST * p = (const cCollectionElement_serviceDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
  return p->mObject.mAttribute_mReturnTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cEnumerator_serviceDeclarationListAST::current_mServiceInstructionList (LOCATION_ARGS) const {
  const cCollectionElement_serviceDeclarationListAST * p = (const cCollectionElement_serviceDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
  return p->mObject.mAttribute_mServiceInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_serviceDeclarationListAST::current_mEndOfServiceLocation (LOCATION_ARGS) const {
  const cCollectionElement_serviceDeclarationListAST * p = (const cCollectionElement_serviceDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_serviceDeclarationListAST) ;
  return p->mObject.mAttribute_mEndOfServiceLocation ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @serviceDeclarationListAST type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_serviceDeclarationListAST ("serviceDeclarationListAST",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_serviceDeclarationListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_serviceDeclarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_serviceDeclarationListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_serviceDeclarationListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST GALGAS_serviceDeclarationListAST::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_serviceDeclarationListAST result ;
  const GALGAS_serviceDeclarationListAST * p = (const GALGAS_serviceDeclarationListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_serviceDeclarationListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("serviceDeclarationListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Class for element of '@primitiveDeclarationListAST' list                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_primitiveDeclarationListAST : public cCollectionElement {
  public : GALGAS_primitiveDeclarationListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_primitiveDeclarationListAST (const GALGAS_lstring & in_mPrimitiveName,
                                                           const GALGAS_bool & in_mPublic,
                                                           const GALGAS_lstringlist & in_mPrimitiveNameAttributeList,
                                                           const GALGAS_procFormalArgumentList & in_mPrimitiveFormalArgumentList,
                                                           const GALGAS_lstring & in_mReturnTypeName,
                                                           const GALGAS_instructionListAST & in_mPrimitiveInstructionList,
                                                           const GALGAS_location & in_mEndOfPrimitiveDeclaration
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

cCollectionElement_primitiveDeclarationListAST::cCollectionElement_primitiveDeclarationListAST (const GALGAS_lstring & in_mPrimitiveName,
                                                                                                const GALGAS_bool & in_mPublic,
                                                                                                const GALGAS_lstringlist & in_mPrimitiveNameAttributeList,
                                                                                                const GALGAS_procFormalArgumentList & in_mPrimitiveFormalArgumentList,
                                                                                                const GALGAS_lstring & in_mReturnTypeName,
                                                                                                const GALGAS_instructionListAST & in_mPrimitiveInstructionList,
                                                                                                const GALGAS_location & in_mEndOfPrimitiveDeclaration
                                                                                                COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mPrimitiveName, in_mPublic, in_mPrimitiveNameAttributeList, in_mPrimitiveFormalArgumentList, in_mReturnTypeName, in_mPrimitiveInstructionList, in_mEndOfPrimitiveDeclaration) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_primitiveDeclarationListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_primitiveDeclarationListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_primitiveDeclarationListAST (mObject.mAttribute_mPrimitiveName, mObject.mAttribute_mPublic, mObject.mAttribute_mPrimitiveNameAttributeList, mObject.mAttribute_mPrimitiveFormalArgumentList, mObject.mAttribute_mReturnTypeName, mObject.mAttribute_mPrimitiveInstructionList, mObject.mAttribute_mEndOfPrimitiveDeclaration COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_primitiveDeclarationListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPrimitiveName" ":" ;
  mObject.mAttribute_mPrimitiveName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPublic" ":" ;
  mObject.mAttribute_mPublic.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPrimitiveNameAttributeList" ":" ;
  mObject.mAttribute_mPrimitiveNameAttributeList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPrimitiveFormalArgumentList" ":" ;
  mObject.mAttribute_mPrimitiveFormalArgumentList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mReturnTypeName" ":" ;
  mObject.mAttribute_mReturnTypeName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPrimitiveInstructionList" ":" ;
  mObject.mAttribute_mPrimitiveInstructionList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEndOfPrimitiveDeclaration" ":" ;
  mObject.mAttribute_mEndOfPrimitiveDeclaration.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_primitiveDeclarationListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_primitiveDeclarationListAST * operand = (cCollectionElement_primitiveDeclarationListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_primitiveDeclarationListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST::GALGAS_primitiveDeclarationListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST::GALGAS_primitiveDeclarationListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST GALGAS_primitiveDeclarationListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_primitiveDeclarationListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST GALGAS_primitiveDeclarationListAST::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                                                  const GALGAS_bool & inOperand1,
                                                                                                  const GALGAS_lstringlist & inOperand2,
                                                                                                  const GALGAS_procFormalArgumentList & inOperand3,
                                                                                                  const GALGAS_lstring & inOperand4,
                                                                                                  const GALGAS_instructionListAST & inOperand5,
                                                                                                  const GALGAS_location & inOperand6
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_primitiveDeclarationListAST result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_primitiveDeclarationListAST::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primitiveDeclarationListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                    const GALGAS_lstring & in_mPrimitiveName,
                                                                    const GALGAS_bool & in_mPublic,
                                                                    const GALGAS_lstringlist & in_mPrimitiveNameAttributeList,
                                                                    const GALGAS_procFormalArgumentList & in_mPrimitiveFormalArgumentList,
                                                                    const GALGAS_lstring & in_mReturnTypeName,
                                                                    const GALGAS_instructionListAST & in_mPrimitiveInstructionList,
                                                                    const GALGAS_location & in_mEndOfPrimitiveDeclaration
                                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_primitiveDeclarationListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_primitiveDeclarationListAST (in_mPrimitiveName,
                                                                 in_mPublic,
                                                                 in_mPrimitiveNameAttributeList,
                                                                 in_mPrimitiveFormalArgumentList,
                                                                 in_mReturnTypeName,
                                                                 in_mPrimitiveInstructionList,
                                                                 in_mEndOfPrimitiveDeclaration COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primitiveDeclarationListAST::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                              const GALGAS_bool & inOperand1,
                                                              const GALGAS_lstringlist & inOperand2,
                                                              const GALGAS_procFormalArgumentList & inOperand3,
                                                              const GALGAS_lstring & inOperand4,
                                                              const GALGAS_instructionListAST & inOperand5,
                                                              const GALGAS_location & inOperand6
                                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_primitiveDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primitiveDeclarationListAST::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                               const GALGAS_bool inOperand1,
                                                               const GALGAS_lstringlist inOperand2,
                                                               const GALGAS_procFormalArgumentList inOperand3,
                                                               const GALGAS_lstring inOperand4,
                                                               const GALGAS_instructionListAST inOperand5,
                                                               const GALGAS_location inOperand6,
                                                               const GALGAS_uint inInsertionIndex,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_primitiveDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primitiveDeclarationListAST::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                               GALGAS_bool & outOperand1,
                                                               GALGAS_lstringlist & outOperand2,
                                                               GALGAS_procFormalArgumentList & outOperand3,
                                                               GALGAS_lstring & outOperand4,
                                                               GALGAS_instructionListAST & outOperand5,
                                                               GALGAS_location & outOperand6,
                                                               const GALGAS_uint inRemoveIndex,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_primitiveDeclarationListAST * p = (cCollectionElement_primitiveDeclarationListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
      outOperand4.drop () ;
      outOperand5.drop () ;
      outOperand6.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
      outOperand0 = p->mObject.mAttribute_mPrimitiveName ;
      outOperand1 = p->mObject.mAttribute_mPublic ;
      outOperand2 = p->mObject.mAttribute_mPrimitiveNameAttributeList ;
      outOperand3 = p->mObject.mAttribute_mPrimitiveFormalArgumentList ;
      outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
      outOperand5 = p->mObject.mAttribute_mPrimitiveInstructionList ;
      outOperand6 = p->mObject.mAttribute_mEndOfPrimitiveDeclaration ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primitiveDeclarationListAST::setter_popFirst (GALGAS_lstring & outOperand0,
                                                          GALGAS_bool & outOperand1,
                                                          GALGAS_lstringlist & outOperand2,
                                                          GALGAS_procFormalArgumentList & outOperand3,
                                                          GALGAS_lstring & outOperand4,
                                                          GALGAS_instructionListAST & outOperand5,
                                                          GALGAS_location & outOperand6,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_primitiveDeclarationListAST * p = (cCollectionElement_primitiveDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mPrimitiveName ;
    outOperand1 = p->mObject.mAttribute_mPublic ;
    outOperand2 = p->mObject.mAttribute_mPrimitiveNameAttributeList ;
    outOperand3 = p->mObject.mAttribute_mPrimitiveFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand5 = p->mObject.mAttribute_mPrimitiveInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfPrimitiveDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primitiveDeclarationListAST::setter_popLast (GALGAS_lstring & outOperand0,
                                                         GALGAS_bool & outOperand1,
                                                         GALGAS_lstringlist & outOperand2,
                                                         GALGAS_procFormalArgumentList & outOperand3,
                                                         GALGAS_lstring & outOperand4,
                                                         GALGAS_instructionListAST & outOperand5,
                                                         GALGAS_location & outOperand6,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_primitiveDeclarationListAST * p = (cCollectionElement_primitiveDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mPrimitiveName ;
    outOperand1 = p->mObject.mAttribute_mPublic ;
    outOperand2 = p->mObject.mAttribute_mPrimitiveNameAttributeList ;
    outOperand3 = p->mObject.mAttribute_mPrimitiveFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand5 = p->mObject.mAttribute_mPrimitiveInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfPrimitiveDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primitiveDeclarationListAST::method_first (GALGAS_lstring & outOperand0,
                                                       GALGAS_bool & outOperand1,
                                                       GALGAS_lstringlist & outOperand2,
                                                       GALGAS_procFormalArgumentList & outOperand3,
                                                       GALGAS_lstring & outOperand4,
                                                       GALGAS_instructionListAST & outOperand5,
                                                       GALGAS_location & outOperand6,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_primitiveDeclarationListAST * p = (cCollectionElement_primitiveDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mPrimitiveName ;
    outOperand1 = p->mObject.mAttribute_mPublic ;
    outOperand2 = p->mObject.mAttribute_mPrimitiveNameAttributeList ;
    outOperand3 = p->mObject.mAttribute_mPrimitiveFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand5 = p->mObject.mAttribute_mPrimitiveInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfPrimitiveDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primitiveDeclarationListAST::method_last (GALGAS_lstring & outOperand0,
                                                      GALGAS_bool & outOperand1,
                                                      GALGAS_lstringlist & outOperand2,
                                                      GALGAS_procFormalArgumentList & outOperand3,
                                                      GALGAS_lstring & outOperand4,
                                                      GALGAS_instructionListAST & outOperand5,
                                                      GALGAS_location & outOperand6,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_primitiveDeclarationListAST * p = (cCollectionElement_primitiveDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mPrimitiveName ;
    outOperand1 = p->mObject.mAttribute_mPublic ;
    outOperand2 = p->mObject.mAttribute_mPrimitiveNameAttributeList ;
    outOperand3 = p->mObject.mAttribute_mPrimitiveFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mReturnTypeName ;
    outOperand5 = p->mObject.mAttribute_mPrimitiveInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfPrimitiveDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST GALGAS_primitiveDeclarationListAST::add_operation (const GALGAS_primitiveDeclarationListAST & inOperand,
                                                                                      C_Compiler * /* inCompiler */
                                                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_primitiveDeclarationListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST GALGAS_primitiveDeclarationListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_primitiveDeclarationListAST result = GALGAS_primitiveDeclarationListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST GALGAS_primitiveDeclarationListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_primitiveDeclarationListAST result = GALGAS_primitiveDeclarationListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST GALGAS_primitiveDeclarationListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_primitiveDeclarationListAST result = GALGAS_primitiveDeclarationListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primitiveDeclarationListAST::plusAssign_operation (const GALGAS_primitiveDeclarationListAST inOperand,
                                                               C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_primitiveDeclarationListAST::getter_mPrimitiveNameAtIndex (const GALGAS_uint & inIndex,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_primitiveDeclarationListAST * p = (cCollectionElement_primitiveDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
    result = p->mObject.mAttribute_mPrimitiveName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_primitiveDeclarationListAST::getter_mPublicAtIndex (const GALGAS_uint & inIndex,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_primitiveDeclarationListAST * p = (cCollectionElement_primitiveDeclarationListAST *) attributes.ptr () ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
    result = p->mObject.mAttribute_mPublic ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_primitiveDeclarationListAST::getter_mPrimitiveNameAttributeListAtIndex (const GALGAS_uint & inIndex,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_primitiveDeclarationListAST * p = (cCollectionElement_primitiveDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstringlist result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
    result = p->mObject.mAttribute_mPrimitiveNameAttributeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_primitiveDeclarationListAST::getter_mPrimitiveFormalArgumentListAtIndex (const GALGAS_uint & inIndex,
                                                                                                              C_Compiler * inCompiler
                                                                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_primitiveDeclarationListAST * p = (cCollectionElement_primitiveDeclarationListAST *) attributes.ptr () ;
  GALGAS_procFormalArgumentList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
    result = p->mObject.mAttribute_mPrimitiveFormalArgumentList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_primitiveDeclarationListAST::getter_mReturnTypeNameAtIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_primitiveDeclarationListAST * p = (cCollectionElement_primitiveDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
    result = p->mObject.mAttribute_mReturnTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_primitiveDeclarationListAST::getter_mPrimitiveInstructionListAtIndex (const GALGAS_uint & inIndex,
                                                                                                       C_Compiler * inCompiler
                                                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_primitiveDeclarationListAST * p = (cCollectionElement_primitiveDeclarationListAST *) attributes.ptr () ;
  GALGAS_instructionListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
    result = p->mObject.mAttribute_mPrimitiveInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_primitiveDeclarationListAST::getter_mEndOfPrimitiveDeclarationAtIndex (const GALGAS_uint & inIndex,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_primitiveDeclarationListAST * p = (cCollectionElement_primitiveDeclarationListAST *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
    result = p->mObject.mAttribute_mEndOfPrimitiveDeclaration ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_primitiveDeclarationListAST::cEnumerator_primitiveDeclarationListAST (const GALGAS_primitiveDeclarationListAST & inEnumeratedObject,
                                                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST_2D_element cEnumerator_primitiveDeclarationListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_primitiveDeclarationListAST * p = (const cCollectionElement_primitiveDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_primitiveDeclarationListAST::current_mPrimitiveName (LOCATION_ARGS) const {
  const cCollectionElement_primitiveDeclarationListAST * p = (const cCollectionElement_primitiveDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
  return p->mObject.mAttribute_mPrimitiveName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_primitiveDeclarationListAST::current_mPublic (LOCATION_ARGS) const {
  const cCollectionElement_primitiveDeclarationListAST * p = (const cCollectionElement_primitiveDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
  return p->mObject.mAttribute_mPublic ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cEnumerator_primitiveDeclarationListAST::current_mPrimitiveNameAttributeList (LOCATION_ARGS) const {
  const cCollectionElement_primitiveDeclarationListAST * p = (const cCollectionElement_primitiveDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
  return p->mObject.mAttribute_mPrimitiveNameAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList cEnumerator_primitiveDeclarationListAST::current_mPrimitiveFormalArgumentList (LOCATION_ARGS) const {
  const cCollectionElement_primitiveDeclarationListAST * p = (const cCollectionElement_primitiveDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
  return p->mObject.mAttribute_mPrimitiveFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_primitiveDeclarationListAST::current_mReturnTypeName (LOCATION_ARGS) const {
  const cCollectionElement_primitiveDeclarationListAST * p = (const cCollectionElement_primitiveDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
  return p->mObject.mAttribute_mReturnTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cEnumerator_primitiveDeclarationListAST::current_mPrimitiveInstructionList (LOCATION_ARGS) const {
  const cCollectionElement_primitiveDeclarationListAST * p = (const cCollectionElement_primitiveDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
  return p->mObject.mAttribute_mPrimitiveInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_primitiveDeclarationListAST::current_mEndOfPrimitiveDeclaration (LOCATION_ARGS) const {
  const cCollectionElement_primitiveDeclarationListAST * p = (const cCollectionElement_primitiveDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_primitiveDeclarationListAST) ;
  return p->mObject.mAttribute_mEndOfPrimitiveDeclaration ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @primitiveDeclarationListAST type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_primitiveDeclarationListAST ("primitiveDeclarationListAST",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_primitiveDeclarationListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_primitiveDeclarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_primitiveDeclarationListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_primitiveDeclarationListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST GALGAS_primitiveDeclarationListAST::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_primitiveDeclarationListAST result ;
  const GALGAS_primitiveDeclarationListAST * p = (const GALGAS_primitiveDeclarationListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_primitiveDeclarationListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("primitiveDeclarationListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Class for element of '@guardDeclarationListAST' list                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_guardDeclarationListAST : public cCollectionElement {
  public : GALGAS_guardDeclarationListAST_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_guardDeclarationListAST (const GALGAS_lstring & in_mGuardName,
                                                       const GALGAS_bool & in_mIsPublic,
                                                       const GALGAS_lstringlist & in_mGuardAttributeList,
                                                       const GALGAS_procFormalArgumentList & in_mGuardFormalArgumentList,
                                                       const GALGAS_guardKind & in_mGuardKind,
                                                       const GALGAS_instructionListAST & in_mGuardInstructionList,
                                                       const GALGAS_location & in_mEndOfGuardDeclaration
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

cCollectionElement_guardDeclarationListAST::cCollectionElement_guardDeclarationListAST (const GALGAS_lstring & in_mGuardName,
                                                                                        const GALGAS_bool & in_mIsPublic,
                                                                                        const GALGAS_lstringlist & in_mGuardAttributeList,
                                                                                        const GALGAS_procFormalArgumentList & in_mGuardFormalArgumentList,
                                                                                        const GALGAS_guardKind & in_mGuardKind,
                                                                                        const GALGAS_instructionListAST & in_mGuardInstructionList,
                                                                                        const GALGAS_location & in_mEndOfGuardDeclaration
                                                                                        COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mGuardName, in_mIsPublic, in_mGuardAttributeList, in_mGuardFormalArgumentList, in_mGuardKind, in_mGuardInstructionList, in_mEndOfGuardDeclaration) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_guardDeclarationListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_guardDeclarationListAST::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_guardDeclarationListAST (mObject.mAttribute_mGuardName, mObject.mAttribute_mIsPublic, mObject.mAttribute_mGuardAttributeList, mObject.mAttribute_mGuardFormalArgumentList, mObject.mAttribute_mGuardKind, mObject.mAttribute_mGuardInstructionList, mObject.mAttribute_mEndOfGuardDeclaration COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_guardDeclarationListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGuardName" ":" ;
  mObject.mAttribute_mGuardName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mIsPublic" ":" ;
  mObject.mAttribute_mIsPublic.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGuardAttributeList" ":" ;
  mObject.mAttribute_mGuardAttributeList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGuardFormalArgumentList" ":" ;
  mObject.mAttribute_mGuardFormalArgumentList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGuardKind" ":" ;
  mObject.mAttribute_mGuardKind.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGuardInstructionList" ":" ;
  mObject.mAttribute_mGuardInstructionList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEndOfGuardDeclaration" ":" ;
  mObject.mAttribute_mEndOfGuardDeclaration.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_guardDeclarationListAST::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_guardDeclarationListAST * operand = (cCollectionElement_guardDeclarationListAST *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_guardDeclarationListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST::GALGAS_guardDeclarationListAST (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST::GALGAS_guardDeclarationListAST (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST GALGAS_guardDeclarationListAST::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_guardDeclarationListAST result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST GALGAS_guardDeclarationListAST::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_bool & inOperand1,
                                                                                          const GALGAS_lstringlist & inOperand2,
                                                                                          const GALGAS_procFormalArgumentList & inOperand3,
                                                                                          const GALGAS_guardKind & inOperand4,
                                                                                          const GALGAS_instructionListAST & inOperand5,
                                                                                          const GALGAS_location & inOperand6
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_guardDeclarationListAST result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_guardDeclarationListAST::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardDeclarationListAST::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                const GALGAS_lstring & in_mGuardName,
                                                                const GALGAS_bool & in_mIsPublic,
                                                                const GALGAS_lstringlist & in_mGuardAttributeList,
                                                                const GALGAS_procFormalArgumentList & in_mGuardFormalArgumentList,
                                                                const GALGAS_guardKind & in_mGuardKind,
                                                                const GALGAS_instructionListAST & in_mGuardInstructionList,
                                                                const GALGAS_location & in_mEndOfGuardDeclaration
                                                                COMMA_LOCATION_ARGS) {
  cCollectionElement_guardDeclarationListAST * p = NULL ;
  macroMyNew (p, cCollectionElement_guardDeclarationListAST (in_mGuardName,
                                                             in_mIsPublic,
                                                             in_mGuardAttributeList,
                                                             in_mGuardFormalArgumentList,
                                                             in_mGuardKind,
                                                             in_mGuardInstructionList,
                                                             in_mEndOfGuardDeclaration COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardDeclarationListAST::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                          const GALGAS_bool & inOperand1,
                                                          const GALGAS_lstringlist & inOperand2,
                                                          const GALGAS_procFormalArgumentList & inOperand3,
                                                          const GALGAS_guardKind & inOperand4,
                                                          const GALGAS_instructionListAST & inOperand5,
                                                          const GALGAS_location & inOperand6
                                                          COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_guardDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardDeclarationListAST::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                           const GALGAS_bool inOperand1,
                                                           const GALGAS_lstringlist inOperand2,
                                                           const GALGAS_procFormalArgumentList inOperand3,
                                                           const GALGAS_guardKind inOperand4,
                                                           const GALGAS_instructionListAST inOperand5,
                                                           const GALGAS_location inOperand6,
                                                           const GALGAS_uint inInsertionIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_guardDeclarationListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardDeclarationListAST::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                           GALGAS_bool & outOperand1,
                                                           GALGAS_lstringlist & outOperand2,
                                                           GALGAS_procFormalArgumentList & outOperand3,
                                                           GALGAS_guardKind & outOperand4,
                                                           GALGAS_instructionListAST & outOperand5,
                                                           GALGAS_location & outOperand6,
                                                           const GALGAS_uint inRemoveIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_guardDeclarationListAST * p = (cCollectionElement_guardDeclarationListAST *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
      outOperand4.drop () ;
      outOperand5.drop () ;
      outOperand6.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
      outOperand0 = p->mObject.mAttribute_mGuardName ;
      outOperand1 = p->mObject.mAttribute_mIsPublic ;
      outOperand2 = p->mObject.mAttribute_mGuardAttributeList ;
      outOperand3 = p->mObject.mAttribute_mGuardFormalArgumentList ;
      outOperand4 = p->mObject.mAttribute_mGuardKind ;
      outOperand5 = p->mObject.mAttribute_mGuardInstructionList ;
      outOperand6 = p->mObject.mAttribute_mEndOfGuardDeclaration ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardDeclarationListAST::setter_popFirst (GALGAS_lstring & outOperand0,
                                                      GALGAS_bool & outOperand1,
                                                      GALGAS_lstringlist & outOperand2,
                                                      GALGAS_procFormalArgumentList & outOperand3,
                                                      GALGAS_guardKind & outOperand4,
                                                      GALGAS_instructionListAST & outOperand5,
                                                      GALGAS_location & outOperand6,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_guardDeclarationListAST * p = (cCollectionElement_guardDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mGuardName ;
    outOperand1 = p->mObject.mAttribute_mIsPublic ;
    outOperand2 = p->mObject.mAttribute_mGuardAttributeList ;
    outOperand3 = p->mObject.mAttribute_mGuardFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mGuardKind ;
    outOperand5 = p->mObject.mAttribute_mGuardInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfGuardDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardDeclarationListAST::setter_popLast (GALGAS_lstring & outOperand0,
                                                     GALGAS_bool & outOperand1,
                                                     GALGAS_lstringlist & outOperand2,
                                                     GALGAS_procFormalArgumentList & outOperand3,
                                                     GALGAS_guardKind & outOperand4,
                                                     GALGAS_instructionListAST & outOperand5,
                                                     GALGAS_location & outOperand6,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_guardDeclarationListAST * p = (cCollectionElement_guardDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mGuardName ;
    outOperand1 = p->mObject.mAttribute_mIsPublic ;
    outOperand2 = p->mObject.mAttribute_mGuardAttributeList ;
    outOperand3 = p->mObject.mAttribute_mGuardFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mGuardKind ;
    outOperand5 = p->mObject.mAttribute_mGuardInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfGuardDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardDeclarationListAST::method_first (GALGAS_lstring & outOperand0,
                                                   GALGAS_bool & outOperand1,
                                                   GALGAS_lstringlist & outOperand2,
                                                   GALGAS_procFormalArgumentList & outOperand3,
                                                   GALGAS_guardKind & outOperand4,
                                                   GALGAS_instructionListAST & outOperand5,
                                                   GALGAS_location & outOperand6,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_guardDeclarationListAST * p = (cCollectionElement_guardDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mGuardName ;
    outOperand1 = p->mObject.mAttribute_mIsPublic ;
    outOperand2 = p->mObject.mAttribute_mGuardAttributeList ;
    outOperand3 = p->mObject.mAttribute_mGuardFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mGuardKind ;
    outOperand5 = p->mObject.mAttribute_mGuardInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfGuardDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardDeclarationListAST::method_last (GALGAS_lstring & outOperand0,
                                                  GALGAS_bool & outOperand1,
                                                  GALGAS_lstringlist & outOperand2,
                                                  GALGAS_procFormalArgumentList & outOperand3,
                                                  GALGAS_guardKind & outOperand4,
                                                  GALGAS_instructionListAST & outOperand5,
                                                  GALGAS_location & outOperand6,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_guardDeclarationListAST * p = (cCollectionElement_guardDeclarationListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
    outOperand0 = p->mObject.mAttribute_mGuardName ;
    outOperand1 = p->mObject.mAttribute_mIsPublic ;
    outOperand2 = p->mObject.mAttribute_mGuardAttributeList ;
    outOperand3 = p->mObject.mAttribute_mGuardFormalArgumentList ;
    outOperand4 = p->mObject.mAttribute_mGuardKind ;
    outOperand5 = p->mObject.mAttribute_mGuardInstructionList ;
    outOperand6 = p->mObject.mAttribute_mEndOfGuardDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST GALGAS_guardDeclarationListAST::add_operation (const GALGAS_guardDeclarationListAST & inOperand,
                                                                              C_Compiler * /* inCompiler */
                                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_guardDeclarationListAST result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST GALGAS_guardDeclarationListAST::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_guardDeclarationListAST result = GALGAS_guardDeclarationListAST::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST GALGAS_guardDeclarationListAST::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_guardDeclarationListAST result = GALGAS_guardDeclarationListAST::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST GALGAS_guardDeclarationListAST::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_guardDeclarationListAST result = GALGAS_guardDeclarationListAST::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardDeclarationListAST::plusAssign_operation (const GALGAS_guardDeclarationListAST inOperand,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_guardDeclarationListAST::getter_mGuardNameAtIndex (const GALGAS_uint & inIndex,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_guardDeclarationListAST * p = (cCollectionElement_guardDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
    result = p->mObject.mAttribute_mGuardName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_guardDeclarationListAST::getter_mIsPublicAtIndex (const GALGAS_uint & inIndex,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_guardDeclarationListAST * p = (cCollectionElement_guardDeclarationListAST *) attributes.ptr () ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
    result = p->mObject.mAttribute_mIsPublic ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_guardDeclarationListAST::getter_mGuardAttributeListAtIndex (const GALGAS_uint & inIndex,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_guardDeclarationListAST * p = (cCollectionElement_guardDeclarationListAST *) attributes.ptr () ;
  GALGAS_lstringlist result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
    result = p->mObject.mAttribute_mGuardAttributeList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_guardDeclarationListAST::getter_mGuardFormalArgumentListAtIndex (const GALGAS_uint & inIndex,
                                                                                                      C_Compiler * inCompiler
                                                                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_guardDeclarationListAST * p = (cCollectionElement_guardDeclarationListAST *) attributes.ptr () ;
  GALGAS_procFormalArgumentList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
    result = p->mObject.mAttribute_mGuardFormalArgumentList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardKind GALGAS_guardDeclarationListAST::getter_mGuardKindAtIndex (const GALGAS_uint & inIndex,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_guardDeclarationListAST * p = (cCollectionElement_guardDeclarationListAST *) attributes.ptr () ;
  GALGAS_guardKind result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
    result = p->mObject.mAttribute_mGuardKind ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_guardDeclarationListAST::getter_mGuardInstructionListAtIndex (const GALGAS_uint & inIndex,
                                                                                               C_Compiler * inCompiler
                                                                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_guardDeclarationListAST * p = (cCollectionElement_guardDeclarationListAST *) attributes.ptr () ;
  GALGAS_instructionListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
    result = p->mObject.mAttribute_mGuardInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_guardDeclarationListAST::getter_mEndOfGuardDeclarationAtIndex (const GALGAS_uint & inIndex,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_guardDeclarationListAST * p = (cCollectionElement_guardDeclarationListAST *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
    result = p->mObject.mAttribute_mEndOfGuardDeclaration ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_guardDeclarationListAST::cEnumerator_guardDeclarationListAST (const GALGAS_guardDeclarationListAST & inEnumeratedObject,
                                                                          const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST_2D_element cEnumerator_guardDeclarationListAST::current (LOCATION_ARGS) const {
  const cCollectionElement_guardDeclarationListAST * p = (const cCollectionElement_guardDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_guardDeclarationListAST::current_mGuardName (LOCATION_ARGS) const {
  const cCollectionElement_guardDeclarationListAST * p = (const cCollectionElement_guardDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
  return p->mObject.mAttribute_mGuardName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_guardDeclarationListAST::current_mIsPublic (LOCATION_ARGS) const {
  const cCollectionElement_guardDeclarationListAST * p = (const cCollectionElement_guardDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
  return p->mObject.mAttribute_mIsPublic ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cEnumerator_guardDeclarationListAST::current_mGuardAttributeList (LOCATION_ARGS) const {
  const cCollectionElement_guardDeclarationListAST * p = (const cCollectionElement_guardDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
  return p->mObject.mAttribute_mGuardAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList cEnumerator_guardDeclarationListAST::current_mGuardFormalArgumentList (LOCATION_ARGS) const {
  const cCollectionElement_guardDeclarationListAST * p = (const cCollectionElement_guardDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
  return p->mObject.mAttribute_mGuardFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardKind cEnumerator_guardDeclarationListAST::current_mGuardKind (LOCATION_ARGS) const {
  const cCollectionElement_guardDeclarationListAST * p = (const cCollectionElement_guardDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
  return p->mObject.mAttribute_mGuardKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cEnumerator_guardDeclarationListAST::current_mGuardInstructionList (LOCATION_ARGS) const {
  const cCollectionElement_guardDeclarationListAST * p = (const cCollectionElement_guardDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
  return p->mObject.mAttribute_mGuardInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_guardDeclarationListAST::current_mEndOfGuardDeclaration (LOCATION_ARGS) const {
  const cCollectionElement_guardDeclarationListAST * p = (const cCollectionElement_guardDeclarationListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_guardDeclarationListAST) ;
  return p->mObject.mAttribute_mEndOfGuardDeclaration ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @guardDeclarationListAST type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_guardDeclarationListAST ("guardDeclarationListAST",
                                                NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_guardDeclarationListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_guardDeclarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_guardDeclarationListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_guardDeclarationListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST GALGAS_guardDeclarationListAST::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_guardDeclarationListAST result ;
  const GALGAS_guardDeclarationListAST * p = (const GALGAS_guardDeclarationListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_guardDeclarationListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("guardDeclarationListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@bootList' sorted list                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cSortedListElement_bootList : public cSortedListElement {
  public : GALGAS_bootList_2D_element mObject ;

//--- Constructor
  public : cSortedListElement_bootList (const GALGAS_location & in_mBootLocation,
                                        const GALGAS_instructionListAST & in_mInstructionList,
                                        const GALGAS_location & in_mEndOfBootLocation,
                                        const GALGAS_bigint & in_mPriority,
                                        const GALGAS_location & in_mPriorityLocation
                                        COMMA_LOCATION_ARGS) ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cSortedListElement * copy (void) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;

//--- Virtual method that comparing element for sorting
  public : virtual typeComparisonResult compareForSorting (const cSortedListElement * inOperand) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cSortedListElement_bootList::cSortedListElement_bootList (const GALGAS_location & in_mBootLocation,
                                                          const GALGAS_instructionListAST & in_mInstructionList,
                                                          const GALGAS_location & in_mEndOfBootLocation,
                                                          const GALGAS_bigint & in_mPriority,
                                                          const GALGAS_location & in_mPriorityLocation
                                                          COMMA_LOCATION_ARGS) :
cSortedListElement (THERE),
mObject (in_mBootLocation, in_mInstructionList, in_mEndOfBootLocation, in_mPriority, in_mPriorityLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cSortedListElement_bootList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cSortedListElement * cSortedListElement_bootList::copy (void) {
  cSortedListElement * result = NULL ;
  macroMyNew (result, cSortedListElement_bootList (mObject.mAttribute_mBootLocation, mObject.mAttribute_mInstructionList, mObject.mAttribute_mEndOfBootLocation, mObject.mAttribute_mPriority, mObject.mAttribute_mPriorityLocation COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cSortedListElement_bootList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mBootLocation" ":" ;
  mObject.mAttribute_mBootLocation.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mInstructionList" ":" ;
  mObject.mAttribute_mInstructionList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEndOfBootLocation" ":" ;
  mObject.mAttribute_mEndOfBootLocation.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPriority" ":" ;
  mObject.mAttribute_mPriority.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPriorityLocation" ":" ;
  mObject.mAttribute_mPriorityLocation.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cSortedListElement_bootList::compare (const cCollectionElement * inOperand) const {
  cSortedListElement_bootList * operand = (cSortedListElement_bootList *) inOperand ;
  macroValidSharedObject (operand, cSortedListElement_bootList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootList::GALGAS_bootList (void) :
AC_GALGAS_sortedlist () {
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cSortedListElement_bootList::compareForSorting (const cSortedListElement * inOperand) const {
  typeComparisonResult result = kOperandEqual ;
  const cSortedListElement_bootList * operand = (const cSortedListElement_bootList *) inOperand ;
  macroValidSharedObject (operand, cSortedListElement_bootList) ;
  if (result == kOperandEqual) {
    result = mObject.mAttribute_mPriority.objectCompare (operand->mObject.mAttribute_mPriority) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootList GALGAS_bootList::constructor_emptySortedList (LOCATION_ARGS) {
  GALGAS_bootList result ;
  result.createNewEmptySortedList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootList GALGAS_bootList::constructor_sortedListWithValue (const GALGAS_location & inOperand0,
                                                                  const GALGAS_instructionListAST & inOperand1,
                                                                  const GALGAS_location & inOperand2,
                                                                  const GALGAS_bigint & inOperand3,
                                                                  const GALGAS_location & inOperand4
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_bootList result = constructor_emptySortedList (THERE) ;
  cSortedListElement * p = NULL ;
  macroMyNew (p, cSortedListElement_bootList (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4 COMMA_THERE)) ;
  capSortedListElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  result.addObject (attributes) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_bootList::addAssign_operation (const GALGAS_location & inOperand0,
                                           const GALGAS_instructionListAST & inOperand1,
                                           const GALGAS_location & inOperand2,
                                           const GALGAS_bigint & inOperand3,
                                           const GALGAS_location & inOperand4
                                           COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cSortedListElement * p = NULL ;
    macroMyNew (p, cSortedListElement_bootList (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4 COMMA_THERE)) ;
    capSortedListElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_bootList::plusAssign_operation (const GALGAS_bootList inOperand,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid ()) {
    appendSortedList (inOperand) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_bootList::setter_popSmallest (GALGAS_location & outOperand0,
                                          GALGAS_instructionListAST & outOperand1,
                                          GALGAS_location & outOperand2,
                                          GALGAS_bigint & outOperand3,
                                          GALGAS_location & outOperand4,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  capSortedListElement attributes ;
  removeSmallestObject (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_bootList * p = (cSortedListElement_bootList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_bootList) ;
    outOperand0 = p->mObject.mAttribute_mBootLocation ;
    outOperand1 = p->mObject.mAttribute_mInstructionList ;
    outOperand2 = p->mObject.mAttribute_mEndOfBootLocation ;
    outOperand3 = p->mObject.mAttribute_mPriority ;
    outOperand4 = p->mObject.mAttribute_mPriorityLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_bootList::setter_popGreatest (GALGAS_location & outOperand0,
                                          GALGAS_instructionListAST & outOperand1,
                                          GALGAS_location & outOperand2,
                                          GALGAS_bigint & outOperand3,
                                          GALGAS_location & outOperand4,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  capSortedListElement attributes ;
  removeGreatestObject (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_bootList * p = (cSortedListElement_bootList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_bootList) ;
    outOperand0 = p->mObject.mAttribute_mBootLocation ;
    outOperand1 = p->mObject.mAttribute_mInstructionList ;
    outOperand2 = p->mObject.mAttribute_mEndOfBootLocation ;
    outOperand3 = p->mObject.mAttribute_mPriority ;
    outOperand4 = p->mObject.mAttribute_mPriorityLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_bootList::method_smallest (GALGAS_location & outOperand0,
                                       GALGAS_instructionListAST & outOperand1,
                                       GALGAS_location & outOperand2,
                                       GALGAS_bigint & outOperand3,
                                       GALGAS_location & outOperand4,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  capSortedListElement attributes ;
  smallestObjectAttributeList (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_bootList * p = (cSortedListElement_bootList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_bootList) ;
    outOperand0 = p->mObject.mAttribute_mBootLocation ;
    outOperand1 = p->mObject.mAttribute_mInstructionList ;
    outOperand2 = p->mObject.mAttribute_mEndOfBootLocation ;
    outOperand3 = p->mObject.mAttribute_mPriority ;
    outOperand4 = p->mObject.mAttribute_mPriorityLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_bootList::method_greatest (GALGAS_location & outOperand0,
                                       GALGAS_instructionListAST & outOperand1,
                                       GALGAS_location & outOperand2,
                                       GALGAS_bigint & outOperand3,
                                       GALGAS_location & outOperand4,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  capSortedListElement attributes ;
  greatestObjectAttributeList (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_bootList * p = (cSortedListElement_bootList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_bootList) ;
    outOperand0 = p->mObject.mAttribute_mBootLocation ;
    outOperand1 = p->mObject.mAttribute_mInstructionList ;
    outOperand2 = p->mObject.mAttribute_mEndOfBootLocation ;
    outOperand3 = p->mObject.mAttribute_mPriority ;
    outOperand4 = p->mObject.mAttribute_mPriorityLocation ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_bootList::cEnumerator_bootList (const GALGAS_bootList & inEnumeratedObject,
                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootList_2D_element cEnumerator_bootList::current (LOCATION_ARGS) const {
  const cSortedListElement_bootList * p = (const cSortedListElement_bootList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_bootList) ;
  return p->mObject ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_bootList::current_mBootLocation (LOCATION_ARGS) const {
  const cSortedListElement_bootList * p = (const cSortedListElement_bootList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_bootList) ;
  return p->mObject.mAttribute_mBootLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cEnumerator_bootList::current_mInstructionList (LOCATION_ARGS) const {
  const cSortedListElement_bootList * p = (const cSortedListElement_bootList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_bootList) ;
  return p->mObject.mAttribute_mInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_bootList::current_mEndOfBootLocation (LOCATION_ARGS) const {
  const cSortedListElement_bootList * p = (const cSortedListElement_bootList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_bootList) ;
  return p->mObject.mAttribute_mEndOfBootLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cEnumerator_bootList::current_mPriority (LOCATION_ARGS) const {
  const cSortedListElement_bootList * p = (const cSortedListElement_bootList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_bootList) ;
  return p->mObject.mAttribute_mPriority ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_bootList::current_mPriorityLocation (LOCATION_ARGS) const {
  const cSortedListElement_bootList * p = (const cSortedListElement_bootList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_bootList) ;
  return p->mObject.mAttribute_mPriorityLocation ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @bootList type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_bootList ("bootList",
                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_bootList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bootList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_bootList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_bootList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootList GALGAS_bootList::extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_bootList result ;
  const GALGAS_bootList * p = (const GALGAS_bootList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_bootList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("bootList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@initList' sorted list                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cSortedListElement_initList : public cSortedListElement {
  public : GALGAS_initList_2D_element mObject ;

//--- Constructor
  public : cSortedListElement_initList (const GALGAS_location & in_mInitLocation,
                                        const GALGAS_lstring & in_mSelfTypeName,
                                        const GALGAS_string & in_mGlobalVarName,
                                        const GALGAS_lstringlist & in_mRequiredByProcList,
                                        const GALGAS_instructionListAST & in_mInstructionList,
                                        const GALGAS_location & in_mEndOfInitLocation,
                                        const GALGAS_lbigint & in_mPriority
                                        COMMA_LOCATION_ARGS) ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cSortedListElement * copy (void) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;

//--- Virtual method that comparing element for sorting
  public : virtual typeComparisonResult compareForSorting (const cSortedListElement * inOperand) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cSortedListElement_initList::cSortedListElement_initList (const GALGAS_location & in_mInitLocation,
                                                          const GALGAS_lstring & in_mSelfTypeName,
                                                          const GALGAS_string & in_mGlobalVarName,
                                                          const GALGAS_lstringlist & in_mRequiredByProcList,
                                                          const GALGAS_instructionListAST & in_mInstructionList,
                                                          const GALGAS_location & in_mEndOfInitLocation,
                                                          const GALGAS_lbigint & in_mPriority
                                                          COMMA_LOCATION_ARGS) :
cSortedListElement (THERE),
mObject (in_mInitLocation, in_mSelfTypeName, in_mGlobalVarName, in_mRequiredByProcList, in_mInstructionList, in_mEndOfInitLocation, in_mPriority) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cSortedListElement_initList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cSortedListElement * cSortedListElement_initList::copy (void) {
  cSortedListElement * result = NULL ;
  macroMyNew (result, cSortedListElement_initList (mObject.mAttribute_mInitLocation, mObject.mAttribute_mSelfTypeName, mObject.mAttribute_mGlobalVarName, mObject.mAttribute_mRequiredByProcList, mObject.mAttribute_mInstructionList, mObject.mAttribute_mEndOfInitLocation, mObject.mAttribute_mPriority COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cSortedListElement_initList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mInitLocation" ":" ;
  mObject.mAttribute_mInitLocation.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSelfTypeName" ":" ;
  mObject.mAttribute_mSelfTypeName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGlobalVarName" ":" ;
  mObject.mAttribute_mGlobalVarName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mRequiredByProcList" ":" ;
  mObject.mAttribute_mRequiredByProcList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mInstructionList" ":" ;
  mObject.mAttribute_mInstructionList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEndOfInitLocation" ":" ;
  mObject.mAttribute_mEndOfInitLocation.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPriority" ":" ;
  mObject.mAttribute_mPriority.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cSortedListElement_initList::compare (const cCollectionElement * inOperand) const {
  cSortedListElement_initList * operand = (cSortedListElement_initList *) inOperand ;
  macroValidSharedObject (operand, cSortedListElement_initList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initList::GALGAS_initList (void) :
AC_GALGAS_sortedlist () {
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cSortedListElement_initList::compareForSorting (const cSortedListElement * inOperand) const {
  typeComparisonResult result = kOperandEqual ;
  const cSortedListElement_initList * operand = (const cSortedListElement_initList *) inOperand ;
  macroValidSharedObject (operand, cSortedListElement_initList) ;
  if (result == kOperandEqual) {
    result = mObject.mAttribute_mPriority.objectCompare (operand->mObject.mAttribute_mPriority) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initList GALGAS_initList::constructor_emptySortedList (LOCATION_ARGS) {
  GALGAS_initList result ;
  result.createNewEmptySortedList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initList GALGAS_initList::constructor_sortedListWithValue (const GALGAS_location & inOperand0,
                                                                  const GALGAS_lstring & inOperand1,
                                                                  const GALGAS_string & inOperand2,
                                                                  const GALGAS_lstringlist & inOperand3,
                                                                  const GALGAS_instructionListAST & inOperand4,
                                                                  const GALGAS_location & inOperand5,
                                                                  const GALGAS_lbigint & inOperand6
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_initList result = constructor_emptySortedList (THERE) ;
  cSortedListElement * p = NULL ;
  macroMyNew (p, cSortedListElement_initList (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE)) ;
  capSortedListElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  result.addObject (attributes) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_initList::addAssign_operation (const GALGAS_location & inOperand0,
                                           const GALGAS_lstring & inOperand1,
                                           const GALGAS_string & inOperand2,
                                           const GALGAS_lstringlist & inOperand3,
                                           const GALGAS_instructionListAST & inOperand4,
                                           const GALGAS_location & inOperand5,
                                           const GALGAS_lbigint & inOperand6
                                           COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cSortedListElement * p = NULL ;
    macroMyNew (p, cSortedListElement_initList (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6 COMMA_THERE)) ;
    capSortedListElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_initList::plusAssign_operation (const GALGAS_initList inOperand,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid ()) {
    appendSortedList (inOperand) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_initList::setter_popSmallest (GALGAS_location & outOperand0,
                                          GALGAS_lstring & outOperand1,
                                          GALGAS_string & outOperand2,
                                          GALGAS_lstringlist & outOperand3,
                                          GALGAS_instructionListAST & outOperand4,
                                          GALGAS_location & outOperand5,
                                          GALGAS_lbigint & outOperand6,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  capSortedListElement attributes ;
  removeSmallestObject (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_initList * p = (cSortedListElement_initList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_initList) ;
    outOperand0 = p->mObject.mAttribute_mInitLocation ;
    outOperand1 = p->mObject.mAttribute_mSelfTypeName ;
    outOperand2 = p->mObject.mAttribute_mGlobalVarName ;
    outOperand3 = p->mObject.mAttribute_mRequiredByProcList ;
    outOperand4 = p->mObject.mAttribute_mInstructionList ;
    outOperand5 = p->mObject.mAttribute_mEndOfInitLocation ;
    outOperand6 = p->mObject.mAttribute_mPriority ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_initList::setter_popGreatest (GALGAS_location & outOperand0,
                                          GALGAS_lstring & outOperand1,
                                          GALGAS_string & outOperand2,
                                          GALGAS_lstringlist & outOperand3,
                                          GALGAS_instructionListAST & outOperand4,
                                          GALGAS_location & outOperand5,
                                          GALGAS_lbigint & outOperand6,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  capSortedListElement attributes ;
  removeGreatestObject (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_initList * p = (cSortedListElement_initList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_initList) ;
    outOperand0 = p->mObject.mAttribute_mInitLocation ;
    outOperand1 = p->mObject.mAttribute_mSelfTypeName ;
    outOperand2 = p->mObject.mAttribute_mGlobalVarName ;
    outOperand3 = p->mObject.mAttribute_mRequiredByProcList ;
    outOperand4 = p->mObject.mAttribute_mInstructionList ;
    outOperand5 = p->mObject.mAttribute_mEndOfInitLocation ;
    outOperand6 = p->mObject.mAttribute_mPriority ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_initList::method_smallest (GALGAS_location & outOperand0,
                                       GALGAS_lstring & outOperand1,
                                       GALGAS_string & outOperand2,
                                       GALGAS_lstringlist & outOperand3,
                                       GALGAS_instructionListAST & outOperand4,
                                       GALGAS_location & outOperand5,
                                       GALGAS_lbigint & outOperand6,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  capSortedListElement attributes ;
  smallestObjectAttributeList (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_initList * p = (cSortedListElement_initList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_initList) ;
    outOperand0 = p->mObject.mAttribute_mInitLocation ;
    outOperand1 = p->mObject.mAttribute_mSelfTypeName ;
    outOperand2 = p->mObject.mAttribute_mGlobalVarName ;
    outOperand3 = p->mObject.mAttribute_mRequiredByProcList ;
    outOperand4 = p->mObject.mAttribute_mInstructionList ;
    outOperand5 = p->mObject.mAttribute_mEndOfInitLocation ;
    outOperand6 = p->mObject.mAttribute_mPriority ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_initList::method_greatest (GALGAS_location & outOperand0,
                                       GALGAS_lstring & outOperand1,
                                       GALGAS_string & outOperand2,
                                       GALGAS_lstringlist & outOperand3,
                                       GALGAS_instructionListAST & outOperand4,
                                       GALGAS_location & outOperand5,
                                       GALGAS_lbigint & outOperand6,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  capSortedListElement attributes ;
  greatestObjectAttributeList (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_initList * p = (cSortedListElement_initList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_initList) ;
    outOperand0 = p->mObject.mAttribute_mInitLocation ;
    outOperand1 = p->mObject.mAttribute_mSelfTypeName ;
    outOperand2 = p->mObject.mAttribute_mGlobalVarName ;
    outOperand3 = p->mObject.mAttribute_mRequiredByProcList ;
    outOperand4 = p->mObject.mAttribute_mInstructionList ;
    outOperand5 = p->mObject.mAttribute_mEndOfInitLocation ;
    outOperand6 = p->mObject.mAttribute_mPriority ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_initList::cEnumerator_initList (const GALGAS_initList & inEnumeratedObject,
                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initList_2D_element cEnumerator_initList::current (LOCATION_ARGS) const {
  const cSortedListElement_initList * p = (const cSortedListElement_initList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_initList) ;
  return p->mObject ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_initList::current_mInitLocation (LOCATION_ARGS) const {
  const cSortedListElement_initList * p = (const cSortedListElement_initList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_initList) ;
  return p->mObject.mAttribute_mInitLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_initList::current_mSelfTypeName (LOCATION_ARGS) const {
  const cSortedListElement_initList * p = (const cSortedListElement_initList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_initList) ;
  return p->mObject.mAttribute_mSelfTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_initList::current_mGlobalVarName (LOCATION_ARGS) const {
  const cSortedListElement_initList * p = (const cSortedListElement_initList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_initList) ;
  return p->mObject.mAttribute_mGlobalVarName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cEnumerator_initList::current_mRequiredByProcList (LOCATION_ARGS) const {
  const cSortedListElement_initList * p = (const cSortedListElement_initList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_initList) ;
  return p->mObject.mAttribute_mRequiredByProcList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cEnumerator_initList::current_mInstructionList (LOCATION_ARGS) const {
  const cSortedListElement_initList * p = (const cSortedListElement_initList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_initList) ;
  return p->mObject.mAttribute_mInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_initList::current_mEndOfInitLocation (LOCATION_ARGS) const {
  const cSortedListElement_initList * p = (const cSortedListElement_initList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_initList) ;
  return p->mObject.mAttribute_mEndOfInitLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint cEnumerator_initList::current_mPriority (LOCATION_ARGS) const {
  const cSortedListElement_initList * p = (const cSortedListElement_initList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_initList) ;
  return p->mObject.mAttribute_mPriority ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @initList type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_initList ("initList",
                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_initList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_initList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_initList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_initList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initList GALGAS_initList::extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_initList result ;
  const GALGAS_initList * p = (const GALGAS_initList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_initList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("initList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Class for element of '@panicClauseListAST' sorted list                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cSortedListElement_panicClauseListAST : public cSortedListElement {
  public : GALGAS_panicClauseListAST_2D_element mObject ;

//--- Constructor
  public : cSortedListElement_panicClauseListAST (const GALGAS_lstring & in_mPanicClauseName,
                                                  const GALGAS_instructionListAST & in_mPanicInstructionList,
                                                  const GALGAS_location & in_mEndOfPanicInstructions,
                                                  const GALGAS_lbigint & in_mPriority,
                                                  const GALGAS_location & in_mLocationPriority
                                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cSortedListElement * copy (void) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;

//--- Virtual method that comparing element for sorting
  public : virtual typeComparisonResult compareForSorting (const cSortedListElement * inOperand) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cSortedListElement_panicClauseListAST::cSortedListElement_panicClauseListAST (const GALGAS_lstring & in_mPanicClauseName,
                                                                              const GALGAS_instructionListAST & in_mPanicInstructionList,
                                                                              const GALGAS_location & in_mEndOfPanicInstructions,
                                                                              const GALGAS_lbigint & in_mPriority,
                                                                              const GALGAS_location & in_mLocationPriority
                                                                              COMMA_LOCATION_ARGS) :
cSortedListElement (THERE),
mObject (in_mPanicClauseName, in_mPanicInstructionList, in_mEndOfPanicInstructions, in_mPriority, in_mLocationPriority) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cSortedListElement_panicClauseListAST::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cSortedListElement * cSortedListElement_panicClauseListAST::copy (void) {
  cSortedListElement * result = NULL ;
  macroMyNew (result, cSortedListElement_panicClauseListAST (mObject.mAttribute_mPanicClauseName, mObject.mAttribute_mPanicInstructionList, mObject.mAttribute_mEndOfPanicInstructions, mObject.mAttribute_mPriority, mObject.mAttribute_mLocationPriority COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cSortedListElement_panicClauseListAST::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPanicClauseName" ":" ;
  mObject.mAttribute_mPanicClauseName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPanicInstructionList" ":" ;
  mObject.mAttribute_mPanicInstructionList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEndOfPanicInstructions" ":" ;
  mObject.mAttribute_mEndOfPanicInstructions.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPriority" ":" ;
  mObject.mAttribute_mPriority.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mLocationPriority" ":" ;
  mObject.mAttribute_mLocationPriority.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cSortedListElement_panicClauseListAST::compare (const cCollectionElement * inOperand) const {
  cSortedListElement_panicClauseListAST * operand = (cSortedListElement_panicClauseListAST *) inOperand ;
  macroValidSharedObject (operand, cSortedListElement_panicClauseListAST) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicClauseListAST::GALGAS_panicClauseListAST (void) :
AC_GALGAS_sortedlist () {
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cSortedListElement_panicClauseListAST::compareForSorting (const cSortedListElement * inOperand) const {
  typeComparisonResult result = kOperandEqual ;
  const cSortedListElement_panicClauseListAST * operand = (const cSortedListElement_panicClauseListAST *) inOperand ;
  macroValidSharedObject (operand, cSortedListElement_panicClauseListAST) ;
  if (result == kOperandEqual) {
    result = mObject.mAttribute_mPriority.objectCompare (operand->mObject.mAttribute_mPriority) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicClauseListAST GALGAS_panicClauseListAST::constructor_emptySortedList (LOCATION_ARGS) {
  GALGAS_panicClauseListAST result ;
  result.createNewEmptySortedList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicClauseListAST GALGAS_panicClauseListAST::constructor_sortedListWithValue (const GALGAS_lstring & inOperand0,
                                                                                      const GALGAS_instructionListAST & inOperand1,
                                                                                      const GALGAS_location & inOperand2,
                                                                                      const GALGAS_lbigint & inOperand3,
                                                                                      const GALGAS_location & inOperand4
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_panicClauseListAST result = constructor_emptySortedList (THERE) ;
  cSortedListElement * p = NULL ;
  macroMyNew (p, cSortedListElement_panicClauseListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4 COMMA_THERE)) ;
  capSortedListElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  result.addObject (attributes) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_panicClauseListAST::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                     const GALGAS_instructionListAST & inOperand1,
                                                     const GALGAS_location & inOperand2,
                                                     const GALGAS_lbigint & inOperand3,
                                                     const GALGAS_location & inOperand4
                                                     COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cSortedListElement * p = NULL ;
    macroMyNew (p, cSortedListElement_panicClauseListAST (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4 COMMA_THERE)) ;
    capSortedListElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_panicClauseListAST::plusAssign_operation (const GALGAS_panicClauseListAST inOperand,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid ()) {
    appendSortedList (inOperand) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_panicClauseListAST::setter_popSmallest (GALGAS_lstring & outOperand0,
                                                    GALGAS_instructionListAST & outOperand1,
                                                    GALGAS_location & outOperand2,
                                                    GALGAS_lbigint & outOperand3,
                                                    GALGAS_location & outOperand4,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  capSortedListElement attributes ;
  removeSmallestObject (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_panicClauseListAST * p = (cSortedListElement_panicClauseListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_panicClauseListAST) ;
    outOperand0 = p->mObject.mAttribute_mPanicClauseName ;
    outOperand1 = p->mObject.mAttribute_mPanicInstructionList ;
    outOperand2 = p->mObject.mAttribute_mEndOfPanicInstructions ;
    outOperand3 = p->mObject.mAttribute_mPriority ;
    outOperand4 = p->mObject.mAttribute_mLocationPriority ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_panicClauseListAST::setter_popGreatest (GALGAS_lstring & outOperand0,
                                                    GALGAS_instructionListAST & outOperand1,
                                                    GALGAS_location & outOperand2,
                                                    GALGAS_lbigint & outOperand3,
                                                    GALGAS_location & outOperand4,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  capSortedListElement attributes ;
  removeGreatestObject (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_panicClauseListAST * p = (cSortedListElement_panicClauseListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_panicClauseListAST) ;
    outOperand0 = p->mObject.mAttribute_mPanicClauseName ;
    outOperand1 = p->mObject.mAttribute_mPanicInstructionList ;
    outOperand2 = p->mObject.mAttribute_mEndOfPanicInstructions ;
    outOperand3 = p->mObject.mAttribute_mPriority ;
    outOperand4 = p->mObject.mAttribute_mLocationPriority ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_panicClauseListAST::method_smallest (GALGAS_lstring & outOperand0,
                                                 GALGAS_instructionListAST & outOperand1,
                                                 GALGAS_location & outOperand2,
                                                 GALGAS_lbigint & outOperand3,
                                                 GALGAS_location & outOperand4,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capSortedListElement attributes ;
  smallestObjectAttributeList (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_panicClauseListAST * p = (cSortedListElement_panicClauseListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_panicClauseListAST) ;
    outOperand0 = p->mObject.mAttribute_mPanicClauseName ;
    outOperand1 = p->mObject.mAttribute_mPanicInstructionList ;
    outOperand2 = p->mObject.mAttribute_mEndOfPanicInstructions ;
    outOperand3 = p->mObject.mAttribute_mPriority ;
    outOperand4 = p->mObject.mAttribute_mLocationPriority ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_panicClauseListAST::method_greatest (GALGAS_lstring & outOperand0,
                                                 GALGAS_instructionListAST & outOperand1,
                                                 GALGAS_location & outOperand2,
                                                 GALGAS_lbigint & outOperand3,
                                                 GALGAS_location & outOperand4,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capSortedListElement attributes ;
  greatestObjectAttributeList (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_panicClauseListAST * p = (cSortedListElement_panicClauseListAST *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_panicClauseListAST) ;
    outOperand0 = p->mObject.mAttribute_mPanicClauseName ;
    outOperand1 = p->mObject.mAttribute_mPanicInstructionList ;
    outOperand2 = p->mObject.mAttribute_mEndOfPanicInstructions ;
    outOperand3 = p->mObject.mAttribute_mPriority ;
    outOperand4 = p->mObject.mAttribute_mLocationPriority ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_panicClauseListAST::cEnumerator_panicClauseListAST (const GALGAS_panicClauseListAST & inEnumeratedObject,
                                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicClauseListAST_2D_element cEnumerator_panicClauseListAST::current (LOCATION_ARGS) const {
  const cSortedListElement_panicClauseListAST * p = (const cSortedListElement_panicClauseListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_panicClauseListAST) ;
  return p->mObject ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_panicClauseListAST::current_mPanicClauseName (LOCATION_ARGS) const {
  const cSortedListElement_panicClauseListAST * p = (const cSortedListElement_panicClauseListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_panicClauseListAST) ;
  return p->mObject.mAttribute_mPanicClauseName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST cEnumerator_panicClauseListAST::current_mPanicInstructionList (LOCATION_ARGS) const {
  const cSortedListElement_panicClauseListAST * p = (const cSortedListElement_panicClauseListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_panicClauseListAST) ;
  return p->mObject.mAttribute_mPanicInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_panicClauseListAST::current_mEndOfPanicInstructions (LOCATION_ARGS) const {
  const cSortedListElement_panicClauseListAST * p = (const cSortedListElement_panicClauseListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_panicClauseListAST) ;
  return p->mObject.mAttribute_mEndOfPanicInstructions ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint cEnumerator_panicClauseListAST::current_mPriority (LOCATION_ARGS) const {
  const cSortedListElement_panicClauseListAST * p = (const cSortedListElement_panicClauseListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_panicClauseListAST) ;
  return p->mObject.mAttribute_mPriority ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_panicClauseListAST::current_mLocationPriority (LOCATION_ARGS) const {
  const cSortedListElement_panicClauseListAST * p = (const cSortedListElement_panicClauseListAST *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_panicClauseListAST) ;
  return p->mObject.mAttribute_mLocationPriority ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @panicClauseListAST type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_panicClauseListAST ("panicClauseListAST",
                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_panicClauseListAST::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_panicClauseListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_panicClauseListAST::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_panicClauseListAST (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicClauseListAST GALGAS_panicClauseListAST::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_panicClauseListAST result ;
  const GALGAS_panicClauseListAST * p = (const GALGAS_panicClauseListAST *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_panicClauseListAST *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("panicClauseListAST", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Class for element of '@taskList' list                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_taskList : public cCollectionElement {
  public : GALGAS_taskList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_taskList (const GALGAS_lstring & in_mTaskName,
                                        const GALGAS_lbigint & in_mPriority,
                                        const GALGAS_lbigint & in_mStackSize,
                                        const GALGAS_taskVarListAST & in_mVarList,
                                        const GALGAS_functionDeclarationListAST & in_mTaskProcList,
                                        const GALGAS_taskInitListAST & in_mTaskInitListAST,
                                        const GALGAS_syncInstructionBranchList & in_mGuardedCommandList,
                                        const GALGAS_location & in_mEndOfTaskDeclaration
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

cCollectionElement_taskList::cCollectionElement_taskList (const GALGAS_lstring & in_mTaskName,
                                                          const GALGAS_lbigint & in_mPriority,
                                                          const GALGAS_lbigint & in_mStackSize,
                                                          const GALGAS_taskVarListAST & in_mVarList,
                                                          const GALGAS_functionDeclarationListAST & in_mTaskProcList,
                                                          const GALGAS_taskInitListAST & in_mTaskInitListAST,
                                                          const GALGAS_syncInstructionBranchList & in_mGuardedCommandList,
                                                          const GALGAS_location & in_mEndOfTaskDeclaration
                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mTaskName, in_mPriority, in_mStackSize, in_mVarList, in_mTaskProcList, in_mTaskInitListAST, in_mGuardedCommandList, in_mEndOfTaskDeclaration) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_taskList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_taskList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_taskList (mObject.mAttribute_mTaskName, mObject.mAttribute_mPriority, mObject.mAttribute_mStackSize, mObject.mAttribute_mVarList, mObject.mAttribute_mTaskProcList, mObject.mAttribute_mTaskInitListAST, mObject.mAttribute_mGuardedCommandList, mObject.mAttribute_mEndOfTaskDeclaration COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_taskList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mTaskName" ":" ;
  mObject.mAttribute_mTaskName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPriority" ":" ;
  mObject.mAttribute_mPriority.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mStackSize" ":" ;
  mObject.mAttribute_mStackSize.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mVarList" ":" ;
  mObject.mAttribute_mVarList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mTaskProcList" ":" ;
  mObject.mAttribute_mTaskProcList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mTaskInitListAST" ":" ;
  mObject.mAttribute_mTaskInitListAST.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGuardedCommandList" ":" ;
  mObject.mAttribute_mGuardedCommandList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mEndOfTaskDeclaration" ":" ;
  mObject.mAttribute_mEndOfTaskDeclaration.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_taskList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_taskList * operand = (cCollectionElement_taskList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_taskList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskList::GALGAS_taskList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskList::GALGAS_taskList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskList GALGAS_taskList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_taskList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskList GALGAS_taskList::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_lbigint & inOperand1,
                                                            const GALGAS_lbigint & inOperand2,
                                                            const GALGAS_taskVarListAST & inOperand3,
                                                            const GALGAS_functionDeclarationListAST & inOperand4,
                                                            const GALGAS_taskInitListAST & inOperand5,
                                                            const GALGAS_syncInstructionBranchList & inOperand6,
                                                            const GALGAS_location & inOperand7
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_taskList result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_taskList::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const GALGAS_lstring & in_mTaskName,
                                                 const GALGAS_lbigint & in_mPriority,
                                                 const GALGAS_lbigint & in_mStackSize,
                                                 const GALGAS_taskVarListAST & in_mVarList,
                                                 const GALGAS_functionDeclarationListAST & in_mTaskProcList,
                                                 const GALGAS_taskInitListAST & in_mTaskInitListAST,
                                                 const GALGAS_syncInstructionBranchList & in_mGuardedCommandList,
                                                 const GALGAS_location & in_mEndOfTaskDeclaration
                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement_taskList * p = NULL ;
  macroMyNew (p, cCollectionElement_taskList (in_mTaskName,
                                              in_mPriority,
                                              in_mStackSize,
                                              in_mVarList,
                                              in_mTaskProcList,
                                              in_mTaskInitListAST,
                                              in_mGuardedCommandList,
                                              in_mEndOfTaskDeclaration COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskList::addAssign_operation (const GALGAS_lstring & inOperand0,
                                           const GALGAS_lbigint & inOperand1,
                                           const GALGAS_lbigint & inOperand2,
                                           const GALGAS_taskVarListAST & inOperand3,
                                           const GALGAS_functionDeclarationListAST & inOperand4,
                                           const GALGAS_taskInitListAST & inOperand5,
                                           const GALGAS_syncInstructionBranchList & inOperand6,
                                           const GALGAS_location & inOperand7
                                           COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_taskList (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskList::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                            const GALGAS_lbigint inOperand1,
                                            const GALGAS_lbigint inOperand2,
                                            const GALGAS_taskVarListAST inOperand3,
                                            const GALGAS_functionDeclarationListAST inOperand4,
                                            const GALGAS_taskInitListAST inOperand5,
                                            const GALGAS_syncInstructionBranchList inOperand6,
                                            const GALGAS_location inOperand7,
                                            const GALGAS_uint inInsertionIndex,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_taskList (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskList::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                            GALGAS_lbigint & outOperand1,
                                            GALGAS_lbigint & outOperand2,
                                            GALGAS_taskVarListAST & outOperand3,
                                            GALGAS_functionDeclarationListAST & outOperand4,
                                            GALGAS_taskInitListAST & outOperand5,
                                            GALGAS_syncInstructionBranchList & outOperand6,
                                            GALGAS_location & outOperand7,
                                            const GALGAS_uint inRemoveIndex,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
      outOperand4.drop () ;
      outOperand5.drop () ;
      outOperand6.drop () ;
      outOperand7.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_taskList) ;
      outOperand0 = p->mObject.mAttribute_mTaskName ;
      outOperand1 = p->mObject.mAttribute_mPriority ;
      outOperand2 = p->mObject.mAttribute_mStackSize ;
      outOperand3 = p->mObject.mAttribute_mVarList ;
      outOperand4 = p->mObject.mAttribute_mTaskProcList ;
      outOperand5 = p->mObject.mAttribute_mTaskInitListAST ;
      outOperand6 = p->mObject.mAttribute_mGuardedCommandList ;
      outOperand7 = p->mObject.mAttribute_mEndOfTaskDeclaration ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskList::setter_popFirst (GALGAS_lstring & outOperand0,
                                       GALGAS_lbigint & outOperand1,
                                       GALGAS_lbigint & outOperand2,
                                       GALGAS_taskVarListAST & outOperand3,
                                       GALGAS_functionDeclarationListAST & outOperand4,
                                       GALGAS_taskInitListAST & outOperand5,
                                       GALGAS_syncInstructionBranchList & outOperand6,
                                       GALGAS_location & outOperand7,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
    outOperand7.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_taskList) ;
    outOperand0 = p->mObject.mAttribute_mTaskName ;
    outOperand1 = p->mObject.mAttribute_mPriority ;
    outOperand2 = p->mObject.mAttribute_mStackSize ;
    outOperand3 = p->mObject.mAttribute_mVarList ;
    outOperand4 = p->mObject.mAttribute_mTaskProcList ;
    outOperand5 = p->mObject.mAttribute_mTaskInitListAST ;
    outOperand6 = p->mObject.mAttribute_mGuardedCommandList ;
    outOperand7 = p->mObject.mAttribute_mEndOfTaskDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskList::setter_popLast (GALGAS_lstring & outOperand0,
                                      GALGAS_lbigint & outOperand1,
                                      GALGAS_lbigint & outOperand2,
                                      GALGAS_taskVarListAST & outOperand3,
                                      GALGAS_functionDeclarationListAST & outOperand4,
                                      GALGAS_taskInitListAST & outOperand5,
                                      GALGAS_syncInstructionBranchList & outOperand6,
                                      GALGAS_location & outOperand7,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
    outOperand7.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_taskList) ;
    outOperand0 = p->mObject.mAttribute_mTaskName ;
    outOperand1 = p->mObject.mAttribute_mPriority ;
    outOperand2 = p->mObject.mAttribute_mStackSize ;
    outOperand3 = p->mObject.mAttribute_mVarList ;
    outOperand4 = p->mObject.mAttribute_mTaskProcList ;
    outOperand5 = p->mObject.mAttribute_mTaskInitListAST ;
    outOperand6 = p->mObject.mAttribute_mGuardedCommandList ;
    outOperand7 = p->mObject.mAttribute_mEndOfTaskDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskList::method_first (GALGAS_lstring & outOperand0,
                                    GALGAS_lbigint & outOperand1,
                                    GALGAS_lbigint & outOperand2,
                                    GALGAS_taskVarListAST & outOperand3,
                                    GALGAS_functionDeclarationListAST & outOperand4,
                                    GALGAS_taskInitListAST & outOperand5,
                                    GALGAS_syncInstructionBranchList & outOperand6,
                                    GALGAS_location & outOperand7,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
    outOperand7.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_taskList) ;
    outOperand0 = p->mObject.mAttribute_mTaskName ;
    outOperand1 = p->mObject.mAttribute_mPriority ;
    outOperand2 = p->mObject.mAttribute_mStackSize ;
    outOperand3 = p->mObject.mAttribute_mVarList ;
    outOperand4 = p->mObject.mAttribute_mTaskProcList ;
    outOperand5 = p->mObject.mAttribute_mTaskInitListAST ;
    outOperand6 = p->mObject.mAttribute_mGuardedCommandList ;
    outOperand7 = p->mObject.mAttribute_mEndOfTaskDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskList::method_last (GALGAS_lstring & outOperand0,
                                   GALGAS_lbigint & outOperand1,
                                   GALGAS_lbigint & outOperand2,
                                   GALGAS_taskVarListAST & outOperand3,
                                   GALGAS_functionDeclarationListAST & outOperand4,
                                   GALGAS_taskInitListAST & outOperand5,
                                   GALGAS_syncInstructionBranchList & outOperand6,
                                   GALGAS_location & outOperand7,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
    outOperand5.drop () ;
    outOperand6.drop () ;
    outOperand7.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_taskList) ;
    outOperand0 = p->mObject.mAttribute_mTaskName ;
    outOperand1 = p->mObject.mAttribute_mPriority ;
    outOperand2 = p->mObject.mAttribute_mStackSize ;
    outOperand3 = p->mObject.mAttribute_mVarList ;
    outOperand4 = p->mObject.mAttribute_mTaskProcList ;
    outOperand5 = p->mObject.mAttribute_mTaskInitListAST ;
    outOperand6 = p->mObject.mAttribute_mGuardedCommandList ;
    outOperand7 = p->mObject.mAttribute_mEndOfTaskDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskList GALGAS_taskList::add_operation (const GALGAS_taskList & inOperand,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_taskList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskList GALGAS_taskList::getter_subListWithRange (const GALGAS_range & inRange,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_taskList result = GALGAS_taskList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskList GALGAS_taskList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_taskList result = GALGAS_taskList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskList GALGAS_taskList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_taskList result = GALGAS_taskList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskList::plusAssign_operation (const GALGAS_taskList inOperand,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_taskList::getter_mTaskNameAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_taskList) ;
    result = p->mObject.mAttribute_mTaskName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint GALGAS_taskList::getter_mPriorityAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
  GALGAS_lbigint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_taskList) ;
    result = p->mObject.mAttribute_mPriority ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint GALGAS_taskList::getter_mStackSizeAtIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
  GALGAS_lbigint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_taskList) ;
    result = p->mObject.mAttribute_mStackSize ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskVarListAST GALGAS_taskList::getter_mVarListAtIndex (const GALGAS_uint & inIndex,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
  GALGAS_taskVarListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_taskList) ;
    result = p->mObject.mAttribute_mVarList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST GALGAS_taskList::getter_mTaskProcListAtIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
  GALGAS_functionDeclarationListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_taskList) ;
    result = p->mObject.mAttribute_mTaskProcList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitListAST GALGAS_taskList::getter_mTaskInitListASTAtIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
  GALGAS_taskInitListAST result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_taskList) ;
    result = p->mObject.mAttribute_mTaskInitListAST ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchList GALGAS_taskList::getter_mGuardedCommandListAtIndex (const GALGAS_uint & inIndex,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
  GALGAS_syncInstructionBranchList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_taskList) ;
    result = p->mObject.mAttribute_mGuardedCommandList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_taskList::getter_mEndOfTaskDeclarationAtIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_taskList * p = (cCollectionElement_taskList *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_taskList) ;
    result = p->mObject.mAttribute_mEndOfTaskDeclaration ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_taskList::cEnumerator_taskList (const GALGAS_taskList & inEnumeratedObject,
                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskList_2D_element cEnumerator_taskList::current (LOCATION_ARGS) const {
  const cCollectionElement_taskList * p = (const cCollectionElement_taskList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_taskList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_taskList::current_mTaskName (LOCATION_ARGS) const {
  const cCollectionElement_taskList * p = (const cCollectionElement_taskList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_taskList) ;
  return p->mObject.mAttribute_mTaskName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint cEnumerator_taskList::current_mPriority (LOCATION_ARGS) const {
  const cCollectionElement_taskList * p = (const cCollectionElement_taskList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_taskList) ;
  return p->mObject.mAttribute_mPriority ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint cEnumerator_taskList::current_mStackSize (LOCATION_ARGS) const {
  const cCollectionElement_taskList * p = (const cCollectionElement_taskList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_taskList) ;
  return p->mObject.mAttribute_mStackSize ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskVarListAST cEnumerator_taskList::current_mVarList (LOCATION_ARGS) const {
  const cCollectionElement_taskList * p = (const cCollectionElement_taskList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_taskList) ;
  return p->mObject.mAttribute_mVarList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionDeclarationListAST cEnumerator_taskList::current_mTaskProcList (LOCATION_ARGS) const {
  const cCollectionElement_taskList * p = (const cCollectionElement_taskList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_taskList) ;
  return p->mObject.mAttribute_mTaskProcList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitListAST cEnumerator_taskList::current_mTaskInitListAST (LOCATION_ARGS) const {
  const cCollectionElement_taskList * p = (const cCollectionElement_taskList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_taskList) ;
  return p->mObject.mAttribute_mTaskInitListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchList cEnumerator_taskList::current_mGuardedCommandList (LOCATION_ARGS) const {
  const cCollectionElement_taskList * p = (const cCollectionElement_taskList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_taskList) ;
  return p->mObject.mAttribute_mGuardedCommandList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_taskList::current_mEndOfTaskDeclaration (LOCATION_ARGS) const {
  const cCollectionElement_taskList * p = (const cCollectionElement_taskList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_taskList) ;
  return p->mObject.mAttribute_mEndOfTaskDeclaration ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @taskList type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_taskList ("taskList",
                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_taskList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_taskList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_taskList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_taskList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskList GALGAS_taskList::extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_taskList result ;
  const GALGAS_taskList * p = (const GALGAS_taskList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_taskList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("taskList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_import_5F_file_i0_ (GALGAS_lstringlist & ioArgument_ioImportedFileList,
                                                                   C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_import) COMMA_SOURCE_FILE ("syntax-grammar.galgas", 20)) ;
  GALGAS_lstring var_importedFile_994 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__22_string_22_) COMMA_SOURCE_FILE ("syntax-grammar.galgas", 21)) ;
  ioArgument_ioImportedFileList.addAssign_operation (var_importedFile_994  COMMA_SOURCE_FILE ("syntax-grammar.galgas", 22)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_importedFile_994.mAttribute_string.getter_pathExtension (SOURCE_FILE ("syntax-grammar.galgas", 23)).objectCompare (GALGAS_string ("plm"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (var_importedFile_994.getter_location (SOURCE_FILE ("syntax-grammar.galgas", 24)), GALGAS_string ("the pah extension should be .plm"), fixItArray1  COMMA_SOURCE_FILE ("syntax-grammar.galgas", 24)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_import_5F_file_i0_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_import) COMMA_SOURCE_FILE ("syntax-grammar.galgas", 20)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__22_string_22_) COMMA_SOURCE_FILE ("syntax-grammar.galgas", 21)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_start_5F_symbol_i1_ (GALGAS_ast & ioArgument_ioAst,
                                                                    GALGAS_lstringlist & outArgument_outImportedFileList,
                                                                    GALGAS_location & outArgument_outEndOfSourceFile,
                                                                    C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outImportedFileList.drop () ; // Release 'out' argument
  outArgument_outEndOfSourceFile.drop () ; // Release 'out' argument
  outArgument_outImportedFileList = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("syntax-grammar.galgas", 36)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_0 (inCompiler)) {
    case 2: {
      nt_declaration_ (ioArgument_ioAst, inCompiler) ;
    } break ;
    case 3: {
      nt_procedure_ (ioArgument_ioAst.mAttribute_mProcedureListAST, inCompiler) ;
    } break ;
    case 4: {
      nt_section_ (ioArgument_ioAst.mAttribute_mSectionListAST, inCompiler) ;
    } break ;
    case 5: {
      nt_service_ (ioArgument_ioAst.mAttribute_mServiceListAST, inCompiler) ;
    } break ;
    case 6: {
      nt_primitive_ (ioArgument_ioAst.mAttribute_mPrimitiveListAST, inCompiler) ;
    } break ;
    case 7: {
      nt_isr_ (ioArgument_ioAst.mAttribute_mISRDeclarationListAST, GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("syntax-grammar.galgas", 49)), GALGAS_string::makeEmptyString (), inCompiler) ;
    } break ;
    case 8: {
      nt_import_5F_file_ (outArgument_outImportedFileList, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  outArgument_outEndOfSourceFile = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("syntax-grammar.galgas", 53)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_start_5F_symbol_i1_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_0 (inCompiler)) {
    case 2: {
      nt_declaration_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_procedure_parse (inCompiler) ;
    } break ;
    case 4: {
      nt_section_parse (inCompiler) ;
    } break ;
    case 5: {
      nt_service_parse (inCompiler) ;
    } break ;
    case 6: {
      nt_primitive_parse (inCompiler) ;
    } break ;
    case 7: {
      nt_isr_parse (inCompiler) ;
    } break ;
    case 8: {
      nt_import_5F_file_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i2_ (GALGAS_ast & ioArgument_ioAST,
                                                                C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_type) COMMA_SOURCE_FILE ("declaration-type.galgas", 10)) ;
  GALGAS_lstring var_newTypeName_592 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-type.galgas", 11)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("declaration-type.galgas", 12)) ;
  GALGAS_abstractDeclaration var_declaration_653 ;
  nt_declaration_5F_type_ (var_newTypeName_592, var_declaration_653, inCompiler) ;
  ioArgument_ioAST.mAttribute_mDeclarationList.addAssign_operation (var_declaration_653  COMMA_SOURCE_FILE ("declaration-type.galgas", 14)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i2_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_type) COMMA_SOURCE_FILE ("declaration-type.galgas", 10)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-type.galgas", 11)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("declaration-type.galgas", 12)) ;
  nt_declaration_5F_type_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_5F_type_i3_ (const GALGAS_lstring constinArgument_inNewTypeName,
                                                                        GALGAS_abstractDeclaration & outArgument_outDeclaration,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outDeclaration.drop () ; // Release 'out' argument
  GALGAS_lstring var_elementTypeName_1424 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-array.galgas", 27)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("type-array.galgas", 28)) ;
  GALGAS_expressionAST var_sizeExpression_1469 ;
  nt_expression_ (var_sizeExpression_1469, inCompiler) ;
  GALGAS_location var_sizeExpressionLocation_1500 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("type-array.galgas", 30)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("type-array.galgas", 31)) ;
  outArgument_outDeclaration = GALGAS_typeArrayDeclaration::constructor_new (constinArgument_inNewTypeName, var_elementTypeName_1424, var_sizeExpression_1469, var_sizeExpressionLocation_1500  COMMA_SOURCE_FILE ("type-array.galgas", 32)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_5F_type_i3_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-array.galgas", 27)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("type-array.galgas", 28)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("type-array.galgas", 31)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i4_ (GALGAS_ast & ioArgument_ioAST,
                                                                C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_enum) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 26)) ;
  GALGAS_lstring var_enumName_1342 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 27)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 34)) ;
  GALGAS_lstringlist var_enumCaseList_1520 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("type-enumeration-declaration.galgas", 35)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_case) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 37)) ;
    GALGAS_lstring var_constantName_1586 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 38)) ;
    var_enumCaseList_1520.addAssign_operation (var_constantName_1586  COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 39)) ;
    switch (select_plm_5F_syntax_1 (inCompiler)) {
    case 2: {
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 42)) ;
  ioArgument_ioAST.mAttribute_mDeclarationList.addAssign_operation (GALGAS_enumerationDeclaration::constructor_new (var_enumName_1342, var_enumCaseList_1520  COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 43))  COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 43)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i4_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_enum) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 26)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 27)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 34)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_case) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 37)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 38)) ;
    switch (select_plm_5F_syntax_1 (inCompiler)) {
    case 2: {
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 42)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_5F_struct_5F_var_i5_ (GALGAS_structurePropertyListAST & ioArgument_ioFieldListAST,
                                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  GALGAS_bool var_public_2096 ;
  switch (select_plm_5F_syntax_2 (inCompiler)) {
  case 1: {
    var_public_2096 = GALGAS_bool (false) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 51)) ;
    var_public_2096 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 54)) ;
  GALGAS_lstring var_fieldName_2220 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 55)) ;
  switch (select_plm_5F_syntax_3 (inCompiler)) {
  case 1: {
    GALGAS_lstring var_typeName_2260 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 57)) ;
    switch (select_plm_5F_syntax_4 (inCompiler)) {
    case 1: {
      ioArgument_ioFieldListAST.addAssign_operation (var_fieldName_2220, var_public_2096, var_typeName_2260, GALGAS_structureVarInit::constructor_noExpression (SOURCE_FILE ("type-structure-declaration.galgas", 59))  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 59)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 61)) ;
      GALGAS_expressionAST var_initExpression_2405 ;
      nt_expression_ (var_initExpression_2405, inCompiler) ;
      ioArgument_ioFieldListAST.addAssign_operation (var_fieldName_2220, var_public_2096, var_typeName_2260, GALGAS_structureVarInit::constructor_expression (var_initExpression_2405  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 63))  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 63)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 66)) ;
    GALGAS_expressionAST var_initExpression_2571 ;
    nt_expression_ (var_initExpression_2571, inCompiler) ;
    ioArgument_ioFieldListAST.addAssign_operation (var_fieldName_2220, var_public_2096, GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("type-structure-declaration.galgas", 68)), GALGAS_structureVarInit::constructor_expression (var_initExpression_2571  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 68))  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 68)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_5F_struct_5F_var_i5_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_2 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 51)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 54)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 55)) ;
  switch (select_plm_5F_syntax_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 57)) ;
    switch (select_plm_5F_syntax_4 (inCompiler)) {
    case 1: {
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 61)) ;
      nt_expression_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 66)) ;
    nt_expression_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i6_ (GALGAS_ast & ioArgument_ioAST,
                                                                C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_struct) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 75)) ;
  GALGAS_lstring var_structureName_2889 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 76)) ;
  GALGAS_lstringlist var_attributeList_2920 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("type-structure-declaration.galgas", 77)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_5 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attribute_2980 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 80)) ;
      var_attributeList_2920.addAssign_operation (var_attribute_2980  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 81)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 83)) ;
  GALGAS_functionDeclarationListAST var_procedureDeclarationListAST_3091 = GALGAS_functionDeclarationListAST::constructor_emptyList (SOURCE_FILE ("type-structure-declaration.galgas", 84)) ;
  GALGAS_structurePropertyListAST var_fieldList_3136 = GALGAS_structurePropertyListAST::constructor_emptyList (SOURCE_FILE ("type-structure-declaration.galgas", 85)) ;
  GALGAS_serviceDeclarationListAST var_serviceListAST_3187 = GALGAS_serviceDeclarationListAST::constructor_emptyList (SOURCE_FILE ("type-structure-declaration.galgas", 86)) ;
  GALGAS_sectionDeclarationListAST var_sectionListAST_3238 = GALGAS_sectionDeclarationListAST::constructor_emptyList (SOURCE_FILE ("type-structure-declaration.galgas", 87)) ;
  GALGAS_primitiveDeclarationListAST var_primitiveListAST_3293 = GALGAS_primitiveDeclarationListAST::constructor_emptyList (SOURCE_FILE ("type-structure-declaration.galgas", 88)) ;
  GALGAS_guardDeclarationListAST var_guardListAST_3340 = GALGAS_guardDeclarationListAST::constructor_emptyList (SOURCE_FILE ("type-structure-declaration.galgas", 89)) ;
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    switch (select_plm_5F_syntax_6 (inCompiler)) {
    case 2: {
      nt_declaration_5F_struct_5F_var_ (var_fieldList_3136, inCompiler) ;
    } break ;
    case 3: {
      nt_procedure_ (var_procedureDeclarationListAST_3091, inCompiler) ;
    } break ;
    case 4: {
      nt_section_ (var_sectionListAST_3238, inCompiler) ;
    } break ;
    case 5: {
      nt_service_ (var_serviceListAST_3187, inCompiler) ;
    } break ;
    case 6: {
      nt_guard_ (var_guardListAST_3340, inCompiler) ;
    } break ;
    case 7: {
      nt_primitive_ (var_primitiveListAST_3293, inCompiler) ;
    } break ;
    case 8: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 104)) ;
    } break ;
    default:
      repeatFlag_1 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 106)) ;
  ioArgument_ioAST.mAttribute_mDeclarationList.addAssign_operation (GALGAS_structureDeclaration::constructor_new (var_structureName_2889, var_attributeList_2920, var_fieldList_3136, var_procedureDeclarationListAST_3091, var_serviceListAST_3187, var_sectionListAST_3238, var_primitiveListAST_3293, var_guardListAST_3340  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 107))  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 107)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i6_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_struct) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 75)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 76)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_5 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 80)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 83)) ;
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    switch (select_plm_5F_syntax_6 (inCompiler)) {
    case 2: {
      nt_declaration_5F_struct_5F_var_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_procedure_parse (inCompiler) ;
    } break ;
    case 4: {
      nt_section_parse (inCompiler) ;
    } break ;
    case 5: {
      nt_service_parse (inCompiler) ;
    } break ;
    case 6: {
      nt_guard_parse (inCompiler) ;
    } break ;
    case 7: {
      nt_primitive_parse (inCompiler) ;
    } break ;
    case 8: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 104)) ;
    } break ;
    default:
      repeatFlag_1 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 106)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_5F_type_i7_ (const GALGAS_lstring constinArgument_inNewTypeName,
                                                                        GALGAS_abstractDeclaration & outArgument_outDeclaration,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outDeclaration.drop () ; // Release 'out' argument
  GALGAS_lstring var_aliasedTypeName_1351 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-alias.galgas", 25)) ;
  outArgument_outDeclaration = GALGAS_typeAliasDeclaration::constructor_new (constinArgument_inNewTypeName, var_aliasedTypeName_1351  COMMA_SOURCE_FILE ("type-alias.galgas", 26)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_5F_type_i7_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-alias.galgas", 25)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i8_ (GALGAS_ast & ioArgument_ioAST,
                                                                C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_extension) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 24)) ;
  GALGAS_lstring var_typeName_1299 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 25)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 26)) ;
  GALGAS_functionDeclarationListAST var_procedureDeclarationListAST_1367 = GALGAS_functionDeclarationListAST::constructor_emptyList (SOURCE_FILE ("type-extension-declaration.galgas", 27)) ;
  GALGAS_structurePropertyListAST var_propertyList_1415 = GALGAS_structurePropertyListAST::constructor_emptyList (SOURCE_FILE ("type-extension-declaration.galgas", 28)) ;
  GALGAS_serviceDeclarationListAST var_serviceListAST_1466 = GALGAS_serviceDeclarationListAST::constructor_emptyList (SOURCE_FILE ("type-extension-declaration.galgas", 29)) ;
  GALGAS_sectionDeclarationListAST var_sectionListAST_1517 = GALGAS_sectionDeclarationListAST::constructor_emptyList (SOURCE_FILE ("type-extension-declaration.galgas", 30)) ;
  GALGAS_primitiveDeclarationListAST var_primitiveListAST_1572 = GALGAS_primitiveDeclarationListAST::constructor_emptyList (SOURCE_FILE ("type-extension-declaration.galgas", 31)) ;
  GALGAS_guardDeclarationListAST var_guardListAST_1619 = GALGAS_guardDeclarationListAST::constructor_emptyList (SOURCE_FILE ("type-extension-declaration.galgas", 32)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_7 (inCompiler)) {
    case 2: {
      nt_property_5F_in_5F_extension_ (var_propertyList_1415, inCompiler) ;
    } break ;
    case 3: {
      nt_procedure_ (var_procedureDeclarationListAST_1367, inCompiler) ;
    } break ;
    case 4: {
      nt_section_ (var_sectionListAST_1517, inCompiler) ;
    } break ;
    case 5: {
      nt_service_ (var_serviceListAST_1466, inCompiler) ;
    } break ;
    case 6: {
      nt_guard_ (var_guardListAST_1619, inCompiler) ;
    } break ;
    case 7: {
      nt_primitive_ (var_primitiveListAST_1572, inCompiler) ;
    } break ;
    case 8: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 47)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 49)) ;
  ioArgument_ioAST.mAttribute_mExtensionDeclarationListAST.addAssign_operation (var_typeName_1299, var_procedureDeclarationListAST_1367, var_propertyList_1415, var_serviceListAST_1466, var_sectionListAST_1517, var_primitiveListAST_1572, var_guardListAST_1619  COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 50)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i8_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_extension) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 24)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 25)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 26)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_7 (inCompiler)) {
    case 2: {
      nt_property_5F_in_5F_extension_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_procedure_parse (inCompiler) ;
    } break ;
    case 4: {
      nt_section_parse (inCompiler) ;
    } break ;
    case 5: {
      nt_service_parse (inCompiler) ;
    } break ;
    case 6: {
      nt_guard_parse (inCompiler) ;
    } break ;
    case 7: {
      nt_primitive_parse (inCompiler) ;
    } break ;
    case 8: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 47)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 49)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_property_5F_in_5F_extension_i9_ (GALGAS_structurePropertyListAST & ioArgument_ioPropertyList,
                                                                                C_Lexique_plm_5F_lexique * inCompiler) {
  GALGAS_bool var_public_2376 ;
  switch (select_plm_5F_syntax_8 (inCompiler)) {
  case 1: {
    var_public_2376 = GALGAS_bool (false) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 67)) ;
    var_public_2376 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 70)) ;
  GALGAS_lstring var_fieldName_2500 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 71)) ;
  GALGAS_lstring var_typeName_2527 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 72)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 73)) ;
  GALGAS_expressionAST var_initExpression_2572 ;
  nt_expression_ (var_initExpression_2572, inCompiler) ;
  ioArgument_ioPropertyList.addAssign_operation (var_fieldName_2500, var_public_2376, var_typeName_2527, GALGAS_structureVarInit::constructor_expression (var_initExpression_2572  COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 75))  COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 75)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_property_5F_in_5F_extension_i9_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_8 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 67)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 70)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 71)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 72)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("type-extension-declaration.galgas", 73)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_5F_type_i10_ (const GALGAS_lstring constinArgument_inNewTypeName,
                                                                         GALGAS_abstractDeclaration & outArgument_outDeclaration,
                                                                         C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outDeclaration.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__28_) COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 27)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__28_) COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 28)) ;
  GALGAS_expressionAST var_sizeExpression_1449 ;
  nt_expression_ (var_sizeExpression_1449, inCompiler) ;
  GALGAS_location var_sizeExpressionLocation_1480 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 30)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__29_) COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 31)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__29_) COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 32)) ;
  GALGAS_lstringlist var_attributeList_1544 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("type-opaque-declaration.galgas", 33)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_9 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attribute_1604 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 36)) ;
      var_attributeList_1544.addAssign_operation (var_attribute_1604  COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 37)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  outArgument_outDeclaration = GALGAS_opaqueTypeDeclaration::constructor_new (constinArgument_inNewTypeName, var_attributeList_1544, var_sizeExpression_1449, var_sizeExpressionLocation_1480  COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 39)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_5F_type_i10_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__28_) COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 27)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__28_) COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 28)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__29_) COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 31)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__29_) COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 32)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_9 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("type-opaque-declaration.galgas", 36)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i11_ (GALGAS_ast & ioArgument_ioAST,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_register) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 55)) ;
  GALGAS_controlRegisterNameList var_registerDeclarationList_2368 = GALGAS_controlRegisterNameList::constructor_emptyList (SOURCE_FILE ("declaration-control-register.galgas", 56)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_lstring var_registerName_2421 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 58)) ;
    GALGAS_lstringlist var_attributeList_2454 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-control-register.galgas", 59)) ;
    bool repeatFlag_1 = true ;
    while (repeatFlag_1) {
      switch (select_plm_5F_syntax_11 (inCompiler)) {
      case 2: {
        GALGAS_lstring var_attribute_2520 = inCompiler->synthetizedAttribute_tokenString () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 62)) ;
        var_attributeList_2454.addAssign_operation (var_attribute_2520  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 63)) ;
      } break ;
      default:
        repeatFlag_1 = false ;
        break ;
      }
    }
    switch (select_plm_5F_syntax_12 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_at) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 66)) ;
      GALGAS_expressionAST var_registerAddress_2634 ;
      nt_expression_ (var_registerAddress_2634, inCompiler) ;
      var_registerDeclarationList_2368.addAssign_operation (var_registerName_2421, GALGAS_controlRegisterKind::constructor_scalar (SOURCE_FILE ("declaration-control-register.galgas", 70)), var_attributeList_2454, var_registerAddress_2634, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 73))  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 68)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 75)) ;
      GALGAS_expressionAST var_sizeExpression_2844 ;
      nt_expression_ (var_sizeExpression_2844, inCompiler) ;
      GALGAS_location var_sizeExpressionLocation_2879 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 77)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 78)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_at) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 79)) ;
      GALGAS_expressionAST var_baseAddressExpression_2969 ;
      nt_expression_ (var_baseAddressExpression_2969, inCompiler) ;
      GALGAS_location var_baseAddressExpressionLocation_3011 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 81)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 82)) ;
      GALGAS_expressionAST var_arrayElementSizeExpression_3093 ;
      nt_expression_ (var_arrayElementSizeExpression_3093, inCompiler) ;
      GALGAS_location var_arrayElementSizeExpressionLocation_3140 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 84)) ;
      var_registerDeclarationList_2368.addAssign_operation (var_registerName_2421, GALGAS_controlRegisterKind::constructor_registerArray (var_sizeExpression_2844, var_sizeExpressionLocation_2879, var_arrayElementSizeExpression_3093, var_arrayElementSizeExpressionLocation_3140  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 87)), var_attributeList_2454, var_baseAddressExpression_2969, var_baseAddressExpressionLocation_3011  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 85)) ;
    } break ;
    default:
      break ;
    }
    switch (select_plm_5F_syntax_10 (inCompiler)) {
    case 2: {
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  GALGAS_lstring var_registerTypeName_3646 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 99)) ;
  GALGAS_controlRegisterBitSliceList var_registerBitSliceList_3700 = GALGAS_controlRegisterBitSliceList::constructor_emptyList (SOURCE_FILE ("declaration-control-register.galgas", 100)) ;
  switch (select_plm_5F_syntax_13 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 103)) ;
    bool repeatFlag_2 = true ;
    while (repeatFlag_2) {
      GALGAS_controlRegisterBitSlice var_registerBitSlice_3796 ;
      switch (select_plm_5F_syntax_15 (inCompiler)) {
      case 1: {
        GALGAS_lbigint var_unusedBitCount_3860 = inCompiler->synthetizedAttribute_bigInteger () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 107)) ;
        var_registerBitSlice_3796 = GALGAS_controlRegisterBitSlice::constructor_unusedBits (var_unusedBitCount_3860  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 108)) ;
      } break ;
      case 2: {
        GALGAS_lstring var_bitName_3972 = inCompiler->synthetizedAttribute_tokenString () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 110)) ;
        switch (select_plm_5F_syntax_16 (inCompiler)) {
        case 1: {
          var_registerBitSlice_3796 = GALGAS_controlRegisterBitSlice::constructor_namedBit (var_bitName_3972, GALGAS_lbigint::constructor_new (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 112)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 112))  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 112))  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 112)) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 114)) ;
          GALGAS_lbigint var_bitCount_4144 = inCompiler->synthetizedAttribute_bigInteger () ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 115)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 116)) ;
          var_registerBitSlice_3796 = GALGAS_controlRegisterBitSlice::constructor_namedBit (var_bitName_3972, var_bitCount_4144  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 117)) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        break ;
      }
      var_registerBitSliceList_3700.addAssign_operation (var_registerBitSlice_3796  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 120)) ;
      switch (select_plm_5F_syntax_14 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 122)) ;
      } break ;
      default:
        repeatFlag_2 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 124)) ;
  } break ;
  default:
    break ;
  }
  ioArgument_ioAST.mAttribute_mControlRegisterDeclarationListAST.addAssign_operation (var_registerDeclarationList_2368, var_registerTypeName_3646, var_registerBitSliceList_3700, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 130))  COMMA_SOURCE_FILE ("declaration-control-register.galgas", 126)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i11_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_register) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 55)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 58)) ;
    bool repeatFlag_1 = true ;
    while (repeatFlag_1) {
      switch (select_plm_5F_syntax_11 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 62)) ;
      } break ;
      default:
        repeatFlag_1 = false ;
        break ;
      }
    }
    switch (select_plm_5F_syntax_12 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_at) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 66)) ;
      nt_expression_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 75)) ;
      nt_expression_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 78)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_at) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 79)) ;
      nt_expression_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 82)) ;
      nt_expression_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
    switch (select_plm_5F_syntax_10 (inCompiler)) {
    case 2: {
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 99)) ;
  switch (select_plm_5F_syntax_13 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 103)) ;
    bool repeatFlag_2 = true ;
    while (repeatFlag_2) {
      switch (select_plm_5F_syntax_15 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 107)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 110)) ;
        switch (select_plm_5F_syntax_16 (inCompiler)) {
        case 1: {
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 114)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 115)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 116)) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        break ;
      }
      switch (select_plm_5F_syntax_14 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 122)) ;
      } break ;
      default:
        repeatFlag_2 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-control-register.galgas", 124)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i12_ (GALGAS_ast & ioArgument_ioAST,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_let) COMMA_SOURCE_FILE ("declaration-global-constant.galgas", 26)) ;
  GALGAS_lstring var_constantName_1354 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-constant.galgas", 27)) ;
  GALGAS_lstring var_typeName_1376 ;
  switch (select_plm_5F_syntax_17 (inCompiler)) {
  case 1: {
    var_typeName_1376 = GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("declaration-global-constant.galgas", 30)) ;
  } break ;
  case 2: {
    var_typeName_1376 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-global-constant.galgas", 32)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("declaration-global-constant.galgas", 34)) ;
  GALGAS_expressionAST var_expression_1513 ;
  nt_expression_ (var_expression_1513, inCompiler) ;
  ioArgument_ioAST.mAttribute_mDeclarationList.addAssign_operation (GALGAS_globalConstantDeclaration::constructor_new (var_constantName_1354, var_typeName_1376, var_expression_1513  COMMA_SOURCE_FILE ("declaration-global-constant.galgas", 36))  COMMA_SOURCE_FILE ("declaration-global-constant.galgas", 36)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i12_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_let) COMMA_SOURCE_FILE ("declaration-global-constant.galgas", 26)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-constant.galgas", 27)) ;
  switch (select_plm_5F_syntax_17 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-global-constant.galgas", 32)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("declaration-global-constant.galgas", 34)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i13_ (GALGAS_ast & ioArgument_ioAST,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 72)) ;
  GALGAS_lstring var_varName_2617 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 73)) ;
  GALGAS_lstring var_typeName_2639 ;
  switch (select_plm_5F_syntax_18 (inCompiler)) {
  case 1: {
    var_typeName_2639 = GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("declaration-global-variable.galgas", 76)) ;
  } break ;
  case 2: {
    var_typeName_2639 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 78)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 80)) ;
  GALGAS_expressionAST var_expression_2776 ;
  nt_expression_ (var_expression_2776, inCompiler) ;
  GALGAS_allowedRoutineList var_allowedRoutineList_2819 = GALGAS_allowedRoutineList::constructor_emptyList (SOURCE_FILE ("declaration-global-variable.galgas", 82)) ;
  GALGAS_allowedInitList var_allowedInitList_2861 = GALGAS_allowedInitList::constructor_emptyList (SOURCE_FILE ("declaration-global-variable.galgas", 83)) ;
  GALGAS_allowedPanicList var_allowedPanicList_2905 = GALGAS_allowedPanicList::constructor_emptyList (SOURCE_FILE ("declaration-global-variable.galgas", 84)) ;
  GALGAS_allowedGuardList var_allowedGuardList_2949 = GALGAS_allowedGuardList::constructor_emptyList (SOURCE_FILE ("declaration-global-variable.galgas", 85)) ;
  GALGAS_allowedISRList var_allowedISRList_2989 = GALGAS_allowedISRList::constructor_emptyList (SOURCE_FILE ("declaration-global-variable.galgas", 86)) ;
  GALGAS_allowedTaskList var_allowedTaskList_3031 = GALGAS_allowedTaskList::constructor_emptyList (SOURCE_FILE ("declaration-global-variable.galgas", 87)) ;
  switch (select_plm_5F_syntax_19 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 90)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_global_5F_var_5F_allowed_5F_routine_ (var_allowedRoutineList_2819, var_allowedInitList_2861, var_allowedPanicList_2905, var_allowedGuardList_2949, var_allowedISRList_2989, var_allowedTaskList_3031, inCompiler) ;
      switch (select_plm_5F_syntax_20 (inCompiler)) {
      case 2: {
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 152)) ;
  } break ;
  default:
    break ;
  }
  ioArgument_ioAST.mAttribute_mGlobalVarDeclarationList.addAssign_operation (var_typeName_2639, var_varName_2617, var_expression_2776, var_allowedRoutineList_2819, var_allowedInitList_2861, var_allowedPanicList_2905, var_allowedGuardList_2949, var_allowedISRList_2989, var_allowedTaskList_3031, GALGAS_bool (true)  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 154)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i13_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 72)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 73)) ;
  switch (select_plm_5F_syntax_18 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 78)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 80)) ;
  nt_expression_parse (inCompiler) ;
  switch (select_plm_5F_syntax_19 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 90)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_global_5F_var_5F_allowed_5F_routine_parse (inCompiler) ;
      switch (select_plm_5F_syntax_20 (inCompiler)) {
      case 2: {
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 152)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_global_5F_var_5F_allowed_5F_routine_i14_ (GALGAS_allowedRoutineList & ioArgument_allowedRoutineList,
                                                                                         GALGAS_allowedInitList & ioArgument_allowedInitList,
                                                                                         GALGAS_allowedPanicList & ioArgument_allowedPanicList,
                                                                                         GALGAS_allowedGuardList & ioArgument_allowedGuardList,
                                                                                         GALGAS_allowedISRList & ioArgument_allowedISRList,
                                                                                         GALGAS_allowedTaskList & ioArgument_allowedTaskList,
                                                                                         C_Lexique_plm_5F_lexique * inCompiler) {
  GALGAS_bool var_hasWriteAccess_5568 ;
  switch (select_plm_5F_syntax_21 (inCompiler)) {
  case 1: {
    var_hasWriteAccess_5568 = GALGAS_bool (false) ;
  } break ;
  case 2: {
    GALGAS_lstring var_attribute_5649 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 181)) ;
    const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_attribute_5649.mAttribute_string.objectCompare (GALGAS_string ("rw"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (var_attribute_5649.getter_location (SOURCE_FILE ("declaration-global-variable.galgas", 183)), GALGAS_string ("attribute should be @rw"), fixItArray1  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 183)) ;
    }
    var_hasWriteAccess_5568 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  switch (select_plm_5F_syntax_22 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_guard) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 188)) ;
    GALGAS_lstring var_typeName_5834 ;
    switch (select_plm_5F_syntax_23 (inCompiler)) {
    case 1: {
      var_typeName_5834 = GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("declaration-global-variable.galgas", 191)) ;
    } break ;
    case 2: {
      var_typeName_5834 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 193)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 194)) ;
    } break ;
    default:
      break ;
    }
    GALGAS_lstring var_sectionName_5973 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 196)) ;
    ioArgument_allowedGuardList.addAssign_operation (var_typeName_5834, var_sectionName_5973  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 197)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_section) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 199)) ;
    GALGAS_lstring var_typeName_6069 ;
    switch (select_plm_5F_syntax_24 (inCompiler)) {
    case 1: {
      var_typeName_6069 = GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("declaration-global-variable.galgas", 202)) ;
    } break ;
    case 2: {
      var_typeName_6069 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 204)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 205)) ;
    } break ;
    default:
      break ;
    }
    GALGAS_lstring var_sectionName_6208 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 207)) ;
    ioArgument_allowedRoutineList.addAssign_operation (var_hasWriteAccess_5568, var_typeName_6069, var_sectionName_6208, GALGAS_routineKind::constructor_section (SOURCE_FILE ("declaration-global-variable.galgas", 208))  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 208)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_func) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 210)) ;
    GALGAS_lstring var_procName_6338 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 211)) ;
    ioArgument_allowedRoutineList.addAssign_operation (var_hasWriteAccess_5568, GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("declaration-global-variable.galgas", 212)), var_procName_6338, GALGAS_routineKind::constructor_function (SOURCE_FILE ("declaration-global-variable.galgas", 212))  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 212)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_func) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 214)) ;
    GALGAS_lstring var_typeName_6466 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 215)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 216)) ;
    GALGAS_lstring var_procName_6509 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 217)) ;
    ioArgument_allowedRoutineList.addAssign_operation (var_hasWriteAccess_5568, var_typeName_6466, var_procName_6509, GALGAS_routineKind::constructor_function (SOURCE_FILE ("declaration-global-variable.galgas", 218))  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 218)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_init) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 220)) ;
    GALGAS_lbigint var_priority_6643 = inCompiler->synthetizedAttribute_bigInteger () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 221)) ;
    ioArgument_allowedInitList.addAssign_operation (var_hasWriteAccess_5568, var_priority_6643  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 222)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_isr) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 224)) ;
    GALGAS_lstring var_isrName_6745 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 225)) ;
    ioArgument_allowedISRList.addAssign_operation (var_hasWriteAccess_5568, var_isrName_6745  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 226)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_task) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 228)) ;
    GALGAS_lstring var_isrName_6846 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 229)) ;
    ioArgument_allowedTaskList.addAssign_operation (var_hasWriteAccess_5568, var_isrName_6846  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 230)) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_panic) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 232)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_func) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 233)) ;
    GALGAS_lstring var_panicName_6964 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 234)) ;
    GALGAS_lbigint var_priority_7003 = inCompiler->synthetizedAttribute_bigInteger () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 235)) ;
    ioArgument_allowedPanicList.addAssign_operation (var_hasWriteAccess_5568, var_panicName_6964, var_priority_7003  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 236)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_global_5F_var_5F_allowed_5F_routine_i14_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_21 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 181)) ;
  } break ;
  default:
    break ;
  }
  switch (select_plm_5F_syntax_22 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_guard) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 188)) ;
    switch (select_plm_5F_syntax_23 (inCompiler)) {
    case 1: {
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 193)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 194)) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 196)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_section) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 199)) ;
    switch (select_plm_5F_syntax_24 (inCompiler)) {
    case 1: {
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 204)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 205)) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 207)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_func) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 210)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 211)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_func) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 214)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 215)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 216)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 217)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_init) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 220)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 221)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_isr) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 224)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 225)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_task) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 228)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 229)) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_panic) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 232)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_func) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 233)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 234)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 235)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_module_5F_variable_i15_ (GALGAS_structurePropertyListAST & ioArgument_ioPropertyList,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("declaration-module.galgas", 18)) ;
  GALGAS_lstring var_fieldName_1070 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-module.galgas", 19)) ;
  GALGAS_lstring var_typeName_1092 ;
  switch (select_plm_5F_syntax_25 (inCompiler)) {
  case 1: {
    var_typeName_1092 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-module.galgas", 22)) ;
  } break ;
  case 2: {
    var_typeName_1092 = GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("declaration-module.galgas", 24)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("declaration-module.galgas", 26)) ;
  GALGAS_expressionAST var_initExpression_1218 ;
  nt_expression_ (var_initExpression_1218, inCompiler) ;
  ioArgument_ioPropertyList.addAssign_operation (var_fieldName_1070, GALGAS_bool (false), var_typeName_1092, GALGAS_structureVarInit::constructor_expression (var_initExpression_1218  COMMA_SOURCE_FILE ("declaration-module.galgas", 28))  COMMA_SOURCE_FILE ("declaration-module.galgas", 28)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_module_5F_variable_i15_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("declaration-module.galgas", 18)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-module.galgas", 19)) ;
  switch (select_plm_5F_syntax_25 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-module.galgas", 22)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("declaration-module.galgas", 26)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i16_ (GALGAS_ast & ioArgument_ioAST,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_module) COMMA_SOURCE_FILE ("declaration-module.galgas", 34)) ;
  GALGAS_lstring var_moduleName_1524 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-module.galgas", 35)) ;
  GALGAS_lstring var_moduleTypeName_1547 = GALGAS_lstring::constructor_new (var_moduleName_1524.mAttribute_string.add_operation (GALGAS_string ("$"), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 36)), var_moduleName_1524.mAttribute_location  COMMA_SOURCE_FILE ("declaration-module.galgas", 36)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-module.galgas", 37)) ;
  GALGAS_functionDeclarationListAST var_functionDeclarationListAST_1677 = GALGAS_functionDeclarationListAST::constructor_emptyList (SOURCE_FILE ("declaration-module.galgas", 38)) ;
  GALGAS_structurePropertyListAST var_fieldList_1722 = GALGAS_structurePropertyListAST::constructor_emptyList (SOURCE_FILE ("declaration-module.galgas", 39)) ;
  GALGAS_serviceDeclarationListAST var_serviceListAST_1773 = GALGAS_serviceDeclarationListAST::constructor_emptyList (SOURCE_FILE ("declaration-module.galgas", 40)) ;
  GALGAS_primitiveDeclarationListAST var_primitiveListAST_1828 = GALGAS_primitiveDeclarationListAST::constructor_emptyList (SOURCE_FILE ("declaration-module.galgas", 41)) ;
  GALGAS_guardDeclarationListAST var_guardListAST_1875 = GALGAS_guardDeclarationListAST::constructor_emptyList (SOURCE_FILE ("declaration-module.galgas", 42)) ;
  GALGAS_sectionDeclarationListAST var_sectionListAST_1926 = GALGAS_sectionDeclarationListAST::constructor_emptyList (SOURCE_FILE ("declaration-module.galgas", 43)) ;
  GALGAS_initList var_initList_1954 = GALGAS_initList::constructor_emptySortedList (SOURCE_FILE ("declaration-module.galgas", 44)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_26 (inCompiler)) {
    case 2: {
      nt_declaration_5F_init_ (var_initList_1954, inCompiler) ;
    } break ;
    case 3: {
      nt_isr_ (ioArgument_ioAST.mAttribute_mISRDeclarationListAST, var_moduleTypeName_1547, var_moduleName_1524.mAttribute_string, inCompiler) ;
    } break ;
    case 4: {
      nt_module_5F_variable_ (var_fieldList_1722, inCompiler) ;
    } break ;
    case 5: {
      nt_procedure_ (var_functionDeclarationListAST_1677, inCompiler) ;
    } break ;
    case 6: {
      nt_service_ (var_serviceListAST_1773, inCompiler) ;
    } break ;
    case 7: {
      nt_section_ (var_sectionListAST_1926, inCompiler) ;
    } break ;
    case 8: {
      nt_guard_ (var_guardListAST_1875, inCompiler) ;
    } break ;
    case 9: {
      nt_primitive_ (var_primitiveListAST_1828, inCompiler) ;
    } break ;
    case 10: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("declaration-module.galgas", 63)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-module.galgas", 65)) ;
  GALGAS_lstringlist var_requiredByList_2471 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-module.galgas", 67)) ;
  cEnumerator_functionDeclarationListAST enumerator_2523 (var_functionDeclarationListAST_1677, kEnumeration_up) ;
  while (enumerator_2523.hasCurrentObject ()) {
    const enumGalgasBool test_1 = enumerator_2523.current (HERE).mAttribute_mPublicFunction.boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_lstring var_routineMangledName_2596 = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (var_moduleTypeName_1547.getter_string (SOURCE_FILE ("declaration-module.galgas", 71)), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 71)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 71)).add_operation (enumerator_2523.current (HERE).mAttribute_mFunctionName.getter_string (SOURCE_FILE ("declaration-module.galgas", 71)), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 71)), enumerator_2523.current (HERE).mAttribute_mFunctionName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-module.galgas", 70)) ;
      var_routineMangledName_2596.mAttribute_string.plusAssign_operation(GALGAS_string ("("), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 74)) ;
      cEnumerator_procFormalArgumentList enumerator_2849 (enumerator_2523.current (HERE).mAttribute_mFunctionFormalArgumentList, kEnumeration_up) ;
      while (enumerator_2849.hasCurrentObject ()) {
        var_routineMangledName_2596.mAttribute_string.plusAssign_operation(extensionGetter_formalPassingModeString (enumerator_2849.current_mFormalArgumentPassingMode (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 76)), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 76)) ;
        var_routineMangledName_2596.mAttribute_string.plusAssign_operation(enumerator_2849.current_mSelector (HERE).mAttribute_string, inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 77)) ;
        var_routineMangledName_2596.mAttribute_string.plusAssign_operation(GALGAS_string (":"), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 78)) ;
        enumerator_2849.gotoNextObject () ;
      }
      var_routineMangledName_2596.mAttribute_string.plusAssign_operation(GALGAS_string (")"), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 80)) ;
      var_requiredByList_2471.addAssign_operation (var_routineMangledName_2596  COMMA_SOURCE_FILE ("declaration-module.galgas", 81)) ;
    }
    enumerator_2523.gotoNextObject () ;
  }
  cEnumerator_serviceDeclarationListAST enumerator_3178 (var_serviceListAST_1773, kEnumeration_up) ;
  while (enumerator_3178.hasCurrentObject ()) {
    GALGAS_lstring var_routineMangledName_3210 = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (var_moduleTypeName_1547.getter_string (SOURCE_FILE ("declaration-module.galgas", 86)), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 86)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 86)).add_operation (enumerator_3178.current (HERE).mAttribute_mServiceName.getter_string (SOURCE_FILE ("declaration-module.galgas", 86)), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 86)), enumerator_3178.current (HERE).mAttribute_mServiceName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-module.galgas", 85)) ;
    var_routineMangledName_3210.mAttribute_string.plusAssign_operation(GALGAS_string ("("), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 89)) ;
    cEnumerator_procFormalArgumentList enumerator_3447 (enumerator_3178.current (HERE).mAttribute_mServiceFormalArgumentList, kEnumeration_up) ;
    while (enumerator_3447.hasCurrentObject ()) {
      var_routineMangledName_3210.mAttribute_string.plusAssign_operation(extensionGetter_formalPassingModeString (enumerator_3447.current_mFormalArgumentPassingMode (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 91)), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 91)) ;
      var_routineMangledName_3210.mAttribute_string.plusAssign_operation(enumerator_3447.current_mSelector (HERE).mAttribute_string, inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 92)) ;
      var_routineMangledName_3210.mAttribute_string.plusAssign_operation(GALGAS_string (":"), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 93)) ;
      enumerator_3447.gotoNextObject () ;
    }
    var_routineMangledName_3210.mAttribute_string.plusAssign_operation(GALGAS_string (")"), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 95)) ;
    var_requiredByList_2471.addAssign_operation (var_routineMangledName_3210  COMMA_SOURCE_FILE ("declaration-module.galgas", 96)) ;
    enumerator_3178.gotoNextObject () ;
  }
  cEnumerator_guardDeclarationListAST enumerator_3750 (var_guardListAST_1875, kEnumeration_up) ;
  while (enumerator_3750.hasCurrentObject ()) {
    GALGAS_lstring var_routineMangledName_3782 = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (var_moduleTypeName_1547.getter_string (SOURCE_FILE ("declaration-module.galgas", 100)), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 100)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 100)).add_operation (enumerator_3750.current (HERE).mAttribute_mGuardName.getter_string (SOURCE_FILE ("declaration-module.galgas", 100)), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 100)), enumerator_3750.current (HERE).mAttribute_mGuardName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-module.galgas", 99)) ;
    var_routineMangledName_3782.mAttribute_string.plusAssign_operation(GALGAS_string ("("), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 103)) ;
    cEnumerator_procFormalArgumentList enumerator_4007 (enumerator_3750.current (HERE).mAttribute_mGuardFormalArgumentList, kEnumeration_up) ;
    while (enumerator_4007.hasCurrentObject ()) {
      var_routineMangledName_3782.mAttribute_string.plusAssign_operation(extensionGetter_formalPassingModeString (enumerator_4007.current_mFormalArgumentPassingMode (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 105)), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 105)) ;
      var_routineMangledName_3782.mAttribute_string.plusAssign_operation(enumerator_4007.current_mSelector (HERE).mAttribute_string, inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 106)) ;
      var_routineMangledName_3782.mAttribute_string.plusAssign_operation(GALGAS_string (":"), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 107)) ;
      enumerator_4007.gotoNextObject () ;
    }
    var_routineMangledName_3782.mAttribute_string.plusAssign_operation(GALGAS_string (")"), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 109)) ;
    var_requiredByList_2471.addAssign_operation (var_routineMangledName_3782  COMMA_SOURCE_FILE ("declaration-module.galgas", 110)) ;
    enumerator_3750.gotoNextObject () ;
  }
  cEnumerator_primitiveDeclarationListAST enumerator_4318 (var_primitiveListAST_1828, kEnumeration_up) ;
  while (enumerator_4318.hasCurrentObject ()) {
    GALGAS_lstring var_routineMangledName_4350 = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (var_moduleTypeName_1547.getter_string (SOURCE_FILE ("declaration-module.galgas", 114)), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 114)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 114)).add_operation (enumerator_4318.current (HERE).mAttribute_mPrimitiveName.getter_string (SOURCE_FILE ("declaration-module.galgas", 114)), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 114)), enumerator_4318.current (HERE).mAttribute_mPrimitiveName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-module.galgas", 113)) ;
    var_routineMangledName_4350.mAttribute_string.plusAssign_operation(GALGAS_string ("("), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 117)) ;
    cEnumerator_procFormalArgumentList enumerator_4599 (enumerator_4318.current (HERE).mAttribute_mPrimitiveFormalArgumentList, kEnumeration_up) ;
    while (enumerator_4599.hasCurrentObject ()) {
      var_routineMangledName_4350.mAttribute_string.plusAssign_operation(extensionGetter_formalPassingModeString (enumerator_4599.current_mFormalArgumentPassingMode (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-module.galgas", 119)), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 119)) ;
      var_routineMangledName_4350.mAttribute_string.plusAssign_operation(enumerator_4599.current_mSelector (HERE).mAttribute_string, inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 120)) ;
      var_routineMangledName_4350.mAttribute_string.plusAssign_operation(GALGAS_string (":"), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 121)) ;
      enumerator_4599.gotoNextObject () ;
    }
    var_routineMangledName_4350.mAttribute_string.plusAssign_operation(GALGAS_string (")"), inCompiler  COMMA_SOURCE_FILE ("declaration-module.galgas", 123)) ;
    var_requiredByList_2471.addAssign_operation (var_routineMangledName_4350  COMMA_SOURCE_FILE ("declaration-module.galgas", 124)) ;
    enumerator_4318.gotoNextObject () ;
  }
  cEnumerator_initList enumerator_4897 (var_initList_1954, kEnumeration_up) ;
  while (enumerator_4897.hasCurrentObject ()) {
    ioArgument_ioAST.mAttribute_mInitList.addAssign_operation (enumerator_4897.current (HERE).mAttribute_mInitLocation, var_moduleTypeName_1547, var_moduleName_1524.mAttribute_string, var_requiredByList_2471, enumerator_4897.current (HERE).mAttribute_mInstructionList, enumerator_4897.current (HERE).mAttribute_mEndOfInitLocation, enumerator_4897.current (HERE).mAttribute_mPriority  COMMA_SOURCE_FILE ("declaration-module.galgas", 127)) ;
    enumerator_4897.gotoNextObject () ;
  }
  ioArgument_ioAST.mAttribute_mDeclarationList.addAssign_operation (GALGAS_structureDeclaration::constructor_new (var_moduleTypeName_1547, GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-module.galgas", 139)), var_fieldList_1722, var_functionDeclarationListAST_1677, var_serviceListAST_1773, var_sectionListAST_1926, var_primitiveListAST_1828, var_guardListAST_1875  COMMA_SOURCE_FILE ("declaration-module.galgas", 137))  COMMA_SOURCE_FILE ("declaration-module.galgas", 137)) ;
  ioArgument_ioAST.mAttribute_mDeclarationList.addAssign_operation (GALGAS_moduleDeclarationAST::constructor_new (var_moduleName_1524  COMMA_SOURCE_FILE ("declaration-module.galgas", 148))  COMMA_SOURCE_FILE ("declaration-module.galgas", 148)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i16_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_module) COMMA_SOURCE_FILE ("declaration-module.galgas", 34)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-module.galgas", 35)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-module.galgas", 37)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_26 (inCompiler)) {
    case 2: {
      nt_declaration_5F_init_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_isr_parse (inCompiler) ;
    } break ;
    case 4: {
      nt_module_5F_variable_parse (inCompiler) ;
    } break ;
    case 5: {
      nt_procedure_parse (inCompiler) ;
    } break ;
    case 6: {
      nt_service_parse (inCompiler) ;
    } break ;
    case 7: {
      nt_section_parse (inCompiler) ;
    } break ;
    case 8: {
      nt_guard_parse (inCompiler) ;
    } break ;
    case 9: {
      nt_primitive_parse (inCompiler) ;
    } break ;
    case 10: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("declaration-module.galgas", 63)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-module.galgas", 65)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i17_ (GALGAS_ast & ioArgument_ioAST,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_task) COMMA_SOURCE_FILE ("declaration-task.galgas", 52)) ;
  GALGAS_lstring var_taskName_2034 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-task.galgas", 53)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_priority) COMMA_SOURCE_FILE ("declaration-task.galgas", 54)) ;
  GALGAS_lbigint var_priority_2086 = inCompiler->synthetizedAttribute_bigInteger () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-task.galgas", 55)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_stackSize) COMMA_SOURCE_FILE ("declaration-task.galgas", 56)) ;
  GALGAS_lbigint var_stackSize_2140 = inCompiler->synthetizedAttribute_bigInteger () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-task.galgas", 57)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-task.galgas", 58)) ;
  GALGAS_taskVarListAST var_taskVarList_2180 = GALGAS_taskVarListAST::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 59)) ;
  GALGAS_functionDeclarationListAST var_taskProcList_2230 = GALGAS_functionDeclarationListAST::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 60)) ;
  GALGAS_taskInitListAST var_taskInitListAST_2272 = GALGAS_taskInitListAST::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 61)) ;
  GALGAS_syncInstructionBranchList var_branchList_2319 = GALGAS_syncInstructionBranchList::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 62)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_27 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("declaration-task.galgas", 65)) ;
      GALGAS_lstring var_varName_2389 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-task.galgas", 66)) ;
      GALGAS_lstring var_typeName_2413 ;
      switch (select_plm_5F_syntax_28 (inCompiler)) {
      case 1: {
        var_typeName_2413 = GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("declaration-task.galgas", 69)) ;
      } break ;
      case 2: {
        var_typeName_2413 = inCompiler->synthetizedAttribute_tokenString () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-task.galgas", 71)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("declaration-task.galgas", 73)) ;
      GALGAS_expressionAST var_initExpression_2553 ;
      nt_expression_ (var_initExpression_2553, inCompiler) ;
      var_taskVarList_2180.addAssign_operation (var_varName_2389, var_typeName_2413, var_initExpression_2553  COMMA_SOURCE_FILE ("declaration-task.galgas", 75)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_func) COMMA_SOURCE_FILE ("declaration-task.galgas", 77)) ;
      GALGAS_lstring var_procName_2665 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-task.galgas", 78)) ;
      GALGAS_procFormalArgumentList var_formalArgumentList_2764 ;
      nt_procedure_5F_formal_5F_arguments_ (var_formalArgumentList_2764, inCompiler) ;
      GALGAS_lstring var_returnTypeName_2794 ;
      switch (select_plm_5F_syntax_29 (inCompiler)) {
      case 1: {
        var_returnTypeName_2794 = GALGAS_string::makeEmptyString ().getter_here (inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 82)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3E_) COMMA_SOURCE_FILE ("declaration-task.galgas", 84)) ;
        var_returnTypeName_2794 = inCompiler->synthetizedAttribute_tokenString () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-task.galgas", 85)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-task.galgas", 87)) ;
      GALGAS_instructionListAST var_instructionList_2962 ;
      nt_instructionList_ (var_instructionList_2962, inCompiler) ;
      GALGAS_location var_endOfProc_2982 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 89)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-task.galgas", 90)) ;
      var_taskProcList_2230.addAssign_operation (GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 91)), GALGAS_bool (false), var_procName_2665, GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 91)), var_formalArgumentList_2764, var_returnTypeName_2794, var_instructionList_2962, var_endOfProc_2982  COMMA_SOURCE_FILE ("declaration-task.galgas", 91)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_init) COMMA_SOURCE_FILE ("declaration-task.galgas", 93)) ;
      GALGAS_lbigint var_priority_3182 = inCompiler->synthetizedAttribute_bigInteger () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-task.galgas", 94)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-task.galgas", 95)) ;
      GALGAS_instructionListAST var_instructionList_3237 ;
      nt_instructionList_ (var_instructionList_3237, inCompiler) ;
      GALGAS_location var_endOfInit_3257 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 97)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-task.galgas", 98)) ;
      var_taskInitListAST_2272.addAssign_operation (var_priority_3182, var_instructionList_3237, var_endOfInit_3257  COMMA_SOURCE_FILE ("declaration-task.galgas", 99)) ;
    } break ;
    case 5: {
      GALGAS_guardedCommand var_guardedCommand_3417 ;
      nt_guarded_5F_command_ (var_guardedCommand_3417, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-task.galgas", 102)) ;
      GALGAS_instructionListAST var_instructionList_3472 ;
      nt_instructionList_ (var_instructionList_3472, inCompiler) ;
      GALGAS_location var_endOfInstructions_3500 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 104)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-task.galgas", 105)) ;
      var_branchList_2319.addAssign_operation (var_guardedCommand_3417, var_instructionList_3472, var_endOfInstructions_3500  COMMA_SOURCE_FILE ("declaration-task.galgas", 106)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  GALGAS_location var_endOfTask_3625 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 108)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-task.galgas", 109)) ;
  ioArgument_ioAST.mAttribute_mTaskList.addAssign_operation (var_taskName_2034, var_priority_2086, var_stackSize_2140, var_taskVarList_2180, var_taskProcList_2230, var_taskInitListAST_2272, var_branchList_2319, var_endOfTask_3625  COMMA_SOURCE_FILE ("declaration-task.galgas", 110)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i17_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_task) COMMA_SOURCE_FILE ("declaration-task.galgas", 52)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-task.galgas", 53)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_priority) COMMA_SOURCE_FILE ("declaration-task.galgas", 54)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-task.galgas", 55)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_stackSize) COMMA_SOURCE_FILE ("declaration-task.galgas", 56)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-task.galgas", 57)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-task.galgas", 58)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_27 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("declaration-task.galgas", 65)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-task.galgas", 66)) ;
      switch (select_plm_5F_syntax_28 (inCompiler)) {
      case 1: {
      } break ;
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-task.galgas", 71)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("declaration-task.galgas", 73)) ;
      nt_expression_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_func) COMMA_SOURCE_FILE ("declaration-task.galgas", 77)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-task.galgas", 78)) ;
      nt_procedure_5F_formal_5F_arguments_parse (inCompiler) ;
      switch (select_plm_5F_syntax_29 (inCompiler)) {
      case 1: {
      } break ;
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3E_) COMMA_SOURCE_FILE ("declaration-task.galgas", 84)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-task.galgas", 85)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-task.galgas", 87)) ;
      nt_instructionList_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-task.galgas", 90)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_init) COMMA_SOURCE_FILE ("declaration-task.galgas", 93)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-task.galgas", 94)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-task.galgas", 95)) ;
      nt_instructionList_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-task.galgas", 98)) ;
    } break ;
    case 5: {
      nt_guarded_5F_command_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-task.galgas", 102)) ;
      nt_instructionList_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-task.galgas", 105)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-task.galgas", 109)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i18_ (GALGAS_ast & ioArgument_ioAST,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_panic) COMMA_SOURCE_FILE ("panic.galgas", 24)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_func) COMMA_SOURCE_FILE ("panic.galgas", 25)) ;
  GALGAS_lstring var_panicClauseName_1188 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("panic.galgas", 26)) ;
  GALGAS_lbigint var_priority_1216 = inCompiler->synthetizedAttribute_bigInteger () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("panic.galgas", 27)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("panic.galgas", 28)) ;
  GALGAS_instructionListAST var_instructionList_1267 ;
  nt_instructionList_ (var_instructionList_1267, inCompiler) ;
  GALGAS_location var_endOfInstructionList_1296 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("panic.galgas", 30)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("panic.galgas", 31)) ;
  ioArgument_ioAST.mAttribute_mPanicClauses.addAssign_operation (var_panicClauseName_1188, var_instructionList_1267, var_endOfInstructionList_1296, var_priority_1216, var_priority_1216.mAttribute_location  COMMA_SOURCE_FILE ("panic.galgas", 32)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i18_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_panic) COMMA_SOURCE_FILE ("panic.galgas", 24)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_func) COMMA_SOURCE_FILE ("panic.galgas", 25)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("panic.galgas", 26)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("panic.galgas", 27)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("panic.galgas", 28)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("panic.galgas", 31)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i19_ (GALGAS_ast & ioArgument_ioAST,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_boot) COMMA_SOURCE_FILE ("declaration-boot.galgas", 24)) ;
  GALGAS_lbigint var_priority_1152 = inCompiler->synthetizedAttribute_bigInteger () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-boot.galgas", 25)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-boot.galgas", 26)) ;
  GALGAS_instructionListAST var_instructionList_1203 ;
  nt_instructionList_ (var_instructionList_1203, inCompiler) ;
  GALGAS_location var_endOfInit_1221 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-boot.galgas", 28)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-boot.galgas", 29)) ;
  ioArgument_ioAST.mAttribute_mBootList.addAssign_operation (var_priority_1152.mAttribute_location, var_instructionList_1203, var_endOfInit_1221, var_priority_1152.mAttribute_bigint, var_priority_1152.mAttribute_location  COMMA_SOURCE_FILE ("declaration-boot.galgas", 30)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i19_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_boot) COMMA_SOURCE_FILE ("declaration-boot.galgas", 24)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-boot.galgas", 25)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-boot.galgas", 26)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-boot.galgas", 29)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i20_ (GALGAS_ast & ioArgument_ioAST,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  nt_declaration_5F_init_ (ioArgument_ioAST.mAttribute_mInitList, inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i20_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_declaration_5F_init_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_5F_init_i21_ (GALGAS_initList & ioArgument_ioInitList,
                                                                         C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_init) COMMA_SOURCE_FILE ("declaration-init.galgas", 32)) ;
  GALGAS_lbigint var_priority_1480 = inCompiler->synthetizedAttribute_bigInteger () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-init.galgas", 33)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-init.galgas", 34)) ;
  GALGAS_instructionListAST var_instructionList_1531 ;
  nt_instructionList_ (var_instructionList_1531, inCompiler) ;
  GALGAS_location var_endOfInit_1549 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-init.galgas", 36)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-init.galgas", 37)) ;
  ioArgument_ioInitList.addAssign_operation (var_priority_1480.mAttribute_location, GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("declaration-init.galgas", 40)), GALGAS_string::makeEmptyString (), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-init.galgas", 42)), var_instructionList_1531, var_endOfInit_1549, var_priority_1480  COMMA_SOURCE_FILE ("declaration-init.galgas", 38)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_5F_init_i21_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_init) COMMA_SOURCE_FILE ("declaration-init.galgas", 32)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("declaration-init.galgas", 33)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-init.galgas", 34)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-init.galgas", 37)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_procedure_i22_ (GALGAS_functionDeclarationListAST & ioArgument_ioProcListAST,
                                                               C_Lexique_plm_5F_lexique * inCompiler) {
  GALGAS_bool var_public_2632 ;
  GALGAS_lstringlist var_procModeList_2666 ;
  GALGAS_lstring var_procName_2691 ;
  GALGAS_lstringlist var_attributeList_2727 ;
  GALGAS_procFormalArgumentList var_procFormalArgumentList_2777 ;
  nt_procedure_5F_header_ (var_public_2632, var_procModeList_2666, var_procName_2691, var_attributeList_2727, var_procFormalArgumentList_2777, inCompiler) ;
  GALGAS_lstring var_returnTypeName_2805 ;
  switch (select_plm_5F_syntax_30 (inCompiler)) {
  case 1: {
    var_returnTypeName_2805 = GALGAS_string::makeEmptyString ().getter_here (inCompiler COMMA_SOURCE_FILE ("declaration-func.galgas", 73)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3E_) COMMA_SOURCE_FILE ("declaration-func.galgas", 75)) ;
    var_returnTypeName_2805 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-func.galgas", 76)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-func.galgas", 78)) ;
  GALGAS_instructionListAST var_instructionList_2957 ;
  nt_instructionList_ (var_instructionList_2957, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-func.galgas", 80)) ;
  ioArgument_ioProcListAST.addAssign_operation (var_procModeList_2666, var_public_2632, var_procName_2691, var_attributeList_2727, var_procFormalArgumentList_2777, var_returnTypeName_2805, var_instructionList_2957, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-func.galgas", 89))  COMMA_SOURCE_FILE ("declaration-func.galgas", 81)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_procedure_i22_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_procedure_5F_header_parse (inCompiler) ;
  switch (select_plm_5F_syntax_30 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3E_) COMMA_SOURCE_FILE ("declaration-func.galgas", 75)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-func.galgas", 76)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-func.galgas", 78)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-func.galgas", 80)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_procedure_5F_header_i23_ (GALGAS_bool & outArgument_outPublic,
                                                                         GALGAS_lstringlist & outArgument_outProcModeList,
                                                                         GALGAS_lstring & outArgument_outProcName,
                                                                         GALGAS_lstringlist & outArgument_outAttributeList,
                                                                         GALGAS_procFormalArgumentList & outArgument_outProcFormalArgumentList,
                                                                         C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outPublic.drop () ; // Release 'out' argument
  outArgument_outProcModeList.drop () ; // Release 'out' argument
  outArgument_outProcName.drop () ; // Release 'out' argument
  outArgument_outAttributeList.drop () ; // Release 'out' argument
  outArgument_outProcFormalArgumentList.drop () ; // Release 'out' argument
  switch (select_plm_5F_syntax_31 (inCompiler)) {
  case 1: {
    outArgument_outPublic = GALGAS_bool (false) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("declaration-func.galgas", 104)) ;
    outArgument_outPublic = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_func) COMMA_SOURCE_FILE ("declaration-func.galgas", 107)) ;
  outArgument_outProcModeList = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-func.galgas", 108)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_lstring var_procMode_3685 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__60_mode) COMMA_SOURCE_FILE ("declaration-func.galgas", 110)) ;
    outArgument_outProcModeList.addAssign_operation (var_procMode_3685  COMMA_SOURCE_FILE ("declaration-func.galgas", 111)) ;
    switch (select_plm_5F_syntax_32 (inCompiler)) {
    case 2: {
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  outArgument_outProcName = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-func.galgas", 114)) ;
  outArgument_outAttributeList = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-func.galgas", 115)) ;
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    switch (select_plm_5F_syntax_33 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attribute_3849 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-func.galgas", 118)) ;
      outArgument_outAttributeList.addAssign_operation (var_attribute_3849  COMMA_SOURCE_FILE ("declaration-func.galgas", 119)) ;
    } break ;
    default:
      repeatFlag_1 = false ;
      break ;
    }
  }
  nt_procedure_5F_formal_5F_arguments_ (outArgument_outProcFormalArgumentList, inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_procedure_5F_header_i23_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_31 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("declaration-func.galgas", 104)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_func) COMMA_SOURCE_FILE ("declaration-func.galgas", 107)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__60_mode) COMMA_SOURCE_FILE ("declaration-func.galgas", 110)) ;
    switch (select_plm_5F_syntax_32 (inCompiler)) {
    case 2: {
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-func.galgas", 114)) ;
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    switch (select_plm_5F_syntax_33 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-func.galgas", 118)) ;
    } break ;
    default:
      repeatFlag_1 = false ;
      break ;
    }
  }
  nt_procedure_5F_formal_5F_arguments_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_procedure_5F_formal_5F_arguments_i24_ (GALGAS_procFormalArgumentList & outArgument_outProcFormalArgumentList,
                                                                                      C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outProcFormalArgumentList.drop () ; // Release 'out' argument
  outArgument_outProcFormalArgumentList = GALGAS_procFormalArgumentList::constructor_emptyList (SOURCE_FILE ("declaration-func.galgas", 127)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__28_) COMMA_SOURCE_FILE ("declaration-func.galgas", 128)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_34 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_selector_4290 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21_) COMMA_SOURCE_FILE ("declaration-func.galgas", 131)) ;
      GALGAS_lstring var_formalArgumentName_4333 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-func.galgas", 132)) ;
      GALGAS_lstring var_formalArgumentTypeName_4376 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-func.galgas", 133)) ;
      outArgument_outProcFormalArgumentList.addAssign_operation (GALGAS_procFormalArgumentPassingMode::constructor_output (SOURCE_FILE ("declaration-func.galgas", 135)), var_selector_4290, var_formalArgumentTypeName_4376, var_formalArgumentName_4333  COMMA_SOURCE_FILE ("declaration-func.galgas", 134)) ;
    } break ;
    case 3: {
      GALGAS_lstring var_selector_4571 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3F__21_) COMMA_SOURCE_FILE ("declaration-func.galgas", 140)) ;
      GALGAS_lstring var_formalArgumentName_4614 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-func.galgas", 141)) ;
      GALGAS_lstring var_formalArgumentTypeName_4657 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-func.galgas", 142)) ;
      outArgument_outProcFormalArgumentList.addAssign_operation (GALGAS_procFormalArgumentPassingMode::constructor_inputOutput (SOURCE_FILE ("declaration-func.galgas", 144)), var_selector_4571, var_formalArgumentTypeName_4657, var_formalArgumentName_4614  COMMA_SOURCE_FILE ("declaration-func.galgas", 143)) ;
    } break ;
    case 4: {
      GALGAS_lstring var_selector_4856 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3F_) COMMA_SOURCE_FILE ("declaration-func.galgas", 149)) ;
      GALGAS_lstring var_formalArgumentName_4899 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-func.galgas", 150)) ;
      GALGAS_lstring var_formalArgumentTypeName_4942 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-func.galgas", 151)) ;
      outArgument_outProcFormalArgumentList.addAssign_operation (GALGAS_procFormalArgumentPassingMode::constructor_input (SOURCE_FILE ("declaration-func.galgas", 153)), var_selector_4856, var_formalArgumentTypeName_4942, var_formalArgumentName_4899  COMMA_SOURCE_FILE ("declaration-func.galgas", 152)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__29_) COMMA_SOURCE_FILE ("declaration-func.galgas", 158)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_procedure_5F_formal_5F_arguments_i24_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__28_) COMMA_SOURCE_FILE ("declaration-func.galgas", 128)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_34 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21_) COMMA_SOURCE_FILE ("declaration-func.galgas", 131)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-func.galgas", 132)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-func.galgas", 133)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3F__21_) COMMA_SOURCE_FILE ("declaration-func.galgas", 140)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-func.galgas", 141)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-func.galgas", 142)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3F_) COMMA_SOURCE_FILE ("declaration-func.galgas", 149)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-func.galgas", 150)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-func.galgas", 151)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__29_) COMMA_SOURCE_FILE ("declaration-func.galgas", 158)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i25_ (GALGAS_ast & ioArgument_ioAST,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_required) COMMA_SOURCE_FILE ("declaration-required-proc.galgas", 21)) ;
  GALGAS_bool var_public_1181 ;
  GALGAS_lstringlist var_requiredModeList_1219 ;
  GALGAS_lstring var_procName_1244 ;
  GALGAS_lstringlist var_attributeList_1287 ;
  GALGAS_procFormalArgumentList var_procFormalArgumentList_1337 ;
  nt_procedure_5F_header_ (var_public_1181, var_requiredModeList_1219, var_procName_1244, var_attributeList_1287, var_procFormalArgumentList_1337, inCompiler) ;
  ioArgument_ioAST.mAttribute_mRequiredProcList.addAssign_operation (var_procName_1244, var_requiredModeList_1219, var_procFormalArgumentList_1337, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-required-proc.galgas", 28))  COMMA_SOURCE_FILE ("declaration-required-proc.galgas", 28)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i25_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_required) COMMA_SOURCE_FILE ("declaration-required-proc.galgas", 21)) ;
  nt_procedure_5F_header_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i26_ (GALGAS_ast & ioArgument_ioAST,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_extern) COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 23)) ;
  GALGAS_bool var_public_1239 ;
  GALGAS_lstringlist var_requiredModeList_1277 ;
  GALGAS_lstring var_procName_1302 ;
  GALGAS_lstringlist var_attributeList_1345 ;
  GALGAS_procFormalArgumentList var_procFormalArgumentList_1395 ;
  nt_procedure_5F_header_ (var_public_1239, var_requiredModeList_1277, var_procName_1302, var_attributeList_1345, var_procFormalArgumentList_1395, inCompiler) ;
  GALGAS_lstring var_returnTypeName_1423 ;
  switch (select_plm_5F_syntax_35 (inCompiler)) {
  case 1: {
    var_returnTypeName_1423 = GALGAS_string::makeEmptyString ().getter_here (inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 32)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3E_) COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 34)) ;
    var_returnTypeName_1423 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 35)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 37)) ;
  GALGAS_lstring var_llvmName_1561 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__22_string_22_) COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 38)) ;
  ioArgument_ioAST.mAttribute_mExternProcList.addAssign_operation (var_procName_1302, var_requiredModeList_1277, var_procFormalArgumentList_1395, var_returnTypeName_1423, var_llvmName_1561, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 39))  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 39)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i26_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_extern) COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 23)) ;
  nt_procedure_5F_header_parse (inCompiler) ;
  switch (select_plm_5F_syntax_35 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3E_) COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 34)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 35)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 37)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__22_string_22_) COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 38)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_isr_i27_ (GALGAS_isrDeclarationListAST & ioArgument_ioISRListAST,
                                                         const GALGAS_lstring constinArgument_inSelfTypeName,
                                                         const GALGAS_string constinArgument_inGlobalVarName,
                                                         C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_isr) COMMA_SOURCE_FILE ("declaration-isr.galgas", 23)) ;
  GALGAS_lstring var_sectionName_1288 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-isr.galgas", 24)) ;
  GALGAS_lstringlist var_attributeList_1319 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-isr.galgas", 25)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_36 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attribute_1379 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-isr.galgas", 28)) ;
      var_attributeList_1319.addAssign_operation (var_attribute_1379  COMMA_SOURCE_FILE ("declaration-isr.galgas", 29)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-isr.galgas", 31)) ;
  GALGAS_instructionListAST var_instructionList_1472 ;
  nt_instructionList_ (var_instructionList_1472, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-isr.galgas", 33)) ;
  ioArgument_ioISRListAST.addAssign_operation (var_sectionName_1288, constinArgument_inSelfTypeName, constinArgument_inGlobalVarName, var_attributeList_1319, var_instructionList_1472, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-isr.galgas", 40))  COMMA_SOURCE_FILE ("declaration-isr.galgas", 34)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_isr_i27_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_isr) COMMA_SOURCE_FILE ("declaration-isr.galgas", 23)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-isr.galgas", 24)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_36 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-isr.galgas", 28)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-isr.galgas", 31)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-isr.galgas", 33)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_section_i28_ (GALGAS_sectionDeclarationListAST & ioArgument_ioSectionListAST,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  GALGAS_bool var_public_1235 ;
  switch (select_plm_5F_syntax_37 (inCompiler)) {
  case 1: {
    var_public_1235 = GALGAS_bool (false) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("declaration-section.galgas", 28)) ;
    var_public_1235 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_section) COMMA_SOURCE_FILE ("declaration-section.galgas", 31)) ;
  GALGAS_lstring var_sectionName_1365 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-section.galgas", 32)) ;
  GALGAS_lstringlist var_attributeList_1396 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-section.galgas", 33)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_38 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attribute_1456 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-section.galgas", 36)) ;
      var_attributeList_1396.addAssign_operation (var_attribute_1456  COMMA_SOURCE_FILE ("declaration-section.galgas", 37)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  GALGAS_procFormalArgumentList var_sectionFormalArgumentList_1578 ;
  nt_procedure_5F_formal_5F_arguments_ (var_sectionFormalArgumentList_1578, inCompiler) ;
  GALGAS_lstring var_returnTypeName_1606 ;
  switch (select_plm_5F_syntax_39 (inCompiler)) {
  case 1: {
    var_returnTypeName_1606 = GALGAS_string::makeEmptyString ().getter_here (inCompiler COMMA_SOURCE_FILE ("declaration-section.galgas", 42)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3E_) COMMA_SOURCE_FILE ("declaration-section.galgas", 44)) ;
    var_returnTypeName_1606 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-section.galgas", 45)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-section.galgas", 47)) ;
  GALGAS_instructionListAST var_instructionList_1758 ;
  nt_instructionList_ (var_instructionList_1758, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-section.galgas", 49)) ;
  ioArgument_ioSectionListAST.addAssign_operation (var_sectionName_1365, var_public_1235, var_attributeList_1396, var_sectionFormalArgumentList_1578, var_returnTypeName_1606, var_instructionList_1758, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-section.galgas", 57))  COMMA_SOURCE_FILE ("declaration-section.galgas", 50)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_section_i28_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_37 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("declaration-section.galgas", 28)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_section) COMMA_SOURCE_FILE ("declaration-section.galgas", 31)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-section.galgas", 32)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_38 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-section.galgas", 36)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  nt_procedure_5F_formal_5F_arguments_parse (inCompiler) ;
  switch (select_plm_5F_syntax_39 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3E_) COMMA_SOURCE_FILE ("declaration-section.galgas", 44)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-section.galgas", 45)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-section.galgas", 47)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-section.galgas", 49)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_service_i29_ (GALGAS_serviceDeclarationListAST & ioArgument_ioServiceListAST,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  GALGAS_bool var_public_1235 ;
  switch (select_plm_5F_syntax_40 (inCompiler)) {
  case 1: {
    var_public_1235 = GALGAS_bool (false) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("declaration-service.galgas", 28)) ;
    var_public_1235 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_service) COMMA_SOURCE_FILE ("declaration-service.galgas", 31)) ;
  GALGAS_lstring var_serviceName_1365 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-service.galgas", 32)) ;
  GALGAS_lstringlist var_attributeList_1396 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-service.galgas", 33)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_41 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attribute_1456 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-service.galgas", 36)) ;
      var_attributeList_1396.addAssign_operation (var_attribute_1456  COMMA_SOURCE_FILE ("declaration-service.galgas", 37)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  GALGAS_procFormalArgumentList var_serviceFormalArgumentList_1578 ;
  nt_procedure_5F_formal_5F_arguments_ (var_serviceFormalArgumentList_1578, inCompiler) ;
  GALGAS_lstring var_returnTypeName_1606 ;
  switch (select_plm_5F_syntax_42 (inCompiler)) {
  case 1: {
    var_returnTypeName_1606 = GALGAS_string::makeEmptyString ().getter_here (inCompiler COMMA_SOURCE_FILE ("declaration-service.galgas", 42)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3E_) COMMA_SOURCE_FILE ("declaration-service.galgas", 44)) ;
    var_returnTypeName_1606 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-service.galgas", 45)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-service.galgas", 47)) ;
  GALGAS_instructionListAST var_instructionList_1758 ;
  nt_instructionList_ (var_instructionList_1758, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-service.galgas", 49)) ;
  ioArgument_ioServiceListAST.addAssign_operation (var_serviceName_1365, var_public_1235, var_attributeList_1396, var_serviceFormalArgumentList_1578, var_returnTypeName_1606, var_instructionList_1758, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-service.galgas", 57))  COMMA_SOURCE_FILE ("declaration-service.galgas", 50)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_service_i29_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_40 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("declaration-service.galgas", 28)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_service) COMMA_SOURCE_FILE ("declaration-service.galgas", 31)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-service.galgas", 32)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_41 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-service.galgas", 36)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  nt_procedure_5F_formal_5F_arguments_parse (inCompiler) ;
  switch (select_plm_5F_syntax_42 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3E_) COMMA_SOURCE_FILE ("declaration-service.galgas", 44)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-service.galgas", 45)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-service.galgas", 47)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-service.galgas", 49)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primitive_i30_ (GALGAS_primitiveDeclarationListAST & ioArgument_ioPrimitiveListAST,
                                                               C_Lexique_plm_5F_lexique * inCompiler) {
  GALGAS_bool var_public_1260 ;
  switch (select_plm_5F_syntax_43 (inCompiler)) {
  case 1: {
    var_public_1260 = GALGAS_bool (false) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 28)) ;
    var_public_1260 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_primitive) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 31)) ;
  GALGAS_lstring var_primitiveName_1394 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 32)) ;
  GALGAS_lstringlist var_attributeList_1425 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-primitive.galgas", 33)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_44 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attribute_1485 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 36)) ;
      var_attributeList_1425.addAssign_operation (var_attribute_1485  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 37)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  GALGAS_procFormalArgumentList var_primitiveFormalArgumentList_1609 ;
  nt_procedure_5F_formal_5F_arguments_ (var_primitiveFormalArgumentList_1609, inCompiler) ;
  GALGAS_lstring var_returnTypeName_1637 ;
  switch (select_plm_5F_syntax_45 (inCompiler)) {
  case 1: {
    var_returnTypeName_1637 = GALGAS_string::makeEmptyString ().getter_here (inCompiler COMMA_SOURCE_FILE ("declaration-primitive.galgas", 42)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3E_) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 44)) ;
    var_returnTypeName_1637 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 45)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 47)) ;
  GALGAS_instructionListAST var_instructionList_1789 ;
  nt_instructionList_ (var_instructionList_1789, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 49)) ;
  ioArgument_ioPrimitiveListAST.addAssign_operation (var_primitiveName_1394, var_public_1260, var_attributeList_1425, var_primitiveFormalArgumentList_1609, var_returnTypeName_1637, var_instructionList_1789, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 57))  COMMA_SOURCE_FILE ("declaration-primitive.galgas", 50)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primitive_i30_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_43 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 28)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_primitive) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 31)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 32)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_44 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 36)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  nt_procedure_5F_formal_5F_arguments_parse (inCompiler) ;
  switch (select_plm_5F_syntax_45 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3E_) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 44)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 45)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 47)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-primitive.galgas", 49)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_guard_i31_ (GALGAS_guardDeclarationListAST & ioArgument_ioGuardListAST,
                                                           C_Lexique_plm_5F_lexique * inCompiler) {
  GALGAS_bool var_public_1430 ;
  switch (select_plm_5F_syntax_46 (inCompiler)) {
  case 1: {
    var_public_1430 = GALGAS_bool (false) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("declaration-guard.galgas", 35)) ;
    var_public_1430 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_guard) COMMA_SOURCE_FILE ("declaration-guard.galgas", 38)) ;
  GALGAS_lstring var_guardName_1556 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-guard.galgas", 39)) ;
  GALGAS_lstringlist var_attributeList_1587 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-guard.galgas", 40)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_47 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attribute_1647 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-guard.galgas", 43)) ;
      var_attributeList_1587.addAssign_operation (var_attribute_1647  COMMA_SOURCE_FILE ("declaration-guard.galgas", 44)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  GALGAS_procFormalArgumentList var_guardFormalArgumentList_1767 ;
  nt_procedure_5F_formal_5F_arguments_ (var_guardFormalArgumentList_1767, inCompiler) ;
  GALGAS_guardKind var_guardKind_1792 ;
  switch (select_plm_5F_syntax_48 (inCompiler)) {
  case 1: {
    var_guardKind_1792 = GALGAS_guardKind::constructor_baseGuard (SOURCE_FILE ("declaration-guard.galgas", 49)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("declaration-guard.galgas", 51)) ;
    GALGAS_callInstructionAST var_instruction_1889 ;
    nt_procedure_5F_call_ (var_instruction_1889, inCompiler) ;
    var_guardKind_1792 = GALGAS_guardKind::constructor_convenienceGuard (var_instruction_1889  COMMA_SOURCE_FILE ("declaration-guard.galgas", 53)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-guard.galgas", 55)) ;
  GALGAS_instructionListAST var_instructionList_2004 ;
  nt_instructionList_ (var_instructionList_2004, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-guard.galgas", 57)) ;
  ioArgument_ioGuardListAST.addAssign_operation (var_guardName_1556, var_public_1430, var_attributeList_1587, var_guardFormalArgumentList_1767, var_guardKind_1792, var_instructionList_2004, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 65))  COMMA_SOURCE_FILE ("declaration-guard.galgas", 58)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_guard_i31_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_46 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_public) COMMA_SOURCE_FILE ("declaration-guard.galgas", 35)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_guard) COMMA_SOURCE_FILE ("declaration-guard.galgas", 38)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("declaration-guard.galgas", 39)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_47 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__40_attribute) COMMA_SOURCE_FILE ("declaration-guard.galgas", 43)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  nt_procedure_5F_formal_5F_arguments_parse (inCompiler) ;
  switch (select_plm_5F_syntax_48 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("declaration-guard.galgas", 51)) ;
    nt_procedure_5F_call_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("declaration-guard.galgas", 55)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("declaration-guard.galgas", 57)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i32_ (GALGAS_ast & ioArgument_ioAST,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  nt_guard_ (ioArgument_ioAST.mAttribute_mGuardListAST, inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i32_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_guard_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_i33_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_expression_5F__31__32__ (outArgument_outExpression, inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_i33_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_expression_5F__31__32__parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__31__32__i34_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                            C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_expression_5F__31__31__ (outArgument_outExpression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_49 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_or) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 26)) ;
      GALGAS_location var_operatorLocation_1277 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 27)) ;
      GALGAS_expressionAST var_rightExpression_1337 ;
      nt_expression_5F__31__31__ (var_rightExpression_1337, inCompiler) ;
      GALGAS_booleanShortCircuitAndOperatorExpressionAST var_andExpression_1413 = GALGAS_booleanShortCircuitAndOperatorExpressionAST::constructor_new (GALGAS_prefixOperatorExpressionAST::constructor_new (var_operatorLocation_1277, GALGAS_prefixOperator::constructor_notOperator (SOURCE_FILE ("expression-operator-priority.galgas", 31)), outArgument_outExpression  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 31)), var_operatorLocation_1277, GALGAS_prefixOperatorExpressionAST::constructor_new (var_operatorLocation_1277, GALGAS_prefixOperator::constructor_notOperator (SOURCE_FILE ("expression-operator-priority.galgas", 33)), var_rightExpression_1337  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 33))  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 30)) ;
      outArgument_outExpression = GALGAS_prefixOperatorExpressionAST::constructor_new (var_operatorLocation_1277, GALGAS_prefixOperator::constructor_notOperator (SOURCE_FILE ("expression-operator-priority.galgas", 37)), var_andExpression_1413  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 35)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__31__32__i34_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_expression_5F__31__31__parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_49 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_or) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 26)) ;
      nt_expression_5F__31__31__parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__31__31__i35_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                            C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_expression_5F__31__30__ (outArgument_outExpression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_50 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_xor) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 49)) ;
      GALGAS_location var_operatorLocation_2105 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 50)) ;
      GALGAS_expressionAST var_rightExpression_2165 ;
      nt_expression_5F__31__30__ (var_rightExpression_2165, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_2105, GALGAS_infixOperator::constructor_booleanXorOp (SOURCE_FILE ("expression-operator-priority.galgas", 55)), var_rightExpression_2165  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 52)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__31__31__i35_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_expression_5F__31__30__parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_50 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_xor) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 49)) ;
      nt_expression_5F__31__30__parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__31__30__i36_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                            C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_expression_5F__39__ (outArgument_outExpression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_51 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_and) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 67)) ;
      GALGAS_location var_operatorLocation_2610 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 68)) ;
      GALGAS_expressionAST var_rightExpression_2669 ;
      nt_expression_5F__39__ (var_rightExpression_2669, inCompiler) ;
      outArgument_outExpression = GALGAS_booleanShortCircuitAndOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_2610, var_rightExpression_2669  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 70)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__31__30__i36_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_expression_5F__39__parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_51 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_and) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 67)) ;
      nt_expression_5F__39__parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__39__i37_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_expression_5F__38__ (outArgument_outExpression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_52 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7C_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 84)) ;
      GALGAS_location var_operatorLocation_3105 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 85)) ;
      GALGAS_expressionAST var_rightExpression_3164 ;
      nt_expression_5F__38__ (var_rightExpression_3164, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_3105, GALGAS_infixOperator::constructor_orOp (SOURCE_FILE ("expression-operator-priority.galgas", 90)), var_rightExpression_3164  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 87)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__39__i37_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_expression_5F__38__parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_52 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7C_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 84)) ;
      nt_expression_5F__38__parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__38__i38_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_expression_5F__37__ (outArgument_outExpression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_53 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5E_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 102)) ;
      GALGAS_location var_operatorLocation_3598 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 103)) ;
      GALGAS_expressionAST var_rightExpression_3657 ;
      nt_expression_5F__37__ (var_rightExpression_3657, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_3598, GALGAS_infixOperator::constructor_xorOp (SOURCE_FILE ("expression-operator-priority.galgas", 108)), var_rightExpression_3657  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 105)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__38__i38_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_expression_5F__37__parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_53 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5E_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 102)) ;
      nt_expression_5F__37__parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__37__i39_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_expression_5F__36__ (outArgument_outExpression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_54 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__26_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 120)) ;
      GALGAS_location var_operatorLocation_4093 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 121)) ;
      GALGAS_expressionAST var_rightExpression_4152 ;
      nt_expression_5F__36__ (var_rightExpression_4152, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_4093, GALGAS_infixOperator::constructor_andOp (SOURCE_FILE ("expression-operator-priority.galgas", 126)), var_rightExpression_4152  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 123)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__37__i39_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_expression_5F__36__parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_54 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__26_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 120)) ;
      nt_expression_5F__36__parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__36__i40_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_expression_5F__35__ (outArgument_outExpression, inCompiler) ;
  switch (select_plm_5F_syntax_55 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D__3D_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 138)) ;
    GALGAS_location var_operatorLocation_4585 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 139)) ;
    GALGAS_expressionAST var_rightExpression_4644 ;
    nt_expression_5F__35__ (var_rightExpression_4644, inCompiler) ;
    outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_4585, GALGAS_infixOperator::constructor_equal (SOURCE_FILE ("expression-operator-priority.galgas", 144)), var_rightExpression_4644  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 141)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21__3D_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 148)) ;
    GALGAS_location var_operatorLocation_4843 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 149)) ;
    GALGAS_expressionAST var_rightExpression_4902 ;
    nt_expression_5F__35__ (var_rightExpression_4902, inCompiler) ;
    outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_4843, GALGAS_infixOperator::constructor_nonEqual (SOURCE_FILE ("expression-operator-priority.galgas", 154)), var_rightExpression_4902  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 151)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__36__i40_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_expression_5F__35__parse (inCompiler) ;
  switch (select_plm_5F_syntax_55 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D__3D_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 138)) ;
    nt_expression_5F__35__parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21__3D_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 148)) ;
    nt_expression_5F__35__parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__35__i41_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_expression_5F__34__ (outArgument_outExpression, inCompiler) ;
  switch (select_plm_5F_syntax_56 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3C__3D_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 166)) ;
    GALGAS_location var_operatorLocation_5338 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 167)) ;
    GALGAS_expressionAST var_rightExpression_5397 ;
    nt_expression_5F__34__ (var_rightExpression_5397, inCompiler) ;
    outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_5338, GALGAS_infixOperator::constructor_infEqual (SOURCE_FILE ("expression-operator-priority.galgas", 172)), var_rightExpression_5397  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 169)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3E__3D_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 176)) ;
    GALGAS_location var_operatorLocation_5599 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 177)) ;
    GALGAS_expressionAST var_rightExpression_5658 ;
    nt_expression_5F__34__ (var_rightExpression_5658, inCompiler) ;
    outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_5599, GALGAS_infixOperator::constructor_supEqual (SOURCE_FILE ("expression-operator-priority.galgas", 182)), var_rightExpression_5658  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 179)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3C_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 186)) ;
    GALGAS_location var_operatorLocation_5859 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 187)) ;
    GALGAS_expressionAST var_rightExpression_5918 ;
    nt_expression_5F__34__ (var_rightExpression_5918, inCompiler) ;
    outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_5859, GALGAS_infixOperator::constructor_strictInf (SOURCE_FILE ("expression-operator-priority.galgas", 192)), var_rightExpression_5918  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 189)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3E_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 196)) ;
    GALGAS_location var_operatorLocation_6120 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 197)) ;
    GALGAS_expressionAST var_rightExpression_6179 ;
    nt_expression_5F__34__ (var_rightExpression_6179, inCompiler) ;
    outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_6120, GALGAS_infixOperator::constructor_strictSup (SOURCE_FILE ("expression-operator-priority.galgas", 202)), var_rightExpression_6179  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 199)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__35__i41_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_expression_5F__34__parse (inCompiler) ;
  switch (select_plm_5F_syntax_56 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3C__3D_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 166)) ;
    nt_expression_5F__34__parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3E__3D_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 176)) ;
    nt_expression_5F__34__parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3C_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 186)) ;
    nt_expression_5F__34__parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3E_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 196)) ;
    nt_expression_5F__34__parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__34__i42_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_expression_5F__33__ (outArgument_outExpression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_57 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3C__3C_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 214)) ;
      GALGAS_location var_operatorLocation_6619 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 215)) ;
      GALGAS_expressionAST var_rightExpression_6678 ;
      nt_expression_5F__33__ (var_rightExpression_6678, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_6619, GALGAS_infixOperator::constructor_leftShiftOp (SOURCE_FILE ("expression-operator-priority.galgas", 220)), var_rightExpression_6678  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 217)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3E__3E_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 224)) ;
      GALGAS_location var_operatorLocation_6886 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 225)) ;
      GALGAS_expressionAST var_rightExpression_6945 ;
      nt_expression_5F__33__ (var_rightExpression_6945, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_6886, GALGAS_infixOperator::constructor_rightShiftOp (SOURCE_FILE ("expression-operator-priority.galgas", 230)), var_rightExpression_6945  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 227)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__34__i42_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_expression_5F__33__parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_57 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3C__3C_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 214)) ;
      nt_expression_5F__33__parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3E__3E_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 224)) ;
      nt_expression_5F__33__parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__33__i43_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_expression_5F__32__ (outArgument_outExpression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_58 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2B_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 242)) ;
      GALGAS_location var_operatorLocation_7387 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 243)) ;
      GALGAS_expressionAST var_rightExpression_7446 ;
      nt_expression_5F__32__ (var_rightExpression_7446, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_7387, GALGAS_infixOperator::constructor_addOp (SOURCE_FILE ("expression-operator-priority.galgas", 248)), var_rightExpression_7446  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 245)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2B__25_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 252)) ;
      GALGAS_location var_operatorLocation_7648 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 253)) ;
      GALGAS_expressionAST var_rightExpression_7707 ;
      nt_expression_5F__32__ (var_rightExpression_7707, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_7648, GALGAS_infixOperator::constructor_addOpNoOvf (SOURCE_FILE ("expression-operator-priority.galgas", 258)), var_rightExpression_7707  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 255)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 262)) ;
      GALGAS_location var_operatorLocation_7913 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 263)) ;
      GALGAS_expressionAST var_rightExpression_7972 ;
      nt_expression_5F__32__ (var_rightExpression_7972, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_7913, GALGAS_infixOperator::constructor_subOp (SOURCE_FILE ("expression-operator-priority.galgas", 268)), var_rightExpression_7972  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 265)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__25_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 272)) ;
      GALGAS_location var_operatorLocation_8174 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 273)) ;
      GALGAS_expressionAST var_rightExpression_8233 ;
      nt_expression_5F__32__ (var_rightExpression_8233, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_8174, GALGAS_infixOperator::constructor_subOpNoOvf (SOURCE_FILE ("expression-operator-priority.galgas", 278)), var_rightExpression_8233  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 275)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__33__i43_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_expression_5F__32__parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_58 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2B_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 242)) ;
      nt_expression_5F__32__parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2B__25_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 252)) ;
      nt_expression_5F__32__parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 262)) ;
      nt_expression_5F__32__parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__25_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 272)) ;
      nt_expression_5F__32__parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__32__i44_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_expression_5F__31__ (outArgument_outExpression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_59 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2A_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 290)) ;
      GALGAS_location var_operatorLocation_8673 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 291)) ;
      GALGAS_expressionAST var_rightExpression_8732 ;
      nt_expression_5F__31__ (var_rightExpression_8732, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_8673, GALGAS_infixOperator::constructor_mulOp (SOURCE_FILE ("expression-operator-priority.galgas", 296)), var_rightExpression_8732  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 293)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2A__25_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 300)) ;
      GALGAS_location var_operatorLocation_8934 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 301)) ;
      GALGAS_expressionAST var_rightExpression_8993 ;
      nt_expression_5F__31__ (var_rightExpression_8993, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_8934, GALGAS_infixOperator::constructor_mulOpNoOvf (SOURCE_FILE ("expression-operator-priority.galgas", 306)), var_rightExpression_8993  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 303)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__25_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 310)) ;
      GALGAS_location var_operatorLocation_9199 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 311)) ;
      GALGAS_expressionAST var_rightExpression_9258 ;
      nt_expression_5F__31__ (var_rightExpression_9258, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_9199, GALGAS_infixOperator::constructor_modOp (SOURCE_FILE ("expression-operator-priority.galgas", 316)), var_rightExpression_9258  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 313)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21__25_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 320)) ;
      GALGAS_location var_operatorLocation_9460 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 321)) ;
      GALGAS_expressionAST var_rightExpression_9519 ;
      nt_expression_5F__31__ (var_rightExpression_9519, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_9460, GALGAS_infixOperator::constructor_modOpNoOvf (SOURCE_FILE ("expression-operator-priority.galgas", 326)), var_rightExpression_9519  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 323)) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2F_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 330)) ;
      GALGAS_location var_operatorLocation_9725 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 331)) ;
      GALGAS_expressionAST var_rightExpression_9784 ;
      nt_expression_5F__31__ (var_rightExpression_9784, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_9725, GALGAS_infixOperator::constructor_divOp (SOURCE_FILE ("expression-operator-priority.galgas", 336)), var_rightExpression_9784  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 333)) ;
    } break ;
    case 7: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21__2F_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 340)) ;
      GALGAS_location var_operatorLocation_9986 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 341)) ;
      GALGAS_expressionAST var_rightExpression_10045 ;
      nt_expression_5F__31__ (var_rightExpression_10045, inCompiler) ;
      outArgument_outExpression = GALGAS_infixOperatorExpressionAST::constructor_new (outArgument_outExpression, var_operatorLocation_9986, GALGAS_infixOperator::constructor_divOpNoOvf (SOURCE_FILE ("expression-operator-priority.galgas", 346)), var_rightExpression_10045  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 343)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__32__i44_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_expression_5F__31__parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_59 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2A_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 290)) ;
      nt_expression_5F__31__parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2A__25_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 300)) ;
      nt_expression_5F__31__parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__25_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 310)) ;
      nt_expression_5F__31__parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21__25_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 320)) ;
      nt_expression_5F__31__parse (inCompiler) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2F_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 330)) ;
      nt_expression_5F__31__parse (inCompiler) ;
    } break ;
    case 7: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21__2F_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 340)) ;
      nt_expression_5F__31__parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__31__i45_ (GALGAS_expressionAST & outArgument_outExpression,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  nt_primary_ (outArgument_outExpression, inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_expression_5F__31__i45_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_primary_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i46_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7E_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 361)) ;
  GALGAS_location var_operatorLocation_10631 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 362)) ;
  GALGAS_expressionAST var_expression_10678 ;
  nt_primary_ (var_expression_10678, inCompiler) ;
  outArgument_outExpression = GALGAS_prefixOperatorExpressionAST::constructor_new (var_operatorLocation_10631, GALGAS_prefixOperator::constructor_unsignedComplement (SOURCE_FILE ("expression-operator-priority.galgas", 366)), var_expression_10678  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 364)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i46_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7E_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 361)) ;
  nt_primary_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i47_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_not) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 374)) ;
  GALGAS_location var_operatorLocation_11019 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 375)) ;
  GALGAS_expressionAST var_expression_11066 ;
  nt_primary_ (var_expression_11066, inCompiler) ;
  outArgument_outExpression = GALGAS_prefixOperatorExpressionAST::constructor_new (var_operatorLocation_11019, GALGAS_prefixOperator::constructor_notOperator (SOURCE_FILE ("expression-operator-priority.galgas", 379)), var_expression_11066  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 377)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i47_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_not) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 374)) ;
  nt_primary_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i48_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 387)) ;
  GALGAS_location var_operatorLocation_11398 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 388)) ;
  GALGAS_expressionAST var_expression_11445 ;
  nt_primary_ (var_expression_11445, inCompiler) ;
  outArgument_outExpression = GALGAS_prefixOperatorExpressionAST::constructor_new (var_operatorLocation_11398, GALGAS_prefixOperator::constructor_minus (SOURCE_FILE ("expression-operator-priority.galgas", 392)), var_expression_11445  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 390)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i48_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 387)) ;
  nt_primary_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i49_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__25_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 400)) ;
  GALGAS_location var_operatorLocation_11772 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 401)) ;
  GALGAS_expressionAST var_expression_11819 ;
  nt_primary_ (var_expression_11819, inCompiler) ;
  outArgument_outExpression = GALGAS_prefixOperatorExpressionAST::constructor_new (var_operatorLocation_11772, GALGAS_prefixOperator::constructor_minusNoOvf (SOURCE_FILE ("expression-operator-priority.galgas", 405)), var_expression_11819  COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 403)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i49_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__25_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 400)) ;
  nt_primary_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i50_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__28_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 413)) ;
  nt_expression_ (outArgument_outExpression, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__29_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 415)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i50_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__28_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 413)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__29_) COMMA_SOURCE_FILE ("expression-operator-priority.galgas", 415)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i51_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_convert) COMMA_SOURCE_FILE ("expression-convert.galgas", 20)) ;
  nt_expression_ (outArgument_outExpression, inCompiler) ;
  GALGAS_location var_endOfExpression_1127 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-convert.galgas", 22)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("expression-convert.galgas", 23)) ;
  GALGAS_lstring var_typeIdentifier_1185 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-convert.galgas", 24)) ;
  outArgument_outExpression = GALGAS_convertExpressionAST::constructor_new (outArgument_outExpression, var_typeIdentifier_1185, var_endOfExpression_1127  COMMA_SOURCE_FILE ("expression-convert.galgas", 25)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i51_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_convert) COMMA_SOURCE_FILE ("expression-convert.galgas", 20)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("expression-convert.galgas", 23)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-convert.galgas", 24)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i52_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_extend) COMMA_SOURCE_FILE ("expression-extend.galgas", 20)) ;
  nt_expression_ (outArgument_outExpression, inCompiler) ;
  GALGAS_location var_endOfExpression_1125 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-extend.galgas", 22)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("expression-extend.galgas", 23)) ;
  GALGAS_lstring var_typeIdentifier_1183 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-extend.galgas", 24)) ;
  outArgument_outExpression = GALGAS_extendExpressionAST::constructor_new (outArgument_outExpression, var_typeIdentifier_1183, var_endOfExpression_1125  COMMA_SOURCE_FILE ("expression-extend.galgas", 25)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i52_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_extend) COMMA_SOURCE_FILE ("expression-extend.galgas", 20)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("expression-extend.galgas", 23)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-extend.galgas", 24)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i53_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_truncate) COMMA_SOURCE_FILE ("expression-truncate.galgas", 20)) ;
  nt_expression_ (outArgument_outExpression, inCompiler) ;
  GALGAS_location var_endOfExpression_1129 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-truncate.galgas", 22)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("expression-truncate.galgas", 23)) ;
  GALGAS_lstring var_typeIdentifier_1187 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-truncate.galgas", 24)) ;
  outArgument_outExpression = GALGAS_truncateExpressionAST::constructor_new (outArgument_outExpression, var_typeIdentifier_1187, var_endOfExpression_1129  COMMA_SOURCE_FILE ("expression-truncate.galgas", 25)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i53_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_truncate) COMMA_SOURCE_FILE ("expression-truncate.galgas", 20)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("expression-truncate.galgas", 23)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-truncate.galgas", 24)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i54_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  GALGAS_lstring var_typeName_1197 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 25)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__28_) COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 26)) ;
  GALGAS_functionCallEffectiveParameterList var_parameterList_1259 = GALGAS_functionCallEffectiveParameterList::constructor_emptyList (SOURCE_FILE ("expression-constructor-call.galgas", 27)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_60 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_selector_1309 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21_) COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 30)) ;
      GALGAS_expressionAST var_expression_1344 ;
      nt_expression_ (var_expression_1344, inCompiler) ;
      var_parameterList_1259.addAssign_operation (var_selector_1309, var_expression_1344  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 32)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  GALGAS_location var_errorLocation_1419 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 34)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__29_) COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 35)) ;
  outArgument_outExpression = GALGAS_constructorCall::constructor_new (var_typeName_1197, var_parameterList_1259, var_errorLocation_1419  COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 36)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i54_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 25)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__28_) COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 26)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_60 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21_) COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 30)) ;
      nt_expression_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__29_) COMMA_SOURCE_FILE ("expression-constructor-call.galgas", 35)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i55_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  GALGAS_lstring var_optionalTypeName_1062 ;
  switch (select_plm_5F_syntax_61 (inCompiler)) {
  case 1: {
    var_optionalTypeName_1062 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 21))  COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 21)) ;
  } break ;
  case 2: {
    var_optionalTypeName_1062 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 23)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 25)) ;
  GALGAS_lstring var_constantName_1207 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 26)) ;
  outArgument_outExpression = GALGAS_typedConstantCall::constructor_new (var_optionalTypeName_1062, var_constantName_1207  COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 27)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i55_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_61 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 23)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 25)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-typed-constant.galgas", 26)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i56_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_if) COMMA_SOURCE_FILE ("expression-if.galgas", 23)) ;
  GALGAS_expressionAST var_ifExpression_1231 ;
  nt_expression_ (var_ifExpression_1231, inCompiler) ;
  GALGAS_location var_ifExpressionEndLocation_1273 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-if.galgas", 25)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("expression-if.galgas", 26)) ;
  GALGAS_expressionAST var_thenExpression_1326 ;
  nt_expression_ (var_thenExpression_1326, inCompiler) ;
  GALGAS_location var_thenExpressionEndLocation_1370 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-if.galgas", 28)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("expression-if.galgas", 29)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_else) COMMA_SOURCE_FILE ("expression-if.galgas", 30)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("expression-if.galgas", 31)) ;
  GALGAS_expressionAST var_elseExpression_1442 ;
  nt_expression_ (var_elseExpression_1442, inCompiler) ;
  GALGAS_location var_elseExpressionEndLocation_1486 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-if.galgas", 33)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("expression-if.galgas", 34)) ;
  outArgument_outExpression = GALGAS_ifExpressionAST::constructor_new (var_ifExpression_1231, var_ifExpressionEndLocation_1273, var_thenExpression_1326, var_thenExpressionEndLocation_1370, var_elseExpression_1442, var_elseExpressionEndLocation_1486  COMMA_SOURCE_FILE ("expression-if.galgas", 35)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i56_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_if) COMMA_SOURCE_FILE ("expression-if.galgas", 23)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("expression-if.galgas", 26)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("expression-if.galgas", 29)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_else) COMMA_SOURCE_FILE ("expression-if.galgas", 30)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("expression-if.galgas", 31)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("expression-if.galgas", 34)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i57_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  GALGAS_lbigint var_integerLiteral_1057 = inCompiler->synthetizedAttribute_bigInteger () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("expression-literal-integer.galgas", 18)) ;
  outArgument_outExpression = GALGAS_literalIntegerInExpressionAST::constructor_new (var_integerLiteral_1057  COMMA_SOURCE_FILE ("expression-literal-integer.galgas", 19)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i57_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_integer) COMMA_SOURCE_FILE ("expression-literal-integer.galgas", 18)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i58_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  GALGAS_lstring var_stringLiteral_1055 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__22_string_22_) COMMA_SOURCE_FILE ("expression-literal-string.galgas", 18)) ;
  outArgument_outExpression = GALGAS_literalStringInExpressionAST::constructor_new (var_stringLiteral_1055  COMMA_SOURCE_FILE ("expression-literal-string.galgas", 19)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i58_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__22_string_22_) COMMA_SOURCE_FILE ("expression-literal-string.galgas", 18)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i59_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_true) COMMA_SOURCE_FILE ("expression-true-false.galgas", 18)) ;
  outArgument_outExpression = GALGAS_literalBooleanInExpressionAST::constructor_new (GALGAS_bool (true)  COMMA_SOURCE_FILE ("expression-true-false.galgas", 19)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i59_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_true) COMMA_SOURCE_FILE ("expression-true-false.galgas", 18)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i60_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_false) COMMA_SOURCE_FILE ("expression-true-false.galgas", 25)) ;
  outArgument_outExpression = GALGAS_literalBooleanInExpressionAST::constructor_new (GALGAS_bool (false)  COMMA_SOURCE_FILE ("expression-true-false.galgas", 26)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i60_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_false) COMMA_SOURCE_FILE ("expression-true-false.galgas", 25)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i61_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  GALGAS_lstring var_registerNameAsTypeName_1372 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 28)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 29)) ;
  GALGAS_lstringlist var_booleanFieldNames_1415 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("expression-cst-registre.galgas", 30)) ;
  GALGAS_registerIntegerFieldListAST var_integerFieldValues_1472 = GALGAS_registerIntegerFieldListAST::constructor_emptyList (SOURCE_FILE ("expression-cst-registre.galgas", 31)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_lstring var_registerFieldName_1530 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 33)) ;
    switch (select_plm_5F_syntax_63 (inCompiler)) {
    case 1: {
      var_booleanFieldNames_1415.addAssign_operation (var_registerFieldName_1530  COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 35)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 37)) ;
      GALGAS_expressionAST var_expression_1649 ;
      nt_expression_ (var_expression_1649, inCompiler) ;
      var_integerFieldValues_1472.addAssign_operation (var_registerFieldName_1530, var_expression_1649, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 39))  COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 39)) ;
    } break ;
    default:
      break ;
    }
    switch (select_plm_5F_syntax_62 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 42)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 44)) ;
  outArgument_outExpression = GALGAS_registerConstantExpressionAST::constructor_new (var_registerNameAsTypeName_1372, var_booleanFieldNames_1415, var_integerFieldValues_1472  COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 45)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i61_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 28)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 29)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 33)) ;
    switch (select_plm_5F_syntax_63 (inCompiler)) {
    case 1: {
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 37)) ;
      nt_expression_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
    switch (select_plm_5F_syntax_62 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 42)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("expression-cst-registre.galgas", 44)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i62_ (GALGAS_expressionAST & outArgument_outExpression,
                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outExpression.drop () ; // Release 'out' argument
  GALGAS_primaryInExpressionSelfAccessAST var_selfAccess_3025 ;
  switch (select_plm_5F_syntax_64 (inCompiler)) {
  case 1: {
    var_selfAccess_3025 = GALGAS_primaryInExpressionSelfAccessAST::constructor_noSelfAccess (SOURCE_FILE ("expression-primary.galgas", 73)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_self) COMMA_SOURCE_FILE ("expression-primary.galgas", 75)) ;
    var_selfAccess_3025 = GALGAS_primaryInExpressionSelfAccessAST::constructor_selfAccess (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 76))  COMMA_SOURCE_FILE ("expression-primary.galgas", 76)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("expression-primary.galgas", 77)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_objectName_3207 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-primary.galgas", 80)) ;
  GALGAS_primaryInExpressionAccessListAST var_accessListAST_3288 = GALGAS_primaryInExpressionAccessListAST::constructor_emptyList (SOURCE_FILE ("expression-primary.galgas", 82)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_65 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("expression-primary.galgas", 85)) ;
      GALGAS_lstring var_propertyName_3361 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-primary.galgas", 86)) ;
      var_accessListAST_3288.addAssign_operation (GALGAS_primaryInExpressionAccessAST::constructor_property (var_propertyName_3361  COMMA_SOURCE_FILE ("expression-primary.galgas", 87))  COMMA_SOURCE_FILE ("expression-primary.galgas", 87)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("expression-primary.galgas", 89)) ;
      GALGAS_expressionAST var_expression_3471 ;
      nt_expression_ (var_expression_3471, inCompiler) ;
      GALGAS_location var_endOfIndex_3492 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 91)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("expression-primary.galgas", 92)) ;
      var_accessListAST_3288.addAssign_operation (GALGAS_primaryInExpressionAccessAST::constructor_arrayAccess (var_expression_3471, var_endOfIndex_3492  COMMA_SOURCE_FILE ("expression-primary.galgas", 93))  COMMA_SOURCE_FILE ("expression-primary.galgas", 93)) ;
    } break ;
    case 4: {
      GALGAS_effectiveParameterListAST var_arguments_3653 ;
      GALGAS_location var_endOfArguments_3673 ;
      nt_effective_5F_parameters_ (var_arguments_3653, var_endOfArguments_3673, inCompiler) ;
      var_accessListAST_3288.addAssign_operation (GALGAS_primaryInExpressionAccessAST::constructor_funcCall (var_arguments_3653, var_endOfArguments_3673  COMMA_SOURCE_FILE ("expression-primary.galgas", 96))  COMMA_SOURCE_FILE ("expression-primary.galgas", 96)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  outArgument_outExpression = GALGAS_primaryInExpressionAST::constructor_new (var_selfAccess_3025, var_objectName_3207, var_accessListAST_3288  COMMA_SOURCE_FILE ("expression-primary.galgas", 99)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_primary_i62_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_64 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_self) COMMA_SOURCE_FILE ("expression-primary.galgas", 75)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("expression-primary.galgas", 77)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-primary.galgas", 80)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_65 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("expression-primary.galgas", 85)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-primary.galgas", 86)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("expression-primary.galgas", 89)) ;
      nt_expression_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("expression-primary.galgas", 92)) ;
    } break ;
    case 4: {
      nt_effective_5F_parameters_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_effective_5F_parameters_i63_ (GALGAS_effectiveParameterListAST & outArgument_outEffectiveParameterList,
                                                                             GALGAS_location & outArgument_outEndOfArgs,
                                                                             C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outEffectiveParameterList.drop () ; // Release 'out' argument
  outArgument_outEndOfArgs.drop () ; // Release 'out' argument
  outArgument_outEffectiveParameterList = GALGAS_effectiveParameterListAST::constructor_emptyList (SOURCE_FILE ("expression-primary.galgas", 105)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__28_) COMMA_SOURCE_FILE ("expression-primary.galgas", 106)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_66 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_selector_4194 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21_) COMMA_SOURCE_FILE ("expression-primary.galgas", 109)) ;
      GALGAS_expressionAST var_expression_4229 ;
      nt_expression_ (var_expression_4229, inCompiler) ;
      outArgument_outEffectiveParameterList.addAssign_operation (GALGAS_effectiveParameterPassingModeAST::constructor_output (var_expression_4229, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 111))  COMMA_SOURCE_FILE ("expression-primary.galgas", 111)), var_selector_4194  COMMA_SOURCE_FILE ("expression-primary.galgas", 111)) ;
    } break ;
    case 3: {
      GALGAS_lstring var_selector_4351 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21__3F_) COMMA_SOURCE_FILE ("expression-primary.galgas", 113)) ;
      GALGAS_lstring var_effectiveParameterName_4398 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-primary.galgas", 114)) ;
      outArgument_outEffectiveParameterList.addAssign_operation (GALGAS_effectiveParameterPassingModeAST::constructor_outputInput (var_effectiveParameterName_4398  COMMA_SOURCE_FILE ("expression-primary.galgas", 115)), var_selector_4351  COMMA_SOURCE_FILE ("expression-primary.galgas", 115)) ;
    } break ;
    case 4: {
      GALGAS_lstring var_selector_4522 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21__3F_) COMMA_SOURCE_FILE ("expression-primary.galgas", 117)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_self) COMMA_SOURCE_FILE ("expression-primary.galgas", 118)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("expression-primary.galgas", 119)) ;
      GALGAS_lstring var_effectiveParameterName_4592 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-primary.galgas", 120)) ;
      outArgument_outEffectiveParameterList.addAssign_operation (GALGAS_effectiveParameterPassingModeAST::constructor_outputInputSelfVariable (var_effectiveParameterName_4592  COMMA_SOURCE_FILE ("expression-primary.galgas", 121)), var_selector_4522  COMMA_SOURCE_FILE ("expression-primary.galgas", 121)) ;
    } break ;
    case 5: {
      GALGAS_lstring var_selector_4727 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3F_) COMMA_SOURCE_FILE ("expression-primary.galgas", 123)) ;
      GALGAS_lstring var_effectiveParameterName_4774 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-primary.galgas", 124)) ;
      outArgument_outEffectiveParameterList.addAssign_operation (GALGAS_effectiveParameterPassingModeAST::constructor_input (var_effectiveParameterName_4774  COMMA_SOURCE_FILE ("expression-primary.galgas", 125)), var_selector_4727  COMMA_SOURCE_FILE ("expression-primary.galgas", 125)) ;
    } break ;
    case 6: {
      GALGAS_lstring var_selector_4891 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3F_) COMMA_SOURCE_FILE ("expression-primary.galgas", 127)) ;
      GALGAS_bool var_constant_4912 ;
      switch (select_plm_5F_syntax_67 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("expression-primary.galgas", 130)) ;
        var_constant_4912 = GALGAS_bool (false) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_let) COMMA_SOURCE_FILE ("expression-primary.galgas", 133)) ;
        var_constant_4912 = GALGAS_bool (true) ;
      } break ;
      default:
        break ;
      }
      GALGAS_lstring var_effectiveParameterName_5068 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-primary.galgas", 136)) ;
      GALGAS_lstring var_typeName_5092 ;
      switch (select_plm_5F_syntax_68 (inCompiler)) {
      case 1: {
        var_typeName_5092 = GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("expression-primary.galgas", 139)) ;
      } break ;
      case 2: {
        var_typeName_5092 = inCompiler->synthetizedAttribute_tokenString () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-primary.galgas", 141)) ;
      } break ;
      default:
        break ;
      }
      outArgument_outEffectiveParameterList.addAssign_operation (GALGAS_effectiveParameterPassingModeAST::constructor_inputWithType (var_constant_4912, var_typeName_5092, var_effectiveParameterName_5068  COMMA_SOURCE_FILE ("expression-primary.galgas", 143)), var_selector_4891  COMMA_SOURCE_FILE ("expression-primary.galgas", 143)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  outArgument_outEndOfArgs = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("expression-primary.galgas", 145)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__29_) COMMA_SOURCE_FILE ("expression-primary.galgas", 146)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_effective_5F_parameters_i63_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__28_) COMMA_SOURCE_FILE ("expression-primary.galgas", 106)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_66 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21_) COMMA_SOURCE_FILE ("expression-primary.galgas", 109)) ;
      nt_expression_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21__3F_) COMMA_SOURCE_FILE ("expression-primary.galgas", 113)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-primary.galgas", 114)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__21__3F_) COMMA_SOURCE_FILE ("expression-primary.galgas", 117)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_self) COMMA_SOURCE_FILE ("expression-primary.galgas", 118)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("expression-primary.galgas", 119)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-primary.galgas", 120)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3F_) COMMA_SOURCE_FILE ("expression-primary.galgas", 123)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-primary.galgas", 124)) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3F_) COMMA_SOURCE_FILE ("expression-primary.galgas", 127)) ;
      switch (select_plm_5F_syntax_67 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("expression-primary.galgas", 130)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_let) COMMA_SOURCE_FILE ("expression-primary.galgas", 133)) ;
      } break ;
      default:
        break ;
      }
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("expression-primary.galgas", 136)) ;
      switch (select_plm_5F_syntax_68 (inCompiler)) {
      case 1: {
      } break ;
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("expression-primary.galgas", 141)) ;
      } break ;
      default:
        break ;
      }
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__29_) COMMA_SOURCE_FILE ("expression-primary.galgas", 146)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instructionList_i64_ (GALGAS_instructionListAST & outArgument_outInstructionList,
                                                                     C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outInstructionList.drop () ; // Release 'out' argument
  outArgument_outInstructionList = GALGAS_instructionListAST::constructor_emptyList (SOURCE_FILE ("instructionList.galgas", 24)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_69 (inCompiler)) {
    case 2: {
      nt_instruction_ (outArgument_outInstructionList, inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("instructionList.galgas", 29)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instructionList_i64_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_69 (inCompiler)) {
    case 2: {
      nt_instruction_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("instructionList.galgas", 29)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i65_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_check) COMMA_SOURCE_FILE ("directive-check.galgas", 19)) ;
  GALGAS_location var_loc_1083 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("directive-check.galgas", 20)) ;
  GALGAS_expressionAST var_expression_1148 ;
  nt_expression_ (var_expression_1148, inCompiler) ;
  ioArgument_ioInstructionList.addAssign_operation (var_loc_1083, GALGAS_checkInstructionAST::constructor_new (var_loc_1083, var_expression_1148  COMMA_SOURCE_FILE ("directive-check.galgas", 22))  COMMA_SOURCE_FILE ("directive-check.galgas", 22)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i65_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_check) COMMA_SOURCE_FILE ("directive-check.galgas", 19)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i66_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  GALGAS_assignmentTargetAST var_assignmentTargetAST_1149 ;
  nt_assignment_5F_target_ (var_assignmentTargetAST_1149, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("instruction-assignment.galgas", 21)) ;
  GALGAS_expressionAST var_sourceExpression_1221 ;
  nt_expression_ (var_sourceExpression_1221, inCompiler) ;
  ioArgument_ioInstructionList.addAssign_operation (var_assignmentTargetAST_1149.mAttribute_mIdentifier.mAttribute_location, GALGAS_varAssignmentInstructionAST::constructor_new (var_assignmentTargetAST_1149, var_sourceExpression_1221  COMMA_SOURCE_FILE ("instruction-assignment.galgas", 26))  COMMA_SOURCE_FILE ("instruction-assignment.galgas", 24)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i66_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_assignment_5F_target_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("instruction-assignment.galgas", 21)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_assignment_5F_operator_i67_ (GALGAS_operatorAssignmentKind & outArgument_outOp,
                                                                            C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outOp.drop () ; // Release 'out' argument
  switch (select_plm_5F_syntax_70 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7C__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 39)) ;
    outArgument_outOp = GALGAS_operatorAssignmentKind::constructor_bitWiseOrAssign (SOURCE_FILE ("instruction-assignment-operator.galgas", 40)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__26__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 42)) ;
    outArgument_outOp = GALGAS_operatorAssignmentKind::constructor_bitWiseAndAssign (SOURCE_FILE ("instruction-assignment-operator.galgas", 43)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5E__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 45)) ;
    outArgument_outOp = GALGAS_operatorAssignmentKind::constructor_bitWiseXorAssign (SOURCE_FILE ("instruction-assignment-operator.galgas", 46)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2B__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 48)) ;
    outArgument_outOp = GALGAS_operatorAssignmentKind::constructor_addAssign (SOURCE_FILE ("instruction-assignment-operator.galgas", 49)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2B__25__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 51)) ;
    outArgument_outOp = GALGAS_operatorAssignmentKind::constructor_addModuloAssign (SOURCE_FILE ("instruction-assignment-operator.galgas", 52)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 54)) ;
    outArgument_outOp = GALGAS_operatorAssignmentKind::constructor_subAssign (SOURCE_FILE ("instruction-assignment-operator.galgas", 55)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__25__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 57)) ;
    outArgument_outOp = GALGAS_operatorAssignmentKind::constructor_subModuloAssign (SOURCE_FILE ("instruction-assignment-operator.galgas", 58)) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2A__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 60)) ;
    outArgument_outOp = GALGAS_operatorAssignmentKind::constructor_mulAssign (SOURCE_FILE ("instruction-assignment-operator.galgas", 61)) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2A__25__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 63)) ;
    outArgument_outOp = GALGAS_operatorAssignmentKind::constructor_mulModuloAssign (SOURCE_FILE ("instruction-assignment-operator.galgas", 64)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_assignment_5F_operator_i67_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_70 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7C__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 39)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__26__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 42)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5E__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 45)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2B__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 48)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2B__25__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 51)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 54)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2D__25__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 57)) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2A__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 60)) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2A__25__3D_) COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 63)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i68_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  GALGAS_assignmentTargetAST var_assignmentTargetAST_2241 ;
  nt_assignment_5F_target_ (var_assignmentTargetAST_2241, inCompiler) ;
  GALGAS_location var_instructionLocation_2269 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 72)) ;
  GALGAS_operatorAssignmentKind var_operatorAssign_2356 ;
  nt_assignment_5F_operator_ (var_operatorAssign_2356, inCompiler) ;
  GALGAS_expressionAST var_expression_2404 ;
  nt_expression_ (var_expression_2404, inCompiler) ;
  ioArgument_ioInstructionList.addAssign_operation (var_instructionLocation_2269, GALGAS_varOperatorAssignInstructionAST::constructor_new (var_assignmentTargetAST_2241, var_operatorAssign_2356, var_expression_2404  COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 75))  COMMA_SOURCE_FILE ("instruction-assignment-operator.galgas", 75)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i68_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_assignment_5F_target_parse (inCompiler) ;
  nt_assignment_5F_operator_parse (inCompiler) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i69_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("instruction-var.galgas", 27)) ;
  GALGAS_lstring var_varName_1339 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-var.galgas", 28)) ;
  GALGAS_lstring var_optionalTypeName_1369 ;
  switch (select_plm_5F_syntax_71 (inCompiler)) {
  case 1: {
    var_optionalTypeName_1369 = GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("instruction-var.galgas", 31)) ;
  } break ;
  case 2: {
    var_optionalTypeName_1369 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("instruction-var.galgas", 33)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("instruction-var.galgas", 35)) ;
  GALGAS_expressionAST var_expression_1522 ;
  nt_expression_ (var_expression_1522, inCompiler) ;
  ioArgument_ioInstructionList.addAssign_operation (var_varName_1339.mAttribute_location, GALGAS_varInstructionWithAssignmentAST::constructor_new (var_varName_1339, var_optionalTypeName_1369, var_expression_1522  COMMA_SOURCE_FILE ("instruction-var.galgas", 37))  COMMA_SOURCE_FILE ("instruction-var.galgas", 37)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i69_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("instruction-var.galgas", 27)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-var.galgas", 28)) ;
  switch (select_plm_5F_syntax_71 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("instruction-var.galgas", 33)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("instruction-var.galgas", 35)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i70_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("instruction-var.galgas", 47)) ;
  GALGAS_lstring var_varName_1898 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-var.galgas", 48)) ;
  GALGAS_lstring var_typeName_1925 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("instruction-var.galgas", 49)) ;
  ioArgument_ioInstructionList.addAssign_operation (var_varName_1898.mAttribute_location, GALGAS_varInstructionAST::constructor_new (var_varName_1898, var_typeName_1925  COMMA_SOURCE_FILE ("instruction-var.galgas", 50))  COMMA_SOURCE_FILE ("instruction-var.galgas", 50)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i70_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_var) COMMA_SOURCE_FILE ("instruction-var.galgas", 47)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-var.galgas", 48)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("instruction-var.galgas", 49)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i71_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_let) COMMA_SOURCE_FILE ("instruction-let.galgas", 20)) ;
  GALGAS_lstring var_varName_1128 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-let.galgas", 21)) ;
  GALGAS_lstring var_optionalTypeName_1158 ;
  switch (select_plm_5F_syntax_72 (inCompiler)) {
  case 1: {
    var_optionalTypeName_1158 = GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("instruction-let.galgas", 24)) ;
  } break ;
  case 2: {
    var_optionalTypeName_1158 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("instruction-let.galgas", 26)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("instruction-let.galgas", 28)) ;
  GALGAS_expressionAST var_expression_1311 ;
  nt_expression_ (var_expression_1311, inCompiler) ;
  ioArgument_ioInstructionList.addAssign_operation (var_varName_1128.mAttribute_location, GALGAS_letInstructionWithAssignmentAST::constructor_new (var_varName_1128, var_optionalTypeName_1158, var_expression_1311  COMMA_SOURCE_FILE ("instruction-let.galgas", 30))  COMMA_SOURCE_FILE ("instruction-let.galgas", 30)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i71_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_let) COMMA_SOURCE_FILE ("instruction-let.galgas", 20)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-let.galgas", 21)) ;
  switch (select_plm_5F_syntax_72 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("instruction-let.galgas", 26)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("instruction-let.galgas", 28)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i72_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_assert) COMMA_SOURCE_FILE ("instruction-assert.galgas", 19)) ;
  GALGAS_location var_loc_1086 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-assert.galgas", 20)) ;
  GALGAS_expressionAST var_expression_1151 ;
  nt_expression_ (var_expression_1151, inCompiler) ;
  ioArgument_ioInstructionList.addAssign_operation (var_loc_1086, GALGAS_assertInstructionAST::constructor_new (var_loc_1086, var_expression_1151  COMMA_SOURCE_FILE ("instruction-assert.galgas", 22))  COMMA_SOURCE_FILE ("instruction-assert.galgas", 22)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i72_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_assert) COMMA_SOURCE_FILE ("instruction-assert.galgas", 19)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i73_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_panic) COMMA_SOURCE_FILE ("instruction-panic.galgas", 19)) ;
  GALGAS_location var_loc_1076 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-panic.galgas", 20)) ;
  GALGAS_expressionAST var_codeExpression_1145 ;
  nt_expression_ (var_codeExpression_1145, inCompiler) ;
  ioArgument_ioInstructionList.addAssign_operation (var_loc_1076, GALGAS_panicInstructionAST::constructor_new (var_loc_1076, var_codeExpression_1145  COMMA_SOURCE_FILE ("instruction-panic.galgas", 22))  COMMA_SOURCE_FILE ("instruction-panic.galgas", 22)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i73_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_panic) COMMA_SOURCE_FILE ("instruction-panic.galgas", 19)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i74_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  GALGAS_location var_instructionLocation_1285 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-if.galgas", 24)) ;
  GALGAS_ifInstructionAST var_ifInstruction_1342 ;
  nt_if_5F_instruction_ (var_ifInstruction_1342, inCompiler) ;
  ioArgument_ioInstructionList.addAssign_operation (var_instructionLocation_1285, var_ifInstruction_1342  COMMA_SOURCE_FILE ("instruction-if.galgas", 26)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i74_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_if_5F_instruction_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_if_5F_instruction_i75_ (GALGAS_ifInstructionAST & outArgument_outIfInstruction,
                                                                       C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outIfInstruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_if) COMMA_SOURCE_FILE ("instruction-if.galgas", 32)) ;
  GALGAS_location var_instructionLocation_1631 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-if.galgas", 33)) ;
  GALGAS_expressionAST var_testExpression_1700 ;
  nt_expression_ (var_testExpression_1700, inCompiler) ;
  GALGAS_location var_testExpressionEndLocation_1734 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-if.galgas", 35)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("instruction-if.galgas", 36)) ;
  GALGAS_instructionListAST var_thenInstructionList_1806 ;
  nt_instructionList_ (var_thenInstructionList_1806, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("instruction-if.galgas", 38)) ;
  GALGAS_location var_endOfThenBranch_1838 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-if.galgas", 39)) ;
  GALGAS_instructionListAST var_elseInstructionList_1899 ;
  switch (select_plm_5F_syntax_73 (inCompiler)) {
  case 1: {
    var_elseInstructionList_1899 = GALGAS_instructionListAST::constructor_emptyList (SOURCE_FILE ("instruction-if.galgas", 42)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_else) COMMA_SOURCE_FILE ("instruction-if.galgas", 44)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("instruction-if.galgas", 45)) ;
    nt_instructionList_ (var_elseInstructionList_1899, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("instruction-if.galgas", 47)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_else) COMMA_SOURCE_FILE ("instruction-if.galgas", 49)) ;
    GALGAS_ifInstructionAST var_ifInstruction_2088 ;
    nt_if_5F_instruction_ (var_ifInstruction_2088, inCompiler) ;
    GALGAS_instructionListAST temp_0 = GALGAS_instructionListAST::constructor_emptyList (SOURCE_FILE ("instruction-if.galgas", 51)) ;
    temp_0.addAssign_operation (var_instructionLocation_1631, var_ifInstruction_2088  COMMA_SOURCE_FILE ("instruction-if.galgas", 51)) ;
    var_elseInstructionList_1899 = temp_0 ;
  } break ;
  default:
    break ;
  }
  GALGAS_location var_endOfElseBranch_2186 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-if.galgas", 53)) ;
  outArgument_outIfInstruction = GALGAS_ifInstructionAST::constructor_new (var_testExpression_1700, var_testExpressionEndLocation_1734, var_thenInstructionList_1806, var_endOfThenBranch_1838, var_elseInstructionList_1899, var_endOfElseBranch_2186, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-if.galgas", 61))  COMMA_SOURCE_FILE ("instruction-if.galgas", 54)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_if_5F_instruction_i75_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_if) COMMA_SOURCE_FILE ("instruction-if.galgas", 32)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("instruction-if.galgas", 36)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("instruction-if.galgas", 38)) ;
  switch (select_plm_5F_syntax_73 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_else) COMMA_SOURCE_FILE ("instruction-if.galgas", 44)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("instruction-if.galgas", 45)) ;
    nt_instructionList_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("instruction-if.galgas", 47)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_else) COMMA_SOURCE_FILE ("instruction-if.galgas", 49)) ;
    nt_if_5F_instruction_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_guarded_5F_command_i76_ (GALGAS_guardedCommand & outArgument_outGuardedCommand,
                                                                        C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outGuardedCommand.drop () ; // Release 'out' argument
  switch (select_plm_5F_syntax_74 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_when) COMMA_SOURCE_FILE ("instruction-sync.galgas", 49)) ;
    GALGAS_expressionAST var_expression_2331 ;
    nt_expression_ (var_expression_2331, inCompiler) ;
    GALGAS_location var_endOfExp_2350 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 51)) ;
    GALGAS_bool var_isWhileCommand_2540 ;
    switch (select_plm_5F_syntax_75 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_until) COMMA_SOURCE_FILE ("instruction-sync.galgas", 57)) ;
      var_isWhileCommand_2540 = GALGAS_bool (false) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_while) COMMA_SOURCE_FILE ("instruction-sync.galgas", 60)) ;
      var_isWhileCommand_2540 = GALGAS_bool (true) ;
    } break ;
    default:
      break ;
    }
    GALGAS_lstring var_name_2710 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-sync.galgas", 63)) ;
    switch (select_plm_5F_syntax_76 (inCompiler)) {
    case 1: {
      GALGAS_effectiveParameterListAST var_effectiveParameterList_2786 ;
      GALGAS_location joker_2788 ; // Joker input parameter
      nt_effective_5F_parameters_ (var_effectiveParameterList_2786, joker_2788, inCompiler) ;
      joker_2788.drop () ; // Release temporary input variables (joker in source)
      outArgument_outGuardedCommand = GALGAS_guardedCommand::constructor_boolAndSync (var_isWhileCommand_2540, var_expression_2331, var_endOfExp_2350, GALGAS_string::makeEmptyString ().getter_here (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 70)), var_name_2710, var_effectiveParameterList_2786  COMMA_SOURCE_FILE ("instruction-sync.galgas", 66)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("instruction-sync.galgas", 75)) ;
      GALGAS_lstring var_guardName_3159 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-sync.galgas", 76)) ;
      GALGAS_effectiveParameterListAST var_effectiveParameterList_3220 ;
      GALGAS_location joker_3222 ; // Joker input parameter
      nt_effective_5F_parameters_ (var_effectiveParameterList_3220, joker_3222, inCompiler) ;
      joker_3222.drop () ; // Release temporary input variables (joker in source)
      outArgument_outGuardedCommand = GALGAS_guardedCommand::constructor_boolAndSync (var_isWhileCommand_2540, var_expression_2331, var_endOfExp_2350, var_name_2710, var_guardName_3159, var_effectiveParameterList_3220  COMMA_SOURCE_FILE ("instruction-sync.galgas", 78)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    GALGAS_bool var_isWhileCommand_3587 ;
    switch (select_plm_5F_syntax_77 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_until) COMMA_SOURCE_FILE ("instruction-sync.galgas", 91)) ;
      var_isWhileCommand_3587 = GALGAS_bool (false) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_while) COMMA_SOURCE_FILE ("instruction-sync.galgas", 94)) ;
      var_isWhileCommand_3587 = GALGAS_bool (true) ;
    } break ;
    default:
      break ;
    }
    GALGAS_lstring var_name_3741 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-sync.galgas", 97)) ;
    switch (select_plm_5F_syntax_78 (inCompiler)) {
    case 1: {
      GALGAS_effectiveParameterListAST var_effectiveParameterList_3813 ;
      GALGAS_location joker_3815 ; // Joker input parameter
      nt_effective_5F_parameters_ (var_effectiveParameterList_3813, joker_3815, inCompiler) ;
      joker_3815.drop () ; // Release temporary input variables (joker in source)
      outArgument_outGuardedCommand = GALGAS_guardedCommand::constructor_synchronization (var_isWhileCommand_3587, GALGAS_string::makeEmptyString ().getter_here (inCompiler COMMA_SOURCE_FILE ("instruction-sync.galgas", 102)), var_name_3741, var_effectiveParameterList_3813  COMMA_SOURCE_FILE ("instruction-sync.galgas", 100)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("instruction-sync.galgas", 107)) ;
      GALGAS_lstring var_guardName_4099 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-sync.galgas", 108)) ;
      GALGAS_effectiveParameterListAST var_effectiveParameterList_4158 ;
      GALGAS_location joker_4160 ; // Joker input parameter
      nt_effective_5F_parameters_ (var_effectiveParameterList_4158, joker_4160, inCompiler) ;
      joker_4160.drop () ; // Release temporary input variables (joker in source)
      outArgument_outGuardedCommand = GALGAS_guardedCommand::constructor_synchronization (var_isWhileCommand_3587, var_name_3741, var_guardName_4099, var_effectiveParameterList_4158  COMMA_SOURCE_FILE ("instruction-sync.galgas", 110)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_guarded_5F_command_i76_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_74 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_when) COMMA_SOURCE_FILE ("instruction-sync.galgas", 49)) ;
    nt_expression_parse (inCompiler) ;
    switch (select_plm_5F_syntax_75 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_until) COMMA_SOURCE_FILE ("instruction-sync.galgas", 57)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_while) COMMA_SOURCE_FILE ("instruction-sync.galgas", 60)) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-sync.galgas", 63)) ;
    switch (select_plm_5F_syntax_76 (inCompiler)) {
    case 1: {
      nt_effective_5F_parameters_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("instruction-sync.galgas", 75)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-sync.galgas", 76)) ;
      nt_effective_5F_parameters_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    switch (select_plm_5F_syntax_77 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_until) COMMA_SOURCE_FILE ("instruction-sync.galgas", 91)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_while) COMMA_SOURCE_FILE ("instruction-sync.galgas", 94)) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-sync.galgas", 97)) ;
    switch (select_plm_5F_syntax_78 (inCompiler)) {
    case 1: {
      nt_effective_5F_parameters_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("instruction-sync.galgas", 107)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-sync.galgas", 108)) ;
      nt_effective_5F_parameters_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i77_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_sync) COMMA_SOURCE_FILE ("instruction-sync.galgas", 123)) ;
  GALGAS_location var_startLocation_4628 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 124)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("instruction-sync.galgas", 125)) ;
  GALGAS_syncInstructionBranchList var_onInstructionBranchList_4708 = GALGAS_syncInstructionBranchList::constructor_emptyList (SOURCE_FILE ("instruction-sync.galgas", 126)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_guardedCommand var_guardedCommand_4784 ;
    nt_guarded_5F_command_ (var_guardedCommand_4784, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("instruction-sync.galgas", 129)) ;
    GALGAS_instructionListAST var_instructionList_4839 ;
    nt_instructionList_ (var_instructionList_4839, inCompiler) ;
    var_onInstructionBranchList_4708.addAssign_operation (var_guardedCommand_4784, var_instructionList_4839, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 131))  COMMA_SOURCE_FILE ("instruction-sync.galgas", 131)) ;
    switch (select_plm_5F_syntax_79 (inCompiler)) {
    case 2: {
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  ioArgument_ioInstructionList.addAssign_operation (var_startLocation_4628, GALGAS_syncInstructionAST::constructor_new (var_startLocation_4628, var_onInstructionBranchList_4708, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-sync.galgas", 134))  COMMA_SOURCE_FILE ("instruction-sync.galgas", 134))  COMMA_SOURCE_FILE ("instruction-sync.galgas", 134)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("instruction-sync.galgas", 135)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i77_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_sync) COMMA_SOURCE_FILE ("instruction-sync.galgas", 123)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("instruction-sync.galgas", 125)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_guarded_5F_command_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("instruction-sync.galgas", 129)) ;
    nt_instructionList_parse (inCompiler) ;
    switch (select_plm_5F_syntax_79 (inCompiler)) {
    case 2: {
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("instruction-sync.galgas", 135)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i78_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_do) COMMA_SOURCE_FILE ("instruction-while.galgas", 21)) ;
  GALGAS_location var_instructionLocation_1179 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-while.galgas", 22)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_while) COMMA_SOURCE_FILE ("instruction-while.galgas", 23)) ;
  GALGAS_expressionAST var_testExpression_1260 ;
  nt_expression_ (var_testExpression_1260, inCompiler) ;
  GALGAS_location var_testExpressionEndLocation_1294 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-while.galgas", 25)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("instruction-while.galgas", 26)) ;
  GALGAS_instructionListAST var_instructionList_1362 ;
  nt_instructionList_ (var_instructionList_1362, inCompiler) ;
  GALGAS_location var_endOfInstruction_1387 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-while.galgas", 28)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("instruction-while.galgas", 29)) ;
  ioArgument_ioInstructionList.addAssign_operation (var_instructionLocation_1179, GALGAS_whileInstructionAST::constructor_new (var_testExpression_1260, var_testExpressionEndLocation_1294, var_instructionList_1362, var_endOfInstruction_1387  COMMA_SOURCE_FILE ("instruction-while.galgas", 30))  COMMA_SOURCE_FILE ("instruction-while.galgas", 30)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i78_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_do) COMMA_SOURCE_FILE ("instruction-while.galgas", 21)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_while) COMMA_SOURCE_FILE ("instruction-while.galgas", 23)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("instruction-while.galgas", 26)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("instruction-while.galgas", 29)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i79_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_for) COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 22)) ;
  GALGAS_lstring var_varName_1212 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 23)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_in) COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 24)) ;
  GALGAS_expressionAST var_expression_1269 ;
  nt_expression_ (var_expression_1269, inCompiler) ;
  GALGAS_location var_endOf_5F_iteratedExpression_5F_instruction_1314 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 26)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 27)) ;
  GALGAS_instructionListAST var_instructionList_1382 ;
  nt_instructionList_ (var_instructionList_1382, inCompiler) ;
  GALGAS_location var_endOfInstruction_1407 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 29)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 30)) ;
  ioArgument_ioInstructionList.addAssign_operation (var_varName_1212.mAttribute_location, GALGAS_forInstructionAST::constructor_new (var_varName_1212, var_expression_1269, var_endOf_5F_iteratedExpression_5F_instruction_1314, var_instructionList_1382, var_endOfInstruction_1407  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 31))  COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 31)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i79_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_for) COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 22)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 23)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_in) COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 24)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 27)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("instruction-for-in-do.galgas", 30)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i80_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_for) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 25)) ;
  GALGAS_lstring var_varName_1343 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 26)) ;
  GALGAS_lstring var_typeName_1370 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 27)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_in) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 28)) ;
  GALGAS_expressionAST var_lowerBoundExpression_1437 ;
  nt_expression_ (var_lowerBoundExpression_1437, inCompiler) ;
  GALGAS_location var_endOf_5F_lowerBoundExpression_5F_instruction_1484 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 30)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E__2E__3C_) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 31)) ;
  GALGAS_expressionAST var_upperBoundExpression_1569 ;
  nt_expression_ (var_upperBoundExpression_1569, inCompiler) ;
  GALGAS_location var_endOf_5F_upperBoundExpression_5F_instruction_1616 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 33)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 34)) ;
  GALGAS_instructionListAST var_instructionList_1684 ;
  nt_instructionList_ (var_instructionList_1684, inCompiler) ;
  GALGAS_location var_endOfInstruction_1709 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 36)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 37)) ;
  ioArgument_ioInstructionList.addAssign_operation (var_varName_1343.mAttribute_location, GALGAS_forLowerUpperBoundInstructionAST::constructor_new (var_varName_1343, var_typeName_1370, var_lowerBoundExpression_1437, var_endOf_5F_lowerBoundExpression_5F_instruction_1484, var_upperBoundExpression_1569, var_endOf_5F_upperBoundExpression_5F_instruction_1616, var_instructionList_1684, var_endOfInstruction_1709  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 38))  COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 38)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i80_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_for) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 25)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 26)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__24_type) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 27)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_in) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 28)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E__2E__3C_) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 31)) ;
  nt_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 34)) ;
  nt_instructionList_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("instruction-for-in-lower-upper-bounds.galgas", 37)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i81_ (GALGAS_instructionListAST & ioArgument_ioInstructionList,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  GALGAS_callInstructionAST var_routineCallInstruction_1152 ;
  nt_procedure_5F_call_ (var_routineCallInstruction_1152, inCompiler) ;
  ioArgument_ioInstructionList.addAssign_operation (var_routineCallInstruction_1152.getter_mEndOfArguments (SOURCE_FILE ("instruction-procedure-call.galgas", 21)), var_routineCallInstruction_1152  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 21)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_instruction_i81_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_procedure_5F_call_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_procedure_5F_call_i82_ (GALGAS_callInstructionAST & outArgument_outInstruction,
                                                                       C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outInstruction.drop () ; // Release 'out' argument
  GALGAS_assignmentTargetAST var_assignmentTargetAST_1481 ;
  nt_assignment_5F_target_ (var_assignmentTargetAST_1481, inCompiler) ;
  GALGAS_effectiveParameterListAST var_arguments_1523 ;
  GALGAS_location var_endOfArguments_1543 ;
  nt_effective_5F_parameters_ (var_arguments_1523, var_endOfArguments_1543, inCompiler) ;
  outArgument_outInstruction = GALGAS_callInstructionAST::constructor_new (var_assignmentTargetAST_1481, var_arguments_1523, var_endOfArguments_1543  COMMA_SOURCE_FILE ("instruction-procedure-call.galgas", 29)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_procedure_5F_call_i82_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  nt_assignment_5F_target_parse (inCompiler) ;
  nt_effective_5F_parameters_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_assignment_5F_target_i83_ (GALGAS_assignmentTargetAST & outArgument_outAssignmentTargetAST,
                                                                          C_Lexique_plm_5F_lexique * inCompiler) {
  outArgument_outAssignmentTargetAST.drop () ; // Release 'out' argument
  GALGAS_assignmentSelfAccessAST var_selfAccess_1816 ;
  switch (select_plm_5F_syntax_80 (inCompiler)) {
  case 1: {
    var_selfAccess_1816 = GALGAS_assignmentSelfAccessAST::constructor_noSelfAccess (SOURCE_FILE ("assignment-target.galgas", 44)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_self) COMMA_SOURCE_FILE ("assignment-target.galgas", 46)) ;
    var_selfAccess_1816 = GALGAS_assignmentSelfAccessAST::constructor_selfAccess (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("assignment-target.galgas", 47))  COMMA_SOURCE_FILE ("assignment-target.galgas", 47)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("assignment-target.galgas", 48)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_identifier_1998 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("assignment-target.galgas", 51)) ;
  GALGAS_accessInAssignmentListAST var_accessListAST_2075 = GALGAS_accessInAssignmentListAST::constructor_emptyList (SOURCE_FILE ("assignment-target.galgas", 53)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_81 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("assignment-target.galgas", 56)) ;
      GALGAS_lstring var_propertyName_2148 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("assignment-target.galgas", 57)) ;
      var_accessListAST_2075.addAssign_operation (GALGAS_accessInAssignmentAST::constructor_property (var_propertyName_2148  COMMA_SOURCE_FILE ("assignment-target.galgas", 58))  COMMA_SOURCE_FILE ("assignment-target.galgas", 58)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("assignment-target.galgas", 60)) ;
      GALGAS_expressionAST var_expression_2258 ;
      nt_expression_ (var_expression_2258, inCompiler) ;
      GALGAS_location var_endOfIndex_2279 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("assignment-target.galgas", 62)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("assignment-target.galgas", 63)) ;
      var_accessListAST_2075.addAssign_operation (GALGAS_accessInAssignmentAST::constructor_arrayAccess (var_expression_2258, var_endOfIndex_2279  COMMA_SOURCE_FILE ("assignment-target.galgas", 64))  COMMA_SOURCE_FILE ("assignment-target.galgas", 64)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  outArgument_outAssignmentTargetAST = GALGAS_assignmentTargetAST::constructor_new (var_selfAccess_1816, var_identifier_1998, var_accessListAST_2075  COMMA_SOURCE_FILE ("assignment-target.galgas", 67)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_assignment_5F_target_i83_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  switch (select_plm_5F_syntax_80 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_self) COMMA_SOURCE_FILE ("assignment-target.galgas", 46)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("assignment-target.galgas", 48)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("assignment-target.galgas", 51)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_plm_5F_syntax_81 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__2E_) COMMA_SOURCE_FILE ("assignment-target.galgas", 56)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_identifier) COMMA_SOURCE_FILE ("assignment-target.galgas", 57)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("assignment-target.galgas", 60)) ;
      nt_expression_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("assignment-target.galgas", 63)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i84_ (GALGAS_ast & ioArgument_ioAST,
                                                                 C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_target) COMMA_SOURCE_FILE ("target-generation.galgas", 10)) ;
  GALGAS_lstring var_targetName_595 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__22_string_22_) COMMA_SOURCE_FILE ("target-generation.galgas", 11)) ;
  ioArgument_ioAST.mAttribute_mTargetList.addAssign_operation (var_targetName_595  COMMA_SOURCE_FILE ("target-generation.galgas", 12)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_plm_5F_syntax::rule_plm_5F_syntax_declaration_i84_parse (C_Lexique_plm_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken_target) COMMA_SOURCE_FILE ("target-generation.galgas", 10)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_plm_5F_lexique::kToken__22_string_22_) COMMA_SOURCE_FILE ("target-generation.galgas", 11)) ;
  inCompiler->resetTemplateString () ;
}

