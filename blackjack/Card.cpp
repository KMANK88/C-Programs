//
//  Card.cpp
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 4/10/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include "Card.hpp"

using namespace std;

Card::Card(){
    string name = "No Name";
    string suit = "No Suit";
    int value = 0;
}

Card::Card(string cardName, string cardSuit, int cardValue){
    string name = cardName;
    string suit = cardSuit;
    int value = cardValue;
    

}
void Card::printCard(){

    cout << name << " of " << suit << endl;
}

void Card::setName(string cardName){
    name = cardName;
    return;
}

void Card::setSuit( string cardSuit){
    suit = cardSuit;
    return;
}

void Card::setValue(int cardValue){
    value = cardValue;
    return;
}

string Card::getName(){
    return name;
}

string Card::getSuit(){
    return suit;
}
int Card::getValue(){
    return value;
}

