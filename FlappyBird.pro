TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    statemachine.cpp \
    assetmanager.cpp \
    inputmanager.cpp \
    mygame.cpp \
    splashstate.cpp \
    mainmenustate.cpp \
    gamestate.cpp \
    gameoverstate.cpp \
    pipe.cpp \
    land.cpp \
    bird.cpp \
    collision.cpp \
    flash.cpp \
    hud.cpp

LIBS += -lsfml-audio
LIBS += -lsfml-graphics
LIBS += -lsfml-network
LIBS += -lsfml-window
LIBS += -lsfml-system

HEADERS += \
    state.h \
    statemachine.h \
    assetmanager.h \
    inputmanager.h \
    mygame.h \
    definitions.h \
    splashstate.h \
    mainmenustate.h \
    gamestate.h \
    gameoverstate.h \
    pipe.h \
    land.h \
    bird.h \
    collision.h \
    flash.h \
    hud.h
