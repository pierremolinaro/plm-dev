#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-9.h"


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST_2D_element::GALGAS_extensionDeclarationListAST_2D_element (void) :
mAttribute_mTypeName (),
mAttribute_mProcedureDeclarationListAST (),
mAttribute_mFieldList () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST_2D_element::~ GALGAS_extensionDeclarationListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST_2D_element::GALGAS_extensionDeclarationListAST_2D_element (const GALGAS_lstring & inOperand0,
                                                                                              const GALGAS_procedureDeclarationListAST & inOperand1,
                                                                                              const GALGAS_structureFieldListAST & inOperand2) :
mAttribute_mTypeName (inOperand0),
mAttribute_mProcedureDeclarationListAST (inOperand1),
mAttribute_mFieldList (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST_2D_element GALGAS_extensionDeclarationListAST_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_extensionDeclarationListAST_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_procedureDeclarationListAST::constructor_emptyList (HERE),
                                                        GALGAS_structureFieldListAST::constructor_emptyList (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST_2D_element GALGAS_extensionDeclarationListAST_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                              const GALGAS_procedureDeclarationListAST & inOperand1,
                                                                                                              const GALGAS_structureFieldListAST & inOperand2 
                                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_extensionDeclarationListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_extensionDeclarationListAST_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_extensionDeclarationListAST_2D_element::objectCompare (const GALGAS_extensionDeclarationListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mTypeName.objectCompare (inOperand.mAttribute_mTypeName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mProcedureDeclarationListAST.objectCompare (inOperand.mAttribute_mProcedureDeclarationListAST) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mFieldList.objectCompare (inOperand.mAttribute_mFieldList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_extensionDeclarationListAST_2D_element::isValid (void) const {
  return mAttribute_mTypeName.isValid () && mAttribute_mProcedureDeclarationListAST.isValid () && mAttribute_mFieldList.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extensionDeclarationListAST_2D_element::drop (void) {
  mAttribute_mTypeName.drop () ;
  mAttribute_mProcedureDeclarationListAST.drop () ;
  mAttribute_mFieldList.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extensionDeclarationListAST_2D_element::description (C_String & ioString,
                                                                 const int32_t inIndentation) const {
  ioString << "<struct @extensionDeclarationListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mTypeName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mProcedureDeclarationListAST.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mFieldList.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_extensionDeclarationListAST_2D_element::getter_mTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureDeclarationListAST GALGAS_extensionDeclarationListAST_2D_element::getter_mProcedureDeclarationListAST (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mProcedureDeclarationListAST ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_structureFieldListAST GALGAS_extensionDeclarationListAST_2D_element::getter_mFieldList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mFieldList ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @extensionDeclarationListAST-element type                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_extensionDeclarationListAST_2D_element ("extensionDeclarationListAST-element",
                                                               NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_extensionDeclarationListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_extensionDeclarationListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_extensionDeclarationListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_extensionDeclarationListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extensionDeclarationListAST_2D_element GALGAS_extensionDeclarationListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_extensionDeclarationListAST_2D_element result ;
  const GALGAS_extensionDeclarationListAST_2D_element * p = (const GALGAS_extensionDeclarationListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_extensionDeclarationListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("extensionDeclarationListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterNameList_2D_element::GALGAS_controlRegisterNameList_2D_element (void) :
mAttribute_mRegisterName (),
mAttribute_mAttributeList (),
mAttribute_mRegisterAddress () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterNameList_2D_element::~ GALGAS_controlRegisterNameList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterNameList_2D_element::GALGAS_controlRegisterNameList_2D_element (const GALGAS_lstring & inOperand0,
                                                                                      const GALGAS_lstringlist & inOperand1,
                                                                                      const GALGAS_lbigint & inOperand2) :
mAttribute_mRegisterName (inOperand0),
mAttribute_mAttributeList (inOperand1),
mAttribute_mRegisterAddress (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterNameList_2D_element GALGAS_controlRegisterNameList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_controlRegisterNameList_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                    GALGAS_lstringlist::constructor_emptyList (HERE),
                                                    GALGAS_lbigint::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterNameList_2D_element GALGAS_controlRegisterNameList_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                      const GALGAS_lstringlist & inOperand1,
                                                                                                      const GALGAS_lbigint & inOperand2 
                                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_controlRegisterNameList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_controlRegisterNameList_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_controlRegisterNameList_2D_element::objectCompare (const GALGAS_controlRegisterNameList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mRegisterName.objectCompare (inOperand.mAttribute_mRegisterName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mAttributeList.objectCompare (inOperand.mAttribute_mAttributeList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mRegisterAddress.objectCompare (inOperand.mAttribute_mRegisterAddress) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_controlRegisterNameList_2D_element::isValid (void) const {
  return mAttribute_mRegisterName.isValid () && mAttribute_mAttributeList.isValid () && mAttribute_mRegisterAddress.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterNameList_2D_element::drop (void) {
  mAttribute_mRegisterName.drop () ;
  mAttribute_mAttributeList.drop () ;
  mAttribute_mRegisterAddress.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterNameList_2D_element::description (C_String & ioString,
                                                             const int32_t inIndentation) const {
  ioString << "<struct @controlRegisterNameList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mRegisterName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mAttributeList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mRegisterAddress.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_controlRegisterNameList_2D_element::getter_mRegisterName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_controlRegisterNameList_2D_element::getter_mAttributeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint GALGAS_controlRegisterNameList_2D_element::getter_mRegisterAddress (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterAddress ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @controlRegisterNameList-element type                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_controlRegisterNameList_2D_element ("controlRegisterNameList-element",
                                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_controlRegisterNameList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_controlRegisterNameList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_controlRegisterNameList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_controlRegisterNameList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterNameList_2D_element GALGAS_controlRegisterNameList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_controlRegisterNameList_2D_element result ;
  const GALGAS_controlRegisterNameList_2D_element * p = (const GALGAS_controlRegisterNameList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_controlRegisterNameList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("controlRegisterNameList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST_2D_element::GALGAS_controlRegisterDeclarationListAST_2D_element (void) :
mAttribute_mRegisterNameList (),
mAttribute_mRegisterTypeName (),
mAttribute_mRegisterBitSliceList () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST_2D_element::~ GALGAS_controlRegisterDeclarationListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST_2D_element::GALGAS_controlRegisterDeclarationListAST_2D_element (const GALGAS_controlRegisterNameList & inOperand0,
                                                                                                          const GALGAS_lstring & inOperand1,
                                                                                                          const GALGAS_controlRegisterBitSliceList & inOperand2) :
mAttribute_mRegisterNameList (inOperand0),
mAttribute_mRegisterTypeName (inOperand1),
mAttribute_mRegisterBitSliceList (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST_2D_element GALGAS_controlRegisterDeclarationListAST_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_controlRegisterDeclarationListAST_2D_element (GALGAS_controlRegisterNameList::constructor_emptyList (HERE),
                                                              GALGAS_lstring::constructor_default (HERE),
                                                              GALGAS_controlRegisterBitSliceList::constructor_emptyList (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST_2D_element GALGAS_controlRegisterDeclarationListAST_2D_element::constructor_new (const GALGAS_controlRegisterNameList & inOperand0,
                                                                                                                          const GALGAS_lstring & inOperand1,
                                                                                                                          const GALGAS_controlRegisterBitSliceList & inOperand2 
                                                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_controlRegisterDeclarationListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_controlRegisterDeclarationListAST_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_controlRegisterDeclarationListAST_2D_element::objectCompare (const GALGAS_controlRegisterDeclarationListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mRegisterNameList.objectCompare (inOperand.mAttribute_mRegisterNameList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mRegisterTypeName.objectCompare (inOperand.mAttribute_mRegisterTypeName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mRegisterBitSliceList.objectCompare (inOperand.mAttribute_mRegisterBitSliceList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_controlRegisterDeclarationListAST_2D_element::isValid (void) const {
  return mAttribute_mRegisterNameList.isValid () && mAttribute_mRegisterTypeName.isValid () && mAttribute_mRegisterBitSliceList.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterDeclarationListAST_2D_element::drop (void) {
  mAttribute_mRegisterNameList.drop () ;
  mAttribute_mRegisterTypeName.drop () ;
  mAttribute_mRegisterBitSliceList.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterDeclarationListAST_2D_element::description (C_String & ioString,
                                                                       const int32_t inIndentation) const {
  ioString << "<struct @controlRegisterDeclarationListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mRegisterNameList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mRegisterTypeName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mRegisterBitSliceList.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterNameList GALGAS_controlRegisterDeclarationListAST_2D_element::getter_mRegisterNameList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterNameList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_controlRegisterDeclarationListAST_2D_element::getter_mRegisterTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceList GALGAS_controlRegisterDeclarationListAST_2D_element::getter_mRegisterBitSliceList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterBitSliceList ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   @controlRegisterDeclarationListAST-element type                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_controlRegisterDeclarationListAST_2D_element ("controlRegisterDeclarationListAST-element",
                                                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_controlRegisterDeclarationListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_controlRegisterDeclarationListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_controlRegisterDeclarationListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_controlRegisterDeclarationListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterDeclarationListAST_2D_element GALGAS_controlRegisterDeclarationListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                                        C_Compiler * inCompiler
                                                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_controlRegisterDeclarationListAST_2D_element result ;
  const GALGAS_controlRegisterDeclarationListAST_2D_element * p = (const GALGAS_controlRegisterDeclarationListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_controlRegisterDeclarationListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("controlRegisterDeclarationListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceList_2D_element::GALGAS_controlRegisterBitSliceList_2D_element (void) :
mAttribute_mRegisterBitSlice () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceList_2D_element::~ GALGAS_controlRegisterBitSliceList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceList_2D_element::GALGAS_controlRegisterBitSliceList_2D_element (const GALGAS_controlRegisterBitSlice & inOperand0) :
mAttribute_mRegisterBitSlice (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceList_2D_element GALGAS_controlRegisterBitSliceList_2D_element::constructor_new (const GALGAS_controlRegisterBitSlice & inOperand0 
                                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_controlRegisterBitSliceList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_controlRegisterBitSliceList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_controlRegisterBitSliceList_2D_element::objectCompare (const GALGAS_controlRegisterBitSliceList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mRegisterBitSlice.objectCompare (inOperand.mAttribute_mRegisterBitSlice) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_controlRegisterBitSliceList_2D_element::isValid (void) const {
  return mAttribute_mRegisterBitSlice.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterBitSliceList_2D_element::drop (void) {
  mAttribute_mRegisterBitSlice.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterBitSliceList_2D_element::description (C_String & ioString,
                                                                 const int32_t inIndentation) const {
  ioString << "<struct @controlRegisterBitSliceList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mRegisterBitSlice.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSlice GALGAS_controlRegisterBitSliceList_2D_element::getter_mRegisterBitSlice (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterBitSlice ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @controlRegisterBitSliceList-element type                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_controlRegisterBitSliceList_2D_element ("controlRegisterBitSliceList-element",
                                                               NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_controlRegisterBitSliceList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_controlRegisterBitSliceList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_controlRegisterBitSliceList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_controlRegisterBitSliceList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceList_2D_element GALGAS_controlRegisterBitSliceList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_controlRegisterBitSliceList_2D_element result ;
  const GALGAS_controlRegisterBitSliceList_2D_element * p = (const GALGAS_controlRegisterBitSliceList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_controlRegisterBitSliceList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("controlRegisterBitSliceList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldMap_2D_element::GALGAS_controlRegisterFieldMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mBitIndex (),
mAttribute_mBitCount () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldMap_2D_element::~ GALGAS_controlRegisterFieldMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldMap_2D_element::GALGAS_controlRegisterFieldMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                                      const GALGAS_uint & inOperand1,
                                                                                      const GALGAS_uint & inOperand2) :
mAttribute_lkey (inOperand0),
mAttribute_mBitIndex (inOperand1),
mAttribute_mBitCount (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldMap_2D_element GALGAS_controlRegisterFieldMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_controlRegisterFieldMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                    GALGAS_uint::constructor_default (HERE),
                                                    GALGAS_uint::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldMap_2D_element GALGAS_controlRegisterFieldMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                      const GALGAS_uint & inOperand1,
                                                                                                      const GALGAS_uint & inOperand2 
                                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_controlRegisterFieldMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_controlRegisterFieldMap_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_controlRegisterFieldMap_2D_element::objectCompare (const GALGAS_controlRegisterFieldMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mBitIndex.objectCompare (inOperand.mAttribute_mBitIndex) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mBitCount.objectCompare (inOperand.mAttribute_mBitCount) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_controlRegisterFieldMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mBitIndex.isValid () && mAttribute_mBitCount.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterFieldMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mBitIndex.drop () ;
  mAttribute_mBitCount.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterFieldMap_2D_element::description (C_String & ioString,
                                                             const int32_t inIndentation) const {
  ioString << "<struct @controlRegisterFieldMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mBitIndex.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mBitCount.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_controlRegisterFieldMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_controlRegisterFieldMap_2D_element::getter_mBitIndex (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mBitIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_controlRegisterFieldMap_2D_element::getter_mBitCount (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mBitCount ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @controlRegisterFieldMap-element type                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_controlRegisterFieldMap_2D_element ("controlRegisterFieldMap-element",
                                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_controlRegisterFieldMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_controlRegisterFieldMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_controlRegisterFieldMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_controlRegisterFieldMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldMap_2D_element GALGAS_controlRegisterFieldMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_controlRegisterFieldMap_2D_element result ;
  const GALGAS_controlRegisterFieldMap_2D_element * p = (const GALGAS_controlRegisterFieldMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_controlRegisterFieldMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("controlRegisterFieldMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceAccessMap_2D_element::GALGAS_controlRegisterBitSliceAccessMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mAccessOperator (),
mAttribute_mAccessRightOperand (),
mAttribute_mSubMap (),
mAttribute_mResultType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceAccessMap_2D_element::~ GALGAS_controlRegisterBitSliceAccessMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceAccessMap_2D_element::GALGAS_controlRegisterBitSliceAccessMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                                                        const GALGAS_llvmBinaryOperation & inOperand1,
                                                                                                        const GALGAS_bigint & inOperand2,
                                                                                                        const GALGAS_controlRegisterBitSliceAccessMap & inOperand3,
                                                                                                        const GALGAS_unifiedTypeMap_2D_proxy & inOperand4) :
mAttribute_lkey (inOperand0),
mAttribute_mAccessOperator (inOperand1),
mAttribute_mAccessRightOperand (inOperand2),
mAttribute_mSubMap (inOperand3),
mAttribute_mResultType (inOperand4) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceAccessMap_2D_element GALGAS_controlRegisterBitSliceAccessMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                                        const GALGAS_llvmBinaryOperation & inOperand1,
                                                                                                                        const GALGAS_bigint & inOperand2,
                                                                                                                        const GALGAS_controlRegisterBitSliceAccessMap & inOperand3,
                                                                                                                        const GALGAS_unifiedTypeMap_2D_proxy & inOperand4 
                                                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_controlRegisterBitSliceAccessMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid ()) {
    result = GALGAS_controlRegisterBitSliceAccessMap_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_controlRegisterBitSliceAccessMap_2D_element::objectCompare (const GALGAS_controlRegisterBitSliceAccessMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mAccessOperator.objectCompare (inOperand.mAttribute_mAccessOperator) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mAccessRightOperand.objectCompare (inOperand.mAttribute_mAccessRightOperand) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSubMap.objectCompare (inOperand.mAttribute_mSubMap) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mResultType.objectCompare (inOperand.mAttribute_mResultType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_controlRegisterBitSliceAccessMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mAccessOperator.isValid () && mAttribute_mAccessRightOperand.isValid () && mAttribute_mSubMap.isValid () && mAttribute_mResultType.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterBitSliceAccessMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mAccessOperator.drop () ;
  mAttribute_mAccessRightOperand.drop () ;
  mAttribute_mSubMap.drop () ;
  mAttribute_mResultType.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterBitSliceAccessMap_2D_element::description (C_String & ioString,
                                                                      const int32_t inIndentation) const {
  ioString << "<struct @controlRegisterBitSliceAccessMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mAccessOperator.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mAccessRightOperand.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSubMap.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mResultType.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_controlRegisterBitSliceAccessMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_llvmBinaryOperation GALGAS_controlRegisterBitSliceAccessMap_2D_element::getter_mAccessOperator (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAccessOperator ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_controlRegisterBitSliceAccessMap_2D_element::getter_mAccessRightOperand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAccessRightOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceAccessMap GALGAS_controlRegisterBitSliceAccessMap_2D_element::getter_mSubMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSubMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_controlRegisterBitSliceAccessMap_2D_element::getter_mResultType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mResultType ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   @controlRegisterBitSliceAccessMap-element type                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_controlRegisterBitSliceAccessMap_2D_element ("controlRegisterBitSliceAccessMap-element",
                                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_controlRegisterBitSliceAccessMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_controlRegisterBitSliceAccessMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_controlRegisterBitSliceAccessMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_controlRegisterBitSliceAccessMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceAccessMap_2D_element GALGAS_controlRegisterBitSliceAccessMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                                      C_Compiler * inCompiler
                                                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_controlRegisterBitSliceAccessMap_2D_element result ;
  const GALGAS_controlRegisterBitSliceAccessMap_2D_element * p = (const GALGAS_controlRegisterBitSliceAccessMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_controlRegisterBitSliceAccessMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("controlRegisterBitSliceAccessMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterMap_2D_element::GALGAS_controlRegisterMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mType (),
mAttribute_mIsReadOnly (),
mAttribute_mIsAccessibleInUserMode (),
mAttribute_mRegisterFieldAccessMap (),
mAttribute_mRegisterFieldMap (),
mAttribute_mAddress (),
mAttribute_mControlRegisterFieldList (),
mAttribute_mRegisterBitCount () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterMap_2D_element::~ GALGAS_controlRegisterMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterMap_2D_element::GALGAS_controlRegisterMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                            const GALGAS_bool & inOperand2,
                                                                            const GALGAS_bool & inOperand3,
                                                                            const GALGAS_controlRegisterBitSliceAccessMap & inOperand4,
                                                                            const GALGAS_controlRegisterFieldMap & inOperand5,
                                                                            const GALGAS_bigint & inOperand6,
                                                                            const GALGAS_controlRegisterFieldList & inOperand7,
                                                                            const GALGAS_uint & inOperand8) :
mAttribute_lkey (inOperand0),
mAttribute_mType (inOperand1),
mAttribute_mIsReadOnly (inOperand2),
mAttribute_mIsAccessibleInUserMode (inOperand3),
mAttribute_mRegisterFieldAccessMap (inOperand4),
mAttribute_mRegisterFieldMap (inOperand5),
mAttribute_mAddress (inOperand6),
mAttribute_mControlRegisterFieldList (inOperand7),
mAttribute_mRegisterBitCount (inOperand8) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterMap_2D_element GALGAS_controlRegisterMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_controlRegisterMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                               GALGAS_unifiedTypeMap_2D_proxy::constructor_null (HERE),
                                               GALGAS_bool::constructor_default (HERE),
                                               GALGAS_bool::constructor_default (HERE),
                                               GALGAS_controlRegisterBitSliceAccessMap::constructor_emptyMap (HERE),
                                               GALGAS_controlRegisterFieldMap::constructor_emptyMap (HERE),
                                               GALGAS_bigint::constructor_zero (HERE),
                                               GALGAS_controlRegisterFieldList::constructor_emptyList (HERE),
                                               GALGAS_uint::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterMap_2D_element GALGAS_controlRegisterMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                            const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                                            const GALGAS_bool & inOperand2,
                                                                                            const GALGAS_bool & inOperand3,
                                                                                            const GALGAS_controlRegisterBitSliceAccessMap & inOperand4,
                                                                                            const GALGAS_controlRegisterFieldMap & inOperand5,
                                                                                            const GALGAS_bigint & inOperand6,
                                                                                            const GALGAS_controlRegisterFieldList & inOperand7,
                                                                                            const GALGAS_uint & inOperand8 
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_controlRegisterMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid () && inOperand8.isValid ()) {
    result = GALGAS_controlRegisterMap_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7, inOperand8) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_controlRegisterMap_2D_element::objectCompare (const GALGAS_controlRegisterMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mType.objectCompare (inOperand.mAttribute_mType) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mIsReadOnly.objectCompare (inOperand.mAttribute_mIsReadOnly) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mIsAccessibleInUserMode.objectCompare (inOperand.mAttribute_mIsAccessibleInUserMode) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mRegisterFieldAccessMap.objectCompare (inOperand.mAttribute_mRegisterFieldAccessMap) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mRegisterFieldMap.objectCompare (inOperand.mAttribute_mRegisterFieldMap) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mAddress.objectCompare (inOperand.mAttribute_mAddress) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mControlRegisterFieldList.objectCompare (inOperand.mAttribute_mControlRegisterFieldList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mRegisterBitCount.objectCompare (inOperand.mAttribute_mRegisterBitCount) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_controlRegisterMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mType.isValid () && mAttribute_mIsReadOnly.isValid () && mAttribute_mIsAccessibleInUserMode.isValid () && mAttribute_mRegisterFieldAccessMap.isValid () && mAttribute_mRegisterFieldMap.isValid () && mAttribute_mAddress.isValid () && mAttribute_mControlRegisterFieldList.isValid () && mAttribute_mRegisterBitCount.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mType.drop () ;
  mAttribute_mIsReadOnly.drop () ;
  mAttribute_mIsAccessibleInUserMode.drop () ;
  mAttribute_mRegisterFieldAccessMap.drop () ;
  mAttribute_mRegisterFieldMap.drop () ;
  mAttribute_mAddress.drop () ;
  mAttribute_mControlRegisterFieldList.drop () ;
  mAttribute_mRegisterBitCount.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterMap_2D_element::description (C_String & ioString,
                                                        const int32_t inIndentation) const {
  ioString << "<struct @controlRegisterMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mType.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mIsReadOnly.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mIsAccessibleInUserMode.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mRegisterFieldAccessMap.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mRegisterFieldMap.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mAddress.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mControlRegisterFieldList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mRegisterBitCount.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_controlRegisterMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_controlRegisterMap_2D_element::getter_mType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_controlRegisterMap_2D_element::getter_mIsReadOnly (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIsReadOnly ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_controlRegisterMap_2D_element::getter_mIsAccessibleInUserMode (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIsAccessibleInUserMode ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceAccessMap GALGAS_controlRegisterMap_2D_element::getter_mRegisterFieldAccessMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterFieldAccessMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldMap GALGAS_controlRegisterMap_2D_element::getter_mRegisterFieldMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterFieldMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_controlRegisterMap_2D_element::getter_mAddress (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAddress ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldList GALGAS_controlRegisterMap_2D_element::getter_mControlRegisterFieldList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mControlRegisterFieldList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_controlRegisterMap_2D_element::getter_mRegisterBitCount (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterBitCount ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @controlRegisterMap-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_controlRegisterMap_2D_element ("controlRegisterMap-element",
                                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_controlRegisterMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_controlRegisterMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_controlRegisterMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_controlRegisterMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterMap_2D_element GALGAS_controlRegisterMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_controlRegisterMap_2D_element result ;
  const GALGAS_controlRegisterMap_2D_element * p = (const GALGAS_controlRegisterMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_controlRegisterMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("controlRegisterMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineList_2D_element::GALGAS_allowedRoutineList_2D_element (void) :
mAttribute_mHasWriteAccess (),
mAttribute_mReceiverTypeName (),
mAttribute_mRoutineName (),
mAttribute_mRoutineKind () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineList_2D_element::~ GALGAS_allowedRoutineList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineList_2D_element::GALGAS_allowedRoutineList_2D_element (const GALGAS_bool & inOperand0,
                                                                            const GALGAS_lstring & inOperand1,
                                                                            const GALGAS_lstring & inOperand2,
                                                                            const GALGAS_routineKind & inOperand3) :
mAttribute_mHasWriteAccess (inOperand0),
mAttribute_mReceiverTypeName (inOperand1),
mAttribute_mRoutineName (inOperand2),
mAttribute_mRoutineKind (inOperand3) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineList_2D_element GALGAS_allowedRoutineList_2D_element::constructor_new (const GALGAS_bool & inOperand0,
                                                                                            const GALGAS_lstring & inOperand1,
                                                                                            const GALGAS_lstring & inOperand2,
                                                                                            const GALGAS_routineKind & inOperand3 
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_allowedRoutineList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    result = GALGAS_allowedRoutineList_2D_element (inOperand0, inOperand1, inOperand2, inOperand3) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_allowedRoutineList_2D_element::objectCompare (const GALGAS_allowedRoutineList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mHasWriteAccess.objectCompare (inOperand.mAttribute_mHasWriteAccess) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mReceiverTypeName.objectCompare (inOperand.mAttribute_mReceiverTypeName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mRoutineName.objectCompare (inOperand.mAttribute_mRoutineName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mRoutineKind.objectCompare (inOperand.mAttribute_mRoutineKind) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_allowedRoutineList_2D_element::isValid (void) const {
  return mAttribute_mHasWriteAccess.isValid () && mAttribute_mReceiverTypeName.isValid () && mAttribute_mRoutineName.isValid () && mAttribute_mRoutineKind.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedRoutineList_2D_element::drop (void) {
  mAttribute_mHasWriteAccess.drop () ;
  mAttribute_mReceiverTypeName.drop () ;
  mAttribute_mRoutineName.drop () ;
  mAttribute_mRoutineKind.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedRoutineList_2D_element::description (C_String & ioString,
                                                        const int32_t inIndentation) const {
  ioString << "<struct @allowedRoutineList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mHasWriteAccess.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mReceiverTypeName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mRoutineName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mRoutineKind.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_allowedRoutineList_2D_element::getter_mHasWriteAccess (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mHasWriteAccess ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_allowedRoutineList_2D_element::getter_mReceiverTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mReceiverTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_allowedRoutineList_2D_element::getter_mRoutineName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRoutineName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineKind GALGAS_allowedRoutineList_2D_element::getter_mRoutineKind (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRoutineKind ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @allowedRoutineList-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_allowedRoutineList_2D_element ("allowedRoutineList-element",
                                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_allowedRoutineList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_allowedRoutineList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_allowedRoutineList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_allowedRoutineList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineList_2D_element GALGAS_allowedRoutineList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_allowedRoutineList_2D_element result ;
  const GALGAS_allowedRoutineList_2D_element * p = (const GALGAS_allowedRoutineList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_allowedRoutineList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("allowedRoutineList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedInitList_2D_element::GALGAS_allowedInitList_2D_element (void) :
mAttribute_mHasWriteAccess (),
mAttribute_mInitPriority () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedInitList_2D_element::~ GALGAS_allowedInitList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedInitList_2D_element::GALGAS_allowedInitList_2D_element (const GALGAS_bool & inOperand0,
                                                                      const GALGAS_lbigint & inOperand1) :
mAttribute_mHasWriteAccess (inOperand0),
mAttribute_mInitPriority (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedInitList_2D_element GALGAS_allowedInitList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_allowedInitList_2D_element (GALGAS_bool::constructor_default (HERE),
                                            GALGAS_lbigint::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedInitList_2D_element GALGAS_allowedInitList_2D_element::constructor_new (const GALGAS_bool & inOperand0,
                                                                                      const GALGAS_lbigint & inOperand1 
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_allowedInitList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_allowedInitList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_allowedInitList_2D_element::objectCompare (const GALGAS_allowedInitList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mHasWriteAccess.objectCompare (inOperand.mAttribute_mHasWriteAccess) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mInitPriority.objectCompare (inOperand.mAttribute_mInitPriority) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_allowedInitList_2D_element::isValid (void) const {
  return mAttribute_mHasWriteAccess.isValid () && mAttribute_mInitPriority.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedInitList_2D_element::drop (void) {
  mAttribute_mHasWriteAccess.drop () ;
  mAttribute_mInitPriority.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedInitList_2D_element::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "<struct @allowedInitList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mHasWriteAccess.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mInitPriority.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_allowedInitList_2D_element::getter_mHasWriteAccess (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mHasWriteAccess ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint GALGAS_allowedInitList_2D_element::getter_mInitPriority (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInitPriority ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @allowedInitList-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_allowedInitList_2D_element ("allowedInitList-element",
                                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_allowedInitList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_allowedInitList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_allowedInitList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_allowedInitList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedInitList_2D_element GALGAS_allowedInitList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_allowedInitList_2D_element result ;
  const GALGAS_allowedInitList_2D_element * p = (const GALGAS_allowedInitList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_allowedInitList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("allowedInitList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedPanicList_2D_element::GALGAS_allowedPanicList_2D_element (void) :
mAttribute_mHasWriteAccess (),
mAttribute_mPanicName (),
mAttribute_mPanicPriority () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedPanicList_2D_element::~ GALGAS_allowedPanicList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedPanicList_2D_element::GALGAS_allowedPanicList_2D_element (const GALGAS_bool & inOperand0,
                                                                        const GALGAS_lstring & inOperand1,
                                                                        const GALGAS_lbigint & inOperand2) :
mAttribute_mHasWriteAccess (inOperand0),
mAttribute_mPanicName (inOperand1),
mAttribute_mPanicPriority (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedPanicList_2D_element GALGAS_allowedPanicList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_allowedPanicList_2D_element (GALGAS_bool::constructor_default (HERE),
                                             GALGAS_lstring::constructor_default (HERE),
                                             GALGAS_lbigint::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedPanicList_2D_element GALGAS_allowedPanicList_2D_element::constructor_new (const GALGAS_bool & inOperand0,
                                                                                        const GALGAS_lstring & inOperand1,
                                                                                        const GALGAS_lbigint & inOperand2 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_allowedPanicList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_allowedPanicList_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_allowedPanicList_2D_element::objectCompare (const GALGAS_allowedPanicList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mHasWriteAccess.objectCompare (inOperand.mAttribute_mHasWriteAccess) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPanicName.objectCompare (inOperand.mAttribute_mPanicName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPanicPriority.objectCompare (inOperand.mAttribute_mPanicPriority) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_allowedPanicList_2D_element::isValid (void) const {
  return mAttribute_mHasWriteAccess.isValid () && mAttribute_mPanicName.isValid () && mAttribute_mPanicPriority.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedPanicList_2D_element::drop (void) {
  mAttribute_mHasWriteAccess.drop () ;
  mAttribute_mPanicName.drop () ;
  mAttribute_mPanicPriority.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedPanicList_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @allowedPanicList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mHasWriteAccess.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPanicName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPanicPriority.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_allowedPanicList_2D_element::getter_mHasWriteAccess (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mHasWriteAccess ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_allowedPanicList_2D_element::getter_mPanicName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPanicName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint GALGAS_allowedPanicList_2D_element::getter_mPanicPriority (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPanicPriority ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @allowedPanicList-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_allowedPanicList_2D_element ("allowedPanicList-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_allowedPanicList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_allowedPanicList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_allowedPanicList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_allowedPanicList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedPanicList_2D_element GALGAS_allowedPanicList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_allowedPanicList_2D_element result ;
  const GALGAS_allowedPanicList_2D_element * p = (const GALGAS_allowedPanicList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_allowedPanicList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("allowedPanicList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardList_2D_element::GALGAS_allowedGuardList_2D_element (void) :
mAttribute_mOptionalTypeName (),
mAttribute_mGuardName () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardList_2D_element::~ GALGAS_allowedGuardList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardList_2D_element::GALGAS_allowedGuardList_2D_element (const GALGAS_lstring & inOperand0,
                                                                        const GALGAS_lstring & inOperand1) :
mAttribute_mOptionalTypeName (inOperand0),
mAttribute_mGuardName (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardList_2D_element GALGAS_allowedGuardList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_allowedGuardList_2D_element (GALGAS_lstring::constructor_default (HERE),
                                             GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardList_2D_element GALGAS_allowedGuardList_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                        const GALGAS_lstring & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_allowedGuardList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_allowedGuardList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_allowedGuardList_2D_element::objectCompare (const GALGAS_allowedGuardList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mOptionalTypeName.objectCompare (inOperand.mAttribute_mOptionalTypeName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mGuardName.objectCompare (inOperand.mAttribute_mGuardName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_allowedGuardList_2D_element::isValid (void) const {
  return mAttribute_mOptionalTypeName.isValid () && mAttribute_mGuardName.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedGuardList_2D_element::drop (void) {
  mAttribute_mOptionalTypeName.drop () ;
  mAttribute_mGuardName.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedGuardList_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @allowedGuardList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mOptionalTypeName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mGuardName.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_allowedGuardList_2D_element::getter_mOptionalTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOptionalTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_allowedGuardList_2D_element::getter_mGuardName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGuardName ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @allowedGuardList-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_allowedGuardList_2D_element ("allowedGuardList-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_allowedGuardList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_allowedGuardList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_allowedGuardList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_allowedGuardList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardList_2D_element GALGAS_allowedGuardList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_allowedGuardList_2D_element result ;
  const GALGAS_allowedGuardList_2D_element * p = (const GALGAS_allowedGuardList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_allowedGuardList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("allowedGuardList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRList_2D_element::GALGAS_allowedISRList_2D_element (void) :
mAttribute_mHasWriteAccess (),
mAttribute_mISRName () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRList_2D_element::~ GALGAS_allowedISRList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRList_2D_element::GALGAS_allowedISRList_2D_element (const GALGAS_bool & inOperand0,
                                                                    const GALGAS_lstring & inOperand1) :
mAttribute_mHasWriteAccess (inOperand0),
mAttribute_mISRName (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRList_2D_element GALGAS_allowedISRList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_allowedISRList_2D_element (GALGAS_bool::constructor_default (HERE),
                                           GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRList_2D_element GALGAS_allowedISRList_2D_element::constructor_new (const GALGAS_bool & inOperand0,
                                                                                    const GALGAS_lstring & inOperand1 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_allowedISRList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_allowedISRList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_allowedISRList_2D_element::objectCompare (const GALGAS_allowedISRList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mHasWriteAccess.objectCompare (inOperand.mAttribute_mHasWriteAccess) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mISRName.objectCompare (inOperand.mAttribute_mISRName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_allowedISRList_2D_element::isValid (void) const {
  return mAttribute_mHasWriteAccess.isValid () && mAttribute_mISRName.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedISRList_2D_element::drop (void) {
  mAttribute_mHasWriteAccess.drop () ;
  mAttribute_mISRName.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedISRList_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @allowedISRList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mHasWriteAccess.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mISRName.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_allowedISRList_2D_element::getter_mHasWriteAccess (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mHasWriteAccess ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_allowedISRList_2D_element::getter_mISRName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mISRName ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @allowedISRList-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_allowedISRList_2D_element ("allowedISRList-element",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_allowedISRList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_allowedISRList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_allowedISRList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_allowedISRList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRList_2D_element GALGAS_allowedISRList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_allowedISRList_2D_element result ;
  const GALGAS_allowedISRList_2D_element * p = (const GALGAS_allowedISRList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_allowedISRList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("allowedISRList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineMap_2D_element::GALGAS_allowedRoutineMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mHasWriteAccess () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineMap_2D_element::~ GALGAS_allowedRoutineMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineMap_2D_element::GALGAS_allowedRoutineMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_bool & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_mHasWriteAccess (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineMap_2D_element GALGAS_allowedRoutineMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_allowedRoutineMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                              GALGAS_bool::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineMap_2D_element GALGAS_allowedRoutineMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_bool & inOperand1 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_allowedRoutineMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_allowedRoutineMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_allowedRoutineMap_2D_element::objectCompare (const GALGAS_allowedRoutineMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mHasWriteAccess.objectCompare (inOperand.mAttribute_mHasWriteAccess) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_allowedRoutineMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mHasWriteAccess.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedRoutineMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mHasWriteAccess.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedRoutineMap_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @allowedRoutineMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mHasWriteAccess.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_allowedRoutineMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_allowedRoutineMap_2D_element::getter_mHasWriteAccess (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mHasWriteAccess ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @allowedRoutineMap-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_allowedRoutineMap_2D_element ("allowedRoutineMap-element",
                                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_allowedRoutineMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_allowedRoutineMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_allowedRoutineMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_allowedRoutineMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineMap_2D_element GALGAS_allowedRoutineMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_allowedRoutineMap_2D_element result ;
  const GALGAS_allowedRoutineMap_2D_element * p = (const GALGAS_allowedRoutineMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_allowedRoutineMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("allowedRoutineMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRMap_2D_element::GALGAS_allowedISRMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mHasWriteAccess () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRMap_2D_element::~ GALGAS_allowedISRMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRMap_2D_element::GALGAS_allowedISRMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                  const GALGAS_bool & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_mHasWriteAccess (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRMap_2D_element GALGAS_allowedISRMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_allowedISRMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                          GALGAS_bool::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRMap_2D_element GALGAS_allowedISRMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_bool & inOperand1 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_allowedISRMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_allowedISRMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_allowedISRMap_2D_element::objectCompare (const GALGAS_allowedISRMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mHasWriteAccess.objectCompare (inOperand.mAttribute_mHasWriteAccess) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_allowedISRMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mHasWriteAccess.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedISRMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mHasWriteAccess.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedISRMap_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @allowedISRMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mHasWriteAccess.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_allowedISRMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_allowedISRMap_2D_element::getter_mHasWriteAccess (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mHasWriteAccess ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @allowedISRMap-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_allowedISRMap_2D_element ("allowedISRMap-element",
                                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_allowedISRMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_allowedISRMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_allowedISRMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_allowedISRMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRMap_2D_element GALGAS_allowedISRMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_allowedISRMap_2D_element result ;
  const GALGAS_allowedISRMap_2D_element * p = (const GALGAS_allowedISRMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_allowedISRMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("allowedISRMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitListAST_2D_element::GALGAS_taskInitListAST_2D_element (void) :
mAttribute_mTaskInitPriority (),
mAttribute_mTaskInitInstructionList (),
mAttribute_mEndOfTaskInitDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitListAST_2D_element::~ GALGAS_taskInitListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitListAST_2D_element::GALGAS_taskInitListAST_2D_element (const GALGAS_lbigint & inOperand0,
                                                                      const GALGAS_instructionListAST & inOperand1,
                                                                      const GALGAS_location & inOperand2) :
mAttribute_mTaskInitPriority (inOperand0),
mAttribute_mTaskInitInstructionList (inOperand1),
mAttribute_mEndOfTaskInitDeclaration (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitListAST_2D_element GALGAS_taskInitListAST_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_taskInitListAST_2D_element (GALGAS_lbigint::constructor_default (HERE),
                                            GALGAS_instructionListAST::constructor_emptyList (HERE),
                                            GALGAS_location::constructor_nowhere (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitListAST_2D_element GALGAS_taskInitListAST_2D_element::constructor_new (const GALGAS_lbigint & inOperand0,
                                                                                      const GALGAS_instructionListAST & inOperand1,
                                                                                      const GALGAS_location & inOperand2 
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_taskInitListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_taskInitListAST_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_taskInitListAST_2D_element::objectCompare (const GALGAS_taskInitListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mTaskInitPriority.objectCompare (inOperand.mAttribute_mTaskInitPriority) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mTaskInitInstructionList.objectCompare (inOperand.mAttribute_mTaskInitInstructionList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mEndOfTaskInitDeclaration.objectCompare (inOperand.mAttribute_mEndOfTaskInitDeclaration) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_taskInitListAST_2D_element::isValid (void) const {
  return mAttribute_mTaskInitPriority.isValid () && mAttribute_mTaskInitInstructionList.isValid () && mAttribute_mEndOfTaskInitDeclaration.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskInitListAST_2D_element::drop (void) {
  mAttribute_mTaskInitPriority.drop () ;
  mAttribute_mTaskInitInstructionList.drop () ;
  mAttribute_mEndOfTaskInitDeclaration.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskInitListAST_2D_element::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "<struct @taskInitListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mTaskInitPriority.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mTaskInitInstructionList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mEndOfTaskInitDeclaration.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint GALGAS_taskInitListAST_2D_element::getter_mTaskInitPriority (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTaskInitPriority ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_taskInitListAST_2D_element::getter_mTaskInitInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTaskInitInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_taskInitListAST_2D_element::getter_mEndOfTaskInitDeclaration (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfTaskInitDeclaration ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @taskInitListAST-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_taskInitListAST_2D_element ("taskInitListAST-element",
                                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_taskInitListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_taskInitListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_taskInitListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_taskInitListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitListAST_2D_element GALGAS_taskInitListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_taskInitListAST_2D_element result ;
  const GALGAS_taskInitListAST_2D_element * p = (const GALGAS_taskInitListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_taskInitListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("taskInitListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitSortedListAST_2D_element::GALGAS_taskInitSortedListAST_2D_element (void) :
mAttribute_mTaskInitPriority (),
mAttribute_mTaskInitInstructionList (),
mAttribute_mEndOfTaskInitDeclaration (),
mAttribute_mPriority () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitSortedListAST_2D_element::~ GALGAS_taskInitSortedListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitSortedListAST_2D_element::GALGAS_taskInitSortedListAST_2D_element (const GALGAS_lbigint & inOperand0,
                                                                                  const GALGAS_instructionListAST & inOperand1,
                                                                                  const GALGAS_location & inOperand2,
                                                                                  const GALGAS_bigint & inOperand3) :
mAttribute_mTaskInitPriority (inOperand0),
mAttribute_mTaskInitInstructionList (inOperand1),
mAttribute_mEndOfTaskInitDeclaration (inOperand2),
mAttribute_mPriority (inOperand3) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitSortedListAST_2D_element GALGAS_taskInitSortedListAST_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_taskInitSortedListAST_2D_element (GALGAS_lbigint::constructor_default (HERE),
                                                  GALGAS_instructionListAST::constructor_emptyList (HERE),
                                                  GALGAS_location::constructor_nowhere (HERE),
                                                  GALGAS_bigint::constructor_zero (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitSortedListAST_2D_element GALGAS_taskInitSortedListAST_2D_element::constructor_new (const GALGAS_lbigint & inOperand0,
                                                                                                  const GALGAS_instructionListAST & inOperand1,
                                                                                                  const GALGAS_location & inOperand2,
                                                                                                  const GALGAS_bigint & inOperand3 
                                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_taskInitSortedListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    result = GALGAS_taskInitSortedListAST_2D_element (inOperand0, inOperand1, inOperand2, inOperand3) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_taskInitSortedListAST_2D_element::objectCompare (const GALGAS_taskInitSortedListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mTaskInitPriority.objectCompare (inOperand.mAttribute_mTaskInitPriority) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mTaskInitInstructionList.objectCompare (inOperand.mAttribute_mTaskInitInstructionList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mEndOfTaskInitDeclaration.objectCompare (inOperand.mAttribute_mEndOfTaskInitDeclaration) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPriority.objectCompare (inOperand.mAttribute_mPriority) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_taskInitSortedListAST_2D_element::isValid (void) const {
  return mAttribute_mTaskInitPriority.isValid () && mAttribute_mTaskInitInstructionList.isValid () && mAttribute_mEndOfTaskInitDeclaration.isValid () && mAttribute_mPriority.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskInitSortedListAST_2D_element::drop (void) {
  mAttribute_mTaskInitPriority.drop () ;
  mAttribute_mTaskInitInstructionList.drop () ;
  mAttribute_mEndOfTaskInitDeclaration.drop () ;
  mAttribute_mPriority.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskInitSortedListAST_2D_element::description (C_String & ioString,
                                                           const int32_t inIndentation) const {
  ioString << "<struct @taskInitSortedListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mTaskInitPriority.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mTaskInitInstructionList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mEndOfTaskInitDeclaration.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPriority.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint GALGAS_taskInitSortedListAST_2D_element::getter_mTaskInitPriority (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTaskInitPriority ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_taskInitSortedListAST_2D_element::getter_mTaskInitInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTaskInitInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_taskInitSortedListAST_2D_element::getter_mEndOfTaskInitDeclaration (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfTaskInitDeclaration ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_taskInitSortedListAST_2D_element::getter_mPriority (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPriority ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @taskInitSortedListAST-element type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_taskInitSortedListAST_2D_element ("taskInitSortedListAST-element",
                                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_taskInitSortedListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_taskInitSortedListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_taskInitSortedListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_taskInitSortedListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskInitSortedListAST_2D_element GALGAS_taskInitSortedListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_taskInitSortedListAST_2D_element result ;
  const GALGAS_taskInitSortedListAST_2D_element * p = (const GALGAS_taskInitSortedListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_taskInitSortedListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("taskInitSortedListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskProcedureMap_2D_element::GALGAS_taskProcedureMap_2D_element (void) :
mAttribute_lkey () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskProcedureMap_2D_element::~ GALGAS_taskProcedureMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskProcedureMap_2D_element::GALGAS_taskProcedureMap_2D_element (const GALGAS_lstring & inOperand0) :
mAttribute_lkey (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskProcedureMap_2D_element GALGAS_taskProcedureMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_taskProcedureMap_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskProcedureMap_2D_element GALGAS_taskProcedureMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_taskProcedureMap_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_taskProcedureMap_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_taskProcedureMap_2D_element::objectCompare (const GALGAS_taskProcedureMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_taskProcedureMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskProcedureMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskProcedureMap_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @taskProcedureMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_taskProcedureMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @taskProcedureMap-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_taskProcedureMap_2D_element ("taskProcedureMap-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_taskProcedureMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_taskProcedureMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_taskProcedureMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_taskProcedureMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskProcedureMap_2D_element GALGAS_taskProcedureMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_taskProcedureMap_2D_element result ;
  const GALGAS_taskProcedureMap_2D_element * p = (const GALGAS_taskProcedureMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_taskProcedureMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("taskProcedureMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskMap_2D_element::GALGAS_taskMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mTaskProcedureMap () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskMap_2D_element::~ GALGAS_taskMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskMap_2D_element::GALGAS_taskMap_2D_element (const GALGAS_lstring & inOperand0,
                                                      const GALGAS_taskProcedureMap & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_mTaskProcedureMap (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskMap_2D_element GALGAS_taskMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_taskMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                    GALGAS_taskProcedureMap::constructor_emptyMap (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskMap_2D_element GALGAS_taskMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                      const GALGAS_taskProcedureMap & inOperand1 
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_taskMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_taskMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_taskMap_2D_element::objectCompare (const GALGAS_taskMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mTaskProcedureMap.objectCompare (inOperand.mAttribute_mTaskProcedureMap) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_taskMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mTaskProcedureMap.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mTaskProcedureMap.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskMap_2D_element::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "<struct @taskMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mTaskProcedureMap.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_taskMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskProcedureMap GALGAS_taskMap_2D_element::getter_mTaskProcedureMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTaskProcedureMap ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @taskMap-element type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_taskMap_2D_element ("taskMap-element",
                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_taskMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_taskMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_taskMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_taskMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskMap_2D_element GALGAS_taskMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_taskMap_2D_element result ;
  const GALGAS_taskMap_2D_element * p = (const GALGAS_taskMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_taskMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("taskMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskMapIR_2D_element::GALGAS_taskMapIR_2D_element (void) :
mAttribute_lkey (),
mAttribute_mTaskType (),
mAttribute_mPriority (),
mAttribute_mStackSize (),
mAttribute_mAllocaList (),
mAttribute_mInitInstructionListIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskMapIR_2D_element::~ GALGAS_taskMapIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskMapIR_2D_element::GALGAS_taskMapIR_2D_element (const GALGAS_lstring & inOperand0,
                                                          const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                          const GALGAS_bigint & inOperand2,
                                                          const GALGAS_bigint & inOperand3,
                                                          const GALGAS_allocaList & inOperand4,
                                                          const GALGAS_instructionListIR & inOperand5) :
mAttribute_lkey (inOperand0),
mAttribute_mTaskType (inOperand1),
mAttribute_mPriority (inOperand2),
mAttribute_mStackSize (inOperand3),
mAttribute_mAllocaList (inOperand4),
mAttribute_mInitInstructionListIR (inOperand5) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskMapIR_2D_element GALGAS_taskMapIR_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_taskMapIR_2D_element (GALGAS_lstring::constructor_default (HERE),
                                      GALGAS_unifiedTypeMap_2D_proxy::constructor_null (HERE),
                                      GALGAS_bigint::constructor_zero (HERE),
                                      GALGAS_bigint::constructor_zero (HERE),
                                      GALGAS_allocaList::constructor_emptyList (HERE),
                                      GALGAS_instructionListIR::constructor_emptyList (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskMapIR_2D_element GALGAS_taskMapIR_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                          const GALGAS_bigint & inOperand2,
                                                                          const GALGAS_bigint & inOperand3,
                                                                          const GALGAS_allocaList & inOperand4,
                                                                          const GALGAS_instructionListIR & inOperand5 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_taskMapIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid ()) {
    result = GALGAS_taskMapIR_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_taskMapIR_2D_element::objectCompare (const GALGAS_taskMapIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mTaskType.objectCompare (inOperand.mAttribute_mTaskType) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPriority.objectCompare (inOperand.mAttribute_mPriority) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mStackSize.objectCompare (inOperand.mAttribute_mStackSize) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mAllocaList.objectCompare (inOperand.mAttribute_mAllocaList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mInitInstructionListIR.objectCompare (inOperand.mAttribute_mInitInstructionListIR) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_taskMapIR_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mTaskType.isValid () && mAttribute_mPriority.isValid () && mAttribute_mStackSize.isValid () && mAttribute_mAllocaList.isValid () && mAttribute_mInitInstructionListIR.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskMapIR_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mTaskType.drop () ;
  mAttribute_mPriority.drop () ;
  mAttribute_mStackSize.drop () ;
  mAttribute_mAllocaList.drop () ;
  mAttribute_mInitInstructionListIR.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskMapIR_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @taskMapIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mTaskType.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPriority.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mStackSize.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mAllocaList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mInitInstructionListIR.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_taskMapIR_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_taskMapIR_2D_element::getter_mTaskType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTaskType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_taskMapIR_2D_element::getter_mPriority (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPriority ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_taskMapIR_2D_element::getter_mStackSize (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mStackSize ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList GALGAS_taskMapIR_2D_element::getter_mAllocaList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAllocaList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_taskMapIR_2D_element::getter_mInitInstructionListIR (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInitInstructionListIR ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @taskMapIR-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_taskMapIR_2D_element ("taskMapIR-element",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_taskMapIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_taskMapIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_taskMapIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_taskMapIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskMapIR_2D_element GALGAS_taskMapIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_taskMapIR_2D_element result ;
  const GALGAS_taskMapIR_2D_element * p = (const GALGAS_taskMapIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_taskMapIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("taskMapIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicRoutinePriorityMap_2D_element::GALGAS_panicRoutinePriorityMap_2D_element (void) :
mAttribute_lkey () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicRoutinePriorityMap_2D_element::~ GALGAS_panicRoutinePriorityMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicRoutinePriorityMap_2D_element::GALGAS_panicRoutinePriorityMap_2D_element (const GALGAS_lstring & inOperand0) :
mAttribute_lkey (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicRoutinePriorityMap_2D_element GALGAS_panicRoutinePriorityMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_panicRoutinePriorityMap_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicRoutinePriorityMap_2D_element GALGAS_panicRoutinePriorityMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_panicRoutinePriorityMap_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_panicRoutinePriorityMap_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_panicRoutinePriorityMap_2D_element::objectCompare (const GALGAS_panicRoutinePriorityMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_panicRoutinePriorityMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_panicRoutinePriorityMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_panicRoutinePriorityMap_2D_element::description (C_String & ioString,
                                                             const int32_t inIndentation) const {
  ioString << "<struct @panicRoutinePriorityMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_panicRoutinePriorityMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @panicRoutinePriorityMap-element type                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_panicRoutinePriorityMap_2D_element ("panicRoutinePriorityMap-element",
                                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_panicRoutinePriorityMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_panicRoutinePriorityMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_panicRoutinePriorityMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_panicRoutinePriorityMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_panicRoutinePriorityMap_2D_element GALGAS_panicRoutinePriorityMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_panicRoutinePriorityMap_2D_element result ;
  const GALGAS_panicRoutinePriorityMap_2D_element * p = (const GALGAS_panicRoutinePriorityMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_panicRoutinePriorityMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("panicRoutinePriorityMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootRoutinePriorityMap_2D_element::GALGAS_bootRoutinePriorityMap_2D_element (void) :
mAttribute_lkey () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootRoutinePriorityMap_2D_element::~ GALGAS_bootRoutinePriorityMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootRoutinePriorityMap_2D_element::GALGAS_bootRoutinePriorityMap_2D_element (const GALGAS_lstring & inOperand0) :
mAttribute_lkey (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootRoutinePriorityMap_2D_element GALGAS_bootRoutinePriorityMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_bootRoutinePriorityMap_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootRoutinePriorityMap_2D_element GALGAS_bootRoutinePriorityMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bootRoutinePriorityMap_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_bootRoutinePriorityMap_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_bootRoutinePriorityMap_2D_element::objectCompare (const GALGAS_bootRoutinePriorityMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_bootRoutinePriorityMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_bootRoutinePriorityMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_bootRoutinePriorityMap_2D_element::description (C_String & ioString,
                                                            const int32_t inIndentation) const {
  ioString << "<struct @bootRoutinePriorityMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_bootRoutinePriorityMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @bootRoutinePriorityMap-element type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_bootRoutinePriorityMap_2D_element ("bootRoutinePriorityMap-element",
                                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_bootRoutinePriorityMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bootRoutinePriorityMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_bootRoutinePriorityMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_bootRoutinePriorityMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootRoutinePriorityMap_2D_element GALGAS_bootRoutinePriorityMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_bootRoutinePriorityMap_2D_element result ;
  const GALGAS_bootRoutinePriorityMap_2D_element * p = (const GALGAS_bootRoutinePriorityMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_bootRoutinePriorityMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("bootRoutinePriorityMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initRoutineMap_2D_element::GALGAS_initRoutineMap_2D_element (void) :
mAttribute_lkey () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initRoutineMap_2D_element::~ GALGAS_initRoutineMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initRoutineMap_2D_element::GALGAS_initRoutineMap_2D_element (const GALGAS_lstring & inOperand0) :
mAttribute_lkey (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initRoutineMap_2D_element GALGAS_initRoutineMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_initRoutineMap_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initRoutineMap_2D_element GALGAS_initRoutineMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_initRoutineMap_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_initRoutineMap_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_initRoutineMap_2D_element::objectCompare (const GALGAS_initRoutineMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_initRoutineMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_initRoutineMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_initRoutineMap_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @initRoutineMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_initRoutineMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @initRoutineMap-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_initRoutineMap_2D_element ("initRoutineMap-element",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_initRoutineMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_initRoutineMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_initRoutineMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_initRoutineMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initRoutineMap_2D_element GALGAS_initRoutineMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_initRoutineMap_2D_element result ;
  const GALGAS_initRoutineMap_2D_element * p = (const GALGAS_initRoutineMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_initRoutineMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("initRoutineMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initRoutinePriorityMap_2D_element::GALGAS_initRoutinePriorityMap_2D_element (void) :
mAttribute_lkey () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initRoutinePriorityMap_2D_element::~ GALGAS_initRoutinePriorityMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initRoutinePriorityMap_2D_element::GALGAS_initRoutinePriorityMap_2D_element (const GALGAS_lstring & inOperand0) :
mAttribute_lkey (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initRoutinePriorityMap_2D_element GALGAS_initRoutinePriorityMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_initRoutinePriorityMap_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initRoutinePriorityMap_2D_element GALGAS_initRoutinePriorityMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_initRoutinePriorityMap_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_initRoutinePriorityMap_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_initRoutinePriorityMap_2D_element::objectCompare (const GALGAS_initRoutinePriorityMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_initRoutinePriorityMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_initRoutinePriorityMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_initRoutinePriorityMap_2D_element::description (C_String & ioString,
                                                            const int32_t inIndentation) const {
  ioString << "<struct @initRoutinePriorityMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_initRoutinePriorityMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @initRoutinePriorityMap-element type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_initRoutinePriorityMap_2D_element ("initRoutinePriorityMap-element",
                                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_initRoutinePriorityMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_initRoutinePriorityMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_initRoutinePriorityMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_initRoutinePriorityMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initRoutinePriorityMap_2D_element GALGAS_initRoutinePriorityMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_initRoutinePriorityMap_2D_element result ;
  const GALGAS_initRoutinePriorityMap_2D_element * p = (const GALGAS_initRoutinePriorityMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_initRoutinePriorityMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("initRoutinePriorityMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initListIR_2D_element::GALGAS_initListIR_2D_element (void) :
mAttribute_mSelfType (),
mAttribute_mGlobalVariable (),
mAttribute_mInitRequiredByProcList (),
mAttribute_mPriority (),
mAttribute_mAllocaList (),
mAttribute_mInstructionListIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initListIR_2D_element::~ GALGAS_initListIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initListIR_2D_element::GALGAS_initListIR_2D_element (const GALGAS_unifiedTypeMap_2D_proxy & inOperand0,
                                                            const GALGAS_string & inOperand1,
                                                            const GALGAS__32_lstringlist & inOperand2,
                                                            const GALGAS_bigint & inOperand3,
                                                            const GALGAS_allocaList & inOperand4,
                                                            const GALGAS_instructionListIR & inOperand5) :
mAttribute_mSelfType (inOperand0),
mAttribute_mGlobalVariable (inOperand1),
mAttribute_mInitRequiredByProcList (inOperand2),
mAttribute_mPriority (inOperand3),
mAttribute_mAllocaList (inOperand4),
mAttribute_mInstructionListIR (inOperand5) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initListIR_2D_element GALGAS_initListIR_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_initListIR_2D_element (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (HERE),
                                       GALGAS_string::constructor_default (HERE),
                                       GALGAS__32_lstringlist::constructor_emptyList (HERE),
                                       GALGAS_bigint::constructor_zero (HERE),
                                       GALGAS_allocaList::constructor_emptyList (HERE),
                                       GALGAS_instructionListIR::constructor_emptyList (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initListIR_2D_element GALGAS_initListIR_2D_element::constructor_new (const GALGAS_unifiedTypeMap_2D_proxy & inOperand0,
                                                                            const GALGAS_string & inOperand1,
                                                                            const GALGAS__32_lstringlist & inOperand2,
                                                                            const GALGAS_bigint & inOperand3,
                                                                            const GALGAS_allocaList & inOperand4,
                                                                            const GALGAS_instructionListIR & inOperand5 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_initListIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid ()) {
    result = GALGAS_initListIR_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_initListIR_2D_element::objectCompare (const GALGAS_initListIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mSelfType.objectCompare (inOperand.mAttribute_mSelfType) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mGlobalVariable.objectCompare (inOperand.mAttribute_mGlobalVariable) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mInitRequiredByProcList.objectCompare (inOperand.mAttribute_mInitRequiredByProcList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPriority.objectCompare (inOperand.mAttribute_mPriority) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mAllocaList.objectCompare (inOperand.mAttribute_mAllocaList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mInstructionListIR.objectCompare (inOperand.mAttribute_mInstructionListIR) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_initListIR_2D_element::isValid (void) const {
  return mAttribute_mSelfType.isValid () && mAttribute_mGlobalVariable.isValid () && mAttribute_mInitRequiredByProcList.isValid () && mAttribute_mPriority.isValid () && mAttribute_mAllocaList.isValid () && mAttribute_mInstructionListIR.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_initListIR_2D_element::drop (void) {
  mAttribute_mSelfType.drop () ;
  mAttribute_mGlobalVariable.drop () ;
  mAttribute_mInitRequiredByProcList.drop () ;
  mAttribute_mPriority.drop () ;
  mAttribute_mAllocaList.drop () ;
  mAttribute_mInstructionListIR.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_initListIR_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @initListIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mSelfType.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mGlobalVariable.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mInitRequiredByProcList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPriority.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mAllocaList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mInstructionListIR.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_initListIR_2D_element::getter_mSelfType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSelfType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_initListIR_2D_element::getter_mGlobalVariable (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGlobalVariable ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS__32_lstringlist GALGAS_initListIR_2D_element::getter_mInitRequiredByProcList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInitRequiredByProcList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_initListIR_2D_element::getter_mPriority (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPriority ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList GALGAS_initListIR_2D_element::getter_mAllocaList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAllocaList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_initListIR_2D_element::getter_mInstructionListIR (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInstructionListIR ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @initListIR-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_initListIR_2D_element ("initListIR-element",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_initListIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_initListIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_initListIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_initListIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_initListIR_2D_element GALGAS_initListIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_initListIR_2D_element result ;
  const GALGAS_initListIR_2D_element * p = (const GALGAS_initListIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_initListIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("initListIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList_2D_element::GALGAS_procFormalArgumentList_2D_element (void) :
mAttribute_mFormalArgumentPassingMode (),
mAttribute_mSelector (),
mAttribute_mFormalArgumentTypeName (),
mAttribute_mFormalArgumentName () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList_2D_element::~ GALGAS_procFormalArgumentList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList_2D_element::GALGAS_procFormalArgumentList_2D_element (const GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                                    const GALGAS_lstring & inOperand1,
                                                                                    const GALGAS_lstring & inOperand2,
                                                                                    const GALGAS_lstring & inOperand3) :
mAttribute_mFormalArgumentPassingMode (inOperand0),
mAttribute_mSelector (inOperand1),
mAttribute_mFormalArgumentTypeName (inOperand2),
mAttribute_mFormalArgumentName (inOperand3) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList_2D_element GALGAS_procFormalArgumentList_2D_element::constructor_new (const GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                                                    const GALGAS_lstring & inOperand1,
                                                                                                    const GALGAS_lstring & inOperand2,
                                                                                                    const GALGAS_lstring & inOperand3 
                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_procFormalArgumentList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    result = GALGAS_procFormalArgumentList_2D_element (inOperand0, inOperand1, inOperand2, inOperand3) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_procFormalArgumentList_2D_element::objectCompare (const GALGAS_procFormalArgumentList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mFormalArgumentPassingMode.objectCompare (inOperand.mAttribute_mFormalArgumentPassingMode) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSelector.objectCompare (inOperand.mAttribute_mSelector) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mFormalArgumentTypeName.objectCompare (inOperand.mAttribute_mFormalArgumentTypeName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mFormalArgumentName.objectCompare (inOperand.mAttribute_mFormalArgumentName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_procFormalArgumentList_2D_element::isValid (void) const {
  return mAttribute_mFormalArgumentPassingMode.isValid () && mAttribute_mSelector.isValid () && mAttribute_mFormalArgumentTypeName.isValid () && mAttribute_mFormalArgumentName.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentList_2D_element::drop (void) {
  mAttribute_mFormalArgumentPassingMode.drop () ;
  mAttribute_mSelector.drop () ;
  mAttribute_mFormalArgumentTypeName.drop () ;
  mAttribute_mFormalArgumentName.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentList_2D_element::description (C_String & ioString,
                                                            const int32_t inIndentation) const {
  ioString << "<struct @procFormalArgumentList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mFormalArgumentPassingMode.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSelector.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mFormalArgumentTypeName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mFormalArgumentName.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentPassingMode GALGAS_procFormalArgumentList_2D_element::getter_mFormalArgumentPassingMode (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mFormalArgumentPassingMode ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_procFormalArgumentList_2D_element::getter_mSelector (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSelector ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_procFormalArgumentList_2D_element::getter_mFormalArgumentTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mFormalArgumentTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_procFormalArgumentList_2D_element::getter_mFormalArgumentName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mFormalArgumentName ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @procFormalArgumentList-element type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procFormalArgumentList_2D_element ("procFormalArgumentList-element",
                                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procFormalArgumentList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procFormalArgumentList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procFormalArgumentList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procFormalArgumentList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList_2D_element GALGAS_procFormalArgumentList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_procFormalArgumentList_2D_element result ;
  const GALGAS_procFormalArgumentList_2D_element * p = (const GALGAS_procFormalArgumentList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procFormalArgumentList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procFormalArgumentList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureDeclarationListAST_2D_element::GALGAS_procedureDeclarationListAST_2D_element (void) :
mAttribute_mProcedureModeList (),
mAttribute_mPublic (),
mAttribute_mProcedureName (),
mAttribute_mProcedureAttributeList (),
mAttribute_mProcedureFormalArgumentList (),
mAttribute_mReturnTypeName (),
mAttribute_mProcedureInstructionList (),
mAttribute_mEndOfProcedureDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureDeclarationListAST_2D_element::~ GALGAS_procedureDeclarationListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureDeclarationListAST_2D_element::GALGAS_procedureDeclarationListAST_2D_element (const GALGAS_lstringlist & inOperand0,
                                                                                              const GALGAS_bool & inOperand1,
                                                                                              const GALGAS_lstring & inOperand2,
                                                                                              const GALGAS_lstringlist & inOperand3,
                                                                                              const GALGAS_procFormalArgumentList & inOperand4,
                                                                                              const GALGAS_lstring & inOperand5,
                                                                                              const GALGAS_instructionListAST & inOperand6,
                                                                                              const GALGAS_location & inOperand7) :
mAttribute_mProcedureModeList (inOperand0),
mAttribute_mPublic (inOperand1),
mAttribute_mProcedureName (inOperand2),
mAttribute_mProcedureAttributeList (inOperand3),
mAttribute_mProcedureFormalArgumentList (inOperand4),
mAttribute_mReturnTypeName (inOperand5),
mAttribute_mProcedureInstructionList (inOperand6),
mAttribute_mEndOfProcedureDeclaration (inOperand7) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureDeclarationListAST_2D_element GALGAS_procedureDeclarationListAST_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_procedureDeclarationListAST_2D_element (GALGAS_lstringlist::constructor_emptyList (HERE),
                                                        GALGAS_bool::constructor_default (HERE),
                                                        GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_lstringlist::constructor_emptyList (HERE),
                                                        GALGAS_procFormalArgumentList::constructor_emptyList (HERE),
                                                        GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_instructionListAST::constructor_emptyList (HERE),
                                                        GALGAS_location::constructor_nowhere (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureDeclarationListAST_2D_element GALGAS_procedureDeclarationListAST_2D_element::constructor_new (const GALGAS_lstringlist & inOperand0,
                                                                                                              const GALGAS_bool & inOperand1,
                                                                                                              const GALGAS_lstring & inOperand2,
                                                                                                              const GALGAS_lstringlist & inOperand3,
                                                                                                              const GALGAS_procFormalArgumentList & inOperand4,
                                                                                                              const GALGAS_lstring & inOperand5,
                                                                                                              const GALGAS_instructionListAST & inOperand6,
                                                                                                              const GALGAS_location & inOperand7 
                                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_procedureDeclarationListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid ()) {
    result = GALGAS_procedureDeclarationListAST_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_procedureDeclarationListAST_2D_element::objectCompare (const GALGAS_procedureDeclarationListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mProcedureModeList.objectCompare (inOperand.mAttribute_mProcedureModeList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPublic.objectCompare (inOperand.mAttribute_mPublic) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mProcedureName.objectCompare (inOperand.mAttribute_mProcedureName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mProcedureAttributeList.objectCompare (inOperand.mAttribute_mProcedureAttributeList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mProcedureFormalArgumentList.objectCompare (inOperand.mAttribute_mProcedureFormalArgumentList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mReturnTypeName.objectCompare (inOperand.mAttribute_mReturnTypeName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mProcedureInstructionList.objectCompare (inOperand.mAttribute_mProcedureInstructionList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mEndOfProcedureDeclaration.objectCompare (inOperand.mAttribute_mEndOfProcedureDeclaration) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_procedureDeclarationListAST_2D_element::isValid (void) const {
  return mAttribute_mProcedureModeList.isValid () && mAttribute_mPublic.isValid () && mAttribute_mProcedureName.isValid () && mAttribute_mProcedureAttributeList.isValid () && mAttribute_mProcedureFormalArgumentList.isValid () && mAttribute_mReturnTypeName.isValid () && mAttribute_mProcedureInstructionList.isValid () && mAttribute_mEndOfProcedureDeclaration.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procedureDeclarationListAST_2D_element::drop (void) {
  mAttribute_mProcedureModeList.drop () ;
  mAttribute_mPublic.drop () ;
  mAttribute_mProcedureName.drop () ;
  mAttribute_mProcedureAttributeList.drop () ;
  mAttribute_mProcedureFormalArgumentList.drop () ;
  mAttribute_mReturnTypeName.drop () ;
  mAttribute_mProcedureInstructionList.drop () ;
  mAttribute_mEndOfProcedureDeclaration.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procedureDeclarationListAST_2D_element::description (C_String & ioString,
                                                                 const int32_t inIndentation) const {
  ioString << "<struct @procedureDeclarationListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mProcedureModeList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPublic.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mProcedureName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mProcedureAttributeList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mProcedureFormalArgumentList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mReturnTypeName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mProcedureInstructionList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mEndOfProcedureDeclaration.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_procedureDeclarationListAST_2D_element::getter_mProcedureModeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mProcedureModeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_procedureDeclarationListAST_2D_element::getter_mPublic (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPublic ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_procedureDeclarationListAST_2D_element::getter_mProcedureName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mProcedureName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_procedureDeclarationListAST_2D_element::getter_mProcedureAttributeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mProcedureAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_procedureDeclarationListAST_2D_element::getter_mProcedureFormalArgumentList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mProcedureFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_procedureDeclarationListAST_2D_element::getter_mReturnTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mReturnTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_procedureDeclarationListAST_2D_element::getter_mProcedureInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mProcedureInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_procedureDeclarationListAST_2D_element::getter_mEndOfProcedureDeclaration (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfProcedureDeclaration ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @procedureDeclarationListAST-element type                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procedureDeclarationListAST_2D_element ("procedureDeclarationListAST-element",
                                                               NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procedureDeclarationListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procedureDeclarationListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procedureDeclarationListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procedureDeclarationListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureDeclarationListAST_2D_element GALGAS_procedureDeclarationListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_procedureDeclarationListAST_2D_element result ;
  const GALGAS_procedureDeclarationListAST_2D_element * p = (const GALGAS_procedureDeclarationListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procedureDeclarationListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procedureDeclarationListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_labelMap_2D_element::GALGAS_labelMap_2D_element (void) :
mAttribute_lkey () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_labelMap_2D_element::~ GALGAS_labelMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_labelMap_2D_element::GALGAS_labelMap_2D_element (const GALGAS_lstring & inOperand0) :
mAttribute_lkey (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_labelMap_2D_element GALGAS_labelMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_labelMap_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_labelMap_2D_element GALGAS_labelMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_labelMap_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_labelMap_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_labelMap_2D_element::objectCompare (const GALGAS_labelMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_labelMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_labelMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_labelMap_2D_element::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "<struct @labelMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_labelMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @labelMap-element type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_labelMap_2D_element ("labelMap-element",
                                            NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_labelMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_labelMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_labelMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_labelMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_labelMap_2D_element GALGAS_labelMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_labelMap_2D_element result ;
  const GALGAS_labelMap_2D_element * p = (const GALGAS_labelMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_labelMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("labelMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST_2D_element::GALGAS_requiredProcedureDeclarationListAST_2D_element (void) :
mAttribute_mRequiredProcedureName (),
mAttribute_mProcedureModeList (),
mAttribute_mProcFormalArgumentList (),
mAttribute_mEndOfProcLocation () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST_2D_element::~ GALGAS_requiredProcedureDeclarationListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST_2D_element::GALGAS_requiredProcedureDeclarationListAST_2D_element (const GALGAS_lstring & inOperand0,
                                                                                                              const GALGAS_lstringlist & inOperand1,
                                                                                                              const GALGAS_procFormalArgumentList & inOperand2,
                                                                                                              const GALGAS_location & inOperand3) :
mAttribute_mRequiredProcedureName (inOperand0),
mAttribute_mProcedureModeList (inOperand1),
mAttribute_mProcFormalArgumentList (inOperand2),
mAttribute_mEndOfProcLocation (inOperand3) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST_2D_element GALGAS_requiredProcedureDeclarationListAST_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_requiredProcedureDeclarationListAST_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                                GALGAS_lstringlist::constructor_emptyList (HERE),
                                                                GALGAS_procFormalArgumentList::constructor_emptyList (HERE),
                                                                GALGAS_location::constructor_nowhere (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST_2D_element GALGAS_requiredProcedureDeclarationListAST_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                                              const GALGAS_lstringlist & inOperand1,
                                                                                                                              const GALGAS_procFormalArgumentList & inOperand2,
                                                                                                                              const GALGAS_location & inOperand3 
                                                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_requiredProcedureDeclarationListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    result = GALGAS_requiredProcedureDeclarationListAST_2D_element (inOperand0, inOperand1, inOperand2, inOperand3) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_requiredProcedureDeclarationListAST_2D_element::objectCompare (const GALGAS_requiredProcedureDeclarationListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mRequiredProcedureName.objectCompare (inOperand.mAttribute_mRequiredProcedureName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mProcedureModeList.objectCompare (inOperand.mAttribute_mProcedureModeList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mProcFormalArgumentList.objectCompare (inOperand.mAttribute_mProcFormalArgumentList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mEndOfProcLocation.objectCompare (inOperand.mAttribute_mEndOfProcLocation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_requiredProcedureDeclarationListAST_2D_element::isValid (void) const {
  return mAttribute_mRequiredProcedureName.isValid () && mAttribute_mProcedureModeList.isValid () && mAttribute_mProcFormalArgumentList.isValid () && mAttribute_mEndOfProcLocation.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_requiredProcedureDeclarationListAST_2D_element::drop (void) {
  mAttribute_mRequiredProcedureName.drop () ;
  mAttribute_mProcedureModeList.drop () ;
  mAttribute_mProcFormalArgumentList.drop () ;
  mAttribute_mEndOfProcLocation.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_requiredProcedureDeclarationListAST_2D_element::description (C_String & ioString,
                                                                         const int32_t inIndentation) const {
  ioString << "<struct @requiredProcedureDeclarationListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mRequiredProcedureName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mProcedureModeList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mProcFormalArgumentList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mEndOfProcLocation.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_requiredProcedureDeclarationListAST_2D_element::getter_mRequiredProcedureName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRequiredProcedureName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_requiredProcedureDeclarationListAST_2D_element::getter_mProcedureModeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mProcedureModeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_requiredProcedureDeclarationListAST_2D_element::getter_mProcFormalArgumentList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mProcFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_requiredProcedureDeclarationListAST_2D_element::getter_mEndOfProcLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfProcLocation ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  @requiredProcedureDeclarationListAST-element type                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_requiredProcedureDeclarationListAST_2D_element ("requiredProcedureDeclarationListAST-element",
                                                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_requiredProcedureDeclarationListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_requiredProcedureDeclarationListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_requiredProcedureDeclarationListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_requiredProcedureDeclarationListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_requiredProcedureDeclarationListAST_2D_element GALGAS_requiredProcedureDeclarationListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                                            C_Compiler * inCompiler
                                                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_requiredProcedureDeclarationListAST_2D_element result ;
  const GALGAS_requiredProcedureDeclarationListAST_2D_element * p = (const GALGAS_requiredProcedureDeclarationListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_requiredProcedureDeclarationListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("requiredProcedureDeclarationListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST_2D_element::GALGAS_isrDeclarationListAST_2D_element (void) :
mAttribute_mISRName (),
mAttribute_mSelfTypeName (),
mAttribute_mGlobalVariableName (),
mAttribute_mISRAttributeList (),
mAttribute_mISRInstructionList (),
mAttribute_mEndOfISRDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST_2D_element::~ GALGAS_isrDeclarationListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST_2D_element::GALGAS_isrDeclarationListAST_2D_element (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_lstring & inOperand1,
                                                                                  const GALGAS_string & inOperand2,
                                                                                  const GALGAS_lstringlist & inOperand3,
                                                                                  const GALGAS_instructionListAST & inOperand4,
                                                                                  const GALGAS_location & inOperand5) :
mAttribute_mISRName (inOperand0),
mAttribute_mSelfTypeName (inOperand1),
mAttribute_mGlobalVariableName (inOperand2),
mAttribute_mISRAttributeList (inOperand3),
mAttribute_mISRInstructionList (inOperand4),
mAttribute_mEndOfISRDeclaration (inOperand5) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST_2D_element GALGAS_isrDeclarationListAST_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_isrDeclarationListAST_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                  GALGAS_lstring::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_lstringlist::constructor_emptyList (HERE),
                                                  GALGAS_instructionListAST::constructor_emptyList (HERE),
                                                  GALGAS_location::constructor_nowhere (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST_2D_element GALGAS_isrDeclarationListAST_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                  const GALGAS_lstring & inOperand1,
                                                                                                  const GALGAS_string & inOperand2,
                                                                                                  const GALGAS_lstringlist & inOperand3,
                                                                                                  const GALGAS_instructionListAST & inOperand4,
                                                                                                  const GALGAS_location & inOperand5 
                                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_isrDeclarationListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid ()) {
    result = GALGAS_isrDeclarationListAST_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_isrDeclarationListAST_2D_element::objectCompare (const GALGAS_isrDeclarationListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mISRName.objectCompare (inOperand.mAttribute_mISRName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSelfTypeName.objectCompare (inOperand.mAttribute_mSelfTypeName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mGlobalVariableName.objectCompare (inOperand.mAttribute_mGlobalVariableName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mISRAttributeList.objectCompare (inOperand.mAttribute_mISRAttributeList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mISRInstructionList.objectCompare (inOperand.mAttribute_mISRInstructionList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mEndOfISRDeclaration.objectCompare (inOperand.mAttribute_mEndOfISRDeclaration) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_isrDeclarationListAST_2D_element::isValid (void) const {
  return mAttribute_mISRName.isValid () && mAttribute_mSelfTypeName.isValid () && mAttribute_mGlobalVariableName.isValid () && mAttribute_mISRAttributeList.isValid () && mAttribute_mISRInstructionList.isValid () && mAttribute_mEndOfISRDeclaration.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_isrDeclarationListAST_2D_element::drop (void) {
  mAttribute_mISRName.drop () ;
  mAttribute_mSelfTypeName.drop () ;
  mAttribute_mGlobalVariableName.drop () ;
  mAttribute_mISRAttributeList.drop () ;
  mAttribute_mISRInstructionList.drop () ;
  mAttribute_mEndOfISRDeclaration.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_isrDeclarationListAST_2D_element::description (C_String & ioString,
                                                           const int32_t inIndentation) const {
  ioString << "<struct @isrDeclarationListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mISRName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSelfTypeName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mGlobalVariableName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mISRAttributeList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mISRInstructionList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mEndOfISRDeclaration.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_isrDeclarationListAST_2D_element::getter_mISRName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mISRName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_isrDeclarationListAST_2D_element::getter_mSelfTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSelfTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_isrDeclarationListAST_2D_element::getter_mGlobalVariableName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGlobalVariableName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_isrDeclarationListAST_2D_element::getter_mISRAttributeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mISRAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_isrDeclarationListAST_2D_element::getter_mISRInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mISRInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_isrDeclarationListAST_2D_element::getter_mEndOfISRDeclaration (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfISRDeclaration ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @isrDeclarationListAST-element type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_isrDeclarationListAST_2D_element ("isrDeclarationListAST-element",
                                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_isrDeclarationListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_isrDeclarationListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_isrDeclarationListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_isrDeclarationListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_isrDeclarationListAST_2D_element GALGAS_isrDeclarationListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_isrDeclarationListAST_2D_element result ;
  const GALGAS_isrDeclarationListAST_2D_element * p = (const GALGAS_isrDeclarationListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_isrDeclarationListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("isrDeclarationListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST_2D_element::GALGAS_sectionDeclarationListAST_2D_element (void) :
mAttribute_mSectionName (),
mAttribute_mPublic (),
mAttribute_mSectionAttributeList (),
mAttribute_mSectionFormalArgumentList (),
mAttribute_mReturnTypeName (),
mAttribute_mSectionInstructionList (),
mAttribute_mEndOfSectionLocation () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST_2D_element::~ GALGAS_sectionDeclarationListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST_2D_element::GALGAS_sectionDeclarationListAST_2D_element (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_bool & inOperand1,
                                                                                          const GALGAS_lstringlist & inOperand2,
                                                                                          const GALGAS_procFormalArgumentList & inOperand3,
                                                                                          const GALGAS_lstring & inOperand4,
                                                                                          const GALGAS_instructionListAST & inOperand5,
                                                                                          const GALGAS_location & inOperand6) :
mAttribute_mSectionName (inOperand0),
mAttribute_mPublic (inOperand1),
mAttribute_mSectionAttributeList (inOperand2),
mAttribute_mSectionFormalArgumentList (inOperand3),
mAttribute_mReturnTypeName (inOperand4),
mAttribute_mSectionInstructionList (inOperand5),
mAttribute_mEndOfSectionLocation (inOperand6) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST_2D_element GALGAS_sectionDeclarationListAST_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sectionDeclarationListAST_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                      GALGAS_bool::constructor_default (HERE),
                                                      GALGAS_lstringlist::constructor_emptyList (HERE),
                                                      GALGAS_procFormalArgumentList::constructor_emptyList (HERE),
                                                      GALGAS_lstring::constructor_default (HERE),
                                                      GALGAS_instructionListAST::constructor_emptyList (HERE),
                                                      GALGAS_location::constructor_nowhere (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST_2D_element GALGAS_sectionDeclarationListAST_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                          const GALGAS_bool & inOperand1,
                                                                                                          const GALGAS_lstringlist & inOperand2,
                                                                                                          const GALGAS_procFormalArgumentList & inOperand3,
                                                                                                          const GALGAS_lstring & inOperand4,
                                                                                                          const GALGAS_instructionListAST & inOperand5,
                                                                                                          const GALGAS_location & inOperand6 
                                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sectionDeclarationListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    result = GALGAS_sectionDeclarationListAST_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_sectionDeclarationListAST_2D_element::objectCompare (const GALGAS_sectionDeclarationListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mSectionName.objectCompare (inOperand.mAttribute_mSectionName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPublic.objectCompare (inOperand.mAttribute_mPublic) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSectionAttributeList.objectCompare (inOperand.mAttribute_mSectionAttributeList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSectionFormalArgumentList.objectCompare (inOperand.mAttribute_mSectionFormalArgumentList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mReturnTypeName.objectCompare (inOperand.mAttribute_mReturnTypeName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSectionInstructionList.objectCompare (inOperand.mAttribute_mSectionInstructionList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mEndOfSectionLocation.objectCompare (inOperand.mAttribute_mEndOfSectionLocation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_sectionDeclarationListAST_2D_element::isValid (void) const {
  return mAttribute_mSectionName.isValid () && mAttribute_mPublic.isValid () && mAttribute_mSectionAttributeList.isValid () && mAttribute_mSectionFormalArgumentList.isValid () && mAttribute_mReturnTypeName.isValid () && mAttribute_mSectionInstructionList.isValid () && mAttribute_mEndOfSectionLocation.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sectionDeclarationListAST_2D_element::drop (void) {
  mAttribute_mSectionName.drop () ;
  mAttribute_mPublic.drop () ;
  mAttribute_mSectionAttributeList.drop () ;
  mAttribute_mSectionFormalArgumentList.drop () ;
  mAttribute_mReturnTypeName.drop () ;
  mAttribute_mSectionInstructionList.drop () ;
  mAttribute_mEndOfSectionLocation.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sectionDeclarationListAST_2D_element::description (C_String & ioString,
                                                               const int32_t inIndentation) const {
  ioString << "<struct @sectionDeclarationListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mSectionName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPublic.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSectionAttributeList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSectionFormalArgumentList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mReturnTypeName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSectionInstructionList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mEndOfSectionLocation.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_sectionDeclarationListAST_2D_element::getter_mSectionName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSectionName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_sectionDeclarationListAST_2D_element::getter_mPublic (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPublic ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_sectionDeclarationListAST_2D_element::getter_mSectionAttributeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSectionAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_sectionDeclarationListAST_2D_element::getter_mSectionFormalArgumentList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSectionFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_sectionDeclarationListAST_2D_element::getter_mReturnTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mReturnTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_sectionDeclarationListAST_2D_element::getter_mSectionInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSectionInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_sectionDeclarationListAST_2D_element::getter_mEndOfSectionLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfSectionLocation ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @sectionDeclarationListAST-element type                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sectionDeclarationListAST_2D_element ("sectionDeclarationListAST-element",
                                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sectionDeclarationListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sectionDeclarationListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sectionDeclarationListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sectionDeclarationListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sectionDeclarationListAST_2D_element GALGAS_sectionDeclarationListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                        C_Compiler * inCompiler
                                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_sectionDeclarationListAST_2D_element result ;
  const GALGAS_sectionDeclarationListAST_2D_element * p = (const GALGAS_sectionDeclarationListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sectionDeclarationListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sectionDeclarationListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST_2D_element::GALGAS_serviceDeclarationListAST_2D_element (void) :
mAttribute_mServiceName (),
mAttribute_mPublic (),
mAttribute_mServiceAttributeList (),
mAttribute_mServiceFormalArgumentList (),
mAttribute_mReturnTypeName (),
mAttribute_mServiceInstructionList (),
mAttribute_mEndOfServiceLocation () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST_2D_element::~ GALGAS_serviceDeclarationListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST_2D_element::GALGAS_serviceDeclarationListAST_2D_element (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_bool & inOperand1,
                                                                                          const GALGAS_lstringlist & inOperand2,
                                                                                          const GALGAS_procFormalArgumentList & inOperand3,
                                                                                          const GALGAS_lstring & inOperand4,
                                                                                          const GALGAS_instructionListAST & inOperand5,
                                                                                          const GALGAS_location & inOperand6) :
mAttribute_mServiceName (inOperand0),
mAttribute_mPublic (inOperand1),
mAttribute_mServiceAttributeList (inOperand2),
mAttribute_mServiceFormalArgumentList (inOperand3),
mAttribute_mReturnTypeName (inOperand4),
mAttribute_mServiceInstructionList (inOperand5),
mAttribute_mEndOfServiceLocation (inOperand6) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST_2D_element GALGAS_serviceDeclarationListAST_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_serviceDeclarationListAST_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                      GALGAS_bool::constructor_default (HERE),
                                                      GALGAS_lstringlist::constructor_emptyList (HERE),
                                                      GALGAS_procFormalArgumentList::constructor_emptyList (HERE),
                                                      GALGAS_lstring::constructor_default (HERE),
                                                      GALGAS_instructionListAST::constructor_emptyList (HERE),
                                                      GALGAS_location::constructor_nowhere (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST_2D_element GALGAS_serviceDeclarationListAST_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                          const GALGAS_bool & inOperand1,
                                                                                                          const GALGAS_lstringlist & inOperand2,
                                                                                                          const GALGAS_procFormalArgumentList & inOperand3,
                                                                                                          const GALGAS_lstring & inOperand4,
                                                                                                          const GALGAS_instructionListAST & inOperand5,
                                                                                                          const GALGAS_location & inOperand6 
                                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_serviceDeclarationListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    result = GALGAS_serviceDeclarationListAST_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_serviceDeclarationListAST_2D_element::objectCompare (const GALGAS_serviceDeclarationListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mServiceName.objectCompare (inOperand.mAttribute_mServiceName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPublic.objectCompare (inOperand.mAttribute_mPublic) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mServiceAttributeList.objectCompare (inOperand.mAttribute_mServiceAttributeList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mServiceFormalArgumentList.objectCompare (inOperand.mAttribute_mServiceFormalArgumentList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mReturnTypeName.objectCompare (inOperand.mAttribute_mReturnTypeName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mServiceInstructionList.objectCompare (inOperand.mAttribute_mServiceInstructionList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mEndOfServiceLocation.objectCompare (inOperand.mAttribute_mEndOfServiceLocation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_serviceDeclarationListAST_2D_element::isValid (void) const {
  return mAttribute_mServiceName.isValid () && mAttribute_mPublic.isValid () && mAttribute_mServiceAttributeList.isValid () && mAttribute_mServiceFormalArgumentList.isValid () && mAttribute_mReturnTypeName.isValid () && mAttribute_mServiceInstructionList.isValid () && mAttribute_mEndOfServiceLocation.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_serviceDeclarationListAST_2D_element::drop (void) {
  mAttribute_mServiceName.drop () ;
  mAttribute_mPublic.drop () ;
  mAttribute_mServiceAttributeList.drop () ;
  mAttribute_mServiceFormalArgumentList.drop () ;
  mAttribute_mReturnTypeName.drop () ;
  mAttribute_mServiceInstructionList.drop () ;
  mAttribute_mEndOfServiceLocation.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_serviceDeclarationListAST_2D_element::description (C_String & ioString,
                                                               const int32_t inIndentation) const {
  ioString << "<struct @serviceDeclarationListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mServiceName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPublic.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mServiceAttributeList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mServiceFormalArgumentList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mReturnTypeName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mServiceInstructionList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mEndOfServiceLocation.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_serviceDeclarationListAST_2D_element::getter_mServiceName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mServiceName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_serviceDeclarationListAST_2D_element::getter_mPublic (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPublic ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_serviceDeclarationListAST_2D_element::getter_mServiceAttributeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mServiceAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_serviceDeclarationListAST_2D_element::getter_mServiceFormalArgumentList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mServiceFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_serviceDeclarationListAST_2D_element::getter_mReturnTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mReturnTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_serviceDeclarationListAST_2D_element::getter_mServiceInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mServiceInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_serviceDeclarationListAST_2D_element::getter_mEndOfServiceLocation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfServiceLocation ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @serviceDeclarationListAST-element type                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_serviceDeclarationListAST_2D_element ("serviceDeclarationListAST-element",
                                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_serviceDeclarationListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_serviceDeclarationListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_serviceDeclarationListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_serviceDeclarationListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_serviceDeclarationListAST_2D_element GALGAS_serviceDeclarationListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                        C_Compiler * inCompiler
                                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_serviceDeclarationListAST_2D_element result ;
  const GALGAS_serviceDeclarationListAST_2D_element * p = (const GALGAS_serviceDeclarationListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_serviceDeclarationListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("serviceDeclarationListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST_2D_element::GALGAS_primitiveDeclarationListAST_2D_element (void) :
mAttribute_mPrimitiveName (),
mAttribute_mPublic (),
mAttribute_mPrimitiveNameAttributeList (),
mAttribute_mPrimitiveFormalArgumentList (),
mAttribute_mReturnTypeName (),
mAttribute_mPrimitiveInstructionList (),
mAttribute_mEndOfPrimitiveDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST_2D_element::~ GALGAS_primitiveDeclarationListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST_2D_element::GALGAS_primitiveDeclarationListAST_2D_element (const GALGAS_lstring & inOperand0,
                                                                                              const GALGAS_bool & inOperand1,
                                                                                              const GALGAS_lstringlist & inOperand2,
                                                                                              const GALGAS_procFormalArgumentList & inOperand3,
                                                                                              const GALGAS_lstring & inOperand4,
                                                                                              const GALGAS_instructionListAST & inOperand5,
                                                                                              const GALGAS_location & inOperand6) :
mAttribute_mPrimitiveName (inOperand0),
mAttribute_mPublic (inOperand1),
mAttribute_mPrimitiveNameAttributeList (inOperand2),
mAttribute_mPrimitiveFormalArgumentList (inOperand3),
mAttribute_mReturnTypeName (inOperand4),
mAttribute_mPrimitiveInstructionList (inOperand5),
mAttribute_mEndOfPrimitiveDeclaration (inOperand6) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST_2D_element GALGAS_primitiveDeclarationListAST_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_primitiveDeclarationListAST_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_bool::constructor_default (HERE),
                                                        GALGAS_lstringlist::constructor_emptyList (HERE),
                                                        GALGAS_procFormalArgumentList::constructor_emptyList (HERE),
                                                        GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_instructionListAST::constructor_emptyList (HERE),
                                                        GALGAS_location::constructor_nowhere (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST_2D_element GALGAS_primitiveDeclarationListAST_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                              const GALGAS_bool & inOperand1,
                                                                                                              const GALGAS_lstringlist & inOperand2,
                                                                                                              const GALGAS_procFormalArgumentList & inOperand3,
                                                                                                              const GALGAS_lstring & inOperand4,
                                                                                                              const GALGAS_instructionListAST & inOperand5,
                                                                                                              const GALGAS_location & inOperand6 
                                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_primitiveDeclarationListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    result = GALGAS_primitiveDeclarationListAST_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_primitiveDeclarationListAST_2D_element::objectCompare (const GALGAS_primitiveDeclarationListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mPrimitiveName.objectCompare (inOperand.mAttribute_mPrimitiveName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPublic.objectCompare (inOperand.mAttribute_mPublic) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPrimitiveNameAttributeList.objectCompare (inOperand.mAttribute_mPrimitiveNameAttributeList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPrimitiveFormalArgumentList.objectCompare (inOperand.mAttribute_mPrimitiveFormalArgumentList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mReturnTypeName.objectCompare (inOperand.mAttribute_mReturnTypeName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPrimitiveInstructionList.objectCompare (inOperand.mAttribute_mPrimitiveInstructionList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mEndOfPrimitiveDeclaration.objectCompare (inOperand.mAttribute_mEndOfPrimitiveDeclaration) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_primitiveDeclarationListAST_2D_element::isValid (void) const {
  return mAttribute_mPrimitiveName.isValid () && mAttribute_mPublic.isValid () && mAttribute_mPrimitiveNameAttributeList.isValid () && mAttribute_mPrimitiveFormalArgumentList.isValid () && mAttribute_mReturnTypeName.isValid () && mAttribute_mPrimitiveInstructionList.isValid () && mAttribute_mEndOfPrimitiveDeclaration.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primitiveDeclarationListAST_2D_element::drop (void) {
  mAttribute_mPrimitiveName.drop () ;
  mAttribute_mPublic.drop () ;
  mAttribute_mPrimitiveNameAttributeList.drop () ;
  mAttribute_mPrimitiveFormalArgumentList.drop () ;
  mAttribute_mReturnTypeName.drop () ;
  mAttribute_mPrimitiveInstructionList.drop () ;
  mAttribute_mEndOfPrimitiveDeclaration.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primitiveDeclarationListAST_2D_element::description (C_String & ioString,
                                                                 const int32_t inIndentation) const {
  ioString << "<struct @primitiveDeclarationListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mPrimitiveName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPublic.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPrimitiveNameAttributeList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPrimitiveFormalArgumentList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mReturnTypeName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPrimitiveInstructionList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mEndOfPrimitiveDeclaration.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_primitiveDeclarationListAST_2D_element::getter_mPrimitiveName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPrimitiveName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_primitiveDeclarationListAST_2D_element::getter_mPublic (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPublic ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_primitiveDeclarationListAST_2D_element::getter_mPrimitiveNameAttributeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPrimitiveNameAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_primitiveDeclarationListAST_2D_element::getter_mPrimitiveFormalArgumentList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPrimitiveFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_primitiveDeclarationListAST_2D_element::getter_mReturnTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mReturnTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_primitiveDeclarationListAST_2D_element::getter_mPrimitiveInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPrimitiveInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_primitiveDeclarationListAST_2D_element::getter_mEndOfPrimitiveDeclaration (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfPrimitiveDeclaration ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @primitiveDeclarationListAST-element type                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_primitiveDeclarationListAST_2D_element ("primitiveDeclarationListAST-element",
                                                               NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_primitiveDeclarationListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_primitiveDeclarationListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_primitiveDeclarationListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_primitiveDeclarationListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primitiveDeclarationListAST_2D_element GALGAS_primitiveDeclarationListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_primitiveDeclarationListAST_2D_element result ;
  const GALGAS_primitiveDeclarationListAST_2D_element * p = (const GALGAS_primitiveDeclarationListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_primitiveDeclarationListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("primitiveDeclarationListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList_2D_element::GALGAS_functionCallEffectiveParameterList_2D_element (void) :
mAttribute_mSelector (),
mAttribute_mExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList_2D_element::~ GALGAS_functionCallEffectiveParameterList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList_2D_element::GALGAS_functionCallEffectiveParameterList_2D_element (const GALGAS_lstring & inOperand0,
                                                                                                            const GALGAS_expressionAST & inOperand1) :
mAttribute_mSelector (inOperand0),
mAttribute_mExpression (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList_2D_element GALGAS_functionCallEffectiveParameterList_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                                            const GALGAS_expressionAST & inOperand1 
                                                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_functionCallEffectiveParameterList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_functionCallEffectiveParameterList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_functionCallEffectiveParameterList_2D_element::objectCompare (const GALGAS_functionCallEffectiveParameterList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mSelector.objectCompare (inOperand.mAttribute_mSelector) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mExpression.objectCompare (inOperand.mAttribute_mExpression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_functionCallEffectiveParameterList_2D_element::isValid (void) const {
  return mAttribute_mSelector.isValid () && mAttribute_mExpression.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionCallEffectiveParameterList_2D_element::drop (void) {
  mAttribute_mSelector.drop () ;
  mAttribute_mExpression.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_functionCallEffectiveParameterList_2D_element::description (C_String & ioString,
                                                                        const int32_t inIndentation) const {
  ioString << "<struct @functionCallEffectiveParameterList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mSelector.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mExpression.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_functionCallEffectiveParameterList_2D_element::getter_mSelector (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSelector ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_expressionAST GALGAS_functionCallEffectiveParameterList_2D_element::getter_mExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mExpression ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  @functionCallEffectiveParameterList-element type                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_functionCallEffectiveParameterList_2D_element ("functionCallEffectiveParameterList-element",
                                                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_functionCallEffectiveParameterList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_functionCallEffectiveParameterList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_functionCallEffectiveParameterList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_functionCallEffectiveParameterList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_functionCallEffectiveParameterList_2D_element GALGAS_functionCallEffectiveParameterList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                                          C_Compiler * inCompiler
                                                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_functionCallEffectiveParameterList_2D_element result ;
  const GALGAS_functionCallEffectiveParameterList_2D_element * p = (const GALGAS_functionCallEffectiveParameterList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_functionCallEffectiveParameterList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("functionCallEffectiveParameterList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchList_2D_element::GALGAS_syncInstructionBranchList_2D_element (void) :
mAttribute_mGuardedCommand (),
mAttribute_mInstructionList (),
mAttribute_mEndOfBranch () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchList_2D_element::~ GALGAS_syncInstructionBranchList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchList_2D_element::GALGAS_syncInstructionBranchList_2D_element (const GALGAS_guardedCommand & inOperand0,
                                                                                          const GALGAS_instructionListAST & inOperand1,
                                                                                          const GALGAS_location & inOperand2) :
mAttribute_mGuardedCommand (inOperand0),
mAttribute_mInstructionList (inOperand1),
mAttribute_mEndOfBranch (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchList_2D_element GALGAS_syncInstructionBranchList_2D_element::constructor_new (const GALGAS_guardedCommand & inOperand0,
                                                                                                          const GALGAS_instructionListAST & inOperand1,
                                                                                                          const GALGAS_location & inOperand2 
                                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_syncInstructionBranchList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_syncInstructionBranchList_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_syncInstructionBranchList_2D_element::objectCompare (const GALGAS_syncInstructionBranchList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mGuardedCommand.objectCompare (inOperand.mAttribute_mGuardedCommand) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mInstructionList.objectCompare (inOperand.mAttribute_mInstructionList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mEndOfBranch.objectCompare (inOperand.mAttribute_mEndOfBranch) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_syncInstructionBranchList_2D_element::isValid (void) const {
  return mAttribute_mGuardedCommand.isValid () && mAttribute_mInstructionList.isValid () && mAttribute_mEndOfBranch.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchList_2D_element::drop (void) {
  mAttribute_mGuardedCommand.drop () ;
  mAttribute_mInstructionList.drop () ;
  mAttribute_mEndOfBranch.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchList_2D_element::description (C_String & ioString,
                                                               const int32_t inIndentation) const {
  ioString << "<struct @syncInstructionBranchList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mGuardedCommand.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mInstructionList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mEndOfBranch.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardedCommand GALGAS_syncInstructionBranchList_2D_element::getter_mGuardedCommand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGuardedCommand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_syncInstructionBranchList_2D_element::getter_mInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_syncInstructionBranchList_2D_element::getter_mEndOfBranch (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfBranch ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @syncInstructionBranchList-element type                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_syncInstructionBranchList_2D_element ("syncInstructionBranchList-element",
                                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_syncInstructionBranchList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_syncInstructionBranchList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_syncInstructionBranchList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_syncInstructionBranchList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchList_2D_element GALGAS_syncInstructionBranchList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                        C_Compiler * inCompiler
                                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_syncInstructionBranchList_2D_element result ;
  const GALGAS_syncInstructionBranchList_2D_element * p = (const GALGAS_syncInstructionBranchList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_syncInstructionBranchList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("syncInstructionBranchList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST_2D_element::GALGAS_effectiveParameterListAST_2D_element (void) :
mAttribute_mEffectiveParameterKind (),
mAttribute_mSelector () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST_2D_element::~ GALGAS_effectiveParameterListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST_2D_element::GALGAS_effectiveParameterListAST_2D_element (const GALGAS_effectiveParameterPassingModeAST & inOperand0,
                                                                                          const GALGAS_lstring & inOperand1) :
mAttribute_mEffectiveParameterKind (inOperand0),
mAttribute_mSelector (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST_2D_element GALGAS_effectiveParameterListAST_2D_element::constructor_new (const GALGAS_effectiveParameterPassingModeAST & inOperand0,
                                                                                                          const GALGAS_lstring & inOperand1 
                                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_effectiveParameterListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_effectiveParameterListAST_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_effectiveParameterListAST_2D_element::objectCompare (const GALGAS_effectiveParameterListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mEffectiveParameterKind.objectCompare (inOperand.mAttribute_mEffectiveParameterKind) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSelector.objectCompare (inOperand.mAttribute_mSelector) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_effectiveParameterListAST_2D_element::isValid (void) const {
  return mAttribute_mEffectiveParameterKind.isValid () && mAttribute_mSelector.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_effectiveParameterListAST_2D_element::drop (void) {
  mAttribute_mEffectiveParameterKind.drop () ;
  mAttribute_mSelector.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_effectiveParameterListAST_2D_element::description (C_String & ioString,
                                                               const int32_t inIndentation) const {
  ioString << "<struct @effectiveParameterListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mEffectiveParameterKind.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSelector.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterPassingModeAST GALGAS_effectiveParameterListAST_2D_element::getter_mEffectiveParameterKind (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEffectiveParameterKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_effectiveParameterListAST_2D_element::getter_mSelector (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSelector ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @effectiveParameterListAST-element type                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_effectiveParameterListAST_2D_element ("effectiveParameterListAST-element",
                                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_effectiveParameterListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_effectiveParameterListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_effectiveParameterListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_effectiveParameterListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterListAST_2D_element GALGAS_effectiveParameterListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                        C_Compiler * inCompiler
                                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_effectiveParameterListAST_2D_element result ;
  const GALGAS_effectiveParameterListAST_2D_element * p = (const GALGAS_effectiveParameterListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_effectiveParameterListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("effectiveParameterListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList_2D_element::GALGAS_procEffectiveParameterList_2D_element (void) :
mAttribute_mEffectiveParameterPassingMode (),
mAttribute_mSelector (),
mAttribute_mParameterType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList_2D_element::~ GALGAS_procEffectiveParameterList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList_2D_element::GALGAS_procEffectiveParameterList_2D_element (const GALGAS_effectiveParameterPassingModeAST & inOperand0,
                                                                                            const GALGAS_lstring & inOperand1,
                                                                                            const GALGAS_unifiedTypeMap_2D_proxy & inOperand2) :
mAttribute_mEffectiveParameterPassingMode (inOperand0),
mAttribute_mSelector (inOperand1),
mAttribute_mParameterType (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList_2D_element GALGAS_procEffectiveParameterList_2D_element::constructor_new (const GALGAS_effectiveParameterPassingModeAST & inOperand0,
                                                                                                            const GALGAS_lstring & inOperand1,
                                                                                                            const GALGAS_unifiedTypeMap_2D_proxy & inOperand2 
                                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_procEffectiveParameterList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_procEffectiveParameterList_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_procEffectiveParameterList_2D_element::objectCompare (const GALGAS_procEffectiveParameterList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mEffectiveParameterPassingMode.objectCompare (inOperand.mAttribute_mEffectiveParameterPassingMode) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSelector.objectCompare (inOperand.mAttribute_mSelector) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mParameterType.objectCompare (inOperand.mAttribute_mParameterType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_procEffectiveParameterList_2D_element::isValid (void) const {
  return mAttribute_mEffectiveParameterPassingMode.isValid () && mAttribute_mSelector.isValid () && mAttribute_mParameterType.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procEffectiveParameterList_2D_element::drop (void) {
  mAttribute_mEffectiveParameterPassingMode.drop () ;
  mAttribute_mSelector.drop () ;
  mAttribute_mParameterType.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procEffectiveParameterList_2D_element::description (C_String & ioString,
                                                                const int32_t inIndentation) const {
  ioString << "<struct @procEffectiveParameterList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mEffectiveParameterPassingMode.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSelector.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mParameterType.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_effectiveParameterPassingModeAST GALGAS_procEffectiveParameterList_2D_element::getter_mEffectiveParameterPassingMode (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEffectiveParameterPassingMode ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_procEffectiveParameterList_2D_element::getter_mSelector (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSelector ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_procEffectiveParameterList_2D_element::getter_mParameterType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mParameterType ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @procEffectiveParameterList-element type                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procEffectiveParameterList_2D_element ("procEffectiveParameterList-element",
                                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procEffectiveParameterList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procEffectiveParameterList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procEffectiveParameterList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procEffectiveParameterList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterList_2D_element GALGAS_procEffectiveParameterList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_procEffectiveParameterList_2D_element result ;
  const GALGAS_procEffectiveParameterList_2D_element * p = (const GALGAS_procEffectiveParameterList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procEffectiveParameterList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procEffectiveParameterList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapForContext_2D_element::GALGAS_routineMapForContext_2D_element (void) :
mAttribute_lkey (),
mAttribute_mIsPublic (),
mAttribute_mModeMap (),
mAttribute_mSignature (),
mAttribute_mRoutineKind (),
mAttribute_mWeak (),
mAttribute_mReturnType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapForContext_2D_element::~ GALGAS_routineMapForContext_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapForContext_2D_element::GALGAS_routineMapForContext_2D_element (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_bool & inOperand1,
                                                                                const GALGAS_modeMap & inOperand2,
                                                                                const GALGAS_procedureSignature & inOperand3,
                                                                                const GALGAS_routineKind & inOperand4,
                                                                                const GALGAS_bool & inOperand5,
                                                                                const GALGAS_unifiedTypeMap_2D_proxy & inOperand6) :
mAttribute_lkey (inOperand0),
mAttribute_mIsPublic (inOperand1),
mAttribute_mModeMap (inOperand2),
mAttribute_mSignature (inOperand3),
mAttribute_mRoutineKind (inOperand4),
mAttribute_mWeak (inOperand5),
mAttribute_mReturnType (inOperand6) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapForContext_2D_element GALGAS_routineMapForContext_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                const GALGAS_bool & inOperand1,
                                                                                                const GALGAS_modeMap & inOperand2,
                                                                                                const GALGAS_procedureSignature & inOperand3,
                                                                                                const GALGAS_routineKind & inOperand4,
                                                                                                const GALGAS_bool & inOperand5,
                                                                                                const GALGAS_unifiedTypeMap_2D_proxy & inOperand6 
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_routineMapForContext_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    result = GALGAS_routineMapForContext_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_routineMapForContext_2D_element::objectCompare (const GALGAS_routineMapForContext_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mIsPublic.objectCompare (inOperand.mAttribute_mIsPublic) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mModeMap.objectCompare (inOperand.mAttribute_mModeMap) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSignature.objectCompare (inOperand.mAttribute_mSignature) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mRoutineKind.objectCompare (inOperand.mAttribute_mRoutineKind) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mWeak.objectCompare (inOperand.mAttribute_mWeak) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mReturnType.objectCompare (inOperand.mAttribute_mReturnType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_routineMapForContext_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mIsPublic.isValid () && mAttribute_mModeMap.isValid () && mAttribute_mSignature.isValid () && mAttribute_mRoutineKind.isValid () && mAttribute_mWeak.isValid () && mAttribute_mReturnType.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapForContext_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mIsPublic.drop () ;
  mAttribute_mModeMap.drop () ;
  mAttribute_mSignature.drop () ;
  mAttribute_mRoutineKind.drop () ;
  mAttribute_mWeak.drop () ;
  mAttribute_mReturnType.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_routineMapForContext_2D_element::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "<struct @routineMapForContext-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mIsPublic.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mModeMap.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSignature.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mRoutineKind.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mWeak.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mReturnType.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_routineMapForContext_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_routineMapForContext_2D_element::getter_mIsPublic (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIsPublic ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_modeMap GALGAS_routineMapForContext_2D_element::getter_mModeMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mModeMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureSignature GALGAS_routineMapForContext_2D_element::getter_mSignature (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSignature ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineKind GALGAS_routineMapForContext_2D_element::getter_mRoutineKind (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRoutineKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_routineMapForContext_2D_element::getter_mWeak (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mWeak ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_routineMapForContext_2D_element::getter_mReturnType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mReturnType ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @routineMapForContext-element type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_routineMapForContext_2D_element ("routineMapForContext-element",
                                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_routineMapForContext_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_routineMapForContext_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_routineMapForContext_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_routineMapForContext_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_routineMapForContext_2D_element GALGAS_routineMapForContext_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_routineMapForContext_2D_element result ;
  const GALGAS_routineMapForContext_2D_element * p = (const GALGAS_routineMapForContext_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_routineMapForContext_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("routineMapForContext-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapForContext_2D_element::GALGAS_guardMapForContext_2D_element (void) :
mAttribute_lkey (),
mAttribute_mIsPublic (),
mAttribute_mSignature () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapForContext_2D_element::~ GALGAS_guardMapForContext_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapForContext_2D_element::GALGAS_guardMapForContext_2D_element (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_bool & inOperand1,
                                                                            const GALGAS_procedureSignature & inOperand2) :
mAttribute_lkey (inOperand0),
mAttribute_mIsPublic (inOperand1),
mAttribute_mSignature (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapForContext_2D_element GALGAS_guardMapForContext_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_guardMapForContext_2D_element (GALGAS_lstring::constructor_default (HERE),
                                               GALGAS_bool::constructor_default (HERE),
                                               GALGAS_procedureSignature::constructor_emptyList (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapForContext_2D_element GALGAS_guardMapForContext_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                            const GALGAS_bool & inOperand1,
                                                                                            const GALGAS_procedureSignature & inOperand2 
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_guardMapForContext_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_guardMapForContext_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_guardMapForContext_2D_element::objectCompare (const GALGAS_guardMapForContext_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mIsPublic.objectCompare (inOperand.mAttribute_mIsPublic) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSignature.objectCompare (inOperand.mAttribute_mSignature) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_guardMapForContext_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mIsPublic.isValid () && mAttribute_mSignature.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardMapForContext_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mIsPublic.drop () ;
  mAttribute_mSignature.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardMapForContext_2D_element::description (C_String & ioString,
                                                        const int32_t inIndentation) const {
  ioString << "<struct @guardMapForContext-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mIsPublic.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSignature.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_guardMapForContext_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_guardMapForContext_2D_element::getter_mIsPublic (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIsPublic ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureSignature GALGAS_guardMapForContext_2D_element::getter_mSignature (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSignature ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @guardMapForContext-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_guardMapForContext_2D_element ("guardMapForContext-element",
                                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_guardMapForContext_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_guardMapForContext_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_guardMapForContext_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_guardMapForContext_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardMapForContext_2D_element GALGAS_guardMapForContext_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_guardMapForContext_2D_element result ;
  const GALGAS_guardMapForContext_2D_element * p = (const GALGAS_guardMapForContext_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_guardMapForContext_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("guardMapForContext-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureSignature_2D_element::GALGAS_procedureSignature_2D_element (void) :
mAttribute_mFormalArgumentPassingMode (),
mAttribute_mSelector (),
mAttribute_mType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureSignature_2D_element::~ GALGAS_procedureSignature_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureSignature_2D_element::GALGAS_procedureSignature_2D_element (const GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                            const GALGAS_string & inOperand1,
                                                                            const GALGAS_unifiedTypeMap_2D_proxy & inOperand2) :
mAttribute_mFormalArgumentPassingMode (inOperand0),
mAttribute_mSelector (inOperand1),
mAttribute_mType (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureSignature_2D_element GALGAS_procedureSignature_2D_element::constructor_new (const GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                                            const GALGAS_string & inOperand1,
                                                                                            const GALGAS_unifiedTypeMap_2D_proxy & inOperand2 
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_procedureSignature_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_procedureSignature_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_procedureSignature_2D_element::objectCompare (const GALGAS_procedureSignature_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mFormalArgumentPassingMode.objectCompare (inOperand.mAttribute_mFormalArgumentPassingMode) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSelector.objectCompare (inOperand.mAttribute_mSelector) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mType.objectCompare (inOperand.mAttribute_mType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_procedureSignature_2D_element::isValid (void) const {
  return mAttribute_mFormalArgumentPassingMode.isValid () && mAttribute_mSelector.isValid () && mAttribute_mType.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procedureSignature_2D_element::drop (void) {
  mAttribute_mFormalArgumentPassingMode.drop () ;
  mAttribute_mSelector.drop () ;
  mAttribute_mType.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procedureSignature_2D_element::description (C_String & ioString,
                                                        const int32_t inIndentation) const {
  ioString << "<struct @procedureSignature-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mFormalArgumentPassingMode.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSelector.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mType.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentPassingMode GALGAS_procedureSignature_2D_element::getter_mFormalArgumentPassingMode (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mFormalArgumentPassingMode ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_procedureSignature_2D_element::getter_mSelector (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSelector ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_procedureSignature_2D_element::getter_mType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mType ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @procedureSignature-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procedureSignature_2D_element ("procedureSignature-element",
                                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procedureSignature_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procedureSignature_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procedureSignature_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procedureSignature_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procedureSignature_2D_element GALGAS_procedureSignature_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_procedureSignature_2D_element result ;
  const GALGAS_procedureSignature_2D_element * p = (const GALGAS_procedureSignature_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procedureSignature_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procedureSignature-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap_2D_element::GALGAS_infixOperatorMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mResultType (),
mAttribute_mOperation () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap_2D_element::~ GALGAS_infixOperatorMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap_2D_element::GALGAS_infixOperatorMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                        const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                        const GALGAS_infixOperatorDescription & inOperand2) :
mAttribute_lkey (inOperand0),
mAttribute_mResultType (inOperand1),
mAttribute_mOperation (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap_2D_element GALGAS_infixOperatorMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                        const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                                        const GALGAS_infixOperatorDescription & inOperand2 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_infixOperatorMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_infixOperatorMap_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_infixOperatorMap_2D_element::objectCompare (const GALGAS_infixOperatorMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mResultType.objectCompare (inOperand.mAttribute_mResultType) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mOperation.objectCompare (inOperand.mAttribute_mOperation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_infixOperatorMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mResultType.isValid () && mAttribute_mOperation.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_infixOperatorMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mResultType.drop () ;
  mAttribute_mOperation.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_infixOperatorMap_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @infixOperatorMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mResultType.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mOperation.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_infixOperatorMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_infixOperatorMap_2D_element::getter_mResultType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mResultType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorDescription GALGAS_infixOperatorMap_2D_element::getter_mOperation (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperation ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @infixOperatorMap-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_infixOperatorMap_2D_element ("infixOperatorMap-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_infixOperatorMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_infixOperatorMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_infixOperatorMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_infixOperatorMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_infixOperatorMap_2D_element GALGAS_infixOperatorMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_infixOperatorMap_2D_element result ;
  const GALGAS_infixOperatorMap_2D_element * p = (const GALGAS_infixOperatorMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_infixOperatorMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("infixOperatorMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap_2D_element::GALGAS_prefixOperatorMap_2D_element (void) :
mAttribute_lkey () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap_2D_element::~ GALGAS_prefixOperatorMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap_2D_element::GALGAS_prefixOperatorMap_2D_element (const GALGAS_lstring & inOperand0) :
mAttribute_lkey (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap_2D_element GALGAS_prefixOperatorMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_prefixOperatorMap_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap_2D_element GALGAS_prefixOperatorMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_prefixOperatorMap_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_prefixOperatorMap_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_prefixOperatorMap_2D_element::objectCompare (const GALGAS_prefixOperatorMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_prefixOperatorMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefixOperatorMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefixOperatorMap_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @prefixOperatorMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_prefixOperatorMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @prefixOperatorMap-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_prefixOperatorMap_2D_element ("prefixOperatorMap-element",
                                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_prefixOperatorMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefixOperatorMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_prefixOperatorMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_prefixOperatorMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap_2D_element GALGAS_prefixOperatorMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_prefixOperatorMap_2D_element result ;
  const GALGAS_prefixOperatorMap_2D_element * p = (const GALGAS_prefixOperatorMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_prefixOperatorMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("prefixOperatorMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap_2D_element::GALGAS_staticStringMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mIndex () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap_2D_element::~ GALGAS_staticStringMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap_2D_element::GALGAS_staticStringMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                      const GALGAS_uint & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_mIndex (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap_2D_element GALGAS_staticStringMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_staticStringMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                            GALGAS_uint::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap_2D_element GALGAS_staticStringMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                      const GALGAS_uint & inOperand1 
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_staticStringMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_staticStringMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_staticStringMap_2D_element::objectCompare (const GALGAS_staticStringMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mIndex.objectCompare (inOperand.mAttribute_mIndex) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_staticStringMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mIndex.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_staticStringMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mIndex.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_staticStringMap_2D_element::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "<struct @staticStringMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mIndex.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_staticStringMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_staticStringMap_2D_element::getter_mIndex (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIndex ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @staticStringMap-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_staticStringMap_2D_element ("staticStringMap-element",
                                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_staticStringMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_staticStringMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_staticStringMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_staticStringMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap_2D_element GALGAS_staticStringMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_staticStringMap_2D_element result ;
  const GALGAS_staticStringMap_2D_element * p = (const GALGAS_staticStringMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_staticStringMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("staticStringMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap_2D_element::GALGAS_allowedGuardMap_2D_element (void) :
mAttribute_lkey () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap_2D_element::~ GALGAS_allowedGuardMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap_2D_element::GALGAS_allowedGuardMap_2D_element (const GALGAS_lstring & inOperand0) :
mAttribute_lkey (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap_2D_element GALGAS_allowedGuardMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_allowedGuardMap_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap_2D_element GALGAS_allowedGuardMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_allowedGuardMap_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_allowedGuardMap_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_allowedGuardMap_2D_element::objectCompare (const GALGAS_allowedGuardMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_allowedGuardMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedGuardMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedGuardMap_2D_element::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "<struct @allowedGuardMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_allowedGuardMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @allowedGuardMap-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_allowedGuardMap_2D_element ("allowedGuardMap-element",
                                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_allowedGuardMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_allowedGuardMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_allowedGuardMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_allowedGuardMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap_2D_element GALGAS_allowedGuardMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_allowedGuardMap_2D_element result ;
  const GALGAS_allowedGuardMap_2D_element * p = (const GALGAS_allowedGuardMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_allowedGuardMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("allowedGuardMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap_2D_element::GALGAS_globalVariableMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_type (),
mAttribute_executionModeSet (),
mAttribute_allowedRoutineMap (),
mAttribute_allowedGuardMap (),
mAttribute_allowedISRMap (),
mAttribute_initialValue (),
mAttribute_isConstant () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap_2D_element::~ GALGAS_globalVariableMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap_2D_element::GALGAS_globalVariableMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                          const GALGAS_stringset & inOperand2,
                                                                          const GALGAS_allowedRoutineMap & inOperand3,
                                                                          const GALGAS_allowedGuardMap & inOperand4,
                                                                          const GALGAS_allowedISRMap & inOperand5,
                                                                          const GALGAS_valueIR & inOperand6,
                                                                          const GALGAS_bool & inOperand7) :
mAttribute_lkey (inOperand0),
mAttribute_type (inOperand1),
mAttribute_executionModeSet (inOperand2),
mAttribute_allowedRoutineMap (inOperand3),
mAttribute_allowedGuardMap (inOperand4),
mAttribute_allowedISRMap (inOperand5),
mAttribute_initialValue (inOperand6),
mAttribute_isConstant (inOperand7) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap_2D_element GALGAS_globalVariableMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                                          const GALGAS_stringset & inOperand2,
                                                                                          const GALGAS_allowedRoutineMap & inOperand3,
                                                                                          const GALGAS_allowedGuardMap & inOperand4,
                                                                                          const GALGAS_allowedISRMap & inOperand5,
                                                                                          const GALGAS_valueIR & inOperand6,
                                                                                          const GALGAS_bool & inOperand7 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_globalVariableMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid () && inOperand7.isValid ()) {
    result = GALGAS_globalVariableMap_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6, inOperand7) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_globalVariableMap_2D_element::objectCompare (const GALGAS_globalVariableMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_type.objectCompare (inOperand.mAttribute_type) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_executionModeSet.objectCompare (inOperand.mAttribute_executionModeSet) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_allowedRoutineMap.objectCompare (inOperand.mAttribute_allowedRoutineMap) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_allowedGuardMap.objectCompare (inOperand.mAttribute_allowedGuardMap) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_allowedISRMap.objectCompare (inOperand.mAttribute_allowedISRMap) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_initialValue.objectCompare (inOperand.mAttribute_initialValue) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_isConstant.objectCompare (inOperand.mAttribute_isConstant) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_globalVariableMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_type.isValid () && mAttribute_executionModeSet.isValid () && mAttribute_allowedRoutineMap.isValid () && mAttribute_allowedGuardMap.isValid () && mAttribute_allowedISRMap.isValid () && mAttribute_initialValue.isValid () && mAttribute_isConstant.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_type.drop () ;
  mAttribute_executionModeSet.drop () ;
  mAttribute_allowedRoutineMap.drop () ;
  mAttribute_allowedGuardMap.drop () ;
  mAttribute_allowedISRMap.drop () ;
  mAttribute_initialValue.drop () ;
  mAttribute_isConstant.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMap_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @globalVariableMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_type.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_executionModeSet.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_allowedRoutineMap.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_allowedGuardMap.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_allowedISRMap.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_initialValue.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_isConstant.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_globalVariableMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_globalVariableMap_2D_element::getter_type (UNUSED_LOCATION_ARGS) const {
  return mAttribute_type ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_globalVariableMap_2D_element::getter_executionModeSet (UNUSED_LOCATION_ARGS) const {
  return mAttribute_executionModeSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedRoutineMap GALGAS_globalVariableMap_2D_element::getter_allowedRoutineMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_allowedRoutineMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap GALGAS_globalVariableMap_2D_element::getter_allowedGuardMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_allowedGuardMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedISRMap GALGAS_globalVariableMap_2D_element::getter_allowedISRMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_allowedISRMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_valueIR GALGAS_globalVariableMap_2D_element::getter_initialValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_initialValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_globalVariableMap_2D_element::getter_isConstant (UNUSED_LOCATION_ARGS) const {
  return mAttribute_isConstant ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @globalVariableMap-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_globalVariableMap_2D_element ("globalVariableMap-element",
                                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_globalVariableMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalVariableMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_globalVariableMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_globalVariableMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap_2D_element GALGAS_globalVariableMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_globalVariableMap_2D_element result ;
  const GALGAS_globalVariableMap_2D_element * p = (const GALGAS_globalVariableMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_globalVariableMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("globalVariableMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_modeMap_2D_element::GALGAS_modeMap_2D_element (void) :
mAttribute_lkey () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_modeMap_2D_element::~ GALGAS_modeMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_modeMap_2D_element::GALGAS_modeMap_2D_element (const GALGAS_lstring & inOperand0) :
mAttribute_lkey (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_modeMap_2D_element GALGAS_modeMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_modeMap_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_modeMap_2D_element GALGAS_modeMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_modeMap_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_modeMap_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_modeMap_2D_element::objectCompare (const GALGAS_modeMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_modeMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_modeMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_modeMap_2D_element::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "<struct @modeMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_modeMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @modeMap-element type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_modeMap_2D_element ("modeMap-element",
                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_modeMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_modeMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_modeMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_modeMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_modeMap_2D_element GALGAS_modeMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_modeMap_2D_element result ;
  const GALGAS_modeMap_2D_element * p = (const GALGAS_modeMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_modeMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("modeMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeList_2D_element::GALGAS_typeList_2D_element (void) :
mAttribute_mActualType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeList_2D_element::~ GALGAS_typeList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeList_2D_element::GALGAS_typeList_2D_element (const GALGAS_unifiedTypeMap_2D_proxy & inOperand0) :
mAttribute_mActualType (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeList_2D_element GALGAS_typeList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_typeList_2D_element (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeList_2D_element GALGAS_typeList_2D_element::constructor_new (const GALGAS_unifiedTypeMap_2D_proxy & inOperand0 
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_typeList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_typeList_2D_element::objectCompare (const GALGAS_typeList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mActualType.objectCompare (inOperand.mAttribute_mActualType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_typeList_2D_element::isValid (void) const {
  return mAttribute_mActualType.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_typeList_2D_element::drop (void) {
  mAttribute_mActualType.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_typeList_2D_element::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "<struct @typeList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mActualType.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_typeList_2D_element::getter_mActualType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mActualType ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @typeList-element type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeList_2D_element ("typeList-element",
                                            NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_typeList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_typeList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeList_2D_element GALGAS_typeList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeList_2D_element result ;
  const GALGAS_typeList_2D_element * p = (const GALGAS_typeList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap_2D_element::GALGAS_constructorMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mInitValue () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap_2D_element::~ GALGAS_constructorMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap_2D_element::GALGAS_constructorMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                    const GALGAS_constructorValue & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_mInitValue (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap_2D_element GALGAS_constructorMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                    const GALGAS_constructorValue & inOperand1 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_constructorMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_constructorMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_constructorMap_2D_element::objectCompare (const GALGAS_constructorMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mInitValue.objectCompare (inOperand.mAttribute_mInitValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_constructorMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mInitValue.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mInitValue.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorMap_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @constructorMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mInitValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_constructorMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorValue GALGAS_constructorMap_2D_element::getter_mInitValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInitValue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @constructorMap-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_constructorMap_2D_element ("constructorMap-element",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_constructorMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_constructorMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_constructorMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_constructorMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap_2D_element GALGAS_constructorMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_constructorMap_2D_element result ;
  const GALGAS_constructorMap_2D_element * p = (const GALGAS_constructorMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_constructorMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("constructorMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList_2D_element::GALGAS_globalTaskVariableList_2D_element (void) :
mAttribute_mTaskName (),
mAttribute_mTaskTypeName (),
mAttribute_mInitialValue () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList_2D_element::~ GALGAS_globalTaskVariableList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList_2D_element::GALGAS_globalTaskVariableList_2D_element (const GALGAS_string & inOperand0,
                                                                                    const GALGAS_string & inOperand1,
                                                                                    const GALGAS_valueIR & inOperand2) :
mAttribute_mTaskName (inOperand0),
mAttribute_mTaskTypeName (inOperand1),
mAttribute_mInitialValue (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList_2D_element GALGAS_globalTaskVariableList_2D_element::constructor_new (const GALGAS_string & inOperand0,
                                                                                                    const GALGAS_string & inOperand1,
                                                                                                    const GALGAS_valueIR & inOperand2 
                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_globalTaskVariableList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_globalTaskVariableList_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_globalTaskVariableList_2D_element::objectCompare (const GALGAS_globalTaskVariableList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mTaskName.objectCompare (inOperand.mAttribute_mTaskName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mTaskTypeName.objectCompare (inOperand.mAttribute_mTaskTypeName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mInitialValue.objectCompare (inOperand.mAttribute_mInitialValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_globalTaskVariableList_2D_element::isValid (void) const {
  return mAttribute_mTaskName.isValid () && mAttribute_mTaskTypeName.isValid () && mAttribute_mInitialValue.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalTaskVariableList_2D_element::drop (void) {
  mAttribute_mTaskName.drop () ;
  mAttribute_mTaskTypeName.drop () ;
  mAttribute_mInitialValue.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalTaskVariableList_2D_element::description (C_String & ioString,
                                                            const int32_t inIndentation) const {
  ioString << "<struct @globalTaskVariableList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mTaskName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mTaskTypeName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mInitialValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_globalTaskVariableList_2D_element::getter_mTaskName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTaskName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_globalTaskVariableList_2D_element::getter_mTaskTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mTaskTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_valueIR GALGAS_globalTaskVariableList_2D_element::getter_mInitialValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInitialValue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @globalTaskVariableList-element type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_globalTaskVariableList_2D_element ("globalTaskVariableList-element",
                                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_globalTaskVariableList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalTaskVariableList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_globalTaskVariableList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_globalTaskVariableList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList_2D_element GALGAS_globalTaskVariableList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_globalTaskVariableList_2D_element result ;
  const GALGAS_globalTaskVariableList_2D_element * p = (const GALGAS_globalTaskVariableList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_globalTaskVariableList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("globalTaskVariableList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration_2D_element::GALGAS_procFormalArgumentListForGeneration_2D_element (void) :
mAttribute_mFormalArgumentKind (),
mAttribute_mFormalArgumentType (),
mAttribute_mFormalArgumentName () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration_2D_element::~ GALGAS_procFormalArgumentListForGeneration_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration_2D_element::GALGAS_procFormalArgumentListForGeneration_2D_element (const GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                                                              const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                                                              const GALGAS_string & inOperand2) :
mAttribute_mFormalArgumentKind (inOperand0),
mAttribute_mFormalArgumentType (inOperand1),
mAttribute_mFormalArgumentName (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration_2D_element GALGAS_procFormalArgumentListForGeneration_2D_element::constructor_new (const GALGAS_procFormalArgumentPassingMode & inOperand0,
                                                                                                                              const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                                                                              const GALGAS_string & inOperand2 
                                                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_procFormalArgumentListForGeneration_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_procFormalArgumentListForGeneration_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_procFormalArgumentListForGeneration_2D_element::objectCompare (const GALGAS_procFormalArgumentListForGeneration_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mFormalArgumentKind.objectCompare (inOperand.mAttribute_mFormalArgumentKind) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mFormalArgumentType.objectCompare (inOperand.mAttribute_mFormalArgumentType) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mFormalArgumentName.objectCompare (inOperand.mAttribute_mFormalArgumentName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_procFormalArgumentListForGeneration_2D_element::isValid (void) const {
  return mAttribute_mFormalArgumentKind.isValid () && mAttribute_mFormalArgumentType.isValid () && mAttribute_mFormalArgumentName.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentListForGeneration_2D_element::drop (void) {
  mAttribute_mFormalArgumentKind.drop () ;
  mAttribute_mFormalArgumentType.drop () ;
  mAttribute_mFormalArgumentName.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procFormalArgumentListForGeneration_2D_element::description (C_String & ioString,
                                                                         const int32_t inIndentation) const {
  ioString << "<struct @procFormalArgumentListForGeneration-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mFormalArgumentKind.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mFormalArgumentType.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mFormalArgumentName.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentPassingMode GALGAS_procFormalArgumentListForGeneration_2D_element::getter_mFormalArgumentKind (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mFormalArgumentKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_procFormalArgumentListForGeneration_2D_element::getter_mFormalArgumentType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mFormalArgumentType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_procFormalArgumentListForGeneration_2D_element::getter_mFormalArgumentName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mFormalArgumentName ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  @procFormalArgumentListForGeneration-element type                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procFormalArgumentListForGeneration_2D_element ("procFormalArgumentListForGeneration-element",
                                                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procFormalArgumentListForGeneration_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procFormalArgumentListForGeneration_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procFormalArgumentListForGeneration_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procFormalArgumentListForGeneration_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentListForGeneration_2D_element GALGAS_procFormalArgumentListForGeneration_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                                            C_Compiler * inCompiler
                                                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_procFormalArgumentListForGeneration_2D_element result ;
  const GALGAS_procFormalArgumentListForGeneration_2D_element * p = (const GALGAS_procFormalArgumentListForGeneration_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procFormalArgumentListForGeneration_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procFormalArgumentListForGeneration-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList_2D_element::GALGAS_allocaList_2D_element (void) :
mAttribute_mVarName (),
mAttribute_mType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList_2D_element::~ GALGAS_allocaList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList_2D_element::GALGAS_allocaList_2D_element (const GALGAS_string & inOperand0,
                                                            const GALGAS_unifiedTypeMap_2D_proxy & inOperand1) :
mAttribute_mVarName (inOperand0),
mAttribute_mType (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList_2D_element GALGAS_allocaList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_allocaList_2D_element (GALGAS_string::constructor_default (HERE),
                                       GALGAS_unifiedTypeMap_2D_proxy::constructor_null (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList_2D_element GALGAS_allocaList_2D_element::constructor_new (const GALGAS_string & inOperand0,
                                                                            const GALGAS_unifiedTypeMap_2D_proxy & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_allocaList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_allocaList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_allocaList_2D_element::objectCompare (const GALGAS_allocaList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mVarName.objectCompare (inOperand.mAttribute_mVarName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mType.objectCompare (inOperand.mAttribute_mType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_allocaList_2D_element::isValid (void) const {
  return mAttribute_mVarName.isValid () && mAttribute_mType.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allocaList_2D_element::drop (void) {
  mAttribute_mVarName.drop () ;
  mAttribute_mType.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allocaList_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @allocaList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mVarName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mType.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_allocaList_2D_element::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mVarName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_allocaList_2D_element::getter_mType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mType ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @allocaList-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_allocaList_2D_element ("allocaList-element",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_allocaList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_allocaList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_allocaList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_allocaList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList_2D_element GALGAS_allocaList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_allocaList_2D_element result ;
  const GALGAS_allocaList_2D_element * p = (const GALGAS_allocaList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_allocaList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("allocaList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterMapIR_2D_element::GALGAS_controlRegisterMapIR_2D_element (void) :
mAttribute_lkey (),
mAttribute_mRegisterTypeName (),
mAttribute_mRegisterAddress () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterMapIR_2D_element::~ GALGAS_controlRegisterMapIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterMapIR_2D_element::GALGAS_controlRegisterMapIR_2D_element (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_string & inOperand1,
                                                                                const GALGAS_bigint & inOperand2) :
mAttribute_lkey (inOperand0),
mAttribute_mRegisterTypeName (inOperand1),
mAttribute_mRegisterAddress (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterMapIR_2D_element GALGAS_controlRegisterMapIR_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_controlRegisterMapIR_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                 GALGAS_string::constructor_default (HERE),
                                                 GALGAS_bigint::constructor_zero (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterMapIR_2D_element GALGAS_controlRegisterMapIR_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                const GALGAS_string & inOperand1,
                                                                                                const GALGAS_bigint & inOperand2 
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_controlRegisterMapIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_controlRegisterMapIR_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_controlRegisterMapIR_2D_element::objectCompare (const GALGAS_controlRegisterMapIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mRegisterTypeName.objectCompare (inOperand.mAttribute_mRegisterTypeName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mRegisterAddress.objectCompare (inOperand.mAttribute_mRegisterAddress) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_controlRegisterMapIR_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mRegisterTypeName.isValid () && mAttribute_mRegisterAddress.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterMapIR_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mRegisterTypeName.drop () ;
  mAttribute_mRegisterAddress.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterMapIR_2D_element::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "<struct @controlRegisterMapIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mRegisterTypeName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mRegisterAddress.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_controlRegisterMapIR_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_controlRegisterMapIR_2D_element::getter_mRegisterTypeName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_controlRegisterMapIR_2D_element::getter_mRegisterAddress (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mRegisterAddress ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @controlRegisterMapIR-element type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_controlRegisterMapIR_2D_element ("controlRegisterMapIR-element",
                                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_controlRegisterMapIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_controlRegisterMapIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_controlRegisterMapIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_controlRegisterMapIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterMapIR_2D_element GALGAS_controlRegisterMapIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_controlRegisterMapIR_2D_element result ;
  const GALGAS_controlRegisterMapIR_2D_element * p = (const GALGAS_controlRegisterMapIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_controlRegisterMapIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("controlRegisterMapIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR_2D_element::GALGAS_globalConstantMapIR_2D_element (void) :
mAttribute_lkey (),
mAttribute_mType (),
mAttribute_mSourceExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR_2D_element::~ GALGAS_globalConstantMapIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR_2D_element::GALGAS_globalConstantMapIR_2D_element (const GALGAS_lstring & inOperand0,
                                                                              const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                              const GALGAS_valueIR & inOperand2) :
mAttribute_lkey (inOperand0),
mAttribute_mType (inOperand1),
mAttribute_mSourceExpression (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR_2D_element GALGAS_globalConstantMapIR_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                              const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                                              const GALGAS_valueIR & inOperand2 
                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_globalConstantMapIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_globalConstantMapIR_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_globalConstantMapIR_2D_element::objectCompare (const GALGAS_globalConstantMapIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mType.objectCompare (inOperand.mAttribute_mType) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSourceExpression.objectCompare (inOperand.mAttribute_mSourceExpression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_globalConstantMapIR_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mType.isValid () && mAttribute_mSourceExpression.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMapIR_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mType.drop () ;
  mAttribute_mSourceExpression.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMapIR_2D_element::description (C_String & ioString,
                                                         const int32_t inIndentation) const {
  ioString << "<struct @globalConstantMapIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mType.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSourceExpression.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_globalConstantMapIR_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_globalConstantMapIR_2D_element::getter_mType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_valueIR GALGAS_globalConstantMapIR_2D_element::getter_mSourceExpression (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSourceExpression ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @globalConstantMapIR-element type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_globalConstantMapIR_2D_element ("globalConstantMapIR-element",
                                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_globalConstantMapIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalConstantMapIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_globalConstantMapIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_globalConstantMapIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR_2D_element GALGAS_globalConstantMapIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_globalConstantMapIR_2D_element result ;
  const GALGAS_globalConstantMapIR_2D_element * p = (const GALGAS_globalConstantMapIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_globalConstantMapIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("globalConstantMapIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeMapIR_2D_element::GALGAS_typeMapIR_2D_element (void) :
mAttribute_lkey (),
mAttribute_mType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeMapIR_2D_element::~ GALGAS_typeMapIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeMapIR_2D_element::GALGAS_typeMapIR_2D_element (const GALGAS_lstring & inOperand0,
                                                          const GALGAS_abstractTypeIR & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_mType (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeMapIR_2D_element GALGAS_typeMapIR_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_abstractTypeIR & inOperand1 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeMapIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_typeMapIR_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_typeMapIR_2D_element::objectCompare (const GALGAS_typeMapIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mType.objectCompare (inOperand.mAttribute_mType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_typeMapIR_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mType.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_typeMapIR_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mType.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_typeMapIR_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @typeMapIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mType.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_typeMapIR_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractTypeIR GALGAS_typeMapIR_2D_element::getter_mType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mType ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @typeMapIR-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeMapIR_2D_element ("typeMapIR-element",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_typeMapIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeMapIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_typeMapIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeMapIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeMapIR_2D_element GALGAS_typeMapIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_typeMapIR_2D_element result ;
  const GALGAS_typeMapIR_2D_element * p = (const GALGAS_typeMapIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeMapIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeMapIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR_2D_element::GALGAS_interruptMapIR_2D_element (void) :
mAttribute_lkey (),
mAttribute_mSelfType (),
mAttribute_mGlobalVariableName (),
mAttribute_mAllocaList (),
mAttribute_mInstructionGenerationList (),
mAttribute_mXTR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR_2D_element::~ GALGAS_interruptMapIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR_2D_element::GALGAS_interruptMapIR_2D_element (const GALGAS_lstring & inOperand0,
                                                                    const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                    const GALGAS_string & inOperand2,
                                                                    const GALGAS_allocaList & inOperand3,
                                                                    const GALGAS_instructionListIR & inOperand4,
                                                                    const GALGAS_bool & inOperand5) :
mAttribute_lkey (inOperand0),
mAttribute_mSelfType (inOperand1),
mAttribute_mGlobalVariableName (inOperand2),
mAttribute_mAllocaList (inOperand3),
mAttribute_mInstructionGenerationList (inOperand4),
mAttribute_mXTR (inOperand5) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR_2D_element GALGAS_interruptMapIR_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_interruptMapIR_2D_element (GALGAS_lstring::constructor_default (HERE),
                                           GALGAS_unifiedTypeMap_2D_proxy::constructor_null (HERE),
                                           GALGAS_string::constructor_default (HERE),
                                           GALGAS_allocaList::constructor_emptyList (HERE),
                                           GALGAS_instructionListIR::constructor_emptyList (HERE),
                                           GALGAS_bool::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR_2D_element GALGAS_interruptMapIR_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                    const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                                    const GALGAS_string & inOperand2,
                                                                                    const GALGAS_allocaList & inOperand3,
                                                                                    const GALGAS_instructionListIR & inOperand4,
                                                                                    const GALGAS_bool & inOperand5 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_interruptMapIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid ()) {
    result = GALGAS_interruptMapIR_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_interruptMapIR_2D_element::objectCompare (const GALGAS_interruptMapIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mSelfType.objectCompare (inOperand.mAttribute_mSelfType) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mGlobalVariableName.objectCompare (inOperand.mAttribute_mGlobalVariableName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mAllocaList.objectCompare (inOperand.mAttribute_mAllocaList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mInstructionGenerationList.objectCompare (inOperand.mAttribute_mInstructionGenerationList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mXTR.objectCompare (inOperand.mAttribute_mXTR) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_interruptMapIR_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mSelfType.isValid () && mAttribute_mGlobalVariableName.isValid () && mAttribute_mAllocaList.isValid () && mAttribute_mInstructionGenerationList.isValid () && mAttribute_mXTR.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptMapIR_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mSelfType.drop () ;
  mAttribute_mGlobalVariableName.drop () ;
  mAttribute_mAllocaList.drop () ;
  mAttribute_mInstructionGenerationList.drop () ;
  mAttribute_mXTR.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptMapIR_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @interruptMapIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mSelfType.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mGlobalVariableName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mAllocaList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mInstructionGenerationList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mXTR.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_interruptMapIR_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_interruptMapIR_2D_element::getter_mSelfType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mSelfType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_interruptMapIR_2D_element::getter_mGlobalVariableName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGlobalVariableName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList GALGAS_interruptMapIR_2D_element::getter_mAllocaList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mAllocaList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_interruptMapIR_2D_element::getter_mInstructionGenerationList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInstructionGenerationList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_interruptMapIR_2D_element::getter_mXTR (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mXTR ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @interruptMapIR-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_interruptMapIR_2D_element ("interruptMapIR-element",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_interruptMapIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_interruptMapIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_interruptMapIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_interruptMapIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptMapIR_2D_element GALGAS_interruptMapIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_interruptMapIR_2D_element result ;
  const GALGAS_interruptMapIR_2D_element * p = (const GALGAS_interruptMapIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_interruptMapIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("interruptMapIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR::GALGAS_operandIR (void) :
mAttribute_mType (),
mAttribute_mValue () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR::~ GALGAS_operandIR (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR::GALGAS_operandIR (const GALGAS_unifiedTypeMap_2D_proxy & inOperand0,
                                    const GALGAS_valueIR & inOperand1) :
mAttribute_mType (inOperand0),
mAttribute_mValue (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_operandIR::constructor_new (const GALGAS_unifiedTypeMap_2D_proxy & inOperand0,
                                                    const GALGAS_valueIR & inOperand1 
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_operandIR result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_operandIR (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_operandIR::objectCompare (const GALGAS_operandIR & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mType.objectCompare (inOperand.mAttribute_mType) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mValue.objectCompare (inOperand.mAttribute_mValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_operandIR::isValid (void) const {
  return mAttribute_mType.isValid () && mAttribute_mValue.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_operandIR::drop (void) {
  mAttribute_mType.drop () ;
  mAttribute_mValue.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_operandIR::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "<struct @operandIR:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mType.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_operandIR::getter_mType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_valueIR GALGAS_operandIR::getter_mValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mValue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @operandIR type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_operandIR ("operandIR",
                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_operandIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_operandIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_operandIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_operandIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_operandIR::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_operandIR result ;
  const GALGAS_operandIR * p = (const GALGAS_operandIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_operandIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("operandIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Extension method '@globalVarDeclarationList-element enterInContext'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterInContext (const GALGAS_globalVarDeclarationList_2D_element inObject,
                                     GALGAS_semanticContext & ioArgument_ioContext,
                                     GALGAS_staticStringMap & ioArgument_ioGlobalLiteralStringMap,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_unifiedTypeMap_2D_proxy var_variableAnnotationType ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, inObject.mAttribute_mTypeName.mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_variableAnnotationType = GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-global-variable.galgas", 204)) ;
  }else if (kBoolFalse == test_0) {
    var_variableAnnotationType = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, inObject.mAttribute_mTypeName, inCompiler  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 206)) ;
  }
  GALGAS_semanticTemporariesStruct var_temporaries = GALGAS_semanticTemporariesStruct::constructor_default (SOURCE_FILE ("declaration-global-variable.galgas", 209)) ;
  GALGAS_instructionListIR var_instructionGenerationList = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("declaration-global-variable.galgas", 210)) ;
  GALGAS_allocaList var_allocaList = GALGAS_allocaList::constructor_emptyList (SOURCE_FILE ("declaration-global-variable.galgas", 211)) ;
  GALGAS_variableMap var_variableMap = function_variableMapWithConstants (ioArgument_ioContext, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 212)) ;
  GALGAS_operandIR var_expressionResult ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) inObject.mAttribute_mSourceExpression.ptr (), GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-global-variable.galgas", 214)), GALGAS_bool (false), GALGAS_string ("compiler").getter_nowhere (SOURCE_FILE ("declaration-global-variable.galgas", 216)), var_variableAnnotationType, ioArgument_ioContext, GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("declaration-global-variable.galgas", 219)), GALGAS_bool (true), var_temporaries, ioArgument_ioGlobalLiteralStringMap, var_variableMap, var_allocaList, var_instructionGenerationList, var_expressionResult, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 213)) ;
  GALGAS_bool test_1 = GALGAS_bool (kIsStrictSup, var_instructionGenerationList.getter_length (SOURCE_FILE ("declaration-global-variable.galgas", 228)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
  if (kBoolTrue != test_1.boolEnum ()) {
    test_1 = GALGAS_bool (kIsStrictSup, var_allocaList.getter_length (SOURCE_FILE ("declaration-global-variable.galgas", 228)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
  }
  GALGAS_bool test_2 = test_1 ;
  if (kBoolTrue != test_2.boolEnum ()) {
    test_2 = extensionGetter_isStatic (var_expressionResult.mAttribute_mValue, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 228)).operator_not (SOURCE_FILE ("declaration-global-variable.galgas", 228)) ;
  }
  const enumGalgasBool test_3 = test_2.boolEnum () ;
  if (kBoolTrue == test_3) {
    GALGAS_location location_4 (inObject.mAttribute_mVarName.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_4, GALGAS_string ("source expression cannot be statically computed")  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 229)) ;
  }
  GALGAS_bool test_5 = GALGAS_bool (kIsEqual, var_variableAnnotationType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-global-variable.galgas", 232)))) ;
  if (kBoolTrue == test_5.boolEnum ()) {
    test_5 = var_expressionResult.mAttribute_mType.getter_kind (inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 232)).getter_isStaticInteger (SOURCE_FILE ("declaration-global-variable.galgas", 232)) ;
  }
  const enumGalgasBool test_6 = test_5.boolEnum () ;
  if (kBoolTrue == test_6) {
    GALGAS_location location_7 (inObject.mAttribute_mVarName.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_7, GALGAS_string ("cannot infer type")  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 233)) ;
  }
  GALGAS_operandIR var_result = function_checkAssignmentCompatibility (var_expressionResult, var_variableAnnotationType, inObject.mAttribute_mVarName.mAttribute_location, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 235)) ;
  GALGAS_stringset var_executionModes = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("declaration-global-variable.galgas", 241)) ;
  GALGAS_allowedRoutineMap var_allowedRoutineMap = GALGAS_allowedRoutineMap::constructor_emptyMap (SOURCE_FILE ("declaration-global-variable.galgas", 243)) ;
  cEnumerator_allowedInitList enumerator_8651 (inObject.mAttribute_mAllowedInitList, kEnumeration_up) ;
  while (enumerator_8651.hasCurrentObject ()) {
    ioArgument_ioContext.mAttribute_mInitRoutineMap.method_searchKey (GALGAS_lstring::constructor_new (enumerator_8651.current_mInitPriority (HERE).mAttribute_bigint.getter_string (SOURCE_FILE ("declaration-global-variable.galgas", 245)), enumerator_8651.current_mInitPriority (HERE).mAttribute_location  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 245)), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 245)) ;
    {
    var_allowedRoutineMap.setter_insertKey (function_initNameForInvocationGraph (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-global-variable.galgas", 246)), enumerator_8651.current_mInitPriority (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 246)), enumerator_8651.current_mHasWriteAccess (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 246)) ;
    }
    enumerator_8651.gotoNextObject () ;
  }
  cEnumerator_allowedPanicList enumerator_8946 (inObject.mAttribute_mAllowedPanicList, kEnumeration_up) ;
  while (enumerator_8946.hasCurrentObject ()) {
    const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, enumerator_8946.current_mPanicName (HERE).mAttribute_string.objectCompare (GALGAS_string ("setup"))).boolEnum () ;
    if (kBoolTrue == test_8) {
      ioArgument_ioContext.mAttribute_mPanicSetupRoutinePriorityMap.method_searchSetupKey (GALGAS_lstring::constructor_new (enumerator_8946.current_mPanicPriority (HERE).mAttribute_bigint.getter_string (SOURCE_FILE ("declaration-global-variable.galgas", 252)), enumerator_8946.current_mPanicPriority (HERE).mAttribute_location  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 252)), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 251)) ;
    }else if (kBoolFalse == test_8) {
      const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, enumerator_8946.current_mPanicName (HERE).mAttribute_string.objectCompare (GALGAS_string ("loop"))).boolEnum () ;
      if (kBoolTrue == test_9) {
        ioArgument_ioContext.mAttribute_mPanicLoopRoutinePriorityMap.method_searchLoopKey (GALGAS_lstring::constructor_new (enumerator_8946.current_mPanicPriority (HERE).mAttribute_bigint.getter_string (SOURCE_FILE ("declaration-global-variable.galgas", 257)), enumerator_8946.current_mPanicPriority (HERE).mAttribute_location  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 257)), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 256)) ;
      }else if (kBoolFalse == test_9) {
        GALGAS_location location_10 (enumerator_8946.current_mPanicName (HERE).getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_10, GALGAS_string ("panic routine name should be \"setup\" or \"loop\"")  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 261)) ;
      }
    }
    {
    var_allowedRoutineMap.setter_insertKey (function_panicNameForInvocationGraph (enumerator_8946.current_mPanicName (HERE).mAttribute_string, enumerator_8946.current_mPanicPriority (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 264)), enumerator_8946.current_mHasWriteAccess (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 263)) ;
    }
    enumerator_8946.gotoNextObject () ;
  }
  cEnumerator_allowedRoutineList enumerator_9677 (inObject.mAttribute_mAllowedProcList, kEnumeration_up) ;
  while (enumerator_9677.hasCurrentObject ()) {
    GALGAS_lstring var_routineMangledName ;
    GALGAS_unifiedTypeMap_2D_proxy var_receiverType ;
    const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, enumerator_9677.current (HERE).mAttribute_mReceiverTypeName.mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_11) {
      var_routineMangledName = GALGAS_lstring::constructor_new (GALGAS_string (".").add_operation (enumerator_9677.current (HERE).mAttribute_mRoutineName.getter_string (SOURCE_FILE ("declaration-global-variable.galgas", 273)), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 273)), enumerator_9677.current (HERE).mAttribute_mRoutineName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 273)) ;
      var_receiverType = GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-global-variable.galgas", 274)) ;
    }else if (kBoolFalse == test_11) {
      var_routineMangledName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (enumerator_9677.current (HERE).mAttribute_mReceiverTypeName.getter_string (SOURCE_FILE ("declaration-global-variable.galgas", 276)), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 276)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 276)).add_operation (enumerator_9677.current (HERE).mAttribute_mRoutineName.getter_string (SOURCE_FILE ("declaration-global-variable.galgas", 276)), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 276)), enumerator_9677.current (HERE).mAttribute_mRoutineName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 276)) ;
      var_receiverType = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_9677.current (HERE).mAttribute_mReceiverTypeName, inCompiler  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 277)) ;
    }
    GALGAS_bool var_isPublic ;
    GALGAS_modeMap var_procedureModeMap ;
    GALGAS_procedureSignature joker_10318_4 ; // Joker input parameter
    GALGAS_routineKind joker_10318_3 ; // Joker input parameter
    GALGAS_bool joker_10318_2 ; // Joker input parameter
    GALGAS_unifiedTypeMap_2D_proxy joker_10318_1 ; // Joker input parameter
    ioArgument_ioContext.mAttribute_mRoutineMapForContext.method_searchKey (var_routineMangledName, var_isPublic, var_procedureModeMap, joker_10318_4, joker_10318_3, joker_10318_2, joker_10318_1, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 279)) ;
    cEnumerator_modeMap enumerator_10357 (var_procedureModeMap, kEnumeration_up) ;
    while (enumerator_10357.hasCurrentObject ()) {
      var_executionModes.addAssign_operation (enumerator_10357.current_lkey (HERE).mAttribute_string  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 286)) ;
      enumerator_10357.gotoNextObject () ;
    }
    GALGAS_lstring var_routineNameForInvocationGraph ;
    switch (enumerator_9677.current (HERE).mAttribute_mRoutineKind.enumValue ()) {
    case GALGAS_routineKind::kNotBuilt:
      break ;
    case GALGAS_routineKind::kEnum_function:
      {
        var_routineNameForInvocationGraph = function_procNameForInvocationGraph (var_receiverType, enumerator_9677.current (HERE).mAttribute_mRoutineName, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 290)) ;
      }
      break ;
    case GALGAS_routineKind::kEnum_section:
      {
        var_routineNameForInvocationGraph = function_sectionNameForInvocationGraph (var_receiverType, enumerator_9677.current (HERE).mAttribute_mRoutineName, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 291)) ;
      }
      break ;
    case GALGAS_routineKind::kEnum_service:
      {
        var_routineNameForInvocationGraph = function_serviceNameForInvocationGraph (var_receiverType, enumerator_9677.current (HERE).mAttribute_mRoutineName, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 292)) ;
      }
      break ;
    case GALGAS_routineKind::kEnum_primitive:
      {
        var_routineNameForInvocationGraph = function_primitiveNameForInvocationGraph (var_receiverType, enumerator_9677.current (HERE).mAttribute_mRoutineName, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 293)) ;
      }
      break ;
    }
    {
    var_allowedRoutineMap.setter_insertKey (var_routineNameForInvocationGraph, enumerator_9677.current (HERE).mAttribute_mHasWriteAccess, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 295)) ;
    }
    enumerator_9677.gotoNextObject () ;
  }
  GALGAS_allowedGuardMap var_allowedGuardMap = GALGAS_allowedGuardMap::constructor_emptyMap (SOURCE_FILE ("declaration-global-variable.galgas", 298)) ;
  cEnumerator_allowedGuardList enumerator_11187 (inObject.mAttribute_mAllowedGuardList, kEnumeration_up) ;
  while (enumerator_11187.hasCurrentObject ()) {
    GALGAS_lstring var_guardMangledName ;
    GALGAS_unifiedTypeMap_2D_proxy var_receiverType ;
    const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, enumerator_11187.current (HERE).mAttribute_mOptionalTypeName.mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_12) {
      var_guardMangledName = GALGAS_lstring::constructor_new (GALGAS_string (".").add_operation (enumerator_11187.current (HERE).mAttribute_mGuardName.getter_string (SOURCE_FILE ("declaration-global-variable.galgas", 303)), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 303)), enumerator_11187.current (HERE).mAttribute_mGuardName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 303)) ;
      var_receiverType = GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-global-variable.galgas", 304)) ;
    }else if (kBoolFalse == test_12) {
      var_guardMangledName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (enumerator_11187.current (HERE).mAttribute_mOptionalTypeName.getter_string (SOURCE_FILE ("declaration-global-variable.galgas", 306)), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 306)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 306)).add_operation (enumerator_11187.current (HERE).mAttribute_mGuardName.getter_string (SOURCE_FILE ("declaration-global-variable.galgas", 306)), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 306)), enumerator_11187.current (HERE).mAttribute_mGuardName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 306)) ;
      var_receiverType = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_11187.current (HERE).mAttribute_mOptionalTypeName, inCompiler  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 307)) ;
    }
    GALGAS_bool var_isPublic ;
    GALGAS_procedureSignature joker_11754 ; // Joker input parameter
    ioArgument_ioContext.mAttribute_mGuardMapForContext.method_searchKey (var_guardMangledName, var_isPublic, joker_11754, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 309)) ;
    var_executionModes.addAssign_operation (function_serviceModeName (inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 314))  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 314)) ;
    GALGAS_lstring var_routineNameForInvocationGraph = function_guardNameForInvocationGraph (var_receiverType, enumerator_11187.current (HERE).mAttribute_mGuardName, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 315)) ;
    {
    var_allowedGuardMap.setter_insertKey (var_routineNameForInvocationGraph, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 316)) ;
    }
    enumerator_11187.gotoNextObject () ;
  }
  GALGAS_allowedISRMap var_allowedISRMap = GALGAS_allowedISRMap::constructor_emptyMap (SOURCE_FILE ("declaration-global-variable.galgas", 319)) ;
  cEnumerator_allowedISRList enumerator_12076 (inObject.mAttribute_mAllowedISRList, kEnumeration_up) ;
  while (enumerator_12076.hasCurrentObject ()) {
    GALGAS_lstring var_name = function_interruptNameForInvocationGraph (enumerator_12076.current (HERE).mAttribute_mISRName, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 321)) ;
    {
    var_allowedISRMap.setter_insertKey (var_name, enumerator_12076.current (HERE).mAttribute_mHasWriteAccess, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 322)) ;
    }
    const enumGalgasBool test_13 = ioArgument_ioContext.mAttribute_mDefinedInterruptSet.getter_hasKey (enumerator_12076.current (HERE).mAttribute_mISRName.mAttribute_string COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 323)).operator_not (SOURCE_FILE ("declaration-global-variable.galgas", 323)).boolEnum () ;
    if (kBoolTrue == test_13) {
      GALGAS_location location_14 (enumerator_12076.current (HERE).mAttribute_mISRName.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_14, GALGAS_string ("this isr is not defined")  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 324)) ;
    }
    enumerator_12076.gotoNextObject () ;
  }
  {
  ioArgument_ioContext.mAttribute_mGlobalVariableMap.setter_insertKey (inObject.mAttribute_mVarName, var_result.mAttribute_mType, var_executionModes, var_allowedRoutineMap, var_allowedGuardMap, var_allowedISRMap, var_result.mAttribute_mValue, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 328)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR_2D_element::GALGAS_globalVariableMapIR_2D_element (void) :
mAttribute_lkey (),
mAttribute_mType (),
mAttribute_mGenerateVolatile (),
mAttribute_mInitialValue () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR_2D_element::~ GALGAS_globalVariableMapIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR_2D_element::GALGAS_globalVariableMapIR_2D_element (const GALGAS_lstring & inOperand0,
                                                                              const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                              const GALGAS_bool & inOperand2,
                                                                              const GALGAS_valueIR & inOperand3) :
mAttribute_lkey (inOperand0),
mAttribute_mType (inOperand1),
mAttribute_mGenerateVolatile (inOperand2),
mAttribute_mInitialValue (inOperand3) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR_2D_element GALGAS_globalVariableMapIR_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                              const GALGAS_unifiedTypeMap_2D_proxy & inOperand1,
                                                                                              const GALGAS_bool & inOperand2,
                                                                                              const GALGAS_valueIR & inOperand3 
                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_globalVariableMapIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    result = GALGAS_globalVariableMapIR_2D_element (inOperand0, inOperand1, inOperand2, inOperand3) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_globalVariableMapIR_2D_element::objectCompare (const GALGAS_globalVariableMapIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mType.objectCompare (inOperand.mAttribute_mType) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mGenerateVolatile.objectCompare (inOperand.mAttribute_mGenerateVolatile) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mInitialValue.objectCompare (inOperand.mAttribute_mInitialValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_globalVariableMapIR_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mType.isValid () && mAttribute_mGenerateVolatile.isValid () && mAttribute_mInitialValue.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMapIR_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mType.drop () ;
  mAttribute_mGenerateVolatile.drop () ;
  mAttribute_mInitialValue.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMapIR_2D_element::description (C_String & ioString,
                                                         const int32_t inIndentation) const {
  ioString << "<struct @globalVariableMapIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mType.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mGenerateVolatile.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mInitialValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_globalVariableMapIR_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_globalVariableMapIR_2D_element::getter_mType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_globalVariableMapIR_2D_element::getter_mGenerateVolatile (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGenerateVolatile ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_valueIR GALGAS_globalVariableMapIR_2D_element::getter_mInitialValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInitialValue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @globalVariableMapIR-element type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_globalVariableMapIR_2D_element ("globalVariableMapIR-element",
                                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_globalVariableMapIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalVariableMapIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_globalVariableMapIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_globalVariableMapIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR_2D_element GALGAS_globalVariableMapIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_globalVariableMapIR_2D_element result ;
  const GALGAS_globalVariableMapIR_2D_element * p = (const GALGAS_globalVariableMapIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_globalVariableMapIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("globalVariableMapIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension method '@taskVarListAST-element enterInContext'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterInContext (const GALGAS_taskVarListAST_2D_element inObject,
                                     GALGAS_semanticContext & ioArgument_ioContext,
                                     GALGAS_staticStringMap & ioArgument_ioGlobalLiteralStringMap,
                                     GALGAS_propertyList & ioArgument_ioPropertyList,
                                     GALGAS_propertyMap & ioArgument_ioPropertyMap,
                                     GALGAS_operandIRList & ioArgument_ioInitialValueList,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_unifiedTypeMap_2D_proxy var_variableAnnotationType ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, inObject.mAttribute_mVarTypeName.mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_variableAnnotationType = GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-task.galgas", 218)) ;
  }else if (kBoolFalse == test_0) {
    var_variableAnnotationType = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, inObject.mAttribute_mVarTypeName, inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 220)) ;
  }
  GALGAS_semanticTemporariesStruct var_temporaries = GALGAS_semanticTemporariesStruct::constructor_default (SOURCE_FILE ("declaration-task.galgas", 223)) ;
  GALGAS_instructionListIR var_instructionGenerationList = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 224)) ;
  GALGAS_allocaList var_allocaList = GALGAS_allocaList::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 225)) ;
  GALGAS_variableMap var_variableMap = function_variableMapWithConstants (ioArgument_ioContext, inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 226)) ;
  GALGAS_operandIR var_expressionResult ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) inObject.mAttribute_mVarInitExpression.ptr (), GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-task.galgas", 228)), GALGAS_bool (false), GALGAS_string ("compiler").getter_nowhere (SOURCE_FILE ("declaration-task.galgas", 230)), var_variableAnnotationType, ioArgument_ioContext, GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("declaration-task.galgas", 233)), GALGAS_bool (true), var_temporaries, ioArgument_ioGlobalLiteralStringMap, var_variableMap, var_allocaList, var_instructionGenerationList, var_expressionResult, inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 227)) ;
  GALGAS_bool test_1 = GALGAS_bool (kIsStrictSup, var_instructionGenerationList.getter_length (SOURCE_FILE ("declaration-task.galgas", 242)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
  if (kBoolTrue != test_1.boolEnum ()) {
    test_1 = GALGAS_bool (kIsStrictSup, var_allocaList.getter_length (SOURCE_FILE ("declaration-task.galgas", 242)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
  }
  GALGAS_bool test_2 = test_1 ;
  if (kBoolTrue != test_2.boolEnum ()) {
    test_2 = extensionGetter_isStatic (var_expressionResult.mAttribute_mValue, inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 242)).operator_not (SOURCE_FILE ("declaration-task.galgas", 242)) ;
  }
  const enumGalgasBool test_3 = test_2.boolEnum () ;
  if (kBoolTrue == test_3) {
    GALGAS_location location_4 (inObject.mAttribute_mVarName.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_4, GALGAS_string ("source expression cannot be statically computed")  COMMA_SOURCE_FILE ("declaration-task.galgas", 243)) ;
  }
  GALGAS_bool test_5 = GALGAS_bool (kIsEqual, var_variableAnnotationType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-task.galgas", 246)))) ;
  if (kBoolTrue == test_5.boolEnum ()) {
    test_5 = var_expressionResult.mAttribute_mType.getter_kind (inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 246)).getter_isStaticInteger (SOURCE_FILE ("declaration-task.galgas", 246)) ;
  }
  const enumGalgasBool test_6 = test_5.boolEnum () ;
  if (kBoolTrue == test_6) {
    GALGAS_location location_7 (inObject.mAttribute_mVarName.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_7, GALGAS_string ("cannot infer type")  COMMA_SOURCE_FILE ("declaration-task.galgas", 247)) ;
  }
  GALGAS_operandIR var_result = function_checkAssignmentCompatibility (var_expressionResult, var_variableAnnotationType, inObject.mAttribute_mVarName.mAttribute_location, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 249)) ;
  const enumGalgasBool test_8 = var_result.mAttribute_mType.getter_instantiable (inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 257)).operator_not (SOURCE_FILE ("declaration-task.galgas", 257)).boolEnum () ;
  if (kBoolTrue == test_8) {
    GALGAS_location location_9 (inObject.mAttribute_mVarName.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_9, GALGAS_string ("$").add_operation (var_result.mAttribute_mType.getter_key (inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 258)), inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 258)).add_operation (GALGAS_string (" type is not instanciable"), inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 258))  COMMA_SOURCE_FILE ("declaration-task.galgas", 258)) ;
  }
  ioArgument_ioPropertyList.addAssign_operation (inObject.mAttribute_mVarName.mAttribute_string, var_result.mAttribute_mType  COMMA_SOURCE_FILE ("declaration-task.galgas", 260)) ;
  {
  ioArgument_ioPropertyMap.setter_insertKey (inObject.mAttribute_mVarName, GALGAS_bool (false), var_result.mAttribute_mType, ioArgument_ioPropertyMap.getter_count (SOURCE_FILE ("declaration-task.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 261)) ;
  }
  ioArgument_ioInitialValueList.addAssign_operation (var_result  COMMA_SOURCE_FILE ("declaration-task.galgas", 262)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension method '@taskList-element semanticAnalysis'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_semanticAnalysis (const GALGAS_taskList_2D_element inObject,
                                       const GALGAS_semanticContext constinArgument_inContext,
                                       GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                       GALGAS_intermediateCodeStruct & ioArgument_ioIntermediateCodeStruct,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint var_stackSize = inObject.mAttribute_mStackSize.mAttribute_bigint ;
  GALGAS_bool test_0 = GALGAS_bool (kIsStrictInf, var_stackSize.objectCompare (GALGAS_bigint ("64", inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 298)))) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    test_0 = GALGAS_bool (kIsNotEqual, var_stackSize.modulo_operation (GALGAS_bigint ("8", inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 298)), inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 298)).objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 298)))) ;
  }
  const enumGalgasBool test_1 = test_0.boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_location location_2 (inObject.mAttribute_mStackSize.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_2, GALGAS_string ("stack size should be a multiple of 8, and >= 64")  COMMA_SOURCE_FILE ("declaration-task.galgas", 299)) ;
  }
  GALGAS_unifiedTypeMap_2D_proxy var_taskType = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.mAttribute_mTypeMap, inObject.mAttribute_mTaskName, inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 302)) ;
  cEnumerator_procedureDeclarationListAST enumerator_11401 (inObject.mAttribute_mTaskProcList, kEnumeration_up) ;
  while (enumerator_11401.hasCurrentObject ()) {
    {
    GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 307)) ;
    temp_3.addAssign_operation (GALGAS_lstring::constructor_new (function_userModeName (inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 307)), enumerator_11401.current (HERE).mAttribute_mProcedureName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-task.galgas", 307))  COMMA_SOURCE_FILE ("declaration-task.galgas", 307)) ;
    routine_routineSemanticAnalysis (var_taskType, GALGAS_routineKind::constructor_function (SOURCE_FILE ("declaration-task.galgas", 306)), temp_3, enumerator_11401.current (HERE).mAttribute_mProcedureName, enumerator_11401.current (HERE).mAttribute_mProcedureFormalArgumentList, enumerator_11401.current (HERE).mAttribute_mReturnTypeName, enumerator_11401.current (HERE).mAttribute_mProcedureInstructionList, enumerator_11401.current (HERE).mAttribute_mEndOfProcedureDeclaration, GALGAS_bool (true), GALGAS_bool (false), GALGAS_bool (false), GALGAS_accessKind::constructor_noAccess (SOURCE_FILE ("declaration-task.galgas", 316)), constinArgument_inContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 304)) ;
    }
    enumerator_11401.gotoNextObject () ;
  }
  GALGAS_taskInitSortedListAST var_taskInitSortedListAST = GALGAS_taskInitSortedListAST::constructor_emptySortedList (SOURCE_FILE ("declaration-task.galgas", 323)) ;
  cEnumerator_taskInitListAST enumerator_12188 (inObject.mAttribute_mTaskInitListAST, kEnumeration_up) ;
  while (enumerator_12188.hasCurrentObject ()) {
    var_taskInitSortedListAST.addAssign_operation (enumerator_12188.current_mTaskInitPriority (HERE), enumerator_12188.current_mTaskInitInstructionList (HERE), enumerator_12188.current_mEndOfTaskInitDeclaration (HERE), enumerator_12188.current_mTaskInitPriority (HERE).mAttribute_bigint  COMMA_SOURCE_FILE ("declaration-task.galgas", 325)) ;
    enumerator_12188.gotoNextObject () ;
  }
  GALGAS_instructionListIR var_initInstructionListIR = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 327)) ;
  GALGAS_allocaList var_initAllocaList = GALGAS_allocaList::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 328)) ;
  cEnumerator_taskInitSortedListAST enumerator_12471 (var_taskInitSortedListAST, kEnumeration_up) ;
  while (enumerator_12471.hasCurrentObject ()) {
    GALGAS_allocaList var_partialAllocaList ;
    GALGAS_instructionListIR var_partialInstructionGenerationList ;
    {
    GALGAS_stringset temp_4 = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("declaration-task.galgas", 336)) ;
    temp_4.addAssign_operation (function_userModeName (inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 336))  COMMA_SOURCE_FILE ("declaration-task.galgas", 336)) ;
    routine_initSemanticAnalysis (constinArgument_inContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, var_taskType, enumerator_12471.current_mTaskInitPriority (HERE), temp_4, GALGAS__32_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 337)), enumerator_12471.current_mTaskInitInstructionList (HERE), enumerator_12471.current_mEndOfTaskInitDeclaration (HERE), var_partialAllocaList, var_partialInstructionGenerationList, inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 330)) ;
    }
    var_initInstructionListIR.plusAssign_operation(var_partialInstructionGenerationList, inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 343)) ;
    var_initAllocaList.plusAssign_operation(var_partialAllocaList, inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 344)) ;
    enumerator_12471.gotoNextObject () ;
  }
  GALGAS_instructionListAST var_taskListInstructionList = GALGAS_instructionListAST::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 348)) ;
  const enumGalgasBool test_5 = GALGAS_bool (kIsStrictSup, inObject.mAttribute_mGuardedCommandList.getter_length (SOURCE_FILE ("declaration-task.galgas", 349)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_5) {
    GALGAS_syncInstructionAST var_syncInstruction = GALGAS_syncInstructionAST::constructor_new (inObject.mAttribute_mTaskName.mAttribute_location, inObject.mAttribute_mGuardedCommandList, inObject.mAttribute_mTaskName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-task.galgas", 350)) ;
    var_taskListInstructionList.addAssign_operation (var_syncInstruction  COMMA_SOURCE_FILE ("declaration-task.galgas", 351)) ;
  }
  {
  GALGAS_lstringlist temp_6 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 356)) ;
  temp_6.addAssign_operation (GALGAS_lstring::constructor_new (function_userModeName (inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 356)), inObject.mAttribute_mTaskName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-task.galgas", 356))  COMMA_SOURCE_FILE ("declaration-task.galgas", 356)) ;
  routine_routineSemanticAnalysis (var_taskType, GALGAS_routineKind::constructor_function (SOURCE_FILE ("declaration-task.galgas", 355)), temp_6, GALGAS_lstring::constructor_new (function_llvmNameForTaskLoopFunction (inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 357)), inObject.mAttribute_mTaskName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-task.galgas", 357)), GALGAS_procFormalArgumentList::constructor_emptyList (SOURCE_FILE ("declaration-task.galgas", 358)), GALGAS_string::makeEmptyString ().getter_nowhere (SOURCE_FILE ("declaration-task.galgas", 359)), var_taskListInstructionList, inObject.mAttribute_mTaskName.mAttribute_location, GALGAS_bool (true), GALGAS_bool (false), GALGAS_bool (false), GALGAS_accessKind::constructor_noAccess (SOURCE_FILE ("declaration-task.galgas", 365)), constinArgument_inContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler  COMMA_SOURCE_FILE ("declaration-task.galgas", 353)) ;
  }
  {
  ioArgument_ioIntermediateCodeStruct.mAttribute_mTaskMapIR.setter_insertKey (inObject.mAttribute_mTaskName, var_taskType, inObject.mAttribute_mPriority.mAttribute_bigint, inObject.mAttribute_mStackSize.mAttribute_bigint, var_initAllocaList, var_initInstructionListIR, inCompiler COMMA_SOURCE_FILE ("declaration-task.galgas", 371)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension method '@panicClauseListAST-element enterInContext'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterInContext (const GALGAS_panicClauseListAST_2D_element inObject,
                                     GALGAS_semanticContext & ioArgument_ioContext,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, inObject.mAttribute_mPanicClauseName.mAttribute_string.objectCompare (GALGAS_string ("setup"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    ioArgument_ioContext.mAttribute_mPanicSetupRoutinePriorityMap.setter_insertSetupKey (GALGAS_lstring::constructor_new (inObject.mAttribute_mPriority.mAttribute_bigint.getter_string (SOURCE_FILE ("panic.galgas", 63)), inObject.mAttribute_mLocationPriority  COMMA_SOURCE_FILE ("panic.galgas", 63)), inCompiler COMMA_SOURCE_FILE ("panic.galgas", 63)) ;
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, inObject.mAttribute_mPanicClauseName.mAttribute_string.objectCompare (GALGAS_string ("loop"))).boolEnum () ;
    if (kBoolTrue == test_1) {
      {
      ioArgument_ioContext.mAttribute_mPanicLoopRoutinePriorityMap.setter_insertLoopKey (GALGAS_lstring::constructor_new (inObject.mAttribute_mPriority.mAttribute_bigint.getter_string (SOURCE_FILE ("panic.galgas", 65)), inObject.mAttribute_mLocationPriority  COMMA_SOURCE_FILE ("panic.galgas", 65)), inCompiler COMMA_SOURCE_FILE ("panic.galgas", 65)) ;
      }
    }else if (kBoolFalse == test_1) {
      GALGAS_location location_2 (inObject.mAttribute_mPanicClauseName.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_2, GALGAS_string ("panic routine name should be \"setup\" or \"loop\"")  COMMA_SOURCE_FILE ("panic.galgas", 67)) ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@initList-element enterInContext'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterInContext (const GALGAS_initList_2D_element inObject,
                                     GALGAS_semanticContext & ioArgument_ioContext,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioContext.mAttribute_mInitRoutineMap.setter_insertKey (GALGAS_lstring::constructor_new (inObject.mAttribute_mPriority.mAttribute_bigint.getter_string (SOURCE_FILE ("declaration-init.galgas", 76)), inObject.mAttribute_mPriority.mAttribute_location  COMMA_SOURCE_FILE ("declaration-init.galgas", 76)), inCompiler COMMA_SOURCE_FILE ("declaration-init.galgas", 76)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//               Extension method '@externProcedureDeclarationListAST-element enterExternProcInContext'                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterExternProcInContext (const GALGAS_externProcedureDeclarationListAST_2D_element inObject,
                                               GALGAS_semanticContext & ioArgument_ioContext,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_procedureSignature var_signature = GALGAS_procedureSignature::constructor_emptyList (SOURCE_FILE ("declaration-extern-proc.galgas", 73)) ;
  cEnumerator_procFormalArgumentList enumerator_3407 (inObject.mAttribute_mProcFormalArgumentList, kEnumeration_up) ;
  while (enumerator_3407.hasCurrentObject ()) {
    GALGAS_unifiedTypeMap_2D_proxy var_typeProxy = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_3407.current_mFormalArgumentTypeName (HERE), inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 75)) ;
    var_signature.addAssign_operation (enumerator_3407.current_mFormalArgumentPassingMode (HERE), enumerator_3407.current_mSelector (HERE).mAttribute_string, var_typeProxy  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 76)) ;
    enumerator_3407.gotoNextObject () ;
  }
  GALGAS_modeMap var_procedureModeMap = GALGAS_modeMap::constructor_emptyMap (SOURCE_FILE ("declaration-extern-proc.galgas", 79)) ;
  cEnumerator_lstringlist enumerator_3664 (inObject.mAttribute_mProcedureModeList, kEnumeration_up) ;
  while (enumerator_3664.hasCurrentObject ()) {
    ioArgument_ioContext.mAttribute_mModeMap.method_searchKey (enumerator_3664.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 81)) ;
    {
    var_procedureModeMap.setter_insertKey (enumerator_3664.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 82)) ;
    }
    enumerator_3664.gotoNextObject () ;
  }
  GALGAS_unifiedTypeMap_2D_proxy temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, inObject.mAttribute_mReturnTypeName.mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-extern-proc.galgas", 86)) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, inObject.mAttribute_mReturnTypeName, inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 88)) ;
  }
  GALGAS_unifiedTypeMap_2D_proxy var_returnType = temp_0 ;
  {
  ioArgument_ioContext.mAttribute_mRoutineMapForContext.setter_insertKey (GALGAS_lstring::constructor_new (GALGAS_string (".").add_operation (inObject.mAttribute_mExternProcedureName.getter_string (SOURCE_FILE ("declaration-extern-proc.galgas", 91)), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 91)), inObject.mAttribute_mExternProcedureName.mAttribute_location  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 91)), GALGAS_bool (true), var_procedureModeMap, var_signature, GALGAS_routineKind::constructor_function (SOURCE_FILE ("declaration-extern-proc.galgas", 95)), GALGAS_bool (false), var_returnType, inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 90)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Extension method '@externProcedureMapIR-element llvmPrototypeGeneration'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_llvmPrototypeGeneration (const GALGAS_externProcedureMapIR_2D_element inObject,
                                              GALGAS_string & ioArgument_ioLLVMcode,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_procName = function_llvmNameForFunction (GALGAS_string (".").add_operation (inObject.mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 192)), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 192)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(function_llvmTitleComment (GALGAS_string ("extern procedure ").add_operation (inObject.mAttribute_lkey.getter_string (SOURCE_FILE ("declaration-extern-proc.galgas", 193)), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 193)), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 193)), inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 193)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("declare"), inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 194)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, inObject.mAttribute_mReturnType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("declaration-extern-proc.galgas", 195)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" void"), inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 196)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" ").add_operation (inObject.mAttribute_mReturnType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 198)), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 198)), inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 198)) ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" @").add_operation (var_procName, inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 200)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 200)), inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 200)) ;
  cEnumerator_procFormalArgumentListForGeneration enumerator_8250 (inObject.mAttribute_mFormalArgumentListForGeneration, kEnumeration_up) ;
  while (enumerator_8250.hasCurrentObject ()) {
    switch (enumerator_8250.current_mFormalArgumentKind (HERE).enumValue ()) {
    case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_input:
      {
        ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8250.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 205)).add_operation (GALGAS_string (" %in."), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 205)).add_operation (enumerator_8250.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 205)), inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 205)) ;
      }
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_output:
      {
        ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8250.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 207)).add_operation (GALGAS_string ("* %"), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 207)).add_operation (enumerator_8250.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 207)), inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 207)) ;
      }
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
      {
        ioArgument_ioLLVMcode.plusAssign_operation(enumerator_8250.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 209)).add_operation (GALGAS_string ("* %"), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 209)).add_operation (enumerator_8250.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 209)), inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 209)) ;
      }
      break ;
    }
    if (enumerator_8250.hasNextObject ()) {
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 212)) ;
    }
    enumerator_8250.gotoNextObject () ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (")").add_operation (function_llvmAttributeFunction (inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 214)), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 214)).add_operation (GALGAS_string ("; defined in C\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 214)), inCompiler  COMMA_SOURCE_FILE ("declaration-extern-proc.galgas", 214)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension method '@guardMapIR-element llvmCodeGeneration'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_llvmCodeGeneration (const GALGAS_guardMapIR_2D_element inObject,
                                         GALGAS_string & ioArgument_ioLLVMcode,
                                         const GALGAS_generationContext constinArgument_inGenerationContext,
                                         GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_guardRoutineName ;
  switch (inObject.mAttribute_mGuardKindGenerationIR.enumValue ()) {
  case GALGAS_guardKindGenerationIR::kNotBuilt:
    break ;
  case GALGAS_guardKindGenerationIR::kEnum_convenienceGuard:
    {
      var_guardRoutineName = function_llvmNameForGuardCall (inObject.mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 578)) ;
    }
    break ;
  case GALGAS_guardKindGenerationIR::kEnum_baseGuard:
    {
      var_guardRoutineName = function_llvmNameForGuardImplementation (inObject.mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 580)) ;
    }
    break ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(function_llvmTitleComment (var_guardRoutineName, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 582)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 582)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("define i1 @").add_operation (var_guardRoutineName, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 583)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 583)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 583)) ;
  GALGAS_string var_receiverTypeName = inObject.mAttribute_lkey.mAttribute_string.getter_stringByDeletingPathExtension (SOURCE_FILE ("declaration-guard.galgas", 584)) ;
  GALGAS_bool var_first = GALGAS_bool (true) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_receiverTypeName.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("%").add_operation (var_receiverTypeName, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 587)).add_operation (GALGAS_string ("* %self"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 587)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 587)) ;
    var_first = GALGAS_bool (false) ;
  }
  cEnumerator_procFormalArgumentListForGeneration enumerator_23998 (inObject.mAttribute_mFormalArgumentListForGeneration, kEnumeration_up) ;
  while (enumerator_23998.hasCurrentObject ()) {
    const enumGalgasBool test_1 = var_first.boolEnum () ;
    if (kBoolTrue == test_1) {
      var_first = GALGAS_bool (false) ;
    }else if (kBoolFalse == test_1) {
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 594)) ;
    }
    switch (enumerator_23998.current_mFormalArgumentKind (HERE).enumValue ()) {
    case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_input:
      {
        ioArgument_ioLLVMcode.plusAssign_operation(enumerator_23998.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 598)).add_operation (GALGAS_string (" %in."), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 598)).add_operation (enumerator_23998.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 598)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 598)) ;
      }
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_output:
      {
        ioArgument_ioLLVMcode.plusAssign_operation(enumerator_23998.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 600)).add_operation (GALGAS_string ("* %"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 600)).add_operation (enumerator_23998.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 600)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 600)) ;
      }
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
      {
        ioArgument_ioLLVMcode.plusAssign_operation(enumerator_23998.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 602)).add_operation (GALGAS_string ("* %"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 602)).add_operation (enumerator_23998.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 602)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 602)) ;
      }
      break ;
    }
    enumerator_23998.gotoNextObject () ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (")").add_operation (function_llvmAttributeFunction (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 605)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 605)).add_operation (GALGAS_string ("{\n"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 605)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 605)) ;
  GALGAS_string var_accepted_5F_llvmName = function_llvmNameForLocalVariable (function_acceptVariableName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 607)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 607)) ;
  cEnumerator_allocaList enumerator_24640 (inObject.mAttribute_mAllocaList, kEnumeration_up) ;
  while (enumerator_24640.hasCurrentObject ()) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (function_llvmNameForLocalVariable (enumerator_24640.current_mVarName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 609)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 609)).add_operation (GALGAS_string (" = alloca "), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 609)).add_operation (enumerator_24640.current_mType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 609)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 609)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 609)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 609)) ;
    enumerator_24640.gotoNextObject () ;
  }
  cEnumerator_procFormalArgumentListForGeneration enumerator_24838 (inObject.mAttribute_mFormalArgumentListForGeneration, kEnumeration_up) ;
  while (enumerator_24838.hasCurrentObject ()) {
    switch (enumerator_24838.current_mFormalArgumentKind (HERE).enumValue ()) {
    case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_input:
      {
        GALGAS_string var_llvmType = enumerator_24838.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 615)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (enumerator_24838.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 616)).add_operation (GALGAS_string (" = alloca "), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 616)).add_operation (var_llvmType, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 616)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 616)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 616)) ;
      }
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_output:
    case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
      {
      }
      break ;
    }
    enumerator_24838.gotoNextObject () ;
  }
  cEnumerator_procFormalArgumentListForGeneration enumerator_25116 (inObject.mAttribute_mFormalArgumentListForGeneration, kEnumeration_up) ;
  while (enumerator_25116.hasCurrentObject ()) {
    switch (enumerator_25116.current_mFormalArgumentKind (HERE).enumValue ()) {
    case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_input:
      {
        GALGAS_string var_llvmType = enumerator_25116.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 623)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  store ").add_operation (var_llvmType, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 624)).add_operation (GALGAS_string (" %in."), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 624)).add_operation (enumerator_25116.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 624)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 624)).add_operation (var_llvmType, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 624)).add_operation (GALGAS_string ("* %"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 624)).add_operation (enumerator_25116.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 624)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 624)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 624)) ;
      }
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_output:
    case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
      {
      }
      break ;
    }
    enumerator_25116.gotoNextObject () ;
  }
  switch (inObject.mAttribute_mGuardKindGenerationIR.enumValue ()) {
  case GALGAS_guardKindGenerationIR::kNotBuilt:
    break ;
  case GALGAS_guardKindGenerationIR::kEnum_baseGuard:
    {
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  store i1 false, i1* %").add_operation (var_accepted_5F_llvmName, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 631)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 631)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 631)) ;
      extensionMethod_instructionListLLVMCode (inObject.mAttribute_mInstructionGenerationList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 632)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (var_accepted_5F_llvmName, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 633)).add_operation (GALGAS_string (".loaded = load i1, i1* %"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 633)).add_operation (var_accepted_5F_llvmName, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 633)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 633)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 633)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 %").add_operation (var_accepted_5F_llvmName, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 634)).add_operation (GALGAS_string (".loaded, label %"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 634)).add_operation (var_accepted_5F_llvmName, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 634)).add_operation (GALGAS_string (".true, label %"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 634)).add_operation (var_accepted_5F_llvmName, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 634)).add_operation (GALGAS_string (".false\n"
        "\n"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 634)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 634)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(var_accepted_5F_llvmName.add_operation (GALGAS_string (".true:\n"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 635)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 635)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  call void @noteGuardHasBeenAccepted ()\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 636)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ret i1 true\n"
        "\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 637)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(var_accepted_5F_llvmName.add_operation (GALGAS_string (".false:\n"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 638)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 638)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ret i1 false\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 639)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("}\n"
        "\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 640)) ;
    }
    break ;
  case GALGAS_guardKindGenerationIR::kEnum_convenienceGuard:
    {
      const cEnumAssociatedValues_guardKindGenerationIR_convenienceGuard * extractPtr_27610 = (const cEnumAssociatedValues_guardKindGenerationIR_convenienceGuard *) (inObject.mAttribute_mGuardKindGenerationIR.unsafePointer ()) ;
      const GALGAS_allocaList extractedValue_baseGuardAllocaList = extractPtr_27610->mAssociatedValue0 ;
      const GALGAS_instructionListIR extractedValue_baseGuardInstructionGenerationList = extractPtr_27610->mAssociatedValue1 ;
      const GALGAS_string extractedValue_baseGuardMangledName = extractPtr_27610->mAssociatedValue2 ;
      const GALGAS_procCallEffectiveParameterListIR extractedValue_baseGuardEffectiveParameterList = extractPtr_27610->mAssociatedValue3 ;
      cEnumerator_allocaList enumerator_26359 (extractedValue_baseGuardAllocaList, kEnumeration_up) ;
      while (enumerator_26359.hasCurrentObject ()) {
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (function_llvmNameForLocalVariable (enumerator_26359.current_mVarName (HERE), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 643)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 643)).add_operation (GALGAS_string (" = alloca "), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 643)).add_operation (enumerator_26359.current_mType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 643)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 643)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 643)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 643)) ;
        enumerator_26359.gotoNextObject () ;
      }
      extensionMethod_instructionListLLVMCode (extractedValue_baseGuardInstructionGenerationList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 645)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %baseGuard.result = call i1 @").add_operation (function_llvmNameForGuardCall (extractedValue_baseGuardMangledName, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 646)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 646)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 646)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" ("), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 647)) ;
      cEnumerator_procCallEffectiveParameterListIR enumerator_26765 (extractedValue_baseGuardEffectiveParameterList, kEnumeration_up) ;
      while (enumerator_26765.hasCurrentObject ()) {
        switch (enumerator_26765.current_mEffectiveParameterPassingMode (HERE).enumValue ()) {
        case GALGAS_procEffectiveParameterPassingModeIR::kNotBuilt:
          break ;
        case GALGAS_procEffectiveParameterPassingModeIR::kEnum_input:
          {
            ioArgument_ioLLVMcode.plusAssign_operation(enumerator_26765.current_mParameter (HERE).mAttribute_mType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 651)).add_operation (GALGAS_string ("* "), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 651)).add_operation (extensionGetter_llvmName (enumerator_26765.current_mParameter (HERE).mAttribute_mValue, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 651)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 651)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 651)) ;
          }
          break ;
        case GALGAS_procEffectiveParameterPassingModeIR::kEnum_output:
          {
            ioArgument_ioLLVMcode.plusAssign_operation(enumerator_26765.current_mParameter (HERE).mAttribute_mType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 653)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 653)).add_operation (extensionGetter_llvmName (enumerator_26765.current_mParameter (HERE).mAttribute_mValue, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 653)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 653)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 653)) ;
          }
          break ;
        case GALGAS_procEffectiveParameterPassingModeIR::kEnum_outputInput:
          {
            ioArgument_ioLLVMcode.plusAssign_operation(enumerator_26765.current_mParameter (HERE).mAttribute_mType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 655)).add_operation (GALGAS_string ("* "), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 655)).add_operation (extensionGetter_llvmName (enumerator_26765.current_mParameter (HERE).mAttribute_mValue, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 655)), inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 655)), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 655)) ;
          }
          break ;
        }
        if (enumerator_26765.hasNextObject ()) {
          ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 658)) ;
        }
        enumerator_26765.gotoNextObject () ;
      }
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (")\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 660)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  br i1 %baseGuard.result, label %baseGuard.true, label %baseGuard.exit\n"
        "\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 661)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("baseGuard.true:\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 662)) ;
      extensionMethod_instructionListLLVMCode (inObject.mAttribute_mInstructionGenerationList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("declaration-guard.galgas", 663)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ret i1 true\n"
        "\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 664)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("baseGuard.exit:\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 665)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ret i1 false\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 666)) ;
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("}\n"
        "\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-guard.galgas", 667)) ;
    }
    break ;
  }
  ioArgument_ioGenerationAdds.mAttribute_mExternFunctionDeclarationSet.addAssign_operation (GALGAS_string ("declare void @noteGuardHasBeenAccepted ()\n")  COMMA_SOURCE_FILE ("declaration-guard.galgas", 669)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension method '@routineMapIR-element llvmCodeGeneration'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_llvmCodeGeneration (const GALGAS_routineMapIR_2D_element inObject,
                                         GALGAS_string & ioArgument_ioLLVMcode,
                                         GALGAS_string & /* ioArgument_ioAssemblerCode */,
                                         const GALGAS_generationContext constinArgument_inGenerationContext,
                                         GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_routineName ;
  switch (inObject.mAttribute_mKind.enumValue ()) {
  case GALGAS_routineKind::kNotBuilt:
    break ;
  case GALGAS_routineKind::kEnum_function:
    {
      var_routineName = function_llvmNameForFunction (inObject.mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 242)) ;
    }
    break ;
  case GALGAS_routineKind::kEnum_section:
    {
      var_routineName = function_llvmNameForSectionImplementation (inObject.mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 243)) ;
    }
    break ;
  case GALGAS_routineKind::kEnum_service:
    {
      var_routineName = function_llvmNameForServiceImplementation (inObject.mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 244)) ;
    }
    break ;
  case GALGAS_routineKind::kEnum_primitive:
    {
      var_routineName = function_llvmNameForPrimitiveImplementation (inObject.mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 245)) ;
    }
    break ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(function_llvmTitleComment (var_routineName, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 247)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 247)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("define"), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 248)) ;
  const enumGalgasBool test_0 = inObject.mAttribute_mGlobal.operator_not (SOURCE_FILE ("semantic-routines.galgas", 249)).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" internal"), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 250)) ;
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, inObject.mAttribute_mReturnType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("semantic-routines.galgas", 252)))).boolEnum () ;
  if (kBoolTrue == test_1) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" void"), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 253)) ;
  }else if (kBoolFalse == test_1) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" ").add_operation (inObject.mAttribute_mReturnType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 255)), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 255)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 255)) ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (" @").add_operation (var_routineName, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 257)).add_operation (GALGAS_string (" ("), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 257)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 257)) ;
  GALGAS_string var_receiverTypeName = inObject.mAttribute_lkey.mAttribute_string.getter_stringByDeletingPathExtension (SOURCE_FILE ("semantic-routines.galgas", 258)) ;
  GALGAS_bool var_first = GALGAS_bool (true) ;
  const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, var_receiverTypeName.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_2) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("%").add_operation (var_receiverTypeName, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 261)).add_operation (GALGAS_string ("* %self"), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 261)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 261)) ;
    var_first = GALGAS_bool (false) ;
  }
  cEnumerator_procFormalArgumentListForGeneration enumerator_10400 (inObject.mAttribute_mFormalArgumentListForGeneration, kEnumeration_up) ;
  while (enumerator_10400.hasCurrentObject ()) {
    const enumGalgasBool test_3 = var_first.boolEnum () ;
    if (kBoolTrue == test_3) {
      var_first = GALGAS_bool (false) ;
    }else if (kBoolFalse == test_3) {
      ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 268)) ;
    }
    switch (enumerator_10400.current_mFormalArgumentKind (HERE).enumValue ()) {
    case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_input:
      {
        ioArgument_ioLLVMcode.plusAssign_operation(enumerator_10400.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 272)).add_operation (GALGAS_string (" %in."), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 272)).add_operation (enumerator_10400.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 272)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 272)) ;
      }
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_output:
      {
        ioArgument_ioLLVMcode.plusAssign_operation(enumerator_10400.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 274)).add_operation (GALGAS_string ("* %"), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 274)).add_operation (enumerator_10400.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 274)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 274)) ;
      }
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
      {
        ioArgument_ioLLVMcode.plusAssign_operation(enumerator_10400.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 276)).add_operation (GALGAS_string ("* %"), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 276)).add_operation (enumerator_10400.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 276)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 276)) ;
      }
      break ;
    }
    enumerator_10400.gotoNextObject () ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string (")").add_operation (function_llvmAttributeFunction (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 279)), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 279)).add_operation (GALGAS_string ("{\n"), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 279)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 279)) ;
  const enumGalgasBool test_4 = GALGAS_bool (kIsNotEqual, inObject.mAttribute_mReturnType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("semantic-routines.galgas", 281)))).boolEnum () ;
  if (kBoolTrue == test_4) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (function_llvmNameForLocalVariable (function_functionResultVariableName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 282)), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 282)), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 282)).add_operation (GALGAS_string (" = alloca "), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 282)).add_operation (inObject.mAttribute_mReturnType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 282)), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 282)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 282)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 282)) ;
  }
  cEnumerator_allocaList enumerator_11133 (inObject.mAttribute_mAllocaList, kEnumeration_up) ;
  while (enumerator_11133.hasCurrentObject ()) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (function_llvmNameForLocalVariable (enumerator_11133.current_mVarName (HERE), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 285)), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 285)).add_operation (GALGAS_string (" = alloca "), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 285)).add_operation (enumerator_11133.current_mType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 285)), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 285)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 285)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 285)) ;
    enumerator_11133.gotoNextObject () ;
  }
  cEnumerator_procFormalArgumentListForGeneration enumerator_11331 (inObject.mAttribute_mFormalArgumentListForGeneration, kEnumeration_up) ;
  while (enumerator_11331.hasCurrentObject ()) {
    switch (enumerator_11331.current_mFormalArgumentKind (HERE).enumValue ()) {
    case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_input:
      {
        GALGAS_string var_llvmType = enumerator_11331.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 291)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %").add_operation (enumerator_11331.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 292)).add_operation (GALGAS_string (" = alloca "), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 292)).add_operation (var_llvmType, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 292)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 292)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 292)) ;
      }
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_output:
    case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
      {
      }
      break ;
    }
    enumerator_11331.gotoNextObject () ;
  }
  cEnumerator_procFormalArgumentListForGeneration enumerator_11609 (inObject.mAttribute_mFormalArgumentListForGeneration, kEnumeration_up) ;
  while (enumerator_11609.hasCurrentObject ()) {
    switch (enumerator_11609.current_mFormalArgumentKind (HERE).enumValue ()) {
    case GALGAS_procFormalArgumentPassingMode::kNotBuilt:
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_input:
      {
        GALGAS_string var_llvmType = enumerator_11609.current_mFormalArgumentType (HERE).getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 299)) ;
        ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  store ").add_operation (var_llvmType, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 300)).add_operation (GALGAS_string (" %in."), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 300)).add_operation (enumerator_11609.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 300)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 300)).add_operation (var_llvmType, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 300)).add_operation (GALGAS_string ("* %"), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 300)).add_operation (enumerator_11609.current_mFormalArgumentName (HERE), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 300)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 300)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 300)) ;
      }
      break ;
    case GALGAS_procFormalArgumentPassingMode::kEnum_output:
    case GALGAS_procFormalArgumentPassingMode::kEnum_inputOutput:
      {
      }
      break ;
    }
    enumerator_11609.gotoNextObject () ;
  }
  extensionMethod_instructionListLLVMCode (inObject.mAttribute_mInstructionGenerationList, ioArgument_ioLLVMcode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 305)) ;
  const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, inObject.mAttribute_mReturnType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("semantic-routines.galgas", 307)))).boolEnum () ;
  if (kBoolTrue == test_5) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ret void\n"), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 308)) ;
  }else if (kBoolFalse == test_5) {
    GALGAS_string var_resultVarLLVMName = GALGAS_string ("%").add_operation (function_llvmNameForLocalVariable (function_functionResultVariableName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 310)), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 310)), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 310)) ;
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  %result = load ").add_operation (inObject.mAttribute_mReturnType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 311)), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 311)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 311)).add_operation (inObject.mAttribute_mReturnType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 311)), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 311)).add_operation (GALGAS_string ("* "), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 311)).add_operation (var_resultVarLLVMName, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 311)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 311)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 311)) ;
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("  ret ").add_operation (inObject.mAttribute_mReturnType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 312)), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 312)).add_operation (GALGAS_string (" %result\n"), inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 312)), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 312)) ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("}\n"
    "\n"), inCompiler  COMMA_SOURCE_FILE ("semantic-routines.galgas", 314)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension Getter '@objectInMemoryIR llvmName'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_llvmName (const GALGAS_objectInMemoryIR & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outName ; // Returned variable
  const GALGAS_objectInMemoryIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectInMemoryIR::kNotBuilt:
    break ;
  case GALGAS_objectInMemoryIR::kEnum_register:
    {
      const cEnumAssociatedValues_objectInMemoryIR_register * extractPtr_3741 = (const cEnumAssociatedValues_objectInMemoryIR_register *) (temp_0.unsafePointer ()) ;
      const GALGAS_lstring extractedValue_name = extractPtr_3741->mAssociatedValue1 ;
      GALGAS_location location_1 (extractedValue_name.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_1, GALGAS_string ("@objectInMemoryIR name")  COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 91)) ;
      result_outName.drop () ; // Release error dropped variable
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalVariable:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalVariable * extractPtr_3838 = (const cEnumAssociatedValues_objectInMemoryIR_globalVariable *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_3838->mAssociatedValue1 ;
      result_outName = GALGAS_string ("@").add_operation (function_llvmNameForGlobalVariable (extractedValue_name, inCompiler COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 93)), inCompiler COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 93)) ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_localValue:
    {
      const cEnumAssociatedValues_objectInMemoryIR_localValue * extractPtr_3928 = (const cEnumAssociatedValues_objectInMemoryIR_localValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_3928->mAssociatedValue1 ;
      result_outName = GALGAS_string ("%").add_operation (function_llvmNameForLocalVariable (extractedValue_name, inCompiler COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 95)), inCompiler COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 95)) ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalConstant:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalConstant * extractPtr_3995 = (const cEnumAssociatedValues_objectInMemoryIR_globalConstant *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_3995->mAssociatedValue1 ;
      result_outName = GALGAS_string ("%").add_operation (extractedValue_name, inCompiler COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 97)) ;
    }
    break ;
  }
//---
  return result_outName ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension Getter '@objectInMemoryIR name'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_name (const GALGAS_objectInMemoryIR & inObject,
                                    C_Compiler * /* inCompiler */
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outName ; // Returned variable
  const GALGAS_objectInMemoryIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectInMemoryIR::kNotBuilt:
    break ;
  case GALGAS_objectInMemoryIR::kEnum_register:
    {
      const cEnumAssociatedValues_objectInMemoryIR_register * extractPtr_4255 = (const cEnumAssociatedValues_objectInMemoryIR_register *) (temp_0.unsafePointer ()) ;
      const GALGAS_lstring extractedValue_name = extractPtr_4255->mAssociatedValue1 ;
      result_outName = extractedValue_name.mAttribute_string ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalVariable:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalVariable * extractPtr_4317 = (const cEnumAssociatedValues_objectInMemoryIR_globalVariable *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_4317->mAssociatedValue1 ;
      result_outName = extractedValue_name ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_localValue:
    {
      const cEnumAssociatedValues_objectInMemoryIR_localValue * extractPtr_4373 = (const cEnumAssociatedValues_objectInMemoryIR_localValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_4373->mAssociatedValue1 ;
      result_outName = extractedValue_name ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalConstant:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalConstant * extractPtr_4434 = (const cEnumAssociatedValues_objectInMemoryIR_globalConstant *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_4434->mAssociatedValue1 ;
      result_outName = extractedValue_name ;
    }
    break ;
  }
//---
  return result_outName ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension Getter '@objectInMemoryIR type'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy extensionGetter_type (const GALGAS_objectInMemoryIR & inObject,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_unifiedTypeMap_2D_proxy result_outType ; // Returned variable
  const GALGAS_objectInMemoryIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectInMemoryIR::kNotBuilt:
    break ;
  case GALGAS_objectInMemoryIR::kEnum_register:
    {
      const cEnumAssociatedValues_objectInMemoryIR_register * extractPtr_4714 = (const cEnumAssociatedValues_objectInMemoryIR_register *) (temp_0.unsafePointer ()) ;
      const GALGAS_unifiedTypeMap_2D_proxy extractedValue_type = extractPtr_4714->mAssociatedValue0 ;
      result_outType = extractedValue_type ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalVariable:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalVariable * extractPtr_4790 = (const cEnumAssociatedValues_objectInMemoryIR_globalVariable *) (temp_0.unsafePointer ()) ;
      const GALGAS_unifiedTypeMap_2D_proxy extractedValue_type = extractPtr_4790->mAssociatedValue0 ;
      result_outType = extractedValue_type ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_localValue:
    {
      const cEnumAssociatedValues_objectInMemoryIR_localValue * extractPtr_4860 = (const cEnumAssociatedValues_objectInMemoryIR_localValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_unifiedTypeMap_2D_proxy extractedValue_type = extractPtr_4860->mAssociatedValue0 ;
      result_outType = extractedValue_type ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalConstant:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalConstant * extractPtr_4931 = (const cEnumAssociatedValues_objectInMemoryIR_globalConstant *) (temp_0.unsafePointer ()) ;
      const GALGAS_operandIR extractedValue_value = extractPtr_4931->mAssociatedValue0 ;
      result_outType = extractedValue_value.mAttribute_mType ;
    }
    break ;
  }
//---
  return result_outType ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension Getter '@objectInMemoryIR address'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR extensionGetter_address (const GALGAS_objectInMemoryIR & inObject,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_operandIR result_outOperand ; // Returned variable
  const GALGAS_objectInMemoryIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectInMemoryIR::kNotBuilt:
    break ;
  case GALGAS_objectInMemoryIR::kEnum_register:
    {
      inCompiler->emitSemanticError (GALGAS_location::constructor_nowhere (SOURCE_FILE ("intermediate-value-representation.galgas", 136)), GALGAS_string ("@objectInMemoryIR register address")  COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 136)) ;
      result_outOperand.drop () ; // Release error dropped variable
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalVariable:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalVariable * extractPtr_5393 = (const cEnumAssociatedValues_objectInMemoryIR_globalVariable *) (temp_0.unsafePointer ()) ;
      const GALGAS_unifiedTypeMap_2D_proxy extractedValue_type = extractPtr_5393->mAssociatedValue0 ;
      const GALGAS_string extractedValue_name = extractPtr_5393->mAssociatedValue1 ;
      result_outOperand = GALGAS_operandIR::constructor_new (extractedValue_type, GALGAS_valueIR::constructor_llvmGlobalObject (function_llvmNameForGlobalVariable (extractedValue_name, inCompiler COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 138))  COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 138))  COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 138)) ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_localValue:
    {
      const cEnumAssociatedValues_objectInMemoryIR_localValue * extractPtr_5545 = (const cEnumAssociatedValues_objectInMemoryIR_localValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_unifiedTypeMap_2D_proxy extractedValue_type = extractPtr_5545->mAssociatedValue0 ;
      const GALGAS_string extractedValue_name = extractPtr_5545->mAssociatedValue1 ;
      result_outOperand = GALGAS_operandIR::constructor_new (extractedValue_type, GALGAS_valueIR::constructor_llvmLocalObject (function_llvmNameForLocalVariable (extractedValue_name, inCompiler COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 140))  COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 140))  COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 140)) ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalConstant:
    {
      inCompiler->emitSemanticError (GALGAS_location::constructor_nowhere (SOURCE_FILE ("intermediate-value-representation.galgas", 142)), GALGAS_string ("@objectInMemoryIR globalConstantaddress")  COMMA_SOURCE_FILE ("intermediate-value-representation.galgas", 142)) ;
      result_outOperand.drop () ; // Release error dropped variable
    }
    break ;
  }
//---
  return result_outOperand ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@objectInMemoryIR loadFromMemory'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_loadFromMemory (const GALGAS_objectInMemoryIR inObject,
                                     GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                     GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                     GALGAS_operandIR & outArgument_outResultingValue,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultingValue.drop () ; // Release 'out' argument
  const GALGAS_objectInMemoryIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectInMemoryIR::kNotBuilt:
    break ;
  case GALGAS_objectInMemoryIR::kEnum_register:
    {
      const cEnumAssociatedValues_objectInMemoryIR_register * extractPtr_617 = (const cEnumAssociatedValues_objectInMemoryIR_register *) (temp_0.unsafePointer ()) ;
      const GALGAS_unifiedTypeMap_2D_proxy extractedValue_type = extractPtr_617->mAssociatedValue0 ;
      const GALGAS_lstring extractedValue_name = extractPtr_617->mAssociatedValue1 ;
      const GALGAS_bigint extractedValue_address = extractPtr_617->mAssociatedValue2 ;
      {
      routine_getNewTempVariable (extractedValue_type, ioArgument_ioTemporaries, outArgument_outResultingValue, inCompiler  COMMA_SOURCE_FILE ("intermediate-load-store.galgas", 10)) ;
      }
      {
      extensionSetter_appendLoadVolatileRegister (ioArgument_ioInstructionGenerationList, outArgument_outResultingValue, extractedValue_name.mAttribute_string, extractedValue_address, inCompiler COMMA_SOURCE_FILE ("intermediate-load-store.galgas", 11)) ;
      }
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalVariable:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalVariable * extractPtr_896 = (const cEnumAssociatedValues_objectInMemoryIR_globalVariable *) (temp_0.unsafePointer ()) ;
      const GALGAS_unifiedTypeMap_2D_proxy extractedValue_type = extractPtr_896->mAssociatedValue0 ;
      const GALGAS_string extractedValue_name = extractPtr_896->mAssociatedValue1 ;
      const GALGAS_bool extractedValue_isVolatile = extractPtr_896->mAssociatedValue2 ;
      {
      routine_getNewTempVariable (extractedValue_type, ioArgument_ioTemporaries, outArgument_outResultingValue, inCompiler  COMMA_SOURCE_FILE ("intermediate-load-store.galgas", 17)) ;
      }
      {
      extensionSetter_appendLoadGlobalVariable (ioArgument_ioInstructionGenerationList, outArgument_outResultingValue, extractedValue_name, extractedValue_isVolatile, inCompiler COMMA_SOURCE_FILE ("intermediate-load-store.galgas", 18)) ;
      }
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_localValue:
    {
      const cEnumAssociatedValues_objectInMemoryIR_localValue * extractPtr_1126 = (const cEnumAssociatedValues_objectInMemoryIR_localValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_unifiedTypeMap_2D_proxy extractedValue_type = extractPtr_1126->mAssociatedValue0 ;
      const GALGAS_string extractedValue_name = extractPtr_1126->mAssociatedValue1 ;
      {
      routine_getNewTempVariable (extractedValue_type, ioArgument_ioTemporaries, outArgument_outResultingValue, inCompiler  COMMA_SOURCE_FILE ("intermediate-load-store.galgas", 24)) ;
      }
      {
      extensionSetter_appendLoadLocalVariable (ioArgument_ioInstructionGenerationList, outArgument_outResultingValue, extractedValue_name, inCompiler COMMA_SOURCE_FILE ("intermediate-load-store.galgas", 25)) ;
      }
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalConstant:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalConstant * extractPtr_1219 = (const cEnumAssociatedValues_objectInMemoryIR_globalConstant *) (temp_0.unsafePointer ()) ;
      const GALGAS_operandIR extractedValue_value = extractPtr_1219->mAssociatedValue0 ;
      const GALGAS_string extractedValue_name = extractPtr_1219->mAssociatedValue1 ;
      outArgument_outResultingValue = extractedValue_value ;
    }
    break ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@objectInMemoryIR storeInMemory'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_storeInMemory (const GALGAS_objectInMemoryIR inObject,
                                    GALGAS_operandIR inArgument_inValue,
                                    GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_objectInMemoryIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectInMemoryIR::kNotBuilt:
    break ;
  case GALGAS_objectInMemoryIR::kEnum_register:
    {
      const cEnumAssociatedValues_objectInMemoryIR_register * extractPtr_1696 = (const cEnumAssociatedValues_objectInMemoryIR_register *) (temp_0.unsafePointer ()) ;
      const GALGAS_unifiedTypeMap_2D_proxy extractedValue_type = extractPtr_1696->mAssociatedValue0 ;
      const GALGAS_lstring extractedValue_registerName = extractPtr_1696->mAssociatedValue1 ;
      const GALGAS_bigint extractedValue_address = extractPtr_1696->mAssociatedValue2 ;
      {
      extensionSetter_appendStoreVolatileRegister (ioArgument_ioInstructionGenerationList, extractedValue_registerName.mAttribute_string, extractedValue_type, extractedValue_address, inArgument_inValue, inCompiler COMMA_SOURCE_FILE ("intermediate-load-store.galgas", 42)) ;
      }
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalVariable:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalVariable * extractPtr_1883 = (const cEnumAssociatedValues_objectInMemoryIR_globalVariable *) (temp_0.unsafePointer ()) ;
      const GALGAS_unifiedTypeMap_2D_proxy extractedValue_type = extractPtr_1883->mAssociatedValue0 ;
      const GALGAS_string extractedValue_name = extractPtr_1883->mAssociatedValue1 ;
      const GALGAS_bool extractedValue_isVolatile = extractPtr_1883->mAssociatedValue2 ;
      {
      extensionSetter_appendStoreGlobalVariable (ioArgument_ioInstructionGenerationList, extractedValue_name, extractedValue_type, inArgument_inValue, extractedValue_isVolatile, inCompiler COMMA_SOURCE_FILE ("intermediate-load-store.galgas", 44)) ;
      }
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_localValue:
    {
      const cEnumAssociatedValues_objectInMemoryIR_localValue * extractPtr_2027 = (const cEnumAssociatedValues_objectInMemoryIR_localValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_unifiedTypeMap_2D_proxy extractedValue_type = extractPtr_2027->mAssociatedValue0 ;
      const GALGAS_string extractedValue_name = extractPtr_2027->mAssociatedValue1 ;
      {
      extensionSetter_appendStoreLocalVariable (ioArgument_ioInstructionGenerationList, extractedValue_name, extractedValue_type, inArgument_inValue, inCompiler COMMA_SOURCE_FILE ("intermediate-load-store.galgas", 46)) ;
      }
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalConstant:
    {
      inCompiler->emitSemanticError (GALGAS_location::constructor_nowhere (SOURCE_FILE ("intermediate-load-store.galgas", 48)), GALGAS_string ("<<@objectInMemoryIR storeInMemory globalConstant>>")  COMMA_SOURCE_FILE ("intermediate-load-store.galgas", 48)) ;
    }
    break ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension method '@objectInMemoryIR enterAccessibleEntities'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterAccessibleEntities (const GALGAS_objectInMemoryIR inObject,
                                              GALGAS_accessibleEntities & ioArgument_ioAccessibleEntities,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_objectInMemoryIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectInMemoryIR::kNotBuilt:
    break ;
  case GALGAS_objectInMemoryIR::kEnum_register:
    {
      const cEnumAssociatedValues_objectInMemoryIR_register * extractPtr_1139 = (const cEnumAssociatedValues_objectInMemoryIR_register *) (temp_0.unsafePointer ()) ;
      const GALGAS_lstring extractedValue_name = extractPtr_1139->mAssociatedValue1 ;
      ioArgument_ioAccessibleEntities.mAttribute_mAccessibleRegisterSet.addAssign_operation (extractedValue_name.mAttribute_string  COMMA_SOURCE_FILE ("code-optimisation.galgas", 21)) ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalVariable:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalVariable * extractPtr_1235 = (const cEnumAssociatedValues_objectInMemoryIR_globalVariable *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_1235->mAssociatedValue1 ;
      ioArgument_ioAccessibleEntities.mAttribute_mGlobalVariableSet.addAssign_operation (extractedValue_name  COMMA_SOURCE_FILE ("code-optimisation.galgas", 23)) ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_localValue:
    {
      const cEnumAssociatedValues_objectInMemoryIR_localValue * extractPtr_1279 = (const cEnumAssociatedValues_objectInMemoryIR_localValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_1279->mAssociatedValue1 ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalConstant:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalConstant * extractPtr_1373 = (const cEnumAssociatedValues_objectInMemoryIR_globalConstant *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_1373->mAssociatedValue1 ;
      ioArgument_ioAccessibleEntities.mAttribute_mGlobalVariableSet.addAssign_operation (extractedValue_name  COMMA_SOURCE_FILE ("code-optimisation.galgas", 26)) ;
    }
    break ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension Getter '@objectInMemoryIR mangledName'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_mangledName (const GALGAS_objectInMemoryIR & inObject,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outResult ; // Returned variable
  const GALGAS_objectInMemoryIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectInMemoryIR::kNotBuilt:
    break ;
  case GALGAS_objectInMemoryIR::kEnum_register:
    {
      const cEnumAssociatedValues_objectInMemoryIR_register * extractPtr_772 = (const cEnumAssociatedValues_objectInMemoryIR_register *) (temp_0.unsafePointer ()) ;
      const GALGAS_lstring extractedValue_name = extractPtr_772->mAssociatedValue1 ;
      result_outResult = function_llvmNameForRegister (extractedValue_name.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("code-generation.galgas", 10)) ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalVariable:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalVariable * extractPtr_865 = (const cEnumAssociatedValues_objectInMemoryIR_globalVariable *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_865->mAssociatedValue1 ;
      result_outResult = function_llvmNameForGlobalVariable (extractedValue_name, inCompiler COMMA_SOURCE_FILE ("code-generation.galgas", 12)) ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_localValue:
    {
      const cEnumAssociatedValues_objectInMemoryIR_localValue * extractPtr_951 = (const cEnumAssociatedValues_objectInMemoryIR_localValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_951->mAssociatedValue1 ;
      result_outResult = function_llvmNameForLocalVariable (extractedValue_name, inCompiler COMMA_SOURCE_FILE ("code-generation.galgas", 14)) ;
    }
    break ;
  case GALGAS_objectInMemoryIR::kEnum_globalConstant:
    {
      const cEnumAssociatedValues_objectInMemoryIR_globalConstant * extractPtr_1042 = (const cEnumAssociatedValues_objectInMemoryIR_globalConstant *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_1042->mAssociatedValue1 ;
      result_outResult = function_llvmNameForGlobalVariable (extractedValue_name, inCompiler COMMA_SOURCE_FILE ("code-generation.galgas", 16)) ;
    }
    break ;
  }
//---
  return result_outResult ;
}




//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptionConfigurationList_2D_element::GALGAS_interruptionConfigurationList_2D_element (void) :
mAttribute_mInterruptName (),
mAttribute_mInterruptionPanicCode () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptionConfigurationList_2D_element::~ GALGAS_interruptionConfigurationList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptionConfigurationList_2D_element::GALGAS_interruptionConfigurationList_2D_element (const GALGAS_lstring & inOperand0,
                                                                                                  const GALGAS_interruptionPanicCode & inOperand1) :
mAttribute_mInterruptName (inOperand0),
mAttribute_mInterruptionPanicCode (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptionConfigurationList_2D_element GALGAS_interruptionConfigurationList_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                                  const GALGAS_interruptionPanicCode & inOperand1 
                                                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_interruptionConfigurationList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_interruptionConfigurationList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_interruptionConfigurationList_2D_element::objectCompare (const GALGAS_interruptionConfigurationList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mInterruptName.objectCompare (inOperand.mAttribute_mInterruptName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mInterruptionPanicCode.objectCompare (inOperand.mAttribute_mInterruptionPanicCode) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_interruptionConfigurationList_2D_element::isValid (void) const {
  return mAttribute_mInterruptName.isValid () && mAttribute_mInterruptionPanicCode.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptionConfigurationList_2D_element::drop (void) {
  mAttribute_mInterruptName.drop () ;
  mAttribute_mInterruptionPanicCode.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_interruptionConfigurationList_2D_element::description (C_String & ioString,
                                                                   const int32_t inIndentation) const {
  ioString << "<struct @interruptionConfigurationList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mInterruptName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mInterruptionPanicCode.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_interruptionConfigurationList_2D_element::getter_mInterruptName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInterruptName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptionPanicCode GALGAS_interruptionConfigurationList_2D_element::getter_mInterruptionPanicCode (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInterruptionPanicCode ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     @interruptionConfigurationList-element type                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_interruptionConfigurationList_2D_element ("interruptionConfigurationList-element",
                                                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_interruptionConfigurationList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_interruptionConfigurationList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_interruptionConfigurationList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_interruptionConfigurationList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptionConfigurationList_2D_element GALGAS_interruptionConfigurationList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                                C_Compiler * inCompiler
                                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_interruptionConfigurationList_2D_element result ;
  const GALGAS_interruptionConfigurationList_2D_element * p = (const GALGAS_interruptionConfigurationList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_interruptionConfigurationList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("interruptionConfigurationList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortedOperandIRList_2D_element::GALGAS_sortedOperandIRList_2D_element (void) :
mAttribute_mOperand (),
mAttribute_mIndex () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortedOperandIRList_2D_element::~ GALGAS_sortedOperandIRList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortedOperandIRList_2D_element::GALGAS_sortedOperandIRList_2D_element (const GALGAS_operandIR & inOperand0,
                                                                              const GALGAS_uint & inOperand1) :
mAttribute_mOperand (inOperand0),
mAttribute_mIndex (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortedOperandIRList_2D_element GALGAS_sortedOperandIRList_2D_element::constructor_new (const GALGAS_operandIR & inOperand0,
                                                                                              const GALGAS_uint & inOperand1 
                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sortedOperandIRList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_sortedOperandIRList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_sortedOperandIRList_2D_element::objectCompare (const GALGAS_sortedOperandIRList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mOperand.objectCompare (inOperand.mAttribute_mOperand) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mIndex.objectCompare (inOperand.mAttribute_mIndex) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_sortedOperandIRList_2D_element::isValid (void) const {
  return mAttribute_mOperand.isValid () && mAttribute_mIndex.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortedOperandIRList_2D_element::drop (void) {
  mAttribute_mOperand.drop () ;
  mAttribute_mIndex.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortedOperandIRList_2D_element::description (C_String & ioString,
                                                         const int32_t inIndentation) const {
  ioString << "<struct @sortedOperandIRList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mOperand.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mIndex.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_sortedOperandIRList_2D_element::getter_mOperand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_sortedOperandIRList_2D_element::getter_mIndex (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIndex ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @sortedOperandIRList-element type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sortedOperandIRList_2D_element ("sortedOperandIRList-element",
                                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sortedOperandIRList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sortedOperandIRList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sortedOperandIRList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sortedOperandIRList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortedOperandIRList_2D_element GALGAS_sortedOperandIRList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_sortedOperandIRList_2D_element result ;
  const GALGAS_sortedOperandIRList_2D_element * p = (const GALGAS_sortedOperandIRList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sortedOperandIRList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sortedOperandIRList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST_2D_element::GALGAS_guardDeclarationListAST_2D_element (void) :
mAttribute_mGuardName (),
mAttribute_mIsPublic (),
mAttribute_mGuardAttributeList (),
mAttribute_mGuardFormalArgumentList (),
mAttribute_mGuardKind (),
mAttribute_mGuardInstructionList (),
mAttribute_mEndOfGuardDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST_2D_element::~ GALGAS_guardDeclarationListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST_2D_element::GALGAS_guardDeclarationListAST_2D_element (const GALGAS_lstring & inOperand0,
                                                                                      const GALGAS_bool & inOperand1,
                                                                                      const GALGAS_lstringlist & inOperand2,
                                                                                      const GALGAS_procFormalArgumentList & inOperand3,
                                                                                      const GALGAS_guardKind & inOperand4,
                                                                                      const GALGAS_instructionListAST & inOperand5,
                                                                                      const GALGAS_location & inOperand6) :
mAttribute_mGuardName (inOperand0),
mAttribute_mIsPublic (inOperand1),
mAttribute_mGuardAttributeList (inOperand2),
mAttribute_mGuardFormalArgumentList (inOperand3),
mAttribute_mGuardKind (inOperand4),
mAttribute_mGuardInstructionList (inOperand5),
mAttribute_mEndOfGuardDeclaration (inOperand6) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST_2D_element GALGAS_guardDeclarationListAST_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                      const GALGAS_bool & inOperand1,
                                                                                                      const GALGAS_lstringlist & inOperand2,
                                                                                                      const GALGAS_procFormalArgumentList & inOperand3,
                                                                                                      const GALGAS_guardKind & inOperand4,
                                                                                                      const GALGAS_instructionListAST & inOperand5,
                                                                                                      const GALGAS_location & inOperand6 
                                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_guardDeclarationListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    result = GALGAS_guardDeclarationListAST_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_guardDeclarationListAST_2D_element::objectCompare (const GALGAS_guardDeclarationListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mGuardName.objectCompare (inOperand.mAttribute_mGuardName) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mIsPublic.objectCompare (inOperand.mAttribute_mIsPublic) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mGuardAttributeList.objectCompare (inOperand.mAttribute_mGuardAttributeList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mGuardFormalArgumentList.objectCompare (inOperand.mAttribute_mGuardFormalArgumentList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mGuardKind.objectCompare (inOperand.mAttribute_mGuardKind) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mGuardInstructionList.objectCompare (inOperand.mAttribute_mGuardInstructionList) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mEndOfGuardDeclaration.objectCompare (inOperand.mAttribute_mEndOfGuardDeclaration) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_guardDeclarationListAST_2D_element::isValid (void) const {
  return mAttribute_mGuardName.isValid () && mAttribute_mIsPublic.isValid () && mAttribute_mGuardAttributeList.isValid () && mAttribute_mGuardFormalArgumentList.isValid () && mAttribute_mGuardKind.isValid () && mAttribute_mGuardInstructionList.isValid () && mAttribute_mEndOfGuardDeclaration.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardDeclarationListAST_2D_element::drop (void) {
  mAttribute_mGuardName.drop () ;
  mAttribute_mIsPublic.drop () ;
  mAttribute_mGuardAttributeList.drop () ;
  mAttribute_mGuardFormalArgumentList.drop () ;
  mAttribute_mGuardKind.drop () ;
  mAttribute_mGuardInstructionList.drop () ;
  mAttribute_mEndOfGuardDeclaration.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_guardDeclarationListAST_2D_element::description (C_String & ioString,
                                                             const int32_t inIndentation) const {
  ioString << "<struct @guardDeclarationListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mGuardName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mIsPublic.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mGuardAttributeList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mGuardFormalArgumentList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mGuardKind.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mGuardInstructionList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mEndOfGuardDeclaration.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_guardDeclarationListAST_2D_element::getter_mGuardName (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGuardName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_guardDeclarationListAST_2D_element::getter_mIsPublic (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mIsPublic ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_guardDeclarationListAST_2D_element::getter_mGuardAttributeList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGuardAttributeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procFormalArgumentList GALGAS_guardDeclarationListAST_2D_element::getter_mGuardFormalArgumentList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGuardFormalArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardKind GALGAS_guardDeclarationListAST_2D_element::getter_mGuardKind (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGuardKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_guardDeclarationListAST_2D_element::getter_mGuardInstructionList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGuardInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_guardDeclarationListAST_2D_element::getter_mEndOfGuardDeclaration (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEndOfGuardDeclaration ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @guardDeclarationListAST-element type                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_guardDeclarationListAST_2D_element ("guardDeclarationListAST-element",
                                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_guardDeclarationListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_guardDeclarationListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_guardDeclarationListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_guardDeclarationListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardDeclarationListAST_2D_element GALGAS_guardDeclarationListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_guardDeclarationListAST_2D_element result ;
  const GALGAS_guardDeclarationListAST_2D_element * p = (const GALGAS_guardDeclarationListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_guardDeclarationListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("guardDeclarationListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR_2D_element::GALGAS_syncInstructionBranchListIR_2D_element (void) :
mAttribute_mGuardedCommand (),
mAttribute_mInstructionGenerationList () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR_2D_element::~ GALGAS_syncInstructionBranchListIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR_2D_element::GALGAS_syncInstructionBranchListIR_2D_element (const GALGAS_guardedCommandIR & inOperand0,
                                                                                              const GALGAS_instructionListIR & inOperand1) :
mAttribute_mGuardedCommand (inOperand0),
mAttribute_mInstructionGenerationList (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR_2D_element GALGAS_syncInstructionBranchListIR_2D_element::constructor_new (const GALGAS_guardedCommandIR & inOperand0,
                                                                                                              const GALGAS_instructionListIR & inOperand1 
                                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_syncInstructionBranchListIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_syncInstructionBranchListIR_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_syncInstructionBranchListIR_2D_element::objectCompare (const GALGAS_syncInstructionBranchListIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mGuardedCommand.objectCompare (inOperand.mAttribute_mGuardedCommand) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mInstructionGenerationList.objectCompare (inOperand.mAttribute_mInstructionGenerationList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_syncInstructionBranchListIR_2D_element::isValid (void) const {
  return mAttribute_mGuardedCommand.isValid () && mAttribute_mInstructionGenerationList.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR_2D_element::drop (void) {
  mAttribute_mGuardedCommand.drop () ;
  mAttribute_mInstructionGenerationList.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR_2D_element::description (C_String & ioString,
                                                                 const int32_t inIndentation) const {
  ioString << "<struct @syncInstructionBranchListIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mGuardedCommand.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mInstructionGenerationList.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardedCommandIR GALGAS_syncInstructionBranchListIR_2D_element::getter_mGuardedCommand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mGuardedCommand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_syncInstructionBranchListIR_2D_element::getter_mInstructionGenerationList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInstructionGenerationList ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @syncInstructionBranchListIR-element type                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_syncInstructionBranchListIR_2D_element ("syncInstructionBranchListIR-element",
                                                               NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_syncInstructionBranchListIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_syncInstructionBranchListIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_syncInstructionBranchListIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_syncInstructionBranchListIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR_2D_element GALGAS_syncInstructionBranchListIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_syncInstructionBranchListIR_2D_element result ;
  const GALGAS_syncInstructionBranchListIR_2D_element * p = (const GALGAS_syncInstructionBranchListIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_syncInstructionBranchListIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("syncInstructionBranchListIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR_2D_element::GALGAS_procCallEffectiveParameterListIR_2D_element (void) :
mAttribute_mEffectiveParameterPassingMode (),
mAttribute_mParameter () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR_2D_element::~ GALGAS_procCallEffectiveParameterListIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR_2D_element::GALGAS_procCallEffectiveParameterListIR_2D_element (const GALGAS_procEffectiveParameterPassingModeIR & inOperand0,
                                                                                                        const GALGAS_operandIR & inOperand1) :
mAttribute_mEffectiveParameterPassingMode (inOperand0),
mAttribute_mParameter (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR_2D_element GALGAS_procCallEffectiveParameterListIR_2D_element::constructor_new (const GALGAS_procEffectiveParameterPassingModeIR & inOperand0,
                                                                                                                        const GALGAS_operandIR & inOperand1 
                                                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_procCallEffectiveParameterListIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_procCallEffectiveParameterListIR_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_procCallEffectiveParameterListIR_2D_element::objectCompare (const GALGAS_procCallEffectiveParameterListIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mEffectiveParameterPassingMode.objectCompare (inOperand.mAttribute_mEffectiveParameterPassingMode) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mParameter.objectCompare (inOperand.mAttribute_mParameter) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_procCallEffectiveParameterListIR_2D_element::isValid (void) const {
  return mAttribute_mEffectiveParameterPassingMode.isValid () && mAttribute_mParameter.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR_2D_element::drop (void) {
  mAttribute_mEffectiveParameterPassingMode.drop () ;
  mAttribute_mParameter.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR_2D_element::description (C_String & ioString,
                                                                      const int32_t inIndentation) const {
  ioString << "<struct @procCallEffectiveParameterListIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mEffectiveParameterPassingMode.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mParameter.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterPassingModeIR GALGAS_procCallEffectiveParameterListIR_2D_element::getter_mEffectiveParameterPassingMode (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEffectiveParameterPassingMode ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_procCallEffectiveParameterListIR_2D_element::getter_mParameter (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mParameter ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   @procCallEffectiveParameterListIR-element type                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_procCallEffectiveParameterListIR_2D_element ("procCallEffectiveParameterListIR-element",
                                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_procCallEffectiveParameterListIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_procCallEffectiveParameterListIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_procCallEffectiveParameterListIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_procCallEffectiveParameterListIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR_2D_element GALGAS_procCallEffectiveParameterListIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                                      C_Compiler * inCompiler
                                                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_procCallEffectiveParameterListIR_2D_element result ;
  const GALGAS_procCallEffectiveParameterListIR_2D_element * p = (const GALGAS_procCallEffectiveParameterListIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_procCallEffectiveParameterListIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("procCallEffectiveParameterListIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap_2D_element::GALGAS_globalConstantMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mValue () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap_2D_element::~ GALGAS_globalConstantMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap_2D_element::GALGAS_globalConstantMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_operandIR & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_mValue (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap_2D_element GALGAS_globalConstantMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_operandIR & inOperand1 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_globalConstantMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_globalConstantMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_globalConstantMap_2D_element::objectCompare (const GALGAS_globalConstantMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mValue.objectCompare (inOperand.mAttribute_mValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_globalConstantMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mValue.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mValue.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMap_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @globalConstantMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_globalConstantMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_globalConstantMap_2D_element::getter_mValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mValue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @globalConstantMap-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_globalConstantMap_2D_element ("globalConstantMap-element",
                                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_globalConstantMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalConstantMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_globalConstantMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_globalConstantMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap_2D_element GALGAS_globalConstantMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_globalConstantMap_2D_element result ;
  const GALGAS_globalConstantMap_2D_element * p = (const GALGAS_globalConstantMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_globalConstantMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("globalConstantMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_classMethodMap_2D_element::GALGAS_classMethodMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mValue () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_classMethodMap_2D_element::~ GALGAS_classMethodMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_classMethodMap_2D_element::GALGAS_classMethodMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                    const GALGAS_operandIR & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_mValue (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_classMethodMap_2D_element GALGAS_classMethodMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                    const GALGAS_operandIR & inOperand1 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_classMethodMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_classMethodMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_classMethodMap_2D_element::objectCompare (const GALGAS_classMethodMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mValue.objectCompare (inOperand.mAttribute_mValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_classMethodMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mValue.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_classMethodMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mValue.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_classMethodMap_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @classMethodMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_classMethodMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_classMethodMap_2D_element::getter_mValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mValue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @classMethodMap-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_classMethodMap_2D_element ("classMethodMap-element",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_classMethodMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_classMethodMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_classMethodMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_classMethodMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_classMethodMap_2D_element GALGAS_classMethodMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_classMethodMap_2D_element result ;
  const GALGAS_classMethodMap_2D_element * p = (const GALGAS_classMethodMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_classMethodMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("classMethodMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIRList_2D_element::GALGAS_operandIRList_2D_element (void) :
mAttribute_mOperand () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIRList_2D_element::~ GALGAS_operandIRList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIRList_2D_element::GALGAS_operandIRList_2D_element (const GALGAS_operandIR & inOperand0) :
mAttribute_mOperand (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIRList_2D_element GALGAS_operandIRList_2D_element::constructor_new (const GALGAS_operandIR & inOperand0 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_operandIRList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_operandIRList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_operandIRList_2D_element::objectCompare (const GALGAS_operandIRList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mOperand.objectCompare (inOperand.mAttribute_mOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_operandIRList_2D_element::isValid (void) const {
  return mAttribute_mOperand.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_operandIRList_2D_element::drop (void) {
  mAttribute_mOperand.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_operandIRList_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @operandIRList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mOperand.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIR GALGAS_operandIRList_2D_element::getter_mOperand (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mOperand ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @operandIRList-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_operandIRList_2D_element ("operandIRList-element",
                                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_operandIRList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_operandIRList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_operandIRList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_operandIRList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_operandIRList_2D_element GALGAS_operandIRList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_operandIRList_2D_element result ;
  const GALGAS_operandIRList_2D_element * p = (const GALGAS_operandIRList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_operandIRList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("operandIRList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap_2D_element::GALGAS_availableInterruptMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mInterruptionPanicCode () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap_2D_element::~ GALGAS_availableInterruptMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap_2D_element::GALGAS_availableInterruptMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_interruptionPanicCode & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_mInterruptionPanicCode (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap_2D_element GALGAS_availableInterruptMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                  const GALGAS_interruptionPanicCode & inOperand1 
                                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_availableInterruptMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_availableInterruptMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_availableInterruptMap_2D_element::objectCompare (const GALGAS_availableInterruptMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mInterruptionPanicCode.objectCompare (inOperand.mAttribute_mInterruptionPanicCode) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_availableInterruptMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mInterruptionPanicCode.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_availableInterruptMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mInterruptionPanicCode.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_availableInterruptMap_2D_element::description (C_String & ioString,
                                                           const int32_t inIndentation) const {
  ioString << "<struct @availableInterruptMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mInterruptionPanicCode.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_availableInterruptMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptionPanicCode GALGAS_availableInterruptMap_2D_element::getter_mInterruptionPanicCode (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mInterruptionPanicCode ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @availableInterruptMap-element type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_availableInterruptMap_2D_element ("availableInterruptMap-element",
                                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_availableInterruptMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_availableInterruptMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_availableInterruptMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_availableInterruptMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap_2D_element GALGAS_availableInterruptMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_availableInterruptMap_2D_element result ;
  const GALGAS_availableInterruptMap_2D_element * p = (const GALGAS_availableInterruptMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_availableInterruptMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("availableInterruptMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension method '@globalVariableMapIR-element generateLLVM'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_generateLLVM (const GALGAS_globalVariableMapIR_2D_element inObject,
                                   GALGAS_string & ioArgument_ioLLVMcode,
                                   C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("@").add_operation (function_llvmNameForGlobalVariable (inObject.mAttribute_lkey.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 372)), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 372)).add_operation (GALGAS_string (" = internal global "), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 372)), inCompiler  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 372)) ;
  ioArgument_ioLLVMcode.plusAssign_operation(inObject.mAttribute_mType.getter_llvmTypeName (inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 373)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 373)), inCompiler  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 373)) ;
  GALGAS_string var_initialString = extensionGetter_llvmName (inObject.mAttribute_mInitialValue, inCompiler COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 374)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, var_initialString.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("zeroinitializer"), inCompiler  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 376)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_ioLLVMcode.plusAssign_operation(var_initialString, inCompiler  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 378)) ;
  }
  ioArgument_ioLLVMcode.plusAssign_operation(GALGAS_string ("\n"), inCompiler  COMMA_SOURCE_FILE ("declaration-global-variable.galgas", 380)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension method '@configurationDeclarationAST addExtension'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_configurationDeclarationAST_addExtension (const cPtr_abstractDeclaration * inObject,
                                                                      GALGAS_extensionDeclarationListAST & /* ioArgument_ioExtensionDeclarationListAST */,
                                                                      GALGAS_abstractDeclaration & outArgument_outNewDeclaration,
                                                                      C_Compiler * /* inCompiler */
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_configurationDeclarationAST * object = (const cPtr_configurationDeclarationAST *) inObject ;
  macroValidSharedObject (object, cPtr_configurationDeclarationAST) ;
  const GALGAS_configurationDeclarationAST temp_0 = object ;
  outArgument_outNewDeclaration = temp_0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_configurationDeclarationAST_addExtension (void) {
  enterExtensionMethod_addExtension (kTypeDescriptor_GALGAS_configurationDeclarationAST.mSlotID,
                                     extensionMethod_configurationDeclarationAST_addExtension) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_configurationDeclarationAST_addExtension (defineExtensionMethod_configurationDeclarationAST_addExtension, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                  Overriding extension method '@configurationDeclarationAST enterInPrecedenceGraph'                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_configurationDeclarationAST_enterInPrecedenceGraph (const cPtr_abstractDeclaration * inObject,
                                                                                GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_configurationDeclarationAST * object = (const cPtr_configurationDeclarationAST *) inObject ;
  macroValidSharedObject (object, cPtr_configurationDeclarationAST) ;
  GALGAS_lstring var_rootNode = GALGAS_lstring::constructor_new (GALGAS_string ("config"), object->mAttribute_mPanicCodeTypeName.mAttribute_location  COMMA_SOURCE_FILE ("configuration.galgas", 107)) ;
  {
  const GALGAS_configurationDeclarationAST temp_0 = object ;
  ioArgument_ioGraph.setter_addNode (var_rootNode, temp_0, inCompiler COMMA_SOURCE_FILE ("configuration.galgas", 108)) ;
  }
  GALGAS_lstring var_panicCodeTypeName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (object->mAttribute_mPanicCodeTypeName.getter_string (SOURCE_FILE ("configuration.galgas", 109)), inCompiler COMMA_SOURCE_FILE ("configuration.galgas", 109)), object->mAttribute_mPanicCodeTypeName.mAttribute_location  COMMA_SOURCE_FILE ("configuration.galgas", 109)) ;
  {
  ioArgument_ioGraph.setter_addEdge (var_rootNode, var_panicCodeTypeName COMMA_SOURCE_FILE ("configuration.galgas", 110)) ;
  }
  GALGAS_lstring var_panicLineTypeName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (object->mAttribute_mPanicLineTypeName.getter_string (SOURCE_FILE ("configuration.galgas", 111)), inCompiler COMMA_SOURCE_FILE ("configuration.galgas", 111)), object->mAttribute_mPanicLineTypeName.mAttribute_location  COMMA_SOURCE_FILE ("configuration.galgas", 111)) ;
  {
  ioArgument_ioGraph.setter_addEdge (var_rootNode, var_panicLineTypeName COMMA_SOURCE_FILE ("configuration.galgas", 112)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_configurationDeclarationAST_enterInPrecedenceGraph (void) {
  enterExtensionMethod_enterInPrecedenceGraph (kTypeDescriptor_GALGAS_configurationDeclarationAST.mSlotID,
                                               extensionMethod_configurationDeclarationAST_enterInPrecedenceGraph) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_configurationDeclarationAST_enterInPrecedenceGraph (defineExtensionMethod_configurationDeclarationAST_enterInPrecedenceGraph, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension getter '@configurationDeclarationAST location'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_location extensionGetter_configurationDeclarationAST_location (const cPtr_abstractDeclaration * inObject,
                                                                             C_Compiler * /* inCompiler */
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_outLocation ; // Returned variable
  const cPtr_configurationDeclarationAST * object = (const cPtr_configurationDeclarationAST *) inObject ;
  macroValidSharedObject (object, cPtr_configurationDeclarationAST) ;
  result_outLocation = object->mAttribute_mPanicCodeTypeName.mAttribute_location ;
//---
  return result_outLocation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_configurationDeclarationAST_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_configurationDeclarationAST.mSlotID,
                                 extensionGetter_configurationDeclarationAST_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_configurationDeclarationAST_location (defineExtensionGetter_configurationDeclarationAST_location, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//            Overriding extension getter '@configurationDeclarationAST keyRepresentationForErrorSignaling'            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_configurationDeclarationAST_keyRepresentationForErrorSignaling (const cPtr_abstractDeclaration * /* inObject */,
                                                                                                     C_Compiler * /* inCompiler */
                                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outRepresentation ; // Returned variable
  result_outRepresentation = GALGAS_string ("config") ;
//---
  return result_outRepresentation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_configurationDeclarationAST_keyRepresentationForErrorSignaling (void) {
  enterExtensionGetter_keyRepresentationForErrorSignaling (kTypeDescriptor_GALGAS_configurationDeclarationAST.mSlotID,
                                                           extensionGetter_configurationDeclarationAST_keyRepresentationForErrorSignaling) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_configurationDeclarationAST_keyRepresentationForErrorSignaling (defineExtensionGetter_configurationDeclarationAST_keyRepresentationForErrorSignaling, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                  Overriding extension method '@configurationDeclarationAST enterRoutinesInContext'                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_configurationDeclarationAST_enterRoutinesInContext (const cPtr_abstractDeclaration * /* inObject */,
                                                                                const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                                                GALGAS_semanticContext & /* ioArgument_ioContext */,
                                                                                GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                                                C_Compiler * /* inCompiler */
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_configurationDeclarationAST_enterRoutinesInContext (void) {
  enterExtensionMethod_enterRoutinesInContext (kTypeDescriptor_GALGAS_configurationDeclarationAST.mSlotID,
                                               extensionMethod_configurationDeclarationAST_enterRoutinesInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_configurationDeclarationAST_enterRoutinesInContext (defineExtensionMethod_configurationDeclarationAST_enterRoutinesInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Overriding extension method '@configurationDeclarationAST enterInContext'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_configurationDeclarationAST_enterInContext (const cPtr_abstractDeclaration * inObject,
                                                                        const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                                        GALGAS_semanticContext & ioArgument_ioContext,
                                                                        GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_configurationDeclarationAST * object = (const cPtr_configurationDeclarationAST *) inObject ;
  macroValidSharedObject (object, cPtr_configurationDeclarationAST) ;
  GALGAS_stringset var_panicCodeSet = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("configuration.galgas", 146)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, ioArgument_ioContext.mAttribute_mPointerSize.objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_location location_1 (object->mAttribute_mPointerSize.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_1, GALGAS_string ("duplicate configuration")  COMMA_SOURCE_FILE ("configuration.galgas", 148)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, object->mAttribute_mPointerSize.mAttribute_bigint.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("configuration.galgas", 149)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      GALGAS_location location_3 (object->mAttribute_mPointerSize.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_3, GALGAS_string ("zero size pointer not allowed")  COMMA_SOURCE_FILE ("configuration.galgas", 150)) ;
    }else if (kBoolFalse == test_2) {
      ioArgument_ioContext.mAttribute_mPointerSize = object->mAttribute_mPointerSize.mAttribute_bigint.getter_uint (inCompiler COMMA_SOURCE_FILE ("configuration.galgas", 152)) ;
    }
  }
  ioArgument_ioContext.mAttribute_mTargetParameters = object->mAttribute_mTargetParameters ;
  ioArgument_ioContext.mAttribute_mPanicCodeType = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, object->mAttribute_mPanicCodeTypeName, inCompiler  COMMA_SOURCE_FILE ("configuration.galgas", 155)) ;
  ioArgument_ioContext.mAttribute_mPanicLineType = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, object->mAttribute_mPanicLineTypeName, inCompiler  COMMA_SOURCE_FILE ("configuration.galgas", 156)) ;
  cEnumerator_interruptionConfigurationList enumerator_6697 (object->mAttribute_mInterruptionConfigurationList, kEnumeration_up) ;
  while (enumerator_6697.hasCurrentObject ()) {
    {
    ioArgument_ioContext.mAttribute_mAvailableInterruptMap.setter_insertKey (enumerator_6697.current_mInterruptName (HERE), enumerator_6697.current_mInterruptionPanicCode (HERE), inCompiler COMMA_SOURCE_FILE ("configuration.galgas", 158)) ;
    }
    switch (enumerator_6697.current_mInterruptionPanicCode (HERE).enumValue ()) {
    case GALGAS_interruptionPanicCode::kNotBuilt:
      break ;
    case GALGAS_interruptionPanicCode::kEnum_noPanicCode:
      {
      }
      break ;
    case GALGAS_interruptionPanicCode::kEnum_panicCode:
      {
        const cEnumAssociatedValues_interruptionPanicCode_panicCode * extractPtr_6996 = (const cEnumAssociatedValues_interruptionPanicCode_panicCode *) (enumerator_6697.current_mInterruptionPanicCode (HERE).unsafePointer ()) ;
        const GALGAS_lbigint extractedValue_value = extractPtr_6996->mAssociatedValue0 ;
        GALGAS_string var_s = extractedValue_value.mAttribute_bigint.getter_string (SOURCE_FILE ("configuration.galgas", 162)) ;
        const enumGalgasBool test_4 = var_panicCodeSet.getter_hasKey (var_s COMMA_SOURCE_FILE ("configuration.galgas", 163)).boolEnum () ;
        if (kBoolTrue == test_4) {
          GALGAS_location location_5 (extractedValue_value.getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_5, GALGAS_string ("duplicate panic code")  COMMA_SOURCE_FILE ("configuration.galgas", 164)) ;
        }
        var_panicCodeSet.addAssign_operation (var_s  COMMA_SOURCE_FILE ("configuration.galgas", 166)) ;
      }
      break ;
    }
    enumerator_6697.gotoNextObject () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_configurationDeclarationAST_enterInContext (void) {
  enterExtensionMethod_enterInContext (kTypeDescriptor_GALGAS_configurationDeclarationAST.mSlotID,
                                       extensionMethod_configurationDeclarationAST_enterInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_configurationDeclarationAST_enterInContext (defineExtensionMethod_configurationDeclarationAST_enterInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension method '@configurationDeclarationAST semanticAnalysis'                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_configurationDeclarationAST_semanticAnalysis (const cPtr_abstractDeclaration * /* inObject */,
                                                                          const GALGAS_semanticContext /* constinArgument_inContext */,
                                                                          GALGAS_semanticTemporariesStruct & /* ioArgument_ioTemporaries */,
                                                                          GALGAS_intermediateCodeStruct & /* ioArgument_ioIntermediateCodeStruct */,
                                                                          C_Compiler * /* inCompiler */
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_configurationDeclarationAST_semanticAnalysis (void) {
  enterExtensionMethod_semanticAnalysis (kTypeDescriptor_GALGAS_configurationDeclarationAST.mSlotID,
                                         extensionMethod_configurationDeclarationAST_semanticAnalysis) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_configurationDeclarationAST_semanticAnalysis (defineExtensionMethod_configurationDeclarationAST_semanticAnalysis, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@typeArrayDeclaration location'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_location extensionGetter_typeArrayDeclaration_location (const cPtr_abstractDeclaration * inObject,
                                                                      C_Compiler * /* inCompiler */
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_outLocation ; // Returned variable
  const cPtr_typeArrayDeclaration * object = (const cPtr_typeArrayDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_typeArrayDeclaration) ;
  result_outLocation = object->mAttribute_mArrayTypeName.mAttribute_location ;
//---
  return result_outLocation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_typeArrayDeclaration_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_typeArrayDeclaration.mSlotID,
                                 extensionGetter_typeArrayDeclaration_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_typeArrayDeclaration_location (defineExtensionGetter_typeArrayDeclaration_location, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@typeArrayDeclaration addExtension'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_typeArrayDeclaration_addExtension (const cPtr_abstractDeclaration * inObject,
                                                               GALGAS_extensionDeclarationListAST & /* ioArgument_ioExtensionDeclarationListAST */,
                                                               GALGAS_abstractDeclaration & outArgument_outNewDeclaration,
                                                               C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_typeArrayDeclaration * object = (const cPtr_typeArrayDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_typeArrayDeclaration) ;
  const GALGAS_typeArrayDeclaration temp_0 = object ;
  outArgument_outNewDeclaration = temp_0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_typeArrayDeclaration_addExtension (void) {
  enterExtensionMethod_addExtension (kTypeDescriptor_GALGAS_typeArrayDeclaration.mSlotID,
                                     extensionMethod_typeArrayDeclaration_addExtension) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_typeArrayDeclaration_addExtension (defineExtensionMethod_typeArrayDeclaration_addExtension, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension method '@typeArrayDeclaration enterInPrecedenceGraph'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_typeArrayDeclaration_enterInPrecedenceGraph (const cPtr_abstractDeclaration * inObject,
                                                                         GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_typeArrayDeclaration * object = (const cPtr_typeArrayDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_typeArrayDeclaration) ;
  GALGAS_lstring var_newTypeName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (object->mAttribute_mArrayTypeName.getter_string (SOURCE_FILE ("type-array.galgas", 63)), inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 63)), object->mAttribute_mArrayTypeName.mAttribute_location  COMMA_SOURCE_FILE ("type-array.galgas", 63)) ;
  GALGAS_lstring var_elementTypeName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (object->mAttribute_mElementTypeName.getter_string (SOURCE_FILE ("type-array.galgas", 64)), inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 64)), object->mAttribute_mElementTypeName.mAttribute_location  COMMA_SOURCE_FILE ("type-array.galgas", 64)) ;
  {
  const GALGAS_typeArrayDeclaration temp_0 = object ;
  ioArgument_ioGraph.setter_addNode (var_newTypeName, temp_0, inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 65)) ;
  }
  {
  ioArgument_ioGraph.setter_addEdge (var_newTypeName, var_elementTypeName COMMA_SOURCE_FILE ("type-array.galgas", 66)) ;
  }
  callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) object->mAttribute_mSizeExpression.ptr (), var_newTypeName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 67)) ;
  GALGAS_lstring var_rootNode = GALGAS_lstring::constructor_new (GALGAS_string ("config"), object->mAttribute_mArrayTypeName.mAttribute_location  COMMA_SOURCE_FILE ("type-array.galgas", 68)) ;
  {
  ioArgument_ioGraph.setter_addEdge (var_newTypeName, var_rootNode COMMA_SOURCE_FILE ("type-array.galgas", 69)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_typeArrayDeclaration_enterInPrecedenceGraph (void) {
  enterExtensionMethod_enterInPrecedenceGraph (kTypeDescriptor_GALGAS_typeArrayDeclaration.mSlotID,
                                               extensionMethod_typeArrayDeclaration_enterInPrecedenceGraph) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_typeArrayDeclaration_enterInPrecedenceGraph (defineExtensionMethod_typeArrayDeclaration_enterInPrecedenceGraph, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//               Overriding extension getter '@typeArrayDeclaration keyRepresentationForErrorSignaling'                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_typeArrayDeclaration_keyRepresentationForErrorSignaling (const cPtr_abstractDeclaration * inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outRepresentation ; // Returned variable
  const cPtr_typeArrayDeclaration * object = (const cPtr_typeArrayDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_typeArrayDeclaration) ;
  result_outRepresentation = GALGAS_string ("arraytype $").add_operation (object->mAttribute_mArrayTypeName.getter_string (SOURCE_FILE ("type-array.galgas", 75)), inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 75)) ;
//---
  return result_outRepresentation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_typeArrayDeclaration_keyRepresentationForErrorSignaling (void) {
  enterExtensionGetter_keyRepresentationForErrorSignaling (kTypeDescriptor_GALGAS_typeArrayDeclaration.mSlotID,
                                                           extensionGetter_typeArrayDeclaration_keyRepresentationForErrorSignaling) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_typeArrayDeclaration_keyRepresentationForErrorSignaling (defineExtensionGetter_typeArrayDeclaration_keyRepresentationForErrorSignaling, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension method '@typeArrayDeclaration enterRoutinesInContext'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_typeArrayDeclaration_enterRoutinesInContext (const cPtr_abstractDeclaration * inObject,
                                                                         const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                                         GALGAS_semanticContext & ioArgument_ioContext,
                                                                         GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_typeArrayDeclaration * object = (const cPtr_typeArrayDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_typeArrayDeclaration) ;
  GALGAS_lstring var_lkey = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (object->mAttribute_mArrayTypeName.getter_string (SOURCE_FILE ("type-array.galgas", 88)), inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 88)).add_operation (GALGAS_string (".count"), inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 88)), object->mAttribute_mArrayTypeName.mAttribute_location  COMMA_SOURCE_FILE ("type-array.galgas", 88)) ;
  {
  ioArgument_ioContext.mAttribute_mRoutineMapForContext.setter_insertKey (var_lkey, GALGAS_bool (true), function_allModeMap (inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 92)), GALGAS_procedureSignature::constructor_emptyList (SOURCE_FILE ("type-array.galgas", 93)), GALGAS_routineKind::constructor_function (SOURCE_FILE ("type-array.galgas", 94)), GALGAS_bool (false), GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, GALGAS_string ("uint32").getter_nowhere (SOURCE_FILE ("type-array.galgas", 96)), inCompiler  COMMA_SOURCE_FILE ("type-array.galgas", 96)), inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 89)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_typeArrayDeclaration_enterRoutinesInContext (void) {
  enterExtensionMethod_enterRoutinesInContext (kTypeDescriptor_GALGAS_typeArrayDeclaration.mSlotID,
                                               extensionMethod_typeArrayDeclaration_enterRoutinesInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_typeArrayDeclaration_enterRoutinesInContext (defineExtensionMethod_typeArrayDeclaration_enterRoutinesInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@typeArrayDeclaration enterInContext'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_typeArrayDeclaration_enterInContext (const cPtr_abstractDeclaration * inObject,
                                                                 const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                                 GALGAS_semanticContext & ioArgument_ioContext,
                                                                 GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_typeArrayDeclaration * object = (const cPtr_typeArrayDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_typeArrayDeclaration) ;
  GALGAS_bool var_copyable ;
  GALGAS_string joker_5035 ; // Joker input parameter
  GALGAS_typeKind joker_5047 ; // Joker input parameter
  GALGAS_classMethodMap joker_5069 ; // Joker input parameter
  GALGAS_bool joker_5089 ; // Joker input parameter
  GALGAS_bool joker_5133 ; // Joker input parameter
  GALGAS_bool joker_5151 ; // Joker input parameter
  GALGAS_unifiedTypeMap_2D_proxy joker_5174 ; // Joker input parameter
  ioArgument_ioContext.mAttribute_mTypeMap.method_searchKey (object->mAttribute_mElementTypeName, joker_5035, joker_5047, joker_5069, joker_5089, var_copyable, joker_5133, joker_5151, joker_5174, inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 108)) ;
  const enumGalgasBool test_0 = var_copyable.operator_not (SOURCE_FILE ("type-array.galgas", 119)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_location location_1 (object->mAttribute_mElementTypeName.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_1, GALGAS_string ("an array element should be copyable")  COMMA_SOURCE_FILE ("type-array.galgas", 120)) ;
  }
  GALGAS_instructionListIR var_initInstructionGenerationList = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("type-array.galgas", 123)) ;
  GALGAS_allocaList var_allocaList = GALGAS_allocaList::constructor_emptyList (SOURCE_FILE ("type-array.galgas", 124)) ;
  GALGAS_semanticTemporariesStruct var_temporaries = GALGAS_semanticTemporariesStruct::constructor_default (SOURCE_FILE ("type-array.galgas", 125)) ;
  GALGAS_staticStringMap joker_5749 = GALGAS_staticStringMap::constructor_emptyMap (SOURCE_FILE ("type-array.galgas", 135)) ;
  GALGAS_variableMap joker_5769 = GALGAS_variableMap::constructor_emptyMap (SOURCE_FILE ("type-array.galgas", 136)) ;
  GALGAS_operandIR var_sizeExpressionIR ;
  callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) object->mAttribute_mSizeExpression.ptr (), GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("type-array.galgas", 127)), GALGAS_bool (false), GALGAS_lstring::constructor_new (object->mAttribute_mArrayTypeName.mAttribute_string.add_operation (GALGAS_string (" init"), inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 129)), object->mAttribute_mArrayTypeName.mAttribute_location  COMMA_SOURCE_FILE ("type-array.galgas", 129)), GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("type-array.galgas", 130)), ioArgument_ioContext, GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("type-array.galgas", 132)), GALGAS_bool (false), var_temporaries, joker_5749, joker_5769, var_allocaList, var_initInstructionGenerationList, var_sizeExpressionIR, inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 126)) ;
  GALGAS_bool test_2 = GALGAS_bool (kIsStrictSup, var_allocaList.getter_length (SOURCE_FILE ("type-array.galgas", 141)).add_operation (var_initInstructionGenerationList.getter_length (SOURCE_FILE ("type-array.galgas", 141)), inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 141)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
  if (kBoolTrue != test_2.boolEnum ()) {
    test_2 = var_sizeExpressionIR.mAttribute_mValue.getter_isLiteralInteger (SOURCE_FILE ("type-array.galgas", 141)).operator_not (SOURCE_FILE ("type-array.galgas", 141)) ;
  }
  const enumGalgasBool test_3 = test_2.boolEnum () ;
  if (kBoolTrue == test_3) {
    inCompiler->emitSemanticError (object->mAttribute_mSizeExpressionLocation, GALGAS_string ("array size expression is not static")  COMMA_SOURCE_FILE ("type-array.galgas", 142)) ;
  }else if (kBoolFalse == test_3) {
    GALGAS_bigint var_arraySize ;
    var_sizeExpressionIR.mAttribute_mValue.method_literalInteger (var_arraySize, inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 144)) ;
    GALGAS_unifiedTypeMap_2D_proxy var_elementType = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, object->mAttribute_mElementTypeName, inCompiler  COMMA_SOURCE_FILE ("type-array.galgas", 145)) ;
    GALGAS_classMethodMap var_classMethodMap = GALGAS_classMethodMap::constructor_emptyMap (SOURCE_FILE ("type-array.galgas", 147)) ;
    {
    var_classMethodMap.setter_insertKey (GALGAS_string ("size").getter_nowhere (SOURCE_FILE ("type-array.galgas", 148)), var_sizeExpressionIR, inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 148)) ;
    }
    {
    ioArgument_ioContext.mAttribute_mTypeMap.setter_insertKey (object->mAttribute_mArrayTypeName, GALGAS_string ("%$").add_operation (object->mAttribute_mArrayTypeName.getter_string (SOURCE_FILE ("type-array.galgas", 152)), inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 152)), GALGAS_typeKind::constructor_arrayType (ioArgument_ioContext.mAttribute_mPointerSize, var_elementType, var_arraySize  COMMA_SOURCE_FILE ("type-array.galgas", 153)), var_classMethodMap, GALGAS_bool (true), GALGAS_bool (true), GALGAS_bool (false), GALGAS_bool (false), var_elementType, inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 150)) ;
    }
    {
    ioArgument_ioContext.mAttribute_mConstructorMap.setter_insertKey (object->mAttribute_mArrayTypeName, GALGAS_constructorValue::constructor_zero (SOURCE_FILE ("type-array.galgas", 164)), inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 162)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_typeArrayDeclaration_enterInContext (void) {
  enterExtensionMethod_enterInContext (kTypeDescriptor_GALGAS_typeArrayDeclaration.mSlotID,
                                       extensionMethod_typeArrayDeclaration_enterInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_typeArrayDeclaration_enterInContext (defineExtensionMethod_typeArrayDeclaration_enterInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@typeArrayDeclaration semanticAnalysis'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_typeArrayDeclaration_semanticAnalysis (const cPtr_abstractDeclaration * inObject,
                                                                   const GALGAS_semanticContext constinArgument_inContext,
                                                                   GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                   GALGAS_intermediateCodeStruct & ioArgument_ioIntermediateCodeStruct,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_typeArrayDeclaration * object = (const cPtr_typeArrayDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_typeArrayDeclaration) ;
  GALGAS_unifiedTypeMap_2D_proxy var_selfType = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.mAttribute_mTypeMap, object->mAttribute_mArrayTypeName, inCompiler  COMMA_SOURCE_FILE ("type-array.galgas", 178)) ;
  GALGAS_unifiedTypeMap_2D_proxy var_countType = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.mAttribute_mTypeMap, GALGAS_string ("uint32").getter_nowhere (SOURCE_FILE ("type-array.galgas", 179)), inCompiler  COMMA_SOURCE_FILE ("type-array.galgas", 179)) ;
  GALGAS_instructionListIR var_countFunctionInstructionGenerationList = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("type-array.galgas", 181)) ;
  GALGAS_objectInMemoryIR var_countPtr = GALGAS_objectInMemoryIR::constructor_localValue (var_countType, GALGAS_string ("count.ptr")  COMMA_SOURCE_FILE ("type-array.galgas", 182)) ;
  {
  GALGAS_elementPtrList temp_0 = GALGAS_elementPtrList::constructor_emptyList (SOURCE_FILE ("type-array.galgas", 183)) ;
  temp_0.addAssign_operation (GALGAS_uint ((uint32_t) 0U), GALGAS_string ("count")  COMMA_SOURCE_FILE ("type-array.galgas", 183)) ;
  extensionSetter_appendGetElementPtrFromSelf (var_countFunctionInstructionGenerationList, var_countPtr, var_selfType, temp_0, inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 183)) ;
  }
  GALGAS_operandIR var_loadedCountValue ;
  extensionMethod_loadFromMemory (var_countPtr, ioArgument_ioTemporaries, var_countFunctionInstructionGenerationList, var_loadedCountValue, inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 184)) ;
  GALGAS_objectInMemoryIR var_resultPtr = GALGAS_objectInMemoryIR::constructor_localValue (var_countType, GALGAS_string ("result")  COMMA_SOURCE_FILE ("type-array.galgas", 185)) ;
  extensionMethod_storeInMemory (var_resultPtr, var_loadedCountValue, var_countFunctionInstructionGenerationList, inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 186)) ;
  ioArgument_ioIntermediateCodeStruct.mAttribute_mRoutineMapIR.addAssign_operation (GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (object->mAttribute_mArrayTypeName.getter_string (SOURCE_FILE ("type-array.galgas", 188)), inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 188)).add_operation (GALGAS_string (".count"), inCompiler COMMA_SOURCE_FILE ("type-array.galgas", 188)), object->mAttribute_mArrayTypeName.mAttribute_location  COMMA_SOURCE_FILE ("type-array.galgas", 188)), GALGAS_procFormalArgumentListForGeneration::constructor_emptyList (SOURCE_FILE ("type-array.galgas", 189)), GALGAS_allocaList::constructor_emptyList (SOURCE_FILE ("type-array.galgas", 190)), var_countFunctionInstructionGenerationList, GALGAS_bool (false), GALGAS_bool (false), GALGAS_bool (false), GALGAS_bool (false), GALGAS_routineKind::constructor_function (SOURCE_FILE ("type-array.galgas", 196)), var_countType, inCompiler  COMMA_SOURCE_FILE ("type-array.galgas", 187)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_typeArrayDeclaration_semanticAnalysis (void) {
  enterExtensionMethod_semanticAnalysis (kTypeDescriptor_GALGAS_typeArrayDeclaration.mSlotID,
                                         extensionMethod_typeArrayDeclaration_semanticAnalysis) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_typeArrayDeclaration_semanticAnalysis (defineExtensionMethod_typeArrayDeclaration_semanticAnalysis, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@booleanDeclaration location'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_location extensionGetter_booleanDeclaration_location (const cPtr_abstractDeclaration * inObject,
                                                                    C_Compiler * /* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_outLocation ; // Returned variable
  const cPtr_booleanDeclaration * object = (const cPtr_booleanDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_booleanDeclaration) ;
  result_outLocation = object->mAttribute_mBooleanTypeName.mAttribute_location ;
//---
  return result_outLocation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_booleanDeclaration_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_booleanDeclaration.mSlotID,
                                 extensionGetter_booleanDeclaration_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_booleanDeclaration_location (defineExtensionGetter_booleanDeclaration_location, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@booleanDeclaration addExtension'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_booleanDeclaration_addExtension (const cPtr_abstractDeclaration * inObject,
                                                             GALGAS_extensionDeclarationListAST & /* ioArgument_ioExtensionDeclarationListAST */,
                                                             GALGAS_abstractDeclaration & outArgument_outNewDeclaration,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_booleanDeclaration * object = (const cPtr_booleanDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_booleanDeclaration) ;
  const GALGAS_booleanDeclaration temp_0 = object ;
  outArgument_outNewDeclaration = temp_0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_booleanDeclaration_addExtension (void) {
  enterExtensionMethod_addExtension (kTypeDescriptor_GALGAS_booleanDeclaration.mSlotID,
                                     extensionMethod_booleanDeclaration_addExtension) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_booleanDeclaration_addExtension (defineExtensionMethod_booleanDeclaration_addExtension, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Overriding extension method '@booleanDeclaration enterInPrecedenceGraph'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_booleanDeclaration_enterInPrecedenceGraph (const cPtr_abstractDeclaration * inObject,
                                                                       GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_booleanDeclaration * object = (const cPtr_booleanDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_booleanDeclaration) ;
  GALGAS_lstring var_boolTypeName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (object->mAttribute_mBooleanTypeName.getter_string (SOURCE_FILE ("type-bool.galgas", 34)), inCompiler COMMA_SOURCE_FILE ("type-bool.galgas", 34)), object->mAttribute_mBooleanTypeName.mAttribute_location  COMMA_SOURCE_FILE ("type-bool.galgas", 34)) ;
  {
  const GALGAS_booleanDeclaration temp_0 = object ;
  ioArgument_ioGraph.setter_addNode (var_boolTypeName, temp_0, inCompiler COMMA_SOURCE_FILE ("type-bool.galgas", 35)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_booleanDeclaration_enterInPrecedenceGraph (void) {
  enterExtensionMethod_enterInPrecedenceGraph (kTypeDescriptor_GALGAS_booleanDeclaration.mSlotID,
                                               extensionMethod_booleanDeclaration_enterInPrecedenceGraph) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_booleanDeclaration_enterInPrecedenceGraph (defineExtensionMethod_booleanDeclaration_enterInPrecedenceGraph, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                Overriding extension getter '@booleanDeclaration keyRepresentationForErrorSignaling'                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_booleanDeclaration_keyRepresentationForErrorSignaling (const cPtr_abstractDeclaration * inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outRepresentation ; // Returned variable
  const cPtr_booleanDeclaration * object = (const cPtr_booleanDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_booleanDeclaration) ;
  result_outRepresentation = GALGAS_string ("bool $").add_operation (object->mAttribute_mBooleanTypeName.getter_string (SOURCE_FILE ("type-bool.galgas", 41)), inCompiler COMMA_SOURCE_FILE ("type-bool.galgas", 41)) ;
//---
  return result_outRepresentation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_booleanDeclaration_keyRepresentationForErrorSignaling (void) {
  enterExtensionGetter_keyRepresentationForErrorSignaling (kTypeDescriptor_GALGAS_booleanDeclaration.mSlotID,
                                                           extensionGetter_booleanDeclaration_keyRepresentationForErrorSignaling) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_booleanDeclaration_keyRepresentationForErrorSignaling (defineExtensionGetter_booleanDeclaration_keyRepresentationForErrorSignaling, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@booleanDeclaration enterInContext'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_booleanDeclaration_enterInContext (const cPtr_abstractDeclaration * inObject,
                                                               const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                               GALGAS_semanticContext & ioArgument_ioContext,
                                                               GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_booleanDeclaration * object = (const cPtr_booleanDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_booleanDeclaration) ;
  GALGAS_bool var_copyable = GALGAS_bool (true) ;
  cEnumerator_lstringlist enumerator_2813 (object->mAttribute_mAttributeList, kEnumeration_up) ;
  while (enumerator_2813.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_2813.current_mValue (HERE).mAttribute_string.objectCompare (GALGAS_string ("unique"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const enumGalgasBool test_1 = var_copyable.operator_not (SOURCE_FILE ("type-bool.galgas", 57)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_location location_2 (enumerator_2813.current_mValue (HERE).getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_2, GALGAS_string ("duplicated attribute")  COMMA_SOURCE_FILE ("type-bool.galgas", 58)) ;
      }
      var_copyable = GALGAS_bool (false) ;
    }
    enumerator_2813.gotoNextObject () ;
  }
  {
  ioArgument_ioContext.mAttribute_mTypeMap.setter_insertKey (object->mAttribute_mBooleanTypeName, GALGAS_string ("i1"), GALGAS_typeKind::constructor_boolean (SOURCE_FILE ("type-bool.galgas", 67)), GALGAS_classMethodMap::constructor_emptyMap (SOURCE_FILE ("type-bool.galgas", 68)), GALGAS_bool (true), var_copyable, GALGAS_bool (true), GALGAS_bool (true), GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("type-bool.galgas", 73)), inCompiler COMMA_SOURCE_FILE ("type-bool.galgas", 64)) ;
  }
  const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, ioArgument_ioContext.mAttribute_mBooleanType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("type-bool.galgas", 76)))).boolEnum () ;
  if (kBoolTrue == test_3) {
    GALGAS_location location_4 (object->mAttribute_mBooleanTypeName.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_4, GALGAS_string ("Boolean type already defined")  COMMA_SOURCE_FILE ("type-bool.galgas", 77)) ;
  }
  GALGAS_unifiedTypeMap_2D_proxy var_boolType = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, object->mAttribute_mBooleanTypeName, inCompiler  COMMA_SOURCE_FILE ("type-bool.galgas", 79)) ;
  ioArgument_ioContext.mAttribute_mBooleanType = var_boolType ;
  {
  routine_enterBooleanOperators (object->mAttribute_mBooleanTypeName, ioArgument_ioContext, inCompiler  COMMA_SOURCE_FILE ("type-bool.galgas", 82)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_booleanDeclaration_enterInContext (void) {
  enterExtensionMethod_enterInContext (kTypeDescriptor_GALGAS_booleanDeclaration.mSlotID,
                                       extensionMethod_booleanDeclaration_enterInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_booleanDeclaration_enterInContext (defineExtensionMethod_booleanDeclaration_enterInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Overriding extension method '@booleanDeclaration enterRoutinesInContext'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_booleanDeclaration_enterRoutinesInContext (const cPtr_abstractDeclaration * /* inObject */,
                                                                       const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                                       GALGAS_semanticContext & /* ioArgument_ioContext */,
                                                                       GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                                       C_Compiler * /* inCompiler */
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_booleanDeclaration_enterRoutinesInContext (void) {
  enterExtensionMethod_enterRoutinesInContext (kTypeDescriptor_GALGAS_booleanDeclaration.mSlotID,
                                               extensionMethod_booleanDeclaration_enterRoutinesInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_booleanDeclaration_enterRoutinesInContext (defineExtensionMethod_booleanDeclaration_enterRoutinesInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@booleanDeclaration semanticAnalysis'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_booleanDeclaration_semanticAnalysis (const cPtr_abstractDeclaration * /* inObject */,
                                                                 const GALGAS_semanticContext /* constinArgument_inContext */,
                                                                 GALGAS_semanticTemporariesStruct & /* ioArgument_ioTemporaries */,
                                                                 GALGAS_intermediateCodeStruct & /* ioArgument_ioIntermediateCodeStruct */,
                                                                 C_Compiler * /* inCompiler */
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_booleanDeclaration_semanticAnalysis (void) {
  enterExtensionMethod_semanticAnalysis (kTypeDescriptor_GALGAS_booleanDeclaration.mSlotID,
                                         extensionMethod_booleanDeclaration_semanticAnalysis) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_booleanDeclaration_semanticAnalysis (defineExtensionMethod_booleanDeclaration_semanticAnalysis, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension getter '@enumerationDeclaration location'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_location extensionGetter_enumerationDeclaration_location (const cPtr_abstractDeclaration * inObject,
                                                                        C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_outLocation ; // Returned variable
  const cPtr_enumerationDeclaration * object = (const cPtr_enumerationDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_enumerationDeclaration) ;
  result_outLocation = object->mAttribute_mEnumerationName.mAttribute_location ;
//---
  return result_outLocation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_enumerationDeclaration_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_enumerationDeclaration.mSlotID,
                                 extensionGetter_enumerationDeclaration_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_enumerationDeclaration_location (defineExtensionGetter_enumerationDeclaration_location, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@enumerationDeclaration addExtension'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_enumerationDeclaration_addExtension (const cPtr_abstractDeclaration * inObject,
                                                                 GALGAS_extensionDeclarationListAST & /* ioArgument_ioExtensionDeclarationListAST */,
                                                                 GALGAS_abstractDeclaration & outArgument_outNewDeclaration,
                                                                 C_Compiler * /* inCompiler */
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_enumerationDeclaration * object = (const cPtr_enumerationDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_enumerationDeclaration) ;
  const GALGAS_enumerationDeclaration temp_0 = object ;
  outArgument_outNewDeclaration = temp_0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_enumerationDeclaration_addExtension (void) {
  enterExtensionMethod_addExtension (kTypeDescriptor_GALGAS_enumerationDeclaration.mSlotID,
                                     extensionMethod_enumerationDeclaration_addExtension) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_enumerationDeclaration_addExtension (defineExtensionMethod_enumerationDeclaration_addExtension, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    Overriding extension method '@enumerationDeclaration enterInPrecedenceGraph'                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_enumerationDeclaration_enterInPrecedenceGraph (const cPtr_abstractDeclaration * inObject,
                                                                           GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_enumerationDeclaration * object = (const cPtr_enumerationDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_enumerationDeclaration) ;
  GALGAS_lstring var_typeName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (object->mAttribute_mEnumerationName.getter_string (SOURCE_FILE ("type-enumeration-declaration.galgas", 72)), inCompiler COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 72)), object->mAttribute_mEnumerationName.mAttribute_location  COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 72)) ;
  {
  const GALGAS_enumerationDeclaration temp_0 = object ;
  ioArgument_ioGraph.setter_addNode (var_typeName, temp_0, inCompiler COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 73)) ;
  }
  {
  ioArgument_ioGraph.setter_addEdge (var_typeName, GALGAS_string ("$").add_operation (function_boolTypeName (inCompiler COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 74)), inCompiler COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 74)).getter_nowhere (SOURCE_FILE ("type-enumeration-declaration.galgas", 74)) COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 74)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_enumerationDeclaration_enterInPrecedenceGraph (void) {
  enterExtensionMethod_enterInPrecedenceGraph (kTypeDescriptor_GALGAS_enumerationDeclaration.mSlotID,
                                               extensionMethod_enumerationDeclaration_enterInPrecedenceGraph) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_enumerationDeclaration_enterInPrecedenceGraph (defineExtensionMethod_enumerationDeclaration_enterInPrecedenceGraph, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//              Overriding extension getter '@enumerationDeclaration keyRepresentationForErrorSignaling'               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_enumerationDeclaration_keyRepresentationForErrorSignaling (const cPtr_abstractDeclaration * inObject,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outRepresentation ; // Returned variable
  const cPtr_enumerationDeclaration * object = (const cPtr_enumerationDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_enumerationDeclaration) ;
  result_outRepresentation = GALGAS_string ("enum $").add_operation (object->mAttribute_mEnumerationName.getter_string (SOURCE_FILE ("type-enumeration-declaration.galgas", 80)), inCompiler COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 80)) ;
//---
  return result_outRepresentation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_enumerationDeclaration_keyRepresentationForErrorSignaling (void) {
  enterExtensionGetter_keyRepresentationForErrorSignaling (kTypeDescriptor_GALGAS_enumerationDeclaration.mSlotID,
                                                           extensionGetter_enumerationDeclaration_keyRepresentationForErrorSignaling) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_enumerationDeclaration_keyRepresentationForErrorSignaling (defineExtensionGetter_enumerationDeclaration_keyRepresentationForErrorSignaling, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@enumerationDeclaration enterInContext'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_enumerationDeclaration_enterInContext (const cPtr_abstractDeclaration * inObject,
                                                                   const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                                   GALGAS_semanticContext & ioArgument_ioContext,
                                                                   GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_enumerationDeclaration * object = (const cPtr_enumerationDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_enumerationDeclaration) ;
  GALGAS_bool var_copyable = GALGAS_bool (true) ;
  GALGAS_unifiedTypeMap_2D_proxy var_selfType ;
  {
  GALGAS_unifiedTypeMap_2D_proxy::class_method_makeProxy (ioArgument_ioContext.mAttribute_mTypeMap, object->mAttribute_mEnumerationName, var_selfType COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 110)) ;
  }
  GALGAS_enumConstantMap var_enumConstantMap = GALGAS_enumConstantMap::constructor_emptyMap (SOURCE_FILE ("type-enumeration-declaration.galgas", 111)) ;
  GALGAS_classMethodMap var_classMethodMap = GALGAS_classMethodMap::constructor_emptyMap (SOURCE_FILE ("type-enumeration-declaration.galgas", 112)) ;
  cEnumerator_lstringlist enumerator_4732 (object->mAttribute_mCaseNameList, kEnumeration_up) ;
  while (enumerator_4732.hasCurrentObject ()) {
    GALGAS_uint var_idx = var_enumConstantMap.getter_count (SOURCE_FILE ("type-enumeration-declaration.galgas", 114)) ;
    {
    var_enumConstantMap.setter_insertKey (enumerator_4732.current_mValue (HERE), var_idx, inCompiler COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 115)) ;
    }
    {
    var_classMethodMap.setter_insertKey (enumerator_4732.current_mValue (HERE), GALGAS_operandIR::constructor_new (var_selfType, GALGAS_valueIR::constructor_literalInteger (var_idx.getter_bigint (SOURCE_FILE ("type-enumeration-declaration.galgas", 116))  COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 116))  COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 116)), inCompiler COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 116)) ;
    }
    enumerator_4732.gotoNextObject () ;
  }
  {
  ioArgument_ioContext.mAttribute_mTypeMap.setter_insertKey (object->mAttribute_mEnumerationName, GALGAS_string ("i").add_operation (var_enumConstantMap.getter_count (SOURCE_FILE ("type-enumeration-declaration.galgas", 120)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 120)).getter_significantBitCount (SOURCE_FILE ("type-enumeration-declaration.galgas", 120)).getter_string (SOURCE_FILE ("type-enumeration-declaration.galgas", 120)), inCompiler COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 120)), GALGAS_typeKind::constructor_enumeration (var_enumConstantMap  COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 121)), var_classMethodMap, GALGAS_bool (true), var_copyable, GALGAS_bool (true), GALGAS_bool (true), GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("type-enumeration-declaration.galgas", 127)), inCompiler COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 118)) ;
  }
  {
  routine_enterEnumerationOperators (object->mAttribute_mEnumerationName, ioArgument_ioContext, inCompiler  COMMA_SOURCE_FILE ("type-enumeration-declaration.galgas", 130)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_enumerationDeclaration_enterInContext (void) {
  enterExtensionMethod_enterInContext (kTypeDescriptor_GALGAS_enumerationDeclaration.mSlotID,
                                       extensionMethod_enumerationDeclaration_enterInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_enumerationDeclaration_enterInContext (defineExtensionMethod_enumerationDeclaration_enterInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    Overriding extension method '@enumerationDeclaration enterRoutinesInContext'                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_enumerationDeclaration_enterRoutinesInContext (const cPtr_abstractDeclaration * /* inObject */,
                                                                           const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                                           GALGAS_semanticContext & /* ioArgument_ioContext */,
                                                                           GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                                           C_Compiler * /* inCompiler */
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_enumerationDeclaration_enterRoutinesInContext (void) {
  enterExtensionMethod_enterRoutinesInContext (kTypeDescriptor_GALGAS_enumerationDeclaration.mSlotID,
                                               extensionMethod_enumerationDeclaration_enterRoutinesInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_enumerationDeclaration_enterRoutinesInContext (defineExtensionMethod_enumerationDeclaration_enterRoutinesInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Overriding extension method '@enumerationDeclaration semanticAnalysis'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_enumerationDeclaration_semanticAnalysis (const cPtr_abstractDeclaration * /* inObject */,
                                                                     const GALGAS_semanticContext /* constinArgument_inContext */,
                                                                     GALGAS_semanticTemporariesStruct & /* ioArgument_ioTemporaries */,
                                                                     GALGAS_intermediateCodeStruct & /* ioArgument_ioIntermediateCodeStruct */,
                                                                     C_Compiler * /* inCompiler */
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_enumerationDeclaration_semanticAnalysis (void) {
  enterExtensionMethod_semanticAnalysis (kTypeDescriptor_GALGAS_enumerationDeclaration.mSlotID,
                                         extensionMethod_enumerationDeclaration_semanticAnalysis) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_enumerationDeclaration_semanticAnalysis (defineExtensionMethod_enumerationDeclaration_semanticAnalysis, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@structureDeclaration location'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_location extensionGetter_structureDeclaration_location (const cPtr_abstractDeclaration * inObject,
                                                                      C_Compiler * /* inCompiler */
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_outLocation ; // Returned variable
  const cPtr_structureDeclaration * object = (const cPtr_structureDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_structureDeclaration) ;
  result_outLocation = object->mAttribute_mStructureName.mAttribute_location ;
//---
  return result_outLocation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_structureDeclaration_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_structureDeclaration.mSlotID,
                                 extensionGetter_structureDeclaration_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_structureDeclaration_location (defineExtensionGetter_structureDeclaration_location, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@structureDeclaration addExtension'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_structureDeclaration_addExtension (const cPtr_abstractDeclaration * inObject,
                                                               GALGAS_extensionDeclarationListAST & ioArgument_ioExtensionDeclarationListAST,
                                                               GALGAS_abstractDeclaration & outArgument_outNewDeclaration,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structureDeclaration * object = (const cPtr_structureDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_structureDeclaration) ;
  const GALGAS_structureDeclaration temp_0 = object ;
  GALGAS_structureDeclaration var_newDeclaration = temp_0 ;
  GALGAS_extensionDeclarationListAST var_currentExtensionDeclarationListAST = ioArgument_ioExtensionDeclarationListAST ;
  ioArgument_ioExtensionDeclarationListAST = GALGAS_extensionDeclarationListAST::constructor_emptyList (SOURCE_FILE ("type-structure-declaration.galgas", 133)) ;
  cEnumerator_extensionDeclarationListAST enumerator_4802 (var_currentExtensionDeclarationListAST, kEnumeration_up) ;
  while (enumerator_4802.hasCurrentObject ()) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, object->mAttribute_mStructureName.mAttribute_string.objectCompare (enumerator_4802.current_mTypeName (HERE).mAttribute_string)).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_newDeclaration = GALGAS_structureDeclaration::constructor_new (var_newDeclaration.getter_mStructureName (SOURCE_FILE ("type-structure-declaration.galgas", 137)), var_newDeclaration.getter_mAttributeListAST (SOURCE_FILE ("type-structure-declaration.galgas", 138)), var_newDeclaration.getter_mStructureFieldListAST (SOURCE_FILE ("type-structure-declaration.galgas", 139)).add_operation (enumerator_4802.current_mFieldList (HERE), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 139)), var_newDeclaration.getter_mProcedureDeclarationListAST (SOURCE_FILE ("type-structure-declaration.galgas", 140)).add_operation (enumerator_4802.current_mProcedureDeclarationListAST (HERE), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 140)), var_newDeclaration.getter_mServiceListAST (SOURCE_FILE ("type-structure-declaration.galgas", 141)), var_newDeclaration.getter_mSectionListAST (SOURCE_FILE ("type-structure-declaration.galgas", 142)), var_newDeclaration.getter_mPrimitiveListAST (SOURCE_FILE ("type-structure-declaration.galgas", 143)), var_newDeclaration.getter_mGuardListAST (SOURCE_FILE ("type-structure-declaration.galgas", 144))  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 136)) ;
    }else if (kBoolFalse == test_1) {
      ioArgument_ioExtensionDeclarationListAST.addAssign_operation (enumerator_4802.current_mTypeName (HERE), enumerator_4802.current_mProcedureDeclarationListAST (HERE), enumerator_4802.current_mFieldList (HERE)  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 147)) ;
    }
    enumerator_4802.gotoNextObject () ;
  }
  outArgument_outNewDeclaration = var_newDeclaration ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_structureDeclaration_addExtension (void) {
  enterExtensionMethod_addExtension (kTypeDescriptor_GALGAS_structureDeclaration.mSlotID,
                                     extensionMethod_structureDeclaration_addExtension) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_structureDeclaration_addExtension (defineExtensionMethod_structureDeclaration_addExtension, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension method '@structureDeclaration enterInPrecedenceGraph'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_structureDeclaration_enterInPrecedenceGraph (const cPtr_abstractDeclaration * inObject,
                                                                         GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structureDeclaration * object = (const cPtr_structureDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_structureDeclaration) ;
  GALGAS_lstring var_structureTypeName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (object->mAttribute_mStructureName.getter_string (SOURCE_FILE ("type-structure-declaration.galgas", 158)), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 158)), object->mAttribute_mStructureName.mAttribute_location  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 158)) ;
  {
  const GALGAS_structureDeclaration temp_0 = object ;
  ioArgument_ioGraph.setter_addNode (var_structureTypeName, temp_0, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 160)) ;
  }
  cEnumerator_structureFieldListAST enumerator_6147 (object->mAttribute_mStructureFieldListAST, kEnumeration_up) ;
  while (enumerator_6147.hasCurrentObject ()) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, enumerator_6147.current_mFieldTypeName (HERE).mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_lstring var_typeName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (enumerator_6147.current_mFieldTypeName (HERE).getter_string (SOURCE_FILE ("type-structure-declaration.galgas", 164)), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 164)), enumerator_6147.current_mFieldTypeName (HERE).mAttribute_location  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 164)) ;
      {
      ioArgument_ioGraph.setter_addEdge (var_structureTypeName, var_typeName COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 165)) ;
      }
    }
    switch (enumerator_6147.current_mInitialisation (HERE).enumValue ()) {
    case GALGAS_structureVarInit::kNotBuilt:
      break ;
    case GALGAS_structureVarInit::kEnum_noExpression:
      {
      }
      break ;
    case GALGAS_structureVarInit::kEnum_expression:
      {
        const cEnumAssociatedValues_structureVarInit_expression * extractPtr_6511 = (const cEnumAssociatedValues_structureVarInit_expression *) (enumerator_6147.current_mInitialisation (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_initExpression = extractPtr_6511->mAssociatedValue0 ;
        callExtensionMethod_addDependenceEdgeForStaticExpression ((const cPtr_expressionAST *) extractedValue_initExpression.ptr (), var_structureTypeName, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 170)) ;
      }
      break ;
    }
    enumerator_6147.gotoNextObject () ;
  }
  cEnumerator_procedureDeclarationListAST enumerator_6596 (object->mAttribute_mProcedureDeclarationListAST, kEnumeration_up) ;
  while (enumerator_6596.hasCurrentObject ()) {
    cEnumerator_procFormalArgumentList enumerator_6670 (enumerator_6596.current_mProcedureFormalArgumentList (HERE), kEnumeration_up) ;
    while (enumerator_6670.hasCurrentObject ()) {
      GALGAS_lstring var_typeName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (enumerator_6670.current_mFormalArgumentTypeName (HERE).getter_string (SOURCE_FILE ("type-structure-declaration.galgas", 176)), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 176)), enumerator_6670.current_mFormalArgumentTypeName (HERE).mAttribute_location  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 176)) ;
      {
      ioArgument_ioGraph.setter_noteNode (var_typeName COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 177)) ;
      }
      enumerator_6670.gotoNextObject () ;
    }
    extensionMethod_noteInstructionListTypesInPrecedenceGraph (enumerator_6596.current_mProcedureInstructionList (HERE), ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 179)) ;
    enumerator_6596.gotoNextObject () ;
  }
  extensionMethod_noteServiceTypesInPrecedenceGraph (object->mAttribute_mServiceListAST, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 182)) ;
  extensionMethod_noteServiceTypesInPrecedenceGraph (object->mAttribute_mSectionListAST, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 183)) ;
  extensionMethod_notePrimitiveTypesInPrecedenceGraph (object->mAttribute_mPrimitiveListAST, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 184)) ;
  extensionMethod_noteTypesInPrecedenceGraph (object->mAttribute_mGuardListAST, ioArgument_ioGraph, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 186)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_structureDeclaration_enterInPrecedenceGraph (void) {
  enterExtensionMethod_enterInPrecedenceGraph (kTypeDescriptor_GALGAS_structureDeclaration.mSlotID,
                                               extensionMethod_structureDeclaration_enterInPrecedenceGraph) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_structureDeclaration_enterInPrecedenceGraph (defineExtensionMethod_structureDeclaration_enterInPrecedenceGraph, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//               Overriding extension getter '@structureDeclaration keyRepresentationForErrorSignaling'                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_structureDeclaration_keyRepresentationForErrorSignaling (const cPtr_abstractDeclaration * inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outRepresentation ; // Returned variable
  const cPtr_structureDeclaration * object = (const cPtr_structureDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_structureDeclaration) ;
  result_outRepresentation = GALGAS_string ("struct $").add_operation (object->mAttribute_mStructureName.getter_string (SOURCE_FILE ("type-structure-declaration.galgas", 192)), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 192)) ;
//---
  return result_outRepresentation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_structureDeclaration_keyRepresentationForErrorSignaling (void) {
  enterExtensionGetter_keyRepresentationForErrorSignaling (kTypeDescriptor_GALGAS_structureDeclaration.mSlotID,
                                                           extensionGetter_structureDeclaration_keyRepresentationForErrorSignaling) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_structureDeclaration_keyRepresentationForErrorSignaling (defineExtensionGetter_structureDeclaration_keyRepresentationForErrorSignaling, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@structureDeclaration enterInContext'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_structureDeclaration_enterInContext (const cPtr_abstractDeclaration * inObject,
                                                                 const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                                 GALGAS_semanticContext & ioArgument_ioContext,
                                                                 GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structureDeclaration * object = (const cPtr_structureDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_structureDeclaration) ;
  GALGAS_propertyList var_propertyList = GALGAS_propertyList::constructor_emptyList (SOURCE_FILE ("type-structure-declaration.galgas", 239)) ;
  GALGAS_propertyMap var_propertyMap = GALGAS_propertyMap::constructor_emptyMap (SOURCE_FILE ("type-structure-declaration.galgas", 240)) ;
  GALGAS_sortedOperandIRList var_sortedOperandIRList = GALGAS_sortedOperandIRList::constructor_emptySortedList (SOURCE_FILE ("type-structure-declaration.galgas", 241)) ;
  GALGAS_constructorSignature var_constructorSignature = GALGAS_constructorSignature::constructor_emptyList (SOURCE_FILE ("type-structure-declaration.galgas", 242)) ;
  GALGAS_bool var_canBeCopied = GALGAS_bool (true) ;
  cEnumerator_structureFieldListAST enumerator_9366 (object->mAttribute_mStructureFieldListAST, kEnumeration_up) ;
  GALGAS_uint index_9337 ((uint32_t) 0) ;
  while (enumerator_9366.hasCurrentObject ()) {
    GALGAS_unifiedTypeMap_2D_proxy temp_0 ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, enumerator_9366.current_mFieldTypeName (HERE).mAttribute_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      temp_0 = GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("type-structure-declaration.galgas", 247)) ;
    }else if (kBoolFalse == test_1) {
      temp_0 = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, enumerator_9366.current_mFieldTypeName (HERE), inCompiler  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 248)) ;
    }
    GALGAS_unifiedTypeMap_2D_proxy var_fieldType = temp_0 ;
    GALGAS_instructionListIR var_initInstructionGenerationList = GALGAS_instructionListIR::constructor_emptyList (SOURCE_FILE ("type-structure-declaration.galgas", 251)) ;
    GALGAS_allocaList var_allocaList = GALGAS_allocaList::constructor_emptyList (SOURCE_FILE ("type-structure-declaration.galgas", 252)) ;
    GALGAS_semanticTemporariesStruct var_temporaries = GALGAS_semanticTemporariesStruct::constructor_default (SOURCE_FILE ("type-structure-declaration.galgas", 253)) ;
    switch (enumerator_9366.current_mInitialisation (HERE).enumValue ()) {
    case GALGAS_structureVarInit::kNotBuilt:
      break ;
    case GALGAS_structureVarInit::kEnum_expression:
      {
        const cEnumAssociatedValues_structureVarInit_expression * extractPtr_11180 = (const cEnumAssociatedValues_structureVarInit_expression *) (enumerator_9366.current_mInitialisation (HERE).unsafePointer ()) ;
        const GALGAS_expressionAST extractedValue_initExpression = extractPtr_11180->mAssociatedValue0 ;
        GALGAS_staticStringMap joker_10146 = GALGAS_staticStringMap::constructor_emptyMap (SOURCE_FILE ("type-structure-declaration.galgas", 265)) ;
        GALGAS_variableMap joker_10170 = GALGAS_variableMap::constructor_emptyMap (SOURCE_FILE ("type-structure-declaration.galgas", 266)) ;
        GALGAS_operandIR var_expressionIR ;
        callExtensionMethod_analyzeExpression ((const cPtr_expressionAST *) extractedValue_initExpression.ptr (), GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("type-structure-declaration.galgas", 257)), GALGAS_bool (false), GALGAS_lstring::constructor_new (object->mAttribute_mStructureName.mAttribute_string.add_operation (GALGAS_string (" init"), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 259)), object->mAttribute_mStructureName.mAttribute_location  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 259)), var_fieldType, ioArgument_ioContext, GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("type-structure-declaration.galgas", 262)), GALGAS_bool (false), var_temporaries, joker_10146, joker_10170, var_allocaList, var_initInstructionGenerationList, var_expressionIR, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 256)) ;
        GALGAS_bool test_2 = GALGAS_bool (kIsStrictSup, var_initInstructionGenerationList.getter_length (SOURCE_FILE ("type-structure-declaration.galgas", 271)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsStrictSup, var_allocaList.getter_length (SOURCE_FILE ("type-structure-declaration.galgas", 271)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
        }
        GALGAS_bool test_3 = test_2 ;
        if (kBoolTrue != test_3.boolEnum ()) {
          test_3 = extensionGetter_isStatic (var_expressionIR.mAttribute_mValue, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 271)).operator_not (SOURCE_FILE ("type-structure-declaration.galgas", 271)) ;
        }
        const enumGalgasBool test_4 = test_3.boolEnum () ;
        if (kBoolTrue == test_4) {
          GALGAS_location location_5 (enumerator_9366.current_mFieldName (HERE).getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_5, GALGAS_string ("initialization expression cannot be computed statically")  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 272)) ;
        }
        GALGAS_unifiedTypeMap_2D_proxy var_actualFieldType ;
        const enumGalgasBool test_6 = GALGAS_bool (kIsNotEqual, var_fieldType.objectCompare (GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("type-structure-declaration.galgas", 275)))).boolEnum () ;
        if (kBoolTrue == test_6) {
          var_actualFieldType = var_fieldType ;
        }else if (kBoolFalse == test_6) {
          var_actualFieldType = var_expressionIR.mAttribute_mType ;
        }
        const enumGalgasBool test_7 = var_actualFieldType.getter_instantiable (inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 280)).operator_not (SOURCE_FILE ("type-structure-declaration.galgas", 280)).boolEnum () ;
        if (kBoolTrue == test_7) {
          GALGAS_location location_8 (enumerator_9366.current_mFieldName (HERE).getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_8, GALGAS_string ("$").add_operation (var_actualFieldType.getter_key (inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 281)), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 281)).add_operation (GALGAS_string (" type is not instanciable"), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 281))  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 281)) ;
        }
        const enumGalgasBool test_9 = var_actualFieldType.getter_copyable (inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 283)).operator_not (SOURCE_FILE ("type-structure-declaration.galgas", 283)).boolEnum () ;
        if (kBoolTrue == test_9) {
          var_canBeCopied = GALGAS_bool (false) ;
        }
        var_propertyList.addAssign_operation (enumerator_9366.current_mFieldName (HERE).mAttribute_string, var_actualFieldType  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 286)) ;
        {
        var_propertyMap.setter_insertKey (enumerator_9366.current_mFieldName (HERE), enumerator_9366.current_mIsPublic (HERE), var_actualFieldType, var_propertyMap.getter_count (SOURCE_FILE ("type-structure-declaration.galgas", 287)), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 287)) ;
        }
        var_sortedOperandIRList.addAssign_operation (GALGAS_operandIR::constructor_new (var_actualFieldType, var_expressionIR.mAttribute_mValue  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 288)), index_9337  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 288)) ;
      }
      break ;
    case GALGAS_structureVarInit::kEnum_noExpression:
      {
        const enumGalgasBool test_10 = var_fieldType.getter_instantiable (inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 290)).operator_not (SOURCE_FILE ("type-structure-declaration.galgas", 290)).boolEnum () ;
        if (kBoolTrue == test_10) {
          GALGAS_location location_11 (enumerator_9366.current_mFieldName (HERE).getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_11, GALGAS_string ("$").add_operation (var_fieldType.getter_key (inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 291)), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 291)).add_operation (GALGAS_string (" type is not instanciable"), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 291))  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 291)) ;
        }
        var_propertyList.addAssign_operation (enumerator_9366.current_mFieldName (HERE).mAttribute_string, var_fieldType  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 293)) ;
        {
        var_propertyMap.setter_insertKey (enumerator_9366.current_mFieldName (HERE), enumerator_9366.current_mIsPublic (HERE), var_fieldType, var_propertyMap.getter_count (SOURCE_FILE ("type-structure-declaration.galgas", 294)), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 294)) ;
        }
        var_constructorSignature.addAssign_operation (enumerator_9366.current_mFieldName (HERE).mAttribute_string, var_fieldType, index_9337  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 295)) ;
      }
      break ;
    }
    enumerator_9366.gotoNextObject () ;
    index_9337.increment_operation (inCompiler  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 244)) ;
  }
  {
  ioArgument_ioContext.mAttribute_mConstructorMap.setter_insertKey (object->mAttribute_mStructureName, GALGAS_constructorValue::constructor_structure (var_constructorSignature, var_sortedOperandIRList  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 300)), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 298)) ;
  }
  GALGAS_bool var_copyableAttribute = GALGAS_bool (false) ;
  cEnumerator_lstringlist enumerator_11851 (object->mAttribute_mAttributeListAST, kEnumeration_up) ;
  while (enumerator_11851.hasCurrentObject ()) {
    const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, enumerator_11851.current_mValue (HERE).mAttribute_string.objectCompare (GALGAS_string ("copyable"))).boolEnum () ;
    if (kBoolTrue == test_12) {
      const enumGalgasBool test_13 = var_copyableAttribute.boolEnum () ;
      if (kBoolTrue == test_13) {
        GALGAS_location location_14 (enumerator_11851.current_mValue (HERE).getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_14, GALGAS_string ("duplicated attribute")  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 307)) ;
      }
      var_copyableAttribute = GALGAS_bool (true) ;
    }else if (kBoolFalse == test_12) {
      GALGAS_location location_15 (enumerator_11851.current_mValue (HERE).getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_15, GALGAS_string ("only @copyable attribute is allowed here")  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 311)) ;
    }
    enumerator_11851.gotoNextObject () ;
  }
  GALGAS_bool test_16 = var_copyableAttribute ;
  if (kBoolTrue == test_16.boolEnum ()) {
    test_16 = var_canBeCopied.operator_not (SOURCE_FILE ("type-structure-declaration.galgas", 314)) ;
  }
  const enumGalgasBool test_17 = test_16.boolEnum () ;
  if (kBoolTrue == test_17) {
    GALGAS_location location_18 (object->mAttribute_mStructureName.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_18, GALGAS_string ("this structure cannot be copied, one field is not copyable")  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 315)) ;
    var_copyableAttribute = GALGAS_bool (false) ;
  }
  {
  ioArgument_ioContext.mAttribute_mTypeMap.setter_insertKey (object->mAttribute_mStructureName, GALGAS_string ("%$").add_operation (object->mAttribute_mStructureName.getter_string (SOURCE_FILE ("type-structure-declaration.galgas", 321)), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 321)), GALGAS_typeKind::constructor_structure (var_propertyMap, var_propertyList  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 322)), GALGAS_classMethodMap::constructor_emptyMap (SOURCE_FILE ("type-structure-declaration.galgas", 323)), GALGAS_bool (true), var_copyableAttribute, GALGAS_bool (false), GALGAS_bool (false), GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("type-structure-declaration.galgas", 328)), inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 319)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_structureDeclaration_enterInContext (void) {
  enterExtensionMethod_enterInContext (kTypeDescriptor_GALGAS_structureDeclaration.mSlotID,
                                       extensionMethod_structureDeclaration_enterInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_structureDeclaration_enterInContext (defineExtensionMethod_structureDeclaration_enterInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension method '@structureDeclaration enterRoutinesInContext'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_structureDeclaration_enterRoutinesInContext (const cPtr_abstractDeclaration * inObject,
                                                                         const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                                         GALGAS_semanticContext & ioArgument_ioContext,
                                                                         GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structureDeclaration * object = (const cPtr_structureDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_structureDeclaration) ;
  extensionMethod_enterInContext (object->mAttribute_mProcedureDeclarationListAST, GALGAS_string ("$").add_operation (object->mAttribute_mStructureName.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 339)), ioArgument_ioContext, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 339)) ;
  extensionMethod_enterInContext (object->mAttribute_mServiceListAST, GALGAS_string ("$").add_operation (object->mAttribute_mStructureName.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 340)), ioArgument_ioContext, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 340)) ;
  extensionMethod_enterInContext (object->mAttribute_mPrimitiveListAST, GALGAS_string ("$").add_operation (object->mAttribute_mStructureName.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 341)), ioArgument_ioContext, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 341)) ;
  extensionMethod_enterInContext (object->mAttribute_mGuardListAST, GALGAS_string ("$").add_operation (object->mAttribute_mStructureName.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 342)), ioArgument_ioContext, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 342)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_structureDeclaration_enterRoutinesInContext (void) {
  enterExtensionMethod_enterRoutinesInContext (kTypeDescriptor_GALGAS_structureDeclaration.mSlotID,
                                               extensionMethod_structureDeclaration_enterRoutinesInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_structureDeclaration_enterRoutinesInContext (defineExtensionMethod_structureDeclaration_enterRoutinesInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@structureDeclaration semanticAnalysis'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_structureDeclaration_semanticAnalysis (const cPtr_abstractDeclaration * inObject,
                                                                   const GALGAS_semanticContext constinArgument_inContext,
                                                                   GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                   GALGAS_intermediateCodeStruct & ioArgument_ioIntermediateCodeStruct,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structureDeclaration * object = (const cPtr_structureDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_structureDeclaration) ;
  GALGAS_unifiedTypeMap_2D_proxy var_structureType = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (constinArgument_inContext.mAttribute_mTypeMap, object->mAttribute_mStructureName, inCompiler  COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 354)) ;
  GALGAS_propertyMap var_propertyMap ;
  switch (var_structureType.getter_kind (inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 356)).enumValue ()) {
  case GALGAS_typeKind::kNotBuilt:
    break ;
  case GALGAS_typeKind::kEnum_structure:
    {
      const cEnumAssociatedValues_typeKind_structure * extractPtr_14236 = (const cEnumAssociatedValues_typeKind_structure *) (var_structureType.getter_kind (inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 356)).unsafePointer ()) ;
      const GALGAS_propertyMap extractedValue_propMap = extractPtr_14236->mAssociatedValue0 ;
      var_propertyMap = extractedValue_propMap ;
    }
    break ;
  case GALGAS_typeKind::kEnum_enumeration:
    {
      var_propertyMap = GALGAS_propertyMap::constructor_emptyMap (SOURCE_FILE ("type-structure-declaration.galgas", 358)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_integer:
    {
      var_propertyMap = GALGAS_propertyMap::constructor_emptyMap (SOURCE_FILE ("type-structure-declaration.galgas", 359)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_staticInteger:
    {
      var_propertyMap = GALGAS_propertyMap::constructor_emptyMap (SOURCE_FILE ("type-structure-declaration.galgas", 360)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_boolean:
    {
      var_propertyMap = GALGAS_propertyMap::constructor_emptyMap (SOURCE_FILE ("type-structure-declaration.galgas", 361)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_boolset:
    {
      var_propertyMap = GALGAS_propertyMap::constructor_emptyMap (SOURCE_FILE ("type-structure-declaration.galgas", 362)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_literalString:
    {
      var_propertyMap = GALGAS_propertyMap::constructor_emptyMap (SOURCE_FILE ("type-structure-declaration.galgas", 363)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_opaque:
    {
      var_propertyMap = GALGAS_propertyMap::constructor_emptyMap (SOURCE_FILE ("type-structure-declaration.galgas", 364)) ;
    }
    break ;
  case GALGAS_typeKind::kEnum_arrayType:
    {
      var_propertyMap = GALGAS_propertyMap::constructor_emptyMap (SOURCE_FILE ("type-structure-declaration.galgas", 365)) ;
    }
    break ;
  }
  const GALGAS_structureDeclaration temp_0 = object ;
  callExtensionMethod_procedureSemanticAnalysis ((const cPtr_structureDeclaration *) temp_0.ptr (), var_structureType, constinArgument_inContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 368)) ;
  extensionMethod_serviceSemanticAnalysis (object->mAttribute_mServiceListAST, var_structureType, constinArgument_inContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 375)) ;
  extensionMethod_sectionSemanticAnalysis (object->mAttribute_mSectionListAST, var_structureType, constinArgument_inContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 382)) ;
  extensionMethod_primitiveSemanticAnalysis (object->mAttribute_mPrimitiveListAST, var_structureType, constinArgument_inContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 389)) ;
  extensionMethod_guardSemanticAnalysis (object->mAttribute_mGuardListAST, var_structureType, constinArgument_inContext, ioArgument_ioTemporaries, ioArgument_ioIntermediateCodeStruct, inCompiler COMMA_SOURCE_FILE ("type-structure-declaration.galgas", 396)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_structureDeclaration_semanticAnalysis (void) {
  enterExtensionMethod_semanticAnalysis (kTypeDescriptor_GALGAS_structureDeclaration.mSlotID,
                                         extensionMethod_structureDeclaration_semanticAnalysis) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_structureDeclaration_semanticAnalysis (defineExtensionMethod_structureDeclaration_semanticAnalysis, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Overriding extension getter '@typeAliasDeclaration location'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_location extensionGetter_typeAliasDeclaration_location (const cPtr_abstractDeclaration * inObject,
                                                                      C_Compiler * /* inCompiler */
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_outLocation ; // Returned variable
  const cPtr_typeAliasDeclaration * object = (const cPtr_typeAliasDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_typeAliasDeclaration) ;
  result_outLocation = object->mAttribute_mNewTypeName.mAttribute_location ;
//---
  return result_outLocation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_typeAliasDeclaration_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_typeAliasDeclaration.mSlotID,
                                 extensionGetter_typeAliasDeclaration_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_typeAliasDeclaration_location (defineExtensionGetter_typeAliasDeclaration_location, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@typeAliasDeclaration addExtension'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_typeAliasDeclaration_addExtension (const cPtr_abstractDeclaration * inObject,
                                                               GALGAS_extensionDeclarationListAST & /* ioArgument_ioExtensionDeclarationListAST */,
                                                               GALGAS_abstractDeclaration & outArgument_outNewDeclaration,
                                                               C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_typeAliasDeclaration * object = (const cPtr_typeAliasDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_typeAliasDeclaration) ;
  const GALGAS_typeAliasDeclaration temp_0 = object ;
  outArgument_outNewDeclaration = temp_0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_typeAliasDeclaration_addExtension (void) {
  enterExtensionMethod_addExtension (kTypeDescriptor_GALGAS_typeAliasDeclaration.mSlotID,
                                     extensionMethod_typeAliasDeclaration_addExtension) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_typeAliasDeclaration_addExtension (defineExtensionMethod_typeAliasDeclaration_addExtension, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension method '@typeAliasDeclaration enterInPrecedenceGraph'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_typeAliasDeclaration_enterInPrecedenceGraph (const cPtr_abstractDeclaration * inObject,
                                                                         GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_typeAliasDeclaration * object = (const cPtr_typeAliasDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_typeAliasDeclaration) ;
  GALGAS_lstring var_newTypeName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (object->mAttribute_mNewTypeName.getter_string (SOURCE_FILE ("type-alias.galgas", 57)), inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 57)), object->mAttribute_mNewTypeName.mAttribute_location  COMMA_SOURCE_FILE ("type-alias.galgas", 57)) ;
  GALGAS_lstring var_aliasedTypeName = GALGAS_lstring::constructor_new (GALGAS_string ("$").add_operation (object->mAttribute_mAliasedTypeName.getter_string (SOURCE_FILE ("type-alias.galgas", 58)), inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 58)), object->mAttribute_mAliasedTypeName.mAttribute_location  COMMA_SOURCE_FILE ("type-alias.galgas", 58)) ;
  {
  const GALGAS_typeAliasDeclaration temp_0 = object ;
  ioArgument_ioGraph.setter_addNode (var_newTypeName, temp_0, inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 59)) ;
  }
  {
  ioArgument_ioGraph.setter_addEdge (var_newTypeName, var_aliasedTypeName COMMA_SOURCE_FILE ("type-alias.galgas", 60)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_typeAliasDeclaration_enterInPrecedenceGraph (void) {
  enterExtensionMethod_enterInPrecedenceGraph (kTypeDescriptor_GALGAS_typeAliasDeclaration.mSlotID,
                                               extensionMethod_typeAliasDeclaration_enterInPrecedenceGraph) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_typeAliasDeclaration_enterInPrecedenceGraph (defineExtensionMethod_typeAliasDeclaration_enterInPrecedenceGraph, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//               Overriding extension getter '@typeAliasDeclaration keyRepresentationForErrorSignaling'                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_typeAliasDeclaration_keyRepresentationForErrorSignaling (const cPtr_abstractDeclaration * inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outRepresentation ; // Returned variable
  const cPtr_typeAliasDeclaration * object = (const cPtr_typeAliasDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_typeAliasDeclaration) ;
  result_outRepresentation = GALGAS_string ("typealias $").add_operation (object->mAttribute_mNewTypeName.getter_string (SOURCE_FILE ("type-alias.galgas", 66)), inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 66)) ;
//---
  return result_outRepresentation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_typeAliasDeclaration_keyRepresentationForErrorSignaling (void) {
  enterExtensionGetter_keyRepresentationForErrorSignaling (kTypeDescriptor_GALGAS_typeAliasDeclaration.mSlotID,
                                                           extensionGetter_typeAliasDeclaration_keyRepresentationForErrorSignaling) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_typeAliasDeclaration_keyRepresentationForErrorSignaling (defineExtensionGetter_typeAliasDeclaration_keyRepresentationForErrorSignaling, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Overriding extension method '@typeAliasDeclaration enterRoutinesInContext'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_typeAliasDeclaration_enterRoutinesInContext (const cPtr_abstractDeclaration * /* inObject */,
                                                                         const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                                         GALGAS_semanticContext & /* ioArgument_ioContext */,
                                                                         GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                                         C_Compiler * /* inCompiler */
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_typeAliasDeclaration_enterRoutinesInContext (void) {
  enterExtensionMethod_enterRoutinesInContext (kTypeDescriptor_GALGAS_typeAliasDeclaration.mSlotID,
                                               extensionMethod_typeAliasDeclaration_enterRoutinesInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_typeAliasDeclaration_enterRoutinesInContext (defineExtensionMethod_typeAliasDeclaration_enterRoutinesInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@typeAliasDeclaration enterInContext'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_typeAliasDeclaration_enterInContext (const cPtr_abstractDeclaration * inObject,
                                                                 const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                                 GALGAS_semanticContext & ioArgument_ioContext,
                                                                 GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_typeAliasDeclaration * object = (const cPtr_typeAliasDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_typeAliasDeclaration) ;
  GALGAS_string var_llvmTypeMane ;
  GALGAS_typeKind var_kind ;
  GALGAS_classMethodMap var_typedConstantMap ;
  GALGAS_bool var_instanciable ;
  GALGAS_bool var_copyable ;
  GALGAS_bool var_equatable ;
  GALGAS_bool var_comparable ;
  GALGAS_unifiedTypeMap_2D_proxy var_enumerationType ;
  ioArgument_ioContext.mAttribute_mTypeMap.method_searchKey (object->mAttribute_mAliasedTypeName, var_llvmTypeMane, var_kind, var_typedConstantMap, var_instanciable, var_copyable, var_equatable, var_comparable, var_enumerationType, inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 88)) ;
  {
  ioArgument_ioContext.mAttribute_mTypeMap.setter_insertKey (object->mAttribute_mNewTypeName, var_llvmTypeMane, var_kind, var_typedConstantMap, var_instanciable, var_copyable, var_equatable, var_comparable, var_enumerationType, inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 100)) ;
  }
  GALGAS_lstring var_newNewInfixKey = function_combineTypeNamesForInfixOperator (object->mAttribute_mNewTypeName.mAttribute_string, object->mAttribute_mNewTypeName.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 112)) ;
  GALGAS_lstring var_aliasAliasInfixKey = function_combineTypeNamesForInfixOperator (object->mAttribute_mAliasedTypeName.mAttribute_string, object->mAttribute_mAliasedTypeName.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 113)) ;
  GALGAS_lstring var_newLiteralIntegerInfixKey = function_combineTypeNamesForInfixOperator (object->mAttribute_mNewTypeName.mAttribute_string, function_staticIntegerTypeName (inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 114)), inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 114)) ;
  GALGAS_lstring var_aliasLiteralIntegerInfixKey = function_combineTypeNamesForInfixOperator (object->mAttribute_mAliasedTypeName.mAttribute_string, function_staticIntegerTypeName (inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 115)), inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 115)) ;
  GALGAS_lstring var_literalIntegerNewInfixKey = function_combineTypeNamesForInfixOperator (function_staticIntegerTypeName (inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 116)), object->mAttribute_mNewTypeName.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 116)) ;
  GALGAS_lstring var_literalIntegerAliasInfixKey = function_combineTypeNamesForInfixOperator (function_staticIntegerTypeName (inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 117)), object->mAttribute_mAliasedTypeName.mAttribute_string, inCompiler COMMA_SOURCE_FILE ("type-alias.galgas", 117)) ;
  GALGAS_unifiedTypeMap_2D_proxy var_newTypeProxy = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, object->mAttribute_mNewTypeName, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 118)) ;
  GALGAS_unifiedTypeMap_2D_proxy var_oldTypeProxy = GALGAS_unifiedTypeMap_2D_proxy::constructor_searchKey (ioArgument_ioContext.mAttribute_mTypeMap, object->mAttribute_mAliasedTypeName, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 119)) ;
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mEqualOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 120)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mNonEqualOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 131)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mStrictInfOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 142)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mInfEqualOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 153)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mStrictSupOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 164)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mSupEqualOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 175)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mAndOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 186)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mOrOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 197)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mXorOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 208)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mBooleanXorOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 219)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mAddOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 230)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mAddNoOvfOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 241)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mSubOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 252)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mSubNoOvfOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 263)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mMulOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 274)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mMulNoOvfOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 285)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mDivOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 296)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mDivNoOvfOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 307)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mModOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 318)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mModNoOvfOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 329)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mLeftShiftOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 340)) ;
  }
  {
  routine_enterAliasInfixOperator (ioArgument_ioContext.mAttribute_mRightShiftOperatorMap, var_newNewInfixKey, var_aliasAliasInfixKey, var_newLiteralIntegerInfixKey, var_aliasLiteralIntegerInfixKey, var_literalIntegerNewInfixKey, var_literalIntegerAliasInfixKey, var_newTypeProxy, var_oldTypeProxy, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 351)) ;
  }
  {
  routine_enterAliasPrefixOperator (ioArgument_ioContext.mAttribute_mUnaryMinusOperatorMap, object->mAttribute_mNewTypeName, object->mAttribute_mAliasedTypeName, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 362)) ;
  }
  {
  routine_enterAliasPrefixOperator (ioArgument_ioContext.mAttribute_mNotOperatorMap, object->mAttribute_mNewTypeName, object->mAttribute_mAliasedTypeName, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 363)) ;
  }
  {
  routine_enterAliasPrefixOperator (ioArgument_ioContext.mAttribute_mUnsignedComplementOperatorMap, object->mAttribute_mNewTypeName, object->mAttribute_mAliasedTypeName, inCompiler  COMMA_SOURCE_FILE ("type-alias.galgas", 364)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_typeAliasDeclaration_enterInContext (void) {
  enterExtensionMethod_enterInContext (kTypeDescriptor_GALGAS_typeAliasDeclaration.mSlotID,
                                       extensionMethod_typeAliasDeclaration_enterInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_typeAliasDeclaration_enterInContext (defineExtensionMethod_typeAliasDeclaration_enterInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Overriding extension method '@typeAliasDeclaration semanticAnalysis'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_typeAliasDeclaration_semanticAnalysis (const cPtr_abstractDeclaration * /* inObject */,
                                                                   const GALGAS_semanticContext /* constinArgument_inContext */,
                                                                   GALGAS_semanticTemporariesStruct & /* ioArgument_ioTemporaries */,
                                                                   GALGAS_intermediateCodeStruct & /* ioArgument_ioIntermediateCodeStruct */,
                                                                   C_Compiler * /* inCompiler */
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_typeAliasDeclaration_semanticAnalysis (void) {
  enterExtensionMethod_semanticAnalysis (kTypeDescriptor_GALGAS_typeAliasDeclaration.mSlotID,
                                         extensionMethod_typeAliasDeclaration_semanticAnalysis) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_typeAliasDeclaration_semanticAnalysis (defineExtensionMethod_typeAliasDeclaration_semanticAnalysis, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Overriding extension getter '@integerDeclaration location'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_location extensionGetter_integerDeclaration_location (const cPtr_abstractDeclaration * /* inObject */,
                                                                    C_Compiler * /* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_outLocation ; // Returned variable
  result_outLocation = GALGAS_location::constructor_nowhere (SOURCE_FILE ("type-integer.galgas", 13)) ;
//---
  return result_outLocation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_integerDeclaration_location (void) {
  enterExtensionGetter_location (kTypeDescriptor_GALGAS_integerDeclaration.mSlotID,
                                 extensionGetter_integerDeclaration_location) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_integerDeclaration_location (defineExtensionGetter_integerDeclaration_location, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Overriding extension method '@integerDeclaration addExtension'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_integerDeclaration_addExtension (const cPtr_abstractDeclaration * inObject,
                                                             GALGAS_extensionDeclarationListAST & /* ioArgument_ioExtensionDeclarationListAST */,
                                                             GALGAS_abstractDeclaration & outArgument_outNewDeclaration,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_integerDeclaration * object = (const cPtr_integerDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_integerDeclaration) ;
  const GALGAS_integerDeclaration temp_0 = object ;
  outArgument_outNewDeclaration = temp_0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_integerDeclaration_addExtension (void) {
  enterExtensionMethod_addExtension (kTypeDescriptor_GALGAS_integerDeclaration.mSlotID,
                                     extensionMethod_integerDeclaration_addExtension) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_integerDeclaration_addExtension (defineExtensionMethod_integerDeclaration_addExtension, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Overriding extension method '@integerDeclaration enterInPrecedenceGraph'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_integerDeclaration_enterInPrecedenceGraph (const cPtr_abstractDeclaration * inObject,
                                                                       GALGAS_semanticTypePrecedenceGraph & ioArgument_ioGraph,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_integerDeclaration * object = (const cPtr_integerDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_integerDeclaration) ;
  const GALGAS_integerDeclaration temp_0 = object ;
  GALGAS_lstring var_integerTypeName = GALGAS_string ("$").add_operation (callExtensionGetter_typeName ((const cPtr_integerDeclaration *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 40)), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 40)).getter_nowhere (SOURCE_FILE ("type-integer.galgas", 40)) ;
  {
  const GALGAS_integerDeclaration temp_1 = object ;
  ioArgument_ioGraph.setter_addNode (var_integerTypeName, temp_1, inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 41)) ;
  }
  {
  ioArgument_ioGraph.setter_addEdge (var_integerTypeName, GALGAS_string ("$").add_operation (function_staticIntegerTypeName (inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 42)), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 42)).getter_nowhere (SOURCE_FILE ("type-integer.galgas", 42)) COMMA_SOURCE_FILE ("type-integer.galgas", 42)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_integerDeclaration_enterInPrecedenceGraph (void) {
  enterExtensionMethod_enterInPrecedenceGraph (kTypeDescriptor_GALGAS_integerDeclaration.mSlotID,
                                               extensionMethod_integerDeclaration_enterInPrecedenceGraph) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_integerDeclaration_enterInPrecedenceGraph (defineExtensionMethod_integerDeclaration_enterInPrecedenceGraph, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                Overriding extension getter '@integerDeclaration keyRepresentationForErrorSignaling'                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_integerDeclaration_keyRepresentationForErrorSignaling (const cPtr_abstractDeclaration * inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outRepresentation ; // Returned variable
  const cPtr_integerDeclaration * object = (const cPtr_integerDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_integerDeclaration) ;
  const GALGAS_integerDeclaration temp_0 = object ;
  result_outRepresentation = GALGAS_string ("integer $").add_operation (callExtensionGetter_typeName ((const cPtr_integerDeclaration *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 48)), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 48)) ;
//---
  return result_outRepresentation ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_integerDeclaration_keyRepresentationForErrorSignaling (void) {
  enterExtensionGetter_keyRepresentationForErrorSignaling (kTypeDescriptor_GALGAS_integerDeclaration.mSlotID,
                                                           extensionGetter_integerDeclaration_keyRepresentationForErrorSignaling) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_integerDeclaration_keyRepresentationForErrorSignaling (defineExtensionGetter_integerDeclaration_keyRepresentationForErrorSignaling, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Overriding extension method '@integerDeclaration enterInContext'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_integerDeclaration_enterInContext (const cPtr_abstractDeclaration * inObject,
                                                               const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                               GALGAS_semanticContext & ioArgument_ioContext,
                                                               GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_integerDeclaration * object = (const cPtr_integerDeclaration *) inObject ;
  macroValidSharedObject (object, cPtr_integerDeclaration) ;
  const GALGAS_integerDeclaration temp_0 = object ;
  GALGAS_lstring var_integerTypeName = callExtensionGetter_typeName ((const cPtr_integerDeclaration *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 60)).getter_nowhere (SOURCE_FILE ("type-integer.galgas", 60)) ;
  GALGAS_bigint var_min ;
  GALGAS_bigint var_max ;
  const enumGalgasBool test_1 = object->mAttribute_mIsSigned.boolEnum () ;
  if (kBoolTrue == test_1) {
    var_min = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("type-integer.galgas", 65)).left_shift_operation (object->mAttribute_mSize.substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 65)) COMMA_SOURCE_FILE ("type-integer.galgas", 65)).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 65)) ;
    var_max = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("type-integer.galgas", 66)).left_shift_operation (object->mAttribute_mSize.substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 66)) COMMA_SOURCE_FILE ("type-integer.galgas", 66)).substract_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("type-integer.galgas", 66)), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 66)) ;
  }else if (kBoolFalse == test_1) {
    var_min = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("type-integer.galgas", 68)) ;
    var_max = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("type-integer.galgas", 69)).left_shift_operation (object->mAttribute_mSize COMMA_SOURCE_FILE ("type-integer.galgas", 69)).substract_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("type-integer.galgas", 69)), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 69)) ;
  }
  {
  ioArgument_ioContext.mAttribute_mTypeMap.setter_insertKey (var_integerTypeName, GALGAS_string ("i").add_operation (object->mAttribute_mSize.getter_string (SOURCE_FILE ("type-integer.galgas", 74)), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 74)), GALGAS_typeKind::constructor_integer (var_min, var_max, object->mAttribute_mIsSigned.operator_not (SOURCE_FILE ("type-integer.galgas", 75)), object->mAttribute_mSize  COMMA_SOURCE_FILE ("type-integer.galgas", 75)), GALGAS_classMethodMap::constructor_emptyMap (SOURCE_FILE ("type-integer.galgas", 76)), GALGAS_bool (true), GALGAS_bool (true), GALGAS_bool (true), GALGAS_bool (true), GALGAS_unifiedTypeMap_2D_proxy::constructor_null (SOURCE_FILE ("type-integer.galgas", 81)), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 72)) ;
  }
  {
  routine_enter_5F_integer_5F_integer_5F_operators (var_integerTypeName, object->mAttribute_mIsSigned, ioArgument_ioContext, inCompiler  COMMA_SOURCE_FILE ("type-integer.galgas", 84)) ;
  }
  {
  routine_enter_5F_integer_5F_literal_5F_operators (var_integerTypeName, object->mAttribute_mIsSigned, ioArgument_ioContext, inCompiler  COMMA_SOURCE_FILE ("type-integer.galgas", 90)) ;
  }
  {
  routine_enter_5F_literal_5F_integer_5F_operators (var_integerTypeName, object->mAttribute_mIsSigned, ioArgument_ioContext, inCompiler  COMMA_SOURCE_FILE ("type-integer.galgas", 96)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_integerDeclaration_enterInContext (void) {
  enterExtensionMethod_enterInContext (kTypeDescriptor_GALGAS_integerDeclaration.mSlotID,
                                       extensionMethod_integerDeclaration_enterInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_integerDeclaration_enterInContext (defineExtensionMethod_integerDeclaration_enterInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Overriding extension method '@integerDeclaration enterRoutinesInContext'                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_integerDeclaration_enterRoutinesInContext (const cPtr_abstractDeclaration * /* inObject */,
                                                                       const GALGAS_procedureDeclarationListAST /* constinArgument_inProcedureListAST */,
                                                                       GALGAS_semanticContext & /* ioArgument_ioContext */,
                                                                       GALGAS_staticStringMap & /* ioArgument_ioGlobalLiteralStringMap */,
                                                                       C_Compiler * /* inCompiler */
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_integerDeclaration_enterRoutinesInContext (void) {
  enterExtensionMethod_enterRoutinesInContext (kTypeDescriptor_GALGAS_integerDeclaration.mSlotID,
                                               extensionMethod_integerDeclaration_enterRoutinesInContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_integerDeclaration_enterRoutinesInContext (defineExtensionMethod_integerDeclaration_enterRoutinesInContext, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Overriding extension method '@integerDeclaration semanticAnalysis'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_integerDeclaration_semanticAnalysis (const cPtr_abstractDeclaration * /* inObject */,
                                                                 const GALGAS_semanticContext /* constinArgument_inContext */,
                                                                 GALGAS_semanticTemporariesStruct & /* ioArgument_ioTemporaries */,
                                                                 GALGAS_intermediateCodeStruct & /* ioArgument_ioIntermediateCodeStruct */,
                                                                 C_Compiler * /* inCompiler */
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_integerDeclaration_semanticAnalysis (void) {
  enterExtensionMethod_semanticAnalysis (kTypeDescriptor_GALGAS_integerDeclaration.mSlotID,
                                         extensionMethod_integerDeclaration_semanticAnalysis) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_integerDeclaration_semanticAnalysis (defineExtensionMethod_integerDeclaration_semanticAnalysis, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//            Overriding extension method '@infixObjectObjectOperatorDescription generateInfixOperatorCode'            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_infixObjectObjectOperatorDescription_generateInfixOperatorCode (const cPtr_infixOperatorDescription * inObject,
                                                                                            GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                                            GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                                            const GALGAS_operandIR constinArgument_inLeftOperand,
                                                                                            const GALGAS_location constinArgument_inOperatorLocation,
                                                                                            const GALGAS_operandIR constinArgument_inRightOperand,
                                                                                            const GALGAS_unifiedTypeMap_2D_proxy constinArgument_inResultType,
                                                                                            GALGAS_operandIR & outArgument_outResult,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_infixObjectObjectOperatorDescription * object = (const cPtr_infixObjectObjectOperatorDescription *) inObject ;
  macroValidSharedObject (object, cPtr_infixObjectObjectOperatorDescription) ;
  GALGAS_bool test_0 = constinArgument_inLeftOperand.mAttribute_mValue.getter_isLiteralInteger (SOURCE_FILE ("type-integer.galgas", 276)) ;
  if (kBoolTrue == test_0.boolEnum ()) {
    test_0 = constinArgument_inRightOperand.mAttribute_mValue.getter_isLiteralInteger (SOURCE_FILE ("type-integer.galgas", 276)) ;
  }
  const enumGalgasBool test_1 = test_0.boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_bigint var_left ;
    constinArgument_inLeftOperand.mAttribute_mValue.method_literalInteger (var_left, inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 277)) ;
    GALGAS_bigint var_right ;
    constinArgument_inRightOperand.mAttribute_mValue.method_literalInteger (var_right, inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 278)) ;
    const GALGAS_infixObjectObjectOperatorDescription temp_2 = object ;
    GALGAS_bigint var_resultValue = callExtensionGetter_performStaticOperation ((const cPtr_infixObjectObjectOperatorDescription *) temp_2.ptr (), var_left, var_right, inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 279)) ;
    outArgument_outResult = GALGAS_operandIR::constructor_new (constinArgument_inResultType, GALGAS_valueIR::constructor_literalInteger (var_resultValue  COMMA_SOURCE_FILE ("type-integer.galgas", 280))  COMMA_SOURCE_FILE ("type-integer.galgas", 280)) ;
  }else if (kBoolFalse == test_1) {
    {
    routine_getNewTempVariable (constinArgument_inResultType, ioArgument_ioTemporaries, outArgument_outResult, inCompiler  COMMA_SOURCE_FILE ("type-integer.galgas", 282)) ;
    }
    {
    extensionSetter_appendBinaryOperation (ioArgument_ioInstructionGenerationList, outArgument_outResult.mAttribute_mValue, constinArgument_inLeftOperand.mAttribute_mType, constinArgument_inOperatorLocation, constinArgument_inLeftOperand.mAttribute_mValue, object->mAttribute_mOperator, constinArgument_inRightOperand.mAttribute_mValue, inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 284)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_infixObjectObjectOperatorDescription_generateInfixOperatorCode (void) {
  enterExtensionMethod_generateInfixOperatorCode (kTypeDescriptor_GALGAS_infixObjectObjectOperatorDescription.mSlotID,
                                                  extensionMethod_infixObjectObjectOperatorDescription_generateInfixOperatorCode) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_infixObjectObjectOperatorDescription_generateInfixOperatorCode (defineExtensionMethod_infixObjectObjectOperatorDescription_generateInfixOperatorCode, NULL) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//            Overriding extension method '@integerObject_literal_infixOperator generateInfixOperatorCode'             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_integerObject_5F_literal_5F_infixOperator_generateInfixOperatorCode (const cPtr_infixOperatorDescription * inObject,
                                                                                                 GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                                                                 GALGAS_instructionListIR & ioArgument_ioInstructionGenerationList,
                                                                                                 const GALGAS_operandIR constinArgument_inLeftOperand,
                                                                                                 const GALGAS_location constinArgument_inOperatorLocation,
                                                                                                 const GALGAS_operandIR constinArgument_inRightOperand,
                                                                                                 const GALGAS_unifiedTypeMap_2D_proxy constinArgument_inResultType,
                                                                                                 GALGAS_operandIR & outArgument_outResult,
                                                                                                 C_Compiler * inCompiler
                                                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_integerObject_5F_literal_5F_infixOperator * object = (const cPtr_integerObject_5F_literal_5F_infixOperator *) inObject ;
  macroValidSharedObject (object, cPtr_integerObject_5F_literal_5F_infixOperator) ;
  GALGAS_bigint var_literalValue ;
  constinArgument_inRightOperand.mAttribute_mValue.method_literalInteger (var_literalValue, inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 439)) ;
  GALGAS_bigint var_min ;
  GALGAS_bigint var_max ;
  GALGAS_bool joker_16742 ; // Joker input parameter
  GALGAS_uint joker_16754 ; // Joker input parameter
  constinArgument_inLeftOperand.mAttribute_mType.getter_kind (inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 440)).method_integer (var_min, var_max, joker_16742, joker_16754, inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 440)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, var_literalValue.objectCompare (var_min)).boolEnum () ;
  if (kBoolTrue == test_0) {
    inCompiler->emitSemanticError (constinArgument_inOperatorLocation, GALGAS_string ("literal right integer expression too small (should be >= ").add_operation (var_min.getter_string (SOURCE_FILE ("type-integer.galgas", 442)), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 442)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 442))  COMMA_SOURCE_FILE ("type-integer.galgas", 442)) ;
    outArgument_outResult.drop () ; // Release error dropped variable
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, var_literalValue.objectCompare (var_max)).boolEnum () ;
    if (kBoolTrue == test_1) {
      inCompiler->emitSemanticError (constinArgument_inOperatorLocation, GALGAS_string ("literal right integer expression too large (should be <= ").add_operation (var_max.getter_string (SOURCE_FILE ("type-integer.galgas", 444)), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 444)).add_operation (GALGAS_string (")"), inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 444))  COMMA_SOURCE_FILE ("type-integer.galgas", 444)) ;
      outArgument_outResult.drop () ; // Release error dropped variable
    }else if (kBoolFalse == test_1) {
      {
      routine_getNewTempVariable (constinArgument_inResultType, ioArgument_ioTemporaries, outArgument_outResult, inCompiler  COMMA_SOURCE_FILE ("type-integer.galgas", 446)) ;
      }
      {
      extensionSetter_appendBinaryOperation (ioArgument_ioInstructionGenerationList, outArgument_outResult.mAttribute_mValue, constinArgument_inLeftOperand.mAttribute_mType, constinArgument_inOperatorLocation, constinArgument_inLeftOperand.mAttribute_mValue, object->mAttribute_mOperator, constinArgument_inRightOperand.mAttribute_mValue, inCompiler COMMA_SOURCE_FILE ("type-integer.galgas", 447)) ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_integerObject_5F_literal_5F_infixOperator_generateInfixOperatorCode (void) {
  enterExtensionMethod_generateInfixOperatorCode (kTypeDescriptor_GALGAS_integerObject_5F_literal_5F_infixOperator.mSlotID,
                                                  extensionMethod_integerObject_5F_literal_5F_infixOperator_generateInfixOperatorCode) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_integerObject_5F_literal_5F_infixOperator_generateInfixOperatorCode (defineExtensionMethod_integerObject_5F_literal_5F_infixOperator_generateInfixOperatorCode, NULL) ;

