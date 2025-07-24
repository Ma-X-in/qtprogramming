//
// @brief: Item基类
// @author: Ma Xin
//

#ifndef QTPROGRAMMING_ITEM_H
#define QTPROGRAMMING_ITEM_H

#include <QGraphicsItem>
#include <QPainter>

class Item : public QGraphicsItem {
public:
    explicit Item(QGraphicsItem *parent, const QString &pixmapPath);

    [[nodiscard]] QRectF boundingRect() const override {
        if (pixmapItem != nullptr) {
            return this->pixmapItem->boundingRect();
        }
        return {};
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
    }

protected:
    QGraphicsPixmapItem *pixmapItem{};
};


#endif //QTPROGRAMMING_ITEM_H
