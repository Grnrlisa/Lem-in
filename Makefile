##
## EPITECH PROJECT, 2021
## B-PSU-101-REN-1-1-minishell1
## File description:
## Minishell 1 makefile
##

## Sources of the prog

SRC	=	sources/lem_ain.c 		\
		sources/find_path.c		\
		sources/file.c 			\
		sources/init_grap.c		\
		sources/check_error.c	\
		sources/check_in_file.c \
		sources/init_room.c 	\
		sources/init_tunnels.c 	\
		sources/end_and_start.c \
		sources/explore.c 		\
		sources/my_strcmp.c 	\
		sources/list_void/list_void_get_nod.c \
		sources/list_void/list_void_init_list.c \
		sources/list_void/list_void_insert_list.c \
		sources/list_void/list_void_kill_nod.c \
		sources/list_void/list_void_print_list.c \
		sources/list_void/list_void_rev_list.c \
		sources/list_void/list_void_size.c \
		sources/list_void/list_void_size_list.c \
		sources/list_void/list_void_temp.c \


OBJ = $(SRC:.c=.o)

NAME =	lem_in

LIB = -L lib/ -lmy

INCLUDE = -I include/

## Compilation flags (auto pick-up)
CFLAGS = -Wall -W $(INCLUDE) -Wextra -L lib/my -lmy

## Make commande
all:	mylib $(OBJ) clean
	gcc -g -o $(NAME) $(SRC) $(INCLUDE) $(LIB)

mylib:
	make -C lib/my/

## clean commande : rm files object
clean:
	rm -f $(OBJ)
	make clean -C lib/my/


## fclean commande : rm binary
fclean:
	rm -f $(NAME)
	make clean
	make fclean -C lib/my/


## re commande : remake after cleaning
re:
	make fclean
	make all

debug: CFLAGS += -g -Og -std=gnu99
debug: re
.PHONY: clean, fclean, re, all
