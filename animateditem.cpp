#include "animateditem.h"
#include <QDateTime>

AnimatedItem::AnimatedItem(bool isFrameRate){
    isFps=isFrameRate;
    newDate=QDateTime::currentMSecsSinceEpoch();
    oldDate=newDate;
    angle = rand()%360;
    setRotation(angle);
    speed = 1;
    int startX=rand()%500;
    int startY=rand()%500;

    setPos(mapToParent(startX,startY));
    //qDebug() << "AnimatedItem";
}

QRectF AnimatedItem::boundingRect() const{
    return QRect(0,0,10,10);
}

void AnimatedItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    QRectF rec = boundingRect();
    QBrush brush(Qt::gray);
    if (scene()->collidingItems(this).isEmpty()){
        brush.setColor(Qt::green);
    }else{
        brush.setColor(Qt::red);
        DoCollision();
    }
    painter->fillRect(rec,brush);
    painter->drawRect(rec);
}

void AnimatedItem::advance(int phase){
    if (!phase) return;
    QPointF location = this->pos();
    setPos(mapToParent(0,-speed));
    if (isFps){
        oldDate=newDate;
        newDate=QDateTime::currentMSecsSinceEpoch();
        avg=avg*0.999+0.001*float(newDate-oldDate);
        cpt++;
        cpt%=100;
        if (cpt==0){
            qDebug() << "FPS=" << int(60.0/avg+0.5);
        }
    }
}

void AnimatedItem::DoCollision(){
    if (rand()%1){
        setRotation(rotation()+(180+(rand()%10)));
    }else{
        setRotation(rotation()+(180+(rand()%-10)));
    }
    QPointF newpoint = mapToParent(-boundingRect().width(),-boundingRect().width()-speed);
    if (!scene()->sceneRect().contains(newpoint)){
        newpoint = mapToParent(0,0);
    }
    setPos(newpoint);
}
