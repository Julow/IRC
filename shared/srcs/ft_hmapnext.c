/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmapnext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 00:12:30 by juloo             #+#    #+#             */
/*   Updated: 2015/06/12 00:34:36 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap_it.h"

t_bool			ft_hmapnext(t_hmap_it *it)
{
	if (it->h != NULL)
		it->h = it->h->next;
	while (it->h == NULL && it->i < it->map->alloc_size)
		it->h = it->map->data[it->i++];
	if (it->h == NULL)
		return (false);
	return (true);
}
