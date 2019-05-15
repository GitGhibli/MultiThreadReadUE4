// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShapefileHandler.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ShapefileSHPReadAsync.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FShapeFilesReady, const TArray<UShapefileHandler*>&, Result);

UCLASS()
class SHAPEFILELIB_API UShapefileSHPReadAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable)
	FShapeFilesReady OnFilesReady;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Flow Control")
	static UShapefileSHPReadAsync* ReadShapeFilesSHPAsync(const UObject* WorldContextObject, TArray<FString> PathToFileInput);

	virtual void Activate() override;

private:
	//Output value
	TArray<UShapefileHandler*> ResultFiles;

	//Input values
	const UObject* WorldContextObject;
	TArray<FString> PathsToFiles;
};
