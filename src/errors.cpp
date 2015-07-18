#include "../include/errors.h"

#include <iostream>
#include <cstdlib>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}
