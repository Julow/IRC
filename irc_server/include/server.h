/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 14:19:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/15 00:03:31 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "ft_irc.h"

# include "ft_circb.h"
# include "ft_dlist.h"

typedef struct	s_server
{
	char const		*port;
	int				socket;
	t_dlist			users;
	t_hmap			channels;
}				t_server;

typedef struct	s_user
{
	t_dhead			list;
	char			*nick;
	char			*realname;
	char			*passwd;
	int				socket;
	t_circb			r_buff;
	t_out			w_buff;
	t_array			channels;
}				t_user;

typedef struct	s_channel
{
	char			*name;
	t_array			users;
}				t_channel;

# define R_BUFF_SIZE	256
# define W_BUFF_SIZE	128

t_bool			parse_argv(t_server *serv, int argc, char **argv);

void			server_start(t_server *serv);

int				channel_hash(char const *key, int length);

#endif
