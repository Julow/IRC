/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 14:18:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/12 15:02:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "msg.h"

static void		init_server(t_server *serv)
{
	ft_bzero(serv, sizeof(t_server));
	ft_arrayini(&(serv->users));
	ft_hmapini(&(serv->channels), 64, &channel_hash);
}

int				main(int argc, char **argv)
{
	t_server		serv;

	init_server(&serv);
	if (!parse_argv(&serv, argc, argv))
		return (1);
	if ((serv.socket = ft_bind(serv.port)) < 0)
		return (ft_fdprintf(2, E_BIND, serv.port), 1);
	ft_printf(I_LISTEN, serv.port);
	return (0);
}
