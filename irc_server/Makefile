#
# server
#
# Makefile
#

#
# Config
#

# Project name
NAME := server

# Project directories
DIRS := srcs include ../shared

# Obj directory
O_DIR := o

# Makefiles to call
LIBS := 

# Number of threads
THREADS := 1

# C compiler
C_CC := clang

# Linking compiler
LD_CC := clang

# Clang flags
C_FLAGS := -Wall -Wextra -Werror -O2 -g

# Linking flags
LD_FLAGS := -L ../libft -l ft

# Clang include flags
C_HEADS := -I include -I ../shared/include -I ../libft

#
# Internal
#

O_FILES := o/_../shared/srcs/ft_bind.o \
	o/_../shared/srcs/ft_circb.o \
	o/_../shared/srcs/ft_connect.o \
	o/_../shared/srcs/ft_hmapbegin.o \
	o/_../shared/srcs/ft_hmapnext.o \
	o/srcs/argv.o \
	o/srcs/channel_hash.o \
	o/srcs/listen.o \
	o/srcs/main.o

MSG_0 := printf '\033[0;32m%-32.32s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-32.32s\033[0;0m\n'
MSG_END := printf '\n'

.SILENT:

all: $(LIBS) $(NAME)
.PHONY: all

$(NAME): $(O_FILES)
	@$(MSG_0) $@ ; $(LD_CC) -o $@ $(O_FILES) $(LD_FLAGS) && $(MSG_END) || $(MSG_1) $@

o/_../shared/srcs/ft_bind.o: ../shared/srcs/ft_bind.c ../shared/include/ft_irc.h
	@mkdir -p o/_../shared/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/_../shared/srcs/ft_circb.o: ../shared/srcs/ft_circb.c ../shared/include/ft_circb.h ../shared/include/ft_irc.h
	@mkdir -p o/_../shared/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/_../shared/srcs/ft_connect.o: ../shared/srcs/ft_connect.c ../shared/include/ft_circb.h ../shared/include/ft_irc.h
	@mkdir -p o/_../shared/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/_../shared/srcs/ft_hmapbegin.o: ../shared/srcs/ft_hmapbegin.c ../shared/include/ft_circb.h ../shared/include/ft_hmap_it.h ../shared/include/ft_irc.h
	@mkdir -p o/_../shared/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/_../shared/srcs/ft_hmapnext.o: ../shared/srcs/ft_hmapnext.c ../shared/include/ft_circb.h ../shared/include/ft_hmap_it.h ../shared/include/ft_irc.h
	@mkdir -p o/_../shared/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/argv.o: srcs/argv.c ../shared/include/ft_circb.h ../shared/include/ft_dlist.h ../shared/include/ft_hmap_it.h ../shared/include/ft_irc.h include/msg.h include/server.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/channel_hash.o: srcs/channel_hash.c ../shared/include/ft_circb.h ../shared/include/ft_dlist.h ../shared/include/ft_hmap_it.h ../shared/include/ft_irc.h include/msg.h include/server.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/listen.o: srcs/listen.c ../shared/include/ft_circb.h ../shared/include/ft_dlist.h ../shared/include/ft_hmap_it.h ../shared/include/ft_irc.h include/msg.h include/server.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

o/srcs/main.o: srcs/main.c ../shared/include/ft_circb.h ../shared/include/ft_dlist.h ../shared/include/ft_hmap_it.h ../shared/include/ft_irc.h include/msg.h include/server.h
	@mkdir -p o/srcs 2> /dev/null || true
	@$(MSG_0) $< ; clang $(C_FLAGS) $(C_HEADS) -c -o $@ $< || ($(MSG_1) $< && false)

$(LIBS):
	@make -C $@
.PHONY: $(LIBS)

clean:
	@rm -f $(O_FILES) 2> /dev/null || true
	@rmdir -p o/srcs o/_../shared/srcs $(O_DIR) 2> /dev/null || true
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
