#ifndef STUDENT_H
#define STUDENT_H


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_TEXT_SIZE 45
#define MAX_STUDENT_COUNT 30

// Declare struct
typedef struct {
    char name[MAX_TEXT_SIZE];
    char major[MAX_TEXT_SIZE];
    int age;
    float GPA;
    int student_id;
} RECORD;

// Function prototypes
void addStudent(RECORD student[], int *Student_count);
void displayStudents(RECORD student[], int Student_count);
void updateStudent(RECORD student[], int Student_count);
void removeStudent(RECORD student[], int *Student_count);
void clearScreen();
void pauseScreen();

#endif