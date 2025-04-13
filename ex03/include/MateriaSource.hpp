#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria* _storage[4];

 public:
  MateriaSource();
  MateriaSource(MateriaSource const& other);
  MateriaSource& operator=(MateriaSource const& other);
  virtual ~MateriaSource();

  virtual void learnMateria(AMateria* m);
  virtual AMateria* createMateria(std::string const& type);
};
