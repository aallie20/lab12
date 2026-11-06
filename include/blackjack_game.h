#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H

#include "game.h"

class Blackjack : public Game
{
public:
    Blackjack();

    void play();

    int times_played() const;

private:
    int m_times_played;
};

#endif
