#ifndef CAT_HPP_EX02
#define CAT_HPP_EX02

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* brain;

public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();

    virtual void makeSound() const;
    Brain* getBrain() const;
};

#endif
