/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_filler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:56:23 by ghtouman          #+#    #+#             */
/*   Updated: 2019/02/12 12:59:36 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	place_weight(t_struct *s, int n, int y, int x)
{
	int		i;
	int		tmp;
	int		ret;

	i = -1;
	tmp = --y;
	x--;
	ret = 0;
	while (++i <= 8)
	{
		if (x >= 0 && y >= 0 && x < s->w_map && y < s->h_map)
			if (s->map[y][x] == 0)
			{
				s->map[y][x] = n;
				ret = 1;
			}
		if (i == 2 || i == 5)
		{
			x++;
			y = tmp;
		}
		else
			y++;
	}
	return (ret);
}

static void	call_place_weight(t_struct *s, int y, int x, int n)
{
	while (x < s->w_map)
	{
		if (s->map[y][x] == 0)
			s->check = 1;
		if (s->map[y][x] == -1)
			if (place_weight(s, n, y, x))
				s->never = 1;
		if (s->map[y][x] == n - 1 && n > 1)
			if (place_weight(s, n, y, x))
				s->never = 1;
		if (s->map[y][x] == -2 && s->never == 2 && s->check)
			place_weight(s, n, y, x);
		if (y == s->h_map - 1 && x == s->w_map - 1 && s->never == 2 && s->check)
			s->map[y][x] = n;
		x++;
	}
}

void		weight_filler(t_struct *s)
{
	int		n;
	int		y;

	s->never = 1;
	n = 1;
	while (1)
	{
		if (s->never == 0)
			s->never = 2;
		else
			s->never = 0;
		y = -1;
		s->check = 0;
		while (++y < s->h_map)
			call_place_weight(s, y, 0, n);
		if (!s->check)
			break ;
		n++;
	}
}
