#include "Parser.hpp"


namespace Virtual_M {

CodeFile Parser::ParseCode(std::string path){
    std::ifstream file(path);
    CodeFile code;

    std::string token;
    while (file >> token) {
        if (token.ends_with(":")) {
            token.pop_back();
            code.NewLabel(token);
        } else {
            Command* cmd = CommandName(token);
            code.NewCommand(cmd);
            if (cmd->NeedArg()) {
                file >> token;
                cmd->AddArg(token);
            }
        }
    }

    return code;
}

}