#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <string>
#include "Header.h"
using namespace std;
int bits = 0;
list<int> dayn;
void BitsPlusFollow(int bit, ofstream *f) {
	//cout << bit;
	dayn.push_back(bit);

	for (; bits > 0; bits--)
	{
	//	cout << "***" <<!bit;
		dayn.push_back(!bit);

	}
}
void code() {
	//string s1 = "Alice was beginning to get very tired of sitting by her nnnnnnnnn";
	ifstream file1("11.txt", ios::out | ios::binary);
	ofstream filecode("112.txt", ios::out | ios::binary);
	map <char, int> m;
	file1.seekg(0, ios_base::end);
	//Получаем текущую позицию
	int filesize = file1.tellg();
	file1.clear();
	file1.seekg(0);
	while (!file1.eof()) { //èù¸ì êîëè÷åñòâî âõîæäåíèé êàæäîãî ñèìâîëà
		char c = file1.get();
		if(c!=-1){ m[c]++; }
	}
	int msize = m.size();
	num ls1[255];
	map<char, int>::iterator i;
	float rayn = 0;
	for (i = m.begin(); i != m.end(); ++i) {
		ls1[i->first].c = i->first;
		ls1[i->first].count = i->second;
		ls1[i->first].left = rayn;
		rayn = ls1[i->first].left + ls1[i->first].count;
		ls1[i->first].right = rayn;
		cout << i->first << " " << ls1[i->first].left << "--00--" << ls1[i->first].right << endl;
	}
	
	double l = 0, h = pow(2, 16) - 1, del = filesize;
	double First = (h + 1) / 4, Half = First * 2, Third = First * 3;
	file1.clear();
	file1.seekg(0);
	while (!file1.eof()) {
		char c = file1.get();
		if(c==-1){}
		else {
			double l1 = l;
			l = l + ls1[c].left * ((h - l1 + 1) / del);
			h = l1 + ls1[c].right * (((h - l1 + 1) / del) - 1);
			//cout << l  << "--1--" << h << endl;
			while (true) {
				if (h < Half) {
					BitsPlusFollow(0, &filecode);
				}
				else if (l >= Half) {
					BitsPlusFollow(1, &filecode);
					l -= Half; h -= Half;

				}
				else if (l >= First && h < Third) {
					bits++;
					l -= First; h -= First;
				}
				else break;
				l += l;
				h += h + 1;
			}
		}

	}
	file1.clear();
	file1.seekg(0);
	dayn.push_back(1);
	dayn.push_back(0);
	if (dayn.size() < 16) { dayn.push_back(1); };

	while (dayn.size() < 15) {
		dayn.push_back(0);
	}
	while (dayn.size() % 8!=0) {
		dayn.push_back(0);
	}
	filecode.write((char*)&filesize, sizeof(int)); //длина файла
	filecode.write((char*)&msize, sizeof(int));//количество уникальных элементов
	for (i = m.begin(); i != m.end(); ++i) {
		int k = i->second;
		char kar = i->first;
		filecode.write((char*)&kar, sizeof(char)); //заносим символ
		filecode.write((char*)&k, sizeof(int));//сколько символ раз входит
	}
	list<int>::iterator kl;
	for (kl = dayn.begin(); kl != dayn.end(); ++kl) {cout << *kl;}
	int count = 7;
	int number = 0;
	while (!dayn.empty()) {
		number = number + (dayn.front() * pow(2, count));
		dayn.pop_front();
		if (count == 0) { filecode.write((char*)&number, sizeof(int)); count = 8; number = 0; }
		count--;
		
	}
	file1.close();
	filecode.close();
	decode();
	/*return;
	double test = 0;
	int x = 15;
	while (x >= 0 && !dayn.empty()) {
		test = test + (dayn.front() * pow(2, x));
		dayn.pop_front();
		x--;
	}
	l = 0, h = pow(2, 16) - 1;
	double freq = 0;
	double value = test;
	cout << endl;
	for (int i = 0; i < filesize; i++) {
		freq = ((value - l + 1) * del - 1) / (h - l + 1);
		int j = 0;
		for (; (ls1[j].right <= freq); j++);
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
				value = value * 2;
				value = value + dayn.front();
				dayn.pop_front();
			}
			else value += value;
		}
		cout << ls1[j].c; 
	}
	*/
}