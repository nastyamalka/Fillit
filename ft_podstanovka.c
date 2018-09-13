/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_podstanovka.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:23:24 by amalkevy          #+#    #+#             */
/*   Updated: 2018/01/11 16:23:26 by amalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_set(t_struct *figure, char ***field)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		(*field)[figure->y[i] + figure->y_prov][figure->x[i] +
			figure->x_prov] = figure->sym;
	}
	figure->ys = figure->y_prov;
	figure->xs = figure->x_prov;
	return (1);
}

int		ft_is_fit(t_struct *figure, char **field, int size)
{
	int		fit;
	int		i;

	figure->x_prov = figure->xs;
	figure->y_prov = figure->ys;
	while (figure->y_prov < size)
	{
		while (figure->x_prov < size)
		{
			fit = 0;
			i = -1;
			while (++i < 4)
				if (figure->y[i] + figure->y_prov < size && figure->x[i] +
						figure->x_prov < size && field[figure->y[i] +
						figure->y_prov][figure->x[i] + figure->x_prov] == '.')
					fit++;
			if (fit == 4)
				return (1);
			figure->x_prov++;
		}
		figure->x_prov = 0;
		figure->y_prov++;
	}
	return (0);
}

void	ft_del(char ***field, char sym, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((*field)[i][j] == sym)
				(*field)[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_fillit(t_struct *figures, char ***field, int size, int last)
{
	static int		index = 0;

	while (1)
	{
		if (ft_is_fit(&figures[index], (*field), size))
		{
			if ((ft_set(&figures[index], field)) && index == last)
				return (size);
			index++;
		}
		else if (index > 0)
		{
			ft_del(field, figures[index - 1].sym, size);
			figures[index].ys = 0;
			figures[index].xs = 0;
			figures[index - 1].xs++;
			index--;
		}
		else
		{
			figures[index].ys = 0;
			figures[index].xs = 0;
			size++;
		}
	}
}
