#include <iostream>

// Among other tings, iostream instantiates  cin, cout, and cerr.
// Analogous to stdin, stdout, and stderr from C, but they are instances
// of class instream and onstream.

int main(int argc, char *argv[]) {

    //std is the standard name space. C++ has namespaces.

    //std::cout << "Hello world!\n";
    std::cout << "Hello world!" << std::endl;

    return 0;
}