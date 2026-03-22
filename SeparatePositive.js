function separate()
{
let negArr = []
let posArr = []
for(let i =0;i<arr.length;i++)  
{
    if(arr[i]<0)
    {
        negArr.push(arr[i]);
    }
    else
    {
        posArr.push(arr[i]);
    }
}
console.log('Negative Array :',negArr)
console.log('Positive Array :',posArr)
}


let arr = [-1,-4,2,4,-3,5,9];
separate(arr)