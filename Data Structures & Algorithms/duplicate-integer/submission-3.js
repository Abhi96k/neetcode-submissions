class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        const n=nums.length;
        for(let i=0;i<n;i++){
            for(let j=i+1;j<n;j++){
                if(nums[i]===nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
}
