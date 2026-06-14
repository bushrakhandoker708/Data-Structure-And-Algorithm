#include <bits/stdc++.h>
using namespace std;


/*
---------------------------------------------------------
0. CORE CONCEPTS: SHIFT OPERATORS
---------------------------------------------------------

Left Shift (<<):
----------------
n << i  → multiplies n by 2^i
Example:
5 = 0101
5 << 1 = 1010 = 10

Right Shift (>>):
------------------
n >> i → divides n by 2^i (integer division)
Example:
5 = 0101
5 >> 1 = 0010 = 2
*/

/*
---------------------------------------------------------
1. GET RIGHTMOST BIT 
---------------------------------------------------------

We want the last bit (LSB).
Three methods:

Method A: AND with 1
Method B: Right shift + AND
Method C: XOR trick (advanced intuition)
*/

// Method A
int rightmostBit_AND(int n) {
    return n & 1;
}

// Method B
int rightmostBit_Shift(int n) {
    return (n >> 0) & 1; // same as AND but shows shift concept
}

// Method C (isolating lowest set bit, NOT just bit value)
int lowestSetBit(int n) {
    return n & (-n);
}

/*
---------------------------------------------------------
2. CHECK i-th BIT
---------------------------------------------------------
*/
bool isBitSet(int n, int i) {
    return (n & (1 << i));
}

/*
---------------------------------------------------------
3. SET i-th BIT
---------------------------------------------------------
*/
int setBit(int n, int i) {
    return n | (1 << i);
}

/*
---------------------------------------------------------
4. CLEAR i-th BIT
---------------------------------------------------------
*/
int clearBit(int n, int i) {
    return n & (~(1 << i));
}

/*
---------------------------------------------------------
5. TOGGLE i-th BIT
---------------------------------------------------------
*/
int toggleBit(int n, int i) {
    return n ^ (1 << i);
}

/*
---------------------------------------------------------
6. REMOVE LAST SET BIT (IMPORTANT TRICK)
---------------------------------------------------------
*/
int removeLastSetBit(int n) {
    return n & (n - 1);
}

/*
---------------------------------------------------------
7. SWAP USING XOR (NO TEMP VARIABLE)
---------------------------------------------------------
*/
void swapXOR(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

/*
---------------------------------------------------------
8. CHECK POWER OF TWO
---------------------------------------------------------
*/
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

/*
---------------------------------------------------------
9. COUNT SET BITS (EASY → HARD)
---------------------------------------------------------
*/

// Method A: Bit by bit
int countBits_Shift(int n) {
    int cnt = 0;
    while (n > 0) {
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt;
}

// Method B: Brian Kernighan (important interview trick)
int countBits_BK(int n) {
    int cnt = 0;
    while (n > 0) {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}

// Method C: Built-in (fastest)
int countBits_builtin(int n) {
    return __builtin_popcount(n);
}

/*
=========================================================
MAIN DEMO
=========================================================
*/
int main() {

    cout << "================ BIT MANIPULATION =================\n\n";

    int n = 13; // 1101

    // 1. Rightmost bit extraction
    cout << "1. Rightmost bit of " << n << ":\n";
    cout << "AND method: " << rightmostBit_AND(n) << "\n";
    cout << "Shift method: " << rightmostBit_Shift(n) << "\n";
    cout << "Lowest set bit (advanced): " << lowestSetBit(n) << "\n\n";

    // 2. Shift explanation
    cout << "2. Shift demo:\n";
    cout << "n << 1 = " << (n << 1) << "\n";
    cout << "n >> 1 = " << (n >> 1) << "\n\n";

    // 3. Bit operations
    cout << "3. Set bit 2 of 9: " << setBit(9, 2) << "\n";
    cout << "4. Clear bit 2 of 13: " << clearBit(13, 2) << "\n";
    cout << "5. Toggle bit 1 of 13: " << toggleBit(13, 1) << "\n\n";

    // 6. Remove last set bit
    cout << "6. Remove last set bit of 12: " << removeLastSetBit(12) << "\n\n";

    // 7. Power of two
    cout << "7. Is 16 power of two? " << isPowerOfTwo(16) << "\n\n";

    // 8. Count bits
    cout << "8. Count set bits in 13:\n";
    cout << "Shift: " << countBits_Shift(13) << "\n";
    cout << "BK: " << countBits_BK(13) << "\n";
    cout << "Builtin: " << countBits_builtin(13) << "\n";

    cout << "\n====================================================\n";

    return 0;
}

/*
=========================================================
COMPLEXITY SUMMARY
=========================================================

All bit operations:
- Time: O(1) per operation (32-bit integer max loop = constant)
- Space: O(1)

Counting bits:
- Shift method: O(log n)
- Brian Kernighan: O(set bits)
- Builtin: O(1)

=========================================================
*/