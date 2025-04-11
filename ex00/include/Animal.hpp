#pragma once

#include <iostream>
#include <string>

#include "color.hpp"

class Animal {
 protected:
  std::string _type;

 public:
  Animal();
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);
  virtual ~Animal();

  std::string getType() const;
  virtual void makeSound() const;
};
