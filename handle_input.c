/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 02:03:56 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/22 05:38:09 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libps/libps.h"
#include "./push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

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

bool	alloc_stacks(int stack_len, struct s_push_swap *ps)
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

bool	set_act(char *arg, long *res, int *sign_counter, int *sign)
{
	while (*arg)
	{
		if (!in("-+0123456789", *arg))
			return (false);
		if (in("-+", *arg))
			(*sign_counter)++;
		if (*arg == '-')
			*sign = 1;
		if ((*sign_counter) > 1 || (*(arg + 1) && in("0123456789", *arg)
				&& in("-+", *(arg + 1))) || (*(arg + 1) && in("-+", *arg)
				&& !in("0123456789", *(arg + 1))))
			return (false);
		if (in("0123456789", *arg))
		{
			(*res) *= 10;
			(*res) += *arg - 48;
		}
		arg++;
	}
	return (true);
}

bool	set_number(char *arg, int *to_set)
{
	long	res;
	int		sign_counter;
	int		sign;

	res = 0;
	sign_counter = 0;
	sign = 0;
	if (set_act(arg, &res, &sign_counter, &sign) == false)
		return (false);
	if (sign == 1)
		res = res * -1;
	if (sign_counter == 1 && res == 0)
		return (false);
	if (res > INT_MAX || res < INT_MIN)
		return (false);
	*to_set = (int)res;
	return (true);
}

int	set_stack(char **argv, int stack_len, struct s_push_swap *ps)
{
	int		counter;
	int		counter2;
	int		counter3;
	char	**arg_parsed;

	if (!alloc_stacks(stack_len, ps))
		ps_exit(1, ps);
	counter = 1;
	counter3 = 0;
	while (argv[counter])
	{
		arg_parsed = ps_split(argv[counter], ' ');
		counter2 = 0;
		while (arg_parsed[counter2])
		{
			if (!set_number(arg_parsed[counter2], &ps->stack_a[counter3]))
				ps_exit(1, ps);
			counter2++;
			counter3++;
		}
		free_map(arg_parsed);
		counter++;
	}
}
