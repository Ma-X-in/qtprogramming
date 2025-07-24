//
// @brief: 步枪类
// @author: Ma Xin
//


#include "Rifle.h"

Rifle::Rifle(QGraphicsItem *parent, const QString &pixmapPath) : RangedWeapon(parent,"://Items/Weapons/Rifle.png") {
    setRangedWeaponDamage(rifleDamage);
}

void Rifle::mountToParent() {
    Mountable::mountToParent();
    setPos(5,30);
    QRectF bounds = boundingRect();
    QPointF bottomMiddle((bounds.width()) / 2, bounds.height());
    setTransformOriginPoint(bottomMiddle);
    setRotation(0);
}

void Rifle::unmount() {
    Mountable::unmount();
    setRotation(0);
}

void Rifle::rangedWeaponOpacity(qreal opacity) {
    pixmapItem->setOpacity(opacity);
}
