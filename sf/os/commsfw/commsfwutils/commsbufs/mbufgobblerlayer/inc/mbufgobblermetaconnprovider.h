// Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// Meta Connection Provider
//  (management plane)
//
//
//  This is a 3-plane comms layer implementation example, which has been customised to be a test layer which gobbles and releases ESOCK MBUFs.
//  The MBuf gobbling functionality can be disabled by undefining the macro SYMBIAN_COMMSFW_MBUF_GOBBLER which is specified in mbufgobblerproviders.mmp.
//  When SYMBIAN_COMMSFW_MBUF_GOBBLER is undefined, the source code specified by mbufgobblerproviders.mmp becomes a pass through layer i.e. it passes the data
//  through to the layer above or below without altering it. This makes it useful as a starting point for implementing your own layers / providers;
//  useful documentation on how to customise your own passthrough layer can be found in ..\docs\MbufGobblerLayer.doc
//

/**
 @file
 @internalComponent
*/

#ifndef MBUFGOBBLERMETACONNPROVIDER_H
#define MBUFGOBBLERMETACONNPROVIDER_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>
#include <comms-infras/coremcpr.h>
#include "mbufgobblertestflags.h"

// CLASS DECLARATION

/**
 *  CMbufGobblerMetaConnectionProvider
 * 
 */
	
class CMbufGobblerMetaConnectionProvider : public CCoreMetaConnectionProvider
	{
public:
	static CMbufGobblerMetaConnectionProvider* NewL(ESock::CMetaConnectionProviderFactoryBase& aFactory,
											const ESock::TProviderInfo& aProviderInfo);
	~CMbufGobblerMetaConnectionProvider();
	 
protected:
	CMbufGobblerMetaConnectionProvider(ESock::CMetaConnectionProviderFactoryBase& aFactory,
	const ESock::TProviderInfo& aProviderInfo, const MeshMachine::TNodeActivityMap& aActivityMap);

	void ConstructL();
	
	// From MCFNode Interface 
	void ReceivedL(const Messages::TRuntimeCtxId& aSender, const Messages::TNodeId& aRecipient, Messages::TSignatureBase& aCFMessage);
private:
	TInt iClientCount; //holds count of clients that node is joined with
	MBUFGOBBLER_TEST_DATA	
	};


#endif // MBUFGOBBLERMETACONNPROVIDER_H
