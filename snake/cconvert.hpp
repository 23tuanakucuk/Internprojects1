//
// Created by tuana on 8/9/24.
//

#ifndef CONSOLE_OPERATIONS_HPP
#define CONSOLE_OPERATIONS_HPP

#include <iostream>


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

void write(const std::string &text, TextColor textColor = TextColor::Default,
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



#endif //CONSOLE_OPERATIONS_HPP