#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class CoinChangeProblem {
public:
    void solveCoinChange(const vector<int>& coins, int amount) {
        if (amount < 0 || coins.empty()) {
            cout << "\n[Error]: Invalid target amount or empty coin list.\n";
            return;
        }
        vector<int> dp(amount + 1, amount + 1);
        vector<int> parent(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0) {
                    if (dp[i - coins[j]] + 1 < dp[i]) {
                        dp[i] = dp[i - coins[j]] + 1;
                        parent[i] = j;
                    }
                }
            }
        }
        if (dp[amount] > amount) {
            cout << "\nResult: IMPOSSIBLE to make change for amount " << amount << " with the given denominations.";
        } else {
            cout << "\nMinimum Coins Required: " << dp[amount];
            cout << "\nCoins Selected Details: ";   
            int tempAmount = amount;
            while (tempAmount > 0) {
                int coinIndex = parent[tempAmount];
                cout << coins[coinIndex] << " ";
                tempAmount -= coins[coinIndex];
            }
        }
        cout << "/n--------------------------------/n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, amount;
    cout << "Enter the number of coin denominations: ";
    if (!(cin >> n) || n <= 0) {
        cout << "[Error]: Invalid number of denominations.\n";
        return 0;
    }
    vector<int> coins(n);
    cout << "Enter the coin denominations:\n";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    cout << "Enter the target amount: ";
    cin >> amount;
    CoinChangeProblem solver;
    solver.solveCoinChange(coins, amount);

    return 0;
}
