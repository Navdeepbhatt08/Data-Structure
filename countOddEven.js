function findOddEven()
{
    let i, countOdd = 0 , countEven = 0;
    for( i = 0;i<arr.length;i++)
    {
        if(arr[i]%2 == 0)
        {
            countEven++;
        }
        else if(arr[i]%2!=0)
        {
        countOdd++;
    }
}
    console.log("Even Element",countEven )
    console.log(" Odd Element ",countOdd )
    
}


let arr = [1,2,4,2,8,5,7,9];
findOddEven(arr)