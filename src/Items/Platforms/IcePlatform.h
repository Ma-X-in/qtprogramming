//
// @brief: 冰场地形平台
// @author: Ma Xin
//


#ifndef ICEPLATFORM_H
#define ICEPLATFORM_H

#include "AirPlatform.h"

class IcePlatform : public AirPlatform {
public:
    explicit IcePlatform(QGraphicsItem *parent = nullptr, const QString &imagePath = "");
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPixmap pixmap;
};

#endif // ICEPLATFORM_H
