######################################################################
# Automatically generated by qmake (3.1) Sun Jul 19 00:10:27 2020
######################################################################
QT += widgets
TEMPLATE = app
DESTDIR = ../
CONFIG -= app_bundle
TARGET = PacketAnalyser
INCLUDEPATH += . \
            ../ui/ \
            ../ui/widgets \
            ../ui/screens \
            ../engine



# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += AppManager.h
SOURCES += AppManager.cpp main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/release/ -lui.1.0.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/debug/ -lui.1.0.0
else:unix: LIBS += -L$$PWD/../lib/ -lui.1.0.0

INCLUDEPATH += $$PWD/../ui
DEPENDPATH += $$PWD/../ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/release/ -lengine.1.0.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/debug/ -lengine.1.0.0
else:unix: LIBS += -L$$PWD/../lib/ -lengine.1.0.0

INCLUDEPATH += $$PWD/../engine
DEPENDPATH += $$PWD/../engine