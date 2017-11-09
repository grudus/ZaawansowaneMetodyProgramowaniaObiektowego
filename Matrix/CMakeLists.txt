cmake_minimum_required(VERSION 3.8)
project(Matrix)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SparseCell.cpp SparseCell.h SpareMatrix.cpp SpareMatrix.h UserInterface.cpp UserInterface.h instructions/Instruction.h instructions/AddInstruction.cpp instructions/AddInstruction.h instructions/ListInstruction.cpp instructions/ListInstruction.h instructions/DeleteInstruction.cpp instructions/DeleteInstruction.h instructions/DeleteAllInstruction.cpp instructions/DeleteAllInstruction.h instructions/DefInstruction.cpp instructions/DefInstruction.h instructions/PrintInstruction.cpp instructions/PrintInstruction.h instructions/CopyInstruction.cpp instructions/CopyInstruction.h instructions/RenameInstruction.cpp instructions/RenameInstruction.h instructions/Instruction.cpp instructions/ReverseInstruction.cpp instructions/ReverseInstruction.h instructions/MultipleInstruction.cpp instructions/MultipleInstruction.h)
add_executable(Matrix ${SOURCE_FILES})