TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    hexagon.cpp \
    triangle.cpp \
    octagon.cpp \
    figure.cpp

HEADERS += \
    figure.h \
    hexagon.h \
    triangle.h \
    octagon.h \
    point.h
