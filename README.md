🧠 push_swap
push_swap is a school algorithmic project focused on sorting data using a limited set of stack operations. The goal is to sort a stack of integers (Stack A) with the smallest possible number of instructions, using only a predefined list of stack operations and a second auxiliary stack (Stack B).

📋 Project Overview
Input: A list of unsorted integers passed as arguments.

Output: A list of operations that will sort the integers in ascending order using two stacks and the allowed operations.

Constraints: You can only use the following operations to manipulate the stacks:

sa, sb, ss — swap the top two elements.

pa, pb — push the top element from one stack to the other.

ra, rb, rr — rotate the stack up.

rra, rrb, rrr — rotate the stack down.

🎯 Goals
Implement the push_swap program that generates an optimized sequence of instructions to sort Stack A.

Ensure the number of operations is as low as possible (efficiency matters!).

Handle input errors, duplicates, and edge cases properly.
🚀 How to Run
./push_swap 3 2 1 6 5 8
This will output a series of instructions to sort the numbers.

🛠 Bonus
A checker program to verify the correctness of the instruction sequence.
