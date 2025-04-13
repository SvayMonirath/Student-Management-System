#include"student.h"

void addStudent(RECORD student[], int *Student_count) {
    clearScreen();

    if (*Student_count >= MAX_STUDENT_COUNT) { 
        printf("Max student limit reached. Cannot add more students.\n");
        pauseScreen();
        return;
    }

    student[*Student_count].student_id = (*Student_count+1)*100;

    printf("Enter Student Name: ");
    getchar();
    fgets(student[*Student_count].name, MAX_TEXT_SIZE, stdin);
    
    student[*Student_count].name[strcspn(student[*Student_count].name, "\n")] = '\0';


    // Give options for major
    clearScreen();
    int choice_two;
    printf("What major are they pursuing: \n1. Computer Science \n2. Telecom and Network\n3. Digital Business\n");
    printf("Choose an option: ");
    scanf("%d", &choice_two);

    switch (choice_two) {
        case 1:
            strcpy(student[*Student_count].major, "Computer Science"); break;
        case 2:
            strcpy(student[*Student_count].major, "Telecom and Network"); break;
        case 3:
            strcpy(student[*Student_count].major, "Digital Business"); break;                
        default:
            printf("Invalid choice. Setting major as 'Undecided'.\n");
            strcpy(student[*Student_count].major, "Undecided");
            break;
    }

    clearScreen();
    do {
        printf("Enter Student age: ");
        scanf("%d", &student[*Student_count].age);
    } while (student[*Student_count].age < 5 || student[*Student_count].age > 60);

    clearScreen();
    do {
        printf("Enter Student GPA: ");
        scanf("%f", &student[*Student_count].GPA);
    } while (student[*Student_count].GPA < 0 || student[*Student_count].GPA > 4.0);

    clearScreen();
    printf("Student Record Added Successfully!\n");

    // Increase student count
    (*Student_count)++;
    pauseScreen();
}

void displayStudents(RECORD student[], int Student_count) {
    clearScreen();
    printf("Display all student records:\n\n");

    if (Student_count == 0) {
        printf("No student records found.\n");
    } else {
        // Table headers
        printf("%-10s %-25s %-25s %-10s %-5s\n", "ID", "Name", "Major", "Age", "GPA");
        printf("--------------------------------------------------------------------------------\n");

        for (int i = 0; i < Student_count; i++) {
            printf("%-10d %-25s %-25s %-10d %-5.2f\n",
                   student[i].student_id,
                   student[i].name,
                   student[i].major,
                   student[i].age,
                   student[i].GPA);
        }
    }
    pauseScreen();
}

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

    // Search for ID
    for (int i = 0; i < Student_count; i++) {
        if (ID == student[i].student_id) {
            int current_student = i;

            printf("What do you want to update about (%s): \n",student[current_student].name);
            printf("1. Name\n2. Major\n3. Age\n4. GPA\n");
            printf("Choose an option: ");
            scanf("%d", &choice_three);

            switch (choice_three) {
                case 1:
                    clearScreen();
                    printf("Change name: ");
                    scanf("%s", student[current_student].name);
                    printf("Changed successfully\n");
                    pauseScreen();
                    break;

                case 2:
                    clearScreen();            
                    printf("Change Major: ");
                    printf("\n1. Computer Science \n2. Telecom and Network\n3. Digital Business\n");
                    scanf("%d", &choice_four);

                    switch (choice_four) {
                        case 1:
                            strcpy(student[current_student].major, "Computer Science"); break;
                        case 2:
                            strcpy(student[current_student].major, "Telecom and Network"); break;
                        case 3:
                            strcpy(student[current_student].major, "Digital Business"); break;                
                        default:
                            printf("Invalid choice. Setting major as 'Undecided'.\n");
                            strcpy(student[current_student].major, "Undecided");
                            break;
                    }
                    printf("Changed successfully\n");
                    pauseScreen();
                    break;

                case 3:
                    clearScreen();
                    do {
                        printf("Enter Student age: ");
                        scanf("%d", &student[current_student].age);
                    } while (student[current_student].age < 5 || student[current_student].age > 60);
                    printf("Changed successfully\n");
                    pauseScreen();
                    break;

                case 4:
                    clearScreen();
                    do {
                        printf("Enter Student GPA: ");
                        scanf("%f", &student[current_student].GPA);
                    } while (student[current_student].GPA < 0 || student[current_student].GPA > 4.0);
                    printf("Changed successfully\n");
                    pauseScreen();
                    break;

                default:
                    clearScreen();
                    printf("Invalid Option\n");
                    pauseScreen();
                    break;
            }
            return;
        }
    }
    printf("Student ID not found.\n");
    pauseScreen();
}

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
            printf("Student record deleted successfully.\n");
            pauseScreen();
            return;
        }
    }
    printf("Student ID not found.\n");
    pauseScreen();
}

int DisplayChoice() {
        int choice_one;
        printf("Student Management System: \n");
        printf("1. Add student record\n");
        printf("2. Display student records\n");
        printf("3. Update student record\n");
        printf("4. Remove student record\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice_one);

        return choice_one;
}

void clearScreen() {
    system("cls");
}

void pauseScreen() {
    // Portable pause screen
    printf("Press Enter to continue...");
    getchar();
    getchar();
}