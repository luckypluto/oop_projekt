<<<<<<< HEAD
﻿#include "igrica.h"
#include <vector>


const float GRAVITACIJA = 0.5f;
const float SKOK = -10.0f;

void azuriraj_igraca(Igrac& igrac, const std::vector<Platforma>& platforme)
{
	if (IsKeyDown(KEY_A)) {
		igrac.oblik.x -= 5;
	}
	if (IsKeyDown(KEY_D)) {
		igrac.oblik.x += 5;
	}

	igrac.skok_pad += GRAVITACIJA;
	igrac.oblik.y += igrac.skok_pad;

	igrac.na_podu = false;

	// koliz
	for (int i = 0; i < platforme.size(); i++) 
	{
		Platforma p = platforme[i]; 
		if (CheckCollisionRecs(igrac.oblik, p.oblik)) 
		{
			if (igrac.skok_pad > 0 && igrac.oblik.y + igrac.oblik.height - igrac.skok_pad<= p.oblik.y)
			{
				igrac.oblik.y = p.oblik.y - igrac.oblik.height;
				igrac.skok_pad = 0;
				igrac.na_podu = true;
			}
			else if (igrac.skok_pad < 0 && igrac.oblik.y <= p.oblik.y + p.oblik.height- igrac.skok_pad)
			{
				igrac.oblik.y = p.oblik.y + p.oblik.height;
				igrac.skok_pad = 0;

			}
			else
			{
				if (igrac.oblik.x <= p.oblik.x)
				{
					igrac.oblik.x = p.oblik.x - igrac.oblik.width;
				}
				else
				{
					igrac.oblik.x = p.oblik.x + p.oblik.width;
				}
			}
		}
	}

	if (igrac.na_podu) 
	{
		if (IsKeyPressed(KEY_W)) 
		{
			igrac.skok_pad = SKOK;
			igrac.na_podu = false;
		}
	}
}

Vector2 azuriraj_kameru(const Igrac& igrac, Vector2 kamera)
{
	kamera.x = igrac.oblik.x - 300;
	if (kamera.x < 0) 
	{
		kamera.x = 0;
	}
	return kamera;
}

void provjera_novcica(Igrac& igrac, std::vector<Novcic>& novcici)
{
	for (int i = 0; i < novcici.size(); i++) 
	{
		if (novcici[i].sakupljen == false && CheckCollisionRecs(igrac.oblik, novcici[i].oblik))
		{
			novcici[i].sakupljen = true;
		}
	}
	//printf("*\n");

}


int broj_skupljenih_novcica(const std::vector<Novcic>& novcici)
{
	int brojac = 0;
	for (int i = 0; i < novcici.size(); i++) 
	{
		if (novcici[i].sakupljen == true) 
		{
			brojac++;
		}
	}
	return brojac;
}

void nacrtaj_level(const Igrac& igrac, const Level& level, Vector2 kamera)
{
	if (level.platforme.empty()) 
	{ 
		throw std::runtime_error("Razina nema platforme!"); 
	}
	
	for (int i = 0; i < level.platforme.size(); i++) 
	{
		level.platforme[i].Nacrtaj(kamera);
	}

	for (int i = 0; i < level.novcici.size(); i++) 
	{
		level.novcici[i].Nacrtaj(kamera);
	}
	Texture2D igrac_slika = LoadTexture("D:\\OOP seminar\\luigi.png");

	DrawTextureEx(igrac_slika,{ igrac.oblik.x - kamera.x, igrac.oblik.y },0.0f,igrac.oblik.width / igrac_slika.width,WHITE);
	//DrawRectangle(igrac.oblik.x - kamera.x, igrac.oblik.y, igrac.oblik.width, igrac.oblik.height, BLUE);
}
=======
#include "igrica.h"
#include <vector>


const float GRAVITACIJA = 0.5f;
const float SKOK = -10.0f;

void azuriraj_igraca(Igrac& igrac, const std::vector<Platforma>& platforme)
{
	if (IsKeyDown(KEY_A)) {
		igrac.oblik.x -= 5;
	}
	if (IsKeyDown(KEY_D)) {
		igrac.oblik.x += 5;
	}

	igrac.skok_pad += GRAVITACIJA;
	igrac.oblik.y += igrac.skok_pad;

	igrac.na_podu = false;

	// koliz
	for (int i = 0; i < platforme.size(); i++) 
	{
		Platforma p = platforme[i]; 
		if (CheckCollisionRecs(igrac.oblik, p.oblik)) 
		{
			if (igrac.skok_pad > 0 && igrac.oblik.y + igrac.oblik.height - igrac.skok_pad<= p.oblik.y)
			{
				igrac.oblik.y = p.oblik.y - igrac.oblik.height;
				igrac.skok_pad = 0;
				igrac.na_podu = true;
			}
			else if (igrac.skok_pad < 0 && igrac.oblik.y <= p.oblik.y + p.oblik.height- igrac.skok_pad)
			{
				igrac.oblik.y = p.oblik.y + p.oblik.height;
				igrac.skok_pad = 0;

			}
			else
			{
				if (igrac.oblik.x <= p.oblik.x)
				{
					igrac.oblik.x = p.oblik.x - igrac.oblik.width;
				}
				else
				{
					igrac.oblik.x = p.oblik.x + p.oblik.width;
				}
			}
		}
	}

	if (igrac.na_podu) 
	{
		if (IsKeyPressed(KEY_W)) 
		{
			igrac.skok_pad = SKOK;
			igrac.na_podu = false;
		}
	}
}

Vector2 azuriraj_kameru(const Igrac& igrac, Vector2 kamera)
{
	kamera.x = igrac.oblik.x - 300;
	if (kamera.x < 0) 
	{
		kamera.x = 0;
	}
	return kamera;
}

void provjera_novcica(Igrac& igrac, std::vector<Novcic>& novcici)
{
	for (int i = 0; i < novcici.size(); i++) 
	{
		if (novcici[i].sakupljen == false && CheckCollisionRecs(igrac.oblik, novcici[i].oblik))
		{
			novcici[i].sakupljen = true;
		}
	}
	//printf("*\n");

}


int broj_skupljenih_novcica(const std::vector<Novcic>& novcici)
{
	int brojac = 0;
	for (int i = 0; i < novcici.size(); i++) 
	{
		if (novcici[i].sakupljen == true) 
		{
			brojac++;
		}
	}
	return brojac;
}

void nacrtaj_level(const Igrac& igrac, const Level& level, Vector2 kamera)
{
	if (level.platforme.empty()) 
	{ 
		throw std::runtime_error("Razina nema platforme!"); 
	}
	
	for (int i = 0; i < level.platforme.size(); i++) 
	{
		level.platforme[i].Nacrtaj(kamera);
	}

	for (int i = 0; i < level.novcici.size(); i++) 
	{
		level.novcici[i].Nacrtaj(kamera);
	}
	Texture2D igrac_slika = LoadTexture("D:\\OOP seminar\\luigi.png");

	DrawTextureEx(igrac_slika,{ igrac.oblik.x - kamera.x, igrac.oblik.y },0.0f,igrac.oblik.width / igrac_slika.width,WHITE);
	//DrawRectangle(igrac.oblik.x - kamera.x, igrac.oblik.y, igrac.oblik.width, igrac.oblik.height, BLUE);
}
>>>>>>> 539167cd6dc79281500aa8b3d721cbda1d90cd4c
