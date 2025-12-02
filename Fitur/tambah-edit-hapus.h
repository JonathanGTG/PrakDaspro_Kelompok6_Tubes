#include "Task.h"

void tambahTugas() {

    system("cls");

    FILE *file = fopen(FILE_TUGAS, "a");
    if (file == NULL) {
        printf(RED "Maaf terjadi kesalahan, file tidak dapat dibuka.\n" RESET);
        return;
    }

    Tugas tugas;

    printf(GREEN"===========================\n"RESET);
    printf(GREEN"||    Tambah Tugas       ||\n"RESET);
    printf(GREEN"===========================\n"RESET);

    flushInput();
    printf("Masukkan Nama Mata Kuliah : ");
    scanf("%19s", tugas.matkul);

    printf("Masukkan Deadline (dd-mm-yyyy) : ");
    scanf("%19s", tugas.deadline);

    printf("Masukkan Status (Belum/Done) : ");
    scanf("%5s", tugas.status);

    
    fprintf(file, "%s\n %s\n %s\n", tugas.matkul, tugas.deadline, tugas.status);

    fclose(file);

    printf(BLUE "\nBerhasil menambahkan tugas!\n" RESET);

}