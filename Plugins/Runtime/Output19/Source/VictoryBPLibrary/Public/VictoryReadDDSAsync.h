// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "VictoryReadDDSAsync.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTexturesReady, UTexture2D*, Result);

UCLASS()
class VICTORYBPLIBRARY_API UVictoryReadDDSAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintAssignable)
	FTexturesReady OnTexturesReady;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Flow Control")
	static UVictoryReadDDSAsync* ReadDDSTexturesAsync(const UObject* WorldContextObject, TArray<FString> PathToFileInput);

	virtual void Activate() override;

private:
	//Output value
	UTexture2D* Texture;

	//Input values
	const UObject* WorldContextObject;
	TArray<FString> PathsToFiles;
};
