// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#include "DBFHandler.h"


void UDBFHandler::Close() const
{
	DBFClose(_handler);
}

EDFBFieldType UDBFHandler::GetFieldInfo(const int FieldIndex, FString& FieldName, int& FieldWidth, int& Decimals) const
{
	char* cFieldName = new char[255];
	int* iFieldWidth = new int;
	int* iDecimals = new int;
	const DBFFieldType FieldType = DBFGetFieldInfo(_handler, FieldIndex, cFieldName, iFieldWidth, iDecimals);

	FieldName = FString(ANSI_TO_TCHAR(cFieldName));
	FieldWidth = int(*iFieldWidth);
	Decimals = int(*iDecimals);

	return IntToDBFFieldType(FieldType);
}

int UDBFHandler::ReadIntAttribute(const int ShapeIndex, const FString& FieldName) const
{
	return DBFReadIntegerAttribute(_handler, ShapeIndex, DBFGetFieldIndex(_handler, TCHAR_TO_ANSI(*FieldName)));
}

float UDBFHandler::ReadDoubleAttribute(const int ShapeIndex, const FString& FieldName) const
{
	return DBFReadDoubleAttribute(_handler, ShapeIndex, DBFGetFieldIndex(_handler, TCHAR_TO_ANSI(*FieldName)));
}

FString UDBFHandler::ReadStringAttribute(const int ShapeIndex, const FString& FieldName) const
{
	return DBFReadStringAttribute(_handler, ShapeIndex, DBFGetFieldIndex(_handler, TCHAR_TO_ANSI(*FieldName)));
}

FString UDBFHandler::ReadLogicalAttribute(const int ShapeIndex, const FString& FieldName) const
{
	return DBFReadLogicalAttribute(_handler, ShapeIndex, DBFGetFieldIndex(_handler, TCHAR_TO_ANSI(*FieldName)));
}

bool UDBFHandler::IsAttributeNull(const int ShapeIndex, const FString& FieldName) const
{
	return DBFIsAttributeNULL(_handler, ShapeIndex, DBFGetFieldIndex(_handler, TCHAR_TO_ANSI(*FieldName))) == 0 ? false : true;
}

void UDBFHandler::SetHandler(const DBFHandle& handler)
{
	_handler = handler;
	FieldCount = DBFGetFieldCount(_handler);
	RecordCount = DBFGetRecordCount(_handler);
}

EDFBFieldType UDBFHandler::IntToDBFFieldType(int type)
{
	switch (type)
	{
	case FTString: return EDFBFieldType::STRING;
	case FTInteger: return EDFBFieldType::INTEGER;
	case FTDouble: return EDFBFieldType::DOUBLE;
	case FTLogical: return  EDFBFieldType::LOGICAL;
	case FTInvalid:
	default:
		return EDFBFieldType::INVALID;
	}
}
