#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    struct Student *next;
};

struct Student *head = NULL;

void addRecord() {
    struct Student *newNode, *temp;

    newNode = (struct Student*)malloc(sizeof(struct Student));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Name: ");
    scanf("%s", newNode->name);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Record Added Successfully!\n");
}

void displayRecords() {
    struct Student *temp = head;

    if (head == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

void deleteRecord() {
    int id;
    struct Student *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("No records to delete!\n");
        return;
    }

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Record Deleted Successfully!\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Record not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Record Deleted Successfully!\n");
}

void freeMemory() {
    struct Student *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Memory Freed Successfully!\n");
}

int main() {
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: deleteRecord(); break;
            case 4: freeMemory(); break;
            default: printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}
