/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circb.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 14:20:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/15 00:21:40 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CIRCB_H
# define FT_CIRCB_H

# include "libft.h"

/*
** ========================================================================== **
** Circular buffer
*/

typedef struct	s_circb
{
	char			*buff;
	int				fd;
	int				flags;
	int				length;
	int				buff_size;
}				t_circb;

# define CIRCB_LINE		(1 << 1)
# define CIRCB_CORRUPT	(1 << 2)

# define CIRCB_MIN		9

/*
** CIRCB
** ----
** Args: fd, buffer, buffer_size
** Init a t_circb
*/
# define CIRCB(f,b,l)	((t_circb){(b), (f), 0, 0, (l)})

/*
** ft_circb
** ----
** Read (once) from the fd
** ----
** If the buffer does not contains a complete line
** 'line' argument is set to an empty string
** ----
** Return false if read fail
** true otherwise
*/
t_bool			ft_circb(t_circb *circb, t_sub *line);

#endif
