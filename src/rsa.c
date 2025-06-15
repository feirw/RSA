#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for function strcmp

//GCD function
long long int gcd(long long int a, long long int b){
    long long int remainder = a % b;
    if (remainder == 0) {
        return b;
    }
    return gcd(b, remainder);
}

//Checking if a number is prime  
int is_prime(long long int n){
    if (n < 2){
        return 0;
    }
    for (long long int i = 2; i * i <= n; i++) {
        if (n % i == 0){
            return 0;
        } 
    }
    return 1;
}

// Euler's totient function (φ)
long long int phi(long long int N){
    long long int result = N;
    // we take that all the numbers are coprime with N
    for (long long int i = 2; i * i <= N; i++) {
        if(N % i == 0){
            while (N % i == 0) {
                N /= i;
            }
            result = result - result / i;
        }
    }
    if(N > 1){ 
        result -= result / N;
    }
    return result;
}

//Function modular_pow
long long int modular_pow(long long int base,long long int exp,long long int N){
    if (N == 1)
        return 0; // Any number mod 1 is 0
    long long int result = 1;
    base = base % N;
    while (exp > 0) {
        if (exp % 2 == 1){  // If the current bit of exp is 1
            result = (result * base) % N;
        }
        exp = exp >> 1; // Shift exp to the right (divide by 2)
        base = (base * base) % N;
    }
    return result;
}

int main(int argc, char *argv[]) {
   
    // Checking if the correct number of arguments is passed
    if (argc != 6) {  
        printf("Usage: %s enc|dec <exp_exp> <priv_exp> <prime1> <prime2>\n", argv[0]);
        return 1;
    }
    
    // Checking if the first argument is 'enc' or 'dec' with function strcmp
    if (strcmp(argv[1], "enc") != 0 && strcmp(argv[1], "dec") != 0) {
        printf("First argument must be 'enc' or 'dec'\n");
        return 1;
    }
    
    // Converting the input arguments to long long int
    long long int e = atoll(argv[2]);  
    long long int d = atoll(argv[3]); 
    long long int p = atoll(argv[4]);   
    long long int q = atoll(argv[5]);   

    // Checking if any of the numbers are non-positive
    if (e <= 0 || d <= 0 || p <= 0 || q <= 0) {
        printf("Negative numbers are not allowed\n");
        return 1;
    }
    // Checking if p and q are prime numbers
    if (!is_prime(p) || !is_prime(q)){
        printf("p and q must be prime\n");
        return 1;
    }
    long long int N = p * q;

    long long int phi_N = phi(N);
    // Checking if e is coprime with phi(N)
    if (gcd(e, phi_N) != 1) {
        printf("e is not coprime with phi(N)\n");
        return 1;
    }
    // Checking if e * d mod phi(N) == 1
    if ((e * d) % phi_N != 1) {
        printf("e * d mod phi(N) is not 1\n");
        return 1;
    }
    long long int m;
    int result;
    result = scanf("%lld", &m);
    if (result != 1) {
        return 1;
    }
    // Checking if the message is non-negative and within the range of N
    if (m <= 0) {
        printf("Negative numbers are not allowed\n");
        return 1;
    }
    if (m >= N) {
        printf("Message is larger than N\n");
        return 1;
    }
    if (strcmp(argv[1], "enc") == 0) {
        printf("%lld\n", modular_pow(m, e, N));
    } else {
        printf("%lld\n", modular_pow(m, d, N));
    }
    return 0;
}