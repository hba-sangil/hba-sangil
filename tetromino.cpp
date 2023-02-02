#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int A[500][500];
bool visited[500][500];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int answer = 0;

void DFS(int r, int c, int depth, int sum)
{
	visited[r][c] = true;
	if (depth == 3) {
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nR = r + dx[i];
		int nC = c + dy[i];
		
		if (nR < 0 || nC < 0 || nR >= N || nC >= M)
			continue;
		if (visited[nR][nC])
			continue;
		
		DFS(nR, nC, depth + 1, sum + A[nR][nC]);
		visited[nR][nC] = false;
	}
}

//ㅏ,ㅗ,ㅓ,ㅜ 모양은 depth=3이 안되므로 따로 계산
void Shape1(int x, int y)	//ㅓ
{
	int temp = 0;
	temp = A[x][y] + A[x][y + 1] + A[x][y + 2] + A[x - 1][y + 1];
	if (answer < temp)
		answer = temp;
}

void Shape2(int x, int y)	//ㅏ
{
	int temp = 0;
	temp = A[x][y] + A[x][y + 1] + A[x][y + 2] + A[x + 1][y + 1];
	if (answer < temp)
		answer = temp;
}

void Shape3(int x, int y)	//ㅜ
{
	int temp = 0;
	temp = A[x][y] + A[x + 1][y] + A[x + 2][y] + A[x + 1][y + 1];
	if (answer < temp)
		answer = temp;
}

void Shape4(int x, int y)	//ㅗ
{
	int temp = 0;
	temp = A[x][y] + A[x - 1][y + 1] + A[x][y + 1] + A[x + 1][y + 1];
	if (answer < temp)
		answer = temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(visited, false, sizeof(visited));
			DFS(i, j, 0, A[i][j]);
			if (i - 1 >= 0 && j + 2 < M)
				Shape1(i, j);
			if (i + 1 < N && j + 2 < M)
				Shape2(i, j);
			if (i + 2 < N && j + 1 < M)
				Shape3(i, j);
			if (i + 1 < N && i - 1 >= 0 && j + 1 < M)
				Shape4(i, j);
		}
	}

	cout << answer << '\n';
	return 0;
}