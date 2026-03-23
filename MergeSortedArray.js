var merge = function(nums1, m, nums2, n) {
    for (let i = m, j = 0; j < n; j++, i++) {
        nums1[i] = nums2[j];
    }

    nums1.sort((a, b) => a - b);
    console.log(nums1);
};

let nums1 = [2,1,9,4];
let nums2 = [0,6,8,3];

merge(nums1, nums1.length, nums2, nums2.length);