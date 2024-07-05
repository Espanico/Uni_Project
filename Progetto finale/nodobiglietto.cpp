#ifndef _NODOBIGLIETTO_
#define _NODOBIGLIETTO_


#include<iostream>
#include"biglietto.h"
using namespace std;

struct Nodobiglietto {
	Biglietto* valore;
	Nodobiglietto* next;
};

#endif
