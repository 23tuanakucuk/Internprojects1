#include <iostream>
#include "cconvert.hpp"
#include "randm.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <curses.h>

bool gameover;
constexpr int width=100; //wall
constexpr int height=50;
int ch;
/*
bool kbhit() {
    timeout(0); // Set non-blocking mode
    ch = getch();
    timeout(-1); // Reset to blocking mode
    if (ch != ERR) {
        ungetch(ch); // Put the character back into input buffer
        return true;
    }
    return false;
}*/
int snakex; //snake head start
int snakey;


int baitx; // bait location
int baity;
int score;

int tailx[100], taily[100]; //array of int snake
int ntail;

}

enum eDirecton {STOP = 0, LEFT,RIGHT, UP, DOWN}; // Controls
eDirecton dir;

void scene() {
    dir = STOP;
    snakex= 3;
    snakey= 3;
    baitx = Utill::generateRandomInteger(1, 30);
    baity = Utill::generateRandomInteger(1, 50);
    score=0;

}

void rulling() {
    clearConsole();

    for(int i = 0; i < width+1; i++)
        std::cout << "#";
   std::cout<<std::endl;


    for (int i = 0; i < height ; i++) {
        for (int j = 0; j < width; j++) {

            if (j == 0)
                std::cout << "#";

            if (j==width-1)
                std::cout<<"#";

            if (i == snakey && j == snakex)

                std::cout << "OOO";

            else if (i == baity && j == baitx )

                std::cout << "*";

            else {

                bool control = false;

                for (int k = 0; k< ntail ; k++) {

                    if (tailx [k] == j && taily [k] == i) {
                        std::cout << "O";
                        control = true;
                    }
                }
                if (!control)
                    std::cout << " ";
            }
        }


        std::cout << std::endl;
    }

    for(int i = 0; i < width+1; i++)
        std::cout << "#";
    std::cout << std::endl;

    }


void UpdateGame(){
    int prevX = tailx[0];
    int prevY = taily[0];
    tailx[0] = snakex;
    taily[0] = snakey;

    for (int i = 1; i < ntail; i++) {
        int prev2X = tailx[i];
        int prev2Y = taily[i];
        tailx[i] = prevX;
        taily[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir) {
        case LEFT:
            snakex--;
        break;
        case RIGHT:
            snakex++;
        break;
        case UP:
            snakey--;
        break;
        case DOWN:
            snakey++;
        break;
        default:
            break;
    }

    // Checks for snake's collision with the wall (|)
    if (snakex >= width || snakex < 0 || snakey >= height || snakey < 0)
        gameover = true;

    // Checks for collision with the tail (o)
    for (int i = 0; i < ntail; i++) {
        if (tailx[i] == snakex && taily[i] == snakey)
            gameover = true;
    }

    // Checks for snake's collision with the food (#)
    if (snakex == baitx && snakey == baity) {
        score += 10;
        baitx = Utill::generateRandomInteger(1, 30);
        baity = Utill::generateRandomInteger(1, 50);
       ntail++;
    }
}
/*
void UserInput() {

        if (kbhit()) {
            switch (getch()) {
                case 'a':
                    dir = LEFT;
                break;
                case 'd':
                    dir = RIGHT;
                break;
                case 'w':
                    dir = UP;
                break;
                case 's':
                    dir = DOWN;
                break;
                case 'x':
                    gameover = true;
                break;
                default:
                    break;
            }
        }

    }

    */

    int main(){

        scene();
        rulling();
        while (!gameover) {

            UpdateGame();

            usleep(100000);
        }
        //endwin();
        return 0;
    }
