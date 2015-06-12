/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 14:19:01 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/12 15:07:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "ft_irc.h"

# include "ft_circb.h"

typedef struct	s_server
{
	char const		*port;
	int				socket;
	t_array			users;
	t_hmap			channels;
}				t_server;

typedef struct	s_client
{
	char			*nick;
	char			*realname;
	char			*passwd;
	t_circb			r_buff;
	t_buff			w_buff;
	t_array			channels;
}				t_client;

typedef struct	s_channel
{
	char			*name;
	t_array			users;
}				t_channel;

/*
** argv
*/
t_bool			parse_argv(t_server *serv, int argc, char **argv);

/*
** utils
*/
int				channel_hash(char const *key, int length);

#endif
