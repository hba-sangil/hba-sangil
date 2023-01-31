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

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		D[i] = A[i];
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i] && D[i] < D[j] + A[i])
				D[i] = D[j] + A[i];
		}
		if (sum < D[i])
			sum = D[i];
	}

	cout << sum << '\n';
	return 0;
}