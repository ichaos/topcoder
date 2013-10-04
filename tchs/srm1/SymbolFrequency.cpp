#include <vector>
#include <map>
#include <string>
#include <climits>
#include <iostream>

using namespace std;

class SymbolFrequency {
public:
	double language(vector<string> frequencies, vector<string> text) {
		map<char, int> dic;
		int n = 0;
		for (int i = 0; i < text.size(); i++) {
			for (int j = 0; j < text[i].size(); j++) {
				if (text[i][j] <= 'z' && text[i][j] >= 'a') {
					n++;
					dic[text[i][j]]++;
				}
			}
		}

		double lowest = INT_MAX;
		double deviation = 0.0;
		for (int i = 0; i < frequencies.size(); i++) {
			map<char, int> tmpd(dic);
			deviation = 0.0;
			for (int j = 0; j < frequencies[i].size(); j += 3) {
				char c = frequencies[i][j];
				int f = (frequencies[i][j + 1] - '0') * 10 + (frequencies[i][j + 2] - '0');
				double fre = f / 100.0;
				deviation += ((n * fre - tmpd[c]) * (n * fre - tmpd[c]));
				tmpd.erase(c);
			}

			for (auto iter = tmpd.begin(); iter != tmpd.end(); iter++) {
				deviation += (iter->second) * (iter->second);
			}
			//cout << deviation << endl;
			if (deviation < lowest) lowest = deviation;
		}

		return lowest;
	}
};