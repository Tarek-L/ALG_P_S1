#include <stdio.h>
#include <stdbool.h>

double power(int base, int exponent)
{
    double result = base;
    int i;

    if (exponent == 0) {
        return 1; // Any number raised to the power 0 is 1
    }
    if (base == 0 && exponent == 0) {
        return 0; // This case is undefined in most contexts
    }

    if (exponent < 0) {
        result = 1.0 / base; // Handle negative exponents
        for (i = -1; i > exponent; --i) {
            result /= base;
        }
    } else {
        for (i = 1; i < exponent; ++i) {
            result *= base; // Compute positive powers
        }
    }

    return result;
}

void swap(int *num1, int *num2)
{
    if (*num1 != *num2) {
        // Swap values using XOR bitwise operation
        *num1 = *num1 ^ *num2;
        *num2 = *num1 ^ *num2;
        *num1 = *num1 ^ *num2;
    }
}

int sumOfDigits(int num)
{
    if (num < o)
        num = -1*num;

    int sum = 0;

    while (num != 0)
    {
        sum = sum + (num % 10); // Add the last digit to the sum
        num = num / 10; // Remove the last digit from the number
    }

    return sum;
}

int reverseNumber(int num)
{
    if (num < o)
        num = -1*num;

    int reversed = 0;

    while (num != 0)
    {
        reversed = reversed * 10 + (num % 10); // Add the last digit to the reversed number
        num = num / 10; // Remove the last digit from the number
    }

    return reversed;
}

bool isPalindrome(int num) 
{
    if (num < o)
        num = -1*num;
    return (num == reverseNumber(num));
}

bool isPrime(int num)
{
    if (num <= 1) {
        return false; // Numbers less than or equal to 1 are not prime
    }

    int i;

    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false; // Found a divisor, so the number is not prime
        }
    }
    return true; // No divisors found, the number is prime
}

int gcd(int num1, int num2)
{
    if (num1 < 0)
        num1 = -1*num1;
        if (num2 < 0)
            num2 = -1*num2;

    int mod;

    if (num1 == 0 && num2 == 0)
    {
        return 1; // Special case: gcd(0, 0) is undefined, returning 1 as a placeholder
    }

    if (num2 > num1)
    {
        swap(&num2, &num1); // Ensure num1 >= num2
    }

    while (num2 != 0 && num2 != 1)
    {
        mod = num1 % num2; // Calculate the remainder
        num1 = num2; // Update num1
        num2 = mod; // Update num2
    }

    if (mod == 0)
    {
        return num1; // gcd found
    }
    else
    {
        return 1; // gcd is 1 when no other common divisor exists
    }
}

int lcm(int num1, int num2) 
{
    int lcm = (num1 * num2) / gcd(num1, num2);//lcm*gcd = num1*num2

    if (lcm < 0)
        lcm = lcm*-1;

    return lcm;
}

long int fact(int num)
{
    // Handle the special case where the input number is negative
    if (num < 0) {
        // Factorial is not defined for negative numbers
        return -1; // Returning -1 to indicate an error
    }

    long int fact = 1;

    // Calculate the factorial by multiplying decrementing numbers
    while (num > 1)
    {
        fact = fact * num;  // Multiply current fact with the number
        num--;  // Decrement num by 1
    }

    return fact;  // Return the calculated factorial
}


bool isEven(int num) 
{
    return (num % 2 == 0);//even mod 2 = 0
}

void primeFact(int num, int factors[])
{
    // Handle the special case where the input number is negative
    if (num <= 0)
    {
        // Prime factorization is not defined for zero or negative numbers
        *factors = 0;  // Indicating the error by setting factors[0] to 0
    }

    int i = 2;
    // Loop through possible factors of num
    while (num > 1)
    {
        // Check if i is prime and a factor of num
        if (isPrime(i) && num % i == 0)
        {
            *factors = i;  // Store the prime factor in the factors array
            factors++;  // Move the pointer to the next position in the array
            num = num / i;  // Divide num by the factor i
        }
        else
        {
            i++;  // Increment i to check the next possible factor
        }
    }

    *factors = 0;  // Mark the end of the factors array with a 0
}

bool isArmstrong(int num)
{
    // Handle the special case where the input number is negative
    if (num < 0)
    {
        // Armstrong numbers are defined only for non-negative integers
        return false;  // Return false for negative numbers
    }

    int temp = num, isArmstrong = 0;

    // Loop through each digit of the number
    while (temp > 0)
    {
        // Add the cube of the last digit to the isArmstrong variable
        isArmstrong = isArmstrong + power((temp % 10), 3);
        temp = temp / 10;  // Remove the last digit from temp
    }

    // Check if the sum of the cubes of the digits equals the original number
    return (isArmstrong == num);
}


void fib(int num, int fib[])
{
    // Handle the special case where the input number is non-positive
    if (num <= 0)
    {
        // Return early if num is non-positive (no Fibonacci sequence to generate)
        return;
    }

    int fib0 = 1, fib1 = 1, fib2, i;

    // Generate Fibonacci sequence up to the num-th term
    for (i = 0; i < num; i++)
    {
        fib[i] = fib0;  // Store the current Fibonacci number in the array
        fib2 = fib1 + fib0;  // Calculate the next Fibonacci number
        fib0 = fib1;  // Update fib0 to the previous fib1
        fib1 = fib2;  // Update fib1 to the new fib2
    }
}

int sumDivisors(int num)
{
    // Handle the special case where the input number is zero
    if (num == 0)
        return 0;  // Return 0 for 0, as it has no divisors

        // Handle the special case where the input number is 1
        if (num == 1)
            return 1;  // 1 has only itself as a divisor

            // Handle the special case where the number is negative
            if (num < 0)
                return 0;  // Return 0 or an error value, as negative numbers don't have a meaningful sum of divisors

                int i, sumDiv = num + 1;  // Start sumDiv with num + 1, as num is always a divisor of itself

                // Loop to find divisors from 2 to num/2
                for (i = 2; i <= num / 2; i++)
                {
                    // Check if i is a divisor of num
                    if (num % i == 0)
                        sumDiv = sumDiv + i;  // Add the divisor to the sum
                }

                return sumDiv;  // Return the total sum of divisors
}

bool isPerfect(int num)
{
    return (sumDivisors(num)-num == num);//check if sum of divisors is the number
}

bool isMagic(int num)
{
    // Handle the special case where the input number is non-positive
    if (num <= 0)
    {
        // Magic numbers are defined for positive integers only
        return false;  // Return false for non-positive numbers
    }

    // Loop to repeatedly sum the digits of the number until it's a single digit
    do
    {
        num = sumOfDigits(num);  // Sum the digits of the number
    }
    while (num >= 10);  // Repeat the process until the number is a single digit

    // Check if the final single digit is 1, which is a magic number
    return (num == 1);
}


int numOfDigits(int num)
{
    int numOfDigits = 0;

    while (num != 0)
    {;
        num = num / 10;//shift the number by one digit
        numOfDigits ++;//count the number of digits
    }

    return numOfDigits;//number of digits
}

bool isAutomorphic(int num)
{
    // Handle the special case where the input number is negative
    if (num < 0)
    {
        // Automorphic numbers are typically defined for non-negative integers
        return false;  // Return false for negative numbers
    }

    // Calculate the rank based on the number of digits in the number
    int rank = power(10, numOfDigits(num));

    // Check if the square of the number modulo the rank equals the number itself
    return ((num * num) % rank == num);
}


void toBinary(int *num)
{
    // Handle the special case where the input number is zero
    if (*num == 0)
    {
        return;
    }

    // Handle the special case where the input number is negative
    if (*num < 0)
    {
        // Binary representation is typically defined for non-negative integers
        return;
    }

    int i = 0;
    int bin[*num];  // Array to store binary digits

    // Loop to convert the number to binary by dividing by 2
    while (*num > 0)
    {
        bin[i] = *num % 2;  // Store the remainder (binary digit) in the array
        *num = *num / 2;    // Divide the number by 2 for the next iteration
        i++;  // Increment the index to store the next binary digit
    }

    // Rebuild the binary number from the array of binary digits
    *num = 0;  // Reset num to 0 before building it from binary digits
    for (i = i - 1; i >= 0; i--)
    {
        *num = *num * 10 + bin[i];  // Rebuild the binary number
    }
}


bool isNarcissistic(int num)
{
    return (power(sumOfDigits(num),numOfDigits(num)) == num);//raise the sum of digits to the power of number of digits and check if it equals the number
}

double sqrtApprox(int num)
{
    // Handle the special case where the input number is negative
    if (num < 0)
    {
        // Square root of a negative number is not defined in the real number domain
        return -1;  // Return -1 or some error value for negative numbers
    }

    // Handle the special case where the input number is zero
    if (num == 0)
    {
        return 0;  // The square root of 0 is 0
    }

    double sq = num * 2, sq1 = num;

    // Use the Babylonian method (Newton's method) for approximating the square root
    while (sq - sq1 > 0.001)
    {
        sq = sq1;
        sq1 = 0.5 * (sq + num / sq);  // Update the approximation
    }

    return sq1;  // Return the approximate square root
}


bool isAbundant(int num)
{
    return (sumDivisors(num)-num >= num);
}

bool isDeficient(int num)
{
    return !(isAbundant(num));
}

int sumEvenFibonacci(int num)
{
    // Handle the special case where the input number is non-positive
    if (num <= 0)
    {
        return 0;  // Return 0 if num is non-positive, as there are no Fibonacci numbers to sum
    }

    int i, sumFib = 0;
    int fibo[num];

    // Generate Fibonacci sequence up to num terms
    fib(num, fibo);

    // Loop through the Fibonacci sequence and sum the even numbers
    for (i = 0; i < num; i++)
    {
        if (fibo[i] % 2 == 0)  // Check if the Fibonacci number is even
        {
            sumFib = sumFib + fibo[i];  // Add the even Fibonacci number to the sum
        }
    }

    return sumFib;  // Return the sum of even Fibonacci numbers
}

bool isHarshad(int num)
{
    return (num % sumOfDigits(num) == 0);//check if number is divisable by it's sum Of Digits
}

bool isHappy(int num)
{
    // Handle the special case where the input number is non-positive
    if (num <= 0)
        return false;  // Return false for non-positive numbers, as happy numbers are positive integers

        int sum = 0, digit;

    // Loop until the number becomes 1 (happy) or 4 (indicating a cycle of unhappy numbers)
    while (num != 1 && num != 4)
    {
        sum = 0;  // Reset sum for each iteration
        // Sum the squares of the digits of num
        while (num != 0)
        {
            digit = num % 10;          // Get the last digit
            sum = sum + digit * digit; // Add the square of the digit to the sum
            num = num / 10;            // Remove the last digit
        }

        num = sum;  // Set num to the sum of squares of its digits
    }

    // If num becomes 1, it's a happy number; otherwise, it's an unhappy number (loop detected)
    return (num == 1);
}

int catalanNumber(int num)
{
    // Handle the special case where the input number is negative
    if (num < 0)
    {
        // Return an error value or handle invalid input
        return -1;  // Return -1 for invalid input (negative number)
    }

    // Handle the special case where num is zero
    if (num == 0)
        return 1;  // The 0th Catalan number is 1

        int catalan0 = 1, catalan1 = 1, i;

    // Loop to calculate the Catalan number using the iterative approach
    for (i = 1; i <= num; i++)
    {
        catalan0 = catalan1;  // Update previous Catalan number
        // Calculate the next Catalan number using the formula
        catalan1 = (catalan0 * 2 * (2 * i + 1)) / (i + 2);
    }

    // Return the nth Catalan number
    return catalan0;
}

void pascalTriangle(int num, int pascalTriangle[][100])
{
    // Handle the special case where the input number is non-positive
    if (num <= 0)
    {
        return;  // Exit the function if the input is invalid
    }

    // Initialize the first column and diagonal elements to 1
    for (int i = 0; i < num; i++)
    {
        pascalTriangle[i][0] = 1;  // Set the first column of each row to 1
        pascalTriangle[i][i] = 1;  // Set the diagonal elements to 1
    }

    // Fill in the rest of the Pascal's Triangle using the formula
    for (int i = 2; i < num; i++)
    {
        for (int j = 1; j < i; j++)
        {
            // The value of each non-border element is the sum of the two elements above it
            pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
        }
    }
}

int bellNumber(int num) {
    if (num < 0) 
    {
        return -1;
    }

    int bell[100][100];
    int i, j;

    // Base case: The first Bell number is 1
    bell[0][0] = 1;

    for (i = 1; i <= num; i++) {
        // The first element of each row is the last element of the previous row
        bell[i][0] = bell[i - 1][i - 1];

       // Fill the rest of the row
        for (j = 1; j <= i; j++) {
            bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
        }
    }

    // Return the Bell number at the specified index
    return bell[num][0];
}

bool isKaprekar(int num)
{
    // Handle the special case where the input number is non-positive
    if (num <= 0)
    {
        // Return false for non-positive numbers, as Kaprekar numbers are defined for positive integers
        return false;
    }

    // Calculate the number of digits in num and use it to find the correct "split point"
    int cPoint = power(10, numOfDigits(num));

    // Calculate the two parts of the squared number
    int kap0 = (num * num) % cPoint;    // Right part (remainder when divided by the split point)
    int kap1 = (num * num) / cPoint;    // Left part (quotient when divided by the split point)

    // Return true if the sum of the two parts equals the original number
    return (kap0 + kap1 == num);
}

bool isSmith(int num)
{
    // Handle the special case for negative numbers
    if (num < 0)
        num = -num;  // Convert negative numbers to positive, as Smith numbers are positive integers

        // If the number is prime, it cannot be a Smith number
        if (isPrime(num))
            return false;  // Return false if the number is prime

            // Calculate the sum of digits of the original number
            int smith0 = sumOfDigits(num), smith1 = 0, i;
        int sFactors[34];

    // Find the prime factors of the number
    primeFact(num, sFactors);

    // Sum the digits of the prime factors
    for (i = 0; sFactors[i] != 0; i++)
        smith1 = smith1 + sumOfDigits(sFactors[i]);

    // Return true if the sum of digits of the number equals the sum of digits of its prime factors
    return (smith0 == smith1);
}

int sumOfPrimes(int num)
{
    // Handle the special case where the input number is less than 2
    if (num < 2)
    {
        return 0;  // No primes less than 2, so return 0
    }

    int sum = 0, i;

    // Loop through all numbers from 2 to num and add the prime numbers to sum
    for (i = 2; i <= num; i++)
    {
        if (isPrime(i))  // Check if the number is prime
        {
            sum = sum + i;  // Add the prime number to the sum
        }
    }

    // Return the sum of prime numbers up to num
    return sum;
}
