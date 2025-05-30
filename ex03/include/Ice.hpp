#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
 public:
  Ice();
  Ice(Ice const& other);
  Ice& operator=(Ice const& other);
  virtual ~Ice();

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};
