#!/bin/bash
wget -O ./temp/libgiga.so https://github.com/DevBasem/alx-low_level_programming/raw/main/0x18-dynamic_libraries/libgiga.so
export LD_PRELOAD=./temp/libgiga.so
