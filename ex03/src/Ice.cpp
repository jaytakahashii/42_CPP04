#include "Ice.hpp"

#include <iostream>

#include "color.hpp"

Ice::Ice() : AMateria("ice") {
  std::cout << YELLOW << "Ice constructed" << RESET << std::endl;
}

Ice::Ice(Ice const& other) : AMateria(other) {
  std::cout << YELLOW << "Ice copy constructed" << RESET << std::endl;
}

Ice& Ice::operator=(Ice const& other) {
  std::cout << YELLOW << "Ice copy assigned" << RESET << std::endl;
  if (this != &other) {
    AMateria::operator=(other);
  }
  return *this;
}

Ice::~Ice() {
  std::cout << YELLOW << "Ice destructed" << RESET << std::endl;
}

AMateria* Ice::clone() const {
  return new Ice(*this);
}

void Ice::use(ICharacter& target) {
  std::cout << YELLOW << "* shoots an ice bolt at " << target.getName() << " *"
            << RESET << std::endl;
}
