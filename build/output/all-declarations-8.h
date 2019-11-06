#pragma once

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-predefined-types.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-declarations-7.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               Extension method '@omnibusType checkIsCompileTimeType'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef void (*extensionMethodSignature_omnibusType_checkIsCompileTimeType) (const class cPtr_omnibusType * inObject,
                                                                             const class GALGAS_location constinArgument0,
                                                                             class C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionMethod_checkIsCompileTimeType (const int32_t inClassIndex,
                                                  extensionMethodSignature_omnibusType_checkIsCompileTimeType inMethod) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void callExtensionMethod_checkIsCompileTimeType (const class cPtr_omnibusType * inObject,
                                                 const GALGAS_location constin_inErrorLocation,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                              Extension method '@omnibusType checkIsNotCompileTimeType'                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef void (*extensionMethodSignature_omnibusType_checkIsNotCompileTimeType) (const class cPtr_omnibusType * inObject,
                                                                                const class GALGAS_location constinArgument0,
                                                                                class C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionMethod_checkIsNotCompileTimeType (const int32_t inClassIndex,
                                                     extensionMethodSignature_omnibusType_checkIsNotCompileTimeType inMethod) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void callExtensionMethod_checkIsNotCompileTimeType (const class cPtr_omnibusType * inObject,
                                                    const GALGAS_location constin_inErrorLocation,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Extension getter '@omnibusType isCompileTimeType'                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef class GALGAS_bool (*enterExtensionGetter_omnibusType_isCompileTimeType) (const class cPtr_omnibusType * inObject,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionGetter_isCompileTimeType (const int32_t inClassIndex,
                                             enterExtensionGetter_omnibusType_isCompileTimeType inGetter) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_bool callExtensionGetter_isCompileTimeType (const cPtr_omnibusType * inObject,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                      Extension getter '@omnibusType equatable'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef class GALGAS_bool (*enterExtensionGetter_omnibusType_equatable) (const class cPtr_omnibusType * inObject,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionGetter_equatable (const int32_t inClassIndex,
                                     enterExtensionGetter_omnibusType_equatable inGetter) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_bool callExtensionGetter_equatable (const cPtr_omnibusType * inObject,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                         Extension getter '@unifiedTypeMap-proxy instanciable' (as function)                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_bool extensionGetter_instanciable (const class GALGAS_unifiedTypeMap_2D_proxy & inObject,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Extension getter '@omnibusType instanciable'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef class GALGAS_bool (*enterExtensionGetter_omnibusType_instanciable) (const class cPtr_omnibusType * inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionGetter_instanciable (const int32_t inClassIndex,
                                        enterExtensionGetter_omnibusType_instanciable inGetter) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_bool callExtensionGetter_instanciable (const cPtr_omnibusType * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                           Extension getter '@unifiedTypeMap-proxy copyable' (as function)                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_bool extensionGetter_copyable (const class GALGAS_unifiedTypeMap_2D_proxy & inObject,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                      Extension getter '@omnibusType copyable'                                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef class GALGAS_bool (*enterExtensionGetter_omnibusType_copyable) (const class cPtr_omnibusType * inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionGetter_copyable (const int32_t inClassIndex,
                                    enterExtensionGetter_omnibusType_copyable inGetter) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_bool callExtensionGetter_copyable (const cPtr_omnibusType * inObject,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Extension method '@omnibusType generateRetain'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef void (*extensionMethodSignature_omnibusType_generateRetain) (const class cPtr_omnibusType * inObject,
                                                                     const class GALGAS_string constinArgument0,
                                                                     class GALGAS_string & ioArgument1,
                                                                     class GALGAS_generationAdds & ioArgument2,
                                                                     class C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionMethod_generateRetain (const int32_t inClassIndex,
                                          extensionMethodSignature_omnibusType_generateRetain inMethod) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void callExtensionMethod_generateRetain (const class cPtr_omnibusType * inObject,
                                         const GALGAS_string constin_inOmnibusName,
                                         GALGAS_string & io_ioLLVMcode,
                                         GALGAS_generationAdds & io_ioGenerationAdds,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                       Extension getter '@omnibusType arcList'                                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef class GALGAS_arcAssignmentList (*enterExtensionGetter_omnibusType_arcList) (const class cPtr_omnibusType * inObject,
                                                                                    const class GALGAS_uintlist constinArgument0,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionGetter_arcList (const int32_t inClassIndex,
                                   enterExtensionGetter_omnibusType_arcList inGetter) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_arcAssignmentList callExtensionGetter_arcList (const cPtr_omnibusType * inObject,
                                                            const GALGAS_uintlist constin_inPropertyIndexPath,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Extension method '@omnibusType generateInsulate'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef void (*extensionMethodSignature_omnibusType_generateInsulate) (const class cPtr_omnibusType * inObject,
                                                                       const class GALGAS_string constinArgument0,
                                                                       class GALGAS_string & ioArgument1,
                                                                       class GALGAS_generationAdds & ioArgument2,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionMethod_generateInsulate (const int32_t inClassIndex,
                                            extensionMethodSignature_omnibusType_generateInsulate inMethod) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void callExtensionMethod_generateInsulate (const class cPtr_omnibusType * inObject,
                                           const GALGAS_string constin_inOmnibusName,
                                           GALGAS_string & io_ioLLVMcode,
                                           GALGAS_generationAdds & io_ioGenerationAdds,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Extension method '@omnibusType generateRelease'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef void (*extensionMethodSignature_omnibusType_generateRelease) (const class cPtr_omnibusType * inObject,
                                                                      const class GALGAS_string constinArgument0,
                                                                      class GALGAS_string & ioArgument1,
                                                                      class GALGAS_generationAdds & ioArgument2,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionMethod_generateRelease (const int32_t inClassIndex,
                                           extensionMethodSignature_omnibusType_generateRelease inMethod) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void callExtensionMethod_generateRelease (const class cPtr_omnibusType * inObject,
                                          const GALGAS_string constin_inOmnibusName,
                                          GALGAS_string & io_ioLLVMcode,
                                          GALGAS_generationAdds & io_ioGenerationAdds,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               Extension getter '@omnibusType descriptionForHTMLFile'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef class GALGAS_string (*enterExtensionGetter_omnibusType_descriptionForHTMLFile) (const class cPtr_omnibusType * inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionGetter_descriptionForHTMLFile (const int32_t inClassIndex,
                                                  enterExtensionGetter_omnibusType_descriptionForHTMLFile inGetter) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_string callExtensionGetter_descriptionForHTMLFile (const cPtr_omnibusType * inObject,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Extension getter '@omnibusType deinitNeeded'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef class GALGAS_bool (*enterExtensionGetter_omnibusType_deinitNeeded) (const class cPtr_omnibusType * inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionGetter_deinitNeeded (const int32_t inClassIndex,
                                        enterExtensionGetter_omnibusType_deinitNeeded inGetter) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_bool callExtensionGetter_deinitNeeded (const cPtr_omnibusType * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                       Abstract extension method '@userLLVMTypeDefinitionIR generateLLVMType'                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef void (*extensionMethodSignature_userLLVMTypeDefinitionIR_generateLLVMType) (const class cPtr_userLLVMTypeDefinitionIR * inObject,
                                                                                    class GALGAS_string & ioArgument0,
                                                                                    class C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionMethod_generateLLVMType (const int32_t inClassIndex,
                                            extensionMethodSignature_userLLVMTypeDefinitionIR_generateLLVMType inMethod) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void callExtensionMethod_generateLLVMType (const class cPtr_userLLVMTypeDefinitionIR * inObject,
                                           GALGAS_string & io_ioLLVMcode,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               Extension method '@panicAST noteTypesInPrecedenceGraph'                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef void (*extensionMethodSignature_panicAST_noteTypesInPrecedenceGraph) (const class cPtr_panicAST * inObject,
                                                                              class GALGAS_semanticTypePrecedenceGraph & ioArgument0,
                                                                              class C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionMethod_noteTypesInPrecedenceGraph (const int32_t inClassIndex,
                                                      extensionMethodSignature_panicAST_noteTypesInPrecedenceGraph inMethod) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void callExtensionMethod_noteTypesInPrecedenceGraph (const class cPtr_panicAST * inObject,
                                                     GALGAS_semanticTypePrecedenceGraph & io_ioGraph,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                            @decoratedPanicRoutine class                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_decoratedPanicRoutine : public GALGAS_abstractDecoratedDeclaration {
//--- Constructor
  public : GALGAS_decoratedPanicRoutine (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_decoratedPanicRoutine constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_decoratedPanicRoutine * ptr (void) const { return (const cPtr_decoratedPanicRoutine *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_decoratedPanicRoutine (const cPtr_decoratedPanicRoutine * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_decoratedPanicRoutine extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_decoratedPanicRoutine constructor_new (const class GALGAS_bool & inOperand0,
                                                                      const class GALGAS_lbigint & inOperand1
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_decoratedPanicRoutine & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mIsSetup (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lbigint getter_mPriority (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_decoratedPanicRoutine class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_decoratedPanicRoutine ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Pointer class for @decoratedPanicRoutine class                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_decoratedPanicRoutine : public cPtr_abstractDecoratedDeclaration {
//--- Attributes
  public : GALGAS_bool mProperty_mIsSetup ;
  public : GALGAS_lbigint mProperty_mPriority ;

//--- Constructor
  public : cPtr_decoratedPanicRoutine (const GALGAS_bool & in_mIsSetup,
                                       const GALGAS_lbigint & in_mPriority
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_mIsSetup (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lbigint getter_mPriority (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          @fileSpecificPanicRoutineIR class                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_fileSpecificPanicRoutineIR : public GALGAS_abstractRoutineIR {
//--- Constructor
  public : GALGAS_fileSpecificPanicRoutineIR (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_fileSpecificPanicRoutineIR constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_fileSpecificPanicRoutineIR * ptr (void) const { return (const cPtr_fileSpecificPanicRoutineIR *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_fileSpecificPanicRoutineIR (const cPtr_fileSpecificPanicRoutineIR * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_fileSpecificPanicRoutineIR extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_fileSpecificPanicRoutineIR constructor_new (const class GALGAS_lstring & inOperand0,
                                                                           const class GALGAS_bool & inOperand1,
                                                                           const class GALGAS_bool & inOperand2,
                                                                           const class GALGAS_string & inOperand3
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_fileSpecificPanicRoutineIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_inFilePath (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_fileSpecificPanicRoutineIR class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_fileSpecificPanicRoutineIR ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Pointer class for @fileSpecificPanicRoutineIR class                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_fileSpecificPanicRoutineIR : public cPtr_abstractRoutineIR {
//--- Attributes
  public : GALGAS_string mProperty_inFilePath ;

//--- Constructor
  public : cPtr_fileSpecificPanicRoutineIR (const GALGAS_lstring & in_mRoutineMangledName,
                                            const GALGAS_bool & in_isRequired,
                                            const GALGAS_bool & in_warnsIfUnused,
                                            const GALGAS_string & in_inFilePath
                                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_inFilePath (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                         @universalModePanicRoutineIR class                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_universalModePanicRoutineIR : public GALGAS_abstractRoutineIR {
//--- Constructor
  public : GALGAS_universalModePanicRoutineIR (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_universalModePanicRoutineIR constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_universalModePanicRoutineIR * ptr (void) const { return (const cPtr_universalModePanicRoutineIR *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_universalModePanicRoutineIR (const cPtr_universalModePanicRoutineIR * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_universalModePanicRoutineIR extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_universalModePanicRoutineIR constructor_new (const class GALGAS_lstring & inOperand0,
                                                                            const class GALGAS_bool & inOperand1,
                                                                            const class GALGAS_bool & inOperand2
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_universalModePanicRoutineIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_universalModePanicRoutineIR class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_universalModePanicRoutineIR ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Pointer class for @universalModePanicRoutineIR class                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_universalModePanicRoutineIR : public cPtr_abstractRoutineIR {
//--- Attributes

//--- Constructor
  public : cPtr_universalModePanicRoutineIR (const GALGAS_lstring & in_mRoutineMangledName,
                                             const GALGAS_bool & in_isRequired,
                                             const GALGAS_bool & in_warnsIfUnused
                                             COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          @sectionModePanicRoutineIR class                                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_sectionModePanicRoutineIR : public GALGAS_abstractRoutineIR {
//--- Constructor
  public : GALGAS_sectionModePanicRoutineIR (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_sectionModePanicRoutineIR constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_sectionModePanicRoutineIR * ptr (void) const { return (const cPtr_sectionModePanicRoutineIR *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_sectionModePanicRoutineIR (const cPtr_sectionModePanicRoutineIR * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_sectionModePanicRoutineIR extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_sectionModePanicRoutineIR constructor_new (const class GALGAS_lstring & inOperand0,
                                                                          const class GALGAS_bool & inOperand1,
                                                                          const class GALGAS_bool & inOperand2,
                                                                          const class GALGAS_panicSortedListIR & inOperand3,
                                                                          const class GALGAS_panicSortedListIR & inOperand4
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_sectionModePanicRoutineIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_panicSortedListIR getter_mPanicLoopListIR (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_panicSortedListIR getter_mPanicSetupListIR (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_sectionModePanicRoutineIR class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sectionModePanicRoutineIR ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Pointer class for @sectionModePanicRoutineIR class                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_sectionModePanicRoutineIR : public cPtr_abstractRoutineIR {
//--- Attributes
  public : GALGAS_panicSortedListIR mProperty_mPanicSetupListIR ;
  public : GALGAS_panicSortedListIR mProperty_mPanicLoopListIR ;

//--- Constructor
  public : cPtr_sectionModePanicRoutineIR (const GALGAS_lstring & in_mRoutineMangledName,
                                           const GALGAS_bool & in_isRequired,
                                           const GALGAS_bool & in_warnsIfUnused,
                                           const GALGAS_panicSortedListIR & in_mPanicSetupListIR,
                                           const GALGAS_panicSortedListIR & in_mPanicLoopListIR
                                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_panicSortedListIR getter_mPanicSetupListIR (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_panicSortedListIR getter_mPanicLoopListIR (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    @compileTimeImplicitConverterToBoolean class                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_compileTimeImplicitConverterToBoolean : public GALGAS_abstractImplicitConverterToBoolean {
//--- Constructor
  public : GALGAS_compileTimeImplicitConverterToBoolean (void) ;

//---
  public : inline const class cPtr_compileTimeImplicitConverterToBoolean * ptr (void) const { return (const cPtr_compileTimeImplicitConverterToBoolean *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_compileTimeImplicitConverterToBoolean (const cPtr_compileTimeImplicitConverterToBoolean * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_compileTimeImplicitConverterToBoolean extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_compileTimeImplicitConverterToBoolean constructor_new (const class GALGAS_lstring & inOperand0,
                                                                                      const class GALGAS_ctExpressionAST & inOperand1
                                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_compileTimeImplicitConverterToBoolean & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_ctExpressionAST getter_mExpression (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mReceiverName (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_compileTimeImplicitConverterToBoolean class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_compileTimeImplicitConverterToBoolean ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                           Pointer class for @compileTimeImplicitConverterToBoolean class                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_compileTimeImplicitConverterToBoolean : public cPtr_abstractImplicitConverterToBoolean {
//--- Attributes
  public : GALGAS_lstring mProperty_mReceiverName ;
  public : GALGAS_ctExpressionAST mProperty_mExpression ;

//--- Constructor
  public : cPtr_compileTimeImplicitConverterToBoolean (const GALGAS_lstring & in_mReceiverName,
                                                       const GALGAS_ctExpressionAST & in_mExpression
                                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_mReceiverName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_ctExpressionAST getter_mExpression (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                        @llvmImplicitConverterToBoolean class                                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_llvmImplicitConverterToBoolean : public GALGAS_abstractImplicitConverterToBoolean {
//--- Constructor
  public : GALGAS_llvmImplicitConverterToBoolean (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_llvmImplicitConverterToBoolean constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_llvmImplicitConverterToBoolean * ptr (void) const { return (const cPtr_llvmImplicitConverterToBoolean *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_llvmImplicitConverterToBoolean (const cPtr_llvmImplicitConverterToBoolean * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_llvmImplicitConverterToBoolean extractObject (const GALGAS_object & inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_llvmImplicitConverterToBoolean constructor_new (const class GALGAS_lstring & inOperand0,
                                                                               const class GALGAS_omnibusType & inOperand1,
                                                                               const class GALGAS_llvmGenerationInstructionList & inOperand2
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_llvmImplicitConverterToBoolean & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_llvmGenerationInstructionList getter_mInstructionList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mReceiverName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_omnibusType getter_mReceiverType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_llvmImplicitConverterToBoolean class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_llvmImplicitConverterToBoolean ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               Pointer class for @llvmImplicitConverterToBoolean class                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_llvmImplicitConverterToBoolean : public cPtr_abstractImplicitConverterToBoolean {
//--- Attributes
  public : GALGAS_lstring mProperty_mReceiverName ;
  public : GALGAS_omnibusType mProperty_mReceiverType ;
  public : GALGAS_llvmGenerationInstructionList mProperty_mInstructionList ;

//--- Constructor
  public : cPtr_llvmImplicitConverterToBoolean (const GALGAS_lstring & in_mReceiverName,
                                                const GALGAS_omnibusType & in_mReceiverType,
                                                const GALGAS_llvmGenerationInstructionList & in_mInstructionList
                                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_mReceiverName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_omnibusType getter_mReceiverType (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_llvmGenerationInstructionList getter_mInstructionList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             @convertInstructionIR class                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_convertInstructionIR : public GALGAS_abstractInstructionIR {
//--- Constructor
  public : GALGAS_convertInstructionIR (void) ;

//---
  public : inline const class cPtr_convertInstructionIR * ptr (void) const { return (const cPtr_convertInstructionIR *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_convertInstructionIR (const cPtr_convertInstructionIR * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_convertInstructionIR extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_convertInstructionIR constructor_new (const class GALGAS_objectIR & inOperand0,
                                                                     const class GALGAS_objectIR & inOperand1,
                                                                     const class GALGAS_location & inOperand2
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_convertInstructionIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_mLocation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectIR getter_mOperand (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectIR getter_mTarget (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_convertInstructionIR class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_convertInstructionIR ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Pointer class for @convertInstructionIR class                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_convertInstructionIR : public cPtr_abstractInstructionIR {
//--- Attributes
  public : GALGAS_objectIR mProperty_mTarget ;
  public : GALGAS_objectIR mProperty_mOperand ;
  public : GALGAS_location mProperty_mLocation ;

//--- Constructor
  public : cPtr_convertInstructionIR (const GALGAS_objectIR & in_mTarget,
                                      const GALGAS_objectIR & in_mOperand,
                                      const GALGAS_location & in_mLocation
                                      COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_objectIR getter_mTarget (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_objectIR getter_mOperand (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_location getter_mLocation (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             @sizeofInstructionIR class                                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_sizeofInstructionIR : public GALGAS_abstractInstructionIR {
//--- Constructor
  public : GALGAS_sizeofInstructionIR (void) ;

//---
  public : inline const class cPtr_sizeofInstructionIR * ptr (void) const { return (const cPtr_sizeofInstructionIR *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_sizeofInstructionIR (const cPtr_sizeofInstructionIR * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_sizeofInstructionIR extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_sizeofInstructionIR constructor_new (const class GALGAS_objectIR & inOperand0,
                                                                    const class GALGAS_omnibusType & inOperand1
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_sizeofInstructionIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_omnibusType getter_mSourceType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectIR getter_mTarget (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_sizeofInstructionIR class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sizeofInstructionIR ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Pointer class for @sizeofInstructionIR class                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_sizeofInstructionIR : public cPtr_abstractInstructionIR {
//--- Attributes
  public : GALGAS_objectIR mProperty_mTarget ;
  public : GALGAS_omnibusType mProperty_mSourceType ;

//--- Constructor
  public : cPtr_sizeofInstructionIR (const GALGAS_objectIR & in_mTarget,
                                     const GALGAS_omnibusType & in_mSourceType
                                     COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_objectIR getter_mTarget (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_omnibusType getter_mSourceType (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      Extension method '@primaryInExpressionAST analyzePrimaryExpressionNoSelf'                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef void (*extensionMethodSignature_primaryInExpressionAST_analyzePrimaryExpressionNoSelf) (const class cPtr_primaryInExpressionAST * inObject,
                                                                                                const class GALGAS_omnibusType constinArgument0,
                                                                                                const class GALGAS_routineAttributes constinArgument1,
                                                                                                const class GALGAS_omnibusType constinArgument2,
                                                                                                const class GALGAS_semanticContext constinArgument3,
                                                                                                const class GALGAS_mode constinArgument4,
                                                                                                class GALGAS_semanticTemporariesStruct & ioArgument5,
                                                                                                class GALGAS_staticEntityMap & ioArgument6,
                                                                                                class GALGAS_universalValuedObjectMap & ioArgument7,
                                                                                                class GALGAS_allocaList & ioArgument8,
                                                                                                class GALGAS_instructionListIR & ioArgument9,
                                                                                                class GALGAS_objectIR & outArgument10,
                                                                                                class C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionMethod_analyzePrimaryExpressionNoSelf (const int32_t inClassIndex,
                                                          extensionMethodSignature_primaryInExpressionAST_analyzePrimaryExpressionNoSelf inMethod) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void callExtensionMethod_analyzePrimaryExpressionNoSelf (const class cPtr_primaryInExpressionAST * inObject,
                                                         const GALGAS_omnibusType constin_inSelfType,
                                                         const GALGAS_routineAttributes constin_inRoutineAttributes,
                                                         const GALGAS_omnibusType constin_inOptionalTargetType,
                                                         const GALGAS_semanticContext constin_inContext,
                                                         const GALGAS_mode constin_inMode,
                                                         GALGAS_semanticTemporariesStruct & io_ioTemporaries,
                                                         GALGAS_staticEntityMap & io_ioStaticEntityMap,
                                                         GALGAS_universalValuedObjectMap & io_ioUniversalMap,
                                                         GALGAS_allocaList & io_ioAllocaList,
                                                         GALGAS_instructionListIR & io_ioInstructionGenerationList,
                                                         GALGAS_objectIR & out_outResult,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Routine 'procAnalyzeAccesListInExpression'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_procAnalyzeAccesListInExpression (const class GALGAS_omnibusType constinArgument0,
                                               const class GALGAS_routineAttributes constinArgument1,
                                               const class GALGAS_omnibusType constinArgument2,
                                               const class GALGAS_semanticContext constinArgument3,
                                               const class GALGAS_mode constinArgument4,
                                               class GALGAS_semanticTemporariesStruct & ioArgument5,
                                               class GALGAS_staticEntityMap & ioArgument6,
                                               class GALGAS_universalValuedObjectMap & ioArgument7,
                                               class GALGAS_allocaList & ioArgument8,
                                               class GALGAS_instructionListIR & ioArgument9,
                                               const class GALGAS_primaryInExpressionAccessListAST constinArgument10,
                                               class GALGAS_objectIR & ioArgument11,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     Extension method '@primaryInExpressionAST analyzePrimaryExpressionWithSelf'                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef void (*extensionMethodSignature_primaryInExpressionAST_analyzePrimaryExpressionWithSelf) (const class cPtr_primaryInExpressionAST * inObject,
                                                                                                  const class GALGAS_omnibusType constinArgument0,
                                                                                                  const class GALGAS_routineAttributes constinArgument1,
                                                                                                  const class GALGAS_omnibusType constinArgument2,
                                                                                                  const class GALGAS_semanticContext constinArgument3,
                                                                                                  const class GALGAS_mode constinArgument4,
                                                                                                  class GALGAS_semanticTemporariesStruct & ioArgument5,
                                                                                                  class GALGAS_staticEntityMap & ioArgument6,
                                                                                                  class GALGAS_universalValuedObjectMap & ioArgument7,
                                                                                                  class GALGAS_allocaList & ioArgument8,
                                                                                                  class GALGAS_instructionListIR & ioArgument9,
                                                                                                  class GALGAS_objectIR & outArgument10,
                                                                                                  class C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionMethod_analyzePrimaryExpressionWithSelf (const int32_t inClassIndex,
                                                            extensionMethodSignature_primaryInExpressionAST_analyzePrimaryExpressionWithSelf inMethod) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void callExtensionMethod_analyzePrimaryExpressionWithSelf (const class cPtr_primaryInExpressionAST * inObject,
                                                           const GALGAS_omnibusType constin_inSelfType,
                                                           const GALGAS_routineAttributes constin_inRoutineAttributes,
                                                           const GALGAS_omnibusType constin_inOptionalTargetType,
                                                           const GALGAS_semanticContext constin_inContext,
                                                           const GALGAS_mode constin_inMode,
                                                           GALGAS_semanticTemporariesStruct & io_ioTemporaries,
                                                           GALGAS_staticEntityMap & io_ioStaticEntityMap,
                                                           GALGAS_universalValuedObjectMap & io_ioUniversalMap,
                                                           GALGAS_allocaList & io_ioAllocaList,
                                                           GALGAS_instructionListIR & io_ioInstructionGenerationList,
                                                           GALGAS_objectIR & out_outResult,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                       Routine 'handleArrayAccessInExpression'                                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_handleArrayAccessInExpression (class GALGAS_objectIR & ioArgument0,
                                            const class GALGAS_expressionAST constinArgument1,
                                            const class GALGAS_location constinArgument2,
                                            const class GALGAS_bool constinArgument3,
                                            const class GALGAS_omnibusType constinArgument4,
                                            const class GALGAS_routineAttributes constinArgument5,
                                            const class GALGAS_omnibusType constinArgument6,
                                            const class GALGAS_semanticContext constinArgument7,
                                            const class GALGAS_mode constinArgument8,
                                            class GALGAS_semanticTemporariesStruct & ioArgument9,
                                            class GALGAS_staticEntityMap & ioArgument10,
                                            class GALGAS_universalValuedObjectMap & ioArgument11,
                                            class GALGAS_allocaList & ioArgument12,
                                            class GALGAS_instructionListIR & ioArgument13,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                      Routine 'handleFunctionCallInExpression'                                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_handleFunctionCallInExpression (const class GALGAS_lstring constinArgument0,
                                             class GALGAS_objectIR & ioArgument1,
                                             const class GALGAS_omnibusType constinArgument2,
                                             const class GALGAS_semanticContext constinArgument3,
                                             const class GALGAS_mode constinArgument4,
                                             const class GALGAS_routineAttributes constinArgument5,
                                             class GALGAS_semanticTemporariesStruct & ioArgument6,
                                             class GALGAS_staticEntityMap & ioArgument7,
                                             class GALGAS_universalValuedObjectMap & ioArgument8,
                                             class GALGAS_allocaList & ioArgument9,
                                             const class GALGAS_effectiveArgumentListAST constinArgument10,
                                             class GALGAS_instructionListIR & ioArgument11,
                                             class C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Routine 'handlePropertyAccessInExpression'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_handlePropertyAccessInExpression (class GALGAS_objectIR & ioArgument0,
                                               const class GALGAS_lstring constinArgument1,
                                               const class GALGAS_mode constinArgument2,
                                               class GALGAS_semanticTemporariesStruct & ioArgument3,
                                               class GALGAS_allocaList & ioArgument4,
                                               class GALGAS_instructionListIR & ioArgument5,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          Routine 'handleSliceInExpression'                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_handleSliceInExpression (const class GALGAS_semanticContext constinArgument0,
                                      class GALGAS_objectIR & ioArgument1,
                                      const class GALGAS_lbigint constinArgument2,
                                      const class GALGAS_lbigint constinArgument3,
                                      class GALGAS_semanticTemporariesStruct & ioArgument4,
                                      class GALGAS_instructionListIR & ioArgument5,
                                      class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                        @compileTimeInfixOperatorUsage class                                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_compileTimeInfixOperatorUsage : public GALGAS_omnibusInfixOperatorUsage {
//--- Constructor
  public : GALGAS_compileTimeInfixOperatorUsage (void) ;

//---
  public : inline const class cPtr_compileTimeInfixOperatorUsage * ptr (void) const { return (const cPtr_compileTimeInfixOperatorUsage *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_compileTimeInfixOperatorUsage (const cPtr_compileTimeInfixOperatorUsage * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_compileTimeInfixOperatorUsage extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_compileTimeInfixOperatorUsage constructor_new (const class GALGAS_lstring & inOperand0,
                                                                              const class GALGAS_lstring & inOperand1,
                                                                              const class GALGAS_ctExpressionAST & inOperand2
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_compileTimeInfixOperatorUsage & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_ctExpressionAST getter_mExpression (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mLeftOperandName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mRightOperandName (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_compileTimeInfixOperatorUsage class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_compileTimeInfixOperatorUsage ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               Pointer class for @compileTimeInfixOperatorUsage class                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_compileTimeInfixOperatorUsage : public cPtr_omnibusInfixOperatorUsage {
//--- Attributes
  public : GALGAS_lstring mProperty_mLeftOperandName ;
  public : GALGAS_lstring mProperty_mRightOperandName ;
  public : GALGAS_ctExpressionAST mProperty_mExpression ;

//--- Constructor
  public : cPtr_compileTimeInfixOperatorUsage (const GALGAS_lstring & in_mLeftOperandName,
                                               const GALGAS_lstring & in_mRightOperandName,
                                               const GALGAS_ctExpressionAST & in_mExpression
                                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_mLeftOperandName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_mRightOperandName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_ctExpressionAST getter_mExpression (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               Extension method '@compileTimeInfixOperatorUsage eval'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef void (*extensionMethodSignature_compileTimeInfixOperatorUsage_eval) (const class cPtr_compileTimeInfixOperatorUsage * inObject,
                                                                             const class GALGAS_objectIR constinArgument0,
                                                                             const class GALGAS_objectIR constinArgument1,
                                                                             class GALGAS_bigint & outArgument2,
                                                                             class C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionMethod_eval (const int32_t inClassIndex,
                                extensionMethodSignature_compileTimeInfixOperatorUsage_eval inMethod) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void callExtensionMethod_eval (const class cPtr_compileTimeInfixOperatorUsage * inObject,
                               const GALGAS_objectIR constin_inLeftOperand,
                               const GALGAS_objectIR constin_inRightOperand,
                               GALGAS_bigint & out_outResult,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    @compileTimeInfixInfEqualOperatorUsage class                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_compileTimeInfixInfEqualOperatorUsage : public GALGAS_omnibusInfixOperatorUsage {
//--- Constructor
  public : GALGAS_compileTimeInfixInfEqualOperatorUsage (void) ;

//---
  public : inline const class cPtr_compileTimeInfixInfEqualOperatorUsage * ptr (void) const { return (const cPtr_compileTimeInfixInfEqualOperatorUsage *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_compileTimeInfixInfEqualOperatorUsage (const cPtr_compileTimeInfixInfEqualOperatorUsage * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_compileTimeInfixInfEqualOperatorUsage extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_compileTimeInfixInfEqualOperatorUsage constructor_new (const class GALGAS_compileTimeInfixOperatorUsage & inOperand0,
                                                                                      const class GALGAS_compileTimeInfixOperatorUsage & inOperand1
                                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_compileTimeInfixInfEqualOperatorUsage & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_compileTimeInfixOperatorUsage getter_mEqualOperatorUsage (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_compileTimeInfixOperatorUsage getter_mLessThanOperatorUsage (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_compileTimeInfixInfEqualOperatorUsage class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_compileTimeInfixInfEqualOperatorUsage ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                           Pointer class for @compileTimeInfixInfEqualOperatorUsage class                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_compileTimeInfixInfEqualOperatorUsage : public cPtr_omnibusInfixOperatorUsage {
//--- Attributes
  public : GALGAS_compileTimeInfixOperatorUsage mProperty_mEqualOperatorUsage ;
  public : GALGAS_compileTimeInfixOperatorUsage mProperty_mLessThanOperatorUsage ;

//--- Constructor
  public : cPtr_compileTimeInfixInfEqualOperatorUsage (const GALGAS_compileTimeInfixOperatorUsage & in_mEqualOperatorUsage,
                                                       const GALGAS_compileTimeInfixOperatorUsage & in_mLessThanOperatorUsage
                                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_compileTimeInfixOperatorUsage getter_mEqualOperatorUsage (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_compileTimeInfixOperatorUsage getter_mLessThanOperatorUsage (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                            @llvmInfixOperatorUsage class                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_llvmInfixOperatorUsage : public GALGAS_omnibusInfixOperatorUsage {
//--- Constructor
  public : GALGAS_llvmInfixOperatorUsage (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_llvmInfixOperatorUsage constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_llvmInfixOperatorUsage * ptr (void) const { return (const cPtr_llvmInfixOperatorUsage *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_llvmInfixOperatorUsage (const cPtr_llvmInfixOperatorUsage * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_llvmInfixOperatorUsage extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_llvmInfixOperatorUsage constructor_new (const class GALGAS_string & inOperand0,
                                                                       const class GALGAS_lstring & inOperand1,
                                                                       const class GALGAS_lstring & inOperand2,
                                                                       const class GALGAS_llvmGenerationInstructionList & inOperand3
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_llvmInfixOperatorUsage & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mInfixMangledFunctionName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_llvmGenerationInstructionList getter_mInstructionList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mLeftOperandName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mRightOperandName (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_llvmInfixOperatorUsage class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_llvmInfixOperatorUsage ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Pointer class for @llvmInfixOperatorUsage class                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_llvmInfixOperatorUsage : public cPtr_omnibusInfixOperatorUsage {
//--- Attributes
  public : GALGAS_string mProperty_mInfixMangledFunctionName ;
  public : GALGAS_lstring mProperty_mLeftOperandName ;
  public : GALGAS_lstring mProperty_mRightOperandName ;
  public : GALGAS_llvmGenerationInstructionList mProperty_mInstructionList ;

//--- Constructor
  public : cPtr_llvmInfixOperatorUsage (const GALGAS_string & in_mInfixMangledFunctionName,
                                        const GALGAS_lstring & in_mLeftOperandName,
                                        const GALGAS_lstring & in_mRightOperandName,
                                        const GALGAS_llvmGenerationInstructionList & in_mInstructionList
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_mInfixMangledFunctionName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_mLeftOperandName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_mRightOperandName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_llvmGenerationInstructionList getter_mInstructionList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                            @infixOperatorRoutineIR class                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_infixOperatorRoutineIR : public GALGAS_abstractRoutineIR {
//--- Constructor
  public : GALGAS_infixOperatorRoutineIR (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_infixOperatorRoutineIR constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_infixOperatorRoutineIR * ptr (void) const { return (const cPtr_infixOperatorRoutineIR *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_infixOperatorRoutineIR (const cPtr_infixOperatorRoutineIR * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_infixOperatorRoutineIR extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_infixOperatorRoutineIR constructor_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_bool & inOperand1,
                                                                       const class GALGAS_bool & inOperand2,
                                                                       const class GALGAS_omnibusType & inOperand3,
                                                                       const class GALGAS_string & inOperand4,
                                                                       const class GALGAS_omnibusType & inOperand5,
                                                                       const class GALGAS_string & inOperand6,
                                                                       const class GALGAS_omnibusType & inOperand7,
                                                                       const class GALGAS_stringlist & inOperand8,
                                                                       const class GALGAS_allocaList & inOperand9
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_infixOperatorRoutineIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_allocaList getter_mAllocaList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_mGeneratedInstructions (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_omnibusType getter_mResultType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_omnibusType getter_mSourceType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mSourceVarName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_omnibusType getter_mTargetType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mTargetVarName (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_infixOperatorRoutineIR class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_infixOperatorRoutineIR ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Pointer class for @infixOperatorRoutineIR class                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_infixOperatorRoutineIR : public cPtr_abstractRoutineIR {
//--- Attributes
  public : GALGAS_omnibusType mProperty_mTargetType ;
  public : GALGAS_string mProperty_mTargetVarName ;
  public : GALGAS_omnibusType mProperty_mSourceType ;
  public : GALGAS_string mProperty_mSourceVarName ;
  public : GALGAS_omnibusType mProperty_mResultType ;
  public : GALGAS_stringlist mProperty_mGeneratedInstructions ;
  public : GALGAS_allocaList mProperty_mAllocaList ;

//--- Constructor
  public : cPtr_infixOperatorRoutineIR (const GALGAS_lstring & in_mRoutineMangledName,
                                        const GALGAS_bool & in_isRequired,
                                        const GALGAS_bool & in_warnsIfUnused,
                                        const GALGAS_omnibusType & in_mTargetType,
                                        const GALGAS_string & in_mTargetVarName,
                                        const GALGAS_omnibusType & in_mSourceType,
                                        const GALGAS_string & in_mSourceVarName,
                                        const GALGAS_omnibusType & in_mResultType,
                                        const GALGAS_stringlist & in_mGeneratedInstructions,
                                        const GALGAS_allocaList & in_mAllocaList
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_omnibusType getter_mTargetType (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_mTargetVarName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_omnibusType getter_mSourceType (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_mSourceVarName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_omnibusType getter_mResultType (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_stringlist getter_mGeneratedInstructions (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_allocaList getter_mAllocaList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//               Abstract extension method '@omnibusInfixOperatorDescription generateInfixOperatorCode'                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef void (*extensionMethodSignature_omnibusInfixOperatorDescription_generateInfixOperatorCode) (const class cPtr_omnibusInfixOperatorDescription * inObject,
                                                                                                    class GALGAS_semanticTemporariesStruct & ioArgument0,
                                                                                                    class GALGAS_instructionListIR & ioArgument1,
                                                                                                    const class GALGAS_objectIR constinArgument2,
                                                                                                    const class GALGAS_location constinArgument3,
                                                                                                    const class GALGAS_objectIR constinArgument4,
                                                                                                    const class GALGAS_omnibusType constinArgument5,
                                                                                                    class GALGAS_objectIR & outArgument6,
                                                                                                    class C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionMethod_generateInfixOperatorCode (const int32_t inClassIndex,
                                                     extensionMethodSignature_omnibusInfixOperatorDescription_generateInfixOperatorCode inMethod) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void callExtensionMethod_generateInfixOperatorCode (const class cPtr_omnibusInfixOperatorDescription * inObject,
                                                    GALGAS_semanticTemporariesStruct & io_ioTemporaries,
                                                    GALGAS_instructionListIR & io_ioInstructionGenerationList,
                                                    const GALGAS_objectIR constin_inLeftOperand,
                                                    const GALGAS_location constin_inOperatorLocation,
                                                    const GALGAS_objectIR constin_inRightOperand,
                                                    const GALGAS_omnibusType constin_inResultType,
                                                    GALGAS_objectIR & out_outResultValue,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     Extension getter '@omnibusInfixOperatorDescription performStaticOperation'                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typedef class GALGAS_bigint (*enterExtensionGetter_omnibusInfixOperatorDescription_performStaticOperation) (const class cPtr_omnibusInfixOperatorDescription * inObject,
                                                                                                            const class GALGAS_bigint constinArgument0,
                                                                                                            const class GALGAS_bigint constinArgument1,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void enterExtensionGetter_performStaticOperation (const int32_t inClassIndex,
                                                  enterExtensionGetter_omnibusInfixOperatorDescription_performStaticOperation inGetter) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_bigint callExtensionGetter_performStaticOperation (const cPtr_omnibusInfixOperatorDescription * inObject,
                                                                const GALGAS_bigint constin_inLeft,
                                                                const GALGAS_bigint constin_inRight,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                        @compileTimePrefixOperatorUsage class                                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_compileTimePrefixOperatorUsage : public GALGAS_prefixOperatorUsage {
//--- Constructor
  public : GALGAS_compileTimePrefixOperatorUsage (void) ;

//---
  public : inline const class cPtr_compileTimePrefixOperatorUsage * ptr (void) const { return (const cPtr_compileTimePrefixOperatorUsage *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_compileTimePrefixOperatorUsage (const cPtr_compileTimePrefixOperatorUsage * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_compileTimePrefixOperatorUsage extractObject (const GALGAS_object & inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_compileTimePrefixOperatorUsage constructor_new (const class GALGAS_location & inOperand0,
                                                                               const class GALGAS_lstring & inOperand1,
                                                                               const class GALGAS_ctExpressionAST & inOperand2
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_compileTimePrefixOperatorUsage & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_ctExpressionAST getter_mExpression (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_mPrefixOperatorLocation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mReceiverOperandName (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_compileTimePrefixOperatorUsage class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_compileTimePrefixOperatorUsage ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               Pointer class for @compileTimePrefixOperatorUsage class                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_compileTimePrefixOperatorUsage : public cPtr_prefixOperatorUsage {
//--- Attributes
  public : GALGAS_location mProperty_mPrefixOperatorLocation ;
  public : GALGAS_lstring mProperty_mReceiverOperandName ;
  public : GALGAS_ctExpressionAST mProperty_mExpression ;

//--- Constructor
  public : cPtr_compileTimePrefixOperatorUsage (const GALGAS_location & in_mPrefixOperatorLocation,
                                                const GALGAS_lstring & in_mReceiverOperandName,
                                                const GALGAS_ctExpressionAST & in_mExpression
                                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_location getter_mPrefixOperatorLocation (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_mReceiverOperandName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_ctExpressionAST getter_mExpression (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                           @llvmPrefixOperatorUsage class                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_llvmPrefixOperatorUsage : public GALGAS_prefixOperatorUsage {
//--- Constructor
  public : GALGAS_llvmPrefixOperatorUsage (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_llvmPrefixOperatorUsage constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_llvmPrefixOperatorUsage * ptr (void) const { return (const cPtr_llvmPrefixOperatorUsage *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_llvmPrefixOperatorUsage (const cPtr_llvmPrefixOperatorUsage * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_llvmPrefixOperatorUsage extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_llvmPrefixOperatorUsage constructor_new (const class GALGAS_string & inOperand0,
                                                                        const class GALGAS_lstring & inOperand1,
                                                                        const class GALGAS_llvmGenerationInstructionList & inOperand2
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_llvmPrefixOperatorUsage & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_llvmGenerationInstructionList getter_mInstructionList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mPrefixMangledFunctionName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mReceiverOperandName (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_llvmPrefixOperatorUsage class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_llvmPrefixOperatorUsage ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Pointer class for @llvmPrefixOperatorUsage class                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_llvmPrefixOperatorUsage : public cPtr_prefixOperatorUsage {
//--- Attributes
  public : GALGAS_string mProperty_mPrefixMangledFunctionName ;
  public : GALGAS_lstring mProperty_mReceiverOperandName ;
  public : GALGAS_llvmGenerationInstructionList mProperty_mInstructionList ;

//--- Constructor
  public : cPtr_llvmPrefixOperatorUsage (const GALGAS_string & in_mPrefixMangledFunctionName,
                                         const GALGAS_lstring & in_mReceiverOperandName,
                                         const GALGAS_llvmGenerationInstructionList & in_mInstructionList
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_mPrefixMangledFunctionName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_mReceiverOperandName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_llvmGenerationInstructionList getter_mInstructionList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                           @prefixOperatorRoutineIR class                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_prefixOperatorRoutineIR : public GALGAS_abstractRoutineIR {
//--- Constructor
  public : GALGAS_prefixOperatorRoutineIR (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_prefixOperatorRoutineIR constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_prefixOperatorRoutineIR * ptr (void) const { return (const cPtr_prefixOperatorRoutineIR *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_prefixOperatorRoutineIR (const cPtr_prefixOperatorRoutineIR * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_prefixOperatorRoutineIR extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_prefixOperatorRoutineIR constructor_new (const class GALGAS_lstring & inOperand0,
                                                                        const class GALGAS_bool & inOperand1,
                                                                        const class GALGAS_bool & inOperand2,
                                                                        const class GALGAS_omnibusType & inOperand3,
                                                                        const class GALGAS_string & inOperand4,
                                                                        const class GALGAS_omnibusType & inOperand5,
                                                                        const class GALGAS_stringlist & inOperand6,
                                                                        const class GALGAS_allocaList & inOperand7
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_prefixOperatorRoutineIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_allocaList getter_mAllocaList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_mGeneratedInstructions (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_omnibusType getter_mReceiverType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mReceiverVarName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_omnibusType getter_mResultType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_prefixOperatorRoutineIR class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_prefixOperatorRoutineIR ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Pointer class for @prefixOperatorRoutineIR class                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_prefixOperatorRoutineIR : public cPtr_abstractRoutineIR {
//--- Attributes
  public : GALGAS_omnibusType mProperty_mReceiverType ;
  public : GALGAS_string mProperty_mReceiverVarName ;
  public : GALGAS_omnibusType mProperty_mResultType ;
  public : GALGAS_stringlist mProperty_mGeneratedInstructions ;
  public : GALGAS_allocaList mProperty_mAllocaList ;

//--- Constructor
  public : cPtr_prefixOperatorRoutineIR (const GALGAS_lstring & in_mRoutineMangledName,
                                         const GALGAS_bool & in_isRequired,
                                         const GALGAS_bool & in_warnsIfUnused,
                                         const GALGAS_omnibusType & in_mReceiverType,
                                         const GALGAS_string & in_mReceiverVarName,
                                         const GALGAS_omnibusType & in_mResultType,
                                         const GALGAS_stringlist & in_mGeneratedInstructions,
                                         const GALGAS_allocaList & in_mAllocaList
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_omnibusType getter_mReceiverType (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_mReceiverVarName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_omnibusType getter_mResultType (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_stringlist getter_mGeneratedInstructions (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_allocaList getter_mAllocaList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               Extension method '@LValueAST analyzeLValueInAssignment'                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void extensionMethod_analyzeLValueInAssignment (const class GALGAS_LValueAST inObject,
                                                const class GALGAS_omnibusType constin_inSelfType,
                                                const class GALGAS_routineAttributes constin_inRoutineAttributes,
                                                const class GALGAS_semanticContext constin_inContext,
                                                const class GALGAS_mode constin_inMode,
                                                class GALGAS_semanticTemporariesStruct & io_ioTemporaries,
                                                class GALGAS_staticEntityMap & io_ioStaticEntityMap,
                                                class GALGAS_universalValuedObjectMap & io_ioUniversalMap,
                                                class GALGAS_allocaList & io_ioAllocaList,
                                                class GALGAS_instructionListIR & io_ioInstructionGenerationList,
                                                class GALGAS_instructionListListIR & io_ioPendingStoreComputedPropertyInstructionGenerationListList,
                                                class GALGAS_LValueRepresentation & out_outInternalRepresentation,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                       Routine 'analyzeSelfLValueInAssignment'                                       *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_analyzeSelfLValueInAssignment (const class GALGAS_omnibusType constinArgument0,
                                            const class GALGAS_routineAttributes constinArgument1,
                                            const class GALGAS_semanticContext constinArgument2,
                                            const class GALGAS_mode constinArgument3,
                                            class GALGAS_semanticTemporariesStruct & ioArgument4,
                                            class GALGAS_staticEntityMap & ioArgument5,
                                            class GALGAS_universalValuedObjectMap & ioArgument6,
                                            class GALGAS_allocaList & ioArgument7,
                                            class GALGAS_instructionListIR & ioArgument8,
                                            class GALGAS_instructionListListIR & ioArgument9,
                                            const class GALGAS_LValueOperandAST constinArgument10,
                                            class GALGAS_LValueRepresentation & outArgument11,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Routine 'analyzeVariableInLValueInAssignment'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_analyzeVariableInLValueInAssignment (const class GALGAS_omnibusType constinArgument0,
                                                  const class GALGAS_routineAttributes constinArgument1,
                                                  const class GALGAS_semanticContext constinArgument2,
                                                  const class GALGAS_mode constinArgument3,
                                                  class GALGAS_semanticTemporariesStruct & ioArgument4,
                                                  class GALGAS_staticEntityMap & ioArgument5,
                                                  class GALGAS_universalValuedObjectMap & ioArgument6,
                                                  class GALGAS_allocaList & ioArgument7,
                                                  class GALGAS_instructionListIR & ioArgument8,
                                                  class GALGAS_instructionListListIR & ioArgument9,
                                                  const class GALGAS_lstring constinArgument10,
                                                  const class GALGAS_string constinArgument11,
                                                  const class GALGAS_omnibusType constinArgument12,
                                                  const class GALGAS_LValueOperandAST constinArgument13,
                                                  class GALGAS_LValueRepresentation & outArgument14,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                           @forInstructionOnArrayIR class                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_forInstructionOnArrayIR : public GALGAS_abstractInstructionIR {
//--- Constructor
  public : GALGAS_forInstructionOnArrayIR (void) ;

//---
  public : inline const class cPtr_forInstructionOnArrayIR * ptr (void) const { return (const cPtr_forInstructionOnArrayIR *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_forInstructionOnArrayIR (const cPtr_forInstructionOnArrayIR * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_forInstructionOnArrayIR extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_forInstructionOnArrayIR constructor_new (const class GALGAS_string & inOperand0,
                                                                        const class GALGAS_lstring & inOperand1,
                                                                        const class GALGAS_objectIR & inOperand2,
                                                                        const class GALGAS_instructionListIR & inOperand3,
                                                                        const class GALGAS_objectIR & inOperand4,
                                                                        const class GALGAS_instructionListIR & inOperand5,
                                                                        const class GALGAS_omnibusType & inOperand6,
                                                                        const class GALGAS_uint & inOperand7,
                                                                        const class GALGAS_stringset & inOperand8
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_forInstructionOnArrayIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mArraySize (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_instructionListIR getter_mDoInstructionList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_omnibusType getter_mElementType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mEnumeratedValueName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringset getter_mInvokedFunctionSet (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectIR getter_mIteratedObject (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mIteratedObjectName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectIR getter_mWhileExpressionResult (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_instructionListIR getter_mWhileInstructionList (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_forInstructionOnArrayIR class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_forInstructionOnArrayIR ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Pointer class for @forInstructionOnArrayIR class                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_forInstructionOnArrayIR : public cPtr_abstractInstructionIR {
//--- Attributes
  public : GALGAS_string mProperty_mEnumeratedValueName ;
  public : GALGAS_lstring mProperty_mIteratedObjectName ;
  public : GALGAS_objectIR mProperty_mIteratedObject ;
  public : GALGAS_instructionListIR mProperty_mWhileInstructionList ;
  public : GALGAS_objectIR mProperty_mWhileExpressionResult ;
  public : GALGAS_instructionListIR mProperty_mDoInstructionList ;
  public : GALGAS_omnibusType mProperty_mElementType ;
  public : GALGAS_uint mProperty_mArraySize ;
  public : GALGAS_stringset mProperty_mInvokedFunctionSet ;

//--- Constructor
  public : cPtr_forInstructionOnArrayIR (const GALGAS_string & in_mEnumeratedValueName,
                                         const GALGAS_lstring & in_mIteratedObjectName,
                                         const GALGAS_objectIR & in_mIteratedObject,
                                         const GALGAS_instructionListIR & in_mWhileInstructionList,
                                         const GALGAS_objectIR & in_mWhileExpressionResult,
                                         const GALGAS_instructionListIR & in_mDoInstructionList,
                                         const GALGAS_omnibusType & in_mElementType,
                                         const GALGAS_uint & in_mArraySize,
                                         const GALGAS_stringset & in_mInvokedFunctionSet
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_mEnumeratedValueName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_mIteratedObjectName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_objectIR getter_mIteratedObject (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_instructionListIR getter_mWhileInstructionList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_objectIR getter_mWhileExpressionResult (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_instructionListIR getter_mDoInstructionList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_omnibusType getter_mElementType (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_uint getter_mArraySize (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_stringset getter_mInvokedFunctionSet (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                       @forInstructionOnLiteralStringIR class                                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_forInstructionOnLiteralStringIR : public GALGAS_abstractInstructionIR {
//--- Constructor
  public : GALGAS_forInstructionOnLiteralStringIR (void) ;

//---
  public : inline const class cPtr_forInstructionOnLiteralStringIR * ptr (void) const { return (const cPtr_forInstructionOnLiteralStringIR *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_forInstructionOnLiteralStringIR (const cPtr_forInstructionOnLiteralStringIR * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_forInstructionOnLiteralStringIR extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_forInstructionOnLiteralStringIR constructor_new (const class GALGAS_string & inOperand0,
                                                                                const class GALGAS_location & inOperand1,
                                                                                const class GALGAS_objectIR & inOperand2,
                                                                                const class GALGAS_omnibusType & inOperand3,
                                                                                const class GALGAS_instructionListIR & inOperand4,
                                                                                const class GALGAS_objectIR & inOperand5,
                                                                                const class GALGAS_instructionListIR & inOperand6
                                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_forInstructionOnLiteralStringIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_instructionListIR getter_mDoInstructionList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_omnibusType getter_mLiteralStringType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_mLocation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectIR getter_mStringElementIteratedObject (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mVarName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectIR getter_mWhileExpressionResult (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_instructionListIR getter_mWhileInstructionList (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_forInstructionOnLiteralStringIR class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_forInstructionOnLiteralStringIR ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                              Pointer class for @forInstructionOnLiteralStringIR class                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_forInstructionOnLiteralStringIR : public cPtr_abstractInstructionIR {
//--- Attributes
  public : GALGAS_string mProperty_mVarName ;
  public : GALGAS_location mProperty_mLocation ;
  public : GALGAS_objectIR mProperty_mStringElementIteratedObject ;
  public : GALGAS_omnibusType mProperty_mLiteralStringType ;
  public : GALGAS_instructionListIR mProperty_mWhileInstructionList ;
  public : GALGAS_objectIR mProperty_mWhileExpressionResult ;
  public : GALGAS_instructionListIR mProperty_mDoInstructionList ;

//--- Constructor
  public : cPtr_forInstructionOnLiteralStringIR (const GALGAS_string & in_mVarName,
                                                 const GALGAS_location & in_mLocation,
                                                 const GALGAS_objectIR & in_mStringElementIteratedObject,
                                                 const GALGAS_omnibusType & in_mLiteralStringType,
                                                 const GALGAS_instructionListIR & in_mWhileInstructionList,
                                                 const GALGAS_objectIR & in_mWhileExpressionResult,
                                                 const GALGAS_instructionListIR & in_mDoInstructionList
                                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_mVarName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_location getter_mLocation (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_objectIR getter_mStringElementIteratedObject (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_omnibusType getter_mLiteralStringType (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_instructionListIR getter_mWhileInstructionList (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_objectIR getter_mWhileExpressionResult (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_instructionListIR getter_mDoInstructionList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                       @forLowerUpperBoundInstructionIR class                                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_forLowerUpperBoundInstructionIR : public GALGAS_abstractInstructionIR {
//--- Constructor
  public : GALGAS_forLowerUpperBoundInstructionIR (void) ;

//---
  public : inline const class cPtr_forLowerUpperBoundInstructionIR * ptr (void) const { return (const cPtr_forLowerUpperBoundInstructionIR *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_forLowerUpperBoundInstructionIR (const cPtr_forLowerUpperBoundInstructionIR * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_forLowerUpperBoundInstructionIR extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_forLowerUpperBoundInstructionIR constructor_new (const class GALGAS_string & inOperand0,
                                                                                const class GALGAS_omnibusType & inOperand1,
                                                                                const class GALGAS_bool & inOperand2,
                                                                                const class GALGAS_location & inOperand3,
                                                                                const class GALGAS_objectIR & inOperand4,
                                                                                const class GALGAS_objectIR & inOperand5,
                                                                                const class GALGAS_instructionListIR & inOperand6
                                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_forLowerUpperBoundInstructionIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_instructionListIR getter_mInstructionList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_mLocation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectIR getter_mLowerExpressionResult (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_omnibusType getter_mType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mUnsigned (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectIR getter_mUpperExpressionResult (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mVarName (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_forLowerUpperBoundInstructionIR class


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_forLowerUpperBoundInstructionIR ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                              Pointer class for @forLowerUpperBoundInstructionIR class                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cPtr_forLowerUpperBoundInstructionIR : public cPtr_abstractInstructionIR {
//--- Attributes
  public : GALGAS_string mProperty_mVarName ;
  public : GALGAS_omnibusType mProperty_mType ;
  public : GALGAS_bool mProperty_mUnsigned ;
  public : GALGAS_location mProperty_mLocation ;
  public : GALGAS_objectIR mProperty_mLowerExpressionResult ;
  public : GALGAS_objectIR mProperty_mUpperExpressionResult ;
  public : GALGAS_instructionListIR mProperty_mInstructionList ;

//--- Constructor
  public : cPtr_forLowerUpperBoundInstructionIR (const GALGAS_string & in_mVarName,
                                                 const GALGAS_omnibusType & in_mType,
                                                 const GALGAS_bool & in_mUnsigned,
                                                 const GALGAS_location & in_mLocation,
                                                 const GALGAS_objectIR & in_mLowerExpressionResult,
                                                 const GALGAS_objectIR & in_mUpperExpressionResult,
                                                 const GALGAS_instructionListIR & in_mInstructionList
                                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_string getter_mVarName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_omnibusType getter_mType (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_mUnsigned (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_location getter_mLocation (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_objectIR getter_mLowerExpressionResult (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_objectIR getter_mUpperExpressionResult (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_instructionListIR getter_mInstructionList (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//           Extension getter '@effectiveArgumentPassingModeAST passingModeForActualSelector' (as function)            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_string extensionGetter_passingModeForActualSelector (const class GALGAS_effectiveArgumentPassingModeAST & inObject,
                                                                  const class GALGAS_lstring & constinArgument0,
                                                                  class C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                         Extension method '@LValueAST noteInstructionTypesInPrecedenceGraph'                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void extensionMethod_noteInstructionTypesInPrecedenceGraph (const class GALGAS_LValueAST inObject,
                                                            class GALGAS_semanticTypePrecedenceGraph & io_ioGraph,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Extension method '@LValueAST analyzeLValue'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void extensionMethod_analyzeLValue (const class GALGAS_LValueAST inObject,
                                    const class GALGAS_omnibusType constin_inSelfType,
                                    const class GALGAS_bool constin_inIsAddressOf,
                                    const class GALGAS_routineAttributes constin_inRoutineAttributes,
                                    const class GALGAS_semanticContext constin_inContext,
                                    const class GALGAS_mode constin_inMode,
                                    class GALGAS_semanticTemporariesStruct & io_ioTemporaries,
                                    class GALGAS_staticEntityMap & io_ioStaticEntityMap,
                                    class GALGAS_universalValuedObjectMap & io_ioUniversalMap,
                                    class GALGAS_allocaList & io_ioAllocaList,
                                    class GALGAS_instructionListIR & io_ioInstructionGenerationList,
                                    class GALGAS_LValueRepresentation & out_outInternalRepresentation,
                                    class C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                            Function 'mutatingAttribute'                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class GALGAS_string function_mutatingAttribute (class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Routine 'analyzeSelfLValue'                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_analyzeSelfLValue (const class GALGAS_omnibusType constinArgument0,
                                const class GALGAS_routineAttributes constinArgument1,
                                const class GALGAS_semanticContext constinArgument2,
                                const class GALGAS_mode constinArgument3,
                                class GALGAS_semanticTemporariesStruct & ioArgument4,
                                class GALGAS_staticEntityMap & ioArgument5,
                                class GALGAS_universalValuedObjectMap & ioArgument6,
                                class GALGAS_allocaList & ioArgument7,
                                class GALGAS_instructionListIR & ioArgument8,
                                const class GALGAS_LValueOperandAST constinArgument9,
                                class GALGAS_LValueRepresentation & outArgument10,
                                class C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          Routine 'analyzeVariableInLValue'                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_analyzeVariableInLValue (const class GALGAS_omnibusType constinArgument0,
                                      const class GALGAS_bool constinArgument1,
                                      const class GALGAS_routineAttributes constinArgument2,
                                      const class GALGAS_semanticContext constinArgument3,
                                      const class GALGAS_mode constinArgument4,
                                      class GALGAS_semanticTemporariesStruct & ioArgument5,
                                      class GALGAS_staticEntityMap & ioArgument6,
                                      class GALGAS_universalValuedObjectMap & ioArgument7,
                                      class GALGAS_allocaList & ioArgument8,
                                      class GALGAS_instructionListIR & ioArgument9,
                                      const class GALGAS_lstring constinArgument10,
                                      const class GALGAS_string constinArgument11,
                                      const class GALGAS_omnibusType constinArgument12,
                                      const class GALGAS_LValueOperandAST constinArgument13,
                                      class GALGAS_LValueRepresentation & outArgument14,
                                      class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

