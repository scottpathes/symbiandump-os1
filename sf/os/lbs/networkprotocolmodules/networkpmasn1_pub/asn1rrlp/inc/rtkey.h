// Copyright (c) 2001-2009 Objective Systems, Inc. (http://www.obj-sys.com) 
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available 
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//

/**
 * This file was generated by the Objective Systems ASN1C Compiler
 * (http://www.obj-sys.com).
 */
#ifndef _RTKEY_H_
#define _RTKEY_H_

static const unsigned char _rtkey[] = {
0x50, 0x65, 0xdb, 0x99, 0x8d, 0x2c, 0xb7, 0xae, 
0xd4, 0xb4, 0xf7, 0x60, 0xb3, 0x6e, 0x9e, 0xb4, 
0x0b, 0xbf, 0xfa, 0x08, 0x45, 0x22, 0x5a, 0xb0, 
0x42, 0x09, 0x8b, 0x42, 0xa3, 0xbd, 0x6d, 0x92, 
0xe8, 0xda, 0x75, 0xa5, 0x8b, 0xac, 0xc5, 0x43, 
0x89, 0x5e, 0x40, 0x30, 0x4c, 0x42, 0xf4, 0x94, 
0x53, 0xa5, 0xf7, 0xe4, 0x33, 0x31, 0x71, 0xe3, 
0xd1, 0x86, 0x31, 0x8d, 0x20, 0xfb, 0x91, 0x3d, 
0xa2, 0x89, 0x77, 0x13, 0xd9, 0xe0, 0x07, 0xa1, 
0x1b, 0x71, 0xce, 0xe5, 0x84, 0x5b, 0x33, 0xfc, 
0xf8, 0x93, 0xad, 0x31, 0x42, 0x99, 0x68, 0x89
} ;
#define rtInitContext(pctxt) \
rtInitContextUsingKey(pctxt,_rtkey,sizeof(_rtkey))

#define rtNewContext() \
rtNewContextUsingKey(_rtkey,sizeof(_rtkey))

#endif