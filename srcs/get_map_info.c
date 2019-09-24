/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:51:35 by ghtouman          #+#    #+#             */
/*   Updated: 2019/02/12 12:51:37 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			get_map_info(t_struct *s, char *line)
{
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "Plateau ", 8) == 0)
		{
			s->h_map = ft_atoi(line + 8);
			s->w_map = ft_atoi(line + 8 + ft_intlen(s->h_map));
			ft_strdel(&line);
			get_next_line(0, &line);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	return (0);
}
