#include "Sudoku.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "Sudoku Solver" << endl;
    Sudoku ob("s15c.txt");  //create object
    ob.printPuzzle();
    cout<<"\n\n\n";
    ob.solvePuzzle();
    ob.printPuzzle();

    return 0;
}
