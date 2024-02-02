#pragma once
#include "pos.h"

namespace Cube
{
	position points[8] = {
		position{1.000,1.000,-1.000},
		position{1.000,-1.000,-1.000},
		position{1.000,1.000,1.000},
		position{1.000,-1.000,1.000},
		position{-1.000,1.000,-1.000},
		position{-1.000,-1.000,-1.000},
		position{-1.000,1.000,1.000},
		position{-1.000,-1.000,1.000},
	};

	vertex edges[24] = {
		vertex{0,1},
		vertex{1,2},
		vertex{2,3},
		vertex{4,0},
		vertex{0,1},
		vertex{1,2},
		vertex{2,3},
		vertex{4,0},
		vertex{0,1},
		vertex{1,2},
		vertex{2,3},
		vertex{4,0},
		vertex{0,1},
		vertex{1,2},
		vertex{2,3},
		vertex{4,0},
		vertex{0,1},
		vertex{1,2},
		vertex{2,3},
		vertex{4,0},
		vertex{0,1},
		vertex{1,2},
		vertex{2,3},
		vertex{4,0},
	};
}
