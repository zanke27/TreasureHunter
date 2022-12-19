#pragma once
#include "Object.h"

class Image;
class Player :

    public Object
{
private:
    Image* m_pImage;
public:
    Player();
    //Player(const Player& _origin) 
    //    : Object(_origin)
    //    , m_pImage(_origin.m_pImage)
    //{}
    ~Player();
private:
    virtual void	EnterCollision(Collider* _pOther);
    virtual void    ExitCollision(Collider* _pOther);
    virtual void    StayCollision(Collider* _pOther);
//    Player* Clone{ return new Player(*this); }
    CLONE(Player);
public:
    void Update()       override;
    void Render(HDC _dc) override;
};

