/*
Wolf Sothe is playing the game Delaymaster. In this game, he can create new words according to the following rules:
For each positive integer n, the string which consists of n copies of 'w', then n copies of 'o', then n copies of 'l', and finally n copies of 'f' is a valid word.
The concatenation of two valid words is a valid word.
Only the words that can be obtained by rules 1 and 2 are valid. There are no other valid words.
Thus, for example:
By rule 1, "wolf", "wwoollff", and "wwwooolllfff" are valid words.
Then, by rule 2, "wolfwwoollff" is a valid word.
By applying rule 2 twice, "wolfwwoollffwolf" is a valid word.
The string "wfol" is not a valid word (order matters).
The string "wwolfolf" is not a valid word (we can only concatenate, not insert one word into another).
The string "wwwoolllfff" is not a valid word (only two 'o's instead of three).
You are given a string str. Return "VALID" if str is a valid word and "INVALID" otherwise. Note that the return value is case-sensitive: you must return the strings "VALID" and "INVALID" in all-uppercase.
*/

#include <string>

using namespace std;

class WolfDelaymaster {
public:
	string check(string s);
};

string WolfDelaymaster::check(string s) {
	int n = 1;
	int m = 0;
	char c = s[0];
	if (c != 'w') return "INVALID";
	for (int i = 1; i < s.size(); i++) {
		switch (c) {
			case 'w':
			if (s[i] == 'w') {
				n++;
			} else {
				if (s[i] != 'o') return "INVALID";
				else m = 1;
			} break;

			case 'o':
			if (s[i] == 'o') {
				m++;
			} else {
				if (m != n || s[i] != 'l') return "INVALID";
				m = 1;
			} break;

			case 'l':
			if (s[i] == 'l') {
				m++;
			} else {
				if (m != n || s[i] != 'f') return "INVALID";
				m = 1;
			} break;

			case 'f':
			if (s[i] == 'f') m++;
			else {
				if (m != n || s[i] != 'w') return "INVALID";
				m = 1;
				n = 1;
			} break;

			default: break;
		}
		c = s[i];
	}
	if (s[s.size() - 1] != 'f' || m != n) return "INVALID";
	return "VALID";
}