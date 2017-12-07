#include <string>
#include <iostream>

class CiCanCopy {
public:
    CiCanCopy();
    explicit CiCanCopy(std::string string);

    CiCanCopy(const CiCanCopy& ref);

    CiCanCopy& operator=(const CiCanCopy& ref);

    CiCanCopy& operator=(std::string string);

    CiCanCopy operator+(const CiCanCopy& other);

    void print();

    ~CiCanCopy();

private:
    std::string *data;
};
