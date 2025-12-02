#include "RPS.h"
#include "SpeedGame.h"
#include "Tebak_Angka.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define BLUE  "\033[34m"
#define RESET "\033[0m"

void menugames() {
    printf(GREEN"=== MENU GAMES ===\n"RESET);
    printf("1. Rock Paper Scissors\n");
    printf("2. Reaction Time Game\n");
    printf("3. Number Guest\n");
    printf("4. Kembali ke Menu Utama\n");
    printf("Pilih game yang ingin dimainkan: \n");
}

void daftarfitur();
void games()

{
   system("cls");

   int opsi_games;
   int mengulang;

    printf(BLUE "=========================================\n" RESET);
    printf(BLUE "|     WELCOME TO PROGRAM MINIGAMES    |\n" RESET);
    printf(BLUE "=========================================\n" RESET);

   do
   {
      menugames();
      mengulang = 1;
      printf("\n[1/2/3/4] : ");
      if (scanf("%d", &opsi_games) != 1)
      {
         printf("Input tidak valid!\n");
         fflush(stdin);
      }

      switch (opsi_games)
      {
      case 1:
         rps();
         break;

      case 2:
         speedG();
         break;

      case 3:
         T_Angka();
         break;

      case 4:
         daftarfitur();
         mengulang = 0;
         break;

      default:
         printf("Pilih angka 1 sampai 4 untuk opsi game\n");
         mengulang = 1;
      }
   } while (mengulang == 1);
}
