// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueprintAsyncActionBase.h"

UMyBlueprintAsyncActionBase::UMyBlueprintAsyncActionBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer), WorldContextObject(nullptr), MyFloatInput(0.0f)
{
}

UMyBlueprintAsyncActionBase* UMyBlueprintAsyncActionBase::WaitForOneFrame(const UObject* WorldContextObject, const float SomeInputVariables)
{
	UMyBlueprintAsyncActionBase* BlueprintNode = NewObject<UMyBlueprintAsyncActionBase>();
	BlueprintNode->WorldContextObject = WorldContextObject;
	BlueprintNode->MyFloatInput = SomeInputVariables;
	return BlueprintNode;
}

void UMyBlueprintAsyncActionBase::Activate()
{
	WorldContextObject->GetWorld()->GetTimerManager().SetTimerForNextTick(this, &UMyBlueprintAsyncActionBase::ExecuteAfterOneFrame);
}

void UMyBlueprintAsyncActionBase::ExecuteAfterOneFrame()
{
	AfterOneFrame.Broadcast(MyFloatInput + 1.0f, MyFloatInput + 2.0f);
}