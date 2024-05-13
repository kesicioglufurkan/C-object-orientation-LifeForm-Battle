#include "CanliBilgi.h"
#include "Habitat.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



//                       ! ! ! ! �NEML� UYARI ! ! ! !       L�tfen okunacak dosyan�n sonunda bo� sat�r b�rakmay�n�z !


int main() {

    int cols = 0;
    int rows = 0;
    
    MatrisVals* matrisM = xyFinder();

    cols = matrisM->x;
    rows = matrisM->y;

    Habitat habitatMatrisM = habitatOlustur(cols, rows);

    FILE* dosya;
    dosya = fopen("Veri.txt", "r");

    if (dosya == NULL) {
        printf("Dosya a��lamad�!");
        return 0;
    }

    int num = 0;        // Okunan tam say�
    int digitCount = 0; // Tam say�n�n basamak say�s�
    int isNum = 0;      // Tam say� okunuyor mu?

    int a = 0;
    int b = 0;

                         // Dosya okuma i�lemleri ba��

    char c;

    while ((c = fgetc(dosya)) != EOF) {


        if (isdigit(c)) { 

            num = num * 10 + (c - '0');
            digitCount++;
            isNum = 1;
            continue;

        }
        else if (c == ' ') {
            if (isNum) {


                habitatMatrisM->matrix[a][b] = createCanliBilgi(num);

                num = 0;
                digitCount = 0;
                isNum = 0;

            }
        }
        else if (c == '\n') {
            if (isNum) {


                habitatMatrisM->matrix[a][b] = createCanliBilgi(num);

                num = 0;
                digitCount = 0;
                isNum = 0;
            }
        }
        
        if (a < cols-1) {
            a++;
           
        }
        else {
            a = 0;
            b++;
            
        }
        if ((b - rows) >= 0) {
            break;
        }

    }

    if (isNum) {

        habitatMatrisM->matrix[a][b] = createCanliBilgi(num);

    }

    fclose(dosya);        // Dosya okuma i�lmleri sonu

    canliYazdir(rows, cols, habitatMatrisM);

    getch();


                          // Sava� ba�lang�c�
    int x0 = 0;
    int y0 = 0;
    char ch1;
    char ch2;
    int sonuc;
    int turSecici;


    for (int y1 = 0; y1 < rows; y1++) {
        for (int x1 = 0; x1 < cols; x1++) {
            if (x1 == 0 && y1 == 0) {
                continue;
            }
            turSecici = habitatMatrisM->matrix[x0][y0]->canliTurSayi;

            ch1 = canliSecSimge(turSecici, habitatMatrisM->matrix[x0][y0]->canliStructPointer);

            turSecici = habitatMatrisM->matrix[x1][y1]->canliTurSayi;

            ch2 = canliSecSimge(turSecici, habitatMatrisM->matrix[x1][y1]->canliStructPointer);


            sonuc = ikiCanliKarsilastir(ch1, ch2);

            if (sonuc == 1) {
                canliSecOldur(habitatMatrisM->matrix[x1][y1]->canliTurSayi, habitatMatrisM->matrix[x1][y1]->canliStructPointer);
            }
            else if (sonuc == 2) {
                canliSecOldur(habitatMatrisM->matrix[x0][y0]->canliTurSayi, habitatMatrisM->matrix[x0][y0]->canliStructPointer);
                x0 = x1;
                y0 = y1;
            }
            
            else if(sonuc == 3){

                int ilkSayi = 0;
                int ikinciSayi = 0;

                ilkSayi = canliSecSayi(habitatMatrisM->matrix[x0][y0]->canliTurSayi, habitatMatrisM->matrix[x0][y0]->canliStructPointer);
                ikinciSayi = canliSecSayi(habitatMatrisM->matrix[x1][y1]->canliTurSayi, habitatMatrisM->matrix[x1][y1]->canliStructPointer);
                
                if (ilkSayi > ikinciSayi) {
                    canliSecOldur(habitatMatrisM->matrix[x1][y1]->canliTurSayi, habitatMatrisM->matrix[x1][y1]->canliStructPointer);
                }
                else if (ikinciSayi > ilkSayi) {
                    canliSecOldur(habitatMatrisM->matrix[x0][y0]->canliTurSayi, habitatMatrisM->matrix[x0][y0]->canliStructPointer);
                    x0 = x1;
                    y0 = y1;
                }
                else if (ikinciSayi == ilkSayi) {
                    canliSecOldur(habitatMatrisM->matrix[x1][y1]->canliTurSayi, habitatMatrisM->matrix[x1][y1]->canliStructPointer);
                }

            }
            canliYazdir(rows, cols, habitatMatrisM);    //Sadece sonucu yazd�rmak i�in bu fonksiyonu gizleyiniz,e�er gizlenirse kazanan de�erin daha h�zl� bulmas�n� sa�lar

            
        }
    }
    
    // Sava� i�lemleri sonu

    canliYazdir(rows, cols, habitatMatrisM);

    

    printf("\nKAZANAN: %c : (%d,%d)\n",canliSecSimge(habitatMatrisM->matrix[x0][y0]->canliTurSayi, habitatMatrisM->matrix[x0][y0]->canliStructPointer), y0, x0);
 


    for (int y1 = 0; y1 < rows; y1++) {
        for (int x1 = 0; x1 < cols; x1++) {
            habitatMatrisM->matrix[x1][y1]->yoket(habitatMatrisM->matrix[x1][y1]);
        }
    }


    yoketHabitat(habitatMatrisM);

    return 0;
}