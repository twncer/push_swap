/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arrays.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:26:24 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/22 05:45:39 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_ARRAYS_H
# define PS_ARRAYS_H

# include "./../push_swap.h"
# include <stdbool.h>

bool	is_array_sorted(int *arr, int len);
void	basicify_array(struct s_push_swap *ps);
void	pb(struct s_push_swap *ps);
void	pa(struct s_push_swap *ps);
void	ra(struct s_push_swap *ps);
void	rb(struct s_push_swap *ps);
void	rra(struct s_push_swap *ps);
void	rrb(struct s_push_swap *ps);
void	sa(struct s_push_swap *ps);
void	sb(struct s_push_swap *ps);
bool	is_array_duplicated(struct s_push_swap *ps);
void	justify_array(struct s_push_swap *ps);

#endif