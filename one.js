var twoSum = function(nums, target) {
    target = 6;
    for(let i=0;i<nums.length-1;i++)
    {
        for(let j =i+1;j<nums.length;j++)
        {
             if(nums[i]+nums[j]==target)
             {
                return [i,j];
                
             }
        }
    }
    return [];
};

 
console.log(twoSum([1,2,3,5,2,4,8]));