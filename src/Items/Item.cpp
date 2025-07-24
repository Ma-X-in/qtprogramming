//
// @brief: Item基类
// @author: Ma Xin
//

#include "Item.h"

Item::Item(QGraphicsItem *parent, const QString &pixmapPath) : QGraphicsItem(parent) {
    if (pixmapPath != "") {
        pixmapItem = new QGraphicsPixmapItem(QPixmap(pixmapPath), this);
    }
}
