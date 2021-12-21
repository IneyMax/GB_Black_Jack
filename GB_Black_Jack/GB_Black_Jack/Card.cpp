#include "Card.h"

#include <iostream>


Card::Card(E_RANK c_rank, E_SUIT c_suit)
: 
  m_rank_(c_rank),
  m_suit_(c_suit)
{
}

Card::Card(int c_rank, int c_suit)
: 
  m_rank_(static_cast<E_RANK>(c_rank)),
  m_suit_(static_cast<E_SUIT>(c_suit))
{
}

void Card::flip()
{
    b_is_face_up_ = !(b_is_face_up_);
}


int Card::get_value() const
{
    // если карта перевернута лицом вниз, ее значение равно О
    int value = 0;
    if (b_is_face_up_)
    {
        // значение - это число, указанное на карте
        value = m_rank_;
        // значение равно 10 для JACK, QUEEN и KING
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}

void Card::print_card() const
{
    if (b_is_face_up_)
    {
        std::cout << m_rank_ << " " <<m_suit_;
    }
    else
    {
        std::cout << "* *";
    }
}


