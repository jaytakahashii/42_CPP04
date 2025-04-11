#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  // const Animal* a = new Animal();  // Error

  std::cout << BLUE "\n--- Animal Creation ---" RESET << std::endl;
  const AAnimal* d = new Dog();
  const AAnimal* c = new Cat();

  std::cout << BLUE "\n--- Sounds ---" RESET << std::endl;
  d->makeSound();
  c->makeSound();

  std::cout << BLUE "\n--- Cleanup ---" RESET << std::endl;
  delete d;
  delete c;

  return 0;
}
