#include "Dog.hpp"

Dog::Dog() : AAnimal(), _brain(new Brain()) {
  _type = "Dog";
  std::cout << CYAN "🐶🛠️  Dog constructed" RESET << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
  _brain = new Brain(*other._brain);
  std::cout << CYAN "🐶📋 Dog copy constructed" RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  std::cout << CYAN "🐶🔁 Dog copy assigned" RESET << std::endl;
  if (this != &other) {
    AAnimal::operator=(other);
    delete _brain;                      // Free the old brain
    _brain = new Brain(*other._brain);  // Create a new brain
  }
  return *this;
}

Dog::~Dog() {
  delete _brain;
  std::cout << CYAN "🐶💥 Dog destructed" RESET << std::endl;
}

void Dog::makeSound() const {
  std::cout << CYAN "🐶 Woof!" RESET << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
  _brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
  return _brain->getIdea(index);
}
