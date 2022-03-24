#ifndef _ALIKORAY_CANKI_ALIKORAY_HW6_PLAYER_H
#define _ALIKORAY_CANKI_ALIKORAY_HW6_PLAYER_H

#include"alikoray_canki_alikoray_hw6_Board.h"
#include<string>
#include <iostream>

using namespace std;

template <class itemType> // because user can input different types we use template
class Player
{
public:
Player(Board <itemType>& b);
itemType openCard(int,int);
bool validMove(int,int);
void increaseNumberOfSuccess();
int getNumberOfSuccess();




private:

Board <itemType>& board; // objects sharing with a referance paramether because 2 player is playing on the same board
int score;
};
#include "alikoray_canki_alikoray_hw6_Player.cpp"
#endif