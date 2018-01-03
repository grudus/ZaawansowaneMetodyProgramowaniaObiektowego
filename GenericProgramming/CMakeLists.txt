cmake_minimum_required(VERSION 3.9)
project(GenericProgramming)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES utils/Errorable.h utils/ErrorCodes.h  utils/NumberUtils.h utils/NumberUtils.cpp utils/VectorUtils.h
        utils/StringUtils.cpp utils/StringUtils.h
        rpn/operators.h rpn/RpnVariable.cpp rpn/RpnVariable.h rpn/RpnElemFactory.h rpn/RpnElem.h rpn/RpnOperator.cpp rpn/RpnOperator.h
        rpn/RpnNumber.cpp rpn/RpnNumber.h rpn/RpnElemFactory.cpp
        tree/Node.cpp tree/Node.h tree/Tree.cpp tree/Tree.h
        tree/RpnTreeFactory.cpp tree/RpnTreeFactory.h
        tree/RpnTreeSolver.cpp
        tree/RpnTreeSolver.h
        generic-tree/GenericTree.cpp generic-tree/GenericTree.h generic-tree/RandomRpnElemCreator.cpp generic-tree/RandomRpnElemCreator.h
        main.cpp FunctionXY.cpp FunctionXY.h FunctionFileReader.cpp FunctionFileReader.h)

add_executable(GenericProgramming ${SOURCE_FILES})