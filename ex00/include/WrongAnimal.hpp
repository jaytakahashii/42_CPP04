#pragma once

#include <string>

class WrongAnimal {
 protected:
  std::string _type;

 public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& other);
  WrongAnimal& operator=(const WrongAnimal& other);
  ~WrongAnimal();

  void makeSound() const;
  std::string getType() const;
};
