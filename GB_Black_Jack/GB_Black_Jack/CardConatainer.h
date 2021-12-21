#pragma once
#include <vector>
#include "Card.h"

class CardConatainer
{
protected:
    std::vector<Card*> m_cards_;
public:
    // добавляем карту в контейнер
    void add_card(Card* cur_card);
    Card* remove_card();
 
    // очищаем контейнер от карт
    void clear_cards();

    virtual ~CardConatainer();
};


class PlayerHand : public  CardConatainer
{
public:
    int get_total() const;
    void print_hand() const;
    void flip_first();
    
    virtual ~PlayerHand(){};
};


class Deck : public CardConatainer
{
    int deck_number_;
    
    int get_random_number(int max_range);

public:
    explicit Deck(int deck_number)
        : deck_number_(deck_number)
    {
        populate();
        shuffle_deck();
    }
    
    void populate();
    void shuffle_deck();
    Card* dealing_card();

    virtual ~Deck(){};
};

