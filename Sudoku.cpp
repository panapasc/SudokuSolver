#include "Sudoku.h"
#include <iostream>
#include <fstream>

using namespace std;

//initialize constructor with the .txt filename
Sudoku::Sudoku(char filename[])
{
    ifstream myFile(filename);
    int x;
    if(myFile.is_open()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                myFile >> x;            //get the number from myFile file
                sudokuArray[i][j] = x;  //pass the value to the sudokuArray element
            }
        }
    }
}

//a function to display the array
void Sudoku::printPuzzle()
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << sudokuArray[i][j] << " ";
        }
        cout << endl;
    }
}

/*a function that checks if an element can be put in a position in the array.
**It checks if the vertical and horizontal line and the block the element belongs
**has the same value. The function returns true if it is safe to assign that value
**in that cell and false otherwise
*/
bool Sudoku::is_safe(int row, int col, int num)
{
    //check row
    for(int i=0;i<9;i++){
        if(i==col){ //case i = col advance row because we don't want to check it self
            continue;
        }
        if(sudokuArray[row][i]==num){
            return false;
        }
    }
    //check column
    for(int i=0;i<9;i++){
        if(i==row){ //case i = row advance col because we don't want to check it self
            continue;
        }
        if(sudokuArray[i][col]==num){
            return false;
        }
    }
    //check block

    //every blocks first cell
    int blockRowStart = row-row%3;
    int blockColStart = col-col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if((blockRowStart+i==row) && (blockColStart+j==col)){   //don't check it's self
                continue;
            }
            if(sudokuArray[blockRowStart+i][blockColStart+j]==num){
                return false;
            }
        }
    }
    return true;    //if it passed all the above return true
}

bool Sudoku::solvePuzzle()
{
    int row,col;
    //check for unassigned(zero) cell
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudokuArray[i][j]==0){
                row = i;
                col = j;
                goto stop_loop_1;   //brakes the 2 loops
            }
        }
    }
    return true;    //if there is no unassigned cell it means we solved it!
stop_loop_1:
    //try numbers to cell
    for(int num=1;num<=9;num++){
        if(is_safe(row,col,num))
        {
            sudokuArray[row][col] = num;    //if its legal put the number in the cell
            if(solvePuzzle()){              //recursively call the function for the next element
                return true;
            }
        }
        else{
            continue;
        }
    }
    sudokuArray[row][col] = 0;  //means this isn't a solution so assign zero again to element and try another value
    return false;   //if no number is assigned return false
}




