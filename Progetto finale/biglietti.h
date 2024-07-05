#ifndef _BIGLIETTI_H_
#define _BIGLIETTI_H_
#include<iostream>
#include<string.h>

#include"biglietto.h"
#include"spettacolo.h"
#include"nodobiglietto.cpp"
using namespace std;

class Biglietti {
	private:
		Nodobiglietto* p;
		int nelem;
		
	public:
		Biglietti();
		
		void inserisci(Biglietto*);
		Nodobiglietto* getP() const;
		int getNelem() const;
		
		
		friend ostream& operator<<(ostream& os, const Biglietti& B);
		
		~Biglietti();
};

#endif
