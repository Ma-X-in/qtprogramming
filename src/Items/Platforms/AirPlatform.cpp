//
// @brief: 空气墙，作为不同材质地形的基类，进行碰撞检测
// @author: Ma Xin
//


#include "AirPlatform.h"

AirPlatform::AirPlatform(QGraphicsItem *parent) : Platform(parent, "") {}

// 设置平台大小
void AirPlatform::setSize(qreal newWidth, qreal newHeight) {
    width = newWidth;
    height = newHeight;
    update();
}
