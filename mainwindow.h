#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "SoundDevice.h"
#include "SoundBuffer.h"
#include "SoundSource.h"
#include "MusicBuffer.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void play1(bool is);
    void play2(bool is);
    void play3(bool is);
    void stop1(bool is);
    void UpdateMusicBuffer();

private:
    Ui::MainWindow *ui;
    void makeAnim();
    QTimer *timerAnim;
    QGraphicsScene *sceneAnim;
    MusicBuffer* myMusic;
    QTimer *timerMusic;
    SoundSource* mySpeaker1;
    SoundSource* mySpeaker2;
    ALuint sound1;
    ALuint sound2;
};
#endif // MAINWINDOW_H
