#pragma once
#include <string>
#include <map>
#include "Stack.hpp"

namespace Virtual_M {
    class CodeFile;

    class Command {
    public:
        virtual void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) = 0;
        virtual void AddArg(const std::string& arg) {}
        virtual bool NeedArg() { return false; }
    };

    class BEGIN : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override {};
    };

    class END : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override {};
    };

    class PUSH : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
        virtual void AddArg(const std::string& arg) override;
        virtual bool NeedArg() override { return true; }
    private:
        int data;
    };

    class PUSHR : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
        virtual void AddArg(const std::string& arg) override;
        virtual bool NeedArg() override { return true; }
    protected:
        std::string regist;
    };

    class POP : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    class POPR : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
        virtual void AddArg(const std::string& arg) override;
        virtual bool NeedArg() override { return true; }
    protected:
        std::string regist;
    };

    class IN : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    class OUT : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    class ADD : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    class SUB : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    class MUL : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    class DIV : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    class JMP : public Command {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
        virtual void AddArg(const std::string& arg) override;
        virtual bool NeedArg() override { return true; }
    protected:
        std::string label;
    };

    class JEQ : public JMP {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    class JNE : public JMP {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    class JA : public JMP {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    class JAE : public JMP {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    class JB : public JMP {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    class JBE : public JMP {
    public:
        void Realize(Stack<int>& stack, std::map<std::string, int>& list, CodeFile& code) override;
    };

    Command* CommandName(const std::string& str);
}