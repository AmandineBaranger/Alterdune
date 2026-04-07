cmake_minimum_required(VERSION 4.1)
project(ProjetA3S6)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProjetA3S6 main.cpp
        entite.h
        entite.cpp
        joueur.h
        joueur.cpp
        monstre.h
        monstre.cpp
        jeu.h
        jeu.cpp
        actionAct.h
        actionAct.cpp
        item.h
        item.cpp
        entreebestiaire.h
        entreebestiaire.cpp
        bestiaire.h
        bestiaire.cpp
        monstrenormal.h
        monstrenormal.cpp
        miniboss.h
        miniboss.cpp
        boss.h
        boss.cpp)
