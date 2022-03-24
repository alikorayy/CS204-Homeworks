#ifndef _ALIKORAY_CANKI_ALIKORAY_HW6_BOARD_H
#define _ALIKORAY_CANKI_ALIKORAY_HW6_BOARD_H
#include <iostream>
#include<string>
using namespace std;

template <class itemType> 
struct arraystruct{ // template struct which hides the value of arrays
itemType value;
bool isfaceclosed;
};

template <class itemType>
class Board {
public:
Board(int,int);
~Board();
void readBoardFromFile(ifstream &);
void displayBoard();
void closeCard(int,int);
int getRow();
int getColumn();
arraystruct<itemType>** getarray();






private:


 int numrow;
 int numcol;
arraystruct <itemType> ** w_array;
};
#include "alikoray_canki_alikoray_hw6_Board.cpp"
#endif
