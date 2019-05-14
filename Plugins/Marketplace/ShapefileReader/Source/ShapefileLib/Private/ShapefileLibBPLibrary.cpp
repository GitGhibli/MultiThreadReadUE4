// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#include "ShapefileLibBPLibrary.h"
#include "ShapefileLib.h"
#include "ThirdParty/ShapeLib/shapefil.h"
#include "DBFHandler.h"

#include "ShapefileHandler.h"


UShapefileLibBPLibrary::UShapefileLibBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

bool UShapefileLibBPLibrary::OpenShapefile(const FString& Path, UShapefileHandler*& Handler)
{
	SAHooks sHooks;

	SASetupDefaultHooks(&sHooks);

	//SHPOpenLLEx rebuilds SHX if not present
	const SHPHandle handle = SHPOpenLLEx(TCHAR_TO_ANSI(*Path), "rb", &sHooks, 1);

	if(handle != nullptr)
	{
		Handler = NewObject<UShapefileHandler>();
		Handler->SetHandler(handle);

		return true;
	}
	return false;
}

bool UShapefileLibBPLibrary::OpenDBF(const FString& Path, UDBFHandler*& Handler)
{
	const DBFHandle handle = DBFOpen(TCHAR_TO_ANSI(*Path), "rb");

	if (handle != nullptr)
	{
		Handler = NewObject<UDBFHandler>();
		Handler->SetHandler(handle);

		return true;
	}
	return false;
}



