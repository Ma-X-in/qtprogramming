//
// @brief: 游戏地图
// @author: Ma Xin
//


#ifndef QTPROGRAMMING_BATTLEFIELD_H
#define QTPROGRAMMING_BATTLEFIELD_H

#include "Map.h"

class Battlefield : public Map {
public:
    explicit Battlefield(QGraphicsItem *parent= nullptr);
    qreal getFloorHeight() override;
};

#endif //QTPROGRAMMING_BATTLEFIELD_H
