let myArray = [ 38, 27, 43, 10 ];


// start and end are the index of the array
const splitArray = (arr, start, end) => {
    if( start < end ) {

        const mid =  Math.floor((end + start ) / 2);
        const split1 = splitArray(arr, start, mid);
        const split2 = splitArray(arr, mid + 1, end);

        const newArray = mergeFunction(split1, split2);
        return newArray;
    }

    return [arr[start]]
    
}

const mergeFunction = (split1, split2) => {

    let i = 0, j = 0;
    let newArray = [];

    while(i < split1.length && j < split2.length) {
        if(split1[i] <= split2[j]){
            newArray.push(split1[i]);
            i++;
        } else {
            newArray.push(split2[j]);
            j++;
        }
    }

    while (i < split1.length) {
        newArray.push(split1[i]);
        i++;
    }

    while (j < split2.length) {
        newArray.push(split2[j]);
        j++;
    }

    return newArray;

}

const mergeSort = () => {

    const sort = splitArray(myArray, 0, myArray.length - 1);

    console.log(sort)

}
mergeSort()