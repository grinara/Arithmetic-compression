#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <string>
using namespace std;
void Print(int n) {
	if (n == 0) { return; }
	Print(n / 2);
	cout << n % 2;
}
struct num {
	char c = 0;
	int count = 0;
	double left = 0;
	double right = 0;
};
int bits = 0;
list<int> dayn;
void BitsPlusFollow(int bit) {
	cout << bit;
	dayn.push_back(bit);

	for (; bits > 0; bits--)
	{
		cout << "***" <<!bit;
		dayn.push_back(!bit);

	}
}
void main() {
	string s1 = "Alice was beginning to get very tired of sitting by her nnnnnnnnn";
	map <char, int> m;
	for (int i = 0; i < s1.size(); i++) {
		m[s1[i]]++;
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
		cout << i->first << " " << ls1[i->first].left << "--00--" << ls1[i->first].right << endl;
	}
	
	double l = 0, h = pow(2, 16) - 1, del = s1.size();
	double First = (h + 1) / 4, Half = First * 2, Third = First * 3;

	for (int i = 0; i < s1.size(); i++) {
		char c = s1[i];
		double l1 = l;
		l = l + ls1[c].left * ((h - l1 + 1) / del);
		h = l1 + ls1[c].right * (((h - l1 + 1) / del) - 1);
		//cout << l  << "--1--" << h << endl;
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
			else {
				break;
			}
			l += l;
			h += h + 1;

		}

	}
	dayn.push_back(1);
	dayn.push_back(0);
	if (dayn.size() < 16) { dayn.push_back(1); };

	while (dayn.size() < 15) {
		dayn.push_back(0);
	}
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
	//cout << freq << endl;
	//Print(value); cout << endl;
	for (int i = 0; i < s1.size(); i++) {
		//cout << freq << endl;
		freq = ((value - l + 1) * del - 1) / (h - l + 1);
		int j = 0;
		for (; (ls1[j].right <= freq); j++);
		double l1 = l;
		l = l + ls1[j].left * ((h - l + 1) / del);
		h = l1 + ls1[j].right * ((h - l1 + 1) / del - 1);
		//	cout << l << "--2----" << h << endl;
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
				
				//cout  << "--1--";
				//Print(value);
				//cout << endl;
				value = value * 2;
				//cout << "--2--";
				//(value);
				// << endl;
				value = value + dayn.front();
				//cout << "--3--";
				//Print(value);
				//cout << endl;
				//cout << endl;
				dayn.pop_front();
					//cout << "--не пуст---" << endl;
			}
			else value += value;
		}
		cout << ls1[j].c; 
	}
	

}