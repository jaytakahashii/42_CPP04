#include "Dog.hpp"

Dog::Dog() : Animal() {
  _type = "Dog";
  std::cout << CYAN "🐶🛠️  Dog constructed" RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
  std::cout << CYAN "🐶📋 Dog copy constructed" RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  std::cout << CYAN "🐶🔁 Dog copy assigned" RESET << std::endl;
  if (this != &other) {
    Animal::operator=(other);
  }
  return *this;
}

Dog::~Dog() {
  std::cout << CYAN "🐶💥 Dog destructed" RESET << std::endl;
}

void Dog::makeSound() const {
  std::cout << CYAN "🐶 Woof!" RESET << std::endl;
}
