#include"spettacoli.h"
#include"spettacolo.h"
#include<iostream>
using namespace std;

Spettacoli::Spettacoli() {
	p = NULL;
	nelem = 0;
}

void Spettacoli::inserisci(Rappresentazioni* R, Spettacolo* temp) {									//inserisce lo spettacolo nella lista
	if(p==NULL) {
		p = new Nodospettacolo;
		p->next = NULL;
		p->valore = temp;
	}
	else {
		Nodospettacolo* q = new Nodospettacolo;
		q->next = p;
		q->valore = temp;
		
		p=q;
	}
	nelem++;
}

void Spettacoli::mostraTitoli() {																	//mostra i titoli
	if(!nelem) {
		cout << "Nessun titolo nella lista\n";
	}
	else {
		cout << "I titoli disponibili sono:\n";
	}
	
	Nodospettacolo* q = p;
	
	for(int i=0; i<nelem; i++) {
		cout << i+1 << ") " << q->valore->getR()->getTitolo() << endl;
		q=q->next;
	}
}


Nodospettacolo* Spettacoli::getP() const {
	return p;
}

int Spettacoli::getNelem() const {
	return nelem;
}

int Spettacoli::find(char* str) const {
	bool found = false;
	int x = 0;
	Nodospettacolo* q = p;
	
	
	if(strcmp(q->valore->getR()->getTitolo(),str) == 0) {											//controlla se il primo titolo coincide con la stringa
		found = true;
		return 1;
	}
		
	while(!found && q!=NULL) {																		//controlla tutti gli altri
		
		if(strcmp(q->valore->getR()->getTitolo(),str) == 0) {
			found = true;
			x++;
			return x;
		} else {
			x++;
			q = q->next;
		}
	}
	return 0;
}


void Spettacoli::cancella(int n) {
	if(p!=NULL) {
		if(n==0) {
			Nodospettacolo* target = p;
			p=p->next;
			delete target;
			nelem--;
		} else {
			Nodospettacolo* target = p;
			for(int i=0; i<n-1; i++) {
				target = target->next;
			}
			Nodospettacolo* q = target;
			target = target->next;
			q->next = target->next;
			delete target;
			nelem--;
		}
	}
}

Spettacoli::~Spettacoli() {
	if(p != NULL) {
		Nodospettacolo* q = p;
		for(int i=0; i<nelem; i++) {
			Nodospettacolo* target = q;
			q=q->next;
			delete target->valore;
		}
	}
}











ostream& operator<<(ostream& os, const Spettacoli& S) {
	if(S.getP() != NULL) {
		Nodospettacolo* q = S.getP();
		for(int i=0; i<S.getNelem(); i++) {
			os << i+1 << ") " << q->valore->getR()->getTitolo() << " " << q->valore->getGiorno() 
			<< " " << q->valore->getOrario()/100 << ":" << q->valore->getOrario()%100;
			if(q->valore->getOrario()%100 == 0) {
				os << "0";
			}
			os << endl << endl;
			q=q->next;
		}
	}
	return os;
}







