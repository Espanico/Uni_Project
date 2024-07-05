#include<iostream>
#include<fstream>
#include<string.h>
#include<exception>
#include"funzioni.h"

using namespace std;
#define CLEAR "\033[2J\033[1;1H"

void aggiungiRappresentazione(Rappresentazioni* R) {
	cout << CLEAR << "Vuoi aggiungere:\n1) Film\n2) Esibizione Teatrale\n\nRISPOSTA: ";
	int risposta;
	cin >> risposta;
	cout << CLEAR;
	cin.ignore();
	char t[100];
	char g[100];
	
	if(risposta==1) {																		//creazione Film
	
		cout << "Titolo del Film: ";
		cin.getline(t,100);
		
		cout << "Genere del Film: ";
		cin.getline(g,100);
		
		cout << "Attori del film: ";
		char a[200];
		cin.getline(a,100);
		cout << "Durata in minuti del film: ";
		int d;
		cin >> d;
		cout << "Film in 3D? ";
		bool tr;
		cin >> tr;
		
		Film* f = new Film(a,d,tr,t,g);
		
		R->inserisci(f);
		saveRappresentazione(f);
		
		
	} else if(risposta==2) {																//creazione Esibizione
		cout << "Titolo dell'esibizione: ";
		cin.getline(t,100);
		
		cout << "Genere dell'esibizione: ";
		cin.getline(g,100);
		
		cout << "Numero di atti: ";
		int atti;
		cin >> atti;
		
		Esibizione* e = new Esibizione(atti,t,g);
		R->inserisci(e);
		saveRappresentazione(e);
		
	}
}


void aggiungiSpettacolo(Rappresentazioni* R, Spettacoli* S) {
	R->mostraTitoli();																		//mostra le Rappresentazioni
	
	int n;
	do {
		cout << "Digitare il numero della rappresentazione: ";
		cin >> n;
	} while(n>R->getNelem() || n<1);
	n--;
	
	Spettacolo* s = new Spettacolo(R,n);													//crea uno spettacolo con la n-esima Rappresentazione
	
	cout << "Quale giorno della settimana: ";
	char g[20];
	cin >> g;
	
	cout << "Orario: ";
	int o;
	cin >> o;
	while(o<0 || 0>2400) {
		cout << "\nInserire un intero compreso tra 0 e 2400: ";
		cin >> o;
	}
	
	cout << "Prezzo: ";
	euro pr;
	cin >> pr;
	
	s->setGiorno(g);
	s->setOrario(o);
	s->setPrezzo(pr);
	
	S->inserisci(R,s);
	saveSpettacolo(s);
	cout << CLEAR;
}

void rimuoviRappresentazione(Rappresentazioni* R, Spettacoli* S) {
	cout << CLEAR << "RAPPRESENTAZIONI DISPONIBILI:\n\n" << *R 
	<< "\nQuale Rappresentazione rimuovere? ";
	int r;
	cin >> r;																				//rimuoviamo Rappresentazione numero r
	cout << "RIMUOVERE UNA RAPPRESENTAZIONE ELIMINERA' TUTTI I RELATIVI SPETTACOLI."
	"\n\nProseguire? \n0) No\n1) Si\n\nRisposta: ";
	int conferma;
	cin >> conferma;
	if(conferma) {
		Nodo* q = R->getP();
		for(int i=0; i<r-1; i++) {
			q=q->next;																		//puntiamo alla Rappresentazione
		}
		char* str = new char(strlen(q->valore->getTitolo())+1);								//str == titolo Rappresentazione
		strcpy(str, q->valore->getTitolo());
		
		while(S->find(str)!=0) {															//loop finchè troviamo spettacoli intitolati str
			int n = S->find(str);
			S->cancella(n-1);																//cancello lo spettacolo
		}
		int aggFile = q->valore->getType();
		R->cancellaRappresentazione(r-1);													//cancella la rappresentazione
		
		if(aggFile == 1) {
			aggiornaFilms(R);																//sovrascrivo i file di salvataggio
		} else {
			aggiornaEsibizioni(R);
		}
	}
	cout << CLEAR;
}

void rimuoviSpettacolo(Spettacoli* S) {
	if(S->getNelem()>0) {
		elencaSpettacoli(S);
		cout << "Quale eliminare? ";
		int n;
		cin >> n;
		S->cancella(n-1);																	//elimina l' n-esimo spettacolo
		aggiornaSpettacoli(S);																//sovrascrivo i file di salvataggio
		cout << CLEAR << "Spettacolo rimosso\n\n";
	}
}



void elencaRappresentazioni(Rappresentazioni* R) {
	cout << CLEAR << "RAPPRESENTAZIONI DISPONIBILI:\n\n";
	
	mostra(*R);																				// USO TEMPLATE
}


void elencaSpettacoli(Spettacoli* S) {
	cout << CLEAR;
	
	mostra(*S);																				// USO TEMPLATE
}



void loadRappresentazioni(Rappresentazioni* R) {
	ifstream fin;
	try{
		fin.open("films.txt");																//carico dal file films.txt
		
		if(!fin) {
			throw std::ios_base::failure("Failed to open file");
			
		} else {
			string t;																		//prendo tutti gli attributi
			string g;
			string a;
			string D;
			int d;
			string TR;
			bool tr;
			
			char str[400];
			
			while(fin.getline(str,400, '\n')) {												//loop per ogni riga del file
			
				string s = str;
				
				t = s.substr(0, s.find(','));												//la riga viene divisa ogni volta che c'è una virgola
				s.erase(0, s.find(',')+1);
				g = s.substr(0, s.find(','));
				s.erase(0, s.find(',')+1);
				a = s.substr(0, s.find(','));
				s.erase(0, s.find(',')+1);
				D = s.substr(0, s.find(','));
				s.erase(0, s.find(',')+1);
				TR = s.substr(0, s.find(','));
				s.erase(0, s.find(',')+1);
				
				d = atoi(D.data());
				tr = atoi(TR.data());
				
				Film* f = new Film(a.data(),d,tr,t.data(),g.data());
				R->inserisci(f);
			
			}		
		}
		fin.close();
	} catch(const std::ios_base::failure& e) {
		cerr << "Error " << e.what() << endl;												//errore per operazioni I/O (lettura, apertura...)
	} catch(const std::exception& e) {
		cerr << "Error " << e.what() << endl;												//errore generico
	}
	
	
	try{
		fin.open("esibizioni.txt");															//carico dal file esibizioni.txt
		
		if(!fin) {
			throw std::ios_base::failure("Failed to open file");
		} else {
			string t;
			string g;
			string A;
			int a;
			char str[400];
			
			while(fin.getline(str,400, '\n')) {
			
				string s = str;
				
				t = s.substr(0, s.find(','));
				s.erase(0, s.find(',')+1);
				g = s.substr(0, s.find(','));
				s.erase(0, s.find(',')+1);
				A = s.substr(0, s.find(','));
				s.erase(0, s.find(',')+1);
				
				
				a = atoi(A.data());
			
				Esibizione* e = new Esibizione(a, t.data(), g.data());
				R->inserisci(e);
			}
		}
		fin.close();
	} catch(const std::ios_base::failure& e) {
		cerr << "Error " << e.what() << endl;												//errore per operazioni I/O (lettura, apertura...)
	} catch(const std::exception& e) {
		cerr << "Error " << e.what() << endl;												//errore generico
	}
}


void saveRappresentazione(Rappresentazione* r) {											//dopo aver creato una Rappresentazione va salvata su file
	ofstream fout;
	if(r->getType()==1) {
		try{
			fout.open("films.txt", ios_base::app);
			if(!fout) {
				throw std::ios_base::failure("Failed to open file");
			} else {
				fout << static_cast<const Film&>(*r);
			}
			fout.close();
		}catch(const std::ios_base::failure& e) {
			cerr << "Error " << e.what() << endl;											//errore per operazioni I/O (lettura, apertura...)
		} catch(const std::exception& e) {
			cerr << "Error " << e.what() << endl;											//errore generico
		}
		cout << CLEAR << "Film aggiunto\n\n";
		
	} else if(r->getType()==2) {
	
		try {
			fout.open("esibizioni.txt", ios_base::app);
			if(!fout) {
				throw std::ios_base::failure("Failed to open file");
			} else {
				fout << static_cast<const Esibizione&>(*r);
			}
			fout.close();
		}catch(const std::ios_base::failure& e) {
			cerr << "Error " << e.what() << endl;											//errore per operazioni I/O (lettura, apertura...)
		} catch(const std::exception& e) {
			cerr << "Error " << e.what() << endl;											//errore generico
		}
		
		cout << CLEAR << "Esibizione aggiunta\n\n";
	}
}

void aggiornaFilms(Rappresentazioni* R) {
	ofstream fout;
	try {
		fout.open("films.txt");
		if(!fout) {
			throw std::ios_base::failure("Failed to open file");
		} else {
			Nodo* q = R->getP();
			for(int i=0; i<R->getNelem(); i++) {											//q->valore == Rappresentazione*
				if(q->valore->getType() == 1) {
					fout << static_cast<const Film&>(*q->valore);
				}
				q = q->next;
			}
		}
		fout.close();
	}catch(const std::ios_base::failure& e) {
		cerr << "Error " << e.what() << endl;												//errore per operazioni I/O (lettura, apertura...)
	} catch(const std::exception& e) {
		cerr << "Error " << e.what() << endl;												//errore generico
	}
}

void aggiornaEsibizioni(Rappresentazioni* R) {
	ofstream fout;
	try {
		fout.open("esibizioni.txt");
		if(!fout) {
			throw std::ios_base::failure("Failed to open file");
		} else {
			Nodo* q = R->getP();
			for(int i=0; i<R->getNelem(); i++) {											//q->valore == Esibizione* 
				if(q->valore->getType() == 2) {
					fout << static_cast<const Esibizione&>(*q->valore);
				}
				q = q->next;
			}
		}
		fout.close();
	}catch(const std::ios_base::failure& e) {
		cerr << "Error " << e.what() << endl;												//errore per operazioni I/O (lettura, apertura...)
	} catch(const std::exception& e) {
		cerr << "Error " << e.what() << endl;												//errore generico
	}
}



void saveSpettacolo(Spettacolo* s) {
	ofstream fout;
	try {
		fout.open("spettacoli.txt", ios_base::app);
		if(!fout) {
			throw std::ios_base::failure("Failed to open file");
		} else {
			fout << *s;
			fout.close();
		}
	}catch(const std::ios_base::failure& e) {
		cerr << "Error " << e.what() << endl;												//errore per operazioni I/O (lettura, apertura...)
	} catch(const std::exception& e) {
		cerr << "Error " << e.what() << endl;												//errore generico
	}
}

void loadSpettacoli(Spettacoli* S, Rappresentazioni* R) {
	ifstream fin;
	
	try {
		fin.open("spettacoli.txt");
		
		if(!fin) {
			throw std::ios_base::failure("Failed to open file");
		} else {
			string t;
			string g;
			string O;
			string PR;
			euro pr;
			int o;
			char str[400];
			
			while(fin.getline(str,400, '\n')) {
			
				string s = str;
				
				t = s.substr(0, s.find(','));
				s.erase(0, s.find(',')+1);
				g = s.substr(0, s.find(','));
				s.erase(0, s.find(',')+1);
				O = s.substr(0, s.find(','));
				s.erase(0, s.find(',')+1);
				PR = s.substr(0, s.find(','));
				s.erase(0, s.find(',')+1);
				
				
				o = atoi(O.data());
				pr = atof(PR.data());
				
				if(R->find(t.data())!=0) {
					Spettacolo* spet = new Spettacolo(R, (R->find(t.data()))-1);
					spet->setGiorno(g.data());
					spet->setOrario(o);
					spet->setPrezzo(pr);
					S->inserisci(R,spet);
				}
			}
		}
		fin.close();
	}catch(const std::ios_base::failure& e) {
		cerr << "Error " << e.what() << endl;												//errore per operazioni I/O (lettura, apertura...)
	} catch(const std::exception& e) {
		cerr << "Error " << e.what() << endl;												//errore generico
	}
}

void aggiornaSpettacoli(Spettacoli* S) {
	ofstream fout;
	try{
		fout.open("spettacoli.txt");
		if(!fout) {
			throw std::ios_base::failure("Failed to open file");
		} else {
			Nodospettacolo* q = S->getP();
			for(int i=0; i<S->getNelem(); i++) {												//q->valore == Spettacolo*
				fout << *q->valore;
				q = q->next;
			}
		}
		fout.close();
	}catch(const std::ios_base::failure& e) {
		cerr << "Error " << e.what() << endl;												//errore per operazioni I/O (lettura, apertura...)
	} catch(const std::exception& e) {
		cerr << "Error " << e.what() << endl;												//errore generico
	}
}


void vendiBiglietto(Spettacoli* S, Biglietti* B) {
	elencaSpettacoli(S);
	cout << "Scegliere uno spettacolo: ";
	int n;
	cin >> n;
	
	while(n<0 || n>S->getNelem()) {
		cout << "Inserire un numero intero valido: ";
		cin >> n;
	}
	n--;
	Nodospettacolo* q = S->getP();
	for(int i=0; i<n; i++) {
		q=q->next;
	}
	
	Biglietto* b = new Biglietto(q->valore->getR()->getTitolo(), q->valore->getGiorno(), q->valore->getOrario(), q->valore->getPrezzo());
	
	ofstream fout;
	try {
		fout.open("biglietto.txt");
		if(!fout) {
			throw std::ios_base::failure("Failed to open file");
		} else { 
			fout << "Spettacolo: " << b->getTitolo() << "\nPer il giorno: " << b->getGiorno() << " alle ore: " << b->getOrario()/100 << ":" << b->getOrario()%100;
			if(b->getOrario()%100 == 0) {
				fout << "0";
			}
		}
		fout.close();
	} catch(const std::ios_base::failure& e) {
		cerr << "Error " << e.what() << endl;												//errore per operazioni I/O (lettura, apertura...)
	} catch(const std::exception& e) {
		cerr << "Error " << e.what() << endl;												//errore generico
	}
	
	
	try {
		fout.open("biglietti.txt", ios_base::app);
		if(!fout) {
			throw std::ios_base::failure("Failed to open file");
		} else { 
			fout << *b << endl;
		}
		fout.close();
	} catch(const std::ios_base::failure& e) {
		cerr << "Error " << e.what() << endl;												//errore per operazioni I/O (lettura, apertura...)
	} catch(const std::exception& e) {
		cerr << "Error " << e.what() << endl;												//errore generico
	}
	B->inserisci(b);
}

void incassiDiOggi(Biglietti* B) {
	cout <<CLEAR<< *B << endl;
}











