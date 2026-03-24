#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void displayPolynomial() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("Polynomial is empty!\n");
        return;
    }

    printf("Polynomial: ");
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

double evaluatePolynomial(double x) {
    struct Node* temp = head;
    double result = 0;

    while (temp != NULL) {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }

    return result;
}

int main() {
    int n, coeff, exp;
    double x;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertTerm(coeff, exp);
    }

    displayPolynomial();

    printf("Enter value of x: ");
    scanf("%lf", &x);

    double result = evaluatePolynomial(x);
    printf("Polynomial Value at x = %.2lf is %.2lf\n", x, result);

    return 0;
}
