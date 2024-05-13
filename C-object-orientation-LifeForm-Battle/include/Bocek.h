#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK {

	Canli super;

	void (*yoket)();

	char (*gorunum)();

};

typedef struct BOCEK* Bocek;

Bocek bocekOlustur(int);
void bocekYoket(const Bocek);


#endif
