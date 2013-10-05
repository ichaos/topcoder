/*
Given a group of dancers' heights, arrange a circle formation that minimizes the maximum height difference 
between each pair of neighboring dancers. 
Write a class CircleDance with a method arrangeDancers that takes a vector <int>, heights,
 and returns the maximum height difference between neighboring dancers.
 */

#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

class CircleDance {
private:
	struct node {
		int dis;
		int s;
		int e;
		node(int _dis, int _s, int _e) : dis(_dis), s(_s), e(_e) {}
		
		bool operator<(const node &a) const {
			return dis < a.dis;
		}
	};
	struct compareLess {
		bool operator()(const node &a, const node &b) {
			return a.dis > b.dis;
		}
	};
	float abs(float n) {
		if (n < 0)
			n = -n;
		return n;
	}
public:
	int arrangeDancers(vector<int> height);
};

int CircleDance::arrangeDancers(std::vector<int> height) {
	vector<int> h(height);
	sort(h.begin(), h.end());

	node a(h[h.size() - 1] - h[0], h[0], h[h.size() - 1]);
	h.erase(h.begin() + h.size() - 1);
	h.erase(h.begin());

	//priority_queue<node, vector<node>, compareLess> pq;
	priority_queue<node> pq;
	pq.push(a);
	pq.push(a);

	while (1) {
		node t = pq.top();
		pq.pop();
		
		// try to split edge t as evenly as possible
		int nd = 30000;
		int index = -1;
		int start = -1;
		for (int i = 0; i < h.size(); i++) {
			if (h[i] >= t.s && h[i] <= t.e) {
				if (start == -1) start = i;
				if (abs((h[i] - t.s) - (t.e - h[i])) < nd) {
					nd = abs((h[i] - t.s) - (t.e - h[i]));
					index = i;
				} else if (abs((h[i] - t.s) - (t.e - h[i])) == nd) { //
					if (index > start)
						index = i;
				}
			}
		}
		if (index == -1) return t.dis;
		node split(h[index] - t.s, t.s, h[index]);
		pq.push(split);
		split.dis = t.e - h[index];
		split.s = h[index];
		split.e = t.e;
		pq.push(split);
		h.erase(h.begin() + index);
		//cout << t.dis << ", " << t.s << " "  << split.s << " " << t.e << endl;
	}
}