//
// @biref: 耦合重力系统的可挂载物品类
// @author: Ma Xin
//


#include "GravitationalMountableItem.h"
#include "Platforms/Platform.h"

#include <QGraphicsScene>

GravitationalMountableItem::GravitationalMountableItem(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {
}

void GravitationalMountableItem::update()
{
    gravityHandler.applyGravity();
    // 帧更新式移动
    QPointF velocity = gravityHandler.getVelocity();
    setPos(pos() + velocity);
    QList<QGraphicsItem*> collidingItems = this->collidingItems();
    for (QGraphicsItem* item : collidingItems) {
        auto platform = dynamic_cast<Platform*>(item);
        if (platform) {
            QRectF weaponRect = mapRectToScene(boundingRect());
            QRectF platformRect = platform->mapRectToScene(platform->boundingRect());
            if (weaponRect.bottom() >= platformRect.top() && weaponRect.bottom() <= platformRect.bottom()) {
                gravityHandler.setVelocity(QPointF(0.0, 0.0));  // 重置速度
                gravityHandler.setOnGround(true);
                setRotation(0);
                return;
            }
        }
    }
}
