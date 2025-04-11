#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const int SIZE = 4;
  Animal* animals[SIZE];

  // Half Dogs, Half Cats
  for (int i = 0; i < SIZE / 2; ++i) {
    animals[i] = new Dog();
  }
  for (int i = SIZE / 2; i < SIZE; ++i) {
    animals[i] = new Cat();
  }

  std::cout << "\n--- Sounds ---" << std::endl;
  for (int i = 0; i < SIZE; ++i) {
    animals[i]->makeSound();
  }

  std::cout << "\n--- Cleanup ---" << std::endl;
  for (int i = 0; i < SIZE; ++i) {
    delete animals[i];
  }

  std::cout << "\n--- Deep Copy Test ---" << std::endl;
  Dog original;
  original.setIdea(0, "Chase the ball");

  Dog copy = original;
  copy.setIdea(0, "Sleep all day");

  std::cout << "Original Dog idea: " << original.getIdea(0) << std::endl;
  std::cout << "Copied Dog idea:   " << copy.getIdea(0) << std::endl;

  return 0;
}
