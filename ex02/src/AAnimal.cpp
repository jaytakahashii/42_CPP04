#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
  std::cout << GREEN "🐾🛠️  Animal constructed" RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
  std::cout << GREEN "🐾📋 Animal copy constructed" RESET << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
  std::cout << GREEN "🐾🔁 Animal copy assigned" RESET << std::endl;
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

AAnimal::~AAnimal() {
  std::cout << GREEN "🐾💥 Animal destructed" RESET << std::endl;
}

std::string AAnimal::getType() const {
  return _type;
}
