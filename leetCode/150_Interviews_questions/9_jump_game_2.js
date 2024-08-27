/**
 * @param {number[]} nums
 * @return {number}
 */


let recursion = (nums, index, newArray) => {

    if (newArray[index] != null) {
        if(newArray[index] == -1) {
            return -1;
        }
        return newArray[index] + 1;
    }
    console.log("index ", index)
    if(index == nums.length - 1 ){
        newArray[index] = 0;
        return 1
    } else if (index >= nums.length) {
        return -1;
    }

    let currentVal = nums[index];

    let bestPath = -1;


    for(let i = 1; i <= currentVal; i++) {

        let val = recursion(nums, index + i, newArray); 

        if(index == 33) {
            console.log("val is i ", i ," is" , val)
        }
        if(val == -1) {
            continue;
        } 
        if(bestPath == -1) {
            bestPath = val;
        } else if(bestPath > val) {
            bestPath = val;
        }
    }

    console.log("index ", index, " best part ", bestPath)

    if(bestPath == -1) {
        newArray[index] = -1;
        return -1;
    } else {
        newArray[index] = bestPath;
    }

    return bestPath + 1;

}

var jump = function(nums) {
    let newArray = []
    recursion(nums, 0, newArray)
    console.log(newArray)
    return newArray[0]
};

// console.log(jump([5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5]))
// console.log(jump([2,3,1,1,4]))

// console.log(jump([2,3,0,1,4]))
console.log(jump([0]))