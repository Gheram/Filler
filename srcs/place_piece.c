/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:37:59 by ghtouman          #+#    #+#             */
/*   Updated: 2019/02/07 17:01:08 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_fits(t_struct s, int y_p, int x_p)
{
	int		x;
	int		y;

	y = s.min_yp;
	while (y <= s.max_yp)
	{
		x = s.min_xp;
		while (x <= s.max_xp)
		{
			if ((s.j = y_p + (y - s.min_yp)) < 0)
				s.j = s.h_map + s.j;
			if ((s.i = x_p + (x - s.min_xp)) < 0)
				s.i = s.w_map + s.i;
			if ((s.j == s.y_pos && s.i == s.x_pos) || s.piece[y][x] == '.')
				x++;
			else if ((x <= s.max_xp && (s.j >= s.h_map || s.i >= s.w_map ||
			s.map[s.j][s.i] == -1 || s.map[s.j][s.i] == -2)))
				return (0);
			else
				x++;
		}
		y++;
	}
	return (1);
}

static void	save_good_pos(t_struct *s, int tmp, int y_p, int x_p)
{
	if (tmp < s->weight || s->weight == 0)
	{
		s->weight = tmp;
		s->y_sol = y_p;
		s->x_sol = x_p;
	}
}

static void	piece_weight(t_struct *s, int y_p, int x_p, int tmp)
{
	int		x;
	int		y;
	int		x_m;
	int		y_m;

	y = s->min_yp - 1;
	while (++y <= s->max_yp)
	{
		x = s->min_xp - 1;
		while (++x <= s->max_xp)
		{
			while (s->piece[y][x] == '.')
				x++;
			if (x <= s->max_xp)
			{
				if ((y_m = y_p + (y - s->min_yp)) < 0)
					y_m = s->h_map + y_m;
				if ((x_m = x_p + (x - s->min_xp)) < 0)
					x_m = s->w_map + x_m;
				tmp += s->map[y_m][x_m] + 2;
			}
		}
	}
	save_good_pos(s, tmp, y_p, x_p);
}

void		place_piece(t_struct *s)
{
	int		y;
	int		x;

	y = s->min_yp;
	while (y <= s->max_yp)
	{
		x = s->min_xp;
		while (x <= s->max_xp)
		{
			if ((s->j = s->y_pos - (y - s->min_yp)) < 0)
				s->j = s->h_map + s->j;
			if ((s->i = s->x_pos - (x - s->min_xp)) < 0)
				s->i = s->w_map + s->i;
			if (s->piece[y][x] == '*')
				if (is_fits(*s, s->j, s->i))
					piece_weight(s, s->j, s->i, 0);
			x++;
		}
		y++;
	}
}
