#include "Cat.hpp"

Cat::Cat() : Animal() {
  _type = "Cat";
  std::cout << WHITE "🐱🛠️  Cat constructed" RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << WHITE "🐱📋 Cat copy constructed" RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  std::cout << WHITE "🐱🔁 Cat copy assigned" RESET << std::endl;
  if (this != &other) {
    Animal::operator=(other);
  }
  return *this;
}

Cat::~Cat() {
  std::cout << WHITE "🐱💥 Cat destructed" RESET << std::endl;
}

void Cat::makeSound() const {
  std::cout << WHITE "🐱 Meow!" RESET << std::endl;
}
