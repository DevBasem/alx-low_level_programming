#!/bin/bash
wget -O /tmp/libgiga.so https://github.com/DevBasem/holbertonschool-low_level_programming/raw/master/0x17-dynamic_libraries/libgiga.so
export LD_PRELOAD=/tmp/libgiga.so
