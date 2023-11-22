#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "animateditem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->BUT_play_1,SIGNAL(clicked(bool)),this,SLOT(play1(bool)));
    connect(ui->BUT_play_2,SIGNAL(clicked(bool)),this,SLOT(play2(bool)));
    connect(ui->BUT_stop_1,SIGNAL(clicked(bool)),this,SLOT(stop1(bool)));
    connect(ui->BUT_play_3,SIGNAL(clicked(bool)),this,SLOT(play3(bool)));
    connect(ui->BUT_loads,SIGNAL(clicked(bool)),this,SLOT(loadAll(bool)));

    makeAnim();
}
void MainWindow::loadAll(bool is){
    SoundDevice::get();

    mySpeaker1=new SoundSource();
    mySpeaker2=new SoundSource();

    sound1 = SoundBuffer::get()->addSoundEffect("../../src/brainteaser/sounds/explose.wav");
    sound2 = SoundBuffer::get()->addSoundEffect("../../src/brainteaser/sounds/rire.wav");

    timerMusic=new QTimer(this);

    myMusic=new MusicBuffer("../../src/brainteaser/sounds/intro.wav");
    connect(timerMusic,SIGNAL(timeout()),this,SLOT(UpdateMusicBuffer()));
    ui->BUT_loads->hide();
}
void MainWindow::makeAnim(){
    sceneAnim = new QGraphicsScene(this);
    ui->graphicsView->setScene(sceneAnim);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    sceneAnim->setSceneRect(20,20,ui->graphicsView->width()-20,ui->graphicsView->height()-20);
    QPen redpen = QPen(Qt::red);
    QLineF topLine(sceneAnim->sceneRect().topLeft(),sceneAnim->sceneRect().topRight());
    QLineF leftLine(sceneAnim->sceneRect().topLeft(),sceneAnim->sceneRect().bottomLeft());
    QLineF rightLine(sceneAnim->sceneRect().topRight(),sceneAnim->sceneRect().bottomRight());
    QLineF bottomLine(sceneAnim->sceneRect().bottomLeft(),sceneAnim->sceneRect().bottomRight());
    sceneAnim->addLine(topLine,redpen);
    sceneAnim->addLine(leftLine,redpen);
    sceneAnim->addLine(rightLine,redpen);
    sceneAnim->addLine(bottomLine,redpen);
    int itemCount = 100;
    for (int i=0;i<itemCount; i++){
        AnimatedItem *item= new AnimatedItem(i==0);
        sceneAnim->addItem(item);
    }
    timerAnim = new QTimer(this);
    connect(timerAnim,SIGNAL(timeout()),sceneAnim,SLOT(advance()));
    timerAnim->start(1);
}
void MainWindow::UpdateMusicBuffer(){
    myMusic->UpdateBufferStream();
}
void MainWindow::play1(bool is){
    if (timerMusic!=nullptr && myMusic!=nullptr){
        if (myMusic->Play()) timerMusic->start(500);
    }
}
void MainWindow::play2(bool is){
    if (mySpeaker2!=nullptr) mySpeaker2->Play(sound2);
}
void MainWindow::play3(bool is){
    if (mySpeaker1!=nullptr) mySpeaker1->Play(sound1);
}
void MainWindow::stop1(bool is){
    if (timerMusic!=nullptr) timerMusic->stop();
}

MainWindow::~MainWindow(){
   delete ui;
}

