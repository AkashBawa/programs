var x = ['A', 'b','c','d','e','!','$'];

let len = x.length;

var start = 0;
var end = len - 1;

console.log(x)

while(start < end){
  if(!isAlphabet(x[start])){
    start++;
    continue;
  }
  if(!isAlphabet(x[end])){
    end--
    continue;
  }
  let temp = x[start];
  x[start] = x[end];
  x[end] = temp;
  start++;
  end--;
}
console.log(x)
console.log()
function isAlphabet(x){
  if((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')){
    return true
  }
}