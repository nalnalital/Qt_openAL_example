#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "animateditem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    SoundDevice::get();
    timerMusic=new QTimer(this);

    myMusic=new MusicBuffer("/Users/dnavatar/Desktop/_dnavatar/apps/src/brainteaser/sounds/intro.wav");
    connect(timerMusic,SIGNAL(timeout()),this,SLOT(UpdateMusicBuffer()));

    mySpeaker1=new SoundSource();
    mySpeaker2=new SoundSource();

    sound1 = SoundBuffer::get()->addSoundEffect("/Users/dnavatar/Desktop/_dnavatar/apps/src/brainteaser/sounds/explose.wav");
    sound2 = SoundBuffer::get()->addSoundEffect("/Users/dnavatar/Desktop/_dnavatar/apps/src/brainteaser/sounds/rire.wav");

    connect(ui->BUT_play_1,SIGNAL(clicked(bool)),this,SLOT(play1(bool)));
    connect(ui->BUT_play_2,SIGNAL(clicked(bool)),this,SLOT(play2(bool)));
    connect(ui->BUT_stop_1,SIGNAL(clicked(bool)),this,SLOT(stop1(bool)));
    connect(ui->BUT_play_3,SIGNAL(clicked(bool)),this,SLOT(play3(bool)));

    makeAnim();
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
    int itemCount = 200;
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
    timerMusic->start(500);
    myMusic->Play();
}
void MainWindow::play2(bool is){
    mySpeaker2->Play(sound2);
}
void MainWindow::play3(bool is){
    mySpeaker1->Play(sound1);
}
void MainWindow::stop1(bool is){
    timerMusic->stop();
}

MainWindow::~MainWindow(){
   delete ui;
}

