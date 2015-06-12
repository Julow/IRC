# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/11 14:51:22 by jaguillo          #+#    #+#              #
#    Updated: 2015/06/12 15:26:20 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := server client

LIBS := libft

all: $(NAME)
.PHONY: all

$(NAME): %: $(LIBS) %_all
	@ln -sf 

$(LIBS):
	@make -C "$@"
.PHONY: $(LIBS)

clean: $(addsuffix _clean,$(NAME))

fclean: $(addsuffix _fclean,$(NAME))
	@rm -f $(NAME)

re: fclean all

$(addprefix %_,all clean fclean re):
	@make -C $(subst _, ,$@)
