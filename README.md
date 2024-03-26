# Next biggest number with the same digits

This repository contains the solution for the CodeWars kata "Next bigger number with the same digits". The challenge is to create a function that takes a positive integer and returns the next bigger number that can be formed by rearranging its digits. If no bigger number can be formed using those digits, return -1.

For more details on the challenge, visit the [kata on CodeWars](https://www.codewars.com/kata/55983863da40caa2c900004e).

## Solution in C

The solution is implemented in C. The approach involves finding the pivot point in the number from right to left where the digit is smaller than the next digit. Then, it rearranges the digits to form the next bigger number using bubble sort and swapping techniques.

## Installation

Clone the repository to your local machine:

```bash
git clone https://github.com/Kazha07/next_biggest_number.git
cd next_biggest_number
```

## Compilation

Compile the source code using the following command:

```bash
gcc -o main biggest_number.c
```

## Running the Code

Execute the compiled program:

```bash
./main
```


## Contributors

[Vipaloo](https://github.com/Vipaloo), [Kazha07](https://github.com/Kazha07)