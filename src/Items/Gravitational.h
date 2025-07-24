//
// @brief: 重力系统基类
// @author: Ma Xin
//


#ifndef GRAVITATIONAL_H
#define GRAVITATIONAL_H

#include <QPointF>

class Gravitational {
public:
    explicit Gravitational(qreal gravity = 0.098);

    // 重力加速度使用接口
    void applyGravity();

    qreal getGravity() const;
    void setGravity(qreal newGravity);
    bool isOnGround() const;
    void setOnGround(bool onGround);
    QPointF getVelocity() const;
    void setVelocity(const QPointF newVelocity);

protected:
    qreal gravity;
    bool onGround=false;
    QPointF velocity={0.0,0.0};
};

#endif // GRAVITATIONAL_H
