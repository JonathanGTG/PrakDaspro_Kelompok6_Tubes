#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void speedG() {
    srand(time(NULL));
    double waktu[5];
    int ronde = 5;

    printf("=== GAME REACTION TIME ===\n");
    printf("Tekan ENTER SECEPATNYA setelah muncul perintah!\n");
    printf("Ada %d ronde.\n", ronde);
    printf("Tekan ENTER untuk mulai...\n");
    getchar();

    for (int i = 0; i < ronde; i++) {
        int delay = rand() % 5 + 1; 
        printf("\nRonde %d...\nBersiap...\n", i + 1);

        time_t startWait = time(NULL);
        while (time(NULL) - startWait < delay) {
        }

        printf("\nTEKAN ENTER SEKARANG!!!\n");

        clock_t start = clock();
        getchar();
        clock_t end = clock();

        waktu[i] = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Waktu reaksi kamu: %.3f detik\n", waktu[i]);
    }

    printf("\n=== HASIL AKHIR ===\n");
    double total = 0;
    for (int i = 0; i < ronde; i++) {
        printf("Ronde %d: %.3f detik\n", i + 1, waktu[i]);
        total += waktu[i];
    }

    double rata = total / ronde;
    printf("\nRata-rata waktu reaksi: %.3f detik\n", rata);

    if (rata < 0.20)
        printf(" Super cepat! Kamu punya refleks luar biasa!\n");
    else if (rata < 0.40)
        printf(" Hebat! Refleks kamu bagus!\n");
    else if (rata < 0.60)
        printf(" Lumayan! Bisa lebih cepat lagi!\n");
    else
        printf(" Lambat nih, jangan ngantuk ya!\n");

    printf("\nTerima kasih sudah bermain!\n");
    printf("\nTekan Enter untuk kembali ke Menu Games...\n");
    getchar();
}