/*
 * People enjoy mazes, but they also get them dirty. Arrows, graffiti, and chewing gum are just a few of the souvenirs people leave
  on the walls. You, the maze keeper, are assigned to whiten the maze walls. Each face of the wall requires one liter of paint, 
  but you are only required to paint visible faces. You are given a map of the maze, and you must determine the amount of paint 
  needed for the job.
The maze is described by a vector <string> maze, where each character can be either '#' (a wall) or '.' (an empty space). 
All '.' characters on the perimeter of the map are considered entrances to the maze. Upon entering the maze, 
one can only move horizontally and vertically through empty spaces, and areas that are not reachable by these movements are not 
considered visible. Each '#' represents a square block with four wall faces (each side of the square is a face). 
A face is visible if it is not directly adjacent to another wall (and is in a reachable area of the maze). 
For example, two adjacent blocks can have at most six visible faces since two of their faces are directly adjacent to each other. 
All exterior faces on the perimeter are considered visible.
For example, the following picture represents a trivial maze with just one (wide) entrance and only four empty reachable spaces:  
 
To whiten this maze you must paint the faces highlighted in yellow above: 16 for its perimeter, plus 8 interior faces. 
Note that there are faces that are not visible and thus need not be painted.

 */

//1000
#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class TroytownKeeper {
private:
	int bfs_lime(vector<string> &maze, vector<vector<bool> > &visited, int x, int y);
public :
	int limeLiters(vector<string> maze);
};

int TroytownKeeper::bfs_lime(vector<string> &maze, vector<vector<bool> > &visited, int x, int y) {
	if (visited[x][y]) return 0;
	int m = maze.size();
	int n = maze[0].size();

	queue<int> q;
	int pos = (x << 16) | y;
	q.push(pos);
	visited[x][y] = true;
	//visited[x][y] = true;

	int liters = 0;
	vector<int> ns(8);

	while (!q.empty()) {
		int np = q.front(); q.pop();
		int xi = np >> 16;
		int yi = np & 0xffff;

		//check four directions
		//up
		ns[0] = xi - 1;
		ns[1] = yi;
		//down
		ns[2] = xi + 1;
		ns[3] = yi;
		//left
		ns[4] = xi;
		ns[5] = yi - 1;
		//right
		ns[6] = xi;
		ns[7] = yi + 1;

		for (int i = 0; i < 4; i++) {
			int nx = ns[i * 2];
			int ny = ns[i * 2 + 1];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
				if (maze[nx][ny] == '#') liters++;
				else {
					q.push((nx << 16) | ny);
					visited[nx][ny] = true;
				}
			}
		}
	}
	//cout << x << ", " << y << ": " << liters << endl;
	return liters;
}

int TroytownKeeper::limeLiters(vector<string> maze) {
	int x = maze.size();
	int y = maze[0].size();
	vector<vector<bool> > visited(x, vector<bool>(y, false));
	int liters = 0;
	//check every cube on perimeter if it's an entrance, then do a bfs to find all the faces need to lime
	for (int j = 0; j < y; j++) {
		//up 
		if (maze[0][j] == '#') { //not an entrance, lime one face
			liters++;
		} else {
			//bfs to lime all faces
			liters += bfs_lime(maze, visited, 0, j);
		}
		//down
		if (maze[x - 1][j] == '#')
			liters++;
		else
			liters += bfs_lime(maze, visited, x - 1, j);
	}

	for (int i = 0; i < x; i++) {
		//left
		if (maze[i][0] == '#')
			liters++;
		else
			liters += bfs_lime(maze, visited, i, 0);

		//right
		if (maze[i][y - 1] == '#') {
			liters++;
		} else {
			liters += bfs_lime(maze, visited, i, y - 1);
		}
	}

	return liters;
}