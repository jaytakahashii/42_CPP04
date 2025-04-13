#include "Character.hpp"

#include <iostream>

#include "color.hpp"

Character::Character() : _name("default"), _floorCount(0) {
  for (int i = 0; i < 4; ++i)
    _inventory[i] = NULL;
  for (int i = 0; i < 100; ++i)
    _floor[i] = NULL;
  std::cout << GREEN << "Character default constructed" << RESET << std::endl;
}

Character::Character(std::string const& name) : _name(name), _floorCount(0) {
  for (int i = 0; i < 4; ++i)
    _inventory[i] = NULL;
  for (int i = 0; i < 100; ++i)
    _floor[i] = NULL;
  std::cout << GREEN << "Character constructed" << RESET << std::endl;
}

Character::Character(Character const& other)
    : _name(other._name), _floorCount(other._floorCount) {
  for (int i = 0; i < 4; ++i)
    _inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
  for (int i = 0; i < 100; ++i)
    _floor[i] = other._floor[i] ? other._floor[i]->clone() : NULL;
  std::cout << GREEN << "Character copy constructed" << RESET << std::endl;
}

Character& Character::operator=(Character const& other) {
  std::cout << GREEN << "Character copy assigned" << RESET << std::endl;
  if (this != &other) {
    _name = other._name;
    for (int i = 0; i < 4; ++i) {
      if (_inventory[i])
        delete _inventory[i];
      _inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
    }
    for (int i = 0; i < 100; ++i) {
      if (_floor[i])
        delete _floor[i];
      _floor[i] = other._floor[i] ? other._floor[i]->clone() : NULL;
    }
    _floorCount = other._floorCount;
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < 4; ++i) {
    if (_inventory[i])
      delete _inventory[i];
  }
  for (int i = 0; i < 100; ++i) {
    if (_floor[i])
      delete _floor[i];
  }
  std::cout << GREEN << "Character destructed" << RESET << std::endl;
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
      std::cout << GREEN << _name << ": Equipped " << m->getType()
                << " to slot [" << i << "]" << RESET << std::endl;
      return;
    }
  }
  std::cout << RED << _name << ": No empty slot to equip " << m->getType()
            << RESET << std::endl;
  delete m;  // Clean up the materia if not equipped
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4 || !_inventory[idx]) {
    std::cout << RED << _name << ": Invalid index or no materia to unequip"
              << RESET << std::endl;
    return;
  }
  if (_floorCount < 100) {
    _floor[_floorCount++] = _inventory[idx];
    _inventory[idx] = NULL;
    std::cout << GREEN << _name << ": Unequipped materia from slot " << idx
              << " and placed on the floor" << RESET << std::endl;
  } else {
    std::cout << RED << _name << ": Floor is full, cannot unequip" << RESET
              << std::endl;
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx < 4 && _inventory[idx])
    _inventory[idx]->use(target);
  else
    std::cout << RED << _name << ": Invalid index or no materia to use" << RESET
              << std::endl;
}
