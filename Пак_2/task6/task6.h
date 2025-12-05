#pragma once

#include <stdio.h>
#include <stddef.h>

typedef struct Student {
    unsigned int id;
    char* name;
    char* surname;
    char* group;
    unsigned char* marks;
} Student;

int read_from_file(Student* table, FILE* file);
int write_to_file(Student* table, FILE* file);
int print_student(Student student, FILE* file);

void sort_by_id(Student* table);
void sort_by_name(Student* table);
void sort_by_surname(Student* table);
void sort_by_group(Student* table);
void sort_by_marks(Student* table);

Student* find_by_id(Student* table, unsigned int id, size_t len);
Student* find_by_name(Student* table, char* name, size_t len);
Student* find_by_surname(Student* table, char* surname, size_t len);
Student* find_by_group(Student* table, char* group, size_t len);

void print_menu();
