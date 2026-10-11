#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int D;
    long long n;
    cin >> D >> n;
    
    // Calculate total number of switches: 2^D - 1
    int total_switches = (1 << D) - 1;
    
    // Initialize all switches to closed (0)
    // Use 1-based indexing for easier tree navigation
    vector<int> switches(total_switches + 1, 0);
    
    int last_position = 0;
    
    // Simulate each ball
    for (long long ball = 1; ball <= n; ball++) {
        int current = 1; // Start at root
        
        // Traverse from root to leaf
        while (current <= total_switches) {
            if (switches[current] == 0) {
                // Switch is closed, open it and go left
                switches[current] = 1;
                current = 2 * current; // Go to left child
            } else {
                // Switch is open, close it and go right
                switches[current] = 0;
                current = 2 * current + 1; // Go to right child
            }
        }
        
        // When current > total_switches, we've reached a leaf position
        last_position = current / 2; // The parent of the invalid position
    }
    
    // Output the final position of the last ball
    cout << last_position << endl;
    
    // Output the state of all leaf nodes (from left to right)
    // Leaf nodes are at positions 2^(D-1) to 2^D - 1
    int leaf_start = 1 << (D - 1);
    int leaf_end = (1 << D) - 1;
    
    for (int i = leaf_start; i <= leaf_end; i++) {
        cout << switches[i];
        if (i < leaf_end) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}