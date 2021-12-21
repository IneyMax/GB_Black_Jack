#pragma once


enum E_RANK
{
 ACE = 1,
 TWO,
 THREE,
 FOUR,
 FIVE,
 SIX,
 SEVEN,
 EIGHT,
 NINE,
 TEN,
 JACK,
 QUEEN,
 KING
};

enum E_SUIT
{
 CLUBS,
 DIAMONDS,
 HEARTS,
 SPADES
};

class Card
{
 bool b_is_face_up_ {true};
 E_RANK m_rank_ {};
 E_SUIT m_suit_ {};
 
public:
 Card(E_RANK c_rank, E_SUIT c_suit);

 Card(int c_rank, int c_suit);

 void flip();
 int get_value() const;
 void print_card() const;
};
