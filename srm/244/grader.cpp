/*

 */

#include <vector>

using namespace std;

class Grader {
public:
	vector<int> grade(vector<int> predictedGrades, vector<int> actualGrades);
};

vector<int> Grader::grade(vector<int> predictedGrades, vector<int> actualGrades) {
	vector<int> result(7, 0);
	int dif = 0;

	for (int i = 0; i < predictedGrades.size(); i++) {
		if (predictedGrades[i] < actualGrades[i])
			dif = actualGrades[i] - predictedGrades[i];
		else
			dif = predictedGrades[i] - actualGrades[i];

		result[dif]++;
	}

	for (int i = 0; i < 7; i++) {
		result[i] = 100 * result[i] / predictedGrades.size();
	}

	return result;
}