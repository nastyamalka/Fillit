/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotlyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:58:40 by dkotlyar          #+#    #+#             */
/*   Updated: 2017/12/08 16:13:49 by dkotlyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUF_SIZE 550

typedef struct		s_struct
{
	char			sym;
	int				x[4];
	int				y[4];
	int				xs;
	int				ys;
	int				x_prov;
	int				y_prov;
}					t_struct;
void				ft_create_struct(char *str);
int					ft_call_all(t_struct *figures, int size);
int					ft_fillit(t_struct *fig, char ***f, int s, int l);
#endif
