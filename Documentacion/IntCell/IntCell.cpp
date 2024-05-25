#include "IntCell.h"

// Default constructor
IntCell::IntCell(int newValue) : storedValue(newValue) {}

// Copy constructor
IntCell::IntCell(const IntCell &rhs) : storedValue(rhs.storedValue) {}

// Reference constructor
IntCell::IntCell(IntCell &&rhs) noexcept : storedValue(rhs.storedValue) {}
// Copy assignment operator
IntCell &IntCell::operator=(const IntCell &rhs) {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
    }
    return *this;
}

// Remove Move assignment operator
IntCell &IntCell::operator=(IntCell &&rhs) noexcept {
    if (this != &rhs) {
        storedValue = rhs.storedValue;
        rhs.storedValue = 0;
    }
    return *this;
}

// Overloaded assignment operator to accept only integer data
IntCell &IntCell::operator=(int rhs) {
    storedValue = rhs;
    return *this;
}

IntCell &IntCell::operator+(const IntCell &rhs) {
    storedValue = storedValue + rhs.storedValue;
    return *this;
}

IntCell &IntCell::operator+(int rhs) {
    storedValue = storedValue + rhs;
    return *this;
}

IntCell &IntCell::operator-(const IntCell &rhs) {
    storedValue = storedValue - rhs.storedValue;
    return *this;
}

IntCell &IntCell::operator-(int rhs) {
    storedValue = storedValue - rhs;
    return *this;
}

int IntCell::getValue() const {
    return storedValue;
}

void IntCell::setValue(int newValue) {
    storedValue = newValue;
}
