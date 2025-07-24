//
// @brief: 地图基类
// @author: Ma Xin
//


#ifndef QTPROGRAMMING_MAP_H
#define QTPROGRAMMING_MAP_H

#include "../Item.h"

#include <QGraphicsScene>
#include <QPointF>

class Map : public Item {
public:
    explicit Map(QGraphicsItem *parent = nullptr, const QString &pixmapPath = "");
    void scaleToFitScene(QGraphicsScene *scene);
    virtual qreal getFloorHeight();
    virtual QPointF getSpawnPos();
};

#endif //QTPROGRAMMING_MAP_H
