+-------------------- HELP LINKS --------------------+

https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

+-------------------- DESCRIPTIONS --------------------+

- Push_swap is an algorithm project at school 42 and the instructions were given in the subject.

- We start with two stacks called A and B.

- A is filled with some random integers (without duplicates) and B is empty.

- We can perform a limited set of instructions on these stacks and the goal is to sort all these integers using the lowest possible number of actions.

- The limited set of instructions are:
sa		swap A - swap the first 2 elements at the top of stack A
sb		swap B - swap the first 2 elements at the top of stack B
ss		sa and sb at the same time
pa		push A - take the first element at the top of b and put it at the top of A
pb		push B - take the first element at the top of a and put it at the top of B
ra		rotate A - shift up all elements of stack A by 1. The first element becomes the last one
rb		rotate B - shift up all elements of stack B by 1. The first element becomes the last one
rr		ra and rb at the same time
rra		reverse rotate A - shift down all elements of stack A by 1. The last element becomes the first one
rrb		reverse rotate B - shift down all elements of stack B by 1. The last element becomes the first one
rrr		rra and rrb at the same time

If you didn't have enough understanding about structures, in this proyect you will have to learn how to use them (or not).

Some of the scripts used in this project have been modified, regarding the ones created for other of my projects, in order to fulfill this ones requirements (see libft_utils folder).

Every function in this project that needs to be explained (to understand it easier) has a few commented lines above it.