#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        int cnt0 = 0;
        for (char c : s) if (c == '0') ++cnt0;
        int misplaced = 0;                 
        for (int i = 0; i < cnt0; ++i)
            if (s[i] == '1') ++misplaced;
        cout << misplaced << '\n';
    }
    return 0;
}

/*
Problem

You are given a binary string s of length n. You are allowed to perform the following operation any number of times (including zero):
Choose three indices 1 ≤ i < j < k ≤ n.
Perform a cyclic shift (either left or right) on the values at positions s[i], s[j], s[k].

For example, if s = 110110:
Choosing (i=1, j=2, k=3) and performing a right shift cyclically → 011110
Choosing (i=4, j=5, k=6) and performing a left shift cyclically → 110101

Your task is to determine the minimum number of operations required to sort the given binary string in non-decreasing order (all 0s first, then all 1s).

Input
The first line contains an integer t — the number of test cases (1 ≤ t ≤ 100).
Each test case consists of:
An integer n (3 ≤ n ≤ 100) — the length of the string.
A binary string s of length n.

Output
For each test case, print a single integer — the minimum number of operations required to sort the binary string.

Examples
Input
4
3
001
4
0110
6
110100
6
101011

Output
0
1
2
1

Explanation
Test case 1: s = "001" is already sorted → 0 operations.
Test case 2: Choose (i=1, j=2, k=4) and perform a right cyclic shift → string becomes 0011, which is sorted.
Test case 3: Needs 2 operations to move misplaced 1s and 0s.
Test case 4: Can be fixed in 1 operation.
*/