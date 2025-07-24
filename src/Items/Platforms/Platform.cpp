//
// @brief: 平台基类
// @author: Ma Xin
//


#include "Platform.h"

QRectF Platform::boundingRect() const {
    return QRectF(0, 0, width, height);
}

void Platform::setName(const QString &name) {
    m_name = name;
}

QString Platform::name() const {
    return m_name;
}
