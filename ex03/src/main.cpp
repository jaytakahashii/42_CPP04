#include <iostream>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "color.hpp"

static void printDivider(std::string title) {
  std::cout << std::endl;
  std::cout << BOLDWHITE << "==== " << title << " ====" << RESET << std::endl;
}

int main() {
  printDivider("Subject Test");

  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");

  me->equip(src->createMateria("ice"));
  me->equip(src->createMateria("cure"));

  ICharacter* bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;

  printDivider("Deep Copy Test (Character)");
  {
    Character original("original");
    original.equip(new Ice());
    original.equip(new Cure());

    Character copyConstructed(original);
    copyConstructed.use(0, original);
    copyConstructed.use(1, original);

    Character assigned("assigned");
    assigned = original;
    assigned.use(0, original);
    assigned.use(1, original);
  }

  printDivider("Edge Case: Unknown Materia Type");

  MateriaSource* src2 = new MateriaSource();
  src2->learnMateria(new Ice());
  AMateria* unknown = src2->createMateria("fire");
  if (unknown == NULL)
    std::cout << RED << "Unknown materia type returned NULL (expected)" << RESET
              << std::endl;
  delete src2;

  printDivider("Edge Case: Unequip and Use");

  Character unequipped("unequipped");
  unequipped.equip(new Ice());
  unequipped.equip(new Cure());
  unequipped.unequip(1);          // Remove Cure
  unequipped.use(1, unequipped);  // Should do nothing safely

  printDivider("Edge Case: Invalid Indices");

  Character invalid("invalid");
  invalid.use(10, invalid);  // Out of bounds
  invalid.unequip(-1);       // Negative index
  invalid.use(-2, invalid);  // Negative index

  return 0;
}
