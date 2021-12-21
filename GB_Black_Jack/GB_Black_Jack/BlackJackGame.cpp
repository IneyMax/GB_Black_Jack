#include "BlackJackGame.h"

#include <iostream>


BlackJackGame::BlackJackGame()
{
    // Создание и замешивание колоды TODO Добавить ограничение по диапозону по количеству колод
    std::cout << "Enter the number of decks to mix: ";
    int deck_number {1};
    //std::cin >> deck_number;
    main_deck_ = new Deck(deck_number);

    // Создание дилера
    m_dealer_ = new Dealer (main_deck_);
    
    // Запрос количества и имён игроков. TODO Добавить ограничение по диапозону по количеству игроков
    std::cout << "Enter the number of players: ";
    int player_number {1};
    //std::cin >> player_number;
    int i {};
    while (i < player_number)
    {
        std::cout << "Enter the player's name: ";
        std::string player_name {"Ivan"};
        //std::cin >> player_name;
        m_players_.push_back(new Player(player_name, main_deck_));
        i ++;
    }

    std::cout << std::endl;
}

void BlackJackGame::play()
{
    {   // Раздача карт
        for (auto player : m_players_)
        {
            player->addltional_card();
            player->addltional_card();
        }
        m_dealer_->addltional_card();
        m_dealer_->addltional_card();
    }

    {   // Печать рук игроков
        for (auto player : m_players_)
        {
            player->print_hand();
        }
        m_dealer_->flip_first();
        m_dealer_->print_hand();
    }
    
    {   // Раунды игроков и дилера
        for (auto player : m_players_)
        {
            player->turn();
        }
        m_dealer_->flip_first();
        m_dealer_->turn();
        m_dealer_->print_hand();
    }
}

void BlackJackGame::end_play()
{
}

BlackJackGame::~BlackJackGame()
{
    // TODO Тут будут уничтожаться все динамические обьекты
}
