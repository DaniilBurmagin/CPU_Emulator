#pragma once
#include "Parser.hpp"
#include "CPU.hpp"

class Runner {
public:
    void run(const std::string& path) {
        Virtual_M::Parser parser;
        Virtual_M::CPU proc;
        Virtual_M::CodeFile code = parser.ParseCode(path);
        proc.ProgramExecution(code);
    };
};
