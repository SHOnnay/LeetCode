class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st = 0, end = numbers.size() - 1;
        while (st < end) {
            if (numbers[st] + numbers[end] == target) {
                return {st+1, end+1};
            } else if (numbers[st] + numbers[end] > target) {
                end--;
            } else if (numbers[st] + numbers[end] < target) {
                st++;
            }
        }
        return {};
    }
};
