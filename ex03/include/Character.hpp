#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
  std::string _name;
  AMateria* _inventory[4];
  AMateria* _floor[100];
  int _floorCount;

 public:
  Character();
  Character(std::string const& name);
  Character(Character const& other);
  Character& operator=(Character const& other);
  virtual ~Character();

  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
};
