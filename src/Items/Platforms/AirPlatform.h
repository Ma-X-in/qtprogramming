//
// @brief: 空气墙，作为不同材质地形的基类，进行碰撞检测
// @author: Ma Xin
//


#ifndef AIRPLATFORM_H
#define AIRPLATFORM_H

#include "Platform.h"

class AirPlatform : public Platform {
public:
    explicit AirPlatform(QGraphicsItem *parent = nullptr);

    // 设置平台大小
    void setSize(qreal width, qreal height);
};

#endif // AIRPLATFORM_H
