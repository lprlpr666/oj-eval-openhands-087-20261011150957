#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int D;
    long long n;
    cin >> D >> n;
    
    int total_switches = (1 << D) - 1;
    vector<int> switches(total_switches + 1, 0);
    
    int last_position = 0;
    
    // Use the correct simulation approach
    for (long long ball = 1; ball <= n; ball++) {
        int current = 1;
        while (current <= total_switches) {
            if (switches[current] == 0) {
                switches[current] = 1;
                current = 2 * current;
            } else {
                switches[current] = 0;
                current = 2 * current + 1;
            }
        }
        last_position = current / 2;
    }
    
    cout << last_position << "\n";
    
    // Output leaf states
    int leaf_start = 1 << (D - 1);
    int leaf_end = (1 << D) - 1;
    
    for (int i = leaf_start; i <= leaf_end; i++) {
        cout << switches[i];
        if (i < leaf_end) cout << " ";
    }
    cout << "\n";
    
    return 0;
}