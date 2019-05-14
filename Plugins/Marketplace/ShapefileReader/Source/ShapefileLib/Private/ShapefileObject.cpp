// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#include "ShapefileObject.h"
#include "ShapefileHandler.h"

void UShapefileObject::SetObject(SHPObject* object)
{
	_object = object;

	ShapefileType = UShapefileHandler::IntToShapefileType(_object->nSHPType);
	ShapeId = _object->nShapeId;

	for(int i = 0 ; i < _object->nVertices ; i++)
	{
		Vertices.Add(FVector4(_object->padfX[i], _object->padfY[i], _object->padfZ[i], _object->padfM[i]));
	}

	// Iteare through parts
	for(int i = 0 ; i < _object->nParts ; i++)
	{
		FObjectPart Part;
		Part.Type = IntToShapefilePartType(_object->panPartType[i]);
		const int endVertex = (i == _object->nParts - 1) ? _object->nVertices : _object->panPartStart[i + 1];
		for(int j = _object->panPartStart[i] ; j < endVertex ; j++)
		{
			Part.Vertices.Add(Vertices[j]);
		}
		Parts.Add(Part);
	}

	MinBound = FVector4(_object->dfXMin, _object->dfYMin, _object->dfZMin, _object->dfMMin);
	MaxBound = FVector4(_object->dfXMax, _object->dfYMax, _object->dfZMax, _object->dfMMax);
}

void UShapefileObject::Close() const
{
	SHPDestroyObject(_object);
}

EShapefilePartType UShapefileObject::IntToShapefilePartType(int type)
{
	switch(type)
	{
		case SHPP_TRISTRIP: return EShapefilePartType::TRISTRIP;
		case SHPP_TRIFAN: return EShapefilePartType::TRIFAN;
		case SHPP_OUTERRING: return EShapefilePartType::OUTERRING;
		case SHPP_INNERRING: return EShapefilePartType::INNERRING;
		case SHPP_FIRSTRING: return EShapefilePartType::FIRSTRING;
		case SHPP_RING: return EShapefilePartType::RING;
		default: return EShapefilePartType::RING;
	}
}
