cmake_minimum_required(VERSION 3.21)
project(ShadowlandsController)

set(CMAKE_CXX_STANDARD 14)

add_executable(ShadowlandsController main.cpp Stats.h Stats.cpp Spell.h SWPain.cpp SWPain.h Controller.cpp Controller.h MindBlast.cpp MindBlast.h MindFlay.cpp MindFlay.h TollTheDead.cpp TollTheDead.h Items.cpp Items.h)
