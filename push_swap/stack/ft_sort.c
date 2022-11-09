/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:31:21 by ksaelim           #+#    #+#             */
/*   Updated: 2022/09/25 00:47:03 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort3(t_stk *stk)
{
	if (stk->size_a == 2 && (stk->a[0].temp > stk->a[1].temp))
		sa(stk);
	else if (stk->a[1].temp > stk->a[0].temp && stk->a[1].temp > stk->a[2].temp)
	{
		if (stk->a[0].temp > stk->a[2].temp)
			rra(stk);
		else
		{
			rra(stk);
			sa(stk);
		}
	}
	else if (stk->a[1].temp < stk->a[0].temp && stk->a[1].temp < stk->a[2].temp)
	{
		if (stk->a[0].temp > stk->a[2].temp)
			ra(stk);
		else
			sa(stk);
	}
	else if (stk->a[0].temp > stk->a[2].temp)
	{
		sa(stk);
		rra(stk);
	}
}

static void	ft_init(t_stk *stk, int mode)
{
	if (mode == 0)
	{
		if (stk->size_a + stk->size_b <= 5)
			stk->range = 5;
		else if (stk->size_a + stk->size_b <= 100)
			stk->range = 10;
		else
			stk->range = 50;
		stk->min = 1;
		if (stk->size_a / stk->range <= 1 && stk->size_a % stk->range > 0)
			stk->max += stk->size_a;
		else
			stk->max = stk->range;
		stk->avg = (stk->min + stk->max) / 2;
	}
	else
	{
		stk->min += stk->range;
		if (stk->size_a / stk->range <= 1 && stk->size_a % stk->range > 0)
			stk->max += stk->size_a;
		else
			stk->max += stk->range;
		stk->avg += stk->range;
	}
}

void	is_range(t_stk *stk)
{
	if (stk->a[0].index >= stk->min && stk->a[0].index <= stk->max)
	{
		if (stk->max == stk->size_a + stk->size_b)
		{
			if (stk->a[0].index >= stk->max - 2)
			{
				ra(stk);
				return ;
			}
		}
		pb(stk);
		if (stk->b[0].index <= stk->avg && stk->size_b >= 2)
			rb(stk);
	}
	else
		ra(stk);
	if (stk->size_b == stk->max)
		ft_init(stk, 1);
}

void	insert_sort(t_stk *stk)
{
	int	top;
	int	i;

	ft_init(stk, 0);
	while (stk->size_a > 3)
		is_range(stk);
	ft_sort3(stk);
	while (stk->size_b > 0)
	{
		i = 0;
		top = stk->a[0].index - 1;
		while (stk->b[i].index != top)
			i++;
		if (stk->b[0].index == top)
			pa(stk);
		else if (i < stk->size_b / 2)
			rb(stk);
		else
			rrb(stk);
	}
}
