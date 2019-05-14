// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ShapefileHandler.h"
#include "DBFHandler.h"
#include "ShapefileLibBPLibrary.generated.h"



UCLASS()
class UShapefileLibBPLibrary : public UBlueprintFunctionLibrary
{
GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Open Shapefile", Keywords = "Shapefile open"), Category = "ShapefileLib")
	static bool OpenShapefile(const FString& Path, UShapefileHandler*& Handler);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Open DBF", Keywords = "DBF open"), Category = "ShapefileLib")
	static bool OpenDBF(const FString& Path, UDBFHandler*& Handler);
};
