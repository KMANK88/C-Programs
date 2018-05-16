//
//  Card.hpp
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 4/10/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//
#ifndef Card_hpp
#define Card_hpp
#include <stdio.h>
#include<iostream>
using namespace std;

class Card {
public:
    void setName(std::string cardName);
    void setSuit(std::string cardSuit);
    void setValue(int cardValue);
    std::string getName();
    std::string getSuit();
    int getValue();
    void printCard();
    Card();
    Card(std::string cardName, std::string cardSuit, int cardValue);
private:
    std::string name;
    std::string suit;
    int value;
    
};

#endif
