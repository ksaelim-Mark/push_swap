/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:17:07 by ksaelim           #+#    #+#             */
/*   Updated: 2022/09/24 22:17:11 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	re_rotate(t_data *stk, int size)
{
	t_data	temp;
	int		len;

	len = size;
	temp = stk[len - 1];
	while (--len > 0)
		stk[len] = stk[len - 1];
	stk[len] = temp;
}

void	rra(t_stk *stk)
{
	re_rotate(stk->a, stk->size_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stk *stk)
{
	re_rotate(stk->b, stk->size_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stk *stk)
{
	re_rotate(stk->a, stk->size_a);
	re_rotate(stk->b, stk->size_b);
	write(1, "rrr\n", 4);
}
