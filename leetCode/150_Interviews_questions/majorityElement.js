/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {

    // time limit exceeds
    let n = nums.length;
    // let ans = nums[0];
    
    // for(let i = 0; i < n; i++) {
    //     let num = 1;
    //     for(let j = 0; j < n; j++) {
    //         if(nums[i] == nums[j] && i != j) {
    //             num++;
    //         }
    //     }

    //     if(num > n / 2 ) {
    //         ans = nums[i]
    //     }
    // }
    // return ans

    let tempArr = [];
    let result;
    for(let i = 0; i < n; i++) {
        if(tempArr[nums[i]]) {
            tempArr[nums[i]]++
        } else {
            tempArr[nums[i]] = 1
        }

        if( tempArr[nums[i]] > n / 2 ) {
            result = nums[i];
            break;
        }
    }
    return result;


    // Best solution

    // increse the counter if the element matches and decrese it if does not, update the value of element if the counter hits zero
    

    let count = 0;
    let element = nums[0]
    for(let i = 0; i < nums.length; i++) {

        if(count == 0) {
            element = nums[i];
            count++
        } else if(nums[i] == element) {
            count++
        } else {
            count--
        }
    }

    return element;
};