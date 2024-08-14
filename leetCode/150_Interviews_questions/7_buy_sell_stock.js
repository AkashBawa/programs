/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {

    let minIndex = 0;
    let currentProfit = 0;
    let totalProfit = 0;
    for(let i = 1; i < prices.length; i++) {

        if(prices[i] <= prices[minIndex]) {
            
            if(currentProfit > 0) {
               totalProfit +=  currentProfit;
               currentProfit = 0;
            }
            minIndex = i; 

        } else if( prices[i] > prices[minIndex] ) {

            let profit = prices[i] - prices[minIndex]
            if(profit > currentProfit) {
                currentProfit = profit;
            } else if ( profit < currentProfit ) {
                totalProfit +=  currentProfit;
                minIndex = i;
                currentProfit = 0;
            }
        }
    }

    if(currentProfit > 0) {
        totalProfit +=  currentProfit;
    }

    return totalProfit;
};