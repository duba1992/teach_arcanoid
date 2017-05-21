#include<iostream>
#include"arcanoid.h"
#include<Windows.h>
#include"Console.h"
#include"Keyboard.h"
#include<time.h>
using namespace std;

void arcanoid::fillPole() {
	for (int x = 0;x < 25;x++) {
		for (int y = 0;y < 41;y++) {
			if (x == 0) {
				pole[x][y] = 1;  // init roof
			}
			else if (y == 0) { // init bottom
				pole[x][y] = 2;

			}
			else if (y == 40) {
				pole[x][y] = 4;
			}
			
			else if (x == 24 && y > 19 && y < 26) { // init Player
				pole[x][y] = 3;
			}
			else if (x > 1 && x < 6 && y>1 && y < 39) {
				pole[x][y] = 5;
			}
			else {
				pole[x][y] = 0; // init field
			}
		}
	}
}
void arcanoid::showPole() {
	for (int x = 0;x < 25;x++) {
		for (int y = 0;y < 41;y++) {
			if (pole[x][y] == 1) {
				cout << char(219);
			}
			else if (pole[x][y] == 2 || pole [x][y] == 4) {
				cout << char(219);
			}
			else if (pole[x][y] == 0) {
				cout << " ";
			}
			///*else if (pole[x][y] == 5) {
			//	cout << 'X';*/
			//}
			else {
				cout << pole[x][y];
			}

		}
		cout << endl;
	}
}


void arcanoid::initBall() {
	srand(time(NULL));
	xBall = 10;
	yBall = 1+rand()%30;
	gotoxy(yBall, xBall);
	cout << "O";
	up = true;
	down = false;
	left = false;
	right = true;

}
void arcanoid::MovingBall() {
	checkBall();
	if (left && up) {
		pole[xBall][yBall] = 0;
		gotoxy(yBall, xBall);
		cout << " ";
		xBall--;
		yBall--;
		gotoxy(yBall, xBall);
		cout << "O";
		pole[xBall][yBall] = 7;
	}
	if (left && down) {
		pole[xBall][yBall] = 0;
		gotoxy(yBall, xBall);
		cout << " ";
		xBall++;
		yBall--;
		gotoxy(yBall, xBall);
		cout << "O";
		pole[xBall][yBall] = 7;
	}
	if (right && up) {
		pole[xBall][yBall] = 0;
		gotoxy(yBall, xBall);
		cout << " ";
		xBall--;
		yBall++;
		gotoxy(yBall, xBall);
		cout << "O";
		pole[xBall][yBall] = 7;
	}
	if (right && down) {
		pole[xBall][yBall] = 0;
		gotoxy(yBall, xBall);
		cout << " ";
		xBall++;
		yBall++;
		gotoxy(yBall, xBall);
		cout << "O";
		pole[xBall][yBall] = 7;
	}
	
}
void arcanoid::checkBall() {
	if (yBall == 39) { //The ball strikes from the right corner
		left = true;
		right = false;
		
	}
	if (xBall == 1) { //The ball strikes from the top 
		
		up = false;
		down = true;
	
		
	}
	if (yBall == 1) {               //The ball strikes from the left corner
		
		right = true;
		left = false;
		
	}
	if (pole[xBall][yBall] == 7 && (pole[xBall + 1][yBall-1] == 3 || pole[xBall][yBall+1] == 3)) { // The ball strikes from the player
		down = false;
		up = true;
		
	}
	
	if (xBall == 25){ //game over
		game = false;
	}
	if (pole[xBall][yBall] == 7 && pole[xBall - 1][yBall-1] == 5 && left) { // crash with enemy left
		gotoxy(yBall-1, xBall-1);
		cout << " ";
		pole[xBall - 1][yBall - 1] = 0;
		up = false;
		down = true;
	
		enemy++;
	
		
	}
	if (pole[xBall][yBall] == 7 && pole[xBall - 1][yBall + 1] == 5 && right) { // crash with enemy right
		gotoxy(yBall + 1, xBall - 1);
		cout << " ";
		pole[xBall - 1][yBall + 1] = 0;
		
		up = false;
		down = true;
	
		enemy++;
	}
}
void arcanoid::move() {
	game = true;
	const int x = 24;
	int iterator = 0;
	while (game) {
		
		unsigned short k = KeyPressed();
		
		k = KeyPressed();
		
		if (k == VK_RIGHT || k == 77) {  // move right Player
			if (pole[24][39] == 3) {
				continue;
			}

			pole[x][y_1] = 0;
			gotoxy(y_1, x);
			cout << ' ';
			y_1++;
			y_2++;

			pole[x][y_2] = 3;

			gotoxy(y_2, x);
			cout << char(219);

		}

		if (k == VK_LEFT || k == 75) {  // move left Player
			if (pole[24][1] == 3) {
				continue;
			}
			pole[x][y_2] = 0;
			gotoxy(y_2, x);
			cout << ' ';
			y_1--;
			y_2--;
			pole[x][y_1] = 3;
			gotoxy(y_1, x);
			cout << char(219);


		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			// Exit in game
		}
		iterator++;
		if (iterator == 30000) {
			checkBall();
			MovingBall();
			iterator = 0;
		}
		

	}
	gotoxy(80, 40);

}
void arcanoid::play() {
	
	fillPole();
	showPole();
	initBall();
	move();
	
}
