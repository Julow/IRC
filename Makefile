# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/11 14:51:22 by jaguillo          #+#    #+#              #
#    Updated: 2015/06/11 17:41:46 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := client

PREFIX := irc_

LIBS := libft

all: $(NAME)

$(NAME): %: $(LIBS) %_all
	@ln -sf $(PREFIX)$@/$@ $@

$(LIBS):
	@make -C $@

clean: $(addsuffix _clean,$(NAME))

fclean: $(addsuffix _fclean,$(NAME))
	@rm -f $(NAME)

re: $(addsuffix _fclean,$(NAME)) all

$(addsuffix _%,$(NAME)):
	@make -C $(PREFIX)$(subst _, ,$@)

.PHONY: all clean fclean re $(LIBS) $(addsuffix _%,$(NAME))
