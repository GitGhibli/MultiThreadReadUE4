// Fill out your copyright notice in the Description page of Project Settings.

#include "VictoryBPLibraryPrivatePCH.h"

#include "VictoryBPLibrary.h"
#include "VictoryReadDDSAsync.h"

UVictoryReadDDSAsync * UVictoryReadDDSAsync::ReadDDSTexturesAsync(const UObject * WorldContextObject, const FString PathToFileInput)
{
	auto blueprintNode = NewObject<UVictoryReadDDSAsync>();
	blueprintNode->WorldContextObject = WorldContextObject;
	blueprintNode->PathToFile = PathToFileInput;
	return blueprintNode;
}

void UVictoryReadDDSAsync::Activate()
{
	Future = Async<void>(EAsyncExecution::ThreadPool, [&]
	{
		UE_LOG(LogTemp, Warning, TEXT("Inside Lambda function"));

		Texture = nullptr;
		for (int i = 0; i < 5; i++) {
			Texture = UVictoryBPFunctionLibrary::LoadTexture2D_FromDDSFile(PathToFile);
		}

		Result = 9027;

		UE_LOG(LogTemp, Warning, TEXT("For Loop Ended"));
	},
		[&] {
		UE_LOG(LogTemp, Warning, TEXT("Callback Function called"));
		OnTexturesReady.Broadcast(Texture);
	});
}