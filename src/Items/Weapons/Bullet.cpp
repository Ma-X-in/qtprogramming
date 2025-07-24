//
// @brief: 子弹类
// @author: Ma Xin
//


#include "Bullet.h"
#include "../Characters/Character.h"

#include <QGraphicsScene>

Bullet::Bullet(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {
}

void Bullet::injuryDetector() {
    QRectF bulletRect = mapRectToScene(boundingRect());
    // 遍历场景中的所有物品，检测与角色的碰撞
    for (QGraphicsItem *item : scene()->items()) {
        if (auto character = dynamic_cast<Character *>(item)) {
            QRectF characterRect = character->mapRectToScene(character->boundingRect());
            if (bulletRect.intersects(characterRect) && character != this->parentItem()) {
                character->setHealth(character->getHealth() - bulletDamage); // 减少角色血量
                this->unmount();
                scene()->removeItem(this);  // 子弹击中后移除子弹
                shouldBeNullptr = true;
                return;
            }
        }
    }
    QList<QGraphicsItem*> collidingItems = this->collidingItems();
    for (QGraphicsItem* item : collidingItems)
    {
        auto platform = dynamic_cast<Platform*>(item);
        if (platform)
        {
            QRectF bulletRect = mapRectToScene(boundingRect());
            QRectF platformRect = platform->mapRectToScene(platform->boundingRect());
            if (bulletRect.intersects(platformRect)) {
                this->unmount();
                scene()->removeItem(this);  // 子弹碰撞平台后移除子弹
                shouldBeNullptr = true;
                return;
            }
        }
    }
}

void Bullet::setVelocity(const QPointF& velocity) {
    this->velocity = velocity;
}

QPointF Bullet::getVelocity() const {
    return velocity;
}

bool Bullet::getIfNullptr() {
    return shouldBeNullptr;
}

void Bullet::update() {
    this->unmount();
    // 获取当前的速度
    QPointF velocity = this->getVelocity();

    // 更新子弹的位置
    this->setPos(x() + velocity.x(), y());
}

void Bullet::setBulletDamage(qreal newBulletDamage) {
    bulletDamage = newBulletDamage;
}
