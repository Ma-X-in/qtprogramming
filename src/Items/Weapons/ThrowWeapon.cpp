//
// @brief: 投掷武器基类
// @author: Ma Xin
//


#include "ThrowWeapon.h"
#include "../Platforms/Platform.h"
#include "../Characters/Character.h"

#include <QGraphicsScene>

ThrowWeapon::ThrowWeapon(QGraphicsItem *parent, const QString &pixmapPath) : GravitationalMountableItem(parent, pixmapPath) {
}

void ThrowWeapon::attack() {
    // 设置初始速度
    gravityHandler.setVelocity(QPointF(3, -3));
}

void ThrowWeapon::injuryDetector() {
    QRectF weaponRect = mapRectToScene(boundingRect());
    for (QGraphicsItem *item : scene()->items()) {
        if (auto character = dynamic_cast<Character*>(item)) {
            QRectF characterRect = character->mapRectToScene(character->boundingRect());
            if (weaponRect.intersects(characterRect)
                &&character!=this->parentItem()) {
                character->setHealth(character->getHealth()-throwWeaponDamage);
                gravityHandler.setVelocity(QPointF(0.0, 0.0)); // 重置速度
                gravityHandler.setOnGround(true);
                scene()->removeItem(this);  // 从场景中移除投掷武器
                shouldBeNullptr = true;
                return;
            }
        }
    }
    QList<QGraphicsItem*> collidingItems = this->collidingItems();
    for (QGraphicsItem* item : collidingItems) {
        Platform* platform = dynamic_cast<Platform*>(item);
        // 获取平台的边界矩形，并转换为全局坐标
        if (platform) {
            QRectF platformRect = platform->mapRectToScene(platform->boundingRect());
            if (weaponRect.intersects(platformRect)) {
                gravityHandler.setVelocity(QPointF(0.0, 0.0));
                gravityHandler.setOnGround(true);
                scene()->removeItem(this);
                shouldBeNullptr = true;
                return;
            }
        }
    }
}

bool ThrowWeapon::getIfNullptr() {
    return shouldBeNullptr;
}
