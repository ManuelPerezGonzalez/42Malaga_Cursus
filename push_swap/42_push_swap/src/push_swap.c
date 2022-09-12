#include "push_swap.h"

int main(int argc, char **argv)
{
    st_stacks   *stacks;

    stacks = ft_initialize_stacks(++argv, argc - 1);
    if (ft_is_ordered(stacks) == 0)
        ft_order(stacks);
    ft_free_stacks(stacks);
}