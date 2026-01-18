<<<<<<< HEAD
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
=======
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
>>>>>>> 539167cd6dc79281500aa8b3d721cbda1d90cd4c
