#pragma once
#include<iostream>
class arcanoid {
private:
	bool game = true;
	int pole[25][41];
	bool up;
	bool down;
	bool left;
	bool right;
	int y_1 = 20;
	int y_2 = 25;
	int xBall;
	int yBall;
	int enemy;
public:
	void fillPole();
	void showPole();
	void move();
	void initBall();
	void MovingBall();
	void checkBall();
	void play();
};
