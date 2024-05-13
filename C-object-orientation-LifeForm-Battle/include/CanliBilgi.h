#include "Bocek.h"
#include "Pire.h"
#include "Sinek.h"
#include "Bitki.h"

#ifndef CANLIBILGI_H
#define CANLIBILGI_H

struct CANLIBILGI {


	int canliTurSayi;

	void* canliStructPointer;

	void (*yoket)();

};

typedef struct CANLIBILGI* CanliBilgi;
CanliBilgi createCanliBilgi(int);
void canliBilgiYoket(const CanliBilgi);
#endif