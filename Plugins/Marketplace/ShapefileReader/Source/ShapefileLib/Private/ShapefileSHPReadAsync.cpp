#include "ShapefileSHPReadAsync.h"

#include "ShapefileLibBPLibrary.h"
#include "Future.h"
#include "Async.h"
#include "ShapefileSHPReadAsync.h"

UShapefileSHPReadAsync* UShapefileSHPReadAsync::ReadShapeFilesSHPAsync(const UObject * WorldContextObject, TArray<FString> PathsToFilesInput)
{
	auto blueprintNode = NewObject<UShapefileSHPReadAsync>();
	blueprintNode->WorldContextObject = WorldContextObject;
	blueprintNode->PathsToFiles = PathsToFilesInput;
	return blueprintNode;
}

void UShapefileSHPReadAsync::Activate()
{
	TFuture<void> future = Async<void>(EAsyncExecution::ThreadPool, [&]
	{
		for (auto path : PathsToFiles) {
			UShapefileHandler* handler;
			UShapefileLibBPLibrary::OpenShapefile(path, handler);
			ResultFiles.Add(handler);
		}
	},
		[&] {
		OnFilesReady.Broadcast(ResultFiles);
	});
}