//
// @brief: 场景基类
// @author: Ma Xin
//


#ifndef QTPROGRAMMING_SCENE_H
#define QTPROGRAMMING_SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QWidget>

class Scene : public QGraphicsScene {
    Q_OBJECT

public:
    explicit Scene(QObject *parent);

    // 启动定时器，开始游戏循环
    void startLoop();

    // 处理输入
    virtual void processInput();
    // 处理移动
    virtual void processMovement();
    // 处理拾取
    virtual void processPicking();

protected slots:
    // 更新场景
    virtual void update();

    virtual void paintEvent(QPaintEvent *event);

protected:
    // 记录从上次更新以来的时间差
    qint64 deltaTime{};

private:
    QTimer *timer;
    qint64 lastTime{-1};
};

#endif //QTPROGRAMMING_SCENE_H
