/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:01:07 by btuncer           #+#    #+#             */
/*   Updated: 2025/04/17 20:32:34 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libps/libps.h"
#include "./push_swap.h"
#include <stdio.h> //dl
#include <stdlib.h>
#include <unistd.h>

__attribute__((destructor))
void exit_f()
{
	printf("\n\n𝒷𝑒𝓃 𝑔𝒾𝒹𝒾𝓎𝑜𝓂·\n");
}

void	ps_exit(char *text, int code, struct s_push_swap *ps)
{
	if (*ps->stack_a)
		free(ps->stack_a);
	if (*ps->stack_b)
		free(ps->stack_b);
	write(1, text, len(text));
	exit(code);
}

int	main(int argc, char **argv)
{
	struct s_push_swap	ps;
	int					counter;

	ps.stack_a = NULL;
	ps.stack_b = NULL;
	counter = 1;
	if (argc < 2)
		ps_exit("Usage: ./push_swap {NUMBER} ... \"{NUMBER}\"\n", 1, &ps);
	while (argv[counter])
	{
		if (count_args(argv[counter], 0) == 1)
			ps_exit("Error!\n", 1, &ps);
		counter++;
	}
	set_stack(argv, count_args(NULL, 1), &ps);
	int ponter = 0;
	while (ponter < count_args(NULL, 1))
	{
		printf("%d\n", ps.stack_a[ponter]);
		ponter++;
	}
	free(ps.stack_a);
	free(ps.stack_b);
}
