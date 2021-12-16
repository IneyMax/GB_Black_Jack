#pragma once
#include <string>
#include <vector>

#include "CardConatainer.h"
#include "GenericPlayer.h"


class Game
{
public:
    Game(const std::vector<std::string>& players_names);
    
    // Начало игры
    void Play();

    ~Game();
    
private:
    Deck m_deck_;
    House m_house_;
    std::vector <Player> m_players_;
};

