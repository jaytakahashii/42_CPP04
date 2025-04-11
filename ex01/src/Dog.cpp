#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain()) {
  _type = "Dog";
  std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
  _brain = new Brain(*other._brain);
  std::cout << "Dog copy constructed" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  std::cout << "Dog copy assigned" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    delete _brain;                      // Free the old brain
    _brain = new Brain(*other._brain);  // Create a new brain
  }
  return *this;
}

Dog::~Dog() {
  delete _brain;
  std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound() const {
  std::cout << "Woof! 🐶" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
  _brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
  return _brain->getIdea(index);
}
