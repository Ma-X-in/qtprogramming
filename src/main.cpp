//
// @brief: 程序入口
// @author: Ma Xin
//


#include "MyGame.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MyGame myGame;
    myGame.show();
    return QApplication::exec();
}
