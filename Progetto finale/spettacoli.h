#ifndef _SPETTACOLI_H_
#define _SPETTACOLI_H_

#include"nodo.cpp"
#include"nodospettacolo.cpp"
#include"rappresentazioni.h"
#include"spettacolo.h"
#include<iostream>
#include<string.h>
using namespace std;

class Spettacoli {
	private:
		Nodospettacolo* p;
		int nelem;
	
	public:
		Spettacoli();
		
		void inserisci(Rappresentazioni*, Spettacolo*);
		void mostraTitoli();
		Nodospettacolo* getP() const;
		int getNelem() const;
		
		int find(char*) const;
		void cancella(int);
		
		friend ostream& operator<<(ostream& os, const Spettacoli& S);
		
		~Spettacoli();
};

#endif
