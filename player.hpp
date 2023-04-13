#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


#include "card.hpp"

namespace ariel{
class Player
{
private:
    string name;
    int amount_cards;
    int amount_winning;
    int cardesT;
    Card* cards;

    

public:
    Player(string const &name);
    Player(Player &p):
    Player(p.name)
    {
        amount_winning=p.amount_winning;
        amount_cards=p.amount_cards;
        cardesT=p.cardesT;
        for(int i=0;i<amount_cards;i++)
        {
            cards[i]=p.cards[i];
        }
    }
    Player(Player &&p) noexcept
    {
        name=p.name;
        amount_winning=p.amount_winning;
        amount_cards=p.amount_cards;
        cardesT=p.cardesT;
        cards=p.cards;
        p.cards=NULL;
    }
    Player();
    ~Player();
    int stacksize();
    int cardesTaken();
    void addWin(int);
    int get_amount_winnings();
    string getName();
   
    void setCard(int,string,string);
    void setCard(Card);
    Card getCard();
    Player& operator=(const Player& other)
    {
        if (this != &other)
        {
            this->name=other.name;
            this->amount_cards=other.amount_cards;
            this->amount_winning=other.amount_winning;
            this->cardesT=other.cardesT;
            for (int i = 0; i < amount_cards; i++)
            {
                (this->cards)[i]=other.cards[i];
            }
           

        }
        return *this;
    }
    Player& operator=(Player&& other) noexcept
    {
        if (this != &other)
        {
            this->name=other.name;
            this->amount_cards=other.amount_cards;
            this->amount_winning=other.amount_winning;
            this->cardesT=other.cardesT;
            this->cards=other.cards;
            other.cards=NULL;
           

        }
        return *this;
    }

};
}

