#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int main() {
    int number = 1234, i = 0;
    do {
        number /= 10;
        i += 1;
    } while (number > 0);
    printf("%d", i);

    return 0;
}
