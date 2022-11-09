/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:11:21 by ksaelim           #+#    #+#             */
/*   Updated: 2022/09/25 00:51:47 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stk	stk;

	if (ac == 1)
		exit(0);
	get_stack(&stk, &av[1]);
	check_sort(&stk);
	index_sort(&stk);
	if (stk.size_a <= 3)
	{
		if (stk.size_a != 1)
			ft_sort3(&stk);
	}
	else
		insert_sort(&stk);
	free(stk.a);
	free(stk.b);
	return (0);
}
