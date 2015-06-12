/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 14:53:00 by jaguillo          #+#    #+#             */
/*   Updated: 2015/06/12 14:56:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# include "ft_colors.h"

# define ENDL			"\n"

# define E_PREFIX		C_RED "[Error]" C_RESET " "
# define I_PREFIX		C_CYAN "[Info]" C_RESET " "

# define E_NOARG		E_PREFIX "Not enougth arguments" ENDL
# define E_BIND			E_PREFIX "Cannot bind to port '%s'" ENDL

# define I_LISTEN		I_PREFIX "Server listening on port %s" ENDL

#endif
