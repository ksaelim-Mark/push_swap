/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:42:23 by ksaelim           #+#    #+#             */
/*   Updated: 2022/09/24 22:19:03 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(char *str, t_stk *stk)
{
	int					i;
	int					sign;
	long int			n;

	i = 0;
	sign = 1;
	n = 0;
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + (str[i++] - '0');
	if (n * sign > 2147483647 || n * sign < -2147483648)
	{
		free(stk->a);
		ft_error();
	}
	return ((int)n * sign);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

static int	num_count(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == ' ')
			s++;
		if (*s && *s != ' ')
			count++;
		while (*s && *s != ' ')
			s++;
	}
	return (count);
}

static char	*keep_num(char *s)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	word = (char *)malloc(i + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != ' ')
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s)
{
	char	**ss;
	int		i;
	int		j;
	int		len;

	len = num_count(s);
	ss = malloc((len + 1) * sizeof(char *));
	if (!ss)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		while (s[j] && s[j] == ' ')
			j++;
		ss[i] = keep_num(&s[j]);
		while (s[j] && s[j] != ' ')
			j++;
		i++;
	}
	ss[i] = NULL;
	return (ss);
}
