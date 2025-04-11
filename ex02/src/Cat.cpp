#include "Cat.hpp"

Cat::Cat() : AAnimal(), _brain(new Brain()) {
  _type = "Cat";
  std::cout << "🐱🛠️  Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
  _brain = new Brain(*other._brain);
  std::cout << "🐱📋 Cat copy constructed" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  std::cout << "🐱🔁 Cat copy assigned" << std::endl;
  if (this != &other) {
    AAnimal::operator=(other);
    delete _brain;
    _brain = new Brain(*other._brain);
  }
  return *this;
}

Cat::~Cat() {
  delete _brain;
  std::cout << "🐱💥 Cat destructed" << std::endl;
}

void Cat::makeSound() const {
  std::cout << YELLOW "🐱 Meow!" RESET << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
  _brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
  return _brain->getIdea(index);
}
