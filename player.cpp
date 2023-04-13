#include "player.hpp"
using namespace ariel;
    Player:: Player(string const &name)
    {
        this->name=name;
        this->amount_cards=0;
        this->amount_winning=0;
        this->cardesT=0;
        this->cards= new Card[26];
    }
    Player:: Player()
    {
        name="";
        amount_cards=0;
        amount_winning=0;
        cardesT=0;
        cards=new Card[26];
    }
    Player:: ~Player()
    {
        delete[] cards;
    }
    int Player:: stacksize()
    {
        return amount_cards;
    }

    int Player:: cardesTaken()
    {
        return cardesT;
    }
    
    void Player:: addWin(int cards)
    {
        amount_winning++;
        cardesT+=cards;
        
    }
    int Player:: get_amount_winnings()
    {
        return amount_winning;
    }
    string Player:: getName()
    {
        return name;
    }
    void Player:: setCard(int num, string name, string type)
    {
        cards[amount_cards++].setCard(num,name,type);

    }
    void Player:: setCard(Card c)
    {
        cards[amount_cards++].setCard(c.getNum(),c.getName(),c.getType());

    }
    Card Player:: getCard()
    {        
        return cards[--amount_cards];

    }
