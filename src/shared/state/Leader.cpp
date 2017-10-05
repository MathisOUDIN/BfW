#include "Leader.h"
#include "Sword.h"
#include "Bow.h"

namespace state {

    Leader::Leader(int id, int team, int positionX, int positionY) {
        this->id = id;
        this->team = team;
        this->positionX = positionX;
        this->positionY = positionY;
        
        life = 100;
        typeId = UnitTypeId::LEADER;
        
        weapons.insert(std::make_pair(WeaponTypeId::SWORD, std::unique_ptr<Sword>(new Sword(WeaponTypeId::SWORD, 20))));
        weapons.insert(std::make_pair(WeaponTypeId::BOW, std::unique_ptr<Bow>(new Bow(WeaponTypeId::BOW, 10))));
    }    

    Unit* Leader::clone() const {
        return new Leader(*this);
    }
    
}