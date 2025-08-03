#include <stdio.h>
#include <string.h>

//Declaring functions
void addStudent(Student *list, int *count);
void displayAll(Student *list, int *count);
void searchByID(Student *list, int *count, int id);
void saveRecords(Student *list, char *filename);
void loadRecords(Student *list, int *count, char *filename);

// Definition of student structure
typedef struct {
    int id;
    char name[50];
    char gender;
    int age;
    float gpa;
} Student;
// End of definition of student structure

//Declaring variables used
int option;
Student students[100];

//Start of main function
int main() {

    // Program Menu
    printf("\nWelcome to our student record management platform!");
    printf("\nWhat would you like to do? Please pick an option from the list below.\n");
    printf("\n1. Add Student Record");
    printf("\n2. Display all records");
    printf("\n3. Search by ID");
    printf("\n4. Save to file");
    printf("\n5. Load from file");
    printf("\n0. Exit\n");

    scanf("%d", &option);

    // Switch

    switch (option) {

        case 1:
            int count = 0;
            add_student(students, &count);
            break;

        case 2:
            int count = 0;
            displayAll(students, &count);
            break;

        case 3:
            int id;
            int count = 0;
            printf("Enter student ID: ");
            scanf("%d", &id);
            searchByID(students, &count, id);
            break;
            
        case 4:
            char filename;
            printf("Enter Filename: ");
            scanf("%s", &filename);
            saveRecords(students, &filename);
            break;
            
        case 5:
            int count = 0;
            char filename;
            printf("Enter Filename: ");
            scanf("%s", &filename);
            loadRecords(students, &count, &filename);
            break;
            
        case 0:
            return 0;
            break;

        default:
            printf("\nPlease enter a valid option.\n");

    }

    return 0;
}
//End of main function


void addStudent(Student *list, int *count) {

    printf("Enter Student ID: \n");
    scanf("%d", &list[*count].id);
    printf("Enter Student Name: \n");
    scanf("%s", &list[*count].name);
    printf("Enter Student Gender (Male/Female): \n");
    scanf("%d", &list[*count].gender);
    printf("Enter Student GPA: \n");
    scanf("%f", &list[*count].gpa);

    (*count)++;

    printf("Student %s with ID %d was successfully added.\n", list[*count].name, list[*count].id);

}



void displayAll(Student *list, int *count) {

    printf("List of all students\n");    
    for (count=0; count<=100; count++) {
        printf("ID: %d  | Name: %s  |   Gender: %s  |   GPA: %f\n", list[*count].id, list[*count].name, list[*count].gender, list[*count].gpa);
    }

}



void searchByID(Student *list, int *count, int id) {
    
    int x = id - 1;
    printf("\n%d   %s  %s  %f\n", list[x].id, list[x].name, list[x].gender, list[x].gpa);

}



void saveRecords(Student *list, char *filename) {
    
    FILE *file = fopen("*filename", "a+");
    if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
    }
    // Open file for writing
    // Write formatted text to the file
    int count = 0;
    for (count=0; count<=100; count++) {
        fprintf(file, "%d   %s  %s  %f\n", list[count].id, list[count].name, list[count].gender, list[count].gpa);
    }
   
    fclose(file);

}

void loadRecords(Student *list, int *count, char *filename) {
    FILE *file = fopen(*filename, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", filename);
        return;
    }

    while (fscanf(file, "%d %s", &list[*count].id, list[*count].name) == 2) {
        (*count)++;
        if (*count >= 100) {
            printf("Maximum number of students (100) reached.\n");
            break;
        }
    }

    fclose(file);
    printf("%d students loaded from file.\n", *count);
}
