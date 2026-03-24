#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(struct Node* head, int n) {
    int value;
    struct Node *newNode, *temp;

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
        }
    }
    return head;
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return head;
    }

    temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;

    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return head;
    }

    temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *temp = head, *last = head;

    if (head->next == head) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        return NULL;
    }

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    printf("Deleted element: %d\n", temp->data);
    free(temp);

    return head;
}

struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *temp = head, *prev = NULL;

    if (head->next == head) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        return NULL;
    }

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    printf("Deleted element: %d\n", temp->data);
    free(temp);

    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    int count = 0;

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    } while (temp != head);

    printf("(Back to Head)\n");
    printf("Total nodes: %d\n", count);
}

int main() {
    struct Node* head = NULL;
    int choice, n, value;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Display & Count\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                head = createList(head, n);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;

            case 4:
                head = deleteFromBeginning(head);
                break;

            case 5:
                head = deleteFromEnd(head);
                break;

            case 6:
                display(head);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}
