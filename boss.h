#pragma once
#include "raylib.h"
#include "igrac.h"

struct Boss
{
public:	
	Rectangle oblik;
	int zivot;

	Boss(Vector2 pozicija, Vector2 velicina)
	{
		oblik = { pozicija.x, pozicija.y, velicina.x, velicina.y };
		zivot = 1;
	}

	void Nacrtaj(Vector2 kamera) const;
	void provjeri_koliziju(Igrac& igrac, bool& level_reset);
};