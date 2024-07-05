#ifndef _RAPPRESENTAZIONE_H_
#define _RAPPRESENTAZIONE_H_

#include<iostream>
#include<string.h>

using namespace std;


class Rappresentazione {
	private:
		int type;
		char* titolo;
		char* genere;
	
	public:
		Rappresentazione(char*, char*);
	
		void setTitolo(char*);
		char* getTitolo() const;
		void setGenere(char*);
		char* getGenere() const;
		void setType(int);
		int getType() const;

		
		friend ostream& operator<<(ostream& os, const Rappresentazione& r);
		
		~Rappresentazione();
};

#endif
