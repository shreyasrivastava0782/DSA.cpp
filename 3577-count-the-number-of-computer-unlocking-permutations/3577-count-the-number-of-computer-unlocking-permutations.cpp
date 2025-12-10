// class Solution {
// public:
//     int countPermutations(vector<int>& complexity) {
        
//     }
// };

class Solution {
public:
    static const long long MOD = 1000000007;

    long long modFact(long long n) {
        long long res = 1;
        for (long long i = 2; i <= n; i++) {
            res = (res * i) % MOD;
        }
        return res;
    }

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        // Check if complexity[0] is strictly the global minimum
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                // Someone has equal or lower complexity → cannot be unlocked
                return 0;
            }
        }

        // Answer is (n-1)! because 0 must be first, others may appear in any order
        return (int)modFact(n - 1);
    }
};
