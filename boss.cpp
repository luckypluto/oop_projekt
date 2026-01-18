#include "boss.h"
#include "raylib.h"
#include "igrac.h"

void Boss::Nacrtaj(Vector2 kamera) const
{
	Texture2D boss_slika = LoadTexture("D:\\OOP seminar\\boss.png");
	if (zivot == 1)
	{
		DrawTextureEx(boss_slika, {oblik.x - kamera.x, oblik.y }, 0.0f, oblik.width / boss_slika.width, WHITE);
	}
}

void Boss::provjeri_koliziju(Igrac& igrac, bool& level_reset)
{
	if (zivot == 1)
	{
		if (CheckCollisionRecs(igrac.oblik, oblik))
		{
			if (igrac.skok_pad > 0 && igrac.oblik.y + igrac.oblik.height - 5 < oblik.y)
			{
				zivot = 0;
			}
			else
			{
				level_reset = true;
			}
		}
	}
}