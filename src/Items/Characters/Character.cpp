//
// @brief: 角色基类
// @author: Ma Xin
//


#include "Character.h"
#include "../Platforms/IcePlatform.h"
#include "../Platforms/GrassPlatform.h"

#include <QTransform>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

Character::Character(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath),healthBar(new QGraphicsRectItem(this)) {
    QTimer::singleShot(0, [this]() {
        handleCollision();
        updateGroundStatus();

        // 出生时若落在平台上，强制归零垂直速度
        if (onGround) {
            velocity.setY(0);
        }
    });

    // 信号槽机制的连接
    connect(this, &Character::groundTypeChanged, this, &Character::handleGroundTypeChanged);

    healthBar->setRect(0, -10, width, 5);
    healthBar->setBrush(Qt::red);

    // 肾上腺素对生命的影响
    healthTimer = new QTimer(this);
    connect(this, &Character::healthIncreaseRequested, this, &Character::increaseHealth);
    connect(healthTimer, &QTimer::timeout, this, [this]() {
        this->setHealth(this->health + 6);
    });

    // 肾上腺素对速度的影响
    extraSpeedTimer = new QTimer(this);
    connect(this, &Character::speedIncreaseRequested, this, &Character::increaseSpeed);
    connect(extraSpeedTimer, &QTimer::timeout, this, &Character::resetSpeed);
}

// 处理角色的按键状态
bool Character::isLeftDown() const {
    return leftDown;
}

void Character::setLeftDown(bool leftDown) {
    Character::leftDown = leftDown;
}

bool Character::isRightDown() const {
    return rightDown;
}

void Character::setRightDown(bool rightDown) {
    Character::rightDown = rightDown;
}

bool Character::isUpDown() const {
    return upDown;
}

void Character::setUpDown(bool upDown) {
    Character::upDown = upDown;
}

bool Character::isPickDown() const {
    return pickDown;
}

void Character::setPickDown(bool pickDown) {
    Character::pickDown = pickDown;
}

bool Character::isPicking() const {
    return picking;
}

bool Character::isAttackDown() const {
    return attackDown;
}

void Character::setAttackDown(bool attackDown) {
    Character::attackDown = attackDown;
}

// 处理角色的速度
const QPointF &Character::getVelocity() const {
    return velocity;
}

void Character::setVelocity(const QPointF &velocity) {
    Character::velocity = velocity;
}

void Character::update() {
    if (isAttacking && fistJustPressed) {
        shortInjuryDetector(mode);
    }
    if (isAttacking) {
        if (rifle) {
            rifle->bulletMovement();
        }
        if (sniper) {
            sniper->bulletMovement();
        }
        longInjuryDetector(mode);
    }
}

void Character::processInput() {
    const auto jumpspeed = -2;

    if (isPickDown()) {
        velocity.setX(0);
        updateCrouchPixmap(true);

        if (!lastPickDown) {
            picking = true;
        } else {
            picking = false;
        }
        lastPickDown = true;

        if (mode==3 || mode==4) {
            if (isAttackDown() && !isAttacking && !fistJustPressed) {
                if (anyWeapon()) {
                    isAttacking = true;  // 开始攻击
                    attackAnimation(mode);
                    fistJustPressed = true;  // 标记已经按下攻击键
                } else {
                    setMode(0);
                }
            }
            if (!isAttackDown()) {
                if (fistJustPressed == true) {
                    reversionAnimation(mode);
                }
                fistJustPressed = false;
            }
        }
    }
    else {
        updateCrouchPixmap(false);
        lastPickDown = false;

        if (isLeftDown()) {
            velocity.setX(-getMoveSpeedByGroundType() - extraSpeed);
            setTransform(QTransform().scale(-1, 1));
        } else if (isRightDown()) {
            velocity.setX(getMoveSpeedByGroundType() + extraSpeed);
            setTransform(QTransform().scale(1, 1));
        } else {
            velocity.setX(0);
        }

        if (isUpDown() && isOnGround()) {
            velocity.setY(jumpspeed);
            onGround = false;
        }

        if (isAttackDown() && !isAttacking && !fistJustPressed) {
            isAttacking = true;  // 开始攻击
            if (!anyWeapon()) {
                setMode(0);
            }
            attackAnimation(mode);
            fistJustPressed = true;  // 标记已经按下攻击键
        }
        if (!isAttackDown()) {
            if (fistJustPressed == true) {
                reversionAnimation(mode);
            }
            fistJustPressed = false;
        }
    }

    applyGravity();
    update();

    // 草地 + 下蹲 -> 隐身
    if (m_lastGroundType == GroundType::Grass && isPickDown()) {
        if (!isInvisible) {
            isInvisible = true;
            pixmapItem->setOpacity(0.2);  // 设为半透明
            if (knife) {
                knife->meleeWeaponOpacity(0.2);
            }
            if (bomb) {
                bomb->throwWeaponOpacity(0.2);
            }
            if (rifle) {
                rifle->rangedWeaponOpacity(0.2);
            }
            if (sniper) {
                sniper->rangedWeaponOpacity(0.2);
            }
        }
    }
    else {
        if (isInvisible) {
            isInvisible = false;
            pixmapItem->setOpacity(1.0);  // 恢复可见
            if (knife) {
                knife->meleeWeaponOpacity(1.0);
            }
            if (bomb) {
                bomb->throwWeaponOpacity(1.0);
            }
            if (rifle) {
                rifle->rangedWeaponOpacity(1.0);
            }
            if (sniper) {
                sniper->rangedWeaponOpacity(1.0);
            }
        }
    }

}

bool Character::isOnGround() const {
    return onGround;
}

void Character::setOnGround(bool onGround) {
    Character::onGround=onGround;
}

void Character::applyGravity() {
    if (!isOnGround()) {
        velocity.setY(velocity.y() + gravity * 0.08);  // 模拟重力影响
    }
    else {
        velocity.setY(0);  // 在地面上时，垂直速度为 0
    }
}

// 检测人物和平台的碰撞
void Character::handleCollision() {
    // 获取角色的边界矩形，并转换为全局坐标
    QRectF characterRect = mapToScene(pixmapItem->boundingRect()).boundingRect();

    for (QGraphicsItem* item : collidingItems()) {
        auto platform = dynamic_cast<Platform*>(item);
        if (platform) {
            // 获取平台的边界矩形，并转换为全局坐标
            QRectF platformRect = platform->mapRectToScene(platform->boundingRect());

            // 检测角色与平台是否发生碰撞
            if (characterRect.intersects(platformRect)) {
                QString name = platform->name();
                if (name == "leftWall") {
                    if (characterRect.left() < platformRect.right()) {
                        setPos(platformRect.right() + characterRect.width(), pos().y());
                        velocity.setX(0);
                    }
                } else if (name == "rightWall") {
                    if (characterRect.right() > platformRect.left()) {
                        setPos(platformRect.left() - characterRect.width(), pos().y());
                        velocity.setX(0);
                    }
                } else {
                    onCollisionWithPlatform(platform);
                }
            }
        }
    }
}

void Character::onCollisionWithPlatform(Platform *platform) {
    // 仅在角色正在向下移动时处理
    if (velocity.y() > 0) {
        QRectF characterRect = mapToScene(pixmapItem->boundingRect()).boundingRect();
        QRectF platformRect = platform->mapRectToScene(platform->boundingRect());
        if (characterRect.bottom() > platformRect.top() && characterRect.bottom() < platformRect.bottom()) {
            // 设置角色的垂直速度为0
            velocity.setY(0);

            // 更新角色的“在地面上”状态
            setOnGround(true);
        }
    }
}

void Character::updateGroundStatus() {
    bool isTouchingAirPlatform = false;
    if (isOnGround()) {
        QRectF characterRect = mapToScene(pixmapItem->boundingRect()).boundingRect();
        for (QGraphicsItem* item : collidingItems()) {
            auto platform = dynamic_cast<Platform*>(item);
            if (platform) {
                // 获取平台的边界矩形，并转换为全局坐标
                QRectF platformRect = platform->mapRectToScene(platform->boundingRect());

                // 检测角色与平台是否发生碰撞
                if (characterRect.intersects(platformRect) && characterRect.bottom() < platformRect.bottom()) {
                    isTouchingAirPlatform=true;
                    break;
                }
            }
        }
        if (!isTouchingAirPlatform) {
            setOnGround((false));
        }
    }
}

// 插值进行位置更新，可以让位置判断更准确
void Character::updatePosition(double deltaTime) {
    setPos(pos().x() + velocity.x() * deltaTime, pos().y());
    handleCollision();

    // 垂直移动拆成子步插值
    const int steps = 6;
    qreal verticalStep = velocity.y() * (deltaTime / steps);
    for (int i = 0; i < steps; ++i) {
        setPos(pos().x(), pos().y() + verticalStep);
        handleCollision();
        updateGroundStatus();
        updateSurfaceEffects();
    }
}

// 检测人物脚踩的平台的类型
GroundType Character::detectGroundType() {
    QRectF characterRect = mapToScene(pixmapItem->boundingRect()).boundingRect();
    QPointF bottomCenter(characterRect.center().x(), characterRect.bottom());
    QPointF rayEnd = bottomCenter + QPointF(0, 10);  // 向下10像素

    // 构建射线路径
    QPainterPath path;
    path.moveTo(bottomCenter);
    path.lineTo(rayEnd);

    // 使用路径查找相交项
    QList<QGraphicsItem*> hitItems = scene()->items(path);

    for (QGraphicsItem* item : hitItems) {
        auto platform = dynamic_cast<Platform*>(item);
        if (platform) {
            if (dynamic_cast<IcePlatform*>(platform)) {
                return GroundType::Ice;
            } else if (dynamic_cast<GrassPlatform*>(platform)) {
                return GroundType::Grass;
            } else {
                return GroundType::Land;
            }
        }
    }
    return GroundType::Land;  // 默认地面类型
}

void Character::updateSurfaceEffects() {
    GroundType currentGround = detectGroundType();
    if (currentGround != m_lastGroundType) {
        m_lastGroundType = currentGround;
        emit groundTypeChanged(currentGround);
    }
}

// 根据平台类型更改速度
qreal Character::getMoveSpeedByGroundType() const {
    switch (m_lastGroundType) {
    case GroundType::Ice:
        return 0.5;  // 冰面加速
    default:
        return moveSpeed;  // 默认速度
    }
}

void Character::handleGroundTypeChanged(GroundType newGround) {
}

bool Character::getInvisibility() const {
    return isInvisible;
}

qreal Character::getHealth() const {
    return health;
}

// 设置人物的生命值
void Character::setHealth(qreal newHealth) {
    if (newHealth <= 100) {
        this->health = newHealth;
    } else {
        this->health = 100;
    }
    updateHealthBar();
}

// 更新人物的血条
void Character::updateHealthBar() {
    qreal healthBarWidth = (width * health) / 100;
    if (healthBarWidth < 0) {
        healthBarWidth = 0;
    }
    healthBar->setRect(0, -10, healthBarWidth, 5);
}

// 获取人物朝向
qreal Character::getRotationAngle() const {
    QTransform transform = this->transform();
    return qAtan2(transform.m12(), transform.m11()) * (180.0 / M_PI);
}

// 拳头攻击伤害检测
void Character::fistInjuryDetector() {
    // 只有在攻击的帧数内才检测伤害
    if (!isAttacking) {
        return;
    }
    QRectF selfRect = mapRectToScene(boundingRect());
    // 遍历场景中的所有物品，检测与角色的碰撞
    for (QGraphicsItem *item : scene()->items()) {
        if (auto character = dynamic_cast<Character *>(item)) {
            if (character == this) continue;  // 不与自己碰撞
            QRectF characterRect = character->mapRectToScene(character->boundingRect());
            if (selfRect.intersects(characterRect)) {
                character->setHealth(character->getHealth() - fistDamage);  // 减少角色血量
            }
            isAttacking = false;
            return;
        }
    }
}

int Character::getMode() const {
    return mode;
}

// 设置武器类型
void Character::setMode(int newMode) {
    mode = newMode;
}

// 判断当前是否有武器
bool Character::anyWeapon() {
    if (knife==nullptr && bomb==nullptr && rifle==nullptr && sniper==nullptr) {
        return false;
    } else {
        return true;
    }
}

// 拾取小刀
Knife *Character::pickupKnife(Knife *newKnife) {
    if (anyWeapon()) {
        if (knife) {
            knife->setOpacity(1.0);
            knife->unmount();
            knife->setParentItem(parentItem());
            scene()->removeItem(knife);
            knife = nullptr;
        } else if (bomb) {
            bomb->setOpacity(0);
            bomb->unmount();
            bomb->setParentItem(parentItem());
            scene()->removeItem(bomb);
            bomb = nullptr;
        } else if (rifle) {
            rifle->deleteBullet();
            rifle->setOpacity(0);
            rifle->unmount();
            rifle->setParentItem(parentItem());
            scene()->removeItem(rifle);
            rifle = nullptr;
        } else if (sniper) {
            sniper->deleteBullet();
            sniper->setOpacity(0);
            sniper->unmount();
            sniper->setParentItem(parentItem());
            scene()->removeItem(sniper);
            sniper = nullptr;
        }
    }
    newKnife->setParentItem(this);
    newKnife->mountToParent();
    knife = newKnife;
    this->setMode(1);
    return knife;
}

// 拾取实心球
Bomb *Character::pickupBomb(Bomb *newBomb) {
    if (anyWeapon()) {
        if (knife) {
            knife->setOpacity(0);
            knife->unmount();
            knife->setParentItem(parentItem());
            scene()->removeItem(knife);
            knife = nullptr;
        } else if (bomb) {
            bomb->setOpacity(1.0);
            bomb->unmount();
            bomb->setParentItem(parentItem());
            scene()->removeItem(bomb);
            bomb = nullptr;
        } else if (rifle) {
            rifle->deleteBullet();
            rifle->setOpacity(0);
            rifle->unmount();
            rifle->setParentItem(parentItem());
            scene()->removeItem(rifle);
            rifle = nullptr;
        } else if (sniper) {
            sniper->deleteBullet();
            sniper->setOpacity(0);
            sniper->unmount();
            sniper->setParentItem(parentItem());
            scene()->removeItem(sniper);
            sniper = nullptr;
        }
    }
    newBomb->setParentItem(this);
    newBomb->mountToParent();
    bomb = newBomb;
    this->setMode(2);
    return bomb;
}

// 拾取步枪
Rifle *Character::pickupRifle(Rifle *newRifle) {
    if (anyWeapon()) {
        if (knife) {
            knife->setOpacity(0);
            knife->unmount();
            knife->setParentItem(parentItem());
            scene()->removeItem(knife);
            knife = nullptr;
        } else if (bomb) {
            bomb->setOpacity(0);
            bomb->unmount();
            bomb->setParentItem(parentItem());
            scene()->removeItem(bomb);
            bomb = nullptr;
        } else if (rifle) {
            rifle->deleteBullet();
            rifle->setOpacity(1.0);
            rifle->unmount();
            rifle->setParentItem(parentItem());
            scene()->removeItem(rifle);
            rifle = nullptr;
        } else if (sniper) {
            sniper->deleteBullet();
            sniper->setOpacity(0);
            sniper->unmount();
            sniper->setParentItem(parentItem());
            scene()->removeItem(sniper);
            sniper = nullptr;
        }
    }
    rifleHasBullet = true;
    newRifle->setParentItem(this);
    newRifle->mountToParent();
    rifle = newRifle;
    this->setMode(3);
    return rifle;
}

// 拾取狙击枪
Sniper *Character::pickupSniper(Sniper *newSniper) {
    if (anyWeapon()) {
        if (knife) {
            knife->setOpacity(0);
            knife->unmount();
            knife->setParentItem(parentItem());
            scene()->removeItem(knife);
            knife = nullptr;
        } else if (bomb) {
            bomb->setOpacity(0);
            bomb->unmount();
            bomb->setParentItem(parentItem());
            scene()->removeItem(bomb);
            bomb = nullptr;
        } else if (rifle) {
            rifle->deleteBullet();
            rifle->setOpacity(0);
            rifle->unmount();
            rifle->setParentItem(parentItem());
            scene()->removeItem(rifle);
            rifle = nullptr;
        } else if (sniper) {
            sniper->deleteBullet();
            sniper->setOpacity(1.0);
            sniper->unmount();
            sniper->setParentItem(parentItem());
            scene()->removeItem(sniper);
            sniper = nullptr;
        }
    }
    sniperHasBullet = true;
    newSniper->setParentItem(this);
    newSniper->mountToParent();
    sniper = newSniper;
    this->setMode(4);
    return sniper;
}

// 拾取绷带
Bandage* Character::pickupBandage(Bandage *newBandage) {
    qreal currentHealth = this->getHealth();
    if ((currentHealth + bandageHeal) > 100) {
        this->setHealth(100);
    } else {
        this->setHealth(currentHealth + bandageHeal);
    }
    bandage = newBandage;
    scene()->removeItem(bandage);
    bandage = nullptr;
    return bandage;
}

// 拾取医疗箱
Medkit* Character::pickupMedkit(Medkit *newMedkit) {
    this->setHealth(100);
    medkit = newMedkit;
    scene()->removeItem(medkit);
    medkit = nullptr;
    return medkit;
}

void Character::increaseHealth() {
    // 每秒增加 6 点血量
    this->setHealth(this->health + 6);
}

void Character::increaseSpeed() {
    extraSpeed = 0.2;
}

void Character::resetSpeed() {
    extraSpeed = 0;
}

// 拾取肾上腺素
Adrenaline* Character::pickupAdrenaline(Adrenaline *newAdrenaline) {
    adrenaline = newAdrenaline;
    scene()->removeItem(adrenaline);
    adrenaline = nullptr;
    emit healthIncreaseRequested();  // 触发信号，开始血量增加
    healthTimer->start(1000);  // 启动定时器，每秒增加血量
    QTimer::singleShot(5000, healthTimer, &QTimer::stop);  // 5秒后停止血量增加
    emit speedIncreaseRequested();
    extraSpeedTimer->start(5000);
    return adrenaline;
}

// 各种不同武器模式下人物的进攻动画
void Character::attackAnimation(int mode) {
    switch(mode) {
    case 0:
        updateFistPixmap(true);
        break;
    case 1:
        if (knife) {
            knife->attack();
        }
        break;
    case 2:
        if (bomb) {
            bomb->attack();
            bomb->unmount();
        }
        break;
    case 3:
        if (rifle && rifleHasBullet) {
            rifle->attack();
            rifleHasBullet = false;
        }
        break;
    case 4:
        if (sniper && sniperHasBullet) {
            sniper->attack();
            sniperHasBullet = false;
        }
        break;
    }
}

// 短程武器的伤害检测
void Character::shortInjuryDetector(int mode) {
    switch(mode) {
    case 0:
        fistInjuryDetector();
        break;
    case 1:
        if (!isAttacking) {
            break;
        }
        if (knife) {
            knife->injuryDetector();
        }
        isAttacking = false;
        break;
    default:
        break;
    }
}

// 投掷和远程武器的伤害检测
void Character::longInjuryDetector(int mode) {
    switch(mode) {
    case 2:
        if (bomb) {
            bomb->injuryDetector();
            if (bomb->getIfNullptr()) {
                bomb = nullptr;
            }
        }
        if (bomb==nullptr) {
            isAttacking = false;
        }
        break;
    case 3:
        if (rifle) {
            if (!rifle->getIfNullptr()) {
                rifle->injuryDetector();
            }
            if (rifle->getIfNullptr()) {
                isAttacking = false;
                scene()->removeItem(rifle);
                rifle = nullptr;
            }
        }
        break;
    case 4:
        if (sniper) {
            if (!sniper->getIfNullptr()) {
                sniper->injuryDetector();
            }
            if (sniper->getIfNullptr()) {
                isAttacking = false;
                scene()->removeItem(sniper);
                sniper = nullptr;
            }
        }
        break;
    default:
        break;
    }
}

// 进攻结束的恢复动画，主要针对小刀状态
void Character::reversionAnimation(int mode) {
    switch(mode) {
    case 0:
        break;
    case 1:
        if (knife) {
            knife->reversion();
        }
        break;
    default:
        break;
    }
}
