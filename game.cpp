/*
 * game.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: Ben
 */

#include "game.h"

MyGame::MyGame()
{
	MAExtent screenSize = maGetScrSize();
	short screenWidth = EXTENT_X(screenSize);
	short screenHeight = EXTENT_Y(screenSize);

	pt1Pos.x = 0;
	pt1Pos.y = 0;

	pt1Vel.x = 1;
	pt1Vel.y = 1;

	pt2Pos.x = screenWidth;
	pt2Pos.y = 0;

	pt2Vel.x = -2;
	pt2Vel.y = 1;

	pt3Pos.x = screenWidth / 2;
	pt3Pos.y = screenHeight / 2;

	pt3Vel.x = -1;
	pt3Vel.y = -1;

	color = 0xff0000;

	//printf("Press zero or back to exit\n");
}

void MyGame::runTimerEvent()
{
	MAExtent screenSize = maGetScrSize();
	short screenWidth = EXTENT_X(screenSize);
	short screenHeight = EXTENT_Y(screenSize);

	updateVertex(pt1Pos, pt1Vel);
	updateVertex(pt2Pos, pt2Vel);
	updateVertex(pt3Pos, pt3Vel);

	updateColor(color);

	maSetColor(color);
	maLine(pt3Pos.x, pt3Pos.y, pt1Pos.x, pt1Pos.y);
	maLine(pt1Pos.x, pt1Pos.y, pt2Pos.x, pt2Pos.y);
	maLine(pt2Pos.x, pt2Pos.y, pt3Pos.x, pt3Pos.y);

	maSetColor(0x000000);
	maDrawText((screenWidth - 100) / 2 + 1, screenHeight / 2 - 32 + 1, "MoSync Demo");
	maDrawText((screenWidth - 100) / 2 + 1, screenHeight / 2 + 1, "by Ben Amos");

	maSetColor(0xffffff);
	maDrawText((screenWidth - 100) / 2, screenHeight / 2 - 32, "MoSync Demo");
	maDrawText((screenWidth - 100) / 2, screenHeight / 2, "by Ben Amos");

	maUpdateScreen();
}

void MyGame::keyPressEvent(int keyCode, int nativeCode)
{
	if(keyCode == MAK_BACK || keyCode == MAK_0 || keyCode == MAK_SOFTRIGHT)
	{
		// Call close to exit the application.
		close();
	}

	// Print the key character.
	//printf("You typed: %c\n", keyCode);
}

void MyGame::keyReleaseEvent(int keyCode, int nativeCode)
{
}

void MyGame::pointerPressEvent(MAPoint2d point)
{
	// Print the x and y coordinate.
	//printf("You touched: %i %i\n", point.x, point.y);
}

void MyGame::updateVertex(MAPoint2d & pos, MAPoint2d & vel)
{
	MAExtent screenSize = maGetScrSize();
	short screenHeight = EXTENT_Y(screenSize);
	short screenWidth = EXTENT_X(screenSize);

	pos.x += vel.x;
	if (pos.x <= 0)
	{
		pos.x = -pos.x;
		vel.x *= -1;
	}
	if (pos.x >= screenWidth)
	{
		pos.x = screenWidth * 2 - pos.x;
		vel.x *= -1;
	}

	pos.y += vel.y;
	if (pos.y <= 0)
	{
		pos.y = -pos.y;
		vel.y *= -1;
	}
	if (pos.y >= screenHeight)
	{
		pos.y = screenHeight * 2 - pos.y;
		vel.y *= -1;
	}
}

void MyGame::updateColor(int & color)
{
	Vector<int> colorVector = colorIntToVector(color);

	if (colorVector[0] == 0xff && colorVector[1] < 0xff)
	{
		if (colorVector[2] > 0)	colorVector[2]--;
		else					colorVector[1]++;
	}
	else if (colorVector[1] == 0xff && colorVector[2] < 0xff)
	{
		if (colorVector[0] > 0)	colorVector[0]--;
		else					colorVector[2]++;
	}
	else if (colorVector[2] == 0xff && colorVector[0] < 0xff)
	{
		if (colorVector[1] > 0)	colorVector[1]--;
		else					colorVector[0]++;
	}
	else
	{
		colorVector[0] = 0xff;
		colorVector[1] = 0x00;
		colorVector[2] = 0x00;
	}

	color = colorVectorToInt(colorVector);
}

void MyGame::pointerMoveEvent(MAPoint2d p)
{
}

void MyGame::pointerReleaseEvent(MAPoint2d p)
{
}

void MyGame::multitouchPressEvent(MAPoint2d p, int touchId)
{
}

void MyGame::multitouchMoveEvent(MAPoint2d p, int touchId)
{
}

void MyGame::multitouchReleaseEvent(MAPoint2d p, int touchId)
{
}

void MyGame::customEvent(const MAEvent& event)
{
}

int MyGame::colorVectorToInt(const Vector<int> & vec)
{
	return (vec[0] << 16 | vec[1] << 8 | vec[2] << 0);
}

Vector<int> MyGame::colorIntToVector(int color)
{
	Vector<int> result;
	result.add((color & 0xFF0000) >> 16);
	result.add((color & 0x00FF00) >> 8);
	result.add((color & 0x0000FF) >> 0);
	return result;
}
