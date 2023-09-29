const arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91];


const binarySearch = (begin, end, toFind) => {

    if (begin < end) {
        const mid = Math.floor((begin + end) / 2);
        if (arr[mid] == toFind) {
            return mid;
        } else if(arr[mid] < toFind) {
            return binarySearch(mid + 1, end, toFind);
        } else if (arr[mid] > toFind) {
            return binarySearch(begin, mid - 1 ,toFind );
        }
    }
}

console.log(binarySearch(0, arr.length - 1, 23));