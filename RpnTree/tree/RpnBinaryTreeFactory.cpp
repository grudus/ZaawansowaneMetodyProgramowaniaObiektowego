
#include "RpnBinaryTreeFactory.h"

Tree *RpnBinaryTreeFactory::create(std::vector<std::string> expressions) const {
    return new Tree(nullptr);
}
