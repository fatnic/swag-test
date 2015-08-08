TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=c++11

LIBS += -lsfml-system -lsfml-graphics -lsfml-window

HEADERS += \
    game.hpp \
    gamestate.hpp \
    mainmenu.hpp \
    maingame.hpp \
    player.h \
    entity.h \
    guard.h \
    pause.h \
    npc.h

SOURCES += \
    game.cpp \
    main.cpp \
    mainmenu.cpp \
    maingame.cpp \
    player.cpp \
    entity.cpp \
    guard.cpp \
    pause.cpp \
    npc.cpp

