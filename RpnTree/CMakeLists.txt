cmake_minimum_required(VERSION 3.8)
project(RpnTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp utils/Errorable.h utils/ErrorCodes.h rpn/RpnElem.h rpn/RpnOperator.cpp rpn/RpnOperator.h rpn/RpnNumber.cpp rpn/RpnNumber.h tree/Node.h tree/Tree.cpp tree/Tree.h rpn/RpnVariable.cpp rpn/RpnVariable.h utils/StringUtils.cpp utils/StringUtils.h tree/RpnTreeFactory.cpp tree/RpnTreeFactory.h rpn/RpnElemFactory.cpp rpn/RpnElemFactory.h utils/NumberUtils.h utils/NumberUtils.cpp utils/VectorUtils.h tree/RpnTreeSolver.cpp tree/RpnTreeSolver.h interface/CommandLineInterface.cpp interface/CommandLineInterface.h interface/instructions/EnterInstruction.h interface/instructions/PrintInstruction.h interface/instructions/VariableInstruction.h interface/instructions/ComputeInstruction.h)
add_executable(RpnTree ${SOURCE_FILES})