//
// @brief: 物品工厂
// @author: Ma Xin
//


#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "ItemType.h"
#include "GravitationalMountableItem.h"

class ItemFactory {
public:
    // 生成物品
    static GravitationalMountableItem* createItem (ItemType type);

    static QVector<ItemType> getItemTypes();
};

#endif // ITEMFACTORY_H
