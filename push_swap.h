/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:38:03 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/22 05:08:45 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdbool.h>

struct	s_push_swap
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
};

int		count_args(char *arg, bool get);
int		set_stack(char **argv, int stack_len, struct s_push_swap *ps);
void	ps_exit(int code, struct s_push_swap *ps);
void	solve(struct s_push_swap *ps);
void	sol_2(struct s_push_swap *ps);
void	sol_3_elem(struct s_push_swap *ps);
void	sol_4_elem(struct s_push_swap *ps);

#endif