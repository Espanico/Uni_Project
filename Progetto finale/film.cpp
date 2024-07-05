#include<iostream>
#include<string.h>
#include"rappresentazione.h"
#include"film.h"
using namespace std;




Film::Film(char* attori, int durata, bool treD, char* titolo, char* genere) : Rappresentazione(titolo, genere) {
	this->attori = new char(strlen(attori)+1);
	strcpy(this->attori, attori);
	
	this->durata  = durata;
	this->treD = treD;
	
	setType(1);
}

void Film::setAttori(char* attori) {
	if(this->attori) { delete[] this->attori; }
	
	this->attori = new char(strlen(attori)+1);
	strcpy(this->attori, attori);
}

char* Film::getAttori() const {
	return this->attori;
}

void Film::setDurata(int durata) {
	this->durata = durata;
}

int Film::getDurata() const {
	return this->durata;
}

void Film::setTreD(bool treD) {
	this->treD = treD;
}

bool Film::getTreD() const {
	return treD;
}


Film::~Film() {
	delete[] attori;
}









ostream& operator<<(ostream& os, const Film& r) {
	os << r.getTitolo() << "," << r.getGenere() << "," << r.getAttori() << "," << r.getDurata() << "," << r.getTreD() << endl;
	return os;
}






