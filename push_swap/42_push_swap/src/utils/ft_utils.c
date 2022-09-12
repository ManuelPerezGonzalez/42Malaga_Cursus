#include "push_swap.h"

int ft_is_ordered(st_stacks *stacks)
{
    int i;

    i = 1;
    while (i < stacks->size_a)
    {
        if (stacks->stack_a[i] < stacks->stack_[i - 1])
            return (0);
        i++;
    }
    return (1);
}