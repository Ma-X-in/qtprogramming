//
// @brief: 步枪类
// @author: Ma Xin
//


#ifndef RIFLE_H
#define RIFLE_H

#include "../RangedWeapon.h"

class Rifle : public RangedWeapon {
public:
    explicit Rifle(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");
    void mountToParent() override;
    void unmount() override;
    void rangedWeaponOpacity(qreal opacity) override;

private:
    // 步枪伤害
    qreal rifleDamage = 30;
};

#endif // RIFLE_H
