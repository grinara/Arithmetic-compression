#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <string>
using namespace std;

struct num {
	char c=0;
	int count=0;
	int left=0;
	int right=0;
};
void main() {
	string s1 = "bukr";
	map <char, int> m;
	for (int i = 0; i < s1.size(); i++) {
		m[s1[i]]++;
	}
	num ls1[255];
	map<char, int>::iterator i;
	float rayn=0;
	for (i = m.begin(); i != m.end(); ++i) {
		ls1[i->first].c = i->first;
		ls1[i->first].count = i->second;
		ls1[i->first].left = rayn;
		rayn = ls1[i->first].left + ls1[i->first].count;
		ls1[i->first].right = rayn;
		//cout << i->first<<" " << ls1[i->first].left << "----" << ls1[i->first].right << endl;
	}
	int l = 0, h = pow(2,16)-1, del = s1.size();
	for (int i = 0; i < s1.size(); i++) {
		char c = s1[i];
		int l1 = l;
		l = l + ls1[c].left * ((h - l1 + 1) / del);
		h = l1 + ls1[c].right * (((h - l1+1)/del)-1);
		cout<< s1[i]<<" " << l << " ------ " << h << endl;
	}
//	cout << l << " ------ " << h<<endl;
	int test = 13822;
	l = 0, h = pow(2, 16) - 1;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			char c = s1[i];
			int l1 = l;
			l = l + ls1[c].left * ((h - l + 1) / del);
			h = l1 + ls1[c].right * ((h - l1 + 1) / del - 1);
			if ((l <= test) && (test < h)) { cout << c; break; }
		}
	}
}