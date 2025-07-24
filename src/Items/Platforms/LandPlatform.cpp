//
// @brief: 土地地形平台
// @author: Ma Xin
//


#include "LandPlatform.h"

LandPlatform::LandPlatform(QGraphicsItem *parent, const QString &imagePath) : AirPlatform(parent) {
    pixmap.load(":/Items/Platforms/LandPlatform.png");
}

void LandPlatform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, width, height, pixmap);
}
