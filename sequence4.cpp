#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1001];
int D[1001];

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
			if (A[i] < A[j])
				D[i] = max(D[i], D[j] + 1);
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
		answer = max(answer, D[i]);

	cout << answer << '\n';
	return 0;
}