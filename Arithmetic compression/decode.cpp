#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;
void decode() {
	string file_name_to_decode;
	cout << "Введите имя декадируемого файла: ";
	cin >> file_name_to_decode;
	ifstream filecod;
	filecod.open(file_name_to_decode.c_str(), ios::out | ios::binary);
	if (filecod) { cout << "Файл успешно открыт" << endl; }
	else { cout << "Файл не открыт" << endl; return; }
	int filesize;
	int msize;
	map<char, int> m;
	filecod.read((char*)&filesize, sizeof(int));
	filecod.read((char*)&msize, sizeof(int));
	list<int> dayn;
	char buff;
	int c;
	for (int i = 8; i < (msize * 5 + 4); i = i + 5) {
		filecod.seekg(i, ios::beg);
		filecod.read((char*)&buff, sizeof(char));
		filecod.seekg(i + 1, ios::beg);
		filecod.read((char*)&c, sizeof(int));
		m[buff] = c;
	}
	num ls1[255];
	map<char, int>::iterator i;
	float rayn = 0;
	for (i = m.begin(); i != m.end(); ++i) {
		ls1[i->first].c = i->first;
		ls1[i->first].count = i->second;
		ls1[i->first].left = rayn;
		rayn = ls1[i->first].left + ls1[i->first].count;
		ls1[i->first].right = rayn;
	}
	int kar;
	list <int> dayn2;
	dayn2.clear();
	while (!filecod.eof())
	{
		filecod.read((char*)&kar, sizeof(int));
		for (int i = 0; i < 8; i++) {
			dayn2.push_front(kar % 2);
			kar = kar / 2;
		}
		while (!dayn2.empty()) { dayn.push_back(dayn2.front()); dayn2.pop_front(); }
	}
	int test = 0;
	int x = 15;
	while (x >= 0 && !dayn.empty()) {
		test = test + (dayn.front() * pow(2, x));
		dayn.pop_front();
		x--;
	}
	int l = 0, h = pow(2, 16) - 1;
	int First = (h + 1) / 4, Half = First * 2, Third = First * 3;
	int freq = 0;
	int del = filesize;
	int value = test;
	for (int i = 0; i < filesize; i++) {
		int r1 = h - l + 1;
		int r2 = (value - l);
		freq = ((r2+1) * del - 1) / r1;
		int j = 0;
		for (; (ls1[j].right <= freq) && j<255; j++);
		h = l + ls1[j].right * r1 / del - 1;
		l = l + ls1[j].left * r1 / del;
		double l1 = l;
		l = l + ls1[j].left * ((h - l + 1) / del);
		h = l1 + ls1[j].right * ((h - l1 + 1) / del - 1);
		while (true) {
			if (h < Half);
			else if (l >= Half) {
				l -= Half; h -= Half; value -= Half;
			}
			else if ((l >= First) && (h < Third)) {
				l -= First; h -= First; value -= First;
			}
			else break;
			l += l; h += h + 1;
			if (!dayn.empty()) {
				value = value*2 + dayn.front();
				dayn.pop_front();
			}
			else value += value;
		}
		cout << ls1[j].c;
	}
}
