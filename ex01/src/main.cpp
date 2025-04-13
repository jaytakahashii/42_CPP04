#include "Cat.hpp"
#include "Dog.hpp"

static void printDivider(std::string title) {
  std::cout << std::endl;
  std::cout << BOLDWHITE << "==== " << title << " ====" << RESET << std::endl;
}

int main() {
  const int SIZE = 6;
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

  printDivider("deep copy test - Dog");
  Dog original;
  original.setIdea(0, "Chase the ball");

  Dog copy = original;
  copy.setIdea(0, "Sleep all day");

  std::cout << YELLOW "Original Dog idea: " << original.getIdea(0) << RESET
            << std::endl;
  std::cout << YELLOW "Copied Dog idea:   " << copy.getIdea(0) << RESET
            << std::endl;

  printDivider("deep copy test - Cat");
  Cat originalCat;
  originalCat.setIdea(0, "Chase the laser");
  originalCat.setIdea(1, "Scratch the couch");
  originalCat.setIdea(2, "Meow at the door");
  originalCat.setIdea(3, "Pounce on the toy");

  Cat copyCat = originalCat;
  copyCat.setIdea(0, "Sleep all day");
  copyCat.setIdea(1, "Chase the mouse");
  copyCat.setIdea(2, "Scratch the post");
  copyCat.setIdea(3, "Meow at the window");

  std::cout << YELLOW "Original Cat idea 0: " << originalCat.getIdea(0) << RESET
            << std::endl;
  std::cout << YELLOW "Original Cat idea 1: " << originalCat.getIdea(1) << RESET
            << std::endl;
  std::cout << YELLOW "Original Cat idea 2: " << originalCat.getIdea(2) << RESET
            << std::endl;
  std::cout << YELLOW "Original Cat idea 3: " << originalCat.getIdea(3) << RESET
            << std::endl;
  std::cout << YELLOW "Copied Cat idea 0:   " << copyCat.getIdea(0) << RESET
            << std::endl;
  std::cout << YELLOW "Copied Cat idea 1:   " << copyCat.getIdea(1) << RESET
            << std::endl;
  std::cout << YELLOW "Copied Cat idea 2:   " << copyCat.getIdea(2) << RESET
            << std::endl;
  std::cout << YELLOW "Copied Cat idea 3:   " << copyCat.getIdea(3) << RESET
            << std::endl;

  return 0;
}
