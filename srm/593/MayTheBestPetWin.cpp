/*
The pony Rainbow Dash wants to choose her pet. There are N animals who want to be her pet. Rainbow Dash numbered them 0 through N-1.  To help her make the decision, Rainbow Dash decided to organize a relay race for the animals. The race track is already known, and for each animal we know how fast it is. More precisely, you are given vector <int>s A and B with the following meaning: For each i, the animal number i will take between A[i] and B[i] seconds (inclusive) to complete the track.  For the race the animals will be divided into two competing teams. This is a relay race, so the team members of each team will all run the same track, one after another -- when the first team member finishes, the second one may start, and so on. Thus the total time in which a team completes the race is the sum of the times of all team members. Note that we can use the estimates given by A and B to estimate the total time for any team of animals.  Given two teams S and T, the value maxdiff(S,T) is defined as the largest possible difference in seconds between the time in which team S finishes the course and the time in which team T finishes the course.  Rainbow Dash now needs to assign each of the animals to one of the two competing teams. She wants to see a close competition, so she wants the teams to finish as close to each other as possible. Formally, she wants to divide all animals into teams S and T in a way that minimizes maxdiff(S,T). Return the smallest possible value of maxdiff(S,T).
*/

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

class MayTheBestPetWin {
public:
	int calc(vector<int> A, vector<int> B);
};

int MayTheBestPetWin::calc(vector<int> A, vector<int> B) {
	vector<int> c(A.size(), 0);
	int sum = 0;
	int sub = 0;
	for (int i = 0; i < A.size(); i++) {
		c[i] = A[i] - B[i];
		sum += c[i];
		sub += (B[i] - A[i]);
	}

	//int mid = (sum + 1) / 2;

	sort(c.begin(), c.end(), std::greater<int>());
	while (c.size() > 1) {
		int a = c[0];
		int b = c[1];
		c.erase(c.begin());
		c.erase(c.begin());
		int r = a - b;
		if (r) {
			c.push_back(r);
			sort(c.begin(), c.end(), std::greater<int>());
		}
	}
	int dif = 0;
	if (c.size() == 1) {
		dif = c[0];
	}
	cout << dif << ", " << sub << endl;
	return (dif + sub) / 2;
}