//
// @brief: 远程武器基类
// @author: Ma Xin
//


#ifndef RANGEDWEAPON_H
#define RANGEDWEAPON_H

#include "../GravitationalMountableItem.h"
#include "Bullet.h"

class Character;

class RangedWeapon : public GravitationalMountableItem {
public:
    explicit RangedWeapon (QGraphicsItem *parent, const QString &pixmapPath);

    virtual void attack();
    virtual void injuryDetector();
    bool getIfNullptr();

    // 透明度设置
    virtual void rangedWeaponOpacity(qreal opacity)=0;

    // 子弹管理方法和伤害设置
    void deleteBullet();
    void bulletMovement();
    void setRangedWeaponDamage(qreal newRangedWeaponDamage);

private:
    Bullet *bullet = nullptr;
    qreal rangedWeaponDamage;
};

#endif // RANGEDWEAPON_H
