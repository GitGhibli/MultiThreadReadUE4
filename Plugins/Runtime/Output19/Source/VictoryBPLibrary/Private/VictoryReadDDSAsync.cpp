// Fill out your copyright notice in the Description page of Project Settings.

#include "VictoryBPLibraryPrivatePCH.h"

#include "VictoryBPFunctionLibrary.h"
#include "VictoryReadDDSAsync.h"

UVictoryReadDDSAsync * UVictoryReadDDSAsync::ReadDDSTexturesAsync(const UObject * WorldContextObject, TArray<FString> PathsToFilesInput)
{
	auto blueprintNode = NewObject<UVictoryReadDDSAsync>();
	blueprintNode->WorldContextObject = WorldContextObject;
	blueprintNode->PathsToFiles = PathsToFilesInput;
	return blueprintNode;
}

void UVictoryReadDDSAsync::Activate()
{
	TFuture<void> future = Async<void>(EAsyncExecution::ThreadPool, [&]
	{
		for (auto path : PathsToFiles) {
			ResultTextures.Add(UVictoryBPFunctionLibrary::LoadTexture2D_FromDDSFile(path));
		}
	},
		[&] {
		OnTexturesReady.Broadcast(ResultTextures);
	});
}