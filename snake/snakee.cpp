#include <iostream>
#include "randdm.hpp"
#include "cconvert.hpp"
#include <cstdio>
#include <unistd.h>
#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include <termios.h>
#include <string>


bool gameover;
constexpr int width=100; //wall
constexpr int height=50;
int ch;

int snakex; //snake head start
int snakey;
std::string snake="O";

int baitx; // bait location
int baity;
int score;

int tailx[100], taily[100]; //array of int snake
int ntail;

void insertDemo()
{
    // Inserts at 5th index,
    // 5 occurrences of '$'
    snake.insert(0, 1, 'o');
    std::cout << snake;
}

enum eDirecton {
    STOP = -1,
    Left = 0,
    Up = 1,
    Right = 2,
    Down = 3
}; // Controls
eDirecton dir;

char getUserInput() {
    char input;
    struct termios old_settings, new_settings;

    tcgetattr(STDIN_FILENO, &old_settings);
    new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

    input = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);

    return input;
}


void scene(){
    dir = STOP;
    snakex=3;
    snakey=3;
    baitx = Utill::generateRandomInteger(2, 30);
    baity = Utill::generateRandomInteger(2, 30);
    score=0;
    locateCursor(52,2);
    std::cout<<"Score:"<<score<<std::endl;
}

void rulling(){

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

                std::cout << snake;

            else if (i == baity && j == baitx )

                std::cout << "*";

            else {

                bool control = false;

                for (int k = 0; k< ntail ; k++) {

                    if (tailx [k] == j && taily [k] == i) {
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

     {
        switch(dir) {
            case Left:
                   snakex--;

            case Right:
                snakex++;
            case Up:
                snakey--;

            case Down:
                snakey++;
            default:
                break;
        }
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
        insertDemo();
        score += 10;
        baitx = Utill::generateRandomInteger(1, 30);
        baity = Utill::generateRandomInteger(1, 50);
        ntail++;
    }
    locateCursor(2,2);
    std::cout<<"Score:"<<score<<std::endl;
}

void UserInput(){
    char user_input = getUserInput();;
    switch (user_input) {
        case 'a':
          dir = Left;
        break;
        case 'w':
            dir = Up;
        break;
        case 'd':
            dir = Right;
        break;
        case 's':
            dir = Down;
        break;
        default:
            dir = STOP;
        gameover=true;
        break;
    }

}




int main()
{
    clearConsole();
    scene();

    while (gameover==false) {
        rulling(); // Render the game scene
        UserInput(); // Handle user input
        UpdateGame(); // Update game state


        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Introduce a delay

        clearConsole(); // Clear the console before the next iteration
        if(gameover==true){break;}
    }
    return 0;

}
