//
// @brief: 物品工厂
// @author: Ma Xin
//


#include "ItemFactory.h"
#include "../Items/Weapons/MeleeWeapons/Knife.h"
#include "../Items/Weapons/ThrowWeapons/Bomb.h"
#include "../Items/Weapons/RangedWeapons/Rifle.h"
#include "../Items/Weapons/RangedWeapons/Sniper.h"
#include "../Items/Kits/Bandage.h"
#include "../Items/Kits/Medkit.h"
#include "../Items/Kits/Adrenaline.h"

GravitationalMountableItem* ItemFactory::createItem(ItemType type) {
    switch (type) {
    case ItemType::Knife:
        return new Knife();
    case ItemType::Bomb:
        return new Bomb();
    case ItemType::Rifle:
        return new Rifle();
    case ItemType::Sniper:
        return new Sniper();
    case ItemType::Bandage:
        return new Bandage();
    case ItemType::Medkit:
        return new Medkit();
    case ItemType::Adrenaline:
        return new Adrenaline();
    default:
        return nullptr;
    }
}

QVector<ItemType> ItemFactory::getItemTypes() {
    return {
        ItemType::Knife,
        ItemType::Bomb,
        ItemType::Rifle,
        ItemType::Sniper,
        ItemType::Bandage,
        ItemType::Medkit,
        ItemType::Adrenaline
    };
}
