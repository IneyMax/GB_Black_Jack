#pragma once
#include <string>

#include "CardConatainer.h"


// абстрактный класс
class GenericPlayer : public CardConatainer
{
protected:
    std::string m_name_;
    friend std::ostream& operator << (std::ostream& os, const GenericPlayer& Current_Player);
public:
    GenericPlayer(const std::string& name = "");

    int GetTotal() const;
    
    // показывает, хочет ли игрок продолжать брать карты
    virtual bool IsHitting();

    // возвращает значение, если у игрока перебор -
    // сумму очков большую 21
    bool IsBusted();
    
    // объявляет, что игрок имеет перебор
    // функция одинакова как для игрока, так и для дилера
    void Bust();
    
protected:
    virtual ~GenericPlayer();
};


class Player : public GenericPlayer
{
public:
    Player(const std::string & name = "");
    
    // показывает, хочет ли игрок продолжать брать карты
    bool IsHitting() override;
    
    // объявляет, что игрок победил
    void Win() const;
    
    // объявляет, что игрок проиграл
    void Lose() const;
    
    // объявляет ничью
    void Push() const;

    virtual ~Player();
};


class House : public GenericPlayer
{
public:
    House(const std::string & name = "House");
    
    // показывает, хочет ли дилер продолжать брать карты
    bool IsHitting() override;
    
    // переворачивает первую карту
    void FlipFirstCard();

    virtual ~House();
};


