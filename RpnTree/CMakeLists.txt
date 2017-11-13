cmake_minimum_required(VERSION 3.8)
project(RpnTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp utils/ErrorableValue.h utils/ErrorCodes.h rpn/RpnElem.h rpn/RpnOperator.cpp rpn/RpnOperator.h rpn/RpnNumber.cpp rpn/RpnNumber.h tree/Node.h tree/Tree.cpp tree/Tree.h rpn/RpnVariable.cpp rpn/RpnVariable.h utils/StringUtils.cpp utils/StringUtils.h tree/RpnBinaryTreeFactory.cpp tree/RpnBinaryTreeFactory.h)
add_executable(RpnTree ${SOURCE_FILES})