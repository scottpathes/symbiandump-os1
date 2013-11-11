// pcredllmain.cpp
//
// Copyright (c) 2009 - 2010 Accenture. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Accenture nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

//  Include Files  
#include <e32std.h>		 // GLDEF_C

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "pcre_internal.h"

//  Exported Functions

PCRE_EXP_DEFN void* PCRE_CALL_CONVENTION pcre_malloc(size_t nBytes)
	{
	return User::Alloc(nBytes);
	}

PCRE_EXP_DEFN void PCRE_CALL_CONVENTION pcre_free(void* p)
	{
	User::Free(p);
	}

PCRE_EXP_DEFN void* PCRE_CALL_CONVENTION pcre_stack_malloc(size_t nBytes)
	{
	return User::Alloc(nBytes);
	}

PCRE_EXP_DEFN void PCRE_CALL_CONVENTION pcre_stack_free(void* p)
	{
	User::Free(p);
	}

PCRE_EXP_DEFN int PCRE_CALL_CONVENTION pcre_callout(pcre_callout_block *)
	{
	return 0;
	}