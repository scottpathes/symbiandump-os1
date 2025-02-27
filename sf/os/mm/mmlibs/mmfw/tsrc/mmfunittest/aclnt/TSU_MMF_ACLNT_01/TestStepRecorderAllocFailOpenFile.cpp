// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// TestStepRecorderAllocFailOpenDesc.cpp
// 
//

#include <e32base.h>
#include <f32file.h>
#include <testframework.h>

#include "TestStepUnitMMFAudClient.h"
#include "TestSuiteUnitMMFAudClient.h"
#include "TestStepRecorderAllocFail.h"
// --------------------------------------------


/*
 *
 * Static constructor for CTestStepRecorderAllocFailOpenFile.
 *
 *
 * @return	"CTestStepRecorderAllocFailOpenFile*"
 *			The constructed CTestStepRecorderAllocFailOpenFile
 *
 * @xxxx
 * 
 */
CTestStepRecorderAllocFailOpenFile* CTestStepRecorderAllocFailOpenFile::NewL(TBool aUseFileHandle)
	{
	CTestStepRecorderAllocFailOpenFile* self = new(ELeave) CTestStepRecorderAllocFailOpenFile;
	if (aUseFileHandle)
		{
		self->iTestStepName = _L("MM-MMF-ACLNT-U-0120-CP");
		}
	else
		{
		self->iTestStepName = _L("MM-MMF-ACLNT-U-0301-CP");
		}
	self->iUseFileHandle = aUseFileHandle;
	self->iHeapSize = 100000;
	return self;
	}

/**
 *
 * Test step Preamble.
 *
 * @xxxx
 * 
 */
enum TVerdict CTestStepRecorderAllocFailOpenFile::DoTestStepPreambleL(void)
	{
	// Printing to the console and log file
	INFO_PRINTF1(iTestStepName);
	INFO_PRINTF1(_L("This is Alloc failure test of CMMFMdaAudioRecorderUtility::OpenDesL"));

	if(!GetStringFromConfig(_L("SectionOne"), _L("AudioPlayFName7"), iFileName))
		{
		INFO_PRINTF1(_L("file not found: "));
		INFO_PRINTF1(iFileName);
		return EInconclusive;
		}

	// this installs the scheduler
	return CTestStepUnitMMFAudClient::DoTestStepPreambleL();
	}

/**
 *
 * Test step Postamble.
 *
 * @xxxx
 * 
 */
enum TVerdict CTestStepRecorderAllocFailOpenFile::DoTestStepPostambleL(void)
	{
	delete iRecorder; iRecorder = NULL;

	iFile.Close();
	iFs.Close();
	//[ Destroy the scheduler ]
	return CTestStepUnitMMFAudClient::DoTestStepPostambleL();
	}

/**
 *
 * Callback Handle.
 *
 * @xxxx
 * 
 */
void CTestStepRecorderAllocFailOpenFile::MoscoStateChangeEvent(CBase* /*aObject*/,
													  TInt /*aPreviousState*/,
													  TInt /*aCurrentState*/,
													  TInt aErrorcCode)
	{
#ifdef __WINS__
	iKErrGeneralIgnored = EFalse;
	if ( aErrorcCode == KErrGeneral )
		iKErrGeneralIgnored = ETrue; //Ignore KErrGeneral on EMULATOR
#endif

	if ( aErrorcCode == KErrNone || aErrorcCode == KErrNoMemory )
		{
		iAllocOK = ETrue;
		if ( aErrorcCode == KErrNone && iRecorder->State() == CMdaAudioRecorderUtility::EOpen )
			iResultOK = ETrue;
		}
	else 
		iAllocOK = EFalse;
	
	CActiveScheduler::Stop();
	}

/**
 *
 * Do the test step.
 * Each test step must supply an implementation for DoTestStepL.
 *
 * @return	"TVerdict"
 *			The result of the test step
 *
 * @xxxx
 * 
 */
TVerdict CTestStepRecorderAllocFailOpenFile::DoTestStepL()
	{
	iAllocOK = ETrue;
	iResultOK = EFalse;
	TInt count;

	INFO_PRINTF1(_L("Testing CMdaAudioRecorderUtility::OpenFileL()"));
		
	__MM_HEAP_MARK;

	//create the player, leave if unsuccessful
	iRecorder = CMdaAudioRecorderUtility::NewL(*this);
	
	if (iUseFileHandle)
		{
		User::LeaveIfError(iFs.Connect());
		User::LeaveIfError(iFs.ShareProtected());
		User::LeaveIfError(iFile.Open(iFs,iFileName, EFileRead));
		}

	TInt error = KErrNone;
	TBool finished = EFalse;


	for( count = 0; iAllocOK && !finished; count++ )
		{
		__MM_HEAP_MARK;

		User::__DbgSetAllocFail(RHeap::EUser,RHeap::EFailNext,count);
		if (iUseFileHandle)
			{
			TRAP( error, iRecorder->OpenFileL( iFile ) );
			}
		else
			{
			TRAP( error, iRecorder->OpenFileL( iFileName ) );
			}
		if ( error != KErrNone && error != KErrNoMemory )
			iAllocOK = EFalse;

		if ( error == KErrNone )
			CActiveScheduler::Start();

		iRecorder->Close();
		TAny *testAlloc = User::Alloc(1); // when this fails, we passed through all allocs within test
		if ( testAlloc == NULL )
			{
			finished = ETrue;
			}
		User::Free(testAlloc);
		__MM_HEAP_MARKEND;
		}
	User::__DbgSetAllocFail(RHeap::EUser,RHeap::EFailNext,NULL);

	delete iRecorder; iRecorder = NULL;
	__MM_HEAP_MARKEND;

	//determine result and print info
	iTestStepResult = EFail;
	if (iAllocOK)
		{
		if (iResultOK)
			{
			INFO_PRINTF2(_L("Completed OK with %d memory allocations tested"),count);
			iTestStepResult = EPass;
			}
		else
			{
			INFO_PRINTF2(_L("Bad result with %d memory allocations tested"),count);
			}
		}
	else
		{
		INFO_PRINTF2(_L("Error occured with %d memory allocations tested"),count);
#ifdef __WINS__
		//Ignore KErrGeneral on EMULATOR
		if ( iKErrGeneralIgnored )
			{
			INFO_PRINTF1(_L("KErrGeneral has been ignored on EMULATOR"));
			INFO_PRINTF1(_L("Subsequent steps may fail with KErrGeneral"));
			iTestStepResult = EPass;
			}
#endif
		}
	
	INFO_PRINTF1(_L("Finished with this test step"));
	return iTestStepResult;
	}




