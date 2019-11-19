#pragma once
#include<iostream>
using namespace std;
#include<time.h>
enum Direction//chuyển động của quả bóng và thanh ngang
{
	STOP = 0,
	UP = 1, 
	UPLEFT = 2, 
	UPRIGHT = 3, 
	DOWN = 4, 
	DOWNLEFT = 5,
	DOWNRIGHT = 6
};
class Ball
{
private:
	int x, y;
	int originX, originY;
	Direction dir;
public:
	int getX();
	int getY();
	Direction getDir();
	void reset();
	void changeDir(Direction val);
	void randDir();
	void moveBall();
public:
	Ball(int, int);
	Ball();
	~Ball();
};

