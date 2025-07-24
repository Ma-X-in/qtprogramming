//
// @brief: 冰场地形平台
// @author: Ma Xin
//


#include "IcePlatform.h"

IcePlatform::IcePlatform(QGraphicsItem *parent, const QString &imagePath) : AirPlatform(parent) {
    pixmap.load(":/Items/Platforms/IcePlatform.png");
}

void IcePlatform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, width, height, pixmap);
}
