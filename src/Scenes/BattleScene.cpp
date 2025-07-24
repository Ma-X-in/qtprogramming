//
// @brief: 游戏场景
// @author: Ma Xin
//


#include "BattleScene.h"
#include "../Items/Characters/Link.h"
#include "../Items/Characters/Enemy.h"
#include "../Items/Maps/Battlefield.h"
#include "../Items/ItemFactory.h"

#include <QDebug>
#include <QRandomGenerator>

BattleScene::BattleScene(QObject *parent) : Scene(parent) {
    // 设置场景大小
    setSceneRect(0, 0, 1280, 720);

    // 每隔 15 秒生成一个物品
    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &BattleScene::spawnRandomItem);
    spawnTimer->start(15000);

    // 添加游戏地图
    map = new Battlefield();
    map->scaleToFitScene(this);
    addItem(map);

    // 添加游戏角色
    link = new Link();
    enemy = new Enemy();
    addItem(link);
    addItem(enemy);
    link->setPos(540, 535);
    enemy->setPos(740, 535);

    // 添加不同地形平台
    airPlatformGround = new AirPlatform();
    airPlatformGround->setPos(0, 625);
    airPlatformGround->setSize(1280, 95);
    icePlatformLeft = new IcePlatform();
    icePlatformLeft->setPos(160, 395);
    icePlatformLeft->setSize(355, 60);
    grassPlatformRight = new GrassPlatform();
    grassPlatformRight->setPos(770, 395);
    grassPlatformRight->setSize(355, 60);
    landPlatformMiddle = new LandPlatform();
    landPlatformMiddle->setPos(465, 165);
    landPlatformMiddle->setSize(355, 60);
    addItem(airPlatformGround);
    addItem(icePlatformLeft);
    addItem(grassPlatformRight);
    addItem(landPlatformMiddle);

    // 添加左右空气墙
    leftWall = new AirPlatform();
    leftWall->setPos(0, 0);
    leftWall->setSize(10, 720);
    leftWall->setName("leftWall");
    addItem(leftWall);
    rightWall = new AirPlatform();
    rightWall->setPos(1270, 0);
    rightWall->setSize(10, 720);
    rightWall->setName("rightWall");
    addItem(rightWall);
}

void BattleScene::processInput() {
    Scene::processInput();
    if (link != nullptr) {
        link->processInput();
    }
    if (enemy != nullptr) {
        enemy->processInput();
    }
}
void BattleScene::processMovement() {
    Scene::processMovement();
    if (link != nullptr) {
        link->updatePosition(deltaTime);
    }
    if (enemy != nullptr) {
        enemy->updatePosition(deltaTime);
    }
}

void BattleScene::processPicking() {
    Scene::processPicking();
    if (link->isPicking()) {
        auto mountable = findNearestUnmountedMountable(link->pos(), 100.);
        if (mountable != nullptr) {
            pickupMountable(link, mountable);
        }
    }
    if (enemy->isPicking()) {
        auto mountable = findNearestUnmountedMountable(enemy->pos(), 100.);
        if (mountable != nullptr) {
            pickupMountable(enemy, mountable);
        }
    }
}

// 键盘按下
void BattleScene::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_A:
            if (link != nullptr) {
                link->setLeftDown(true);
            }
            break;
        case Qt::Key_Left:
            if (enemy != nullptr) {
                enemy->setLeftDown(true);
            }
            break;
        case Qt::Key_D:
            if (link != nullptr) {
                link->setRightDown(true);
            }
            break;
        case Qt::Key_Right:
            if (enemy != nullptr) {
                enemy->setRightDown(true);
            }
            break;
        case Qt::Key_W:
            if (link != nullptr) {
                link->setUpDown(true);
            }
            break;
        case Qt::Key_Up:
            if (enemy != nullptr) {
                enemy->setUpDown(true);
            }
            break;
        case Qt::Key_S:
            if (link != nullptr) {
                link->setPickDown(true);
            }
            break;
        case Qt::Key_Down:
            if (enemy != nullptr) {
                enemy->setPickDown(true);
            }
            break;
        case Qt::Key_E:
            if (link != nullptr) {
                link->setAttackDown(true);
            }
            break;
        case Qt::Key_0:
            if (enemy != nullptr) {
                enemy->setAttackDown(true);
            }
            break;
        default:
            Scene::keyPressEvent(event);
    }
}

// 键盘释放
void BattleScene::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_A:
            if (link != nullptr) {
                link->setLeftDown(false);
            }
            break;
        case Qt::Key_Left:
            if (enemy != nullptr) {
                enemy->setLeftDown(false);
            }
            break;
        case Qt::Key_D:
            if (link != nullptr) {
                link->setRightDown(false);
            }
            break;
        case Qt::Key_Right:
            if (enemy != nullptr) {
                enemy->setRightDown(false);
            }
            break;
        case Qt::Key_W:
            if (link != nullptr) {
                link->setUpDown(false);
            }
            break;
        case Qt::Key_Up:
            if (enemy != nullptr) {
                enemy->setUpDown(false);
            }
            break;
        case Qt::Key_S:
            if (link != nullptr) {
                link->setPickDown(false);
            }
            break;
        case Qt::Key_Down:
            if (enemy != nullptr) {
                enemy->setPickDown(false);
            }
            break;
        case Qt::Key_E:
            if (link != nullptr) {
                link->setAttackDown(false);
            }
            break;
        case Qt::Key_0:
            if (enemy != nullptr) {
                enemy->setAttackDown(false);
            }
            break;
        default:
            Scene::keyReleaseEvent(event);
    }
}

void BattleScene::update() {
    this->checkGameOver();  // 判断游戏是否结束

    Scene::update();

    for (QGraphicsItem *item: items()) {
        if (auto mountable = dynamic_cast<Mountable *>(item)) {
            if (mountable!=nullptr&&
                !(mountable->isMounted())) {
                mountable->update();
            }
        }
    }
}

// 寻找地上最近的物品
Mountable *BattleScene::findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold) {
    Mountable *nearest = nullptr;
    qreal minDistance = distance_threshold;
    for (QGraphicsItem *item: items()) {
        if (auto mountable = dynamic_cast<Mountable *>(item)) {
            if (!mountable->isMounted()) {
                qreal distance = QLineF(pos, item->pos()).length();
                if (distance < minDistance) {
                    minDistance = distance;
                    nearest = mountable;
                }
            }
        }
    }
    return nearest;
}

// 捡起各种可挂载物品
Mountable *BattleScene::pickupMountable(Character *currentCharacter, Mountable *mountable) {
    if (auto knife = dynamic_cast<Knife *>(mountable)) {
        return currentCharacter->pickupKnife(knife);
    }
    if (auto bomb = dynamic_cast<Bomb *>(mountable)) {
        return currentCharacter->pickupBomb(bomb);
    }
    if (auto rifle = dynamic_cast<Rifle *>(mountable)) {
        return currentCharacter->pickupRifle(rifle);
    }
    if (auto sniper = dynamic_cast<Sniper *>(mountable)) {
        return currentCharacter->pickupSniper(sniper);
    }
    if (auto bandage = dynamic_cast<Bandage *>(mountable)) {
        return currentCharacter->pickupBandage(bandage);
    }
    if (auto medkit = dynamic_cast<Medkit *>(mountable)) {
        return currentCharacter->pickupMedkit(medkit);
    }
    if (auto adrenaline = dynamic_cast<Adrenaline *>(mountable)) {
        return currentCharacter->pickupAdrenaline(adrenaline);
    }
    return nullptr;
}

// 随机生成物品
void BattleScene::spawnRandomItem() {
    QVector<ItemType> itemTypes = ItemFactory::getItemTypes();
    int randomIndex = QRandomGenerator::global()->bounded(itemTypes.size());
    ItemType randomType = itemTypes[randomIndex];
    GravitationalMountableItem* item=ItemFactory::createItem(randomType);
    if (item) {
        int randomX = QRandomGenerator::global()->bounded(100, 1180);  // 物品随机生成的水平范围
        item->setPos(randomX, 0);  // 生成的位置为随机
        addItem(item);
        item->unmount();
    }
}

// 判断游戏是否结束
void BattleScene::checkGameOver() {
    if (link->getHealth()<=0) {
        emit gameoverSignal(0);  // 蓝方死亡
    }
    else if (enemy->getHealth()<=0) {
        emit gameoverSignal(1);  // 红方死亡
    }
}
