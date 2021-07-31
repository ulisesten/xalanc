/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the  "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#if !defined(XALAN_ELEMVALUEOF_HEADER_GUARD)
#define XALAN_ELEMVALUEOF_HEADER_GUARD 



// Base include file.  Must be first.
#include "XSLTDefinitions.hpp"



// Base class header file.
#include "ElemTemplateElement.hpp"



namespace XALAN_CPP_NAMESPACE {



class XObjectPtr;
class XPath;



class ElemValueOf : public ElemTemplateElement
{
public:

    /**
     * Construct an object corresponding to an "xsl:value-of" element
     * 
     * @param constructionContext context for construction of object
     * @param stylesheetTree      stylesheet containing element
     * @param atts                list of attributes for element
     * @param lineNumber                line number in document
     * @param columnNumber          column number in document
     */
    ElemValueOf(
            StylesheetConstructionContext&  constructionContext,
            Stylesheet&                     stylesheetTree,
            const AttributeListType&        atts,
            XalanFileLoc                    lineNumber, 
            XalanFileLoc                    columnNumber);

    virtual
    ~ElemValueOf();

    // These methods are inherited from ElemTemplateElement ...

    virtual const XalanDOMString&
    getElementName() const;

#if !defined(XALAN_RECURSIVE_STYLESHEET_EXECUTION)
    virtual const ElemTemplateElement*
    startElement(StylesheetExecutionContext&        executionContext) const;
#else
    virtual void
    execute(StylesheetExecutionContext&     executionContext) const;
#endif
    virtual const XPath*
    getXPath(XalanSize_t    index) const;

private:

    void
    fireSelectionEvent(
            StylesheetExecutionContext&     executionContext,
            XalanNode*                      sourceNode,
            const XalanDOMString&           theValue) const;

    void
    fireSelectionEvent(
            StylesheetExecutionContext&     executionContext,
            XalanNode*                      sourceNode,
            const XObjectPtr                theValue) const;

    void
    fireSelectionEvent(
            StylesheetExecutionContext&     executionContext,
            XalanNode*                      sourceNode,
            const XObjectPtr                theValue,
            const XalanDOMString&           thePattern) const;


    /**
     * The select pattern used to locate the value.
     */
    const XPath*    m_selectPattern;
};



}



#endif  // XALAN_ELEMVALUEOF_HEADER_GUARD
