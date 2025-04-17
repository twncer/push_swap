/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 02:03:56 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/17 20:37:26 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libps/libps.h"
#include "./push_swap.h"
#include <stdbool.h>
#include <stdio.h> //dl
#include <stdlib.h>

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

int	count_args(char *arg, bool get)
{
	static int	total = 0;
	char		**arg_parsed;
	int			temp;
	int			counter;

	if (get)
        return (total);
	arg_parsed = ps_split(arg, ' ');
	if (!arg_parsed)
		return (1);
	counter = 0;
	while (arg_parsed[counter])
		counter++;
	total += counter;
    free_map(arg_parsed);
	return (0);
}

bool alloc_stacks(int stack_len, struct s_push_swap *ps)
{
    ps->stack_a = malloc(sizeof(int) * stack_len);
    if (!ps->stack_a)
        return (false);
    ps->stack_b = malloc(sizeof(int) * stack_len);
    if (!ps->stack_b)
    {
        free(ps->stack_a);
        return (false);
    }
    ps->size_a = stack_len;
    ps->size_b = 0;
    return (true);
}

bool set_number(char *arg, int *to_set);

int	set_stack(char **argv, int stack_len, struct s_push_swap *ps)
{
    int counter;
    int counter2;
    int counter3;
    char **arg_parsed;
    
    if (!alloc_stacks(stack_len, ps));
        ps_exit("Allocation fault.\n", 1, ps);
    counter = 1;
    counter3 = 0;
    while (argv[counter])
    {
        arg_parsed = ps_split(argv[counter], ' ');
        counter2 = 0;
        while (arg_parsed[counter2])
        {
            ps->stack_a[counter3] = atoi(arg_parsed[counter2]);
            counter2++;
            counter3++;
        }
        free_map(arg_parsed);
        counter++;
    }
}
