#include "Cat.hpp"
#include "Dog.hpp"

static void printDivider(std::string title) {
  std::cout << std::endl;
  std::cout << BOLDWHITE << "==== " << title << " ====" << RESET << std::endl;
}

int main() {
  const int SIZE = 4;
  Animal* animals[SIZE];

  // Half Dogs, Half Cats
  printDivider("instantiation");
  for (int i = 0; i < SIZE / 2; ++i) {
    animals[i] = new Dog();
  }
  for (int i = SIZE / 2; i < SIZE; ++i) {
    animals[i] = new Cat();
  }

  printDivider("types");
  for (int i = 0; i < SIZE; ++i) {
    animals[i]->makeSound();
  }

  printDivider("destruction");
  for (int i = 0; i < SIZE; ++i) {
    delete animals[i];
  }

  printDivider("deep copy test");
  Dog original;
  original.setIdea(0, "Chase the ball");

  Dog copy = original;
  copy.setIdea(0, "Sleep all day");

  std::cout << YELLOW "Original Dog idea: " << original.getIdea(0) << RESET
            << std::endl;
  std::cout << YELLOW "Copied Dog idea:   " << copy.getIdea(0) << RESET
            << std::endl;

  return 0;
}
