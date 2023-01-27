#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1000001
int F, G, S, U, D;
int visited[MAX];		//��ư�� ������ Ƚ��
queue<int> q;

void BFS()
{
	q.push(S);
	visited[S] = 1;		//ó����ġ

	while (!q.empty()) {
		int next;
		int now = q.front();

		if (now == G) {
			cout << visited[now] - 1 << '\n';	//�������� 1�̹Ƿ� �ϳ��� ���ش�
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