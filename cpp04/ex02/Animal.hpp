#ifndef ANIMAL_HPP_EX02
#define ANIMAL_HPP_EX02

#include <string>
#include <iostream>

class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const = 0; // Pure virtual function
};

#endif
