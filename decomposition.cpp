#include <iostream>
using namespace std;

#define NUM 1000000000;
int N, K;
int D[200][200];	//K�� �̿��ؼ� ���� N�� �Ǵ� ����� ��

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;

	for (int i = 0; i <= K; i++) {
		D[i][1] = i;
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 2; j <= N; j++)
			D[i][j] = (D[i - 1][j] + D[i][j - 1]) % NUM;
	}

	cout << D[K][N];
	return 0;
}