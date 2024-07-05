#include<iostream>
#include<string.h>
#include"spettacolo.h"
using namespace std;

Spettacolo::Spettacolo(Rappresentazioni* R, int n) {
	
	Nodo* q = R->getP();
	
	for(int i=0; i<n; i++) {
		q=q->next;
	}
	
	this->r = q->valore;
	
	this->giorno = new char(strlen("")+1);
	strcpy(this->giorno, "");
	this->orario = 0;
	this->prezzo = 0;
}

Spettacolo::Spettacolo(Rappresentazione* r, char* giorno, int orario, euro prezzo) {
	this->r = r;
	this->giorno = new char(strlen(giorno)+1);
	strcpy(this->giorno, giorno);
	this->orario = orario;
	this->prezzo = prezzo;
}



void Spettacolo::setGiorno(char* giorno) {
	this->giorno = new char(strlen(giorno)+1);
	strcpy(this->giorno, giorno);
}

char* Spettacolo::getGiorno() const {
	return giorno;
}

void Spettacolo::setOrario(int orario) {
	this->orario = orario;
}

int Spettacolo::getOrario() const {
	return orario;
}

void Spettacolo::setPrezzo(euro prezzo) {
	this->prezzo=prezzo;
}

euro Spettacolo::getPrezzo() const {
	return prezzo;
}


Rappresentazione* Spettacolo::getR() const {
	return r;
}


Spettacolo::~Spettacolo() {
	delete[] giorno;
}






ostream& operator<<(ostream& os, const Spettacolo& s) {
	
	os << s.getR()->getTitolo() << "," << s.getGiorno() << "," << s.getOrario() << "," << s.getPrezzo() << endl;

	return os;
}









