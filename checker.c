/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:12:32 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/03/11 15:04:58 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

static int  *get_stack(int ac, char **av)
{
    int     *stack;
    int     i;

    stack = (int*)malloc(sizeof(int) * ac);
    i = 0;
    while (i < ac)
    {
        stack[i] = ft_atoi(av[i + 1]);
        i++;
    }
    return (stack);
}

static void swap_first(t_stack *stacks, char *command)
{
    if (stacks->size_a > 1 && (ft_strequ("sa", command) || ft_strequ("ss", command)))
        swap_int(&stacks->a[0], &stacks->a[1]);
    if (stacks->size_b > 1 && (ft_strequ("sb", command) || ft_strequ("ss", command)))
        swap_int(&stacks->b[0], &stacks->b[1]);
}

static void push_top(t_stack *stacks, char *command)
{
    if (stacks->size_b > 0 && ft_strequ("pa", command))
        push_to_top(&stacks->b, &stacks->a, &stacks->size_b, &stacks->size_a);
    else if (stacks->size_a > 0 && ft_strequ("pb", command))
        push_to_top(&stacks->a, &stacks->b, &stacks->size_a, &stacks->size_b);
}

static void shift_up_stack(t_stack *stacks, char *command)
{
    if (stacks->size_a > 1 && (ft_strequ("ra", command) || ft_strequ("rr", command)))
        shift_up(&stacks->a, stacks->size_a);
    if (stacks->size_b > 1 && (ft_strequ("rb", command) || ft_strequ("rr", command)))
        shift_up(&stacks->b, stacks->size_b);
}

static void shift_down_stack(t_stack *stacks, char *command)
{
    if (stacks->size_a > 1 && (ft_strequ("rra", command) || ft_strequ("rrr", command)))
        shift_down(&stacks->a, stacks->size_a);
    if (stacks->size_b > 1 && (ft_strequ("rrb", command) || ft_strequ("rrr", command)))
        shift_down(&stacks->b, stacks->size_b);
}

static void exec_command(t_stack *stacks, char *command)
{
    if (ft_strequ("sa", command) || ft_strequ("sb", command) ||
            ft_strequ("ss", command))
        swap_first(stacks, command);
    else if (ft_strequ("pa", command) || ft_strequ("pb", command))
        push_top(stacks, command);
    else if (ft_strequ("ra", command) || ft_strequ("rb", command) ||
            ft_strequ("rr", command))
        shift_up_stack(stacks, command);
    else if (ft_strequ("rra", command) || ft_strequ("rrb", command) ||
            ft_strequ("rrr", command))
        shift_down_stack(stacks, command);
    else
    {
        ft_putstr_fd("Error\n", 2);
        exit(0);
    }
}

static void print_stack(t_stack stacks)
{
    int     i;

    printf("STACK A\n");
    i = 0;
    while (i < stacks.size_a)
    {
        printf("%d\n", stacks.a[i]);
        i++;
    }
    printf("---\nSTACK B\n");
    i = 0;
    while (i < stacks.size_b)
    {
        printf("%d\n", stacks.b[i]);
        i++;
    }
    printf("---\n");
}

static int  check(t_stack stacks)
{
    int     i;
    int     max;

    if (stacks.size_b == 0)
    {
        max = stacks.a[0];
        i = 1;
        while (i < stacks.size_a)
        {
            if (max < stacks.a[i])
                max = stacks.a[i];
            else
                return (0);
            i++;
        }
        return (1);
    }
    return (0);
}

int         main(int ac, char **av)
{
    t_stack stacks;
    char    *command;

    stacks.b = (int*)malloc(sizeof(int) * ac - 1);
    stacks.a = get_stack(ac - 1, av);
    stacks.size_a = ac - 1;
    stacks.size_b = 0;
    while (get_next_line(0, &command) > 0)
    {
//      printf("%s\n", command);
        exec_command(&stacks, command);
        ft_strdel(&command);
    }
    print_stack(stacks);
    if (check(stacks))
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");
    ft_intdel(&stacks.a);
    ft_intdel(&stacks.b);
//  system("leaks a.out");
    return (0);
}
