/*
The pony Applejack is going to raise a new barn. The barn will consist of N sections in a row. Some of the sections will be empty, others will contain a single cow each. You are given a String str with N characters. This string describes the desired layout of the barn: the character 'c' represents a section with a cow, and the character '.' represents an empty section.  After she raises the barn, Applejack will build a wall that will divide the barn into two separate parts: one containing the first k sections and the other containing the last N-k sections, for some integer k. Each part must contain at least one section. (I.e., k must be between 1 and N-1, inclusive.) Additionally, Applejack wants both parts to contain exactly the same number of cows.  Return the number of possible positions for the wall. In other words, return the number of choices for the integer k such that all the conditions above are satisfied.
*/

#include <vector>
#include <string>

using namespace std;

class RaiseThisBarn {
public:
	int calc(string str);
};

int RaiseThisBarn::calc(string str) {
	//count the number of cow
	int n = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'c') n++;
	}

	if (n % 2) return 0;
	if (n == 0) return str.size() - 1;

	int m = n / 2;
	int h = 0;
	int s = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'c') h++;
		if (h == m) s++;
	}

	return s;
}