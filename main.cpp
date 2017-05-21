#include<iostream>
#include"arcanoid.h"
#include<windows.h>
using namespace std;

int main() {
	arcanoid game;
	system("mode con cols=120 lines=40");
	game.play();

	

}