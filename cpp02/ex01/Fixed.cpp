#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->_fixedPointValue = rhs.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> this->_fractionalBits;
}

// Stream insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
