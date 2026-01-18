#pragma once
#include <vector>
#include "platforma.h"
#include "novcic.h"

struct Level 
{
	std::vector<Platforma> platforme;
	std::vector<Novcic> novcici;
	int potrebno_novcica;
};
