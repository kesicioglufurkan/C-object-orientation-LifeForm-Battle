#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"


struct CANLI {


	int sayi;

	char simge;

	char (*gorunum)();

	void (*setSayi)(struct CANLI*, int);

	void (*setSimge)(struct CANLI*, char);

	void (*yoket)(struct CANLI*);
};

typedef struct CANLI* Canli;
Canli canliOlustur(int, char);
void setSayi(const Canli, int);
void setSimge(const Canli, char);
void canliYoket(const Canli);
char canliGorunum(const Canli);

#endif 
