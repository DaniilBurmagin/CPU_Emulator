#pragma once
#include "Stack.hpp"
#include "CodeFile.hpp"
#include <map>
#include <iostream>

namespace Virtual_M {
    class CPU {
    private:
        Stack<int> stack_;
        std::map<std::string, int> rgstr_;
        CodeFile current_;
    public:
        void ProgramExecution(CodeFile& Code);
    };
}