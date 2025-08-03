#include <stdio.h>
#include <string.h>

// Definition of student structure
typedef struct {
    int id;
    char name[50];
    char gender[10];
    int age;
    float gpa;
} Student;
// End of definition of student structure

//Declaring functions
void addStudent(Student *list, int *count);
void displayAll(Student *list, int *count);
void searchByID(Student *list, int *count, int id);
int saveRecords(Student *list, char *filename);
int loadRecords(Student *list, int *count, char *filename);


//Declaring variables used
int option;
int count = 0;
char filename[20];
Student list[100];

//Start of main function
int main() {

    printf("\nWelcome to our student record management platform!");
    printf("\nWhat would you like to do?\n");

    do {

    // Program Menu
    printf("Please pick an option from the list below.\n");
    printf("\n1. Add Student Record");
    printf("\n2. Display all records");
    printf("\n3. Search by ID");
    printf("\n4. Save to file");
    printf("\n5. Load from file");
    printf("\n0. Exit\n\n");

    scanf("%d", &option);

    // Switch

    switch (option) {

        case 1:
            
            addStudent(list, &count);
            break;

        case 2:
            
            displayAll(list, &count);
            break;

        case 3:
            int id;
            
            printf("Enter student ID: ");
            scanf("%d", &id);
            searchByID(list, &count, id);
            break;
            
        // case 4:
        //     
        //     printf("Enter Filename: ");
        //     scanf("%s", filename);
        //     saveRecords(list, &filename);
        //     break;
            
        // case 5:
        //     
        //     printf("Enter Filename: ");
        //     scanf("%s", filename);
        //     loadRecords(list, &count, &filename);
        //     break;
            
        case 0:
            return 0;
            break;

        default:
            printf("\nPlease enter a valid option.\n");

    }

} while (option != 0);

    return 0;
}
//End of main function


void addStudent(Student *list, int *count) {

    printf("Enter Student ID: \n");
    scanf("%d", &list[*count].id);
    printf("Enter Student Name: \n");
    scanf("%s", list[*count].name);
    printf("Enter Student Gender (Male/Female): \n");
    scanf("%s", list[*count].gender);
    printf("Enter Student Age: \n");
    scanf("%d", &list[*count].age);
    printf("Enter Student GPA: \n");
    scanf("%f", &list[*count].gpa);
    printf("Student %s with ID %d was successfully added.\n", list[*count].name, list[*count].id);
    (*count)++;

    

}



void displayAll(Student *list, int *count) {

    printf("List of all students\n");    
    for (int i = 0; i <= *count; i++) {
        printf("ID: %d  | Name: %s  |   Gender: %s  |   Age: %d |   GPA: %f\n", list[*count].id, list[*count].name, list[*count].gender, list[*count].age, list[*count].gpa);
    }

}



void searchByID(Student *list, int *count, int id) {
    
    for (int i = 0; i <= *count; i++) {

        if (list[i].id == id) {
            printf("\n%d  %s  %s  %d  %f\n", list[i].id, list[i].name, list[i].gender, list[i].age, list[i].gpa);
            }
    }
}



int saveRecords(Student *list, char *filename) {
    
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
    }
    // Open file for writing
    // Write formatted text to the file
    
    for (int j = 0; j <= count; j++) {
        fprintf(file, "%d   %s  %s %d  %f\n", list[count].id, list[count].name, list[count].gender, list[count].age, list[count].gpa);
    }
   
    fclose(file);
    return 0;
}

int loadRecords(Student *list, int *count, char *filename) {
    
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < *count; i++) {
        fprintf(file, "%d %s %s %d %.2f\n", list[i].id, list[i].name, list[i].gender, list[i].age, list[i].gpa);
    }

    fclose(file);
    return 0;

}
