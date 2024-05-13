#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK {

	Bocek super;

	void (*yoket)();

	char (*gorunum)();

};

typedef struct SINEK* Sinek;

Sinek sinekOlustur(int);
void sinekYoket(const Sinek);


#endif
