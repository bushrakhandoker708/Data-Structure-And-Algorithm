#include <iostream>
#include <map>
using namespace std;

int main() {

    /*
        MAP (STL)

        - A map stores key-value pairs.
        - Each key is UNIQUE.
        - Internally implemented as a Balanced Binary Search Tree (usually Red-Black Tree).

        Syntax:
            map<KeyType, ValueType> m;
    */

    map<int, int> mp;

    // ------------------------------------------------------------
    // INSERTION
    // ------------------------------------------------------------
    mp[1] = 10;   // O(log n)
    mp[2] = 20;
    mp[5] = 50;

    /*
        If key does not exist, mp[key] creates it with default value.
        Example: mp[10] will create key 10 with value 0 initially.
    */

    // ------------------------------------------------------------
    // ACCESS
    // ------------------------------------------------------------
    cout << "Value at key 1: " << mp[1] << endl; // O(log n)

    // Safe access using find()
    if (mp.find(2) != mp.end()) {
        cout << "Key 2 exists, value = " << mp[2] << endl;
    }

    // ------------------------------------------------------------
    // ITERATION (SORTED ORDER)
    // ------------------------------------------------------------
    cout << "\nMap elements (sorted by key):" << endl;

    for (auto it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    /*
        IMPORTANT:
        - Map ALWAYS stores keys in sorted order (ascending).
    */

    // ------------------------------------------------------------
    // UPDATE VALUE
    // ------------------------------------------------------------
    mp[2] += 5;  // O(log n)

    cout << "\nAfter update:" << endl;
    cout << "mp[2] = " << mp[2] << endl;

    // ------------------------------------------------------------
    // ERASE
    // ------------------------------------------------------------
    mp.erase(1); // O(log n)

    cout << "\nAfter deleting key 1:" << endl;
    for (auto it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    // ------------------------------------------------------------
    // FREQUENCY MAP USE CASE (VERY IMPORTANT IN CP)
    // ------------------------------------------------------------
    /*
        Example: counting frequency
    */

    int arr[] = {1, 2, 2, 3, 3, 3};
    int n = 6;

    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;   // O(log n)
                          // in freq map, we can just input the value, frquencty will be updated automatically, if key does not exist, it will be created with default value 0 and then incremented to 1
    }

    cout << "\nFrequency map:" << endl;
    for (auto it : freq) {
        cout << it.first << " appears " << it.second << " times" << endl;
    }

    // ------------------------------------------------------------
    // TIME COMPLEXITY
    // ------------------------------------------------------------
    /*
        - Insert: O(log n)
        - Delete: O(log n)
        - Find: O(log n)
        - Access (mp[key]): O(log n)
        - Iteration: O(n)

        Space Complexity:
        - O(n) for storing n key-value pairs
    */

    return 0;
}