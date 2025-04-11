#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain& other) {
  std::cout << "Brain copy constructed" << std::endl;
  *this = other;
}

Brain& Brain::operator=(const Brain& other) {
  std::cout << "Brain copy assigned" << std::endl;
  if (this != &other)
    for (int i = 0; i < 100; ++i)
      _ideas[i] = other._ideas[i];
  return *this;
}

Brain::~Brain() {
  std::cout << "Brain destructed" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
  if (index >= 0 && index < 100)
    _ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
  if (index >= 0 && index < 100)
    return _ideas[index];
  return "";
}
