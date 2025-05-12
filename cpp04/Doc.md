ex00/
├── Animal.cpp
├── Animal.hpp
├── Cat.cpp
├── Cat.hpp
├── Dog.cpp
├── Dog.hpp
├── Makefile
├── WrongAnimal.cpp
├── WrongAnimal.hpp
├── WrongCat.cpp
├── WrongCat.hpp
└── main.cpp

ex01/
├── Animal.cpp
├── Animal.hpp
├── Brain.cpp
├── Brain.hpp
├── Cat.cpp
├── Cat.hpp
├── Dog.cpp
├── Dog.hpp
├── Makefile
└── main.cpp

ex02/
├── Animal.cpp
├── Animal.hpp
├── Brain.cpp
├── Brain.hpp
├── Cat.cpp
├── Cat.hpp
├── Dog.cpp
├── Dog.hpp
├── Makefile
└── main.cpp

# Polimorfismo, Classes Abstratas e Interfaces em C++

Vou explicar a teoria por trás dos exercícios 00, 01 e 02 do módulo 04, focando nos conceitos fundamentais e usando exemplos práticos.

## Exercício 00: Polimorfismo

### O que é Polimorfismo?
O polimorfismo é um conceito central da programação orientada a objetos que permite que objetos de diferentes classes sejam tratados como objetos de uma classe comum. Literalmente significa "muitas formas" e permite que diferentes classes compartilhem métodos com o mesmo nome mas comportamentos distintos.

### Tipos de Polimorfismo em C++:
1. **Polimorfismo em Tempo de Compilação (Estático)**:
   - Sobrecarga de função
   - Sobrecarga de operador

2. **Polimorfismo em Tempo de Execução (Dinâmico)**:
   - Funções virtuais e substituição de método

### O Polimorfismo do Exercício 00:

O exercício 00 demonstra o polimorfismo em tempo de execução através das classes `Animal`, `Dog` e `Cat`:

```cpp
class Animal {
protected:
    std::string type;
    
public:
    virtual void makeSound() const {
        std::cout << "Animal: *silêncio*" << std::endl;
    }
    
    std::string getType() const {
        return type;
    }
    
    // Construtores e destrutores
};

class Dog : public Animal {
public:
    Dog() {
        this->type = "Dog";
    }
    
    void makeSound() const override {
        std::cout << "Dog: Woof!" << std::endl;
    }
    
    // Outros métodos
};

class Cat : public Animal {
public:
    Cat() {
        this->type = "Cat";
    }
    
    void makeSound() const override {
        std::cout << "Cat: Meow!" << std::endl;
    }
    
    // Outros métodos
};
```

### Como Funciona:
1. A palavra-chave `virtual` na função `makeSound()` da classe base `Animal` permite que as classes derivadas sobrescrevam essa função.
2. A palavra-chave `override` nas classes derivadas indica explicitamente que estão sobrescrevendo um método virtual.
3. Quando chamamos `makeSound()` através de um ponteiro ou referência de `Animal` que aponta para um objeto `Dog` ou `Cat`, o sistema irá chamar a versão da função adequada para o tipo real do objeto, não o tipo do ponteiro.

### Exemplo Real:

Imagine um sistema de uma clínica veterinária onde diferentes tipos de animais precisam ser tratados. A consulta médica pode registrar sons do animal como parte do diagnóstico:

```cpp
void medicoVeterinario(const Animal* paciente) {
    std::cout << "Examinando um " << paciente->getType() << std::endl;
    std::cout << "Som do animal: ";
    paciente->makeSound();  // Polimorfismo em ação
    // Continua o exame...
}

// Uso:
Animal* rex = new Dog();
Animal* felix = new Cat();

medicoVeterinario(rex);    // Imprime o som do cachorro
medicoVeterinario(felix);  // Imprime o som do gato
```

O exercício também demonstra o que acontece quando **não** usamos polimorfismo corretamente através das classes `WrongAnimal` e `WrongCat`, onde `makeSound()` não é virtual, então sempre chama o método da classe base, independentemente do tipo real do objeto.

## Exercício 01: Herança e Gerenciamento de Memória

### Conceitos Principais:
1. **Composição**: A relação "tem um" - uma classe contém outra como atributo
2. **Deep Copy vs Shallow Copy**: Diferenças na cópia de objetos com alocação dinâmica
3. **Gerenciamento de Memória**: Prevenção de vazamentos de memória em hierarquias de classes

### Cópia Superficial (Shallow) vs Cópia Profunda (Deep):

#### Cópia Superficial:
```cpp
class Dog : public Animal {
private:
    Brain* brain;
    
public:
    Dog(const Dog& other) : Animal(other) {
        // PROBLEMA: Cópia superficial - ambos objetos apontam para o mesmo Brain
        this->brain = other.brain;  // Apenas copia o endereço
    }
};
```

#### Cópia Profunda (Correta):
```cpp
class Dog : public Animal {
private:
    Brain* brain;
    
public:
    Dog(const Dog& other) : Animal(other) {
        // Cópia profunda - cria um novo Brain com os mesmos dados
        this->brain = new Brain(*other.brain);
    }
    
    Dog& operator=(const Dog& other) {
        if (this != &other) {
            Animal::operator=(other);
            delete brain;  // Libera memória existente
            brain = new Brain(*other.brain);  // Aloca e copia novo cérebro
        }
        return *this;
    }
    
    ~Dog() {
        delete brain;  // Libera memória ao destruir
    }
};
```

### Exemplo Real:

Pense em um jogo onde cada personagem (`Dog` ou `Cat`) tem um conjunto de habilidades armazenadas em seu `Brain`:

```cpp
class Brain {
private:
    std::string ideas[100];
    
public:
    void setIdea(int index, const std::string& idea) {
        if (index >= 0 && index < 100)
            ideas[index] = idea;
    }
    
    std::string getIdea(int index) const {
        if (index >= 0 && index < 100)
            return ideas[index];
        return "";
    }
};

// No jogo:
Dog* rex = new Dog();
rex->getBrain()->setIdea(0, "Buscar vara");
rex->getBrain()->setIdea(1, "Latir para carteiro");

// Criando uma cópia de Rex
Dog* rexJr = new Dog(*rex);

// Se a cópia for superficial e modificarmos uma ideia em rexJr...
rexJr->getBrain()->setIdea(0, "Perseguir gato");
// ...isso também modificaria a ideia em rex! (não desejável)

// Com cópia profunda, cada cachorro tem seu próprio cérebro independente
```

O exercício também destaca a importância de destruir objetos através do tipo correto para garantir que todos os destrutores apropriados sejam chamados na ordem correta, prevenindo vazamentos de memória.

## Exercício 02: Classes Abstratas

### O que são Classes Abstratas?

Uma classe abstrata é uma classe que não pode ser instanciada diretamente e serve como modelo para outras classes derivadas. Em C++, uma classe se torna abstrata quando contém pelo menos uma função virtual pura (declarada com `= 0`).

### Características:
1. Não pode ser instanciada diretamente
2. Pode conter funções virtuais puras e normais
3. Classes derivadas devem implementar todas as funções virtuais puras para serem concretas

### Implementação:

```cpp
class AAnimal {  // O 'A' prefixado indica que é abstrata
protected:
    std::string type;
    
public:
    virtual ~AAnimal() { }
    
    virtual void makeSound() const = 0;  // Função virtual pura
    
    std::string getType() const {
        return type;
    }
};

// Agora Dog deve implementar makeSound:
class Dog : public AAnimal {
public:
    Dog() {
        this->type = "Dog";
    }
    
    void makeSound() const override {
        std::cout << "Dog: Woof!" << std::endl;
    }
};
```

### Por que Usar Classes Abstratas?

1. **Forçar um Contrato**: As subclasses são obrigadas a implementar certos métodos
2. **Modelar Conceitos**: Representar conceitos abstratos que não fazem sentido como objetos concretos
3. **Evitar Instanciação Incorreta**: Prevenir a criação de objetos de tipos genéricos

### Exemplo Real:

Imagine um sistema de desenho vetorial:

```cpp
class Shape {  // Classe abstrata
protected:
    int x, y;  // Posição

public:
    Shape(int x, int y) : x(x), y(y) { }
    virtual ~Shape() { }
    
    // Métodos abstratos
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void draw() const = 0;
    
    // Métodos concretos
    void move(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(int x, int y, double r) : Shape(x, y), radius(r) { }
    
    double area() const override {
        return M_PI * radius * radius;
    }
    
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
    
    void draw() const override {
        std::cout << "Desenhando círculo em (" << x << "," << y 
                  << ") com raio " << radius << std::endl;
    }
};

class Rectangle : public Shape {
    // Implementação similar...
};
```

Neste exemplo:
- `Shape` é uma classe abstrata que define o que todas as formas devem fazer
- Não faz sentido criar uma "forma" genérica sem especificar qual é a forma
- Cada forma concreta (círculo, retângulo) implementa os métodos abstratos conforme sua geometria

## Conclusão

Os exercícios 00, 01 e 02 exploram conceitos fundamentais da programação orientada a objetos em C++:

1. **Polimorfismo** permite que objetos de diferentes classes sejam tratados de maneira uniforme, com comportamentos específicos.

2. **Cópias Profundas e Gerenciamento de Memória** são essenciais para evitar vazamentos de memória e comportamento inesperado em hierarquias de classes com alocação dinâmica.

3. **Classes Abstratas** fornecem um meio de definir interfaces e comportamentos comuns sem permitir a instanciação de classes genéricas que não fazem sentido como objetos concretos.

Esses conceitos são fundamentais para projetar sistemas orientados a objetos robustos e flexíveis.