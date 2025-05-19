#include <stdio.h>
#include <string.h>

#define SIZE 3

typedef struct {
    char surname[30];
    char name[30];
    char group[20];
    float scholarship;
} Student;

int main() {
    Student students[SIZE] = {
        {"Ш", "О", "КН", 1800.00},
        {"І", "П", "КН", 1950.00},
        {"К", "Т", "КН", 2000.00}
    };

    char searchSurname[30];
    float newScholarship;
    int found = 0;

    printf("Enter the last name of the student whose scholarship you want to change: ");
    scanf("%s", searchSurname);

    for (int i = 0; i < SIZE; i++) {
        if (strcmp(students[i].surname, searchSurname) == 0) {
            printf("Current scholarship: %.2f UAH.\n", students[i].scholarship);
            printf("Enter a new scholarship: ");
            scanf("%f", &newScholarship);
            students[i].scholarship = newScholarship;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student '%s' didn't find.\n", searchSurname);
    }

    printf("\nUpdated student database:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%s %s, group: %s, scholarship: %.2f UAH.\n",
               students[i].surname, students[i].name,
               students[i].group, students[i].scholarship);
    }

    return 0;
}
