/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:51:19 by ghtouman          #+#    #+#             */
/*   Updated: 2019/02/12 12:51:21 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_pos(t_struct *s)
{
	s->y_pos = 0;
	s->weight = 0;
	while (s->y_pos < s->h_map)
	{
		s->x_pos = 0;
		while (s->x_pos < s->w_map)
		{
			if (s->map[s->y_pos][s->x_pos] == -2)
				place_piece(s);
			(s->x_pos)++;
		}
		(s->y_pos)++;
	}
	return (s->weight);
}
