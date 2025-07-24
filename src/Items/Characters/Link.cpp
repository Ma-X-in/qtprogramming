//
// @brief: Link角色
// @author: Ma Xin
//


#include "Link.h"

Link::Link(QGraphicsItem *parent, const QString &pixmapPath) : Character(parent, ":/Items/Players/NPC_Blue.png") {
    standPixmap = QPixmap(":/Items/Players/NPC_Blue.png");
    crouchPixmap = QPixmap(":/Items/Players/NPC_Blue_Crouch.png");
    fistPixmap = QPixmap(":/Items/Players/NPC_Blue_Fist.png");
}

void Link::updateCrouchPixmap(bool crouch) {
    if (crouch) {
        pixmapItem->setPixmap(crouchPixmap);
    } else {
        pixmapItem->setPixmap(standPixmap);
    }
}

void Link::updateFistPixmap(bool fist) {
    if (fist) {
        pixmapItem->setPixmap(fistPixmap);
    } else {
        pixmapItem->setPixmap(standPixmap);
    }
}
