class Node_ {
    
    data : number;
    left : Node_;
    right : Node_;
    
    constructor (data: number){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}



const root = new Node_(1);
root.left = new Node_(2);
root.right = new Node_(3);
root.left.right = new Node_(4);
root.left.right.right = new Node_(5);
root.left.right.right.right = new Node_(6);


let obj : {[key : string] : number} = {}  // key represent the horizontal distance and the value represent the data in that node
let arr : Node_[] = [];

interface nodeWithHorizontal {
    node : Node_ 
    horizontalDistance : number
}

let bstArray : nodeWithHorizontal[] = [];

function arrangeInBFS(start : Node_){

    bstArray.push({node : start,horizontalDistance :0})

    while(bstArray.length > 0){
        let current = bstArray.shift();

        if(!obj[current.horizontalDistance]){
            obj[current.horizontalDistance] = current.node.data;
        }

        if(current.node.left != null)
            bstArray.push({node : current.node.left, horizontalDistance : current.horizontalDistance - 1});
        if(current.node.right != null)
            bstArray.push({node : current.node.right, horizontalDistance : current.horizontalDistance + 1})
    }
}

arrangeInBFS(root)

function arrangObj(obj){
    let keys =  Object.keys(obj);
    keys = keys.sort((a,b)=>{
        return Number(a) - Number(b)
    })

    for(let i = 0; i < keys.length; i++){
        console.log(obj[keys[i]])
    }
}
arrangObj(obj)