class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int fill = left;
        int pivot = nums[right];

        for (int i = left; i < right; i++) {
            if (nums[i] <= pivot) {
                swap(nums[fill], nums[i]);
                fill++;
            }
        }
        swap(nums[fill], nums[right]); 
        return fill;
    }

    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int pivot = partition(nums, left, right);
            if (pivot < k) {
                left = pivot + 1;
            } else if (pivot > k) {
                right = pivot - 1;
            } else {
                break;
            }
        }
        return nums[k];
    }
};
