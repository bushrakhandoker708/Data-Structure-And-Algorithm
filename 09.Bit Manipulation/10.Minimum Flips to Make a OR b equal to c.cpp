/* Minimum Flips to Make a OR b Equal to c (LeetCode 1318)
 * Problem Statement:
 * -------------------
 * Given three integers a, b, and c.
 * You are allowed to flip any bit of a or b (0 → 1 or 1 → 0).
 *
 * Goal:
 * Make (a OR b) == c with minimum number of bit flips.
 *
 * Return the minimum number of flips required.
 */

#include <iostream>
using namespace std;

/*
 * Intuition:
 * ----------
 * We compare each bit of a, b, and c independently.
 *
 * Because OR works bit-by-bit, we analyze each bit position:
 *
 * Case 1: c's bit = 1
 * --------------------------------
 * We need at least one of (a, b) bits to be 1.
 * - If both are 0 → we need 1 flip (turn either a or b into 1)
 * - If at least one is 1 → no flip needed
 *
 * Case 2: c's bit = 0
 * --------------------------------
 * We need both a and b bits to be 0.
 * - If a bit is 1 → flip it
 * - If b bit is 1 → flip it
 * - So total flips = number of 1s in (a bit, b bit)
 *
 * We process bit-by-bit using:
 * - (x & 1) → extract last bit
 * - x >>= 1 → move to next bit
 */

int minFlips(int a, int b, int c) {
    int flips = 0;

    while (a > 0 || b > 0 || c > 0) { // > 0 means we still have bits to process
                                    // > 0 is used instead of != 0 to handle negative numbers correctly (if needed)
                                    // > sign is called "arithmetic right shift" which preserves the sign bit for negative numbers
        int abit = a & 1; // Extract last bit
        int bbit = b & 1;
        int cbit = c & 1;

        if (cbit == 1) {
            // We need at least one of a or b to be 1
            if (abit == 0 && bbit == 0) {
                flips += 1;
            }
        } 
        else {
            // cbit == 0 → both must be 0
            flips += abit + bbit;
        }

        // move to next bit
        a >>= 1;
        b >>= 1;
        c >>= 1;
    }

    return flips;
}

int main() {
    int a = 2, b = 6, c = 5;

    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    int result = minFlips(a, b, c);

    cout << "Minimum flips required: " << result << endl;

    return 0;
}

/*
 * Complexity Analysis:
 * --------------------
 * Time Complexity:
 * - O(log N), where N is the maximum value among a, b, c
 * - Because we process each bit once (~32 bits for integers)
 *
 * Space Complexity:
 * - O(1), no extra space used
 *
 * Notes:
 * ------
 * This bit-by-bit greedy approach is preferred in interviews
 * because it is intuitive, clean, and avoids complex bit tricks.
 */