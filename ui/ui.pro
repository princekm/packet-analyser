######################################################################
# Automatically generated by qmake (3.1) Sat Jul 18 23:41:21 2020
######################################################################

QT += widgets xml
TEMPLATE = lib
TARGET = ui
win32:DESTDIR = ../exe/win
unix:DESTDIR = ../lib/unix

INCLUDEPATH += . \
                ../inc \
                ../types \
                ../engine \
                widgets \
                screens  \
                dialogs \
win32:INCLUDEPATH += ../pcap_win ../pcap_win/pcap
unix:INCLUDEPATH += ../pcap_linux


MOC_DIR = ../generated/moc
OBJECTS_DIR = ../generated/obj
CONFIG+=sdk_no_version_check
# Input
HEADERS += UIManager.h \
           dialogs/ArrayDialog.h \
           dialogs/DataTypeDialog.h \
           dialogs/FormatDialog.h \
           dialogs/NameEntryDialog.h \
           dialogs/ObjectTypeDialog.h \
           screens/MainScreen.h \
           widgets/CaptureWidget.h \
           widgets/ExplorerWidget.h \
           widgets/InspectorWidget.h \
           widgets/PacketEditor.h \
           widgets/SettingsWidget.h \
           widgets/SnackBar.h \
           screens/SplashScreen.h \
           widgets/Widget.h
SOURCES += UIManager.cpp \
           dialogs/ArrayDialog.cpp \
           dialogs/DataTypeDialog.cpp \
           dialogs/FormatDialog.cpp \
           dialogs/NameEntryDialog.cpp \
           dialogs/ObjectTypeDialog.cpp \
           screens/MainScreen.cpp \
           widgets/CaptureWidget.cpp \
           widgets/ExplorerWidget.cpp \
           widgets/InspectorWidget.cpp \
           widgets/PacketEditor.cpp \
           widgets/SettingsWidget.cpp \
           widgets/SnackBar.cpp \
           screens/SplashScreen.cpp \
           widgets/Widget.cpp

win32: LIBS += -L$$PWD/../exe/win/ -lengine
unix: LIBS += -L$$PWD/../lib/unix/ -lengine
win32: LIBS += -L$$PWD/../exe/win/ -ltypes
unix: LIBS += -L$$PWD/../lib/unix/ -ltypes
win32: LIBS += -L$$PWD/exe/win/ -lwsock32



RESOURCES += \
    ../resources/res.qrc
