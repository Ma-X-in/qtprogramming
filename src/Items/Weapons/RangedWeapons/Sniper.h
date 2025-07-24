//
// @brief: 狙击枪类
// @author: Ma Xin
//


#ifndef SNIPER_H
#define SNIPER_H

#include "../RangedWeapon.h"

class Sniper : public RangedWeapon {
public:
    explicit Sniper(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");
    void mountToParent() override;
    void unmount() override;
    void rangedWeaponOpacity(qreal opacity) override;

private:
    // 狙击枪伤害
    qreal sniperDamage = 50;
};

#endif // SNIPER_H
