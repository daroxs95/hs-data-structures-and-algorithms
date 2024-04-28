//https://leetcode.com/problems/jump-game/description/

#include <vector>
#include <iostream>

using namespace std;

bool can_jump(int pos, const vector<int> &nums, vector<int> &memo) {
    if (pos + 1 == nums.size()) {
        return true;
    }

    if (memo[pos] != -1) {
        return memo[pos];
    }
    memo[pos] = false;

    for (int i = pos + 1; i < nums.size() and i <= pos + nums[pos]; ++i) {
        if (can_jump(i, nums, memo)) {
            return memo[i] = true;
        }
    }

    return false;
}

class Solution {
public:
    bool canJump(vector<int> &nums) {
        vector<int> memo(nums.size(), -1);
        return can_jump(0, nums, memo);
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << s.canJump(nums) << endl;
    return 0;
}