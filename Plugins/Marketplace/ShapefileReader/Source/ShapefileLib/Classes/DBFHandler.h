// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#pragma once

#include "shapefil.h"
#include "ObjectMacros.h"

#include "DBFHandler.generated.h"


UENUM(BlueprintType)
enum class EDFBFieldType : uint8
{
	STRING				UMETA(DisplayName = "STRING"),
	INTEGER			UMETA(DisplayName = "INTEGER"),
	DOUBLE				UMETA(DisplayName = "DOUBLE"),
	LOGICAL			UMETA(DisplayName = "LOGICAL"),
	INVALID		UMETA(DisplayName = "INVALID"),

};

UCLASS(BlueprintType)
class SHAPEFILELIB_API UDBFHandler : public UObject
{
	GENERATED_BODY()
public:
	void SetHandler(const DBFHandle& handler);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Close handler"), Category = "ShapefileLib")
	void Close() const;

	UFUNCTION(BlueprintCallable, Category = "ShapefileLib")
	EDFBFieldType GetFieldInfo(const int FieldIndex, FString& FieldName, int& FieldWidth, int& Decimals) const;

	UFUNCTION(BlueprintCallable, Category = "ShapefileLib")
	int ReadIntAttribute(const int ShapeIndex, const FString& FieldName) const;

	UFUNCTION(BlueprintCallable, Category = "ShapefileLib")
	float ReadDoubleAttribute(const int ShapeIndex, const FString& FieldName) const;

	UFUNCTION(BlueprintCallable, Category = "ShapefileLib")
	FString ReadStringAttribute(const int ShapeIndex, const FString& FieldName) const;

	UFUNCTION(BlueprintCallable, Category = "ShapefileLib")
	FString ReadLogicalAttribute(const int ShapeIndex, const FString& FieldName) const;

	UFUNCTION(BlueprintCallable, Category = "ShapefileLib")
	bool IsAttributeNull(const int ShapeIndex, const FString& FieldName) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	int FieldCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShapefileLib")
	int RecordCount;

	static EDFBFieldType IntToDBFFieldType(int type);

private:
	DBFHandle _handler;
};
