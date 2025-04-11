
//future improvement

// Adding file handling so records are saved/loaded.

// Improving input validation.

// Enhancing the UI/UX (like formatted tables).

// Adding search by name or major.

// Converting to use dynamic memory (with malloc/free).

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"

int main(void) {
    // Initialize struct
    RECORD student[MAX_STUDENT_COUNT];

    int choice_one, Student_count = 3;

    // Add default students
    strcpy(student[0].name, "Svay Monirath");
    strcpy(student[0].major, "Computer Science");
    student[0].age = 20;
    student[0].GPA = 3.6;
    student[0].student_id = 100;

    strcpy(student[1].name, "SokHeng Mengly");
    strcpy(student[1].major, "Telecom and Network");
    student[1].age = 18;
    student[1].GPA = 3.8;
    student[1].student_id = 200;

    strcpy(student[2].name, "Vann Sokha");
    strcpy(student[2].major, "Digital Business");
    student[2].age = 19;
    student[2].GPA = 3.4;
    student[2].student_id = 300;

    // Start menu
    do {
        clearScreen();
        printf("Student Management System: \n");
        printf("1. Add student record\n");
        printf("2. Display student records\n");
        printf("3. Update student record\n");
        printf("4. Remove student record\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice_one);

        switch (choice_one) {
            case 1: 
                addStudent(student, &Student_count);
                break;
            case 2: 
                displayStudents(student, Student_count);
                break;
            case 3:
                updateStudent(student, Student_count);
                break;
            case 4:
                removeStudent(student, &Student_count);
                break;
            case 5:
                break;
            default:
                printf("Invalid option. Please try again.\n");
                pauseScreen();
                break;
        }
    } while (choice_one != 5);

    return 0;
}
