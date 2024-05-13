#include <stdio.h>
#include <stdlib.h>
#include <Habitat.h>

Habitat habitatOlustur(int rows, int cols) {
    Habitat habitatMatris = (Habitat)malloc(sizeof(struct HABITAT));
    if (habitatMatris == NULL) {
        // Bellek yetersiz
        exit(EXIT_FAILURE);
    }

    // Sat�r ve s�tun say�s�na g�re bellekten yer ay�rma
    habitatMatris->matrix = (CanliBilgi**)malloc(rows * sizeof(CanliBilgi*));
    if (habitatMatris->matrix == NULL) {
        // Bellek yetersiz
        free(habitatMatris);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        habitatMatris->matrix[i] = (CanliBilgi*)malloc(cols * sizeof(CanliBilgi));
        if (habitatMatris->matrix[i] == NULL) {
            // Bellek yetersiz
            for (int j = 0; j < i; j++) {
                free(habitatMatris->matrix[j]);
            }
            free(habitatMatris->matrix);
            free(habitatMatris);
            exit(EXIT_FAILURE);
        }
    }

    habitatMatris->rows = rows;
    habitatMatris->cols = cols;

    return habitatMatris;
}

int ikiCanliKarsilastir(char ilkChar, char ikinciChar) { //d�nen de�er 1 ise birinci kazan�r, 2 ise ikinci, 3 ise uzatmalara kal�r

    if (ilkChar == 'C') {
        if (ikinciChar == 'B') {
            return 1;
        }
        else if (ikinciChar == 'S') {
            return 2;
        }
        else if (ikinciChar == 'P') {
            return 1;
        }
        else if (ikinciChar == 'C') {
            return 3;
        }
        else {
            printf("Hata 1111");
        }
    }

    else if (ilkChar == 'B') {
        if (ikinciChar == 'C') {
            return 2;
        }
        else if (ikinciChar == 'S') {
            return 1;
        }
        else if (ikinciChar == 'P') {
            return 1;
        }
        else if (ikinciChar == 'B') {
            return 3;
        }
        else {
            printf("Hata 1112");
        }
    }

    else if (ilkChar == 'S') {
        if (ikinciChar == 'C') {
            return 1;
        }
        else if (ikinciChar == 'S') {
            return 3;
        }
        else if (ikinciChar == 'P') {
            return 1;
        }
        else if (ikinciChar == 'B') {
            return 2;
        }
        else {
            printf("Hata 1113");
        }
    }

    else if (ilkChar == 'P') {
        if (ikinciChar == 'C') {
            return 2;
        }
        else if (ikinciChar == 'S') {
            return 2;
        }
        else if (ikinciChar == 'P') {
            return 3;
        }
        else if (ikinciChar == 'B') {
            return 2;
        }
        else {
            printf("Hata 1114");
        }
    }

}

void yoketHabitat(Habitat habitatMatris) {
    if (habitatMatris == NULL) {
        return;
    }

    // Matris i�indeki her bir sat�r i�in belle�i serbest b�rak
    for (int i = 0; i < habitatMatris->rows; i++) {
        free(habitatMatris->matrix[i]);
    }

    // Matrisin kendisini serbest b�rak
    free(habitatMatris->matrix);

    // Habitat yap�s�n� serbest b�rak
    free(habitatMatris);
}

// Adresi girilen canl�n�n simgesini yazd�r�r
void canliSecYaz(int turSayi, void* adresi) {

    char ch;
    if (turSayi == 1) {
        Bitki bitkiPtr = (Bitki)adresi;
        ch = bitkiPtr->super->gorunum(bitkiPtr->super);
        printf("%c ", ch);
    }
    else if (turSayi == 2) {
        Bocek bocekPtr = (Bocek)adresi;
        ch = bocekPtr->super->gorunum(bocekPtr->super);
        printf("%c ", ch);
    }
    else if (turSayi == 3) {
        Sinek sinekPtr = (Sinek)adresi;
        ch = sinekPtr->super->gorunum(sinekPtr->super->super);
        printf("%c ", ch);
    }
    else if (turSayi == 4) {
        Pire pirePtr = (Pire)adresi;
        ch = pirePtr->super->gorunum(pirePtr->super->super);
        printf("%c ", ch);
    }
    else {
        printf("hata");
    }


}

// Adresi girilen canl�n�n simgesini d�nd�r�r
char canliSecSimge(int turSayi, void* adresi) {

    char ch;
    if (turSayi == 1) {
        Bitki bitkiPtr = (Bitki)adresi;
        ch = bitkiPtr->super->gorunum(bitkiPtr->super);
    }
    else if (turSayi == 2) {
        Bocek bocekPtr = (Bocek)adresi;
        ch = bocekPtr->super->gorunum(bocekPtr->super);
    }
    else if (turSayi == 3) {
        Sinek sinekPtr = (Sinek)adresi;
        ch = sinekPtr->super->gorunum(sinekPtr->super->super);
    }
    else if (turSayi == 4) {
        Pire pirePtr = (Pire)adresi;
        ch = pirePtr->super->gorunum(pirePtr->super->super);
    }
    else {

    }
    return ch;

}

// Adresi girilen canl�n�n sayisini d�nd�r�r
char canliSecSayi(int turSayi, void* adresi) {

    int num;
    if (turSayi == 1) {
        Bitki bitkiPtr = (Bitki)adresi;
        num = bitkiPtr->super->sayi;
    }
    else if (turSayi == 2) {
        Bocek bocekPtr = (Bocek)adresi;
        num = bocekPtr->super->sayi;
    }
    else if (turSayi == 3) {
        Sinek sinekPtr = (Sinek)adresi;
        num = sinekPtr->super->super->sayi;
    }
    else if (turSayi == 4) {
        Pire pirePtr = (Pire)adresi;
        num = pirePtr->super->super->sayi;
    }
    else {

    }
    return num;

}

// Adresi girilen canl�n�n simgesini de�i�tirir 'X' atar
void canliSecOldur(int turSayi, void* adresi) {

    char ch;
    if (turSayi == 1) {
        Bitki bitkiPtr = (Bitki)adresi;
        bitkiPtr->super->simge = 'X';
    }
    else if (turSayi == 2) {
        Bocek bocekPtr = (Bocek)adresi;
        bocekPtr->super->simge = 'X';

    }
    else if (turSayi == 3) {
        Sinek sinekPtr = (Sinek)adresi;
        sinekPtr->super->super->simge = 'X';

    }
    else if (turSayi == 4) {
        Pire pirePtr = (Pire)adresi;
        pirePtr->super->super->simge = 'X';

    }
    else {
        printf("hata");
    }


}

// Adresi girilen habitat� tek tek dola�arak matrisi yazd�r�r
void canliYazdir(int rows, int cols, Habitat habitatMatrisM) {


    printf("\e[1;1H\e[2J");
    int turSecici = 0;
    for (int j = 0; j < rows; j++) {

        for (int i = 0; i < cols; i++) {

            turSecici = habitatMatrisM->matrix[i][j]->canliTurSayi;

            canliSecYaz(turSecici, habitatMatrisM->matrix[i][j]->canliStructPointer);

        }
        printf("\n");
    }

}
