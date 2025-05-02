class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        vector<int> forces(n, 0);

        int force = 0;
        for (int i = 0; i < n; ++i)
        {
            force = (dominoes[i] == 'R') ? n : (dominoes[i] == 'L') ? 0 : max(force - 1, 0);
            forces[i] += force;
        }

        force = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            force = (dominoes[i] == 'L') ? n : (dominoes[i] == 'R') ? 0 : max(force - 1, 0);
            forces[i] -= force;
        }

        string result;
        for (int i = 0; i < n; ++i)
            result += (forces[i] > 0) ? 'R' : (forces[i] < 0) ? 'L' : '.';

        return result;
    }
};