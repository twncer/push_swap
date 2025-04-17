/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 00:38:03 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/17 18:29:31 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

struct s_push_swap
{
    int *stack_a;
    int *stack_b;
    int size_a;
    int size_b;
};

int count_args(char *arg, bool get);
int	set_stack(char **argv, int stack_len, struct s_push_swap *ps);