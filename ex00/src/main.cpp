#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "color.hpp"

int main() {
  std::cout << BLUE "=== Correct Animal Test ===" RESET << std::endl;
  const Animal* a1 = new Dog();
  const Animal* a2 = new Cat();

  a1->makeSound();  // Woof!
  a2->makeSound();  // Meow!

  delete a1;
  delete a2;

  std::cout << BLUE "\n=== Wrong Animal Test ===" RESET << std::endl;
  const WrongAnimal* wa = new WrongCat();

  wa->makeSound();  // ❌ WrongAnimalのmakeSound()が呼ばれる

  delete wa;

  return 0;
}
