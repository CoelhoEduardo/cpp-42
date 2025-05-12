#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "--- Animal Tests ---" << std::endl;
    
    // Test from the subject
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    
    i->makeSound(); // Will output the cat sound
    j->makeSound(); // Will output the dog sound
    meta->makeSound(); // Will output the generic animal sound
    
    // Additional tests
    std::cout << "\n--- Additional Animal Tests ---" << std::endl;
    
    // Test copy constructor
    const Animal* animal_copy = new Animal(*meta);
    animal_copy->makeSound();
    
    // Cleanup
    delete meta;
    delete j;
    delete i;
    delete animal_copy;
    
    std::cout << "\n--- WrongAnimal Tests ---" << std::endl;
    
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    
    std::cout << wrong_cat->getType() << std::endl;
    
    wrong_cat->makeSound(); // Will output the WrongAnimal sound, not the WrongCat sound!
    wrong_meta->makeSound();
    
    // Direct WrongCat test
    std::cout << "\n--- Direct WrongCat Test ---" << std::endl;
    const WrongCat* direct_wrong_cat = new WrongCat();
    direct_wrong_cat->makeSound(); // Will output the WrongCat sound
    
    // Cleanup
    delete wrong_meta;
    delete wrong_cat;
    delete direct_wrong_cat;
    
    std::cout << "\n--- Stack-Allocated Tests ---" << std::endl;
    
    Animal stack_animal;
    Dog stack_dog;
    Cat stack_cat;
    
    stack_animal.makeSound();
    stack_dog.makeSound();
    stack_cat.makeSound();
    
    std::cout << "\n--- Automatic Cleanup ---" << std::endl;
    
    return 0;
}
