#include "GenericPlayer.h"


std::ostream& operator<<(std::ostream& os, const GenericPlayer& Current_Player)
{
    return os;
}

GenericPlayer::GenericPlayer(const std::string& name)
{
    
}

bool GenericPlayer::IsHitting()
{
    return false;
}

bool GenericPlayer::IsBusted()
{
    return false;
}

void GenericPlayer::Bust() 
{
}

GenericPlayer::~GenericPlayer()
{
}

Player::Player(const std::string& name)
{
}

bool Player::IsHitting()
{
    return GenericPlayer::IsHitting();
}

void Player::Win() const
{
}

void Player::Lose() const
{
}

void Player::Push() const
{
}

Player::~Player()
{
}

int GenericPlayer::GetTotal() const
{
    // находим сумму очков всех карт, каждый туз дает 1 очко и определяем, держит ли рука туз
    int total = 0;
    bool containsAce = false;
    std::vector<Card*>::const_iterator iter;
    for (iter = m_cards_.begin(); iter != m_cards_.end(); ++iter)
    {
        int card_value = (*iter)->get_value_();
        if ((*iter)->get_value_() == ACE)
        {
            containsAce = true;
        }
        total += card_value;
    }
    
    // если рука держит туз и сумма маленькая, добавляем 10 очков
    if (containsAce && total <= 11)
    {
        total += 10;
    }
    
    return total;
}


House::House(const std::string& name)
{
}

bool House::IsHitting()
{
    return {};
}

void House::FlipFirstCard()
{
    
}

House::~House()
{
    
}