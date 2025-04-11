#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  std::cout << BLUE
      "initializing Animal, Cat, Dog, WrongAnimal, and WrongCat" RESET
            << std::endl;
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << BLUE "\nGetting types and making sounds" RESET << std::endl;

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();

  std::cout << BLUE "\nDeleting objects" RESET << std::endl;
  delete i;
  delete j;
  delete meta;

  std::cout << BLUE "\nInitializing WrongAnimal and WrongCat" RESET
            << std::endl;
  const WrongAnimal* wrongMeta = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();

  std::cout << BLUE "\nGetting types and making sounds" RESET << std::endl;
  std::cout << wrongCat->getType() << " " << std::endl;
  wrongCat->makeSound();
  wrongMeta->makeSound();

  std::cout << BLUE "\nDeleting objects" RESET << std::endl;
  delete wrongMeta;
  delete wrongCat;

  return 0;
}
