#pragma once
#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15
			
#define default_ColorCode		7
#include"Ball.h"
#include"Paddle.h"
#include<Windows.h>
class GamePlay
{
private:
	int width;//chiều ngang của màn hình chơi
	int height;//chiều dọc của màn hình chơi
	int score1;//điểm của player 1
	int score2;//điểm của palyer 2
	char left1, right1;//phím di chuyển của player 1
	char left2, right2;//phím di chuyển của player 2
	bool quit;
	Ball* ball;
	Paddle* player1;
	Paddle* player2;
public:
	void countScore(Paddle*);//tính điểm
	void drawGameScreen();//vẽ màn hình chơi
	void inputKey();//xử lí các sự kiện phím được nhấn
	void rule();//xử lí các tình huống xảy ra khi chơi
	void play();
public:
	GamePlay(int,int);
	~GamePlay();
};
void textColor(int color);
