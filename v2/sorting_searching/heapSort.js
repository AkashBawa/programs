const myArray = [1, 11, 13, 5, 6, 7];

const getLeftChild = (index) => {
    return index * 2 + 1;
}

const getRightChild = (index) => {
    return index * 2 + 2 ;
}

const getParentIndex = (index) => {
    return Math.floor((index - 1)/2);
}

const swap = (index1, index2) => {
    let temp = myArray[index1];
    myArray[index1] = myArray[index2];
    myArray[index2] = temp;
}

const getNonLeafNode = (n) => {
    if (n % 2 == 0) {
        return n / 2 - 1;
    } else {
        return Math.floor(n/2);
    }
}


// heapify down method
const createHeapDown = (index, n) => {
    
    // console.log("Index ", index)

    const leftChild = getLeftChild(index);
    const rightChild = getRightChild(index);
    let largest = -1;

    if(rightChild <= n) {
        largest = myArray[leftChild] > myArray[rightChild] ? leftChild : rightChild
    } else {
        largest = leftChild;
    }

    if(myArray[index] < myArray[largest]) {
        swap(index, largest);
        createHeapDown(largest, n)
    }
}


const createHeapDownInSort = (index, n) => {
    
    console.log("Index ", index)

    const leftChild = getLeftChild(index);
    const rightChild = getRightChild(index);
    let largest = -1;

    if(leftChild > n) {
        return;
    } 
    if(rightChild <= n) {
        largest = myArray[leftChild] > myArray[rightChild] ? leftChild : rightChild;
    } else {
        largest = leftChild;
    }

    if(myArray[index] < myArray[largest]) {
        swap(index, largest);
        createHeapDownInSort(largest, n);
    }
}


// head sort
let newArray = [];
const heapSort = (last) => {


    // console.log("Top: ", myArray[0], "Last: ", myArray[last]);
    swap(0, last);
    createHeapDownInSort(0, last - 1);
}

const main = () => {

    const startIndex = getNonLeafNode(myArray.length);
    const length = myArray.length;
    for(let i = startIndex; i >= 0; i--) {
        createHeapDown(i, myArray.length - 1);
    }
    console.log(myArray);

    for(let i = 0; i < length; i++) {
        
        heapSort(length - 1 - i);
    }
    console.log(myArray);
}

main();