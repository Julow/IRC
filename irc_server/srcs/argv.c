/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 14:43:43 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/12 15:02:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "msg.h"

t_bool			parse_argv(t_server *serv, int argc, char **argv)
{
	if (argc < 2)
		return (ft_fdprintf(2, E_NOARG), false);
	serv->port = argv[1];
	return (true);
}
