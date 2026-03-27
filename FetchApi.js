async function getData() {
  const url = "https://example.org/products.json";
  try {
    const response = await fetch(url);
    if (!response.ok) throw new Error(`Status: ${response.status}`);

    const result = await response.json();
    return result; // return instead of just logging
  } catch (error) {
    console.error(error.message);
  }
}

// Call and use the data
const data = await getData();
console.log(data);