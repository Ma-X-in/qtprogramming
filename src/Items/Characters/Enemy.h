//
// @brief: Enemy角色
// @author: Ma Xin
//


#ifndef QTPROGRAMMING_ENEMY_H
#define QTPROGRAMMING_ENEMY_H

#include "Character.h"

class Enemy : public Character {
public:
    explicit Enemy(QGraphicsItem *parent = nullptr, const QString &pixmapPath = "");

protected:
    void updateCrouchPixmap(bool crouch);
    void updateFistPixmap(bool fist);

private:
    QPixmap standPixmap;
    QPixmap crouchPixmap;
    QPixmap fistPixmap;
};

#endif //QTPROGRAMMING_ENEMY_H
