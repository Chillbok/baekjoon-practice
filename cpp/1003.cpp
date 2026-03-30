#include <iostream>
using std::cin; using std::cout; using std::endl;

int dp[41] = {0, 1, 1};

int main() {
    // 피보나치 수열 미리 계산 (DP 테이블 채우기)
    for (int i = 2; i <= 40; i++) dp[i] = dp[i - 1] + dp[i - 2];

    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;

        if (N == 0) cout << "1 0" << endl;
        else if (N == 1) cout << "0 1" << endl;
        else cout << dp[N - 1] << " " << dp[N] << endl;
    }
    return 0;
}