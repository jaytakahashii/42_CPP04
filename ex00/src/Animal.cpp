#include "Animal.hpp"

#include <iostream>

Animal::Animal() : _type("Animal") {
  std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = other;
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal copy assignment called" << std::endl;
  if (this != &other)
    _type = other._type;
  return *this;
}

Animal::~Animal() {
  std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
  std::cout << "* Generic animal sound *" << std::endl;
}

std::string Animal::getType() const {
  return _type;
}
