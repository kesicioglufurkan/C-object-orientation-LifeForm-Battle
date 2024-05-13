#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE {

	Bocek super;

	void (*yoket)();

	char (*gorunum)();

};

typedef struct PIRE* Pire;

Pire pireOlustur(int);
void pireYoket(const Pire);


#endif
