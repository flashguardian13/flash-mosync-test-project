#include "game.h"

/**
 * Entry point of the program. The MAMain function
 * needs to be declared as extern "C".
 */
extern "C" int MAMain()
{
	MyGame myMoblet;
	myMoblet.addTimer(&myMoblet, 1000 / 60, 0);
	Moblet::run( &myMoblet );

	return 0;
};
