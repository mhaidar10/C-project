// /* ATM Machine service
// Untuk memenuhi matkul algroritma pemrograman
// |=========================================|
// |---------- ATM Machine service ----------|
// |---------- | Telkom University  |--------|
// |------------| Author: Haidar |-----------|
// |---------| Password: 123 |---------------|
// |=========================================|*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
    int pilihNomor, saldo = 5000000;
    int tagihanListrik = 200000;
    int rekening, nominaltransfer;

    int pin, enter = 1, pwd = 123;
login:
    while (enter)
    {
        printf("Input nomor PIN = ");
        scanf("%d", &pin);
        if (pin == pwd)
        {
            enter = 0;
            system("cls");
        }
    }
   
    char tanyaListrik;

    char tanyaPin;
   
    char tanyabayar;

    int inside = 1;

    while (inside)
    {

    menu:

        printf("\n\n=====Selamat datang di ATM=====\n");
        printf("1. Lihat Saldo     \n");
        printf("2. Transfer        \n");
        printf("3. Tagihan Listrik \n");
        printf("4. Ganti PIN       \n");
        printf("5. Logout          \n\n");

        printf("Pilih Nomor = ");
        scanf("%d", &pilihNomor);
        printf("\n");

        if (pilihNomor == 1)
        {
            printf("Saldo kamu = %d\n", saldo);
            sleep(2);
        }
        else if (pilihNomor == 2)
        {
            printf("Masukan Nomor Rekening tujuan = ");
            scanf("%d", &rekening);
            printf("Masukan Nominal Uang yg akan di transfer = ");
            scanf("%d", &nominaltransfer);
            if (nominaltransfer > 0)
            {
            konfirmasi:
                printf("Konfirmasi Pembayaran? (y/n) = ");
                fflush(stdin);
                scanf("%c", &tanyabayar);
                if (tanyabayar == 'y')
                {
                    printf("Pembayaran Berhasil");
                    sleep(3);
                    saldo-=nominaltransfer;
                    system("cls");
                }
                else if (tanyabayar == 'n')
                {
                    printf("Pembayaran dibatalkan");
                    nominaltransfer = 0;
                    rekening = 0;
                    sleep(3);
                }

                else
                {
                    goto konfirmasi;
                }
            }
        }
        else if (pilihNomor == 3)
        {

            printf("Tagihan listrik kamu = Rp.%d \n", tagihanListrik);
            if (tagihanListrik > 0)
            {

            listrik:
                printf("\nMau bayar sekarang?(y/n)= ");
                fflush(stdin);
                scanf("%c", &tanyaListrik);

                if (tanyaListrik == 'y')
                {
                    if (saldo > tagihanListrik)
                    {
                        saldo -= tagihanListrik;
                        tagihanListrik -= tagihanListrik;
                        printf("\n===Pembayaran Berhasil===\n");
                        sleep(3);
                        system("cls");
                    }
                    else
                    {
                        printf("\nSaldo tidak mencukupi\n");
                        sleep(3);
                        system("cls");
                        goto menu;
                    }
                }
                else if (tanyaListrik == 'n')
                {
                    sleep(2);
                    system("cls");
                    goto menu;
                }
                else
                {
                    goto listrik;
                }
            }
            else if (tagihanListrik <= 0)
            {
                printf("Kamu Tidak punya tagihan listrik\n");
                sleep(3);
                system("cls");
            }
        }
        else if (pilihNomor == 4)
        {
        gantiPin:
            printf("Ingin Mengganti PIN?(y/n)= ");
            fflush(stdin);
            scanf("%c", &tanyaPin);

            if (tanyaPin == 'y')
            {
                printf("Masukan Pin yang baru = ");
                scanf("%d", &pin);
                printf("\n===Pin berhasil diganti,silahkan login kembali===\n");
                sleep(3);
                enter = 1;
                pwd = pin;
                system("cls");
                goto login;
            }
            else if (tanyaPin == 'n')
            {
                system("cls");
                goto menu;
            }
            else
            {
                goto gantiPin;
            }
        }
        else if (pilihNomor == 5)
        {
            //back to login
            printf("Kamu berhasil Logout");
            printf("\nSilahkan login kembali!");
            sleep(3);
            enter = 1;
            system("cls");
            goto login;

            //looping stop
            // break;
        }

        else
        {
            system("cls");
        }
    }
}
