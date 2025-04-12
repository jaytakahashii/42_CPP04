#include "Cure.hpp"

#include <iostream>

#include "color.hpp"

Cure::Cure() : AMateria("cure") {
  std::cout << BOLDCYAN << "Cure constructed" << RESET << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
  std::cout << BOLDCYAN << "Cure copy constructed" << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
  std::cout << BOLDCYAN << "Cure copy assigned" << RESET << std::endl;
  if (this != &other) {
    AMateria::operator=(other);
  }
  return *this;
}

Cure::~Cure() {
  std::cout << BOLDCYAN << "Cure destructed" << RESET << std::endl;
}

AMateria* Cure::clone() const {
  return new Cure(*this);
}

void Cure::use(ICharacter& target) {
  std::cout << BOLDCYAN << "* heals " << target.getName() << "'s wounds *"
            << RESET << std::endl;
}
