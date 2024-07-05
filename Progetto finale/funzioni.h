#include<iostream>
#include"string.h"
#include"rappresentazioni.h"
#include"spettacoli.h"
#include"rappresentazione.h"
#include"film.h"
#include"esibizione.h"
#include"biglietto.h"
#include"biglietti.h"



#ifndef FUNZIONI
#define FUNZIONI
	void aggiungiRappresentazione(Rappresentazioni*);
	void aggiungiSpettacolo(Rappresentazioni*, Spettacoli*);
	
	void rimuoviRappresentazione(Rappresentazioni*, Spettacoli*);
	void rimuoviSpettacolo(Spettacoli*);
	
	void elencaRappresentazioni(Rappresentazioni*);
	void elencaSpettacoli(Spettacoli*);
	
	void loadRappresentazioni(Rappresentazioni*); 
	void saveRappresentazione(Rappresentazione*);
	void aggiornaFilms(Rappresentazioni*);
	void aggiornaEsibizioni(Rappresentazioni*);
	
	void saveSpettacolo(Spettacolo*);
	void loadSpettacoli(Spettacoli*, Rappresentazioni*);
	void aggiornaSpettacoli(Spettacoli*);
	
	void vendiBiglietto(Spettacoli*, Biglietti*);
	void incassiDiOggi(Biglietti*);
	
	template <class T>
	void mostra(const T& obj) {
		cout << obj << endl;
	}
#endif
