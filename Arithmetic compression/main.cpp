#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <string>
#include "Header.h"
void main() {
	setlocale(LC_ALL, "Russian");
	int check;

	while (true) {
		cout << "Для кодирования введите 0" << endl;
		cout << "Для разкодирования введите 1" << endl;
		cout << "Для выхода введите что угодно" << endl;
		scanf_s("%d", &check);
		if (check == 0) { code(); }
		else if (check == 1) { decode(); }
		else { return; }
	}
}