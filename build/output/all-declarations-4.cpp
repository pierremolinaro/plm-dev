#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-4.h"


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_scopeKind::GALGAS_scopeKind (void) :
mEnum (kNotBuilt) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_scopeKind GALGAS_scopeKind::constructor_selectScope (UNUSED_LOCATION_ARGS) {
  GALGAS_scopeKind result ;
  result.mEnum = kEnum_selectScope ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_scopeKind GALGAS_scopeKind::constructor_repeatScope (UNUSED_LOCATION_ARGS) {
  GALGAS_scopeKind result ;
  result.mEnum = kEnum_repeatScope ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * gEnumNameArrayFor_scopeKind [3] = {
  "(not built)",
  "selectScope",
  "repeatScope"
} ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_scopeKind::getter_isSelectScope (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_selectScope == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_scopeKind::getter_isRepeatScope (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_repeatScope == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_scopeKind::description (C_String & ioString,
                                    const int32_t /* inIndentation */) const {
  ioString << "<enum @scopeKind: " << gEnumNameArrayFor_scopeKind [mEnum] ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_scopeKind::objectCompare (const GALGAS_scopeKind & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @scopeKind type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_scopeKind ("scopeKind",
                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_scopeKind::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_scopeKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_scopeKind::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_scopeKind (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_scopeKind GALGAS_scopeKind::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_scopeKind result ;
  const GALGAS_scopeKind * p = (const GALGAS_scopeKind *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_scopeKind *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("scopeKind", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_referenceStateMap::cMapElement_referenceStateMap (const GALGAS_lstring & inKey,
                                                              const GALGAS_valuedObjectState & in_mState
                                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mState (in_mState) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_referenceStateMap::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mState.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_referenceStateMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_referenceStateMap (mProperty_lkey, mProperty_mState COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_referenceStateMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mState" ":" ;
  mProperty_mState.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_referenceStateMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_referenceStateMap * operand = (cMapElement_referenceStateMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mState.objectCompare (operand->mProperty_mState) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_referenceStateMap::GALGAS_referenceStateMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_referenceStateMap::GALGAS_referenceStateMap (const GALGAS_referenceStateMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_referenceStateMap & GALGAS_referenceStateMap::operator = (const GALGAS_referenceStateMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_referenceStateMap GALGAS_referenceStateMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_referenceStateMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_referenceStateMap GALGAS_referenceStateMap::constructor_mapWithMapToOverride (const GALGAS_referenceStateMap & inMapToOverride
                                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_referenceStateMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_referenceStateMap GALGAS_referenceStateMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_referenceStateMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_referenceStateMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                    const GALGAS_valuedObjectState & inArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_referenceStateMap * p = NULL ;
  macroMyNew (p, cMapElement_referenceStateMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@referenceStateMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_referenceStateMap::setter_insertKey (GALGAS_lstring inKey,
                                                 GALGAS_valuedObjectState inArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_referenceStateMap * p = NULL ;
  macroMyNew (p, cMapElement_referenceStateMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "INTERNAL ERROR" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_referenceStateMap_searchKey = "INTERNAL ERROR" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_referenceStateMap::method_searchKey (GALGAS_lstring inKey,
                                                 GALGAS_valuedObjectState & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  const cMapElement_referenceStateMap * p = (const cMapElement_referenceStateMap *) performSearch (inKey,
                                                                                                   inCompiler,
                                                                                                   kSearchErrorMessage_referenceStateMap_searchKey
                                                                                                   COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_referenceStateMap) ;
    outArgument0 = p->mProperty_mState ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_valuedObjectState GALGAS_referenceStateMap::getter_mStateForKey (const GALGAS_string & inKey,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_referenceStateMap * p = (const cMapElement_referenceStateMap *) attributes ;
  GALGAS_valuedObjectState result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_referenceStateMap) ;
    result = p->mProperty_mState ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_referenceStateMap::setter_setMStateForKey (GALGAS_valuedObjectState inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_referenceStateMap * p = (cMapElement_referenceStateMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_referenceStateMap) ;
    p->mProperty_mState = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_referenceStateMap * GALGAS_referenceStateMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                             const GALGAS_string & inKey
                                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_referenceStateMap * result = (cMapElement_referenceStateMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_referenceStateMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_referenceStateMap::cEnumerator_referenceStateMap (const GALGAS_referenceStateMap & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_referenceStateMap_2D_element cEnumerator_referenceStateMap::current (LOCATION_ARGS) const {
  const cMapElement_referenceStateMap * p = (const cMapElement_referenceStateMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_referenceStateMap) ;
  return GALGAS_referenceStateMap_2D_element (p->mProperty_lkey, p->mProperty_mState) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_referenceStateMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_valuedObjectState cEnumerator_referenceStateMap::current_mState (LOCATION_ARGS) const {
  const cMapElement_referenceStateMap * p = (const cMapElement_referenceStateMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_referenceStateMap) ;
  return p->mProperty_mState ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @referenceStateMap type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_referenceStateMap ("referenceStateMap",
                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_referenceStateMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_referenceStateMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_referenceStateMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_referenceStateMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_referenceStateMap GALGAS_referenceStateMap::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_referenceStateMap result ;
  const GALGAS_referenceStateMap * p = (const GALGAS_referenceStateMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_referenceStateMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("referenceStateMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension Getter '@valuedObjectState string'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_string (const GALGAS_valuedObjectState & inObject,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_valuedObjectState temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_valuedObjectState::kNotBuilt:
    break ;
  case GALGAS_valuedObjectState::kEnum_noValue:
    {
      result_result = GALGAS_string ("no value") ;
    }
    break ;
  case GALGAS_valuedObjectState::kEnum_hasUnreadValue:
    {
      result_result = GALGAS_string ("unread value") ;
    }
    break ;
  case GALGAS_valuedObjectState::kEnum_hasReadValue:
    {
      result_result = GALGAS_string ("read value") ;
    }
    break ;
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        '@semanticTypePrecedenceGraph' graph                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_semanticTypePrecedenceGraph::GALGAS_semanticTypePrecedenceGraph (void) :
AC_GALGAS_graph () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_semanticTypePrecedenceGraph GALGAS_semanticTypePrecedenceGraph::constructor_emptyGraph (LOCATION_ARGS) {
  GALGAS_semanticTypePrecedenceGraph result ;
  result.makeNewEmptyGraph (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_semanticTypePrecedenceGraph::setter_addNode (GALGAS_lstring inKey,
                                                         GALGAS_abstractDeclarationAST inArgument_0,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  GALGAS_declarationListAST::makeAttributesFromObjects (attributes, inArgument_0 COMMA_THERE) ;
  const char * kErrorMessage = "the '%K' symbol is already declared at %L" ;
  internalAddNode (inKey, kErrorMessage, attributes, inCompiler COMMA_THERE) ;
}


//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_semanticTypePrecedenceGraph::method_topologicalSort (GALGAS_declarationListAST & outSortedList,
                                                                 GALGAS_lstringlist & outSortedKeyList,
                                                                 GALGAS_declarationListAST & outUnsortedList,
                                                                 GALGAS_lstringlist & outUnsortedKeyList,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElementArray sortedList ;
  capCollectionElementArray unsortedList ;
  internalTopologicalSort (sortedList, outSortedKeyList, unsortedList, outUnsortedKeyList, inCompiler COMMA_THERE) ;
  outSortedList = GALGAS_declarationListAST (sortedList) ;
  outUnsortedList = GALGAS_declarationListAST (unsortedList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_semanticTypePrecedenceGraph::method_depthFirstTopologicalSort (GALGAS_declarationListAST & outSortedList,
                                                                           GALGAS_lstringlist & outSortedKeyList,
                                                                           GALGAS_declarationListAST & outUnsortedList,
                                                                           GALGAS_lstringlist & outUnsortedKeyList,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElementArray sortedList ;
  capCollectionElementArray unsortedList ;
  internalDepthFirstTopologicalSort (sortedList, outSortedKeyList, unsortedList, outUnsortedKeyList, inCompiler COMMA_THERE) ;
  outSortedList = GALGAS_declarationListAST (sortedList) ;
  outUnsortedList = GALGAS_declarationListAST (unsortedList) ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_semanticTypePrecedenceGraph GALGAS_semanticTypePrecedenceGraph::getter_reversedGraph (LOCATION_ARGS) const {
  GALGAS_semanticTypePrecedenceGraph result ;
  result.reversedGraphFromGraph (*this COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_semanticTypePrecedenceGraph::method_circularities (GALGAS_declarationListAST & outInfoList,
                                                               GALGAS_lstringlist & outKeyList
                                                               COMMA_LOCATION_ARGS) const {
  capCollectionElementArray infoList ;
  internalFindCircularities (infoList, outKeyList COMMA_THERE) ;
  outInfoList = GALGAS_declarationListAST (infoList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_semanticTypePrecedenceGraph::method_nodesWithNoSuccessor (GALGAS_declarationListAST & outInfoList,
                                                                      GALGAS_lstringlist & outKeyList
                                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElementArray infoList ;
  internalNodesWithNoSuccessor (infoList, outKeyList COMMA_THERE) ;
  outInfoList = GALGAS_declarationListAST (infoList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_semanticTypePrecedenceGraph::method_nodesWithNoPredecessor (GALGAS_declarationListAST & outInfoList,
                                                                        GALGAS_lstringlist & outKeyList
                                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElementArray infoList ;
  internalNodesWithNoPredecessor (infoList, outKeyList COMMA_THERE) ;
  outInfoList = GALGAS_declarationListAST (infoList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_semanticTypePrecedenceGraph GALGAS_semanticTypePrecedenceGraph::getter_subgraphFromNodes (const GALGAS_lstringlist & inStartKeyList,
                                                                                                 const GALGAS_stringset & inKeysToExclude,
                                                                                                 C_Compiler * inCompiler
                                                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_semanticTypePrecedenceGraph result ;
  subGraph (result, inStartKeyList, inKeysToExclude, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_semanticTypePrecedenceGraph::getter_accessibleNodesFrom (const GALGAS_lstringlist & inStartKeyList,
                                                                                   const GALGAS_stringset & inNodesToExclude,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  GALGAS_semanticTypePrecedenceGraph resultingGraph ;
  subGraph (resultingGraph,
            inStartKeyList,
            inNodesToExclude,
            inCompiler
            COMMA_THERE) ;
  if (resultingGraph.isValid ()) {
    result = resultingGraph.getter_lkeyList (THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @semanticTypePrecedenceGraph type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_semanticTypePrecedenceGraph ("semanticTypePrecedenceGraph",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_semanticTypePrecedenceGraph::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_semanticTypePrecedenceGraph ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_semanticTypePrecedenceGraph::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_semanticTypePrecedenceGraph (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_semanticTypePrecedenceGraph GALGAS_semanticTypePrecedenceGraph::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_semanticTypePrecedenceGraph result ;
  const GALGAS_semanticTypePrecedenceGraph * p = (const GALGAS_semanticTypePrecedenceGraph *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_semanticTypePrecedenceGraph *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("semanticTypePrecedenceGraph", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Abstract extension method '@abstractDeclarationAST enterInPrecedenceGraph'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_abstractDeclarationAST_enterInPrecedenceGraph> gExtensionMethodTable_abstractDeclarationAST_enterInPrecedenceGraph ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_enterInPrecedenceGraph (const int32_t inClassIndex,
                                                  extensionMethodSignature_abstractDeclarationAST_enterInPrecedenceGraph inMethod) {
  gExtensionMethodTable_abstractDeclarationAST_enterInPrecedenceGraph.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_abstractDeclarationAST_enterInPrecedenceGraph (void) {
  gExtensionMethodTable_abstractDeclarationAST_enterInPrecedenceGraph.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_abstractDeclarationAST_enterInPrecedenceGraph (NULL,
                                                                          freeExtensionMethod_abstractDeclarationAST_enterInPrecedenceGraph) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_enterInPrecedenceGraph (const cPtr_abstractDeclarationAST * inObject,
                                                 GALGAS_semanticTypePrecedenceGraph & io_ioGraph,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_abstractDeclarationAST) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_abstractDeclarationAST_enterInPrecedenceGraph f = NULL ;
    if (classIndex < gExtensionMethodTable_abstractDeclarationAST_enterInPrecedenceGraph.count ()) {
      f = gExtensionMethodTable_abstractDeclarationAST_enterInPrecedenceGraph (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_abstractDeclarationAST_enterInPrecedenceGraph.count ()) {
          f = gExtensionMethodTable_abstractDeclarationAST_enterInPrecedenceGraph (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_abstractDeclarationAST_enterInPrecedenceGraph.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_ioGraph, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//               Abstract extension getter '@abstractDeclarationAST keyRepresentationForErrorSignaling'                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_abstractDeclarationAST_keyRepresentationForErrorSignaling> gExtensionGetterTable_abstractDeclarationAST_keyRepresentationForErrorSignaling ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_keyRepresentationForErrorSignaling (const int32_t inClassIndex,
                                                              enterExtensionGetter_abstractDeclarationAST_keyRepresentationForErrorSignaling inGetter) {
  gExtensionGetterTable_abstractDeclarationAST_keyRepresentationForErrorSignaling.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_abstractDeclarationAST_keyRepresentationForErrorSignaling (void) {
  gExtensionGetterTable_abstractDeclarationAST_keyRepresentationForErrorSignaling.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_abstractDeclarationAST_keyRepresentationForErrorSignaling (NULL,
                                                                                      freeExtensionGetter_abstractDeclarationAST_keyRepresentationForErrorSignaling) ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string callExtensionGetter_keyRepresentationForErrorSignaling (const cPtr_abstractDeclarationAST * inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_abstractDeclarationAST) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_abstractDeclarationAST_keyRepresentationForErrorSignaling f = NULL ;
    if (classIndex < gExtensionGetterTable_abstractDeclarationAST_keyRepresentationForErrorSignaling.count ()) {
      f = gExtensionGetterTable_abstractDeclarationAST_keyRepresentationForErrorSignaling (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_abstractDeclarationAST_keyRepresentationForErrorSignaling.count ()) {
           f = gExtensionGetterTable_abstractDeclarationAST_keyRepresentationForErrorSignaling (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_abstractDeclarationAST_keyRepresentationForErrorSignaling.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
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
//                               Class for element of '@declarationDecorationList' list                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_declarationDecorationList : public cCollectionElement {
  public : GALGAS_declarationDecorationList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_declarationDecorationList (const GALGAS_abstractDecoratedDeclaration & in_mDeclaration
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

cCollectionElement_declarationDecorationList::cCollectionElement_declarationDecorationList (const GALGAS_abstractDecoratedDeclaration & in_mDeclaration
                                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mDeclaration) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_declarationDecorationList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_declarationDecorationList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_declarationDecorationList (mObject.mProperty_mDeclaration COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_declarationDecorationList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mDeclaration" ":" ;
  mObject.mProperty_mDeclaration.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_declarationDecorationList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_declarationDecorationList * operand = (cCollectionElement_declarationDecorationList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_declarationDecorationList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationDecorationList::GALGAS_declarationDecorationList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationDecorationList::GALGAS_declarationDecorationList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationDecorationList GALGAS_declarationDecorationList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_declarationDecorationList  (capCollectionElementArray ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationDecorationList GALGAS_declarationDecorationList::constructor_listWithValue (const GALGAS_abstractDecoratedDeclaration & inOperand0
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_declarationDecorationList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_declarationDecorationList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_declarationDecorationList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationDecorationList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                  const GALGAS_abstractDecoratedDeclaration & in_mDeclaration
                                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_declarationDecorationList * p = NULL ;
  macroMyNew (p, cCollectionElement_declarationDecorationList (in_mDeclaration COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationDecorationList::addAssign_operation (const GALGAS_abstractDecoratedDeclaration & inOperand0
                                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_declarationDecorationList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationDecorationList::setter_insertAtIndex (const GALGAS_abstractDecoratedDeclaration inOperand0,
                                                             const GALGAS_uint inInsertionIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_declarationDecorationList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationDecorationList::setter_removeAtIndex (GALGAS_abstractDecoratedDeclaration & outOperand0,
                                                             const GALGAS_uint inRemoveIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_declarationDecorationList * p = (cCollectionElement_declarationDecorationList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_declarationDecorationList) ;
      outOperand0 = p->mObject.mProperty_mDeclaration ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationDecorationList::setter_popFirst (GALGAS_abstractDecoratedDeclaration & outOperand0,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_declarationDecorationList * p = (cCollectionElement_declarationDecorationList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_declarationDecorationList) ;
    outOperand0 = p->mObject.mProperty_mDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationDecorationList::setter_popLast (GALGAS_abstractDecoratedDeclaration & outOperand0,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_declarationDecorationList * p = (cCollectionElement_declarationDecorationList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_declarationDecorationList) ;
    outOperand0 = p->mObject.mProperty_mDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationDecorationList::method_first (GALGAS_abstractDecoratedDeclaration & outOperand0,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_declarationDecorationList * p = (cCollectionElement_declarationDecorationList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_declarationDecorationList) ;
    outOperand0 = p->mObject.mProperty_mDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationDecorationList::method_last (GALGAS_abstractDecoratedDeclaration & outOperand0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_declarationDecorationList * p = (cCollectionElement_declarationDecorationList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_declarationDecorationList) ;
    outOperand0 = p->mObject.mProperty_mDeclaration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationDecorationList GALGAS_declarationDecorationList::add_operation (const GALGAS_declarationDecorationList & inOperand,
                                                                                  C_Compiler * /* inCompiler */
                                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_declarationDecorationList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationDecorationList GALGAS_declarationDecorationList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_declarationDecorationList result = GALGAS_declarationDecorationList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationDecorationList GALGAS_declarationDecorationList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_declarationDecorationList result = GALGAS_declarationDecorationList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationDecorationList GALGAS_declarationDecorationList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_declarationDecorationList result = GALGAS_declarationDecorationList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationDecorationList::plusAssign_operation (const GALGAS_declarationDecorationList inOperand,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractDecoratedDeclaration GALGAS_declarationDecorationList::getter_mDeclarationAtIndex (const GALGAS_uint & inIndex,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_declarationDecorationList * p = (cCollectionElement_declarationDecorationList *) attributes.ptr () ;
  GALGAS_abstractDecoratedDeclaration result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_declarationDecorationList) ;
    result = p->mObject.mProperty_mDeclaration ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_declarationDecorationList::cEnumerator_declarationDecorationList (const GALGAS_declarationDecorationList & inEnumeratedObject,
                                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationDecorationList_2D_element cEnumerator_declarationDecorationList::current (LOCATION_ARGS) const {
  const cCollectionElement_declarationDecorationList * p = (const cCollectionElement_declarationDecorationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_declarationDecorationList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractDecoratedDeclaration cEnumerator_declarationDecorationList::current_mDeclaration (LOCATION_ARGS) const {
  const cCollectionElement_declarationDecorationList * p = (const cCollectionElement_declarationDecorationList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_declarationDecorationList) ;
  return p->mObject.mProperty_mDeclaration ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @declarationDecorationList type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_declarationDecorationList ("declarationDecorationList",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_declarationDecorationList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_declarationDecorationList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_declarationDecorationList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_declarationDecorationList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationDecorationList GALGAS_declarationDecorationList::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_declarationDecorationList result ;
  const GALGAS_declarationDecorationList * p = (const GALGAS_declarationDecorationList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_declarationDecorationList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("declarationDecorationList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_prefixOperatorMap::cMapElement_prefixOperatorMap (const GALGAS_lstring & inKey
                                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_prefixOperatorMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_prefixOperatorMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_prefixOperatorMap (mProperty_lkey COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_prefixOperatorMap::description (C_String & /* ioString */, const int32_t /* inIndentation */) const {
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_prefixOperatorMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_prefixOperatorMap * operand = (cMapElement_prefixOperatorMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap::GALGAS_prefixOperatorMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap::GALGAS_prefixOperatorMap (const GALGAS_prefixOperatorMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap & GALGAS_prefixOperatorMap::operator = (const GALGAS_prefixOperatorMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap GALGAS_prefixOperatorMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_prefixOperatorMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap GALGAS_prefixOperatorMap::constructor_mapWithMapToOverride (const GALGAS_prefixOperatorMap & inMapToOverride
                                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_prefixOperatorMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap GALGAS_prefixOperatorMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_prefixOperatorMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefixOperatorMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_prefixOperatorMap * p = NULL ;
  macroMyNew (p, cMapElement_prefixOperatorMap (inKey COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@prefixOperatorMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefixOperatorMap::setter_insertKey (GALGAS_lstring inKey,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_prefixOperatorMap * p = NULL ;
  macroMyNew (p, cMapElement_prefixOperatorMap (inKey COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "** internal error **" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_prefixOperatorMap_searchKey = "prefix operation is not defined for $%K type" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefixOperatorMap::method_searchKey (GALGAS_lstring inKey,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  const cMapElement_prefixOperatorMap * p = (const cMapElement_prefixOperatorMap *) performSearch (inKey,
                                                                                                   inCompiler,
                                                                                                   kSearchErrorMessage_prefixOperatorMap_searchKey
                                                                                                   COMMA_THERE) ;
  if (NULL == p) {
  }else{
    macroValidSharedObject (p, cMapElement_prefixOperatorMap) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_prefixOperatorMap * GALGAS_prefixOperatorMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                             const GALGAS_string & inKey
                                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_prefixOperatorMap * result = (cMapElement_prefixOperatorMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_prefixOperatorMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_prefixOperatorMap::cEnumerator_prefixOperatorMap (const GALGAS_prefixOperatorMap & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap_2D_element cEnumerator_prefixOperatorMap::current (LOCATION_ARGS) const {
  const cMapElement_prefixOperatorMap * p = (const cMapElement_prefixOperatorMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_prefixOperatorMap) ;
  return GALGAS_prefixOperatorMap_2D_element (p->mProperty_lkey) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_prefixOperatorMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @prefixOperatorMap type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_prefixOperatorMap ("prefixOperatorMap",
                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_prefixOperatorMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefixOperatorMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_prefixOperatorMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_prefixOperatorMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefixOperatorMap GALGAS_prefixOperatorMap::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_prefixOperatorMap result ;
  const GALGAS_prefixOperatorMap * p = (const GALGAS_prefixOperatorMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_prefixOperatorMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("prefixOperatorMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_staticStringMap::cMapElement_staticStringMap (const GALGAS_lstring & inKey,
                                                          const GALGAS_uint & in_mIndex
                                                          COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mIndex (in_mIndex) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_staticStringMap::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_staticStringMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_staticStringMap (mProperty_lkey, mProperty_mIndex COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_staticStringMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mIndex" ":" ;
  mProperty_mIndex.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_staticStringMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_staticStringMap * operand = (cMapElement_staticStringMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mIndex.objectCompare (operand->mProperty_mIndex) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap::GALGAS_staticStringMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap::GALGAS_staticStringMap (const GALGAS_staticStringMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap & GALGAS_staticStringMap::operator = (const GALGAS_staticStringMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap GALGAS_staticStringMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_staticStringMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap GALGAS_staticStringMap::constructor_mapWithMapToOverride (const GALGAS_staticStringMap & inMapToOverride
                                                                                 COMMA_LOCATION_ARGS) {
  GALGAS_staticStringMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap GALGAS_staticStringMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_staticStringMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_staticStringMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                  const GALGAS_uint & inArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cMapElement_staticStringMap * p = NULL ;
  macroMyNew (p, cMapElement_staticStringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@staticStringMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_staticStringMap::setter_insertKey (GALGAS_lstring inKey,
                                               GALGAS_uint inArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cMapElement_staticStringMap * p = NULL ;
  macroMyNew (p, cMapElement_staticStringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "-- internal error --" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_staticStringMap_searchKey = "-- internal error --" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_staticStringMap::method_searchKey (GALGAS_lstring inKey,
                                               GALGAS_uint & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  const cMapElement_staticStringMap * p = (const cMapElement_staticStringMap *) performSearch (inKey,
                                                                                               inCompiler,
                                                                                               kSearchErrorMessage_staticStringMap_searchKey
                                                                                               COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_staticStringMap) ;
    outArgument0 = p->mProperty_mIndex ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_staticStringMap::getter_mIndexForKey (const GALGAS_string & inKey,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_staticStringMap * p = (const cMapElement_staticStringMap *) attributes ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_staticStringMap) ;
    result = p->mProperty_mIndex ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_staticStringMap::setter_setMIndexForKey (GALGAS_uint inAttributeValue,
                                                     GALGAS_string inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_staticStringMap * p = (cMapElement_staticStringMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_staticStringMap) ;
    p->mProperty_mIndex = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_staticStringMap * GALGAS_staticStringMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                         const GALGAS_string & inKey
                                                                                         COMMA_LOCATION_ARGS) {
  cMapElement_staticStringMap * result = (cMapElement_staticStringMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_staticStringMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_staticStringMap::cEnumerator_staticStringMap (const GALGAS_staticStringMap & inEnumeratedObject,
                                                          const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap_2D_element cEnumerator_staticStringMap::current (LOCATION_ARGS) const {
  const cMapElement_staticStringMap * p = (const cMapElement_staticStringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_staticStringMap) ;
  return GALGAS_staticStringMap_2D_element (p->mProperty_lkey, p->mProperty_mIndex) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_staticStringMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cEnumerator_staticStringMap::current_mIndex (LOCATION_ARGS) const {
  const cMapElement_staticStringMap * p = (const cMapElement_staticStringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_staticStringMap) ;
  return p->mProperty_mIndex ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @staticStringMap type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_staticStringMap ("staticStringMap",
                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_staticStringMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_staticStringMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_staticStringMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_staticStringMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap GALGAS_staticStringMap::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_staticStringMap result ;
  const GALGAS_staticStringMap * p = (const GALGAS_staticStringMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_staticStringMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("staticStringMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension method '@staticStringMap findOrAddStaticString'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_findOrAddStaticString (GALGAS_staticStringMap & ioObject,
                                            GALGAS_string inArgument_inString,
                                            GALGAS_uint & outArgument_outIndex,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outIndex.drop () ; // Release 'out' argument
  const GALGAS_staticStringMap temp_0 = ioObject ;
  const enumGalgasBool test_1 = temp_0.getter_hasKey (inArgument_inString COMMA_SOURCE_FILE ("context.galgas", 45)).boolEnum () ;
  if (kBoolTrue == test_1) {
    const GALGAS_staticStringMap temp_2 = ioObject ;
    temp_2.method_searchKey (inArgument_inString.getter_nowhere (SOURCE_FILE ("context.galgas", 46)), outArgument_outIndex, inCompiler COMMA_SOURCE_FILE ("context.galgas", 46)) ;
  }else if (kBoolFalse == test_1) {
    const GALGAS_staticStringMap temp_3 = ioObject ;
    outArgument_outIndex = temp_3.getter_count (SOURCE_FILE ("context.galgas", 48)) ;
    {
    ioObject.setter_insertKey (inArgument_inString.getter_nowhere (SOURCE_FILE ("context.galgas", 49)), outArgument_outIndex, inCompiler COMMA_SOURCE_FILE ("context.galgas", 49)) ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*

cMapElement_globalConstantMap::cMapElement_globalConstantMap (const GALGAS_lstring & inKey,
                                                              const GALGAS_objectIR & in_mValue
                                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mValue (in_mValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_globalConstantMap::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mValue.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_globalConstantMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_globalConstantMap (mProperty_lkey, mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_globalConstantMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue" ":" ;
  mProperty_mValue.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_globalConstantMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_globalConstantMap * operand = (cMapElement_globalConstantMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mValue.objectCompare (operand->mProperty_mValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap::GALGAS_globalConstantMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap::GALGAS_globalConstantMap (const GALGAS_globalConstantMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap & GALGAS_globalConstantMap::operator = (const GALGAS_globalConstantMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap GALGAS_globalConstantMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_globalConstantMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap GALGAS_globalConstantMap::constructor_mapWithMapToOverride (const GALGAS_globalConstantMap & inMapToOverride
                                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_globalConstantMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap GALGAS_globalConstantMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_globalConstantMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                    const GALGAS_objectIR & inArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_globalConstantMap * p = NULL ;
  macroMyNew (p, cMapElement_globalConstantMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@globalConstantMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMap::setter_insertKey (GALGAS_lstring inKey,
                                                 GALGAS_objectIR inArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_globalConstantMap * p = NULL ;
  macroMyNew (p, cMapElement_globalConstantMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the '%K' constant is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_globalConstantMap_searchKey = "there is no '%K' constant" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMap::method_searchKey (GALGAS_lstring inKey,
                                                 GALGAS_objectIR & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  const cMapElement_globalConstantMap * p = (const cMapElement_globalConstantMap *) performSearch (inKey,
                                                                                                   inCompiler,
                                                                                                   kSearchErrorMessage_globalConstantMap_searchKey
                                                                                                   COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_globalConstantMap) ;
    outArgument0 = p->mProperty_mValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_globalConstantMap::getter_mValueForKey (const GALGAS_string & inKey,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_globalConstantMap * p = (const cMapElement_globalConstantMap *) attributes ;
  GALGAS_objectIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalConstantMap) ;
    result = p->mProperty_mValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMap::setter_setMValueForKey (GALGAS_objectIR inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_globalConstantMap * p = (cMapElement_globalConstantMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalConstantMap) ;
    p->mProperty_mValue = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_globalConstantMap * GALGAS_globalConstantMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                             const GALGAS_string & inKey
                                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_globalConstantMap * result = (cMapElement_globalConstantMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_globalConstantMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_globalConstantMap::cEnumerator_globalConstantMap (const GALGAS_globalConstantMap & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap_2D_element cEnumerator_globalConstantMap::current (LOCATION_ARGS) const {
  const cMapElement_globalConstantMap * p = (const cMapElement_globalConstantMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalConstantMap) ;
  return GALGAS_globalConstantMap_2D_element (p->mProperty_lkey, p->mProperty_mValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_globalConstantMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cEnumerator_globalConstantMap::current_mValue (LOCATION_ARGS) const {
  const cMapElement_globalConstantMap * p = (const cMapElement_globalConstantMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalConstantMap) ;
  return p->mProperty_mValue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @globalConstantMap type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_globalConstantMap ("globalConstantMap",
                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_globalConstantMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalConstantMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_globalConstantMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_globalConstantMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMap GALGAS_globalConstantMap::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_globalConstantMap result ;
  const GALGAS_globalConstantMap * p = (const GALGAS_globalConstantMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_globalConstantMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("globalConstantMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_allowedGuardMap::cMapElement_allowedGuardMap (const GALGAS_lstring & inKey
                                                          COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_allowedGuardMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_allowedGuardMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_allowedGuardMap (mProperty_lkey COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_allowedGuardMap::description (C_String & /* ioString */, const int32_t /* inIndentation */) const {
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_allowedGuardMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_allowedGuardMap * operand = (cMapElement_allowedGuardMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap::GALGAS_allowedGuardMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap::GALGAS_allowedGuardMap (const GALGAS_allowedGuardMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap & GALGAS_allowedGuardMap::operator = (const GALGAS_allowedGuardMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap GALGAS_allowedGuardMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_allowedGuardMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap GALGAS_allowedGuardMap::constructor_mapWithMapToOverride (const GALGAS_allowedGuardMap & inMapToOverride
                                                                                 COMMA_LOCATION_ARGS) {
  GALGAS_allowedGuardMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap GALGAS_allowedGuardMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  GALGAS_allowedGuardMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedGuardMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cMapElement_allowedGuardMap * p = NULL ;
  macroMyNew (p, cMapElement_allowedGuardMap (inKey COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@allowedGuardMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedGuardMap::setter_insertKey (GALGAS_lstring inKey,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cMapElement_allowedGuardMap * p = NULL ;
  macroMyNew (p, cMapElement_allowedGuardMap (inKey COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the '%K' guard is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_allowedGuardMap_searchKey = "there is no '%K' guard" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_allowedGuardMap::method_searchKey (GALGAS_lstring inKey,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  const cMapElement_allowedGuardMap * p = (const cMapElement_allowedGuardMap *) performSearch (inKey,
                                                                                               inCompiler,
                                                                                               kSearchErrorMessage_allowedGuardMap_searchKey
                                                                                               COMMA_THERE) ;
  if (NULL == p) {
  }else{
    macroValidSharedObject (p, cMapElement_allowedGuardMap) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_allowedGuardMap * GALGAS_allowedGuardMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                         const GALGAS_string & inKey
                                                                                         COMMA_LOCATION_ARGS) {
  cMapElement_allowedGuardMap * result = (cMapElement_allowedGuardMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_allowedGuardMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_allowedGuardMap::cEnumerator_allowedGuardMap (const GALGAS_allowedGuardMap & inEnumeratedObject,
                                                          const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap_2D_element cEnumerator_allowedGuardMap::current (LOCATION_ARGS) const {
  const cMapElement_allowedGuardMap * p = (const cMapElement_allowedGuardMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_allowedGuardMap) ;
  return GALGAS_allowedGuardMap_2D_element (p->mProperty_lkey) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_allowedGuardMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @allowedGuardMap type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_allowedGuardMap ("allowedGuardMap",
                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_allowedGuardMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_allowedGuardMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_allowedGuardMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_allowedGuardMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap GALGAS_allowedGuardMap::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_allowedGuardMap result ;
  const GALGAS_allowedGuardMap * p = (const GALGAS_allowedGuardMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_allowedGuardMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("allowedGuardMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_globalVariableMap::cMapElement_globalVariableMap (const GALGAS_lstring & inKey,
                                                              const GALGAS_PLMType & in_type,
                                                              const GALGAS_stringset & in_executionModeSet,
                                                              const GALGAS_allowedGuardMap & in_allowedGuardMap,
                                                              const GALGAS_objectIR & in_initialValue,
                                                              const GALGAS_bool & in_isConstant,
                                                              const GALGAS_bool & in_allowedAccessToAll
                                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_type (in_type),
mProperty_executionModeSet (in_executionModeSet),
mProperty_allowedGuardMap (in_allowedGuardMap),
mProperty_initialValue (in_initialValue),
mProperty_isConstant (in_isConstant),
mProperty_allowedAccessToAll (in_allowedAccessToAll) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_globalVariableMap::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_type.isValid () && mProperty_executionModeSet.isValid () && mProperty_allowedGuardMap.isValid () && mProperty_initialValue.isValid () && mProperty_isConstant.isValid () && mProperty_allowedAccessToAll.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_globalVariableMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_globalVariableMap (mProperty_lkey, mProperty_type, mProperty_executionModeSet, mProperty_allowedGuardMap, mProperty_initialValue, mProperty_isConstant, mProperty_allowedAccessToAll COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_globalVariableMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "type" ":" ;
  mProperty_type.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "executionModeSet" ":" ;
  mProperty_executionModeSet.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "allowedGuardMap" ":" ;
  mProperty_allowedGuardMap.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "initialValue" ":" ;
  mProperty_initialValue.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "isConstant" ":" ;
  mProperty_isConstant.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "allowedAccessToAll" ":" ;
  mProperty_allowedAccessToAll.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_globalVariableMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_globalVariableMap * operand = (cMapElement_globalVariableMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (operand->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_executionModeSet.objectCompare (operand->mProperty_executionModeSet) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_allowedGuardMap.objectCompare (operand->mProperty_allowedGuardMap) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_initialValue.objectCompare (operand->mProperty_initialValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_isConstant.objectCompare (operand->mProperty_isConstant) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_allowedAccessToAll.objectCompare (operand->mProperty_allowedAccessToAll) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap::GALGAS_globalVariableMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap::GALGAS_globalVariableMap (const GALGAS_globalVariableMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap & GALGAS_globalVariableMap::operator = (const GALGAS_globalVariableMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap GALGAS_globalVariableMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_globalVariableMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap GALGAS_globalVariableMap::constructor_mapWithMapToOverride (const GALGAS_globalVariableMap & inMapToOverride
                                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_globalVariableMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap GALGAS_globalVariableMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_globalVariableMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                    const GALGAS_PLMType & inArgument0,
                                                    const GALGAS_stringset & inArgument1,
                                                    const GALGAS_allowedGuardMap & inArgument2,
                                                    const GALGAS_objectIR & inArgument3,
                                                    const GALGAS_bool & inArgument4,
                                                    const GALGAS_bool & inArgument5,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_globalVariableMap * p = NULL ;
  macroMyNew (p, cMapElement_globalVariableMap (inKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4, inArgument5 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@globalVariableMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMap::setter_insertKey (GALGAS_lstring inKey,
                                                 GALGAS_PLMType inArgument0,
                                                 GALGAS_stringset inArgument1,
                                                 GALGAS_allowedGuardMap inArgument2,
                                                 GALGAS_objectIR inArgument3,
                                                 GALGAS_bool inArgument4,
                                                 GALGAS_bool inArgument5,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_globalVariableMap * p = NULL ;
  macroMyNew (p, cMapElement_globalVariableMap (inKey, inArgument0, inArgument1, inArgument2, inArgument3, inArgument4, inArgument5 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the '%K' global variable is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_globalVariableMap_searchKey = "there is no '%K' global variable" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMap::method_searchKey (GALGAS_lstring inKey,
                                                 GALGAS_PLMType & outArgument0,
                                                 GALGAS_stringset & outArgument1,
                                                 GALGAS_allowedGuardMap & outArgument2,
                                                 GALGAS_objectIR & outArgument3,
                                                 GALGAS_bool & outArgument4,
                                                 GALGAS_bool & outArgument5,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) performSearch (inKey,
                                                                                                   inCompiler,
                                                                                                   kSearchErrorMessage_globalVariableMap_searchKey
                                                                                                   COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
    outArgument2.drop () ;
    outArgument3.drop () ;
    outArgument4.drop () ;
    outArgument5.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    outArgument0 = p->mProperty_type ;
    outArgument1 = p->mProperty_executionModeSet ;
    outArgument2 = p->mProperty_allowedGuardMap ;
    outArgument3 = p->mProperty_initialValue ;
    outArgument4 = p->mProperty_isConstant ;
    outArgument5 = p->mProperty_allowedAccessToAll ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMType GALGAS_globalVariableMap::getter_typeForKey (const GALGAS_string & inKey,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) attributes ;
  GALGAS_PLMType result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    result = p->mProperty_type ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_globalVariableMap::getter_executionModeSetForKey (const GALGAS_string & inKey,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) attributes ;
  GALGAS_stringset result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    result = p->mProperty_executionModeSet ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap GALGAS_globalVariableMap::getter_allowedGuardMapForKey (const GALGAS_string & inKey,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) attributes ;
  GALGAS_allowedGuardMap result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    result = p->mProperty_allowedGuardMap ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_globalVariableMap::getter_initialValueForKey (const GALGAS_string & inKey,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) attributes ;
  GALGAS_objectIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    result = p->mProperty_initialValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_globalVariableMap::getter_isConstantForKey (const GALGAS_string & inKey,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    result = p->mProperty_isConstant ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_globalVariableMap::getter_allowedAccessToAllForKey (const GALGAS_string & inKey,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    result = p->mProperty_allowedAccessToAll ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMap::setter_setTypeForKey (GALGAS_PLMType inAttributeValue,
                                                     GALGAS_string inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_globalVariableMap * p = (cMapElement_globalVariableMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    p->mProperty_type = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMap::setter_setExecutionModeSetForKey (GALGAS_stringset inAttributeValue,
                                                                 GALGAS_string inKey,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_globalVariableMap * p = (cMapElement_globalVariableMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    p->mProperty_executionModeSet = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMap::setter_setAllowedGuardMapForKey (GALGAS_allowedGuardMap inAttributeValue,
                                                                GALGAS_string inKey,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_globalVariableMap * p = (cMapElement_globalVariableMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    p->mProperty_allowedGuardMap = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMap::setter_setInitialValueForKey (GALGAS_objectIR inAttributeValue,
                                                             GALGAS_string inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_globalVariableMap * p = (cMapElement_globalVariableMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    p->mProperty_initialValue = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMap::setter_setIsConstantForKey (GALGAS_bool inAttributeValue,
                                                           GALGAS_string inKey,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_globalVariableMap * p = (cMapElement_globalVariableMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    p->mProperty_isConstant = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMap::setter_setAllowedAccessToAllForKey (GALGAS_bool inAttributeValue,
                                                                   GALGAS_string inKey,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_globalVariableMap * p = (cMapElement_globalVariableMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMap) ;
    p->mProperty_allowedAccessToAll = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_globalVariableMap * GALGAS_globalVariableMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                             const GALGAS_string & inKey
                                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_globalVariableMap * result = (cMapElement_globalVariableMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_globalVariableMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_globalVariableMap::cEnumerator_globalVariableMap (const GALGAS_globalVariableMap & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap_2D_element cEnumerator_globalVariableMap::current (LOCATION_ARGS) const {
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalVariableMap) ;
  return GALGAS_globalVariableMap_2D_element (p->mProperty_lkey, p->mProperty_type, p->mProperty_executionModeSet, p->mProperty_allowedGuardMap, p->mProperty_initialValue, p->mProperty_isConstant, p->mProperty_allowedAccessToAll) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_globalVariableMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMType cEnumerator_globalVariableMap::current_type (LOCATION_ARGS) const {
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalVariableMap) ;
  return p->mProperty_type ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset cEnumerator_globalVariableMap::current_executionModeSet (LOCATION_ARGS) const {
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalVariableMap) ;
  return p->mProperty_executionModeSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allowedGuardMap cEnumerator_globalVariableMap::current_allowedGuardMap (LOCATION_ARGS) const {
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalVariableMap) ;
  return p->mProperty_allowedGuardMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cEnumerator_globalVariableMap::current_initialValue (LOCATION_ARGS) const {
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalVariableMap) ;
  return p->mProperty_initialValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_globalVariableMap::current_isConstant (LOCATION_ARGS) const {
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalVariableMap) ;
  return p->mProperty_isConstant ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_globalVariableMap::current_allowedAccessToAll (LOCATION_ARGS) const {
  const cMapElement_globalVariableMap * p = (const cMapElement_globalVariableMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalVariableMap) ;
  return p->mProperty_allowedAccessToAll ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @globalVariableMap type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_globalVariableMap ("globalVariableMap",
                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_globalVariableMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalVariableMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_globalVariableMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_globalVariableMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMap GALGAS_globalVariableMap::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_globalVariableMap result ;
  const GALGAS_globalVariableMap * p = (const GALGAS_globalVariableMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_globalVariableMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("globalVariableMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_availableInterruptMap::cMapElement_availableInterruptMap (const GALGAS_lstring & inKey,
                                                                      const GALGAS_interruptionPanicCode & in_mInterruptionPanicCode
                                                                      COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mInterruptionPanicCode (in_mInterruptionPanicCode) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_availableInterruptMap::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mInterruptionPanicCode.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_availableInterruptMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_availableInterruptMap (mProperty_lkey, mProperty_mInterruptionPanicCode COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_availableInterruptMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mInterruptionPanicCode" ":" ;
  mProperty_mInterruptionPanicCode.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_availableInterruptMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_availableInterruptMap * operand = (cMapElement_availableInterruptMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mInterruptionPanicCode.objectCompare (operand->mProperty_mInterruptionPanicCode) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap::GALGAS_availableInterruptMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap::GALGAS_availableInterruptMap (const GALGAS_availableInterruptMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap & GALGAS_availableInterruptMap::operator = (const GALGAS_availableInterruptMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap GALGAS_availableInterruptMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_availableInterruptMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap GALGAS_availableInterruptMap::constructor_mapWithMapToOverride (const GALGAS_availableInterruptMap & inMapToOverride
                                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_availableInterruptMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap GALGAS_availableInterruptMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_availableInterruptMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_availableInterruptMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                        const GALGAS_interruptionPanicCode & inArgument0,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  cMapElement_availableInterruptMap * p = NULL ;
  macroMyNew (p, cMapElement_availableInterruptMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@availableInterruptMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_availableInterruptMap::setter_insertKey (GALGAS_lstring inKey,
                                                     GALGAS_interruptionPanicCode inArgument0,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cMapElement_availableInterruptMap * p = NULL ;
  macroMyNew (p, cMapElement_availableInterruptMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "interrupt '%K' is already defined" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_availableInterruptMap_searchKey = "interrupt '%K' is not defined" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_availableInterruptMap::method_searchKey (GALGAS_lstring inKey,
                                                     GALGAS_interruptionPanicCode & outArgument0,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  const cMapElement_availableInterruptMap * p = (const cMapElement_availableInterruptMap *) performSearch (inKey,
                                                                                                           inCompiler,
                                                                                                           kSearchErrorMessage_availableInterruptMap_searchKey
                                                                                                           COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_availableInterruptMap) ;
    outArgument0 = p->mProperty_mInterruptionPanicCode ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptionPanicCode GALGAS_availableInterruptMap::getter_mInterruptionPanicCodeForKey (const GALGAS_string & inKey,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_availableInterruptMap * p = (const cMapElement_availableInterruptMap *) attributes ;
  GALGAS_interruptionPanicCode result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_availableInterruptMap) ;
    result = p->mProperty_mInterruptionPanicCode ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_availableInterruptMap::setter_setMInterruptionPanicCodeForKey (GALGAS_interruptionPanicCode inAttributeValue,
                                                                           GALGAS_string inKey,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_availableInterruptMap * p = (cMapElement_availableInterruptMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_availableInterruptMap) ;
    p->mProperty_mInterruptionPanicCode = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_availableInterruptMap * GALGAS_availableInterruptMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                     const GALGAS_string & inKey
                                                                                                     COMMA_LOCATION_ARGS) {
  cMapElement_availableInterruptMap * result = (cMapElement_availableInterruptMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_availableInterruptMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_availableInterruptMap::cEnumerator_availableInterruptMap (const GALGAS_availableInterruptMap & inEnumeratedObject,
                                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap_2D_element cEnumerator_availableInterruptMap::current (LOCATION_ARGS) const {
  const cMapElement_availableInterruptMap * p = (const cMapElement_availableInterruptMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_availableInterruptMap) ;
  return GALGAS_availableInterruptMap_2D_element (p->mProperty_lkey, p->mProperty_mInterruptionPanicCode) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_availableInterruptMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_interruptionPanicCode cEnumerator_availableInterruptMap::current_mInterruptionPanicCode (LOCATION_ARGS) const {
  const cMapElement_availableInterruptMap * p = (const cMapElement_availableInterruptMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_availableInterruptMap) ;
  return p->mProperty_mInterruptionPanicCode ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @availableInterruptMap type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_availableInterruptMap ("availableInterruptMap",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_availableInterruptMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_availableInterruptMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_availableInterruptMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_availableInterruptMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap GALGAS_availableInterruptMap::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_availableInterruptMap result ;
  const GALGAS_availableInterruptMap * p = (const GALGAS_availableInterruptMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_availableInterruptMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("availableInterruptMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Class for element of '@globalTaskVariableList' list                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_globalTaskVariableList : public cCollectionElement {
  public : GALGAS_globalTaskVariableList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_globalTaskVariableList (const GALGAS_string & in_mTaskName,
                                                      const GALGAS_string & in_mTaskTypeName,
                                                      const GALGAS_objectIR & in_mInitialValue
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

cCollectionElement_globalTaskVariableList::cCollectionElement_globalTaskVariableList (const GALGAS_string & in_mTaskName,
                                                                                      const GALGAS_string & in_mTaskTypeName,
                                                                                      const GALGAS_objectIR & in_mInitialValue
                                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mTaskName, in_mTaskTypeName, in_mInitialValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_globalTaskVariableList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_globalTaskVariableList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_globalTaskVariableList (mObject.mProperty_mTaskName, mObject.mProperty_mTaskTypeName, mObject.mProperty_mInitialValue COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_globalTaskVariableList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mTaskName" ":" ;
  mObject.mProperty_mTaskName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mTaskTypeName" ":" ;
  mObject.mProperty_mTaskTypeName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mInitialValue" ":" ;
  mObject.mProperty_mInitialValue.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_globalTaskVariableList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_globalTaskVariableList * operand = (cCollectionElement_globalTaskVariableList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_globalTaskVariableList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList::GALGAS_globalTaskVariableList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList::GALGAS_globalTaskVariableList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList GALGAS_globalTaskVariableList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_globalTaskVariableList  (capCollectionElementArray ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList GALGAS_globalTaskVariableList::constructor_listWithValue (const GALGAS_string & inOperand0,
                                                                                        const GALGAS_string & inOperand1,
                                                                                        const GALGAS_objectIR & inOperand2
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_globalTaskVariableList result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_globalTaskVariableList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_globalTaskVariableList::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalTaskVariableList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                               const GALGAS_string & in_mTaskName,
                                                               const GALGAS_string & in_mTaskTypeName,
                                                               const GALGAS_objectIR & in_mInitialValue
                                                               COMMA_LOCATION_ARGS) {
  cCollectionElement_globalTaskVariableList * p = NULL ;
  macroMyNew (p, cCollectionElement_globalTaskVariableList (in_mTaskName,
                                                            in_mTaskTypeName,
                                                            in_mInitialValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalTaskVariableList::addAssign_operation (const GALGAS_string & inOperand0,
                                                         const GALGAS_string & inOperand1,
                                                         const GALGAS_objectIR & inOperand2
                                                         COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_globalTaskVariableList (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalTaskVariableList::setter_insertAtIndex (const GALGAS_string inOperand0,
                                                          const GALGAS_string inOperand1,
                                                          const GALGAS_objectIR inOperand2,
                                                          const GALGAS_uint inInsertionIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_globalTaskVariableList (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalTaskVariableList::setter_removeAtIndex (GALGAS_string & outOperand0,
                                                          GALGAS_string & outOperand1,
                                                          GALGAS_objectIR & outOperand2,
                                                          const GALGAS_uint inRemoveIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_globalTaskVariableList * p = (cCollectionElement_globalTaskVariableList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_globalTaskVariableList) ;
      outOperand0 = p->mObject.mProperty_mTaskName ;
      outOperand1 = p->mObject.mProperty_mTaskTypeName ;
      outOperand2 = p->mObject.mProperty_mInitialValue ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalTaskVariableList::setter_popFirst (GALGAS_string & outOperand0,
                                                     GALGAS_string & outOperand1,
                                                     GALGAS_objectIR & outOperand2,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_globalTaskVariableList * p = (cCollectionElement_globalTaskVariableList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_globalTaskVariableList) ;
    outOperand0 = p->mObject.mProperty_mTaskName ;
    outOperand1 = p->mObject.mProperty_mTaskTypeName ;
    outOperand2 = p->mObject.mProperty_mInitialValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalTaskVariableList::setter_popLast (GALGAS_string & outOperand0,
                                                    GALGAS_string & outOperand1,
                                                    GALGAS_objectIR & outOperand2,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_globalTaskVariableList * p = (cCollectionElement_globalTaskVariableList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_globalTaskVariableList) ;
    outOperand0 = p->mObject.mProperty_mTaskName ;
    outOperand1 = p->mObject.mProperty_mTaskTypeName ;
    outOperand2 = p->mObject.mProperty_mInitialValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalTaskVariableList::method_first (GALGAS_string & outOperand0,
                                                  GALGAS_string & outOperand1,
                                                  GALGAS_objectIR & outOperand2,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_globalTaskVariableList * p = (cCollectionElement_globalTaskVariableList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_globalTaskVariableList) ;
    outOperand0 = p->mObject.mProperty_mTaskName ;
    outOperand1 = p->mObject.mProperty_mTaskTypeName ;
    outOperand2 = p->mObject.mProperty_mInitialValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalTaskVariableList::method_last (GALGAS_string & outOperand0,
                                                 GALGAS_string & outOperand1,
                                                 GALGAS_objectIR & outOperand2,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_globalTaskVariableList * p = (cCollectionElement_globalTaskVariableList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_globalTaskVariableList) ;
    outOperand0 = p->mObject.mProperty_mTaskName ;
    outOperand1 = p->mObject.mProperty_mTaskTypeName ;
    outOperand2 = p->mObject.mProperty_mInitialValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList GALGAS_globalTaskVariableList::add_operation (const GALGAS_globalTaskVariableList & inOperand,
                                                                            C_Compiler * /* inCompiler */
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_globalTaskVariableList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList GALGAS_globalTaskVariableList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_globalTaskVariableList result = GALGAS_globalTaskVariableList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList GALGAS_globalTaskVariableList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_globalTaskVariableList result = GALGAS_globalTaskVariableList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList GALGAS_globalTaskVariableList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_globalTaskVariableList result = GALGAS_globalTaskVariableList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalTaskVariableList::plusAssign_operation (const GALGAS_globalTaskVariableList inOperand,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_globalTaskVariableList::getter_mTaskNameAtIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalTaskVariableList * p = (cCollectionElement_globalTaskVariableList *) attributes.ptr () ;
  GALGAS_string result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalTaskVariableList) ;
    result = p->mObject.mProperty_mTaskName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_globalTaskVariableList::getter_mTaskTypeNameAtIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalTaskVariableList * p = (cCollectionElement_globalTaskVariableList *) attributes.ptr () ;
  GALGAS_string result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalTaskVariableList) ;
    result = p->mObject.mProperty_mTaskTypeName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_globalTaskVariableList::getter_mInitialValueAtIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_globalTaskVariableList * p = (cCollectionElement_globalTaskVariableList *) attributes.ptr () ;
  GALGAS_objectIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_globalTaskVariableList) ;
    result = p->mObject.mProperty_mInitialValue ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_globalTaskVariableList::cEnumerator_globalTaskVariableList (const GALGAS_globalTaskVariableList & inEnumeratedObject,
                                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList_2D_element cEnumerator_globalTaskVariableList::current (LOCATION_ARGS) const {
  const cCollectionElement_globalTaskVariableList * p = (const cCollectionElement_globalTaskVariableList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalTaskVariableList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_globalTaskVariableList::current_mTaskName (LOCATION_ARGS) const {
  const cCollectionElement_globalTaskVariableList * p = (const cCollectionElement_globalTaskVariableList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalTaskVariableList) ;
  return p->mObject.mProperty_mTaskName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_globalTaskVariableList::current_mTaskTypeName (LOCATION_ARGS) const {
  const cCollectionElement_globalTaskVariableList * p = (const cCollectionElement_globalTaskVariableList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalTaskVariableList) ;
  return p->mObject.mProperty_mTaskTypeName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cEnumerator_globalTaskVariableList::current_mInitialValue (LOCATION_ARGS) const {
  const cCollectionElement_globalTaskVariableList * p = (const cCollectionElement_globalTaskVariableList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_globalTaskVariableList) ;
  return p->mObject.mProperty_mInitialValue ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @globalTaskVariableList type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_globalTaskVariableList ("globalTaskVariableList",
                                               NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_globalTaskVariableList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalTaskVariableList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_globalTaskVariableList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_globalTaskVariableList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList GALGAS_globalTaskVariableList::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_globalTaskVariableList result ;
  const GALGAS_globalTaskVariableList * p = (const GALGAS_globalTaskVariableList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_globalTaskVariableList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("globalTaskVariableList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_unifiedTypeMap::cMapElement_unifiedTypeMap (const GALGAS_lstring & inKey,
                                                        const GALGAS_PLMType & in_type,
                                                        const GALGAS_uint & in_index
                                                        COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_type (in_type),
mProperty_index (in_index) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_unifiedTypeMap::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_type.isValid () && mProperty_index.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_unifiedTypeMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_unifiedTypeMap (mProperty_lkey, mProperty_type, mProperty_index COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_unifiedTypeMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "type" ":" ;
  mProperty_type.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "index" ":" ;
  mProperty_index.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_unifiedTypeMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_unifiedTypeMap * operand = (cMapElement_unifiedTypeMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (operand->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_index.objectCompare (operand->mProperty_index) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap::GALGAS_unifiedTypeMap (void) :
AC_GALGAS_uniqueMap (kMapAutomatonNoIssue, "") {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap::GALGAS_unifiedTypeMap (const GALGAS_unifiedTypeMap & inSource) :
AC_GALGAS_uniqueMap (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap & GALGAS_unifiedTypeMap::operator = (const GALGAS_unifiedTypeMap & inSource) {
  * ((AC_GALGAS_uniqueMap *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap GALGAS_unifiedTypeMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_unifiedTypeMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//  Map automaton states                                                                                               *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//  Map automaton state names                                                                                          *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//  Map automaton actions                                                                                              *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//  Map automaton transitions                                                                                          *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//  Map automaton final state issues                                                                                   *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_unifiedTypeMap::setter_insertType (GALGAS_lstring inKey,
                                               GALGAS_PLMType inArgument0,
                                               GALGAS_uint inArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cMapElement_unifiedTypeMap * p = NULL ;
  macroMyNew (p, cMapElement_unifiedTypeMap (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the '%K' type is already declared in %L" ;
  insertInSharedMap (attributes,
                     inCompiler,
                     0,
                     NULL,
                     kInsertErrorMessage
                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_unifiedTypeMap_searchKey = "there is no '%K' type" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_unifiedTypeMap::method_searchKey (GALGAS_lstring inKey,
                                              GALGAS_PLMType & outArgument0,
                                              GALGAS_uint & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  const cMapElement_unifiedTypeMap * p = (const cMapElement_unifiedTypeMap *) performSearch (inKey,
                                                                                               inCompiler,
                                                                                               kSearchErrorMessage_unifiedTypeMap_searchKey
                                                                                               COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_unifiedTypeMap) ;
    outArgument0 = p->mProperty_type ;
    outArgument1 = p->mProperty_index ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMType GALGAS_unifiedTypeMap::getter_typeForKey (const GALGAS_string & inKey,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_unifiedTypeMap * p = (const cMapElement_unifiedTypeMap *) attributes ;
  GALGAS_PLMType result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_unifiedTypeMap) ;
    result = p->mProperty_type ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_unifiedTypeMap::getter_indexForKey (const GALGAS_string & inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_unifiedTypeMap * p = (const cMapElement_unifiedTypeMap *) attributes ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_unifiedTypeMap) ;
    result = p->mProperty_index ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_unifiedTypeMap::setter_setTypeForKey (GALGAS_PLMType inAttributeValue,
                                                  GALGAS_string inKey,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_unifiedTypeMap * p = (cMapElement_unifiedTypeMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_unifiedTypeMap) ;
    p->mProperty_type = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_unifiedTypeMap::setter_setIndexForKey (GALGAS_uint inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_unifiedTypeMap * p = (cMapElement_unifiedTypeMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_unifiedTypeMap) ;
    p->mProperty_index = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_unifiedTypeMap * GALGAS_unifiedTypeMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) {
  cMapElement_unifiedTypeMap * result = (cMapElement_unifiedTypeMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_unifiedTypeMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_unifiedTypeMap::cEnumerator_unifiedTypeMap (const GALGAS_unifiedTypeMap & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_unifiedTypeMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMType cEnumerator_unifiedTypeMap::current_type (LOCATION_ARGS) const {
  const cMapElement_unifiedTypeMap * p = (const cMapElement_unifiedTypeMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_unifiedTypeMap) ;
  return p->mProperty_type ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cEnumerator_unifiedTypeMap::current_index (LOCATION_ARGS) const {
  const cMapElement_unifiedTypeMap * p = (const cMapElement_unifiedTypeMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_unifiedTypeMap) ;
  return p->mProperty_index ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @unifiedTypeMap type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_unifiedTypeMap ("unifiedTypeMap",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_unifiedTypeMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_unifiedTypeMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_unifiedTypeMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_unifiedTypeMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap GALGAS_unifiedTypeMap::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_unifiedTypeMap result ;
  const GALGAS_unifiedTypeMap * p = (const GALGAS_unifiedTypeMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_unifiedTypeMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("unifiedTypeMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Abstract extension method '@abstractDeclarationAST enterInContext'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_abstractDeclarationAST_enterInContext> gExtensionMethodTable_abstractDeclarationAST_enterInContext ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_enterInContext (const int32_t inClassIndex,
                                          extensionMethodSignature_abstractDeclarationAST_enterInContext inMethod) {
  gExtensionMethodTable_abstractDeclarationAST_enterInContext.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_abstractDeclarationAST_enterInContext (void) {
  gExtensionMethodTable_abstractDeclarationAST_enterInContext.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_abstractDeclarationAST_enterInContext (NULL,
                                                                  freeExtensionMethod_abstractDeclarationAST_enterInContext) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_enterInContext (const cPtr_abstractDeclarationAST * inObject,
                                         const GALGAS_functionDeclarationListAST constin_inProcedureListAST,
                                         GALGAS_semanticContext & io_ioContext,
                                         GALGAS_declarationDecorationList & io_ioDecoratedDeclarationList,
                                         GALGAS_subprogramInvocationGraph & io_ioSubprogramInvocationGraph,
                                         GALGAS_staticListInitializationMap & io_ioStaticListValueMap,
                                         GALGAS_staticStringMap & io_ioGlobalLiteralStringMap,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_abstractDeclarationAST) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_abstractDeclarationAST_enterInContext f = NULL ;
    if (classIndex < gExtensionMethodTable_abstractDeclarationAST_enterInContext.count ()) {
      f = gExtensionMethodTable_abstractDeclarationAST_enterInContext (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_abstractDeclarationAST_enterInContext.count ()) {
          f = gExtensionMethodTable_abstractDeclarationAST_enterInContext (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_abstractDeclarationAST_enterInContext.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_inProcedureListAST, io_ioContext, io_ioDecoratedDeclarationList, io_ioSubprogramInvocationGraph, io_ioStaticListValueMap, io_ioGlobalLiteralStringMap, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes::GALGAS_PLMTypeAttributes (void) :
mFlags (0),
mIsValid (false) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes::GALGAS_PLMTypeAttributes (const uint64_t inFlags) :
mFlags (inFlags),
mIsValid (true) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes GALGAS_PLMTypeAttributes::constructor_none (UNUSED_LOCATION_ARGS) {
  return GALGAS_PLMTypeAttributes (0) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes GALGAS_PLMTypeAttributes::constructor_all (UNUSED_LOCATION_ARGS) {
  return GALGAS_PLMTypeAttributes (0xF) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes GALGAS_PLMTypeAttributes::constructor_instanciable (UNUSED_LOCATION_ARGS) {
  return GALGAS_PLMTypeAttributes (((uint64_t) 1) << 0) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes GALGAS_PLMTypeAttributes::constructor_equatable (UNUSED_LOCATION_ARGS) {
  return GALGAS_PLMTypeAttributes (((uint64_t) 1) << 1) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes GALGAS_PLMTypeAttributes::constructor_copyable (UNUSED_LOCATION_ARGS) {
  return GALGAS_PLMTypeAttributes (((uint64_t) 1) << 2) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes GALGAS_PLMTypeAttributes::constructor_generateAssignmentRoutine (UNUSED_LOCATION_ARGS) {
  return GALGAS_PLMTypeAttributes (((uint64_t) 1) << 3) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes::~ GALGAS_PLMTypeAttributes (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_PLMTypeAttributes::objectCompare (const GALGAS_PLMTypeAttributes & inOperand) const {
   typeComparisonResult result = kOperandNotValid ;
   if (mIsValid && inOperand.mIsValid) {
     result = kOperandEqual ;
     if (mFlags < inOperand.mFlags) {
       result = kFirstOperandLowerThanSecond ;
     }else if (mFlags > inOperand.mFlags) {
       result = kFirstOperandGreaterThanSecond ;
     }
   }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_PLMTypeAttributes::isValid (void) const {
  return mIsValid ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_PLMTypeAttributes::drop (void) {
  mIsValid = false ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes GALGAS_PLMTypeAttributes::operator_or (const GALGAS_PLMTypeAttributes & inOperand
                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_PLMTypeAttributes result ;
  if (mIsValid && inOperand.mIsValid) {
    result = GALGAS_PLMTypeAttributes (mFlags | inOperand.mFlags) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes GALGAS_PLMTypeAttributes::operator_and (const GALGAS_PLMTypeAttributes & inOperand
                                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_PLMTypeAttributes result ;
  if (mIsValid && inOperand.mIsValid) {
    result = GALGAS_PLMTypeAttributes (mFlags & inOperand.mFlags) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes GALGAS_PLMTypeAttributes::operator_xor (const GALGAS_PLMTypeAttributes & inOperand
                                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_PLMTypeAttributes result ;
  if (mIsValid && inOperand.mIsValid) {
    result = GALGAS_PLMTypeAttributes (mFlags ^ inOperand.mFlags) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes GALGAS_PLMTypeAttributes::substract_operation (const GALGAS_PLMTypeAttributes & inOperand,
                                                                        C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_PLMTypeAttributes result ;
  if (mIsValid && inOperand.mIsValid) {
    result = GALGAS_PLMTypeAttributes (mFlags & ~ inOperand.mFlags) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes GALGAS_PLMTypeAttributes::operator_tilde (UNUSED_LOCATION_ARGS) const {
  GALGAS_PLMTypeAttributes result ;
  if (mIsValid) {
    result = GALGAS_PLMTypeAttributes (0xF ^ mFlags) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_PLMTypeAttributes::description (C_String & ioString,
                                            const int32_t /* inIndentation */) const {
  ioString << "<boolset @PLMTypeAttributes:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    if ((mFlags & ((uint64_t) 1) << 0) != 0) {
      ioString << " instanciable" ;
    }
    if ((mFlags & ((uint64_t) 1) << 1) != 0) {
      ioString << " equatable" ;
    }
    if ((mFlags & ((uint64_t) 1) << 2) != 0) {
      ioString << " copyable" ;
    }
    if ((mFlags & ((uint64_t) 1) << 3) != 0) {
      ioString << " generateAssignmentRoutine" ;
    }
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_PLMTypeAttributes::getter_none (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (mIsValid) {
    result = GALGAS_bool (mFlags == 0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_PLMTypeAttributes::getter_all (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (mIsValid) {
    result = GALGAS_bool (mFlags == 0xF) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_PLMTypeAttributes::getter_instanciable (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (mIsValid) {
    result = GALGAS_bool ((mFlags & ((uint64_t) 1) << 0) != 0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_PLMTypeAttributes::getter_equatable (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (mIsValid) {
    result = GALGAS_bool ((mFlags & ((uint64_t) 1) << 1) != 0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_PLMTypeAttributes::getter_copyable (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (mIsValid) {
    result = GALGAS_bool ((mFlags & ((uint64_t) 1) << 2) != 0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_PLMTypeAttributes::getter_generateAssignmentRoutine (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (mIsValid) {
    result = GALGAS_bool ((mFlags & ((uint64_t) 1) << 3) != 0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @PLMTypeAttributes type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_PLMTypeAttributes ("PLMTypeAttributes",
                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_PLMTypeAttributes::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_PLMTypeAttributes ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_PLMTypeAttributes::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_PLMTypeAttributes (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMTypeAttributes GALGAS_PLMTypeAttributes::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_PLMTypeAttributes result ;
  const GALGAS_PLMTypeAttributes * p = (const GALGAS_PLMTypeAttributes *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_PLMTypeAttributes *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("PLMTypeAttributes", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_propertyMap::cMapElement_propertyMap (const GALGAS_lstring & inKey,
                                                  const GALGAS_bool & in_mIsPublic,
                                                  const GALGAS_propertyAccessKind & in_mAccess
                                                  COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mIsPublic (in_mIsPublic),
mProperty_mAccess (in_mAccess) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_propertyMap::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIsPublic.isValid () && mProperty_mAccess.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_propertyMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_propertyMap (mProperty_lkey, mProperty_mIsPublic, mProperty_mAccess COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_propertyMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mIsPublic" ":" ;
  mProperty_mIsPublic.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mAccess" ":" ;
  mProperty_mAccess.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_propertyMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_propertyMap * operand = (cMapElement_propertyMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mIsPublic.objectCompare (operand->mProperty_mIsPublic) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mAccess.objectCompare (operand->mProperty_mAccess) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyMap::GALGAS_propertyMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyMap::GALGAS_propertyMap (const GALGAS_propertyMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyMap & GALGAS_propertyMap::operator = (const GALGAS_propertyMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyMap GALGAS_propertyMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_propertyMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyMap GALGAS_propertyMap::constructor_mapWithMapToOverride (const GALGAS_propertyMap & inMapToOverride
                                                                         COMMA_LOCATION_ARGS) {
  GALGAS_propertyMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyMap GALGAS_propertyMap::getter_overriddenMap (C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  GALGAS_propertyMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_propertyMap::addAssign_operation (const GALGAS_lstring & inKey,
                                              const GALGAS_bool & inArgument0,
                                              const GALGAS_propertyAccessKind & inArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cMapElement_propertyMap * p = NULL ;
  macroMyNew (p, cMapElement_propertyMap (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@propertyMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_propertyMap::setter_insertKey (GALGAS_lstring inKey,
                                           GALGAS_bool inArgument0,
                                           GALGAS_propertyAccessKind inArgument1,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  cMapElement_propertyMap * p = NULL ;
  macroMyNew (p, cMapElement_propertyMap (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the '%K' property is already declared" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_propertyMap_searchKey = "there is no '%K' property" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_propertyMap::method_searchKey (GALGAS_lstring inKey,
                                           GALGAS_bool & outArgument0,
                                           GALGAS_propertyAccessKind & outArgument1,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  const cMapElement_propertyMap * p = (const cMapElement_propertyMap *) performSearch (inKey,
                                                                                       inCompiler,
                                                                                       kSearchErrorMessage_propertyMap_searchKey
                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_propertyMap) ;
    outArgument0 = p->mProperty_mIsPublic ;
    outArgument1 = p->mProperty_mAccess ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_propertyMap::getter_mIsPublicForKey (const GALGAS_string & inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_propertyMap * p = (const cMapElement_propertyMap *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_propertyMap) ;
    result = p->mProperty_mIsPublic ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyAccessKind GALGAS_propertyMap::getter_mAccessForKey (const GALGAS_string & inKey,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_propertyMap * p = (const cMapElement_propertyMap *) attributes ;
  GALGAS_propertyAccessKind result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_propertyMap) ;
    result = p->mProperty_mAccess ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_propertyMap::setter_setMIsPublicForKey (GALGAS_bool inAttributeValue,
                                                    GALGAS_string inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_propertyMap * p = (cMapElement_propertyMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_propertyMap) ;
    p->mProperty_mIsPublic = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_propertyMap::setter_setMAccessForKey (GALGAS_propertyAccessKind inAttributeValue,
                                                  GALGAS_string inKey,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_propertyMap * p = (cMapElement_propertyMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_propertyMap) ;
    p->mProperty_mAccess = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_propertyMap * GALGAS_propertyMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                 const GALGAS_string & inKey
                                                                                 COMMA_LOCATION_ARGS) {
  cMapElement_propertyMap * result = (cMapElement_propertyMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_propertyMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_propertyMap::cEnumerator_propertyMap (const GALGAS_propertyMap & inEnumeratedObject,
                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyMap_2D_element cEnumerator_propertyMap::current (LOCATION_ARGS) const {
  const cMapElement_propertyMap * p = (const cMapElement_propertyMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_propertyMap) ;
  return GALGAS_propertyMap_2D_element (p->mProperty_lkey, p->mProperty_mIsPublic, p->mProperty_mAccess) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_propertyMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_propertyMap::current_mIsPublic (LOCATION_ARGS) const {
  const cMapElement_propertyMap * p = (const cMapElement_propertyMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_propertyMap) ;
  return p->mProperty_mIsPublic ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyAccessKind cEnumerator_propertyMap::current_mAccess (LOCATION_ARGS) const {
  const cMapElement_propertyMap * p = (const cMapElement_propertyMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_propertyMap) ;
  return p->mProperty_mAccess ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @propertyMap type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_propertyMap ("propertyMap",
                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_propertyMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_propertyMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_propertyMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_propertyMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyMap GALGAS_propertyMap::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_propertyMap result ;
  const GALGAS_propertyMap * p = (const GALGAS_propertyMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_propertyMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("propertyMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_constructorMap::cMapElement_constructorMap (const GALGAS_lstring & inKey,
                                                        const GALGAS_constructorSignature & in_mSignature,
                                                        const GALGAS_constructorValue & in_mInitValue
                                                        COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mSignature (in_mSignature),
mProperty_mInitValue (in_mInitValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_constructorMap::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mSignature.isValid () && mProperty_mInitValue.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_constructorMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_constructorMap (mProperty_lkey, mProperty_mSignature, mProperty_mInitValue COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_constructorMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSignature" ":" ;
  mProperty_mSignature.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mInitValue" ":" ;
  mProperty_mInitValue.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_constructorMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_constructorMap * operand = (cMapElement_constructorMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mSignature.objectCompare (operand->mProperty_mSignature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mInitValue.objectCompare (operand->mProperty_mInitValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap::GALGAS_constructorMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap::GALGAS_constructorMap (const GALGAS_constructorMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap & GALGAS_constructorMap::operator = (const GALGAS_constructorMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap GALGAS_constructorMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_constructorMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap GALGAS_constructorMap::constructor_mapWithMapToOverride (const GALGAS_constructorMap & inMapToOverride
                                                                               COMMA_LOCATION_ARGS) {
  GALGAS_constructorMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap GALGAS_constructorMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_constructorMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                 const GALGAS_constructorSignature & inArgument0,
                                                 const GALGAS_constructorValue & inArgument1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_constructorMap * p = NULL ;
  macroMyNew (p, cMapElement_constructorMap (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@constructorMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorMap::setter_insertKey (GALGAS_lstring inKey,
                                              GALGAS_constructorSignature inArgument0,
                                              GALGAS_constructorValue inArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cMapElement_constructorMap * p = NULL ;
  macroMyNew (p, cMapElement_constructorMap (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "-- internal error --" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_constructorMap_searchKey = "constructor is not defined" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorMap::method_searchKey (GALGAS_lstring inKey,
                                              GALGAS_constructorSignature & outArgument0,
                                              GALGAS_constructorValue & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  const cMapElement_constructorMap * p = (const cMapElement_constructorMap *) performSearch (inKey,
                                                                                             inCompiler,
                                                                                             kSearchErrorMessage_constructorMap_searchKey
                                                                                             COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_constructorMap) ;
    outArgument0 = p->mProperty_mSignature ;
    outArgument1 = p->mProperty_mInitValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorSignature GALGAS_constructorMap::getter_mSignatureForKey (const GALGAS_string & inKey,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_constructorMap * p = (const cMapElement_constructorMap *) attributes ;
  GALGAS_constructorSignature result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_constructorMap) ;
    result = p->mProperty_mSignature ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorValue GALGAS_constructorMap::getter_mInitValueForKey (const GALGAS_string & inKey,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_constructorMap * p = (const cMapElement_constructorMap *) attributes ;
  GALGAS_constructorValue result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_constructorMap) ;
    result = p->mProperty_mInitValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorMap::setter_setMSignatureForKey (GALGAS_constructorSignature inAttributeValue,
                                                        GALGAS_string inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_constructorMap * p = (cMapElement_constructorMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_constructorMap) ;
    p->mProperty_mSignature = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorMap::setter_setMInitValueForKey (GALGAS_constructorValue inAttributeValue,
                                                        GALGAS_string inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_constructorMap * p = (cMapElement_constructorMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_constructorMap) ;
    p->mProperty_mInitValue = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_constructorMap * GALGAS_constructorMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) {
  cMapElement_constructorMap * result = (cMapElement_constructorMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_constructorMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_constructorMap::cEnumerator_constructorMap (const GALGAS_constructorMap & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap_2D_element cEnumerator_constructorMap::current (LOCATION_ARGS) const {
  const cMapElement_constructorMap * p = (const cMapElement_constructorMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_constructorMap) ;
  return GALGAS_constructorMap_2D_element (p->mProperty_lkey, p->mProperty_mSignature, p->mProperty_mInitValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_constructorMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorSignature cEnumerator_constructorMap::current_mSignature (LOCATION_ARGS) const {
  const cMapElement_constructorMap * p = (const cMapElement_constructorMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_constructorMap) ;
  return p->mProperty_mSignature ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorValue cEnumerator_constructorMap::current_mInitValue (LOCATION_ARGS) const {
  const cMapElement_constructorMap * p = (const cMapElement_constructorMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_constructorMap) ;
  return p->mProperty_mInitValue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @constructorMap type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_constructorMap ("constructorMap",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_constructorMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_constructorMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_constructorMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_constructorMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorMap GALGAS_constructorMap::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_constructorMap result ;
  const GALGAS_constructorMap * p = (const GALGAS_constructorMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_constructorMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("constructorMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_typeKind_enumeration::cEnumAssociatedValues_typeKind_enumeration (const GALGAS_uint & inAssociatedValue0
                                                                                        COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_typeKind_enumeration::description (C_String & ioString,
                                                              const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_typeKind_enumeration::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_typeKind_enumeration * ptr = dynamic_cast<const cEnumAssociatedValues_typeKind_enumeration *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_typeKind_structure::cEnumAssociatedValues_typeKind_structure (const GALGAS_propertyList & inAssociatedValue0,
                                                                                    const GALGAS_guardMapForContext & inAssociatedValue1
                                                                                    COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0),
mAssociatedValue1 (inAssociatedValue1) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_typeKind_structure::description (C_String & ioString,
                                                            const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  mAssociatedValue1.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_typeKind_structure::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_typeKind_structure * ptr = dynamic_cast<const cEnumAssociatedValues_typeKind_structure *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  if (result == kOperandEqual) {
    result = mAssociatedValue1.objectCompare (ptr->mAssociatedValue1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_typeKind_integer::cEnumAssociatedValues_typeKind_integer (const GALGAS_bigint & inAssociatedValue0,
                                                                                const GALGAS_bigint & inAssociatedValue1,
                                                                                const GALGAS_bool & inAssociatedValue2,
                                                                                const GALGAS_uint & inAssociatedValue3
                                                                                COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0),
mAssociatedValue1 (inAssociatedValue1),
mAssociatedValue2 (inAssociatedValue2),
mAssociatedValue3 (inAssociatedValue3) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_typeKind_integer::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  mAssociatedValue1.description (ioString, inIndentation) ;
  mAssociatedValue2.description (ioString, inIndentation) ;
  mAssociatedValue3.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_typeKind_integer::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_typeKind_integer * ptr = dynamic_cast<const cEnumAssociatedValues_typeKind_integer *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  if (result == kOperandEqual) {
    result = mAssociatedValue1.objectCompare (ptr->mAssociatedValue1) ;
  }
  if (result == kOperandEqual) {
    result = mAssociatedValue2.objectCompare (ptr->mAssociatedValue2) ;
  }
  if (result == kOperandEqual) {
    result = mAssociatedValue3.objectCompare (ptr->mAssociatedValue3) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_typeKind_opaque::cEnumAssociatedValues_typeKind_opaque (const GALGAS_bigint & inAssociatedValue0
                                                                              COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_typeKind_opaque::description (C_String & ioString,
                                                         const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_typeKind_opaque::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_typeKind_opaque * ptr = dynamic_cast<const cEnumAssociatedValues_typeKind_opaque *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_typeKind_arrayType::cEnumAssociatedValues_typeKind_arrayType (const GALGAS_PLMType & inAssociatedValue0,
                                                                                    const GALGAS_bigint & inAssociatedValue1
                                                                                    COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0),
mAssociatedValue1 (inAssociatedValue1) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_typeKind_arrayType::description (C_String & ioString,
                                                            const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  mAssociatedValue1.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_typeKind_arrayType::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_typeKind_arrayType * ptr = dynamic_cast<const cEnumAssociatedValues_typeKind_arrayType *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  if (result == kOperandEqual) {
    result = mAssociatedValue1.objectCompare (ptr->mAssociatedValue1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_typeKind_function::cEnumAssociatedValues_typeKind_function (const GALGAS_routineDescriptor & inAssociatedValue0
                                                                                  COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_typeKind_function::description (C_String & ioString,
                                                           const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_typeKind_function::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_typeKind_function * ptr = dynamic_cast<const cEnumAssociatedValues_typeKind_function *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_typeKind_pointer::cEnumAssociatedValues_typeKind_pointer (const GALGAS_PLMType & inAssociatedValue0
                                                                                COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_typeKind_pointer::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_typeKind_pointer::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_typeKind_pointer * ptr = dynamic_cast<const cEnumAssociatedValues_typeKind_pointer *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind::GALGAS_typeKind (void) :
mAssociatedValues (),
mEnum (kNotBuilt) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind GALGAS_typeKind::constructor_void (UNUSED_LOCATION_ARGS) {
  GALGAS_typeKind result ;
  result.mEnum = kEnum_void ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind GALGAS_typeKind::constructor_boolean (UNUSED_LOCATION_ARGS) {
  GALGAS_typeKind result ;
  result.mEnum = kEnum_boolean ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind GALGAS_typeKind::constructor_literalString (UNUSED_LOCATION_ARGS) {
  GALGAS_typeKind result ;
  result.mEnum = kEnum_literalString ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind GALGAS_typeKind::constructor_enumeration (const GALGAS_uint & inAssociatedValue0
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_typeKind result ;
  if (inAssociatedValue0.isValid ()) {
    result.mEnum = kEnum_enumeration ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_typeKind_enumeration (inAssociatedValue0 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind GALGAS_typeKind::constructor_structure (const GALGAS_propertyList & inAssociatedValue0,
                                                        const GALGAS_guardMapForContext & inAssociatedValue1
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_typeKind result ;
  if (inAssociatedValue0.isValid () && inAssociatedValue1.isValid ()) {
    result.mEnum = kEnum_structure ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_typeKind_structure (inAssociatedValue0, inAssociatedValue1 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind GALGAS_typeKind::constructor_integer (const GALGAS_bigint & inAssociatedValue0,
                                                      const GALGAS_bigint & inAssociatedValue1,
                                                      const GALGAS_bool & inAssociatedValue2,
                                                      const GALGAS_uint & inAssociatedValue3
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeKind result ;
  if (inAssociatedValue0.isValid () && inAssociatedValue1.isValid () && inAssociatedValue2.isValid () && inAssociatedValue3.isValid ()) {
    result.mEnum = kEnum_integer ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_typeKind_integer (inAssociatedValue0, inAssociatedValue1, inAssociatedValue2, inAssociatedValue3 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind GALGAS_typeKind::constructor_staticInteger (UNUSED_LOCATION_ARGS) {
  GALGAS_typeKind result ;
  result.mEnum = kEnum_staticInteger ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind GALGAS_typeKind::constructor_opaque (const GALGAS_bigint & inAssociatedValue0
                                                     COMMA_LOCATION_ARGS) {
  GALGAS_typeKind result ;
  if (inAssociatedValue0.isValid ()) {
    result.mEnum = kEnum_opaque ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_typeKind_opaque (inAssociatedValue0 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind GALGAS_typeKind::constructor_arrayType (const GALGAS_PLMType & inAssociatedValue0,
                                                        const GALGAS_bigint & inAssociatedValue1
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_typeKind result ;
  if (inAssociatedValue0.isValid () && inAssociatedValue1.isValid ()) {
    result.mEnum = kEnum_arrayType ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_typeKind_arrayType (inAssociatedValue0, inAssociatedValue1 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind GALGAS_typeKind::constructor_function (const GALGAS_routineDescriptor & inAssociatedValue0
                                                       COMMA_LOCATION_ARGS) {
  GALGAS_typeKind result ;
  if (inAssociatedValue0.isValid ()) {
    result.mEnum = kEnum_function ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_typeKind_function (inAssociatedValue0 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind GALGAS_typeKind::constructor_pointer (const GALGAS_PLMType & inAssociatedValue0
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeKind result ;
  if (inAssociatedValue0.isValid ()) {
    result.mEnum = kEnum_pointer ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_typeKind_pointer (inAssociatedValue0 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_typeKind::method_enumeration (GALGAS_uint & outAssociatedValue0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_enumeration) {
    outAssociatedValue0.drop () ;
    C_String s ;
    s << "method @typeKind enumeration invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_typeKind_enumeration * ptr = (const cEnumAssociatedValues_typeKind_enumeration *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_typeKind::method_structure (GALGAS_propertyList & outAssociatedValue0,
                                        GALGAS_guardMapForContext & outAssociatedValue1,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_structure) {
    outAssociatedValue0.drop () ;
    outAssociatedValue1.drop () ;
    C_String s ;
    s << "method @typeKind structure invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_typeKind_structure * ptr = (const cEnumAssociatedValues_typeKind_structure *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
    outAssociatedValue1 = ptr->mAssociatedValue1 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_typeKind::method_integer (GALGAS_bigint & outAssociatedValue0,
                                      GALGAS_bigint & outAssociatedValue1,
                                      GALGAS_bool & outAssociatedValue2,
                                      GALGAS_uint & outAssociatedValue3,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_integer) {
    outAssociatedValue0.drop () ;
    outAssociatedValue1.drop () ;
    outAssociatedValue2.drop () ;
    outAssociatedValue3.drop () ;
    C_String s ;
    s << "method @typeKind integer invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_typeKind_integer * ptr = (const cEnumAssociatedValues_typeKind_integer *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
    outAssociatedValue1 = ptr->mAssociatedValue1 ;
    outAssociatedValue2 = ptr->mAssociatedValue2 ;
    outAssociatedValue3 = ptr->mAssociatedValue3 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_typeKind::method_opaque (GALGAS_bigint & outAssociatedValue0,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_opaque) {
    outAssociatedValue0.drop () ;
    C_String s ;
    s << "method @typeKind opaque invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_typeKind_opaque * ptr = (const cEnumAssociatedValues_typeKind_opaque *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_typeKind::method_arrayType (GALGAS_PLMType & outAssociatedValue0,
                                        GALGAS_bigint & outAssociatedValue1,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_arrayType) {
    outAssociatedValue0.drop () ;
    outAssociatedValue1.drop () ;
    C_String s ;
    s << "method @typeKind arrayType invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_typeKind_arrayType * ptr = (const cEnumAssociatedValues_typeKind_arrayType *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
    outAssociatedValue1 = ptr->mAssociatedValue1 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_typeKind::method_function (GALGAS_routineDescriptor & outAssociatedValue0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_function) {
    outAssociatedValue0.drop () ;
    C_String s ;
    s << "method @typeKind function invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_typeKind_function * ptr = (const cEnumAssociatedValues_typeKind_function *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_typeKind::method_pointer (GALGAS_PLMType & outAssociatedValue0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_pointer) {
    outAssociatedValue0.drop () ;
    C_String s ;
    s << "method @typeKind pointer invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_typeKind_pointer * ptr = (const cEnumAssociatedValues_typeKind_pointer *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * gEnumNameArrayFor_typeKind [12] = {
  "(not built)",
  "void",
  "boolean",
  "literalString",
  "enumeration",
  "structure",
  "integer",
  "staticInteger",
  "opaque",
  "arrayType",
  "function",
  "pointer"
} ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_typeKind::getter_isVoid (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_void == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_typeKind::getter_isBoolean (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_boolean == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_typeKind::getter_isLiteralString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_literalString == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_typeKind::getter_isEnumeration (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_enumeration == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_typeKind::getter_isStructure (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_structure == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_typeKind::getter_isInteger (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_integer == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_typeKind::getter_isStaticInteger (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_staticInteger == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_typeKind::getter_isOpaque (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_opaque == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_typeKind::getter_isArrayType (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_arrayType == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_typeKind::getter_isFunction (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_function == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_typeKind::getter_isPointer (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_pointer == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_typeKind::description (C_String & ioString,
                                   const int32_t inIndentation) const {
  ioString << "<enum @typeKind: " << gEnumNameArrayFor_typeKind [mEnum] ;
  mAssociatedValues.description (ioString, inIndentation) ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_typeKind::objectCompare (const GALGAS_typeKind & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mAssociatedValues.objectCompare (inOperand.mAssociatedValues) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @typeKind type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeKind ("typeKind",
                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_typeKind::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_typeKind::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeKind (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typeKind GALGAS_typeKind::extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeKind result ;
  const GALGAS_typeKind * p = (const GALGAS_typeKind *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeKind *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeKind", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_propertyAccessKind_constantProperty::cEnumAssociatedValues_propertyAccessKind_constantProperty (const GALGAS_objectIR & inAssociatedValue0
                                                                                                                      COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_propertyAccessKind_constantProperty::description (C_String & ioString,
                                                                             const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_propertyAccessKind_constantProperty::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_propertyAccessKind_constantProperty * ptr = dynamic_cast<const cEnumAssociatedValues_propertyAccessKind_constantProperty *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_propertyAccessKind_indexed::cEnumAssociatedValues_propertyAccessKind_indexed (const GALGAS_PLMType & inAssociatedValue0,
                                                                                                    const GALGAS_uint & inAssociatedValue1
                                                                                                    COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0),
mAssociatedValue1 (inAssociatedValue1) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_propertyAccessKind_indexed::description (C_String & ioString,
                                                                    const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  mAssociatedValue1.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_propertyAccessKind_indexed::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_propertyAccessKind_indexed * ptr = dynamic_cast<const cEnumAssociatedValues_propertyAccessKind_indexed *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  if (result == kOperandEqual) {
    result = mAssociatedValue1.objectCompare (ptr->mAssociatedValue1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod::cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod (const GALGAS_routineDescriptor & inAssociatedValue0
                                                                                                                      COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod::description (C_String & ioString,
                                                                             const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod * ptr = dynamic_cast<const cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyAccessKind::GALGAS_propertyAccessKind (void) :
mAssociatedValues (),
mEnum (kNotBuilt) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyAccessKind GALGAS_propertyAccessKind::constructor_constantProperty (const GALGAS_objectIR & inAssociatedValue0
                                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_propertyAccessKind result ;
  if (inAssociatedValue0.isValid ()) {
    result.mEnum = kEnum_constantProperty ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_propertyAccessKind_constantProperty (inAssociatedValue0 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyAccessKind GALGAS_propertyAccessKind::constructor_indexed (const GALGAS_PLMType & inAssociatedValue0,
                                                                          const GALGAS_uint & inAssociatedValue1
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_propertyAccessKind result ;
  if (inAssociatedValue0.isValid () && inAssociatedValue1.isValid ()) {
    result.mEnum = kEnum_indexed ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_propertyAccessKind_indexed (inAssociatedValue0, inAssociatedValue1 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyAccessKind GALGAS_propertyAccessKind::constructor_nonVirtualMethod (const GALGAS_routineDescriptor & inAssociatedValue0
                                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_propertyAccessKind result ;
  if (inAssociatedValue0.isValid ()) {
    result.mEnum = kEnum_nonVirtualMethod ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod (inAssociatedValue0 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_propertyAccessKind::method_constantProperty (GALGAS_objectIR & outAssociatedValue0,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_constantProperty) {
    outAssociatedValue0.drop () ;
    C_String s ;
    s << "method @propertyAccessKind constantProperty invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_propertyAccessKind_constantProperty * ptr = (const cEnumAssociatedValues_propertyAccessKind_constantProperty *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_propertyAccessKind::method_indexed (GALGAS_PLMType & outAssociatedValue0,
                                                GALGAS_uint & outAssociatedValue1,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_indexed) {
    outAssociatedValue0.drop () ;
    outAssociatedValue1.drop () ;
    C_String s ;
    s << "method @propertyAccessKind indexed invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_propertyAccessKind_indexed * ptr = (const cEnumAssociatedValues_propertyAccessKind_indexed *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
    outAssociatedValue1 = ptr->mAssociatedValue1 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_propertyAccessKind::method_nonVirtualMethod (GALGAS_routineDescriptor & outAssociatedValue0,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_nonVirtualMethod) {
    outAssociatedValue0.drop () ;
    C_String s ;
    s << "method @propertyAccessKind nonVirtualMethod invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod * ptr = (const cEnumAssociatedValues_propertyAccessKind_nonVirtualMethod *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * gEnumNameArrayFor_propertyAccessKind [4] = {
  "(not built)",
  "constantProperty",
  "indexed",
  "nonVirtualMethod"
} ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_propertyAccessKind::getter_isConstantProperty (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_constantProperty == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_propertyAccessKind::getter_isIndexed (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_indexed == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_propertyAccessKind::getter_isNonVirtualMethod (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_nonVirtualMethod == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_propertyAccessKind::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "<enum @propertyAccessKind: " << gEnumNameArrayFor_propertyAccessKind [mEnum] ;
  mAssociatedValues.description (ioString, inIndentation) ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_propertyAccessKind::objectCompare (const GALGAS_propertyAccessKind & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mAssociatedValues.objectCompare (inOperand.mAssociatedValues) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @propertyAccessKind type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_propertyAccessKind ("propertyAccessKind",
                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_propertyAccessKind::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_propertyAccessKind ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_propertyAccessKind::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_propertyAccessKind (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_propertyAccessKind GALGAS_propertyAccessKind::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_propertyAccessKind result ;
  const GALGAS_propertyAccessKind * p = (const GALGAS_propertyAccessKind *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_propertyAccessKind *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("propertyAccessKind", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension method '@propertyMap addFunction'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_addFunction (GALGAS_propertyMap & ioObject,
                                  const GALGAS_string constinArgument_inReceiverTypeName,
                                  const GALGAS_string constinArgument_inMethodName,
                                  const GALGAS_unifiedTypeMap_2D_proxy constinArgument_inResultType,
                                  GALGAS_subprogramInvocationGraph & ioArgument_ioSubprogramInvocationGraph,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_routineDescriptor var_descriptor_1268 = GALGAS_routineDescriptor::constructor_new (GALGAS_bool (true), GALGAS_bool (false), GALGAS_routineKind::constructor_function (GALGAS_mode::constructor_anyMode (SOURCE_FILE ("property-map.galgas", 31))  COMMA_SOURCE_FILE ("property-map.galgas", 31)), GALGAS_routineTypedSignature::constructor_emptyList (SOURCE_FILE ("property-map.galgas", 32)), constinArgument_inResultType, GALGAS_bool (false), GALGAS_bool (false)  COMMA_SOURCE_FILE ("property-map.galgas", 28)) ;
  {
  ioObject.setter_insertKey (constinArgument_inMethodName.add_operation (GALGAS_string ("()"), inCompiler COMMA_SOURCE_FILE ("property-map.galgas", 38)).getter_nowhere (SOURCE_FILE ("property-map.galgas", 38)), GALGAS_bool (true), GALGAS_propertyAccessKind::constructor_nonVirtualMethod (var_descriptor_1268  COMMA_SOURCE_FILE ("property-map.galgas", 40)), inCompiler COMMA_SOURCE_FILE ("property-map.galgas", 37)) ;
  }
  GALGAS_lstring var_routineNameForInvocationGraph_1801 = function_routineMangledNameFromAST (function_llvmTypeStringFromPLMname (constinArgument_inReceiverTypeName, inCompiler COMMA_SOURCE_FILE ("property-map.galgas", 44)), constinArgument_inMethodName.getter_nowhere (SOURCE_FILE ("property-map.galgas", 45)), GALGAS_routineFormalArgumentListAST::constructor_emptyList (SOURCE_FILE ("property-map.galgas", 46)), inCompiler COMMA_SOURCE_FILE ("property-map.galgas", 43)) ;
  {
  ioArgument_ioSubprogramInvocationGraph.setter_addNode (var_routineNameForInvocationGraph_1801, var_routineNameForInvocationGraph_1801, inCompiler COMMA_SOURCE_FILE ("property-map.galgas", 48)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_constructorValue_simple::cEnumAssociatedValues_constructorValue_simple (const GALGAS_bigint & inAssociatedValue0
                                                                                              COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_constructorValue_simple::description (C_String & ioString,
                                                                 const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_constructorValue_simple::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_constructorValue_simple * ptr = dynamic_cast<const cEnumAssociatedValues_constructorValue_simple *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_constructorValue_structure::cEnumAssociatedValues_constructorValue_structure (const GALGAS_sortedOperandIRList & inAssociatedValue0
                                                                                                    COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_constructorValue_structure::description (C_String & ioString,
                                                                    const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_constructorValue_structure::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_constructorValue_structure * ptr = dynamic_cast<const cEnumAssociatedValues_constructorValue_structure *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumAssociatedValues_constructorValue_arrayValue::cEnumAssociatedValues_constructorValue_arrayValue (const GALGAS_PLMType & inAssociatedValue0,
                                                                                                      const GALGAS_uint & inAssociatedValue1
                                                                                                      COMMA_LOCATION_ARGS) :
cEnumAssociatedValues (THERE),
mAssociatedValue0 (inAssociatedValue0),
mAssociatedValue1 (inAssociatedValue1) {
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cEnumAssociatedValues_constructorValue_arrayValue::description (C_String & ioString,
                                                                     const int32_t inIndentation) const {
  ioString << "(\n" ;
  mAssociatedValue0.description (ioString, inIndentation) ;
  mAssociatedValue1.description (ioString, inIndentation) ;
  ioString << ")" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cEnumAssociatedValues_constructorValue_arrayValue::compare (const cEnumAssociatedValues * inOperand) const {
  const cEnumAssociatedValues_constructorValue_arrayValue * ptr = dynamic_cast<const cEnumAssociatedValues_constructorValue_arrayValue *> (inOperand) ;
  macroValidPointer (ptr) ;
  typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAssociatedValue0.objectCompare (ptr->mAssociatedValue0) ;
  }
  if (result == kOperandEqual) {
    result = mAssociatedValue1.objectCompare (ptr->mAssociatedValue1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorValue::GALGAS_constructorValue (void) :
mAssociatedValues (),
mEnum (kNotBuilt) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorValue GALGAS_constructorValue::constructor_simple (const GALGAS_bigint & inAssociatedValue0
                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_constructorValue result ;
  if (inAssociatedValue0.isValid ()) {
    result.mEnum = kEnum_simple ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_constructorValue_simple (inAssociatedValue0 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorValue GALGAS_constructorValue::constructor_structure (const GALGAS_sortedOperandIRList & inAssociatedValue0
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_constructorValue result ;
  if (inAssociatedValue0.isValid ()) {
    result.mEnum = kEnum_structure ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_constructorValue_structure (inAssociatedValue0 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorValue GALGAS_constructorValue::constructor_arrayValue (const GALGAS_PLMType & inAssociatedValue0,
                                                                         const GALGAS_uint & inAssociatedValue1
                                                                         COMMA_LOCATION_ARGS) {
  GALGAS_constructorValue result ;
  if (inAssociatedValue0.isValid () && inAssociatedValue1.isValid ()) {
    result.mEnum = kEnum_arrayValue ;
    cEnumAssociatedValues * ptr = NULL ;
    macroMyNew (ptr, cEnumAssociatedValues_constructorValue_arrayValue (inAssociatedValue0, inAssociatedValue1 COMMA_THERE)) ;
    result.mAssociatedValues.setPointer (ptr) ;
    macroDetachSharedObject (ptr) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorValue::method_simple (GALGAS_bigint & outAssociatedValue0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_simple) {
    outAssociatedValue0.drop () ;
    C_String s ;
    s << "method @constructorValue simple invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_constructorValue_simple * ptr = (const cEnumAssociatedValues_constructorValue_simple *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorValue::method_structure (GALGAS_sortedOperandIRList & outAssociatedValue0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_structure) {
    outAssociatedValue0.drop () ;
    C_String s ;
    s << "method @constructorValue structure invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_constructorValue_structure * ptr = (const cEnumAssociatedValues_constructorValue_structure *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorValue::method_arrayValue (GALGAS_PLMType & outAssociatedValue0,
                                                 GALGAS_uint & outAssociatedValue1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  if (mEnum != kEnum_arrayValue) {
    outAssociatedValue0.drop () ;
    outAssociatedValue1.drop () ;
    C_String s ;
    s << "method @constructorValue arrayValue invoked with an invalid enum value" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }else{
    const cEnumAssociatedValues_constructorValue_arrayValue * ptr = (const cEnumAssociatedValues_constructorValue_arrayValue *) unsafePointer () ;
    outAssociatedValue0 = ptr->mAssociatedValue0 ;
    outAssociatedValue1 = ptr->mAssociatedValue1 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static const char * gEnumNameArrayFor_constructorValue [4] = {
  "(not built)",
  "simple",
  "structure",
  "arrayValue"
} ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_constructorValue::getter_isSimple (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_simple == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_constructorValue::getter_isStructure (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_structure == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_constructorValue::getter_isArrayValue (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_arrayValue == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorValue::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "<enum @constructorValue: " << gEnumNameArrayFor_constructorValue [mEnum] ;
  mAssociatedValues.description (ioString, inIndentation) ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_constructorValue::objectCompare (const GALGAS_constructorValue & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mAssociatedValues.objectCompare (inOperand.mAssociatedValues) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @constructorValue type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_constructorValue ("constructorValue",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_constructorValue::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_constructorValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_constructorValue::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_constructorValue (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorValue GALGAS_constructorValue::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_constructorValue result ;
  const GALGAS_constructorValue * p = (const GALGAS_constructorValue *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_constructorValue *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("constructorValue", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Class for element of '@constructorSignature' list                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_constructorSignature : public cCollectionElement {
  public : GALGAS_constructorSignature_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_constructorSignature (const GALGAS_string & in_mSelector,
                                                    const GALGAS_PLMType & in_mType,
                                                    const GALGAS_uint & in_mFieldIndex
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

cCollectionElement_constructorSignature::cCollectionElement_constructorSignature (const GALGAS_string & in_mSelector,
                                                                                  const GALGAS_PLMType & in_mType,
                                                                                  const GALGAS_uint & in_mFieldIndex
                                                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mSelector, in_mType, in_mFieldIndex) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_constructorSignature::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_constructorSignature::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_constructorSignature (mObject.mProperty_mSelector, mObject.mProperty_mType, mObject.mProperty_mFieldIndex COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_constructorSignature::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSelector" ":" ;
  mObject.mProperty_mSelector.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mType" ":" ;
  mObject.mProperty_mType.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mFieldIndex" ":" ;
  mObject.mProperty_mFieldIndex.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_constructorSignature::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_constructorSignature * operand = (cCollectionElement_constructorSignature *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_constructorSignature) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorSignature::GALGAS_constructorSignature (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorSignature::GALGAS_constructorSignature (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorSignature GALGAS_constructorSignature::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_constructorSignature  (capCollectionElementArray ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorSignature GALGAS_constructorSignature::constructor_listWithValue (const GALGAS_string & inOperand0,
                                                                                    const GALGAS_PLMType & inOperand1,
                                                                                    const GALGAS_uint & inOperand2
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_constructorSignature result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_constructorSignature (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_constructorSignature::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorSignature::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                             const GALGAS_string & in_mSelector,
                                                             const GALGAS_PLMType & in_mType,
                                                             const GALGAS_uint & in_mFieldIndex
                                                             COMMA_LOCATION_ARGS) {
  cCollectionElement_constructorSignature * p = NULL ;
  macroMyNew (p, cCollectionElement_constructorSignature (in_mSelector,
                                                          in_mType,
                                                          in_mFieldIndex COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorSignature::addAssign_operation (const GALGAS_string & inOperand0,
                                                       const GALGAS_PLMType & inOperand1,
                                                       const GALGAS_uint & inOperand2
                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_constructorSignature (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorSignature::setter_insertAtIndex (const GALGAS_string inOperand0,
                                                        const GALGAS_PLMType inOperand1,
                                                        const GALGAS_uint inOperand2,
                                                        const GALGAS_uint inInsertionIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_constructorSignature (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorSignature::setter_removeAtIndex (GALGAS_string & outOperand0,
                                                        GALGAS_PLMType & outOperand1,
                                                        GALGAS_uint & outOperand2,
                                                        const GALGAS_uint inRemoveIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_constructorSignature * p = (cCollectionElement_constructorSignature *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_constructorSignature) ;
      outOperand0 = p->mObject.mProperty_mSelector ;
      outOperand1 = p->mObject.mProperty_mType ;
      outOperand2 = p->mObject.mProperty_mFieldIndex ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorSignature::setter_popFirst (GALGAS_string & outOperand0,
                                                   GALGAS_PLMType & outOperand1,
                                                   GALGAS_uint & outOperand2,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_constructorSignature * p = (cCollectionElement_constructorSignature *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_constructorSignature) ;
    outOperand0 = p->mObject.mProperty_mSelector ;
    outOperand1 = p->mObject.mProperty_mType ;
    outOperand2 = p->mObject.mProperty_mFieldIndex ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorSignature::setter_popLast (GALGAS_string & outOperand0,
                                                  GALGAS_PLMType & outOperand1,
                                                  GALGAS_uint & outOperand2,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_constructorSignature * p = (cCollectionElement_constructorSignature *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_constructorSignature) ;
    outOperand0 = p->mObject.mProperty_mSelector ;
    outOperand1 = p->mObject.mProperty_mType ;
    outOperand2 = p->mObject.mProperty_mFieldIndex ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorSignature::method_first (GALGAS_string & outOperand0,
                                                GALGAS_PLMType & outOperand1,
                                                GALGAS_uint & outOperand2,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_constructorSignature * p = (cCollectionElement_constructorSignature *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_constructorSignature) ;
    outOperand0 = p->mObject.mProperty_mSelector ;
    outOperand1 = p->mObject.mProperty_mType ;
    outOperand2 = p->mObject.mProperty_mFieldIndex ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorSignature::method_last (GALGAS_string & outOperand0,
                                               GALGAS_PLMType & outOperand1,
                                               GALGAS_uint & outOperand2,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_constructorSignature * p = (cCollectionElement_constructorSignature *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_constructorSignature) ;
    outOperand0 = p->mObject.mProperty_mSelector ;
    outOperand1 = p->mObject.mProperty_mType ;
    outOperand2 = p->mObject.mProperty_mFieldIndex ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorSignature GALGAS_constructorSignature::add_operation (const GALGAS_constructorSignature & inOperand,
                                                                        C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_constructorSignature result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorSignature GALGAS_constructorSignature::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_constructorSignature result = GALGAS_constructorSignature::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorSignature GALGAS_constructorSignature::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_constructorSignature result = GALGAS_constructorSignature::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorSignature GALGAS_constructorSignature::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_constructorSignature result = GALGAS_constructorSignature::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_constructorSignature::plusAssign_operation (const GALGAS_constructorSignature inOperand,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_constructorSignature::getter_mSelectorAtIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_constructorSignature * p = (cCollectionElement_constructorSignature *) attributes.ptr () ;
  GALGAS_string result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_constructorSignature) ;
    result = p->mObject.mProperty_mSelector ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMType GALGAS_constructorSignature::getter_mTypeAtIndex (const GALGAS_uint & inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_constructorSignature * p = (cCollectionElement_constructorSignature *) attributes.ptr () ;
  GALGAS_PLMType result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_constructorSignature) ;
    result = p->mObject.mProperty_mType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_constructorSignature::getter_mFieldIndexAtIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_constructorSignature * p = (cCollectionElement_constructorSignature *) attributes.ptr () ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_constructorSignature) ;
    result = p->mObject.mProperty_mFieldIndex ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_constructorSignature::cEnumerator_constructorSignature (const GALGAS_constructorSignature & inEnumeratedObject,
                                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorSignature_2D_element cEnumerator_constructorSignature::current (LOCATION_ARGS) const {
  const cCollectionElement_constructorSignature * p = (const cCollectionElement_constructorSignature *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_constructorSignature) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_constructorSignature::current_mSelector (LOCATION_ARGS) const {
  const cCollectionElement_constructorSignature * p = (const cCollectionElement_constructorSignature *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_constructorSignature) ;
  return p->mObject.mProperty_mSelector ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMType cEnumerator_constructorSignature::current_mType (LOCATION_ARGS) const {
  const cCollectionElement_constructorSignature * p = (const cCollectionElement_constructorSignature *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_constructorSignature) ;
  return p->mObject.mProperty_mType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cEnumerator_constructorSignature::current_mFieldIndex (LOCATION_ARGS) const {
  const cCollectionElement_constructorSignature * p = (const cCollectionElement_constructorSignature *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_constructorSignature) ;
  return p->mObject.mProperty_mFieldIndex ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @constructorSignature type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_constructorSignature ("constructorSignature",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_constructorSignature::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_constructorSignature ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_constructorSignature::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_constructorSignature (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_constructorSignature GALGAS_constructorSignature::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_constructorSignature result ;
  const GALGAS_constructorSignature * p = (const GALGAS_constructorSignature *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_constructorSignature *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("constructorSignature", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Abstract extension method '@abstractDecoratedDeclaration semanticAnalysis'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_abstractDecoratedDeclaration_semanticAnalysis> gExtensionMethodTable_abstractDecoratedDeclaration_semanticAnalysis ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_semanticAnalysis (const int32_t inClassIndex,
                                            extensionMethodSignature_abstractDecoratedDeclaration_semanticAnalysis inMethod) {
  gExtensionMethodTable_abstractDecoratedDeclaration_semanticAnalysis.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_abstractDecoratedDeclaration_semanticAnalysis (void) {
  gExtensionMethodTable_abstractDecoratedDeclaration_semanticAnalysis.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_abstractDecoratedDeclaration_semanticAnalysis (NULL,
                                                                          freeExtensionMethod_abstractDecoratedDeclaration_semanticAnalysis) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_semanticAnalysis (const cPtr_abstractDecoratedDeclaration * inObject,
                                           const GALGAS_semanticContext constin_inContext,
                                           GALGAS_semanticTemporariesStruct & io_ioTemporaries,
                                           GALGAS_intermediateCodeStruct & io_ioIntermediateCodeStruct,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_abstractDecoratedDeclaration) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_abstractDecoratedDeclaration_semanticAnalysis f = NULL ;
    if (classIndex < gExtensionMethodTable_abstractDecoratedDeclaration_semanticAnalysis.count ()) {
      f = gExtensionMethodTable_abstractDecoratedDeclaration_semanticAnalysis (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_abstractDecoratedDeclaration_semanticAnalysis.count ()) {
          f = gExtensionMethodTable_abstractDecoratedDeclaration_semanticAnalysis (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_abstractDecoratedDeclaration_semanticAnalysis.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_inContext, io_ioTemporaries, io_ioIntermediateCodeStruct, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         '@subprogramInvocationGraph' graph                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_subprogramInvocationGraph::GALGAS_subprogramInvocationGraph (void) :
AC_GALGAS_graph () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_subprogramInvocationGraph GALGAS_subprogramInvocationGraph::constructor_emptyGraph (LOCATION_ARGS) {
  GALGAS_subprogramInvocationGraph result ;
  result.makeNewEmptyGraph (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_subprogramInvocationGraph::setter_addNode (GALGAS_lstring inKey,
                                                       GALGAS_lstring inArgument_0,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  GALGAS_lstringlist::makeAttributesFromObjects (attributes, inArgument_0 COMMA_THERE) ;
  const char * kErrorMessage = "the '%K' routine is already declared at %L" ;
  internalAddNode (inKey, kErrorMessage, attributes, inCompiler COMMA_THERE) ;
}


//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_subprogramInvocationGraph::method_topologicalSort (GALGAS_lstringlist & outSortedList,
                                                               GALGAS_lstringlist & outSortedKeyList,
                                                               GALGAS_lstringlist & outUnsortedList,
                                                               GALGAS_lstringlist & outUnsortedKeyList,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  capCollectionElementArray sortedList ;
  capCollectionElementArray unsortedList ;
  internalTopologicalSort (sortedList, outSortedKeyList, unsortedList, outUnsortedKeyList, inCompiler COMMA_THERE) ;
  outSortedList = GALGAS_lstringlist (sortedList) ;
  outUnsortedList = GALGAS_lstringlist (unsortedList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_subprogramInvocationGraph::method_depthFirstTopologicalSort (GALGAS_lstringlist & outSortedList,
                                                                         GALGAS_lstringlist & outSortedKeyList,
                                                                         GALGAS_lstringlist & outUnsortedList,
                                                                         GALGAS_lstringlist & outUnsortedKeyList,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElementArray sortedList ;
  capCollectionElementArray unsortedList ;
  internalDepthFirstTopologicalSort (sortedList, outSortedKeyList, unsortedList, outUnsortedKeyList, inCompiler COMMA_THERE) ;
  outSortedList = GALGAS_lstringlist (sortedList) ;
  outUnsortedList = GALGAS_lstringlist (unsortedList) ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_subprogramInvocationGraph GALGAS_subprogramInvocationGraph::getter_reversedGraph (LOCATION_ARGS) const {
  GALGAS_subprogramInvocationGraph result ;
  result.reversedGraphFromGraph (*this COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_subprogramInvocationGraph::method_circularities (GALGAS_lstringlist & outInfoList,
                                                             GALGAS_lstringlist & outKeyList
                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElementArray infoList ;
  internalFindCircularities (infoList, outKeyList COMMA_THERE) ;
  outInfoList = GALGAS_lstringlist (infoList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_subprogramInvocationGraph::method_nodesWithNoSuccessor (GALGAS_lstringlist & outInfoList,
                                                                    GALGAS_lstringlist & outKeyList
                                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElementArray infoList ;
  internalNodesWithNoSuccessor (infoList, outKeyList COMMA_THERE) ;
  outInfoList = GALGAS_lstringlist (infoList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_subprogramInvocationGraph::method_nodesWithNoPredecessor (GALGAS_lstringlist & outInfoList,
                                                                      GALGAS_lstringlist & outKeyList
                                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElementArray infoList ;
  internalNodesWithNoPredecessor (infoList, outKeyList COMMA_THERE) ;
  outInfoList = GALGAS_lstringlist (infoList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_subprogramInvocationGraph GALGAS_subprogramInvocationGraph::getter_subgraphFromNodes (const GALGAS_lstringlist & inStartKeyList,
                                                                                             const GALGAS_stringset & inKeysToExclude,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) const {
  GALGAS_subprogramInvocationGraph result ;
  subGraph (result, inStartKeyList, inKeysToExclude, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_subprogramInvocationGraph::getter_accessibleNodesFrom (const GALGAS_lstringlist & inStartKeyList,
                                                                                 const GALGAS_stringset & inNodesToExclude,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  GALGAS_subprogramInvocationGraph resultingGraph ;
  subGraph (resultingGraph,
            inStartKeyList,
            inNodesToExclude,
            inCompiler
            COMMA_THERE) ;
  if (resultingGraph.isValid ()) {
    result = resultingGraph.getter_lkeyList (THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @subprogramInvocationGraph type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_subprogramInvocationGraph ("subprogramInvocationGraph",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_subprogramInvocationGraph::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_subprogramInvocationGraph ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_subprogramInvocationGraph::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_subprogramInvocationGraph (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_subprogramInvocationGraph GALGAS_subprogramInvocationGraph::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_subprogramInvocationGraph result ;
  const GALGAS_subprogramInvocationGraph * p = (const GALGAS_subprogramInvocationGraph *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_subprogramInvocationGraph *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("subprogramInvocationGraph", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@routineMapIR llvmCodeGeneration'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_llvmCodeGeneration (const GALGAS_routineMapIR inObject,
                                         GALGAS_string & ioArgument_ioLLVMcode,
                                         GALGAS_string & ioArgument_ioAssemblerCode,
                                         const GALGAS_generationContext constinArgument_inGenerationContext,
                                         GALGAS_generationAdds & ioArgument_ioGenerationAdds,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_routineMapIR temp_0 = inObject ;
  cEnumerator_routineMapIR enumerator_5845 (temp_0, kENUMERATION_UP) ;
  while (enumerator_5845.hasCurrentObject ()) {
    extensionMethod_llvmCodeGeneration (enumerator_5845.current (HERE), ioArgument_ioLLVMcode, ioArgument_ioAssemblerCode, constinArgument_inGenerationContext, ioArgument_ioGenerationAdds, inCompiler COMMA_SOURCE_FILE ("semantic-routines.galgas", 148)) ;
    enumerator_5845.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension Getter '@objectIR isConstantValue'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool extensionGetter_isConstantValue (const GALGAS_objectIR & inObject,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const GALGAS_objectIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectIR::kNotBuilt:
    break ;
  case GALGAS_objectIR::kEnum_null:
    {
      result_result = GALGAS_bool (true) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_zero:
    {
      result_result = GALGAS_bool (true) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalInteger:
    {
      result_result = GALGAS_bool (true) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmValue:
    {
      result_result = GALGAS_bool (false) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_reference:
    {
      result_result = GALGAS_bool (false) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmStructureValue:
    {
      const cEnumAssociatedValues_objectIR_llvmStructureValue * extractPtr_1290 = (const cEnumAssociatedValues_objectIR_llvmStructureValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_sortedOperandIRList extractedValue_inValues = extractPtr_1290->mAssociatedValue1 ;
      result_result = GALGAS_bool (true) ;
      cEnumerator_sortedOperandIRList enumerator_1224 (extractedValue_inValues, kENUMERATION_UP) ;
      bool bool_1 = result_result.isValidAndTrue () ;
      if (enumerator_1224.hasCurrentObject () && bool_1) {
        while (enumerator_1224.hasCurrentObject () && bool_1) {
          result_result = extensionGetter_isConstantValue (enumerator_1224.current_mOperand (HERE), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 36)) ;
          enumerator_1224.gotoNextObject () ;
          if (enumerator_1224.hasCurrentObject ()) {
            bool_1 = result_result.isValidAndTrue () ;
          }
        }
      }
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmArrayValue:
    {
      const cEnumAssociatedValues_objectIR_llvmArrayValue * extractPtr_1449 = (const cEnumAssociatedValues_objectIR_llvmArrayValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_operandIRList extractedValue_inValues = extractPtr_1449->mAssociatedValue1 ;
      result_result = GALGAS_bool (true) ;
      cEnumerator_operandIRList enumerator_1383 (extractedValue_inValues, kENUMERATION_UP) ;
      bool bool_2 = result_result.isValidAndTrue () ;
      if (enumerator_1383.hasCurrentObject () && bool_2) {
        while (enumerator_1383.hasCurrentObject () && bool_2) {
          result_result = extensionGetter_isConstantValue (enumerator_1383.current_mOperand (HERE), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 41)) ;
          enumerator_1383.gotoNextObject () ;
          if (enumerator_1383.hasCurrentObject ()) {
            bool_2 = result_result.isValidAndTrue () ;
          }
        }
      }
    }
    break ;
  case GALGAS_objectIR::kEnum_literalString:
    {
      result_result = GALGAS_bool (true) ;
    }
    break ;
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension Getter '@objectIR isStructuredNonConstantValue'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool extensionGetter_isStructuredNonConstantValue (const GALGAS_objectIR & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const GALGAS_objectIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectIR::kNotBuilt:
    break ;
  case GALGAS_objectIR::kEnum_null:
    {
      result_result = GALGAS_bool (false) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_zero:
    {
      result_result = GALGAS_bool (false) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalInteger:
    {
      result_result = GALGAS_bool (false) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmValue:
    {
      result_result = GALGAS_bool (false) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_reference:
    {
      result_result = GALGAS_bool (false) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmStructureValue:
    {
      const cEnumAssociatedValues_objectIR_llvmStructureValue * extractPtr_2075 = (const cEnumAssociatedValues_objectIR_llvmStructureValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_sortedOperandIRList extractedValue_inValues = extractPtr_2075->mAssociatedValue1 ;
      result_result = GALGAS_bool (true) ;
      cEnumerator_sortedOperandIRList enumerator_2009 (extractedValue_inValues, kENUMERATION_UP) ;
      bool bool_1 = result_result.isValidAndTrue () ;
      if (enumerator_2009.hasCurrentObject () && bool_1) {
        while (enumerator_2009.hasCurrentObject () && bool_1) {
          result_result = extensionGetter_isConstantValue (enumerator_2009.current_mOperand (HERE), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 65)) ;
          enumerator_2009.gotoNextObject () ;
          if (enumerator_2009.hasCurrentObject ()) {
            bool_1 = result_result.isValidAndTrue () ;
          }
        }
      }
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmArrayValue:
    {
      const cEnumAssociatedValues_objectIR_llvmArrayValue * extractPtr_2234 = (const cEnumAssociatedValues_objectIR_llvmArrayValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_operandIRList extractedValue_inValues = extractPtr_2234->mAssociatedValue1 ;
      result_result = GALGAS_bool (true) ;
      cEnumerator_operandIRList enumerator_2168 (extractedValue_inValues, kENUMERATION_UP) ;
      bool bool_2 = result_result.isValidAndTrue () ;
      if (enumerator_2168.hasCurrentObject () && bool_2) {
        while (enumerator_2168.hasCurrentObject () && bool_2) {
          result_result = extensionGetter_isConstantValue (enumerator_2168.current_mOperand (HERE), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 70)) ;
          enumerator_2168.gotoNextObject () ;
          if (enumerator_2168.hasCurrentObject ()) {
            bool_2 = result_result.isValidAndTrue () ;
          }
        }
      }
    }
    break ;
  case GALGAS_objectIR::kEnum_literalString:
    {
      result_result = GALGAS_bool (false) ;
    }
    break ;
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension Getter '@objectIR llvmName'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_llvmName (const GALGAS_objectIR & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_objectIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectIR::kNotBuilt:
    break ;
  case GALGAS_objectIR::kEnum_null:
    {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_nowhere (SOURCE_FILE ("object-intermediate-representation.galgas", 81)), GALGAS_string ("<<@objectIR llvmName null>>"), fixItArray1  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 81)) ;
      result_result.drop () ; // Release error dropped variable
    }
    break ;
  case GALGAS_objectIR::kEnum_zero:
    {
      result_result = GALGAS_string ("zeroinitializer") ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalInteger:
    {
      const cEnumAssociatedValues_objectIR_literalInteger * extractPtr_2648 = (const cEnumAssociatedValues_objectIR_literalInteger *) (temp_0.unsafePointer ()) ;
      const GALGAS_bigint extractedValue_value = extractPtr_2648->mAssociatedValue1 ;
      result_result = extractedValue_value.getter_string (SOURCE_FILE ("object-intermediate-representation.galgas", 83)) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmValue:
    {
      const cEnumAssociatedValues_objectIR_llvmValue * extractPtr_2698 = (const cEnumAssociatedValues_objectIR_llvmValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_llvmName = extractPtr_2698->mAssociatedValue1 ;
      result_result = extractedValue_llvmName ;
    }
    break ;
  case GALGAS_objectIR::kEnum_reference:
    {
      const cEnumAssociatedValues_objectIR_reference * extractPtr_2748 = (const cEnumAssociatedValues_objectIR_reference *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_llvmName = extractPtr_2748->mAssociatedValue1 ;
      result_result = extractedValue_llvmName ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmStructureValue:
    {
      const cEnumAssociatedValues_objectIR_llvmStructureValue * extractPtr_2976 = (const cEnumAssociatedValues_objectIR_llvmStructureValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_sortedOperandIRList extractedValue_inValues = extractPtr_2976->mAssociatedValue1 ;
      result_result = GALGAS_string ("{") ;
      cEnumerator_sortedOperandIRList enumerator_2850 (extractedValue_inValues, kENUMERATION_UP) ;
      while (enumerator_2850.hasCurrentObject ()) {
        result_result.plusAssign_operation(extensionGetter_llvmTypeName (enumerator_2850.current_mOperand (HERE), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 89)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 89)).add_operation (extensionGetter_llvmName (enumerator_2850.current_mOperand (HERE), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 89)), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 89)), inCompiler  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 89)) ;
        if (enumerator_2850.hasNextObject ()) {
          result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 90)) ;
        }
        enumerator_2850.gotoNextObject () ;
      }
      result_result.plusAssign_operation(GALGAS_string ("}"), inCompiler  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 92)) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmArrayValue:
    {
      const cEnumAssociatedValues_objectIR_llvmArrayValue * extractPtr_3194 = (const cEnumAssociatedValues_objectIR_llvmArrayValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_operandIRList extractedValue_inValues = extractPtr_3194->mAssociatedValue1 ;
      result_result = GALGAS_string ("[") ;
      cEnumerator_operandIRList enumerator_3068 (extractedValue_inValues, kENUMERATION_UP) ;
      while (enumerator_3068.hasCurrentObject ()) {
        result_result.plusAssign_operation(extensionGetter_llvmTypeName (enumerator_3068.current_mOperand (HERE), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 96)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 96)).add_operation (extensionGetter_llvmName (enumerator_3068.current_mOperand (HERE), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 96)), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 96)), inCompiler  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 96)) ;
        if (enumerator_3068.hasNextObject ()) {
          result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 97)) ;
        }
        enumerator_3068.gotoNextObject () ;
      }
      result_result.plusAssign_operation(GALGAS_string ("]"), inCompiler  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 99)) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalString:
    {
      const cEnumAssociatedValues_objectIR_literalString * extractPtr_3432 = (const cEnumAssociatedValues_objectIR_literalString *) (temp_0.unsafePointer ()) ;
      const GALGAS_uint extractedValue_size = extractPtr_3432->mAssociatedValue0 ;
      const GALGAS_uint extractedValue_index = extractPtr_3432->mAssociatedValue1 ;
      GALGAS_string var_sizeStr_3259 = extractedValue_size.getter_string (SOURCE_FILE ("object-intermediate-representation.galgas", 101)) ;
      result_result = GALGAS_string ("getelementptr inbounds ([").add_operation (var_sizeStr_3259, inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 102)).add_operation (GALGAS_string (" x i8], ["), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 102)).add_operation (var_sizeStr_3259, inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 102)).add_operation (GALGAS_string (" x i8]* "), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 102)) ;
      result_result.plusAssign_operation(function_literalCharacterArrayName (extractedValue_index, inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 103)).add_operation (GALGAS_string (", i32 0, i32 0)"), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 103)), inCompiler  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 103)) ;
    }
    break ;
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Extension Getter '@objectIR type'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMType extensionGetter_type (const GALGAS_objectIR & inObject,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_PLMType result_result ; // Returned variable
  const GALGAS_objectIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectIR::kNotBuilt:
    break ;
  case GALGAS_objectIR::kEnum_null:
    {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_nowhere (SOURCE_FILE ("object-intermediate-representation.galgas", 112)), GALGAS_string ("<<@objectIR type null>>"), fixItArray1  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 112)) ;
      result_result.drop () ; // Release error dropped variable
    }
    break ;
  case GALGAS_objectIR::kEnum_reference:
    {
      const cEnumAssociatedValues_objectIR_reference * extractPtr_3725 = (const cEnumAssociatedValues_objectIR_reference *) (temp_0.unsafePointer ()) ;
      const GALGAS_PLMType extractedValue_type = extractPtr_3725->mAssociatedValue0 ;
      result_result = extractedValue_type ;
    }
    break ;
  case GALGAS_objectIR::kEnum_zero:
    {
      const cEnumAssociatedValues_objectIR_zero * extractPtr_3760 = (const cEnumAssociatedValues_objectIR_zero *) (temp_0.unsafePointer ()) ;
      const GALGAS_PLMType extractedValue_type = extractPtr_3760->mAssociatedValue0 ;
      result_result = extractedValue_type ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalInteger:
    {
      const cEnumAssociatedValues_objectIR_literalInteger * extractPtr_3807 = (const cEnumAssociatedValues_objectIR_literalInteger *) (temp_0.unsafePointer ()) ;
      const GALGAS_PLMType extractedValue_type = extractPtr_3807->mAssociatedValue0 ;
      result_result = extractedValue_type ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmValue:
    {
      const cEnumAssociatedValues_objectIR_llvmValue * extractPtr_3849 = (const cEnumAssociatedValues_objectIR_llvmValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_PLMType extractedValue_type = extractPtr_3849->mAssociatedValue0 ;
      result_result = extractedValue_type ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmStructureValue:
    {
      const cEnumAssociatedValues_objectIR_llvmStructureValue * extractPtr_3900 = (const cEnumAssociatedValues_objectIR_llvmStructureValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_PLMType extractedValue_type = extractPtr_3900->mAssociatedValue0 ;
      result_result = extractedValue_type ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmArrayValue:
    {
      const cEnumAssociatedValues_objectIR_llvmArrayValue * extractPtr_3947 = (const cEnumAssociatedValues_objectIR_llvmArrayValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_PLMType extractedValue_type = extractPtr_3947->mAssociatedValue0 ;
      result_result = extractedValue_type ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalString:
    {
      result_result = function_literalStringType (inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 119)) ;
    }
    break ;
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension Getter '@objectIR llvmTypeName'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_llvmTypeName (const GALGAS_objectIR & inObject,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_objectIR temp_0 = inObject ;
  result_result = extensionGetter_llvmTypeName (extensionGetter_type (temp_0, inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 126)), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 126)) ;
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension Getter '@objectIR plmTypeName'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_plmTypeName (const GALGAS_objectIR & inObject,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_objectIR temp_0 = inObject ;
  result_result = extensionGetter_type (temp_0, inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 132)).getter_plmTypeName (HERE) ;
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension Getter '@objectIR withType'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR extensionGetter_withType (const GALGAS_objectIR & inObject,
                                          const GALGAS_PLMType & constinArgument_inType,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectIR result_result ; // Returned variable
  const GALGAS_objectIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectIR::kNotBuilt:
    break ;
  case GALGAS_objectIR::kEnum_null:
    {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_nowhere (SOURCE_FILE ("object-intermediate-representation.galgas", 139)), GALGAS_string ("<<@objectIR withType null>>"), fixItArray1  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 139)) ;
      result_result.drop () ; // Release error dropped variable
    }
    break ;
  case GALGAS_objectIR::kEnum_reference:
    {
      const cEnumAssociatedValues_objectIR_reference * extractPtr_4782 = (const cEnumAssociatedValues_objectIR_reference *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_llvmName = extractPtr_4782->mAssociatedValue1 ;
      result_result = GALGAS_objectIR::constructor_reference (constinArgument_inType, extractedValue_llvmName  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 141)) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalInteger:
    {
      const cEnumAssociatedValues_objectIR_literalInteger * extractPtr_4883 = (const cEnumAssociatedValues_objectIR_literalInteger *) (temp_0.unsafePointer ()) ;
      const GALGAS_bigint extractedValue_value = extractPtr_4883->mAssociatedValue1 ;
      result_result = GALGAS_objectIR::constructor_literalInteger (constinArgument_inType, extractedValue_value  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 143)) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmValue:
    {
      const cEnumAssociatedValues_objectIR_llvmValue * extractPtr_4974 = (const cEnumAssociatedValues_objectIR_llvmValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_llvmName = extractPtr_4974->mAssociatedValue1 ;
      result_result = GALGAS_objectIR::constructor_llvmValue (constinArgument_inType, extractedValue_llvmName  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 145)) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_zero:
    {
      result_result = GALGAS_objectIR::constructor_zero (constinArgument_inType  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 147)) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmStructureValue:
    {
      const cEnumAssociatedValues_objectIR_llvmStructureValue * extractPtr_5152 = (const cEnumAssociatedValues_objectIR_llvmStructureValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_sortedOperandIRList extractedValue_values = extractPtr_5152->mAssociatedValue1 ;
      result_result = GALGAS_objectIR::constructor_llvmStructureValue (constinArgument_inType, extractedValue_values  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 149)) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmArrayValue:
    {
      const cEnumAssociatedValues_objectIR_llvmArrayValue * extractPtr_5263 = (const cEnumAssociatedValues_objectIR_llvmArrayValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_operandIRList extractedValue_values = extractPtr_5263->mAssociatedValue1 ;
      result_result = GALGAS_objectIR::constructor_llvmArrayValue (constinArgument_inType, extractedValue_values  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 151)) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalString:
    {
      const cEnumAssociatedValues_objectIR_literalString * extractPtr_5372 = (const cEnumAssociatedValues_objectIR_literalString *) (temp_0.unsafePointer ()) ;
      const GALGAS_uint extractedValue_size = extractPtr_5372->mAssociatedValue0 ;
      const GALGAS_uint extractedValue_index = extractPtr_5372->mAssociatedValue1 ;
      result_result = GALGAS_objectIR::constructor_literalString (extractedValue_size, extractedValue_index  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 153)) ;
    }
    break ;
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Extension Getter '@objectIR name'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string extensionGetter_name (const GALGAS_objectIR & inObject,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_objectIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectIR::kNotBuilt:
    break ;
  case GALGAS_objectIR::kEnum_null:
    {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_nowhere (SOURCE_FILE ("object-intermediate-representation.galgas", 161)), GALGAS_string ("<<@objectIR name null>>"), fixItArray1  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 161)) ;
      result_result.drop () ; // Release error dropped variable
    }
    break ;
  case GALGAS_objectIR::kEnum_reference:
    {
      const cEnumAssociatedValues_objectIR_reference * extractPtr_5668 = (const cEnumAssociatedValues_objectIR_reference *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_llvmName = extractPtr_5668->mAssociatedValue1 ;
      result_result = extractedValue_llvmName ;
    }
    break ;
  case GALGAS_objectIR::kEnum_zero:
    {
      result_result = GALGAS_string ("zeroinitializer") ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalInteger:
    {
      const cEnumAssociatedValues_objectIR_literalInteger * extractPtr_5779 = (const cEnumAssociatedValues_objectIR_literalInteger *) (temp_0.unsafePointer ()) ;
      const GALGAS_bigint extractedValue_value = extractPtr_5779->mAssociatedValue1 ;
      result_result = extractedValue_value.getter_string (SOURCE_FILE ("object-intermediate-representation.galgas", 164)) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmValue:
    {
      const cEnumAssociatedValues_objectIR_llvmValue * extractPtr_5821 = (const cEnumAssociatedValues_objectIR_llvmValue *) (temp_0.unsafePointer ()) ;
      const GALGAS_string extractedValue_name = extractPtr_5821->mAssociatedValue1 ;
      result_result = extractedValue_name ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmStructureValue:
    {
      result_result = GALGAS_string ("{...}") ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmArrayValue:
    {
      result_result = GALGAS_string ("[...]") ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalString:
    {
      const cEnumAssociatedValues_objectIR_literalString * extractPtr_6157 = (const cEnumAssociatedValues_objectIR_literalString *) (temp_0.unsafePointer ()) ;
      const GALGAS_uint extractedValue_size = extractPtr_6157->mAssociatedValue0 ;
      const GALGAS_uint extractedValue_index = extractPtr_6157->mAssociatedValue1 ;
      GALGAS_string var_sizeStr_5984 = extractedValue_size.getter_string (SOURCE_FILE ("object-intermediate-representation.galgas", 169)) ;
      result_result = GALGAS_string ("getelementptr inbounds ([").add_operation (var_sizeStr_5984, inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 170)).add_operation (GALGAS_string (" x i8], ["), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 170)).add_operation (var_sizeStr_5984, inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 170)).add_operation (GALGAS_string (" x i8]* "), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 170)) ;
      result_result.plusAssign_operation(function_literalCharacterArrayName (extractedValue_index, inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 171)).add_operation (GALGAS_string (", i32 0, i32 0)"), inCompiler COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 171)), inCompiler  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 171)) ;
    }
    break ;
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Extension Getter '@objectIR isStatic'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool extensionGetter_isStatic (const GALGAS_objectIR & inObject,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const GALGAS_objectIR temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_objectIR::kNotBuilt:
    break ;
  case GALGAS_objectIR::kEnum_null:
    {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_nowhere (SOURCE_FILE ("object-intermediate-representation.galgas", 179)), GALGAS_string ("<<@objectIR isStatic null>>"), fixItArray1  COMMA_SOURCE_FILE ("object-intermediate-representation.galgas", 179)) ;
      result_result.drop () ; // Release error dropped variable
    }
    break ;
  case GALGAS_objectIR::kEnum_reference:
    {
      result_result = GALGAS_bool (false) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_zero:
    {
      result_result = GALGAS_bool (true) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalInteger:
    {
      result_result = GALGAS_bool (true) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmValue:
    {
      result_result = GALGAS_bool (false) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmStructureValue:
    {
      result_result = GALGAS_bool (true) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmArrayValue:
    {
      result_result = GALGAS_bool (true) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalString:
    {
      result_result = GALGAS_bool (true) ;
    }
    break ;
  }
//---
  return result_result ;
}




//---------------------------------------------------------------------------------------------------------------------*

cMapElement_globalVariableMapIR::cMapElement_globalVariableMapIR (const GALGAS_lstring & inKey,
                                                                  const GALGAS_bool & in_mGenerateVolatile,
                                                                  const GALGAS_objectIR & in_mInitialValue
                                                                  COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mGenerateVolatile (in_mGenerateVolatile),
mProperty_mInitialValue (in_mInitialValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_globalVariableMapIR::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mGenerateVolatile.isValid () && mProperty_mInitialValue.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_globalVariableMapIR::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_globalVariableMapIR (mProperty_lkey, mProperty_mGenerateVolatile, mProperty_mInitialValue COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_globalVariableMapIR::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGenerateVolatile" ":" ;
  mProperty_mGenerateVolatile.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mInitialValue" ":" ;
  mProperty_mInitialValue.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_globalVariableMapIR::compare (const cCollectionElement * inOperand) const {
  cMapElement_globalVariableMapIR * operand = (cMapElement_globalVariableMapIR *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mGenerateVolatile.objectCompare (operand->mProperty_mGenerateVolatile) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mInitialValue.objectCompare (operand->mProperty_mInitialValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR::GALGAS_globalVariableMapIR (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR::GALGAS_globalVariableMapIR (const GALGAS_globalVariableMapIR & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR & GALGAS_globalVariableMapIR::operator = (const GALGAS_globalVariableMapIR & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR GALGAS_globalVariableMapIR::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_globalVariableMapIR result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR GALGAS_globalVariableMapIR::constructor_mapWithMapToOverride (const GALGAS_globalVariableMapIR & inMapToOverride
                                                                                         COMMA_LOCATION_ARGS) {
  GALGAS_globalVariableMapIR result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR GALGAS_globalVariableMapIR::getter_overriddenMap (C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const {
  GALGAS_globalVariableMapIR result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMapIR::addAssign_operation (const GALGAS_lstring & inKey,
                                                      const GALGAS_bool & inArgument0,
                                                      const GALGAS_objectIR & inArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  cMapElement_globalVariableMapIR * p = NULL ;
  macroMyNew (p, cMapElement_globalVariableMapIR (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@globalVariableMapIR insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMapIR::setter_insertKey (GALGAS_lstring inKey,
                                                   GALGAS_bool inArgument0,
                                                   GALGAS_objectIR inArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cMapElement_globalVariableMapIR * p = NULL ;
  macroMyNew (p, cMapElement_globalVariableMapIR (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "** internal error **" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_globalVariableMapIR_searchKey = "** internal error **" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMapIR::method_searchKey (GALGAS_lstring inKey,
                                                   GALGAS_bool & outArgument0,
                                                   GALGAS_objectIR & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  const cMapElement_globalVariableMapIR * p = (const cMapElement_globalVariableMapIR *) performSearch (inKey,
                                                                                                       inCompiler,
                                                                                                       kSearchErrorMessage_globalVariableMapIR_searchKey
                                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_globalVariableMapIR) ;
    outArgument0 = p->mProperty_mGenerateVolatile ;
    outArgument1 = p->mProperty_mInitialValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_globalVariableMapIR::getter_mGenerateVolatileForKey (const GALGAS_string & inKey,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_globalVariableMapIR * p = (const cMapElement_globalVariableMapIR *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMapIR) ;
    result = p->mProperty_mGenerateVolatile ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_globalVariableMapIR::getter_mInitialValueForKey (const GALGAS_string & inKey,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_globalVariableMapIR * p = (const cMapElement_globalVariableMapIR *) attributes ;
  GALGAS_objectIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMapIR) ;
    result = p->mProperty_mInitialValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMapIR::setter_setMGenerateVolatileForKey (GALGAS_bool inAttributeValue,
                                                                    GALGAS_string inKey,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_globalVariableMapIR * p = (cMapElement_globalVariableMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMapIR) ;
    p->mProperty_mGenerateVolatile = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalVariableMapIR::setter_setMInitialValueForKey (GALGAS_objectIR inAttributeValue,
                                                                GALGAS_string inKey,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_globalVariableMapIR * p = (cMapElement_globalVariableMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalVariableMapIR) ;
    p->mProperty_mInitialValue = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_globalVariableMapIR * GALGAS_globalVariableMapIR::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                 const GALGAS_string & inKey
                                                                                                 COMMA_LOCATION_ARGS) {
  cMapElement_globalVariableMapIR * result = (cMapElement_globalVariableMapIR *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_globalVariableMapIR) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_globalVariableMapIR::cEnumerator_globalVariableMapIR (const GALGAS_globalVariableMapIR & inEnumeratedObject,
                                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR_2D_element cEnumerator_globalVariableMapIR::current (LOCATION_ARGS) const {
  const cMapElement_globalVariableMapIR * p = (const cMapElement_globalVariableMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalVariableMapIR) ;
  return GALGAS_globalVariableMapIR_2D_element (p->mProperty_lkey, p->mProperty_mGenerateVolatile, p->mProperty_mInitialValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_globalVariableMapIR::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_globalVariableMapIR::current_mGenerateVolatile (LOCATION_ARGS) const {
  const cMapElement_globalVariableMapIR * p = (const cMapElement_globalVariableMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalVariableMapIR) ;
  return p->mProperty_mGenerateVolatile ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cEnumerator_globalVariableMapIR::current_mInitialValue (LOCATION_ARGS) const {
  const cMapElement_globalVariableMapIR * p = (const cMapElement_globalVariableMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalVariableMapIR) ;
  return p->mProperty_mInitialValue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @globalVariableMapIR type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_globalVariableMapIR ("globalVariableMapIR",
                                            NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_globalVariableMapIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalVariableMapIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_globalVariableMapIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_globalVariableMapIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalVariableMapIR GALGAS_globalVariableMapIR::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_globalVariableMapIR result ;
  const GALGAS_globalVariableMapIR * p = (const GALGAS_globalVariableMapIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_globalVariableMapIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("globalVariableMapIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_globalConstantMapIR::cMapElement_globalConstantMapIR (const GALGAS_lstring & inKey,
                                                                  const GALGAS_unifiedTypeMap_2D_proxy & in_mType,
                                                                  const GALGAS_objectIR & in_mSourceExpression
                                                                  COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mType (in_mType),
mProperty_mSourceExpression (in_mSourceExpression) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_globalConstantMapIR::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mType.isValid () && mProperty_mSourceExpression.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_globalConstantMapIR::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_globalConstantMapIR (mProperty_lkey, mProperty_mType, mProperty_mSourceExpression COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_globalConstantMapIR::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mType" ":" ;
  mProperty_mType.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSourceExpression" ":" ;
  mProperty_mSourceExpression.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_globalConstantMapIR::compare (const cCollectionElement * inOperand) const {
  cMapElement_globalConstantMapIR * operand = (cMapElement_globalConstantMapIR *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mType.objectCompare (operand->mProperty_mType) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mSourceExpression.objectCompare (operand->mProperty_mSourceExpression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR::GALGAS_globalConstantMapIR (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR::GALGAS_globalConstantMapIR (const GALGAS_globalConstantMapIR & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR & GALGAS_globalConstantMapIR::operator = (const GALGAS_globalConstantMapIR & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR GALGAS_globalConstantMapIR::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_globalConstantMapIR result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR GALGAS_globalConstantMapIR::constructor_mapWithMapToOverride (const GALGAS_globalConstantMapIR & inMapToOverride
                                                                                         COMMA_LOCATION_ARGS) {
  GALGAS_globalConstantMapIR result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR GALGAS_globalConstantMapIR::getter_overriddenMap (C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const {
  GALGAS_globalConstantMapIR result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMapIR::addAssign_operation (const GALGAS_lstring & inKey,
                                                      const GALGAS_unifiedTypeMap_2D_proxy & inArgument0,
                                                      const GALGAS_objectIR & inArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  cMapElement_globalConstantMapIR * p = NULL ;
  macroMyNew (p, cMapElement_globalConstantMapIR (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@globalConstantMapIR insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMapIR::setter_insertKey (GALGAS_lstring inKey,
                                                   GALGAS_unifiedTypeMap_2D_proxy inArgument0,
                                                   GALGAS_objectIR inArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cMapElement_globalConstantMapIR * p = NULL ;
  macroMyNew (p, cMapElement_globalConstantMapIR (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "** internal error **" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_globalConstantMapIR_searchKey = "** internal error **" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMapIR::method_searchKey (GALGAS_lstring inKey,
                                                   GALGAS_unifiedTypeMap_2D_proxy & outArgument0,
                                                   GALGAS_objectIR & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  const cMapElement_globalConstantMapIR * p = (const cMapElement_globalConstantMapIR *) performSearch (inKey,
                                                                                                       inCompiler,
                                                                                                       kSearchErrorMessage_globalConstantMapIR_searchKey
                                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_globalConstantMapIR) ;
    outArgument0 = p->mProperty_mType ;
    outArgument1 = p->mProperty_mSourceExpression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy GALGAS_globalConstantMapIR::getter_mTypeForKey (const GALGAS_string & inKey,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_globalConstantMapIR * p = (const cMapElement_globalConstantMapIR *) attributes ;
  GALGAS_unifiedTypeMap_2D_proxy result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalConstantMapIR) ;
    result = p->mProperty_mType ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_globalConstantMapIR::getter_mSourceExpressionForKey (const GALGAS_string & inKey,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_globalConstantMapIR * p = (const cMapElement_globalConstantMapIR *) attributes ;
  GALGAS_objectIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalConstantMapIR) ;
    result = p->mProperty_mSourceExpression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMapIR::setter_setMTypeForKey (GALGAS_unifiedTypeMap_2D_proxy inAttributeValue,
                                                        GALGAS_string inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_globalConstantMapIR * p = (cMapElement_globalConstantMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalConstantMapIR) ;
    p->mProperty_mType = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_globalConstantMapIR::setter_setMSourceExpressionForKey (GALGAS_objectIR inAttributeValue,
                                                                    GALGAS_string inKey,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_globalConstantMapIR * p = (cMapElement_globalConstantMapIR *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_globalConstantMapIR) ;
    p->mProperty_mSourceExpression = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_globalConstantMapIR * GALGAS_globalConstantMapIR::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                 const GALGAS_string & inKey
                                                                                                 COMMA_LOCATION_ARGS) {
  cMapElement_globalConstantMapIR * result = (cMapElement_globalConstantMapIR *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_globalConstantMapIR) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_globalConstantMapIR::cEnumerator_globalConstantMapIR (const GALGAS_globalConstantMapIR & inEnumeratedObject,
                                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR_2D_element cEnumerator_globalConstantMapIR::current (LOCATION_ARGS) const {
  const cMapElement_globalConstantMapIR * p = (const cMapElement_globalConstantMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalConstantMapIR) ;
  return GALGAS_globalConstantMapIR_2D_element (p->mProperty_lkey, p->mProperty_mType, p->mProperty_mSourceExpression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_globalConstantMapIR::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_unifiedTypeMap_2D_proxy cEnumerator_globalConstantMapIR::current_mType (LOCATION_ARGS) const {
  const cMapElement_globalConstantMapIR * p = (const cMapElement_globalConstantMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalConstantMapIR) ;
  return p->mProperty_mType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cEnumerator_globalConstantMapIR::current_mSourceExpression (LOCATION_ARGS) const {
  const cMapElement_globalConstantMapIR * p = (const cMapElement_globalConstantMapIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_globalConstantMapIR) ;
  return p->mProperty_mSourceExpression ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @globalConstantMapIR type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_globalConstantMapIR ("globalConstantMapIR",
                                            NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_globalConstantMapIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_globalConstantMapIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_globalConstantMapIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_globalConstantMapIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalConstantMapIR GALGAS_globalConstantMapIR::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_globalConstantMapIR result ;
  const GALGAS_globalConstantMapIR * p = (const GALGAS_globalConstantMapIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_globalConstantMapIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("globalConstantMapIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@generationListIR' list                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_generationListIR : public cCollectionElement {
  public : GALGAS_generationListIR_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_generationListIR (const GALGAS_abstractGenerationIR & in_mGeneration
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

cCollectionElement_generationListIR::cCollectionElement_generationListIR (const GALGAS_abstractGenerationIR & in_mGeneration
                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mGeneration) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_generationListIR::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_generationListIR::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_generationListIR (mObject.mProperty_mGeneration COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_generationListIR::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mGeneration" ":" ;
  mObject.mProperty_mGeneration.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_generationListIR::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_generationListIR * operand = (cCollectionElement_generationListIR *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_generationListIR) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationListIR::GALGAS_generationListIR (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationListIR::GALGAS_generationListIR (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationListIR GALGAS_generationListIR::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_generationListIR  (capCollectionElementArray ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationListIR GALGAS_generationListIR::constructor_listWithValue (const GALGAS_abstractGenerationIR & inOperand0
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_generationListIR result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_generationListIR (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_generationListIR::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationListIR::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                         const GALGAS_abstractGenerationIR & in_mGeneration
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_generationListIR * p = NULL ;
  macroMyNew (p, cCollectionElement_generationListIR (in_mGeneration COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationListIR::addAssign_operation (const GALGAS_abstractGenerationIR & inOperand0
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_generationListIR (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationListIR::setter_insertAtIndex (const GALGAS_abstractGenerationIR inOperand0,
                                                    const GALGAS_uint inInsertionIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_generationListIR (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationListIR::setter_removeAtIndex (GALGAS_abstractGenerationIR & outOperand0,
                                                    const GALGAS_uint inRemoveIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_generationListIR * p = (cCollectionElement_generationListIR *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_generationListIR) ;
      outOperand0 = p->mObject.mProperty_mGeneration ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationListIR::setter_popFirst (GALGAS_abstractGenerationIR & outOperand0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_generationListIR * p = (cCollectionElement_generationListIR *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_generationListIR) ;
    outOperand0 = p->mObject.mProperty_mGeneration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationListIR::setter_popLast (GALGAS_abstractGenerationIR & outOperand0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_generationListIR * p = (cCollectionElement_generationListIR *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_generationListIR) ;
    outOperand0 = p->mObject.mProperty_mGeneration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationListIR::method_first (GALGAS_abstractGenerationIR & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_generationListIR * p = (cCollectionElement_generationListIR *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_generationListIR) ;
    outOperand0 = p->mObject.mProperty_mGeneration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationListIR::method_last (GALGAS_abstractGenerationIR & outOperand0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_generationListIR * p = (cCollectionElement_generationListIR *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_generationListIR) ;
    outOperand0 = p->mObject.mProperty_mGeneration ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationListIR GALGAS_generationListIR::add_operation (const GALGAS_generationListIR & inOperand,
                                                                C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_generationListIR result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationListIR GALGAS_generationListIR::getter_subListWithRange (const GALGAS_range & inRange,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_generationListIR result = GALGAS_generationListIR::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationListIR GALGAS_generationListIR::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_generationListIR result = GALGAS_generationListIR::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationListIR GALGAS_generationListIR::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_generationListIR result = GALGAS_generationListIR::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationListIR::plusAssign_operation (const GALGAS_generationListIR inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractGenerationIR GALGAS_generationListIR::getter_mGenerationAtIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_generationListIR * p = (cCollectionElement_generationListIR *) attributes.ptr () ;
  GALGAS_abstractGenerationIR result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_generationListIR) ;
    result = p->mObject.mProperty_mGeneration ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_generationListIR::cEnumerator_generationListIR (const GALGAS_generationListIR & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationListIR_2D_element cEnumerator_generationListIR::current (LOCATION_ARGS) const {
  const cCollectionElement_generationListIR * p = (const cCollectionElement_generationListIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_generationListIR) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractGenerationIR cEnumerator_generationListIR::current_mGeneration (LOCATION_ARGS) const {
  const cCollectionElement_generationListIR * p = (const cCollectionElement_generationListIR *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_generationListIR) ;
  return p->mObject.mProperty_mGeneration ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @generationListIR type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_generationListIR ("generationListIR",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_generationListIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_generationListIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_generationListIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_generationListIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationListIR GALGAS_generationListIR::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_generationListIR result ;
  const GALGAS_generationListIR * p = (const GALGAS_generationListIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_generationListIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("generationListIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension method '@instructionListIR appendNOP'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendNOP (GALGAS_instructionListIR & ioObject,
                                C_Compiler * /* inCompiler */
                                COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_nopIR::constructor_new (SOURCE_FILE ("intermediate-nop.galgas", 3))  COMMA_SOURCE_FILE ("intermediate-nop.galgas", 3)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_nopIR::dynamicObjectCompare (const acPtr_class * /* inOperandPtr */) const {
  return kOperandEqual ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_nopIR::objectCompare (const GALGAS_nopIR & inOperand) const {
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

GALGAS_nopIR::GALGAS_nopIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_nopIR GALGAS_nopIR::constructor_default (LOCATION_ARGS) {
  return GALGAS_nopIR::constructor_new (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_nopIR::GALGAS_nopIR (const cPtr_nopIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_nopIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_nopIR GALGAS_nopIR::constructor_new (LOCATION_ARGS) {
  GALGAS_nopIR result ;
  macroMyNew (result.mObjectPtr, cPtr_nopIR (THERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                           Pointer class for @nopIR class                                            *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_nopIR::cPtr_nopIR (LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_nopIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_nopIR ;
}

void cPtr_nopIR::description (C_String & ioString,
                              const int32_t /* inIndentation */) const {
  ioString << "[@nopIR]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_nopIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_nopIR (THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                     @nopIR type                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_nopIR ("nopIR",
                              & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_nopIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_nopIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_nopIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_nopIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_nopIR GALGAS_nopIR::extractObject (const GALGAS_object & inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_nopIR result ;
  const GALGAS_nopIR * p = (const GALGAS_nopIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_nopIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("nopIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@instructionListIR appendExtend'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendExtend (GALGAS_instructionListIR & ioObject,
                                   const GALGAS_objectIR constinArgument_inResult,
                                   const GALGAS_objectIR constinArgument_inSource,
                                   C_Compiler * /* inCompiler */
                                   COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_extendIR::constructor_new (constinArgument_inResult, constinArgument_inSource  COMMA_SOURCE_FILE ("intermediate-extend.galgas", 6))  COMMA_SOURCE_FILE ("intermediate-extend.galgas", 6)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_extendIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_extendIR * p = (const cPtr_extendIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_extendIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mResult.objectCompare (p->mProperty_mResult) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mSource.objectCompare (p->mProperty_mSource) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_extendIR::objectCompare (const GALGAS_extendIR & inOperand) const {
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

GALGAS_extendIR::GALGAS_extendIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extendIR::GALGAS_extendIR (const cPtr_extendIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_extendIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extendIR GALGAS_extendIR::constructor_new (const GALGAS_objectIR & inAttribute_mResult,
                                                  const GALGAS_objectIR & inAttribute_mSource
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_extendIR result ;
  if (inAttribute_mResult.isValid () && inAttribute_mSource.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_extendIR (inAttribute_mResult, inAttribute_mSource COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_extendIR::getter_mResult (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_extendIR * p = (const cPtr_extendIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_extendIR) ;
    result = p->mProperty_mResult ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_extendIR::getter_mResult (UNUSED_LOCATION_ARGS) const {
  return mProperty_mResult ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_extendIR::getter_mSource (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_extendIR * p = (const cPtr_extendIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_extendIR) ;
    result = p->mProperty_mSource ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_extendIR::getter_mSource (UNUSED_LOCATION_ARGS) const {
  return mProperty_mSource ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @extendIR class                                          *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_extendIR::cPtr_extendIR (const GALGAS_objectIR & in_mResult,
                              const GALGAS_objectIR & in_mSource
                              COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mResult (in_mResult),
mProperty_mSource (in_mSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_extendIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_extendIR ;
}

void cPtr_extendIR::description (C_String & ioString,
                                 const int32_t inIndentation) const {
  ioString << "[@extendIR:" ;
  mProperty_mResult.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mSource.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_extendIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_extendIR (mProperty_mResult, mProperty_mSource COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @extendIR type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_extendIR ("extendIR",
                                 & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_extendIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_extendIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_extendIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_extendIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extendIR GALGAS_extendIR::extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_extendIR result ;
  const GALGAS_extendIR * p = (const GALGAS_extendIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_extendIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("extendIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension method '@instructionListIR appendTrunc'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendTrunc (GALGAS_instructionListIR & ioObject,
                                  const GALGAS_objectIR constinArgument_inResult,
                                  const GALGAS_objectIR constinArgument_inSource,
                                  C_Compiler * /* inCompiler */
                                  COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_truncIR::constructor_new (constinArgument_inResult, constinArgument_inSource  COMMA_SOURCE_FILE ("intermediate-trunc.galgas", 6))  COMMA_SOURCE_FILE ("intermediate-trunc.galgas", 6)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_truncIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_truncIR * p = (const cPtr_truncIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_truncIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mResult.objectCompare (p->mProperty_mResult) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mSource.objectCompare (p->mProperty_mSource) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_truncIR::objectCompare (const GALGAS_truncIR & inOperand) const {
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

GALGAS_truncIR::GALGAS_truncIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_truncIR::GALGAS_truncIR (const cPtr_truncIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_truncIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_truncIR GALGAS_truncIR::constructor_new (const GALGAS_objectIR & inAttribute_mResult,
                                                const GALGAS_objectIR & inAttribute_mSource
                                                COMMA_LOCATION_ARGS) {
  GALGAS_truncIR result ;
  if (inAttribute_mResult.isValid () && inAttribute_mSource.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_truncIR (inAttribute_mResult, inAttribute_mSource COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_truncIR::getter_mResult (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_truncIR * p = (const cPtr_truncIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_truncIR) ;
    result = p->mProperty_mResult ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_truncIR::getter_mResult (UNUSED_LOCATION_ARGS) const {
  return mProperty_mResult ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_truncIR::getter_mSource (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_truncIR * p = (const cPtr_truncIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_truncIR) ;
    result = p->mProperty_mSource ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_truncIR::getter_mSource (UNUSED_LOCATION_ARGS) const {
  return mProperty_mSource ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @truncIR class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_truncIR::cPtr_truncIR (const GALGAS_objectIR & in_mResult,
                            const GALGAS_objectIR & in_mSource
                            COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mResult (in_mResult),
mProperty_mSource (in_mSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_truncIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_truncIR ;
}

void cPtr_truncIR::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@truncIR:" ;
  mProperty_mResult.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mSource.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_truncIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_truncIR (mProperty_mResult, mProperty_mSource COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @truncIR type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_truncIR ("truncIR",
                                & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_truncIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_truncIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_truncIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_truncIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_truncIR GALGAS_truncIR::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_truncIR result ;
  const GALGAS_truncIR * p = (const GALGAS_truncIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_truncIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("truncIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension method '@instructionListIR appendShiftLeft'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendShiftLeft (GALGAS_instructionListIR & ioObject,
                                      const GALGAS_objectIR constinArgument_inResult,
                                      const GALGAS_objectIR constinArgument_inSource,
                                      const GALGAS_uint constinArgument_inShiftAmount,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_leftShiftIR::constructor_new (constinArgument_inResult, constinArgument_inSource, constinArgument_inShiftAmount  COMMA_SOURCE_FILE ("intermediate-shift-left.galgas", 7))  COMMA_SOURCE_FILE ("intermediate-shift-left.galgas", 7)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_leftShiftIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_leftShiftIR * p = (const cPtr_leftShiftIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_leftShiftIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mResult.objectCompare (p->mProperty_mResult) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mSource.objectCompare (p->mProperty_mSource) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mShiftAmount.objectCompare (p->mProperty_mShiftAmount) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_leftShiftIR::objectCompare (const GALGAS_leftShiftIR & inOperand) const {
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

GALGAS_leftShiftIR::GALGAS_leftShiftIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_leftShiftIR::GALGAS_leftShiftIR (const cPtr_leftShiftIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_leftShiftIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_leftShiftIR GALGAS_leftShiftIR::constructor_new (const GALGAS_objectIR & inAttribute_mResult,
                                                        const GALGAS_objectIR & inAttribute_mSource,
                                                        const GALGAS_uint & inAttribute_mShiftAmount
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_leftShiftIR result ;
  if (inAttribute_mResult.isValid () && inAttribute_mSource.isValid () && inAttribute_mShiftAmount.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_leftShiftIR (inAttribute_mResult, inAttribute_mSource, inAttribute_mShiftAmount COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_leftShiftIR::getter_mResult (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_leftShiftIR * p = (const cPtr_leftShiftIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_leftShiftIR) ;
    result = p->mProperty_mResult ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_leftShiftIR::getter_mResult (UNUSED_LOCATION_ARGS) const {
  return mProperty_mResult ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_leftShiftIR::getter_mSource (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_leftShiftIR * p = (const cPtr_leftShiftIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_leftShiftIR) ;
    result = p->mProperty_mSource ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_leftShiftIR::getter_mSource (UNUSED_LOCATION_ARGS) const {
  return mProperty_mSource ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_leftShiftIR::getter_mShiftAmount (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_leftShiftIR * p = (const cPtr_leftShiftIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_leftShiftIR) ;
    result = p->mProperty_mShiftAmount ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_leftShiftIR::getter_mShiftAmount (UNUSED_LOCATION_ARGS) const {
  return mProperty_mShiftAmount ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @leftShiftIR class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_leftShiftIR::cPtr_leftShiftIR (const GALGAS_objectIR & in_mResult,
                                    const GALGAS_objectIR & in_mSource,
                                    const GALGAS_uint & in_mShiftAmount
                                    COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mResult (in_mResult),
mProperty_mSource (in_mSource),
mProperty_mShiftAmount (in_mShiftAmount) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_leftShiftIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_leftShiftIR ;
}

void cPtr_leftShiftIR::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "[@leftShiftIR:" ;
  mProperty_mResult.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mSource.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mShiftAmount.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_leftShiftIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_leftShiftIR (mProperty_mResult, mProperty_mSource, mProperty_mShiftAmount COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @leftShiftIR type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_leftShiftIR ("leftShiftIR",
                                    & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_leftShiftIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_leftShiftIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_leftShiftIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_leftShiftIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_leftShiftIR GALGAS_leftShiftIR::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_leftShiftIR result ;
  const GALGAS_leftShiftIR * p = (const GALGAS_leftShiftIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_leftShiftIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("leftShiftIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension method '@instructionListIR appendBinaryOperation'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendBinaryOperation (GALGAS_instructionListIR & ioObject,
                                            const GALGAS_objectIR constinArgument_inTarget,
                                            const GALGAS_PLMType constinArgument_inOperandType,
                                            const GALGAS_location constinArgument_inLocation,
                                            const GALGAS_objectIR constinArgument_inLeft,
                                            const GALGAS_llvmBinaryOperation constinArgument_inOperation,
                                            const GALGAS_objectIR constinArgument_inRight,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_binaryOperationIR::constructor_new (constinArgument_inTarget, constinArgument_inOperandType, constinArgument_inLeft, constinArgument_inOperation, constinArgument_inRight, constinArgument_inLocation  COMMA_SOURCE_FILE ("intermediate-binary-operation.galgas", 51))  COMMA_SOURCE_FILE ("intermediate-binary-operation.galgas", 51)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension method '@instructionListIR appendShortCircuitAndOperation'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendShortCircuitAndOperation (GALGAS_instructionListIR & ioObject,
                                                     const GALGAS_objectIR constinArgument_inTargetOperand,
                                                     const GALGAS_objectIR constinArgument_inLeftOperand,
                                                     const GALGAS_instructionListIR constinArgument_inLeftInstructionList,
                                                     const GALGAS_objectIR constinArgument_inRightOperand,
                                                     const GALGAS_instructionListIR constinArgument_inRightInstructionList,
                                                     const GALGAS_location constinArgument_inLocation,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_shortCircuitAndOperationIR::constructor_new (constinArgument_inTargetOperand, constinArgument_inLeftOperand, constinArgument_inLeftInstructionList, constinArgument_inRightOperand, constinArgument_inRightInstructionList, constinArgument_inLocation  COMMA_SOURCE_FILE ("intermediate-short-circuit-and.galgas", 11))  COMMA_SOURCE_FILE ("intermediate-short-circuit-and.galgas", 11)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_shortCircuitAndOperationIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mTargetOperand.objectCompare (p->mProperty_mTargetOperand) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mLeftOperand.objectCompare (p->mProperty_mLeftOperand) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mLeftInstructionList.objectCompare (p->mProperty_mLeftInstructionList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mRightOperand.objectCompare (p->mProperty_mRightOperand) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mRightInstructionList.objectCompare (p->mProperty_mRightInstructionList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mLocation.objectCompare (p->mProperty_mLocation) ;
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

GALGAS_shortCircuitAndOperationIR GALGAS_shortCircuitAndOperationIR::constructor_new (const GALGAS_objectIR & inAttribute_mTargetOperand,
                                                                                      const GALGAS_objectIR & inAttribute_mLeftOperand,
                                                                                      const GALGAS_instructionListIR & inAttribute_mLeftInstructionList,
                                                                                      const GALGAS_objectIR & inAttribute_mRightOperand,
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

GALGAS_objectIR GALGAS_shortCircuitAndOperationIR::getter_mTargetOperand (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
    result = p->mProperty_mTargetOperand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_shortCircuitAndOperationIR::getter_mTargetOperand (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTargetOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_shortCircuitAndOperationIR::getter_mLeftOperand (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
    result = p->mProperty_mLeftOperand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_shortCircuitAndOperationIR::getter_mLeftOperand (UNUSED_LOCATION_ARGS) const {
  return mProperty_mLeftOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_shortCircuitAndOperationIR::getter_mLeftInstructionList (UNUSED_LOCATION_ARGS) const {
  GALGAS_instructionListIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
    result = p->mProperty_mLeftInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cPtr_shortCircuitAndOperationIR::getter_mLeftInstructionList (UNUSED_LOCATION_ARGS) const {
  return mProperty_mLeftInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_shortCircuitAndOperationIR::getter_mRightOperand (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
    result = p->mProperty_mRightOperand ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_shortCircuitAndOperationIR::getter_mRightOperand (UNUSED_LOCATION_ARGS) const {
  return mProperty_mRightOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_shortCircuitAndOperationIR::getter_mRightInstructionList (UNUSED_LOCATION_ARGS) const {
  GALGAS_instructionListIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
    result = p->mProperty_mRightInstructionList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR cPtr_shortCircuitAndOperationIR::getter_mRightInstructionList (UNUSED_LOCATION_ARGS) const {
  return mProperty_mRightInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_shortCircuitAndOperationIR::getter_mLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_shortCircuitAndOperationIR * p = (const cPtr_shortCircuitAndOperationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_shortCircuitAndOperationIR) ;
    result = p->mProperty_mLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_shortCircuitAndOperationIR::getter_mLocation (UNUSED_LOCATION_ARGS) const {
  return mProperty_mLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @shortCircuitAndOperationIR class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_shortCircuitAndOperationIR::cPtr_shortCircuitAndOperationIR (const GALGAS_objectIR & in_mTargetOperand,
                                                                  const GALGAS_objectIR & in_mLeftOperand,
                                                                  const GALGAS_instructionListIR & in_mLeftInstructionList,
                                                                  const GALGAS_objectIR & in_mRightOperand,
                                                                  const GALGAS_instructionListIR & in_mRightInstructionList,
                                                                  const GALGAS_location & in_mLocation
                                                                  COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mTargetOperand (in_mTargetOperand),
mProperty_mLeftOperand (in_mLeftOperand),
mProperty_mLeftInstructionList (in_mLeftInstructionList),
mProperty_mRightOperand (in_mRightOperand),
mProperty_mRightInstructionList (in_mRightInstructionList),
mProperty_mLocation (in_mLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_shortCircuitAndOperationIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_shortCircuitAndOperationIR ;
}

void cPtr_shortCircuitAndOperationIR::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@shortCircuitAndOperationIR:" ;
  mProperty_mTargetOperand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mLeftOperand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mLeftInstructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mRightOperand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mRightInstructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mLocation.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_shortCircuitAndOperationIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_shortCircuitAndOperationIR (mProperty_mTargetOperand, mProperty_mLeftOperand, mProperty_mLeftInstructionList, mProperty_mRightOperand, mProperty_mRightInstructionList, mProperty_mLocation COMMA_THERE)) ;
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
//                                                                                                                     *
//                    Extension method '@instructionListIR appendLoadVolatileRegisterWithSubscript'                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendLoadVolatileRegisterWithSubscript (GALGAS_instructionListIR & ioObject,
                                                              const GALGAS_objectIR constinArgument_inTarget,
                                                              const GALGAS_objectIR constinArgument_inIndexResult,
                                                              const GALGAS_bigint constinArgument_inAddress,
                                                              const GALGAS_bigint constinArgument_inElementArraySize,
                                                              C_Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_loadRegisterWithSubscriptIR::constructor_new (constinArgument_inTarget, constinArgument_inIndexResult, constinArgument_inAddress, constinArgument_inElementArraySize  COMMA_SOURCE_FILE ("intermediate-load-control-register-with-subscript.galgas", 8))  COMMA_SOURCE_FILE ("intermediate-load-control-register-with-subscript.galgas", 8)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_loadRegisterWithSubscriptIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_loadRegisterWithSubscriptIR * p = (const cPtr_loadRegisterWithSubscriptIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_loadRegisterWithSubscriptIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mTarget.objectCompare (p->mProperty_mTarget) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mIndexResult.objectCompare (p->mProperty_mIndexResult) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mRegisterAddress.objectCompare (p->mProperty_mRegisterAddress) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mElementArraySize.objectCompare (p->mProperty_mElementArraySize) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_loadRegisterWithSubscriptIR::objectCompare (const GALGAS_loadRegisterWithSubscriptIR & inOperand) const {
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

GALGAS_loadRegisterWithSubscriptIR::GALGAS_loadRegisterWithSubscriptIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadRegisterWithSubscriptIR::GALGAS_loadRegisterWithSubscriptIR (const cPtr_loadRegisterWithSubscriptIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_loadRegisterWithSubscriptIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadRegisterWithSubscriptIR GALGAS_loadRegisterWithSubscriptIR::constructor_new (const GALGAS_objectIR & inAttribute_mTarget,
                                                                                        const GALGAS_objectIR & inAttribute_mIndexResult,
                                                                                        const GALGAS_bigint & inAttribute_mRegisterAddress,
                                                                                        const GALGAS_bigint & inAttribute_mElementArraySize
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_loadRegisterWithSubscriptIR result ;
  if (inAttribute_mTarget.isValid () && inAttribute_mIndexResult.isValid () && inAttribute_mRegisterAddress.isValid () && inAttribute_mElementArraySize.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_loadRegisterWithSubscriptIR (inAttribute_mTarget, inAttribute_mIndexResult, inAttribute_mRegisterAddress, inAttribute_mElementArraySize COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_loadRegisterWithSubscriptIR::getter_mTarget (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadRegisterWithSubscriptIR * p = (const cPtr_loadRegisterWithSubscriptIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadRegisterWithSubscriptIR) ;
    result = p->mProperty_mTarget ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_loadRegisterWithSubscriptIR::getter_mTarget (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTarget ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_loadRegisterWithSubscriptIR::getter_mIndexResult (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadRegisterWithSubscriptIR * p = (const cPtr_loadRegisterWithSubscriptIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadRegisterWithSubscriptIR) ;
    result = p->mProperty_mIndexResult ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_loadRegisterWithSubscriptIR::getter_mIndexResult (UNUSED_LOCATION_ARGS) const {
  return mProperty_mIndexResult ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_loadRegisterWithSubscriptIR::getter_mRegisterAddress (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadRegisterWithSubscriptIR * p = (const cPtr_loadRegisterWithSubscriptIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadRegisterWithSubscriptIR) ;
    result = p->mProperty_mRegisterAddress ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_loadRegisterWithSubscriptIR::getter_mRegisterAddress (UNUSED_LOCATION_ARGS) const {
  return mProperty_mRegisterAddress ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_loadRegisterWithSubscriptIR::getter_mElementArraySize (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadRegisterWithSubscriptIR * p = (const cPtr_loadRegisterWithSubscriptIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadRegisterWithSubscriptIR) ;
    result = p->mProperty_mElementArraySize ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_loadRegisterWithSubscriptIR::getter_mElementArraySize (UNUSED_LOCATION_ARGS) const {
  return mProperty_mElementArraySize ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                Pointer class for @loadRegisterWithSubscriptIR class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_loadRegisterWithSubscriptIR::cPtr_loadRegisterWithSubscriptIR (const GALGAS_objectIR & in_mTarget,
                                                                    const GALGAS_objectIR & in_mIndexResult,
                                                                    const GALGAS_bigint & in_mRegisterAddress,
                                                                    const GALGAS_bigint & in_mElementArraySize
                                                                    COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mTarget (in_mTarget),
mProperty_mIndexResult (in_mIndexResult),
mProperty_mRegisterAddress (in_mRegisterAddress),
mProperty_mElementArraySize (in_mElementArraySize) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_loadRegisterWithSubscriptIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_loadRegisterWithSubscriptIR ;
}

void cPtr_loadRegisterWithSubscriptIR::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@loadRegisterWithSubscriptIR:" ;
  mProperty_mTarget.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mIndexResult.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mRegisterAddress.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mElementArraySize.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_loadRegisterWithSubscriptIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_loadRegisterWithSubscriptIR (mProperty_mTarget, mProperty_mIndexResult, mProperty_mRegisterAddress, mProperty_mElementArraySize COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @loadRegisterWithSubscriptIR type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_loadRegisterWithSubscriptIR ("loadRegisterWithSubscriptIR",
                                                    & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_loadRegisterWithSubscriptIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_loadRegisterWithSubscriptIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_loadRegisterWithSubscriptIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_loadRegisterWithSubscriptIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadRegisterWithSubscriptIR GALGAS_loadRegisterWithSubscriptIR::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_loadRegisterWithSubscriptIR result ;
  const GALGAS_loadRegisterWithSubscriptIR * p = (const GALGAS_loadRegisterWithSubscriptIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_loadRegisterWithSubscriptIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("loadRegisterWithSubscriptIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//               Extension method '@instructionListIR appendComputeVolatileRegisterAddressWithSubscript'               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendComputeVolatileRegisterAddressWithSubscript (GALGAS_instructionListIR & ioObject,
                                                                        const GALGAS_objectIR constinArgument_inTarget,
                                                                        const GALGAS_objectIR constinArgument_inIndexResult,
                                                                        const GALGAS_bigint constinArgument_inAddress,
                                                                        const GALGAS_bigint constinArgument_inElementArraySize,
                                                                        C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_ComputeRegisterAddressWithSubscriptIR::constructor_new (constinArgument_inTarget, constinArgument_inIndexResult, constinArgument_inAddress, constinArgument_inElementArraySize  COMMA_SOURCE_FILE ("intermediate-compute-control-register-address-with-subscript.galgas", 8))  COMMA_SOURCE_FILE ("intermediate-compute-control-register-address-with-subscript.galgas", 8)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_ComputeRegisterAddressWithSubscriptIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_ComputeRegisterAddressWithSubscriptIR * p = (const cPtr_ComputeRegisterAddressWithSubscriptIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_ComputeRegisterAddressWithSubscriptIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mTarget.objectCompare (p->mProperty_mTarget) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mIndexResult.objectCompare (p->mProperty_mIndexResult) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mRegisterAddress.objectCompare (p->mProperty_mRegisterAddress) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mElementArraySize.objectCompare (p->mProperty_mElementArraySize) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_ComputeRegisterAddressWithSubscriptIR::objectCompare (const GALGAS_ComputeRegisterAddressWithSubscriptIR & inOperand) const {
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

GALGAS_ComputeRegisterAddressWithSubscriptIR::GALGAS_ComputeRegisterAddressWithSubscriptIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ComputeRegisterAddressWithSubscriptIR::GALGAS_ComputeRegisterAddressWithSubscriptIR (const cPtr_ComputeRegisterAddressWithSubscriptIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_ComputeRegisterAddressWithSubscriptIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ComputeRegisterAddressWithSubscriptIR GALGAS_ComputeRegisterAddressWithSubscriptIR::constructor_new (const GALGAS_objectIR & inAttribute_mTarget,
                                                                                                            const GALGAS_objectIR & inAttribute_mIndexResult,
                                                                                                            const GALGAS_bigint & inAttribute_mRegisterAddress,
                                                                                                            const GALGAS_bigint & inAttribute_mElementArraySize
                                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_ComputeRegisterAddressWithSubscriptIR result ;
  if (inAttribute_mTarget.isValid () && inAttribute_mIndexResult.isValid () && inAttribute_mRegisterAddress.isValid () && inAttribute_mElementArraySize.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_ComputeRegisterAddressWithSubscriptIR (inAttribute_mTarget, inAttribute_mIndexResult, inAttribute_mRegisterAddress, inAttribute_mElementArraySize COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_ComputeRegisterAddressWithSubscriptIR::getter_mTarget (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_ComputeRegisterAddressWithSubscriptIR * p = (const cPtr_ComputeRegisterAddressWithSubscriptIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ComputeRegisterAddressWithSubscriptIR) ;
    result = p->mProperty_mTarget ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_ComputeRegisterAddressWithSubscriptIR::getter_mTarget (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTarget ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_ComputeRegisterAddressWithSubscriptIR::getter_mIndexResult (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_ComputeRegisterAddressWithSubscriptIR * p = (const cPtr_ComputeRegisterAddressWithSubscriptIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ComputeRegisterAddressWithSubscriptIR) ;
    result = p->mProperty_mIndexResult ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_ComputeRegisterAddressWithSubscriptIR::getter_mIndexResult (UNUSED_LOCATION_ARGS) const {
  return mProperty_mIndexResult ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_ComputeRegisterAddressWithSubscriptIR::getter_mRegisterAddress (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_ComputeRegisterAddressWithSubscriptIR * p = (const cPtr_ComputeRegisterAddressWithSubscriptIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ComputeRegisterAddressWithSubscriptIR) ;
    result = p->mProperty_mRegisterAddress ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_ComputeRegisterAddressWithSubscriptIR::getter_mRegisterAddress (UNUSED_LOCATION_ARGS) const {
  return mProperty_mRegisterAddress ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_ComputeRegisterAddressWithSubscriptIR::getter_mElementArraySize (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_ComputeRegisterAddressWithSubscriptIR * p = (const cPtr_ComputeRegisterAddressWithSubscriptIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_ComputeRegisterAddressWithSubscriptIR) ;
    result = p->mProperty_mElementArraySize ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_ComputeRegisterAddressWithSubscriptIR::getter_mElementArraySize (UNUSED_LOCATION_ARGS) const {
  return mProperty_mElementArraySize ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                           Pointer class for @ComputeRegisterAddressWithSubscriptIR class                            *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_ComputeRegisterAddressWithSubscriptIR::cPtr_ComputeRegisterAddressWithSubscriptIR (const GALGAS_objectIR & in_mTarget,
                                                                                        const GALGAS_objectIR & in_mIndexResult,
                                                                                        const GALGAS_bigint & in_mRegisterAddress,
                                                                                        const GALGAS_bigint & in_mElementArraySize
                                                                                        COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mTarget (in_mTarget),
mProperty_mIndexResult (in_mIndexResult),
mProperty_mRegisterAddress (in_mRegisterAddress),
mProperty_mElementArraySize (in_mElementArraySize) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_ComputeRegisterAddressWithSubscriptIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ComputeRegisterAddressWithSubscriptIR ;
}

void cPtr_ComputeRegisterAddressWithSubscriptIR::description (C_String & ioString,
                                                              const int32_t inIndentation) const {
  ioString << "[@ComputeRegisterAddressWithSubscriptIR:" ;
  mProperty_mTarget.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mIndexResult.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mRegisterAddress.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mElementArraySize.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_ComputeRegisterAddressWithSubscriptIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_ComputeRegisterAddressWithSubscriptIR (mProperty_mTarget, mProperty_mIndexResult, mProperty_mRegisterAddress, mProperty_mElementArraySize COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     @ComputeRegisterAddressWithSubscriptIR type                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ComputeRegisterAddressWithSubscriptIR ("ComputeRegisterAddressWithSubscriptIR",
                                                              & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_ComputeRegisterAddressWithSubscriptIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ComputeRegisterAddressWithSubscriptIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_ComputeRegisterAddressWithSubscriptIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ComputeRegisterAddressWithSubscriptIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ComputeRegisterAddressWithSubscriptIR GALGAS_ComputeRegisterAddressWithSubscriptIR::extractObject (const GALGAS_object & inObject,
                                                                                                          C_Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_ComputeRegisterAddressWithSubscriptIR result ;
  const GALGAS_ComputeRegisterAddressWithSubscriptIR * p = (const GALGAS_ComputeRegisterAddressWithSubscriptIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ComputeRegisterAddressWithSubscriptIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ComputeRegisterAddressWithSubscriptIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Extension method '@instructionListIR appendLoadVolatileRegister'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendLoadVolatileRegister (GALGAS_instructionListIR & ioObject,
                                                 const GALGAS_objectIR constinArgument_inTargetValue,
                                                 const GALGAS_bigint constinArgument_inAddress,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_loadRegisterIR::constructor_new (constinArgument_inTargetValue, constinArgument_inAddress  COMMA_SOURCE_FILE ("intermediate-load-volatile-register.galgas", 6))  COMMA_SOURCE_FILE ("intermediate-load-volatile-register.galgas", 6)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_loadRegisterIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_loadRegisterIR * p = (const cPtr_loadRegisterIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_loadRegisterIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mTargetValue.objectCompare (p->mProperty_mTargetValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mRegisterAddress.objectCompare (p->mProperty_mRegisterAddress) ;
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

GALGAS_loadRegisterIR GALGAS_loadRegisterIR::constructor_new (const GALGAS_objectIR & inAttribute_mTargetValue,
                                                              const GALGAS_bigint & inAttribute_mRegisterAddress
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_loadRegisterIR result ;
  if (inAttribute_mTargetValue.isValid () && inAttribute_mRegisterAddress.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_loadRegisterIR (inAttribute_mTargetValue, inAttribute_mRegisterAddress COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_loadRegisterIR::getter_mTargetValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadRegisterIR * p = (const cPtr_loadRegisterIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadRegisterIR) ;
    result = p->mProperty_mTargetValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_loadRegisterIR::getter_mTargetValue (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTargetValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_loadRegisterIR::getter_mRegisterAddress (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadRegisterIR * p = (const cPtr_loadRegisterIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadRegisterIR) ;
    result = p->mProperty_mRegisterAddress ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_loadRegisterIR::getter_mRegisterAddress (UNUSED_LOCATION_ARGS) const {
  return mProperty_mRegisterAddress ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @loadRegisterIR class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_loadRegisterIR::cPtr_loadRegisterIR (const GALGAS_objectIR & in_mTargetValue,
                                          const GALGAS_bigint & in_mRegisterAddress
                                          COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mTargetValue (in_mTargetValue),
mProperty_mRegisterAddress (in_mRegisterAddress) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_loadRegisterIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_loadRegisterIR ;
}

void cPtr_loadRegisterIR::description (C_String & ioString,
                                       const int32_t inIndentation) const {
  ioString << "[@loadRegisterIR:" ;
  mProperty_mTargetValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mRegisterAddress.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_loadRegisterIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_loadRegisterIR (mProperty_mTargetValue, mProperty_mRegisterAddress COMMA_THERE)) ;
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
//                                                                                                                     *
//                            Extension method '@instructionListIR appendLoadFromReference'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendLoadFromReference (GALGAS_instructionListIR & ioObject,
                                              const GALGAS_objectIR constinArgument_inTargetValue,
                                              const GALGAS_string constinArgument_inLLVMName,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_loadFromReferenceIR::constructor_new (constinArgument_inTargetValue, constinArgument_inLLVMName  COMMA_SOURCE_FILE ("intermediate-load-from-reference.galgas", 6))  COMMA_SOURCE_FILE ("intermediate-load-from-reference.galgas", 6)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_loadFromReferenceIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_loadFromReferenceIR * p = (const cPtr_loadFromReferenceIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_loadFromReferenceIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mTargetValue.objectCompare (p->mProperty_mTargetValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mLLVMName.objectCompare (p->mProperty_mLLVMName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_loadFromReferenceIR::objectCompare (const GALGAS_loadFromReferenceIR & inOperand) const {
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

GALGAS_loadFromReferenceIR::GALGAS_loadFromReferenceIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadFromReferenceIR::GALGAS_loadFromReferenceIR (const cPtr_loadFromReferenceIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_loadFromReferenceIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadFromReferenceIR GALGAS_loadFromReferenceIR::constructor_new (const GALGAS_objectIR & inAttribute_mTargetValue,
                                                                        const GALGAS_string & inAttribute_mLLVMName
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_loadFromReferenceIR result ;
  if (inAttribute_mTargetValue.isValid () && inAttribute_mLLVMName.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_loadFromReferenceIR (inAttribute_mTargetValue, inAttribute_mLLVMName COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_loadFromReferenceIR::getter_mTargetValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadFromReferenceIR * p = (const cPtr_loadFromReferenceIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadFromReferenceIR) ;
    result = p->mProperty_mTargetValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_loadFromReferenceIR::getter_mTargetValue (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTargetValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_loadFromReferenceIR::getter_mLLVMName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_loadFromReferenceIR * p = (const cPtr_loadFromReferenceIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_loadFromReferenceIR) ;
    result = p->mProperty_mLLVMName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_loadFromReferenceIR::getter_mLLVMName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mLLVMName ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @loadFromReferenceIR class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_loadFromReferenceIR::cPtr_loadFromReferenceIR (const GALGAS_objectIR & in_mTargetValue,
                                                    const GALGAS_string & in_mLLVMName
                                                    COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mTargetValue (in_mTargetValue),
mProperty_mLLVMName (in_mLLVMName) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_loadFromReferenceIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_loadFromReferenceIR ;
}

void cPtr_loadFromReferenceIR::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@loadFromReferenceIR:" ;
  mProperty_mTargetValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mLLVMName.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_loadFromReferenceIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_loadFromReferenceIR (mProperty_mTargetValue, mProperty_mLLVMName COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @loadFromReferenceIR type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_loadFromReferenceIR ("loadFromReferenceIR",
                                            & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_loadFromReferenceIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_loadFromReferenceIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_loadFromReferenceIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_loadFromReferenceIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_loadFromReferenceIR GALGAS_loadFromReferenceIR::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_loadFromReferenceIR result ;
  const GALGAS_loadFromReferenceIR * p = (const GALGAS_loadFromReferenceIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_loadFromReferenceIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("loadFromReferenceIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                Extension method '@instructionListIR appendComputeSubscriptedVolatileRegisterAddress'                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendComputeSubscriptedVolatileRegisterAddress (GALGAS_instructionListIR & ioObject,
                                                                      const GALGAS_string constinArgument_inLLVMResultVarName,
                                                                      const GALGAS_objectIR constinArgument_inIndexIR,
                                                                      const GALGAS_bigint constinArgument_inAddress,
                                                                      const GALGAS_uint constinArgument_inElementSize,
                                                                      C_Compiler * /* inCompiler */
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_computeSubscriptedVolatileRegisterAddress::constructor_new (constinArgument_inLLVMResultVarName, constinArgument_inIndexIR, constinArgument_inAddress, constinArgument_inElementSize  COMMA_SOURCE_FILE ("intermediate-compute-subscripted-volatile-register-address.galgas", 8))  COMMA_SOURCE_FILE ("intermediate-compute-subscripted-volatile-register-address.galgas", 8)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_computeSubscriptedVolatileRegisterAddress::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_computeSubscriptedVolatileRegisterAddress * p = (const cPtr_computeSubscriptedVolatileRegisterAddress *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_computeSubscriptedVolatileRegisterAddress) ;
  if (kOperandEqual == result) {
    result = mProperty_mLLVMResultVarName.objectCompare (p->mProperty_mLLVMResultVarName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mIndexResult.objectCompare (p->mProperty_mIndexResult) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mRegisterBaseAddress.objectCompare (p->mProperty_mRegisterBaseAddress) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mElementSize.objectCompare (p->mProperty_mElementSize) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_computeSubscriptedVolatileRegisterAddress::objectCompare (const GALGAS_computeSubscriptedVolatileRegisterAddress & inOperand) const {
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

GALGAS_computeSubscriptedVolatileRegisterAddress::GALGAS_computeSubscriptedVolatileRegisterAddress (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_computeSubscriptedVolatileRegisterAddress::GALGAS_computeSubscriptedVolatileRegisterAddress (const cPtr_computeSubscriptedVolatileRegisterAddress * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_computeSubscriptedVolatileRegisterAddress) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_computeSubscriptedVolatileRegisterAddress GALGAS_computeSubscriptedVolatileRegisterAddress::constructor_new (const GALGAS_string & inAttribute_mLLVMResultVarName,
                                                                                                                    const GALGAS_objectIR & inAttribute_mIndexResult,
                                                                                                                    const GALGAS_bigint & inAttribute_mRegisterBaseAddress,
                                                                                                                    const GALGAS_uint & inAttribute_mElementSize
                                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_computeSubscriptedVolatileRegisterAddress result ;
  if (inAttribute_mLLVMResultVarName.isValid () && inAttribute_mIndexResult.isValid () && inAttribute_mRegisterBaseAddress.isValid () && inAttribute_mElementSize.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_computeSubscriptedVolatileRegisterAddress (inAttribute_mLLVMResultVarName, inAttribute_mIndexResult, inAttribute_mRegisterBaseAddress, inAttribute_mElementSize COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_computeSubscriptedVolatileRegisterAddress::getter_mLLVMResultVarName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_computeSubscriptedVolatileRegisterAddress * p = (const cPtr_computeSubscriptedVolatileRegisterAddress *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_computeSubscriptedVolatileRegisterAddress) ;
    result = p->mProperty_mLLVMResultVarName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_computeSubscriptedVolatileRegisterAddress::getter_mLLVMResultVarName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mLLVMResultVarName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_computeSubscriptedVolatileRegisterAddress::getter_mIndexResult (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_computeSubscriptedVolatileRegisterAddress * p = (const cPtr_computeSubscriptedVolatileRegisterAddress *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_computeSubscriptedVolatileRegisterAddress) ;
    result = p->mProperty_mIndexResult ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_computeSubscriptedVolatileRegisterAddress::getter_mIndexResult (UNUSED_LOCATION_ARGS) const {
  return mProperty_mIndexResult ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_computeSubscriptedVolatileRegisterAddress::getter_mRegisterBaseAddress (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_computeSubscriptedVolatileRegisterAddress * p = (const cPtr_computeSubscriptedVolatileRegisterAddress *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_computeSubscriptedVolatileRegisterAddress) ;
    result = p->mProperty_mRegisterBaseAddress ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_computeSubscriptedVolatileRegisterAddress::getter_mRegisterBaseAddress (UNUSED_LOCATION_ARGS) const {
  return mProperty_mRegisterBaseAddress ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_computeSubscriptedVolatileRegisterAddress::getter_mElementSize (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_computeSubscriptedVolatileRegisterAddress * p = (const cPtr_computeSubscriptedVolatileRegisterAddress *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_computeSubscriptedVolatileRegisterAddress) ;
    result = p->mProperty_mElementSize ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_computeSubscriptedVolatileRegisterAddress::getter_mElementSize (UNUSED_LOCATION_ARGS) const {
  return mProperty_mElementSize ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         Pointer class for @computeSubscriptedVolatileRegisterAddress class                          *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_computeSubscriptedVolatileRegisterAddress::cPtr_computeSubscriptedVolatileRegisterAddress (const GALGAS_string & in_mLLVMResultVarName,
                                                                                                const GALGAS_objectIR & in_mIndexResult,
                                                                                                const GALGAS_bigint & in_mRegisterBaseAddress,
                                                                                                const GALGAS_uint & in_mElementSize
                                                                                                COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mLLVMResultVarName (in_mLLVMResultVarName),
mProperty_mIndexResult (in_mIndexResult),
mProperty_mRegisterBaseAddress (in_mRegisterBaseAddress),
mProperty_mElementSize (in_mElementSize) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_computeSubscriptedVolatileRegisterAddress::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_computeSubscriptedVolatileRegisterAddress ;
}

void cPtr_computeSubscriptedVolatileRegisterAddress::description (C_String & ioString,
                                                                  const int32_t inIndentation) const {
  ioString << "[@computeSubscriptedVolatileRegisterAddress:" ;
  mProperty_mLLVMResultVarName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mIndexResult.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mRegisterBaseAddress.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mElementSize.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_computeSubscriptedVolatileRegisterAddress::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_computeSubscriptedVolatileRegisterAddress (mProperty_mLLVMResultVarName, mProperty_mIndexResult, mProperty_mRegisterBaseAddress, mProperty_mElementSize COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   @computeSubscriptedVolatileRegisterAddress type                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_computeSubscriptedVolatileRegisterAddress ("computeSubscriptedVolatileRegisterAddress",
                                                                  & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_computeSubscriptedVolatileRegisterAddress::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_computeSubscriptedVolatileRegisterAddress ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_computeSubscriptedVolatileRegisterAddress::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_computeSubscriptedVolatileRegisterAddress (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_computeSubscriptedVolatileRegisterAddress GALGAS_computeSubscriptedVolatileRegisterAddress::extractObject (const GALGAS_object & inObject,
                                                                                                                  C_Compiler * inCompiler
                                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_computeSubscriptedVolatileRegisterAddress result ;
  const GALGAS_computeSubscriptedVolatileRegisterAddress * p = (const GALGAS_computeSubscriptedVolatileRegisterAddress *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_computeSubscriptedVolatileRegisterAddress *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("computeSubscriptedVolatileRegisterAddress", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension method '@instructionListIR appendNoteGlobalVariableAccess'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendNoteGlobalVariableAccess (GALGAS_instructionListIR & ioObject,
                                                     const GALGAS_string constinArgument_inGlobalVarName,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_noteGlobalVariableAccessIR::constructor_new (constinArgument_inGlobalVarName  COMMA_SOURCE_FILE ("intermediate-note-global-variable-access.galgas", 3))  COMMA_SOURCE_FILE ("intermediate-note-global-variable-access.galgas", 3)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_noteGlobalVariableAccessIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_noteGlobalVariableAccessIR * p = (const cPtr_noteGlobalVariableAccessIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_noteGlobalVariableAccessIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mGlobalVarName.objectCompare (p->mProperty_mGlobalVarName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_noteGlobalVariableAccessIR::objectCompare (const GALGAS_noteGlobalVariableAccessIR & inOperand) const {
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

GALGAS_noteGlobalVariableAccessIR::GALGAS_noteGlobalVariableAccessIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noteGlobalVariableAccessIR GALGAS_noteGlobalVariableAccessIR::constructor_default (LOCATION_ARGS) {
  return GALGAS_noteGlobalVariableAccessIR::constructor_new (GALGAS_string::constructor_default (HERE)
                                                             COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noteGlobalVariableAccessIR::GALGAS_noteGlobalVariableAccessIR (const cPtr_noteGlobalVariableAccessIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_noteGlobalVariableAccessIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noteGlobalVariableAccessIR GALGAS_noteGlobalVariableAccessIR::constructor_new (const GALGAS_string & inAttribute_mGlobalVarName
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_noteGlobalVariableAccessIR result ;
  if (inAttribute_mGlobalVarName.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_noteGlobalVariableAccessIR (inAttribute_mGlobalVarName COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_noteGlobalVariableAccessIR::getter_mGlobalVarName (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_noteGlobalVariableAccessIR * p = (const cPtr_noteGlobalVariableAccessIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_noteGlobalVariableAccessIR) ;
    result = p->mProperty_mGlobalVarName ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_noteGlobalVariableAccessIR::getter_mGlobalVarName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mGlobalVarName ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @noteGlobalVariableAccessIR class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_noteGlobalVariableAccessIR::cPtr_noteGlobalVariableAccessIR (const GALGAS_string & in_mGlobalVarName
                                                                  COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mGlobalVarName (in_mGlobalVarName) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_noteGlobalVariableAccessIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_noteGlobalVariableAccessIR ;
}

void cPtr_noteGlobalVariableAccessIR::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@noteGlobalVariableAccessIR:" ;
  mProperty_mGlobalVarName.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_noteGlobalVariableAccessIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_noteGlobalVariableAccessIR (mProperty_mGlobalVarName COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @noteGlobalVariableAccessIR type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_noteGlobalVariableAccessIR ("noteGlobalVariableAccessIR",
                                                   & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_noteGlobalVariableAccessIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_noteGlobalVariableAccessIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_noteGlobalVariableAccessIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_noteGlobalVariableAccessIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noteGlobalVariableAccessIR GALGAS_noteGlobalVariableAccessIR::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_noteGlobalVariableAccessIR result ;
  const GALGAS_noteGlobalVariableAccessIR * p = (const GALGAS_noteGlobalVariableAccessIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_noteGlobalVariableAccessIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("noteGlobalVariableAccessIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension method '@instructionListIR appendStoreToUniversalReference'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendStoreToUniversalReference (GALGAS_instructionListIR & ioObject,
                                                      const GALGAS_string constinArgument_inLLVMVarName,
                                                      const GALGAS_PLMType constinArgument_inTargetVarType,
                                                      const GALGAS_objectIR constinArgument_inSourceValue,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_storeToUniversalReferenceIR::constructor_new (constinArgument_inLLVMVarName, constinArgument_inTargetVarType, constinArgument_inSourceValue  COMMA_SOURCE_FILE ("intermediate-store-to-universal-reference.galgas", 7))  COMMA_SOURCE_FILE ("intermediate-store-to-universal-reference.galgas", 7)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Extension method '@instructionListIR appendStoreIndirectVolatileRegister'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendStoreIndirectVolatileRegister (GALGAS_instructionListIR & ioObject,
                                                          const GALGAS_PLMType constinArgument_inTargetVarType,
                                                          const GALGAS_string constinArgument_inLLVMName,
                                                          const GALGAS_objectIR constinArgument_inSourceValue,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_storeIndirectVolatileIR::constructor_new (constinArgument_inTargetVarType, constinArgument_inLLVMName, constinArgument_inSourceValue  COMMA_SOURCE_FILE ("intermediate-store-indirect-volatile-register.galgas", 7))  COMMA_SOURCE_FILE ("intermediate-store-indirect-volatile-register.galgas", 7)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Extension method '@instructionListIR appendStoreVolatileRegister'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendStoreVolatileRegister (GALGAS_instructionListIR & ioObject,
                                                  const GALGAS_PLMType constinArgument_inTargetVarType,
                                                  const GALGAS_bigint constinArgument_inAddress,
                                                  const GALGAS_objectIR constinArgument_inSourceValue,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_storeVolatileIR::constructor_new (constinArgument_inTargetVarType, constinArgument_inAddress, constinArgument_inSourceValue  COMMA_SOURCE_FILE ("intermediate-store-volatile-register.galgas", 7))  COMMA_SOURCE_FILE ("intermediate-store-volatile-register.galgas", 7)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Extension method '@instructionListIR appendStoreLocalVariable'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendStoreLocalVariable (GALGAS_instructionListIR & ioObject,
                                               const GALGAS_string constinArgument_inLocalVarName,
                                               const GALGAS_PLMType constinArgument_inTargetVarType,
                                               const GALGAS_objectIR constinArgument_inSourceValue,
                                               C_Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_storeLocalVariableIR::constructor_new (constinArgument_inLocalVarName, constinArgument_inTargetVarType, constinArgument_inSourceValue  COMMA_SOURCE_FILE ("intermediate-store-local-variable.galgas", 7))  COMMA_SOURCE_FILE ("intermediate-store-local-variable.galgas", 7)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Extension method '@instructionListIR appendStoreTemporaryReference'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendStoreTemporaryReference (GALGAS_instructionListIR & ioObject,
                                                    const GALGAS_PLMType constinArgument_inTargetVarType,
                                                    const GALGAS_string constinArgument_inLLVMName,
                                                    const GALGAS_objectIR constinArgument_inSourceValue,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_storeFromTemporaryReferenceIR::constructor_new (constinArgument_inTargetVarType, constinArgument_inLLVMName, constinArgument_inSourceValue  COMMA_SOURCE_FILE ("intermediate-store-to-temporary-reference.galgas", 8))  COMMA_SOURCE_FILE ("intermediate-store-to-temporary-reference.galgas", 8)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension method '@instructionListIR appendLoadWhenReference'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendLoadWhenReference (GALGAS_instructionListIR & ioObject,
                                              GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                              const GALGAS_objectIR constinArgument_inSource,
                                              GALGAS_objectIR & outArgument_outResultingValue,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultingValue.drop () ; // Release 'out' argument
  switch (constinArgument_inSource.enumValue ()) {
  case GALGAS_objectIR::kNotBuilt:
    break ;
  case GALGAS_objectIR::kEnum_null:
    {
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_nowhere (SOURCE_FILE ("intermediate-load-when-reference.galgas", 10)), GALGAS_string ("<<@instructionListIR appendLoadWhenReference null>>"), fixItArray0  COMMA_SOURCE_FILE ("intermediate-load-when-reference.galgas", 10)) ;
      outArgument_outResultingValue.drop () ; // Release error dropped variable
    }
    break ;
  case GALGAS_objectIR::kEnum_reference:
    {
      const cEnumAssociatedValues_objectIR_reference * extractPtr_574 = (const cEnumAssociatedValues_objectIR_reference *) (constinArgument_inSource.unsafePointer ()) ;
      const GALGAS_PLMType extractedValue_type = extractPtr_574->mAssociatedValue0 ;
      const GALGAS_string extractedValue_llvmName = extractPtr_574->mAssociatedValue1 ;
      {
      routine_getNewTempValue (extractedValue_type, ioArgument_ioTemporaries, outArgument_outResultingValue, inCompiler  COMMA_SOURCE_FILE ("intermediate-load-when-reference.galgas", 12)) ;
      }
      {
      extensionSetter_appendLoadFromReference (ioObject, outArgument_outResultingValue, extractedValue_llvmName, inCompiler COMMA_SOURCE_FILE ("intermediate-load-when-reference.galgas", 13)) ;
      }
    }
    break ;
  case GALGAS_objectIR::kEnum_literalInteger:
    {
      outArgument_outResultingValue = constinArgument_inSource ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmValue:
    {
      outArgument_outResultingValue = constinArgument_inSource ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmStructureValue:
    {
      outArgument_outResultingValue = constinArgument_inSource ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmArrayValue:
    {
      outArgument_outResultingValue = constinArgument_inSource ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalString:
    {
      outArgument_outResultingValue = constinArgument_inSource ;
    }
    break ;
  case GALGAS_objectIR::kEnum_zero:
    {
      outArgument_outResultingValue = constinArgument_inSource ;
    }
    break ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                           Extension method '@instructionListIR appendCopyFromReferences'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendCopyFromReferences (GALGAS_instructionListIR & ioObject,
                                               GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                               const GALGAS_location constinArgument_inErrorLocation,
                                               const GALGAS_objectIR constinArgument_inSourcePossibleReference,
                                               const GALGAS_LValueRepresentation constinArgument_inTargetReference,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool test_0 = constinArgument_inTargetReference.getter_isVolatileAbsoluteReference (SOURCE_FILE ("intermediate-copy-from-references.galgas", 10)) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    test_0 = constinArgument_inTargetReference.getter_isVolatileIndirectReference (SOURCE_FILE ("intermediate-copy-from-references.galgas", 11)) ;
  }
  GALGAS_bool test_1 = test_0 ;
  if (kBoolTrue != test_1.boolEnum ()) {
    test_1 = constinArgument_inSourcePossibleReference.getter_isReference (SOURCE_FILE ("intermediate-copy-from-references.galgas", 12)).operator_not (SOURCE_FILE ("intermediate-copy-from-references.galgas", 12)) ;
  }
  GALGAS_bool var_performLoadStore_444 = test_1 ;
  const enumGalgasBool test_2 = var_performLoadStore_444.boolEnum () ;
  if (kBoolTrue == test_2) {
    GALGAS_objectIR var_loadedResultValue_750 ;
    {
    extensionSetter_appendLoadWhenReference (ioObject, ioArgument_ioTemporaries, constinArgument_inSourcePossibleReference, var_loadedResultValue_750, inCompiler COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 15)) ;
    }
    GALGAS_objectIR var_result_771 = function_checkAssignmentCompatibility (var_loadedResultValue_750, extensionGetter_type (constinArgument_inTargetReference, inCompiler COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 22)), constinArgument_inErrorLocation, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 20)) ;
    switch (constinArgument_inTargetReference.enumValue ()) {
    case GALGAS_LValueRepresentation::kNotBuilt:
      break ;
    case GALGAS_LValueRepresentation::kEnum_volatileAbsoluteReference:
      {
        const cEnumAssociatedValues_LValueRepresentation_volatileAbsoluteReference * extractPtr_1125 = (const cEnumAssociatedValues_LValueRepresentation_volatileAbsoluteReference *) (constinArgument_inTargetReference.unsafePointer ()) ;
        const GALGAS_PLMType extractedValue_type = extractPtr_1125->mAssociatedValue0 ;
        const GALGAS_uint extractedValue_address = extractPtr_1125->mAssociatedValue1 ;
        {
        extensionSetter_appendStoreVolatileRegister (ioObject, extractedValue_type, extractedValue_address.getter_bigint (SOURCE_FILE ("intermediate-copy-from-references.galgas", 28)), var_result_771, inCompiler COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 28)) ;
        }
      }
      break ;
    case GALGAS_LValueRepresentation::kEnum_volatileIndirectReference:
      {
        const cEnumAssociatedValues_LValueRepresentation_volatileIndirectReference * extractPtr_1270 = (const cEnumAssociatedValues_LValueRepresentation_volatileIndirectReference *) (constinArgument_inTargetReference.unsafePointer ()) ;
        const GALGAS_PLMType extractedValue_type = extractPtr_1270->mAssociatedValue0 ;
        const GALGAS_string extractedValue_llvmName = extractPtr_1270->mAssociatedValue1 ;
        {
        extensionSetter_appendStoreIndirectVolatileRegister (ioObject, extractedValue_type, extractedValue_llvmName, var_result_771, inCompiler COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 30)) ;
        }
      }
      break ;
    case GALGAS_LValueRepresentation::kEnum_universalReference:
      {
        const cEnumAssociatedValues_LValueRepresentation_universalReference * extractPtr_1416 = (const cEnumAssociatedValues_LValueRepresentation_universalReference *) (constinArgument_inTargetReference.unsafePointer ()) ;
        const GALGAS_PLMType extractedValue_type = extractPtr_1416->mAssociatedValue0 ;
        const GALGAS_string extractedValue_targetLLVMname = extractPtr_1416->mAssociatedValue1 ;
        {
        extensionSetter_appendStoreToUniversalReference (ioObject, extractedValue_targetLLVMname, extractedValue_type, var_result_771, inCompiler COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 32)) ;
        }
      }
      break ;
    }
  }else if (kBoolFalse == test_2) {
    GALGAS_PLMType var_targetType_1516 ;
    GALGAS_string var_targetLLVMName_1546 ;
    constinArgument_inTargetReference.method_universalReference (var_targetType_1516, var_targetLLVMName_1546, inCompiler COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 35)) ;
    GALGAS_PLMType var_sourceType_1609 ;
    GALGAS_string var_sourceLLVMName_1638 ;
    constinArgument_inSourcePossibleReference.method_reference (var_sourceType_1609, var_sourceLLVMName_1638, inCompiler COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 36)) ;
    const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, var_sourceType_1609.objectCompare (var_targetType_1516)).boolEnum () ;
    if (kBoolTrue == test_3) {
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (constinArgument_inErrorLocation, GALGAS_string ("object of type $").add_operation (var_targetType_1516.getter_plmTypeName (HERE), inCompiler COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 39)).add_operation (GALGAS_string (" cannot be assigned from expression of type $"), inCompiler COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 39)).add_operation (var_sourceType_1609.getter_plmTypeName (HERE), inCompiler COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 40)), fixItArray4  COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 38)) ;
    }
    ioObject.addAssign_operation (GALGAS_copyFromReferencesIR::constructor_new (var_sourceType_1609, var_targetLLVMName_1546, var_sourceLLVMName_1638  COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 42))  COMMA_SOURCE_FILE ("intermediate-copy-from-references.galgas", 42)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                          Extension method '@instructionListIR referenceFromPossibleValue'                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_referenceFromPossibleValue (GALGAS_instructionListIR & ioObject,
                                                 GALGAS_semanticTemporariesStruct & ioArgument_ioTemporaries,
                                                 GALGAS_allocaList & ioArgument_ioAllocaList,
                                                 GALGAS_objectIR & ioArgument_ioObjectIR,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool var_performStore_325 ;
  switch (ioArgument_ioObjectIR.enumValue ()) {
  case GALGAS_objectIR::kNotBuilt:
    break ;
  case GALGAS_objectIR::kEnum_null:
    {
      var_performStore_325 = GALGAS_bool (false) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_reference:
    {
      var_performStore_325 = GALGAS_bool (false) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmValue:
    {
      var_performStore_325 = GALGAS_bool (true) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalInteger:
    {
      var_performStore_325 = GALGAS_bool (true) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmStructureValue:
    {
      var_performStore_325 = GALGAS_bool (true) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_llvmArrayValue:
    {
      var_performStore_325 = GALGAS_bool (true) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_literalString:
    {
      var_performStore_325 = GALGAS_bool (true) ;
    }
    break ;
  case GALGAS_objectIR::kEnum_zero:
    {
      var_performStore_325 = GALGAS_bool (true) ;
    }
    break ;
  }
  const enumGalgasBool test_0 = var_performStore_325.boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_string var_llvmTemporaryName_908 = function_llvmNameForLocalVariable (GALGAS_string ("tempz.").add_operation (ioArgument_ioTemporaries.getter_mTemporaryIndex (HERE).getter_string (SOURCE_FILE ("intermediate-reference-from-possible-value.galgas", 30)), inCompiler COMMA_SOURCE_FILE ("intermediate-reference-from-possible-value.galgas", 30)), inCompiler COMMA_SOURCE_FILE ("intermediate-reference-from-possible-value.galgas", 30)) ;
    ioArgument_ioTemporaries.mProperty_mTemporaryIndex.increment_operation (inCompiler  COMMA_SOURCE_FILE ("intermediate-reference-from-possible-value.galgas", 31)) ;
    ioArgument_ioAllocaList.addAssign_operation (var_llvmTemporaryName_908, extensionGetter_llvmTypeName (extensionGetter_type (ioArgument_ioObjectIR, inCompiler COMMA_SOURCE_FILE ("intermediate-reference-from-possible-value.galgas", 33)), inCompiler COMMA_SOURCE_FILE ("intermediate-reference-from-possible-value.galgas", 33))  COMMA_SOURCE_FILE ("intermediate-reference-from-possible-value.galgas", 33)) ;
    {
    extensionSetter_appendStoreTemporaryReference (ioObject, extensionGetter_type (ioArgument_ioObjectIR, inCompiler COMMA_SOURCE_FILE ("intermediate-reference-from-possible-value.galgas", 35)), var_llvmTemporaryName_908, ioArgument_ioObjectIR, inCompiler COMMA_SOURCE_FILE ("intermediate-reference-from-possible-value.galgas", 35)) ;
    }
    ioArgument_ioObjectIR = GALGAS_objectIR::constructor_reference (extensionGetter_type (ioArgument_ioObjectIR, inCompiler COMMA_SOURCE_FILE ("intermediate-reference-from-possible-value.galgas", 36)), var_llvmTemporaryName_908  COMMA_SOURCE_FILE ("intermediate-reference-from-possible-value.galgas", 36)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Extension method '@instructionListIR appendGetUniversalPropertyReference'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendGetUniversalPropertyReference (GALGAS_instructionListIR & ioObject,
                                                          const GALGAS_PLMType constinArgument_inType,
                                                          const GALGAS_string constinArgument_inLLVMName,
                                                          const GALGAS_PLMType constinArgument_inElementType,
                                                          const GALGAS_string constinArgument_inElementLLVMName,
                                                          const GALGAS_uint constinArgument_inPropertyIndex,
                                                          const GALGAS_string constinArgument_inPropertyName,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_getUniversalPropertyReferenceIR::constructor_new (constinArgument_inType, constinArgument_inLLVMName, constinArgument_inElementType, constinArgument_inElementLLVMName, constinArgument_inPropertyIndex, constinArgument_inPropertyName  COMMA_SOURCE_FILE ("intermediate-get-universal-property-reference.galgas", 10))  COMMA_SOURCE_FILE ("intermediate-get-universal-property-reference.galgas", 10)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    Extension method '@instructionListIR appendGetUniversalArrayElementReference'                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendGetUniversalArrayElementReference (GALGAS_instructionListIR & ioObject,
                                                              const GALGAS_PLMType constinArgument_inType,
                                                              const GALGAS_string constinArgument_inLLVMName,
                                                              const GALGAS_PLMType constinArgument_inElementType,
                                                              const GALGAS_string constinArgument_inElementLLVMName,
                                                              const GALGAS_objectIR constinArgument_inIndexIR,
                                                              C_Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_getUniversalArrayElementReferenceIR::constructor_new (constinArgument_inType, constinArgument_inLLVMName, constinArgument_inElementType, constinArgument_inElementLLVMName, constinArgument_inIndexIR  COMMA_SOURCE_FILE ("intermediate-get-universal-array-element-reference.galgas", 9))  COMMA_SOURCE_FILE ("intermediate-get-universal-array-element-reference.galgas", 9)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                        Extension method '@instructionListIR appendGetArrayElementReference'                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendGetArrayElementReference (GALGAS_instructionListIR & ioObject,
                                                     const GALGAS_objectIR constinArgument_inTarget,
                                                     const GALGAS_objectIR constinArgument_inSource,
                                                     const GALGAS_string constinArgument_inElementIndex,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_getArrayElementReferenceIR::constructor_new (constinArgument_inTarget, constinArgument_inSource, constinArgument_inElementIndex  COMMA_SOURCE_FILE ("intermediate-get-array-element-reference.galgas", 7))  COMMA_SOURCE_FILE ("intermediate-get-array-element-reference.galgas", 7)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_getArrayElementReferenceIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_getArrayElementReferenceIR * p = (const cPtr_getArrayElementReferenceIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_getArrayElementReferenceIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mTarget.objectCompare (p->mProperty_mTarget) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mSource.objectCompare (p->mProperty_mSource) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mElementIndex.objectCompare (p->mProperty_mElementIndex) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_getArrayElementReferenceIR::objectCompare (const GALGAS_getArrayElementReferenceIR & inOperand) const {
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

GALGAS_getArrayElementReferenceIR::GALGAS_getArrayElementReferenceIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_getArrayElementReferenceIR::GALGAS_getArrayElementReferenceIR (const cPtr_getArrayElementReferenceIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_getArrayElementReferenceIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_getArrayElementReferenceIR GALGAS_getArrayElementReferenceIR::constructor_new (const GALGAS_objectIR & inAttribute_mTarget,
                                                                                      const GALGAS_objectIR & inAttribute_mSource,
                                                                                      const GALGAS_string & inAttribute_mElementIndex
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_getArrayElementReferenceIR result ;
  if (inAttribute_mTarget.isValid () && inAttribute_mSource.isValid () && inAttribute_mElementIndex.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_getArrayElementReferenceIR (inAttribute_mTarget, inAttribute_mSource, inAttribute_mElementIndex COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_getArrayElementReferenceIR::getter_mTarget (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_getArrayElementReferenceIR * p = (const cPtr_getArrayElementReferenceIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_getArrayElementReferenceIR) ;
    result = p->mProperty_mTarget ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_getArrayElementReferenceIR::getter_mTarget (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTarget ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_getArrayElementReferenceIR::getter_mSource (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_getArrayElementReferenceIR * p = (const cPtr_getArrayElementReferenceIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_getArrayElementReferenceIR) ;
    result = p->mProperty_mSource ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_getArrayElementReferenceIR::getter_mSource (UNUSED_LOCATION_ARGS) const {
  return mProperty_mSource ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_getArrayElementReferenceIR::getter_mElementIndex (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_getArrayElementReferenceIR * p = (const cPtr_getArrayElementReferenceIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_getArrayElementReferenceIR) ;
    result = p->mProperty_mElementIndex ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_getArrayElementReferenceIR::getter_mElementIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mElementIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                 Pointer class for @getArrayElementReferenceIR class                                 *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_getArrayElementReferenceIR::cPtr_getArrayElementReferenceIR (const GALGAS_objectIR & in_mTarget,
                                                                  const GALGAS_objectIR & in_mSource,
                                                                  const GALGAS_string & in_mElementIndex
                                                                  COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mTarget (in_mTarget),
mProperty_mSource (in_mSource),
mProperty_mElementIndex (in_mElementIndex) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_getArrayElementReferenceIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_getArrayElementReferenceIR ;
}

void cPtr_getArrayElementReferenceIR::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@getArrayElementReferenceIR:" ;
  mProperty_mTarget.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mSource.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mElementIndex.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_getArrayElementReferenceIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_getArrayElementReferenceIR (mProperty_mTarget, mProperty_mSource, mProperty_mElementIndex COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @getArrayElementReferenceIR type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_getArrayElementReferenceIR ("getArrayElementReferenceIR",
                                                   & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_getArrayElementReferenceIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_getArrayElementReferenceIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_getArrayElementReferenceIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_getArrayElementReferenceIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_getArrayElementReferenceIR GALGAS_getArrayElementReferenceIR::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_getArrayElementReferenceIR result ;
  const GALGAS_getArrayElementReferenceIR * p = (const GALGAS_getArrayElementReferenceIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_getArrayElementReferenceIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("getArrayElementReferenceIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension method '@instructionListIR appendSelectOperation'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendSelectOperation (GALGAS_instructionListIR & ioObject,
                                            const GALGAS_objectIR constinArgument_inTargetValue,
                                            const GALGAS_objectIR constinArgument_in_5F_if_5F_variable,
                                            const GALGAS_objectIR constinArgument_in_5F_then_5F_variable,
                                            const GALGAS_objectIR constinArgument_in_5F_else_5F_variable,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_selectInstructionIR::constructor_new (constinArgument_inTargetValue, constinArgument_in_5F_if_5F_variable, constinArgument_in_5F_then_5F_variable, constinArgument_in_5F_else_5F_variable  COMMA_SOURCE_FILE ("intermediate-select-instruction.galgas", 8))  COMMA_SOURCE_FILE ("intermediate-select-instruction.galgas", 8)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_selectInstructionIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_selectInstructionIR * p = (const cPtr_selectInstructionIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_selectInstructionIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mTargetValue.objectCompare (p->mProperty_mTargetValue) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_m_5F_if_5F_variable.objectCompare (p->mProperty_m_5F_if_5F_variable) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_m_5F_then_5F_variable.objectCompare (p->mProperty_m_5F_then_5F_variable) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_m_5F_else_5F_variable.objectCompare (p->mProperty_m_5F_else_5F_variable) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_selectInstructionIR::objectCompare (const GALGAS_selectInstructionIR & inOperand) const {
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

GALGAS_selectInstructionIR::GALGAS_selectInstructionIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_selectInstructionIR::GALGAS_selectInstructionIR (const cPtr_selectInstructionIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_selectInstructionIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_selectInstructionIR GALGAS_selectInstructionIR::constructor_new (const GALGAS_objectIR & inAttribute_mTargetValue,
                                                                        const GALGAS_objectIR & inAttribute_m_5F_if_5F_variable,
                                                                        const GALGAS_objectIR & inAttribute_m_5F_then_5F_variable,
                                                                        const GALGAS_objectIR & inAttribute_m_5F_else_5F_variable
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_selectInstructionIR result ;
  if (inAttribute_mTargetValue.isValid () && inAttribute_m_5F_if_5F_variable.isValid () && inAttribute_m_5F_then_5F_variable.isValid () && inAttribute_m_5F_else_5F_variable.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_selectInstructionIR (inAttribute_mTargetValue, inAttribute_m_5F_if_5F_variable, inAttribute_m_5F_then_5F_variable, inAttribute_m_5F_else_5F_variable COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_selectInstructionIR::getter_mTargetValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_selectInstructionIR * p = (const cPtr_selectInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_selectInstructionIR) ;
    result = p->mProperty_mTargetValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_selectInstructionIR::getter_mTargetValue (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTargetValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_selectInstructionIR::getter_m_5F_if_5F_variable (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_selectInstructionIR * p = (const cPtr_selectInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_selectInstructionIR) ;
    result = p->mProperty_m_5F_if_5F_variable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_selectInstructionIR::getter_m_5F_if_5F_variable (UNUSED_LOCATION_ARGS) const {
  return mProperty_m_5F_if_5F_variable ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_selectInstructionIR::getter_m_5F_then_5F_variable (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_selectInstructionIR * p = (const cPtr_selectInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_selectInstructionIR) ;
    result = p->mProperty_m_5F_then_5F_variable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_selectInstructionIR::getter_m_5F_then_5F_variable (UNUSED_LOCATION_ARGS) const {
  return mProperty_m_5F_then_5F_variable ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_selectInstructionIR::getter_m_5F_else_5F_variable (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_selectInstructionIR * p = (const cPtr_selectInstructionIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_selectInstructionIR) ;
    result = p->mProperty_m_5F_else_5F_variable ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_selectInstructionIR::getter_m_5F_else_5F_variable (UNUSED_LOCATION_ARGS) const {
  return mProperty_m_5F_else_5F_variable ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @selectInstructionIR class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_selectInstructionIR::cPtr_selectInstructionIR (const GALGAS_objectIR & in_mTargetValue,
                                                    const GALGAS_objectIR & in_m_5F_if_5F_variable,
                                                    const GALGAS_objectIR & in_m_5F_then_5F_variable,
                                                    const GALGAS_objectIR & in_m_5F_else_5F_variable
                                                    COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mTargetValue (in_mTargetValue),
mProperty_m_5F_if_5F_variable (in_m_5F_if_5F_variable),
mProperty_m_5F_then_5F_variable (in_m_5F_then_5F_variable),
mProperty_m_5F_else_5F_variable (in_m_5F_else_5F_variable) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_selectInstructionIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_selectInstructionIR ;
}

void cPtr_selectInstructionIR::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@selectInstructionIR:" ;
  mProperty_mTargetValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_m_5F_if_5F_variable.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_m_5F_then_5F_variable.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_m_5F_else_5F_variable.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_selectInstructionIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_selectInstructionIR (mProperty_mTargetValue, mProperty_m_5F_if_5F_variable, mProperty_m_5F_then_5F_variable, mProperty_m_5F_else_5F_variable COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @selectInstructionIR type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_selectInstructionIR ("selectInstructionIR",
                                            & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_selectInstructionIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_selectInstructionIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_selectInstructionIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_selectInstructionIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_selectInstructionIR GALGAS_selectInstructionIR::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_selectInstructionIR result ;
  const GALGAS_selectInstructionIR * p = (const GALGAS_selectInstructionIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_selectInstructionIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("selectInstructionIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension method '@instructionListIR testArrayIndex'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_testArrayIndex (GALGAS_instructionListIR & ioObject,
                                     const GALGAS_objectIR constinArgument_inIndex,
                                     const GALGAS_location constinArgument_inErrorLocation,
                                     const GALGAS_bigint constinArgument_inSize,
                                     GALGAS_bool & outArgument_outGeneratePanicInstruction,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outGeneratePanicInstruction.drop () ; // Release 'out' argument
  GALGAS_bigint var_max_207 ;
  GALGAS_bool var_isUnsigned_232 ;
  GALGAS_bigint joker_192_1 ; // Joker input parameter
  GALGAS_uint joker_234_1 ; // Joker input parameter
  extensionGetter_type (constinArgument_inIndex, inCompiler COMMA_SOURCE_FILE ("intermediate-test-array-index.galgas", 8)).getter_kind (HERE).method_integer (joker_192_1, var_max_207, var_isUnsigned_232, joker_234_1, inCompiler COMMA_SOURCE_FILE ("intermediate-test-array-index.galgas", 8)) ;
  GALGAS_bool test_0 = var_isUnsigned_232.operator_not (SOURCE_FILE ("intermediate-test-array-index.galgas", 9)) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    test_0 = GALGAS_bool (kIsSupOrEqual, var_max_207.objectCompare (constinArgument_inSize)) ;
  }
  outArgument_outGeneratePanicInstruction = test_0 ;
  ioObject.addAssign_operation (GALGAS_testArrayIndexIR::constructor_new (constinArgument_inIndex, constinArgument_inErrorLocation, constinArgument_inSize  COMMA_SOURCE_FILE ("intermediate-test-array-index.galgas", 10))  COMMA_SOURCE_FILE ("intermediate-test-array-index.galgas", 10)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_testArrayIndexIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_testArrayIndexIR * p = (const cPtr_testArrayIndexIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_testArrayIndexIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mIndex.objectCompare (p->mProperty_mIndex) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mErrorLocation.objectCompare (p->mProperty_mErrorLocation) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mSize.objectCompare (p->mProperty_mSize) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_testArrayIndexIR::objectCompare (const GALGAS_testArrayIndexIR & inOperand) const {
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

GALGAS_testArrayIndexIR::GALGAS_testArrayIndexIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_testArrayIndexIR::GALGAS_testArrayIndexIR (const cPtr_testArrayIndexIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_testArrayIndexIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_testArrayIndexIR GALGAS_testArrayIndexIR::constructor_new (const GALGAS_objectIR & inAttribute_mIndex,
                                                                  const GALGAS_location & inAttribute_mErrorLocation,
                                                                  const GALGAS_bigint & inAttribute_mSize
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_testArrayIndexIR result ;
  if (inAttribute_mIndex.isValid () && inAttribute_mErrorLocation.isValid () && inAttribute_mSize.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_testArrayIndexIR (inAttribute_mIndex, inAttribute_mErrorLocation, inAttribute_mSize COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_testArrayIndexIR::getter_mIndex (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_testArrayIndexIR * p = (const cPtr_testArrayIndexIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_testArrayIndexIR) ;
    result = p->mProperty_mIndex ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_testArrayIndexIR::getter_mIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_testArrayIndexIR::getter_mErrorLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_testArrayIndexIR * p = (const cPtr_testArrayIndexIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_testArrayIndexIR) ;
    result = p->mProperty_mErrorLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_testArrayIndexIR::getter_mErrorLocation (UNUSED_LOCATION_ARGS) const {
  return mProperty_mErrorLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_testArrayIndexIR::getter_mSize (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_testArrayIndexIR * p = (const cPtr_testArrayIndexIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_testArrayIndexIR) ;
    result = p->mProperty_mSize ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_testArrayIndexIR::getter_mSize (UNUSED_LOCATION_ARGS) const {
  return mProperty_mSize ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @testArrayIndexIR class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_testArrayIndexIR::cPtr_testArrayIndexIR (const GALGAS_objectIR & in_mIndex,
                                              const GALGAS_location & in_mErrorLocation,
                                              const GALGAS_bigint & in_mSize
                                              COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mIndex (in_mIndex),
mProperty_mErrorLocation (in_mErrorLocation),
mProperty_mSize (in_mSize) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_testArrayIndexIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_testArrayIndexIR ;
}

void cPtr_testArrayIndexIR::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@testArrayIndexIR:" ;
  mProperty_mIndex.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mErrorLocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mSize.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_testArrayIndexIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_testArrayIndexIR (mProperty_mIndex, mProperty_mErrorLocation, mProperty_mSize COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @testArrayIndexIR type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_testArrayIndexIR ("testArrayIndexIR",
                                         & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_testArrayIndexIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_testArrayIndexIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_testArrayIndexIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_testArrayIndexIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_testArrayIndexIR GALGAS_testArrayIndexIR::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_testArrayIndexIR result ;
  const GALGAS_testArrayIndexIR * p = (const GALGAS_testArrayIndexIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_testArrayIndexIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("testArrayIndexIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension method '@instructionListIR appendUpperBoundCheck'                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendUpperBoundCheck (GALGAS_instructionListIR & ioObject,
                                            const GALGAS_objectIR constinArgument_inSource,
                                            const GALGAS_bigint constinArgument_inUpperBoundPlusOne,
                                            const GALGAS_uint constinArgument_inPanicCode,
                                            const GALGAS_location constinArgument_inLocation,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_upperBoundCheckIR::constructor_new (constinArgument_inSource, constinArgument_inUpperBoundPlusOne, constinArgument_inPanicCode, constinArgument_inLocation  COMMA_SOURCE_FILE ("intermediate-upper-bound-check.galgas", 8))  COMMA_SOURCE_FILE ("intermediate-upper-bound-check.galgas", 8)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_upperBoundCheckIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_upperBoundCheckIR * p = (const cPtr_upperBoundCheckIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_upperBoundCheckIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mSource.objectCompare (p->mProperty_mSource) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mUpperBoundPlusOne.objectCompare (p->mProperty_mUpperBoundPlusOne) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mPanicCode.objectCompare (p->mProperty_mPanicCode) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mLocation.objectCompare (p->mProperty_mLocation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_upperBoundCheckIR::objectCompare (const GALGAS_upperBoundCheckIR & inOperand) const {
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

GALGAS_upperBoundCheckIR::GALGAS_upperBoundCheckIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_upperBoundCheckIR::GALGAS_upperBoundCheckIR (const cPtr_upperBoundCheckIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_upperBoundCheckIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_upperBoundCheckIR GALGAS_upperBoundCheckIR::constructor_new (const GALGAS_objectIR & inAttribute_mSource,
                                                                    const GALGAS_bigint & inAttribute_mUpperBoundPlusOne,
                                                                    const GALGAS_uint & inAttribute_mPanicCode,
                                                                    const GALGAS_location & inAttribute_mLocation
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_upperBoundCheckIR result ;
  if (inAttribute_mSource.isValid () && inAttribute_mUpperBoundPlusOne.isValid () && inAttribute_mPanicCode.isValid () && inAttribute_mLocation.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_upperBoundCheckIR (inAttribute_mSource, inAttribute_mUpperBoundPlusOne, inAttribute_mPanicCode, inAttribute_mLocation COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_upperBoundCheckIR::getter_mSource (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectIR result ;
  if (NULL != mObjectPtr) {
    const cPtr_upperBoundCheckIR * p = (const cPtr_upperBoundCheckIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_upperBoundCheckIR) ;
    result = p->mProperty_mSource ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR cPtr_upperBoundCheckIR::getter_mSource (UNUSED_LOCATION_ARGS) const {
  return mProperty_mSource ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_upperBoundCheckIR::getter_mUpperBoundPlusOne (UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (NULL != mObjectPtr) {
    const cPtr_upperBoundCheckIR * p = (const cPtr_upperBoundCheckIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_upperBoundCheckIR) ;
    result = p->mProperty_mUpperBoundPlusOne ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint cPtr_upperBoundCheckIR::getter_mUpperBoundPlusOne (UNUSED_LOCATION_ARGS) const {
  return mProperty_mUpperBoundPlusOne ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_upperBoundCheckIR::getter_mPanicCode (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_upperBoundCheckIR * p = (const cPtr_upperBoundCheckIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_upperBoundCheckIR) ;
    result = p->mProperty_mPanicCode ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_upperBoundCheckIR::getter_mPanicCode (UNUSED_LOCATION_ARGS) const {
  return mProperty_mPanicCode ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_upperBoundCheckIR::getter_mLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_upperBoundCheckIR * p = (const cPtr_upperBoundCheckIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_upperBoundCheckIR) ;
    result = p->mProperty_mLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_upperBoundCheckIR::getter_mLocation (UNUSED_LOCATION_ARGS) const {
  return mProperty_mLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @upperBoundCheckIR class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_upperBoundCheckIR::cPtr_upperBoundCheckIR (const GALGAS_objectIR & in_mSource,
                                                const GALGAS_bigint & in_mUpperBoundPlusOne,
                                                const GALGAS_uint & in_mPanicCode,
                                                const GALGAS_location & in_mLocation
                                                COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mSource (in_mSource),
mProperty_mUpperBoundPlusOne (in_mUpperBoundPlusOne),
mProperty_mPanicCode (in_mPanicCode),
mProperty_mLocation (in_mLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_upperBoundCheckIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_upperBoundCheckIR ;
}

void cPtr_upperBoundCheckIR::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@upperBoundCheckIR:" ;
  mProperty_mSource.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mUpperBoundPlusOne.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mPanicCode.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mLocation.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_upperBoundCheckIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_upperBoundCheckIR (mProperty_mSource, mProperty_mUpperBoundPlusOne, mProperty_mPanicCode, mProperty_mLocation COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @upperBoundCheckIR type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_upperBoundCheckIR ("upperBoundCheckIR",
                                          & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_upperBoundCheckIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_upperBoundCheckIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_upperBoundCheckIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_upperBoundCheckIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_upperBoundCheckIR GALGAS_upperBoundCheckIR::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_upperBoundCheckIR result ;
  const GALGAS_upperBoundCheckIR * p = (const GALGAS_upperBoundCheckIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_upperBoundCheckIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("upperBoundCheckIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension method '@instructionListIR appendSourceLineComment'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionSetter_appendSourceLineComment (GALGAS_instructionListIR & ioObject,
                                              const GALGAS_location constinArgument_inSourceLocation,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  ioObject.addAssign_operation (GALGAS_sourceLocationIR::constructor_new (constinArgument_inSourceLocation  COMMA_SOURCE_FILE ("intermediate-comment-source-line.galgas", 3))  COMMA_SOURCE_FILE ("intermediate-comment-source-line.galgas", 3)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sourceLocationIR::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sourceLocationIR * p = (const cPtr_sourceLocationIR *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sourceLocationIR) ;
  if (kOperandEqual == result) {
    result = mProperty_mSourceLocation.objectCompare (p->mProperty_mSourceLocation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_sourceLocationIR::objectCompare (const GALGAS_sourceLocationIR & inOperand) const {
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

GALGAS_sourceLocationIR::GALGAS_sourceLocationIR (void) :
GALGAS_abstractInstructionIR () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sourceLocationIR GALGAS_sourceLocationIR::constructor_default (LOCATION_ARGS) {
  return GALGAS_sourceLocationIR::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                                   COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sourceLocationIR::GALGAS_sourceLocationIR (const cPtr_sourceLocationIR * inSourcePtr) :
GALGAS_abstractInstructionIR (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sourceLocationIR) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sourceLocationIR GALGAS_sourceLocationIR::constructor_new (const GALGAS_location & inAttribute_mSourceLocation
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_sourceLocationIR result ;
  if (inAttribute_mSourceLocation.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sourceLocationIR (inAttribute_mSourceLocation COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_sourceLocationIR::getter_mSourceLocation (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_sourceLocationIR * p = (const cPtr_sourceLocationIR *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sourceLocationIR) ;
    result = p->mProperty_mSourceLocation ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_sourceLocationIR::getter_mSourceLocation (UNUSED_LOCATION_ARGS) const {
  return mProperty_mSourceLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @sourceLocationIR class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sourceLocationIR::cPtr_sourceLocationIR (const GALGAS_location & in_mSourceLocation
                                              COMMA_LOCATION_ARGS) :
cPtr_abstractInstructionIR (THERE),
mProperty_mSourceLocation (in_mSourceLocation) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sourceLocationIR::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sourceLocationIR ;
}

void cPtr_sourceLocationIR::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@sourceLocationIR:" ;
  mProperty_mSourceLocation.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sourceLocationIR::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sourceLocationIR (mProperty_mSourceLocation COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @sourceLocationIR type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sourceLocationIR ("sourceLocationIR",
                                         & kTypeDescriptor_GALGAS_abstractInstructionIR) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sourceLocationIR::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sourceLocationIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sourceLocationIR::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sourceLocationIR (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sourceLocationIR GALGAS_sourceLocationIR::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_sourceLocationIR result ;
  const GALGAS_sourceLocationIR * p = (const GALGAS_sourceLocationIR *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sourceLocationIR *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sourceLocationIR", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_accessibleEntities::GALGAS_accessibleEntities (void) :
mProperty_mRoutineSet (),
mProperty_mGuardSet (),
mProperty_mSectionSet (),
mProperty_mGlobalVariableSet (),
mProperty_mTaskVariableSet () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_accessibleEntities::~ GALGAS_accessibleEntities (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_accessibleEntities::GALGAS_accessibleEntities (const GALGAS_stringset & inOperand0,
                                                      const GALGAS_stringset & inOperand1,
                                                      const GALGAS_stringset & inOperand2,
                                                      const GALGAS_stringset & inOperand3,
                                                      const GALGAS_stringset & inOperand4) :
mProperty_mRoutineSet (inOperand0),
mProperty_mGuardSet (inOperand1),
mProperty_mSectionSet (inOperand2),
mProperty_mGlobalVariableSet (inOperand3),
mProperty_mTaskVariableSet (inOperand4) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_accessibleEntities GALGAS_accessibleEntities::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_accessibleEntities (GALGAS_stringset::constructor_emptySet (HERE),
                                    GALGAS_stringset::constructor_emptySet (HERE),
                                    GALGAS_stringset::constructor_emptySet (HERE),
                                    GALGAS_stringset::constructor_emptySet (HERE),
                                    GALGAS_stringset::constructor_emptySet (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_accessibleEntities GALGAS_accessibleEntities::constructor_new (const GALGAS_stringset & inOperand0,
                                                                      const GALGAS_stringset & inOperand1,
                                                                      const GALGAS_stringset & inOperand2,
                                                                      const GALGAS_stringset & inOperand3,
                                                                      const GALGAS_stringset & inOperand4 
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_accessibleEntities result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid ()) {
    result = GALGAS_accessibleEntities (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_accessibleEntities::objectCompare (const GALGAS_accessibleEntities & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mRoutineSet.objectCompare (inOperand.mProperty_mRoutineSet) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mGuardSet.objectCompare (inOperand.mProperty_mGuardSet) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mSectionSet.objectCompare (inOperand.mProperty_mSectionSet) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mGlobalVariableSet.objectCompare (inOperand.mProperty_mGlobalVariableSet) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mTaskVariableSet.objectCompare (inOperand.mProperty_mTaskVariableSet) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_accessibleEntities::isValid (void) const {
  return mProperty_mRoutineSet.isValid () && mProperty_mGuardSet.isValid () && mProperty_mSectionSet.isValid () && mProperty_mGlobalVariableSet.isValid () && mProperty_mTaskVariableSet.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_accessibleEntities::drop (void) {
  mProperty_mRoutineSet.drop () ;
  mProperty_mGuardSet.drop () ;
  mProperty_mSectionSet.drop () ;
  mProperty_mGlobalVariableSet.drop () ;
  mProperty_mTaskVariableSet.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_accessibleEntities::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "<struct @accessibleEntities:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mRoutineSet.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mGuardSet.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mSectionSet.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mGlobalVariableSet.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mTaskVariableSet.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_accessibleEntities::getter_mRoutineSet (UNUSED_LOCATION_ARGS) const {
  return mProperty_mRoutineSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_accessibleEntities::getter_mGuardSet (UNUSED_LOCATION_ARGS) const {
  return mProperty_mGuardSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_accessibleEntities::getter_mSectionSet (UNUSED_LOCATION_ARGS) const {
  return mProperty_mSectionSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_accessibleEntities::getter_mGlobalVariableSet (UNUSED_LOCATION_ARGS) const {
  return mProperty_mGlobalVariableSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_accessibleEntities::getter_mTaskVariableSet (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTaskVariableSet ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @accessibleEntities type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_accessibleEntities ("accessibleEntities",
                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_accessibleEntities::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_accessibleEntities ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_accessibleEntities::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_accessibleEntities (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_accessibleEntities GALGAS_accessibleEntities::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_accessibleEntities result ;
  const GALGAS_accessibleEntities * p = (const GALGAS_accessibleEntities *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_accessibleEntities *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("accessibleEntities", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     Abstract extension method '@abstractInstructionIR enterAccessibleEntities'                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_abstractInstructionIR_enterAccessibleEntities> gExtensionMethodTable_abstractInstructionIR_enterAccessibleEntities ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_enterAccessibleEntities (const int32_t inClassIndex,
                                                   extensionMethodSignature_abstractInstructionIR_enterAccessibleEntities inMethod) {
  gExtensionMethodTable_abstractInstructionIR_enterAccessibleEntities.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_abstractInstructionIR_enterAccessibleEntities (void) {
  gExtensionMethodTable_abstractInstructionIR_enterAccessibleEntities.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_abstractInstructionIR_enterAccessibleEntities (NULL,
                                                                          freeExtensionMethod_abstractInstructionIR_enterAccessibleEntities) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_enterAccessibleEntities (const cPtr_abstractInstructionIR * inObject,
                                                  GALGAS_accessibleEntities & io_ioAccessibleEntities,
                                                  GALGAS_uint & io_ioMaxBranchOfOnInstructions,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_abstractInstructionIR) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_abstractInstructionIR_enterAccessibleEntities f = NULL ;
    if (classIndex < gExtensionMethodTable_abstractInstructionIR_enterAccessibleEntities.count ()) {
      f = gExtensionMethodTable_abstractInstructionIR_enterAccessibleEntities (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_abstractInstructionIR_enterAccessibleEntities.count ()) {
          f = gExtensionMethodTable_abstractInstructionIR_enterAccessibleEntities (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_abstractInstructionIR_enterAccessibleEntities.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_ioAccessibleEntities, io_ioMaxBranchOfOnInstructions, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                            Extension method '@instructionListIR enterAccessibleEntities'                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void extensionMethod_enterAccessibleEntities (const GALGAS_instructionListIR inObject,
                                              GALGAS_accessibleEntities & ioArgument_ioAccessibleEntities,
                                              GALGAS_uint & ioArgument_ioMaxBranchOfOnInstructions,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_instructionListIR temp_0 = inObject ;
  cEnumerator_instructionListIR enumerator_1321 (temp_0, kENUMERATION_UP) ;
  while (enumerator_1321.hasCurrentObject ()) {
    callExtensionMethod_enterAccessibleEntities ((const cPtr_abstractInstructionIR *) enumerator_1321.current_mInstructionGeneration (HERE).ptr (), ioArgument_ioAccessibleEntities, ioArgument_ioMaxBranchOfOnInstructions, inCompiler COMMA_SOURCE_FILE ("code-optimisation.galgas", 25)) ;
    enumerator_1321.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationAdds::GALGAS_generationAdds (void) :
mProperty_mUniqueIndex (),
mProperty_mExternFunctionDeclarationSet (),
mProperty_mStaticStringMap (),
mProperty_mUsesGuards () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationAdds::~ GALGAS_generationAdds (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationAdds::GALGAS_generationAdds (const GALGAS_uint & inOperand0,
                                              const GALGAS_stringset & inOperand1,
                                              const GALGAS_staticStringMap & inOperand2,
                                              const GALGAS_bool & inOperand3) :
mProperty_mUniqueIndex (inOperand0),
mProperty_mExternFunctionDeclarationSet (inOperand1),
mProperty_mStaticStringMap (inOperand2),
mProperty_mUsesGuards (inOperand3) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationAdds GALGAS_generationAdds::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_generationAdds (GALGAS_uint::constructor_default (HERE),
                                GALGAS_stringset::constructor_emptySet (HERE),
                                GALGAS_staticStringMap::constructor_emptyMap (HERE),
                                GALGAS_bool::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationAdds GALGAS_generationAdds::constructor_new (const GALGAS_uint & inOperand0,
                                                              const GALGAS_stringset & inOperand1,
                                                              const GALGAS_staticStringMap & inOperand2,
                                                              const GALGAS_bool & inOperand3 
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_generationAdds result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid ()) {
    result = GALGAS_generationAdds (inOperand0, inOperand1, inOperand2, inOperand3) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_generationAdds::objectCompare (const GALGAS_generationAdds & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mUniqueIndex.objectCompare (inOperand.mProperty_mUniqueIndex) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mExternFunctionDeclarationSet.objectCompare (inOperand.mProperty_mExternFunctionDeclarationSet) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mStaticStringMap.objectCompare (inOperand.mProperty_mStaticStringMap) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mUsesGuards.objectCompare (inOperand.mProperty_mUsesGuards) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_generationAdds::isValid (void) const {
  return mProperty_mUniqueIndex.isValid () && mProperty_mExternFunctionDeclarationSet.isValid () && mProperty_mStaticStringMap.isValid () && mProperty_mUsesGuards.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationAdds::drop (void) {
  mProperty_mUniqueIndex.drop () ;
  mProperty_mExternFunctionDeclarationSet.drop () ;
  mProperty_mStaticStringMap.drop () ;
  mProperty_mUsesGuards.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationAdds::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "<struct @generationAdds:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mUniqueIndex.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mExternFunctionDeclarationSet.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mStaticStringMap.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mUsesGuards.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_generationAdds::getter_mUniqueIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mUniqueIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_generationAdds::getter_mExternFunctionDeclarationSet (UNUSED_LOCATION_ARGS) const {
  return mProperty_mExternFunctionDeclarationSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticStringMap GALGAS_generationAdds::getter_mStaticStringMap (UNUSED_LOCATION_ARGS) const {
  return mProperty_mStaticStringMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_generationAdds::getter_mUsesGuards (UNUSED_LOCATION_ARGS) const {
  return mProperty_mUsesGuards ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @generationAdds type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_generationAdds ("generationAdds",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_generationAdds::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_generationAdds ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_generationAdds::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_generationAdds (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationAdds GALGAS_generationAdds::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_generationAdds result ;
  const GALGAS_generationAdds * p = (const GALGAS_generationAdds *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_generationAdds *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("generationAdds", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       Abstract extension method '@abstractInstructionIR llvmInstructionCode'                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_abstractInstructionIR_llvmInstructionCode> gExtensionMethodTable_abstractInstructionIR_llvmInstructionCode ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_llvmInstructionCode (const int32_t inClassIndex,
                                               extensionMethodSignature_abstractInstructionIR_llvmInstructionCode inMethod) {
  gExtensionMethodTable_abstractInstructionIR_llvmInstructionCode.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_abstractInstructionIR_llvmInstructionCode (void) {
  gExtensionMethodTable_abstractInstructionIR_llvmInstructionCode.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_abstractInstructionIR_llvmInstructionCode (NULL,
                                                                      freeExtensionMethod_abstractInstructionIR_llvmInstructionCode) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_llvmInstructionCode (const cPtr_abstractInstructionIR * inObject,
                                              GALGAS_string & io_ioLLVMcode,
                                              const GALGAS_generationContext constin_inGenerationContext,
                                              GALGAS_generationAdds & io_ioGenerationAdds,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_abstractInstructionIR) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_abstractInstructionIR_llvmInstructionCode f = NULL ;
    if (classIndex < gExtensionMethodTable_abstractInstructionIR_llvmInstructionCode.count ()) {
      f = gExtensionMethodTable_abstractInstructionIR_llvmInstructionCode (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_abstractInstructionIR_llvmInstructionCode.count ()) {
          f = gExtensionMethodTable_abstractInstructionIR_llvmInstructionCode (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_abstractInstructionIR_llvmInstructionCode.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_ioLLVMcode, constin_inGenerationContext, io_ioGenerationAdds, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Abstract extension method '@abstractGenerationIR generateLLVMcode'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_abstractGenerationIR_generateLLVMcode> gExtensionMethodTable_abstractGenerationIR_generateLLVMcode ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_generateLLVMcode (const int32_t inClassIndex,
                                            extensionMethodSignature_abstractGenerationIR_generateLLVMcode inMethod) {
  gExtensionMethodTable_abstractGenerationIR_generateLLVMcode.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_abstractGenerationIR_generateLLVMcode (void) {
  gExtensionMethodTable_abstractGenerationIR_generateLLVMcode.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_abstractGenerationIR_generateLLVMcode (NULL,
                                                                  freeExtensionMethod_abstractGenerationIR_generateLLVMcode) ;

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_generateLLVMcode (const cPtr_abstractGenerationIR * inObject,
                                           GALGAS_string & io_ioLLVMcode,
                                           GALGAS_generationAdds & io_ioGenerationAdds,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_abstractGenerationIR) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_abstractGenerationIR_generateLLVMcode f = NULL ;
    if (classIndex < gExtensionMethodTable_abstractGenerationIR_generateLLVMcode.count ()) {
      f = gExtensionMethodTable_abstractGenerationIR_generateLLVMcode (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
      const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
      while ((NULL == f) && (NULL != p)) {
        if (p->mSlotID < gExtensionMethodTable_abstractGenerationIR_generateLLVMcode.count ()) {
          f = gExtensionMethodTable_abstractGenerationIR_generateLLVMcode (p->mSlotID COMMA_HERE) ;
        }
        p = p->mSuperclassDescriptor ;
      }
      gExtensionMethodTable_abstractGenerationIR_generateLLVMcode.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_ioLLVMcode, io_ioGenerationAdds, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationContext::GALGAS_generationContext (void) :
mProperty_mPanicCodeLLVMType (),
mProperty_mPanicLineLLVMType (),
mProperty_mNopInstructionInLLVM (),
mProperty_mGlobalTaskVariableList (),
mProperty_mAvailableInterruptMap () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationContext::~ GALGAS_generationContext (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationContext::GALGAS_generationContext (const GALGAS_string & inOperand0,
                                                    const GALGAS_string & inOperand1,
                                                    const GALGAS_string & inOperand2,
                                                    const GALGAS_globalTaskVariableList & inOperand3,
                                                    const GALGAS_availableInterruptMap & inOperand4) :
mProperty_mPanicCodeLLVMType (inOperand0),
mProperty_mPanicLineLLVMType (inOperand1),
mProperty_mNopInstructionInLLVM (inOperand2),
mProperty_mGlobalTaskVariableList (inOperand3),
mProperty_mAvailableInterruptMap (inOperand4) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationContext GALGAS_generationContext::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_generationContext (GALGAS_string::constructor_default (HERE),
                                   GALGAS_string::constructor_default (HERE),
                                   GALGAS_string::constructor_default (HERE),
                                   GALGAS_globalTaskVariableList::constructor_emptyList (HERE),
                                   GALGAS_availableInterruptMap::constructor_emptyMap (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationContext GALGAS_generationContext::constructor_new (const GALGAS_string & inOperand0,
                                                                    const GALGAS_string & inOperand1,
                                                                    const GALGAS_string & inOperand2,
                                                                    const GALGAS_globalTaskVariableList & inOperand3,
                                                                    const GALGAS_availableInterruptMap & inOperand4 
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_generationContext result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid ()) {
    result = GALGAS_generationContext (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_generationContext::objectCompare (const GALGAS_generationContext & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mPanicCodeLLVMType.objectCompare (inOperand.mProperty_mPanicCodeLLVMType) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mPanicLineLLVMType.objectCompare (inOperand.mProperty_mPanicLineLLVMType) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mNopInstructionInLLVM.objectCompare (inOperand.mProperty_mNopInstructionInLLVM) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mGlobalTaskVariableList.objectCompare (inOperand.mProperty_mGlobalTaskVariableList) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mAvailableInterruptMap.objectCompare (inOperand.mProperty_mAvailableInterruptMap) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_generationContext::isValid (void) const {
  return mProperty_mPanicCodeLLVMType.isValid () && mProperty_mPanicLineLLVMType.isValid () && mProperty_mNopInstructionInLLVM.isValid () && mProperty_mGlobalTaskVariableList.isValid () && mProperty_mAvailableInterruptMap.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationContext::drop (void) {
  mProperty_mPanicCodeLLVMType.drop () ;
  mProperty_mPanicLineLLVMType.drop () ;
  mProperty_mNopInstructionInLLVM.drop () ;
  mProperty_mGlobalTaskVariableList.drop () ;
  mProperty_mAvailableInterruptMap.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_generationContext::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "<struct @generationContext:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mPanicCodeLLVMType.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mPanicLineLLVMType.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mNopInstructionInLLVM.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mGlobalTaskVariableList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mAvailableInterruptMap.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_generationContext::getter_mPanicCodeLLVMType (UNUSED_LOCATION_ARGS) const {
  return mProperty_mPanicCodeLLVMType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_generationContext::getter_mPanicLineLLVMType (UNUSED_LOCATION_ARGS) const {
  return mProperty_mPanicLineLLVMType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_generationContext::getter_mNopInstructionInLLVM (UNUSED_LOCATION_ARGS) const {
  return mProperty_mNopInstructionInLLVM ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_globalTaskVariableList GALGAS_generationContext::getter_mGlobalTaskVariableList (UNUSED_LOCATION_ARGS) const {
  return mProperty_mGlobalTaskVariableList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_availableInterruptMap GALGAS_generationContext::getter_mAvailableInterruptMap (UNUSED_LOCATION_ARGS) const {
  return mProperty_mAvailableInterruptMap ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @generationContext type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_generationContext ("generationContext",
                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_generationContext::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_generationContext ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_generationContext::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_generationContext (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_generationContext GALGAS_generationContext::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_generationContext result ;
  const GALGAS_generationContext * p = (const GALGAS_generationContext *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_generationContext *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("generationContext", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Class for element of '@orderedTypeList' sorted list                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cSortedListElement_orderedTypeList : public cSortedListElement {
  public : GALGAS_orderedTypeList_2D_element mObject ;

//--- Constructor
  public : cSortedListElement_orderedTypeList (const GALGAS_PLMType & in_mType,
                                               const GALGAS_uint & in_mIndex
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

cSortedListElement_orderedTypeList::cSortedListElement_orderedTypeList (const GALGAS_PLMType & in_mType,
                                                                        const GALGAS_uint & in_mIndex
                                                                        COMMA_LOCATION_ARGS) :
cSortedListElement (THERE),
mObject (in_mType, in_mIndex) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cSortedListElement_orderedTypeList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cSortedListElement * cSortedListElement_orderedTypeList::copy (void) {
  cSortedListElement * result = NULL ;
  macroMyNew (result, cSortedListElement_orderedTypeList (mObject.mProperty_mType, mObject.mProperty_mIndex COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cSortedListElement_orderedTypeList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mType" ":" ;
  mObject.mProperty_mType.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mIndex" ":" ;
  mObject.mProperty_mIndex.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cSortedListElement_orderedTypeList::compare (const cCollectionElement * inOperand) const {
  cSortedListElement_orderedTypeList * operand = (cSortedListElement_orderedTypeList *) inOperand ;
  macroValidSharedObject (operand, cSortedListElement_orderedTypeList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_orderedTypeList::GALGAS_orderedTypeList (void) :
AC_GALGAS_sortedlist () {
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cSortedListElement_orderedTypeList::compareForSorting (const cSortedListElement * inOperand) const {
  typeComparisonResult result = kOperandEqual ;
  const cSortedListElement_orderedTypeList * operand = (const cSortedListElement_orderedTypeList *) inOperand ;
  macroValidSharedObject (operand, cSortedListElement_orderedTypeList) ;
  if (result == kOperandEqual) {
    result = mObject.mProperty_mIndex.objectCompare (operand->mObject.mProperty_mIndex) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_orderedTypeList GALGAS_orderedTypeList::constructor_emptySortedList (LOCATION_ARGS) {
  GALGAS_orderedTypeList result ;
  result.createNewEmptySortedList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_orderedTypeList GALGAS_orderedTypeList::constructor_sortedListWithValue (const GALGAS_PLMType & inOperand0,
                                                                                const GALGAS_uint & inOperand1
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_orderedTypeList result = constructor_emptySortedList (THERE) ;
  cSortedListElement * p = NULL ;
  macroMyNew (p, cSortedListElement_orderedTypeList (inOperand0, inOperand1 COMMA_THERE)) ;
  capSortedListElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  result.appendObject (attributes) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_orderedTypeList::addAssign_operation (const GALGAS_PLMType & inOperand0,
                                                  const GALGAS_uint & inOperand1
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cSortedListElement * p = NULL ;
    macroMyNew (p, cSortedListElement_orderedTypeList (inOperand0, inOperand1 COMMA_THERE)) ;
    capSortedListElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_orderedTypeList::plusAssign_operation (const GALGAS_orderedTypeList inOperand,
                                                   C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid ()) {
    appendSortedList (inOperand) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_orderedTypeList::setter_popSmallest (GALGAS_PLMType & outOperand0,
                                                 GALGAS_uint & outOperand1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  capSortedListElement attributes ;
  removeSmallestObject (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_orderedTypeList * p = (cSortedListElement_orderedTypeList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_orderedTypeList) ;
    outOperand0 = p->mObject.mProperty_mType ;
    outOperand1 = p->mObject.mProperty_mIndex ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_orderedTypeList::setter_popGreatest (GALGAS_PLMType & outOperand0,
                                                 GALGAS_uint & outOperand1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  capSortedListElement attributes ;
  removeGreatestObject (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_orderedTypeList * p = (cSortedListElement_orderedTypeList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_orderedTypeList) ;
    outOperand0 = p->mObject.mProperty_mType ;
    outOperand1 = p->mObject.mProperty_mIndex ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_orderedTypeList::method_smallest (GALGAS_PLMType & outOperand0,
                                              GALGAS_uint & outOperand1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  capSortedListElement attributes ;
  smallestObjectAttributeList (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_orderedTypeList * p = (cSortedListElement_orderedTypeList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_orderedTypeList) ;
    outOperand0 = p->mObject.mProperty_mType ;
    outOperand1 = p->mObject.mProperty_mIndex ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_orderedTypeList::method_greatest (GALGAS_PLMType & outOperand0,
                                              GALGAS_uint & outOperand1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  capSortedListElement attributes ;
  greatestObjectAttributeList (attributes, inCompiler COMMA_THERE) ;
  cSortedListElement_orderedTypeList * p = (cSortedListElement_orderedTypeList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cSortedListElement_orderedTypeList) ;
    outOperand0 = p->mObject.mProperty_mType ;
    outOperand1 = p->mObject.mProperty_mIndex ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_orderedTypeList::cEnumerator_orderedTypeList (const GALGAS_orderedTypeList & inEnumeratedObject,
                                                          const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_orderedTypeList_2D_element cEnumerator_orderedTypeList::current (LOCATION_ARGS) const {
  const cSortedListElement_orderedTypeList * p = (const cSortedListElement_orderedTypeList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_orderedTypeList) ;
  return p->mObject ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_PLMType cEnumerator_orderedTypeList::current_mType (LOCATION_ARGS) const {
  const cSortedListElement_orderedTypeList * p = (const cSortedListElement_orderedTypeList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_orderedTypeList) ;
  return p->mObject.mProperty_mType ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cEnumerator_orderedTypeList::current_mIndex (LOCATION_ARGS) const {
  const cSortedListElement_orderedTypeList * p = (const cSortedListElement_orderedTypeList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cSortedListElement_orderedTypeList) ;
  return p->mObject.mProperty_mIndex ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @orderedTypeList type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_orderedTypeList ("orderedTypeList",
                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_orderedTypeList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_orderedTypeList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_orderedTypeList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_orderedTypeList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_orderedTypeList GALGAS_orderedTypeList::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_orderedTypeList result ;
  const GALGAS_orderedTypeList * p = (const GALGAS_orderedTypeList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_orderedTypeList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("orderedTypeList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortedOperandIRList_2D_element::GALGAS_sortedOperandIRList_2D_element (void) :
mProperty_mOperand (),
mProperty_mIndex () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortedOperandIRList_2D_element::~ GALGAS_sortedOperandIRList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortedOperandIRList_2D_element::GALGAS_sortedOperandIRList_2D_element (const GALGAS_objectIR & inOperand0,
                                                                              const GALGAS_uint & inOperand1) :
mProperty_mOperand (inOperand0),
mProperty_mIndex (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortedOperandIRList_2D_element GALGAS_sortedOperandIRList_2D_element::constructor_new (const GALGAS_objectIR & inOperand0,
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
    result = mProperty_mOperand.objectCompare (inOperand.mProperty_mOperand) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mIndex.objectCompare (inOperand.mProperty_mIndex) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_sortedOperandIRList_2D_element::isValid (void) const {
  return mProperty_mOperand.isValid () && mProperty_mIndex.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortedOperandIRList_2D_element::drop (void) {
  mProperty_mOperand.drop () ;
  mProperty_mIndex.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortedOperandIRList_2D_element::description (C_String & ioString,
                                                         const int32_t inIndentation) const {
  ioString << "<struct @sortedOperandIRList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mOperand.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mIndex.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_sortedOperandIRList_2D_element::getter_mOperand (UNUSED_LOCATION_ARGS) const {
  return mProperty_mOperand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_sortedOperandIRList_2D_element::getter_mIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mIndex ;
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

GALGAS_controlRegisterBitSliceList_2D_element::GALGAS_controlRegisterBitSliceList_2D_element (void) :
mProperty_mRegisterBitSlice () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceList_2D_element::~ GALGAS_controlRegisterBitSliceList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSliceList_2D_element::GALGAS_controlRegisterBitSliceList_2D_element (const GALGAS_controlRegisterBitSlice & inOperand0) :
mProperty_mRegisterBitSlice (inOperand0) {
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
    result = mProperty_mRegisterBitSlice.objectCompare (inOperand.mProperty_mRegisterBitSlice) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_controlRegisterBitSliceList_2D_element::isValid (void) const {
  return mProperty_mRegisterBitSlice.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterBitSliceList_2D_element::drop (void) {
  mProperty_mRegisterBitSlice.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterBitSliceList_2D_element::description (C_String & ioString,
                                                                 const int32_t inIndentation) const {
  ioString << "<struct @controlRegisterBitSliceList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mRegisterBitSlice.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterBitSlice GALGAS_controlRegisterBitSliceList_2D_element::getter_mRegisterBitSlice (UNUSED_LOCATION_ARGS) const {
  return mProperty_mRegisterBitSlice ;
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

GALGAS_controlRegisterFieldList_2D_element::GALGAS_controlRegisterFieldList_2D_element (void) :
mProperty_mFieldBitCount (),
mProperty_mFieldName () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldList_2D_element::~ GALGAS_controlRegisterFieldList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldList_2D_element::GALGAS_controlRegisterFieldList_2D_element (const GALGAS_uint & inOperand0,
                                                                                        const GALGAS_string & inOperand1) :
mProperty_mFieldBitCount (inOperand0),
mProperty_mFieldName (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldList_2D_element GALGAS_controlRegisterFieldList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_controlRegisterFieldList_2D_element (GALGAS_uint::constructor_default (HERE),
                                                     GALGAS_string::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldList_2D_element GALGAS_controlRegisterFieldList_2D_element::constructor_new (const GALGAS_uint & inOperand0,
                                                                                                        const GALGAS_string & inOperand1 
                                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_controlRegisterFieldList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_controlRegisterFieldList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_controlRegisterFieldList_2D_element::objectCompare (const GALGAS_controlRegisterFieldList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mFieldBitCount.objectCompare (inOperand.mProperty_mFieldBitCount) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mFieldName.objectCompare (inOperand.mProperty_mFieldName) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_controlRegisterFieldList_2D_element::isValid (void) const {
  return mProperty_mFieldBitCount.isValid () && mProperty_mFieldName.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterFieldList_2D_element::drop (void) {
  mProperty_mFieldBitCount.drop () ;
  mProperty_mFieldName.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_controlRegisterFieldList_2D_element::description (C_String & ioString,
                                                              const int32_t inIndentation) const {
  ioString << "<struct @controlRegisterFieldList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mFieldBitCount.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mFieldName.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_controlRegisterFieldList_2D_element::getter_mFieldBitCount (UNUSED_LOCATION_ARGS) const {
  return mProperty_mFieldBitCount ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_controlRegisterFieldList_2D_element::getter_mFieldName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mFieldName ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @controlRegisterFieldList-element type                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_controlRegisterFieldList_2D_element ("controlRegisterFieldList-element",
                                                            NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_controlRegisterFieldList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_controlRegisterFieldList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_controlRegisterFieldList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_controlRegisterFieldList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_controlRegisterFieldList_2D_element GALGAS_controlRegisterFieldList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                      C_Compiler * inCompiler
                                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_controlRegisterFieldList_2D_element result ;
  const GALGAS_controlRegisterFieldList_2D_element * p = (const GALGAS_controlRegisterFieldList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_controlRegisterFieldList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("controlRegisterFieldList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticListValueListAST_2D_element::GALGAS_staticListValueListAST_2D_element (void) :
mProperty_mExpressions () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticListValueListAST_2D_element::~ GALGAS_staticListValueListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticListValueListAST_2D_element::GALGAS_staticListValueListAST_2D_element (const GALGAS_extendStaticListElementListAST & inOperand0) :
mProperty_mExpressions (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticListValueListAST_2D_element GALGAS_staticListValueListAST_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_staticListValueListAST_2D_element (GALGAS_extendStaticListElementListAST::constructor_emptyList (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticListValueListAST_2D_element GALGAS_staticListValueListAST_2D_element::constructor_new (const GALGAS_extendStaticListElementListAST & inOperand0 
                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_staticListValueListAST_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_staticListValueListAST_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_staticListValueListAST_2D_element::objectCompare (const GALGAS_staticListValueListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mExpressions.objectCompare (inOperand.mProperty_mExpressions) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_staticListValueListAST_2D_element::isValid (void) const {
  return mProperty_mExpressions.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_staticListValueListAST_2D_element::drop (void) {
  mProperty_mExpressions.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_staticListValueListAST_2D_element::description (C_String & ioString,
                                                            const int32_t inIndentation) const {
  ioString << "<struct @staticListValueListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mExpressions.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extendStaticListElementListAST GALGAS_staticListValueListAST_2D_element::getter_mExpressions (UNUSED_LOCATION_ARGS) const {
  return mProperty_mExpressions ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @staticListValueListAST-element type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_staticListValueListAST_2D_element ("staticListValueListAST-element",
                                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_staticListValueListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_staticListValueListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_staticListValueListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_staticListValueListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_staticListValueListAST_2D_element GALGAS_staticListValueListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_staticListValueListAST_2D_element result ;
  const GALGAS_staticListValueListAST_2D_element * p = (const GALGAS_staticListValueListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_staticListValueListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("staticListValueListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extendStaticListElementListAST_2D_element::GALGAS_extendStaticListElementListAST_2D_element (void) :
mProperty_mExpression (),
mProperty_mEndOfExpression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extendStaticListElementListAST_2D_element::~ GALGAS_extendStaticListElementListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extendStaticListElementListAST_2D_element::GALGAS_extendStaticListElementListAST_2D_element (const GALGAS_extendStaticListExpressionAST & inOperand0,
                                                                                                    const GALGAS_location & inOperand1) :
mProperty_mExpression (inOperand0),
mProperty_mEndOfExpression (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extendStaticListElementListAST_2D_element GALGAS_extendStaticListElementListAST_2D_element::constructor_new (const GALGAS_extendStaticListExpressionAST & inOperand0,
                                                                                                                    const GALGAS_location & inOperand1 
                                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_extendStaticListElementListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_extendStaticListElementListAST_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_extendStaticListElementListAST_2D_element::objectCompare (const GALGAS_extendStaticListElementListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mExpression.objectCompare (inOperand.mProperty_mExpression) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mEndOfExpression.objectCompare (inOperand.mProperty_mEndOfExpression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_extendStaticListElementListAST_2D_element::isValid (void) const {
  return mProperty_mExpression.isValid () && mProperty_mEndOfExpression.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extendStaticListElementListAST_2D_element::drop (void) {
  mProperty_mExpression.drop () ;
  mProperty_mEndOfExpression.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_extendStaticListElementListAST_2D_element::description (C_String & ioString,
                                                                    const int32_t inIndentation) const {
  ioString << "<struct @extendStaticListElementListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mExpression.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mEndOfExpression.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extendStaticListExpressionAST GALGAS_extendStaticListElementListAST_2D_element::getter_mExpression (UNUSED_LOCATION_ARGS) const {
  return mProperty_mExpression ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_extendStaticListElementListAST_2D_element::getter_mEndOfExpression (UNUSED_LOCATION_ARGS) const {
  return mProperty_mEndOfExpression ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    @extendStaticListElementListAST-element type                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_extendStaticListElementListAST_2D_element ("extendStaticListElementListAST-element",
                                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_extendStaticListElementListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_extendStaticListElementListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_extendStaticListElementListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_extendStaticListElementListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_extendStaticListElementListAST_2D_element GALGAS_extendStaticListElementListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                                  C_Compiler * inCompiler
                                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_extendStaticListElementListAST_2D_element result ;
  const GALGAS_extendStaticListElementListAST_2D_element * p = (const GALGAS_extendStaticListElementListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_extendStaticListElementListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("extendStaticListElementListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskSortedListIR_2D_element::GALGAS_taskSortedListIR_2D_element (void) :
mProperty_mTaskName (),
mProperty_mPriority (),
mProperty_mStackSize (),
mProperty_mAllocaList (),
mProperty_mSetupInstructionListIR (),
mProperty_mTaskNameStringIndex () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskSortedListIR_2D_element::~ GALGAS_taskSortedListIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskSortedListIR_2D_element::GALGAS_taskSortedListIR_2D_element (const GALGAS_string & inOperand0,
                                                                        const GALGAS_bigint & inOperand1,
                                                                        const GALGAS_bigint & inOperand2,
                                                                        const GALGAS_allocaList & inOperand3,
                                                                        const GALGAS_instructionListIR & inOperand4,
                                                                        const GALGAS_uint & inOperand5) :
mProperty_mTaskName (inOperand0),
mProperty_mPriority (inOperand1),
mProperty_mStackSize (inOperand2),
mProperty_mAllocaList (inOperand3),
mProperty_mSetupInstructionListIR (inOperand4),
mProperty_mTaskNameStringIndex (inOperand5) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskSortedListIR_2D_element GALGAS_taskSortedListIR_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_taskSortedListIR_2D_element (GALGAS_string::constructor_default (HERE),
                                             GALGAS_bigint::constructor_zero (HERE),
                                             GALGAS_bigint::constructor_zero (HERE),
                                             GALGAS_allocaList::constructor_emptyList (HERE),
                                             GALGAS_instructionListIR::constructor_emptyList (HERE),
                                             GALGAS_uint::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskSortedListIR_2D_element GALGAS_taskSortedListIR_2D_element::constructor_new (const GALGAS_string & inOperand0,
                                                                                        const GALGAS_bigint & inOperand1,
                                                                                        const GALGAS_bigint & inOperand2,
                                                                                        const GALGAS_allocaList & inOperand3,
                                                                                        const GALGAS_instructionListIR & inOperand4,
                                                                                        const GALGAS_uint & inOperand5 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_taskSortedListIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid ()) {
    result = GALGAS_taskSortedListIR_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_taskSortedListIR_2D_element::objectCompare (const GALGAS_taskSortedListIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mTaskName.objectCompare (inOperand.mProperty_mTaskName) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mPriority.objectCompare (inOperand.mProperty_mPriority) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mStackSize.objectCompare (inOperand.mProperty_mStackSize) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mAllocaList.objectCompare (inOperand.mProperty_mAllocaList) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mSetupInstructionListIR.objectCompare (inOperand.mProperty_mSetupInstructionListIR) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mTaskNameStringIndex.objectCompare (inOperand.mProperty_mTaskNameStringIndex) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_taskSortedListIR_2D_element::isValid (void) const {
  return mProperty_mTaskName.isValid () && mProperty_mPriority.isValid () && mProperty_mStackSize.isValid () && mProperty_mAllocaList.isValid () && mProperty_mSetupInstructionListIR.isValid () && mProperty_mTaskNameStringIndex.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskSortedListIR_2D_element::drop (void) {
  mProperty_mTaskName.drop () ;
  mProperty_mPriority.drop () ;
  mProperty_mStackSize.drop () ;
  mProperty_mAllocaList.drop () ;
  mProperty_mSetupInstructionListIR.drop () ;
  mProperty_mTaskNameStringIndex.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_taskSortedListIR_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @taskSortedListIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mTaskName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mPriority.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mStackSize.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mAllocaList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mSetupInstructionListIR.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mTaskNameStringIndex.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_taskSortedListIR_2D_element::getter_mTaskName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTaskName ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_taskSortedListIR_2D_element::getter_mPriority (UNUSED_LOCATION_ARGS) const {
  return mProperty_mPriority ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_taskSortedListIR_2D_element::getter_mStackSize (UNUSED_LOCATION_ARGS) const {
  return mProperty_mStackSize ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList GALGAS_taskSortedListIR_2D_element::getter_mAllocaList (UNUSED_LOCATION_ARGS) const {
  return mProperty_mAllocaList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_taskSortedListIR_2D_element::getter_mSetupInstructionListIR (UNUSED_LOCATION_ARGS) const {
  return mProperty_mSetupInstructionListIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_taskSortedListIR_2D_element::getter_mTaskNameStringIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTaskNameStringIndex ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @taskSortedListIR-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_taskSortedListIR_2D_element ("taskSortedListIR-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_taskSortedListIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_taskSortedListIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_taskSortedListIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_taskSortedListIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_taskSortedListIR_2D_element GALGAS_taskSortedListIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_taskSortedListIR_2D_element result ;
  const GALGAS_taskSortedListIR_2D_element * p = (const GALGAS_taskSortedListIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_taskSortedListIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("taskSortedListIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListSortedListIR_2D_element::GALGAS_instructionListSortedListIR_2D_element (void) :
mProperty_mInstructionList (),
mProperty_mPriority () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListSortedListIR_2D_element::~ GALGAS_instructionListSortedListIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListSortedListIR_2D_element::GALGAS_instructionListSortedListIR_2D_element (const GALGAS_instructionListIR & inOperand0,
                                                                                              const GALGAS_bigint & inOperand1) :
mProperty_mInstructionList (inOperand0),
mProperty_mPriority (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListSortedListIR_2D_element GALGAS_instructionListSortedListIR_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_instructionListSortedListIR_2D_element (GALGAS_instructionListIR::constructor_emptyList (HERE),
                                                        GALGAS_bigint::constructor_zero (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListSortedListIR_2D_element GALGAS_instructionListSortedListIR_2D_element::constructor_new (const GALGAS_instructionListIR & inOperand0,
                                                                                                              const GALGAS_bigint & inOperand1 
                                                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_instructionListSortedListIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_instructionListSortedListIR_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_instructionListSortedListIR_2D_element::objectCompare (const GALGAS_instructionListSortedListIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mInstructionList.objectCompare (inOperand.mProperty_mInstructionList) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mPriority.objectCompare (inOperand.mProperty_mPriority) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_instructionListSortedListIR_2D_element::isValid (void) const {
  return mProperty_mInstructionList.isValid () && mProperty_mPriority.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_instructionListSortedListIR_2D_element::drop (void) {
  mProperty_mInstructionList.drop () ;
  mProperty_mPriority.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_instructionListSortedListIR_2D_element::description (C_String & ioString,
                                                                 const int32_t inIndentation) const {
  ioString << "<struct @instructionListSortedListIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mInstructionList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mPriority.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_instructionListSortedListIR_2D_element::getter_mInstructionList (UNUSED_LOCATION_ARGS) const {
  return mProperty_mInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_instructionListSortedListIR_2D_element::getter_mPriority (UNUSED_LOCATION_ARGS) const {
  return mProperty_mPriority ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      @instructionListSortedListIR-element type                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_instructionListSortedListIR_2D_element ("instructionListSortedListIR-element",
                                                               NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_instructionListSortedListIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_instructionListSortedListIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_instructionListSortedListIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_instructionListSortedListIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListSortedListIR_2D_element GALGAS_instructionListSortedListIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                            C_Compiler * inCompiler
                                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_instructionListSortedListIR_2D_element result ;
  const GALGAS_instructionListSortedListIR_2D_element * p = (const GALGAS_instructionListSortedListIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_instructionListSortedListIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("instructionListSortedListIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootListIR_2D_element::GALGAS_bootListIR_2D_element (void) :
mProperty_mBootIndex (),
mProperty_mInitLocation (),
mProperty_mAllocaList (),
mProperty_mInstructionListIR (),
mProperty_mEndOfInitLocation () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootListIR_2D_element::~ GALGAS_bootListIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootListIR_2D_element::GALGAS_bootListIR_2D_element (const GALGAS_bigint & inOperand0,
                                                            const GALGAS_location & inOperand1,
                                                            const GALGAS_allocaList & inOperand2,
                                                            const GALGAS_instructionListIR & inOperand3,
                                                            const GALGAS_location & inOperand4) :
mProperty_mBootIndex (inOperand0),
mProperty_mInitLocation (inOperand1),
mProperty_mAllocaList (inOperand2),
mProperty_mInstructionListIR (inOperand3),
mProperty_mEndOfInitLocation (inOperand4) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootListIR_2D_element GALGAS_bootListIR_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_bootListIR_2D_element (GALGAS_bigint::constructor_zero (HERE),
                                       GALGAS_location::constructor_nowhere (HERE),
                                       GALGAS_allocaList::constructor_emptyList (HERE),
                                       GALGAS_instructionListIR::constructor_emptyList (HERE),
                                       GALGAS_location::constructor_nowhere (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootListIR_2D_element GALGAS_bootListIR_2D_element::constructor_new (const GALGAS_bigint & inOperand0,
                                                                            const GALGAS_location & inOperand1,
                                                                            const GALGAS_allocaList & inOperand2,
                                                                            const GALGAS_instructionListIR & inOperand3,
                                                                            const GALGAS_location & inOperand4 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bootListIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid ()) {
    result = GALGAS_bootListIR_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_bootListIR_2D_element::objectCompare (const GALGAS_bootListIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mBootIndex.objectCompare (inOperand.mProperty_mBootIndex) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mInitLocation.objectCompare (inOperand.mProperty_mInitLocation) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mAllocaList.objectCompare (inOperand.mProperty_mAllocaList) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mInstructionListIR.objectCompare (inOperand.mProperty_mInstructionListIR) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mEndOfInitLocation.objectCompare (inOperand.mProperty_mEndOfInitLocation) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_bootListIR_2D_element::isValid (void) const {
  return mProperty_mBootIndex.isValid () && mProperty_mInitLocation.isValid () && mProperty_mAllocaList.isValid () && mProperty_mInstructionListIR.isValid () && mProperty_mEndOfInitLocation.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_bootListIR_2D_element::drop (void) {
  mProperty_mBootIndex.drop () ;
  mProperty_mInitLocation.drop () ;
  mProperty_mAllocaList.drop () ;
  mProperty_mInstructionListIR.drop () ;
  mProperty_mEndOfInitLocation.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_bootListIR_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @bootListIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mBootIndex.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mInitLocation.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mAllocaList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mInstructionListIR.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mEndOfInitLocation.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_bootListIR_2D_element::getter_mBootIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mBootIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_bootListIR_2D_element::getter_mInitLocation (UNUSED_LOCATION_ARGS) const {
  return mProperty_mInitLocation ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_allocaList GALGAS_bootListIR_2D_element::getter_mAllocaList (UNUSED_LOCATION_ARGS) const {
  return mProperty_mAllocaList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_bootListIR_2D_element::getter_mInstructionListIR (UNUSED_LOCATION_ARGS) const {
  return mProperty_mInstructionListIR ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_bootListIR_2D_element::getter_mEndOfInitLocation (UNUSED_LOCATION_ARGS) const {
  return mProperty_mEndOfInitLocation ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @bootListIR-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_bootListIR_2D_element ("bootListIR-element",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_bootListIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bootListIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_bootListIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_bootListIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bootListIR_2D_element GALGAS_bootListIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_bootListIR_2D_element result ;
  const GALGAS_bootListIR_2D_element * p = (const GALGAS_bootListIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_bootListIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("bootListIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST_2D_element::GALGAS_primaryInExpressionAccessListAST_2D_element (void) :
mProperty_mAccess () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST_2D_element::~ GALGAS_primaryInExpressionAccessListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST_2D_element::GALGAS_primaryInExpressionAccessListAST_2D_element (const GALGAS_primaryInExpressionAccessAST & inOperand0) :
mProperty_mAccess (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST_2D_element GALGAS_primaryInExpressionAccessListAST_2D_element::constructor_new (const GALGAS_primaryInExpressionAccessAST & inOperand0 
                                                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_primaryInExpressionAccessListAST_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_primaryInExpressionAccessListAST_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_primaryInExpressionAccessListAST_2D_element::objectCompare (const GALGAS_primaryInExpressionAccessListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mAccess.objectCompare (inOperand.mProperty_mAccess) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_primaryInExpressionAccessListAST_2D_element::isValid (void) const {
  return mProperty_mAccess.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionAccessListAST_2D_element::drop (void) {
  mProperty_mAccess.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_primaryInExpressionAccessListAST_2D_element::description (C_String & ioString,
                                                                      const int32_t inIndentation) const {
  ioString << "<struct @primaryInExpressionAccessListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mAccess.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessAST GALGAS_primaryInExpressionAccessListAST_2D_element::getter_mAccess (UNUSED_LOCATION_ARGS) const {
  return mProperty_mAccess ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   @primaryInExpressionAccessListAST-element type                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_primaryInExpressionAccessListAST_2D_element ("primaryInExpressionAccessListAST-element",
                                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_primaryInExpressionAccessListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_primaryInExpressionAccessListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_primaryInExpressionAccessListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_primaryInExpressionAccessListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_primaryInExpressionAccessListAST_2D_element GALGAS_primaryInExpressionAccessListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                                      C_Compiler * inCompiler
                                                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_primaryInExpressionAccessListAST_2D_element result ;
  const GALGAS_primaryInExpressionAccessListAST_2D_element * p = (const GALGAS_primaryInExpressionAccessListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_primaryInExpressionAccessListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("primaryInExpressionAccessListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST_2D_element::GALGAS_instructionListAST_2D_element (void) :
mProperty_mInstruction () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST_2D_element::~ GALGAS_instructionListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST_2D_element::GALGAS_instructionListAST_2D_element (const GALGAS_instructionAST & inOperand0) :
mProperty_mInstruction (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST_2D_element GALGAS_instructionListAST_2D_element::constructor_new (const GALGAS_instructionAST & inOperand0 
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_instructionListAST_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_instructionListAST_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_instructionListAST_2D_element::objectCompare (const GALGAS_instructionListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mInstruction.objectCompare (inOperand.mProperty_mInstruction) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_instructionListAST_2D_element::isValid (void) const {
  return mProperty_mInstruction.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_instructionListAST_2D_element::drop (void) {
  mProperty_mInstruction.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_instructionListAST_2D_element::description (C_String & ioString,
                                                        const int32_t inIndentation) const {
  ioString << "<struct @instructionListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mInstruction.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionAST GALGAS_instructionListAST_2D_element::getter_mInstruction (UNUSED_LOCATION_ARGS) const {
  return mProperty_mInstruction ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @instructionListAST-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_instructionListAST_2D_element ("instructionListAST-element",
                                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_instructionListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_instructionListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_instructionListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_instructionListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST_2D_element GALGAS_instructionListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_instructionListAST_2D_element result ;
  const GALGAS_instructionListAST_2D_element * p = (const GALGAS_instructionListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_instructionListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("instructionListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListAST_2D_element::GALGAS_syncInstructionBranchListAST_2D_element (void) :
mProperty_mGuardedCommand (),
mProperty_mInstructionList (),
mProperty_mEndOfBranch () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListAST_2D_element::~ GALGAS_syncInstructionBranchListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListAST_2D_element::GALGAS_syncInstructionBranchListAST_2D_element (const GALGAS_guardedCommandAST & inOperand0,
                                                                                                const GALGAS_instructionListAST & inOperand1,
                                                                                                const GALGAS_location & inOperand2) :
mProperty_mGuardedCommand (inOperand0),
mProperty_mInstructionList (inOperand1),
mProperty_mEndOfBranch (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListAST_2D_element GALGAS_syncInstructionBranchListAST_2D_element::constructor_new (const GALGAS_guardedCommandAST & inOperand0,
                                                                                                                const GALGAS_instructionListAST & inOperand1,
                                                                                                                const GALGAS_location & inOperand2 
                                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_syncInstructionBranchListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_syncInstructionBranchListAST_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_syncInstructionBranchListAST_2D_element::objectCompare (const GALGAS_syncInstructionBranchListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mGuardedCommand.objectCompare (inOperand.mProperty_mGuardedCommand) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mInstructionList.objectCompare (inOperand.mProperty_mInstructionList) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mEndOfBranch.objectCompare (inOperand.mProperty_mEndOfBranch) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_syncInstructionBranchListAST_2D_element::isValid (void) const {
  return mProperty_mGuardedCommand.isValid () && mProperty_mInstructionList.isValid () && mProperty_mEndOfBranch.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListAST_2D_element::drop (void) {
  mProperty_mGuardedCommand.drop () ;
  mProperty_mInstructionList.drop () ;
  mProperty_mEndOfBranch.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListAST_2D_element::description (C_String & ioString,
                                                                  const int32_t inIndentation) const {
  ioString << "<struct @syncInstructionBranchListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mGuardedCommand.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mInstructionList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mEndOfBranch.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardedCommandAST GALGAS_syncInstructionBranchListAST_2D_element::getter_mGuardedCommand (UNUSED_LOCATION_ARGS) const {
  return mProperty_mGuardedCommand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_syncInstructionBranchListAST_2D_element::getter_mInstructionList (UNUSED_LOCATION_ARGS) const {
  return mProperty_mInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_syncInstructionBranchListAST_2D_element::getter_mEndOfBranch (UNUSED_LOCATION_ARGS) const {
  return mProperty_mEndOfBranch ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     @syncInstructionBranchListAST-element type                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_syncInstructionBranchListAST_2D_element ("syncInstructionBranchListAST-element",
                                                                NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_syncInstructionBranchListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_syncInstructionBranchListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_syncInstructionBranchListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_syncInstructionBranchListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListAST_2D_element GALGAS_syncInstructionBranchListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                              C_Compiler * inCompiler
                                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_syncInstructionBranchListAST_2D_element result ;
  const GALGAS_syncInstructionBranchListAST_2D_element * p = (const GALGAS_syncInstructionBranchListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_syncInstructionBranchListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("syncInstructionBranchListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR_2D_element::GALGAS_syncInstructionBranchListIR_2D_element (void) :
mProperty_mGuardedCommand (),
mProperty_mInstructionGenerationList () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR_2D_element::~ GALGAS_syncInstructionBranchListIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_syncInstructionBranchListIR_2D_element::GALGAS_syncInstructionBranchListIR_2D_element (const GALGAS_guardedCommandIR & inOperand0,
                                                                                              const GALGAS_instructionListIR & inOperand1) :
mProperty_mGuardedCommand (inOperand0),
mProperty_mInstructionGenerationList (inOperand1) {
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
    result = mProperty_mGuardedCommand.objectCompare (inOperand.mProperty_mGuardedCommand) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mInstructionGenerationList.objectCompare (inOperand.mProperty_mInstructionGenerationList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_syncInstructionBranchListIR_2D_element::isValid (void) const {
  return mProperty_mGuardedCommand.isValid () && mProperty_mInstructionGenerationList.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR_2D_element::drop (void) {
  mProperty_mGuardedCommand.drop () ;
  mProperty_mInstructionGenerationList.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_syncInstructionBranchListIR_2D_element::description (C_String & ioString,
                                                                 const int32_t inIndentation) const {
  ioString << "<struct @syncInstructionBranchListIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mGuardedCommand.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mInstructionGenerationList.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_guardedCommandIR GALGAS_syncInstructionBranchListIR_2D_element::getter_mGuardedCommand (UNUSED_LOCATION_ARGS) const {
  return mProperty_mGuardedCommand ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_syncInstructionBranchListIR_2D_element::getter_mInstructionGenerationList (UNUSED_LOCATION_ARGS) const {
  return mProperty_mInstructionGenerationList ;
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
mProperty_mEffectiveParameterPassingMode (),
mProperty_mParameter () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR_2D_element::~ GALGAS_procCallEffectiveParameterListIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR_2D_element::GALGAS_procCallEffectiveParameterListIR_2D_element (const GALGAS_procEffectiveParameterPassingModeIR & inOperand0,
                                                                                                        const GALGAS_objectIR & inOperand1) :
mProperty_mEffectiveParameterPassingMode (inOperand0),
mProperty_mParameter (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procCallEffectiveParameterListIR_2D_element GALGAS_procCallEffectiveParameterListIR_2D_element::constructor_new (const GALGAS_procEffectiveParameterPassingModeIR & inOperand0,
                                                                                                                        const GALGAS_objectIR & inOperand1 
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
    result = mProperty_mEffectiveParameterPassingMode.objectCompare (inOperand.mProperty_mEffectiveParameterPassingMode) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mParameter.objectCompare (inOperand.mProperty_mParameter) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_procCallEffectiveParameterListIR_2D_element::isValid (void) const {
  return mProperty_mEffectiveParameterPassingMode.isValid () && mProperty_mParameter.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR_2D_element::drop (void) {
  mProperty_mEffectiveParameterPassingMode.drop () ;
  mProperty_mParameter.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_procCallEffectiveParameterListIR_2D_element::description (C_String & ioString,
                                                                      const int32_t inIndentation) const {
  ioString << "<struct @procCallEffectiveParameterListIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mEffectiveParameterPassingMode.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mParameter.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_procEffectiveParameterPassingModeIR GALGAS_procCallEffectiveParameterListIR_2D_element::getter_mEffectiveParameterPassingMode (UNUSED_LOCATION_ARGS) const {
  return mProperty_mEffectiveParameterPassingMode ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectIR GALGAS_procCallEffectiveParameterListIR_2D_element::getter_mParameter (UNUSED_LOCATION_ARGS) const {
  return mProperty_mParameter ;
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

GALGAS_switchCaseListAST_2D_element::GALGAS_switchCaseListAST_2D_element (void) :
mProperty_mCaseIdentifiers (),
mProperty_mCaseInstructionList () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseListAST_2D_element::~ GALGAS_switchCaseListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseListAST_2D_element::GALGAS_switchCaseListAST_2D_element (const GALGAS_lstringlist & inOperand0,
                                                                          const GALGAS_instructionListAST & inOperand1) :
mProperty_mCaseIdentifiers (inOperand0),
mProperty_mCaseInstructionList (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseListAST_2D_element GALGAS_switchCaseListAST_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_switchCaseListAST_2D_element (GALGAS_lstringlist::constructor_emptyList (HERE),
                                              GALGAS_instructionListAST::constructor_emptyList (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseListAST_2D_element GALGAS_switchCaseListAST_2D_element::constructor_new (const GALGAS_lstringlist & inOperand0,
                                                                                          const GALGAS_instructionListAST & inOperand1 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_switchCaseListAST_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_switchCaseListAST_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_switchCaseListAST_2D_element::objectCompare (const GALGAS_switchCaseListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mCaseIdentifiers.objectCompare (inOperand.mProperty_mCaseIdentifiers) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mCaseInstructionList.objectCompare (inOperand.mProperty_mCaseInstructionList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_switchCaseListAST_2D_element::isValid (void) const {
  return mProperty_mCaseIdentifiers.isValid () && mProperty_mCaseInstructionList.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseListAST_2D_element::drop (void) {
  mProperty_mCaseIdentifiers.drop () ;
  mProperty_mCaseInstructionList.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseListAST_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @switchCaseListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mCaseIdentifiers.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mCaseInstructionList.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_switchCaseListAST_2D_element::getter_mCaseIdentifiers (UNUSED_LOCATION_ARGS) const {
  return mProperty_mCaseIdentifiers ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListAST GALGAS_switchCaseListAST_2D_element::getter_mCaseInstructionList (UNUSED_LOCATION_ARGS) const {
  return mProperty_mCaseInstructionList ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @switchCaseListAST-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_switchCaseListAST_2D_element ("switchCaseListAST-element",
                                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_switchCaseListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_switchCaseListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_switchCaseListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_switchCaseListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseListAST_2D_element GALGAS_switchCaseListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_switchCaseListAST_2D_element result ;
  const GALGAS_switchCaseListAST_2D_element * p = (const GALGAS_switchCaseListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_switchCaseListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("switchCaseListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseListIR_2D_element::GALGAS_switchCaseListIR_2D_element (void) :
mProperty_mCaseIdentifierIndexes (),
mProperty_mCaseInstructionList () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseListIR_2D_element::~ GALGAS_switchCaseListIR_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseListIR_2D_element::GALGAS_switchCaseListIR_2D_element (const GALGAS_uintlist & inOperand0,
                                                                        const GALGAS_instructionListIR & inOperand1) :
mProperty_mCaseIdentifierIndexes (inOperand0),
mProperty_mCaseInstructionList (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseListIR_2D_element GALGAS_switchCaseListIR_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_switchCaseListIR_2D_element (GALGAS_uintlist::constructor_emptyList (HERE),
                                             GALGAS_instructionListIR::constructor_emptyList (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseListIR_2D_element GALGAS_switchCaseListIR_2D_element::constructor_new (const GALGAS_uintlist & inOperand0,
                                                                                        const GALGAS_instructionListIR & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_switchCaseListIR_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_switchCaseListIR_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_switchCaseListIR_2D_element::objectCompare (const GALGAS_switchCaseListIR_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mCaseIdentifierIndexes.objectCompare (inOperand.mProperty_mCaseIdentifierIndexes) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mCaseInstructionList.objectCompare (inOperand.mProperty_mCaseInstructionList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_switchCaseListIR_2D_element::isValid (void) const {
  return mProperty_mCaseIdentifierIndexes.isValid () && mProperty_mCaseInstructionList.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseListIR_2D_element::drop (void) {
  mProperty_mCaseIdentifierIndexes.drop () ;
  mProperty_mCaseInstructionList.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_switchCaseListIR_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @switchCaseListIR-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mCaseIdentifierIndexes.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mCaseInstructionList.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uintlist GALGAS_switchCaseListIR_2D_element::getter_mCaseIdentifierIndexes (UNUSED_LOCATION_ARGS) const {
  return mProperty_mCaseIdentifierIndexes ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_instructionListIR GALGAS_switchCaseListIR_2D_element::getter_mCaseInstructionList (UNUSED_LOCATION_ARGS) const {
  return mProperty_mCaseInstructionList ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @switchCaseListIR-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_switchCaseListIR_2D_element ("switchCaseListIR-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_switchCaseListIR_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_switchCaseListIR_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_switchCaseListIR_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_switchCaseListIR_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_switchCaseListIR_2D_element GALGAS_switchCaseListIR_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_switchCaseListIR_2D_element result ;
  const GALGAS_switchCaseListIR_2D_element * p = (const GALGAS_switchCaseListIR_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_switchCaseListIR_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("switchCaseListIR-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_accessInAssignmentListAST_2D_element::GALGAS_accessInAssignmentListAST_2D_element (void) :
mProperty_mAccess () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_accessInAssignmentListAST_2D_element::~ GALGAS_accessInAssignmentListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_accessInAssignmentListAST_2D_element::GALGAS_accessInAssignmentListAST_2D_element (const GALGAS_accessInAssignmentAST & inOperand0) :
mProperty_mAccess (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_accessInAssignmentListAST_2D_element GALGAS_accessInAssignmentListAST_2D_element::constructor_new (const GALGAS_accessInAssignmentAST & inOperand0 
                                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_accessInAssignmentListAST_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_accessInAssignmentListAST_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_accessInAssignmentListAST_2D_element::objectCompare (const GALGAS_accessInAssignmentListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mAccess.objectCompare (inOperand.mProperty_mAccess) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_accessInAssignmentListAST_2D_element::isValid (void) const {
  return mProperty_mAccess.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_accessInAssignmentListAST_2D_element::drop (void) {
  mProperty_mAccess.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_accessInAssignmentListAST_2D_element::description (C_String & ioString,
                                                               const int32_t inIndentation) const {
  ioString << "<struct @accessInAssignmentListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mAccess.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_accessInAssignmentAST GALGAS_accessInAssignmentListAST_2D_element::getter_mAccess (UNUSED_LOCATION_ARGS) const {
  return mProperty_mAccess ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @accessInAssignmentListAST-element type                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_accessInAssignmentListAST_2D_element ("accessInAssignmentListAST-element",
                                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_accessInAssignmentListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_accessInAssignmentListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_accessInAssignmentListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_accessInAssignmentListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_accessInAssignmentListAST_2D_element GALGAS_accessInAssignmentListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                        C_Compiler * inCompiler
                                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_accessInAssignmentListAST_2D_element result ;
  const GALGAS_accessInAssignmentListAST_2D_element * p = (const GALGAS_accessInAssignmentListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_accessInAssignmentListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("accessInAssignmentListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST_2D_element::GALGAS_declarationListAST_2D_element (void) :
mProperty_mDeclaration () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST_2D_element::~ GALGAS_declarationListAST_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST_2D_element::GALGAS_declarationListAST_2D_element (const GALGAS_abstractDeclarationAST & inOperand0) :
mProperty_mDeclaration (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST_2D_element GALGAS_declarationListAST_2D_element::constructor_new (const GALGAS_abstractDeclarationAST & inOperand0 
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_declarationListAST_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_declarationListAST_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_declarationListAST_2D_element::objectCompare (const GALGAS_declarationListAST_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mDeclaration.objectCompare (inOperand.mProperty_mDeclaration) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_declarationListAST_2D_element::isValid (void) const {
  return mProperty_mDeclaration.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationListAST_2D_element::drop (void) {
  mProperty_mDeclaration.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_declarationListAST_2D_element::description (C_String & ioString,
                                                        const int32_t inIndentation) const {
  ioString << "<struct @declarationListAST-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mDeclaration.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_abstractDeclarationAST GALGAS_declarationListAST_2D_element::getter_mDeclaration (UNUSED_LOCATION_ARGS) const {
  return mProperty_mDeclaration ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @declarationListAST-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_declarationListAST_2D_element ("declarationListAST-element",
                                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_declarationListAST_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_declarationListAST_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_declarationListAST_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_declarationListAST_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_declarationListAST_2D_element GALGAS_declarationListAST_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_declarationListAST_2D_element result ;
  const GALGAS_declarationListAST_2D_element * p = (const GALGAS_declarationListAST_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_declarationListAST_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("declarationListAST-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

