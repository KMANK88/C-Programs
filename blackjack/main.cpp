//
//  blackjack.cpp
//  ProgrammingLanguages
//
//  Created by Karsten Pease on 4/10/18.
//  Copyright © 2018 Karsten Pease. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Card.hpp"
#include "Deck.hpp"

//g++ main.cpp Deck.cpp Card.cpp -o main


using namespace std;

void PrintHand(vector<Card> hand){
    for(int i=0; i< hand.size(); i++){
        cout << hand[i].getName() << " of " << hand[i].getSuit() << endl;   //simple print function to save some code.
    }
}

int PlayerScore(vector <Card> hand) {
    int tot =0;
    int newTot=0;
    for(int i=0; i < hand.size(); i++){
        
        tot = tot + hand[i].getValue();
    }
      for(int i=0; i < hand.size(); i++){
        if(hand[i].getName() == "Ace" && tot > 21) {
            hand[i].setValue(1);            //if it has an ace in it and the total is 21 it resets teh ace to a 1
        }
            newTot = newTot +hand[i].getValue();
        }
    if(newTot < tot){
        tot = newTot;
    }
    
    return tot;
}

int main(){
   
    Deck d1;
    d1.newDeck();
    char userAnswer;
    int bet;
    int userTotal;
    int userHand;
    int DealerHand;
    int blackJack = 21;
    int score;
    
    
    vector<Card> user;
    vector<Card> dealer;
    
    cout << "************WELCOME TO BLACKJACK*************" << endl;
    cout << "Do you want to play? (q is quit and y is yes)" << endl;
    
    cin >> userAnswer;
    cout << "How much do you want to gambel?" << endl;
    cin >> userTotal;
    if(userTotal ==0){
        cout << "You cannot bet $0 comman what is this disney land?" << endl;   //Im funny disney land XD
        cout << "How much you really gambeling?" << endl;
        cin >> userTotal;       //How much you are gambeling
    }
    
    while(true){            //true so it goes any way until break or 'q' is pressed
    if(userAnswer =='q'){
        break;
    }else if(userAnswer =='y'){
        user.clear();       //clear so we dont get any repeats.
        dealer.clear();
        userHand =0;
        DealerHand =0;
        
        if(d1.deckSize() <= 20) {
            d1.newDeck();
            cout << "Shuffeling deck!" << endl;     //even though real black jack there is multiple decks. shuffel so you can count cards
        }
        user.push_back(d1.dealCard());
        user.push_back(d1.dealCard());
        dealer.push_back(d1.dealCard());
        dealer.push_back(d1.dealCard());        //method to draw card
        
        cout << "How much are you betting this hand?" << endl;
        cin >> bet;     //betting amount
        
        if(userTotal == 0){
            cout << "Sorry you are out of money. Try again next time." <<endl;
            exit(1);            //if money is 0 quit. (or get kicked out).
        }

        if(bet ==0){
            cout << "If you are betting 0 you cant win anything nice try buddy but only the rich can play" << endl;
            cout << "But how much are you realling betting" << endl;
            cin >> bet;
        }else if(bet > userTotal){
            cout << "You cannot bet more than you have." << endl;
            cout << "But how much are you realling betting" << endl;
            cin >> bet;
        }
        cout << endl;
        cout << "Your hand holds:"<< endl;
        PrintHand(user);
        userHand = user[0].getValue() + user[1].getValue();
        cout << "Your hand total is: " << userHand << endl;
        cout << endl;
        cout << "Dealer is showing a: " << dealer[0].getName() << " of " << dealer[0].getSuit() << endl;
        if(PlayerScore(user) == 21){
            PrintHand(user);    //automatic blackjack
                cout << "You win., You got lucky!" << endl;
                userTotal = userTotal +(bet *1.5);
                cout << "Your total is $" << userTotal << endl;
                cout << "Do you want to give it another try? (y for yes q to quit)" << endl;
                cin >> userAnswer;
            }else if(PlayerScore(dealer) == 21){
            PrintHand(dealer);  //dealer automatic black jack.
            cout << "Dealer BlackJack dealer wins!" << endl;
            userTotal = userTotal - bet;
            cout << "Your total is $" << userTotal << endl;
            cout << "Do you want to give it another try? (y for yes q to quit)" << endl;
            cin >> userAnswer;
        }else if (PlayerScore(user)== 21 && PlayerScore(dealer)==21){
            cout << "Push both have black jack!" << endl;
            cout << "Your total is $" << userTotal << endl;
            cout << "Do you want to give it another try? (y for yes q to quit)" << endl;
            cin >> userAnswer;
            
        }else{
        cout << endl << "Do you hit or stay? (h for hit s for stay)" << endl;
        cin >> userAnswer;
        }

    } else  if(userAnswer == 'h'){  //functions for hit
         score = PlayerScore(user);
        user.push_back(d1.dealCard());
        cout << endl << "Your hand is " << endl;
        PrintHand(user);
        cout << "Total score: " << PlayerScore(user) << endl;
   
        if(PlayerScore(user) == 21){
            cout << "You reached 21 nice job." << endl;
            userTotal = userTotal +bet;
            cout << "Your total is $" << userTotal << endl;
             cout << "Do you want to give it another try? (y for yes q to quit)" << endl;
            cin >> userAnswer;
            
        } else if((PlayerScore(user) > blackJack)){
            userTotal = userTotal - bet;
            cout << endl << "User busted" << endl;
            cout << "Your total is $" << userTotal << endl;
            cout << "Do you want to give it another try? (y for yes q to quit)" << endl;
            cin >> userAnswer;
        }else{
            cout << endl << "Do you hit or stay? (h for hit s for stay)" << endl;
            cin >> userAnswer;
        }
    }else if(userAnswer == 's'){
        //functions for stay and dealers turn
        score = PlayerScore(user);
        cout << "Your hand total is " << PlayerScore(user) << endl;
        DealerHand = PlayerScore(dealer);
        while(DealerHand < 17){
            dealer.push_back(d1.dealCard());
            DealerHand = PlayerScore(dealer);
        }
        cout << "Dealer hand is " << endl;
        PrintHand(dealer);
        cout << endl <<  DealerHand << endl;
        
        if(DealerHand > blackJack){
            cout << "Dealer busted" << endl;
            userTotal = userTotal + bet;
        }else if(DealerHand == blackJack){
            cout << "Dealer Wins...." << endl << "It was close though!" << endl;
            userTotal = userTotal - bet;
        }else if(DealerHand == PlayerScore(user)){
            cout << "Push - Everyone loses." << endl;
        }else if(DealerHand > PlayerScore(user)){
            cout << "Dealer Wins, again!" << endl;
            userTotal = userTotal - bet;
        }else if(PlayerScore(user) > DealerHand){
            userTotal = userTotal + bet;
            cout << "You win!!" << endl << "Play again?.....and bet MORE!" << endl;
            
        }
        cout << "Current chip count is $" << userTotal << endl << endl;
        if(userTotal == 0){
            cout << "Sorry you are out of money. Try again next time." <<endl;
            exit(1);
        }
        cout << "Do you want to give it another try? (y for yes q to quit)" << endl;
        cin >> userAnswer;
        //play another hand. 
    }
    
}
    return 0;
    
}
