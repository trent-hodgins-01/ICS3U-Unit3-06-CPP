// Copyright (c) 2021 Trent Hodgins All rights reserved

// Created by Trent Hodgins
// Created on 09/23/2021
// This is a guessing game program
// The user enters in a number between 1 and 100

#include <iostream>
#include <random>

int main() {
    // this function checks to see if the user guessed the correct number
    int someRandomNumber;
    std::string guessed_number;
    int guessedNumberAsInt;

    // making the someRandomNumber variable a random number
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 100);
    // [0, 100]
    someRandomNumber = idist(rgen);

    // input
    std::cout << "Guess a number between 0 and 100 (integer): ";
    std::cin >> guessed_number;
    std::cout << "" << std::endl;

    // process and output
    try {
        // convert string to int
        guessedNumberAsInt = std::stoi(guessed_number);

        if (guessedNumberAsInt == someRandomNumber) {
         std::cout << "You Guessed Correctly!" << std::endl;
        } else {
            std::cout << "You Guessed Wrong! Correct answer was "
                      << someRandomNumber << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "You didn’t enter in an integer" << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
