function maxArray()
{
    let i, max = arr[0];
    for( i = 0;i<arr.length;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}

let arr = [1,2,4,2,8,9];
console.log(maxArray(arr))