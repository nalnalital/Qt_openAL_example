QT += core gui
QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += /Users/dnavatar/Desktop/_dnavatar/apps/install/mac/arm64/lib/openAL/libsndfile.a
LIBS += /Users/dnavatar/Desktop/_dnavatar/apps/install/mac/arm64/lib/openAL/libopenal.dylib
INCLUDEPATH += /Users/dnavatar/Desktop/_dnavatar/apps/install/mac/arm64/lib/openAL/include
DEPENDPATH += /Users/dnavatar/Desktop/_dnavatar/apps/install/mac/arm64/lib/openAL
SOURCES += \
    MusicBuffer.cpp \
    SoundBuffer.cpp \
    SoundDevice.cpp \
    SoundSource.cpp \
    animateditem.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    MusicBuffer.h \
    SoundBuffer.h \
    SoundDevice.h \
    SoundSource.h \
    animateditem.h \
    mainwindow.h

FORMS += \
    mainwindow.ui
