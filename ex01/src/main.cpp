#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const int SIZE = 4;
  Animal* animals[SIZE];

  // Half Dogs, Half Cats
  std::cout << BLUE "\n--- Animal Creation ---" RESET << std::endl;
  for (int i = 0; i < SIZE / 2; ++i) {
    animals[i] = new Dog();
  }
  for (int i = SIZE / 2; i < SIZE; ++i) {
    animals[i] = new Cat();
  }

  std::cout << BLUE "\n--- Sounds ---" RESET << std::endl;
  for (int i = 0; i < SIZE; ++i) {
    animals[i]->makeSound();
  }

  std::cout << BLUE "\n--- Cleanup ---" RESET << std::endl;
  for (int i = 0; i < SIZE; ++i) {
    delete animals[i];
  }

  std::cout << BLUE "\n--- Deep Copy Test ---" RESET << std::endl;
  Dog original;
  original.setIdea(0, "Chase the ball");

  Dog copy = original;
  copy.setIdea(0, "Sleep all day");

  std::cout << YELLOW "Original Dog idea: " << original.getIdea(0) << RESET
            << std::endl;
  std::cout << YELLOW "Copied Dog idea:   " << copy.getIdea(0) << RESET
            << std::endl;

  std::cout << BLUE "\n--- end of main ---" RESET << std::endl;

  return 0;
}
