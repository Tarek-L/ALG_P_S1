#include <stdbool.h>
#include <stdio.h>
#include "numop.h"

int main() {
    // Test SumOfDigits
    printf("Sum of digits of 1234: %d\n", sumOfDigits(1234));

    // Test reverseNumber
    printf("Reversed number of 1234: %d\n", reverseNumber(1234));

    // Test isPalindrome
    printf("1234 is palindrome: %s\n", isPalindrome(1234) ? "True" : "False");

    // Test isPrime
    printf("1234 is prime: %s\n", isPrime(1234) ? "True" : "False");

    // Test swap
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    // Test gcd
    printf("GCD of 15 and 20: %d\n", gcd(15, 20));

    // Test lcm
    printf("LCM of 15 and 20: %d\n", lcm(15, 20));

    // Test fact
    printf("Factorial of 5: %ld\n", fact(5));

    // Test isEven
    printf("1234 is even: %s\n", isEven(1234) ? "True" : "False");

    // Test primeFact
    int factors[100]; // assuming maximum 100 factors
    primeFact(28, factors);
    printf("Prime factors of 28: ");
    for (int i = 0; factors[i] != 0; i++) {
        printf("%d ", factors[i]);
    }
    printf("\n");

    // Test power
    printf("2^3 = %f\n", power(2, 3));

    // Test fib
    int fibi[100]; // assuming maximum 100
    fib(28, fibi);
    printf("Fibonacci sequence of 28: ");
    for (int i = 0; i < 28; i++) {
        printf("%d ", fibi[i]);
    }
    printf("\n");

    // Test sumDivisors
    printf("Sum of divisors of 0: %d\n", sumDivisors(0));
    printf("Sum of divisors of 1: %d\n", sumDivisors(1));
    printf("Sum of divisors of 15: %d\n", sumDivisors(15));

    // Test isPerfect
    printf("6 is perfect: %s\n", isPerfect(6) ? "True" : "False");
    printf("1234 is perfect: %s\n", isPerfect(1234) ? "True" : "False");

    // Test isMagic
    printf("1234 is magic: %s\n", isMagic(1234) ? "True" : "False");
    printf("2234 is magic: %s\n", isMagic(2234) ? "True" : "False");

    // Test isAutomorphic
    printf("9 is automorphic: %s\n", isAutomorphic(9) ? "True" : "False");
    printf("5 is automorphic: %s\n", isAutomorphic(5) ? "True" : "False");

    // Test toBinary
    int d = 12, e = 0, c = 5;
    toBinary(&d);
    toBinary(&e);
    toBinary(&c);
    printf("%d\n%d\n%d\n", d, e, c);

    // Test isNarcissistic
    printf("1234 is narcissistic: %s\n", isNarcissistic(1234) ? "True" : "False");
    printf("7 is narcissistic: %s\n", isNarcissistic(7) ? "True" : "False");

    // Test sqrtApprox
    int k = 12, h = 0, g = 25;
    double A = sqrtApprox(k);
    double B = sqrtApprox(h);
    double C = sqrtApprox(g);
    printf("%f\n%f\n%f\n", A, B, C);

    // Test isAbundant
    printf("20 is abundant: %s\n", isAbundant(20) ? "True" : "False");
    printf("17 is abundant: %s\n", isAbundant(17) ? "True" : "False");

    // Test isDeficient
    printf("17 is deficient: %s\n", isDeficient(17) ? "True" : "False");

    // Test sumEvenFibonacci
    printf("Sum of even Fibonacci numbers up to 6: %d\n", sumEvenFibonacci(6));
    printf("Sum of even Fibonacci numbers up to 1: %d\n", sumEvenFibonacci(1));

    // Test isHarshad
    printf("21 is Harshad: %s\n", isHarshad(21) ? "True" : "False");
    printf("22 is Harshad: %s\n", isHarshad(22) ? "True" : "False");

    // Test isHappy
    printf("0 is happy: %s\n", isHappy(0) ? "True" : "False");
    printf("9 is happy: %s\n", isHappy(9) ? "True" : "False");
    printf("7 is happy: %s\n", isHappy(7) ? "True" : "False");

    // Test catalanNumber
    printf("10th Catalan number: %d\n", catalanNumber(10));
    printf("1st Catalan number: %d\n", catalanNumber(1));

    // Test pascalTriangle
    int pascal[100][100]; // assuming maximum 100
    pascalTriangle(7, pascal);
    printf("Pascal triangle of 7: \n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", pascal[i][j]);
        }
        printf("\n");
    }

    // Test bellNumber
    printf("10th Bell number: %d\n", bellNumber(10));
    printf("1st Bell number: %d\n", bellNumber(1));

    // Test isKaprekar
    printf("45 is Kaprekar: %s\n", isKaprekar(45) ? "True" : "False");
    printf("300 is Kaprekar: %s\n", isKaprekar(300) ? "True" : "False");

    // Test isSmith
    printf("666 is Smith: %s\n", isSmith(666) ? "True" : "False");
    printf("17 is Smith: %s\n", isSmith(17) ? "True" : "False");

    // Test SumOfPrimes
    printf("Sum of primes up to 1234: %d\n", sumOfPrimes(1234));

    return 0;
}
