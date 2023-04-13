#include "card.hpp"
using namespace ariel;
Card::Card(int num,string name,string type)
{
    this->num=num;
    this->name=name;
    this->type=type;
}

int Card:: getNum()
{
    return num;
}

string Card:: getCard()
{
    return name+" "+type;
}
void Card:: setCard(int num, string name, string type)
{
    this->num=num;
    this->name=name;
    this->type=type;
}
string Card:: getType()
{
    return type;
}
string Card:: getName()
{
    return name;
}
Card::~Card()
{
}
