#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
  std::cout << "🐾🛠️  Animal constructed" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
  std::cout << "🐾📋 Animal copy constructed" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  std::cout << "🐾🔁 Animal copy assigned" << std::endl;
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

Animal::~Animal() {
  std::cout << "🐾💥 Animal destructed" << std::endl;
}

std::string Animal::getType() const {
  return _type;
}

void Animal::makeSound() const {
  std::cout << YELLOW "🐾 *Generic animal sound*" RESET << std::endl;
}
