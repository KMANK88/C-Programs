//
//  Deck.hpp
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 4/10/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//
#ifndef Deck_hpp
#define Deck_hpp
#include <stdio.h>
#include <vector>
#include "Card.hpp"
using namespace std;

class Deck{
public:

int deckSize();
void newDeck();
Card dealCard();
std::vector <Card> mydeck;

};

#endif



