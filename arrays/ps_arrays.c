/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arrays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:32:42 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/22 04:55:53 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"
#include <stdlib.h>

void	copy_arr(int *arr1, int *arr2, int len)
{
	int	counter;

	counter = 0;
	while (counter < len)
	{
		arr2[counter] = arr1[counter];
		counter++;
	}
}

bool	is_array_sorted(int *arr, int len)
{
	int	counter;

	counter = 0;
	while (counter < len)
	{
		if (counter != len - 1 && arr[counter] > arr[counter + 1])
			return (false);
		counter++;
	}
	return (true);
}

void	bubble_arr(int *arr, int len)
{
	int	swap;
	int	counter;

	counter = 0;
	while (!is_array_sorted(arr, len))
	{
		if (counter + 1 < len && arr[counter] > arr[counter + 1])
		{
			swap = arr[counter];
			arr[counter] = arr[counter + 1];
			arr[counter + 1] = swap;
		}
		counter++;
		if (counter == len)
			counter = 0;
	}
}

bool	basicify_array(struct s_push_swap *ps)
{
	int	*clone;
	int	counter;
	int	counter2;

	clone = malloc(sizeof(int) * ps->size_a);
	if (!clone)
		return (false);
	copy_arr(ps->stack_a, clone, ps->size_a);
	bubble_arr(clone, ps->size_a);
	counter = 0;
	while (counter < ps->size_a)
	{
		counter2 = 0;
		while (counter2 < ps->size_a)
		{
			if (clone[counter] == ps->stack_a[counter2])
				ps->stack_a[counter2] = counter;
			counter2++;
		}
		counter++;
	}
}

bool	is_array_duplicated(struct s_push_swap *ps)
{
	int	counter;
	int	counter2;

	counter = 0;
	while (counter < ps->size_a)
	{
		counter2 = 0;
		while (counter2 < ps->size_a)
		{
			if (counter != counter2
				&& ps->stack_a[counter] == ps->stack_a[counter2])
				return (true);
			counter2++;
		}
		counter++;
	}
	return (false);
}
