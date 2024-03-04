// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool snakeGame;
const int width = 50, breadth = 50;
int x, y;
int targetX, targetY;
int score;
enum direction {
    STOP = 0, UP, DOWN, LEFT,RIGHT
};
direction dir;
void game_setup() {
    snakeGame = true;
    dir = STOP;
    x = width / 2;
    y = width / 2;
    targetX = rand() % width;
    targetY = rand() % breadth;
    if (x == targetX && y == targetY) {
        targetX = rand() % width;
        targetY = rand() % breadth;
    }
    score = 0;

}
void game_window() {

}
void game_input() {

}
void game_program() {

}
int main()
{
    std::cout << "Hello World!\n";
}
