#ifndef _NODOSPETTACOLO_
#define _NODOSPETTACOLO_


#include<iostream>
#include"spettacolo.h"
using namespace std;

struct Nodospettacolo {
	Spettacolo* valore;
	Nodospettacolo* next;
};

#endif
