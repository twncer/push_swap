/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:48:39 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/22 05:12:11 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./arrays/ps_arrays.h"
#include "./push_swap.h"

int	get_max_bit(struct s_push_swap *ps)
{
	int	max_bit;
	int	size;

	max_bit = 0;
	size = ps->size_a;
	while (size > 1)
	{
		size /= 2;
		max_bit++;
	}
	return (max_bit);
}

void	solve(struct s_push_swap *ps)
{
	int	max_bit;
	int	phase;
	int	counter;
	int	size;

	max_bit = get_max_bit(ps) + 1;
	phase = 0;
	while (max_bit)
	{
		counter = 0;
		size = ps->size_a;
		while (counter < size && !is_array_sorted(ps->stack_a, ps->size_a))
		{
			if (ps->stack_a[0] & (1 << phase))
				ra(ps);
			else
				pb(ps);
			counter++;
		}
		counter = 0;
		phase++;
		size = ps->size_b;
		while (counter < size)
		{
			if (ps->stack_b[0] & (1 << phase))
				pa(ps);
			else
				rb(ps);
			counter++;
		}
		max_bit--;
	}
	while (ps->size_b)
		pa(ps);
}
