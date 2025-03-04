#include <iostream>

void swap_c(int *x, int *y) {
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(int argc, char *argv[]) {

    int i, j;

    i = 0, j = 1;

    std::cout << i << " " << j << std::endl;

    swap_c(&i, &j);
    
    std::cout << i << " " << j << std::endl;

    swap_c(&i, &j);

    std::cout << i << " " << j << std::endl;

    swap_c(&i, &j);
}

// void swap_cpp(int &x, int &y) {
//     int tmp;

//     tmp = x;
//     x = y;
//     y = tmp;
// }

// int main(int argc, char *argv[]) {

//     int i, j;

//     i = 0, j = 1;

//     std::cout << i << " " << j << std::endl;

//     swap_cpp(i, j);
    
//     std::cout << i << " " << j << std::endl;

//     swap_cpp(i, j);

//     std::cout << i << " " << j << std::endl;

//     swap_cpp(i, j);
// }