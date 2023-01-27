#include <iostream>
using namespace std;

#define NUM 10007;
int N;
int D[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	D[1] = 1;	D[2] = 2;
	for (int i = 3; i <= N; i++)
		D[i] = (D[i - 2] + D[i - 1]) % NUM;

	cout << D[N] % NUM;
	return 0;
}