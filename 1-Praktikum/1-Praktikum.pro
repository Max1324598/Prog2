QT += core gui
greaterThan ( QT_MAJOR_VERSION , 4) : QT += widgets
CONFIG += c ++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        abstractUI.cpp \
        abstractcontroller.cpp \
        active.cpp \
        attackcontroller.cpp \
        character.cpp \
        door.cpp \
        dungeoncrawler.cpp \
        endscreen.cpp \
        floor.cpp \
        graph.cpp \
        graphicalui.cpp \
        guardcontroller.cpp \
        level.cpp \
        levelchanger.cpp \
        lootchest.cpp \
        main.cpp \
        mainwindow.cpp \
        mylist.cpp \
        npc.cpp \
        passive.cpp \
        pit.cpp \
        portal.cpp \
        ramp.cpp \
        startscreen.cpp \
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
    attackcontroller.h \
    character.h \
    door.h \
    dungeoncrawler.h \
    endscreen.h \
    floor.h \
    graph.h \
    graphicalui.h \
    guardcontroller.h \
    level.h \
    levelchanger.h \
    lootchest.h \
    mainwindow.h \
    mylist.h \
    npc.h \
    passive.h \
    pit.h \
    portal.h \
    ramp.h \
    startscreen.h \
    switch.h \
    terminalUI.h \
    tile.h \
    wall.h

FORMS += \
    endscreen.ui \
    mainwindow.ui \
    startscreen.ui
