#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <string>
using namespace std;
int count1 = 0;
void Print(int n) {
	if (n == 0) { 
		int t = 16 - count1;
		while (t > 0) {
			cout << 0;
			t--;
		}
		count1 = 0;
		return; }
	count1++;
	Print(n / 2);
	cout << n%2;
}
struct num {
	char c=0;
	int count=0;
	int left=0;
	int right=0;
};
int bits = 0;
list<int> dayn;
void BitsPlusFollow(int bit) {
	cout << bit;
	dayn.push_back(bit);
		//cout << endl;
		for (; bits > 0; bits--)
		{
			cout << !bit;
			dayn.push_back(!bit);
			//cout << endl;
		}
}
void main() {
	string s1 = "jjjyh";
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
		cout << i->first<<" " << ls1[i->first].left << "--00--" << ls1[i->first].right << endl;
	}
	int l = 0, h = pow(2,16)-1, del = s1.size();
	int First = (h + 1) / 4, Half = First * 2, Third = First * 3;
	
	for (int i = 0; i < s1.size(); i++) {
		char c = s1[i];
		int l1 = l;
		l = l + ls1[c].left * ((h - l1 + 1) / del);
		h = l1 + ls1[c].right * (((h - l1+1)/del)-1);
		//cout << s1[i] << " " << l << " ---01--- " << h<<" ";
		//cout << endl;
		//Print(l);
	    //cout << " ---- ";
		//Print(h);
		//cout << endl;
		while (true) { //*********
			if(h<Half){
				BitsPlusFollow(0);
			}
			else if (l >= Half) {
				BitsPlusFollow(1);
				l -= Half; h -= Half;
				//cout << s1[i] << " " << l << " ---1--- " << h << " ";
				//cout << endl;
				
				//Print(l);
				//cout << " ---- ";
				//Print(h);
				//cout << endl;
			}
			else if(l>=First && h<Third) {
				bits++;
				l -= First; h -= First;
				//cout << s1[i] << " " << l << " ---2--- " << h << " ";
				//cout << endl;
				//Print(l);
				//cout << " ---- ";
				//Print(h);
				//cout << endl;
			}
			else {
				//cout << s1[i] << " " << l << " ---break--- " << h << " ";
				//cout << endl;
				break; 
			
			}
			l += l;
			h += h + 1;
			//cout << s1[i] << " " << l << " ----3-- " << h << " ";
			//cout << endl;
			
			//Print(l);
			//cout << " ---- ";
			//Print(h);
			//cout << endl;
		}
		 //*************
	}
	dayn.push_back(1);
	while (dayn.size() < 16) {
		dayn.push_back(0);
	}
	int test = 0;
	int x = 0;
	while (dayn.size() > 0) {
		test = test + dayn.back() * pow(2, x);
		dayn.pop_back();
		x++;
	}
	cout << endl;
	l = 0, h = pow(2, 16) - 1;
	double freq = 0, value = test;
	for (int i = 0; i < s1.size(); i++) {
		freq = ((value - l + 1) * del - 1) / (h - l + 1); 
		cout << freq << endl;
		char c = s1[i];
		int j = 0;
		for (; (ls1[j].right <= freq); j++);
		//cout << ls1[j].c;
			int l1 = l;
			l = l + ls1[c].left * ((h - l + 1) / del);
			h = l1 + ls1[c].right * ((h - l1 + 1) / del - 1);
			//cout << ls1[c].c << " " << l << " ---02--- " << h << " ";
			//cout << endl;
			//Print(l);
			//cout << " ---- ";
			//Print(h);
			cout << endl;
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
				value += value;
			}
	cout << ls1[j].c; cout << endl;
	}
}
