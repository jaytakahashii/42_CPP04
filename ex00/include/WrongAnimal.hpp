#pragma once

#include <iostream>
#include <string>

#include "color.hpp"

class WrongAnimal {
 protected:
  std::string _type;

 public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& other);
  WrongAnimal& operator=(const WrongAnimal& other);
  ~WrongAnimal();

  std::string getType() const;
  void makeSound() const;
};
