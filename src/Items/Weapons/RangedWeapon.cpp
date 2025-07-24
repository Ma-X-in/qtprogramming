//
// @brief: 远程武器基类
// @author: Ma Xin
//


#include "RangedWeapon.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPointF>

RangedWeapon::RangedWeapon(QGraphicsItem *parent, const QString &pixmapPath) : GravitationalMountableItem(parent, pixmapPath) {
}

// 子弹射击方法
void RangedWeapon::attack() {
    // 创建子弹
    bullet = new Bullet(this, "://Items/Weapons/Bullet.png");
    bullet->setBulletDamage(rangedWeaponDamage);
    bullet->setParentItem(parentItem());
    bullet->mountToParent();

    // 设置子弹的位置，假设枪口在武器的中心
    bullet->setPos(60,30);
    bullet->setVelocity(QPointF(4,0));
}

void RangedWeapon::injuryDetector() {
    if (bullet) {
        bullet->injuryDetector();
    } else {
        return;
    }
}

bool RangedWeapon::getIfNullptr() {
    return bullet->getIfNullptr();
}

void RangedWeapon::deleteBullet() {
    bullet = nullptr;
}

void RangedWeapon::bulletMovement() {
    if (bullet) {
        bullet->update();
    }
}

void RangedWeapon::setRangedWeaponDamage(qreal newRangedWeaponDamage) {
    rangedWeaponDamage = newRangedWeaponDamage;
}
