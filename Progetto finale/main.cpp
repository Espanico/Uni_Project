#include<iostream>
#include<string.h>
#include"rappresentazione.h"
#include"film.h"
#include"esibizione.h"
#include"rappresentazioni.h"
#include"spettacolo.h"
#include"spettacoli.h"
#include"funzioni.h"
#include"biglietto.h"
#include"biglietti.h"


using namespace std;
typedef float euro;
#define CLEAR "\033[2J\033[1;1H"

int main() {	
	cout << CLEAR;
	Rappresentazioni* R = new Rappresentazioni();
	Spettacoli* S = new Spettacoli();
	Biglietti* B = new Biglietti();

	loadRappresentazioni(R);
	loadSpettacoli(S,R);

	bool attivo = 1;
	while(attivo) {
		cout << "Cosa vuoi fare? Premere:\n0) Per uscire\n1) Per Aggiungere una Rappresentazione\n"
				"2) Per dare un orario ad una Rappresentazione (creare uno Spettacolo)\n"
				"3) Per rimuovere una Rappresentazione\n4) Per rimuovere uno Spettacolo\n5) Per mostrare le Rappresentazioni disponibili\n"
				"6) Per mostrare gli Spettacoli disponibili\n7) Per vendere un biglietto"
				"\n8) Per vedere gli incassi di oggi\n\nRISPOSTA: ";
		int risposta;
		cin >> risposta;
		
		switch(risposta) {
			case 0:
				attivo = 0;
				break;
			case 1:
				aggiungiRappresentazione(R);
				break;
			case 2:
				aggiungiSpettacolo(R,S);
				break;
			case 3:
				rimuoviRappresentazione(R,S);
				break;
			case 4:
				rimuoviSpettacolo(S);
				break;
			case 5:
				elencaRappresentazioni(R);
				break;
			case 6:
				elencaSpettacoli(S);
				break;
			case 7:
				vendiBiglietto(S,B);
				break;
			case 8:
				incassiDiOggi(B);
				break;
		}
	
	}
	delete S;
	delete R;
	delete B;
	
	return 0;
}
