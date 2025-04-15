#include "student.h"
#include <string.h>
#include <ctype.h>

/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/

// Function to clear the input buffer
void ClearInputBuffer() { 
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer only once
}

// Function to pause and clear the screen together
void pauseAndClear() {
    pauseScreen();
    clearScreen();
}

// Function to add a new student record
void addStudent(RECORD student[], int *Student_count) {
    clearScreen();

    if (*Student_count >= MAX_STUDENT_COUNT) { 
        printf("Max student limit reached. Cannot add more students.\n");
        pauseScreen();
        return;
    }

    student[*Student_count].student_id = (*Student_count + 1);

    int valid_name;
    do { // Validation for correct name input
        
        ClearInputBuffer(); 
        clearScreen(); 

        printf("Enter Student Name: ");

        fgets(student[*Student_count].name, MAX_TEXT_SIZE, stdin);
        student[*Student_count].name[strcspn(student[*Student_count].name, "\n")] = '\0'; // Remove trailing newline

        if (strlen(student[*Student_count].name) < 1) { // Checking for valid name

            clearScreen();
            printf("Name cannot be empty. Please enter a valid name.\n");
            pauseScreen();

        } else {
            valid_name = 1; // Reset valid check
            for (int i = 0; student[*Student_count].name[i] != '\0'; i++) {
                if (!(isalpha(student[*Student_count].name[i]) || student[*Student_count].name[i] == ' ' || student[*Student_count].name[i] == '\'' || student[*Student_count].name[i] == '-')) { 
                    valid_name = 0;
                    break;
                }
            }
            if (!valid_name) { // Error invalid name

                clearScreen();
                printf("Name can only contain alphabetic characters, spaces, apostrophes, or hyphens. Please enter a valid name.\n");
                pauseScreen();
            }
        }
    } while (strlen(student[*Student_count].name) < 1 || !valid_name);

    // Give options for major
    clearScreen();
    int choice_two;
    printf("What major are they pursuing: \n1. Computer Science \n2. Telecom and Network\n3. Digital Business\n");
    printf("Choose an option: ");
    scanf("%d", &choice_two);

    switch (choice_two) {
        case 1:
            strcpy(student[*Student_count].major, "Computer Science");
            break;
        case 2:
            strcpy(student[*Student_count].major, "Telecom and Network");
            break;
        case 3:
            strcpy(student[*Student_count].major, "Digital Business");
            break;                
        default:
            printf("Invalid choice. Setting major as 'Undecided'.\n");
            strcpy(student[*Student_count].major, "Undecided");
            break;
    }

    clearScreen();
    do {
        clearScreen();
        printf("Enter Student age: ");
    } while (!getValidAge(&student[*Student_count].age));

    clearScreen();
    do {
        clearScreen();
        printf("Enter Student GPA: ");
    } while (!getValidGPA(&student[*Student_count].GPA));

    clearScreen();
    printf("Student Record Added Successfully!\n");

    // Increase student count
    (*Student_count)++;

}

/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/

// Function to display all student records
void displayStudents(RECORD student[], int Student_count) {
    pauseScreen();
    clearScreen();// Then clear
    printf("\nDisplay all student records:\n\n");
    
    if (Student_count == 0) {
        printf("No student records found.\n");
    } else {
        // Table headers
        printf("%-10s %-25s %-25s %-10s %-5s\n", "ID", "Name", "Major", "Age", "GPA");
        printf("--------------------------------------------------------------------------------------------------\n");

        for (int i = 0; i < Student_count; i++) {
            printf("%-10d %-25s %-25s %-10d %-5.2f\n",
                   student[i].student_id,
                   student[i].name,
                   student[i].major,
                   student[i].age,
                   student[i].GPA);
        }
    }

}

/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/

// Function to update a student's record
void updateStudent(RECORD student[], int Student_count) {
    clearScreen();
    if (Student_count == 0) {
        printf("No student records found.\n");
        pauseScreen();
        return;
    }

    int ID, choice_three, choice_four;
    printf("Enter Student ID: ");
    scanf("%d", &ID);
    ClearInputBuffer();

    // Search for ID
    for (int i = 0; i < Student_count; i++) {
        if (ID == student[i].student_id) {
            int current_student = i;

            printf("What do you want to update about (%s): \n", student[current_student].name);
            printf("1. Name\n2. Major\n3. Age\n4. GPA\n");
            printf("Choose an option: ");
            scanf("%d", &choice_three);
            ClearInputBuffer();

            switch (choice_three) {
                case 1:
                    clearScreen();
                    printf("Previous: %s\n", student[current_student].name); //display previous stats
                    printf("Change name: ");
                    fgets(student[current_student].name, MAX_TEXT_SIZE, stdin);
                    student[current_student].name[strcspn(student[current_student].name, "\n")] = '\0'; // Remove newline
                    printf("Changed successfully\n");
                    break;

                case 2:
                    clearScreen();
                    printf("Previous: %s\n", student[current_student].major);       
                    printf("Change Major: ");
                    printf("\n1. Computer Science \n2. Telecom and Network\n3. Digital Business\n");
                    scanf("%d", &choice_four);
                    ClearInputBuffer();

                    switch (choice_four) {
                        case 1:
                            strcpy(student[current_student].major, "Computer Science"); 
                            break;
                        case 2:
                            strcpy(student[current_student].major, "Telecom and Network"); 
                            break;
                        case 3:
                            strcpy(student[current_student].major, "Digital Business"); 
                            break;                
                        default:
                            printf("Invalid choice. Setting major as 'Undecided'.\n");
                            strcpy(student[current_student].major, "Undecided");
                            break;
                    }
                    printf("Changed successfully\n");
                    break;

                case 3:
                    clearScreen();
                    do {
                        printf("Previous: %d\n", student[current_student].age);
                        printf("Enter Student age: ");
                    } while (!getValidAge(&student[current_student].age));
                    printf("Changed successfully\n");
                    break;

                case 4:
                    clearScreen();
                    do {
                        printf("Previous: %.2f\n", student[current_student].GPA);
                        printf("Enter Student GPA: ");
                    } while (!getValidGPA(&student[current_student].GPA));
                    printf("Changed successfully\n");
                    break;

                default:
                    clearScreen();
                    printf("Invalid Option\n");
                    break;
            }
            return;
        }
    }
    printf("Student ID not found.\n");

}

/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/

// Function to remove a student record
void removeStudent(RECORD student[], int *Student_count) {
    clearScreen();
    if (*Student_count == 0) {
        printf("No student records found.\n");
        pauseScreen();
        return;
    }

    int ID;
    printf("Enter Student ID to delete: ");
    scanf("%d", &ID);

    for (int i = 0; i < *Student_count; i++) {
        if (ID == student[i].student_id) {
            // Shift all records after the deleted student
            for (int j = i; j < *Student_count - 1; j++) {
                student[j] = student[j + 1];
            }
            
            (*Student_count)--;
            pauseScreen();
            printf("Student record deleted successfully.\n");

            return;
        }
    }
    printf("Student ID not found.\n");

}

/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/

// Function to get a valid age input
int getValidAge(int *age) {
    if (scanf("%d", age) == 1 && *age >= 5 && *age <= 60) {
        ClearInputBuffer(); 
        return 1; // Valid input
    }
    ClearInputBuffer(); 
    printf("Invalid age. Please enter a valid age between 5 and 60.\n");
    return 0; // Invalid input
}

/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/

// Function to get a valid GPA input
int getValidGPA(float *GPA) {
    if (scanf("%f", GPA) == 1 && *GPA >= 0 && *GPA <= 4.0) {
        ClearInputBuffer();
        return 1; // Valid input
    }
    ClearInputBuffer();
    printf("Invalid GPA. Please enter a GPA between 0 and 4.0.\n");
    return 0; // Invalid input
}

/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/

// Function to clear the screen
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // For Windows
    #else
        system("clear");  // For macOS and Linux
    #endif
}

// Function to pause the screen and wait for the user to press Enter
void pauseScreen() {
    // Portable pause screen
    printf("Press Enter to continue...");
    getchar();
}
