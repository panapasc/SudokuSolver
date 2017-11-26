#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <fstream>

using namespace std;

class Sudoku
{
    private:
        int sudokuArray[9][9];
    public:
        Sudoku(char[]);
        void printPuzzle();
        bool is_safe(int,int,int);
        bool solvePuzzle();



};

#endif // SUDOKU_H

