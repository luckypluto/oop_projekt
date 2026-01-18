<<<<<<< HEAD
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
=======
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
>>>>>>> 539167cd6dc79281500aa8b3d721cbda1d90cd4c
