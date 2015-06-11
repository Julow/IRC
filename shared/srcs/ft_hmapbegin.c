/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapbegin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 00:12:30 by juloo             #+#    #+#             */
/*   Updated: 2015/06/12 00:34:39 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap_it.h"

void			ft_hmapbegin(t_hmap *map, t_hmap_it *it)
{
	it->map = map;
	it->h = NULL;
	it->i = 0;
}
