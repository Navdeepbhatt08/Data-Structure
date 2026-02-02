// stack_menu.js
const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let stack = [];

function showMenu() {
  //Menu Is Here
    console.log("1. Push");
    console.log("2. Pop");
    console.log("3. Peek");
    console.log("4. Display");
    console.log("5. Exit");

    rl.question("Enter your choice: ", handleChoice);
}

function handleChoice(choice) {
    switch (choice) {
        case "1": 
            rl.question("Enter element to push: ", (element) => {
                stack.push(element);
                console.log(element + " pushed into stack");
                showMenu();
            });
            break;

        case "2": 
            if (stack.length === 0) {
                console.log("Stack Underflow! Stack is empty");
            } else {
                let removed = stack.pop();
                console.log(removed + " popped from stack");
            }
            showMenu();
            break;

        case "3": // PEEK
            if (stack.length === 0) {
                console.log("Stack is empty");
            } else {
                console.log("Top element is:", stack[stack.length - 1]);
            }
            showMenu();
            break;

        case "4": // DISPLAY
            if (stack.length === 0) {
                console.log("Stack is empty");
            } else {
                console.log("Stack elements:", stack.join(" "));
            }
            showMenu();
            break;

        case "5": // EXIT
            console.log("Exiting program...");
            rl.close();
            break;

        default:
            console.log("Invalid choice! Try again");
            showMenu();
    }
}

// start program
showMenu();
