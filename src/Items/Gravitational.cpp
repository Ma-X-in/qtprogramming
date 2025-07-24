//
// @brief: 重力加速度基类
// @author: Ma Xin
//


#include "Gravitational.h"

Gravitational::Gravitational(qreal gravity) : gravity(gravity) {
}

void Gravitational::applyGravity() {
    if (!onGround) {
        velocity.setY(velocity.y() + gravity);
    }
}

qreal Gravitational::getGravity() const {
    return gravity;
}

void Gravitational::setGravity(qreal newGravity) {
    gravity = newGravity;
}

bool Gravitational::isOnGround() const {
    return onGround;
}

void Gravitational::setOnGround(bool onGround) {
    Gravitational::onGround=onGround;
}

QPointF Gravitational::getVelocity() const {
    return velocity;
}

void Gravitational::setVelocity(const QPointF newVelocity) {
    velocity=newVelocity;
}
