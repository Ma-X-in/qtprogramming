//
// @biref: 耦合重力系统的可挂载物品类
// @author: Ma Xin
//


#ifndef GRAVITATIONALMOUNTABLEITEM_H
#define GRAVITATIONALMOUNTABLEITEM_H

#include "Item.h"
#include "Mountable.h"
#include "Gravitational.h"

class GravitationalMountableItem : public QObject, public Item, public Mountable {
    Q_OBJECT

public:
    explicit GravitationalMountableItem(QGraphicsItem *parent, const QString &pixmapPath);

    // 物品的下落和碰撞实现
    void update() override;
    Gravitational gravityHandler;
};

#endif // GRAVITATIONALMOUNTABLEITEM_H
