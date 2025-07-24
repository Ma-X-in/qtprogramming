//
// @brief: 小刀类
// @author: Ma Xin
//


#include "Knife.h"

Knife::Knife(QGraphicsItem *parent, const QString &pixmapPath) : MeleeWeapon(parent,"://Items/Weapons/Knife.png") {
}

void Knife::mountToParent() {
    Mountable::mountToParent();
    setPos(30,5);
    QRectF bounds = boundingRect();
    QPointF bottomMiddle((bounds.width()) / 2, bounds.height());
    setTransformOriginPoint(bottomMiddle);
    setRotation(0);
}

void Knife::unmount() {
    gravityHandler.setOnGround(false);
    Mountable::unmount();
    setRotation(0);
}

void Knife::meleeWeaponOpacity(qreal opacity) {
    pixmapItem->setOpacity(opacity);
}
