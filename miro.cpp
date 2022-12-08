#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int A[101][101];
int D[101][101];
int dx[4] = { -1,1,0.0 };
int dy[4] = { 0,0,-1,1 };

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	D[x][y]++;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx > N || ny > M)
				continue;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (A[nx][ny] == 1 && D[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					D[nx][ny] = D[x][y] + 1;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < M; j++)
			A[i][j] = row[j] - '0';
	}

	BFS(0, 0);
	cout << D[N - 1][M - 1] << '\n';
	return 0;
}