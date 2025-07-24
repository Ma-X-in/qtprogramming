//
// @brief: 肾上腺素类
// @author: Ma Xin
//


#ifndef ADRENALINE_H
#define ADRENALINE_H

#include "../GravitationalMountableItem.h"

class Character;

class Adrenaline : public GravitationalMountableItem {
public:
    explicit Adrenaline (QGraphicsItem *parent=nullptr, const QString &pixmapPath="");
};

#endif // ADRENALINE_H
