#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "player.hpp"
#include "card.hpp"

namespace ariel{
class Game
{
private:
    Player* p1;
    Player* p2;
    string situations;
    string lastTurn;
    int winer;
    int draw;
    int amount_cards;
    Card* cards;
    int num_turn;
    int gameOver;
    

public:
    Game(Player&, Player&);
    Game(Game&);
    ~Game();
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    Card getCard();
    void setCard(int, string, string);
    Game& operator=(const Game& other)
    {
        if (this != &other)
        {
            this->p1=other.p1;
            this->p2=other.p2;
            this->situations=other.situations;
            this->lastTurn=other.lastTurn;
            this->winer=other.winer;
            this->draw=other.draw;
            this->amount_cards=other.amount_cards;
            for (int i = 0; i < amount_cards; i++)
            {
                (this->cards)[i]=other.cards[i];
            }
            this->num_turn=other.num_turn;
            this->gameOver=other.gameOver;

        }
        return *this;
    }
    Game( Game && ) noexcept;
    Game& operator=(Game&& other) noexcept
    {
        if (this != &other)
        {
            this->p1=other.p1;
            this->p2=other.p2;
            this->situations=other.situations;
            this->lastTurn=other.lastTurn;
            this->winer=other.winer;
            this->draw=other.draw;
            this->amount_cards=other.amount_cards;
            this->cards=other.cards;
            this->num_turn=other.num_turn;
            this->gameOver=other.gameOver;
            other.cards=NULL;

        }
        return *this;
    }

    

};
}





