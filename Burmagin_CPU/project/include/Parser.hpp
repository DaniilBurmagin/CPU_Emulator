#pragma once
#include <string>
#include <fstream>
#include <unordered_map>
#include "CodeFile.hpp"


namespace Virtual_M {

class Parser {
public:
    CodeFile ParseCode(std::string path);
};

}