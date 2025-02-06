# Push Swap

Push Swap is a project about sorting a stack using another stack with a limited number of operations.


## Introduction

- The Push Swap project is designed to sort a stack of integers using a set of predefined operations.

## Features

- Sorting a stack of integers using a limited set of operations.
- Efficient sorting algorithms for small and large stacks.
- Comprehensive error handling and input validation.
- Modular code structure for easy maintenance and extension.

## Operations  
The following operations manipulate the stacks:  

- **sa**: Swap the first two elements at the top of stack A.  
- **sb**: Swap the first two elements at the top of stack B.  
- **ss**: Perform `sa` and `sb` simultaneously.  
- **pa**: Push the top element from stack B onto stack A.  
- **pb**: Push the top element from stack A onto stack B.  
- **ra**: Rotate stack A upwards (the first element moves to the bottom).  
- **rb**: Rotate stack B upwards (the first element moves to the bottom).  
- **rr**: Perform `ra` and `rb` simultaneously.  
- **rra**: Rotate stack A downwards (the last element moves to the top).  
- **rrb**: Rotate stack B downwards (the last element moves to the top).  
- **rrr**: Perform `rra` and `rrb` simultaneously.  

## Algorthims

- **Hamad Sort** (My own sorting algorhim but i use it for smaller inputs)
- **Radix Sort**: [https://en.wikipedia.org/wiki/Radix_sort](https://en.wikipedia.org/wiki/Radix_sort) (I use it for big inputs)

## Installation

To install and build the project, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/push_swap.git
    cd push_swap
    ```

2. Build the project:
    ```sh
    make
    ```

## Usage

To run the Push Swap program, use the following command:

```sh
./push_swap [numbers...]
```

## Example
Example 1
```sh 
./push_swap 3 1 2
output:
ra

```
Example 2
```sh
./push_swap 5 1 32 -2 49 123 45
output:
    pb
ra
ra
pb
ra
pb
pb
pa
pa
pa
pa
ra
pb
ra
pb
pb
ra
pb
pa
pa
pa
pa
pb
ra
pb
ra
pb
ra
pb
pa
pa
pa
pa
```
