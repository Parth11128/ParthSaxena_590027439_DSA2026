#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data d;

    d.i = 10;
    printf("After assigning integer:\n");
    printf("Integer: %d\n", d.i);

    d.f = 3.14;
    printf("\nAfter assigning float:\n");
    printf("Float: %f\n", d.f);

    d.c = 'A';
    printf("\nAfter assigning character:\n");
    printf("Character: %c\n", d.c);

    printf("\nSize of union: %lu bytes\n", sizeof(d));

    return 0;
}
