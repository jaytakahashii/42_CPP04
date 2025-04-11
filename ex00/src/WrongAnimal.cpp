#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
  std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
  std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
  if (this != &other)
    this->_type = other._type;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
  std::cout << "* WrongAnimal sound *" << std::endl;
}

std::string WrongAnimal::getType() const {
  return _type;
}
