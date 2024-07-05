#ifndef _SPETTACOLO_H_
#define _SPETTACOLO_H_

#include<iostream>
#include<string.h>
#include"rappresentazione.h"
#include"film.h"
#include"esibizione.h"
#include"rappresentazioni.h"

using namespace std;
typedef float euro;


class Spettacolo {
	private:
		Rappresentazione* r;
		char* giorno;
		int orario;
		euro prezzo;
	
	public:
		Spettacolo(Rappresentazioni*, int);
		Spettacolo(Rappresentazione*, char*, int, euro);
		
		void setGiorno(char*);
		char* getGiorno() const;
		void setOrario(int);
		int getOrario() const;
		void setPrezzo(euro);
		euro getPrezzo() const;
		
		
		Rappresentazione* getR() const;
		
		friend ostream& operator<<(ostream& os, const Spettacolo& s);
		
		~Spettacolo();
};

#endif
