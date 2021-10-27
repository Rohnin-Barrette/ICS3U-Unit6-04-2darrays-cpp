// Copyright (c) 2019 St. Mother Teresa HS All rights reserved.
//
// Created by: Mr. Coxall
// Created on: Dec 2019
// This program uses a 2D array

#include <time.h>
#include <iostream>
#include <random>


template <int rows, int cols>
int AverageFinder(int (&passedIn2DList)[rows][cols]) {
    // this function finds the average of all the elements in  a 2D array
    int average = 0;
    int total = 0;

    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < cols; ++columnElement)
            total += passedIn2DList[rowElement][columnElement];
    average = total / (rows * cols);
    }

    return average;
}


int main() {
    // this function gets rows and collumns

    int aSingleRandomNumber = 0;
    int sum = 0;
    const int rows = 2;
    const int columns = 5;
    int a2DArray[rows][columns];
    int average;
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 50);  // [1,10]

    srand(time(NULL));

    // input

    for (int rowElement = 0; rowElement < rows; rowElement++) {
        for (int columnElement = 0; columnElement < columns; columnElement++) {
            aSingleRandomNumber = idist(rgen);
            a2DArray[rowElement][columnElement] = aSingleRandomNumber;
            std::cout << aSingleRandomNumber << ", ";
        }
        std::cout << std::endl;
    }

    average = AverageFinder(a2DArray);
    std::cout << "\nThe average of all the numbers is: "
        << average << std::endl;
}
