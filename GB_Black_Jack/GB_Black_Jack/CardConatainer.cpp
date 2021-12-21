#include "CardConatainer.h"

#include <iostream>
#include <random>
#include <tuple>


void CardConatainer::add_card(Card* cur_card)
{
    m_cards_.push_back(cur_card);
}

Card* CardConatainer::remove_card()
{
    if (!m_cards_.empty())
    {
        auto templ_card = m_cards_.back();
        m_cards_.pop_back();
        return templ_card;
    }
    return nullptr;
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
}

int PlayerHand::get_total() const
{
    bool check_ace {false};
    int total {};
    for (auto element : m_cards_)
    {
        int card_value {element->get_value()};
        total += card_value;
        if (card_value == 1)
        {
            check_ace = true;
        }
    }

    if (total < 11 && check_ace)
    {
        total += 10;
    }
    return total;
}

void PlayerHand::print_hand() const
{
    std::cout << "|";
    for (auto element : m_cards_)
    {
        element->print_card();
        std::cout << "|";
    }
}

void PlayerHand::flip_first()
{
    m_cards_[0]->flip();
}


void Deck::populate()
{
    clear_cards();
    // TODO Сделать замешивание зависимым от числа колод
    for (int card_suit = CLUBS; card_suit <= SPADES; ++card_suit)
    {
        for (int card_rank = ACE; card_rank <= KING; ++card_rank)
        {
            add_card(new Card(card_rank, card_suit));
        }
    }
}

int Deck::get_random_number(int max_range)
{
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> dist(0,max_range); // distribute results between 1 and 6 inclusive.
    return dist(gen);
}

void Deck::shuffle_deck()
{
    int deck_size = static_cast<int>(m_cards_.size()) - 1;
    for (auto &cur_card: m_cards_)
    {
        std::swap(cur_card, m_cards_[get_random_number(deck_size)]);
    }
}

Card* Deck::dealing_card()
{
    if (!m_cards_.empty())
    {
        return remove_card();
    }
    populate();
    shuffle_deck();
    return remove_card();
}
