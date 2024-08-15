// Dymanic programming method
/**
 * @param {number[]} nums
 * @return {boolean}
 */

let isRechable = (nums, index, newArr) => {

    if(newArr[index] != null) {
        return newArr[index];
    }
    if(index == nums.length - 1 ) {
        newArr[index] = true;
        return true
    }
    if(index > nums.length) return false;

    let firstVal = nums[index];
    for(let i = 1; i <= firstVal; i++){
        if(isRechable(nums, index + i, newArr)) {
            return true;
        }
    }
    newArr[index] = false;
    return false;
}


var canJump = function(nums) {
    let newArr = [];
    return isRechable(nums, 0, newArr)
};


// /**
//  * @param {number[]} nums
//  * @return {boolean}
//  */

// let isRechable = (nums, index) => {

//     if(index == nums.length - 1 ) {
//         return true
//     }
//     if(index > nums.length) return false;

//     let firstVal = nums[index];
//     let isReached = false;
//     for(let i = 1; i <= firstVal; i++){
//         let reached = isRechable(nums, index + i);
//         if( reached ) {
//             isReached = true;
//             break;
//         }
//     }

//     return isReached;
// }


// var canJump = function(nums) {
//     return isRechable(nums, 0)
// };

// console.log(canJump([2,3,1,1,4]))