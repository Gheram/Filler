/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:51:26 by ghtouman          #+#    #+#             */
/*   Updated: 2019/02/12 12:51:31 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		fill_map_line(t_struct *s, char *line, int y)
{
	int			x;

	x = 0;
	if (!(s->map[y] = (int*)malloc(sizeof(int) * s->w_map)))
		return ;
	while (line[x])
	{
		if (line[x] == '.')
			s->map[y][x] = 0;
		else if (line[x] == s->status || line[x] == s->status + 32)
			s->map[y][x] = -2;
		else
			s->map[y][x] = -1;
		x++;
	}
}

void			gen_map(t_struct *s, char *line)
{
	int			y;

	y = 0;
	if (!(s->map = (int **)malloc(sizeof(int*) * s->h_map)))
		return ;
	while (get_next_line(0, &line))
	{
		fill_map_line(s, line + 4, y);
		y++;
		ft_strdel(&line);
		if (y >= s->h_map)
			break ;
	}
	ft_strdel(&line);
}
