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

	int length = 0;
	for (int i = 1; i <= N; i++) {
		D[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i])
				D[i] = max(D[i], D[j]+1);
		}
		length = max(length, D[i]);
	}

	cout << length << '\n';
	return 0;
}