/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:57:47 by ksaelim           #+#    #+#             */
/*   Updated: 2022/09/24 22:18:22 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_data *a, t_data *b)
{
	t_data	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	sa(t_stk *stk)
{
	if (stk->size_a < 2)
		return ;
	swap(&stk->a[0], &stk->a[1]);
	write(1, "sa\n", 3);
}

void	sb(t_stk *stk)
{
	if (stk->size_b < 2)
		return ;
	swap(&stk->b[0], &stk->b[1]);
	write(1, "sb\n", 3);
}

void	ss(t_stk *stk)
{
	if (stk->size_a >= 2)
		swap(&stk->a[0], &stk->a[1]);
	if (stk->size_b >= 2)
		swap(&stk->b[0], &stk->b[1]);
	write(1, "ss\n", 3);
}
