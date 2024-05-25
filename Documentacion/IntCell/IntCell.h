#ifndef INTCELL_H
#define INTCELL_H

class IntCell {
public:
    IntCell() = default;//Default constructor
    IntCell(int newValue = 0);//Constructor int
    IntCell(const IntCell &rhs);// Copy constructor
    IntCell(IntCell &&rhs) noexcept;//Reference constructor
    ~IntCell() = default;//Destructor

    IntCell &operator=(const IntCell &rhs);
    IntCell &operator=(IntCell &&rhs) noexcept;

    // Overloaded assignment operator to accept primitive int
    IntCell &operator=(int rhs);

    //Overload the add operator
    IntCell &operator+(const IntCell &rhs);

    // Overload the add operator to accept primitive int
    IntCell &operator+(int rhs);

    // Overload the subtract operator on both IntCell and primitive int
    IntCell &operator-(const IntCell &rhs);
    IntCell &operator-(int rhs);

    int getValue() const;

    void setValue(int newValue);

private:
    int storedValue;
};

#endif  // INTCELL_H
