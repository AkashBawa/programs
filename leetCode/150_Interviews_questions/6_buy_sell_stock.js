/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    
    let minIndex = 0;
    let maxDifference = 0;
    let maxIndex = 0;
    for(let i = 1; i < prices.length; i++) {

        if( prices[i] > prices[minIndex] ) {
            let tempDifference = prices[i] - prices[minIndex];

            if(tempDifference > maxDifference ) {
                maxDifference = tempDifference;
            } else {

            }
        } else if(prices[i] < prices[minIndex]) {
            minIndex = i;
        }

    }

    return maxDifference;

};