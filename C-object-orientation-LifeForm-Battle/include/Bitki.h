#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI {

	Canli super;

	void (*yoket)();

	char (*gorunum)();

};

typedef struct BITKI* Bitki;

Bitki bitkiOlustur(int);
void bitkiYoket(const Bitki);


#endif
