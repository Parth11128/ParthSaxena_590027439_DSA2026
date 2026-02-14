#include <stdio.h>

struct SampleStruct {
    int a;
    float b;
    char c;
};

union SampleUnion {
    int a;
    float b;
    char c;
};

int main() {

    struct SampleStruct s;
    union SampleUnion u;

    printf("Size of Structure: %lu bytes\n", sizeof(s));
    printf("Size of Union: %lu bytes\n", sizeof(u));

    return 0;
}
