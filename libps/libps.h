/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:56:31 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/16 00:09:20 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H
# include <sys/types.h>
# include <stdbool.h>

char	**ps_split(char const *s, char c);
ssize_t	len(char *str);
bool	in(char *str, char c);

#endif