#!/bin/sh
set -e
cd $HOME
if [ ! -d "$HOME/yaml-cpp-release-0.5.2/build/"]
  wget https://github.com/jbeder/yaml-cpp/archive/release-0.5.2.tar.gz
  tar -xzvf release-0.5.2.tar.gz
  cd yaml-cpp-release-0.5.2 && mkdir build && cd build && cmake .. && make && make install
else
  echo 'Using cached directory.'
fi
