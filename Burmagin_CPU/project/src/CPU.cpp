#include "../include/CPU.hpp"

namespace Virtual_M {

    void CPU::ProgramExecution(CodeFile& Code) {
        Code.Compile();
        Command* actual = Code.ActualCommand();
        while(actual != nullptr) {
            actual->Realize(stack_, rgstr_, Code);
            actual = Code.ActualCommand();
        }
    }
}