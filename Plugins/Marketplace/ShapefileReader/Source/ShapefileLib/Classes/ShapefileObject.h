// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#pragma once
#include "shapefil.h"
#include "ShapefileHandler.h"

#include "ShapefileObject.generated.h"



UENUM(BlueprintType)
enum class EShapefilePartType : uint8
{
	TRISTRIP						UMETA(DisplayName = "TRISTRIP"),
	TRIFAN							UMETA(DisplayName = "TRIFAN"),
	OUTERRING						UMETA(DisplayName = "OUTERRING"),
	INNERRING						UMETA(DisplayName = "INNERRING"),
	FIRSTRING						UMETA(DisplayName = "FIRSTRING"),
	RING							UMETA(DisplayName = "RING"),
};

USTRUCT(BlueprintType)
struct FObjectPart
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	EShapefilePartType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	TArray<FVector4> Vertices;
};


UCLASS(BlueprintType)
class SHAPEFILELIB_API UShapefileObject : public UObject
{
GENERATED_BODY()
public:
	void SetObject(SHPObject* object);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Close object"), Category = "ShapefileLib")
	void Close() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	EShapefileType ShapefileType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	int	ShapeId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	TArray<FObjectPart> Parts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	TArray<FVector4> Vertices;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	FVector4 MinBound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	FVector4 MaxBound;

private:
	static EShapefilePartType IntToShapefilePartType(int type);
	
	SHPObject* _object;



};
