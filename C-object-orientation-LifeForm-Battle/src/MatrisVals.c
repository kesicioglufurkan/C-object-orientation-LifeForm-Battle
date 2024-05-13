#include "MatrisVals.h"
#include <stdio.h>
#include <stdlib.h>

// Dosyan�n sat�r ve s�tun say�s�n� d�nd�r�r

MatrisVals* xyFinder() {

    FILE* dosya = fopen("Veri.txt", "r");

    if (dosya == NULL) {
        printf("Dosya a��lamad�!");
        return NULL;
    }

    int sutun = 0;
    int satir = 0;
    char c;
    while ((c = fgetc(dosya)) != EOF) {
        if (c == ' ') { // Karakter bir bo�luk mu?
            if (satir == 0) {
                sutun++;
            }
        }
        else if (c == '\n') { // Karakter bir yeni sat�r m�?
            satir++;
        }
    }
    sutun++;
    satir++;

    fclose(dosya);

    // struct MatrisVals t�r�nde dinamik olarak bellek ay�r
    MatrisVals* matris = malloc(sizeof(MatrisVals));
    if (matris == NULL) {
        printf("Bellek tahsisi hatas�!");
        return NULL;
    }

    matris->x = sutun;
    matris->y = satir;
    return matris;
}
