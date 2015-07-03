#include "Main.h"
#include "TestConfig.h"

#include <iostream>

Main::Main() {

}

Main::~Main() {

}

int Main::printout() {
    std::cout << Test_VERSION_MAJOR << '.' << Test_VERSION_MINOR << std::endl;

    return 0;
}

int main() {
    int status;

    status = Main::printout();

    return status;
}
