#include <iostream>
#include <vector>

using namespace std;

// Optimized solution using mathematical patterns
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int D;
    long long n;
    cin >> D >> n;
    
    int total_switches = (1 << D) - 1;
    vector<int> switches(total_switches + 1, 0);
    
    // Key optimization: process balls in batches when possible
    // and use bit manipulation for faster operations
    
    long long ball = 1;
    int last_position = 0;
    
    while (ball <= n) {
        // Try to find patterns to skip multiple balls at once
        // For now, process balls individually but with optimizations
        
        int current = 1;
        int path_length = 0;
        
        // Follow the path with minimal operations
        while (current <= total_switches) {
            if (switches[current] == 0) {
                switches[current] = 1;
                current = 2 * current;
            } else {
                switches[current] = 0;
                current = 2 * current + 1;
            }
            path_length++;
        }
        
        last_position = current / 2;
        ball++;
    }
    
    cout << last_position << "\n";
    
    // Output leaf states efficiently
    int leaf_start = 1 << (D - 1);
    int leaf_end = (1 << D) - 1;
    
    for (int i = leaf_start; i <= leaf_end; i++) {
        cout << switches[i];
        if (i < leaf_end) cout << " ";
    }
    cout << "\n";
    
    return 0;
}