#include <stdio.h>
#include <string.h>

// Definition of student structure
typedef struct {
    int id;
    char name[48];
    char gender[12];
    int age;
    float gpa;
} Student;
// End of definition of student structure

// Declaring functions
void addStudent(Student *list, int *count);
void displayAll(Student *list, int *count);
void searchByID(Student *list, int *count, int id);
int saveRecords(Student *list, int *count, char *filename);
int loadRecords(Student *list, int *count, char *filename);
// End of function declarations


//Declaring variables used
int option;
int count = 0;
char filename[24];
Student list[100];
// End of variable declarations

//Start of main function
int main() {

    // Welcome messaging
    printf("\nWelcome to our student record management platform!");
    printf("\nWhat would you like to do?\n");

    // Program Menu
    do {
    
    printf("\nPlease pick an option from the list below.\n");
    printf("\n1. Add Student Record");
    printf("\n2. Display all records");
    printf("\n3. Search by ID");
    printf("\n4. Save to file");
    printf("\n5. Load from file");
    printf("\n0. Exit\n\n");
    // End of program menu

    scanf("%d", &option); // save user input as option

    // Analyze user input and respond accordingly
    switch (option) {

        case 1:
            
            addStudent(list, &count); // Load addStudent function
            break;

        case 2:
            
            displayAll(list, &count); // Load displayAll function
            break;

        case 3:

            int id;    
            printf("\nEnter student ID: "); 
            scanf("%d", &id); // Obtain student ID from user
            searchByID(list, &count, id); // Load searchByID function
            break;
            
        case 4:
            
            printf("\nEnter Filename: ");
            scanf("%s", filename); // Obtain file name to save records into
            saveRecords(list, &count, filename); // Load saveRecords function
            break;
            
        case 5:
            
            printf("\nEnter Filename: ");
            scanf("%s", filename); // Obtain file name to load records from
            loadRecords(list, &count, filename); // Load loadRecords function
            break;
            
        case 0:
            return 0; // Exit the program if user picks this option
            break;

        default:
            printf("\nPlease enter a valid option.\n");

    }

} while (option != 0); // Ensures program keeps running unless use decides to exit program

    return 0;
}
//End of main function

// Start of addStudent function definition
void addStudent(Student *list, int *count) {

    printf("\nEnter Student ID: \n");
    scanf("%d", &list[*count].id); // save student ID 
    printf("\nEnter Student Name: \n");
    scanf("%s", list[*count].name); // save student name
    printf("\nEnter Student Gender (Male/Female): \n");
    scanf("%s", list[*count].gender); // save student gender
    printf("\nEnter Student Age: \n");
    scanf("%d", &list[*count].age); // save student age
    printf("\nEnter Student GPA: \n");
    scanf("%f", &list[*count].gpa); // save student gpa
    // Print success message for user feedback
    printf("ID: %d  |  Name: %s  |  Gender: %s  |   Age: %d  |  GPA: %.2f was successfully added.\n", list[*count].id, list[*count].name, list[*count].gender, list[*count].age, list[*count].gpa);
    (*count)++;

}
// End of addStudent function definition

// Start of displayAll function definition
void displayAll(Student *list, int *count) {

    printf("\nList of all students\n");    
    // Loop to go through current list of recently added students
    for (int i = 0; i < *count; i++) {
        // Print each student line by line
        printf("ID: %d  | Name: %s  |   Gender: %s  |   Age: %d |   GPA: %.2f\n", list[i].id, list[i].name, list[i].gender, list[i].age, list[i].gpa);
    }

}
// End of displayAll function definition

// Start of of searchByID function definition
void searchByID(Student *list, int *count, int id) {
    
    // Loops through the entire list of recently added students
    for (int i = 0; i <= *count; i++) {
        // Check if student ID being searched for is in the current student list
        if (list[i].id == id) {
            // Print student information if student ID is found
            printf("\nID: %d    |   Name: %s    |   Gender: %s  |   Age: %d   |   GPA: %.2f\n", list[i].id, list[i].name, list[i].gender, list[i].age, list[i].gpa);
            }
    }
}
// End of searchByID function definition

// Start of saveRecords function definition
int saveRecords(Student *list, int *count, char *filename) {
    
    FILE *records = fopen(filename, "a+"); // Opens file with appending permission, also creates file if file doesn't exist
    // Verify if file exist
    if (records == NULL) {
        printf("\nThere was an error opening file!\n"); // Output message if there was an error
        return 1;
    }
   
    // Loads through the current student list
    for (int i = 0; i < *count; i++) {
        // Prints every student record into file
        fprintf(records, "ID: %d   |   Name: %s    |   Gender: %s  |   Age: %d    |   GPA: %.2f\n", list[i].id, list[i].name, list[i].gender, list[i].age, list[i].gpa);
    }
   
    fclose(records); // Close file after writing to it
    return 0;
}
// End of saveRecords function definition

// Start of loadRecords function definition
int loadRecords(Student *list, int *count, char *filename) {
    
    FILE *records = fopen(filename, "r"); // Opens file with reading permission

    if (records == NULL) {
        printf("\n There was an Error opening file!\n"); // Output message if there was an error or file doesn't exist
        return 1;
    }

    char line[100]; // Define a variable to save a complete line within the file
        // Loop through each line within the file
        while (fgets(line, sizeof(line), records)) {
        printf("%s", line); // Print each line on the console
    }

    fclose(records); // Close the file after reading its content

    return 0;

}
// End of loadRecords function definition 