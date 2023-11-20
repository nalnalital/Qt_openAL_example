#ifndef ANIMATEDITEM_H
#define ANIMATEDITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class AnimatedItem : public QGraphicsItem
{
public:
    AnimatedItem(bool isFrameRate=false);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

protected:
    void advance(int phase);

private:
    bool isFps=false;
    qint64 oldDate=0;
    qint64 newDate=0;
    float avg=0.0;
    int cpt=0;
    qreal angle;
    qreal speed;
    void DoCollision();
};

#endif // ANIMATEDITEM_H
