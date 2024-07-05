#include<iostream>
#include<string.h>
#include"biglietto.h"
using namespace std;



Biglietto::Biglietto(char* titolo, char* giorno, int orario, euro prezzo) {

	this->titolo = new char(strlen(titolo)+1);	
	strcpy(this->titolo, titolo);
	
	this->giorno = new char(strlen(giorno)+1);
	strcpy(this->giorno, giorno);
	
	this->orario = orario;
	this->prezzo = prezzo;
}

void Biglietto::setTitolo(char* titolo) {
	this->titolo = new char(strlen(titolo)+1);	
	strcpy(this->titolo, titolo);
}

char* Biglietto::getTitolo() const {
	return titolo;
}

void Biglietto::setGiorno(char* giorno) {
	this->giorno = new char(strlen(giorno)+1);
	strcpy(this->giorno, giorno);
}

char* Biglietto::getGiorno() const {
	return giorno;
}

void Biglietto::setOrario(int orario) {
	this->orario = orario;
}

int Biglietto::getOrario() const {
	return orario;
}

void Biglietto::setPrezzo(euro prezzo) {
	this->prezzo = prezzo;
}

euro Biglietto::getPrezzo() const {
	return prezzo;
}


int operator+(Biglietto const& b) {
	return b.getPrezzo();
}


Biglietto::~Biglietto() {
	delete[] titolo;
	delete[] giorno;
}

ostream& operator<<(ostream& os, const Biglietto& b) {
	os << b.getTitolo() << "," << b.getGiorno() << "," << b.getOrario() << "," << b.getPrezzo();
	return os;
}






