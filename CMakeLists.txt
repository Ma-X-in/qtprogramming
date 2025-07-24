cmake_minimum_required(VERSION 3.28)
project(qtprogramming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qtprogramming src/main.cpp
        src/MyGame.cpp
        src/MyGame.h
        src/Items/Item.cpp
        src/Items/Item.h
        src/Items/Characters/Character.cpp
        src/Items/Characters/Character.h
        src/Items/Characters/Link.cpp
        src/Items/Characters/Link.h
        src/Items/Characters/Enemy.cpp
        src/Items/Characters/Enemy.h
        src/Scenes/Scene.cpp
        src/Scenes/Scene.h
        src/Scenes/BattleScene.cpp
        src/Scenes/BattleScene.h
        src/Items/Maps/Map.cpp
        src/Items/Maps/Map.h
        src/Items/Maps/Battlefield.cpp
        src/Items/Maps/Battlefield.h
        src/Items/Mountable.cpp
        src/Items/Mountable.h
        assets/assets.qrc
        src/Items/Platforms/Platform.h
        src/Items/Platforms/Platform.cpp
        src/Items/Platforms/LandPlatform.h
        src/Items/Platforms/GrassPlatform.h
        src/Items/Platforms/IcePlatform.h
        src/Items/Platforms/LandPlatform.cpp
        src/Items/Platforms/GrassPlatform.cpp
        src/Items/Platforms/IcePlatform.cpp
        src/Items/Platforms/AirPlatform.h
        src/Items/Platforms/AirPlatform.cpp
        src/Items/Gravitational.h
        src/Items/Gravitational.cpp
        src/Items/GravitationalMountableItem.h
        src/Items/GravitationalMountableItem.cpp
        src/Items/Kits/Adrenaline.cpp
        src/Items/Kits/Adrenaline.h
        src/Items/Kits/Bandage.cpp
        src/Items/Kits/Bandage.h
        src/Items/Kits/Medkit.cpp
        src/Items/Kits/Medkit.h
        src/Items/Weapons/MeleeWeapon.cpp
        src/Items/Weapons/MeleeWeapon.h
        src/Items/Weapons/RangedWeapon.cpp
        src/Items/Weapons/RangedWeapon.h
        src/Items/Weapons/ThrowWeapon.cpp
        src/Items/Weapons/ThrowWeapon.h
        src/Items/Weapons/MeleeWeapons/Knife.cpp
        src/Items/Weapons/MeleeWeapons/Knife.h
        src/Items/Weapons/RangedWeapons/Rifle.cpp
        src/Items/Weapons/RangedWeapons/Rifle.h
        src/Items/Weapons/RangedWeapons/Sniper.cpp
        src/Items/Weapons/RangedWeapons/Sniper.h


        src/Items/Weapons/Bullet.cpp
        src/Items/Weapons/Bullet.h
        src/Items/ItemType.h
        src/Items/ItemFactory.cpp
        src/Items/ItemFactory.h
        src/Items/Weapons/ThrowWeapons/Bomb.cpp src/Items/Weapons/ThrowWeapons/Bomb.h
)
target_link_libraries(qtprogramming
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

