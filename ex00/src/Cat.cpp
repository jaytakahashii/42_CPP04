#include "Cat.hpp"

#include <iostream>

Cat::Cat() {
  _type = "Cat";
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
  *this = other;
}

Cat& Cat::operator=(const Cat& other) {
  std::cout << "Cat copy assignment called" << std::endl;
  if (this != &other)
    _type = other._type;
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
  std::cout << "Meow! 🐱" << std::endl;
}
