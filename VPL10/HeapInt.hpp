#ifndef HEAPINT_HPP
#define HEAPINT_HPP

#include <iostream>

class HeapInt {
private: 
    int *origin;

public:
    HeapInt();
    HeapInt(int received);
    HeapInt(const HeapInt &received);

    HeapInt& operator=(int received);
    HeapInt& operator=(const HeapInt &received);
    HeapInt operator+(const HeapInt &received) const;
    HeapInt operator-(const HeapInt &received) const;
    bool operator==(const HeapInt &received) const;

    friend std::istream& operator>>(std::istream &in, HeapInt &object);
    friend std::ostream& operator<<(std::ostream &out, const HeapInt &object);

    ~HeapInt();
};

#endif