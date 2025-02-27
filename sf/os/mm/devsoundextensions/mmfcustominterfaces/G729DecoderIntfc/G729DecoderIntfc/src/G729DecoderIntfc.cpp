/*
* Copyright (c) 2002-2006 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:   Interface definition for G729 decoder interface.
*
*/



// INCLUDE FILES
#include "G729DecoderIntfcProxy.h"
#include "G729DecoderIntfc.h"

#include <mdaaudiooutputstream.h>
#include <sounddevice.h>

// EXTERNAL DATA STRUCTURES

// EXTERNAL FUNCTION PROTOTYPES  

// CONSTANTS

// MACROS

// LOCAL CONSTANTS AND MACROS

// MODULE DATA STRUCTURES

// LOCAL FUNCTION PROTOTYPES

// FORWARD DECLARATIONS

// ============================= LOCAL FUNCTIONS ===============================

// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CG729DecoderIntfc::NewL
// Creates the custom interface.
// Calls the custom interface method on the devsound passed in.
// Devsound will return the handle to the custom interface proxy.
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C CG729DecoderIntfc* 
CG729DecoderIntfc::NewL(CMMFDevSound& aDevSound)
    {
    CG729DecoderIntfcProxy* g729DecoderIntfcProxy;
    g729DecoderIntfcProxy = 
        (CG729DecoderIntfcProxy*)aDevSound.CustomInterface(
                                           KUidG729DecoderIntfc);
    if (!g729DecoderIntfcProxy)
        {
        User::Leave(KErrNotFound);
        }
    return g729DecoderIntfcProxy;
    }

// -----------------------------------------------------------------------------
// CG729DecoderIntfc::NewL
// Creates the custom interface.
// Calls the custom interface method on the CMdaAudioOutputStream passed in.
// The CMdaAudioOutputStream utility will return the handle to the custom 
// interface proxy.
// (other items were commented in a header).
// -----------------------------------------------------------------------------
//
EXPORT_C CG729DecoderIntfc* 
CG729DecoderIntfc::NewL(CMdaAudioOutputStream& aUtility)
    {
    CG729DecoderIntfcProxy* g729DecoderIntfcProxy;
    g729DecoderIntfcProxy = 
        (CG729DecoderIntfcProxy*)aUtility.CustomInterface(
                                          KUidG729DecoderIntfc);
    if (!g729DecoderIntfcProxy)
        {
        User::Leave(KErrNotFound);
        }
    return g729DecoderIntfcProxy;
    }
    
// ========================== OTHER EXPORTED FUNCTIONS =========================

//  End of File  
