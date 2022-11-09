/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:40:15 by ksaelim           #+#    #+#             */
/*   Updated: 2022/09/25 00:46:38 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

static void	ft_isnbr(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (input[i][j] == '-' && input[i][j + 1] >= '0' \
					&& input[i][j + 1] <= '9')
				j++;
			if (input[i][j] < '0' || input[i][j] > '9')
				ft_error();
			j++;
		}
		i++;
	}
}

void	change_input(t_stk *stk, char **av)
{
	stk->i = 0;
	stk->size_a = 0;
	while (av[stk->i])
	{
		if (!av[stk->i][0])
			exit(0);
		stk->input = ft_split(av[stk->i]);
		stk->j = 0;
		ft_isnbr(stk->input);
		while (stk->input[stk->j])
		{
			stk->size_a++;
			stk->j++;
		}
		free_split(stk->input);
		stk->i++;
	}
}

void	get_input(t_stk *stk, char **av)
{
	int		k;
	int		temp;

	stk->i = -1;
	stk->size_a = 0;
	while (av[++(stk->i)])
	{
		stk->input = ft_split(av[stk->i]);
		stk->j = -1;
		while (stk->input[++(stk->j)])
		{
			temp = ft_atoi(stk->input[stk->j], stk);
			k = -1;
			while (++k < stk->size_a)
			{
				if (stk->a[k].temp == temp)
				{
					free(stk->a);
					ft_error();
				}
			}
			stk->a[stk->size_a++].temp = temp;
		}
		free_split(stk->input);
	}
}

void	get_stack(t_stk *stk, char **av)
{
	change_input(stk, av);
	stk->a = malloc(sizeof(t_data) * stk->size_a);
	if (!stk->a)
		exit(0);
	get_input(stk, av);
	stk->b = malloc(sizeof(t_data) * stk->size_a);
	if (!stk->b)
		exit(0);
}
