#pragma once
#include <vector>
#include "Card.h"

class CardConatainer
{
protected:
 std::vector<Card*> m_cards_;
public:
 // добавляем карту в контейнер     
 void add_card(Card* pCard);
    
 // очищаем контейнер от карт
 void clear_cards();

 virtual ~CardConatainer();
};

class Deck : public CardConatainer
{
public:
 // создает стандартную колоду из 52 карт
 void populate();
 int get_random_number();
 void shuffle_deck();
    
 // раздает одну карту в руку
 void deal_card(CardConatainer& player_hand);
 
 virtual ~Deck()
 {
  clear_cards();
 };
};

