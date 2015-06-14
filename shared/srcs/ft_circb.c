/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 17:51:04 by juloo             #+#    #+#             */
/*   Updated: 2015/06/15 00:19:32 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_circb.h"
#include <unistd.h>

t_bool			ft_circb(t_circb *circb, t_sub *line)
{
	int				len;
	int				i;

	i = circb->length;
	if ((i + CIRCB_MIN) >= circb->buff_size || circb->flags & CIRCB_LINE)
	{
		circb->flags = (circb->flags & CIRCB_LINE) ? 0 : CIRCB_CORRUPT;
		i = 0;
	}
	if ((len = read(circb->fd, circb->buff, circb->buff_size - i)) <= 0)
		return (*line = SUB("", 0), false);
	len += i--;
	while (++i < len)
		if (circb->buff[i] == '\n')
		{
			if (i > 0 && circb->buff[i - 1] == '\r')
				i--;
			circb->buff[i] = '\0';
			circb->flags |= CIRCB_LINE;
			break ;
		}
	*line = (circb->flags == CIRCB_LINE) ? SUB(circb->buff, i) : SUB("", 0);
	circb->length = i;
	return (true);
}
