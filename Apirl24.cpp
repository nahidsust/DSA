#include<bits/stdc++.h>
using namespace std;

int main(){
    map<char, int> m; // Map to store character counts in t
    string s, t;
    cin >> s >> t;
    
    // Initialize the map with the frequency of each character in t
    for(int i = 0; i < t.size(); i++) {
        m[t[i]]++;
    }

    int l = 0, r = 0, cnt = 0, minlen = INT_MAX, init = -1;
    int required = t.size();  // Total characters we need to match in the window

    while (r < s.size()) {
        // If the current character is in t, process it
        if (m[s[r]] > 0) {
            cnt++;
        }
        
        // Decrease the frequency of the character in the map
        m[s[r]]--;
        
        // While the window is valid (i.e., contains all characters from t)
        while (cnt == required) {
            if (r - l + 1 < minlen) {
                minlen = r - l + 1;
                init = l;
            }
            
            // Try to shrink the window from the left
            m[s[l]]++;
            if (m[s[l]] > 0) {
                cnt--;
            }
            l++;
        }

        r++;
    }
    
    // Output the minimum window substring or an empty string if no valid window is found
    if (init == -1) {
        cout << "";
    } else {
        cout << s.substr(init, minlen);
    }
}
