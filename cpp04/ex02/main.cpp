#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    // This would not compile because Animal is now abstract:
    // Animal test;  // Compile error: cannot instantiate abstract class

    // But we can create pointers to Animal:
    Animal* j = new Dog();
    Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); // Will output the cat sound
    j->makeSound(); // Will output the dog sound
    
    // Create and test a Dog object directly
    Dog dog;
    dog.makeSound();
    dog.getBrain()->setIdea(0, "I love bones!");
    std::cout << "Dog's idea: " << dog.getBrain()->getIdea(0) << std::endl;
    
    // Create and test a Cat object directly
    Cat cat;
    cat.makeSound();
    cat.getBrain()->setIdea(0, "I love napping in the sun!");
    std::cout << "Cat's idea: " << cat.getBrain()->getIdea(0) << std::endl;
    
    // Test deep copy
    std::cout << "\n====== DEEP COPY TEST ======" << std::endl;
    Cat* original = new Cat();
    original->getBrain()->setIdea(0, "Original cat thought");
    
    Cat* copy = new Cat(*original);
    
    std::cout << "Original cat's idea: " << original->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy cat's idea: " << copy->getBrain()->getIdea(0) << std::endl;
    
    // Change original's idea
    original->getBrain()->setIdea(0, "Modified original thought");
    
    std::cout << "After modification:" << std::endl;
    std::cout << "Original cat's idea: " << original->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy cat's idea: " << copy->getBrain()->getIdea(0) << std::endl;
    
    // Cleanup
    delete j;
    delete i;
    delete original;
    delete copy;
    
    // Test array of animals
    std::cout << "\n====== ANIMAL ARRAY TEST ======" << std::endl;
    const int arraySize = 4;
    Animal* animals[arraySize];
    
    // Fill array with half dogs and half cats
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }
    
    // Show the type and sound of each animal
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << " is a " << animals[i]->getType() << " and says: ";
        animals[i]->makeSound();
    }
    
    // Delete all animals
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    
    return 0;
}
