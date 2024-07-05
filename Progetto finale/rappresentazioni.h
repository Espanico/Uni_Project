#ifndef _RAPPRESENTAZIONI_H_
#define _RAPPRESENTAZIONI_H_
#include<iostream>
#include<string.h>

#include"film.h"
#include"esibizione.h"
#include"rappresentazione.h"
#include"nodo.cpp"
using namespace std;

class Rappresentazioni {
	private:
		Nodo* p;
		int nelem;
	
	public:
		Rappresentazioni();
		
		void inserisci(Rappresentazione*);
		void mostraTitoli();
		Nodo* getP() const;
		int getNelem() const;
		
		int find(char*) const;
		void cancellaRappresentazione(int);
		
		friend ostream& operator<<(ostream& os, const Rappresentazioni& R);
		
		~Rappresentazioni();
};

#endif
