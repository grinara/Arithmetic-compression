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
void BitsPlusFollow(int bit) {
	dayn.push_back(bit);
	//cout << bit;
	for (; bits > 0; bits--)
	{
		//cout << !bit;
		dayn.push_back(!bit);
	}

}
void code() {
	setlocale(LC_ALL, "Russian");
	string file_name_to_code;
	cout << "Введите имя файла для кодирования: ";
	cin >> file_name_to_code;
	ifstream file1;
	file1.open(file_name_to_code.c_str(), ios::in | ios::binary);
	if (file1) { cout << "Файл успешно открыт" << endl; }
	else { cout << "Файл не открыт" << endl; return; }
	ofstream filecode("112.txt", ios::out | ios::binary);
	map <char, int> m;
	file1.seekg(0, ios_base::end);
	//Получаем текущую позицию
	int filesize = file1.tellg();
	file1.clear();
	file1.seekg(0);
	while (!file1.eof()) {
		char c = file1.get();
		if (c != -1) { m[c]++; }
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
		
	}
	int l = 0, h = pow(2, 16) - 1, del = filesize;
	int First = (h + 1) / 4, Half = First * 2, Third = First * 3;
	file1.clear();
	file1.seekg(0);
	while (!file1.eof()) {
		char c = file1.get();
		if (c == -1) {}
		else {
            int r1 = (h - l + 1) ;
			h = l - 1 + ls1[c].right * r1 / del;
			l = l + ls1[c].left * r1 / del;
			while (true) {
				if (h < Half) {
					BitsPlusFollow(0);
				}
				else if (l >= Half) {
					BitsPlusFollow(1);
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
	while (dayn.size() % 8 != 0) {
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
	return;
}
