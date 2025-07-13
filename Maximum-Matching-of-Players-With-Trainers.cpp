class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int matches = 0;
        int j = 0;

        for (int i = 0; i < players.size() && j < trainers.size(); i++) {
            while (j < trainers.size() && trainers[j] < players[i]) {
                j++;
            }
            if (j < trainers.size()) {
                matches++;
                j++;
            }
        }

        return matches;
    }
};