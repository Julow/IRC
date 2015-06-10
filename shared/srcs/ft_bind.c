/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 17:59:41 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/10 18:55:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

static int		try_bind(struct addrinfo *addr)
{
	int				fd;

	while (addr != NULL)
	{
		fd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
		if (fd >= 0)
		{
			if (bind(fd, addr->ai_addr, addr->ai_addrlen) == 0
				&& listen(fd, MAX_CLIENTS) == 0)
				return (fd);
			close(fd);
		}
		addr = addr->ai_next;
	}
	return (-1);
}

int				ft_bind(char const *port)
{
	struct addrinfo	hints;
	struct addrinfo	*res;
	struct protoent	*proto;
	int				fd;

	if ((proto = getprotobyname("tcp")) == NULL)
		return (-1);
	ft_bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_INET6;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	hints.ai_protocol = proto->p_proto;
	if (getaddrinfo(NULL, port, &hints, &res) != 0)
		return (-1);
	fd = try_bind(res);
	freeaddrinfo(res);
	return (fd);
}
