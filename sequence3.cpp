#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int A[1010];
int D[1010];
vector<int> V[1010];
vector<int> Answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	int length = 0;
	for (int i = 1; i <= N; i++) {
		D[i] = 1;
		V[i].push_back(A[i]);
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i]) {
				if (D[i] < D[j] + 1) {
					V[i].clear();	//가장 긴 증가하는 부분 수열 갱신
					V[i] = V[j];
					V[i].push_back(A[i]);
					D[i] = D[j] + 1;
				}
			}
		}
		if (Answer.size() < V[i].size())
			Answer = V[i];
	}

	cout << Answer.size() << '\n';
	for (int i = 0; i < Answer.size(); i++)
		cout << Answer[i] << " ";
	return 0;
}