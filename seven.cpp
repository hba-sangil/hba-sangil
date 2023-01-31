#include <iostream>
#include <algorithm>
using namespace std;

int A[9];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> A[i];
		sum += A[i];
	}

	sort(A, A+9);
	for (int i = 0; i < 8; i++) {
		for (int j = 1; j < 9; j++) {
			if (sum - A[i] - A[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j)
						continue;
					cout << A[k] << '\n';	
				}
				return 0;
			}
		}
	}

	return 0;
}