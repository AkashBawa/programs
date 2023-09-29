const arr = [12, 11, 13, 5, 6 ];

const swap = (first, second) => {
    let temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

const insertionSort = () => {
    for (let  i = 0; i < arr.length; i++) {

        for (let j = i; j > 0; j--) {
            if ( arr[j] < arr[j - 1]  ) {
                swap(j, j -1);
            }
        }
        
    }
}
insertionSort();
console.log(arr);