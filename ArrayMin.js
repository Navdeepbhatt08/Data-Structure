function maxArray()
{
    let i, min = arr[0];
    for( i = 0;i<arr.length;i++)
    {
        if(arr[i]<min)
        {
            min = arr[i];
        }
    }
    return min;
}

let arr = [1,2,4,2,8,9];
console.log(maxArray(arr))