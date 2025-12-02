#include "Fitur/Task.h"
#include "Fitur/tambah-edit-hapus.h"
#include "Fitur/cari-statistik-timeline.h"
#include "Fitur/checkstatus.h"
#include "Games/games.h"
#include "Fitur/exit.h"



void daftarfitur() {
    printf(GREEN "=== Daftar Fitur Tugas ===\n" RESET);
    printf("1. Tambah Tugas\n");
    printf("2. Cari Tugas\n");
    printf("3. Timeline Tugas\n");
    printf("4. Edit Tugas\n");
    printf("5. Hapus Tugas\n");
    printf("6. Statistik Tugas\n");
    printf("7. Minigames\n");
    printf("8. Keluar\n");
}

int main() {
    int pilih;

    system("cls");
    printf(BLUE "=========================================\n" RESET);
    printf(BLUE "|     WELCOME TO PROGRAM TO DO LIST     |\n" RESET);
    printf(BLUE "=========================================\n" RESET);

    do {
        daftarfitur();
        printf("Pilih Fitur yang ingin kamu gunakan : ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: tambahTugas(); 
            break;
            case 2: cariTugas(); 
            break;
            case 3: timeline(); 
            break;
            case 4: editTugas(); 
            break;
            case 5: hapusTugas(); 
            break;
            case 6: statistikTugas(); 
            break;
            case 7: if (adaTugasDone()) {
                        games();
                    } else {
                        printf(RED "\nAyo kerjakan tugas dulu!\n" RESET);
                        printf("Kamu bisa bermain jika ada tugas yang sudah DONE.\n");
                    }
            break;
            case 8: keluarprogram();
            return 0;
            default: printf(RED "Pilihan tidak valid!\n" RESET);
        }
        printf("\n");
        system("pause");
    } while (pilih != 8);

    return 0;
}
