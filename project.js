// Select the buttons and sections
const calculatorButton = document.getElementById('calculator-button');
const converterButton = document.getElementById('converter-button');
const calculatorSection = document.getElementById('calculator-section');
const converterSection = document.getElementById('converter-section');

// Toggle visibility between Calculator and Converter
calculatorButton.addEventListener('click', () => {
    calculatorSection.style.display = 'block';
    converterSection.style.display = 'none';
   

});

converterButton.addEventListener('click', () => {
    calculatorSection.style.display = 'none';
    converterSection.style.display = 'block';
});

// Currency converter logic
const apiKey = '52e45dee4537fe342271b78d';  //API key
const apiUrl = `https://v6.exchangerate-api.com/v6/${apiKey}/latest/USD`;

// Fetch available currencies and populate dropdowns
fetch(apiUrl)
  .then(response => response.json())
  .then(data => {
    const currencies = data.conversion_rates;
    populateCurrencyDropdowns(currencies);
  })
  .catch(error => console.error('Error fetching exchange rates:', error));

function populateCurrencyDropdowns(currencies) {
    const fromCurrencyEl = document.getElementById('from-currency');
    const toCurrencyEl = document.getElementById('to-currency');
    
    const currencyOptions = Object.keys(currencies)
        .map(currency => `<option value="${currency}">${currency}</option>`)
        .join('');

    fromCurrencyEl.innerHTML = currencyOptions;
    toCurrencyEl.innerHTML = currencyOptions;

    fromCurrencyEl.value = 'USD';
    toCurrencyEl.value = 'INR';
}

// Handle conversion
document.getElementById('convert').addEventListener('click', () => {
    const amount = document.getElementById('amount').value;
    const fromCurrency = document.getElementById('from-currency').value;
    const toCurrency = document.getElementById('to-currency').value;

    if (!amount || amount <= 0) {
        document.getElementById('result').textContent = 'Please enter a valid amount.';
        return;
    }

    fetch(`https://v6.exchangerate-api.com/v6/${apiKey}/pair/${fromCurrency}/${toCurrency}/${amount}`)
        .then(response => response.json())
        .then(data => {
            const convertedAmount = data.conversion_result;
            document.getElementById('result').textContent = `${amount} ${fromCurrency} = ${convertedAmount} ${toCurrency}`;
        })
        .catch(error => console.error('Error converting currency:', error));
});

// Calculator logic
let displayValue = '0';
let firstOperand = null;
let operator = null;
let waitingForSecondOperand = false;

const calcDisplay = document.getElementById('calc-display');
const numberButtons = document.querySelectorAll('.number');
const operatorButtons = document.querySelectorAll('.operators');

numberButtons.forEach(button => {
    button.addEventListener('click', () => {
        handleNumber(button.textContent);
        updateDisplay();
    });
});

operatorButtons.forEach(button => {
    button.addEventListener('click', () => {
        handleOperator(button.textContent);
        updateDisplay();
    });
});

document.querySelector('.func_keys').addEventListener('click', clear);
document.getElementById('equal').addEventListener('click', () => {
    if (firstOperand !== null && operator) {
        const result = calculate(firstOperand, parseFloat(displayValue), operator);
        displayValue = String(result);
        operator = null; // Reset operator after calculation
        firstOperand = null; // Reset first operand for a new calculation
        waitingForSecondOperand = false; // Reset the second operand flag
        updateDisplay();
    }
});

function handleNumber(number) {
    if (waitingForSecondOperand) {
        displayValue = number; // Start a new operand
        waitingForSecondOperand = false;
    } else {
        displayValue = displayValue === '0' ? number : displayValue + number;
    }
}

function handleOperator(nextOperator) {
    const inputValue = parseFloat(displayValue);
    
    if (firstOperand === null) {
        firstOperand = inputValue; // Set first operand
    } else if (operator) {
        const result = calculate(firstOperand, inputValue, operator);
        displayValue = String(result); // Update display with result
    }
    
    waitingForSecondOperand = true; // Now waiting for second operand
    operator = nextOperator; // Update operator
    updateDisplay(); // Update display with first operand and operator
}

function calculate(first, second, operator) {
    switch (operator) {
        case '+': return first + second;
        case '-': return first - second;
        case '*': return first * second;
        case '/': return first / second;
        case '%': return first % second;
        case '^': return Math.pow(first, second);
        default: return second;
    }
}

function updateDisplay() {
    if (waitingForSecondOperand) {
        // Show first operand and operator only
        calcDisplay.textContent = `${firstOperand} ${operator}`;
    } else if (operator) {
        // Show first operand, operator, and second operand
        calcDisplay.textContent = `${firstOperand} ${operator} ${displayValue}`;
    } else {
        calcDisplay.textContent = displayValue; // Show the current input value
    }
}

function clear() {
    displayValue = '0';
    firstOperand = null;
    operator = null;
    waitingForSecondOperand = false;
    updateDisplay();
}
