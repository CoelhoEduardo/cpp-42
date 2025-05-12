#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testDeepCopy() {
    std::cout << "===== TESTING DEEP COPY =====" << std::endl;

    Dog* original = new Dog();
    original->getBrain()->setIdea(0, "I like bones");
    original->getBrain()->setIdea(1, "I want to chase cats");
    
    std::cout << "Original dog's idea 0: " << original->getBrain()->getIdea(0) << std::endl;
    std::cout << "Original dog's idea 1: " << original->getBrain()->getIdea(1) << std::endl;

    // Test copy constructor - deep copy
    Dog* copy_constructor = new Dog(*original);
    
    // Change original's ideas to verify deep copy
    original->getBrain()->setIdea(0, "Modified idea 0");
    original->getBrain()->setIdea(1, "Modified idea 1");
    
    std::cout << "\nAfter modifying original:" << std::endl;
    std::cout << "Original dog's idea 0: " << original->getBrain()->getIdea(0) << std::endl;
    std::cout << "Original dog's idea 1: " << original->getBrain()->getIdea(1) << std::endl;
    std::cout << "Copy dog's idea 0: " << copy_constructor->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy dog's idea 1: " << copy_constructor->getBrain()->getIdea(1) << std::endl;
    
    // Test assignment operator - deep copy
    Dog* assignment_copy = new Dog();
    *assignment_copy = *original;
    
    // Change original again to verify deep copy
    original->getBrain()->setIdea(0, "Another modified idea 0");
    
    std::cout << "\nAfter assignment and modifying original again:" << std::endl;
    std::cout << "Original dog's idea 0: " << original->getBrain()->getIdea(0) << std::endl;
    std::cout << "Assignment copy's idea 0: " << assignment_copy->getBrain()->getIdea(0) << std::endl;
    
    // Cleanup
    delete original;
    delete copy_constructor;
    delete assignment_copy;
}

int main()
{
    // Test from the subject
    std::cout << "===== BASIC TESTS =====" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // Should not create a leak
    delete i;
    
    // Array of Animals
    std::cout << "\n===== ANIMAL ARRAY TEST =====" << std::endl;
    const int arraySize = 10;
    Animal* animals[arraySize];
    
    // Fill array with half dogs and half cats
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }
    
    // Show the type of each animal
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << " is a " << animals[i]->getType() << std::endl;
    }
    
    // Make each animal sound
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << " says: ";
        animals[i]->makeSound();
    }
    
    // Delete all animals
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    
    // Test the scope-based lifetime
    std::cout << "\n===== SCOPE TEST =====" << std::endl;
    {
        Dog basic;
        basic.getBrain()->setIdea(0, "I'm a basic dog");
        
        // Create a dog in a nested scope
        {
            std::cout << "-- Entering nested scope --" << std::endl;
            Dog tmp = basic; // Copy
            std::cout << "Copied dog's idea 0: " << tmp.getBrain()->getIdea(0) << std::endl;
            std::cout << "-- Exiting nested scope --" << std::endl;
        }
        
        std::cout << "After nested scope, basic dog's idea 0: " << basic.getBrain()->getIdea(0) << std::endl;
    }
    
    // Test deep copy specifically
    testDeepCopy();
    
    return 0;
}
