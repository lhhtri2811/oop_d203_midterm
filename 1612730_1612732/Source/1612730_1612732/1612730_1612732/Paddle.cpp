#include "Paddle.h"

int Paddle::getX()
{
	return this->x;
}

int Paddle::getY()
{
	return this->y;
}

void Paddle::reset()
{
	this->x = this->originX;
	this->y = this->originY;
}

void Paddle::moveLEFT()
{
	x-=3;
}

void Paddle::moveRIGHT()
{
	x+=3;
}

Paddle::Paddle()
{
	this->x = 0;
	this->y = 0;
	this->originX = 0;
	this->originY = 0;
}

Paddle::Paddle(int valX, int valY)
{
	this->originX = valX;
	this->originY = valY;
	this->x = valX;
	this->y = valY;
}

Paddle::~Paddle()
{

}

