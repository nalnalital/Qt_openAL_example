QT += core gui
QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
message(Host: $$[QT_HOST_PREFIX])
message(os: $$QMAKE_HOST.os)
message(cpu_count: $$QMAKE_HOST.cpu_count)
message(name: $$QMAKE_HOST.name)
message(version: $$QMAKE_HOST.version)

linux-g++{
    DESTROOT=../../install/linux/x86-64
    LIBS += $$DESTROOT/lib/openal/bin/libopenal.so
    LIBS += $$DESTROOT/lib/openal/bin/libsndfile.a
    INCLUDEPATH += $$DESTROOT/lib/openal/include
}
win32-g++{
    DESTROOT=..\..\install\gcc\x86-64
    LIBS += $$DESTROOT\lib\openal\bin\OpenAL32.dll
    LIBS += $$DESTROOT\lib\openal\bin\libsndfile.a
    INCLUDEPATH += $$DESTROOT\lib\openal\include
}
win32-msvc*{
    DESTROOT=..\..\install\msvc\x86-64

    #LIBS += $$DESTROOT\lib\openal\bin\OpenAL32.dll
    #LIBS += $$DESTROOT/lib/openAL/bin/libsndfile.a
    INCLUDEPATH += $$DESTROOT/lib/openal/include
}
macx{
    DESTROOT=../../install/mac/arm64
    LIBS += $$DESTROOT/lib/openAL/libsndfile.a
    LIBS += $$DESTROOT/lib/openAL/libopenal.dylib
    INCLUDEPATH += $$DESTROOT/lib/openAL/include
    DEPENDPATH += $$DESTROOT/lib/openAL
}
message(INCLUDEPATH=$$INCLUDEPATH)
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
