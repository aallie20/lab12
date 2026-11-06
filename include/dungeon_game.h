#ifndef DUNGEON_GAME_H
#define DUNGEON_GAME_H

#include "game.h"

class Dungeon : public Game
{
public:
    Dungeon();

    void play();

    int times_played() const;

private:
    int m_times_played;
};

#endif
