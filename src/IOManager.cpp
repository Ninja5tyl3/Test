#include "../include/IOManager.h"

IOManager::IOManager() {

}

IOManager::~IOManager() {

}

int IOManager::TextParser(std::string FilePath) {
  int status;
  status = 0;
  return status;
}

bool IOManager::fileCheck(const std::string &name) {
  struct stat buffer;
  return (stat(name.c_str(), &buffer) == 0);
}
