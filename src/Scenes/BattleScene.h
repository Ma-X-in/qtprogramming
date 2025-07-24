//
// @brief: 游戏场景
// @author: Ma Xin
//


#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include "Scene.h"
#include "../Items/Maps/Map.h"
#include "../Items/Characters/Character.h"
#include "../Items/Platforms/AirPlatform.h"
#include "../Items/Platforms/LandPlatform.h"
#include "../Items/Platforms/GrassPlatform.h"
#include "../Items/Platforms/IcePlatform.h"

#include <QKeyEvent>

class BattleScene : public Scene {
    Q_OBJECT

public:
    explicit BattleScene(QObject *parent);
    void processInput() override;
    void processMovement() override;
    void processPicking() override;

protected slots:
    void update() override;
    // 实现物品的随机生成
    void spawnRandomItem();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void checkGameOver();

private:
    Mountable *findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold = std::numeric_limits<qreal>::max());
    static Mountable * pickupMountable(Character *currentCharacter, Mountable *mountable);

    Map *map;
    Character *link;
    Character *enemy;
    AirPlatform *airPlatformGround;
    IcePlatform *icePlatformLeft;
    GrassPlatform *grassPlatformRight;
    LandPlatform *landPlatformMiddle;
    AirPlatform *leftWall;
    AirPlatform *rightWall;

    QTimer* spawnTimer;

signals:
    void gameoverSignal(int winner);
};

#endif //BATTLESCENE_H
