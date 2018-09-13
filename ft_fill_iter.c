/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:23:09 by amalkevy          #+#    #+#             */
/*   Updated: 2018/01/11 16:23:12 by amalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_field(char **field, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(field[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

char	**ft_create_field(void)
{
	char	**tab;
	int		i;
	int		j;

	if (!(tab = (char**)malloc(sizeof(char*) * (27))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < 27)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * (27))))
			return (NULL);
		while (j < 26)
			tab[i][j++] = '.';
		tab[i][j] = '\0';
		j = 0;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int		ft_call_all(t_struct *figures, int num)
{
	char	**field;
	int		size;
	int		num_copy;
	int		n;

	n = 0;
	num_copy = num;
	num *= 4;
	size = 0;
	while (size == 0)
	{
		while (n <= num / 2)
		{
			if (n * n == num)
				size = n;
			n++;
		}
		n = 0;
		num++;
	}
	if ((field = ft_create_field()))
		ft_print_field(field, ft_fillit(figures, &field, size, num_copy - 1));
	return (0);
}
