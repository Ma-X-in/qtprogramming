//
// @brief: 游戏地图
// @author: Ma Xin
//


#include "Battlefield.h"

Battlefield::Battlefield(QGraphicsItem *parent) : Map(parent, ":/Items/Maps/Battlefield/Background.png") {}

qreal Battlefield::getFloorHeight() {
    auto sceneRect = sceneBoundingRect();
    return sceneRect.bottom() - 185;
}
