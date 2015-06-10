/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:01:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/10 18:42:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

static int		try_connect(struct addrinfo *addr)
{
	int				fd;

	while (addr != NULL)
	{
		fd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
		if (fd >= 0)
		{
			if (connect(fd, addr->ai_addr, addr->ai_addrlen) == 0)
				return (fd);
			close(fd);
		}
		addr = addr->ai_next;
	}
	return (-1);
}

int				ft_connect(char const *addr, char const *port)
{
	struct addrinfo	hints;
	struct addrinfo	*res;
	struct protoent	*proto;
	int				fd;

	if ((proto = getprotobyname("tcp")) == NULL)
		return (-1);
	ft_bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = proto->p_proto;
	if (getaddrinfo(addr, port, &hints, &res) != 0)
		return (-1);
	fd = try_connect(res);
	freeaddrinfo(res);
	return (fd);
}
