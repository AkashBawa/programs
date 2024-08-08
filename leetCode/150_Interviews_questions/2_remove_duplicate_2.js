/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    // let k = 0
    // for(let i = 1; i < nums.length; i++) {
    //     if(nums[i] == nums[k]) {
    //         if(k == 0 || nums[k - 1] != nums[i]) {
    //             k++;
    //             nums[k] = nums[i]
    //         }
    //     } else {
    //         k++;
    //         nums[k] = nums[i]
    //     }
    // }
    // k++;
    // return k;  


    // best way 

    let j = 2;
    for(let i = 2; i < nums.length; i++) {
        if(nums[i] !== nums[j -2]) {
            nums[j] = nums[i];
            j++
        }
    }

    return j
};