//
//  Deck.cpp
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 4/10/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.
//

#include "Deck.hpp"
#include "Card.hpp"

Card  Deck::dealCard() {
    if(mydeck.size() ==0){
       cout << "Deck is empty." << endl;
        exit(0);
 }
    Card card;
    int pick;
    srand((int)time(0));
    pick = rand() % mydeck.size();
    card = mydeck.at(pick);
    mydeck.erase(mydeck.begin() + pick);
    
    return card;
}

void Deck::newDeck(){
    int i = 0;
    Card card;
    mydeck.clear();
    
    for(int i=0; i < 4; i++){
        if(i==0){
            card.setSuit("Spades");
        }
        if(i==1){
            card.setSuit("Hearts");
        }
        if(i==2){
            card.setSuit("Clubs");
        }
        if(i==3){
            card.setSuit("Dimonds");
        }
        
        
    card.setName("Ace");
    card.setValue(11);
    mydeck.push_back(card);
    card.setName("Two");
    card.setValue(2);
    mydeck.push_back(card);
    card.setName("Three");
    card.setValue(3);
    mydeck.push_back(card);
    card.setName("Four");
    card.setValue(4);
    mydeck.push_back(card);
    card.setName("Five");
    card.setValue(5);
    mydeck.push_back(card);
    card.setName("Six");
    card.setValue(6);
    mydeck.push_back(card);
    card.setName("Seven");
    card.setValue(7);
    mydeck.push_back(card);
    card.setName("Eight");
    card.setValue(8);
    mydeck.push_back(card);
    card.setName("Nine");
    card.setValue(9);
    mydeck.push_back(card);
    card.setName("Ten");
    card.setValue(10);
    mydeck.push_back(card);
    card.setName("Jack");
    card.setValue(10);
    mydeck.push_back(card);
    card.setName("Queen");
    card.setValue(10);
    mydeck.push_back(card);
    card.setName("King");
    card.setValue(10);
    mydeck.push_back(card);
    
    }
    
    
    

    }


int Deck::deckSize(){
    return mydeck.size();
}
