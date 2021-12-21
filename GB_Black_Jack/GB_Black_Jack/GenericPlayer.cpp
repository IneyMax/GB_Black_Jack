#include "GenericPlayer.h"
#include <iostream>


GenericPlayer::GenericPlayer(Deck * main_deck)
{
    main_deck_ = main_deck;
}

int GenericPlayer::get_total() const
{
    return p_hand_.get_total();
}

void GenericPlayer::addltional_card()
{
    p_hand_.add_card (main_deck_->dealing_card());
}

void GenericPlayer::print_hand()
{
    std::cout << p_name_ << ":\t";
    p_hand_.print_hand();
    std::cout << std::endl;
}

Player::Player(const std::string& name, Deck * main_deck):
    GenericPlayer(main_deck)
{
    p_name_ = name;
}

void Player::turn()
{
    char hit {};
    while (hit != 'n')
    {
        std::cin >> hit;
        if (hit == 'y')
        {
            addltional_card();
            print_hand();
            
            if (p_hand_.get_total() >= 21)
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}

Dealer::Dealer(Deck * main_deck): GenericPlayer(main_deck)
{
    p_name_ = "Dealer";
}

void Dealer::flip_first()
{
    p_hand_.flip_first();
}


void Dealer::turn()
{
    while (p_hand_.get_total() <= 16)
    {
        addltional_card();
        print_hand();
        
        if (p_hand_.get_total() >= 21)
        {
            break;
        }
    }
}
