function maxGoodSubarraySum(arr, k) {
  let left = 0;
  let sum = 0;
  let maxSum = 0;

  let freq = new Map();

  for (let right = 0; right < arr.length; right++) {
    let val = arr[right];
    freq.set(val, (freq.get(val) || 0) + 1);
    sum += val;
    while (freq.size > k) {
      let leftVal = arr[left];

      freq.set(leftVal, freq.get(leftVal) - 1);
      if (freq.get(leftVal) === 0) {
        freq.delete(leftVal);
      }

      sum -= leftVal;
      left++;
    }

    maxSum = Math.max(maxSum, sum);
  }

  return maxSum;
}

let A = [1, 2, 2, 3, 2, 3, 5, 1, 2, 1, 1];
let k = 2;

console.log(maxGoodSubarraySum(A, k));
