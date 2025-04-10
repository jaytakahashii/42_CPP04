#include "Dog.hpp"

#include <iostream>

Dog::Dog() {
  _type = "Dog";
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
  *this = other;
}

Dog& Dog::operator=(const Dog& other) {
  std::cout << "Dog copy assignment called" << std::endl;
  if (this != &other)
    _type = other._type;
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
  std::cout << "Woof! 🐶" << std::endl;
}
