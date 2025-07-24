//
// @brief: 游戏主窗口类
// @author: Ma Xin
//


#ifndef QTPROGRAMMING_MYGAME_H
#define QTPROGRAMMING_MYGAME_H

#include <QGraphicsView>
#include <QMainWindow>
#include "Scenes/Scene.h"

class MyGame : public QMainWindow {
    Q_OBJECT

public:
    explicit MyGame(QWidget *parent = nullptr);

public slots:
    void gameover(int winner);

private:
    Scene *battleScene;
    QGraphicsView *view;
};

#endif //QTPROGRAMMING_MYGAME_H
