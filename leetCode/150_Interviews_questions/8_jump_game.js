/**
 * @param {number[]} nums
 * @return {boolean}
 */

let isRechable = (nums, index) => {
    
    if(index == nums.length - 1 ) {
        return true
    }
    if(index > nums.length) return false;

    let firstVal = nums[index];
    let isReached = false;
    for(let i = 1; i <= firstVal; i++){
        let reached = isRechable(nums, index + i);
        if( reached ) {
            isReached = true;
            break;
        }
    }

    return isReached;
}


var canJump = function(nums) {
    return isRechable(nums, 0)
};

console.log(canJump([2,3,1,1,4]))