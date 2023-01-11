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
void BitsPlusFollow(int bit) {// заносим биты
	dayn.push_back(bit); 
	for (; bits > 0; bits--) 
	{
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
	himan m[255];
	file1.seekg(0, ios_base::end);
	int filesize = file1.tellg(); //кол-во символов в файле
	file1.clear();
	file1.seekg(0);
	while (!file1.eof()) { //ищем уникальные символы и их количество
		char  c0 = file1.get();
		for (int i = 0; i < 255; i++) {
			if (m[i].c == 0) {
				m[i].c = c0;
				m[i].count++;
				break;
			}
			if (m[i].c == c0) {
				m[i].count++;
				break;
			}
		}
	}
	int msize=0;
	for (int i = 0; i < 255; i++) { if (m[i].count > 0) { msize++; } }
	int step = 255 / 2;       // в группе выбранных элементов проводим сортировку
	while (step > 0) {       // прямой вставкой
		for (int i = step; i < 255; i++) {
			int j = i;
			himan x = m[j];
			while ((j >= step) && (x.count < m[j - step].count)) { //вместо обменов сделай сдвиги
				m[j] = m[j - step];
				j = j - step;
			}
			m[j] = x;
		}
		step = step / 2;     // уменьшаем шаг, повторям пока шаг больше нуля
	}
	num ls1[255];
	int rayn = 0;
	for (int i=0; i<255; i++) { //список элементов с их границами
		if (m[i].count > 0) {
			ls1[i].c = m[i].c;
			ls1[i].count = m[i].count;
			ls1[i].left = rayn;
			rayn = ls1[i].left + ls1[i].count;
			ls1[i].right = rayn;
		}
	}
	int l = 0, h = pow(2, 16) - 1, del = filesize;
	int First = (h + 1) / 4, Half = First * 2, Third = First * 3;
	file1.clear();
	file1.seekg(0);
	while (!file1.eof()) { 
		char c0 = file1.get();
		int j = 0;
		for (; m[j].c != c0 && j<255; j++);//считаем границы
			int r1 = (h - l + 1);
			h = l - 1 + ls1[j].right * r1 / del;
			l = l + ls1[j].left * r1 / del;
			while (true) {
				if (h < Half) { //если весь интервал слева
					BitsPlusFollow(0);
				}
				else if (l >= Half) { //если весь интервал справа
					BitsPlusFollow(1);
					l -= Half; h -= Half;

				}
				else if (l >= First && h < Third) { //если по разные стороны
					bits++;//накапливаем биты
					l -= First; h -= First;
				}
				else break;
				l += l;
				h += h + 1;
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
	for (int i=0; i < 255; i++) {
		if (m[i].count > 0) {
			int k = m[i].count;
			char kar = m[i].c;
			filecode.write((char*)&kar, sizeof(char)); //заносим символ
			filecode.write((char*)&k, sizeof(int));//сколько символ раз входит
		}
	}
	int count = 7;
	int number = 0;
	while (!dayn.empty()) { //заносим в файл биты
		number = number + (dayn.front() * pow(2, count));
		dayn.pop_front();
		if (count == 0) { filecode.write((char*)&number, sizeof(int)); count = 8; number = 0; }
		count--;

	}
	file1.close();
	filecode.close();
	return;
}
