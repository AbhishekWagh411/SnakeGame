// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<ctime>
#include <cstdlib>
#include<conio.h> // for inputs 
using namespace std;

bool snakeGame; // is game on
const int width = 50, height = 50;
int x, y; // snake possition
int targetX, targetY; // food possition
int snakeTailLen;
int snakeTailX[50], snakeTailY[50];
int score;
enum direction {
    STOP = 0, UP, DOWN, LEFT,RIGHT
}; // in which direction snake is going or either stopped
direction dir;
void game_setup() {
    snakeGame = true; // game started
    dir = STOP; // snake is not moving
    x = width / 2;
    y = height / 2;
    srand(time(NULL));
    score = 0;
}
void game_window() {
    system("cls"); // clear screen
    targetX = rand() % width; // food will appear at random co-ordinates
    targetY = rand() % height;
    while (x == targetX && y == targetY) {// food should not appear at snake's possition
        srand(time(NULL));
        targetX = rand() % width;
        targetY = rand() % height;
    }
    //top
    for (int i = 0; i < width;i++) {
        cout << "_";
    }
    cout << endl;
    //body
    for (int i = 0; i < height;i++) {
        for (int j = 0;j < width;j++) {
            if (j == 0 || j ==width-1) {
                cout << "|";
            }
            else 
                if (i == y && j == x) {
                    cout << "0";
                }
                else if (i == targetY && j == targetX) {
                    cout << "#";
                }
                else{
                    cout << " ";
                    }
        }
        cout << endl;
    }
    //bottom
    for (int i = 0; i < width;i++) {
        cout << "-";
    }
    cout << endl;
}
void game_input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            if (dir != RIGHT) {
                dir = LEFT;
            }
            break;
        case 'd':
            if (dir != LEFT)
            {
                dir = RIGHT;
            }
            break;

        case 'w':
            if (dir != DOWN)
            {
                dir = UP;
            }
            break;
        case 's':
            if (dir!=UP)
            {
                dir = DOWN;
            }
            break;
        case '0':
            snakeGame = false;
            break;
        }
    }
}
void game_program() {

}
int main()
{
    srand(time(NULL));
    game_setup();
    while (snakeGame) {
        srand(time(NULL));
        game_window();
        game_input();
        game_program();
        //snakeGame = false;
    }
 
}
