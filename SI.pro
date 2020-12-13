QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        aliens.cpp \
        bart.cpp \
        bullet.cpp \
        game.cpp \
        main.cpp \
        mikail.cpp \
        osman.cpp \
        players.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    aliens.h \
    bart.h \
    bullet.h \
    game.h \
    mikail.h \
    osman.h \
    players.h

RESOURCES += \
    resources.qrc
