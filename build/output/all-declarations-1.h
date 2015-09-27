#ifndef all_2D_declarations_2D__31__ENTITIES_DEFINED
#define all_2D_declarations_2D__31__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-0.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @labelMap_2D_element struct                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_labelMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_labelMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_labelMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_labelMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_labelMap_2D_element (const GALGAS_lstring & in_lkey) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_labelMap_2D_element extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_labelMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_labelMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_labelMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_labelMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @procedureMap map                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_procedureMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_procedureMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procedureMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_procedureMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_procedureMap (const GALGAS_procedureMap & inSource) ;
  public : GALGAS_procedureMap & operator = (const GALGAS_procedureMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procedureMap extractObject (const GALGAS_object & inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procedureMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_procedureMap constructor_mapWithMapToOverride (const class GALGAS_procedureMap & inOperand0
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_bool & inOperand1,
                                                      const class GALGAS_modeMap & inOperand2,
                                                      const class GALGAS_procedureSignature & inOperand3,
                                                      const class GALGAS_bool & inOperand4,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_bool constinArgument1,
                                                     class GALGAS_modeMap constinArgument2,
                                                     class GALGAS_procedureSignature constinArgument3,
                                                     class GALGAS_bool constinArgument4,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_bool & outArgument1,
                                                     class GALGAS_modeMap & outArgument2,
                                                     class GALGAS_procedureSignature & outArgument3,
                                                     class GALGAS_bool & outArgument4,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMMutatingForKey (class GALGAS_bool constinArgument0,
                                                              class GALGAS_string constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMProcedureModeMapForKey (class GALGAS_modeMap constinArgument0,
                                                                      class GALGAS_string constinArgument1,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMSignatureForKey (class GALGAS_procedureSignature constinArgument0,
                                                               class GALGAS_string constinArgument1,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMWeakProcedureForKey (class GALGAS_bool constinArgument0,
                                                                   class GALGAS_string constinArgument1,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_bool & outArgument1,
                                                   class GALGAS_modeMap & outArgument2,
                                                   class GALGAS_procedureSignature & outArgument3,
                                                   class GALGAS_bool & outArgument4,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mMutatingForKey (const class GALGAS_string & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_modeMap reader_mProcedureModeMapForKey (const class GALGAS_string & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procedureSignature reader_mSignatureForKey (const class GALGAS_string & constinOperand0,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mWeakProcedureForKey (const class GALGAS_string & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procedureMap reader_overriddenMap (C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_procedureMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                          const GALGAS_string & inKey
                                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_procedureMap ;
 
} ; // End of GALGAS_procedureMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_procedureMap : public cGenericAbstractEnumerator {
  public : cEnumerator_procedureMap (const GALGAS_procedureMap & inEnumeratedObject,
                                     const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_mMutating (LOCATION_ARGS) const ;
  public : class GALGAS_modeMap current_mProcedureModeMap (LOCATION_ARGS) const ;
  public : class GALGAS_procedureSignature current_mSignature (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_mWeakProcedure (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_procedureMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procedureMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @procedureSignature list                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procedureSignature : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_procedureSignature (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_procedureSignature (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_procFormalArgumentPassingMode & in_mFormalArgumentPassingMode,
                                                  const class GALGAS_lstring & in_mSelector,
                                                  const class GALGAS_unifiedTypeMap_2D_proxy & in_mType
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procedureSignature extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procedureSignature constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_procedureSignature constructor_listWithValue (const class GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                       const class GALGAS_lstring & inOperand1,
                                                                       const class GALGAS_unifiedTypeMap_2D_proxy & inOperand2
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_procedureSignature inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                      const class GALGAS_lstring & inOperand1,
                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand2
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_procedureSignature operator_concat (const GALGAS_procedureSignature & inOperand
                                                                       COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_procedureSignature add_operation (const GALGAS_procedureSignature & inOperand,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_procFormalArgumentPassingMode constinArgument0,
                                                         class GALGAS_lstring constinArgument1,
                                                         class GALGAS_unifiedTypeMap_2D_proxy constinArgument2,
                                                         class GALGAS_uint constinArgument3,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_procFormalArgumentPassingMode & outArgument0,
                                                    class GALGAS_lstring & outArgument1,
                                                    class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_procFormalArgumentPassingMode & outArgument0,
                                                   class GALGAS_lstring & outArgument1,
                                                   class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_procFormalArgumentPassingMode & outArgument0,
                                                         class GALGAS_lstring & outArgument1,
                                                         class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                                         class GALGAS_uint constinArgument3,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_procFormalArgumentPassingMode & outArgument0,
                                               class GALGAS_lstring & outArgument1,
                                               class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_procFormalArgumentPassingMode & outArgument0,
                                              class GALGAS_lstring & outArgument1,
                                              class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_procFormalArgumentPassingMode reader_mFormalArgumentPassingModeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                                                 C_Compiler * inCompiler
                                                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_mSelectorAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mTypeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procedureSignature reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procedureSignature reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_procedureSignature ;
 
} ; // End of GALGAS_procedureSignature class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_procedureSignature : public cGenericAbstractEnumerator {
  public : cEnumerator_procedureSignature (const GALGAS_procedureSignature & inEnumeratedObject,
                                           const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_procFormalArgumentPassingMode current_mFormalArgumentPassingMode (LOCATION_ARGS) const ;
  public : class GALGAS_lstring current_mSelector (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mType (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_procedureSignature_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procedureSignature ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Class for element of '@procedureMap' map                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_procedureMap : public cMapElement {
//--- Map attributes
  public : GALGAS_bool mAttribute_mMutating ;
  public : GALGAS_modeMap mAttribute_mProcedureModeMap ;
  public : GALGAS_procedureSignature mAttribute_mSignature ;
  public : GALGAS_bool mAttribute_mWeakProcedure ;

//--- Constructor
  public : cMapElement_procedureMap (const GALGAS_lstring & inKey,
                                     const GALGAS_bool & in_mMutating,
                                     const GALGAS_modeMap & in_mProcedureModeMap,
                                     const GALGAS_procedureSignature & in_mSignature,
                                     const GALGAS_bool & in_mWeakProcedure
                                     COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @procedureMap_2D_element struct                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procedureMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_bool mAttribute_mMutating ;
  public : GALGAS_modeMap mAttribute_mProcedureModeMap ;
  public : GALGAS_procedureSignature mAttribute_mSignature ;
  public : GALGAS_bool mAttribute_mWeakProcedure ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_procedureMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_procedureMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_procedureMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_procedureMap_2D_element (const GALGAS_lstring & in_lkey,
                                           const GALGAS_bool & in_mMutating,
                                           const GALGAS_modeMap & in_mProcedureModeMap,
                                           const GALGAS_procedureSignature & in_mSignature,
                                           const GALGAS_bool & in_mWeakProcedure) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procedureMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procedureMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                  const class GALGAS_bool & inOperand1,
                                                                  const class GALGAS_modeMap & inOperand2,
                                                                  const class GALGAS_procedureSignature & inOperand3,
                                                                  const class GALGAS_bool & inOperand4
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_procedureMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mMutating (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_modeMap reader_mProcedureModeMap (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procedureSignature reader_mSignature (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mWeakProcedure (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_procedureMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procedureMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @procedureSignature_2D_element struct                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procedureSignature_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_procFormalArgumentPassingMode mAttribute_mFormalArgumentPassingMode ;
  public : GALGAS_lstring mAttribute_mSelector ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mType ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_procedureSignature_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_procedureSignature_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_procedureSignature_2D_element (const GALGAS_procFormalArgumentPassingMode & in_mFormalArgumentPassingMode,
                                                 const GALGAS_lstring & in_mSelector,
                                                 const GALGAS_unifiedTypeMap_2D_proxy & in_mType) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procedureSignature_2D_element extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procedureSignature_2D_element constructor_new (const class GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                        const class GALGAS_lstring & inOperand1,
                                                                        const class GALGAS_unifiedTypeMap_2D_proxy & inOperand2
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_procedureSignature_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_procFormalArgumentPassingMode reader_mFormalArgumentPassingMode (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_mSelector (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_procedureSignature_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procedureSignature_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @procFormalArgumentListForGeneration list                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procFormalArgumentListForGeneration : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_procFormalArgumentListForGeneration (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_procFormalArgumentListForGeneration (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_procFormalArgumentPassingMode & in_mFormalArgumentKind,
                                                  const class GALGAS_unifiedTypeMap_2D_proxy & in_mFormalArgumentType,
                                                  const class GALGAS_string & in_mFormalArgumentName
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procFormalArgumentListForGeneration extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procFormalArgumentListForGeneration constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_procFormalArgumentListForGeneration constructor_listWithValue (const class GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                                        const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                                        const class GALGAS_string & inOperand2
                                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_procFormalArgumentListForGeneration inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                      const class GALGAS_string & inOperand2
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_procFormalArgumentListForGeneration operator_concat (const GALGAS_procFormalArgumentListForGeneration & inOperand
                                                                                        COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_procFormalArgumentListForGeneration add_operation (const GALGAS_procFormalArgumentListForGeneration & inOperand,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_procFormalArgumentPassingMode constinArgument0,
                                                         class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                         class GALGAS_string constinArgument2,
                                                         class GALGAS_uint constinArgument3,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_procFormalArgumentPassingMode & outArgument0,
                                                    class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                    class GALGAS_string & outArgument2,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_procFormalArgumentPassingMode & outArgument0,
                                                   class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                   class GALGAS_string & outArgument2,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_procFormalArgumentPassingMode & outArgument0,
                                                         class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                         class GALGAS_string & outArgument2,
                                                         class GALGAS_uint constinArgument3,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_procFormalArgumentPassingMode & outArgument0,
                                               class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                               class GALGAS_string & outArgument2,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_procFormalArgumentPassingMode & outArgument0,
                                              class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                              class GALGAS_string & outArgument2,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_procFormalArgumentPassingMode reader_mFormalArgumentKindAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_mFormalArgumentNameAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mFormalArgumentTypeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procFormalArgumentListForGeneration reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                                      C_Compiler * inCompiler
                                                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procFormalArgumentListForGeneration reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                                      C_Compiler * inCompiler
                                                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_procFormalArgumentListForGeneration ;
 
} ; // End of GALGAS_procFormalArgumentListForGeneration class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_procFormalArgumentListForGeneration : public cGenericAbstractEnumerator {
  public : cEnumerator_procFormalArgumentListForGeneration (const GALGAS_procFormalArgumentListForGeneration & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_procFormalArgumentPassingMode current_mFormalArgumentKind (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mFormalArgumentType (LOCATION_ARGS) const ;
  public : class GALGAS_string current_mFormalArgumentName (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_procFormalArgumentListForGeneration_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procFormalArgumentListForGeneration ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               @procFormalArgumentListForGeneration_2D_element struct                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procFormalArgumentListForGeneration_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_procFormalArgumentPassingMode mAttribute_mFormalArgumentKind ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mFormalArgumentType ;
  public : GALGAS_string mAttribute_mFormalArgumentName ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_procFormalArgumentListForGeneration_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_procFormalArgumentListForGeneration_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_procFormalArgumentListForGeneration_2D_element (const GALGAS_procFormalArgumentPassingMode & in_mFormalArgumentKind,
                                                                  const GALGAS_unifiedTypeMap_2D_proxy & in_mFormalArgumentType,
                                                                  const GALGAS_string & in_mFormalArgumentName) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procFormalArgumentListForGeneration_2D_element extractObject (const GALGAS_object & inObject,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procFormalArgumentListForGeneration_2D_element constructor_new (const class GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                                         const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                                         const class GALGAS_string & inOperand2
                                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_procFormalArgumentListForGeneration_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_procFormalArgumentPassingMode reader_mFormalArgumentKind (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_mFormalArgumentName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mFormalArgumentType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_procFormalArgumentListForGeneration_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procFormalArgumentListForGeneration_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @subprogramInvocationGraph graph                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_subprogramInvocationGraph : public AC_GALGAS_graph {
//--------------------------------- Default constructor
  public : GALGAS_subprogramInvocationGraph (void) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_subprogramInvocationGraph extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_subprogramInvocationGraph constructor_emptyGraph (LOCATION_ARGS) ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_addNode (class GALGAS_lstring inArgument0,
                                                   class GALGAS_lstring inArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_circularities (class GALGAS_lstringlist & outArgument0,
                                                       class GALGAS_lstringlist & outArgument1
                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_depthFirstTopologicalSort (class GALGAS_lstringlist & outArgument0,
                                                                   class GALGAS_lstringlist & outArgument1,
                                                                   class GALGAS_lstringlist & outArgument2,
                                                                   class GALGAS_lstringlist & outArgument3,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_nodesWithNoPredecessor (class GALGAS_lstringlist & outArgument0,
                                                                class GALGAS_lstringlist & outArgument1
                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_nodesWithNoSuccessor (class GALGAS_lstringlist & outArgument0,
                                                              class GALGAS_lstringlist & outArgument1
                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_topologicalSort (class GALGAS_lstringlist & outArgument0,
                                                         class GALGAS_lstringlist & outArgument1,
                                                         class GALGAS_lstringlist & outArgument2,
                                                         class GALGAS_lstringlist & outArgument3,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstringlist reader_accessibleNodesFromNodes (const class GALGAS_lstringlist & constinOperand0,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_subprogramInvocationGraph reader_reversedGraph (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_subprogramInvocationGraph reader_subgraphFromNodes (const class GALGAS_lstringlist & constinOperand0,
                                                                                             const class GALGAS_stringset & constinOperand1,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_subprogramInvocationGraph class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_subprogramInvocationGraph ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     @registerDeclarationList_2D_element struct                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_registerDeclarationList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_mRegisterName ;
  public : GALGAS_lstringlist mAttribute_mAttributeList ;
  public : GALGAS_lbigint mAttribute_mRegisterAddress ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_registerDeclarationList_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_registerDeclarationList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_registerDeclarationList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_registerDeclarationList_2D_element (const GALGAS_lstring & in_mRegisterName,
                                                      const GALGAS_lstringlist & in_mAttributeList,
                                                      const GALGAS_lbigint & in_mRegisterAddress) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_registerDeclarationList_2D_element extractObject (const GALGAS_object & inObject,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_registerDeclarationList_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                             const class GALGAS_lstringlist & inOperand1,
                                                                             const class GALGAS_lbigint & inOperand2
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_registerDeclarationList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstringlist reader_mAttributeList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lbigint reader_mRegisterAddress (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_mRegisterName (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_registerDeclarationList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_registerDeclarationList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @registerBitSliceList_2D_element struct                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_registerBitSliceList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_registerBitSlice mAttribute_mRegisterBitSlice ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_registerBitSliceList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_registerBitSliceList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_registerBitSliceList_2D_element (const GALGAS_registerBitSlice & in_mRegisterBitSlice) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_registerBitSliceList_2D_element extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_registerBitSliceList_2D_element constructor_new (const class GALGAS_registerBitSlice & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_registerBitSliceList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_registerBitSlice reader_mRegisterBitSlice (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_registerBitSliceList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_registerBitSliceList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @registerFieldMap map                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_registerFieldMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_registerFieldMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_registerFieldMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_registerFieldMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_registerFieldMap (const GALGAS_registerFieldMap & inSource) ;
  public : GALGAS_registerFieldMap & operator = (const GALGAS_registerFieldMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_registerFieldMap extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_registerFieldMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_registerFieldMap constructor_mapWithMapToOverride (const class GALGAS_registerFieldMap & inOperand0
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_uint & inOperand1,
                                                      const class GALGAS_uint & inOperand2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_uint constinArgument1,
                                                     class GALGAS_uint constinArgument2,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMBitCountForKey (class GALGAS_uint constinArgument0,
                                                              class GALGAS_string constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMBitIndexForKey (class GALGAS_uint constinArgument0,
                                                              class GALGAS_string constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_uint & outArgument1,
                                                   class GALGAS_uint & outArgument2,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint reader_mBitCountForKey (const class GALGAS_string & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint reader_mBitIndexForKey (const class GALGAS_string & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_registerFieldMap reader_overriddenMap (C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_registerFieldMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                              const GALGAS_string & inKey
                                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_registerFieldMap ;
 
} ; // End of GALGAS_registerFieldMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_registerFieldMap : public cGenericAbstractEnumerator {
  public : cEnumerator_registerFieldMap (const GALGAS_registerFieldMap & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_uint current_mBitIndex (LOCATION_ARGS) const ;
  public : class GALGAS_uint current_mBitCount (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_registerFieldMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_registerFieldMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@registerFieldMap' map                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_registerFieldMap : public cMapElement {
//--- Map attributes
  public : GALGAS_uint mAttribute_mBitIndex ;
  public : GALGAS_uint mAttribute_mBitCount ;

//--- Constructor
  public : cMapElement_registerFieldMap (const GALGAS_lstring & inKey,
                                         const GALGAS_uint & in_mBitIndex,
                                         const GALGAS_uint & in_mBitCount
                                         COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @registerFieldMap_2D_element struct                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_registerFieldMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_uint mAttribute_mBitIndex ;
  public : GALGAS_uint mAttribute_mBitCount ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_registerFieldMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_registerFieldMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_registerFieldMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_registerFieldMap_2D_element (const GALGAS_lstring & in_lkey,
                                               const GALGAS_uint & in_mBitIndex,
                                               const GALGAS_uint & in_mBitCount) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_registerFieldMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_registerFieldMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                      const class GALGAS_uint & inOperand1,
                                                                      const class GALGAS_uint & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_registerFieldMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint reader_mBitCount (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint reader_mBitIndex (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_registerFieldMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_registerFieldMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @registerBitSliceAccessMap map                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_registerBitSliceAccessMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_registerBitSliceAccessMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_registerBitSliceAccessMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_registerBitSliceAccessMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_registerBitSliceAccessMap (const GALGAS_registerBitSliceAccessMap & inSource) ;
  public : GALGAS_registerBitSliceAccessMap & operator = (const GALGAS_registerBitSliceAccessMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_registerBitSliceAccessMap extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_registerBitSliceAccessMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_registerBitSliceAccessMap constructor_mapWithMapToOverride (const class GALGAS_registerBitSliceAccessMap & inOperand0
                                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_llvmBinaryOperation & inOperand1,
                                                      const class GALGAS_bigint & inOperand2,
                                                      const class GALGAS_registerBitSliceAccessMap & inOperand3,
                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand4,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_llvmBinaryOperation constinArgument1,
                                                     class GALGAS_bigint constinArgument2,
                                                     class GALGAS_registerBitSliceAccessMap constinArgument3,
                                                     class GALGAS_unifiedTypeMap_2D_proxy constinArgument4,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMAccessOperatorForKey (class GALGAS_llvmBinaryOperation constinArgument0,
                                                                    class GALGAS_string constinArgument1,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMAccessRightOperandForKey (class GALGAS_bigint constinArgument0,
                                                                        class GALGAS_string constinArgument1,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMResultTypeForKey (class GALGAS_unifiedTypeMap_2D_proxy constinArgument0,
                                                                class GALGAS_string constinArgument1,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMSubMapForKey (class GALGAS_registerBitSliceAccessMap constinArgument0,
                                                            class GALGAS_string constinArgument1,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_llvmBinaryOperation & outArgument1,
                                                   class GALGAS_bigint & outArgument2,
                                                   class GALGAS_registerBitSliceAccessMap & outArgument3,
                                                   class GALGAS_unifiedTypeMap_2D_proxy & outArgument4,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_llvmBinaryOperation reader_mAccessOperatorForKey (const class GALGAS_string & constinOperand0,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bigint reader_mAccessRightOperandForKey (const class GALGAS_string & constinOperand0,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mResultTypeForKey (const class GALGAS_string & constinOperand0,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_registerBitSliceAccessMap reader_mSubMapForKey (const class GALGAS_string & constinOperand0,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_registerBitSliceAccessMap reader_overriddenMap (C_Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_registerBitSliceAccessMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                       const GALGAS_string & inKey
                                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_registerBitSliceAccessMap ;
 
} ; // End of GALGAS_registerBitSliceAccessMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_registerBitSliceAccessMap : public cGenericAbstractEnumerator {
  public : cEnumerator_registerBitSliceAccessMap (const GALGAS_registerBitSliceAccessMap & inEnumeratedObject,
                                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_llvmBinaryOperation current_mAccessOperator (LOCATION_ARGS) const ;
  public : class GALGAS_bigint current_mAccessRightOperand (LOCATION_ARGS) const ;
  public : class GALGAS_registerBitSliceAccessMap current_mSubMap (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mResultType (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_registerBitSliceAccessMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_registerBitSliceAccessMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @llvmBinaryOperation enum                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_llvmBinaryOperation : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public : GALGAS_llvmBinaryOperation (void) ;

//--------------------------------- Enumeration
  public : typedef enum {
    kNotBuilt,
    kEnum_addNoOVF,
    kEnum_subNoOVF,
    kEnum_mulNoOVF,
    kEnum_udivNoOVF,
    kEnum_sdivNoOVF,
    kEnum_uremNoOVF,
    kEnum_sremNoOVF,
    kEnum_uaddOVF,
    kEnum_saddOVF,
    kEnum_usubOVF,
    kEnum_ssubOVF,
    kEnum_umulOVF,
    kEnum_smulOVF,
    kEnum_udivOVF,
    kEnum_sdivOVF,
    kEnum_uremOVF,
    kEnum_sremOVF,
    kEnum_and,
    kEnum_ior,
    kEnum_xor,
    kEnum_shl,
    kEnum_ashr,
    kEnum_lshr,
    kEnum_icmp_5F_eq,
    kEnum_icmp_5F_ne,
    kEnum_icmp_5F_ult,
    kEnum_icmp_5F_ule,
    kEnum_icmp_5F_ugt,
    kEnum_icmp_5F_uge,
    kEnum_icmp_5F_slt,
    kEnum_icmp_5F_sle,
    kEnum_icmp_5F_sgt,
    kEnum_icmp_5F_sge
  } enumeration ;
  
//--------------------------------- Private data member
  private : enumeration mEnum ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return kNotBuilt != mEnum ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mEnum = kNotBuilt ; }
  public : inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_llvmBinaryOperation extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_llvmBinaryOperation constructor_addNoOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_and (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_ashr (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_icmp_5F_eq (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_icmp_5F_ne (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_icmp_5F_sge (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_icmp_5F_sgt (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_icmp_5F_sle (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_icmp_5F_slt (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_icmp_5F_uge (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_icmp_5F_ugt (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_icmp_5F_ule (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_icmp_5F_ult (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_ior (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_lshr (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_mulNoOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_saddOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_sdivNoOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_sdivOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_shl (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_smulOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_sremNoOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_sremOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_ssubOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_subNoOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_uaddOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_udivNoOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_udivOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_umulOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_uremNoOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_uremOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_usubOVF (LOCATION_ARGS) ;

  public : static GALGAS_llvmBinaryOperation constructor_xor (LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_llvmBinaryOperation & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isAddNoOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isAnd (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isAshr (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIcmp_5F_eq (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIcmp_5F_ne (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIcmp_5F_sge (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIcmp_5F_sgt (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIcmp_5F_sle (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIcmp_5F_slt (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIcmp_5F_uge (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIcmp_5F_ugt (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIcmp_5F_ule (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIcmp_5F_ult (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIor (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isLshr (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isMulNoOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isSaddOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isSdivNoOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isSdivOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isShl (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isSmulOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isSremNoOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isSremOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isSsubOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isSubNoOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isUaddOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isUdivNoOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isUdivOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isUmulOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isUremNoOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isUremOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isUsubOVF (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isXor (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_llvmBinaryOperation class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_llvmBinaryOperation ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Class for element of '@registerBitSliceAccessMap' map                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_registerBitSliceAccessMap : public cMapElement {
//--- Map attributes
  public : GALGAS_llvmBinaryOperation mAttribute_mAccessOperator ;
  public : GALGAS_bigint mAttribute_mAccessRightOperand ;
  public : GALGAS_registerBitSliceAccessMap mAttribute_mSubMap ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mResultType ;

//--- Constructor
  public : cMapElement_registerBitSliceAccessMap (const GALGAS_lstring & inKey,
                                                  const GALGAS_llvmBinaryOperation & in_mAccessOperator,
                                                  const GALGAS_bigint & in_mAccessRightOperand,
                                                  const GALGAS_registerBitSliceAccessMap & in_mSubMap,
                                                  const GALGAS_unifiedTypeMap_2D_proxy & in_mResultType
                                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    @registerBitSliceAccessMap_2D_element struct                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_registerBitSliceAccessMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_llvmBinaryOperation mAttribute_mAccessOperator ;
  public : GALGAS_bigint mAttribute_mAccessRightOperand ;
  public : GALGAS_registerBitSliceAccessMap mAttribute_mSubMap ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mResultType ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_registerBitSliceAccessMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_registerBitSliceAccessMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_registerBitSliceAccessMap_2D_element (const GALGAS_lstring & in_lkey,
                                                        const GALGAS_llvmBinaryOperation & in_mAccessOperator,
                                                        const GALGAS_bigint & in_mAccessRightOperand,
                                                        const GALGAS_registerBitSliceAccessMap & in_mSubMap,
                                                        const GALGAS_unifiedTypeMap_2D_proxy & in_mResultType) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_registerBitSliceAccessMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_registerBitSliceAccessMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                               const class GALGAS_llvmBinaryOperation & inOperand1,
                                                                               const class GALGAS_bigint & inOperand2,
                                                                               const class GALGAS_registerBitSliceAccessMap & inOperand3,
                                                                               const class GALGAS_unifiedTypeMap_2D_proxy & inOperand4
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_registerBitSliceAccessMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_llvmBinaryOperation reader_mAccessOperator (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bigint reader_mAccessRightOperand (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mResultType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_registerBitSliceAccessMap reader_mSubMap (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_registerBitSliceAccessMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_registerBitSliceAccessMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @registerMap map                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_registerMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_registerMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_registerMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_registerMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_registerMap (const GALGAS_registerMap & inSource) ;
  public : GALGAS_registerMap & operator = (const GALGAS_registerMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_registerMap extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_registerMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_registerMap constructor_mapWithMapToOverride (const class GALGAS_registerMap & inOperand0
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                      const class GALGAS_bool & inOperand2,
                                                      const class GALGAS_registerBitSliceAccessMap & inOperand3,
                                                      const class GALGAS_registerFieldMap & inOperand4,
                                                      const class GALGAS_bigint & inOperand5,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                     class GALGAS_bool constinArgument2,
                                                     class GALGAS_registerBitSliceAccessMap constinArgument3,
                                                     class GALGAS_registerFieldMap constinArgument4,
                                                     class GALGAS_bigint constinArgument5,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMAddressForKey (class GALGAS_bigint constinArgument0,
                                                             class GALGAS_string constinArgument1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMIsReadOnlyForKey (class GALGAS_bool constinArgument0,
                                                                class GALGAS_string constinArgument1,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMRegisterFieldAccessMapForKey (class GALGAS_registerBitSliceAccessMap constinArgument0,
                                                                            class GALGAS_string constinArgument1,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMRegisterFieldMapForKey (class GALGAS_registerFieldMap constinArgument0,
                                                                      class GALGAS_string constinArgument1,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMTypeForKey (class GALGAS_unifiedTypeMap_2D_proxy constinArgument0,
                                                          class GALGAS_string constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                   class GALGAS_bool & outArgument2,
                                                   class GALGAS_registerBitSliceAccessMap & outArgument3,
                                                   class GALGAS_registerFieldMap & outArgument4,
                                                   class GALGAS_bigint & outArgument5,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bigint reader_mAddressForKey (const class GALGAS_string & constinOperand0,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mIsReadOnlyForKey (const class GALGAS_string & constinOperand0,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_registerBitSliceAccessMap reader_mRegisterFieldAccessMapForKey (const class GALGAS_string & constinOperand0,
                                                                                                         C_Compiler * inCompiler
                                                                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_registerFieldMap reader_mRegisterFieldMapForKey (const class GALGAS_string & constinOperand0,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mTypeForKey (const class GALGAS_string & constinOperand0,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_registerMap reader_overriddenMap (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_registerMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                         const GALGAS_string & inKey
                                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_registerMap ;
 
} ; // End of GALGAS_registerMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_registerMap : public cGenericAbstractEnumerator {
  public : cEnumerator_registerMap (const GALGAS_registerMap & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mType (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_mIsReadOnly (LOCATION_ARGS) const ;
  public : class GALGAS_registerBitSliceAccessMap current_mRegisterFieldAccessMap (LOCATION_ARGS) const ;
  public : class GALGAS_registerFieldMap current_mRegisterFieldMap (LOCATION_ARGS) const ;
  public : class GALGAS_bigint current_mAddress (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_registerMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_registerMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Class for element of '@registerMap' map                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_registerMap : public cMapElement {
//--- Map attributes
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mType ;
  public : GALGAS_bool mAttribute_mIsReadOnly ;
  public : GALGAS_registerBitSliceAccessMap mAttribute_mRegisterFieldAccessMap ;
  public : GALGAS_registerFieldMap mAttribute_mRegisterFieldMap ;
  public : GALGAS_bigint mAttribute_mAddress ;

//--- Constructor
  public : cMapElement_registerMap (const GALGAS_lstring & inKey,
                                    const GALGAS_unifiedTypeMap_2D_proxy & in_mType,
                                    const GALGAS_bool & in_mIsReadOnly,
                                    const GALGAS_registerBitSliceAccessMap & in_mRegisterFieldAccessMap,
                                    const GALGAS_registerFieldMap & in_mRegisterFieldMap,
                                    const GALGAS_bigint & in_mAddress
                                    COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @registerMap_2D_element struct                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_registerMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mType ;
  public : GALGAS_bool mAttribute_mIsReadOnly ;
  public : GALGAS_registerBitSliceAccessMap mAttribute_mRegisterFieldAccessMap ;
  public : GALGAS_registerFieldMap mAttribute_mRegisterFieldMap ;
  public : GALGAS_bigint mAttribute_mAddress ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_registerMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_registerMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_registerMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_registerMap_2D_element (const GALGAS_lstring & in_lkey,
                                          const GALGAS_unifiedTypeMap_2D_proxy & in_mType,
                                          const GALGAS_bool & in_mIsReadOnly,
                                          const GALGAS_registerBitSliceAccessMap & in_mRegisterFieldAccessMap,
                                          const GALGAS_registerFieldMap & in_mRegisterFieldMap,
                                          const GALGAS_bigint & in_mAddress) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_registerMap_2D_element extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_registerMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                 const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                 const class GALGAS_bool & inOperand2,
                                                                 const class GALGAS_registerBitSliceAccessMap & inOperand3,
                                                                 const class GALGAS_registerFieldMap & inOperand4,
                                                                 const class GALGAS_bigint & inOperand5
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_registerMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bigint reader_mAddress (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mIsReadOnly (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_registerBitSliceAccessMap reader_mRegisterFieldAccessMap (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_registerFieldMap reader_mRegisterFieldMap (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_registerMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_registerMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @infixOperatorMap map                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_infixOperatorMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_infixOperatorMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_infixOperatorMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_infixOperatorMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_infixOperatorMap (const GALGAS_infixOperatorMap & inSource) ;
  public : GALGAS_infixOperatorMap & operator = (const GALGAS_infixOperatorMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_infixOperatorMap extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_infixOperatorMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_infixOperatorMap constructor_mapWithMapToOverride (const class GALGAS_infixOperatorMap & inOperand0
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                      const class GALGAS_llvmBinaryOperation & inOperand2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                     class GALGAS_llvmBinaryOperation constinArgument2,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMOperationForKey (class GALGAS_llvmBinaryOperation constinArgument0,
                                                               class GALGAS_string constinArgument1,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMResultTypeForKey (class GALGAS_unifiedTypeMap_2D_proxy constinArgument0,
                                                                class GALGAS_string constinArgument1,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                   class GALGAS_llvmBinaryOperation & outArgument2,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_llvmBinaryOperation reader_mOperationForKey (const class GALGAS_string & constinOperand0,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mResultTypeForKey (const class GALGAS_string & constinOperand0,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_infixOperatorMap reader_overriddenMap (C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_infixOperatorMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                              const GALGAS_string & inKey
                                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_infixOperatorMap ;
 
} ; // End of GALGAS_infixOperatorMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_infixOperatorMap : public cGenericAbstractEnumerator {
  public : cEnumerator_infixOperatorMap (const GALGAS_infixOperatorMap & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mResultType (LOCATION_ARGS) const ;
  public : class GALGAS_llvmBinaryOperation current_mOperation (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_infixOperatorMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_infixOperatorMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@infixOperatorMap' map                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_infixOperatorMap : public cMapElement {
//--- Map attributes
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mResultType ;
  public : GALGAS_llvmBinaryOperation mAttribute_mOperation ;

//--- Constructor
  public : cMapElement_infixOperatorMap (const GALGAS_lstring & inKey,
                                         const GALGAS_unifiedTypeMap_2D_proxy & in_mResultType,
                                         const GALGAS_llvmBinaryOperation & in_mOperation
                                         COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @infixOperatorMap_2D_element struct                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_infixOperatorMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mResultType ;
  public : GALGAS_llvmBinaryOperation mAttribute_mOperation ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_infixOperatorMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_infixOperatorMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_infixOperatorMap_2D_element (const GALGAS_lstring & in_lkey,
                                               const GALGAS_unifiedTypeMap_2D_proxy & in_mResultType,
                                               const GALGAS_llvmBinaryOperation & in_mOperation) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_infixOperatorMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_infixOperatorMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                      const class GALGAS_llvmBinaryOperation & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_infixOperatorMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_llvmBinaryOperation reader_mOperation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mResultType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_infixOperatorMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_infixOperatorMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @infixOperatorIR enum                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_infixOperatorIR : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public : GALGAS_infixOperatorIR (void) ;

//--------------------------------- Enumeration
  public : typedef enum {
    kNotBuilt,
    kEnum_infixNoOvf,
    kEnum_infixOvf,
    kEnum_infixUnsignedDivide,
    kEnum_infixModulo
  } enumeration ;
  
//--------------------------------- Private data member
  private : AC_GALGAS_enumAssociatedValues mAssociatedValues ;
  public : VIRTUAL_IN_DEBUG const cEnumAssociatedValues * unsafePointer (void) const {
    return mAssociatedValues.unsafePointer () ;
  }

  private : enumeration mEnum ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return kNotBuilt != mEnum ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mEnum = kNotBuilt ; }
  public : inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_infixOperatorIR extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_infixOperatorIR constructor_infixModulo (const class GALGAS_uint & inOperand0
                                                                  COMMA_LOCATION_ARGS) ;

  public : static GALGAS_infixOperatorIR constructor_infixNoOvf (const class GALGAS_string & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

  public : static GALGAS_infixOperatorIR constructor_infixOvf (const class GALGAS_string & inOperand0,
                                                               const class GALGAS_uint & inOperand1
                                                               COMMA_LOCATION_ARGS) ;

  public : static GALGAS_infixOperatorIR constructor_infixUnsignedDivide (const class GALGAS_uint & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_infixOperatorIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_infixModulo (class GALGAS_uint & outArgument0,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_infixNoOvf (class GALGAS_string & outArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_infixOvf (class GALGAS_string & outArgument0,
                                                  class GALGAS_uint & outArgument1,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_infixUnsignedDivide (class GALGAS_uint & outArgument0,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isInfixModulo (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isInfixNoOvf (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isInfixOvf (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isInfixUnsignedDivide (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_infixOperatorIR class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_infixOperatorIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @infixOperatorIR enum, associated values                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_infixOperatorIR_infixNoOvf : public cEnumAssociatedValues {
  public : const GALGAS_string mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_infixOperatorIR_infixNoOvf (const GALGAS_string & inAssociatedValue0
                                                             COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_infixOperatorIR_infixNoOvf (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_infixOperatorIR_infixOvf : public cEnumAssociatedValues {
  public : const GALGAS_string mAssociatedValue0 ;
  public : const GALGAS_uint mAssociatedValue1 ;

//--- Constructor
  public : cEnumAssociatedValues_infixOperatorIR_infixOvf (const GALGAS_string & inAssociatedValue0,
                                                           const GALGAS_uint & inAssociatedValue1
                                                           COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_infixOperatorIR_infixOvf (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_infixOperatorIR_infixUnsignedDivide : public cEnumAssociatedValues {
  public : const GALGAS_uint mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_infixOperatorIR_infixUnsignedDivide (const GALGAS_uint & inAssociatedValue0
                                                                      COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_infixOperatorIR_infixUnsignedDivide (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_infixOperatorIR_infixModulo : public cEnumAssociatedValues {
  public : const GALGAS_uint mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_infixOperatorIR_infixModulo (const GALGAS_uint & inAssociatedValue0
                                                              COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_infixOperatorIR_infixModulo (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @prefixOperatorMap map                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_prefixOperatorMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_prefixOperatorMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_prefixOperatorMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_prefixOperatorMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_prefixOperatorMap (const GALGAS_prefixOperatorMap & inSource) ;
  public : GALGAS_prefixOperatorMap & operator = (const GALGAS_prefixOperatorMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_prefixOperatorMap extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_prefixOperatorMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_prefixOperatorMap constructor_mapWithMapToOverride (const class GALGAS_prefixOperatorMap & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMResultTypeForKey (class GALGAS_unifiedTypeMap_2D_proxy constinArgument0,
                                                                class GALGAS_string constinArgument1,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mResultTypeForKey (const class GALGAS_string & constinOperand0,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_prefixOperatorMap reader_overriddenMap (C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_prefixOperatorMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                               const GALGAS_string & inKey
                                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_prefixOperatorMap ;
 
} ; // End of GALGAS_prefixOperatorMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_prefixOperatorMap : public cGenericAbstractEnumerator {
  public : cEnumerator_prefixOperatorMap (const GALGAS_prefixOperatorMap & inEnumeratedObject,
                                          const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mResultType (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_prefixOperatorMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_prefixOperatorMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@prefixOperatorMap' map                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_prefixOperatorMap : public cMapElement {
//--- Map attributes
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mResultType ;

//--- Constructor
  public : cMapElement_prefixOperatorMap (const GALGAS_lstring & inKey,
                                          const GALGAS_unifiedTypeMap_2D_proxy & in_mResultType
                                          COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @prefixOperatorMap_2D_element struct                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_prefixOperatorMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mResultType ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_prefixOperatorMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_prefixOperatorMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_prefixOperatorMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_prefixOperatorMap_2D_element (const GALGAS_lstring & in_lkey,
                                                const GALGAS_unifiedTypeMap_2D_proxy & in_mResultType) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_prefixOperatorMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_prefixOperatorMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_prefixOperatorMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mResultType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_prefixOperatorMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_prefixOperatorMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @prefixOperatorIR enum                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_prefixOperatorIR : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public : GALGAS_prefixOperatorIR (void) ;

//--------------------------------- Enumeration
  public : typedef enum {
    kNotBuilt,
    kEnum_prefix,
    kEnum_prefixMinusOvf
  } enumeration ;
  
//--------------------------------- Private data member
  private : AC_GALGAS_enumAssociatedValues mAssociatedValues ;
  public : VIRTUAL_IN_DEBUG const cEnumAssociatedValues * unsafePointer (void) const {
    return mAssociatedValues.unsafePointer () ;
  }

  private : enumeration mEnum ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return kNotBuilt != mEnum ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mEnum = kNotBuilt ; }
  public : inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_prefixOperatorIR extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_prefixOperatorIR constructor_prefix (const class GALGAS_string & inOperand0
                                                              COMMA_LOCATION_ARGS) ;

  public : static GALGAS_prefixOperatorIR constructor_prefixMinusOvf (const class GALGAS_uint & inOperand0
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_prefixOperatorIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_prefix (class GALGAS_string & outArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_prefixMinusOvf (class GALGAS_uint & outArgument0,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isPrefix (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isPrefixMinusOvf (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_prefixOperatorIR class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_prefixOperatorIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @prefixOperatorIR enum, associated values                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_prefixOperatorIR_prefix : public cEnumAssociatedValues {
  public : const GALGAS_string mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_prefixOperatorIR_prefix (const GALGAS_string & inAssociatedValue0
                                                          COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_prefixOperatorIR_prefix (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_prefixOperatorIR_prefixMinusOvf : public cEnumAssociatedValues {
  public : const GALGAS_uint mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_prefixOperatorIR_prefixMinusOvf (const GALGAS_uint & inAssociatedValue0
                                                                  COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_prefixOperatorIR_prefixMinusOvf (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @operandIR enum                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_operandIR : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public : GALGAS_operandIR (void) ;

//--------------------------------- Enumeration
  public : typedef enum {
    kNotBuilt,
    kEnum_literalInteger,
    kEnum_llvmLocalObject,
    kEnum_llvmGlobalObject
  } enumeration ;
  
//--------------------------------- Private data member
  private : AC_GALGAS_enumAssociatedValues mAssociatedValues ;
  public : VIRTUAL_IN_DEBUG const cEnumAssociatedValues * unsafePointer (void) const {
    return mAssociatedValues.unsafePointer () ;
  }

  private : enumeration mEnum ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return kNotBuilt != mEnum ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mEnum = kNotBuilt ; }
  public : inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_operandIR extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_operandIR constructor_literalInteger (const class GALGAS_bigint & inOperand0
                                                               COMMA_LOCATION_ARGS) ;

  public : static GALGAS_operandIR constructor_llvmGlobalObject (const class GALGAS_string & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

  public : static GALGAS_operandIR constructor_llvmLocalObject (const class GALGAS_string & inOperand0
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_operandIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_literalInteger (class GALGAS_bigint & outArgument0,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_llvmGlobalObject (class GALGAS_string & outArgument0,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_llvmLocalObject (class GALGAS_string & outArgument0,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isLiteralInteger (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isLlvmGlobalObject (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isLlvmLocalObject (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_operandIR class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_operandIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @operandIR enum, associated values                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_operandIR_literalInteger : public cEnumAssociatedValues {
  public : const GALGAS_bigint mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_operandIR_literalInteger (const GALGAS_bigint & inAssociatedValue0
                                                           COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_operandIR_literalInteger (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_operandIR_llvmLocalObject : public cEnumAssociatedValues {
  public : const GALGAS_string mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_operandIR_llvmLocalObject (const GALGAS_string & inAssociatedValue0
                                                            COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_operandIR_llvmLocalObject (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_operandIR_llvmGlobalObject : public cEnumAssociatedValues {
  public : const GALGAS_string mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_operandIR_llvmGlobalObject (const GALGAS_string & inAssociatedValue0
                                                             COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_operandIR_llvmGlobalObject (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  @procEffectiveParameterListAST_2D_element struct                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procEffectiveParameterListAST_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_procEffectiveParameterPassingModeAST mAttribute_mEffectiveParameterKind ;
  public : GALGAS_lstring mAttribute_mSelector ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_procEffectiveParameterListAST_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_procEffectiveParameterListAST_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_procEffectiveParameterListAST_2D_element (const GALGAS_procEffectiveParameterPassingModeAST & in_mEffectiveParameterKind,
                                                            const GALGAS_lstring & in_mSelector) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procEffectiveParameterListAST_2D_element extractObject (const GALGAS_object & inObject,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procEffectiveParameterListAST_2D_element constructor_new (const class GALGAS_procEffectiveParameterPassingModeAST & inOperand0,
                                                                                   const class GALGAS_lstring & inOperand1
                                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_procEffectiveParameterListAST_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_procEffectiveParameterPassingModeAST reader_mEffectiveParameterKind (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_mSelector (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_procEffectiveParameterListAST_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procEffectiveParameterListAST_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @procEffectiveParameterList list                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procEffectiveParameterList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_procEffectiveParameterList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_procEffectiveParameterList (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_procEffectiveParameterPassingModeAST & in_mEffectiveParameterPassingMode,
                                                  const class GALGAS_lstring & in_mSelector,
                                                  const class GALGAS_unifiedTypeMap_2D_proxy & in_mParameterType
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procEffectiveParameterList extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procEffectiveParameterList constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_procEffectiveParameterList constructor_listWithValue (const class GALGAS_procEffectiveParameterPassingModeAST & inOperand0,
                                                                               const class GALGAS_lstring & inOperand1,
                                                                               const class GALGAS_unifiedTypeMap_2D_proxy & inOperand2
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_procEffectiveParameterList inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_procEffectiveParameterPassingModeAST & inOperand0,
                                                      const class GALGAS_lstring & inOperand1,
                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand2
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_procEffectiveParameterList operator_concat (const GALGAS_procEffectiveParameterList & inOperand
                                                                               COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_procEffectiveParameterList add_operation (const GALGAS_procEffectiveParameterList & inOperand,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_procEffectiveParameterPassingModeAST constinArgument0,
                                                         class GALGAS_lstring constinArgument1,
                                                         class GALGAS_unifiedTypeMap_2D_proxy constinArgument2,
                                                         class GALGAS_uint constinArgument3,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_procEffectiveParameterPassingModeAST & outArgument0,
                                                    class GALGAS_lstring & outArgument1,
                                                    class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_procEffectiveParameterPassingModeAST & outArgument0,
                                                   class GALGAS_lstring & outArgument1,
                                                   class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_procEffectiveParameterPassingModeAST & outArgument0,
                                                         class GALGAS_lstring & outArgument1,
                                                         class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                                         class GALGAS_uint constinArgument3,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_procEffectiveParameterPassingModeAST & outArgument0,
                                               class GALGAS_lstring & outArgument1,
                                               class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_procEffectiveParameterPassingModeAST & outArgument0,
                                              class GALGAS_lstring & outArgument1,
                                              class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_procEffectiveParameterPassingModeAST reader_mEffectiveParameterPassingModeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                                                            C_Compiler * inCompiler
                                                                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mParameterTypeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                               C_Compiler * inCompiler
                                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_mSelectorAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procEffectiveParameterList reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procEffectiveParameterList reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_procEffectiveParameterList ;
 
} ; // End of GALGAS_procEffectiveParameterList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_procEffectiveParameterList : public cGenericAbstractEnumerator {
  public : cEnumerator_procEffectiveParameterList (const GALGAS_procEffectiveParameterList & inEnumeratedObject,
                                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_procEffectiveParameterPassingModeAST current_mEffectiveParameterPassingMode (LOCATION_ARGS) const ;
  public : class GALGAS_lstring current_mSelector (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mParameterType (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_procEffectiveParameterList_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procEffectiveParameterList ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    @procEffectiveParameterList_2D_element struct                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procEffectiveParameterList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_procEffectiveParameterPassingModeAST mAttribute_mEffectiveParameterPassingMode ;
  public : GALGAS_lstring mAttribute_mSelector ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mParameterType ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_procEffectiveParameterList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_procEffectiveParameterList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_procEffectiveParameterList_2D_element (const GALGAS_procEffectiveParameterPassingModeAST & in_mEffectiveParameterPassingMode,
                                                         const GALGAS_lstring & in_mSelector,
                                                         const GALGAS_unifiedTypeMap_2D_proxy & in_mParameterType) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procEffectiveParameterList_2D_element extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procEffectiveParameterList_2D_element constructor_new (const class GALGAS_procEffectiveParameterPassingModeAST & inOperand0,
                                                                                const class GALGAS_lstring & inOperand1,
                                                                                const class GALGAS_unifiedTypeMap_2D_proxy & inOperand2
                                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_procEffectiveParameterList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_procEffectiveParameterPassingModeAST reader_mEffectiveParameterPassingMode (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mParameterType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_mSelector (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_procEffectiveParameterList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procEffectiveParameterList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @procEffectiveParameterPassingModeIR enum                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procEffectiveParameterPassingModeIR : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public : GALGAS_procEffectiveParameterPassingModeIR (void) ;

//--------------------------------- Enumeration
  public : typedef enum {
    kNotBuilt,
    kEnum_input,
    kEnum_output,
    kEnum_outputInput
  } enumeration ;
  
//--------------------------------- Private data member
  private : enumeration mEnum ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return kNotBuilt != mEnum ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mEnum = kNotBuilt ; }
  public : inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procEffectiveParameterPassingModeIR extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procEffectiveParameterPassingModeIR constructor_input (LOCATION_ARGS) ;

  public : static GALGAS_procEffectiveParameterPassingModeIR constructor_output (LOCATION_ARGS) ;

  public : static GALGAS_procEffectiveParameterPassingModeIR constructor_outputInput (LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_procEffectiveParameterPassingModeIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isInput (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isOutput (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isOutputInput (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_procEffectiveParameterPassingModeIR class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procEffectiveParameterPassingModeIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @procCallEffectiveParameterListIR list                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procCallEffectiveParameterListIR : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_procCallEffectiveParameterListIR (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_procCallEffectiveParameterListIR (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_procEffectiveParameterPassingModeIR & in_mEffectiveParameterPassingMode,
                                                  const class GALGAS_lstring & in_mSelector,
                                                  const class GALGAS_unifiedTypeMap_2D_proxy & in_mParameterType,
                                                  const class GALGAS_operandIR & in_mParameter
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procCallEffectiveParameterListIR extractObject (const GALGAS_object & inObject,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procCallEffectiveParameterListIR constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_procCallEffectiveParameterListIR constructor_listWithValue (const class GALGAS_procEffectiveParameterPassingModeIR & inOperand0,
                                                                                     const class GALGAS_lstring & inOperand1,
                                                                                     const class GALGAS_unifiedTypeMap_2D_proxy & inOperand2,
                                                                                     const class GALGAS_operandIR & inOperand3
                                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_procCallEffectiveParameterListIR inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_procEffectiveParameterPassingModeIR & inOperand0,
                                                      const class GALGAS_lstring & inOperand1,
                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand2,
                                                      const class GALGAS_operandIR & inOperand3
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_procCallEffectiveParameterListIR operator_concat (const GALGAS_procCallEffectiveParameterListIR & inOperand
                                                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_procCallEffectiveParameterListIR add_operation (const GALGAS_procCallEffectiveParameterListIR & inOperand,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_procEffectiveParameterPassingModeIR constinArgument0,
                                                         class GALGAS_lstring constinArgument1,
                                                         class GALGAS_unifiedTypeMap_2D_proxy constinArgument2,
                                                         class GALGAS_operandIR constinArgument3,
                                                         class GALGAS_uint constinArgument4,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_procEffectiveParameterPassingModeIR & outArgument0,
                                                    class GALGAS_lstring & outArgument1,
                                                    class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                                    class GALGAS_operandIR & outArgument3,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_procEffectiveParameterPassingModeIR & outArgument0,
                                                   class GALGAS_lstring & outArgument1,
                                                   class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                                   class GALGAS_operandIR & outArgument3,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_procEffectiveParameterPassingModeIR & outArgument0,
                                                         class GALGAS_lstring & outArgument1,
                                                         class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                                         class GALGAS_operandIR & outArgument3,
                                                         class GALGAS_uint constinArgument4,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_procEffectiveParameterPassingModeIR & outArgument0,
                                               class GALGAS_lstring & outArgument1,
                                               class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                               class GALGAS_operandIR & outArgument3,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_procEffectiveParameterPassingModeIR & outArgument0,
                                              class GALGAS_lstring & outArgument1,
                                              class GALGAS_unifiedTypeMap_2D_proxy & outArgument2,
                                              class GALGAS_operandIR & outArgument3,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_procEffectiveParameterPassingModeIR reader_mEffectiveParameterPassingModeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                                                           C_Compiler * inCompiler
                                                                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_operandIR reader_mParameterAtIndex (const class GALGAS_uint & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mParameterTypeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                               C_Compiler * inCompiler
                                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_mSelectorAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procCallEffectiveParameterListIR reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                                   C_Compiler * inCompiler
                                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procCallEffectiveParameterListIR reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                                   C_Compiler * inCompiler
                                                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_procCallEffectiveParameterListIR ;
 
} ; // End of GALGAS_procCallEffectiveParameterListIR class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_procCallEffectiveParameterListIR : public cGenericAbstractEnumerator {
  public : cEnumerator_procCallEffectiveParameterListIR (const GALGAS_procCallEffectiveParameterListIR & inEnumeratedObject,
                                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_procEffectiveParameterPassingModeIR current_mEffectiveParameterPassingMode (LOCATION_ARGS) const ;
  public : class GALGAS_lstring current_mSelector (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mParameterType (LOCATION_ARGS) const ;
  public : class GALGAS_operandIR current_mParameter (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_procCallEffectiveParameterListIR_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procCallEffectiveParameterListIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 @procCallEffectiveParameterListIR_2D_element struct                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procCallEffectiveParameterListIR_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_procEffectiveParameterPassingModeIR mAttribute_mEffectiveParameterPassingMode ;
  public : GALGAS_lstring mAttribute_mSelector ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mParameterType ;
  public : GALGAS_operandIR mAttribute_mParameter ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_procCallEffectiveParameterListIR_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_procCallEffectiveParameterListIR_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_procCallEffectiveParameterListIR_2D_element (const GALGAS_procEffectiveParameterPassingModeIR & in_mEffectiveParameterPassingMode,
                                                               const GALGAS_lstring & in_mSelector,
                                                               const GALGAS_unifiedTypeMap_2D_proxy & in_mParameterType,
                                                               const GALGAS_operandIR & in_mParameter) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procCallEffectiveParameterListIR_2D_element extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procCallEffectiveParameterListIR_2D_element constructor_new (const class GALGAS_procEffectiveParameterPassingModeIR & inOperand0,
                                                                                      const class GALGAS_lstring & inOperand1,
                                                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand2,
                                                                                      const class GALGAS_operandIR & inOperand3
                                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_procCallEffectiveParameterListIR_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_procEffectiveParameterPassingModeIR reader_mEffectiveParameterPassingMode (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_operandIR reader_mParameter (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mParameterType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_mSelector (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_procCallEffectiveParameterListIR_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procCallEffectiveParameterListIR_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @valueIR enum                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_valueIR : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public : GALGAS_valueIR (void) ;

//--------------------------------- Enumeration
  public : typedef enum {
    kNotBuilt,
    kEnum_literalInteger,
    kEnum_llvmObject
  } enumeration ;
  
//--------------------------------- Private data member
  private : AC_GALGAS_enumAssociatedValues mAssociatedValues ;
  public : VIRTUAL_IN_DEBUG const cEnumAssociatedValues * unsafePointer (void) const {
    return mAssociatedValues.unsafePointer () ;
  }

  private : enumeration mEnum ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return kNotBuilt != mEnum ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mEnum = kNotBuilt ; }
  public : inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_valueIR extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_valueIR constructor_literalInteger (const class GALGAS_bigint & inOperand0
                                                             COMMA_LOCATION_ARGS) ;

  public : static GALGAS_valueIR constructor_llvmObject (const class GALGAS_string & inOperand0
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_valueIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_literalInteger (class GALGAS_bigint & outArgument0,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_llvmObject (class GALGAS_string & outArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isLiteralInteger (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isLlvmObject (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_valueIR class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_valueIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @valueIR enum, associated values                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_valueIR_literalInteger : public cEnumAssociatedValues {
  public : const GALGAS_bigint mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_valueIR_literalInteger (const GALGAS_bigint & inAssociatedValue0
                                                         COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_valueIR_literalInteger (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_valueIR_llvmObject : public cEnumAssociatedValues {
  public : const GALGAS_string mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_valueIR_llvmObject (const GALGAS_string & inAssociatedValue0
                                                     COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_valueIR_llvmObject (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @variableListIR list                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_variableListIR : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_variableListIR (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_variableListIR (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_variableKindIR & in_mVar
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_variableListIR extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_variableListIR constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_variableListIR constructor_listWithValue (const class GALGAS_variableKindIR & inOperand0
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_variableListIR inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_variableKindIR & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_variableListIR operator_concat (const GALGAS_variableListIR & inOperand
                                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_variableListIR add_operation (const GALGAS_variableListIR & inOperand,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_variableKindIR constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_variableKindIR & outArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_variableKindIR & outArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_variableKindIR & outArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_variableKindIR & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_variableKindIR & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_variableKindIR reader_mVarAtIndex (const class GALGAS_uint & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_variableListIR reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_variableListIR reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_variableListIR ;
 
} ; // End of GALGAS_variableListIR class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_variableListIR : public cGenericAbstractEnumerator {
  public : cEnumerator_variableListIR (const GALGAS_variableListIR & inEnumeratedObject,
                                       const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_variableKindIR current_mVar (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_variableListIR_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_variableListIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @variableKindIR enum                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_variableKindIR : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public : GALGAS_variableKindIR (void) ;

//--------------------------------- Enumeration
  public : typedef enum {
    kNotBuilt,
    kEnum_register,
    kEnum_globalVariable,
    kEnum_localValue,
    kEnum_globalConstant,
    kEnum_localAccess,
    kEnum_literalString,
    kEnum_literalStructure
  } enumeration ;
  
//--------------------------------- Private data member
  private : AC_GALGAS_enumAssociatedValues mAssociatedValues ;
  public : VIRTUAL_IN_DEBUG const cEnumAssociatedValues * unsafePointer (void) const {
    return mAssociatedValues.unsafePointer () ;
  }

  private : enumeration mEnum ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return kNotBuilt != mEnum ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mEnum = kNotBuilt ; }
  public : inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_variableKindIR extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_variableKindIR constructor_globalConstant (const class GALGAS_operandIR & inOperand0
                                                                    COMMA_LOCATION_ARGS) ;

  public : static GALGAS_variableKindIR constructor_globalVariable (const class GALGAS_unifiedTypeMap_2D_proxy & inOperand0,
                                                                    const class GALGAS_string & inOperand1,
                                                                    const class GALGAS_bool & inOperand2
                                                                    COMMA_LOCATION_ARGS) ;

  public : static GALGAS_variableKindIR constructor_literalString (const class GALGAS_string & inOperand0,
                                                                   const class GALGAS_string & inOperand1
                                                                   COMMA_LOCATION_ARGS) ;

  public : static GALGAS_variableKindIR constructor_literalStructure (const class GALGAS_literalStructureList & inOperand0
                                                                      COMMA_LOCATION_ARGS) ;

  public : static GALGAS_variableKindIR constructor_localAccess (const class GALGAS_lstring & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

  public : static GALGAS_variableKindIR constructor_localValue (const class GALGAS_unifiedTypeMap_2D_proxy & inOperand0,
                                                                const class GALGAS_lstring & inOperand1
                                                                COMMA_LOCATION_ARGS) ;

  public : static GALGAS_variableKindIR constructor_register (const class GALGAS_unifiedTypeMap_2D_proxy & inOperand0,
                                                              const class GALGAS_lstring & inOperand1,
                                                              const class GALGAS_bigint & inOperand2
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_variableKindIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_globalConstant (class GALGAS_operandIR & outArgument0,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_globalVariable (class GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                                        class GALGAS_string & outArgument1,
                                                        class GALGAS_bool & outArgument2,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_literalString (class GALGAS_string & outArgument0,
                                                       class GALGAS_string & outArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_literalStructure (class GALGAS_literalStructureList & outArgument0,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_localAccess (class GALGAS_lstring & outArgument0,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_localValue (class GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                                    class GALGAS_lstring & outArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_register (class GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                                  class GALGAS_lstring & outArgument1,
                                                  class GALGAS_bigint & outArgument2,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isGlobalConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isGlobalVariable (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isLiteralString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isLiteralStructure (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isLocalAccess (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isLocalValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isRegister (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_variableKindIR class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_variableKindIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @variableKindIR enum, associated values                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_variableKindIR_register : public cEnumAssociatedValues {
  public : const GALGAS_unifiedTypeMap_2D_proxy mAssociatedValue0 ;
  public : const GALGAS_lstring mAssociatedValue1 ;
  public : const GALGAS_bigint mAssociatedValue2 ;

//--- Constructor
  public : cEnumAssociatedValues_variableKindIR_register (const GALGAS_unifiedTypeMap_2D_proxy & inAssociatedValue0,
                                                          const GALGAS_lstring & inAssociatedValue1,
                                                          const GALGAS_bigint & inAssociatedValue2
                                                          COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_variableKindIR_register (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_variableKindIR_globalVariable : public cEnumAssociatedValues {
  public : const GALGAS_unifiedTypeMap_2D_proxy mAssociatedValue0 ;
  public : const GALGAS_string mAssociatedValue1 ;
  public : const GALGAS_bool mAssociatedValue2 ;

//--- Constructor
  public : cEnumAssociatedValues_variableKindIR_globalVariable (const GALGAS_unifiedTypeMap_2D_proxy & inAssociatedValue0,
                                                                const GALGAS_string & inAssociatedValue1,
                                                                const GALGAS_bool & inAssociatedValue2
                                                                COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_variableKindIR_globalVariable (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_variableKindIR_localValue : public cEnumAssociatedValues {
  public : const GALGAS_unifiedTypeMap_2D_proxy mAssociatedValue0 ;
  public : const GALGAS_lstring mAssociatedValue1 ;

//--- Constructor
  public : cEnumAssociatedValues_variableKindIR_localValue (const GALGAS_unifiedTypeMap_2D_proxy & inAssociatedValue0,
                                                            const GALGAS_lstring & inAssociatedValue1
                                                            COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_variableKindIR_localValue (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_variableKindIR_globalConstant : public cEnumAssociatedValues {
  public : const GALGAS_operandIR mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_variableKindIR_globalConstant (const GALGAS_operandIR & inAssociatedValue0
                                                                COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_variableKindIR_globalConstant (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_variableKindIR_localAccess : public cEnumAssociatedValues {
  public : const GALGAS_lstring mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_variableKindIR_localAccess (const GALGAS_lstring & inAssociatedValue0
                                                             COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_variableKindIR_localAccess (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_variableKindIR_literalString : public cEnumAssociatedValues {
  public : const GALGAS_string mAssociatedValue0 ;
  public : const GALGAS_string mAssociatedValue1 ;

//--- Constructor
  public : cEnumAssociatedValues_variableKindIR_literalString (const GALGAS_string & inAssociatedValue0,
                                                               const GALGAS_string & inAssociatedValue1
                                                               COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_variableKindIR_literalString (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_variableKindIR_literalStructure : public cEnumAssociatedValues {
  public : const GALGAS_literalStructureList mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_variableKindIR_literalStructure (const GALGAS_literalStructureList & inAssociatedValue0
                                                                  COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_variableKindIR_literalStructure (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @variableListIR_2D_element struct                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_variableListIR_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_variableKindIR mAttribute_mVar ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_variableListIR_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_variableListIR_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_variableListIR_2D_element (const GALGAS_variableKindIR & in_mVar) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_variableListIR_2D_element extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_variableListIR_2D_element constructor_new (const class GALGAS_variableKindIR & inOperand0
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_variableListIR_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_variableKindIR reader_mVar (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_variableListIR_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_variableListIR_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @variableMap unique map                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_variableMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_variableMap_searchForReadAccess ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_variableMap_searchForWriteAccess ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_variableMap_searchForReadWriteAccess ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_variableMap_searchForDropAccess ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_variableMap_neutralAccess ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_variableMap : public AC_GALGAS_uniqueMap {
//--------------------------------- Default constructor
  public : GALGAS_variableMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_variableMap (const GALGAS_variableMap & inSource) ;
  public : GALGAS_variableMap & operator = (const GALGAS_variableMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_variableMap extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_variableMap constructor_emptyMap (LOCATION_ARGS) ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_closeBranch (class GALGAS_location inArgument0,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertConstantInputFormalArgument (class GALGAS_lstring constinArgument0,
                                                                             class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                             class GALGAS_bool constinArgument2,
                                                                             class GALGAS_variableKindIR constinArgument3,
                                                                             class GALGAS_bool constinArgument4,
                                                                             class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                             class GALGAS_bool constinArgument6,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertConstantInputFormalArgumentDeclaredAsUnused (class GALGAS_lstring constinArgument0,
                                                                                             class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                                             class GALGAS_bool constinArgument2,
                                                                                             class GALGAS_variableKindIR constinArgument3,
                                                                                             class GALGAS_bool constinArgument4,
                                                                                             class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                                             class GALGAS_bool constinArgument6,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertDefinedLocalVariable (class GALGAS_lstring constinArgument0,
                                                                      class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                      class GALGAS_bool constinArgument2,
                                                                      class GALGAS_variableKindIR constinArgument3,
                                                                      class GALGAS_bool constinArgument4,
                                                                      class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                      class GALGAS_bool constinArgument6,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertGlobalVariable (class GALGAS_lstring constinArgument0,
                                                                class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                class GALGAS_bool constinArgument2,
                                                                class GALGAS_variableKindIR constinArgument3,
                                                                class GALGAS_bool constinArgument4,
                                                                class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                class GALGAS_bool constinArgument6,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertInputFormalArgument (class GALGAS_lstring constinArgument0,
                                                                     class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                     class GALGAS_bool constinArgument2,
                                                                     class GALGAS_variableKindIR constinArgument3,
                                                                     class GALGAS_bool constinArgument4,
                                                                     class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                     class GALGAS_bool constinArgument6,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertInputFormalArgumentDeclaredAsUnused (class GALGAS_lstring constinArgument0,
                                                                                     class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                                     class GALGAS_bool constinArgument2,
                                                                                     class GALGAS_variableKindIR constinArgument3,
                                                                                     class GALGAS_bool constinArgument4,
                                                                                     class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                                     class GALGAS_bool constinArgument6,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertInputOutputFormalArgument (class GALGAS_lstring constinArgument0,
                                                                           class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                           class GALGAS_bool constinArgument2,
                                                                           class GALGAS_variableKindIR constinArgument3,
                                                                           class GALGAS_bool constinArgument4,
                                                                           class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                           class GALGAS_bool constinArgument6,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertInputOutputFormalArgumentDeclaredAsUnused (class GALGAS_lstring constinArgument0,
                                                                                           class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                                           class GALGAS_bool constinArgument2,
                                                                                           class GALGAS_variableKindIR constinArgument3,
                                                                                           class GALGAS_bool constinArgument4,
                                                                                           class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                                           class GALGAS_bool constinArgument6,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertLocalConstant (class GALGAS_lstring constinArgument0,
                                                               class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                               class GALGAS_bool constinArgument2,
                                                               class GALGAS_variableKindIR constinArgument3,
                                                               class GALGAS_bool constinArgument4,
                                                               class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                               class GALGAS_bool constinArgument6,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertMutableAttribute (class GALGAS_lstring constinArgument0,
                                                                  class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                  class GALGAS_bool constinArgument2,
                                                                  class GALGAS_variableKindIR constinArgument3,
                                                                  class GALGAS_bool constinArgument4,
                                                                  class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                  class GALGAS_bool constinArgument6,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertNonMutableAttribute (class GALGAS_lstring constinArgument0,
                                                                     class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                     class GALGAS_bool constinArgument2,
                                                                     class GALGAS_variableKindIR constinArgument3,
                                                                     class GALGAS_bool constinArgument4,
                                                                     class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                     class GALGAS_bool constinArgument6,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertOutputFormalArgument (class GALGAS_lstring constinArgument0,
                                                                      class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                      class GALGAS_bool constinArgument2,
                                                                      class GALGAS_variableKindIR constinArgument3,
                                                                      class GALGAS_bool constinArgument4,
                                                                      class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                      class GALGAS_bool constinArgument6,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertUndefinedLocalConstant (class GALGAS_lstring constinArgument0,
                                                                        class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                        class GALGAS_bool constinArgument2,
                                                                        class GALGAS_variableKindIR constinArgument3,
                                                                        class GALGAS_bool constinArgument4,
                                                                        class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                        class GALGAS_bool constinArgument6,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertUndefinedLocalVariable (class GALGAS_lstring constinArgument0,
                                                                        class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                        class GALGAS_bool constinArgument2,
                                                                        class GALGAS_variableKindIR constinArgument3,
                                                                        class GALGAS_bool constinArgument4,
                                                                        class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                        class GALGAS_bool constinArgument6,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertUsedConstantInputFormalArgument (class GALGAS_lstring constinArgument0,
                                                                                 class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                                 class GALGAS_bool constinArgument2,
                                                                                 class GALGAS_variableKindIR constinArgument3,
                                                                                 class GALGAS_bool constinArgument4,
                                                                                 class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                                 class GALGAS_bool constinArgument6,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insertUsedLocalConstant (class GALGAS_lstring constinArgument0,
                                                                   class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                                   class GALGAS_bool constinArgument2,
                                                                   class GALGAS_variableKindIR constinArgument3,
                                                                   class GALGAS_bool constinArgument4,
                                                                   class GALGAS_registerBitSliceAccessMap constinArgument5,
                                                                   class GALGAS_bool constinArgument6,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_neutralAccess (class GALGAS_lstring constinArgument0,
                                                         class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                         class GALGAS_bool & outArgument2,
                                                         class GALGAS_variableKindIR & outArgument3,
                                                         class GALGAS_bool & outArgument4,
                                                         class GALGAS_registerBitSliceAccessMap & outArgument5,
                                                         class GALGAS_bool & outArgument6,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_openOverrideForRepeatBlock (C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_openOverrideForSelectBlock (C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_searchForDropAccess (class GALGAS_lstring constinArgument0,
                                                               class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                               class GALGAS_bool & outArgument2,
                                                               class GALGAS_variableKindIR & outArgument3,
                                                               class GALGAS_bool & outArgument4,
                                                               class GALGAS_registerBitSliceAccessMap & outArgument5,
                                                               class GALGAS_bool & outArgument6,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_searchForReadAccess (class GALGAS_lstring constinArgument0,
                                                               class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                               class GALGAS_bool & outArgument2,
                                                               class GALGAS_variableKindIR & outArgument3,
                                                               class GALGAS_bool & outArgument4,
                                                               class GALGAS_registerBitSliceAccessMap & outArgument5,
                                                               class GALGAS_bool & outArgument6,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_searchForReadWriteAccess (class GALGAS_lstring constinArgument0,
                                                                    class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                                    class GALGAS_bool & outArgument2,
                                                                    class GALGAS_variableKindIR & outArgument3,
                                                                    class GALGAS_bool & outArgument4,
                                                                    class GALGAS_registerBitSliceAccessMap & outArgument5,
                                                                    class GALGAS_bool & outArgument6,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_searchForWriteAccess (class GALGAS_lstring constinArgument0,
                                                                class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                                class GALGAS_bool & outArgument2,
                                                                class GALGAS_variableKindIR & outArgument3,
                                                                class GALGAS_bool & outArgument4,
                                                                class GALGAS_registerBitSliceAccessMap & outArgument5,
                                                                class GALGAS_bool & outArgument6,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setCopiableForKey (class GALGAS_bool constinArgument0,
                                                             class GALGAS_string constinArgument1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setFieldMapForKey (class GALGAS_registerBitSliceAccessMap constinArgument0,
                                                             class GALGAS_string constinArgument1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMAccessAllowedForKey (class GALGAS_bool constinArgument0,
                                                                   class GALGAS_string constinArgument1,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMCanBeUsedAsInputParameterForKey (class GALGAS_bool constinArgument0,
                                                                               class GALGAS_string constinArgument1,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMTypeForKey (class GALGAS_unifiedTypeMap_2D_proxy constinArgument0,
                                                          class GALGAS_string constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMVariableKindForKey (class GALGAS_variableKindIR constinArgument0,
                                                                  class GALGAS_string constinArgument1,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_checkAutomatonStates (class GALGAS_location inArgument0,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_copiableForKey (const class GALGAS_string & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_registerBitSliceAccessMap reader_fieldMapForKey (const class GALGAS_string & constinOperand0,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mAccessAllowedForKey (const class GALGAS_string & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mCanBeUsedAsInputParameterForKey (const class GALGAS_string & constinOperand0,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mTypeForKey (const class GALGAS_string & constinOperand0,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_variableKindIR reader_mVariableKindForKey (const class GALGAS_string & constinOperand0,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_variableMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                         const GALGAS_string & inKey
                                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_variableMap ;
 
} ; // End of GALGAS_variableMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_variableMap : public cGenericAbstractEnumerator {
  public : cEnumerator_variableMap (const GALGAS_variableMap & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mType (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_mAccessAllowed (LOCATION_ARGS) const ;
  public : class GALGAS_variableKindIR current_mVariableKind (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_copiable (LOCATION_ARGS) const ;
  public : class GALGAS_registerBitSliceAccessMap current_fieldMap (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_mCanBeUsedAsInputParameter (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_variableMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Class for element of '@variableMap' map                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_variableMap : public cMapElement {
//--- Map attributes
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mType ;
  public : GALGAS_bool mAttribute_mAccessAllowed ;
  public : GALGAS_variableKindIR mAttribute_mVariableKind ;
  public : GALGAS_bool mAttribute_copiable ;
  public : GALGAS_registerBitSliceAccessMap mAttribute_fieldMap ;
  public : GALGAS_bool mAttribute_mCanBeUsedAsInputParameter ;

//--- Constructor
  public : cMapElement_variableMap (const GALGAS_lstring & inKey,
                                    const GALGAS_unifiedTypeMap_2D_proxy & in_mType,
                                    const GALGAS_bool & in_mAccessAllowed,
                                    const GALGAS_variableKindIR & in_mVariableKind,
                                    const GALGAS_bool & in_copiable,
                                    const GALGAS_registerBitSliceAccessMap & in_fieldMap,
                                    const GALGAS_bool & in_mCanBeUsedAsInputParameter
                                    COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @variableMap_2D_proxy map proxy                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_variableMap_2D_proxy : public AC_GALGAS_uniqueMapProxy {
//--------------------------------- Default constructor
  public : GALGAS_variableMap_2D_proxy (void) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_variableMap_2D_proxy extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_variableMap_2D_proxy constructor_neutralAccess (const class GALGAS_variableMap & inOperand0,
                                                                         const class GALGAS_lstring & inOperand1,
                                                                         class C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

  public : static GALGAS_variableMap_2D_proxy constructor_null (LOCATION_ARGS) ;

  public : static GALGAS_variableMap_2D_proxy constructor_searchForDropAccess (const class GALGAS_variableMap & inOperand0,
                                                                               const class GALGAS_lstring & inOperand1,
                                                                               class C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

  public : static GALGAS_variableMap_2D_proxy constructor_searchForReadAccess (const class GALGAS_variableMap & inOperand0,
                                                                               const class GALGAS_lstring & inOperand1,
                                                                               class C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

  public : static GALGAS_variableMap_2D_proxy constructor_searchForReadWriteAccess (const class GALGAS_variableMap & inOperand0,
                                                                                    const class GALGAS_lstring & inOperand1,
                                                                                    class C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) ;

  public : static GALGAS_variableMap_2D_proxy constructor_searchForWriteAccess (const class GALGAS_variableMap & inOperand0,
                                                                                const class GALGAS_lstring & inOperand1,
                                                                                class C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods
  public : static void class_method_makeProxy (class GALGAS_variableMap & ioArgument0,
                                               class GALGAS_lstring constinArgument1,
                                               class GALGAS_variableMap_2D_proxy & outArgument2
                                               COMMA_LOCATION_ARGS) ;

  public : static void class_method_makeProxyFromString (class GALGAS_variableMap & ioArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         class GALGAS_variableMap_2D_proxy & outArgument2
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_copiable (C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_registerBitSliceAccessMap reader_fieldMap (C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mAccessAllowed (C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mCanBeUsedAsInputParameter (C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mType (C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_variableKindIR reader_mVariableKind (C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_variableMap_2D_proxy class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_variableMap_2D_proxy ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @semanticTypePrecedenceGraph graph                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_semanticTypePrecedenceGraph : public AC_GALGAS_graph {
//--------------------------------- Default constructor
  public : GALGAS_semanticTypePrecedenceGraph (void) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_semanticTypePrecedenceGraph extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_semanticTypePrecedenceGraph constructor_emptyGraph (LOCATION_ARGS) ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_addNode (class GALGAS_lstring inArgument0,
                                                   class GALGAS_abstractDeclaration inArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_circularities (class GALGAS_declarationListAST & outArgument0,
                                                       class GALGAS_lstringlist & outArgument1
                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_depthFirstTopologicalSort (class GALGAS_declarationListAST & outArgument0,
                                                                   class GALGAS_lstringlist & outArgument1,
                                                                   class GALGAS_declarationListAST & outArgument2,
                                                                   class GALGAS_lstringlist & outArgument3,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_nodesWithNoPredecessor (class GALGAS_declarationListAST & outArgument0,
                                                                class GALGAS_lstringlist & outArgument1
                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_nodesWithNoSuccessor (class GALGAS_declarationListAST & outArgument0,
                                                              class GALGAS_lstringlist & outArgument1
                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_topologicalSort (class GALGAS_declarationListAST & outArgument0,
                                                         class GALGAS_lstringlist & outArgument1,
                                                         class GALGAS_declarationListAST & outArgument2,
                                                         class GALGAS_lstringlist & outArgument3,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstringlist reader_accessibleNodesFromNodes (const class GALGAS_lstringlist & constinOperand0,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_semanticTypePrecedenceGraph reader_reversedGraph (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_semanticTypePrecedenceGraph reader_subgraphFromNodes (const class GALGAS_lstringlist & constinOperand0,
                                                                                               const class GALGAS_stringset & constinOperand1,
                                                                                               C_Compiler * inCompiler
                                                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_semanticTypePrecedenceGraph class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_semanticTypePrecedenceGraph ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @typeKind enum                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_typeKind : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public : GALGAS_typeKind (void) ;

//--------------------------------- Enumeration
  public : typedef enum {
    kNotBuilt,
    kEnum_boolean,
    kEnum_boolset,
    kEnum_literalString,
    kEnum_enumeration,
    kEnum_structure,
    kEnum_integer
  } enumeration ;
  
//--------------------------------- Private data member
  private : AC_GALGAS_enumAssociatedValues mAssociatedValues ;
  public : VIRTUAL_IN_DEBUG const cEnumAssociatedValues * unsafePointer (void) const {
    return mAssociatedValues.unsafePointer () ;
  }

  private : enumeration mEnum ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return kNotBuilt != mEnum ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mEnum = kNotBuilt ; }
  public : inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeKind extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_typeKind constructor_boolean (LOCATION_ARGS) ;

  public : static GALGAS_typeKind constructor_boolset (LOCATION_ARGS) ;

  public : static GALGAS_typeKind constructor_enumeration (const class GALGAS_enumConstantMap & inOperand0
                                                           COMMA_LOCATION_ARGS) ;

  public : static GALGAS_typeKind constructor_integer (const class GALGAS_bigint & inOperand0,
                                                       const class GALGAS_bigint & inOperand1,
                                                       const class GALGAS_bool & inOperand2,
                                                       const class GALGAS_uint & inOperand3
                                                       COMMA_LOCATION_ARGS) ;

  public : static GALGAS_typeKind constructor_literalString (LOCATION_ARGS) ;

  public : static GALGAS_typeKind constructor_structure (const class GALGAS_propertyMap & inOperand0
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeKind & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_enumeration (class GALGAS_enumConstantMap & outArgument0,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_integer (class GALGAS_bigint & outArgument0,
                                                 class GALGAS_bigint & outArgument1,
                                                 class GALGAS_bool & outArgument2,
                                                 class GALGAS_uint & outArgument3,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_structure (class GALGAS_propertyMap & outArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isBoolean (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isBoolset (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isEnumeration (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isInteger (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isLiteralString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isStructure (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeKind class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeKind ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @typeKind enum, associated values                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_typeKind_enumeration : public cEnumAssociatedValues {
  public : const GALGAS_enumConstantMap mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_typeKind_enumeration (const GALGAS_enumConstantMap & inAssociatedValue0
                                                       COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_typeKind_enumeration (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_typeKind_structure : public cEnumAssociatedValues {
  public : const GALGAS_propertyMap mAssociatedValue0 ;

//--- Constructor
  public : cEnumAssociatedValues_typeKind_structure (const GALGAS_propertyMap & inAssociatedValue0
                                                     COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_typeKind_structure (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*

class cEnumAssociatedValues_typeKind_integer : public cEnumAssociatedValues {
  public : const GALGAS_bigint mAssociatedValue0 ;
  public : const GALGAS_bigint mAssociatedValue1 ;
  public : const GALGAS_bool mAssociatedValue2 ;
  public : const GALGAS_uint mAssociatedValue3 ;

//--- Constructor
  public : cEnumAssociatedValues_typeKind_integer (const GALGAS_bigint & inAssociatedValue0,
                                                   const GALGAS_bigint & inAssociatedValue1,
                                                   const GALGAS_bool & inAssociatedValue2,
                                                   const GALGAS_uint & inAssociatedValue3
                                                   COMMA_LOCATION_ARGS) ;

  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;
  public : virtual typeComparisonResult compare (const cEnumAssociatedValues * inOperand) const ;

  public : virtual ~ cEnumAssociatedValues_typeKind_integer (void) {}
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @incDecOperatorMap map                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_incDecOperatorMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_incDecOperatorMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_incDecOperatorMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_incDecOperatorMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_incDecOperatorMap (const GALGAS_incDecOperatorMap & inSource) ;
  public : GALGAS_incDecOperatorMap & operator = (const GALGAS_incDecOperatorMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_incDecOperatorMap extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_incDecOperatorMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_incDecOperatorMap constructor_mapWithMapToOverride (const class GALGAS_incDecOperatorMap & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_llvmBinaryOperation & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_llvmBinaryOperation constinArgument1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMOperationForKey (class GALGAS_llvmBinaryOperation constinArgument0,
                                                               class GALGAS_string constinArgument1,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_llvmBinaryOperation & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_llvmBinaryOperation reader_mOperationForKey (const class GALGAS_string & constinOperand0,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_incDecOperatorMap reader_overriddenMap (C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_incDecOperatorMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                               const GALGAS_string & inKey
                                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_incDecOperatorMap ;
 
} ; // End of GALGAS_incDecOperatorMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_incDecOperatorMap : public cGenericAbstractEnumerator {
  public : cEnumerator_incDecOperatorMap (const GALGAS_incDecOperatorMap & inEnumeratedObject,
                                          const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_llvmBinaryOperation current_mOperation (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_incDecOperatorMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_incDecOperatorMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@incDecOperatorMap' map                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_incDecOperatorMap : public cMapElement {
//--- Map attributes
  public : GALGAS_llvmBinaryOperation mAttribute_mOperation ;

//--- Constructor
  public : cMapElement_incDecOperatorMap (const GALGAS_lstring & inKey,
                                          const GALGAS_llvmBinaryOperation & in_mOperation
                                          COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @incDecOperatorMap_2D_element struct                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_incDecOperatorMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_llvmBinaryOperation mAttribute_mOperation ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_incDecOperatorMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_incDecOperatorMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_incDecOperatorMap_2D_element (const GALGAS_lstring & in_lkey,
                                                const GALGAS_llvmBinaryOperation & in_mOperation) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_incDecOperatorMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_incDecOperatorMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_llvmBinaryOperation & inOperand1
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_incDecOperatorMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_llvmBinaryOperation reader_mOperation (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_incDecOperatorMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_incDecOperatorMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @globalLiteralStringMap map                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_globalLiteralStringMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_globalLiteralStringMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_globalLiteralStringMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_globalLiteralStringMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_globalLiteralStringMap (const GALGAS_globalLiteralStringMap & inSource) ;
  public : GALGAS_globalLiteralStringMap & operator = (const GALGAS_globalLiteralStringMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_globalLiteralStringMap extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_globalLiteralStringMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_globalLiteralStringMap constructor_mapWithMapToOverride (const class GALGAS_globalLiteralStringMap & inOperand0
                                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_string & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_string constinArgument1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMLiteralStringCnameForKey (class GALGAS_string constinArgument0,
                                                                        class GALGAS_string constinArgument1,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_string & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_mLiteralStringCnameForKey (const class GALGAS_string & constinOperand0,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_globalLiteralStringMap reader_overriddenMap (C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_globalLiteralStringMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                    const GALGAS_string & inKey
                                                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_globalLiteralStringMap ;
 
} ; // End of GALGAS_globalLiteralStringMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_globalLiteralStringMap : public cGenericAbstractEnumerator {
  public : cEnumerator_globalLiteralStringMap (const GALGAS_globalLiteralStringMap & inEnumeratedObject,
                                               const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_string current_mLiteralStringCname (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_globalLiteralStringMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_globalLiteralStringMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Class for element of '@globalLiteralStringMap' map                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_globalLiteralStringMap : public cMapElement {
//--- Map attributes
  public : GALGAS_string mAttribute_mLiteralStringCname ;

//--- Constructor
  public : cMapElement_globalLiteralStringMap (const GALGAS_lstring & inKey,
                                               const GALGAS_string & in_mLiteralStringCname
                                               COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @globalLiteralStringMap_2D_element struct                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_globalLiteralStringMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_string mAttribute_mLiteralStringCname ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_globalLiteralStringMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_globalLiteralStringMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_globalLiteralStringMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_globalLiteralStringMap_2D_element (const GALGAS_lstring & in_lkey,
                                                     const GALGAS_string & in_mLiteralStringCname) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_globalLiteralStringMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_globalLiteralStringMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                            const class GALGAS_string & inOperand1
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_globalLiteralStringMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_mLiteralStringCname (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_globalLiteralStringMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_globalLiteralStringMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @globalConstantMap map                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_globalConstantMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_globalConstantMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_globalConstantMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_globalConstantMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_globalConstantMap (const GALGAS_globalConstantMap & inSource) ;
  public : GALGAS_globalConstantMap & operator = (const GALGAS_globalConstantMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_globalConstantMap extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_globalConstantMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_globalConstantMap constructor_mapWithMapToOverride (const class GALGAS_globalConstantMap & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                      const class GALGAS_operandIR & inOperand2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                     class GALGAS_operandIR constinArgument2,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMConstantTypeForKey (class GALGAS_unifiedTypeMap_2D_proxy constinArgument0,
                                                                  class GALGAS_string constinArgument1,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMExpressionCodeForKey (class GALGAS_operandIR constinArgument0,
                                                                    class GALGAS_string constinArgument1,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                   class GALGAS_operandIR & outArgument2,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mConstantTypeForKey (const class GALGAS_string & constinOperand0,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_operandIR reader_mExpressionCodeForKey (const class GALGAS_string & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_globalConstantMap reader_overriddenMap (C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_globalConstantMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                               const GALGAS_string & inKey
                                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_globalConstantMap ;
 
} ; // End of GALGAS_globalConstantMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_globalConstantMap : public cGenericAbstractEnumerator {
  public : cEnumerator_globalConstantMap (const GALGAS_globalConstantMap & inEnumeratedObject,
                                          const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mConstantType (LOCATION_ARGS) const ;
  public : class GALGAS_operandIR current_mExpressionCode (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_globalConstantMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_globalConstantMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@globalConstantMap' map                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_globalConstantMap : public cMapElement {
//--- Map attributes
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mConstantType ;
  public : GALGAS_operandIR mAttribute_mExpressionCode ;

//--- Constructor
  public : cMapElement_globalConstantMap (const GALGAS_lstring & inKey,
                                          const GALGAS_unifiedTypeMap_2D_proxy & in_mConstantType,
                                          const GALGAS_operandIR & in_mExpressionCode
                                          COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @globalConstantMap_2D_element struct                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_globalConstantMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mConstantType ;
  public : GALGAS_operandIR mAttribute_mExpressionCode ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_globalConstantMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_globalConstantMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_globalConstantMap_2D_element (const GALGAS_lstring & in_lkey,
                                                const GALGAS_unifiedTypeMap_2D_proxy & in_mConstantType,
                                                const GALGAS_operandIR & in_mExpressionCode) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_globalConstantMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_globalConstantMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                       const class GALGAS_operandIR & inOperand2
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_globalConstantMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mConstantType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_operandIR reader_mExpressionCode (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_globalConstantMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_globalConstantMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @globalVariableMap map                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_globalVariableMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_globalVariableMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_globalVariableMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_globalVariableMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_globalVariableMap (const GALGAS_globalVariableMap & inSource) ;
  public : GALGAS_globalVariableMap & operator = (const GALGAS_globalVariableMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_globalVariableMap extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_globalVariableMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_globalVariableMap constructor_mapWithMapToOverride (const class GALGAS_globalVariableMap & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                      const class GALGAS_stringset & inOperand2,
                                                      const class GALGAS_allowedRoutineMap & inOperand3,
                                                      const class GALGAS_operandIR & inOperand4,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                     class GALGAS_stringset constinArgument2,
                                                     class GALGAS_allowedRoutineMap constinArgument3,
                                                     class GALGAS_operandIR constinArgument4,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMAllowedProcedureMapForKey (class GALGAS_allowedRoutineMap constinArgument0,
                                                                         class GALGAS_string constinArgument1,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMExecutionModeSetForKey (class GALGAS_stringset constinArgument0,
                                                                      class GALGAS_string constinArgument1,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMInitialValueForKey (class GALGAS_operandIR constinArgument0,
                                                                  class GALGAS_string constinArgument1,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMVariableTypeForKey (class GALGAS_unifiedTypeMap_2D_proxy constinArgument0,
                                                                  class GALGAS_string constinArgument1,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                   class GALGAS_stringset & outArgument2,
                                                   class GALGAS_allowedRoutineMap & outArgument3,
                                                   class GALGAS_operandIR & outArgument4,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_allowedRoutineMap reader_mAllowedProcedureMapForKey (const class GALGAS_string & constinOperand0,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringset reader_mExecutionModeSetForKey (const class GALGAS_string & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_operandIR reader_mInitialValueForKey (const class GALGAS_string & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mVariableTypeForKey (const class GALGAS_string & constinOperand0,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_globalVariableMap reader_overriddenMap (C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_globalVariableMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                               const GALGAS_string & inKey
                                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_globalVariableMap ;
 
} ; // End of GALGAS_globalVariableMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_globalVariableMap : public cGenericAbstractEnumerator {
  public : cEnumerator_globalVariableMap (const GALGAS_globalVariableMap & inEnumeratedObject,
                                          const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mVariableType (LOCATION_ARGS) const ;
  public : class GALGAS_stringset current_mExecutionModeSet (LOCATION_ARGS) const ;
  public : class GALGAS_allowedRoutineMap current_mAllowedProcedureMap (LOCATION_ARGS) const ;
  public : class GALGAS_operandIR current_mInitialValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_globalVariableMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_globalVariableMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@globalVariableMap' map                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_globalVariableMap : public cMapElement {
//--- Map attributes
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mVariableType ;
  public : GALGAS_stringset mAttribute_mExecutionModeSet ;
  public : GALGAS_allowedRoutineMap mAttribute_mAllowedProcedureMap ;
  public : GALGAS_operandIR mAttribute_mInitialValue ;

//--- Constructor
  public : cMapElement_globalVariableMap (const GALGAS_lstring & inKey,
                                          const GALGAS_unifiedTypeMap_2D_proxy & in_mVariableType,
                                          const GALGAS_stringset & in_mExecutionModeSet,
                                          const GALGAS_allowedRoutineMap & in_mAllowedProcedureMap,
                                          const GALGAS_operandIR & in_mInitialValue
                                          COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @globalVariableMap_2D_element struct                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_globalVariableMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mVariableType ;
  public : GALGAS_stringset mAttribute_mExecutionModeSet ;
  public : GALGAS_allowedRoutineMap mAttribute_mAllowedProcedureMap ;
  public : GALGAS_operandIR mAttribute_mInitialValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_globalVariableMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_globalVariableMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_globalVariableMap_2D_element (const GALGAS_lstring & in_lkey,
                                                const GALGAS_unifiedTypeMap_2D_proxy & in_mVariableType,
                                                const GALGAS_stringset & in_mExecutionModeSet,
                                                const GALGAS_allowedRoutineMap & in_mAllowedProcedureMap,
                                                const GALGAS_operandIR & in_mInitialValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_globalVariableMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_globalVariableMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                       const class GALGAS_stringset & inOperand2,
                                                                       const class GALGAS_allowedRoutineMap & inOperand3,
                                                                       const class GALGAS_operandIR & inOperand4
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_globalVariableMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_allowedRoutineMap reader_mAllowedProcedureMap (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringset reader_mExecutionModeSet (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_operandIR reader_mInitialValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mVariableType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_globalVariableMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_globalVariableMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @constructorMap map                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_constructorMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_constructorMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_constructorMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_constructorMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_constructorMap (const GALGAS_constructorMap & inSource) ;
  public : GALGAS_constructorMap & operator = (const GALGAS_constructorMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_constructorMap extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_constructorMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_constructorMap constructor_mapWithMapToOverride (const class GALGAS_constructorMap & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_operandIR & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_operandIR constinArgument1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMValueForKey (class GALGAS_operandIR constinArgument0,
                                                           class GALGAS_string constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_operandIR & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_operandIR reader_mValueForKey (const class GALGAS_string & constinOperand0,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_constructorMap reader_overriddenMap (C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_constructorMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                            const GALGAS_string & inKey
                                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_constructorMap ;
 
} ; // End of GALGAS_constructorMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_constructorMap : public cGenericAbstractEnumerator {
  public : cEnumerator_constructorMap (const GALGAS_constructorMap & inEnumeratedObject,
                                       const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_operandIR current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_constructorMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_constructorMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @unifiedTypeMap unique map                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_unifiedTypeMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_unifiedTypeMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_unifiedTypeMap : public AC_GALGAS_uniqueMap {
//--------------------------------- Default constructor
  public : GALGAS_unifiedTypeMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_unifiedTypeMap (const GALGAS_unifiedTypeMap & inSource) ;
  public : GALGAS_unifiedTypeMap & operator = (const GALGAS_unifiedTypeMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_unifiedTypeMap extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_unifiedTypeMap constructor_emptyMap (LOCATION_ARGS) ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_typeKind constinArgument1,
                                                     class GALGAS_constructorMap constinArgument2,
                                                     class GALGAS_procedureMap constinArgument3,
                                                     class GALGAS_bool constinArgument4,
                                                     class GALGAS_bool constinArgument5,
                                                     class GALGAS_bool constinArgument6,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setComparableForKey (class GALGAS_bool constinArgument0,
                                                               class GALGAS_string constinArgument1,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setConstructorMapForKey (class GALGAS_constructorMap constinArgument0,
                                                                   class GALGAS_string constinArgument1,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setCopiableForKey (class GALGAS_bool constinArgument0,
                                                             class GALGAS_string constinArgument1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setEquatableForKey (class GALGAS_bool constinArgument0,
                                                              class GALGAS_string constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setKindForKey (class GALGAS_typeKind constinArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setProcedureMapForKey (class GALGAS_procedureMap constinArgument0,
                                                                 class GALGAS_string constinArgument1,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_typeKind & outArgument1,
                                                   class GALGAS_constructorMap & outArgument2,
                                                   class GALGAS_procedureMap & outArgument3,
                                                   class GALGAS_bool & outArgument4,
                                                   class GALGAS_bool & outArgument5,
                                                   class GALGAS_bool & outArgument6,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_comparableForKey (const class GALGAS_string & constinOperand0,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_constructorMap reader_constructorMapForKey (const class GALGAS_string & constinOperand0,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_copiableForKey (const class GALGAS_string & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_equatableForKey (const class GALGAS_string & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typeKind reader_kindForKey (const class GALGAS_string & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procedureMap reader_procedureMapForKey (const class GALGAS_string & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_unifiedTypeMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                            const GALGAS_string & inKey
                                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_unifiedTypeMap ;
 
} ; // End of GALGAS_unifiedTypeMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_unifiedTypeMap : public cGenericAbstractEnumerator {
  public : cEnumerator_unifiedTypeMap (const GALGAS_unifiedTypeMap & inEnumeratedObject,
                                       const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_typeKind current_kind (LOCATION_ARGS) const ;
  public : class GALGAS_constructorMap current_constructorMap (LOCATION_ARGS) const ;
  public : class GALGAS_procedureMap current_procedureMap (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_copiable (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_equatable (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_comparable (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_unifiedTypeMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Class for element of '@unifiedTypeMap' map                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_unifiedTypeMap : public cMapElement {
//--- Map attributes
  public : GALGAS_typeKind mAttribute_kind ;
  public : GALGAS_constructorMap mAttribute_constructorMap ;
  public : GALGAS_procedureMap mAttribute_procedureMap ;
  public : GALGAS_bool mAttribute_copiable ;
  public : GALGAS_bool mAttribute_equatable ;
  public : GALGAS_bool mAttribute_comparable ;

//--- Constructor
  public : cMapElement_unifiedTypeMap (const GALGAS_lstring & inKey,
                                       const GALGAS_typeKind & in_kind,
                                       const GALGAS_constructorMap & in_constructorMap,
                                       const GALGAS_procedureMap & in_procedureMap,
                                       const GALGAS_bool & in_copiable,
                                       const GALGAS_bool & in_equatable,
                                       const GALGAS_bool & in_comparable
                                       COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Class for element of '@constructorMap' map                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_constructorMap : public cMapElement {
//--- Map attributes
  public : GALGAS_operandIR mAttribute_mValue ;

//--- Constructor
  public : cMapElement_constructorMap (const GALGAS_lstring & inKey,
                                       const GALGAS_operandIR & in_mValue
                                       COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @constructorMap_2D_element struct                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_constructorMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_operandIR mAttribute_mValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_constructorMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_constructorMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_constructorMap_2D_element (const GALGAS_lstring & in_lkey,
                                             const GALGAS_operandIR & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_constructorMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_constructorMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_operandIR & inOperand1
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_constructorMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_operandIR reader_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_constructorMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_constructorMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @typeList list                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_typeList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_typeList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_typeList (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_unifiedTypeMap_2D_proxy & in_mActualType
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeList extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_typeList constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_typeList constructor_listWithValue (const class GALGAS_unifiedTypeMap_2D_proxy & inOperand0
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_typeList inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_unifiedTypeMap_2D_proxy & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_typeList operator_concat (const GALGAS_typeList & inOperand
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_typeList add_operation (const GALGAS_typeList & inOperand,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_unifiedTypeMap_2D_proxy constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mActualTypeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typeList reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typeList reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_typeList ;
 
} ; // End of GALGAS_typeList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_typeList : public cGenericAbstractEnumerator {
  public : cEnumerator_typeList (const GALGAS_typeList & inEnumeratedObject,
                                 const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mActualType (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_typeList_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeList ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @typeList_2D_element struct                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_typeList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mActualType ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeList_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_typeList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_typeList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_typeList_2D_element (const GALGAS_unifiedTypeMap_2D_proxy & in_mActualType) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeList_2D_element extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_typeList_2D_element constructor_new (const class GALGAS_unifiedTypeMap_2D_proxy & inOperand0
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mActualType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @registerMapIR map                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_registerMapIR ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_registerMapIR_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_registerMapIR : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_registerMapIR (void) ;

//--------------------------------- Handle copy
  public : GALGAS_registerMapIR (const GALGAS_registerMapIR & inSource) ;
  public : GALGAS_registerMapIR & operator = (const GALGAS_registerMapIR & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_registerMapIR extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_registerMapIR constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_registerMapIR constructor_mapWithMapToOverride (const class GALGAS_registerMapIR & inOperand0
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_string & inOperand1,
                                                      const class GALGAS_bigint & inOperand2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_string constinArgument1,
                                                     class GALGAS_bigint constinArgument2,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMRegisterAddressForKey (class GALGAS_bigint constinArgument0,
                                                                     class GALGAS_string constinArgument1,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMRegisterTypeNameForKey (class GALGAS_string constinArgument0,
                                                                      class GALGAS_string constinArgument1,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_string & outArgument1,
                                                   class GALGAS_bigint & outArgument2,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bigint reader_mRegisterAddressForKey (const class GALGAS_string & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_mRegisterTypeNameForKey (const class GALGAS_string & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_registerMapIR reader_overriddenMap (C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_registerMapIR * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_registerMapIR ;
 
} ; // End of GALGAS_registerMapIR class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_registerMapIR : public cGenericAbstractEnumerator {
  public : cEnumerator_registerMapIR (const GALGAS_registerMapIR & inEnumeratedObject,
                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_string current_mRegisterTypeName (LOCATION_ARGS) const ;
  public : class GALGAS_bigint current_mRegisterAddress (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_registerMapIR_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_registerMapIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Class for element of '@registerMapIR' map                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_registerMapIR : public cMapElement {
//--- Map attributes
  public : GALGAS_string mAttribute_mRegisterTypeName ;
  public : GALGAS_bigint mAttribute_mRegisterAddress ;

//--- Constructor
  public : cMapElement_registerMapIR (const GALGAS_lstring & inKey,
                                      const GALGAS_string & in_mRegisterTypeName,
                                      const GALGAS_bigint & in_mRegisterAddress
                                      COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @registerMapIR_2D_element struct                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_registerMapIR_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_string mAttribute_mRegisterTypeName ;
  public : GALGAS_bigint mAttribute_mRegisterAddress ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_registerMapIR_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_registerMapIR_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_registerMapIR_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_registerMapIR_2D_element (const GALGAS_lstring & in_lkey,
                                            const GALGAS_string & in_mRegisterTypeName,
                                            const GALGAS_bigint & in_mRegisterAddress) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_registerMapIR_2D_element extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_registerMapIR_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                   const class GALGAS_string & inOperand1,
                                                                   const class GALGAS_bigint & inOperand2
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_registerMapIR_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bigint reader_mRegisterAddress (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_mRegisterTypeName (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_registerMapIR_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_registerMapIR_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @globalVariableMapIR map                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_globalVariableMapIR ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_globalVariableMapIR_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_globalVariableMapIR : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_globalVariableMapIR (void) ;

//--------------------------------- Handle copy
  public : GALGAS_globalVariableMapIR (const GALGAS_globalVariableMapIR & inSource) ;
  public : GALGAS_globalVariableMapIR & operator = (const GALGAS_globalVariableMapIR & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_globalVariableMapIR extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_globalVariableMapIR constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_globalVariableMapIR constructor_mapWithMapToOverride (const class GALGAS_globalVariableMapIR & inOperand0
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                      const class GALGAS_bool & inOperand2,
                                                      const class GALGAS_operandIR & inOperand3,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_unifiedTypeMap_2D_proxy constinArgument1,
                                                     class GALGAS_bool constinArgument2,
                                                     class GALGAS_operandIR constinArgument3,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMGenerateVolatileForKey (class GALGAS_bool constinArgument0,
                                                                      class GALGAS_string constinArgument1,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMInitialValueForKey (class GALGAS_operandIR constinArgument0,
                                                                  class GALGAS_string constinArgument1,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMTypeForKey (class GALGAS_unifiedTypeMap_2D_proxy constinArgument0,
                                                          class GALGAS_string constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_unifiedTypeMap_2D_proxy & outArgument1,
                                                   class GALGAS_bool & outArgument2,
                                                   class GALGAS_operandIR & outArgument3,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mGenerateVolatileForKey (const class GALGAS_string & constinOperand0,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_operandIR reader_mInitialValueForKey (const class GALGAS_string & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mTypeForKey (const class GALGAS_string & constinOperand0,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_globalVariableMapIR reader_overriddenMap (C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_globalVariableMapIR * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                 const GALGAS_string & inKey
                                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_globalVariableMapIR ;
 
} ; // End of GALGAS_globalVariableMapIR class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_globalVariableMapIR : public cGenericAbstractEnumerator {
  public : cEnumerator_globalVariableMapIR (const GALGAS_globalVariableMapIR & inEnumeratedObject,
                                            const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mType (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_mGenerateVolatile (LOCATION_ARGS) const ;
  public : class GALGAS_operandIR current_mInitialValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_globalVariableMapIR_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_globalVariableMapIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Class for element of '@globalVariableMapIR' map                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_globalVariableMapIR : public cMapElement {
//--- Map attributes
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mType ;
  public : GALGAS_bool mAttribute_mGenerateVolatile ;
  public : GALGAS_operandIR mAttribute_mInitialValue ;

//--- Constructor
  public : cMapElement_globalVariableMapIR (const GALGAS_lstring & inKey,
                                            const GALGAS_unifiedTypeMap_2D_proxy & in_mType,
                                            const GALGAS_bool & in_mGenerateVolatile,
                                            const GALGAS_operandIR & in_mInitialValue
                                            COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @globalVariableMapIR_2D_element struct                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_globalVariableMapIR_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mType ;
  public : GALGAS_bool mAttribute_mGenerateVolatile ;
  public : GALGAS_operandIR mAttribute_mInitialValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_globalVariableMapIR_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_globalVariableMapIR_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_globalVariableMapIR_2D_element (const GALGAS_lstring & in_lkey,
                                                  const GALGAS_unifiedTypeMap_2D_proxy & in_mType,
                                                  const GALGAS_bool & in_mGenerateVolatile,
                                                  const GALGAS_operandIR & in_mInitialValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_globalVariableMapIR_2D_element extractObject (const GALGAS_object & inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_globalVariableMapIR_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                         const class GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                         const class GALGAS_bool & inOperand2,
                                                                         const class GALGAS_operandIR & inOperand3
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_globalVariableMapIR_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mGenerateVolatile (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_operandIR reader_mInitialValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_globalVariableMapIR_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_globalVariableMapIR_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @globalConstantMapIR map                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_globalConstantMapIR ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_globalConstantMapIR_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_globalConstantMapIR : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_globalConstantMapIR (void) ;

//--------------------------------- Handle copy
  public : GALGAS_globalConstantMapIR (const GALGAS_globalConstantMapIR & inSource) ;
  public : GALGAS_globalConstantMapIR & operator = (const GALGAS_globalConstantMapIR & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_globalConstantMapIR extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_globalConstantMapIR constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_globalConstantMapIR constructor_mapWithMapToOverride (const class GALGAS_globalConstantMapIR & inOperand0
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_operandIR & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_operandIR constinArgument1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMValueExpressionGenerationForKey (class GALGAS_operandIR constinArgument0,
                                                                               class GALGAS_string constinArgument1,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_operandIR & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_operandIR reader_mValueExpressionGenerationForKey (const class GALGAS_string & constinOperand0,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_globalConstantMapIR reader_overriddenMap (C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_globalConstantMapIR * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                 const GALGAS_string & inKey
                                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_globalConstantMapIR ;
 
} ; // End of GALGAS_globalConstantMapIR class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_globalConstantMapIR : public cGenericAbstractEnumerator {
  public : cEnumerator_globalConstantMapIR (const GALGAS_globalConstantMapIR & inEnumeratedObject,
                                            const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_operandIR current_mValueExpressionGeneration (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_globalConstantMapIR_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_globalConstantMapIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Class for element of '@globalConstantMapIR' map                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_globalConstantMapIR : public cMapElement {
//--- Map attributes
  public : GALGAS_operandIR mAttribute_mValueExpressionGeneration ;

//--- Constructor
  public : cMapElement_globalConstantMapIR (const GALGAS_lstring & inKey,
                                            const GALGAS_operandIR & in_mValueExpressionGeneration
                                            COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @globalConstantMapIR_2D_element struct                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_globalConstantMapIR_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_operandIR mAttribute_mValueExpressionGeneration ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_globalConstantMapIR_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_globalConstantMapIR_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_globalConstantMapIR_2D_element (const GALGAS_lstring & in_lkey,
                                                  const GALGAS_operandIR & in_mValueExpressionGeneration) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_globalConstantMapIR_2D_element extractObject (const GALGAS_object & inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_globalConstantMapIR_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                         const class GALGAS_operandIR & inOperand1
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_globalConstantMapIR_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_operandIR reader_mValueExpressionGeneration (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_globalConstantMapIR_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_globalConstantMapIR_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @procedureMapIR map                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_procedureMapIR ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_procedureMapIR_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procedureMapIR : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_procedureMapIR (void) ;

//--------------------------------- Handle copy
  public : GALGAS_procedureMapIR (const GALGAS_procedureMapIR & inSource) ;
  public : GALGAS_procedureMapIR & operator = (const GALGAS_procedureMapIR & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procedureMapIR extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procedureMapIR constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_procedureMapIR constructor_mapWithMapToOverride (const class GALGAS_procedureMapIR & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_procFormalArgumentListForGeneration & inOperand1,
                                                      const class GALGAS_instructionListIR & inOperand2,
                                                      const class GALGAS_bool & inOperand3,
                                                      const class GALGAS_bool & inOperand4,
                                                      const class GALGAS_bool & inOperand5,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_procFormalArgumentListForGeneration constinArgument1,
                                                     class GALGAS_instructionListIR constinArgument2,
                                                     class GALGAS_bool constinArgument3,
                                                     class GALGAS_bool constinArgument4,
                                                     class GALGAS_bool constinArgument5,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_procFormalArgumentListForGeneration & outArgument1,
                                                     class GALGAS_instructionListIR & outArgument2,
                                                     class GALGAS_bool & outArgument3,
                                                     class GALGAS_bool & outArgument4,
                                                     class GALGAS_bool & outArgument5,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMFormalArgumentListForGenerationForKey (class GALGAS_procFormalArgumentListForGeneration constinArgument0,
                                                                                     class GALGAS_string constinArgument1,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMInstructionGenerationListForKey (class GALGAS_instructionListIR constinArgument0,
                                                                               class GALGAS_string constinArgument1,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMIsRequiredForKey (class GALGAS_bool constinArgument0,
                                                                class GALGAS_string constinArgument1,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMWarnIfUnusedForKey (class GALGAS_bool constinArgument0,
                                                                  class GALGAS_string constinArgument1,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMWeakForKey (class GALGAS_bool constinArgument0,
                                                          class GALGAS_string constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_procFormalArgumentListForGeneration & outArgument1,
                                                   class GALGAS_instructionListIR & outArgument2,
                                                   class GALGAS_bool & outArgument3,
                                                   class GALGAS_bool & outArgument4,
                                                   class GALGAS_bool & outArgument5,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_procFormalArgumentListForGeneration reader_mFormalArgumentListForGenerationForKey (const class GALGAS_string & constinOperand0,
                                                                                                                            C_Compiler * inCompiler
                                                                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_instructionListIR reader_mInstructionGenerationListForKey (const class GALGAS_string & constinOperand0,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mIsRequiredForKey (const class GALGAS_string & constinOperand0,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mWarnIfUnusedForKey (const class GALGAS_string & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mWeakForKey (const class GALGAS_string & constinOperand0,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procedureMapIR reader_overriddenMap (C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_procedureMapIR * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                            const GALGAS_string & inKey
                                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_procedureMapIR ;
 
} ; // End of GALGAS_procedureMapIR class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_procedureMapIR : public cGenericAbstractEnumerator {
  public : cEnumerator_procedureMapIR (const GALGAS_procedureMapIR & inEnumeratedObject,
                                       const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_procFormalArgumentListForGeneration current_mFormalArgumentListForGeneration (LOCATION_ARGS) const ;
  public : class GALGAS_instructionListIR current_mInstructionGenerationList (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_mIsRequired (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_mWarnIfUnused (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_mWeak (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_procedureMapIR_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procedureMapIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Class for element of '@procedureMapIR' map                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_procedureMapIR : public cMapElement {
//--- Map attributes
  public : GALGAS_procFormalArgumentListForGeneration mAttribute_mFormalArgumentListForGeneration ;
  public : GALGAS_instructionListIR mAttribute_mInstructionGenerationList ;
  public : GALGAS_bool mAttribute_mIsRequired ;
  public : GALGAS_bool mAttribute_mWarnIfUnused ;
  public : GALGAS_bool mAttribute_mWeak ;

//--- Constructor
  public : cMapElement_procedureMapIR (const GALGAS_lstring & inKey,
                                       const GALGAS_procFormalArgumentListForGeneration & in_mFormalArgumentListForGeneration,
                                       const GALGAS_instructionListIR & in_mInstructionGenerationList,
                                       const GALGAS_bool & in_mIsRequired,
                                       const GALGAS_bool & in_mWarnIfUnused,
                                       const GALGAS_bool & in_mWeak
                                       COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @procedureMapIR_2D_element struct                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_procedureMapIR_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_procFormalArgumentListForGeneration mAttribute_mFormalArgumentListForGeneration ;
  public : GALGAS_instructionListIR mAttribute_mInstructionGenerationList ;
  public : GALGAS_bool mAttribute_mIsRequired ;
  public : GALGAS_bool mAttribute_mWarnIfUnused ;
  public : GALGAS_bool mAttribute_mWeak ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_procedureMapIR_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_procedureMapIR_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_procedureMapIR_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_procedureMapIR_2D_element (const GALGAS_lstring & in_lkey,
                                             const GALGAS_procFormalArgumentListForGeneration & in_mFormalArgumentListForGeneration,
                                             const GALGAS_instructionListIR & in_mInstructionGenerationList,
                                             const GALGAS_bool & in_mIsRequired,
                                             const GALGAS_bool & in_mWarnIfUnused,
                                             const GALGAS_bool & in_mWeak) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_procedureMapIR_2D_element extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_procedureMapIR_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_procFormalArgumentListForGeneration & inOperand1,
                                                                    const class GALGAS_instructionListIR & inOperand2,
                                                                    const class GALGAS_bool & inOperand3,
                                                                    const class GALGAS_bool & inOperand4,
                                                                    const class GALGAS_bool & inOperand5
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_procedureMapIR_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_procFormalArgumentListForGeneration reader_mFormalArgumentListForGeneration (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_instructionListIR reader_mInstructionGenerationList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mIsRequired (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mWarnIfUnused (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_mWeak (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_procedureMapIR_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_procedureMapIR_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @functionMapIR map                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_functionMapIR ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_functionMapIR_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_functionMapIR : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_functionMapIR (void) ;

//--------------------------------- Handle copy
  public : GALGAS_functionMapIR (const GALGAS_functionMapIR & inSource) ;
  public : GALGAS_functionMapIR & operator = (const GALGAS_functionMapIR & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_functionMapIR extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_functionMapIR constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_functionMapIR constructor_mapWithMapToOverride (const class GALGAS_functionMapIR & inOperand0
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_funcFormalArgumentListForGeneration & inOperand1,
                                                      const class GALGAS_instructionListIR & inOperand2,
                                                      const class GALGAS_unifiedTypeMap_2D_proxy & inOperand3,
                                                      const class GALGAS_string & inOperand4,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_funcFormalArgumentListForGeneration constinArgument1,
                                                     class GALGAS_instructionListIR constinArgument2,
                                                     class GALGAS_unifiedTypeMap_2D_proxy constinArgument3,
                                                     class GALGAS_string constinArgument4,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMFormalArgumentListForGenerationForKey (class GALGAS_funcFormalArgumentListForGeneration constinArgument0,
                                                                                     class GALGAS_string constinArgument1,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMInstructionGenerationListForKey (class GALGAS_instructionListIR constinArgument0,
                                                                               class GALGAS_string constinArgument1,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMResultTypeForKey (class GALGAS_unifiedTypeMap_2D_proxy constinArgument0,
                                                                class GALGAS_string constinArgument1,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMResultVarNameForKey (class GALGAS_string constinArgument0,
                                                                   class GALGAS_string constinArgument1,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_funcFormalArgumentListForGeneration & outArgument1,
                                                   class GALGAS_instructionListIR & outArgument2,
                                                   class GALGAS_unifiedTypeMap_2D_proxy & outArgument3,
                                                   class GALGAS_string & outArgument4,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_funcFormalArgumentListForGeneration reader_mFormalArgumentListForGenerationForKey (const class GALGAS_string & constinOperand0,
                                                                                                                            C_Compiler * inCompiler
                                                                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_instructionListIR reader_mInstructionGenerationListForKey (const class GALGAS_string & constinOperand0,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mResultTypeForKey (const class GALGAS_string & constinOperand0,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_mResultVarNameForKey (const class GALGAS_string & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_functionMapIR reader_overriddenMap (C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_functionMapIR * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_functionMapIR ;
 
} ; // End of GALGAS_functionMapIR class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_functionMapIR : public cGenericAbstractEnumerator {
  public : cEnumerator_functionMapIR (const GALGAS_functionMapIR & inEnumeratedObject,
                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_funcFormalArgumentListForGeneration current_mFormalArgumentListForGeneration (LOCATION_ARGS) const ;
  public : class GALGAS_instructionListIR current_mInstructionGenerationList (LOCATION_ARGS) const ;
  public : class GALGAS_unifiedTypeMap_2D_proxy current_mResultType (LOCATION_ARGS) const ;
  public : class GALGAS_string current_mResultVarName (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_functionMapIR_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_functionMapIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Class for element of '@functionMapIR' map                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_functionMapIR : public cMapElement {
//--- Map attributes
  public : GALGAS_funcFormalArgumentListForGeneration mAttribute_mFormalArgumentListForGeneration ;
  public : GALGAS_instructionListIR mAttribute_mInstructionGenerationList ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mResultType ;
  public : GALGAS_string mAttribute_mResultVarName ;

//--- Constructor
  public : cMapElement_functionMapIR (const GALGAS_lstring & inKey,
                                      const GALGAS_funcFormalArgumentListForGeneration & in_mFormalArgumentListForGeneration,
                                      const GALGAS_instructionListIR & in_mInstructionGenerationList,
                                      const GALGAS_unifiedTypeMap_2D_proxy & in_mResultType,
                                      const GALGAS_string & in_mResultVarName
                                      COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @functionMapIR_2D_element struct                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_functionMapIR_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_funcFormalArgumentListForGeneration mAttribute_mFormalArgumentListForGeneration ;
  public : GALGAS_instructionListIR mAttribute_mInstructionGenerationList ;
  public : GALGAS_unifiedTypeMap_2D_proxy mAttribute_mResultType ;
  public : GALGAS_string mAttribute_mResultVarName ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_functionMapIR_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_functionMapIR_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_functionMapIR_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_functionMapIR_2D_element (const GALGAS_lstring & in_lkey,
                                            const GALGAS_funcFormalArgumentListForGeneration & in_mFormalArgumentListForGeneration,
                                            const GALGAS_instructionListIR & in_mInstructionGenerationList,
                                            const GALGAS_unifiedTypeMap_2D_proxy & in_mResultType,
                                            const GALGAS_string & in_mResultVarName) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_functionMapIR_2D_element extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_functionMapIR_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                   const class GALGAS_funcFormalArgumentListForGeneration & inOperand1,
                                                                   const class GALGAS_instructionListIR & inOperand2,
                                                                   const class GALGAS_unifiedTypeMap_2D_proxy & inOperand3,
                                                                   const class GALGAS_string & inOperand4
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_functionMapIR_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_funcFormalArgumentListForGeneration reader_mFormalArgumentListForGeneration (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_instructionListIR reader_mInstructionGenerationList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_unifiedTypeMap_2D_proxy reader_mResultType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_mResultVarName (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_functionMapIR_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_functionMapIR_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @typeMapIR map                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_typeMapIR ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_typeMapIR_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_typeMapIR : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_typeMapIR (void) ;

//--------------------------------- Handle copy
  public : GALGAS_typeMapIR (const GALGAS_typeMapIR & inSource) ;
  public : GALGAS_typeMapIR & operator = (const GALGAS_typeMapIR & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeMapIR extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_typeMapIR constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_typeMapIR constructor_mapWithMapToOverride (const class GALGAS_typeMapIR & inOperand0
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_abstractTypeIR & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_abstractTypeIR constinArgument1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMTypeForKey (class GALGAS_abstractTypeIR constinArgument0,
                                                          class GALGAS_string constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_abstractTypeIR & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_abstractTypeIR reader_mTypeForKey (const class GALGAS_string & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typeMapIR reader_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_typeMapIR * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_typeMapIR ;
 
} ; // End of GALGAS_typeMapIR class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_typeMapIR : public cGenericAbstractEnumerator {
  public : cEnumerator_typeMapIR (const GALGAS_typeMapIR & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_abstractTypeIR current_mType (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_typeMapIR_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeMapIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @abstractTypeIR class                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_abstractTypeIR : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_abstractTypeIR (void) ;

//---
  public : inline const class cPtr_abstractTypeIR * ptr (void) const { return (const cPtr_abstractTypeIR *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_abstractTypeIR (const cPtr_abstractTypeIR * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_abstractTypeIR extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_abstractTypeIR & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_abstractTypeIR class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_abstractTypeIR ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Class for element of '@typeMapIR' map                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_typeMapIR : public cMapElement {
//--- Map attributes
  public : GALGAS_abstractTypeIR mAttribute_mType ;

//--- Constructor
  public : cMapElement_typeMapIR (const GALGAS_lstring & inKey,
                                  const GALGAS_abstractTypeIR & in_mType
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @typeMapIR_2D_element struct                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_typeMapIR_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_abstractTypeIR mAttribute_mType ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_typeMapIR_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_typeMapIR_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_typeMapIR_2D_element (const GALGAS_lstring & in_lkey,
                                        const GALGAS_abstractTypeIR & in_mType) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeMapIR_2D_element extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_typeMapIR_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                               const class GALGAS_abstractTypeIR & inOperand1
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeMapIR_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_abstractTypeIR reader_mType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeMapIR_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeMapIR_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//  GRAMMAR plm_grammar
//---------------------------------------------------------------------------------------------------------------------*

class cGrammar_plm_5F_grammar : public cParser_common_5F_syntax,
                                public cParser_plm_5F_specific_5F_syntax {
//------------------------------------- 'declaration' non terminal
//--- 'parse' label
  public : virtual void nt_declaration_parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_declaration_ (GALGAS_ast & ioArgument0,
                                         C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression' non terminal
//--- 'parse' label
  public : virtual void nt_expression_parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_ (GALGAS_expressionAST & outArgument0,
                                        C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression_1' non terminal
//--- 'parse' label
  public : virtual void nt_expression_5F__31__parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_5F__31__ (GALGAS_expressionAST & outArgument0,
                                                C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression_10' non terminal
//--- 'parse' label
  public : virtual void nt_expression_5F__31__30__parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_5F__31__30__ (GALGAS_expressionAST & outArgument0,
                                                    C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression_11' non terminal
//--- 'parse' label
  public : virtual void nt_expression_5F__31__31__parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_5F__31__31__ (GALGAS_expressionAST & outArgument0,
                                                    C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression_12' non terminal
//--- 'parse' label
  public : virtual void nt_expression_5F__31__32__parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_5F__31__32__ (GALGAS_expressionAST & outArgument0,
                                                    C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression_2' non terminal
//--- 'parse' label
  public : virtual void nt_expression_5F__32__parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_5F__32__ (GALGAS_expressionAST & outArgument0,
                                                C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression_3' non terminal
//--- 'parse' label
  public : virtual void nt_expression_5F__33__parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_5F__33__ (GALGAS_expressionAST & outArgument0,
                                                C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression_4' non terminal
//--- 'parse' label
  public : virtual void nt_expression_5F__34__parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_5F__34__ (GALGAS_expressionAST & outArgument0,
                                                C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression_5' non terminal
//--- 'parse' label
  public : virtual void nt_expression_5F__35__parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_5F__35__ (GALGAS_expressionAST & outArgument0,
                                                C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression_6' non terminal
//--- 'parse' label
  public : virtual void nt_expression_5F__36__parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_5F__36__ (GALGAS_expressionAST & outArgument0,
                                                C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression_7' non terminal
//--- 'parse' label
  public : virtual void nt_expression_5F__37__parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_5F__37__ (GALGAS_expressionAST & outArgument0,
                                                C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression_8' non terminal
//--- 'parse' label
  public : virtual void nt_expression_5F__38__parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_5F__38__ (GALGAS_expressionAST & outArgument0,
                                                C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'expression_9' non terminal
//--- 'parse' label
  public : virtual void nt_expression_5F__39__parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_5F__39__ (GALGAS_expressionAST & outArgument0,
                                                C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'if_instruction' non terminal
//--- 'parse' label
  public : virtual void nt_if_5F_instruction_parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_if_5F_instruction_ (GALGAS_ifInstructionAST & outArgument0,
                                               GALGAS_labelMap & ioArgument1,
                                               const GALGAS_lstring inArgument2,
                                               C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'instruction' non terminal
//--- 'parse' label
  public : virtual void nt_instruction_parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_instruction_ (GALGAS_instructionListAST & ioArgument0,
                                         GALGAS_labelMap & ioArgument1,
                                         C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'instructionList' non terminal
//--- 'parse' label
  public : virtual void nt_instructionList_parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_instructionList_ (GALGAS_instructionListAST & outArgument0,
                                             GALGAS_labelMap & ioArgument1,
                                             C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'primary' non terminal
//--- 'parse' label
  public : virtual void nt_primary_parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_primary_ (GALGAS_expressionAST & outArgument0,
                                     C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'procedure' non terminal
//--- 'parse' label
  public : virtual void nt_procedure_parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_procedure_ (const GALGAS_procedureKindAST inArgument0,
                                       GALGAS_procedureDeclarationListAST & ioArgument1,
                                       C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'procedure_formal_arguments' non terminal
//--- 'parse' label
  public : virtual void nt_procedure_5F_formal_5F_arguments_parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_procedure_5F_formal_5F_arguments_ (GALGAS_procFormalArgumentList & outArgument0,
                                                              C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'procedure_header' non terminal
//--- 'parse' label
  public : virtual void nt_procedure_5F_header_parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_procedure_5F_header_ (GALGAS_lstringlist & outArgument0,
                                                 GALGAS_lstring & outArgument1,
                                                 GALGAS_lstringlist & outArgument2,
                                                 GALGAS_procFormalArgumentList & outArgument3,
                                                 C_Lexique_plm_5F_lexique * inCompiler) ;

//------------------------------------- 'start_symbol' non terminal
//--- 'parse' label
  public : virtual void nt_start_5F_symbol_parse (C_Lexique_plm_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_start_5F_symbol_ (GALGAS_ast & ioArgument0,
                                             GALGAS_lstringlist & outArgument1,
                                             GALGAS_location & outArgument2,
                                             C_Lexique_plm_5F_lexique * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName,
                                                   GALGAS_ast & ioArgument0,
                                                   GALGAS_lstringlist & outArgument1,
                                                   GALGAS_location & outArgument2
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString,
                                                     GALGAS_ast & ioArgument0,
                                                     GALGAS_lstringlist & outArgument1,
                                                     GALGAS_location & outArgument2
                                                     COMMA_LOCATION_ARGS) ;

//--- Indexing
  public : static void performIndexing (C_Compiler * inCompiler,
                                        const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public : static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                   const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public : static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

  public : virtual int32_t select_common_5F_syntax_0 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_1 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_2 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_3 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_4 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_5 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_6 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_7 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_8 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_9 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_10 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_11 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_12 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_13 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_14 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_15 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_16 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_17 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_18 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_19 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_20 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_21 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_22 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_23 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_24 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_25 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_26 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_27 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_28 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_29 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_30 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_31 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_32 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_33 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_34 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_35 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_36 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_37 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_38 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_39 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_40 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_41 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_42 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_43 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_44 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_45 (C_Lexique_plm_5F_lexique *) ;

  public : virtual int32_t select_common_5F_syntax_46 (C_Lexique_plm_5F_lexique *) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
#endif
