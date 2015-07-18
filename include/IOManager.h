#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sys/stat.h>

class Main {
public:
    /** Default constructor */
    IOManager();
    /** Default destructor */
    virtual ~IOManager();

    int TextParser(std::string FilePath);

    bool fileCheck(const std::string& name);

protected:
private:
};

#endif //IOMANAGER_H
