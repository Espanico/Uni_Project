#ifndef _BIGLIETTO_H_
#define _BIGLIETTO_H_

#include<iostream>
#include<string.h>

using namespace std;
typedef float euro;



class Biglietto {
	private:
		char* titolo;
		char* giorno;
		int orario;
		euro prezzo;
	
	public:
		Biglietto(char*, char*, int, euro);
	
		void setTitolo(char*);
		char* getTitolo() const;
		void setGiorno(char*);
		char* getGiorno() const;
		void setOrario(int);
		int getOrario() const;
		void setPrezzo(euro);
		euro getPrezzo() const;

		int operator+(Biglietto const& b);
		friend ostream& operator<<(ostream& os, const Biglietto& b);
		
		~Biglietto();
};

#endif
