#include "CardConatainer.h"

#include <iostream>
#include <random>
#include <tuple>


void CardConatainer::add_card(Card* pCard)
{
    m_cards_.push_back(pCard);
}

void CardConatainer::clear_cards()
{
    // проходит по вектору, освобождая всю память в куче
    std::vector<Card*>::iterator iter = m_cards_.begin();
    for (iter = m_cards_.begin(); iter != m_cards_.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    // очищает вектор указателей
    m_cards_.clear();

}

CardConatainer::~CardConatainer()
{
    clear_cards();
};

void Deck::populate()
{
    clear_cards();
    
    for (int card_suit = CLUBS; card_suit <= SPADES; ++card_suit)
    {
        for (int card_rank = ACE; card_rank <= KING; ++card_rank)
        {
            // TODO Разобраться, можно ли хранить только значения без ссылки
            add_card(new Card(card_rank, card_suit));
        }
    }

}

int Deck::get_random_number()
{
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> dist(0,51); // distribute results between 1 and 6 inclusive.
    return dist(gen);
}

void Deck::shuffle_deck()
{
    // TODO Сделать замешивание зависимым от числа колод
    for (auto cur_card: m_cards_)
    {
        std::swap(cur_card, m_cards_[get_random_number()]);
    }
}

void Deck::deal_card(CardConatainer& player_hand)
{
    if (!m_cards_.empty())
    {
        player_hand.add_card(m_cards_.back());
        m_cards_.pop_back();
    }
    else
    { // Чтобы колода была бессконечной
        populate();
        shuffle_deck();
        deal_card(player_hand);
    }
}
