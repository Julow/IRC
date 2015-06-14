/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 22:21:28 by juloo             #+#    #+#             */
/*   Updated: 2015/06/15 00:44:10 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include "libft.h"

/*
** ========================================================================== **
** Double-linked list
*/

/*
** t_dhead
** ----
** Represent an element
*/
typedef struct	s_dhead
{
	struct s_dhead	*next;
	struct s_dhead	*prev;
}				t_dhead;

# define DHEAD()		((t_dhead){NULL, NULL})

/*
** t_dlist
** ----
** List container
*/
typedef struct	s_dlist
{
	t_dhead			*front;
	t_dhead			*back;
	int				count;
}				t_dlist;

# define DLIST()		((t_dlist){NULL, NULL, 0})

/*
** Iterator
*/
# define DLISTBEGIN(l)	((void*)(l))

# define DLISTNEXT(l)	((void*)(((t_dhead*)(l))->next))
# define DLISTPREV(l)	((void*)(((t_dhead*)(l))->prev))

# define DLISTHEAD(l)	((t_dhead*)(l))

/*
** ft_dlistpush
** ----
** Push an element to the list after 'prev'
** ----
** If 'prev' is NULL push to the front
** ----
** Warning: If 'prev' is not NULL it need to be into the list
*/
inline void		ft_dlistpush(t_dlist *dlist, void *prev, void *add)
{
	DLISTHEAD(add)->prev = prev;
	if (prev == NULL)
		prev = dlist;
	DLISTHEAD(add)->next = DLISTHEAD(prev)->next;
	DLISTHEAD(prev)->next = add;
	if (DLISTHEAD(add)->next == NULL)
		dlist->back = add;
	else
		DLISTHEAD(add)->next->prev = add;
	dlist->count++;
}

/*
** ft_dlistremove
** ----
** Remove an element from the list
** ----
** Warning: 'rem' need to be into the list
*/
inline void		ft_dlistremove(t_dlist *dlist, void *rem)
{
	if (DLISTHEAD(rem)->prev != NULL)
		DLISTHEAD(rem)->prev->next = DLISTHEAD(rem)->next;
	else
		dlist->front = DLISTHEAD(rem)->next;
	if (DLISTHEAD(rem)->next != NULL)
		DLISTHEAD(rem)->next->prev = DLISTHEAD(rem)->prev;
	else
		dlist->back = DLISTHEAD(rem)->prev;
	dlist->count--;
}

#endif
