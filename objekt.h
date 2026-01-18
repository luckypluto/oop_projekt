#pragma once
#include "raylib.h"

class Objekt 
{
public:
	Rectangle oblik;

	Objekt(Rectangle r) : oblik(r) {}
	virtual ~Objekt() {}

	virtual void Nacrtaj(Vector2 kamera) const = 0;
};
