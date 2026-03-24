#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

void search(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found at position %d\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Element does not exist\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        head = insert(head, value);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    search(head, key);

    return 0;
}
