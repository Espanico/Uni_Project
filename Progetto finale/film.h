#ifndef _FILM_H_
#define _FILM_H_

#include"rappresentazione.h"
#include<iostream>
#include<string.h>

using namespace std;


class Film: public Rappresentazione {
	private:
		char* attori;
		int durata;
		bool treD;
	
	public:
		Film(char*, int, bool, char*, char*);
	
		void setAttori(char*);
		char* getAttori() const;
		void setDurata(int);
		int getDurata() const;
		void setTreD(bool);
		bool getTreD() const;
		
		friend ostream& operator<<(ostream& os, const Film& r);
		
		~Film();
};

#endif
