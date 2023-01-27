#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[10];
bool visited[10];
vector<int> V;

void BackTracking(int level, int start)
{
	if (level == M) {
		for (int i = 0; i < M; i++)
			cout << A[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = start; i <= N; i++) {
		visited[i] = true;
		A[level] = i;
		BackTracking(level + 1, i);
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	BackTracking(0, 1);
	return 0;
}