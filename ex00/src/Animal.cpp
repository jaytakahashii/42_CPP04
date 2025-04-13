#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
  std::cout << GREEN "🐾🛠️  Animal constructed" RESET << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
  std::cout << GREEN "🐾📋 Animal copy constructed" RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  std::cout << GREEN "🐾🔁 Animal copy assigned" RESET << std::endl;
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

Animal::~Animal() {
  std::cout << GREEN "🐾💥 Animal destructed" RESET << std::endl;
}

std::string Animal::getType() const {
  return _type;
}

void Animal::makeSound() const {
  std::cout << GREEN "🐾 *Generic animal sound*" RESET << std::endl;
}
