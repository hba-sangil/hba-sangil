#include <iostream>
#include <vector>
using namespace std;

int N;	//전체 사람의 수
int num1, num2;		//촌수를 계산해야 하는 두 사람의 번호
int M;		//관계의 개수
int result = 0;
vector<int> V[101];
bool visited[101];

//start와 end는 구하려는 가족의 번호, count는 촌수계산
void DFS(int start, int end, int count)
{
	visited[start] = true;
	if (start == end)
		result = count;

	for (int i = 0; i < V[start].size(); i++) {
		int next = V[start][i];
		if (!visited[next])
			DFS(next, end, count + 1);		//방문하지 않은 노드이면 촌수+1
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> num1 >> num2 >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}

	DFS(num1, num2, 0);
	if (result != 0)
		cout << result << '\n';
	else
		cout << "-1";
	return 0;
}