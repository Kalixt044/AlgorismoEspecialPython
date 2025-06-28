// Function definition
function myFunction(a, b) {
    // Function returns the product of a and b
    return a * b;
}

// Get arguments from command line
const a = process.argv[2];
const b = process.argv[3];

// Function is called, the return value will end up in x
let x = myFunction(a, b);

// Display the result
console.log(x);
