TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

INCLUDEPATH += $$PWD/include/

SOURCES += $$PWD/src/*.cpp
#HEADERS += $$PWD/include/*.hpp

SOURCES += main.cpp \
    wall.cpp \
    entity.cpp \
    game.cpp \
    guard.cpp \
    maingame.cpp \
    mainmenu.cpp \
    npc.cpp \
    pause.cpp \
    player.cpp

LIBS += -lsfml-window -lsfml-system -lsfml-graphics -lz


HEADERS += \
    wall.h \
    entity.h \
    game.h \
    gamestate.h \
    guard.h \
    maingame.h \
    mainmenu.h \
    npc.h \
    pause.h \
    player.h


