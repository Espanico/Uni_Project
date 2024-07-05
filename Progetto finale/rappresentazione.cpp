#include<iostream>
#include<string.h>
#include"rappresentazione.h"
using namespace std;



Rappresentazione::Rappresentazione(char* titolo, char* genere) {
	
	this->titolo = new char(strlen(titolo)+1);								//titolo punta ad uno spazio di memoria di dimensione della stringa da assegnare+1 per dar spazio allo \0
	
	
	strcpy(this->titolo, titolo);											// copiare la stringa nello spazio puntato da titolo
	
	this->genere = new char(strlen(genere)+1);								// facciamo lo stesso per il genere
	strcpy(this->genere, genere);
	
	this->type = 0;
}

void Rappresentazione::setTitolo(char* titolo) {
	
	if(this->titolo) { delete[] this->titolo; }								// controllo se esiste già un titolo e in tal caso libero la memoria
	
	
	this->titolo = new char(strlen(titolo)+1);								//titolo punta ad uno spazio di memoria di dimensione della stringa da assegnare+1 e poi copio la stringa interessata
	strcpy(this->titolo, titolo);
}

char* Rappresentazione::getTitolo() const {
	return this->titolo;
}

void Rappresentazione::setGenere(char* genere) {
	
	if(this->genere) { delete[] this->genere; }								// controllo se esiste già un genere e in tal caso libero la memoria
	
	
	this->genere = new char(strlen(genere)+1);								//genere punta ad uno spazio di memoria di dimensione della stringa da assegnare+1 e poi copio la stringa interessata
	strcpy(this->genere, genere);
}

char* Rappresentazione::getGenere() const {
	return this-> genere;
}

void Rappresentazione::setType(int n) {
	this->type = n;
}

int Rappresentazione::getType() const {
	return type;
}

Rappresentazione::~Rappresentazione() {
	delete[] this->titolo;
	delete[] this->genere;
}



ostream& operator<<(ostream& os, const Rappresentazione& r) {
	os << r.getTitolo() << "," << r.getGenere() << "," << endl;
	return os;
}








