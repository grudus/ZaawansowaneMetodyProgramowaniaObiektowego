#include "CiCanCopy.h"

CiCanCopy::CiCanCopy(): data(new std::string) {}

CiCanCopy::CiCanCopy(std::string string): data(new std::string) {
    *data = string;
}

CiCanCopy::CiCanCopy(const CiCanCopy &ref): data(new std::string) {
    *data = *ref.data;
}

CiCanCopy &CiCanCopy::operator=(const CiCanCopy &ref) {
    *data = *ref.data;
    return *this;
}

CiCanCopy &CiCanCopy::operator=(std::string string) {
    *data = string;
    return *this;
}

CiCanCopy CiCanCopy::operator+(const CiCanCopy &other) {
    return CiCanCopy(*data + *other.data);
}

void CiCanCopy::print() {
    std::cout << *data << std::endl;
}

CiCanCopy::~CiCanCopy() {
    delete data;
}
