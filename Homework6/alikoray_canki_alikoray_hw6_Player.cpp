#include "alikoray_canki_alikoray_hw6_Player.h"



template <class itemType>
Player<itemType>::Player(Board <itemType>& b) // parametric constructor of player class takes board object as parameter and set score value as 0
	:board(b),score(0)
{}


template <class itemType>
itemType Player<itemType>::openCard(int row_index, int col_index){ // member function which opens the face of card

board.getarray()[row_index][col_index].isfaceclosed=false;
itemType card=board.getarray()[row_index][col_index].value;
return card;
}
template <class itemType>
bool Player<itemType>::validMove(int row_index,int col_index){ // a member function which decides whether player playing a valid move or not
	int row_range=board.getRow();
	int col_range=board.getColumn();
	if(row_index >=0){ // if row index and column index >= 0 and if they are smaller than size of 2d array and if the face of vard is closed return true
		if(col_index >=0){
			if(row_index<row_range&&col_index<col_range){
				if(board.getarray()[row_index][col_index].isfaceclosed==true){
					return true;
				}
			}
		}
	}
	return false; 
}

template <class itemType>
void Player<itemType>::increaseNumberOfSuccess(){ // a member function which increments the score
score++;
}
template <class itemType>
int Player<itemType>::getNumberOfSuccess(){ // a member function which returns total score
return score;
}