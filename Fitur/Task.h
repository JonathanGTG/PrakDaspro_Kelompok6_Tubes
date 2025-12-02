#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define BLUE  "\033[34m"
#define RESET "\033[0m"

#define FILE_TUGAS "DataTugas.txt"

typedef struct {
    char matkul[30];
    char deadline[15];
    char status[10];
} Tugas;

static inline void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void tambahTugas();
void cariTugas();
void timeline();
void editTugas();
void hapusTugas();
void statistikTugas();
int adaTugasDone();
void games();
void keluarprogram();

#endif
