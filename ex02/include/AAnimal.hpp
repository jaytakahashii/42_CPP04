#pragma once

#include <iostream>
#include <string>

#include "color.hpp"

class AAnimal {
 protected:
  std::string _type;

 public:
  AAnimal();
  AAnimal(const AAnimal &other);
  AAnimal &operator=(const AAnimal &other);
  virtual ~AAnimal();

  std::string getType() const;
  virtual void makeSound() const = 0;  // Pure virtual function
};
