
const traverseIndex = 0;
const finalArray = [];
const findSubset = (array, currentState, index) => {
    
    if(index >= array.length) {

        finalArray.push([...currentState]);
        return;
    }
    
    let newArray = [...currentState];
    newArray.push(array[index]);

    findSubset(array, [...newArray], index + 1);
    findSubset(array, [...currentState], index + 1);

}

const mainFunction = (array) => {
    
    findSubset(array, [], 0);
    console.log(finalArray);

}

mainFunction([0])