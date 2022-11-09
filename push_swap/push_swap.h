/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:15:56 by ksaelim           #+#    #+#             */
/*   Updated: 2022/09/24 23:59:02 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int		temp;
	int		index;
}	t_data;

typedef struct s_stack
{
	t_data	*a;
	t_data	*b;
	int		size_a;
	int		size_b;
	int		min;
	int		max;
	int		avg;
	int		range;
	int		i;
	int		j;
	char	**input;
}	t_stk;

int		ft_atoi(char *str, t_stk *stk);
void	ft_error(void);
void	free_split(char **str);
void	get_stack(t_stk *stk, char **av);
void	check_input(t_stk *stk, char **av);
void	get_input(t_stk *stk, char **av);
char	**ft_split(char *s);
void	check_sort(t_stk *stk);

void	ft_sort3(t_stk *stk);
void	ft_sort5(t_stk *stk);
void	insert_sort(t_stk *stk);
void	index_sort(t_stk *stk);

void	sa(t_stk *stk);
void	sb(t_stk *stk);
void	ss(t_stk *stk);
void	pa(t_stk *stk);
void	pb(t_stk *stk);
void	ra(t_stk *stk);
void	rb(t_stk *stk);
void	rr(t_stk *stk);
void	rra(t_stk *stk);
void	rrb(t_stk *stk);
void	rrr(t_stk *stk);

#endif
