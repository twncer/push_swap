/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:10:31 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/22 05:45:07 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"
#include <unistd.h>

void	pb(struct s_push_swap *ps)
{
	int	counter;

	counter = ps->size_b;
	while (counter)
	{
		ps->stack_b[counter] = ps->stack_b[counter - 1];
		counter--;
	}
	ps->stack_b[0] = ps->stack_a[0];
	counter = 0;
	while (counter < ps->size_a)
	{
		ps->stack_a[counter] = ps->stack_a[counter + 1];
		counter++;
	}
	ps->size_a -= 1;
	ps->size_b += 1;
	write(1, "pb\n", 3);
}

void	pa(struct s_push_swap *ps)
{
	int	counter;

	counter = ps->size_a;
	while (counter)
	{
		ps->stack_a[counter] = ps->stack_a[counter - 1];
		counter--;
	}
	ps->stack_a[0] = ps->stack_b[0];
	counter = 0;
	while (counter < ps->size_b)
	{
		ps->stack_b[counter] = ps->stack_b[counter + 1];
		counter++;
	}
	ps->size_b -= 1;
	ps->size_a += 1;
	write(1, "pa\n", 3);
}

void	ra(struct s_push_swap *ps)
{
	int	swap;
	int	counter;

	swap = ps->stack_a[0];
	counter = 0;
	while (counter < ps->size_a)
	{
		ps->stack_a[counter] = ps->stack_a[counter + 1];
		counter++;
	}
	ps->stack_a[ps->size_a - 1] = swap;
	write(1, "ra\n", 3);
}

void	rb(struct s_push_swap *ps)
{
	int	swap;
	int	counter;

	swap = ps->stack_b[0];
	counter = 0;
	while (counter < ps->size_b)
	{
		ps->stack_b[counter] = ps->stack_b[counter + 1];
		counter++;
	}
	ps->stack_b[ps->size_b - 1] = swap;
	write(1, "rb\n", 3);
}
