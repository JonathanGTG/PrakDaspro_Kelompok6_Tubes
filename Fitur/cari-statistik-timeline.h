#include "Task.h"

void toLowerCase(char *str) {
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

void cariTugas()
{
    system("cls");
    char pencarian[100];
    int found = 0;
    int valid = 1;
    Tugas tugas;

    FILE *file = fopen(FILE_TUGAS, "r");
    if (file == NULL)
    {
        printf("Maaf Terjadi Kesalahan Please Reload\n");
        return;
    }
    else
    {
        printf(GREEN "============================\n" RESET);
        printf("        Cari Tugas\n");
        printf(GREEN "============================\n" RESET);
        printf("Masukan Nama Pelajaran yang ingin dicari: ");

        flushInput();
        fgets(pencarian, sizeof(pencarian), stdin);
        pencarian[strcspn(pencarian, "\n")] = '\0';


        printf(RED "\n==============================\n" RESET);
        printf("    Hasil Pencarian: %s\n", pencarian);
        printf(RED "==============================\n" RESET);

        printf(BLUE "\nTugas:\n" RESET);
        
        // Convert pencarian ke lowercase untuk case-insensitive search
        char pencarianLower[100];
        strcpy(pencarianLower, pencarian);
        toLowerCase(pencarianLower);
        
        while(fscanf(file, "%19s %19s %5s", tugas.matkul, tugas.deadline, tugas.status) != EOF){
            char matkulLower[20];
            strcpy(matkulLower, tugas.matkul);
            toLowerCase(matkulLower);
            
            // Jika pencarian kosong atau ditemukan kecocokan
            if(strlen(pencarian) == 0 || strstr(matkulLower, pencarianLower) != NULL){
                printf("%s - Deadline: %s - Status: %s\n", tugas.matkul, tugas.deadline, tugas.status);
                found = 1;
            }
        }
        
        if(!found){
            printf("Tidak ditemukan tugas untuk pelajaran: %s\n", pencarian);
        }
        
        fclose(file);
    }
}
