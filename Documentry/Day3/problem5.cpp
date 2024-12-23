//Q5 Minimun  non zero product of an Array Elements
//You are given a positive integer p. Consider an array nums (1-indexed) that consists of the integers in the inclusive range [1, 2p - 1] in their binary representations. You are allowed to do the following operation any number of times:
// Choose two elements x and y from nums.
//Choose a bit in x and swap it with its corresponding bit in y. Corresponding bit refers to the bit that is in the same position in the other integer.
//For example, if x = 1101 and y = 0011, after swapping the 2nd bit from the right, we have x = 1111 and y = 0001.
//Find the minimum non-zero product of nums after performing the above operation any number of times. Return this product modulo 109 + 7.
#include <iostream>
#include <cmath>
#define MOD 1000000007
using namespace std;

class Solution {
public:
    int minNonZeroProduct(int p) {
        // The largest number in the array nums is (2^p - 1)
        long long max_num = (1LL << p) - 1;  // 2^p - 1
        // The second largest number in the array nums is (2^p - 2)
        long long second_max = max_num - 1;

        // Compute the product of the two largest numbers mod MOD
        long long product = max_num * second_max % MOD;

        // Now we need to raise max_num to the power of (2^(p-1)) modulo MOD
        // This is because we are taking the power of (2^(p-1)) for the rest of the array
        long long exponent = (1LL << (p - 1)) % (MOD - 1); // Fermat's Little Theorem
        long long result = mod_pow(max_num, exponent, MOD);

        // The final result is the product of these two quantities mod MOD
        return (product * result) % MOD;
    }

private:
    // Function to compute base^exp % mod using binary exponentiation
    long long mod_pow(long long base, long long exp, long long mod) {
        long long result = 1;
        base = base % mod; // In case base is larger than mod
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};

int main() {
    Solution solution;
    int p;
    
    cout << "Enter the value of p: ";
    cin >> p;

    int result = solution.minNonZeroProduct(p);
    cout << "The minimum non-zero product is: " << result << endl;
    
    return 0;
}
