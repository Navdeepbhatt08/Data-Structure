function maxArray()
{
    let i, sum = 0;
    for( i = 0;i<arr.length;i++)
    {
        {
            sum = sum+arr[i];
        }
    }
    return sum;
}

let arr = [1,2,4,2,8,9];
console.log("Sum is :",maxArray(arr))