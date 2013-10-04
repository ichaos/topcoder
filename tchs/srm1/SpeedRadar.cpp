#include <vector>

using namespace std;

class SpeedRadar {
public:
double averageSpeed(int minLimit, int maxLimit, vector<int> readings);
};

double SpeedRadar::averageSpeed(int minLimit, int maxLimit, vector<int> readings) {
	int n = readings.size();
	int sum = 0;
	int infringe = 0;
	for (int i = 0; i < n; i++) {
		if (readings[i] >= minLimit && readings[i] <= maxLimit) {
			sum += readings[i];
		} else {
			infringe++;
		}
	}
	if (infringe * 10 > n) return 0.0;
	return (sum * 1.0) / (n - infringe);
}