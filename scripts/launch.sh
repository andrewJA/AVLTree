cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
cmake --build _build --target install
./_install/bin/tree-cli 8 11 3 6 9 21 13 16 4 1 15