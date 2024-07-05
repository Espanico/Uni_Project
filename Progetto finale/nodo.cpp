#ifndef _NODO_
#define _NODO_


#include<iostream>
#include"rappresentazione.h"
using namespace std;

struct Nodo {
	Rappresentazione* valore;
	Nodo* next;
};

#endif
