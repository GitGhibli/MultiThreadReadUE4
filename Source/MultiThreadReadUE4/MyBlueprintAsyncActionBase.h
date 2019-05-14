// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MyBlueprintAsyncActionBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelayOneFrameOutputPin, float, InputFloatPlusOne, float, InputFloatPlusTwo);

UCLASS()
class MULTITHREADREADUE4_API UMyBlueprintAsyncActionBase : public UBlueprintAsyncActionBase
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(BlueprintAssignable)
	FDelayOneFrameOutputPin AfterOneFrame;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "Flow Control")
	static UMyBlueprintAsyncActionBase* WaitForOneFrame(const UObject* WorldContextObject, const float SomeInputVariables);

	virtual void Activate() override;
private:
	UFUNCTION()
		void ExecuteAfterOneFrame();


private:
	const UObject* WorldContextObject;
	float MyFloatInput;
};
