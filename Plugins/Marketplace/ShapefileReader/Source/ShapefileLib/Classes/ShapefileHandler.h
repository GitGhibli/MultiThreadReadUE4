// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#pragma once

#include "shapefil.h"
#include "ObjectMacros.h"
#include "ShapefileHandler.generated.h"


UENUM(BlueprintType)

enum class EShapefileType : uint8
{
	N				UMETA(DisplayName = "NULL"),
	POINT			UMETA(DisplayName = "2D POINT"),
	ARC				UMETA(DisplayName = "2D ARC"),
	POLYGON			UMETA(DisplayName = "2D POLYGON"),
	MULTIPOINT		UMETA(DisplayName = "2D MULTIPOINT"),
	POINTZ			UMETA(DisplayName = "3D POINT"),
	ARCZ			UMETA(DisplayName = "3D ARC"),
	POLYGONZ		UMETA(DisplayName = "3D POLYGON"),
	MULTIPOINTZ		UMETA(DisplayName = "3D MULTIPOINT"),
	POINTM			UMETA(DisplayName = "2D + Measure POINT"),
	ARCM			UMETA(DisplayName = "2D + Measure ARC"),
	POLYGONM		UMETA(DisplayName = "2D + Measure POLYGON"),
	MULTIPOINTM		UMETA(DisplayName = "2D + Measure MULTIPOINT"),
	MULTIPATCH		UMETA(DisplayName = "Complex  MULTIPATCH")
};

UCLASS(BlueprintType)

class SHAPEFILELIB_API UShapefileHandler : public UObject
{
	GENERATED_BODY()
public:
	void SetHandler(const SHPHandle& handler);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Close handler"), Category = "ShapefileLib")
	void Close() const;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Read object"), Category = "ShapefileLib")
	UShapefileObject* ReadObject(const int index) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	int EntitiesCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	EShapefileType ShapeType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	FVector4 MinBound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	FVector4 MaxBound;

	static EShapefileType IntToShapefileType(int type);

private:
	SHPHandle _handler;
};
