// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#include "ShapefileHandler.h"
#include "ShapefileObject.h"

void UShapefileHandler::Close() const
{
	SHPClose(_handler);
}

UShapefileObject* UShapefileHandler::ReadObject(const int index) const
{
	SHPObject* object = SHPReadObject(_handler, index);
	if (object != nullptr)
	{
		UShapefileObject* Object = NewObject<UShapefileObject>();
		Object->SetObject(object);

		return Object;
	}
	return nullptr;
}

void UShapefileHandler::SetHandler(const SHPHandle& handler)
{
	_handler = handler;

	double minBound[4];
	double maxBound[4];
	int type;
	SHPGetInfo(_handler, &EntitiesCount, &type, minBound, maxBound);

	ShapeType = IntToShapefileType(type);
	MinBound = FVector4(minBound[0], minBound[1], minBound[2], minBound[3]);
	MaxBound = FVector4(maxBound[0], maxBound[1], maxBound[2], maxBound[3]);
}

EShapefileType UShapefileHandler::IntToShapefileType(int type)
{
	switch (type)
	{
	case SHPT_POINT: return EShapefileType::POINT;
		case SHPT_ARC: return EShapefileType::ARC;
		case SHPT_POLYGON: return EShapefileType::POLYGON;
		case SHPT_MULTIPOINT: return EShapefileType::MULTIPOINT;
		case SHPT_POINTZ:return EShapefileType::POINTZ;
		case SHPT_ARCZ: return EShapefileType::ARCZ;
		case SHPT_POLYGONZ: return EShapefileType::POLYGONZ;
		case SHPT_MULTIPOINTZ: return EShapefileType::MULTIPOINTZ;
		case SHPT_POINTM: return EShapefileType::POINTM;
		case SHPT_ARCM: return EShapefileType::ARCM;
		case SHPT_POLYGONM: return EShapefileType::POLYGONM;
		case SHPT_MULTIPOINTM: return EShapefileType::MULTIPOINTM;
		case SHPT_MULTIPATCH: return EShapefileType::MULTIPATCH;
		case SHPT_NULL: 
		default:
			return EShapefileType::N;
	}
}
