/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:51:44 by ghtouman          #+#    #+#             */
/*   Updated: 2019/02/12 12:51:46 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	origine_piece(t_struct *s)
{
	int		x;
	int		y;

	y = 0;
	s->min_xp = s->w_piece;
	s->max_xp = 0;
	s->min_yp = s->h_piece;
	s->max_yp = 0;
	while (y < s->h_piece)
	{
		x = 0;
		while (x < s->w_piece)
		{
			if (s->piece[y][x] == '*')
			{
				(x < s->min_xp) ? s->min_xp = x : x;
				(y < s->min_yp) ? s->min_yp = y : y;
				(x > s->max_xp) ? s->max_xp = x : x;
				(y > s->max_yp) ? s->max_yp = y : y;
			}
			x++;
		}
		y++;
	}
}

void		get_piece(t_struct *s, char *line)
{
	int		i;

	i = 0;
	get_next_line(0, &line);
	s->h_piece = ft_atoi(line + 6);
	s->w_piece = ft_atoi(line + 6 + ft_intlen(s->h_piece));
	ft_strdel(&line);
	if (!(s->piece = (char**)malloc(sizeof(char*) * (s->h_piece + 1))))
		return ;
	while (get_next_line(0, &line))
	{
		s->piece[i] = ft_strsub(line, 0, s->w_piece);
		i++;
		ft_strdel(&line);
		if (i >= s->h_piece)
			break ;
	}
	s->piece[i] = NULL;
	origine_piece(s);
}
