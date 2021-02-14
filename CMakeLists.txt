cmake_minimum_required(VERSION 3.17)
project(Cards)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cards main.cpp Card.cpp Card.h global.h User.h Player.cpp Player.h Human.cpp Human.h Bot.cpp Bot.h Deck.cpp Deck.h Table.cpp Table.h GCard.h global.cpp)