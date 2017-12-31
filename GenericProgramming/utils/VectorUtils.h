
#ifndef RPNTREE_VECTORUTILS_H
#define RPNTREE_VECTORUTILS_H

#include <vector>

template<class T>
std::vector<T> tail(std::vector<T> vector) {
    return std::vector<T>(vector.begin() + 1, vector.end());
}


#endif //RPNTREE_VECTORUTILS_H
