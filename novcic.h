#pragma once
#include "objekt.h"

class Novcic : public Objekt 
{
public:
	bool sakupljen;

	Novcic(Vector2 pozicija) : Objekt({ pozicija.x - 10, pozicija.y - 10, 20, 20 }), sakupljen(false) {}

	void Nacrtaj(Vector2 kamera) const override 
	{
		if (sakupljen == false)
		{
			DrawCircle(oblik.x + 10 - kamera.x, oblik.y + 10, 10, GOLD);
		}
	}
};
