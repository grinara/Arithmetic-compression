#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <string>
using namespace std;

struct govno {
	char c=0;
	float count=0;
	float left=0;
	float right=0;
};
void main() {
	string s1 = "dbabbabc";
	map <char, int> m;
	for (int i = 0; i < s1.size(); i++) {
		m[s1[i]]++;
	}
	govno ls1[255];
	map<char, int>::iterator i;
	float rayn=0;
	for (i = m.begin(); i != m.end(); ++i) {
		ls1[i->first].c = i->first;
		ls1[i->first].count = i->second;
		ls1[i->first].left = rayn;
		rayn = ls1[i->first].left + (ls1[i->first].count / s1.size());
		ls1[i->first].right = rayn;
	}
	float l = 0, h = 1;
	for (int i = 0; i < s1.size(); i++) {
		char c = s1[i];
		float l1 = l;
		l = l + ls1[c].left * (h - l);
		h = l1 + ls1[c].right * (h - l1);
	}
	cout << l << " ------ " << h<<endl;
	float test = 0.91273;
	l = 0, h = 1;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			char c = s1[i];
			float l1 = l;
			l = l + ls1[c].left * (h - l);
			h = l1 + ls1[c].right * (h - l1);
			if ((l <= test) && (test < h)) { cout << c; break; }
		}
	}
}