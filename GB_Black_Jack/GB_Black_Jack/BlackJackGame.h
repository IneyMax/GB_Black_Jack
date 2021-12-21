#pragma once
#include <vector>

#include "CardConatainer.h"
#include "GenericPlayer.h"


class BlackJackGame
{
    Deck * main_deck_;
    std::vector <Player*> m_players_;
    Dealer * m_dealer_;
public:
    BlackJackGame ();
    
    void play();
    void end_play();
    
    ~BlackJackGame();
};

