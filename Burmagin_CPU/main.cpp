#include <iostream>
#include "Runner.h"


int main(int argc, char *argv[]) {
    std::string path = "../programs/fac";
    if (argc > 1)
        path = argv[1];

    Runner runner;
    runner.run(path);
    return 0;
}
