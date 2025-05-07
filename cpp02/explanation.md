I'll explain the strategy and concepts behind implementing exercises 00, 01, and 02, focusing on the logic of fixed-point numbers and how the implementations work.

## Exercise 00: Understanding Fixed-Point Numbers

**Core Concept:**
Fixed-point numbers are a way to represent fractional values using integers, allocating a fixed number of bits for the integer part and a fixed number of bits for the fractional part.

### Strategy:
1. **Data Storage:**
   - We store a fixed-point number as a single integer (`_fixedPointValue`)
   - We define how many bits are used for the fractional part (`_fractionalBits = 8`)

2. **Orthodox Canonical Form:**
   - Implement the four required methods: default constructor, copy constructor, copy assignment operator, and destructor
   - These form the foundation of a well-behaved C++ class

3. **Basic Operations:**
   - `getRawBits()`: Returns the raw integer value
   - `setRawBits()`: Sets the raw integer value

### Logical Representation:
If we have 8 fractional bits, our number's value can be represented as:
```
value = _fixedPointValue / 2^8
```

For example, if `_fixedPointValue = 256` (binary: 100000000), then:
```
value = 256 / 2^8 = 256 / 256 = 1.0
```

## Exercise 01: Converting Between Fixed-Point and Other Number Types

**Core Concept:**
To make fixed-point numbers useful, we need ways to convert between regular numbers (integers and floats) and fixed-point representation.

### Strategy:
1. **Integer Conversion:**
   - To convert an integer to fixed-point: Shift left by `_fractionalBits`
   - To convert fixed-point to integer: Shift right by `_fractionalBits`

2. **Float Conversion:**
   - To convert a float to fixed-point: Multiply by 2^`_fractionalBits` and round to nearest integer
   - To convert fixed-point to float: Divide by 2^`_fractionalBits`

3. **Output Representation:**
   - Overload the `<<` operator to display fixed-point numbers in their floating-point representation

### Logical Examples:
Converting integer 5 to fixed-point with 8 fractional bits:
```
_fixedPointValue = 5 << 8 = 5 * 256 = 1280
```

Converting float 5.5 to fixed-point with 8 fractional bits:
```
_fixedPointValue = round(5.5 * 256) = round(1408) = 1408
```

Converting fixed-point 1408 back to float:
```
floatValue = 1408 / 256 = 5.5
```

## Exercise 02: Operations on Fixed-Point Numbers

**Core Concept:**
To make fixed-point numbers fully functional, we need to implement mathematical operations and comparisons.

### Strategy:
1. **Comparison Operators:**
   - Simple integer comparisons, since the scaling is consistent

2. **Arithmetic Operators:**
   - Addition/Subtraction: Direct integer addition/subtraction works because the scale is the same
   - Multiplication: Need to account for double-scaling (shift right by _fractionalBits)
   - Division: Need to account for loss of scaling (shift left by _fractionalBits)

3. **Increment/Decrement:**
   - Incrementing/decrementing by 1 in fixed-point actually changes the value by 1/2^8 (or 0.00390625)
   - This is the smallest representable ε such that 1 + ε > 1

4. **Min/Max Functions:**
   - Utility functions that leverage comparison operators

### Logical Examples:

**Addition:**
For 5.5 + 2.25 (stored as 1408 + 576 = 1984):
```
5.5 + 2.25 = 7.75
1408 + 576 = 1984
1984 / 256 = 7.75 ✓
```

**Multiplication:**
For 5.5 * 2.0 (stored as 1408 * 512):
```
5.5 * 2.0 = 11.0
1408 * 512 = 720896
720896 >> 8 = 2816
2816 / 256 = 11.0 ✓
```

Without the right-shift correction, we'd get:
```
720896 / 256 = 2816.0 (incorrect!)
```

**Division:**
For 5.5 / 2.0 (stored as 1408 / 512):
```
5.5 / 2.0 = 2.75
(1408 << 8) / 512 = 360448 / 512 = 704
704 / 256 = 2.75 ✓
```

Without the left-shift correction, we'd get:
```
1408 / 512 = 2.75 (accidentally correct because of integer rounding)
But for 5.5 / 2.25 = 2.44..., it would be incorrect
```

**Increment:**
```
++fixedPointValue: Increases raw value by 1
For example, 1408 (5.5) becomes 1409 (5.5039...)
```

## Key Concepts in Fixed-Point Arithmetic:

1. **Bit Manipulation:** 
   - Left shift (`<<`) multiplies by 2^n
   - Right shift (`>>`) divides by 2^n

2. **Precision vs. Range:**
   - More fractional bits gives better precision but smaller range
   - With 8 fractional bits, the smallest representable value is 1/256 ≈ 0.00390625

3. **Scaling Factors:**
   - All operations must account for the scaling factor (2^_fractionalBits)
   - Addition/subtraction are straightforward
   - Multiplication/division need to adjust for the scaling factor

4. **Operator Overloading:**
   - Allows us to use fixed-point numbers with natural syntax
   - Makes the class more intuitive to use

5. **Orthodox Canonical Form:**
   - Ensures proper object lifecycle management
   - Copy operations preserve the exact value of fixed-point numbers

These exercises provide a foundation for understanding fixed-point arithmetic, which is valuable in systems where floating-point operations are too expensive or unavailable, such as embedded systems, graphics rendering, and audio processing where deterministic behavior is important.

The implementations follow a logical progression from basic representation to full arithmetic capability, introducing C++ concepts like operator overloading and proper class design along the way.