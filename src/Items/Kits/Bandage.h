//
// @brief: 绷带类
// @author: Ma Xin
//


#ifndef BANDAGE_H
#define BANDAGE_H

#include "../GravitationalMountableItem.h"

class Character;

class Bandage : public GravitationalMountableItem {
public:
    explicit Bandage (QGraphicsItem *parent=nullptr, const QString &pixmapPath="");
};

#endif // BANDAGE_H
