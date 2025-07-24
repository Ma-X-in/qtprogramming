//
// @brief: 游戏主窗口类
// @author: Ma Xin
//


#include "MyGame.h"
#include "Scenes/BattleScene.h"

#include <QMessageBox>
#include <QApplication>

MyGame::MyGame(QWidget *parent) : QMainWindow(parent) {
    // 创建游戏场景并设置为当前视图
    battleScene = new BattleScene(this);
    view = new QGraphicsView(this);
    view->setScene(battleScene);

    // 设置视图的窗口大小为 1280x720
    view->setFixedSize((int) view->scene()->width(), (int) view->scene()->height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 将视图设置为中央控件
    setCentralWidget(view);

    // 调整主窗口大小 QGraphicsView
    setFixedSize(view->sizeHint());
    battleScene->startLoop();

    auto actualBattleScene = qobject_cast<BattleScene*>(battleScene);
    if (actualBattleScene != nullptr) {
        // 连接战斗场景的游戏结束信号到 MyGame 的 gameover 槽函数
        connect(actualBattleScene, &BattleScene::gameoverSignal, this, &MyGame::gameover);
    }
}

// 游戏结束函数
void MyGame::gameover(int winner) {
    QMessageBox::StandardButton reply;
    switch (winner) {
    case 0:
        reply = QMessageBox::information(this, "游戏结束", "红方胜利！", QMessageBox::Ok);
        if (reply == QMessageBox::Ok) {
            QApplication::quit();
        }
        break;
    case 1:
        reply = QMessageBox::information(this, "游戏结束", "蓝方胜利！", QMessageBox::Ok);
        if (reply == QMessageBox::Ok) {
            QApplication::quit();
        }
        break;
    }
}
