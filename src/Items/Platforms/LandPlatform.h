//
// @brief: 土地地形平台
// @author: Ma Xin
//


#ifndef LANDPLATFORM_H
#define LANDPLATFORM_H

#include "AirPlatform.h"

class LandPlatform : public AirPlatform {
public:
    explicit LandPlatform(QGraphicsItem *parent = nullptr, const QString &imagePath = "");
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPixmap pixmap;
};

#endif // LANDPLATFORM_H
