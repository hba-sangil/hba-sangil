#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1000001
int F, G, S, U, D;
int visited[MAX];		//버튼을 누르는 횟수
queue<int> q;

void BFS()
{
	q.push(S);
	visited[S] = 1;		//처음위치

	while (!q.empty()) {
		int next;
		int now = q.front();

		if (now == G) {
			cout << visited[now] - 1 << '\n';	//시작점이 1이므로 하나를 빼준다
			return;
		}

		next = now + U;
		if (next <= F && visited[next] == 0) {
			q.push(next);
			visited[next] = visited[now] + 1;
		}

		next = now - D;
		if (next > 0 && visited[next] == 0) {
			q.push(next);
			visited[next] = visited[now] + 1;
		}
		q.pop();
	}
	cout << "use the stairs" << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> F >> S >> G >> U >> D;

	BFS();
	return 0;
}