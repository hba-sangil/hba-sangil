#include <iostream>
#include <algorithm>
using namespace std;

int N;
int D[100001];		//항의 최소 개수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		D[i] = i;
		for (int j = 1; j*j <= i; j++)
			D[i] = min(D[i], D[i - j * j] + 1);
	}

	cout << D[N] << '\n';
	return 0;
}