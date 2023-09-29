const arr = [5, 6, 7, 8, 9, 10, 1, 2, 3];

const binaryInRoatation = (begin, end, toFind) => {
    if( begin <= end) {
        const mid = Math.floor((begin + end) / 2);
        if(arr[mid] == toFind) {
            return mid;
        } else if(arr[mid] > toFind && arr[begin] <= toFind) {
            return binaryInRoatation(begin, mid - 1, toFind);
        } else if (arr[mid] > toFind && arr[begin] >= toFind) {
            return binaryInRoatation(mid + 1, end, toFind);
        } else if (arr[mid] < toFind) {
            return binaryInRoatation(mid + 1, end, toFind);
        }
    }
}

// console.log(binaryInRoatation(0, arr.length - 1, 5));


const findPivot = (begin, end) => {
    if (begin <= end) {
        const mid = Math.floor((begin + end) / 2);
        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        } else if (arr[mid] > arr[begin]) {
            return findPivot(mid + 1, end);
        } else {
            return findPivot(begin , mid-1 );
        }
    }
}

console.log(findPivot(0, arr.length - 1));