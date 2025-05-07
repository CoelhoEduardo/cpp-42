#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* Constructors and Destructor */
Fixed::Fixed() : _fixedPointValue(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    // std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
    // std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

/* Assignment Operator */
Fixed &Fixed::operator=(const Fixed &rhs) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->_fixedPointValue = rhs.getRawBits();
    }
    return *this;
}

/* Comparison Operators */
bool Fixed::operator>(const Fixed &rhs) const {
    return this->_fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed &rhs) const {
    return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed &rhs) const {
    return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return this->_fixedPointValue != rhs._fixedPointValue;
}

/* Arithmetic Operators */
Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue + rhs._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(this->_fixedPointValue - rhs._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits((this->_fixedPointValue * rhs._fixedPointValue) >> this->_fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    if (rhs._fixedPointValue == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits((this->_fixedPointValue << this->_fractionalBits) / rhs._fixedPointValue);
    return result;
}

/* Increment/Decrement Operators */
Fixed &Fixed::operator++() {  // Pre-increment
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {  // Post-increment
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {  // Pre-decrement
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {  // Post-decrement
    Fixed temp(*this);
    --(*this);
    return temp;
}

/* Member Functions */
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

/* Static Member Functions */
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

/* Stream Insertion Operator */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
