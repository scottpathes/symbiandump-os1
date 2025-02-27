// Copyright (c) 2006-2010 Nokia Corporation and/or its subsidiary(-ies).
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
// This file was generated automatically from the template commandsource.tmpl
// on Fri, 26 Mar 2010 16:16:13 (time stamp)
// 
//

/**
 @file
 @internalComponent
*/

#include <bluetooth/hci/switchrolecommand.h>
#include <bluetooth/hci/event.h>
#include <bluetooth/hci/commandcompleteevent.h>
#include <bluetooth/hci/hciframe.h>
#include <bluetooth/hci/hciopcodes.h>
#include <bluetooth/hci/rolechangeevent.h>


#ifdef __FLOG_ACTIVE
_LIT8(KLogComponent, LOG_COMPONENT_COMMANDSEVENTS_SYMBIAN);
#endif



// Factory methods

EXPORT_C CSwitchRoleCommand* CSwitchRoleCommand::NewL(const TBTDevAddr& aBDADDR, TUint8 aRole)
	{
	CSwitchRoleCommand* self = new (ELeave) CSwitchRoleCommand(aBDADDR, aRole);
	CleanupStack::PushL(self);
	self->CHCICommandBase::BaseConstructL();
	CleanupStack::Pop(self);
	return self;
	}

EXPORT_C CSwitchRoleCommand* CSwitchRoleCommand::NewL()
	{
	CSwitchRoleCommand* self = new (ELeave) CSwitchRoleCommand();
	CleanupStack::PushL(self);
	self->CHCICommandBase::BaseConstructL();
	CleanupStack::Pop(self);
	return self;
	}

// Constructors

CSwitchRoleCommand::CSwitchRoleCommand(const TBTDevAddr& aBDADDR, TUint8 aRole)
	: CHCICommandBase(KSwitchRoleOpcode)
	, iBDADDR(aBDADDR)
	, iRole(aRole)
	{
	SetExpectsCommandCompleteEvent(EFalse);
	}

CSwitchRoleCommand::CSwitchRoleCommand()
	: CHCICommandBase(KSwitchRoleOpcode)
	{
	SetExpectsCommandCompleteEvent(EFalse);
	}

// Destructor
CSwitchRoleCommand::~CSwitchRoleCommand()
	{
	
	}	

/*virtual*/ void CSwitchRoleCommand::Match(const THCIEventBase& aEvent, TBool& aMatchesCmd, TBool& aConcludesCmd, TBool& aContinueMatching) const
	{
	if (aEvent.EventCode() == ERoleChangeEvent)
		{
		TRoleChangeEvent& event = TRoleChangeEvent::Cast(aEvent);
		if (event.BDADDR() == BDADDR())
			{
			aMatchesCmd = ETrue;
			aConcludesCmd = ETrue;
			aContinueMatching = EFalse;
			}
		}
	// Command Status Event and default Command Complete Event matching
	// is implemented in the base class.  If we haven't matched already
	// then we should try the default matching.
	if (!aMatchesCmd)
		{
		CHCICommandBase::Match(aEvent, aMatchesCmd, aConcludesCmd, aContinueMatching);
		}
	}
	

// Override of pure virtual from CHCICommandBase. This method embodies the knowledge
// of how to format the specifics of this command into the HCTL command frame.
void CSwitchRoleCommand::Format(CHctlCommandFrame& aCommandFrame) const
	{
	aCommandFrame.PutDevAddr(iBDADDR);
	aCommandFrame.PutByte(iRole);
	}

// Assign new values to the parameters of this command
EXPORT_C void CSwitchRoleCommand::Reset(const TBTDevAddr& aBDADDR, TUint8 aRole)
	{
	iBDADDR = aBDADDR;
	iRole = aRole;
	}

// Accessor methods for the parameters of the command

EXPORT_C TBTDevAddr CSwitchRoleCommand::BDADDR() const
	{
	return iBDADDR;
	}

EXPORT_C TUint8 CSwitchRoleCommand::Role() const
	{
	return iRole;
	}



// Extension function.  Use this to retrieve any extension interfaces from CSwitchRoleCommand
// or any class from which it derives.
/*virtual*/ TInt CSwitchRoleCommand::Extension_(TUint aExtensionId, TAny*& aInterface, TAny* aData)
	{
	// To add an additional interface implementation specific for this class check the 
	// provided ID and return an appropriate interface.

	// If a specific interface implementation is not provided - forward the call to the base class.
	return CHCICommandBase::Extension_(aExtensionId, aInterface, aData);
	}

