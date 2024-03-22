#include "../include/CodeFile.hpp"


namespace Virtual_M {
    void CodeFile::NewCommand(Command* cmd) {
        commands_.push_back(std::shared_ptr<Command>(cmd));
    }

    void CodeFile::NewLabel(const std::string& lbl) {
        labels_.insert({lbl, commands_.size()});
    }

    void CodeFile::Compile() {
        if (flag) {
            return;
        }

        size_t first_command = 0;
        bool begin = false;
        bool end = false;
        for (size_t i = 0; i < commands_.size(); i++) {
            Command* cur = commands_[i].get();
            if (typeid(*cur) == typeid(BEGIN)) {
                begin = true;
                first_command = i;
            }
            if (typeid(*cur) == typeid(END)) {
                end = true;
            }
        }

        if (begin == 0 || end == 0) {
            return; // переделать
        }

        flag = true;
        StartIndex = first_command;
        CurIndex = first_command;
    }

    Command* CodeFile::ActualCommand() {
        if (CurIndex >= commands_.size()) {
            return nullptr;
        }
        Command* actual = commands_.at(CurIndex++).get();
        return actual;
    }

    void CodeFile::IndexJump(size_t index) {
        CurIndex = index;
    }

    void CodeFile::LabelJump(const std::string& lbl) {
        CurIndex = labels_[lbl];
    }


}