#include "Character.hpp"

#include <iostream>

#include "color.hpp"

Character::Character(std::string const& name) : _name(name) {
  for (int i = 0; i < 4; ++i)
    _inventory[i] = NULL;
  std::cout << GREEN << "Character constructed" << RESET << std::endl;
}

Character::Character(Character const& other) {
  std::cout << GREEN << "Character copy constructed" << RESET << std::endl;
  *this = other;
}

Character& Character::operator=(Character const& other) {
  std::cout << GREEN << "Character copy assigned" << RESET << std::endl;
  if (this != &other) {
    _name = other._name;
    _clearInventory();
    _copyInventory(other);
  }
  return *this;
}

Character::~Character() {
  _clearInventory();
  std::cout << GREEN << "Character destructed" << RESET << std::endl;
}

void Character::_clearInventory() {
  for (int i = 0; i < 4; ++i) {
    if (_inventory[i])
      delete _inventory[i];
    _inventory[i] = NULL;
  }
}

void Character::_copyInventory(Character const& other) {
  for (int i = 0; i < 4; ++i) {
    if (other._inventory[i])
      _inventory[i] = other._inventory[i]->clone();
    else
      _inventory[i] = NULL;
  }
}

std::string const& Character::getName() const {
  return _name;
}

void Character::equip(AMateria* m) {
  if (!m)
    return;
  for (int i = 0; i < 4; ++i) {
    if (!_inventory[i]) {
      _inventory[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4)
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx < 4 && _inventory[idx])
    _inventory[idx]->use(target);
}
