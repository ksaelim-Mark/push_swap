/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:04:29 by ksaelim           #+#    #+#             */
/*   Updated: 2022/09/24 22:17:49 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_data *stk, int len)
{
	t_data	temp;
	int		i;

	i = -1;
	temp = stk[0];
	while (++i < len)
		stk[i] = stk[i + 1];
	stk[len - 1] = temp;
}

void	ra(t_stk *stk)
{
	rotate(stk->a, stk->size_a);
	write(1, "ra\n", 3);
}

void	rb(t_stk *stk)
{
	rotate(stk->b, stk->size_b);
	write(1, "rb\n", 3);
}

void	rr(t_stk *stk)
{
	rotate(stk->a, stk->size_a);
	rotate(stk->b, stk->size_b);
	write(1, "rr\n", 3);
}
