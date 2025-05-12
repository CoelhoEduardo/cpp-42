# Explicação sobre Números de Ponto Fixo em C++

Vou explicar a estratégia e os conceitos por trás da implementação dos exercícios 00, 01 e 02, focando na lógica dos números de ponto fixo e como as implementações funcionam.

## Exercício 00: Entendendo Números de Ponto Fixo

**Conceito Principal:**
Números de ponto fixo são uma maneira de representar valores fracionários usando inteiros, alocando um número fixo de bits para a parte inteira e um número fixo de bits para a parte fracionária.

> **Explicação simplificada:** 
> Imagine que você tem um número como 5,75. Em vez de armazenar "5" e "75" separadamente, multiplicamos por 100 e armazenamos como 575. Depois, quando precisamos do valor real, dividimos por 100 novamente. No caso dos computadores, usamos potências de 2 (como 256) em vez de potências de 10.

### Estratégia:
1. **Armazenamento de Dados:**
   - Armazenamos um número de ponto fixo como um único inteiro (`_fixedPointValue`)
   - Definimos quantos bits são usados para a parte fracionária (`_fractionalBits = 8`)

2. **Forma Canônica Ortodoxa:**
   - Implementamos os quatro métodos necessários: construtor padrão, construtor de cópia, operador de atribuição de cópia e destrutor
   - Esses formam a base de uma classe C++ bem comportada

3. **Operações Básicas:**
   - `getRawBits()`: Retorna o valor inteiro bruto
   - `setRawBits()`: Define o valor inteiro bruto

### Representação Lógica:
Se temos 8 bits fracionários, o valor do nosso número pode ser representado como:
```
valor = _fixedPointValue / 2^8
```

Por exemplo, se `_fixedPointValue = 256` (binário: 100000000), então:
```
valor = 256 / 2^8 = 256 / 256 = 1,0
```

## Exercício 01: Convertendo Entre Ponto Fixo e Outros Tipos de Números

**Conceito Principal:**
Para tornar os números de ponto fixo úteis, precisamos de maneiras de converter entre números regulares (inteiros e floats) e representação de ponto fixo.

> **Explicação simplificada:** 
> Se queremos armazenar o número 5 em nosso formato especial, multiplicamos por 256 (que é 2^8) e obtemos 1280. 
> Para o número 5,5, fazemos 5,5 × 256 = 1408.
> Quando queremos voltar ao número original, dividimos por 256 novamente.

### Estratégia:
1. **Conversão de Inteiro:**
   - Para converter um inteiro para ponto fixo: Deslocamos à esquerda por `_fractionalBits`
   - Para converter ponto fixo para inteiro: Deslocamos à direita por `_fractionalBits`

2. **Conversão de Float:**
   - Para converter um float para ponto fixo: Multiplicamos por 2^`_fractionalBits` e arredondamos para o inteiro mais próximo
   - Para converter ponto fixo para float: Dividimos por 2^`_fractionalBits`

3. **Representação de Saída:**
   - Sobrecarregamos o operador `<<` para exibir números de ponto fixo em sua representação de ponto flutuante

### Exemplos Lógicos:
Convertendo o inteiro 5 para ponto fixo com 8 bits fracionários:
```
_fixedPointValue = 5 << 8 = 5 * 256 = 1280
```

Convertendo o float 5,5 para ponto fixo com 8 bits fracionários:
```
_fixedPointValue = round(5,5 * 256) = round(1408) = 1408
```

Convertendo o ponto fixo 1408 de volta para float:
```
floatValue = 1408 / 256 = 5,5
```

## Exercício 02: Operações em Números de Ponto Fixo

**Conceito Principal:**
Para tornar os números de ponto fixo totalmente funcionais, precisamos implementar operações matemáticas e comparações.

> **Explicação simplificada:** 
> Queremos poder fazer contas como 5,5 + 2,25 ou 5,5 × 2,0 usando nosso formato especial. 
> A adição é fácil: só somamos os números internos. 
> Mas multiplicação e divisão são mais complicadas porque precisamos ajustar a escala.

### Estratégia:
1. **Operadores de Comparação:**
   - Comparações simples de inteiros, já que a escala é consistente

2. **Operadores Aritméticos:**
   - Adição/Subtração: A adição/subtração direta de inteiros funciona porque a escala é a mesma
   - Multiplicação: Precisamos considerar a escala dupla (deslocar à direita por _fractionalBits)
   - Divisão: Precisamos considerar a perda de escala (deslocar à esquerda por _fractionalBits)

3. **Incremento/Decremento:**
   - Incrementar/decrementar por 1 em ponto fixo na verdade muda o valor em 1/2^8 (ou 0,00390625)
   - Este é o menor ε representável tal que 1 + ε > 1

4. **Funções Min/Max:**
   - Funções utilitárias que aproveitam os operadores de comparação

### Exemplos Lógicos:

**Adição:**
Para 5,5 + 2,25 (armazenados como 1408 + 576 = 1984):
```
5,5 + 2,25 = 7,75
1408 + 576 = 1984
1984 / 256 = 7,75 ✓
```

**Multiplicação:**
Para 5,5 * 2,0 (armazenados como 1408 * 512):
```
5,5 * 2,0 = 11,0
1408 * 512 = 720896
720896 >> 8 = 2816
2816 / 256 = 11,0 ✓
```

Sem a correção de deslocamento à direita, teríamos:
```
720896 / 256 = 2816,0 (incorreto!)
```

**Divisão:**
Para 5,5 / 2,0 (armazenados como 1408 / 512):
```
5,5 / 2,0 = 2,75
(1408 << 8) / 512 = 360448 / 512 = 704
704 / 256 = 2,75 ✓
```

Sem a correção de deslocamento à esquerda, teríamos:
```
1408 / 512 = 2,75 (acidentalmente correto devido ao arredondamento de inteiros)
Mas para 5,5 / 2,25 = 2,44..., seria incorreto
```

**Incremento:**
```
++fixedPointValue: Aumenta o valor bruto em 1
Por exemplo, 1408 (5,5) se torna 1409 (5,5039...)
```

## Conceitos-Chave na Aritmética de Ponto Fixo:

1. **Manipulação de Bits:** 
   - Deslocamento à esquerda (`<<`) multiplica por 2^n
   - Deslocamento à direita (`>>`) divide por 2^n

   > **Analogia:** Deslocar dígitos em um número decimal é como multiplicar ou dividir por 10. No sistema binário, deslocar bits é como multiplicar ou dividir por 2.

2. **Precisão vs. Alcance:**
   - Mais bits fracionários dão melhor precisão, mas menor alcance
   - Com 8 bits fracionários, o menor valor representável é 1/256 ≈ 0,00390625

   > **Explicação simplificada:** Com nosso formato, podemos representar números com precisão de até 1/256. É como uma régua que pode medir até milímetros, mas não pode medir frações de milímetro.

3. **Fatores de Escala:**
   - Todas as operações devem considerar o fator de escala (2^_fractionalBits)
   - Adição/subtração são diretas
   - Multiplicação/divisão precisam ajustar o fator de escala

4. **Sobrecarga de Operadores:**
   - Permite usar números de ponto fixo com sintaxe natural
   - Torna a classe mais intuitiva de usar

   > **Analogia:** É como ensinar o computador a entender que quando escrevemos "5,5 + 2,25", ele deve fazer a operação correta mesmo que internamente os números sejam representados de forma diferente.

5. **Forma Canônica Ortodoxa:**
   - Garante o gerenciamento adequado do ciclo de vida do objeto
   - Operações de cópia preservam o valor exato dos números de ponto fixo

Esses exercícios fornecem uma base para entender a aritmética de ponto fixo, que é valiosa em sistemas onde operações de ponto flutuante são muito caras ou indisponíveis, como sistemas embarcados, renderização gráfica e processamento de áudio onde o comportamento determinístico é importante.

As implementações seguem uma progressão lógica da representação básica à capacidade aritmética completa, introduzindo conceitos de C++ como sobrecarga de operadores e design adequado de classes ao longo do caminho.