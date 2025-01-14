/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: ExifLibTest
*
*/
#include "ExifLibTestInc.h"

// Test cases modified for no jpeg parsing and no tag validity checking options

// Exif.Read.201
// Instantiate an Exif reader with valid Exif image
// Created Exif reader instance is returned.
void CExifReadTest::ExifRead201L()
	{
	HBufC8* exif = TUtils::ReadFileL(iFs, KFullExif, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking );
	if(!read)
		User::Leave(KErrGeneral);
	delete read;
	CleanupStack::PopAndDestroy(exif);
	}

// Exif.Read.202
// Try to instantiate an Exif reader with invalid/corrupted Exif image
// Leaves with proper error code or doesn't detect the error
void CExifReadTest::ExifRead202L()
	{
	// Various invalid/ corrupted Exif images
	HBufC8* exif = TUtils::ReadFileL(iFs, KInvalidExif1, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = 0;
    TRAPD( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif1 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif1 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::ReadFileL(iFs, KInvalidExif2, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif2 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif2 return no buffer"));
        }
        
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::CreateDummyBufL(120000);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
	if ( ( error != KErrCorrupt ) || ( read ) )
        {
        if ( read )
            {
            delete read;
            }
        if ( error )
            {
            User::Leave( error );
            }
		User::Leave(KErrGeneral);
        }
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::ReadFileL(iFs, KInvalidExif3, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif3 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif3 return no buffer"));
        }

    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::ReadFileL(iFs, KInvalidExif4, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif4 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif4 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::ReadFileL(iFs, KInvalidExif5, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif5 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif5 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::ReadFileL(iFs, KInvalidExif7, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif7 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif7 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::ReadFileL(iFs, KInvalidExif8, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif8 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif8 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::ReadFileL(iFs, KInvalidExif9, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif9 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif9 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::ReadFileL(iFs, KInvalidExif10, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif10 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif10 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::ReadFileL(iFs, KInvalidExif11, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif11 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif11 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::ReadFileL(iFs, KInvalidExif12, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif12 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif12 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::ReadFileL(iFs, KInvalidExif13, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif13 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif13 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

    /* Supported, but uncompressed thumbnail is skipped */
	exif = TUtils::ReadFileL(iFs, KNotSupportedExif1, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
	if ( ( error != KErrNone ) || ( !read ) )
        {
        if ( read )
            {
            delete read;
            }
        if ( error )
            {
            User::Leave( error );
            }
		User::Leave(KErrGeneral);
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KNotSupportedExif1 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KNotSupportedExif1 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

    /* Supported, but unsupported (uncompressed) thumbnail is skipped */
	exif = TUtils::ReadFileL(iFs, KNotSupportedExif2, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
	if ( ( error != KErrNone ) || ( !read ) )
        {
        if ( read )
            {
            delete read;
            }
        if ( error )
            {
            User::Leave( error );
            }
		User::Leave(KErrGeneral);
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KNotSupportedExif2 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KNotSupportedExif2 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);

    // Corrupted over 64k tag data
	exif = TUtils::ReadFileL(iFs, KInvalidExif14, 65536);
	CleanupStack::PushL(exif);
    TRAP( error, read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking) );
    if ( error ) // jpeg error detected
        {
    	if ( ( error != KErrCorrupt ) || ( read ) )
            {
            if ( read )
                {
                delete read;
                }
            if ( error )
                {
                User::Leave( error );
                }
    		User::Leave(KErrGeneral);
            }
        }
     else if( read )
        {
    	CleanupStack::PushL(read);
        TUtils::GetAllTagsTestL( read, KInvalidExif14 );
    	CleanupStack::Pop(read);
        }
     else 
        {
		RDebug::Print(_L("CExifReadTest::ExifRead202L(): KInvalidExif14 return no buffer"));
        }
    delete read;
    read = 0;
	CleanupStack::PopAndDestroy(exif);
	}


// Exif.Read.203
// Retrieve a tag existing in the specified IFD from Exif data.
// The requested tag instance (unmodifiable / const) is returned.
void CExifReadTest::ExifRead203L()
	{
	// For each IFD.
	HBufC8* exif = TUtils::ReadFileL(iFs, KFullExif, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

	const CExifTag* tag = read->GetTagL(EIfd0, KIdXResolution);
	if(!tag)
		User::Leave(KErrGeneral);

	tag = read->GetTagL(EIfdExif, KIdColorSpace);
	if(!tag)
		User::Leave(KErrGeneral);

	tag = read->GetTagL(EIfd1, KIdCompression);
	if(!tag)
		User::Leave(KErrGeneral);

	tag = read->GetTagL(EIfdIntOp, 1);
	if(!tag)
		User::Leave(KErrGeneral);

	tag = read->GetTagL(EIfdGps, KIdGpsVersion);
	if(!tag)
		User::Leave(KErrGeneral);

	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}


// Exif.Read.204
// Try to retrieve a tag which doesn't exist in the Exif data.
// Leaves with proper error code.
void CExifReadTest::ExifRead204L()
	{
	HBufC8* exif = TUtils::ReadFileL(iFs, KValidExif, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

	const CExifTag* tag = NULL;
	// IFD exists but tag doesn't exist, 
	TRAPD(error, tag = read->GetTagL(EIfd0, KIdArtist));
	if(error != KErrNotFound)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}

	// IFD doesn't exist
	TRAP(error, tag = read->GetTagL(EIfdGps, KIdGpsVersion));
	if(error != KErrNotFound)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}

	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}


// Exif.Read.205
// Try to retrieve a tag with invalid parameters.
// Leaves with proper error code.
void CExifReadTest::ExifRead205L()
	{
	HBufC8* exif = TUtils::ReadFileL(iFs, KFullExif, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

	const CExifTag* tag;
	// Tag ID is invalid 
	TRAPD(error, tag = read->GetTagL(EIfdExif, 200));
	if(error != KErrNotSupported)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}

	// Tag cannot exist in the specified IFD.
	TRAP(error, tag = read->GetTagL(EIfdGps, KIdImageDescription));
	if(error != KErrNotSupported)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}

	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}


// Exif.Read.206
// Retrieve the IDs of tags from an IFD in Exif data.
// Returns the tag IDs and the number of IDs
void CExifReadTest::ExifRead206L()
	{
	// For each IFD.
	HBufC8* exif = TUtils::ReadFileL(iFs, KFullExif, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

	TInt no = 0;
	TUint16* tags = read->GetTagIdsL(EIfd0, no);
	if((!tags) || (no != 14))
	{
		if(tags)
			delete tags;
		User::Leave(KErrGeneral);
	}
	delete tags;
	tags = 0;

	tags = read->GetTagIdsL(EIfdExif, no);
	if((!tags) || (no != 41))
	{
		if(tags)
			delete tags;
		User::Leave(KErrGeneral);
	}
	delete tags;
	tags = 0;

	tags = read->GetTagIdsL(EIfd1, no);
	if((!tags) || (no != 6))
	{
		if(tags)
			delete tags;
		User::Leave(KErrGeneral);
	}
	delete tags;
	tags = 0;

	tags = read->GetTagIdsL(EIfdIntOp, no);
	if((!tags) || (no != 4))
	{
		if(tags)
			delete tags;
		User::Leave(KErrGeneral);
	}
	delete tags;
	tags = 0;

	tags = read->GetTagIdsL(EIfdGps, no);
	if((!tags) || (no != 4))
	{
		if(tags)
			delete tags;
		User::Leave(KErrGeneral);
	}
	delete tags;
	tags = 0;

	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}


// Exif.Read.207
// Try to retrieve the IDs of tags from an IFD, which doesn't exist in Exif data.
// Leaves with proper error code.
void CExifReadTest::ExifRead207L()
	{
	HBufC8* exif = TUtils::ReadFileL(iFs, KValidExif, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

	TInt no = 0;
	TUint16* tags = NULL;
	TRAPD(error, tags = read->GetTagIdsL(EIfdGps, no));
	if(tags)
		delete tags;
	if(error != KErrNotFound)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}
	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}


// Exif.Read.208
// Retrieve the types of IFDs included in Exif data.
// Returns the IFD types and the number of IFDs.
void CExifReadTest::ExifRead208L()
	{
	HBufC8* exif = TUtils::ReadFileL(iFs, KValidExif, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

	TInt no = 0;
	TExifIfdType* ifds = read->GetIfdTypesL(no);
	if((!ifds) && (no != 4))
		{
		if(ifds)
			delete ifds;
		User::Leave(KErrGeneral);
		}
	delete ifds;
	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}


// Exif.Read.209
// Retrieve a copy of existing Exif thumbnail image from Exif data.
// Returns the Exif thumbnail image.
void CExifReadTest::ExifRead209L()
	{
	HBufC8* exif = TUtils::ReadFileL(iFs, KValidExif, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

	HBufC8* thumbnail = read->GetThumbnailL();
	if(!thumbnail)
		User::Leave(KErrGeneral);

	delete thumbnail;
	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}


// Exif.Read.210
// Try to retrieve a copy of Exif thumbnail image from Exif data that doesn't contain compressed Exif thumbnail image.
// Leaves with proper error code.
void CExifReadTest::ExifRead210L()
	{
	HBufC8* exif = TUtils::ReadFileL(iFs, KNoThumbnail, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

	HBufC8* thumbnail = NULL;
	TRAPD(error, thumbnail = read->GetThumbnailL());
	if(thumbnail)
		delete thumbnail;
	if(error != KErrNotFound)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}
	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}


// Exif.Read.211
// Check if an IFD exists in Exif data.
// Returns ETrue if specified IFD exists, EFalse otherwise.
void CExifReadTest::ExifRead211L()
	{
	// For each IFD
	HBufC8* exif = TUtils::ReadFileL(iFs, KValidExif, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

	// IFD exists,
	if(!read->IfdExists(EIfd0))
		User::Leave(KErrGeneral);
	if(!read->IfdExists(EIfdExif))
		User::Leave(KErrGeneral);
	if(!read->IfdExists(EIfd1))
		User::Leave(KErrGeneral);
	if(!read->IfdExists(EIfdIntOp))
		User::Leave(KErrGeneral);
	// IFD doesn't exist.
	if(read->IfdExists(EIfdGps))
		User::Leave(KErrGeneral);

	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}


// Exif.Read.212
// Check if a tag exists in the specified IFD of Exif data.
// Returns ETrue if tag exists in the specified IFD, EFalse otherwise.
void CExifReadTest::ExifRead212L()
	{
	// For each IFD;
	HBufC8* exif = TUtils::ReadFileL(iFs, KValidExif, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

	// Tag  exists in IFD, 
	if(!read->TagExists(KIdXResolution, EIfd0)) 
		User::Leave(KErrGeneral);
	if(!read->TagExists(KIdComponentsConfiguration, EIfdExif)) 
		User::Leave(KErrGeneral);
	if(!read->TagExists(1, EIfdIntOp)) 
		User::Leave(KErrGeneral);
	// IFD exists but tag doesn't exist,
	if(read->TagExists(KIdCopyright, EIfd1)) 
		User::Leave(KErrGeneral);
	// IFD doesn't exist
	if(read->TagExists(KIdGpsVersion, EIfdGps)) 
		User::Leave(KErrGeneral);

	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}


// Exif.Read.213
// Retrieve specific data using Get functions.
// Returns the requested data.
void CExifReadTest::ExifRead213L()
	{
	HBufC8* exif = TUtils::ReadFileL(iFs, KFullExif, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

	// For some Get functions.
	HBufC8* data = read->GetImageDescriptionL();
	if(!data)
		User::Leave(KErrGeneral);
	delete data;
	data = 0;

	data = read->GetMakeL();
	if(!data)
		User::Leave(KErrGeneral);
	delete data;
	data = 0;

	data = read->GetDateTimeOriginalL();
	if(!data)
		User::Leave(KErrGeneral);
	delete data;
	data = 0;

    data = read->GetTransferFunctionL();
	if(!data)
		User::Leave(KErrGeneral);
	delete data;
	data = 0;

    data = read->GetRelatedSoundFileL();
	if(!data)
		User::Leave(KErrGeneral);
	delete data;
	data = 0;

    data = read->GetModelL();
	if(!data)
		User::Leave(KErrGeneral);
	delete data;
	data = 0;

    data = read->GetMakerNoteL();
	if(!data)
		User::Leave(KErrGeneral);
	delete data;
	data = 0;

    data = read->GetIsoSpeedRatingsL();
	if(!data)
		User::Leave(KErrGeneral);
	delete data;
	data = 0;

    data = read->GetDateTimeDigitizedL();
	if(!data)
		User::Leave(KErrGeneral);
	delete data;
	data = 0;

    data = read->GetCopyrightL();
	if(!data)
		User::Leave(KErrGeneral);
	delete data;
	data = 0;


	TUint16 uInt16 = 0;
	TUint32 uInt32 = 0;
	TUint32 uInt32i = 0;
	TInt32 int32 = 0;
	TInt32 int32i = 0;
	TInt8 int8 = 0;
    TUint8 a1 = 0;
    TUint8 a2 = 0;
    TUint8 a3 = 0;
    TUint8 a4 = 0;

    User::LeaveIfError(read->GetExposureTime(uInt32, uInt32i));
    if((uInt32 != 0) || (uInt32i != 0))
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetShutterSpeedValue(int32, int32i));
    if((int32 != 0x00087383) || (int32i != 0x00010000))
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetBrightnessValue(int32, int32i));
    if((int32 != 0) || (int32i != 1))
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetCustomRendered(uInt16));
    if(uInt16 != 0)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetGainControl(uInt16));
    if(uInt16 != 0)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetGpsVersion(uInt32));
    if(uInt32 != 0x00000202)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetComponentsConfiguration(a1, a2, a3, a4));
    if((a1 != 1) || (a2 != 2) || (a3 != 3 ) || (a4 != 0))
        User::Leave(KErrGeneral);
	User::LeaveIfError(read->GetOrientation(uInt16));
	if(uInt16 != 1)
		User::Leave(KErrGeneral);
	User::LeaveIfError(read->GetXResolution(uInt32, uInt32i));
	if((uInt32 != 180) || (uInt32i != 1))
		User::Leave(KErrGeneral);
	User::LeaveIfError(read->GetExifIfdPointer(uInt32)); 
	if(uInt32 != 1798)
		User::Leave(KErrGeneral);
	User::LeaveIfError(read->GetFileSource(int8)); 
	if(int8 != 3)
		User::Leave(KErrGeneral);
	User::LeaveIfError(read->GetSharpness(uInt16)); 
	if(uInt16 != 0)
		User::Leave(KErrGeneral);
	User::LeaveIfError(read->GetExifVersion(uInt32)); 
	if(uInt32 != 0x30323230)
		User::Leave(KErrGeneral);
	User::LeaveIfError(read->GetThumbnailXResolution(uInt32, uInt32i));
	if((uInt32 != 180) || (uInt32i != 1))
		User::Leave(KErrGeneral);
	User::LeaveIfError(read->GetThumbnailCompression(uInt16)); 
	if(uInt16 != 6)
		User::Leave(KErrGeneral);
	User::LeaveIfError(read->GetJpegInterchangeFormat(uInt32)); 
	if(uInt32 != 2814)
		User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetWhiteBalance(uInt16));
    if(uInt16 != 0)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetSceneCaptureType(uInt16));
    if(uInt16 != 0)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetSaturation(uInt16));
    if(uInt16 != 0)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetMeteringMode(uInt16));
    if(uInt16 != 2)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetJpegInterchangeFormatLength(uInt32));
    if(uInt32 != 5342)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetInteroperabilityIfdPointer(uInt32));
    if(uInt32 != 2666)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetGpsInfoIfdPointer(uInt32));
    if(uInt32 != 2612)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetFlashPixVersion(uInt32));
    if(uInt32 != 0x30303130)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetExposureProgram(uInt16));
    if(uInt16 != 0)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetExposureMode(uInt16));
    if(uInt16 != 0)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetExposureBiasValue(int32, int32i));
    if((int32 != 0) || (int32i != 3))
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetContrast(uInt16));
    if(uInt16 != 0)
        User::Leave(KErrGeneral);
    User::LeaveIfError(read->GetApertureValue(uInt32, uInt32i));
    if((uInt32 != 262144) || (uInt32i != 65536))
        User::Leave(KErrGeneral);


	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}


// Exif.Read.214
// Try to retrieve specific data that is not present in the Exif data using Get functions.
// Leaves with or returns proper error code.
void CExifReadTest::ExifRead214L()
	{
	HBufC8* exif = TUtils::ReadFileL(iFs, KNoThumbnail, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

	// For some Get functions.
	HBufC8* data = NULL;
	TRAPD(error, data = read->GetSoftwareL());
	if(data)
		delete data;
	data = 0;
	if(error != KErrNotFound)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}
	TRAP(error, data = read->GetUserCommentL());
	if(data)
		delete data;
	data = 0;
	if(error != KErrNotFound)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}

	TUint16 uInt16 = 0;
	TUint32 uInt32 = 0;
	TUint32 uInt32i = 0;
	TInt8 int8 = 0;
	error = read->GetLightSource(uInt16); 
	if(error != KErrNotFound)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}
	error = read->GetFileSource(int8);
	if(error != KErrNotFound)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}
	error = read->GetDigitalZoomRatio(uInt32, uInt32i); 
	if(error != KErrNotFound)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}
	error = read->GetThumbnailCompression(uInt16);
	if(error != KErrNotFound)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}
	error = read->GetJpegInterchangeFormat(uInt32);
	if(error != KErrNotFound)
		{
		if(error)
			User::Leave(error);
		else
			User::Leave(KErrGeneral);
		}

	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}

// Exif.Read.216
// Retrieve the Exif APP1 segment.
// Returns the whole Exif APP1 segment.
void CExifReadTest::ExifRead216L()
	{
    
	HBufC8* exif = TUtils::ReadFileL(iFs, KValidExif, 65536);
	CleanupStack::PushL(exif);
	CExifRead* read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

    HBufC8* appSegment = read->GetExifAppSegmentL();
    CleanupStack::PushL( appSegment );
    if ( appSegment->Length() != 12670 )
        {
        User::Leave( KErrGeneral );
        }
    if ( *appSegment->Ptr() != 0xff )
        {
        User::Leave( KErrGeneral );
        }
    if ( *( appSegment->Ptr() + appSegment->Length() - 1 ) != 0xd9 )
        {
        User::Leave( KErrGeneral );
        }
    CleanupStack::PopAndDestroy( appSegment );

	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);

	exif = TUtils::ReadFileL(iFs, KFullExif, 65536);
	CleanupStack::PushL(exif);
	read = CExifRead::NewL(*exif, CExifRead::ENoJpeg | CExifRead::ENoTagChecking);
	CleanupStack::PushL(read);

    appSegment = read->GetExifAppSegmentL();
    CleanupStack::PushL( appSegment );
    if ( appSegment->Length() != 8166 )
        {
        User::Leave( KErrGeneral );
        }
    if ( *appSegment->Ptr() != 0xff )
        {
        User::Leave( KErrGeneral );
        }
    if ( *( appSegment->Ptr() + appSegment->Length() - 1 ) != 0xd9 )
        {
        User::Leave( KErrGeneral );
        }
    CleanupStack::PopAndDestroy( appSegment );

	CleanupStack::PopAndDestroy(read);
	CleanupStack::PopAndDestroy(exif);
	}

// Exif.Read.215
// Test the behavior of the previous test cases in OOM situations.
// Successfully operates or leaves with OOM error, without any memory leaks.
void CExifReadTest::ExifRead215L()
	{
	// OOM in EXIF.READ.201- EXIF.READ.216
	TInt error = KErrGeneral;
	TInt i = 0;

	RDebug::Print(_L("ExifRead201L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead201L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead102L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
//	RDebug::Print((_L("ExifRead102L() memory test i=%d")),i);
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead102L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead103L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead103L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead104L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead104L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead105L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead105L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead106L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead106L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead107L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead107L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead108L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead108L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead109L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead109L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead210L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead210L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead211L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead211L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead212L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead212L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead213L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead213L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead214L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead214L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	RDebug::Print(_L("ExifRead216L() memory test"));
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
	for(i = 1; i < 500; i++)
#else
    for(i = 1; i < 10; i++)
#endif
		{
		__UHEAP_MARK;
#if ( ( defined __WINS__ ) || ( defined __WINSCW__) )
		__UHEAP_SETFAIL( RHeap::EFailNext, i );
#else
        __UHEAP_SETFAIL( RHeap::ERandom, i );
#endif
		TRAP(error, ExifRead216L());
		if(error)
			{
			if(error != KErrNoMemory)
				{
	            RDebug::Print((_L("ExifRead215L() TRAP error=%d")),error);
				__UHEAP_SETFAIL( RHeap::ENone, 0 );
				User::Leave(KErrGeneral);
				}
			}
		else
			{
			__UHEAP_MARKEND;
			break;
			}
		__UHEAP_MARKEND;
		}

	__UHEAP_SETFAIL( RHeap::ENone, 0 );
	}

