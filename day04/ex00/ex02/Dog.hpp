#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain *brain;

public:
	Dog();
	Dog(const Dog& a);
	virtual ~Dog();

	Dog& operator=(const Dog& a);

	void makeSound() const;
};

#endif
