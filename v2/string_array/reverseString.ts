// as string is primitive value and str[i] can only be used to reading purpose


let str1 = "a!!!b.c.d,e'f,ghi";
const str = [...str1];
function isAlphabet(s : string) {
    if((s >= 'a' && s <= 'z' ) || s >= 'A' && s <= 'Z') {
        return true
    }
    return false;
}

(function reverse() {

    let i = 0, j = str.length;

    while(i < j) {
        if(isAlphabet(str[i]) && isAlphabet(str[j])) {
            let temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        } else if (!isAlphabet(str[i])) {
            i++
        } else if(!isAlphabet(str[j])) {
            j--;
        }
    }

}) ();

console.log(str)