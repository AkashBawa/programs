// const arr = [3, 0, 2, 0, 4];
const arr = [ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1];
let totalWater = 0;
const trappingArray = () => {

    for(let i = 1; i < arr.length - 1; i++) {

        let leftMax = arr[i];
        let rightMax = arr[i];

        for(let j = 0; j < i; j++) {
            if(arr[j] > leftMax) {
                leftMax = arr[j]
            }
        }

        for(let j = i; j < arr.length; j++) {
            if(arr[j] > rightMax) {
                rightMax = arr[j]
            }
        }
        console.log("left Right arr[i]" , leftMax, rightMax, arr[i])

        let smaller = leftMax > rightMax ? rightMax : leftMax;
        if(smaller - arr[i] )
        totalWater += smaller - arr[i]

        console.log(totalWater)
    }

}

trappingArray();

console.log(totalWater)