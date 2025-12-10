class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Peak is to the right
                left = mid + 1;
            } else {
                // Peak is on left side or at mid
                right = mid;
            }
        }

        return left; // or right, since left == right
    }
};
