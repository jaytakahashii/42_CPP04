#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
  std::cout << "WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
  std::cout << "WrongAnimal copy constructed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  std::cout << "WrongAnimal copy assigned" << std::endl;
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructed" << std::endl;
}

std::string WrongAnimal::getType() const {
  return _type;
}

void WrongAnimal::makeSound() const {
  std::cout << "*WrongAnimal generic sound*" << std::endl;
}
