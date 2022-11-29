QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        abstractUI.cpp \
        abstractcontroller.cpp \
        active.cpp \
        character.cpp \
        door.cpp \
        dungeoncrawler.cpp \
        floor.cpp \
        guardcontroller.cpp \
        level.cpp \
        main.cpp \
        npc.cpp \
        passive.cpp \
        pit.cpp \
        portal.cpp \
        ramp.cpp \
        switch.cpp \
        terminalUI.cpp \
        tile.cpp \
        wall.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    abstractUI.h \
    abstractcontroller.h \
    active.h \
    character.h \
    door.h \
    dungeoncrawler.h \
    floor.h \
    guardcontroller.h \
    level.h \
    npc.h \
    passive.h \
    pit.h \
    portal.h \
    ramp.h \
    switch.h \
    terminalUI.h \
    tile.h \
    wall.h
