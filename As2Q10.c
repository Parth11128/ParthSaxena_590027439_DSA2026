#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student* next;
};

struct Student* head = NULL;

struct Student* createNode(int roll, char name[], float marks) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->marks = marks;
    newNode->next = NULL;
    return newNode;
}

void insertStudent(int roll, char name[], float marks) {
    struct Student* newNode = createNode(roll, name, marks);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Student* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void deleteStudent(int roll) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Student *temp = head, *prev = NULL;

    if (temp != NULL && temp->roll == roll) {
        head = temp->next;
        free(temp);
        printf("Record deleted successfully.\n");
        return;
    }

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Record not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Record deleted successfully.\n");
}

void searchStudent(int roll) {
    struct Student* temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Record Found:\n");
            printf("Roll No: %d\n", temp->roll);
            printf("Name   : %s\n", temp->name);
            printf("Marks  : %.2f\n", temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Record not found!\n");
}

void displayStudents() {
    struct Student* temp = head;

    if (temp == NULL) {
        printf("No records available.\n");
        return;
    }

    printf("\nStudent Records:\n");
    while (temp != NULL) {
        printf("Roll No: %d | Name: %s | Marks: %.2f\n",
               temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}

int main() {
    int choice, roll;
    char name[50];
    float marks;

    while (1) {
        printf("\n--- Student Record Menu ---\n");
        printf("1. Insert Record\n");
        printf("2. Delete Record\n");
        printf("3. Search Record\n");
        printf("4. Display Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll No: ");
                scanf("%d", &roll);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Marks: ");
                scanf("%f", &marks);
                insertStudent(roll, name, marks);
                break;

            case 2:
                printf("Enter Roll No to delete: ");
                scanf("%d", &roll);
                deleteStudent(roll);
                break;

            case 3:
                printf("Enter Roll No to search: ");
                scanf("%d", &roll);
                searchStudent(roll);
                break;

            case 4:
                displayStudents();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
