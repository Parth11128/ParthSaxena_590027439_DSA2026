#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);

    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted element: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;

    return head;
}

struct Node* deleteAfterNode(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Deletion not possible.\n");
        return head;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted element: %d\n", nodeToDelete->data);
    free(nodeToDelete);

    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, key, n;

    printf("Enter number of elements to create list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Delete After Given Node\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = deleteFromBeginning(head);
                break;

            case 2:
                head = deleteFromEnd(head);
                break;

            case 3:
                printf("Enter node value after which to delete: ");
                scanf("%d", &key);
                head = deleteAfterNode(head, key);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
