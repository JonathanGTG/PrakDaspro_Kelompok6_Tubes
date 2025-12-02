#include "Task.h"

int adaTugasDone() {
    FILE *file = fopen(FILE_TUGAS, "r");
    Tugas tugas;

    if (!file) return 0;

    while (fscanf(file, "%29s %14s %9s",
                  tugas.matkul,
                  tugas.deadline,
                  tugas.status) != EOF)
    {
        if (strcasecmp(tugas.status, "Done") == 0 ||
            strcasecmp(tugas.status, "Selesai") == 0)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}