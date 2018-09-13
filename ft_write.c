/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 21:13:41 by amalkevy          #+#    #+#             */
/*   Updated: 2018/01/09 21:13:46 by amalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t			ft_strlen(const char *s)
{
	size_t	l;
	char	*str;

	str = (char*)s;
	l = 0;
	while (str[l])
	{
		l++;
	}
	return (l);
}

t_struct		ft_corx_coordinates(t_struct figures)
{
	int			i;
	int			j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (figures.x[j] > 0 && j < 4)
		{
			j++;
		}
		if (j == 4)
		{
			j = 0;
			while (j < 4)
				figures.x[j++] -= 1;
		}
		i++;
	}
	figures.xs = 0;
	figures.ys = 0;
	return (figures);
}

t_struct		ft_cory_coordinates(t_struct figures)
{
	int			i;
	int			j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (figures.y[j] > 0 && j < 4)
			j++;
		if (j == 4)
		{
			j = 0;
			while (j < 4)
				figures.y[j++] -= 1;
		}
		i++;
	}
	return (figures);
}

t_struct		*ft_write_figures(char *str, t_struct *figures)
{
	int			x;
	int			y;
	int			a;
	int			i;

	i = 0;
	x = 0;
	y = 0;
	a = 0;
	while (i != 19 && ++x)
	{
		if (str[i] == '#')
		{
			figures[0].x[a] = x - 1;
			figures[0].y[a++] = y;
		}
		if (str[i++] == '\n')
		{
			x = 0;
			y++;
		}
	}
	if (str[i + 1])
		ft_write_figures(&str[i + 2], &figures[1]);
	return (figures);
}

void			ft_create_struct(char *str)
{
	t_struct	*figures;
	int			j;
	int			size;

	size = (int)(ft_strlen(str) / 20);
	if (!(figures = (t_struct*)malloc(sizeof(t_struct) * (size + 1))))
		return ;
	figures = ft_write_figures(str, figures);
	figures[size].sym = '0';
	j = -1;
	while (++j < size)
	{
		figures[j] = ft_corx_coordinates(figures[j]);
		figures[j] = ft_cory_coordinates(figures[j]);
		figures[j].sym = (char)('A' + j);
	}
	ft_call_all(figures, size);
}
