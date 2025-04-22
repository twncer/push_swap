/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:10:31 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/22 05:45:30 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"
#include <unistd.h>

void	rra(struct s_push_swap *ps)
{
	int	swap;
	int	size;

	swap = ps->stack_a[ps->size_a - 1];
	size = ps->size_a;
	while (size--)
	{
		if (size == 0)
			ps->stack_a[size] = swap;
		else
			ps->stack_a[size] = ps->stack_a[size - 1];
	}
	write(1, "rra\n", 4);
}

void	rrb(struct s_push_swap *ps)
{
	int	swap;
	int	size;

	swap = ps->stack_b[ps->size_b - 1];
	size = ps->size_b;
	while (size--)
	{
		if (size == 0)
			ps->stack_b[size] = swap;
		else
			ps->stack_b[size] = ps->stack_b[size - 1];
	}
}

void	sa(struct s_push_swap *ps)
{
	int	swap;

	swap = ps->stack_a[0];
	ps->stack_a[0] = ps->stack_a[1];
	ps->stack_a[1] = swap;
	write(1, "sa\n", 3);
}

void	sb(struct s_push_swap *ps)
{
	int		swap;

	swap = ps->stack_b[0];
	ps->stack_b[0] = ps->stack_b[1];
	ps->stack_b[1] = swap;
	write(1, "sb\n", 3);
}
