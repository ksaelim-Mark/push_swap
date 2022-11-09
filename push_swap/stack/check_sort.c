/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:44:28 by ksaelim           #+#    #+#             */
/*   Updated: 2022/09/24 23:01:26 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_sort(t_stk *stk)
{
	int	i;

	i = 0;
	while (i < stk->size_a)
	{
		if (stk->a[i].temp > stk->a[i + 1].temp && (i + 1) != stk->size_a)
			return ;
		i++;
	}
	exit(0);
}

static int	find_index(t_stk *stk, t_data index)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (i < stk->size_a)
	{
		if (index.temp > stk->a[i].temp)
			count++;
		i++;
	}
	return (count);
}

void	index_sort(t_stk *stk)
{
	int	i;

	i = 0;
	while (i < stk->size_a)
	{
		stk->a[i].index = find_index(stk, stk->a[i]);
		i++;
	}
}
