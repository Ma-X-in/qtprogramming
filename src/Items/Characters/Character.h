//
// @brief: 角色基类
// @author: Ma Xin
//


#ifndef QTPROGRAMMING_CHARACTER_H
#define QTPROGRAMMING_CHARACTER_H

#include "../Item.h"
#include "../Platforms/Platform.h"
#include "../Weapons/MeleeWeapons/Knife.h"
#include "../Weapons/RangedWeapons/Rifle.h"
#include "../Weapons/RangedWeapons/Sniper.h"
#include "../Weapons/ThrowWeapons/Bomb.h"
#include "../Kits/Bandage.h"
#include "../Kits/Medkit.h"
#include "../Kits/Adrenaline.h"

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>

// 定义地面类型枚举
enum class GroundType {
    Land,
    Grass,
    Ice
};

class Character : public QObject, public Item {
    Q_OBJECT

public:
    explicit Character(QGraphicsItem *parent = nullptr, const QString &pixmapPath = "");

    // 处理角色的按键状态
    [[nodiscard]] bool isLeftDown() const;
    void setLeftDown(bool leftDown);
    [[nodiscard]] bool isRightDown() const;
    void setRightDown(bool rightDown);
    [[nodiscard]] bool isUpDown() const;
    void setUpDown(bool upDown);
    [[nodiscard]] bool isPickDown() const;
    void setPickDown(bool pickDown);
    [[nodiscard]] bool isPicking() const;
    [[nodiscard]] bool isAttackDown() const;
    void setAttackDown(bool attackDown);

    // 处理角色的速度
    [[nodiscard]] const QPointF &getVelocity() const;
    void setVelocity(const QPointF &velocity);

    void update();
    void processInput();
    void updatePosition(double deltaTime);
    void checkCollisionsAndUpdateState();

    // 地形相关效果
    void updateSurfaceEffects();
    qreal getMoveSpeedByGroundType() const;
    [[nodiscard]] bool getInvisibility() const;

    // 生命值相关方法
    [[nodiscard]] qreal getHealth() const;
    void setHealth(qreal newHealth);

    // 判断角色朝向
    qreal getRotationAngle() const;

    // 拳头攻击相关指标
    bool isAttacking = false;  // 标记是否正在攻击
    void fistInjuryDetector();

    // 拾取武器或药品
    Knife* pickupKnife(Knife* newKnife);
    Bomb* pickupBomb(Bomb* newBomb);
    Rifle* pickupRifle(Rifle* newRifle);
    Sniper* pickupSniper(Sniper* newSniper);
    Bandage* pickupBandage(Bandage* newBandage);
    Medkit* pickupMedkit(Medkit* newMedkit);
    Adrenaline* pickupAdrenaline(Adrenaline* newAdrenaline);

    // 进攻模式
    int getMode() const;
    void setMode(int newMode);

    // 是否有武器
    bool anyWeapon();

protected:
    // 速度、重力相关指标
    QPointF velocity{};
    const qreal moveSpeed = 0.2;
    qreal gravity = 0.98;
    bool onGround = true;

    // 站立和蹲下姿势切换
    virtual void updateCrouchPixmap(bool crouch) = 0;

    // 站立和出拳姿势切换
    virtual void updateFistPixmap(bool fist) = 0;

    // 碰撞检测、重力实现相关方法
    [[nodiscard]] bool isOnGround() const;
    void setOnGround(bool onGround);
    void applyGravity();
    void handleCollision();
    void onCollisionWithPlatform(Platform* platform);
    void updateGroundStatus();

    // 更新生命值条
    void updateHealthBar();

    // 武器和药品库
    Knife *knife{nullptr};
    Rifle *rifle{nullptr};
    Sniper *sniper{nullptr};
    Bomb *bomb{nullptr};
    Bandage *bandage{nullptr};
    Medkit *medkit{nullptr};
    Adrenaline *adrenaline{nullptr};

    // 攻击相关动画和伤害检测
    void attackAnimation(int mode);
    void reversionAnimation(int mode);
    void shortInjuryDetector(int mode);
    void longInjuryDetector(int mode);

private:
    bool leftDown{}, rightDown{}, upDown{}, pickDown{}, attackDown{};
    bool lastPickDown = false;
    bool picking{};
    bool isInvisible = false;
    bool fistJustPressed = false;
    bool rifleHasBullet = false;
    bool sniperHasBullet = false;

    GroundType detectGroundType();
    GroundType m_lastGroundType = GroundType::Land;

    // 生命值相关指标
    qreal width{46};  // 人物宽度
    qreal height{90};  // 人物高度
    qreal health{100};  // 初始生命值
    QGraphicsRectItem *healthBar;

    // 拳头伤害值
    qreal fistDamage{10};

    // 武器模式：0：未携带武器，1：小刀，2：实心球，3：步枪，4：狙击枪
    int mode{0};

    // 绷带治疗血量
    qreal bandageHeal{30};

    // 肾上腺素相关指标
    QTimer *healthTimer;
    QTimer *extraSpeedTimer;
    qreal extraSpeed{0};

signals:
    void groundTypeChanged(GroundType newGround);
    void healthIncreaseRequested();
    void speedIncreaseRequested();

private slots:
    void handleGroundTypeChanged(GroundType newGround);
    void increaseHealth();
    void increaseSpeed();
    void resetSpeed();
};

#endif //QTPROGRAMMING_CHARACTER_H
