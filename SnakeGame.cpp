// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<Windows.h> // for sleep function
#include<ctime>
#include <cstdlib>
#include<conio.h> // for inputs 
using namespace std;

bool snakeGame; // is game on
const int width = 30, height = 30;
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
    targetX = rand() % width; // food will appear at random co-ordinates
    targetY = rand() % height;
    score = 0;
    snakeTailLen = 0;
}
void game_window() {
    system("cls"); // clear screen
   /*
    while (x == targetX && y == targetY) {// food should not appear at snake's possition
        srand(time(NULL));
        targetX = rand() % width;
        targetY = rand() % height;
    }
    */

    //top
    for (int i = 0; i < width+2;i++) {
        cout << "_";
    }
    cout << endl;
    //body
    for (int i = 0; i < height;i++) {
        for (int j = 0;j < width;j++) {

            if (j == 0) {
                cout << "|";
            }
            else 
                if (i == y && j == x) {
                    cout << "0";        //head
                }
                else if (i == targetY && j == targetX) {
                    cout << "#"; // food
                }
                else{
                    bool printTail = false;
                    for (int k = 0; k < snakeTailLen; k++) {
                        if (snakeTailX[k] == j && snakeTailY[k] == i) {
                            cout << "o";
                            printTail = true;
                        }
                    }
                    if (!printTail) {
                        cout << " ";
                    }
                }

            if (j == width - 1) {
                cout << "|";   //right broder
            }
        }
        cout << endl;
    }
    //bottom
    for (int i = 0; i < width+2;i++) {
        cout << "-";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}
void game_input() {
    if (_kbhit()) {     // is key pressed?
        switch (_getch()) {   // which key is pressed 
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
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;
    for (int i = 1; i < snakeTailLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case STOP:
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    default:
        break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < snakeTailLen; i++) {
        if (snakeTailX[i] == x && snakeTailY[i] == y) {
            snakeGame = false; // game pver
        }
    }

    //if food is eaten 
    if (x == targetX && y == targetY) {
        score += 10;
        targetX = rand() % width;
        targetY = rand() % height;
        snakeTailLen++;
    }
}
int main()
{
    //srand(time(NULL));
    game_setup();
    while (snakeGame) {
       // srand(time(NULL));
        game_window();
        game_input();
        if (dir != STOP) {
            game_program();
        }
        Sleep(200); // delay for gamespeed
        //snakeGame = false;

    }
    return 0;
 
}
