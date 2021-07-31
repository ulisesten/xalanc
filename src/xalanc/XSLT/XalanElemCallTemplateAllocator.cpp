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

// Class header file.
#include "XalanElemCallTemplateAllocator.hpp"



namespace XALAN_CPP_NAMESPACE {



XalanElemCallTemplateAllocator::XalanElemCallTemplateAllocator(
            MemoryManager&  theManager,
            size_type           theBlockCount) :
    m_allocator(
        theManager,
        theBlockCount)
{
}



XalanElemCallTemplateAllocator::~XalanElemCallTemplateAllocator()
{
}



XalanElemCallTemplateAllocator::data_type*
XalanElemCallTemplateAllocator::create(
            StylesheetConstructionContext&  constructionContext,
            Stylesheet&                     stylesheetTree,
            const AttributeListType&        atts,
            XalanFileLoc                    lineNumber,
            XalanFileLoc                    columnNumber)
{
    data_type* const    theBlock = m_allocator.allocateBlock();
    assert(theBlock != 0);

    data_type* const    theResult =
        new(theBlock) data_type(
                constructionContext,
                stylesheetTree,
                atts,
                lineNumber,
                columnNumber);

    m_allocator.commitAllocation(theBlock);

    return theResult;
}



}