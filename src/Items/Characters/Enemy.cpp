//
// @brief: Enemy角色
// @author: Ma Xin
//


#include "Enemy.h"

Enemy::Enemy(QGraphicsItem *parent, const QString &pixmapPath) : Character(parent, ":/Items/Players/NPC_Red.png") {
    standPixmap = QPixmap(":/Items/Players/NPC_Red.png");
    crouchPixmap = QPixmap(":/Items/Players/NPC_Red_Crouch.png");
    fistPixmap = QPixmap(":/Items/Players/NPC_Red_Fist.png");
}

void Enemy::updateCrouchPixmap(bool crouch) {
    if (crouch) {
        pixmapItem->setPixmap(crouchPixmap);
    } else {
        pixmapItem->setPixmap(standPixmap);
    }
}

void Enemy::updateFistPixmap(bool fist) {
    if (fist) {
        pixmapItem->setPixmap(fistPixmap);
    } else {
        pixmapItem->setPixmap(standPixmap);
    }
}
