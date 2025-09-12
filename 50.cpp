#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;  
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        double res = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res *= x;   
            }
            x *= x;         
            exp /= 2;    
        }
        return res;
    }
};
int main() {
    Solution sol;
    double x;
    int n;
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;
    double result = sol.myPow(x, n);
    cout << x << "^" << n << " = " << result << endl;
    return 0;
}

/*
The logic is for x^n, we can use the property of exponents:
- If n is even, x^n = (x^(n/2))^2
- If n is odd, x^n = x * (x^(n//2))
This allows us to reduce the problem size by half at each step, leading to a logarithmic time complexity O(log n).
*/