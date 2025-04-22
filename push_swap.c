/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:01:07 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/22 04:59:04 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./arrays/ps_arrays.h"
#include "./libps/libps.h"
#include "./push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	ps_exit(int code, struct s_push_swap *ps)
{
	if (ps->stack_a)
		free(ps->stack_a);
	if (ps->stack_b)
		free(ps->stack_b);
	write(1, "Error!\n", 7);
	exit(code);
}

void	ps_hub(int argc, struct s_push_swap *ps)
{
	if (argc == 2)
		sol_2(ps);
	if (argc == 4)
		sol_3_elem(ps);
	else if (argc == 5 || argc == 6)
		sol_4_elem(ps);
	else
		solve(ps);
	ps_exit(0, ps);
}

int	main(int argc, char **argv)
{
	struct s_push_swap	ps;
	int					counter;

	ps.stack_a = NULL;
	ps.stack_b = NULL;
	counter = 1;
	if (argc == 1)
		exit(1);
	while (argv[counter])
	{
		if (count_args(argv[counter], 0) == 1)
			ps_exit(1, &ps);
		counter++;
	}
	set_stack(argv, count_args(NULL, 1), &ps);
	if (is_array_duplicated(&ps))
		ps_exit(1, &ps);
	basicify_array(&ps);
	if (is_array_sorted(ps.stack_a, ps.size_a))
		exit(1);
	ps_hub(argc, &ps);
}
