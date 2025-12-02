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

void editTugas() {
  system("cls");

  FILE *file = fopen(FILE_TUGAS, "r");

  if (!file) {
      printf("Gagal membuka file '%s'!\n" RESET);
      return;
  }

  
  Tugas tugas[100];
  int jumlah = 0;
  
  while (fscanf(file, "%29s %14s %9s", tugas[jumlah].matkul, 
    tugas[jumlah].deadline, tugas[jumlah].status) != EOF) {
      jumlah++;
  }
  fclose(file);

  printf(RED"|========================|\n"RESET);
  printf(RED"!     -DAFTAR TUGAS-     !\n"RESET);
  printf(RED"|========================|\n"RESET);
    
  for (int i = 0; i < jumlah; i++) {
      printf("%d. %s - %s - %s\n", i + 1, tugas[i].matkul, 
        tugas[i].deadline, tugas[i].status);
  }

  int pilih;
  printf("\n--> Pilih nomor tugas yang mau di edit: ");
  scanf("%d", &pilih);

  if (pilih < 1 || pilih > jumlah) {
      printf("Nomor tidak valid!\n");
      return;
  }

  pilih--;
  
   printf("Masukkan Matkul baru: "); scanf("%29s", tugas[pilih].matkul);
   printf("Masukkan Deadline baru: "); scanf("%14s", tugas[pilih].deadline);
   printf("Masukkan Status baru: "); scanf("%9s", tugas[pilih].status);

  file = fopen(FILE_TUGAS, "w");
  if (!file) {
      printf("Gagal membuka file untuk menulis!\n");
      return;
  }

  for (int i = 0; i < jumlah; i++) {
      fprintf(file, "%s %s %s\n",
                tugas[i].matkul, tugas[i].deadline, tugas[i].status);
    }

  fclose(file);

  printf(GREEN "\nYeayy!! Tugas kamu berhasil di edit!\n" RESET);

}

void hapusTugas() {
    system("cls");

    FILE *file = fopen(FILE_TUGAS, "r");
    if (!file) {
        printf(RED "Belum ada tugas!\n" RESET);
        return;
    }

    Tugas tugas[100];
    int jumlah = 0;

    while (fscanf(file,"%29s %14s %9s",
                  tugas[jumlah].matkul,
                  tugas[jumlah].deadline,
                  tugas[jumlah].status) != EOF)
        jumlah++;

    fclose(file);

    printf(GREEN "=== Hapus Tugas ===\n" RESET);
    for(int i = 0; i < jumlah; i++) {
        printf("%d. %s - %s - %s\n",
               i+1,
               tugas[i].matkul,
               tugas[i].deadline,
               tugas[i].status);
    }

    int pilih;
    printf("\nPilih nomor tugas yang ingin dihapus: ");
    scanf("%d", &pilih);

    if (pilih < 1 || pilih > jumlah) {
        printf(RED "Nomor tidak valid!\n" RESET);
        return;
    }

    pilih--;

    file = fopen(FILE_TUGAS,"w");

    for (int i = 0; i < jumlah; i++) {
        if (i != pilih) {
            fprintf(file,"%s %s %s\n",
                    tugas[i].matkul,
                    tugas[i].deadline,
                    tugas[i].status);
        }
    }

    fclose(file);

    printf(GREEN "\nTugas berhasil dihapus!\n" RESET);
}
