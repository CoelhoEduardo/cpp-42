#ifndef DOG_HPP_EX02
#define DOG_HPP_EX02

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* brain;

public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    virtual void makeSound() const;
    Brain* getBrain() const;
};

#endif
