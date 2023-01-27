#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100001];
int D[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	int answer = A[0];
	D[0] = A[0];
	for (int i = 1; i < N; i++) {
		D[i] = max(D[i - 1] + A[i], A[i]);
		answer = max(answer, D[i]);
	}

	cout << answer << '\n';
	return 0;
}