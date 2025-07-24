//
// @brief: 医疗箱类
// @author: Ma Xin
//


#ifndef MEDKIT_H
#define MEDKIT_H

#include "../GravitationalMountableItem.h"

class Character;

class Medkit : public GravitationalMountableItem {
public:
    explicit Medkit (QGraphicsItem *parent=nullptr, const QString &pixmapPath="");
};

#endif // MEDKIT_H
