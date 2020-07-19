######################################################################
# Automatically generated by qmake (3.1) Sat Jul 18 23:39:48 2020
######################################################################

TEMPLATE = lib
DESTDIR = ../lib
TARGET = engine
MOC_DIR = ../generated/moc
OBJECTS_DIR = ../generated/obj
INCLUDEPATH += .    \
                ../pcap


HEADERS += DataStore.h Worker.h
SOURCES += DataStore.cpp Worker.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/release/ -lpcap
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/debug/ -lpcap
else:unix: LIBS += -L$$PWD/../lib/ -lpcap

INCLUDEPATH += $$PWD/../pcap
DEPENDPATH += $$PWD/../pcap

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../lib/release/libpcap.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../lib/debug/libpcap.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../lib/release/pcap.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../lib/debug/pcap.lib
else:unix: PRE_TARGETDEPS += $$PWD/../lib/libpcap.a