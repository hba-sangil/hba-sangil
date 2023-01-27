#include <iostream>
#include <algorithm>
using namespace std;

int N;
int D[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++)
		D[i] = i;
	
	for (int i = 2; i <= N; i++) {
		if (i % 2 == 0)
			D[i] = min(D[i], D[i / 2]);
		if (i % 3 == 0)
			D[i] = min(D[i], D[i / 3]);
		D[i] = min(D[i], D[i - 1]) + 1;
	}

	cout << D[N] << '\n';

	while (N != 0) {
		cout << N << " ";
		if (N % 2 == 0 && D[N] == D[N / 2] + 1)
			N = N / 2;
		else if (N % 3 == 0 && D[N] == D[N / 3] + 1)
			N = N / 3;
		else if (D[N] == D[N - 1] + 1)
			N = N - 1;
	}

	return 0;
}