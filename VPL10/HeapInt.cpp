#include <iostream>
#include "HeapInt.hpp"

HeapInt::HeapInt() {
    this->origin = new int(0);
}

HeapInt::HeapInt(int received){
    this->origin = new int(received);
}
HeapInt::HeapInt(const HeapInt &received){
    this->origin = new int(*received.origin);
}

HeapInt& HeapInt::operator=(int received) {
    *this->origin = received;
    return *this;
}

HeapInt& HeapInt::operator=(const HeapInt &received){
    if(this != &received) {
        *this->origin = *received.origin;
    }
    return *this;
}

HeapInt HeapInt::operator+(const HeapInt &received) const {
    return HeapInt(*this->origin + *received.origin);
}

HeapInt HeapInt::operator-(const HeapInt &received) const {
    return HeapInt(*this->origin - *received.origin);
}

bool HeapInt::operator==(const HeapInt &received) const {
    return *this->origin == *received.origin;
}

std::istream& operator>>(std::istream &in, HeapInt &object) {
    in >> *object.origin;
    return in;
}

std::ostream& operator<<(std::ostream &out, const HeapInt &object) {
    out << *object.origin;
    return out;
}

HeapInt::~HeapInt() {
    delete this->origin;
}