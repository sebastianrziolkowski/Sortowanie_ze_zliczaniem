#include <iostream>
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int ile = 0;
int iles = 0;
int rsum = 0;
bool x = false;

class Tabsort
{
public:
	int roz;
	int nroz;
	int q, p, o, y;
	int temp;
	int *tab;
	int *tabm;
	int *ttab;
	int *ttabm;
	bool quik;
	int quikint;
	void quiks();
	void settab();
	void Tabsorter();
	void Tabsorters();
	void Tabsumer();
	void pushtab();
	int binarysearch(int, int, int);
	void quicksort(int, int);
	void gettab();
	void gettab2();
	void sum();
	Tabsort();
	~Tabsort();
};

void Tabsort::pushtab() {
	int i = 0;
	while (i < roz) {
		if (ttab[i] == 0) {
			for (int j = i; j < roz; j++) {
				ttab[j] = ttab[j + 1];
				ttabm[j] = ttabm[j + 1];
			}

		}
		i++;
	}
}

void Tabsort::gettab() {
	o = 1;
	do {
		o++;
	} while ((tab[o] != 0) && (o < roz));


	cout << o << "  ";
	for (int i = 0; i < o; i++) {
		cout << tab[i] << " ";
		cout << tabm[i] << " ";
	}
	roz = o;
	nroz = o;
	cout << endl;
}


void Tabsort::gettab2() {
	o = 0;
	do {
		o++;
	} while ((ttab[o] != 0) && (o < roz));
	cout << o << "  ";
	for (int i = 0; i < o; i++) {
		cout << ttab[i] << " ";
		cout << ttabm[i] << " ";
	}
	cout << endl;
}




void Tabsort::sum() {
	int p = 0;
	for (int i = 0; i < roz;) {
		if (tab[i] == tab[i + 1]) {
			ttab[p] = tab[i];
			ttabm[p] = tabm[i];
			i++;
			while (ttab[p] == tab[i]) {
				ttabm[p] += tabm[i];
				i++;
			}
			p++;
		}
		else {
			ttab[p] = tab[i];
			ttabm[p] = tabm[i];
			i++;
			p++;
		}
	}
}

void Tabsort::quiks() {
	quik = true;
	quikint = 1;
	for (int i = 0; i < (roz - 1); i++) {
		if (tab[i] < tab[i + 1]) {
			quikint++;
		}
	}
	if (quikint == roz)quik = false;
}


void Tabsort::quicksort(int l, int r) {
	if (quik == true) {
		int i = l;
		int j = r;
		int x = tab[(l + r) >> 1];
		do {
			while (tab[i] < x) i++;
			while (tab[j] > x) j--;
			if (i <= j) {
				int temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
				temp = tabm[i];
				tabm[i] = tabm[j];
				tabm[j] = temp;
				i++;
				j--;
			}
		} while (i <= j);
		if (l < j) quicksort(l, j);
		if (r > i) quicksort(i, r);
	}
}

int Tabsort::binarysearch(int l, int r, int x) {
	int s = 0;
	while (l <= r) {
		s = (l + r) / 2;
		if (ttab[s] == x)
			return s;
		if (ttab[s] > x) r = s - 1;
		else l = s + 1;
	}
	return -1;
}


void Tabsort::Tabsumer() {
	quik = true;
	nroz = rsum;
	roz = rsum;
	tab = new int[rsum];
	tabm = new int[rsum];
	ttab = new int[rsum];
	ttabm = new int[rsum];
	for (int i = 0; i < rsum; i++) {
		tab[i] = 0;
		tabm[i] = 0;
		ttab[i] = 0;
		ttabm[i] = 0;
	}
}



void Tabsort::Tabsorter() {
	cin >> roz;
	tab = new int[roz];
	tabm = new int[roz];
	ttab = new int[roz];
	ttabm = new int[roz];
	for (int i = 0; i < roz; i++) {
		tab[i] = 0;
		ttab[i] = 0;
		tabm[i] = 0;
		ttabm[i] = 0;
	}
	for (int i = 0; i < roz; i++) {
		cin >> tab[i];
		cin >> tabm[i];
	}

}


void Tabsort::Tabsorters() {
	cin >> roz;
	tab = new int[roz];
	tabm = new int[roz];
	for (int i = 0; i < roz; i++) {
		tab[i] = 0;
		tabm[i] = 0;
	}
	for (int i = 0; i < roz; i++) {
		cin >> tab[i];
	}

}



Tabsort::Tabsort() { nroz = 0; q = 0; }

Tabsort::~Tabsort() {}


int test;
Tabsort *a;
int main()
{
	cin >> ile;

	// wpisz do tablicy //
	a = new Tabsort[ile + 2];
	a[ile + 1].Tabsumer();
	for (int j = 0; j < ile; j++) {
		a[j].Tabsorter();
	}


	// wpisz do tablicy szukania //
	a[ile + 1].Tabsorters();

	// rozmiar tablicy zsumowanej //
	for (int i = 0; i < ile; i++) {
		rsum += a[i].roz;
	}

	//Sumowanie tablic//
	a[ile + 2].Tabsumer();


	//wypisz na ekran//
	for (int i = 0; i < ile; i++) {
		a[i].quiks();
		a[i].quicksort(0, a[i].roz - 1);
		a[i].sum();
		a[i].gettab2();
	}

	// Wpisywanie w tablice //
	a[ile + 2].y = 0;
	int r = 0;
	int j = 0;
	int m = 0;
	for (int i = 0; i < ile; i++) {
		a[ile + 2].y = a[ile + 2].y + a[i].roz;
		r = a[ile + 2].y - a[i].roz;
		m = 0;
		while (r < a[ile + 2].y) {
			a[ile + 2].tab[j] = a[i].tab[m];
			a[ile + 2].tabm[j] = a[i].tabm[m];
			j++;
			m++;
			r++;
		}
	}


	a[ile + 2].quicksort(0, (a[ile + 2].y - 1));
	a[ile + 2].sum();
	a[ile + 2].gettab2();

	/*          DO OPtymalizacji!           */

	int indeks = -1;
	for (int i = 0; i < a[ile + 1].roz; i++) {
		indeks = a[ile + 2].binarysearch(0, a[ile + 2].o, a[ile + 1].tab[i]);
		if (indeks >= 0) {
			cout << a[ile + 2].ttabm[indeks] << " ";
		}
		if (indeks < 0) {
			cout << "0 ";
		}
	}
	cout << endl;

	return 0;
}