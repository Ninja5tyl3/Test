#include "../include/Main.h"
#include "../include/TestConfig.h"

#include <iostream>

Main::Main() {

}

Main::~Main() {

}

int printout() {
    std::cout << Test_VERSION_MAJOR << '.' << Test_VERSION_MINOR << '.' << Test_VERSION_PATCH << std::endl;

    return 0;
}

int main() {
    int status;

    status = printout();

    return status;
}
