//
// @brief: 草地地形平台
// @author: Ma Xin
//


#ifndef GRASSPLATFORM_H
#define GRASSPLATFORM_H

#include "AirPlatform.h"

class GrassPlatform : public AirPlatform {
public:
    explicit GrassPlatform(QGraphicsItem *parent = nullptr, const QString &imagePath = "");
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPixmap pixmap;
};

#endif // GRASSPLATFORM_H
