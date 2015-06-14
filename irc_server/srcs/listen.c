/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 12:14:41 by juloo             #+#    #+#             */
/*   Updated: 2015/06/15 00:41:34 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

static int		user_fd_set(t_server *serv, fd_set *fds)
{
	t_user			*user;
	int				max;

	max = 0;
	user = DLISTBEGIN(&(serv->users));
	while ((user = DLISTNEXT(user)) != NULL)
	{
		FD_SET(user->socket, fds);
		if (user->socket > max)
			max = user->socket;
	}
	return (max);
}

static void		user_fd_isset(t_server *serv, fd_set *fds)
{
	t_user			*user;
	t_sub			line;

	user = DLISTBEGIN(&(serv->users));
	while (user != NULL && (user = DLISTNEXT(user)) != NULL)
		if (FD_ISSET(user->socket, fds))
		{
			ft_printf("Receiving data\n");
			if (!ft_circb(&(user->r_buff), &line))
			{
				ft_printf("User leave\n");
				ft_dlistremove(&(serv->users), user);
				// free + close user
				user = DLISTPREV(user);
			}
			else if (line.length > 0)
				ft_printf("User say %.*s\n", line.length, line.str);
		}
}

static void		accept_user(t_server *serv)
{
	t_user			user;

	user = (t_user){DHEAD(), "lol", NULL, NULL, -1, {}, {}, {}};
	if ((user.socket = accept(serv->socket, NULL, NULL)) < 0)
		return (ft_fdprintf(2, "lol accept fail\n"), VOID);
	user.r_buff = CIRCB(user.socket, MAL(char, R_BUFF_SIZE), R_BUFF_SIZE);
	user.w_buff = OUT(user.socket, MAL(char, W_BUFF_SIZE), W_BUFF_SIZE);
	ft_arrayini(&(user.channels));
	ft_dlistpush(&(serv->users), NULL, ft_memdup(&user, sizeof(t_user)));
	ft_printf("user connected\n");
}

void			server_start(t_server *serv)
{
	fd_set			fd_read;
	int				max;

	while (true)
	{
		FD_ZERO(&fd_read);
		FD_SET(serv->socket, &fd_read);
		max = user_fd_set(serv, &fd_read);
		ft_printf("lal");
		if (select(MAX(max, serv->socket) + 1, &fd_read, NULL, NULL, NULL) < 0)
			continue ;
		ft_printf("lal");
		user_fd_isset(serv, &fd_read);
		ft_printf("lul");
		if (FD_ISSET(serv->socket, &fd_read))
			accept_user(serv);
		{
			t_user *user = DLISTBEGIN(&(serv->users));
			while ((user = DLISTNEXT(user)))
			{
				ft_printf("User... %d\n", user->socket);
			}
		}
	}
}
