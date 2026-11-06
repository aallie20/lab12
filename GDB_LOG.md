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

`print *g` (paste it):

What is different, and why:

`ptype Hangman` and `ptype g` (paste them):

One sentence on what `ptype Hangman` revealed about inheritance:
