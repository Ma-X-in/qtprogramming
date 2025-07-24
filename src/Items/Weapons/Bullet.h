//
// @brief: 子弹类
// @author: Ma Xin
//


#ifndef BULLET_H
#define BULLET_H

#include "../Item.h"
#include "../Mountable.h"

class Bullet : public Item, public Mountable {
public:
    Bullet(QGraphicsItem *parent, const QString &pixmapPath);

    // 子弹伤害检测
    void injuryDetector();

    void setVelocity(const QPointF& velocity);
    QPointF getVelocity() const;
    bool getIfNullptr();
    void update() override;
    void setBulletDamage(qreal newBulletDamage);

private:
    qreal bulletDamage = 30;
    QPointF velocity;
    bool shouldBeNullptr = false;
};

#endif // BULLET_H
