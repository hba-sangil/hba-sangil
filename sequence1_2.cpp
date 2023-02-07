#include <iostream>
#include <algorithm>

#define endl "\n"
#define MAX 100010
using namespace std;

int N, answer;
int A[MAX];
int D[MAX];
int E[MAX];

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
}

void Solution()
{
    if (N == 1)
    {
        cout << A[1] << endl;
        return;
    }

    D[1] = A[1];
    answer = D[1];
    for (int i = 2; i <= N; i++)
    {
        D[i] = max(A[i], D[i - 1] + A[i]);
        answer = max(answer, D[i]);
    }

    E[N] = A[N];
    for (int i = N - 1; i >= 1; i--)
    {
        E[i] = max(A[i], E[i + 1] + A[i]);
    }

    for (int i = 2; i <= N - 1; i++) 
        answer = max(answer, D[i - 1] + E[i + 1]);

    cout << answer << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();
    return 0;
}
