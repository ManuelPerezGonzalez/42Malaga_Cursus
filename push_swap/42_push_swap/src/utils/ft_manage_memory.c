#include "push_swap.h"
#include <unistd.h>

void    ft_free_stacks(st_stacks *stacks)
{
    free(stacks->stack_a);
    free(stacks->stack_b);
    free(stacks);
    exir(0);
}

void    ft_free_struct(st_stacks *stacks)
{
    free(stacks);
    exit(0);
}

void    ft_free_stack_a(st_stacks *stacks)
{
    free(stacks->stack_a);
    free(stacks);
    exit(0);
}

void    ft_error(st_stacks *stacks)
{
    write(1, "Error", 5);
    ft_free_stacks(stacks);
}

st_stacks   *ft_initialize_stacks(char **numbers, int narg)
{
    struct s_stacks *stacks; // Declare a new struct of type s_stacks.
    int i;

    stacks = malloc(sizeof(struct s_stacks));
    if (!stacks)
        exit(0);
    if (narg != 1) // Give the stack the size of the number of arguments received.
        stacks->max_size = narg;
    else // Or count number of words saved in $ARG.
        stacks->max_size = ft_count_words(numbers[0], ' ');
    stacks->size_a = stacks->max_size; // Give every variable in stacks a value.
    stacks->size_b = 0;
    stacks->stack_a = ft_calloc((stacks->max_size + 1), sizeof(int));
    if (!stacks->stack_a)
        ft_free_struct(stacks);
    stacks->stack_b = ft_calloc((stacks->max_size + 1), sizeof(int));
    if (!stacks->stack_b)
        ft_free_a_stack(stacks);
    i = 0;
    while (i < stacks->max_size)
        stacks->stack_a[i++] = -1;
    ft_fill_stack(stacks, numbers, narg);
    return (stacks);
}