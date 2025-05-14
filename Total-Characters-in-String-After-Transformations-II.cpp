class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int> &nums) {
        const int K = 26;
        const int MOD = 1e9 + 7;

        auto matrixPower = [K](auto &&self, vector<vector<long long>> M, int exp) -> vector<vector<long long>> {
            vector<vector<long long>> res(K, vector<long long>(K));
            for (int i = 0; i < K; i++)
                res[i][i] = 1;

            auto multiply = [](const vector<vector<long long>> &A, const vector<vector<long long>> &B) {
                vector<vector<long long>> C(K, vector<long long>(K));
                for (int i = 0; i < K; i++)
                    for (int k = 0; k < K; k++) {
                        long long aik = A[i][k];
                        if (!aik)
                            continue;
                        for (int j = 0; j < K; j++)
                            C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                    }
                return C;
            };

            while (exp > 0) {
                if (exp & 1)
                    res = multiply(res, M);
                M = multiply(M, M);
                exp >>= 1;
            }
            return res;
        };

        vector<long long> freq(K, 0);
        for (char c : s)
            freq[c - 'a']++;

        vector<vector<long long>> base(K, vector<long long>(K));
        for (int i = 0; i < K; i++)
            for (int k = 1; k <= nums[i]; k++)
                base[i][(i + k) % K]++;

        auto mt = matrixPower(matrixPower, base, t);
        long long ans = 0;
        for (int i = 0; i < K; i++) {
            if (freq[i] == 0)
                continue;
            for (int j = 0; j < K; j++)
                ans = (ans + freq[i] * mt[i][j]) % MOD;
        }
        return (int)ans;
    }
};
