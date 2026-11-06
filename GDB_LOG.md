# GDB log

One dated section per week. Paste the commands you used and the output you saw, then explain what it means in your own words. Pasted output with no explanation earns partial credit at most.

## Week 12 (Lab 12)

### The constructor chain

Commands, in the order you typed them, with one line on what each did:

break Hangman::Hangman
run
bt
break Game::Game
continue
bt
finish
bt
break Hangman::~Hangman
break Game::~Game
continue

Backtrace inside `Hangman::Hangman` (paste it):

#0  Hangman::Hangman (this=0xffffffffefd8)
    at /home/allison-avila/cosc1437/lab12/src/hangman_game.cpp:4
#1  0x0000aaaaaaaa3100 in main ()
    at /home/allison-avila/cosc1437/lab12/app/main.cpp:51

Backtrace inside `Game::Game` (paste it):

#0  Game::Game (this=0xffffffffefd8, title="Hangman")
    at /home/allison-avila/cosc1437/lab12/src/game.cpp:4
#1  0x0000aaaaaaaaa6f8 in Hangman::Hangman (this=0xffffffffefd8)
    at /home/allison-avila/cosc1437/lab12/src/hangman_game.cpp:6
#2  0x0000aaaaaaaa3100 in main ()
    at /home/allison-avila/cosc1437/lab12/app/main.cpp:51

Where `finish` returned to:

0x0000aaaaaaaaa6f8 in Hangman::Hangman (this=0xffffffffefd8)
    at /home/allison-avila/cosc1437/lab12/src/hangman_game.cpp:6

Order of destructor breakpoints when the program ended:

Hangman::~Hangman
Game::~Game

Construction order and destruction order, as read from the backtraces:

Game::Game
Hangman::Hangman

### What a base pointer shows

`print hangman` (paste it):

$1 = {
  <Game> = {
    m_title = "Hangman",
    m_last_score = 0
  },
  members of Hangman:
  m_times_played = 0
}

`print *g` (paste it):

$2 = {
  m_title = "Hangman",
  m_last_score = 0
}

What is different, and why:

print hangman showed both the inherited Game members and Hangman's own m_times_played member. print *g showed only the Game portion of the object because g is a Game pointer, so GDB displays the object through the base-class type.

`ptype Hangman` and `ptype g` (paste them):

type = class Hangman : public Game {
    int m_times_played;

  public:
    Hangman(void);
    void play(void);
    int times_played(void) const;
}

One sentence on what `ptype Hangman` revealed about inheritance:

ptype Hangman revealed that Hangman publicly inherits from Game and adds its own m_times_played data member while also inheriting Game's members and member functions.

