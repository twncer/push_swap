/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:56:31 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/22 04:57:05 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H
# include <stdbool.h>
# include <sys/types.h>

char	**ps_split(char const *s, char c);
ssize_t	len(char *str);
bool	in(char *str, char c);
bool	in_int(int *arr, int i, int len);
void	free_map(char **map);

#endif