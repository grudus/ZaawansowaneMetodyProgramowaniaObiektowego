#include "RpnBinaryTreeFactory.h"

Tree *RpnBinaryTreeFactory::create(std::vector<std::string> expressions) const {
    std::vector<RpnElem *> elems;

    std::transform(expressions.begin(), expressions.end(), std::back_inserter(elems),
                   [](std::string elem) -> RpnElem* { return RpnElemFactory().create(elem); });

    return nullptr;
}
