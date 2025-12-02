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
    fgets(tugas.matkul, sizeof(tugas.matkul), stdin);
    tugas.matkul[strcspn(tugas.matkul, "\n")] = '\0';

    printf("Masukkan Deadline (dd-mm-yyyy) : ");
    fgets(tugas.deadline, sizeof(tugas.deadline), stdin);
    tugas.deadline[strcspn(tugas.deadline, "\n")] = '\0';

    printf("Masukkan Status (Belum/Done) : ");
    fgets(tugas.status, sizeof(tugas.status), stdin);
    tugas.status[strcspn(tugas.status, "\n")] = '\0';

    
    fprintf(file, "%s\n%s\n%s\n", tugas.matkul, tugas.deadline, tugas.status);

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
  
  while (fgets(tugas[jumlah].matkul, sizeof(tugas[jumlah].matkul), file) != NULL &&
       fgets(tugas[jumlah].deadline, sizeof(tugas[jumlah].deadline), file) != NULL &&
       fgets(tugas[jumlah].status, sizeof(tugas[jumlah].status), file) != NULL) {

    tugas[jumlah].matkul[strcspn(tugas[jumlah].matkul, "\n")] = '\0';
    tugas[jumlah].deadline[strcspn(tugas[jumlah].deadline, "\n")] = '\0';
    tugas[jumlah].status[strcspn(tugas[jumlah].status, "\n")] = '\0';

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
  
   flushInput();
    printf("Masukkan Matkul baru: ");
    fgets(tugas[pilih].matkul, sizeof(tugas[pilih].matkul), stdin);
    tugas[pilih].matkul[strcspn(tugas[pilih].matkul, "\n")] = '\0';

    printf("Masukkan Deadline baru: ");
    fgets(tugas[pilih].deadline, sizeof(tugas[pilih].deadline), stdin);
    tugas[pilih].deadline[strcspn(tugas[pilih].deadline, "\n")] = '\0';

    printf("Masukkan Status baru (Belum/Done): ");
    fgets(tugas[pilih].status, sizeof(tugas[pilih].status), stdin);
    tugas[pilih].status[strcspn(tugas[pilih].status, "\n")] = '\0';

  file = fopen(FILE_TUGAS, "w");
  if (!file) {
      printf("Gagal membuka file untuk menulis!\n");
      return;
  }

  for (int i = 0; i < jumlah; i++) {
      fprintf(file, "%s\n%s\n%s\n",
                tugas[i].matkul, 
                tugas[i].deadline, 
                tugas[i].status);
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

   while (fgets(tugas[jumlah].matkul, sizeof(tugas[jumlah].matkul), file) != NULL &&
       fgets(tugas[jumlah].deadline, sizeof(tugas[jumlah].deadline), file) != NULL &&
       fgets(tugas[jumlah].status, sizeof(tugas[jumlah].status), file) != NULL) {

    tugas[jumlah].matkul[strcspn(tugas[jumlah].matkul, "\n")] = '\0';
    tugas[jumlah].deadline[strcspn(tugas[jumlah].deadline, "\n")] = '\0';
    tugas[jumlah].status[strcspn(tugas[jumlah].status, "\n")] = '\0';

    jumlah++;
    }

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
            fprintf(file,"%s\n%s\n%s\n",
                    tugas[i].matkul,
                    tugas[i].deadline,
                    tugas[i].status);
        }
    }

    fclose(file);

    printf(GREEN "\nTugas berhasil dihapus!\n" RESET);
    system("pause");
    system("cls");
}
