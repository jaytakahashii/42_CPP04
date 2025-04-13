#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  // const Animal* a = new Animal();  // Error

  const AAnimal* d = new Dog();
  const AAnimal* c = new Cat();
  d->makeSound();
  c->makeSound();
  delete d;
  delete c;

  return 0;
}
