//
// @brief: 实心球类
// @author: Ma Xin
//


#include "Bomb.h"

Bomb::Bomb(QGraphicsItem *parent, const QString &pixmapPath) : ThrowWeapon(parent,"://Items/Weapons/Bomb.png") {
}

void Bomb::mountToParent() {
    Mountable::mountToParent();
    setPos(30,30);
    QRectF bounds = boundingRect();
    QPointF bottomMiddle((bounds.width()) / 2, bounds.height());
    setTransformOriginPoint(bottomMiddle);
    setRotation(0);
}

void Bomb::unmount() {
    gravityHandler.setOnGround(false);
    Mountable::unmount();
    setRotation(0);
}

void Bomb::throwWeaponOpacity(qreal opacity) {
    pixmapItem->setOpacity(opacity);
}
