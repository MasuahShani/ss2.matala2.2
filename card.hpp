#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

namespace ariel{
class Card
{
private:
    int num;
    string name;
    string type;
public:
    Card(int,string,string);
    Card(){
        num=0;
        name="";
        type="";
    }
    Card(Card &c)
    {
        num=c.getNum();
        name=c.getName();
        type=c.getType();
    }
    Card(Card &&c) noexcept
    {
        num=c.getNum();
        name=c.getName();
        type=c.getType();
    }
    int getNum();
    string getCard();
    void setCard(int, string, string);
    string getType();
    string getName();
    ~Card();
    Card& operator=(const Card& other)
    {
        if (this != &other)
        {
            this->num=other.num;
            this->name=other.name;
            this->type=other.type;
        }
        return *this;
    }
    Card& operator=(Card&& other) noexcept
    {
        if (this != &other)
        {
            this->num=other.num;
            this->name=other.name;
            this->type=other.type;
        }
        return *this;
    }
};
}

