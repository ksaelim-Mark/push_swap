/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:52:32 by ksaelim           #+#    #+#             */
/*   Updated: 2022/09/24 22:17:18 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	pick(int size, t_data *pick)
{
	int	temp;

	temp = size;
	while (temp > 0)
	{
		pick[temp] = pick[temp - 1];
		temp--;
	}
}

static void	push(int size, t_data *push)
{
	int	temp;

	temp = 0;
	while (temp < size)
	{
		push[temp] = push[temp + 1];
		temp++;
	}
}

void	pa(t_stk *stk)
{
	if (!stk->b[0].index)
		return ;
	pick(stk->size_a, stk->a);
	stk->a[0] = stk->b[0];
	stk->size_a++;
	stk->size_b--;
	push(stk->size_b, stk->b);
	write(1, "pa\n", 3);
}

void	pb(t_stk *stk)
{
	if (!stk->a[0].index)
		return ;
	pick(stk->size_b, stk->b);
	stk->b[0] = stk->a[0];
	stk->size_b++;
	stk->size_a--;
	push(stk->size_a, stk->a);
	write(1, "pb\n", 3);
}
