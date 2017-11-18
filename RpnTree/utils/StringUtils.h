#ifndef RPNTREE_STRINGUTILS_H
#define RPNTREE_STRINGUTILS_H

#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

std::vector<std::string> split(const std::string &s, char delim);


template<typename Out>
void split(const std::string &s, char delim, Out result);

void ltrim(std::string &s);

#endif //RPNTREE_STRINGUTILS_H
