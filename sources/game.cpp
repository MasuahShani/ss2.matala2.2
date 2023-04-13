#include "game.hpp"
using namespace ariel;
Game:: Game(Player& p1, Player& p2):
p1(&p1),p2(&p2)
{
    this->situations="";
    this->lastTurn="";
    this->winer=0;
    this->draw=0;
    this->amount_cards=0;
    this->gameOver=0;
    this->cards=new Card[52];
    this->num_turn=0;



    for(int i=2 ; i<11; i++)
    {
        setCard(i,to_string(i),"of heart");
        
        setCard(i,to_string(i),"of diamond");
        
        setCard(i,to_string(i),"of leaf");
        
       setCard(i,to_string(i),"of clover");
        
    }

    
    setCard(14,"ace","of heart");
    setCard(14,"ace","of diamond");
    setCard(14,"ace","of leaf");
    setCard(14,"ace","of clover");
    

    setCard(13,"king","of heart");
    setCard(13,"king","of diamond");
    setCard(13,"king","of leaf");
    setCard(13,"king","of clover");


    setCard(12,"queen","of heart");
    setCard(12,"queen","of diamond");
    setCard(12,"queen","of leaf");
    setCard(12,"queen","of clover");


    setCard(11,"prince","of heart");
    setCard(11,"prince","of diamond");
    setCard(11,"prince","of leaf");
    setCard(11,"prince","of clover");

    

    
    while (this->p1->stacksize()<26)
    {
        
        Card c1=getCard();
        Card c2=getCard();

        this->p1->setCard(c1);
        this->p2->setCard(c2);
    }
    


} 


Game::~Game()
{
    delete[] cards;
}

void Game:: playTurn()
{
    if(gameOver==1)
    {
        throw std::invalid_argument("The game is over");
        return;
    }
    if(p1==p2)
    {
        throw std::invalid_argument("Try with diffrent plyers");
        return;

    }
    num_turn++;
   
    if(p1->stacksize()==0)// if we finished
    {
        num_turn--;
        if(p1->cardesTaken()>p2->cardesTaken())
        {
            this->winer=1;
        }
        else if (p1->cardesTaken()<p2->cardesTaken())
        {
            this->winer=2;
        }
        else
        {
            this->winer=-1;
        }
        
        gameOver=1;
        cout << "GAME OVER" << endl;
        return;
    }
    if(p1->stacksize()==1)// the last turn
    {
        Card card_p1=p1->getCard();
        Card card_p2=p2->getCard();
       
        int p1_card_num=card_p1.getNum();
        int p2_card_num=card_p2.getNum();
        string p1_str=card_p1.getCard();
        string p2_str=card_p2.getCard();

        //2 wins ace
        if((p1_card_num==14&&p2_card_num==2)||(p2_card_num==14&&p1_card_num==2))
        {
            if(p1_card_num>p2_card_num)
            {
                p2->addWin(2);
                (this->situations)+=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". "+p2->getName()+" wins. ";
                (this->lastTurn)=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". "+p2->getName()+" wins. ";
                
            }
            p1->addWin(2);
            (this->situations)+=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". "+p1->getName()+" wins. ";
            (this->lastTurn)=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". "+p1->getName()+" wins. ";
            
        }

        else if(p1_card_num>p2_card_num)
        {
            p1->addWin(2);
            (this->situations)+=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". "+p1->getName()+" wins. ";
            (this->lastTurn)=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". "+p1->getName()+" wins. ";
            
        }
        else if(p1_card_num<p2_card_num)
        {
            p2->addWin(2);
            (this->situations)+=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". "+p2->getName()+" wins. ";
            (this->lastTurn)=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". "+p2->getName()+" wins. ";
            
        }
        else
        {
            draw++;
        }
        playTurn();// for the finish
        return;
    }

    Card table [52];// the cards that on the table
    int indx_table=0;
    Card card_p1=p1->getCard();
    Card card_p2=p2->getCard();
    table[indx_table++]=card_p1;//put the cards on the table
    table[indx_table++]=card_p2;
   
    int p1_card_num=card_p1.getNum();
    int p2_card_num=card_p2.getNum();
    string p1_str=card_p1.getCard();
    string p2_str=card_p2.getCard();

    //2 wins ace
    if((p1_card_num==14&&p2_card_num==2)||(p2_card_num==14&&p1_card_num==2))
    {
        if(p1_card_num>p2_card_num)
        {
            p2->addWin(2);
            (this->situations)+=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". "+p2->getName()+" wins. ";
            (this->lastTurn)=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". "+p2->getName()+" wins. ";
            return;
        }
        p1->addWin(2);
        (this->situations)+=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". "+p1->getName()+" wins. ";
        (this->lastTurn)=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". "+p1->getName()+" wins. ";
        return;
    }

    if(p1_card_num>p2_card_num)
    {
        p1->addWin(2);
        (this->situations)+=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". "+p1->getName()+" wins. ";
        (this->lastTurn)=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". "+p1->getName()+" wins. ";
        return;
    }
    else if(p1_card_num<p2_card_num)
    {
        p2->addWin(2);
        (this->situations)+=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". "+p2->getName()+" wins. ";
        (this->lastTurn)=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". "+p2->getName()+" wins. ";
        return;
    }
    else //draw
    {
        (this->lastTurn)="";
        
        while(p1->stacksize()==1 && p1_card_num==p2_card_num)
        {
            draw++;
            (this->situations)+=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". draw ";
            (this->lastTurn)+=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". draw ";
            card_p1=p1->getCard();
            card_p2=p2->getCard();
            if(card_p1.getNum()==card_p2.getNum()&&card_p2.getNum()==table[indx_table-1].getNum())
            {
                //if the last 4 cards is the same, the game over
                draw++;
                lastTurn+=" the last 4 cards is the same, the game over. ";
                playTurn();
                return;
            }
            //return the cards
            p1->setCard(card_p1);
            p2->setCard(card_p2);
            p1->setCard(table[indx_table--]);
            p2->setCard(table[indx_table--]);

            //and play again
            card_p1=p1->getCard();
            card_p2=p2->getCard();
            p1_card_num=card_p1.getNum();
            p2_card_num=card_p2.getNum();
            
        }

        
        while (p1->stacksize()>1 && p1_card_num==p2_card_num)
        {
            draw++;

            (this->situations)+=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". draw. ";
            (this->lastTurn)+=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". draw. ";

            //Put a card face down on the table
            card_p1=p1->getCard();
            card_p2=p2->getCard();
            table[indx_table++]=card_p1;
            table[indx_table++]=card_p2;
            // take card
            card_p1=p1->getCard();
            card_p2=p2->getCard();
            table[indx_table++]=card_p1;
            table[indx_table++]=card_p2;

            p1_card_num=card_p1.getNum();
            p2_card_num=card_p2.getNum();
            p1_str=card_p1.getCard();
            p2_str=card_p2.getCard();
          
                    
            if((p1->stacksize()==0||p1->stacksize()==1) && p1_card_num==p2_card_num)//Give each player half
            {                
                int half=indx_table/2;
                while(indx_table>half)
                {
                    p1->setCard(table[--indx_table]);
                }
                while(indx_table>0)
                {
                    p2->setCard(table[--indx_table]);
                }

            }

        }
        //2 wins ace
        if((p1_card_num==14&&p2_card_num==2)||(p2_card_num==14&&p1_card_num==2))
        {
            if(p1_card_num>p2_card_num)
            {
                p2->addWin(indx_table);
                (this->situations)+=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". "+p2->getName()+" wins. ";
                (this->lastTurn)+=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". "+p2->getName()+" wins. ";
                return;
            }
            p1->addWin(indx_table);
            (this->situations)+=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". "+p1->getName()+" wins. ";
            (this->lastTurn)+=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". "+p1->getName()+" wins. ";
            return;
        }

        if(p1_card_num>p2_card_num)
        {
            p1->addWin(indx_table);//takes all the cards on the table
            (this->situations)+=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". "+p1->getName()+" wins. ";
            (this->lastTurn)+=p1->getName()+" played "+p1_str+" "+p2->getName()+" played "+p2_str+". "+p1->getName()+" wins. ";
            return;
        }
        else if(p1_card_num<p2_card_num)
        {
            p2->addWin(indx_table);
            (this->situations)+=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". "+p2->getName()+" wins. ";
            (this->lastTurn)+=p2->getName()+" played "+p2_str+" "+p1->getName()+" played "+p1_str+". "+p2->getName()+" wins. ";
            return;
        }
        
    }
}

void Game:: printLastTurn()
{
    cout << this->lastTurn << endl;
}
void Game:: playAll()
{
    while (this->winer==0)
    {
        playTurn();
    }
    
}
void Game:: printWiner()
{
    if(this->winer==0)
    {
        cout << "There is no winer yet" << endl;
    }
    else if(this->winer==-1)
    {
        cout << "Drow" << endl;
    }
    else if(this->winer==1)
    {
        cout << p1->getName() << endl;
    }
    else if(this->winer==2)
    {
        cout << p2->getName() << endl;
    }
}
void Game:: printLog()
{
    cout << this->situations << endl;
}
void Game:: printStats()
{
    cout << p1->getName() + " stats:" << endl;
    cout << "win rate: "<<(double)p1->get_amount_winnings()/num_turn<< " cards won:"<<p1->cardesTaken()<<" num wins:"<<p1->get_amount_winnings()<<endl;
    cout << p2->getName() + " stats:" << endl;
    cout << "win rate: "<<(double)p2->get_amount_winnings()/num_turn<< " cards won:"<<p2->cardesTaken()<<" num wins:"<<p2->get_amount_winnings()<<endl;
    cout << "draw rate: "<<(double)draw/num_turn<<" num draw: "<<draw<<endl;
    cout<<"amount turn: "<<num_turn<<endl;

}
Card Game:: getCard()
{
    srand(time(0));
    int rand_indx=rand()%amount_cards;

    Card card=cards[rand_indx];
    cards[rand_indx]=cards[--amount_cards];
    
    return card;

}
void Game:: setCard(int num, string name, string type)
{
    cards[amount_cards++].setCard(num,name,type);

}

Game:: Game(Game& g)
    {
        p1=g.p1;
        p2=g.p2;
        situations=g.situations;
        lastTurn=g.lastTurn;
        draw=g.draw;
        amount_cards=g.amount_cards;
        num_turn=g.num_turn;
        gameOver=g.gameOver;
        for (int i = 0; i < amount_cards; i++)
        {
            cards[i]=g.cards[i];
        }
        
    }
Game:: Game( Game && g) noexcept
    {
        p1=g.p1;
        p2=g.p2;
        situations=g.situations;
        lastTurn=g.lastTurn;
        draw=g.draw;
        amount_cards=g.amount_cards;
        cards=g.cards;
        num_turn=g.num_turn;
        gameOver=g.gameOver;

        g.cards=NULL;

    }
