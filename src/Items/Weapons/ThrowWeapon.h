//
// @brief: 投掷武器基类
// @author: Ma Xin
//


#ifndef THROWWEAPON_H
#define THROWWEAPON_H

#include "../GravitationalMountableItem.h"

class Character;

class ThrowWeapon : public GravitationalMountableItem {
public:
    explicit ThrowWeapon (QGraphicsItem *parent, const QString &pixmapPath);
    virtual void attack();
    virtual void injuryDetector();

    // 透明度设置
    virtual void throwWeaponOpacity(qreal opacity)=0;

    bool getIfNullptr();

private:
    qreal throwWeaponDamage = 20;
    bool shouldBeNullptr = false;
};

#endif // THROWWEAPON_H
