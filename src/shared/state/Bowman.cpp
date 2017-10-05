#include "Bowman.h"
#include "Bow.h"
#include "Sword.h"

namespace state {

    Bowman::Bowman(int id, int team, int positionX, int positionY) {
        this->id = id;
        this->team = team;
        this->positionX = positionX;
        this->positionY = positionY;
        
        life = 40;
        typeId = UnitTypeId::BOWMAN;

        weapons.insert(std::make_pair(WeaponTypeId::SWORD, std::unique_ptr<Sword>(new Sword(WeaponTypeId::SWORD, 5))));
        weapons.insert(std::make_pair(WeaponTypeId::BOW, std::unique_ptr<Bow>(new Bow(WeaponTypeId::BOW, 15))));
    }
    
    Unit* Bowman::clone() const {
         return new Bowman(*this);
    }
    
}