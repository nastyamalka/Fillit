/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:17:24 by dkotlyar          #+#    #+#             */
/*   Updated: 2017/11/30 20:07:55 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_putstr(char const *s)
{
	if (s)
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
}

int			ft_cout_svyaz(char const *str, int i, int con)
{
	if (str[i] == '#' && i + 1 <= 20 && str[i + 1] == '#')
		con++;
	if (str[i] == '#' && i + 5 <= 20 && str[i + 5] == '#')
		con++;
	if (str[i] == '#' && i - 1 >= 0 && str[i - 1] == '#')
		con++;
	if (str[i] == '#' && i - 5 >= 0 && str[i - 5] == '#')
		con++;
	return (con);
}

int			check_figure(char const *str)
{
	long	i;
	int		full;
	int		empty;
	int		con;

	con = 0;
	full = 0;
	empty = 0;
	i = 0;
	while (i < 20)
	{
		if ((i == 4 || i == 9 || i == 14 || i == 19) && str[i] != '\n')
			return (0);
		con = ft_cout_svyaz(str, i, con);
		if (str[i] == '#')
			full++;
		if (str[i++] == '.')
			empty++;
	}
	return ((con < 6 || empty != 12 || full != 4) ? 0 : 1);
}

int			check_and_read(int fd)
{
	char	str[BUF_SIZE + 1];
	int		ret;
	int		i;
	int		n;

	if (!(ret = read(fd, str, BUF_SIZE)) || ret < 20 || ret > 545)
		return (0);
	str[ret] = '\0';
	if (ret % 21 != 20)
		return (0);
	n = ret / 20 > 20 ? 1 : 0;
	i = 0;
	while (ret / 20 > n)
	{
		if (!check_figure(&str[i]))
			return (0);
		i += 21;
		n++;
	}
	ft_create_struct(str);
	return (1);
}

int			main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit \"source_file\"\n");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	if (!check_and_read(fd))
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	return (0);
}
