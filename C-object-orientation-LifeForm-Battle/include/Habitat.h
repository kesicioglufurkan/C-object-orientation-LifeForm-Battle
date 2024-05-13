#ifndef HABITAT_H
#define HABITAT_H

#include "CanliBilgi.h"
#include "MatrisVals.h"
#include "stdio.h"
#include "stdlib.h"

// Habitat yap�s� tan�m�
struct HABITAT {
    CanliBilgi** matrix; // CANLIBILGI yap�s�n�n adreslerini tutan bir matris
    int rows;            // Sat�r say�s�
    int cols;            // S�tun say�s�
};

// Habitat tipi tan�m�
typedef struct HABITAT* Habitat;

// Fonksiyon bildirimleri
Habitat habitatOlustur(int , int);
int ikiCanliKarsilastir(char, char);
void yoketHabitat(Habitat);
void canliSecYaz(int turSayi, void* adresi);
char canliSecSimge(int turSayi, void* adresi);
char canliSecSayi(int turSayi, void* adresi);
void canliSecOldur(int turSayi, void* adresi);
void canliYazdir(int rows, int cols, Habitat habitatMatrisM);

#endif

