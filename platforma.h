#pragma once
#include "objekt.h"

class Platforma : public Objekt 
{
public:
	Platforma(Rectangle r) : Objekt(r) {}

	void Nacrtaj(Vector2 kamera) const override 
	{
		DrawRectangle(oblik.x - kamera.x, oblik.y, oblik.width, oblik.height, GRAY );
	}
};
