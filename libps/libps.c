/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:58:57 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/16 01:00:57 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdbool.h>

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

int ps_atoi(char *str)
{
    int counter;
    int res;
    int sign_counter;
    bool minus;

    counter = 0;
    res = 0;
    sign_counter = 0;
    minus = false;
    while (str[counter])
    {
        if (!(in("-+0123456789", str[counter])))
            return (false);
        if (in("-+", str[counter]))
            sign_counter++;
        if ((str[counter + 1] && in("0123456789", str[counter])
                && in("-+", str[counter + 1])) || sign_counter > 1)
            return (false);
    }
}
