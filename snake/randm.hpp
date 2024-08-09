//
// Created by tuana on 8/9/24.
//

#ifndef UTILS_HPP
#define UTILS_HPP

#include <random>

namespace Utill {
    int generateRandomInteger(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }
}

#endif // UTILS_HPP