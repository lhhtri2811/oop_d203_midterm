#include "Ball.h"

int Ball::getX()
{
	return this->x;
}

int Ball::getY()
{
	return this->y;
}

Direction Ball::getDir()
{
	return this->dir;
}

void Ball::reset()
{
	this->x = this->originX;
	this->y = this->originY;
	this->dir = STOP;
}

void Ball::changeDir(Direction val)
{
	this->dir = val;
}

void Ball::randDir()
{
	this->dir = (Direction)((rand() % 6) + 1);
}

void Ball::moveBall()
{
	switch (dir)
	{
	case STOP:
		break;
	case UP:
		y--;
		break;
	case UPLEFT:
		y--;
		x--;
		break;
	case DOWNLEFT:
		y++;
		x--;
		break;
	case DOWN:
		y++;
		break;
	case UPRIGHT:
		y--;
		x++;
		break;
	case DOWNRIGHT:
		y++;
		x++;
		break;
	default:
		break;
	}
}

Ball::Ball(int valX, int valY)
{
	this->originX = valX;
	this->originY = valY;
	this->x = valX;
	this->y = valY;
	this->dir = STOP;
}

Ball::Ball()
{
	this->x = 0;
	this->y = 0;
	this->originX = 0;
	this->originY = 0;
	this->dir = STOP;
}

Ball::~Ball()
{

}

