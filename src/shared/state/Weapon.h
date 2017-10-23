// Generated by dia2code
#ifndef STATE__WEAPON__H
#define STATE__WEAPON__H


namespace state {
  class Weapon;
}

#include "WeaponTypeId.h"

namespace state {

  /// class Weapon - 
  class Weapon {
    // Associations
    // Attributes
  protected:
    int id     = 0;
    int damage;
    WeaponTypeId typeId     = WeaponTypeId::INVALIDWEAPON;
    // Operations
  public:
    Weapon ();
    virtual ~Weapon ();
    virtual bool const isCloseCombat ();
    int getDamage () const;
    const WeaponTypeId& getTypeId () const;
    int getId () const;
    virtual Weapon* clone () const = 0;
    // Setters and Getters
    void setId(int id);
    void setDamage(int damage);
    void setTypeId(WeaponTypeId typeId);
  };

};

#endif