/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 17:51:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/10 19:07:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"
#include <sys/select.h>
#include <unistd.h>

/*
** LOL JUST A TEST
*/

static void		read_write(r, w)
{
	char			buff[512];
	int				len;

	if ((len = read(r, buff, 512)) > 0)
		write(w, buff, len);
}

int				main(int argc, char **argv)
{
	int				socket;
	fd_set			fdsr;

	if (argc <= 2)
		return (1);
	if ((socket = ft_connect(argv[1], argv[2])) < 0)
		return (1);
	while (1)
	{
		FD_ZERO(&fdsr);
		FD_SET(0, &fdsr);
		FD_SET(socket, &fdsr);
		if (select(socket + 1, &fdsr, NULL, NULL, NULL) < 0)
			continue ;
		if (FD_ISSET(0, &fdsr))
			read_write(0, socket);
		if (FD_ISSET(socket, &fdsr))
			read_write(socket, 1);
	}
	return (0);
	(void)argc;
	(void)argv;
}
