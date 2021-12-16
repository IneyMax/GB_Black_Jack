#include "Game.h"


Game::Game(const std::vector<std::string>& players_names)
{
    m_deck_.populate();
    m_deck_.shuffle_deck();
}


