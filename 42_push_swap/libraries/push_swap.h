/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperez- <maperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:37:10 by maperez-          #+#    #+#             */
/*   Updated: 2022/09/13 10:30:31 by maperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

// Struct
typedef struct s_stacks
{
    int *stack_a;
    int *stack_b;
    int max_size;
    int size_a;
    int size_b;
}       st_stacks;

// Libft functions

int     ft_atoi(char *str, st_stacks *stacks);
void    *ft_calloc(int amount, int size);
int     strncmp(const char *s1, const char *s2, int number);
int     ft_count_words(char const *s, char c);
char    **ft_split(char const *s, char c);

// Operations functions

void    ft_push_a(st_stacks *stacks, int write);
void    ft_push_b(st_stacks *stacks, int write);
void    ft_push(int *stack, int stack_lenght, int number);
void    ft_remove_element(int *stack, int stack_len);
void    ft_reverse_rotate_a(st_stacks *stack, int write);
void    ft_reverse_rotate_b(st_stacks *stack, int write);
void    ft_reverse_rotate_both(st_stacks *stacks, int write);
void    ft_rotate_a(st_stacks *stacks, int write);
void    ft_rotate_b(st_stacks *stacks, int write);
void    ft_rotate(int *stack, int stack_lenght, int number);
void    ft_swap_a(st_stacks *stack, int write);
void    ft_swap_b(st_stacks *stack, int write);
void    ft_swap_both(st_stacks *stacks, int write);

// Memory functions

st_stacks   *ft_initialize_stacks(char **numbers, int narg);
void        ft_error(st_stacks *stacks);
void        ft_free_stack_a(st_stacks *stacks);
void        ft_free_struct(st_stacks *stacks);
void        ft_free_stacks(st_stacks *stacks);

// Utils functions

int     ft_is_ordered(st_stacks *stacks);
void    ft_replace_number(int *stack_a, int *aux, int min, int i);
void    ft_transform_array(int *stack_a, int lenght, int *aux);
void    ft_fill_array(st_stacks *stacks, char **numbers);
void    ft_fill_stack(st_stacks *stacks, char **numbers, int n);

// Order functions



// Trash functions

void    ft_print_struct(st_stacks *stacks);

# endif