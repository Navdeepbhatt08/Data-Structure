function countFrequency(arr) {
    let n = arr.length;

    for (let i = 0; i < n; i++) {
        // Skip already counted elements
        if (arr[i] === null) continue;

        let count = 1;

        for (let j = i + 1; j < n; j++) {
            if (arr[i] === arr[j]) {
                count++;
                arr[j] = null; 
            }
        }

        console.log(arr[i] + " occurs " + count + " times");
    }
}


let arr = [2, 3, 2, 5, 3, 2];
countFrequency(arr);