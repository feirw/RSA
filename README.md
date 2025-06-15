# RSA
Encrypt. Decrypt. Repeat. — RSA Algorithm in Code

# 🔐 RSA Encryption Playground: Learn, Code, Secure (in C)

This repository contains a complete C implementation of the **RSA encryption algorithm**, built for educational and demonstrative purposes. It supports both **encryption** and **decryption** directly from the command line.

## 📌 Overview

The program uses:
- Prime number validation
- Euler's totient function
- Modular exponentiation
- GCD calculation
- Command-line interface for RSA operations

## 🧠 How It Works

The program expects **five arguments** and reads a message (`m`) from standard input:

./rsa enc|dec <public_exp> <private_exp> <prime1> <prime2>


### Parameters:
- `enc` or `dec`: Choose encryption or decryption
- `<public_exp>`: The public exponent (e)
- `<private_exp>`: The private exponent (d)
- `<prime1>` and `<prime2>`: Two prime numbers (p, q)

### How Encryption Works:
1. Compute `N = p × q`
2. Compute `phi(N) = (p-1)(q-1)`
3. Ensure `e` and `phi(N)` are coprime
4. Ensure `e * d mod phi(N) = 1`
5. Encrypt: `cipher = m^e mod N`

### How Decryption Works:
- Decrypt: `message = c^d mod N`

## 🚀 Example Usage

### Compile:

```bash
gcc -o rsa rsa.c
```

## Ideal For:

- Informatics students preparing for exams

- Those learning about cryptography fundamentals

- C programming practice with math-heavy algorithms