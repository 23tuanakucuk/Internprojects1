#include <iostream>
#include <string>
#include <random>
#include <conio.h>
#include <Windows.h>


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

namespace Utill {
	int generateRandomInteger(int min, int max) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(min, max);
		return dist(gen);
	}
}


enum class TextColor {
	Default = 0,
	Black = 30, Red = 31, Green = 32, Yellow = 33, Blue = 34,
	Magenta = 35, Cyan = 36, White = 37,
	BlackBright = 90, RedBright = 91, GreenBright = 92, YellowBright = 93,
	BlueBright = 94, MagentaBright = 95, CyanBright = 96, WhiteBright = 97
};

enum class BackgroundColor {
	Default = 0,
	Black = 40, Red = 41, Green = 42, Yellow = 43, Blue = 44,
	Magenta = 45, Cyan = 46, White = 47,
	BlackBright = 100, RedBright = 101, GreenBright = 102, YellowBright = 103,
	BlueBright = 104, MagentaBright = 105, CyanBright = 106, WhiteBright = 107
};

void clearConsole() {
	std::cout << "\033[H\033[J";
}

void locateCursor(int x, int y) {
	std::cout << "\033[" << y << ";" << x << "H";
}

void hideCursor() {
	std::cout << "\033[?25l" << std::flush;
}

void showCursor() {
	std::cout << "\033[?25h" << std::flush;
}

void write(const std::string& text, TextColor textColor = TextColor::Default,
	BackgroundColor backgroundColor = BackgroundColor::Default) {
	std::cout << "\033[" << static_cast<int>(textColor) << ";" << static_cast<int>(backgroundColor) << "m" << text <<
		"\033[0m";
}

std::string read(TextColor textColor = TextColor::Default, BackgroundColor backgroundColor = BackgroundColor::Default) {
	std::cout << "\033[" << static_cast<int>(textColor) << ";" << static_cast<int>(backgroundColor) << "m";

	std::string value;

	std::getline(std::cin, value);

	std::cout << "\033[0m";

	return value;
}


std::string snake_b = "O";
std::string bait = "*";

int c = 0;
int snakex = 2;
int snakey = 2;



int baitx;
int baity;

class Obj {
public:
	int& snakexx = snakex;
	int& sankeyy = snakey;
	std::string& snake_b = snake_b;
	int& baitx = baitx;
	int& baitx = baity;
	std::string& bait = bait;
};


void randmmLocation(int& locate) {
	locate = Utill::generateRandomInteger(2, 39);
}

bool snakemove(const int& lastDirection) {
	while (1) {
		switch (lastDirection) {
			hideCursor();
		case KEY_UP:
			while (KEY_UP = true) {
				snakey--;
			}
			break;
		case KEY_DOWN:
			while (KEY_DOWN = true) {
				snakey++;
			}
			break;
		case KEY_LEFT:
			while (KEY_LEFT = true) {
				snakex--;
			}
			break;
		case KEY_RIGHT:
			while (KEY_RIGHT = true) {
				snakex++;
			}
			break;
		default:

			break;
		}
if (snakex > 40 || snakex < 2) {
			write("Kaybettiniz", TextColor::Red); 
			break;
		} 	
		if (snakey > 40 || snakey < 2) { 
			write("Kaybettiniz", TextColor::Red); 
			break;
		}
		return true;
		
	}
}



int main() {
	clearConsole();

	Obj snake;
	Obj feed;


	for (int wall_l = 1; wall_l <= 41; wall_l++) {
		locateCursor(1, wall_l);
		write("#", TextColor::CyanBright);
	}
	for (int wall_r = 1; wall_r <= 41; wall_r++) {
		locateCursor(41, wall_r);
		write("#", TextColor::CyanBright);
	}
	for (int wall_u = 2; wall_u <= 40; wall_u++) {
		locateCursor(wall_u, 1);
		write("#", TextColor::CyanBright);
	}
	for (int wall_d = 2; wall_d <= 40; wall_d++) {
		locateCursor(wall_d, 41);
		write("#", TextColor::CyanBright);
	}

	locateCursor(snakex, snakey);
	write(snake.snake_b, TextColor::Red);


	randmmLocation(baitx);
	randmmLocation(baity);
	locateCursor(baitx, baity);
	write(feed.bait, TextColor::White);


	while (1) {
		c = 0;

		switch ((c = _getch())) {
		case KEY_UP:
			snakemove(KEY_UP);
		case KEY_DOWN:
			snakemove(KEY_DOWN);
		case KEY_LEFT:
			snakemove(KEY_LEFT);
		case KEY_RIGHT:
			snakemove(KEY_RIGHT);
			if (!snakemove(c)) {
				return 0;
			}
			break;
		default:
			break;
			
		}

		if (snakex == baitx && snakey == baity) {
			randmmLocation(baitx);
			randmmLocation(baity);
			locateCursor(baitx, baity);

			snake_b.append("O");
		}
		locateCursor(snakex, snakey);
		write(snake.snake_b, TextColor::Red);
		write(feed.bait, TextColor::White);
	}

	return 0;
}
	
	
	
	
