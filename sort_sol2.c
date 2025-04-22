/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sol2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 03:25:53 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/22 05:46:41 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrays/ps_arrays.h"
#include "push_swap.h"

void	sol_3_elem(struct s_push_swap *ps)
{
	if (ps->stack_a[2] != 2)
	{
		if (ps->stack_a[0] == 2)
			ra(ps);
		else
			rra(ps);
	}
	if (ps->stack_a[0] > ps->stack_a[1])
		sa(ps);
}

void	sol_4_elem(struct s_push_swap *ps)
{
	while (ps->size_b <= 1)
	{
		if (ps->stack_a[0] == 0 || ps->stack_a[0] == 1)
			pb(ps);
		else
			ra(ps);
	}
	if (ps->stack_b[0] == 0)
		sb(ps);
	if (!(ps->stack_a[2] == 4))
	{
		if (ps->stack_a[0] == 4)
			ra(ps);
		else
			rra(ps);
	}
	if (ps->stack_a[0] > ps->stack_a[1])
		sa(ps);
	pa(ps);
	pa(ps);
}

void	sol_2(struct s_push_swap *ps)
{
	if (ps->size_a == 2)
	{
		if (ps->stack_a[0] > ps->stack_a[1])
		{
			sa(ps);
			ps_exit(1, ps);
		}
	}
}
