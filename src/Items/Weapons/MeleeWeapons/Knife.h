//
// @brief: 小刀类
// @author: Ma Xin
//


#ifndef KNIFE_H
#define KNIFE_H

#include "../MeleeWeapon.h"

class Knife : public MeleeWeapon {
public:
    explicit Knife(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");
    void mountToParent() override;
    void unmount() override;
    void meleeWeaponOpacity(qreal opacity) override;
};

#endif // KNIFE_H
