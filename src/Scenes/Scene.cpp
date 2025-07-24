//
// @brief: 场景基类
// @author: Ma Xin
//


#include "Scene.h"

#include <QDateTime>

Scene::Scene(QObject *parent) : QGraphicsScene(parent), timer(new QTimer(this)) {
    connect(timer, &QTimer::timeout, this, &Scene::update);
}

// 在游戏循环中更新游戏逻辑
void Scene::update() {
    auto currentTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
    if (lastTime == -1) {
        deltaTime = 0;
    } else {
        deltaTime = currentTime - lastTime;
    }
    lastTime = currentTime;
    processInput();
    processMovement();
    processPicking();
}

void Scene::startLoop() {
    timer->start(1000 / 90); // 90FPS
}

void Scene::processInput() {
}

void Scene::processMovement() {
}

void Scene::processPicking() {
}

void Scene::paintEvent(QPaintEvent *event) {
}
