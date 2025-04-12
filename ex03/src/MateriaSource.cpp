#include "MateriaSource.hpp"

#include <iostream>

#include "color.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; ++i)
    _storage[i] = NULL;
  std::cout << MAGENTA << "MateriaSource constructed" << RESET << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const& other) {
  std::cout << MAGENTA << "MateriaSource copy constructed" << RESET
            << std::endl;
  *this = other;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other) {
  std::cout << MAGENTA << "MateriaSource copy assigned" << RESET << std::endl;
  if (this != &other) {
    _clearStorage();
    _copyStorage(other);
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  _clearStorage();
  std::cout << MAGENTA << "MateriaSource destructed" << RESET << std::endl;
}

void MateriaSource::_clearStorage() {
  for (int i = 0; i < 4; ++i) {
    if (_storage[i])
      delete _storage[i];
    _storage[i] = NULL;
  }
}

void MateriaSource::_copyStorage(MateriaSource const& other) {
  for (int i = 0; i < 4; ++i) {
    if (other._storage[i])
      _storage[i] = other._storage[i]->clone();
    else
      _storage[i] = NULL;
  }
}

void MateriaSource::learnMateria(AMateria* m) {
  if (!m)
    return;
  for (int i = 0; i < 4; ++i) {
    if (!_storage[i]) {
      _storage[i] = m;
      break;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < 4; ++i) {
    if (_storage[i] && _storage[i]->getType() == type)
      return _storage[i]->clone();
  }
  return NULL;
}
