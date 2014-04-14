/*
 * game.h
 *
 *  Created on: Apr 13, 2014
 *      Author: Ben
 */

#ifndef GAME_H_
#define GAME_H_

#include <MAUtil/Moblet.h>
#include <MAUtil/Vector.h>

using namespace MAUtil;

/**
 * A Moblet is a high-level class that defines the
 * behaviour of a MoSync program.
 */
class MyGame : public Moblet, public TimerListener
{
private:
	MAPoint2d pt1Pos, pt1Vel, pt2Pos, pt2Vel, pt3Pos, pt3Vel;
	int		color;

	void updateVertex(MAPoint2d & pos, MAPoint2d & vel);
	void updateColor(int & color);

	int colorVectorToInt(const Vector<int> & vec);
	Vector<int> colorIntToVector(int color);
public:
	MyGame();

	void runTimerEvent();

	void keyPressEvent(int keyCode, int nativeCode);
	void keyReleaseEvent(int keyCode, int nativeCode);
	void pointerPressEvent(MAPoint2d p);
	void pointerMoveEvent(MAPoint2d p);
	void pointerReleaseEvent(MAPoint2d p);
	void multitouchPressEvent(MAPoint2d p, int touchId);
	void multitouchMoveEvent(MAPoint2d p, int touchId);
	void multitouchReleaseEvent(MAPoint2d p, int touchId);

	/**
	* This function is called when an event that Moblet doesn't recognize is recieved.
	*/
	void customEvent(const MAEvent& event);
};

#endif /* GAME_H_ */
