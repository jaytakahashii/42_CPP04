#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void printDivider(std::string title) {
  std::cout << std::endl;
  std::cout << BOLDWHITE << "==== " << title << " ====" << RESET << std::endl;
}

int main() {
  printDivider("Animal test");
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  meta->makeSound();

  delete i;
  delete j;
  delete meta;

  printDivider("WrongAnimal test");
  const WrongAnimal* wrongMeta = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();

  std::cout << wrongCat->getType() << " " << std::endl;
  wrongCat->makeSound();
  wrongMeta->makeSound();

  delete wrongMeta;
  delete wrongCat;

  return 0;
}
