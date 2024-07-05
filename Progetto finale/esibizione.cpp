#include<iostream>
#include<string.h>
#include"rappresentazione.h"
#include"esibizione.h"
using namespace std;

Esibizione::Esibizione(int atti, char* titolo, char* genere) : Rappresentazione(titolo, genere) {
	this->atti = atti;
	
	setType(2);
}

void Esibizione::setAtti(int atti) {
	this->atti = atti;
}

int Esibizione::getAtti() const {
	return this->atti;
}





ostream& operator<<(ostream& os, const Esibizione& r) {
	os << r.getTitolo() << "," << r.getGenere() << "," << r.getAtti() << endl;
	return os;
}
