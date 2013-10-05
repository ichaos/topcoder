/*
A typical phone pad has the following layout:
 1 2 3
 4 5 6
 7 8 9
 * 0 #
The finger movement distance between any pair of keys is defined as their Manhattan distance (the sum of the absolute differences of their coordinates) on the phone pad. For example, the key '6' is 0 units away from itself, 1 unit away from '3', '5', and '9', 2 units away from '2', '4', '8', and '#', 3 units away from '1', '7', and '0', and 4 units away from '*'. Write a class PhonePad with a method fingerMovement that takes a String, phoneNumber, and returns the minimal distance of total finger movement distance required to dial the phone number. Note that the finger is initially on key '5'.
*/

#include <vector>
#include <string>

using namespace std;

class PhonePad {
private:
	int abs(int n) {
		if (n < 0)
			n = 0 - n;
		return n;
	}
public:
	int fingerMovement(string phoneNumber);
};

int PhonePad::fingerMovement(string phoneNumber) {
	int x = 1, y = 1;
	int nx = 0, ny = 0;
	int moves = 0;
	for (int i = 0; i < phoneNumber.size(); i++) {
		int pos = phoneNumber[i] - '0';
		if (pos == 0) {
			nx = 1;
			ny = 3;
		} else {
			nx = (pos - 1) % 3;
			ny = (pos - 1) / 3;
		}
		moves += abs(nx - x) + abs(ny - y);
		x = nx;
		y = ny;
	}
	return moves;
}