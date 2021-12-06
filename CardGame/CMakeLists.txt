cmake_minimum_required(VERSION 3.20)
project(CardGame)

set(CMAKE_CXX_STANDARD 11)

add_executable(CardGame main.cpp Card.h CardFactory.h Player.h TradeArea.h Hand.h Chain.h DiscardPile.h Table.h)
