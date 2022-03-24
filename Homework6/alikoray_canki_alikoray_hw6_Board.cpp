#include "alikoray_canki_alikoray_hw6_Board.h"
#include <iostream>
#include<sstream> 
#include <string>

using namespace std;

template <class itemType>
Board<itemType>::Board(int numRow, int numCol) { //  parametric constructor of board class, set of 2d dynamic array 
	w_array= new arraystruct<itemType> *[numRow];
	for(int i=0; i<numRow;i++){
	w_array[i]= new arraystruct<itemType>[numCol];
	}
	numrow=numRow;
	numcol=numCol;
}

template <class itemType>
Board<itemType>::~Board() // destructor of 2d dynamic array
{
	for(int i=0; i<numrow;i++){
		delete [] w_array[i];
	}
	delete[] w_array;
	w_array=NULL;

}

template <class itemType>
void Board <itemType>::readBoardFromFile(ifstream & input) { // a member function which takes values as parameter and fill the matrix 
	string line;
	for (int i=0;i<numrow;i++){
		getline(input,line);
		istringstream input2(line);
		for(int k=0;k<numcol;k++){
			input2>>w_array[i][k].value;
			w_array[i][k].isfaceclosed=true;
		}
		}
}

template <class itemType>
void Board <itemType>::displayBoard(){ // a member function which displays the board
	for (int i=0;i<numrow;i++){
		for(int k=0;k<numcol;k++){
			if(w_array[i][k].isfaceclosed==true){ // if face of card is closed print x else print the value of card
			cout<<"X"<<"  ";
			}
			else if(w_array[i][k].isfaceclosed==false){
			cout<<w_array[i][k].value<<"  ";
			}
		}
		cout<<endl;
	}
}

template <class itemType>
void Board <itemType>::closeCard(int row_index,int col_index){ // a member function which closes face of card
w_array[row_index][col_index].isfaceclosed=true;
}

template <class itemType>
int Board <itemType>::getRow(){ // a member function which returns the total row of 2d array
return numrow;
}
template <class itemType>
int Board <itemType>::getColumn(){ // a member function which returns the column of 2d array
	return numcol;
}

template <class itemType>
arraystruct<itemType>**Board<itemType>::getarray(){ // a member function which returns the 2d array
return w_array;
}