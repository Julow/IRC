/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 18:06:46 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/10 13:50:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IRC_H
# define FT_IRC_H

/*
** ========================================================================== **
** Protocol:
** ----
** Commands:
**  PASS <passwd>						Set a password (use before USER)
**  USER <username>						Register a new user
**  NICK <nick>							Set a nickname (registration finish)
**  OPER <username> <passwd>			Get OP rights
**  QUIT [msg]							Quit
**  JOIN <channel> [key]				Join a channel
**  PART <channel>						Leave a channel
**  MODE <channel> [+-]opsitnbv [arg]	Change the channel mode (OP only)
**  MODE <nickname> [+-]iswo [arg]		Change the user mode (OP only)
**  TOPIC <channel> [topic]				Change or print the channel topic
**  NAMES [channel ...]					List all channels and user
**  LIST [channel ...]					List all channels and their topics
**  INVITE <nickname> <channel>			Invite an user in a channel
**  KICK <channel> <user> [comment]		Kick an user
**  STATS								Print stats
**  TIME								Print current time
**  HELP								Print help
**  PRIVMSG <user> <msg>				Send a private message
**  NOTICE <user> <msg>					Like PRIVMSG but without response
**  WHO [name]							Print matching names (can contains *)
**  WHOIS <name>						Print stats about a user
**  WHOWAS <name>						Like WHOIS but search for logout user
**  KILL <user> [comment]				Kill connection with an user
**  AWAY [message]						Automatic reply to PRIVMSG
** ----
** Channel:
**  Can be invite-only
**  Have a ban list
**  Can have a passwd (key)
** ----
** User:
**  Can be without channel
**  Can be in sevaral channels
*/

/*
** https://tools.ietf.org/html/rfc1459
** <message>  ::= [':' <prefix> <SPACE> ] <command> <params> <crlf>
** <prefix>   ::= <servername> | <nick> [ '!' <user> ] [ '@' <host> ]
** <command>  ::= <letter> { <letter> } | <number> <number> <number>
** <SPACE>    ::= ' ' { ' ' }
** <params>   ::= <SPACE> [ ':' <trailing> | <middle> <params> ]
** <middle>   ::= <Any *non-empty* sequence of octets not including SPACE
**                or NUL or CR or LF, the first of which may not be ':'>
** <trailing> ::= <Any, possibly *empty*, sequence of octets not including
**                  NUL or CR or LF>
** <crlf>     ::= CR LF
** NOTES:
**   1)    <SPACE> is consists only of SPACE character(s) (0x20).
**         Specially notice that TABULATION, and all other control
**         characters are considered NON-WHITE-SPACE.
**   2)    After extracting the parameter list, all parameters are equal,
**         whether matched by <middle> or <trailing>. <Trailing> is just
**         a syntactic trick to allow SPACE within parameter.
**   3)    The fact that CR and LF cannot appear in parameter strings is
**         just artifact of the message framing. This might change later.
**   4)    The NUL character is not special in message framing, and
**         basically could end up inside a parameter, but as it would
**         cause extra complexities in normal C string handling. Therefore
**         NUL is not allowed within messages.
**   5)    The last parameter may be an empty string.
**   6)    Use of the extended prefix (['!' <user> ] ['@' <host> ]) must
**         not be used in server to server communications and is only
**         intended for server to client messages in order to provide
**         clients with more useful information about who a message is
**         from without the need for additional queries.
**    Most protocol messages specify additional semantics and syntax for
**    the extracted parameter strings dictated by their position in the
**    list.  For example, many server commands will assume that the first
**    parameter after the command is the list of targets, which can be
**    described with:
**    <target>     ::= <to> [ "," <target> ]
**    <to>         ::= <channel> | <user> '@' <servername> | <nick> | <mask>
**    <channel>    ::= ('#' | '&') <chstring>
**    <servername> ::= <host>
**    <host>       ::= see RFC 952 [DNS:4] for details on allowed hostnames
**    <nick>       ::= <letter> { <letter> | <number> | <special> }
**    <mask>       ::= ('#' | '$') <chstring>
**    <chstring>   ::= <any 8bit code except SPACE, BELL, NUL, CR, LF and
**                      comma (',')>
**    Other parameter syntaxes are:
**    <user>       ::= <nonwhite> { <nonwhite> }
**    <letter>     ::= 'a' ... 'z' | 'A' ... 'Z'
**    <number>     ::= '0' ... '9'
**    <special>    ::= '-' | '[' | ']' | '\' | '`' | '^' | '{' | '}'
**    <nonwhite>   ::= <any 8bit code except SPACE (0x20), NUL (0x0), CR
**                      (0xd), and LF (0xa)>
*/

#endif
