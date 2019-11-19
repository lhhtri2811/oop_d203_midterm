#pragma once
#include<iostream>
using namespace std;
class Paddle
{
private:
	int x, y;
	int originX, originY;
public:
	int getX();
	int getY();
	void reset();
	void moveLEFT();
	void moveRIGHT();
public:
	Paddle();
	Paddle(int, int);
	~Paddle();
};

