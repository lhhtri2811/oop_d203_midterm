#include"Ball.h"
#include"Paddle.h"
#include"GamePlay.h"
int main()
{
	GamePlay game(40, 30);
	game.play();

	system("pause");
	return 0;
}


