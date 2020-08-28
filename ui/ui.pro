######################################################################
# Automatically generated by qmake (3.1) Sat Jul 18 23:41:21 2020
######################################################################

QT += widgets xml
TEMPLATE = lib
TARGET = ui
win32:DESTDIR = ../exe/win
unix!macx:DESTDIR = ../lib/linux
macx:DESTDIR = ../lib/mac

INCLUDEPATH += . \
                ../inc \
                ../types \
                ../engine \
                widgets \
                screens  \
                dialogs \

win32:INCLUDEPATH += ../pcap/pcap_win ../pcap/pcap_win/pcap
unix:!macx:INCLUDEPATH += ../pcap/pcap_linux
macx:INCLUDEPATH += ../pcap/pcap_mac


MOC_DIR = ../generated/moc
OBJECTS_DIR = ../generated/obj
CONFIG+=sdk_no_version_check
# Input
HEADERS += UIManager.h \
           dialogs/AboutDialog.h \
           dialogs/ArrayDialog.h \
           dialogs/DataTypeDialog.h \
           dialogs/FormatDialog.h \
           dialogs/NameEntryDialog.h \
           dialogs/ObjectTypeDialog.h \
           dialogs/PacketDialog.h \
           screens/MainScreen.h \
           widgets/CaptureWidget.h \
           widgets/ExplorerWidget.h \
           widgets/InspectorWidget.h \
           widgets/MenuBar.h \
           widgets/PacketEditor.h \
           widgets/SettingsWidget.h \
           widgets/SnackBar.h \
           screens/SplashScreen.h \
           widgets/Widget.h
SOURCES += UIManager.cpp \
           dialogs/AboutDialog.cpp \
           dialogs/ArrayDialog.cpp \
           dialogs/DataTypeDialog.cpp \
           dialogs/FormatDialog.cpp \
           dialogs/NameEntryDialog.cpp \
           dialogs/ObjectTypeDialog.cpp \
           dialogs/PacketDialog.cpp \
           screens/MainScreen.cpp \
           widgets/CaptureWidget.cpp \
           widgets/ExplorerWidget.cpp \
           widgets/InspectorWidget.cpp \
           widgets/MenuBar.cpp \
           widgets/PacketEditor.cpp \
           widgets/SettingsWidget.cpp \
           widgets/SnackBar.cpp \
           screens/SplashScreen.cpp \
           widgets/Widget.cpp

win32: LIBS += -L$$PWD/../exe/win/ -lengine
win32: LIBS += -L$$PWD/../exe/win/ -ltypes
win32: LIBS += -L$$PWD/exe/win/ -lwsock32
unix!macx: LIBS += -L$$PWD/../lib/linux/ -lengine
unix:!macx: LIBS += -L$$PWD/../lib/linux/ -ltypes
macx: LIBS += -L$$PWD/../lib/mac/ -lengine
macx: LIBS += -L$$PWD/../lib/mac/ -ltypes



RESOURCES += \
    ../resources/res.qrc