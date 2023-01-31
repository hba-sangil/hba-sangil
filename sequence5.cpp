#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1001];
int D[1001];	//가장 증가하는 수열
int E[1001];	//가장 감소하는 수열

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	for (int i = 1; i <= N; i++) {
		D[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j])
				D[i] = max(D[i], D[j] + 1);
		}
	}

	for (int i = N; i >= 1; i--) {
		E[i] = 1;
		for (int j = N; j > i; j--) {
			if (A[i] > A[j])
				E[i] = max(E[i], E[j] + 1);
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (answer < D[i] + E[i] - 1)
			answer = D[i] + E[i] - 1;
	}

	cout << answer << '\n';
	return 0;
}