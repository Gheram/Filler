/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:34:29 by ghtouman          #+#    #+#             */
/*   Updated: 2019/02/12 13:00:57 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_struct
{
	int				w_map;
	int				h_map;
	int				**map;
	int				w_piece;
	int				h_piece;
	int				min_xp;
	int				min_yp;
	int				max_xp;
	int				max_yp;
	char			**piece;
	char			status;
	int				y_pos;
	int				x_pos;
	int				x_sol;
	int				y_sol;
	int				weight;
	int				i;
	int				j;
	int				x_p;
	int				y_p;
	int				never;
	int				check;
}					t_struct;

int					get_map_info(t_struct *s, char *line);
int					find_pos(t_struct *s);

void				get_player_info(t_struct *s, char *line);
void				gen_map(t_struct *s, char *line);
void				get_piece(t_struct *s, char *line);
void				weight_filler(t_struct *s);
void				one_for_all(t_struct *s);
void				place_piece(t_struct *s);

#endif
