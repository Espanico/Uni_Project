#ifndef _ESIBIZIONE_H_
#define _ESIBIZIONE_H_

#include"rappresentazione.h"
#include<iostream>
#include<string.h>

using namespace std;


class Esibizione: public Rappresentazione {
	private:
		int atti;
	
	public:
		Esibizione(int, char*, char*);
	
		void setAtti(int);
		int getAtti() const;
		
		friend ostream& operator<<(ostream& os, const Esibizione& r);
		
		
};

#endif
