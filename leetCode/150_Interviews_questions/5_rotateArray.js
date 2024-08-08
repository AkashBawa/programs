/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    // let n = nums.length;
    // let lastIndex = n - 1;

    //  time out
    // for(let i = 0; i < k; i++) {
    //     let nextVal = nums[0];
    //     for(let j = 1; j <= n; j++) {

    //         let modVal = j % n;

    //         let temp = nums[modVal];
    //         nums[modVal] = nextVal;
    //         nextVal = temp;
    //     }
    // }  


    //  copy entire array
    // let newArray = [...nums];
    // for(let i = 0; i < n; i++) {
    //     let modVal = (i + k) % n;
    //     nums[modVal] = newArray[i]; 
    // }

    // copy last k element
    let n = nums.length;
    let newk = k % n;
    let tempArray = [];
    if(newk == 0) return;

    for(let  i = n - newk, j = 0; i < n; i++, j++){
        tempArray[j] = nums[i]
    }
    for(let i = n - 1; i >= newk; i--) {
        nums[i] = nums[i - newk]; 
    }

    for(let i = 0; i < tempArray.length; i++ ) {
        nums[i] = tempArray[i]
    }

};