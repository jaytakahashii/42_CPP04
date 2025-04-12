#include "AMateria.hpp"

#include <iostream>

#include "color.hpp"

AMateria::AMateria(std::string const& type) : _type(type) {
  std::cout << BLUE << "AMateria constructed" << RESET << std::endl;
}

AMateria::AMateria(AMateria const& other) : _type(other._type) {
  std::cout << BLUE << "AMateria copy constructed" << RESET << std::endl;
}

AMateria& AMateria::operator=(AMateria const& other) {
  std::cout << BLUE << "AMateria copy assigned" << RESET << std::endl;
  if (this != &other) {
    this->_type = other._type;
  }
  return *this;
}

AMateria::~AMateria() {
  std::cout << BLUE << "AMateria destructed" << RESET << std::endl;
}

std::string const& AMateria::getType() const {
  return this->_type;
}

void AMateria::use(ICharacter& target) {
  std::cout << BLUE << "* uses generic materia on " << target.getName() << " *"
            << RESET << std::endl;
}
