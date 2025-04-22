/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:58:57 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/22 04:56:54 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>

bool	in(char *str, char c)
{
	ssize_t	counter;

	counter = 0;
	while (str[counter])
	{
		if (str[counter] == c)
			return (true);
		counter++;
	}
	return (false);
}

bool	in_int(int *arr, int i, int len)
{
	ssize_t	counter;

	counter = 0;
	while (counter < len)
	{
		if (arr[counter] == i)
			return (true);
		counter++;
	}
	return (false);
}

ssize_t	len(char *str)
{
	ssize_t	counter;

	counter = 0;
	while (*str)
	{
		counter = counter + 1;
		str++;
	}
	return (counter);
}

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}
