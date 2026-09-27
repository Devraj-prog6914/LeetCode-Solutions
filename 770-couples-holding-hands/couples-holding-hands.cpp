class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int ans = 0;

        for (int i = 0; i < n; i += 2) {
            int partner = row[i] ^ 1;

            if (row[i + 1] == partner)
                continue;

            for (int j = i + 2; j < n; j++) {
                if (row[j] == partner) {
                    swap(row[j], row[i + 1]);
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};