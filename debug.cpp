#include <iostream>
#include <vector>

using namespace std;

int main() {
    int D = 4;
    long long n = 3;
    
    // Calculate total number of switches: 2^D - 1
    int total_switches = (1 << D) - 1;
    
    // Initialize all switches to closed (0)
    vector<int> switches(total_switches + 1, 0);
    
    cout << "Initial switches: ";
    for (int i = 1; i <= total_switches; i++) {
        cout << switches[i] << " ";
    }
    cout << endl;
    
    int last_position = 0;
    
    // Simulate each ball step by step
    for (long long ball = 1; ball <= n; ball++) {
        cout << "\nBall " << ball << ":" << endl;
        int current = 1;
        string path = "1";
        
        // Traverse from root to leaf
        while (current <= total_switches) {
            cout << "  At position " << current << ", switch is " << switches[current];
            
            if (switches[current] == 0) {
                // Switch is closed, open it and go left
                switches[current] = 1;
                current = 2 * current; // Go to left child
                cout << " -> open it, go left to " << current << endl;
            } else {
                // Switch is open, close it and go right
                switches[current] = 0;
                current = 2 * current + 1; // Go to right child
                cout << " -> close it, go right to " << current << endl;
            }
            
            if (current <= total_switches) {
                path += " -> " + to_string(current);
            }
        }
        
        // When current > total_switches, we've reached a leaf position
        last_position = current / 2; // The parent of the invalid position
        cout << "  Ball " << ball << " ends at position " << last_position << endl;
        cout << "  Path: " << path << endl;
        
        cout << "  Switches after ball " << ball << ": ";
        for (int i = 1; i <= total_switches; i++) {
            cout << switches[i] << " ";
        }
        cout << endl;
    }
    
    cout << "\nFinal result:" << endl;
    cout << "Last position: " << last_position << endl;
    
    // Output the state of all leaf nodes (from left to right)
    int leaf_start = 1 << (D - 1);
    int leaf_end = (1 << D) - 1;
    
    cout << "Leaf states: ";
    for (int i = leaf_start; i <= leaf_end; i++) {
        cout << switches[i];
        if (i < leaf_end) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}