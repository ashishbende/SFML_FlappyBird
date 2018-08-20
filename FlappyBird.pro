TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    statemachine.cpp \
    assetmanager.cpp \
    inputmanager.cpp \
    mygame.cpp \
    splashstate.cpp

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
    splashstate.h
