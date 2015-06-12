/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 15:02:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/12 15:07:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int				channel_hash(char const *key, int length)
{
	int				i;
	int				hash;

	i = -1;
	hash = 0;
	while (++i < length)
		hash = ((key[i] * hash) << 8) + hash;
	return (hash);
}
