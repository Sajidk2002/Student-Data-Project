#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_record {
    int rollno;
    char name[20];
    float marks;
    struct student_record *next;
} SRM;

/* Function prototypes */
void add_node(SRM **ptr);
void delete_node(SRM **ptr);
void print_node(SRM *ptr);
void modify_node(SRM *ptr);
void save_file(SRM *ptr);
void read_file(SRM **ptr);
int count_node(SRM *ptr);
void sort_data(SRM *ptr);
void delete_all(SRM **ptr);
void reverse(SRM **ptr);
void save_exit(SRM *ptr);
void sort_data1(SRM *ptr);
void sort_data2(SRM *ptr);

#endif /* HEADER_H */