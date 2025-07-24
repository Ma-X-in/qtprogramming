//
// @brief: Link角色
// @author: Ma Xin
//


#ifndef QTPROGRAMMING_LINK_H
#define QTPROGRAMMING_LINK_H

#include "Character.h"

class Link : public Character {
public:
    explicit Link(QGraphicsItem *parent = nullptr, const QString &pixmapPath = "");

protected:
    void updateCrouchPixmap(bool crouch);
    void updateFistPixmap(bool fist);

private:
    QPixmap standPixmap;
    QPixmap crouchPixmap;
    QPixmap fistPixmap;
};

#endif //QTPROGRAMMING_LINK_H
