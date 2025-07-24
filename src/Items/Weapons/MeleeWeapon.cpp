//
// @brief: 近战武器基类
// @author: Ma Xin
//


#include "MeleeWeapon.h"
#include "../Characters/Character.h"

#include <QGraphicsScene>

MeleeWeapon::MeleeWeapon(QGraphicsItem *parent, const QString &pixmapPath) : GravitationalMountableItem(parent, pixmapPath) {
}

// 攻击方法
void MeleeWeapon::attack() {
    // 获取缩放后的边界矩形
    QRectF bounds = boundingRect();
    QPointF bottomMiddle((bounds.width()) / 2, (bounds.height()));

    // 设置旋转原点为底边中点
    setTransformOriginPoint(bottomMiddle);
    setRotation(90);
}

// 还原方法
void MeleeWeapon::reversion() {
    QRectF bounds = boundingRect();
    // 计算缩放后的底边中点
    QPointF bottomMiddle((bounds.width()) / 2, (bounds.height()));

    // 设置旋转原点为底边中点
    setTransformOriginPoint(bottomMiddle);
    setRotation(0);
}

// 伤害检测
void MeleeWeapon::injuryDetector() {
    QRectF weaponRect = mapRectToScene(boundingRect());
    for (QGraphicsItem *item : scene()->items()) {
        if (auto character = dynamic_cast<Character*>(item)) {
            QRectF characterRect = character->mapRectToScene(character->boundingRect());
            if (weaponRect.intersects(characterRect)
                &&character != this->parentItem()) {
                character->setHealth(character->getHealth() - meleeWeaponDamage);
            }
        }
    }
}
