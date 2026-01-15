#include "raylib.h"
#include "igrica.h"

int main()
{
	InitWindow(800, 450, "2D Platformer");
	SetTargetFPS(60);

	Igrac igrac = { {100,300,30,50}, 0, false };
	Vector2 kamera = { 0,0 };

	std::vector<Level> leveli(3);

	//prvi level
	leveli[0].potrebno_novcica = 6;
	leveli[0].platforme = {Platforma({50,350,700,20}),Platforma({200,250,100,20}),Platforma({500,250,100,20}), Platforma({700,160,300,20}),Platforma({700,400,300,20})};
	leveli[0].novcici = {Novcic({350,310}),Novcic({750,130}),Novcic({900,130}),Novcic({950,370}), Novcic({250,210}),Novcic({550,210})};

	//drugi level
	leveli[1].potrebno_novcica = 9;
	leveli[1].platforme = {Platforma({50,350,700,20}),Platforma({150,270,100,20}),Platforma({400,200,100,20}), Platforma({600,250,100,20}),Platforma({150,100,100,20}),Platforma({770,150,100,20})};
	leveli[1].novcici = {Novcic({190,70}),Novcic({800,110}),Novcic({420,160}),Novcic({620,210}), Novcic({200,230}),Novcic({500,230}),Novcic({550,160}),Novcic({600,160}),Novcic({350,310})};

	//treci
	leveli[2].potrebno_novcica = 12;
	leveli[2].platforme = { Platforma({50,350,400,20})};
	leveli[2].novcici = { Novcic({200, 320})};

	int trenutni_level = 0;

	Texture2D background = LoadTexture("D:\\OOP seminar\\PlatformerRaylib\\Debug\\pozadina.png");
	if (background.width == 0 || background.height == 0)
	{
		printf("Background nije ucitan!");
	}
	bool gotova_igra = false;
	while (!WindowShouldClose())
	{
		Level& r = leveli[trenutni_level];

		azuriraj_igraca(igrac, r.platforme);
		kamera = azuriraj_kameru(igrac, kamera);
		provjera_novcica(igrac, r.novcici);

		//ako padne
		if (igrac.oblik.y > 450) 
		{
			igrac.oblik.x = 100;
			igrac.oblik.y = 300;
			igrac.skok_pad = 0;
			for (auto& n : r.novcici)
			{
				n.sakupljen = false;
			}
		}

		//iduci level
		if (broj_skupljenih_novcica(r.novcici) >= r.potrebno_novcica && trenutni_level < 2)
		{
			trenutni_level++;
			igrac.oblik.x = 100;
			igrac.oblik.y = 300;
			igrac.skok_pad = 0;
		}

		//bool gotova_igra = false;

		if ((!gotova_igra) && broj_skupljenih_novcica(r.novcici) >= r.potrebno_novcica && trenutni_level == 2)
		{
			gotova_igra = true;
		}

		if (gotova_igra)
		{
			DrawText(TextFormat("YOU WIN!!!"), 200, 200, 100, YELLOW);
		}

		BeginDrawing();

		
		ClearBackground(RAYWHITE);
		DrawTexture(background, 0, 0, WHITE);

		nacrtaj_level(igrac, r, kamera);

		DrawText(TextFormat("Level %d", trenutni_level + 1), 10, 10, 20, DARKGRAY);
		DrawText(TextFormat("Novcici: %d/%d", broj_skupljenih_novcica(r.novcici), r.potrebno_novcica), 10, 40, 20, DARKGRAY);

		if (gotova_igra)
		{
			DrawText(TextFormat("YOU WIN!!!"), 200, 200, 100, YELLOW);
		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
