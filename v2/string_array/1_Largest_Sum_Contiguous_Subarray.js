const arr = [-2,-3,4,-1,-2,1,5,-3];
// const arr = [5,4,1,7,8];

const findLargest = () => {

    let largestSum = arr[0];
    let activeSum = arr[0];
    let startIndex = 0;
    let endIndex = 0;

    for(let i = 1; i < arr.length; i++) {

        activeSum = activeSum + arr[i];

        // if(activeSum < 0 && arr[i] > 0) {
        //     activeSum = arr[i];
        //     startIndex = i
        // } else if (activeSum > 0 && arr[i] > 0) {
        //     activeSum += arr[i];
        //     endIndex = i
        // } else if ( activeSum > 0 && arr[i] < 0) {
        //     activeSum += arr[i];
        //     endIndex = i
        // } else {
        //     activeSum += arr[i];
        //     endIndex = i
        // }


        if(largestSum < activeSum) {
            largestSum = activeSum
        }

        if(activeSum < 0) {
            activeSum = 0
        }
    }


    console.log(largestSum)

} 


findLargest()