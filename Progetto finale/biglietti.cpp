#include"biglietti.h"

#include<iostream>
using namespace std;

Biglietti::Biglietti() {
	p = NULL;
	nelem = 0;
}



void Biglietti::inserisci(Biglietto* b) {
	if(p==NULL) {
		p = new Nodobiglietto;
		p->next = NULL;
		p->valore = b;
	}
	else {
		Nodobiglietto* q = new Nodobiglietto;
		q->next = p;
		q->valore = b;
		
		p=q;
	}
	nelem++;
}


Nodobiglietto* Biglietti::getP() const {
	return p;
}

int Biglietti::getNelem() const {
	return nelem;
}


Biglietti::~Biglietti() {
	if(p != NULL) {
		Nodobiglietto* q = p;
		for(int i=0; i<nelem; i++) {
			Nodobiglietto* target = q;
			q=q->next;
			delete target->valore;
		}
	}
}




ostream& operator<<(ostream& os, const Biglietti& B) {
	if(B.getP() != NULL) {
		int x = 0;
		Nodobiglietto* q = B.getP();
		for(int i=0; i<B.nelem; i++) {
			os << *q->valore << endl;
			x+=q->valore->getPrezzo();
			q=q->next;
		}
		os << "Totale guadagni: " << x << endl;
	}
	return os;
}
