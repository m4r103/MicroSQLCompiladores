TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pugixml.cpp \
    Tabla.cpp

HEADERS += \
    pugiconfig.hpp \
    pugixml.hpp \
    Tabla.h
