//
// @brief: 草地地形平台
// @author: Ma Xin
//


#include "GrassPlatform.h"

GrassPlatform::GrassPlatform(QGraphicsItem *parent, const QString &imagePath) : AirPlatform(parent) {
    pixmap.load(":/Items/Platforms/GrassPlatform.png");
}

void GrassPlatform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, width, height, pixmap);
}
