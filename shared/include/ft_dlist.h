/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 22:21:28 by juloo             #+#    #+#             */
/*   Updated: 2015/06/13 01:23:28 by juloo            ###   ########.fr       */
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
** ft_dlistpush
** ----
** Push an element to the list after 'prev'
** ----
** If 'prev' is NULL push to the front
** ----
** Warning: If 'prev' is not NULL it need to be into the list
*/
inline void		ft_dlistpush(t_dlist *dlist, t_dhead *prev, t_dhead *add)
{
	add->prev = prev;
	if (prev == NULL)
		prev = (t_dhead*)dlist;
	add->next = prev->next;
	prev->next = add;
	if (add->next == NULL)
		dlist->back = add;
	else
		add->next->prev = add;
	dlist->count++;
}

/*
** ft_dlistremove
** ----
** Remove an element from the list
** ----
** Warning: 'rem' need to be into the list
*/
inline void		ft_dlistremove(t_dlist *dlist, t_dhead *rem)
{
	if (rem->prev != NULL)
		rem->prev->next = rem->next;
	else
		dlist->front = rem->next;
	if (rem->next != NULL)
		rem->next->prev = rem->prev;
	else
		dlist->back = rem->prev;
	dlist->count--;
}

#endif
