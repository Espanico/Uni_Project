#include"rappresentazioni.h"

#include<iostream>
using namespace std;

Rappresentazioni::Rappresentazioni() {
	p = NULL;
	nelem = 0;
}



void Rappresentazioni::inserisci(Rappresentazione* r) {
	if(p==NULL) {
		p = new Nodo;
		p->next = NULL;
		p->valore = r;
	}
	else {
		Nodo* q = p;
		bool inserito = false;
		
		if(strcmp(r->getTitolo(),q->valore->getTitolo())<0) {
			Nodo* n = new Nodo;
			n->next = q;
			n->valore = r;
			p=n;
			inserito = true;
		}
		while(!inserito && q!=NULL) {
			if(q->next==NULL) {
				Nodo* n = new Nodo;
				n->next = NULL;
				n->valore = r;
				q->next = n;
				inserito = true;
			} else if(strcmp(r->getTitolo(),q->valore->getTitolo())>0 && strcmp(r->getTitolo(),q->next->valore->getTitolo())<0) {
				Nodo* n = new Nodo;
				n->next = q->next;
				n->valore = r;
				q->next = n;
				inserito = true;
			}
			q=q->next;
		}		
	}
	nelem++;
}

void Rappresentazioni::mostraTitoli() {
	if(!nelem) {
		cout << "Nessun titolo nella lista\n";
	}
	else {
		cout << "I titoli disponibili sono:\n";
	}
	
	Nodo* q = p;
	
	for(int i=0; i<nelem; i++) {
		cout << i+1 << ") " << q->valore->getTitolo() << endl;
		q=q->next;
	}
}


Nodo* Rappresentazioni::getP() const {
	return p;
}

int Rappresentazioni::getNelem() const {
	return nelem;
}


int Rappresentazioni::find(char* str) const {
	bool found = false;
	int x = 0;
	Nodo* q = p;
	
	if(strcmp(q->valore->getTitolo(),str) == 0) {
		found = true;
		return 1;
	}
	
	while(!found && q!=NULL) {
		
		if(strcmp(q->valore->getTitolo(),str) == 0) {
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

void Rappresentazioni::cancellaRappresentazione(int n) {
	if(p!=NULL) {
		if(n==0) {
			Nodo* target = p;
			p=p->next;
			delete target;
			nelem--;
		} else {
			Nodo* target = p;
			for(int i=0; i<n-1; i++) {
				target = target->next;
			}
			Nodo* q = target;
			target = target->next;
			q->next = target->next;
			delete target;
			nelem--;
		}
	}
}







Rappresentazioni::~Rappresentazioni() {
	if(p != NULL) {
		Nodo* q = p;
		for(int i=0; i<nelem; i++) {
			Nodo* target = q;
			q=q->next;
			delete target->valore;
		}
	}
}









ostream& operator<<(ostream& os, const Rappresentazioni& R) {
	if(R.getP() != NULL) {
		Nodo* q = R.getP();
		for(int i=0; i<R.nelem; i++) {
			if(q->valore->getType() == 1) {
				os << i+1 << ") Titolo: " << q->valore->getTitolo() << "\n   Genere: " << q->valore->getGenere() << "\n   Attori: " << static_cast<const Film*>(q->valore)->getAttori() 
				<< "\n   Durata: " << static_cast<const Film*>(q->valore)->getDurata() << "'\n   3D: ";
				if(static_cast<const Film*>(q->valore)->getTreD()) {
					os << "Si\n\n";
				} else {
					os << "No\n\n";
				}
				q=q->next;
			} else if(q->valore->getType() == 2) {
				os << i+1 << ") Titolo: " << q->valore->getTitolo() << "\n   Genere: " << q->valore->getGenere() << "\n   Atti: " <<
					static_cast<const Esibizione*>(q->valore)->getAtti() << endl << endl;
				q=q->next;
			}
		}
	}
	return os;
}






