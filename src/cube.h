/*
	AUTOGENERATED FILE

	This file was automatically generated by the model generator tool.
	(https://github.com/riley0122/numworks_doom/tree/main/tools/modelGenerator)
*/
#pragma once
#include "pos.h"

namespace Cube
{
	position points[8] = {
		position{-15.000,-15.000,15.000},
		position{-15.000,15.000,15.000},
		position{-15.000,-15.000,-15.000},
		position{-15.000,15.000,-15.000},
		position{15.000,-15.000,15.000},
		position{15.000,15.000,15.000},
		position{15.000,-15.000,-15.000},
		position{15.000,15.000,-15.000},
	};

	vertex edges[24] = {
		vertex{0,1},
		vertex{1,3},
		vertex{3,2},
		vertex{2,0},
		vertex{2,3},
		vertex{3,7},
		vertex{7,6},
		vertex{6,2},
		vertex{6,7},
		vertex{7,5},
		vertex{5,4},
		vertex{4,6},
		vertex{4,5},
		vertex{5,1},
		vertex{1,0},
		vertex{0,4},
		vertex{2,6},
		vertex{6,4},
		vertex{4,0},
		vertex{0,2},
		vertex{7,3},
		vertex{3,1},
		vertex{1,5},
		vertex{5,7},
	};
}
