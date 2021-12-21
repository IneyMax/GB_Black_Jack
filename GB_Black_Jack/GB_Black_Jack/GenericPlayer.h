#pragma once
#include <string>
#include "CardConatainer.h"


class GenericPlayer
{
protected:
    Deck *main_deck_;
    PlayerHand p_hand_;
    std::string p_name_;
public:
    GenericPlayer(Deck * main_deck);
    
    int get_total() const;
    void addltional_card();
    void print_hand();
    
    virtual void turn() = 0;
    
    virtual ~GenericPlayer(){};
};


class Player : public GenericPlayer
{
public:
    explicit Player(const std::string & name, Deck * main_deck);
    
    void turn() override;
    
    virtual ~Player(){}
};


class Dealer : public GenericPlayer
{
public:
    Dealer(Deck * main_deck);

    void flip_first();
    void turn() override;
    
    virtual ~Dealer(){}
};




