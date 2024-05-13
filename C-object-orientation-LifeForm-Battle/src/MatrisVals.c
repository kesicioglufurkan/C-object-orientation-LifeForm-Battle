#include "MatrisVals.h"
#include <stdio.h>
#include <stdlib.h>

// Dosyanýn satýr ve sütun sayýsýný döndürür

MatrisVals* xyFinder() {

    FILE* dosya = fopen("Veri.txt", "r");

    if (dosya == NULL) {
        printf("Dosya açýlamadý!");
        return NULL;
    }

    int sutun = 0;
    int satir = 0;
    char c;
    while ((c = fgetc(dosya)) != EOF) {
        if (c == ' ') { // Karakter bir boþluk mu?
            if (satir == 0) {
                sutun++;
            }
        }
        else if (c == '\n') { // Karakter bir yeni satýr mý?
            satir++;
        }
    }
    sutun++;
    satir++;

    fclose(dosya);

    // struct MatrisVals türünde dinamik olarak bellek ayýr
    MatrisVals* matris = malloc(sizeof(MatrisVals));
    if (matris == NULL) {
        printf("Bellek tahsisi hatasý!");
        return NULL;
    }

    matris->x = sutun;
    matris->y = satir;
    return matris;
}
