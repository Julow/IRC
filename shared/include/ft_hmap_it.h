/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_it.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 22:50:34 by juloo             #+#    #+#             */
/*   Updated: 2015/06/12 00:34:53 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HMAP_IT_H
# define FT_HMAP_IT_H

# include "ft_internal.h"

typedef struct	s_hmap_it
{
	t_hmap			*map;
	t_h				*h;
	int				i;
}				t_hmap_it;

void			ft_hmapbegin(t_hmap *map, t_hmap_it *it);
t_bool			ft_hmapnext(t_hmap_it *it);

#endif
