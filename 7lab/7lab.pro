TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    figure.cpp \
    hexagon.cpp \
    octagon.cpp \
    tarray.cpp \
    titerator.cpp \
    triangle.cpp \
    tstack.cpp \
    tstackitem.cpp \
    tremovecriteria.cpp \
    tremovecriteriaall.cpp \
    tremovecriteriavalue.cpp \
    tremovecriterialesssquare.cpp \
    titerator.cpp

HEADERS += \
    figure.h \
    hexagon.h \
    octagon.h \
    point.h \
    tarray.h \
    titerator.h \
    triangle.h \
    tstack.h \
    tstackitem.h \
    tremovecriteria.h \
    tremovecriteriaall.h \
    tremovecriteriavalue.h \
    tremovecriterialesssquare.h \
    titerator.h
