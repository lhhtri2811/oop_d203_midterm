#include "GamePlay.h"
#include<conio.h>
#include<time.h>
void GamePlay::countScore(Paddle* player)
{
	if (player == player1)
	{
		score1++;
	}
	else if (player == player2)
	{
		score2++;
	}
	ball->reset();
	player1->reset();
	player2->reset();
}

void GamePlay::drawGameScreen()
{
	system("cls");//xóa màn hình
	textColor(11);
	//vẽ viền ngang trên của màn hình chơi
	for (int i = 0; i < width + 2; i++)
	{
		if (i == 0) cout << "\xC9";
		cout << "\xCD";
		if (i == width + 1) cout << "\xBB";
	}
	cout << endl;

	//vẽ viền dọc của màn hình chơi
	for (int i = 0; i < height ; i++)
	{
		for (int j = 0; j < width + 2; j++)
		{
			int xB = ball->getX();
			int yB = ball->getY();
			int xP1 = player1->getX();
			int xP2 = player2->getX();
			int yP1 = player1->getY();
			int yP2 = player2->getY();

			//viền dọc bên trái màn hình chơi
			if (j == 0)
				cout << "\xBA";
			//vị trí quả bóng ở tâm màn hình chơi
			if (xB == j && yB == i)
			{
				textColor(12);//set màu cho quả bóng
				cout << "O";
			}
			//vị trí thanh ngang phía trên màn hình chơi
			else if (xP1 == j && yP1 == i + 1)
			{
				textColor(14);
				cout << "\xCD";
			}
			else if (xP1 + 1 == j && yP1 == i + 1)
			{
				textColor(14);
				cout << "\xCD";
			}
			else if (xP1 + 2 == j && yP1 == i + 1)
			{
				textColor(14);
				cout << "\xCD";
			}
			else if (xP1 + 3 == j && yP1 == i + 1)
			{
				textColor(14);
				cout << "\xCD";
			}
			else if (xP1 + 4 == j && yP1 == i + 1)
			{
				textColor(14);
				cout << "\xCD";
			}
			else if (xP1 + 5 == j && yP1 == i + 1)
			{
				textColor(14);
				cout << "\xCD";
			}
			else if (xP1 + 6 == j && yP1 == i + 1)
			{
				textColor(14);
				cout << "\xCD";
			}
			else if (xP1 + 7 == j && yP1 == i + 1)
			{
				textColor(14);
				cout << "\xCD";
			}
			
			//vị trí thanh ngang phía dưới màn hình chơi
			else if (xP2 == j && yP2 == i)
			{
				textColor(10);
				cout << "\xCD";
			}
			else if (xP2 + 1 == j && yP2 == i)
			{
				textColor(10);
				cout << "\xCD";
			}
			else if (xP2 + 2 == j && yP2 == i)
			{
				textColor(10);
				cout << "\xCD";
			}
			else if (xP2 + 3 == j && yP2 == i)
			{
				textColor(10);
				cout << "\xCD";
			}
			else if (xP2 + 4 == j && yP2 == i)
			{
				textColor(10);
				cout << "\xCD";
			}
			else if (xP2 + 5 == j && yP2 == i)
			{
				textColor(10);
				cout << "\xCD";
			}
			else if (xP2 + 6 == j && yP2  == i)
			{
				textColor(10);
				cout << "\xCD";
			}
			else if (xP2 + 7 == j && yP2  == i)
			{
				textColor(10);
				cout << "\xCD";
			}

			//phần trống trong màn hình chơi
			else cout << " ";
			textColor(11);
			//viền dọc bên phải của màn hình chơi
			if (j == width + 1)
				cout << "\xBA";
		}
		cout << endl;
	}

	//vẽ viền ngang dưới của màn hình chơi
	for (int i = 0; i < width + 2; i++)
	{
		if (i == 0) cout << "\xC8";
		cout << "\xCD";
		if (i == width + 1) cout << "\xBC";
	}
	cout << endl;
	
	//hiển thị điểm số của 2 player
	textColor(14);
	cout << "Player 1 Score: " << score1 << endl;
	textColor(10);
	cout << "Player 2 Score: " << score2 << endl;
	textColor(7);
	//Thoát trò chơi
	cout << "Press ESC to quit game" << endl;
}

void GamePlay::inputKey()
{
	ball->moveBall();

	int xB = ball->getX();
	int yB = ball->getY();
	int xP1 = player1->getX();
	int xP2 = player2->getX();
	int yP1 = player1->getY();
	int yP2 = player2->getY();

	if (_kbhit())
	{
		char key = _getch();
		//xử lí di chuyển của thanh ngang(paddle) của player 1
		if (key == left1)
			if (xP1 > 0)
				player1->moveLEFT();
		if (key == right1)
			if (xP1 + 4 < width)
				player1->moveRIGHT();

		//xử lí di chuyển của thanh ngang(paddle) của player 2
		if (key == left2)
			if (xP2 > 0)
				player2->moveLEFT();
		if (key == right2)
			if (xP2 + 4 < width)
				player2->moveRIGHT();

		if (ball->getDir() == STOP)
			ball->randDir();
		//xử lí lựa chọn "THOÁT" của người chơi
		if (key == 27)
			quit = true;
	}
}

void GamePlay::rule()
{
	int xB = ball->getX();
	int yB = ball->getY();
	int xP1 = player1->getX();
	int xP2 = player2->getX();
	int yP1 = player1->getY();
	int yP2 = player2->getY();


	//biên trên
	if (yB >= 0 && yB <= 1) countScore(player2);

	//biên dưới
	if (yB >= yP2 && yB <= height - 1) countScore(player1);

	//biên trái
	if (xB == 1)
		if (ball->getDir() == DOWNLEFT) ball->changeDir(DOWNRIGHT);
		else if (ball->getDir() == UPLEFT) ball->changeDir(UPRIGHT);
	//biên phải
	if (xB == width)
		if (ball->getDir() == DOWNRIGHT) ball->changeDir(DOWNLEFT);
		else if (ball->getDir() == UPRIGHT) ball->changeDir(UPLEFT);
	//thanh ngang trên
	if (yB == yP1 + 1)
		if (xB >= xP1 && xB <= xP1 + 7)
			ball->changeDir((Direction)(rand() % (6 - 4 + 1) + 4));
	//thanh ngang dưới
	if (yB == yP2 - 1)
		if (xB >= xP2 && xB <= xP2 + 7)
			ball->changeDir((Direction)(rand() % (3 - 1 + 1) + 1));

	if (score1 == 3)
	{
		textColor(14);
		cout << "Player 1 win!!!" <<" Score: "<<score1<< endl;
		/*exit(1);
		system("pause");*/
		quit = true;
	}
	else if (score2 == 3)
	{
		textColor(10);
		cout << "Player 2 win!!!" << " Score: " << score2 << endl;
		/*exit(1);
		system("pause");*/
		quit = true;
	}
}

void GamePlay::play()
{
	while (!quit)
	{
		drawGameScreen();
		inputKey();
		rule();
		Sleep(60);
	}
}

GamePlay::GamePlay(int valW, int valH)
{
	srand(time(NULL));
	this->width = valW;
	this->height = valH;
	this->score1 = this->score2 = 0;
	this->quit = false;
	ball = new Ball(valW / 2, valH / 2);
	player1 = new Paddle(valW / 2 - 3, 1);
	player2 = new Paddle(valW / 2 - 3, valH - 1);
	this->left1 = 'a';
	this->right1 = 'd';
	this->left2 = 75;//phím mũi tên sang trái
	this->right2 = 77;//phím mũi tên sang phải
}

GamePlay::~GamePlay()
{
	delete ball;
	delete player1;
	delete player2;
}

//thay đổi màu kí tự được in ra			
void textColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
