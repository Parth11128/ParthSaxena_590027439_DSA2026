#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n, i, j;
    struct Student *s, temp;

    printf("Enter number of students: ");
    scanf("%d", &n);

    s = (struct Student *)malloc(n * sizeof(struct Student));
    if (s == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", s[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &s[i].marks);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i].marks < s[j].marks) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("\n--- Students Sorted by Marks (High to Low) ---\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s, Marks: %d\n", s[i].name, s[i].marks);
    }

    free(s);

    return 0;
}
