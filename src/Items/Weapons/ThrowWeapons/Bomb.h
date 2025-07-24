//
// @brief: 实心球类
// @author: Ma Xin
//


#ifndef BOMB_H
#define BOMB_H

#include "../ThrowWeapon.h"

class Bomb : public ThrowWeapon {
public:
    explicit Bomb(QGraphicsItem *parent=nullptr, const QString &pixmapPath="");
    void mountToParent() override;
    void unmount() override;
    void throwWeaponOpacity(qreal opacity) override;
};

#endif // BOMB_H
