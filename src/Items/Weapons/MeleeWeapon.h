//
// @brief: 近战武器基类
// @author: Ma Xin
//


#ifndef MELEEWEAPON_H
#define MELEEWEAPON_H

#include "../GravitationalMountableItem.h"

class Character;

class MeleeWeapon : public GravitationalMountableItem {
public:
    explicit MeleeWeapon (QGraphicsItem *parent, const QString &pixmapPath);

    // 攻击、还原动作和伤害检测
    virtual void attack();
    virtual void reversion();
    virtual void injuryDetector();

    // 透明度设置
    virtual void meleeWeaponOpacity(qreal opacity)=0;

private:
    qreal meleeWeaponDamage{15};
};

#endif // MELEEWEAPON_H
