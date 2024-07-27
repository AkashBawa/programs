const arr = [1,2,3,5];

const findMissing = () => {

    let temp = [];

    for(let i = 1; i <= arr.length + 1; i++) {
        temp[i] = 0
    }
    // console.log(temp)
    for(let i = 0; i < arr.length; i++) {
        temp[arr[i]] = 1
    }

    for(let i = 1; i <= temp.length; i++) {
        if(temp[i] == 0) {
            console.log(i)
        }
    }

}

findMissing();