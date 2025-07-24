//
// @brief: 狙击枪类
// @author: Ma Xin
//


#include "Sniper.h"

Sniper::Sniper(QGraphicsItem *parent, const QString &pixmapPath) : RangedWeapon(parent,"://Items/Weapons/Sniper.png") {
    setRangedWeaponDamage(sniperDamage);
}

void Sniper::mountToParent() {
    Mountable::mountToParent();
    setPos(5,30);
    QRectF bounds = boundingRect();
    QPointF bottomMiddle((bounds.width()) / 2, bounds.height());
    setTransformOriginPoint(bottomMiddle);
    setRotation(0);
}

void Sniper::unmount() {
    Mountable::unmount();
    setRotation(0);
}

void Sniper::rangedWeaponOpacity(qreal opacity) {
    pixmapItem->setOpacity(opacity);
}
