#include "C_v15_point.h"
#include "C_v16_whole.h"

/*
The key function in "C_v15_point.h":
	getflagpoint()
	geteverypoint()
	getborder()

The key function in "C_v16_whole.h":
	show_military_thisCityWall()
	show_spiralNumber()
	show_military_everyCityWall()
*/

void 示整图每层边框()__attribute__((weak,alias("show_military_everyCityWall")));

void 示螺旋数()__attribute__((alias("show_spiralNumber")));