#include <stdlib.h>
#include "CanliBilgi.h"

CanliBilgi createCanliBilgi(int sayi) {
    CanliBilgi canlibilgi = malloc(sizeof(struct CANLIBILGI)); 

    // Sayýya göre canlý türünü belirle
    if (sayi >= 1 && sayi <= 9) {
        canlibilgi->canliTurSayi = 1; // Bitki
        Bitki bitki = bitkiOlustur(sayi);
        canlibilgi->canliStructPointer = bitki;
    }
    else if (sayi >= 10 && sayi <= 20) {
        canlibilgi->canliTurSayi = 2; // Böcek
        Bocek bocek = bocekOlustur(sayi);
        canlibilgi->canliStructPointer = bocek;
    }
    else if (sayi >= 21 && sayi <= 50) {
        canlibilgi->canliTurSayi = 3; // Sinek
        Sinek sinek = sinekOlustur(sayi);
        canlibilgi->canliStructPointer = sinek;
    }
    else if (sayi >= 51 && sayi <= 99) {
        canlibilgi->canliTurSayi = 4; // Pire
        Pire pire = pireOlustur(sayi);
        canlibilgi->canliStructPointer = pire;
    }
    else {
        // Geçersiz sayý
        canlibilgi->canliTurSayi = 0;
        canlibilgi->canliStructPointer = NULL;
    }

    canlibilgi->yoket = &canliBilgiYoket;

    return canlibilgi;
}

void canliBilgiYoket(const CanliBilgi this) {


    if (this == NULL) return;

    int turSayi = this->canliTurSayi;

    void* adresi = this->canliStructPointer;

    if (turSayi == 1) {
        Bitki bitkiPtr = (Bitki)adresi;
        bitkiPtr->yoket(bitkiPtr);
    }
    else if (turSayi == 2) {
        Bocek bocekPtr = (Bocek)adresi;
        bocekPtr->yoket(bocekPtr);
    }
    else if (turSayi == 3) {
        Sinek sinekPtr = (Sinek)adresi;
        sinekPtr->yoket(sinekPtr);
    }
    else if (turSayi == 4) {
        Pire pirePtr = (Pire)adresi;
        pirePtr->yoket(pirePtr);
    }
    else {

    }

    free(this);
}