#ifndef IOMANAGER_H
#define IOMANAGER_H

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

class Main {
public:
    /** Default constructor */
    IOManager();
    /** Default destructor */
    virtual ~IOManager();

    int TextParser(std::string FilePath);

protected:
private:
};

#endif //IOMANAGER_H
