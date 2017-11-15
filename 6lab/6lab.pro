TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    figure.cpp \
    hexagon.cpp \
    octagon.cpp \
    titerator.cpp \
    triangle.cpp \
    tstack.cpp \
    tstackitem.cpp \
    tallocationblock.cpp

HEADERS += \
    figure.h \
    hexagon.h \
    octagon.h \
    point.h \
    titerator.h \
    triangle.h \
    tstack.h \
    tstackitem.h \
    tallocationblock.h
