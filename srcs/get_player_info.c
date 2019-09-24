/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:51:51 by ghtouman          #+#    #+#             */
/*   Updated: 2019/02/12 13:03:12 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_player_info(t_struct *s, char *line)
{
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line + 23, "ghtouman.filler", 15) == 0)
		{
			if (ft_atoi(line + 10) == 1)
				s->status = 'O';
			else
				s->status = 'X';
			break ;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
