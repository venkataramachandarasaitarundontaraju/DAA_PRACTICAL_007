#include <iostream>
#include <vector>

using namespace std;

void solveCoinChange(vector<int>& coins, int targetAmount) {
    // 1. Initialize DP and Tracking tables
    // We fill it with (targetAmount + 1) which acts as our "Infinity" marker
    vector<int> dp(targetAmount + 1, targetAmount + 1);
    vector<int> parent(targetAmount + 1, -1);
    
    // Base Case: 0 coins needed to make an amount of 0
    dp[0] = 0;

    // 2. Iterate through all states sequentially (Bottom-Up loop)
    for (int i = 1; i <= targetAmount; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            // 3. Apply the state transition relation
            if (i >= coins[j] && dp[i - coins[j]] + 1 < dp[i]) {
                dp[i] = dp[i - coins[j]] + 1; // Update with minimum coin count
                parent[i] = j;                 // Save the index of the coin used
            }
        }
    }

    // 4. Print or Return the final required target state
    if (dp[targetAmount] > targetAmount) {
        cout << "Result: Impossible to make change for " << targetAmount << "\n";
    } else {
        cout << "Minimum Coins Required: " << dp[targetAmount] << "\n";
        cout << "Coins Used: ";
        
        // Backtrack using the parent tracker to print the exact choices
        int currentAmount = targetAmount;
        while (currentAmount > 0) {
            int coinIndex = parent[currentAmount];
            cout << coins[coinIndex] << " ";
            currentAmount -= coins[coinIndex];
        }
        cout << "\n";
    }
}

int main() {
    // Hardcoded variables for a quick, plug-and-play execution
    vector<int> coins = {1, 3, 4, 5}; 
    int targetAmount = 7;

    cout << "Target Amount: " << targetAmount << "\n";
    cout << "Available Coins: 1, 3, 4, 5\n\n";

    // Call the DP function
    solveCoinChange(coins, targetAmount);

    return 0;
}
