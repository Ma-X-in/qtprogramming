//
// @brief: 平台基类
// @author: Ma Xin
//


#ifndef PLATFORM_H
#define PLATFORM_H

#include "../Item.h"

#include <QGraphicsItem>

class Platform : public Item {
public:
    explicit Platform(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {}
    QRectF boundingRect() const override;
    void setName(const QString &name);
    QString name() const;

protected:
    qreal width;
    qreal height;

private:
    QString m_name;
};

#endif // PLATFORM_H
