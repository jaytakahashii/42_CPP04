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
    for (int i = 0; i < 4; ++i) {
      if (_storage[i]) {
        delete _storage[i];
        _storage[i] = NULL;
      }
      if (other._storage[i])
        _storage[i] = other._storage[i]->clone();
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; ++i) {
    if (_storage[i]) {
      delete _storage[i];
    }
  }
  std::cout << MAGENTA << "MateriaSource destructed" << RESET << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
  if (!m) {
    std::cout << RED << "MateriaSource: NULL Materia cannot be learned" << RESET
              << std::endl;
    return;
  }
  for (int i = 0; i < 4; ++i) {
    if (!_storage[i]) {
      _storage[i] = m;
      std::cout << MAGENTA << "MateriaSource: Learned " << m->getType()
                << " Materia [" << i << "]" << RESET << std::endl;
      return;
    }
  }
  std::cout << RED << "MateriaSource: No space to learn " << m->getType()
            << " Materia" << RESET << std::endl;
  delete m;  // Clean up the materia if not stored
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < 4; ++i) {
    if (_storage[i] && _storage[i]->getType() == type) {
      std::cout << MAGENTA << "MateriaSource: Created "
                << _storage[i]->getType() << " Materia [" << i << "]" << RESET
                << std::endl;
      return _storage[i]->clone();
    }
  }
  std::cout << RED << "MateriaSource: Unknown Materia type " << type
            << " requested" << RESET << std::endl;
  return NULL;
}
