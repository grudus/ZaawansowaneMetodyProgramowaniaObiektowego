cmake_minimum_required(VERSION 3.9)
project(GenericProgramming)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp  rpn/operators.h utils/Errorable.h utils/ErrorCodes.h rpn/RpnElem.h rpn/RpnOperator.cpp rpn/RpnOperator.h
        rpn/RpnNumber.cpp rpn/RpnNumber.h tree/Node.h tree/Tree.cpp tree/Tree.h rpn/RpnVariable.cpp rpn/RpnVariable.h
        utils/StringUtils.cpp utils/StringUtils.h tree/RpnTreeFactory.cpp tree/RpnTreeFactory.h rpn/RpnElemFactory.cpp
        rpn/RpnElemFactory.h utils/NumberUtils.h utils/NumberUtils.cpp utils/VectorUtils.h tree/RpnTreeSolver.cpp
        tree/RpnTreeSolver.h
        tree/Node.cpp generic-tree/GenericTree.cpp generic-tree/GenericTree.h generic-tree/RandomRpnElemCreator.cpp generic-tree/RandomRpnElemCreator.h)

add_executable(GenericProgramming ${SOURCE_FILES})